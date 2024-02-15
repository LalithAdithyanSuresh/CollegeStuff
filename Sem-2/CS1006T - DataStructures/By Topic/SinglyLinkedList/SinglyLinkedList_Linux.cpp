
#include <stdio.h>
#include <stdlib.h>

class List{
    private:
        struct Node{
            int data;
            struct Node *Next;
        };
        struct Node *Head;
        struct Node *CurrentPoint;
        struct Node *NewNode;
    public:
        List(){
            Head = nullptr;
        }
        struct Node *CreateNode();
        void DeleteNode(struct Node *);
        int IsEmpty();
        int Insert_Beg_Node(int);
        int Append_Node(int);
        int Insert_Pos_Node(int,int);
        int Delete_Beg_Node();
        int Pop_Node();
        int Delete_Pos_Node(int);
        int SearchNode(int);
        void Display();
        void recursiveDisp(struct Node *);
        void Rev_Display();
        void recursiveRev(struct Node *);
        void Rev_Nodes();
};



int main(){

    List NewList;
    int opt,var,pos,variable;
    while(1==1){
        system("clear");
        printf("\n-------------------------------------------------\nOptions : \n\t0-Exit\n\t1-Insert At Beginning\n\t2-Appending\n\t3-Insertion\n\t4-Delete beginning\n\t5-Pop\n\t6-Deletetion\n\t7-Search\n\t8-Display\n\t9-Reverse Display\n\t10-Reverse\n>>> ");
        scanf("%d",&opt);
        system("clear");
        switch (opt)
        {
        case 0:
            return 0;
        case 1:
            printf("\nValue : ");
            scanf("%d",&var);
            if(NewList.Insert_Beg_Node(var)==1){
                printf("\nInserted Successful");
            }else{
                printf("\nList is Full : ");
            }
            break;
        case 2:
            printf("Value to append :  ");
            scanf("%d",&var);
            if(NewList.Append_Node(var)==1){
                printf("\nInserted Successful");
            }else{
                printf("\nList is Full :(");
            }
            break;
        case 3:
            printf("Value to Insert :  ");
            scanf("%d",&var);
            printf("Position to Insert :  ");
            scanf("%d",&pos);
            variable = NewList.Insert_Pos_Node(var,pos);
            if(variable==1){
                printf("\nInserted Successful");
            }else if(variable==0){
                printf("\nList is Full :(");
            }else{
                printf("Invalid Position");
            }
            break;
        case 4:
            if(NewList.Delete_Beg_Node()==1){
                printf("\nDeleted Successfully");
            }else{
                printf("\nList is Empty :(");
            }
            break;
        case 5:
            if(NewList.Pop_Node()==1){
                printf("\nPopped Successfully");
            }else{
                printf("\nList is Empty :(");
            }
            break;
        case 6:
            printf("Position to Remove :  ");
            scanf("%d",&pos);
            if(NewList.Delete_Pos_Node(pos)==1){
                printf("\nDeleted Successfully");
            }else{
                printf("\nList is Empty :(");
            }
            break;
        case 7:
            printf("Element to search :  ");
            scanf("%d",&var);
            pos = NewList.SearchNode(var);
            if(pos!=-1){
                printf("\nFound Element In index :%d",pos);
            }else{
                printf("\nElement Not Found in List");
            }
            break;
        case 8:
            printf("Values in List : ");
            NewList.Display();
            break;
        case 9:
            printf("Printing Reverse Display : ");
            NewList.Rev_Display();
            break;
        case 10:
            printf("Reversin list");
            NewList.Rev_Nodes();
            break;
        default:
            printf("Invalid Choise\n");
            break;
        }
        printf("\n\n(Press ENTER key to continue)");
        getchar();
        getchar();
    }
}





// Create New Node And return Pointer
struct List::Node * List::CreateNode(){
    return (struct Node *)malloc(sizeof(struct Node));
}

// Delete and free memoryof the Node
void List::DeleteNode(struct Node *del){
    free(del);
}

// Check if the List is empty
int List::IsEmpty(){
    if (Head==nullptr){
        return 1;
    }else{
        return 0;
    }
    
}

// Insert a New Node in the beginning
int List::Insert_Beg_Node(int val){
    NewNode = CreateNode();
    NewNode->data = val;
    NewNode->Next = Head;
    Head = NewNode;
    return 1;
}

