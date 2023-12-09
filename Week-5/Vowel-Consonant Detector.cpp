#include<iostream>
using namespace std;
int main(){
    char vowel;
    cout<<"Enter Letter"<<endl;
    cin >> vowel;
    vowel = toupper(vowel);
    if(isalpha(vowel)){
    if (vowel == 'A' && vowel == 'E'&& vowel == 'I' && vowel == 'O' && vowel == 'U'){
        cout<<" is is a Vowel"<<endl;
    }else{
            cout<<vowel<<" is is a Consonant"<<endl;
    }
    }
    else{
            cout<<vowel<<" is is not a valid letter"<<endl;
    }
       
    
    return 0;
    
}