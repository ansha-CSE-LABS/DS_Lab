#include<stdio.h>
#include<stdlib.h>

struct node{
    int coeff;
    int exp;
    struct node *next;
};
typedef struct node* NODE;
NODE head=NULL;

NODE insert(NODE head, int c, int e){
    NODE temp;
    NODE p=(NODE)malloc(sizeof(struct node));
    p->coeff=c;
    p->exp=e;
    p->next=NULL;

    if(head==NULL || e > head->exp){
        p->next=head;
        head=p;
    }
    else{
        temp=head;
        while(temp->next!=NULL && temp->next->exp>e){
            temp=temp->next;
        }
        p->next=temp->next;
        temp->next=p;
    }
    return head;
}
NODE create(NODE head){
    int n;
    printf("Enter no. of terms:");
    scanf("%d",&n);
    int c,e;
    for(int i=0;i<n;i++){
        printf("Enter the coefficient of term %d :",i+1);
        scanf("%d",&c);
        printf("Enter the exponent of term %d :",i+1);
        scanf("%d",&e);
        head=insert(head,c,e);
    }
    return head;
}
void print(NODE head){
    if(head==NULL)
        printf("No polynomial found");
    else{
        NODE temp=head;
        while(temp!=NULL)
        {
            printf("(%d^%d)",temp->coeff,temp->exp);
            temp=temp->next;
            if(temp!=NULL)
                printf(" + ");
            else
                printf("\n");
        }
    }
}
void polyadd(NODE head1,NODE head2)
{
    NODE ptr1=head1;
    NODE ptr2=head2;
    NODE head3=NULL;

    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->exp ==ptr2->exp){
            head3=insert(head3,ptr1->coeff+ptr2->coeff,ptr1->exp);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        else if(ptr1->exp > ptr2->exp){
            head3=insert(head3,ptr1->coeff,ptr1->exp);
            ptr1=ptr1->next;
        }
        else if(ptr1->exp < ptr2->exp){
            head3=insert(head3,ptr2->coeff,ptr2->exp);
            ptr2=ptr2->next;
        }
    }
    while(ptr1!=NULL){
        head3=insert(head3,ptr1->coeff,ptr1->exp);
        ptr1=ptr1->next;
    }
    while(ptr2!=NULL){
        head3=insert(head3,ptr2->coeff,ptr2->exp);
        ptr2=ptr2->next;
    }
    printf("Added polynomial is :");
    print(head3);
}
int main(void){
    NODE head1, head2;
    printf("enter first polynomial\n");
    head1=create(head);
    printf("enter second polynomial\n");
    head2=create(head);

    polyadd(head1,head2);
}
