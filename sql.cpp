#include<stdlib.h>
#include <stdio.h>
void create();
void insert_end();
void insert_position();
void delete_end();
void delete_position();
void delete_que();
void Insert_que(int val);
void displayque();
void displaystack();
void insert_stack(int val);
void delete_stack() ;
struct node
{
        char info;
        struct node *next;
};
struct node *start=NULL;
int main()     
{
        int choice;
        while(1){
               
                printf("               MENU                             ");
                printf(" 1.Create     ");
                printf(" 2.Insert at the end  ");
                printf(" 3.Insert at specified position       ");
                printf(" 4.Delete from the end        ");
                printf(" 5.Delete from specified position     ");
                printf(" 6.Exit       ");
                printf("Enter your choice:");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                                        create();
                                        break;
                        case 2:
                                        insert_end();
                                        break;
                        case 3:
                                        insert_position();
                                        break;
                        case 4:
                                        delete_end();
                                        break;
                        case 5:
                                        delete_position();
                                        break;
                        case 6:
                                        exit(0);
                                        break; 
                        default:
                                        printf("Wrong Choice:");
                                        break;
                }
        }
        return 0;
}
void create()
{
        struct node *temp,*ptr;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("Out of Memory Space:");
                exit(0);
        }
        printf("Enter the data value for the node:");
        scanf("%d",&temp->info);
        temp->next=NULL;
        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                ptr=start;
                while(ptr->next!=NULL)
                {
                        ptr=ptr->next;
                }
                ptr->next=temp;
        }
        if(start==NULL)
        {
                printf("List is empty:");
                return;
        }
        else
        {
                ptr=start;
                printf("The List elements are:");
                while(ptr!=NULL)
                {
                        printf("%d ->",ptr->info );
                        ptr=ptr->next ;
                }
}
        
}
void insert_begin()
{
        struct node *temp, *ptr;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("Out of Memory Space:");
                return;
        }
        printf("Enter the data value for the node:" );
        scanf("%d",&temp->info);
        temp->next =NULL;
        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                temp->next=start;
                start=temp;
        }
        if(start==NULL)
        {
                printf("List is empty:");
                return;
        }
        else
        {
                ptr=start;
                printf("The List elements are:");
                while(ptr!=NULL)
                {
                        printf("%d ->",ptr->info );
                        ptr=ptr->next ;
                }
}
}
void insert_end()
{
        struct node *temp,*ptr;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("Out of Memory Space:");
                return;
        }
        printf("Enter the data value for the node:" );
        scanf("%d",&temp->info );
        temp->next =NULL;
        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                ptr=start;
                while(ptr->next !=NULL)
                {
                        ptr=ptr->next ;
                }
                ptr->next =temp;
        }
        if(start==NULL)
        {
                printf("List is empty:");
                return;
        }
        else
        {
                ptr=start;
                printf("The List elements are:");
                while(ptr!=NULL)
                {
                        printf("%d ->",ptr->info );
                        ptr=ptr->next ;
                }
}
}
void insert_position()
{
        struct node *ptr,*temp;
        int i,pos;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("Out of Memory Space:");
                return;
        }
        printf("Enter the position for the new node to be inserted:");
        scanf("%d",&pos);
        printf("Enter the data value of the node:");
        scanf("%d",&temp->info) ;
  
        temp->next=NULL;
        if(pos==0)
        {
                temp->next=start;
                start=temp;
        }
        else
        {
                for(i=0,ptr=start;i<pos-1;i++) { 
                        ptr=ptr->next;                        
                        if(ptr==NULL)
                        {
                                printf("Position not found:");
                                return;
                        }
                }
                temp->next =ptr->next ;
                ptr->next=temp;
        }
        if(start==NULL)
        {
                printf("List is empty:");
                return;
        }
        else
        {
                ptr=start;
                printf("The List elements are:");
                while(ptr!=NULL)
                {
                        printf("%d ->",ptr->info );
                        ptr=ptr->next ;
                }
}
}
void delete_begin()
{
        struct node *ptr;
        if(start==NULL)
        {
                printf("List is Empty:");
                return;
        }
        else
        {
                ptr=start;
                start=start->next ;
                printf("The deleted element is :",ptr->info);
                free(ptr);
        }
        if(start==NULL)
        {
                printf("List is empty:");
                return;
        }
        else
        {
                ptr=start;
                printf("The List elements are:");
                while(ptr!=NULL)
                {
                        printf("%d ->",ptr->info );
                        ptr=ptr->next ;
                }
}
}
void delete_end()
{
        struct node *temp,*ptr;
        if(start==NULL)
        {
                printf("List is Empty:");
                exit(0);
        }
        else if(start->next ==NULL)
        {
                ptr=start;
                start=NULL;
                printf("The deleted element is:",ptr->info);
                free(ptr);
        }
        else
        {
                ptr=start;
                while(ptr->next!=NULL)
                {
                        temp=ptr;
                        ptr=ptr->next;
                }
                temp->next=NULL;
                printf("The deleted element is:",ptr->info);
                free(ptr);
        }
        if(start==NULL)
        {
                printf("List is empty:");
                return;
        }
        else
        {
                ptr=start;
                printf("The List elements are:");
                while(ptr!=NULL)
                {
                        printf("%d ->",ptr->info );
                        ptr=ptr->next ;
                }
}
}
void delete_position()
{
        int i,pos;
        struct node *temp,*ptr;
        if(start==NULL)
        {
                printf("The List is Empty:");
                exit(0);
        }
        else
        {
                printf("Enter the position of the node to be deleted:");
                scanf("%d",&pos);
                if(pos==0)
                {
                        ptr=start;
                        start=start->next ;
                        printf("The deleted element is:",ptr->info  );
                        free(ptr);
                }
                else
                {
                        ptr=start;
                        for(i=0;i<pos;i++) { temp=ptr; ptr=ptr->next ;
                                if(ptr==NULL)
                                {
                                        printf("Position not Found:");
                                        return;
                                }
                        }
                        temp->next =ptr->next ;
                        printf("The deleted element is:",ptr->info );
                        free(ptr);
                }
        }
        if(start==NULL)
        {
                printf("List is empty:");
                return;
        }
        else
        {
                ptr=start;
                printf("The List elements are:");
                while(ptr!=NULL)
                {
                        printf("%d ->",ptr->info );
                        ptr=ptr->next ;
                }
}
}


