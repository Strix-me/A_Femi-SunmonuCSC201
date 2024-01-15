#include <iostream>
#include <thread>
using namespacestd;
void printx()
{
    for(int i=0; i<=50; i++)
    cout<<"x";
}
int main(){
    thread t1(printx);
    t1.join();
    return 0;
}