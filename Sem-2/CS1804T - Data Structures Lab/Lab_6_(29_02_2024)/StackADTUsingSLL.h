
#include <stdio.h>
#include <stdlib.h>

class List{
    private:
        struct Node{
            char data;
            struct Node *Next;
        };
        struct Node *Head;
        struct Node *CurrentPoint;
        struct Node *NewNode;
    public:
        List(){
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
int List::Insert_Beg_Node(char val){
    NewNode = CreateNode();
    NewNode->data = val;
    NewNode->Next = Head;
    Head = NewNode;
    return 1;
}

// Delete the beginning Node
int List::Delete_Beg_Node(){
    if(IsEmpty()==0){
        printf("POPPED Element = > %c",Head->data);
        CurrentPoint = Head;
        Head = CurrentPoint->Next;
        DeleteNode(CurrentPoint);
        return 1;

    }else{
        return 0;
    }
}
// Display the top of the list of the List
char List::Display(){
    if(IsEmpty()==0){
        return Head->data;
    }else{
        return '_';
    }
}