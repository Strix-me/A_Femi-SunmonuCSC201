#include <iostream>
    using namespace std;
main()
{
    int a = 21;
    int b= 3;
    int c;
        c = a + b;
    cout << "a + b, value of c = :" << c << endl;
        c +=a;
    cout << "+=  a, Value of c = : " << c << endl;
    c -=a;
    cout << "-= a, Value of c = : " << c << endl;
        c /= a;
    cout << "/= a, Value of c = : " << c << endl;
        c = 200;
    c%= a;
    cout << "when c=  2;, c %= a Value of c = : " << c << endl;
        c << 2;
    cout << "c <<=  2;, Value of c = : " << c << endl;
        c >> 2;
    cout << "c >>=  2;, Value of c = : " << c << endl;
        c &= 2;
    cout << "c &=  2;, Value of c = : " << c << endl;
      c ^= 2;
    cout << "c ^=  2;, Value of c = : " << c << endl;
        c |= 2;
    cout << "c |= 2, Value of C = : " << c << endl;

    return 0;
}