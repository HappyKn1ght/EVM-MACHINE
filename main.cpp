#include <iostream>
#include <string>

using namespace std;
// function for user information
void start()
{
    string userName;
    string uId;
    cout << "Enter Your Name: ";
    cin.ignore();
    getline(cin, userName);
    if (userName.empty() || userName == " ")
    {
        cout << "Name cannot be empty! " << endl;
    }
    else
    {
        cout << "Welcome " << userName << "!" << endl;
        cout << "Enter Your UID: ";
        getline(cin, uId);
        if (uId.length() == 10)
        {
            cout << "Valid UID";
        }
        else if (uId.length() < 10 || uId.length() > 10)
        {
            cout << "Invalid! UID must be 10 digits." << endl;
        }
        else if (uId.empty() || uId == " ")
        {
            cout << "UID cannot be empty! " << endl;
        }
        else
        {
            cout << "Invalid UID";
        }
        cin >> uId;
        cout << userName << endl;
        cout << uId << endl;
    }
}
// function to 2.How-To-Use
void howToUse()
{
    cout << "HOW TO USE" << endl;
}

// function to 3.About
void about()
{
    cout << "About EVM Machine" << endl;
}

// function to exit
int exit()
{
    cout << "Exiting..." << endl;
    system("pause");
    cout << "Exited" << endl;
    return 0;
}

int main()
{

    // Interface for EVM Machine
    int input;
    system("cls");
    cout << "[][][][][][][][][][]" << endl;
    cout << "[]                []" << endl;
    cout << "[]   EVM Machine  []" << endl;
    cout << "[]                []" << endl;
    cout << "[][][][][][][][][][]" << endl;

    // Greeting from machine
    cout << "\nWelcome to EVM Machine\n"
         << endl;
    // user input options
    cout << "Choose Your Option:- " << endl;
    cout << "1.Start" << endl;
    cout << "2.How-To-Use" << endl;
    cout << "3.About" << endl;
    cout << "4.Exit" << endl;
    cout << "Select Your Option: ";
    cin >> input;
    // do-while loop
    do
    {

        // switch statement
        switch (input)
        {
        case 1:
            start();
            continue;;
        case 2:
            howToUse();
            continue;;
        case 3:
            about();
            continue;;
        case 4:
            exit();
            break;
        }

    } while (input != exit());
    return 0;
}