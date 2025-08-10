#include<stdio.h>
#include<stdlib.h>
struct student{
    int roll;
    float cgpa;
    char gender;
    char name[100];
};

int main(){
    int n;
    printf("Enter number of students: ");
    scanf("%d",&n);

    struct student *ptr=(struct student*)malloc(n*sizeof(struct student));
    printf("Enter student data: \n");
    for(int i=0;i<n;i++){
    printf("Enter name: ");
    scanf("%s",(ptr+i)->name);
    printf("Enter roll no: ");
    scanf("%d",&(ptr+i)->roll);
    printf("Enter gpa: ");
    scanf("%f",&(ptr+i)->cgpa);
    printf("Enter gender: ");
    scanf(" %c",&(ptr+i)->gender);
    }

    for(int i=0;i<n;i++){
        printf("Roll no : %d\n",(ptr+i)->roll);
        printf("Name : %s\n",(ptr+i)->name);
        printf("CGPA :  %0.2f\n",(ptr+i)->cgpa);
        printf("Gender :  %c\n",(ptr+i)->gender);

    }
    return 0;
}