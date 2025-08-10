#include <stdio.h>
void main()
{
    char str[100];
    char *ptr = str;
    char *ptr2 = str;
    puts("Enter a string: ");
    gets(ptr);

    while (*(ptr2) != '\0')
    {
        ptr2++;
    }
    ptr2--;

    for (char *i = ptr2; i >= ptr; i--)
    {
        printf("%c", *i);
    }
}