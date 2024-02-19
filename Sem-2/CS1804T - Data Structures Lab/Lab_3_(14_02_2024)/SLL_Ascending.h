#include <stdio.h>
#include <stdlib.h>

class List{
    private:
        struct Node{
            int data;
            struct Node *Next;
        };
        struct Node *CurrentPoint;
        struct Node *PrevPoint;
        struct Node *NewNode;
    public:
        struct Node *Head;
        List(){
            Head = nullptr;
        }
        struct Node * CreateNode();
        void DeleteNode(struct Node *);
        int IsEmpty();
        int Insert_Beg_Node(int);
        int Insert_asc(int);
        List Merge(List *);
        void Display();
};

struct List::Node * List::CreateNode(){
    return (struct Node *)malloc(sizeof(struct Node));
}
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


// Insert Ascending
int List::Insert_asc(int val){
    if(IsEmpty()==0){
        if(Head->data >= val){
            Insert_Beg_Node(val);
            return 1;
        }
        CurrentPoint = Head;
        PrevPoint = CurrentPoint;
        while(CurrentPoint->Next != nullptr){
            PrevPoint = CurrentPoint;
            CurrentPoint = CurrentPoint->Next;
            if(CurrentPoint->data >= val){
                NewNode = CreateNode();
                NewNode->data = val;
                NewNode->Next = PrevPoint->Next;
                PrevPoint->Next = NewNode;
                return 1;
            }
        }
        NewNode = CreateNode();
        NewNode->data = val;
        NewNode->Next = CurrentPoint->Next;
        CurrentPoint->Next = NewNode;
        return 1;
        
        return 1;
    }else{
        Insert_Beg_Node(val);
        return 1;
    }
}  

// Merge in Ascending
List List::Merge(List *other){
    List NewL;
    struct Node *Cur;
    struct Node *Oth;
    struct Node *New;
    Cur = Head;
    Oth = other->Head;
    New = NewL.Head;
    while(Cur!=nullptr || Oth!=nullptr){
        if(Cur == nullptr || Cur->data >= Oth->data){
            NewNode = CreateNode();
            NewNode->data = Oth->data;
            Oth = Oth->Next;
        }else{
            NewNode = CreateNode();
            NewNode->data = Cur->data;
            Cur = Cur->Next;
        }
        NewNode->Next = nullptr;
        if(New == nullptr){
            NewL.Head = NewNode;
            New = NewL.Head;
        }else{
            New->Next = NewNode;
            New = New->Next;
        }
    }
    return NewL;


}
// Display
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