//Queue


struct node* front = NULL;
struct node* rear = NULL;
struct node* temp;
void displayque() {
    temp = front;
    if ((front == NULL) && (rear == NULL)) {
        printf("Queue is empty");
        return;
        }
    while (temp != NULL) {
        printf("%d->",temp->info);
        temp = temp->next;
        }
    }
void Insert_que(int val) {
    if (rear == NULL) {
        rear = new node;
        rear->next = NULL;
        rear->info = val;
        front = rear;
        } 
    else {
        temp=new node;
        rear->next = temp;
        temp->info = val;
        temp->next = NULL;
        rear = temp;
        }
        displayque();
    }
void delete_que() {
    temp = front;
    if (front == NULL) {
        printf("Queue is empty!!"); 
        } 
    else if (temp->next != NULL) {
        temp = temp->next;
        printf("Element deleted from queue is : ",front->info);
        free(front);
        front = temp;}
    else {
        printf("Element deleted from queue is : ",front->info);
        free(front);
        front = NULL;
        rear = NULL;
        }
        displayque();
    }

//stack


struct node* top = NULL;
void displaystack() {
   struct node* ptr;
   if(top==NULL)
   printf("stack is empty");
   else {
      ptr = top;
      printf("Stack elements are: ");
      while (ptr != NULL) {
        printf("%d->",ptr->info);
        ptr = ptr->next;
      }
   }
}
void insert_stack(int val) {
   struct node* newnode = (struct node*) malloc(sizeof(struct node));
   newnode->info = val;
   newnode->next = top;
   top = newnode;
   displaystack();
        }
void delete_stack() {
   if(top==NULL)
   printf("Stack Underflow");
   else {
      printf("The popped element is ",top->info);
      top = top->next;
   }
   displaystack();
}