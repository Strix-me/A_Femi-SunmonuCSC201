#include<iostream>
using namespace std;
float num, ans, denom;

int main(){
cout<<"Handling Exceptions"<<endl;
cout<<"Enter Numerator"<<endl;
cin>>num;
cout<<"Enter Numerator"<<endl;
cin>>denom;

try{
    if(denom == 0)
        throw denom;
    else if(denom>num)
        throw "Denominator is grater than numerator";
    else{
        ans=num/denom;
        cout<<"Output :"<<ans;}
    }catch(float e){
        cout<<"Denominator is Zero";
    }
    catch (const char *St){
        cout<<"Denominator is grater than numerator";
    }
    return 0;
}
    