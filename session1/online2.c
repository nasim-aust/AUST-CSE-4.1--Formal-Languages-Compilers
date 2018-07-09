//2.Write a program to add line numbers to a source program.
#include<stdio.h>
int main()
{
    FILE *p1, *p2;
    char c;
    int line_no=1;

    p1 = fopen("input.c", "r");
    p2 = fopen("output.txt", "w");

    printf("%d:",line_no);
    fprintf(p2,"%d:",line_no);

    if(!p1)printf("File can't be found");
    else
    {
        while((c = fgetc(p1)) != EOF)
        {
            printf("%c", c);
            fputc(c, p2);

            if(c == '\n')
            {
                line_no++;
                printf("%d:",line_no);
                fprintf(p2,"%d:",line_no);
            }
        }
    }

    fclose(p1);
    fclose(p2);

    return 0;
}
