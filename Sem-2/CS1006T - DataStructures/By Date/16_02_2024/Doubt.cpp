//Program to implement list adt usig singley linked lists
#include <stdio.h>
#include <stdlib.h>

class List
{
   struct node
   {
       int data;
       struct node* next;
   };

   public:
   struct node* head;
   struct node* tail;
   List()
   {
       head=NULL;
       tail=NULL;
   }
   int insertbeg(int);
   void display();
   int insertend(int);
   int insertpos(int,int);
   int delbeg();
   int delend();
   int delpos(int);
   int search(int);
   void revdisp();
   int revlink();

};

int main()
{
   int num,pos,n,a;
   List l1;
   while (1)
   {
       printf("\nEnter\n1. Insertion in the beginning\n2. Inert in the end\n3.Insert at a position\n8. Display\n11. Exit: ");
       scanf("%d",&n);
       switch(n)
       {
           case 1:
           printf("\nEnter the number you want to insert: ");
           scanf("%d",&num);
           if (l1.insertbeg(num))
           {
               printf("\nNumber successfully inserted in the beginning.");
           }
           else
           {
               printf("\nInsertion in the begnning failed.");
           }
           break;
           
           case 2:
           printf("\nEnter the number you want to insert in the end: ");
           scanf("%d",&num);
           if (l1.insertend(num))
           {
               printf("\nInsertion at end successful.");
           }
           else
           {
               printf("Insertion failed.");
           }
           break;


           case 3:
           printf("\nEnter the positon of the number you want to insert: ");
           scanf("%d",&pos);
           printf("\nEnter the number you want to insert: ");
           scanf("%d",&num);
           if (l1.insertpos(pos,num))
           {
               printf("\nInsertion at position %d successful.",pos);
           }
           else
           {
               printf("\nInsertion at position %d failed.",pos);
           }
           break;

          
           case 8:
           printf("\nThe numbers in the list are: ");
           l1.display();
           break;
           
          

           case 11:
           printf("\nThe program is terminated.");
           exit(0);
           break;
       }
   }
}

//Method to insert a number in a specific position of the list
int List::insertpos(int pos,int num)
{
   struct node* newnode;
   newnode=(struct node*)malloc(sizeof(struct node));
   struct node* temp=head;
   int count=0;
   while(temp->next != head)
   {
       count+=1;
       temp=temp->next;
   }
       count+=1;

   if (pos<1 ||pos>count+1)
   {
       return 0;
   }
   else if (pos==1)
   {
       insertbeg(num);
       return 1;
   }
   else if (pos==count+1)
   {
       insertend(num);
       return 1;
   }
   else
   {
       temp=head;
       for (int i=2;i<pos;i++)
       {
           temp=temp->next;
       }
       newnode->data=num;
       newnode->next=temp->next;
       temp->next=newnode;
       return 1;
   }
}


//Method to display the numbers in the list
void List::display()
{
    if (head==NULL)
    {
        printf("\nThe list is empty.");
    }
    else 
    {
   struct node* temp;
   temp=head;
   do
   {
       printf("%d ",temp->data);
       temp=temp->next;
   }while ((temp!=head));
    }
}

//Method to insert a number in the beginning of the list
int List::insertbeg(int num)
{
   struct node* newnode;
   newnode=(struct node*)malloc(sizeof(struct node));
   if (head==NULL)
   {
       newnode->data=num;
       head=newnode;
       tail=newnode;
       tail->next=head;
       return 1;
   }
   else
   {
       newnode->data=num;
       newnode->next=head;
       head=newnode;
        tail->next=head;
       return 1;
   }
}
//Method to insert a number in the end of the list
int List::insertend(int num)
{
   struct node* newnode;
   newnode=(struct node*)malloc(sizeof(struct node));
   struct node* temp=head;
   if (head==NULL)
   {
       insertbeg(num);
       return 1;
   }
   else
   {
       newnode->data=num;
       tail->next=newnode;
       tail=newnode;
       tail->next=head;
       return 1;
    }
}