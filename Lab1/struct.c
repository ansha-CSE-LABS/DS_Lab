#include <stdio.h>

struct student{
    int id;
    int age;
    int marks;
};
void accept_input(struct student* s1){
    printf("Enter the id : ");
    scanf("%d",&s1->id);
    printf("Enter the age : ");
    scanf("%d",&s1->age);
    printf("Enter the marks : ");
    scanf("%d",&s1->marks);
}
void display_output(struct student s1){
    printf("\nStudent details are : \n");
    printf("Id - %d\t",s1.id);
    printf("Age - %d\t",s1.age);
    printf("Marks - %d\n",s1.marks);
}
int main(){
    int num,i;
    printf("Enter the number of students : ");
    scanf("%d",&num);
    struct student s[num];
    for(i=0;i<num;i++){
        accept_input(&s[i]);//passing the memory address of structure element
    }
    for(i=0;i<num;i++){
        display_output(s[i]);
    }
    return 0;
}
