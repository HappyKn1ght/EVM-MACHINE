#include <iostream>
#include <string>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
int votes[5] = {0, 0, 0, 0, 0};
string votedUIDs[100];
string votedNames[100];
int totalVoters = 0;
bool pollingOpen = true;
string candidates[5] =
    {
        "Narendra Modi    - BJP",
        "Rahul Gandhi     - INC",
        "Arvind Kejriwal  - AAP",
        "Mayawati         - BSP",
        "NOTA"};

// function to vote
void vote()
{
    if (pollingOpen == false)
    {
        cout << "Polling is closed! Cannot vote." << endl;
        return;
    }
    else
    {
        // showing candidates
        cout << "\n--- Candidates ---" << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << i + 1 << ". " << candidates[i] << endl;
        }

        // taking votes with loop
        int choice;
        while (true)
        {
            cout << "\nEnter candidate number (1-5): ";

            string input;
            getline(cin, input);

            choice = atoi(input.c_str());

            if (choice < 1 || choice > 5)
            {
                cout << "Invalid choice! Enter between 1-5." << endl;
            }
            else
            {
                break;
            }
        }

        // confirmation with loop
        char confirm;
        while (true)
        {
            cout << "Confirm vote for " << candidates[choice - 1] << "? (Y/N): ";
            confirm = cin.get();

            if (confirm == 'Y' || confirm == 'y')
            {
                cin.ignore(1000, '\n');
                votes[choice - 1]++;
                cout << "Vote cast successfully!\nThank you for voting!" << endl;
                break;
            }
            else if (confirm == 'N' || confirm == 'n')
            {
                cin.ignore(1000, '\n');
                cout << "Vote cancelled!" << endl;
                break;
            }
            else if (confirm == '\n')
            {
                cout << "Cannot be empty! Try again." << endl;
            }
            else
            {
                cin.ignore(1000, '\n');
                cout << "Invalid! Enter Y or N only!" << endl;
            }
        }
    }
}
// function for user information
void start()
{
    string userName;
    string uId;
    cin.ignore();
    while (true)
    {
        // random generate for CAPTCHA
        // Name input loop
        cout << "\nEnter Your Name: ";
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

    // UID input loop
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

    // CAPTCHA verification
    srand(time(0));
    while (true)
    {
        int captcha = (rand() % 900000) + 100000;
        cout << "CAPTCHA: " << captcha << endl;
        cout << "Enter CAPTCHA: ";
        string input;
        getline(cin, input);

        int captchaEnter = atoi(input.c_str());
        if (captchaEnter != captcha)
        {
            cout << "Invalid CAPTCHA!\nTry again." << endl;
            continue;
        }
        else
        {
            cout << "Correct CAPTCHA" << endl;
            break;
        }
    }

    // Verification animation
    for (int i = 0; i <= 100; i++)
    {
        int barWidth = 20; // total size of bar

        int filled = (i * barWidth) / 100; // how many
        cout << "\r[";

        // print filled part
        for (int j = 0; j < filled; j++)
            cout << "#";

        // print empty part
        for (int j = filled; j < barWidth; j++)
            cout << ".";

        cout << "] " << i << "%" << flush;

        Sleep(30);
    }

    cout << "\nVerification Complete!\n";
    // checking if already voted
    bool alreadyVoted = false;
    int foundIndex = -1;
    for (int i = 0; i < totalVoters; i++)
    {
        if (votedUIDs[i] == uId)
        {
            alreadyVoted = true;
            foundIndex = i;
            break;
        }
    }

    if (alreadyVoted)
    {
        cout << "\nThis UID has already been used!" << endl;
        cout << "Previously voted by: " << votedNames[foundIndex] << endl;
        cout << "UID: " << uId << endl;
        cout << "You cannot vote with this UID!" << endl;
        return;
    }
    else
    {
        votedUIDs[totalVoters] = uId;
        votedNames[totalVoters] = userName;
        totalVoters++;
        vote(); // vote function call after verification completed
    }
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
    cout << "Thanks for using EVM Machine!\nGoodbye!" << endl;
    exit(0);
}

int main()
{
    // Interface for EVM Machine
    int input;
    // do-while loop
    do
    {
        system("cls");
        cout << "[][][][][][][][][][]" << endl;
        cout << "[]                []" << endl;
        cout << "[]   EVM Machine  []" << endl;
        cout << "[]                []" << endl;
        cout << "[][][][][][][][][][]" << endl;

        // Greeting from machine
        cout << "\n===Welcome to EVM Machine==="
             << endl;
        // user input options
        cout << "[1].Start Voting" << endl;
        // cout << "[2].Close Polling" << endl;
        // cout << "[3].Results" << endl;
        cout << "[2].How-To-Use" << endl;
        cout << "[3].About" << endl;
        cout << "[4].Exit" << endl;
        cout << "Select Your Option: ";

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
        cin.ignore();
        cin.get();
    } while (input != 4);
    return 0;
}