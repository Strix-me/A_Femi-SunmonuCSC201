#include <iostream> 
using namespace std;

namespace first{
    int x = 5;
}
namespace second{
    double x = 3.1416;
}
int main()
{
    namespace one=first;
    namespace two=second;
    
    {
        using namespace one;
        cout << x << '\n';
    }

     {
        using namespace two;
        cout << x << '\n';
    }
    return 0;
  
  
        
   
} 