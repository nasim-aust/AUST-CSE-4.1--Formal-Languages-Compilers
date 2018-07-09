#include<stdio.h>

int main()
{
    FILE *fp1, *fp2;
    char c;
    char *input = "input.c";
    char *output = "output.txt";
    int line_no=1;

    fp1 = fopen(input, "r");
    fp2 = fopen(output, "w");

    printf("%d:",line_no);
    fprintf(fp2,"%d:",line_no);

    if(!fp1)printf("File can't be found");
    else
    {
        while((c = fgetc(fp1)) != EOF)
        {
            printf("%c", c);
            fputc(c, fp2);

            if(c == '\n')
            {
                line_no++;
                printf("%d:",line_no);
                fprintf(fp2,"%d:",line_no);
            }
        }
    }

    fclose(fp1);
    fclose(fp2);

    return 0;
}
