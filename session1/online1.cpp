//1.Write a program to print the header files used in a source program.
#include<bits/stdc++.h>
using namespace std;

int main()
{
    FILE *p1, *p2;
    char c;

    p1 = fopen("input.c", "r");
    p2 = fopen("output.txt", "w");

    if(!p1)printf("File can't be found");
    else
    {
        while((c = fgetc(p1)) != EOF)
        {
            if(c == '<')
            {
                while(c != '>')
                {
                    c = fgetc(p1);
                    if(c != '>') fputc(c, p2);
                }
                fputc('\n',p2);
            }
        }
    }
    fclose(p1);
    fclose(p2);

    p2 = fopen("output.txt", "r");
    //while((c=fgetc(fp2)) != EOF) printf("%c", c);
    while((c=fgetc(p2)) != EOF) cout << c;
    fclose(p2);

    return 0;
}
