#include <stdio.h>
#include <stdlib.h>

class MaxHeap{
    private:
        int *array;
        int E_ind;
        void Heapify(int);
    public:
        MaxHeap(){
            array = (int *)malloc(sizeof(int));
            E_ind = -1;
        }
        int insert(int);
        int Delete();
        int Search(int);
        int *Sort();
        void Display();
};

int main(){
    MaxHeap M1;
    int val,opt;
    while (1==1){
        printf("Options : \n\t1. Insert\n\t2 -  Delete\n\t3 -  Display\n\t4 -  Search\n\t5 -  Sort (Heap Sort) \n\t6 -  Exit\n>>>");
        scanf("%d",&opt);
        switch (opt)
        {
        case 1:
            printf("Enter value to insert : ");
            scanf("%d",&val);
            M1.insert(val);
            break;
        case 2:
            printf("Deleted Element : %d",M1.Delete());
            break;
        case 3:
            printf("Displaying Heap : ");
            M1.Display();
            break;
        case 4:
            printf("Enter value to Search : ");
            scanf("%d",&val);
            if(M1.Search(val)){
                printf("Found the Element");
                break;
            }
            printf("Not Found");
            break;
        case 5:
            int *PQueue;
            PQueue = M1.Sort();
            printf("Priority Queue Elements : ");
            for(int i=0;i<sizeof(PQueue)/sizeof(int);i++){
                printf("%d,",PQueue[i]);
            }
            break;
        case 6:
            return 1;
        default:
            break;
        }
    }
    

}

// method to Heapify and maintang Max Heap
void MaxHeap::Heapify(int parent){
    int ch1 = parent*2 +1;
    int ch2 = ch1 +1;
    if(ch1 <= E_ind){
        Heapify(ch1);
        if(array[parent] < array[ch1]){
            int temp = array[parent];
            array[parent] = array[ch1];
            array[ch1] = temp;
        }
    }
    if(ch2 <= E_ind){
        Heapify(ch2);
        if(array[parent] < array[ch2]){
            int temp = array[parent];
            array[parent] = array[ch2];
            array[ch2] = temp;
        }
    }
}

// Method to insert a new element into the Queue
int MaxHeap::insert(int val){
    E_ind++;
    array = (int *)realloc(array,sizeof(array) + sizeof(int));
    array[E_ind] = val;
    Heapify(0);
    return 1;
}

// Methid to delete the largest value of max heap
int MaxHeap::Delete(){
    int temp = array[0];
    array[0] = array[E_ind];
    array[E_ind] = temp;
    E_ind--;
    array = (int *)realloc(array,sizeof(array)- sizeof(int));
    Heapify(0);
    return temp;
    
}

// Method to search for a value in Heap
int MaxHeap::Search(int val){
    for(int i=0;i<=E_ind;i++){
        if(val == array[i])return 1;
    }
    return 0;
}

// Method to return an array that is in decsending order
int *MaxHeap::Sort(){
    int *NewArray = (int *)malloc(sizeof(int)*(E_ind+1));
    for(int i =0;i<=E_ind;i++){
        NewArray[i] = Delete();
    }
    return NewArray;
}

// method to display the Tree with array ADT
void MaxHeap::Display(){
    for(int i=0;i<=E_ind;i++){
        printf("%d",array[i]);
    }
}