#include <iostream>
using namespace std;

struct book_t{
    char title[50]="C++ programming";
    char author[50]="Bjarne Stoustrup";
    union{
        int dollars;
        int yen;
    };
    
} book2;

int main(){
    cout<"Book Title"<<book2.title<<endl;
    cout<<"Book Author"<<book2.author<<endl;
    cout<<"Price in dollars"<<book2.dollars<<endl;
    cout<<"Price in yen"<<book2.yen<<endl;

    return 0;

}