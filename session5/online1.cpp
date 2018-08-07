#include<stdio.h>
#include<string.h>
#include<bits/stdc++.h>


void A(void);
void X(void);
char str[100];
int f=0;
int i=0;
int l;

int main(void)
{

    printf("\nCFG:\n");
    printf("\n\A -> aXd\n");
    printf("\nX -> bbX");
    printf("\nX-> bcX");
    printf("\nEnter a string to parse: ");
    scanf("%s", str);

    l = strlen(str);
    if (l>=1)  A();

    else
        printf("\nInvalid String\n");

    if (l == i && f )
        printf("\nValid String\n");
    else
        printf("\nInvalid String\n");

    return 0;
}

void A()
{
    if(str[i]=='a')
    {
        i++;

        X();

        if(str[i]=='d')
        {
            i++;
            f=1;
            return ;
        }else {
            f=0;
            return;
        }

    }
}

void X()
{
    if(str[i]=='b')
    {
        i++;
        if(str[i]=='b' ||str[i]=='c')
        {
            i++;
            f=1;
            if(i<l-1)X();
        }
        else
        {
            f=0;
            return;
        }
    }
    else
    {
        return ;
    }


}