// Add a new node to the end
int List::Append_Node(int val){
    if(IsEmpty()==0){
        CurrentPoint = Head;
        while(CurrentPoint->Next !=nullptr){
            CurrentPoint= CurrentPoint->Next;
        }
        NewNode = CreateNode();
        NewNode->data = val;
        NewNode->Next = nullptr;
        CurrentPoint->Next = NewNode;
        return 1;
    }else{
        Insert_Beg_Node(val);
        return 1;
    }
    return 0;
}

// Insert A new Node with the given position
int List::Insert_Pos_Node(int val ,int pos){
    if(pos == 0){
        Insert_Beg_Node(val);
        return 1;
    }
    if(IsEmpty()==0){
        pos--;

        CurrentPoint = Head;
        while(pos >0){
            CurrentPoint = CurrentPoint->Next;
            pos--;
        }
        printf("%d",CurrentPoint->data);
        NewNode = CreateNode();
        NewNode->data = val;
        NewNode->Next = CurrentPoint->Next;
        CurrentPoint->Next = NewNode;
        return 1;
    }return 0;
}

// Delete the beginning Node
int List::Delete_Beg_Node(){
    if(IsEmpty()==0){
        CurrentPoint = Head;
        Head = CurrentPoint->Next;
        DeleteNode(CurrentPoint);
        return 1;

    }else{
        return 0;
    }
}

// Remove the last Node
int List::Pop_Node(){
    if(IsEmpty()==0){
        CurrentPoint = Head;
        NewNode = Head;
        while(CurrentPoint->Next != nullptr){
            NewNode = CurrentPoint;
            CurrentPoint = CurrentPoint->Next;
        }
        NewNode->Next = nullptr;
        DeleteNode(CurrentPoint);
        return 1;
    }else{
        return 0;
    }
}

// Delete the node at given index
int List::Delete_Pos_Node(int pos){
    if(pos == 0){
        Delete_Beg_Node();
        return 1;
    }
    if(IsEmpty()==0){
        CurrentPoint = Head;
        NewNode = Head;
        while((CurrentPoint->Next != nullptr) && (pos>0)){
            pos--;
            NewNode = CurrentPoint;
            CurrentPoint = CurrentPoint->Next;
        }
        if(pos>0){
            return 0;
        }else{
            NewNode->Next = CurrentPoint->Next;
            DeleteNode(CurrentPoint);
            return 1;
        }
    }
    return 0;
}

// Search the index of a given Value
int List::SearchNode(int val){
    int pos = 0;
    CurrentPoint = Head;
    if(IsEmpty()==0){
        while(CurrentPoint->data != val && CurrentPoint->Next != nullptr){
            CurrentPoint = CurrentPoint->Next;
            pos++;
        }
        if(CurrentPoint->data == val){
            return pos;
        }
        else{
            return -1;
        }
    }
    return -1;
    
}

// Display the contents of the List
void List::Display(){
    if(IsEmpty()==0){
        CurrentPoint = Head;
        printf("[");
        while(CurrentPoint->Next != nullptr){
            printf("%d,",CurrentPoint->data);
            CurrentPoint = CurrentPoint->Next;
        }
        printf("%d]",CurrentPoint->data);
    }else{
        printf("[]");
    }
}

// recursive Disp
void List::recursiveDisp(struct Node *NextNode){
    if(NextNode->Next==nullptr){
        printf("[%d,",NextNode->data);
    }else{
        int val = NextNode->data;
        recursiveDisp(NextNode->Next);
        printf("%d,",val);
    }
}

// Reverse Display the list
void List::Rev_Display(){
    if(IsEmpty()==0){
        recursiveDisp(Head->Next);
        printf("%d]",Head->data);
    }else{
        printf("[]");
    }
}

// Recursive Reverse
void List::recursiveRev(struct Node *NextNode){
    if(NextNode->Next == nullptr){
        Head = NextNode;
    }else{
        recursiveRev(NextNode->Next);
        NextNode->Next->Next = NextNode;
        NextNode->Next = nullptr;
    }
}

void List::Rev_Nodes(){
    if(IsEmpty()==0){
        recursiveRev(Head);
    }
}