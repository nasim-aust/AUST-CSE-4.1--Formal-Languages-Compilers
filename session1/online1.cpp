#include<bits/stdc++.h>
using namespace std;

int main()
{
    FILE *fp1, *fp2;
    char c;
    char *input = "input.c";
    char *output = "output.txt";

    fp1 = fopen(input, "r");
    fp2 = fopen(output, "w");

    if(!fp1)printf("File can't be found");
    else
    {
        while((c = fgetc(fp1)) != EOF)
        {
            if(c == '<')
            {
                while(c != '>')
                {
                    c = fgetc(fp1);
                    if(c != '>') fputc(c, fp2);
                }
            }
        }
    }
    fclose(fp1);
    fclose(fp2);

    fp2 = fopen(output, "r");
    //while((c=fgetc(fp2)) != EOF) printf("%c", c);
    while((c=fgetc(fp2)) != EOF) cout << c;
    fclose(fp2);

    return 0;
}
