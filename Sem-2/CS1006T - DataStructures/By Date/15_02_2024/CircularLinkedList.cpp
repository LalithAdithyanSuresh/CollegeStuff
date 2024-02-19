#include <stdio.h>
#include <stdlib.h>

class CircularList{
    private:
        struct Node{
            int data;
            struct Node *Next;
        };
        struct Node* Head;
        struct Node* Tail;
        struct Node* NewNode;
        struct Node* CurrNode;

    public:
        CircularList(){
            Head = nullptr;
            Tail = nullptr;
        }
        struct Node * CreateNode();
        int IsEmpty();
        int Insert_beg_node(int val);
        void Display();
        
};



// Createing a new Node and returning the Pointer
struct CircularList::Node * CircularList::CreateNode(){
    return (struct Node*)malloc(sizeof(struct Node));
}

// To Check if it is empty
int CircularList::IsEmpty(){
    if(Head == nullptr){
        return 1;
    }return 0;
}

// Insert a new Node at the beginning
int CircularList::Insert_beg_node(int val){
    if(IsEmpty()==0){
        NewNode = CreateNode();
        Head =NewNode;
        NewNode->data = val;
        NewNode->Next = NewNode;
        Tail = NewNode;
        return 1;
    }else{
        NewNode = CreateNode();
        NewNode->data = val;
        NewNode->Next = Head;
        Head = NewNode;
        Tail->Next = Head;
    }
}

void CircularList::Display(){
    if(IsEmpty()==0){
        CurrNode = Head;
    }
}