//Login and Registration System
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
bool IsLoggedIn()
{
    string username, password, un, pw; 
    //un pw are comparision strings;

    cout<<"Enter username:"<<endl;
    cin>>username;
    cout<<"Enter Password:"<<endl;
    cin>>password;
    ifstream read("Login_Registration.txt");
    getline(read, un); // un will store the input username from input file read
    getline(read, pw); // pw will store the input password from input file read

    if (un == username && pw == password)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

int main()
{
    int choice;
    cout<<"Register(1)   or   Login(2)"<<endl<<"ENTER YOUR CHOICE(R/L):"<<endl;
    cin>>choice;
    if (choice == 1)
    {
        string username, password;
        cout<<"Enter a Username of your choice:"<<endl;
        cin>>username;
        cout<<"Choose your Password"<<endl;
        cin>>password;

        ofstream file;
        file.open("Login_Registration.txt");
        file<<username<<endl<<password;
        file.close();
        main();
    }

    else if(choice ==2)
    {
        bool status = IsLoggedIn();
        if (status == false)
        {
            cout<<"Invalid Username or Password"<<endl;
            system("Pause");
            return 0;
        }
        else
        {
            cout<<"Logged in successfully."<<endl;
            system("color 70");
            system("Pause");
            return 1;
        }
    }
}