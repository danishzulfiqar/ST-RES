#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *str;
    int i,j,k,v=0,n=0,s=0;
    char vowel[20]="aeiouAEIOU";
    char integers[15]="0123456789";

    str=(char*)calloc(20,sizeof(char));

    if(str == NULL)
    {
        printf("NO space allocated\n");
        exit(1);
    }

    printf("Enter a string\n");
    gets(str);

    while(str[i] != '\0')
    {
        j=0;

        while(vowel[j] != '\0')
        {
            if(str[i] == vowel[j])
            {
                v=v+1;
            }

            j++;
        }

        i++;
    }

    i=0;

     while(str[i] != '\0')
    {
        j=0;

        while(integers[j] != '\0')
        {
            if(str[i] == integers[j])
            {
                n=n+1;
            }

            j++;
        }

        i++;
    }

    i=0;

    while(str[i] != '\0')
    {
        if(str[i] == ' ')
        {
          s=s+1;
        }

        i++;
    }


    printf("\nThe number of vowels are %d\n", v);
    printf("\nThe number of integers are %d\n", n);
    printf("\nThe number of spaces are %d\n", s);

    free(str);

    return 0;
}
