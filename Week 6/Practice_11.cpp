#include <iostream>
using namespace std;
union unionJob
{
    char name[32];
    float salary;
    int workerNO;
}uJob;

struct structJob
{
    char name[32];
    float salary;
    int workerNO;
} sJob;

int main(){
    cout<<"size of union in bytes"<< sizeof(uJob)<<endl;
    cout<<"size of structure in bytes"<< sizeof(sJob)<<endl;
    return 0;


}