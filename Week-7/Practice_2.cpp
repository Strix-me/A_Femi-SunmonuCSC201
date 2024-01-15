#include <iostream>
#include <iterator>
#include <map>

using namespace std;
int main(){
    map<int, map<int, int>m;

    map<int, map<int, int> >::iterator itr;

    map<int, int> >::iterator ptr;
        for(int i =0; i < 2; i++ ){
            for(int j = 0; j < 2; j++){
                m[i][j] = i + j;
            }
        }
        for(int i = 0; i<2; i++){
            for (int j = 0; j < 2, j++)
        }
        for (int i = 0; i< 2; i++){
            for(int j = 0; j < 2; j++){
                cout<<"First Key is"<< i
                    <<"And second key is" <<j
                    <<"And value is"<<m[i][j]<< endl;
            }
        }

}
    cout<<"\n Now accesssing map though iterator\n\n";