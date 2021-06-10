#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

void *create();
void insert_begin(node**);
void insert_end(node**);
void delete_begin(node**);
void delete_end(node**);
void delete_before(node**);
void delete_after(node**);
void display(node*);

int main()
{
    node *start=NULL;
    printf("\tCIRCULAR LINKED LIST\n");

    int ch;
    while(1)
    printf("1. Insert_beg\n");
    printf("2. Insert_end\n");
    printf("3. deletion_beg\n");
    printf("4. deletion_end\n");
    printf("5. delete before search \n");
    printf("7. delete after search\n");
    printf("8.exit\n");
    printf("Enter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            insert_begin(&start);
            break;
        case 2:
            insert_end(&start);
            break;
        case 3:
            delete_begin(&start);
            break;
        case 4:
            delete_end(&start);
            break;
        case 5:
            delete_before(&start);
            break;
        case 6:
            delete_after(&start);
            break;
        case 7:
            display(start);
            break;
        case 8:
            system("cls");
            printf("THANK YOU\n");
            exit(1);
        default:
            printf("WRONG CHOICE\n");
    }
}

node (create)
{
    node *temp;
    temp=(node *)malloc(sizeof(struct node));
    printf("\n\n Enter new node:");
    scanf("%d",&temp->data);
    temp->next=NULL;
    return temp;
}

void insert_begin(node **start)
{
    node *ptr,*temp;
    ptr=create();
    if(*start==NULL)
    {
        *start=ptr;
        ptr->next=*start;
    }
    else
    {
        temp=*start;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=ptr;
        ptr->next=*start;
        *start=ptr;
    }
    printf("\n Node Insertion At the First succussfully");
    
}

void insert_end(node **start)
{
    node *ptr,*temp;
    ptr=create();
    if(*start==NULL)
    {
        *start=ptr;
        ptr->next=*start;
    }
    else
    {
        temp=*start;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=ptr;
        ptr->next=*start;
    }
    printf("Node Insertion At end is succussfully");
    
}

void delete_begin(node **start)
{
    node *curptr,*ptr;
    if(*start==NULL)
        printf("\n Linked List Is empty");
    else
    {
        ptr=*start;
        if(ptr->next==*start)
        *start=NULL;
        else
        {
            curptr=*start;
            while(curptr->next!=*start)
            {
                curptr=curptr->next;
            }
            curptr->next=(*start)->next;
            (*start)=(*start)->next;
        }
        free(ptr);
        printf("\n\n Delete First node succssfully");
    }
    
}

void delete_end(node **start)
{
        node *preptr,*ptr;
    if(*start==NULL)
        printf("\n Linked List Is empty");
    else
    {
        ptr=*start;
        if(ptr->next==*start)
        *start=NULL;
    else
    {
        while(ptr->next!=*start)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=*start;
    }
    free(ptr);
    printf("Delete last node succussfully");
}

void display(node **start)
{
    node *ptr;
    printf("cirxular linked list");
    if(start==NULL)
        printf("Empty");
    else
    {
        ptr=start;
        while(ptr->next!=start)
        {
            printf("%d->",ptr->data);
            ptr=ptr->next;
        }
        printf("%d",ptr->data);
        
    }
    
}
}