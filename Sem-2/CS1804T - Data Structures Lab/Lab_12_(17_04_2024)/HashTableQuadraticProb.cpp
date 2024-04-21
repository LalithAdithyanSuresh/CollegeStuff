#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
#define EMPTY -1
#define TOMB -2

class QPHash{
    private:
        int array[SIZE];
    public:
        QPHash(){
            for(int i=0;i<SIZE;i++){
                array[i] = EMPTY;
            }
        }
        int Insert(int);
        int Delete(int);
        int Search(int);
        void Display();
};

int main(){
    int data,opt;
    QPHash H1;
    while(1==1){
        printf("\nOptions:\n\t1. Insert\n\t2. Delete\n\t3. Search\n\t4. Display\n\t5. Exit\n>>>");
        scanf("%d",&opt);
        switch (opt)
        {
        case 1:
            printf("Enter Value to Insert : ");
            scanf("%d",&data);
            if(H1.Insert(data) == 1){
                printf("Insert Successful");
            }else{
                printf("Hash Full");
            }
            break;
        case 2:
            printf("Enter Value to Delete : ");
            scanf("%d",&data);
            if(H1.Delete(data) == data){
                printf("Deletion Successful");
            }else{
                printf("Element not found");
            }
            break;
        case 3:
            printf("Enter Value to Search : ");
            scanf("%d",&data);
            if(H1.Search(data) == data){
                printf("Element Found");
            }else{
                printf("Element not Found");
            }
            break;
        case 4:
            printf("Displaying elements of Hash\n");
            H1.Display();
            break;
        case 5:
            return 1;
        default:
            break;
        }
    }
}


// Method to Insert a value into the hash table
int QPHash::Insert(int val){
    for(int i=0;i<SIZE;i++){
        if(array[(val+(i*i))%SIZE]==EMPTY || array[(val+(i*i))%SIZE]==TOMB){
            array[(val+(i*i))%SIZE] = val;
            return 1;
        }
    }
    return 0;
}

// Method to Delete an element form the hash table and repalce with tombstone
int QPHash::Delete(int val){
    for(int i=0;i<SIZE;i++){
        if(array[(val+(i*i))%SIZE]==EMPTY){
            return EMPTY;
        }else if(array[(val+(i*i))%SIZE] == val){
            array[(val+(i*i))%SIZE] = TOMB;
            return val;
        }
    }
    return EMPTY;
}

// Method to search for an element
int QPHash::Search(int val){
    for(int i=0;i<SIZE;i++){
        if(array[(val+(i*i))%SIZE]==EMPTY){
            return EMPTY;
        }else if(array[(val+(i*i))%SIZE] == val){
            return val;
        }
    }
    return EMPTY;
}

// Method to Display the whole hash table
void QPHash::Display(){
    for(int i=0;i<SIZE;i++){
        printf("\n%d - ",i);
        if(array[i] != EMPTY && array[i] != TOMB){
            printf("%d",array[i]);
        }
    }
}