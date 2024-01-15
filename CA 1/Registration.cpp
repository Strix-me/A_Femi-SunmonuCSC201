#include <iostream>
#include <fstream>
#include <cstdlib> 

using namespace std;

class Student {
public:
    void stud_register_name_and_password();
};

void Student::stud_register_name_and_password()
{
    string un, pw;

    
    ofstream myfile("student_credentials.txt", ios::out | ios::app);

    if (!myfile.is_open()) {
        cout << "Error opening file!" << endl;
        return; 
    }

    cout << "Enter Username: ";
    getline(cin, un);

    
    if (un.empty()) {
        cout << "Username cannot be empty!" << endl;
        return; 
    }

    cout << "Enter Password: ";
    getline(cin, pw);

    
    if (pw.empty()) {
        cout << "Password cannot be empty!" << endl;
        return; 
    }

    
    myfile << un << " " << pw << endl;

    myfile.close();

    cout << "Registration Successful." << endl;
    system("pause");
}

int main() {
    Student student;
    student.stud_register_name_and_password();

    return 0;
}
