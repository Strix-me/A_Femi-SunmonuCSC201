#include <iostream>
using namespace std;
enum week{ Sundnay, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};

int main(){
    typedef week weekdays;
    weekdays today;
    if(today ==1){
        cout<< "Today is Monday";
    }else{
         cout<< "Today is not monday "<<;
    }
   
    return 0;
}