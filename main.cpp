#include <iostream>
#include <string>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
// #include <limits>

using namespace std;
// function for user information
void start()
{
    string userName;
    string uId;
    while (true)
    {
        // random generate for capcha
        // Name input loop
        cout << "\nEnter Your Name: ";
        cin.ignore();
        getline(cin, userName);

        if (userName.empty())
        {
            cout << "Name cannot be empty! Try again.\n";
        }
        else
        {
            break; // valid → exit loop
        }
    }

    cout << "Welcome " << userName << "!\n";

    // 🔹 UID input loop
    while (true)
    {
        cout << "Enter Your UID: ";
        getline(cin, uId);

        if (uId.empty())
        {
            cout << "UID cannot be empty! Try again.\n";
        }
        else if (uId.length() != 10)
        {
            cout << "Invalid! UID must be 10 digits.\n";
        }
        else
        {
            break; // valid → exit loop
        }
    }

    // capcha verification
    while (true)
    {
        srand(time(0));
        int capcha = (rand() % 100000);
        int capchaEnter;
        cout << "Capcha: " << capcha << endl;
        cout << "Enter Capcha : ";
        cin >> capchaEnter;
        if (capchaEnter != capcha)
        {
            cout << "Invalid Capcha!\nTry again." << endl;
            continue;
        }
        else
        {
            cout << "Correct Capcha" << endl;
            break;
        }
    }

    // Verification animation
    for (int i = 0; i <= 100; i++)
    {
        cout << "\rVerifying UID... " << i << "%" << flush;
        Sleep(30);
    }

    cout << "\nVerification Complete!\n";
}
// function to 2.How-To-Use
void howToUse()
{
    cout << "\n--- How To Use ---\n";
    cout << "1. Select 'Start' to begin the process.\n";
    cout << "2. Enter your name and a valid 10-digit UID.\n";
    cout << "3. The system will verify your UID with a loading process.\n";
    cout << "4. After successful verification, follow instructions to proceed.\n";
    cout << "5. Use the menu to navigate between options or exit the program.\n";
}

// function to 3.About
void about()
{
    cout << "\n--- About EVM Machine ---\n";
    cout << "1. This is a simple Electronic Voting Machine (EVM) program developed in C++.\n";
    cout << "2. It allows users to cast votes for different candidates.\n";
    cout << "3. The program counts votes and displays the final result.\n";
    cout << "4. It helps in understanding basic programming concepts and logic.\n";
    cout << "5. This project is created for learning and practice purposes.\n";
}

// function to exit
void quit()
{
    cout << "Exiting..." << endl;
    system("pause");
    cout << "Exited" << endl;
    exit(0);
}

int main()
{

    // Interface for EVM Machine
    int input;
    do
    {
        system("cls");
        cout << "[][][][][][][][][][]" << endl;
        cout << "[]                []" << endl;
        cout << "[]   EVM Machine  []" << endl;
        cout << "[]                []" << endl;
        cout << "[][][][][][][][][][]" << endl;

        // Greeting from machine
        cout << "\nWelcome to EVM Machine"
             << endl;
        // user input options
        cout << "\nChoose Your Option:- " << endl;
        cout << "1.Start" << endl;
        cout << "2.How-To-Use" << endl;
        cout << "3.About" << endl;
        cout << "4.Exit" << endl;
        cout << "Select Your Option: ";
        // do-while loop

        cin >> input;
        // switch statement
        switch (input)
        {
        case 1:
            start();
            break;
        case 2:
            howToUse();
            break;
        case 3:
            about();
            break;
        case 4:
            quit();
            break;
        default:
            cout << "Invalid option! Try again.\n";
        }

        cout << "\nPress Enter to continue...";
        // cin.ignore(numeric_limits<streamsize>::max(), '\n');
        // cin.get();
        cin.ignore();
        cin.get();
    } while (input != 4);
    return 0;
}