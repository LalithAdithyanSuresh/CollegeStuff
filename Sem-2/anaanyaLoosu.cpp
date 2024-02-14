#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define size 10
class list
{
    private:
       int current=-1;
       int i;
       int array[size];
    public:
       int empty()
       {
        if (current==-1)
        {
            return 1;
        }
        return 0;
       }
       int full()
       {
        if(current==size-1)
        {
            return 1;
        }
        return 0;
        }
        int insatbeg(int value)
        {
            if(full()==0)
            {
                for(i=current;i>-1;i--)
                {
                    array[i+1]=array[i];
                }
                array[0]=value;
                current++;
                return 1;
            }
            return 0;
        }
        int insatend(int value)
        {
            if(full()==0)
            {
                array[current+1]=value;
                current++;
                return 1;
            }
            return 0;
        }
        int insatpos(int value,int pos)
        {
            if(full()==0)
            {
                if(pos<=current)
                {
                    for(i=current;i>=pos;i--)
                    {
                        array[i+1]=array[i];
                    }
                    array[pos]=value;
                    current++;
                    return 0;
                }
                return -1;
            }
            return 0;
        }
        void display()
        {
            printf("\n[");
            if(empty()==0)
            {
                for(i=0;i<current+1;i++)
                {
                    printf("%d,",array[i]);
                }
            }
            printf("]");
        }
        int delatbeg()
        {
            if(empty()==0)
            {
                for(i=1;i<=current;i++)
                {
                    array[i-1]=array[i];
                }
                current--;
                return 1;
            }
            return 0;
        }
        int delatpos(int pos)
        {
            if(empty()==0)
            {
                for(i=pos+1;i<=current;i++)
                {
                    array[i-1]=array[i];
                }
                current--;
                return 1;
            }
            return 0;
        }
        int delatend()
        {
            if(empty()==0)
            {
                current--;
                return 1;
            }
            return 0;
        }
        int search(int value)
        {
            if(empty()==0)
            {
                for (i=0;i<current;i++)
                {
                    if(array[i]==value)
                    {
                        return i;
                    }
                }
            }
            return -1;
        }
};
int main()
{
    list a;
    int choice,choice1,choice2,val,pos,val1,posi;
    while(true)
    {
        printf("\nMENU");
        printf("\n1.INSERTION");
        printf("\n2.DELETION");
        printf("\n3.SEARCHING");
        printf("\n4.DISPLAY");
        printf("\n5.EXIT");
        printf("\n\n");
        printf("Enter the choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case(1):
        {
            printf("\nMENU");
            printf("\n1.At the beginning");
            printf("\n2.At a position");
            printf("\n3.At the end");
            printf("\nEnter the choice:");
            scanf("%d",&choice1);
            switch (choice1)
            {
                case(1):
                {
                    printf("\nEnter the value to be inserted");
                    scanf("%d",&val);
                    if (a.insatbeg(val)==1)
                    {
                        printf("\nThe element has been successfully installed");
                    }
                    else
                    {
                        printf("\nThe list is full");
                    }
                    break;
                }
                case(2):
                {
                    printf("\nEnter the value to be inserted");
                    scanf("%d",&val);
                    printf("\nEnter the position to be inserted:");
                    scanf("%d",&pos);
                    if (a.insatpos(val,pos)==1)
                    {
                        printf("\nThe element has been successfully installed");
                    }
                    else if(a.insatpos(val,pos)==-1)
                    {
                        printf("\nThe postion is greater than the current index so cannot be inserted.");
                    }
                    else if(a.insatpos(val,pos)==0)
                    {
                        printf("\nThe list is full");
                    }
                    break;
                }
                case(3):
                {
                    printf("\nEnter the value to be inserted");
                    scanf("%d",&val);
                    if (a.insatend(val)==1)
                    {
                        printf("\nThe element has been successfully installed");
                    }
                    else
                    {
                        printf("\nThe list is full");
                    }
                    break;
                }
            }
            break;
        }
        case 2:
        {
            printf("\nMENU");
            printf("\n1.At beginning");
            printf("\n2.At a position");
            printf("\n3.At end");
            printf("\nEnter the choice:");
            scanf("%d",&choice2);
            switch(choice2)
            {
                case 1:
                {
                    if(a.delatbeg()==1)
                    {
                        printf("\nDeleted successfully");
                    }
                    else
                    {
                        printf("\nThe list is empty");
                    }
                    break;
                }
                case 2:
                {
                    printf("\nEnter the position to be deleted:");
                    scanf("%d",&posi);
                    if(a.delatpos(posi)==1)
                    {
                        printf("\nDeleted successfully");
                    }
                    else
                    {
                        printf("\nThe lsit is empty");
                    }
                    break;
                }
                case 3:
                {
                    if(a.delatend()==1)
                    {
                        printf("\nDeleted successfully");
                    }
                    else
                    {
                        printf("The list is empty");
                    }
                    break;
                }
            }
            break;
        }
        case 3:
        {
            printf("Enter the value to be searched:");
            scanf("%d",&val1);
            if(a.search(val1)==-1)
            {
                printf("The list is empty");
            }
            else
            {
                printf("The value is found at %d position",a.search(val1));
            }
            break;
        }
        case 4:
        {
            printf("The values of the list:");
            a.display();
            break;
        }
        case 5:
        {
            return 0;
        }
        default:
        {
            printf("Invalid choice");
            break;
        }
    }
    }
}