#include <iostream>
using namespace std;
enum week{ Sundnay, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};

int main(){
    week today;
    today = Monday;
    if(today ==1){
        cout<< "Today is Monday";
    }else{
         cout<< "Today is not monday "<< today+1;
    }
   
    return 0;
}