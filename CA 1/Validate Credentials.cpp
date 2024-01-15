#include <iostream>
#include <fstream>
#include <cstdlib> 

using namespace std;

class Student {
private:
    string stud_username;
    string stud_password;

public:
    void validate_stud_username_and_password();
    void stud_mainmenu();
};

void Student::validate_stud_username_and_password() {
    string uname, pword;
    cout << "Enter username: ";
    cin >> uname;
    cout << "Enter password: ";
    cin >> pword;

    ifstream myfile("student_credentials.txt");

    if (myfile.is_open()) {
        bool found = false;

        while (myfile >> stud_username >> stud_password) {
            if (uname == stud_username && pword == stud_password) {
                found = true;
                break;
            }
        }

        myfile.close();

        if (found) {
            cout << "Login successful." << endl;
           
        } else {
            cout << "Wrong username or password!" << endl;
        }
    } else {
        cout << "Error opening file!" << endl;
    }
}



int main() {
    // Example usage
    Student student;
    student.validate_stud_username_and_password();

    return 0;
}
