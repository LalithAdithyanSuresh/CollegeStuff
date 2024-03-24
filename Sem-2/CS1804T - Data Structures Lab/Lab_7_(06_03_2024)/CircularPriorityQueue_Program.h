#include<stdlib.h>

class P_Queue{
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
        struct Node *Temp;
    
    public:
        P_Queue(){
            Head = nullptr;
            Tail = nullptr;
        }
        struct Node * CreateNode();
        int enqueue(int,int,int);
        struct Node * dequeue();
        int peek(); 
};


//Method to create a new mnode
struct P_Queue::Node * P_Queue::CreateNode(){
    return (struct Node *)malloc(sizeof(struct Node));
}

// Method to Enqueue an element to the queue
// Time Complexity : O(1)
int P_Queue::enqueue(int a, int b,int p) {
    NewNode = CreateNode();
    NewNode->A_time = a;
    NewNode->B_time = b;
    NewNode->P_Num = p;
    NewNode->Next = nullptr;
    if(Head == nullptr){
        Head = NewNode;
        Tail = NewNode;
        Head->Next = Head;
    }else{
        if(a < Head->A_time){
            NewNode->Next = Head;
            Head = NewNode;
            Tail->Next = Head;
        }else{
            Temp = Head;
            while(Temp->Next != Head && Temp->Next->A_time <= a){
                Temp = Temp->Next;
            }
            NewNode->Next = Temp->Next;
            Temp->Next = NewNode;
            if(NewNode->Next == Head){
                Tail = NewNode;
            }
        }
    }
    return 1;
}

// Method to Dequeue an element form the queue
// Time Complexity : O(1)
struct P_Queue::Node * P_Queue::dequeue() {
    if(Head == nullptr){
        return nullptr;
    } else {
        Node *Temp = Head;
        if(Head == Tail){
            Head = nullptr;
            Tail = nullptr;
        }else{
            Head = Head->Next;
            Tail->Next = Head;
        }
        return Temp;
    }
}

// Method to return the element at the front of the queue
// Time Complexity : O(1)
int P_Queue::peek(){
    if(Head==nullptr){
        return -1;
    }else{
        return Head->A_time;
    }
}