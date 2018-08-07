#include<bits/stdc++.h>
#include<ctype.h>
#include <string.h>
using namespace std;

int isKey(char lex[20]){
    char a[100][100]= {"int","float","void","char","long","if","else","double"};
    for(int i=0; i<8; i++){
        if(strcmp(lex,a[i])==0){
            return 1;
        }
    }
    return 0;
}


int main(void){
    FILE *p1,*p2,*p3;
    char c,d;

    p1 = fopen("input.txt","r");
    p2 = fopen("1output.txt","w");

    int flagForNewIden = 0;
    int line = 1;
    int  bracketCounterStart = 0, bracketCounterEnd = 0;
    if(!p1) printf("\nFile can't be opened!");
    else
    {
        while((c = fgetc(p1)) != EOF)
        {
            if(c=='\n')
                line++;

            if(c=='{')
                bracketCounterStart++;
            if(c=='}'){
                bracketCounterEnd++;
                if(bracketCounterStart < bracketCounterEnd)
                cout <<"Misplaced '}' at line " << line << endl;
            }

        }
    }

    fclose(p1);
    fclose(p2);

    p1 = fopen("input.txt","r");
    p2 = fopen("1output.txt","w");
    int semiBalance = 0;
    char chk[100],chk2[100];
    int  j=0;
    int ln=1;
    while((c=fgetc(p1))!=EOF)
    {
        chk[j]=c;
        j++;
        if(c=='\n')
            {ln++;

             chk[--j]=NULL;

            if(strcmp(chk,chk2)==0)
                printf("Duplicate token at line %d\n",ln);
            strcpy (chk2,chk);
            j=0;
            }
        if(c==' ')
        {

            chk[--j]=NULL;

            if(strcmp(chk,chk2)==0 )
                printf("Duplicate token %s at line %d\n",chk,ln);
            if(isKey(chk) && isKey(chk2) )
                printf("Duplicate token %s at line %d\n",chk,ln);
            strcpy (chk2,chk);
            j=0;
        }



    }

    fclose(p1);
    fclose(p2);

    p1 = fopen("input.txt","r");
    p2 = fopen("output.txt","w");


    j=0;
    ln=1;
    int ifBalance=0;
    while((c=fgetc(p1))!=EOF)
    {
        chk[j]=c;
        j++;
        if(c=='\n')
            {ln++;

            }
        if(c==' ')
        {

            chk[--j]=NULL;

            if(strcmp(chk,"if")==0) ifBalance=1;
            else if(strcmp(chk,"else")==0) ifBalance--;
            if(ifBalance<0){
                printf("Unmatched %s at line %d\n",chk,ln);
                ifBalance=0;
            }

            strcpy (chk2,chk);
            j=0;
        }
    }

    fclose(p1);
    fclose(p2);


    ///If else balance checker :
    p1 = fopen("input.txt","r");
    p2 = fopen("output.txt","w");

    ln=1;
    int ifBalance1 = 0;

    while((c=fgetc(p1))!=EOF)
    {
        chk[j]=c;
        if(c=='\n')
            ln++;
        j++;
        if(c==' ')
        {
            chk[--j]=NULL;
            if(strcmp(chk,"if")==0)
            {
                ifBalance1=1;

            }
            else if(strcmp(chk,"else")==0)
            {
                ifBalance1--;
            }

            //else if(strcmp(chk, isKey())==0) ifBalance1--;

            if(ifBalance <0)
            {
                printf("Extra ELSE detected at line %d\n",ln);
                ifBalance1=0;
            }
            strcpy (chk2,chk);
            j=0;
        }


    }
    fclose(p1);
    fclose(p2);


    return 0;
}
