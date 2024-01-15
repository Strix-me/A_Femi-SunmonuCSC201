#include<iostream>
#include<fstream>
#include<string.h>
#include<cstdlib> // Added for system("cls")
using namespace std;

void questions(){
    cout<<"\t\t\tWelcome To Csc 201 CBT\n"<<endl;
    
}

void login() {
    int count = 0; // Declare and initialize count
    string user, pass, u, p;
    system("cls");
    cout << "please enter the following details" << endl;
    cout << "USERNAME :";
    cin >> user;
    cout << "PASSWORD :";
    cin >> pass;

    ifstream input("student_credentials.txt");
    while (input >> u >> p) {
        if (u == user && p == pass) {
            count = 1;
            cout << "\nHello " << user << "\n<LOGIN SUCCESSFUL>";
            system("cls");
        }
    }
    input.close();
    if (count == 1) {
        cout << "\nHello " << user << "\n<LOGIN SUCCESSFUL>";
        cin.get();
        cin.get();
        questions();
    
        
    }
    else {
        int d;
        cout << "\nLOGIN ERROR\nPlease check your username and password\n";
        cout <<"You are not eligible";
        cout<<"\nPress 1 START AGAIN"<<endl; 
        cin>> d;
        cout<<endl;
       if (d == 1)
       {
        login();

       }
       else{
        cout << "Please Enter a Valid Input from the Options Given\n" << endl;
       }
       
        
        
    }
}



void landingpg() {
    int c;
   
    cout << "MENU\n\n\n";
    cout << "Press 1 to LOGIN" << endl;
    cout << "Press 2 to EXIT\n" << endl;
    cin >> c;
    cout << endl;

    switch (c) {
    case 1:
        login();
        break;
    case 2:
        exit(0);
    default:
        cout << "Please Enter a Valid Input from the Options Given\n" << endl;
        landingpg();
    }
}

int main() {
    landingpg();
    return 0; // Add return statement
}
