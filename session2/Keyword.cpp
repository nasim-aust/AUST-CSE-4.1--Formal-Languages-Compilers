//online 1
//Write a program to recognize whether the entered string is a keyword or not

#include<bits/stdc++.h>
using namespace std;

int id_rec(string lex)
{
    //int s=0;
    if(lex=="int" || lex=="double" || lex=="float" || lex=="string" || lex=="long" || lex=="char" || lex=="boolean") return 1;
    //if(s==1) return 1;
    else return 0;
}
int main()
{
    string id ;
    printf("Enter a Identifier: ");
    cin>>id;
    if(id=="") printf("Invalid Input!!!");
    else
    {
        if(id_rec(id)) printf("Valid Identifier!");
        else printf("Invalid Identifier!");
    }
    return 0;
}
