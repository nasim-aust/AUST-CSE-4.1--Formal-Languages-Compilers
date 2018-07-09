//assignment-1
///MD Abdullah Al Nasim
#include <stdio.h>
int main()
{
    FILE *p1,*p2;
    char c;

    char *in = "input.c";
    char *out1 = "output1.txt";
    char *out2 = "output2.txt";
    char *out3 = "output3.txt";
    char *out4 = "output4.txt";

    //Remove single line comment
    p1 = fopen(in, "r");
    p2 = fopen(out1,"w");
    if(!p1) printf("\nFile can't be opened!");
    else
    {
        while((c = fgetc(p1)) != EOF)
        {
            if (c == '/')
            {
                c = fgetc(p1);
                if(c == '/') while(c!='\n') c = fgetc(p1);
                else
                {
                    fputc('/', p2);
                    fputc(c, p2);
                }
            }
            else fputc(c, p2);
        }
    }
    fclose(p1);
    fclose(p2);

    //Remove multiple comment
    p1 = fopen(out1, "r");
    p2 = fopen(out2,"w");
    if(!p1) printf("\nFile can't be opened!");
    else
    {
        while((c = fgetc(p1)) != EOF)
        {
            if (c == '/')
            {
                c = fgetc(p1);
                if(c == '*')
                {
                    do{
                        c = fgetc(p1);
                    }while(c != '*');
                    c = fgetc(p1);
                }
                else fputc(c, p2);
            }
            else fputc(c, p2);
        }
    }
    fclose(p1);
    fclose(p2);

    //Remove white space
    p1 = fopen(out2, "r");
    p2 = fopen(out3,"w");
    if(!p1) printf("\nFile can't be opened!");
    else
    {
        while((c = fgetc(p1)) != EOF)
        {
            if (c == ' ')
            {
                while(c == ' ') c = fgetc(p1);
                fputc(' ', p2);
                fputc(c, p2);
            }
            else fputc(c, p2);
        }
    }
    fclose(p1);
    fclose(p2);

    //Replace newline with single white space
    p1 = fopen(out3, "r");
    p2 = fopen(out4,"w");
    if(!p1) printf("\nFile can't be opened!");
    else
    {
        while((c = fgetc(p1)) != EOF)
        {
            if (c == '\n') fputc(' ', p2);
            else fputc(c, p2);
        }
    }
    fclose(p1);
    fclose(p2);

    //Final Output
    p1 = fopen(out4,"r");
    while((c=fgetc(p1))!=EOF) printf("%c",c);
    fclose(p1);

    return 0;
}
