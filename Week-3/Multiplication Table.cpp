#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter the value of n: ";
    cin >> n;

  
    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= 12; j++) {
            cout << i << " x " << j << " = " << (i * j) << "\t";
        }
        cout << endl; 
    }

    return 0;
}
