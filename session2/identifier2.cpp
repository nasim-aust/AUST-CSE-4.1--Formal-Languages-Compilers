#include<bits/stdc++.h>
using namespace std;

int id_rec(char lex[50]){
	int i=0, s;
	if(isalpha(lex[0]) || lex[0]=='_'){
		s=1;
		i++;
	}
	else if(isdigit(lex[0])) return 0;
	        else s=0;

    if(strlen(lex)>1)
    {
        s=2;
    }


	if(s==2){ // s = 1 (q)
    for(i=0;i<strlen(lex);i++){
		if(isalpha(lex[i]) || lex[i]=='_' || isdigit(lex[i]) )
            s=2;

        else{
            s=0;
            break;
			}
		}
    }





	if(s==1)
       return 1;
    if(s==2)
       return 1;
    else
        return 0;

}



int main()
{

    char id[50] ;
    int i=0;

    printf("Enter a Identifier: ");
    cin>>id;

    if(id[i]=='\0')
    {
        printf("Invalid Input!!!");
    }

    else
    {

        if(id_rec(id))
            printf("Valid Identifier!");
        else
            printf("Invalid Identifier!");
    }

    //getch();
    return 0;
}



