#include<stdio.h>
#include<string.h>


void E(void);
void T(void);
void F(void);


char str[100];
int f=0;
int i=0;
int l;


void E()
{
    T();
    if(str[i]=='+')
    {
        i++;
        f=1;
        T();
    }
    else if(str[i]=='-')
    {
        i++;
        f=1;
        T();
    }
    else
    {
      return ;

    }
}

void T()
{
    F();
    if(str[i]=='*')
    {
        i++;
        f=1;
        F();
    }
    else if(str[i]=='/')
    {
        i++;
        f=1;
        F();
    }
    else return ;
}

void F()
{
    if(str[i]=='(')
    {
        i++;

        E();
        if(str[i]==')')
        {
            i++;

        }
    }
    else if(str[i]>='a'&&str[i]<='e')
    {
        i++;
        f=1;
        return;
    }
    else if(str[i]>='0'&&str[i]<='9')
    {
        i++;
        f=1;
        return ;
    }
}



int main(void)
{

    printf("\nEnter a string to parse: ");
    scanf("%s", str);



    l = strlen(str);
    if (l>=1)  E();
    else
        printf("\nInvalid String\n");

    if (l == i && f )
        printf("\nValid String\n");
    else
        printf("\nInvalid String\n");

    return 0;
}

