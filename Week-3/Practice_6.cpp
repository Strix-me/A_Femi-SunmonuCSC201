#include <iostream>
using namespace std;


int main()
{
int score;
cout <<"Please Enter Your Score";
cin >> score;
if(score>=70)
    cout <<"Grade A" << endl;
else if(score>=60)
    cout <<"Grade  " << endl;
else if(score>=50)
    cout <<"Grade C" << endl;
else if(score>=40)
    cout <<"Grade D" << endl;
else if(score>=30)
    cout <<"Grade E" << endl;
    return 0;
}