#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void registerUser()
{
    string username, password;
    cout << "\n--- Registration ---\n";

    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    // Check if username already exists
    ifstream infile("users.txt");
    string user, pass;

    while (infile >> user >> pass)
    {
        if (user == username)
        {
            cout << "Username already exists!\n";
            infile.close();
            return;
        }
    }
    infile.close();

    // Save new user
    ofstream outfile("users.txt", ios::app);
    outfile << username << " " << password << endl;
    outfile.close();

    cout << "Registration Successful!\n";
}

void loginUser()
{
    string username, password;
    cout << "\n--- Login ---\n";

    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    ifstream infile("users.txt");
    string user, pass;
    bool found = false;

    while (infile >> user >> pass)
    {
        if (user == username && pass == password)
        {
            found = true;
            break;
        }
    }
    infile.close();

    if (found)
        cout << "Login Successful! Welcome " << username << endl;
    else
        cout << "Invalid Username or Password!\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n===== Login & Registration System =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            registerUser();
            break;

        case 2:
            loginUser();
            break;

        case 3:
            cout << "Thank You!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 3);

    return 0;
}