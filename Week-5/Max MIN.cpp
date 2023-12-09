#include <iostream>
using namespace std;
#include <climits> 

int main() {
    int n; 
    int number; 
    int maximum = INT_MIN; 
    int minimum = INT_MAX; 

    cout << "Enter the number of values: ";
    cin >> n;

    if (n <= 0) {
        cerr << "Invalid input. Please enter a positive number of values." <<endl;
        return 1;
    }

    for (int i = 0; i < n; i++) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> number;

        if (number > maximum) {
            maximum = number;
        }

        if (number < minimum) {
            minimum = number;
        }
    }

    cout << "Maximum value: " << maximum <<endl;
    cout << "Minimum value: " << minimum <<endl;

    return 0;
}
