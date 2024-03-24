#include <stdio.h>
#include <stdlib.h>
#define ArraySize 5
class Queue{
    private:
        int Array[ArraySize];
        int Front,Rear;
    public:
        Queue(){
            Front = -1;
            Rear = -1;
        }
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
            if(val==0){
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


// Method to Enqueue an element to the queue
// Time Complextiy : O(1)
int Queue::enqueue(int val){
    if((Rear+1)%ArraySize != Front%ArraySize){
        if(Front == Rear && Front == -1){
            Front++;
        }
        Rear++;
        Array[Rear%ArraySize] = val;
        return 1;
    }else{
        return 0;
    }
}

// Method to Dequeue an element form the array
// Time Complextiy : O(1)
int Queue::dequeue(){
    if(Front != -1){
        if((Front)%ArraySize == Rear%ArraySize){
            int val = Array[Front%ArraySize];
            Front = -1;
            Rear = -1;
            return val;
        }else{
            int val = Array[Front%ArraySize];
            Front++;
            return val;
        }
    }
    return 0;
}

// Method to return the fornt-most element in the array
// Time Complextiy : O(1)
int Queue::peek(){
    if(Front==-1){
        return 0;
    }else{
        return Array[Front%ArraySize];
    }
}