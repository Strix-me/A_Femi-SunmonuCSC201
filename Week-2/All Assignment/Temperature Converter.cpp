#include <iostream>
using namespace std;
main()
{
    //temperature conversion//
    int k;
    cout << "Please enter you temperature in kelvin: " ;
    cin >> k;
    cout << "The temperature you entered is " << k;
    cout << "The Temperature in Farenheit is "<< (((k - 273.15)*9)/5) + 32<< ".\n";
    return 0;
} 