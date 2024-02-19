// A node with a previous address , a data and the next Node
// This is used to track back in the linked list to the previous value !

// Insert begin , Display
// Insert end , Display
// Insert Pos , Display
// Insert Mid , Display
// Insert Odd/Even w/ count , Display  (Choose odd or even : ) {Doubly Linked List | Exclusive}


#include <stdio.h>
#include <stdlib.h>

class DLList{
    private:
        struct DNode{
            struct DNode *P_Node;
            int data;
            struct DNode *N_Node;
        };
        struct DNode *Head;
        struct DNode *Tail;
        struct DNode *C_Node;
        struct DNode *New_Node;
    public:
        DLList(){
            Head = nullptr;
        }
        struct DNode * CreateNode();
        int IsEmpty();
        int Insert_beg_node(int val);
        int Insert_end_node(int val);
        int Insert_pos_node(int val,int index);
        void Display();
};

struct DLList::DNode * DLList::CreateNode(){
    return (struct DNode * ) malloc(sizeof(struct DNode));
}
int DLList::IsEmpty(){
    if(Head == nullptr){
        return 1;
    }
    else{
        return 0;
    }
}

// Insert at begining
int DLList::Insert_beg_node(int val){
    C_Node = CreateNode();
    C_Node->data = val;
    C_Node->N_Node = nullptr;
    if(IsEmpty()==0){
        C_Node->N_Node = Head;
        Head->P_Node = C_Node;
    }else{
        C_Node->P_Node = nullptr;
        Tail = C_Node;
    }
    Head = C_Node;
    return 1;
}

// Insert at the End
int DLList::Insert_end_node(int val){
    C_Node = CreateNode();
    C_Node->data = val;
    C_Node->N_Node = nullptr;
    C_Node->P_Node = Tail;
    Tail->N_Node = C_Node;
    Tail = C_Node;
    return 1;
}

// Insert at pos

int DLList::Insert_pos_node(int val,int index){
    New_Node = CreateNode();
    New_Node->data = val;
    if(IsEmpty()==0){
        C_Node = Head;
        while(C_Node != Tail && index >0){
            index--;
            C_Node = C_Node->N_Node;
        }
        C_Node->P_Node->N_Node = New_Node;
        New_Node->P_Node = C_Node->P_Node;
        New_Node->N_Node = C_Node;
        C_Node->P_Node = New_Node;
        return 1;
    }
    return 0;
}


// Display the list

void DLList::Display(){
    if(IsEmpty()==0){
        C_Node = Head;
        printf("[");
        while(C_Node->N_Node != nullptr){
            printf("%d,",C_Node->data);
            C_Node = C_Node->N_Node;
        }
        printf("%d]",C_Node->data);
        C_Node = Tail;
        printf(" Reversed = > [");
        while(C_Node->P_Node != nullptr){
            printf("%d,",C_Node->data);
            C_Node = C_Node->P_Node;
        }
        printf("%d]",C_Node->data);
    }else{
        printf("[]");
    }
}


int main(){
    DLList list;
    int count,mode,val,opt=1;
    while(opt!=0){
        printf("Enter your option\n\t1 - Insert Beg\n\t2 - Insert End\n\t3 - Odd/Even Pos\n\t4 - Display\n>>>");
        scanf("%d",&opt);
        switch (opt)
        {
        case 1:
            printf("Enter the value to insert : ");
            scanf("%d",&val);
            list.Insert_beg_node(val);
            break;
        case 2:
            printf("Enter the value to insert : ");
            scanf("%d",&val);
            list.Insert_end_node(val);
            break;
        case 3:
            printf("Enter the mode : ");
            scanf("%d",&mode);
            printf("Enter Count : ");
            scanf("%d",&count);
            printf("Enter the value to insert : ");
            scanf("%d",&val);
            
            if(mode==0){
                list.Insert_pos_node(val,(count-1)*2);
            }else{
                list.Insert_pos_node(val,((count-1)*2) +1);
            }
        case 4:
            printf("Displaying List = > ");
            list.Display();
            printf("\n");
        default:
            break;
        }
    }
    return 0;
}