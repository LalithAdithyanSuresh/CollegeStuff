#include<stdlib.h>

class Queue{
    private:
        struct Node{
            int A_time;
            int B_time;
            int P_Num;
            struct Node *Next;
        };
        struct Node *Head;
        struct Node *Tail;
        struct Node *NewNode;
    
    public:
        Queue(){
            Head = nullptr;
            Tail = nullptr;
        }
        struct Node * CreateNode();
        int enqueue(int,int,int);
        struct Node * dequeue();
        int peek(); 
};


//Method to create a new mnode
struct Queue::Node * Queue::CreateNode(){
    return (struct Node *)malloc(sizeof(struct Node));
}

// Method to Enqueue an element to the queue
// Time Complexity : O(1)
int Queue::enqueue(int a,int b,int p){
    NewNode = CreateNode();
    NewNode->A_time = a;
    NewNode->B_time = b;
    NewNode->P_Num = p;
    NewNode->Next = nullptr;
    if(Head==nullptr){
        Head = NewNode;
    }else{
        Tail->Next = NewNode;
    }
    Tail = NewNode;
    Tail->Next = Head;
    return 1;
}

// Method to Dequeue an element form the queue
// Time Complexity : O(1)
struct Queue::Node * Queue::dequeue(){
    if(Head == nullptr){
        return nullptr;
    }else if(Head==Tail){
        NewNode = Head;
        Head = nullptr;
        Tail = nullptr;
        return NewNode;
    }else{
        NewNode = Head;
        Head = Head->Next;
        Tail->Next = Head;
        return NewNode;
    }
}

// Method to return the element at the front of the queue
// Time Complexity : O(1)
int Queue::peek(){
    if(Head==nullptr){
        return -1;
    }else{
        return Head->A_time;
    }
}