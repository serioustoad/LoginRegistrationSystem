# include <iostream>
# include <fstream>
# include <string>

using namespace std;

// Prompt user for input
bool prompt()
{
    bool pathway{ false }; // Returned to main()
    bool checknum{ false }; // While-loop control
    char answer{ NULL };
    
    while (checknum == false) // Prompt user for new answer until it is a number
    {
        std::cout << "Do you have an account with us?" << std::endl;
        std::cout << "1: Yes" << std::endl;
        std::cout << "2: No" << std::endl; 
        std::cin >> answer; 
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignores input beyond first digit

        // If input not numeric or does not start with 1 or 2, considered invalid
        if (std::isdigit(answer) == 0 || int(answer) - 48 != 1 && int(answer) - 48 != 2)
        {
            std::cout << "Invalid response! (1: Yes, 2: No)" << std::endl; 
        }
        else
        {
            checknum = true;
        }
    }

    if (int(answer) - 48 == 1)
    {
        pathway = true;
        return pathway;
    }
    if (int(answer) - 48 == 2)
    {
        pathway = false;
        return pathway;
    }
    else
    {
        std::cout << "Something went wrong. Please exit the program and try again." << std::endl;
        exit(EXIT_FAILURE);
    }
}

// Log-in repeats until successful
bool login()
{
    std::string username, password, r_un, r_pw;

    std::cout << "Please log-in below." << std::endl;
    std::cout << "Please type in your username: "; std::cin >> username;
    std::cout << "Please type in your password: "; std::cin >> password;

    // Check .txt files for user account
    ifstream read(username + ".txt");
    std::getline(read, r_un);
    std::getline(read, r_pw);

    if (r_un == username && r_pw == password)
    {
        return true;
    }
    if (r_un == username && r_pw != password)
    {
        return false;
    }
    else
    {
        std::cout << "This username is incorrect or does not exist. Please exit the program and try again." << std::endl;
        system("pause");
        exit(1);
    }
}

// Successful registration leads to log-in in main()
bool registration()
{
    std::string username, c_un;
    bool un_unique{ false };
    
    std::cout << "Please register below." << std::endl;
    
    // Create a username
    while (un_unique == false)
    {
        std::cout << "Create a username: "; std::cin >> username;
        
        // FEATURE: Check if username is unique
        ifstream read(username + ".txt");
        std::getline(read, c_un);

        if (c_un == username)
        {
            std::cout << "This username is already taken. Please create a different username." << std::endl;
        }
        else
        {
            un_unique = true;
        }
    }
    
    std::string password;
    bool c_pw{ false }; // While-loop control

    // Create a password
    while (c_pw == false)
    {
        std::cout << "Passwords must be 8 characters or longer, and must include a letter, a digit, and a special symbol." << std::endl;
        std::cout << "Create a password : " << std::endl; std::cin >> password;
        
        // FEATURE: Check if password is 8 long, includes a char, a digit, a special symbol
        if (password.length() < 8)
        {
            std::cout << "The password must be longer than 8 characters." << std::endl;
        }
        else
        {
            int cr = 0, dg = 0, ss = 0, sslength = 8;
            const char symbols[8] = { '!', '@', '#', '$', '%', '^', '&', '*'};

            for (size_t i = 0; i < password.length(); i++) // Count char, digits, special symbols in password
            {
                char temp = int(password[i]);
                if (std::isdigit(temp) != 0)
                {
                    dg++;
                }
                if (std::isalpha(password[i]) != 0)
                {
                    cr++;
                }
                else
                    for (int j = 0; j < sslength; j++)
                    {
                        if (password[i] == symbols[j])
                        {
                            ss++;
                        }
                    }
            }
            if (cr > 0 && dg > 0 && ss > 0)
            {
                c_pw = true;
            }
            else
            {
                std::cout << "Passwords must include a letter, a digit, and a special symbol. Please create a different password." << std::endl;
            }
        }
    }

    // Create a .txt file for each new user
    std::ofstream file;
    file.open(username + ".txt");
    file << username << std::endl << password;
    file.close();

    std::cout << "Success! You are now registered. Please log in below." << std::endl;
    return false;
}

// Log-in vs registration
int main()
{
    bool accountstatus = prompt(); // Receives and cleans user input
    bool loginmode{ false }; // Do-while loop control
    int loginattemptsrem{ 3 }; // User's # of attempts remaining  

    do
    {
        if (accountstatus == true)
        {
            // FEATURE: Security measure that allows only 3 log-in attempts
            if (loginattemptsrem > 0) 
            {
                loginmode = login();
                loginattemptsrem--;
                
                if (loginmode == false)
                {
                    std::cout << "Incorrect password. You have " << loginattemptsrem << " attempt(s) remaining to try again." << std::endl;
                }
                else
                {
                    continue;
                }
            }
            else
            {
                std::cout << "You are out of log-in attempts. Please exit the program now." << std::endl;
                system("pause");
                exit(2);
            }
        }
        if (accountstatus == false)
        {
            loginmode = registration();
            accountstatus = true;
        }
    } while (loginmode == false);

    std::cout << "Log-in successful! The is the extent of the program, please exit now." << std::endl;

    system("pause");
    return 0;
}

