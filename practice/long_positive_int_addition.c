#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
struct node
{
  int digit;
  struct node *next,*prev;
};
struct node *start1=NULL,*current1=NULL,*start2=NULL,*current2=NULL;
struct node *start=NULL,*current=NULL;
void Create(int listno, int no)
{
  struct node *newnode;
  newnode=(struct node *)malloc(sizeof(struct node));
  if(newnode==NULL)
   exit(0);
  newnode->digit=no;
  newnode->next=NULL;
  newnode->prev=NULL;
  if(listno==1)
  {
      if(start1==NULL)
      {
       start1=newnode;
       current1=newnode;
      }
      else
      {
        start1->next=newnode;
        newnode->prev=start1;
        start1=newnode;
      }
  }
  else if(listno==2)
  {
    if(start2==NULL)
    {
     start2=newnode;
     current2=newnode;
    }
    else
    {
      start2->next=newnode;
      newnode->prev=start2;
      start2=newnode;
    }
  }
}

void Addition()
{
  int carry=0;
  struct node *newnode,*temp1=start1,*temp2=start2;
  while(temp1!=NULL||temp2!=NULL)
  {

    newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL)
      exit(0);

    newnode->next=NULL;
    newnode->prev=NULL;
    if(temp1!=NULL&&temp2!=NULL)
    {
    newnode->digit=(temp1->digit)+(temp2->digit)+carry;
    carry=(newnode->digit)/10;

    newnode->digit=(newnode->digit)%10;
    temp1=temp1->prev;
    temp2=temp2->prev;
    }
    else if(temp1!=NULL)
    {
      newnode->digit=(temp1->digit)+carry;
      carry=(newnode->digit)/10;
      newnode->digit=(newnode->digit)%10;
      temp1=temp1->prev;
    }
    else if(temp2!=NULL)
    {
      newnode->digit=(temp2->digit)+carry;
      carry=(newnode->digit)/10;
      newnode->digit=(newnode->digit)%10;
      temp2=temp2->prev;
    }
    if(start==NULL)
    {
      start=newnode;
      current=newnode;
    }
    else
    {
      current->prev=newnode;
      newnode->next=current;
      current=newnode;

    }
  }
  if(carry>0)
  {
      newnode=(struct node *)malloc(sizeof(struct node));
      if(newnode==NULL)
        exit(0);

      newnode->next=NULL;
      newnode->prev=NULL;
      newnode->digit=carry;
      current->prev=newnode;
      newnode->next=current;
      current=newnode;
  }
}
void Display(int no)
{
 struct node *temp;
 if(no==1)
 {
     temp=current1;
     printf("First number: ");
 }

 else if(no==2)
 {
     temp=current2;
     printf("Second number: ");
 }

 else if(no==3)
 {
   temp=current;
   printf("Sum: ");
 }
 while(temp!=NULL)
 {
   printf("%d",temp->digit);
   temp=temp->next;
 }
 printf("\n");
}
void main()
{
  int c,no=0;
  //clrscr();
  printf("Enter first number digit by digit\n");
  printf("Enter a digit >9 or <0 to terminate.\n");
  printf("Enter the digit to be stored ");
  scanf("%d",&no);
  while(no>=0&&no<10)
  {
     Create(1,no);
     printf("Enter the digit to be stored ");
     scanf("%d",&no);
  }

  printf("Enter second number digit by digit\n");
  printf("Enter a digit >9 or <0 to terminate.\n");
  printf("Enter the digit to be stored ");
  scanf("%d",&no);
  while(no>=0&&no<10)
  {
     Create(2,no);
     printf("Enter the digit to be stored ");
     scanf("%d",&no);
  }
  Display(1);
  Display(2);
  Addition();
  Display(3);
}
