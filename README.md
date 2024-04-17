# LOG-IN & REGISTRATION SYSTEM
#### **Video Demo**: <https://youtu.be/D0iMYZ_Wh4M>
#### **Description**: A C++ console application that allows users to create an account by registering a username and password. After registration, users may log-in using the created credentials.

## Overview
### Goals & Purpose

#### There were two primary goals behind this project. The first was to learn the language C++, and the second was to familiarize myself with a basic feature in the programming world.
#### I heard about language C++ and its uses before I began programming. I thought it would be an interesting and practical language to learn, considering its versatility, potential for optimization, and speed. One of the main reasons I chose to take CS50x as my first programming course was in fact because it taught foundational programming concepts in C. Therefore, writing my final project for CS50x in C++ was a way to come full circle.
#### I decided to write a log-in and registration system as my final project for similar reasons as the above. A log-in and registration system is an underlying feature of many programs where users must establish a unique identity in order to access secure information. It is a universal feature that is found in operating systems, the Starbucks rewards program, and every application in between. Considering its widespread use, I thought it was beneficial to familiarize myself with its fundamental concepts.
#### These two goals merged in this final project for CS50x - a log-in and registration system written in C++.

### SLDC Methodology

#### In software development, software engineers use structured approaches to create and deliver their work. As a means to learn more about these software development life cycle (SDLC) methodologies, five common methodologies were researched and one implemented in this project's workflow.
#### The five methodologies studied were the following: Agile, Kanban, Scrum, DevOps, and Waterfall.
#### Agile, Kanban, and Scrum were ruled out for this project as these center on customer satisfaction and prioritize communication between multiple parties involved in a project. DevOps was ruled out because it prioritizes communication between the development team and the operations team (there was no operations team on this project).
#### The log-in and registration system project was a solo endeavor with a well-defined requirement. Therefore, a methodology that focuses more on the organization of checkpoints and tasks seemed best. Out of the five, the Waterfall methodology fit the characteristics of this project best with its straightforward process and clearly defined project phases.
#### The project milestones under the Waterfall methodology were the following:
1. Visual Studio, Git, GitHub installation and familiarization
2. Learn the basics of C++
3. Application framework and pseudocode complete
4. Coding and individual components debugging complete
5. Testing complete
6. CS50x final project presentation and documentation complete
7. Project submitted to CS50x

## Documentation

#### The project was implemented in one program file (*LoginRegistrationSystem.cpp*). The following components were written as separate functions from the main function within the program: prompt(), login(), and registration().

### prompt()

#### This is the first function call from main() when the application begins. Prompt() returns a Boolean "pathway", which determines if main() should direct the user to login() or registration().
#### User input is validated through a filter of isdigit() and ASCII conversion to check for whole numbers. If the response is a char or a number else than "1" or "2", the user's input is considered invalid. Input beyond the first value is ignored by a stream size limitation (implemented through cin.ignore()).

### main()

#### The main function is essentially one large do-while loop with nested if-statements. The if-statements were encased in a loop so that users could be prompted to register and/or log-in multiple times, if necessary. A do-while loop was chosen over a while loop because it allowed more flexibility with how I could control the loop. Regardless of what condition I used to control the loop, the do-while loop would run at least once. In trying to follow the Waterfall methodology and attempting to minimize as many back-and-forth edits to the main function as possible, the do-while loop stood out to be a better choice.
#### The Boolean value, "accountstatus", returned from prompt() plays a key role in the if-statements within the do-while loop. Until "accountstatus" is "true", the user is asked to register an account.
#### One security feature I created in main() consists of a countdown of log-in attempts. Users are limited to three log-in attempts before the program exits. The "loginattemptsrem" counts down if the do-while loop repeats the if-statements related to logging in. After three failed log-in attempts, "loginattemptsrem" equals zero and users are exited out of the program.

### registration()

#### Users must create a username and a password as part of the registration process. All created accounts are stored locally as text files. *Although storing credentials in text files is not considered safe practice in the real world, implementing a different strategy was beyond the scope of this project.*
#### Within registration(), I ensured the creation of unique usernames by checking the username input against existing accounts. Some common password complexity rules were also implemented through the use of functions such as .length(), isdigit(), and isalpha().
#### Registration completes when a new text file is written for the new user. Registration() then returns "false" to main(), prompting the user to log-in using their new credentials.

### login()

#### Two pathways lead to login() from main(). The direct pathway begins when the user inputs "1" in prompt(), leading them straight to the log-in portion of the do-while loop in the main function. The indirect pathway is through the user input "2", which leads the user to registration(). Successful registration changes the value of "accountstatus" to "true", which, on the next iteration of the do-while loop, leads to login().
#### Login() is simple; user inputs for a username and a password are checked against existing accounts. There are three outcomes:
1. If the account is not found[^1], the user is asked to exit the program and try again.
2. If the account is found but the password is incorrect, "loginattemptsrem" is deducted one integer value, and the user is prompted to try logging in again.
3. If the account is found and the username and password are correct, the program displays a message saying that the user is successfully logged in.

[^1]: The accounts (text files) are named the following way: username + ".txt". The program attempts the log-in process by screening for accounts named after the username, then reads the file if found. It then checks to see if the username within the file matches the user's input, along with the password. Therefore, even if the account exists and is found, if the username within the account file is not correct, login() will return false to main().

## License
[License](docs/LICENSE.txt)