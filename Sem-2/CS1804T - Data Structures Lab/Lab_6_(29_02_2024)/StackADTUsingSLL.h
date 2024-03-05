
#include <stdio.h>
#include <stdlib.h>

class Stack{
    private:
        struct Node{
            char data;
            struct Node *Next;
        };
        struct Node *Head;
        struct Node *CurrentPoint;
        struct Node *NewNode;
    public:
        Stack(){
            Head = nullptr;
        }
        struct Node * CreateNode();
        void DeleteNode(struct Node *del);
        int IsEmpty();
        int Insert_Beg_Node(char val);
        int Delete_Beg_Node();
        char Display();
};
// Create New Node And return Pointer
struct Stack::Node * Stack::CreateNode(){
    return (struct Node *)malloc(sizeof(struct Node));
}

// Delete and free memoryof the Node
void Stack::DeleteNode(struct Node *del){
    free(del);
}

// Check if the Stack is empty
int Stack::IsEmpty(){
    if (Head==nullptr){
        return 1;
    }else{
        return 0;
    }
    
}

// Insert a New Node in the beginning
int Stack::Insert_Beg_Node(char val){
    NewNode = CreateNode();
    NewNode->data = val;
    NewNode->Next = Head;
    Head = NewNode;
    return 1;
}

// Delete the beginning Node
int Stack::Delete_Beg_Node(){
    if(IsEmpty()==0){
        CurrentPoint = Head;
        Head = CurrentPoint->Next;
        DeleteNode(CurrentPoint);
        return 1;

    }else{
        return 0;
    }
}
// Display the top of the Stack of the Stack
char Stack::Display(){
    if(IsEmpty()==0){
        return Head->data;
    }else{
        return '~';
    }
}