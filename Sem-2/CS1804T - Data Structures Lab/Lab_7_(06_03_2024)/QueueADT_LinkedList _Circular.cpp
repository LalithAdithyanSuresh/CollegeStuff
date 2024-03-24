#include<stdio.h>
#include<stdlib.h>

class Queue{
    private:
        struct Node{
            int data;
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
        int enqueue(int);
        int dequeue();
        int peek();
};

int main(){
    Queue MyQueue;
    int opt=1,val;
    while(opt!=0){
        system("clear");
        printf("\n\nYour Choises\n\t1 - Enqueue\n\t2 - Dequeue\n\t3 - Peek\n\t0 - Exit\n>>> ");
        scanf("%d",&opt);
        switch (opt)
        {
        case 1:
            printf("Enter element to be enqueued : ");
            scanf("%d",&val);
            if(MyQueue.enqueue(val)==1){
                printf("Enqueue Successful");
            }else{
                printf("Queue is Full");
            }
            break;
        case 2:
            printf("Dequeing Element");
            val = MyQueue.dequeue();
            if(val == 0){
                printf("\n>>Deque Unsuccessful");
            }else{
                printf("\nDequed Element : %d",val);
            }
            break;
        case 3:
            val = MyQueue.peek();
            if(val==-1){
                printf("Queue is Empty");
            }else{
                printf("Front Element : %d",val);
            }
            break;
        default:
            break;
        }
        getchar();
        printf("\n\n>>>Press Enter to continue<<<");
        getchar();
    }
}


//Method to create a new mnode
struct Queue::Node * Queue::CreateNode(){
    return (struct Node *)malloc(sizeof(struct Node));
}

// Method to Enqueue an element to the queue
// Time Complexity : O(1)
int Queue::enqueue(int val){
    NewNode = CreateNode();
    NewNode->data = val;
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
int Queue::dequeue(){
    if(Head == nullptr){
        return 0;
    }else if(Head==Tail){
        int val = Head->data;
        free(Head);
        Head = nullptr;
        Tail = nullptr;
        return val;
    }else{
        Tail = Head->Next;
        int val = Head->data;
        NewNode = Head;
        Head = Head->Next;
        free(NewNode);
        Tail->Next = Head;
        return val;
    }
}

// Method to return the element at the front of the queue
// Time Complexity : O(1)
int Queue::peek(){
    if(Head==nullptr){
        return -1;
    }else{
        return Head->data;
    }
}