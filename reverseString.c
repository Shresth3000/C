#include<stdio.h>
void main(){
    char str[100];
    char *ptr=str;
    puts("Enter a string: ");
    gets(ptr);
    int l=0;
    while(*(ptr+l)!='\0'){
        l++;
    }
    for(int i=l-1;i>=0;i--){
        printf("%c",*(ptr+i));
    }
}