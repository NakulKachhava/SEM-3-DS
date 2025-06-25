#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Student {
    char name[20];
    int roll_no;
    char branch[20];
    int batch_no;
};
int main(){
    struct Student *student1 = (struct Student*)malloc(sizeof(struct Student));
    strcpy(student1->name,"Nakul");
    student1->roll_no = 115;
    strcpy(student1->branch,"CSE");
    student1->batch_no = 1;
    printf("Name - ",student1->name);
    printf("Name - ",student1->roll_no);
    printf("Name - ",student1->branch);
    printf("Name - ",student1->batch_no);
    return 0;
}