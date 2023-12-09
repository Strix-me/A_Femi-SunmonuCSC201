#include <iostream>
using namespace std;
main()
{
    //Number And Minutes converter//
    int minutes;
    cout << "Please enter your value: " ;
    cin >> minutes;

    int hours = minutes / 60;
    int remaining_hours = minutes %60;


    cout << "The time is "<< hours << " hours and " << remaining_hours << " minutes ";
    return 0;
} 