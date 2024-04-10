#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

class Hash{
    private:
        struct Node{
            int data;
            struct Node* Next;
        };
        struct Node* table[SIZE];
        struct Node* NewNode;
    public:
        Hash(){
            for(int i=0;i<SIZE;i++){
                table[i] = nullptr;
            }
        }
        struct Node* CreateNode();
        int Insert(int);
        int Search(int);
        int Delete(int);
        void Display();
};

int main(){
    Hash HT1;
    int val,opt;
    while(1==1){
        printf("\nOPTIONS  : \n\t1 - Insert\n\t2 - Delete\n\t3 - Search\n\t4 - Display\n\t5 - Exit\n>>>");
        scanf("%d",&opt);
        switch (opt)
        {
        case 1:
            printf("Enter the value to Insert : ");
            scanf("%d",&val);
            HT1.Insert(val);
            break;
        case 2:
            printf("Enter the value to Delete : ");
            scanf("%d",&val);
            HT1.Delete(val);
            break;
        case 3:
            printf("Enter the value to Search : ");
            scanf("%d",&val);
            if(HT1.Search(val)){
                printf("Element is Found");
            }else{
                printf("Element not Found");
            }
            break;
        case 4:
            HT1.Display();
            break;
        case 5:
            return 1;
        default:
            break;
        }
    }
    HT1.Insert(12);
    HT1.Insert(13);
    HT1.Insert(14);
    HT1.Insert(15);
    HT1.Insert(22);
    HT1.Insert(16);
    HT1.Insert(182);
    HT1.Display();
    if(HT1.Search(22)){
        printf("Found 22");
    }
    HT1.Delete(22);
    HT1.Display();
    HT1.Delete(12);
    HT1.Display();
    if(HT1.Search(22)){
        printf("Found 22");
    }
    HT1.Delete(16);
    HT1.Display();
}

struct Hash::Node * Hash::CreateNode(){
    return (struct Node*)malloc(sizeof(struct Node));
}

int Hash::Insert(int val){
    NewNode = CreateNode();
    NewNode->data = val;
    NewNode->Next = table[val%SIZE];
    table[val%SIZE] = NewNode;
    return 1;
}

int Hash::Delete(int val){
    NewNode = table[val%SIZE];
    if(NewNode == nullptr){
        return 0;
    }else{
        if(NewNode->data == val){
            table[val%SIZE] = table[val%SIZE]->Next;
            free(NewNode);
        }else{
            struct Node* parent;
            while(NewNode->Next!=nullptr){
                parent = NewNode;
                if(NewNode->Next->data == val){
                    struct Node* temp = NewNode->Next;
                    NewNode->Next = temp->Next;
                    free(temp);
                    return 1;
                }
                NewNode = NewNode->Next;
            }
            if(NewNode->data ==val){
                parent->Next = nullptr;
                free(NewNode);
                return 1;
            }
        }
    }
    return 0;
}

int Hash::Search(int val){
    NewNode = table[val%SIZE];
    while(NewNode != nullptr){
        if(NewNode->data == val){
            return 1;
        }
        NewNode = NewNode->Next;
    }
    return 0;
}


void Hash::Display(){
    for(int i=0;i<SIZE;i++){
        printf("\n%d : ",i);
        NewNode = table[i];
        while(NewNode!=nullptr){
            printf(" %d -> ",NewNode->data);
            NewNode = NewNode->Next;

        }
    }
}