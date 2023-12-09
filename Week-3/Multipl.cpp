#include <iostream>
using namespace std;

int main() {
    int n;

    std::cout << "Enter the value of n: ";
    cin >> n;

  
    for (int i = 0; i <= n; i++) {

        for (int j = 1; j <= 10; j++) {
            cout << i << " x " << j << " = " << (i * j) << "\t";
        }
        cout << std::endl; 
    }

    return 0;
}
