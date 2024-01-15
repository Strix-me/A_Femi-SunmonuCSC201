#include <iostream>
#include <vector>
using namespace std;

int main()
{

vector<int> v{10,20,30,40,50};
vector<int> :: iterator it;

for (it = v.begin(); it != v.end(); it++)
{
    *it = *it - 10;
}

cout <<"Ouptput og Begin and end: ";
    for(auto i = v.begin(); i != v.end(); ++i)
        cout << *i<< "";

}