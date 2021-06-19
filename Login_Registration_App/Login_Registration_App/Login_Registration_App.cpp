// Login_Registration_App.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;

bool IsLoggedIn() {
    string saved_pw, saved_un, input_pw, input_un;
    char c = ' ';

    cout << "Enter username: " << endl;
    cin >> input_un;

    ifstream read;
    read.open("C:\\Users\\Oroni\\source\\repos\\Login_Registration_App\\forms\\" + input_un + ".txt");
    getline(read, saved_un);
    getline(read, saved_pw);

    input_pw = "";
    cout << "Enter password: " << endl;
    c = _getch();
    while (c != 13) {
        input_pw += c;
        cout << "*";
        c = _getch();
    }
    cout << endl;

    if (input_un == saved_un && input_pw == saved_pw) {
        return true;
    } else {
        return false;
    }
}

void RegisterLogin() {

    int choice;

    cout << "Enter 1 to create a new account.\nEnter 2 to log in." << endl;
    cin >> choice;

    if (choice == 1) {
        string input_un, input_pw;
        char c = ' ';
        cout << "Enter username: " << endl;
        cin >> input_un;
        cout << "Enter password: " << endl;
        c = _getch();
        while (c != 13) {
            input_pw += c;
            cout << "*";
            c = _getch();
        }
        cout << endl;

        ofstream file;
        file.open("C:\\Users\\Oroni\\source\\repos\\Login_Registration_App\\forms\\" + input_un + ".txt");
        file << input_un << endl << input_pw;
        file.close();

        RegisterLogin();
    }
    else if (choice == 2) {
        bool loggedin = IsLoggedIn();
        if (loggedin) {
            cout << "Successfully logged in." << endl;
            system("PAUSE");
        } else {
            cout << "Login failed." << endl;
            RegisterLogin();
        }

    } else {
        RegisterLogin();
    }
}

int main()
{
    RegisterLogin();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
