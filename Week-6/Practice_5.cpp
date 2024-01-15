#include<iostream>
#include <string>
#include <sstream>
using namespace std;

struct biodata{
    string name;
    int dob;
};
 struct csc211{
    biodata data;
    int score;
 };

 csc211 student1;

 int main(){
    cout<<"Enter Students Name :";
    cin>>student1.data.name;
    cout<<"Enter Students age: ";
    cin>>student1.data.dob;
    cout<<"Enter Students csc211 Score: ";
    cin>>student1.score;
    cout <<"The Students name is: "<<student1.data.name<<endl;
    cout<<"The Students age is: "<<student1.data.dob<<endl;
    cout<<"The students score un csc211 is: "<<student1.score<<endl;

    return 0;
 }