// Doubly Linked list implementation in c++

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
        int Delete_beg_node();
        int Delete_end_node();
        int Delete_pos_node(int pos);
        int Search(int val);
        void Display();
};


int main(){
    DLList list;
    int pos,val,opt=1;
    while(opt!=0){
        system("clear");
        printf("Enter your option\n\t1 - Insert Beg\n\t2 - Insert End\n\t3 - Insert at Pos\n\t4 - Delete Beg\n\t5 - Delete End\n\t6 - Delete at Pos\n\t7 - Search\n\t8 - Display\n\t9 - Exit\n>>>");
        scanf("%d",&opt);
        system("clear");
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
            printf("Enter Position : ");
            scanf("%d",&pos);
            printf("Enter the value to insert : ");
            scanf("%d",&val);
            if(list.Insert_pos_node(val,pos)==1){
                printf("Value inserting success");
            }else{
                printf("Valu cannot be inserted at this index");
            }
            break;
        case 4:
            if(list.Delete_beg_node()==1){
                printf("Deleted First node");
            }else{
                printf("Failed to delete first node");
            }
            break;
        case 5:
            if(list.Delete_end_node()==1){
                printf("Deleted the last node");
            }else{
                printf("Error in deleting the last node");
            }
            break;
        case 6:
            printf("Enter Position : ");
            scanf("%d",&pos);
            list.Delete_pos_node(pos);
            break;
        case 7:
            printf("Enter value to search for : ");
            scanf("%d",&val);
            pos = list.Search(val);
            if(pos!= -1){
                printf("The Element you have been searching for is on index : %d",pos);
            }else{
                printf("The element is not found in the list");
            }
            break;
        case 8:
            printf("Displaying List = > ");
            list.Display();
            printf("\n");
            break;
        case 9:
            return 0;
        default:
            break;
        }
        printf("\n\n(Press ENTER key to continue)");
        getchar();
        getchar();
    }
    return 0;
}



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
// Time Complexity => O(1)
int DLList::Insert_beg_node(int val){
    C_Node = CreateNode();
    C_Node->data = val;
    C_Node->N_Node = nullptr;
    C_Node->P_Node = nullptr;
    if(IsEmpty()==0){
        C_Node->N_Node = Head;
        Head->P_Node = C_Node;
    }else{
        Tail = C_Node;
    }
    Head = C_Node;
    return 1;
}

// Insert at the End
// Time Complexity => O(1)
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
// Time Complexity => O(N)
int DLList::Insert_pos_node(int val,int index){
    New_Node = CreateNode();
    New_Node->data = val;
    if(IsEmpty()==0){
        C_Node = Head;
        while(C_Node != Tail && index >0){
            index--;
            C_Node = C_Node->N_Node;
        }
        if(index > 0){
            return 0;
        }
        if(C_Node->P_Node == nullptr){
            Insert_beg_node(val);
            return 1;
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
// Time Complexity => O(N)
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

// Delete the first node
// Time Complexity => O(1)
int DLList::Delete_beg_node(){
    if(IsEmpty()==0){
        C_Node = Head;
        if(C_Node->N_Node == nullptr){
            Tail = nullptr;
            Head = nullptr;
            free(C_Node);
            return 1;
        }
        Head = C_Node->N_Node;
        Head->P_Node = nullptr;
        free(C_Node);
        return 1;
    }
    return 0;
}

// Delete the last node
// Time Complexity => O(1)
int DLList::Delete_end_node(){
    if(IsEmpty()==0){
        C_Node = Tail;
        if(C_Node->P_Node == nullptr){
            Tail = nullptr;
            Head = nullptr;
            free(C_Node);
            return 1;
        }
        Tail = C_Node->P_Node;
        Tail->N_Node = nullptr;
        free(C_Node);
    return 1;
    }
    return 0;
}

// Delete the node at given index position
// Time Complexity => O(N)
int DLList::Delete_pos_node(int pos){
    if(IsEmpty()==0){
        if(pos == 0){
            Delete_beg_node();
            return 1;
        }
        if(IsEmpty()==0){
            C_Node = Head;
            while((C_Node->N_Node != nullptr) && (pos>0)){
                pos--;
                C_Node = C_Node->N_Node;
            }
            if(pos>0){
                return 0;
            }else{
                if(C_Node->N_Node == nullptr){
                    Delete_end_node();
                    return 1;
                }else if(C_Node->P_Node == nullptr){
                    Delete_beg_node();
                    return 1;
                }
                C_Node->P_Node->N_Node = C_Node->N_Node;
                C_Node->N_Node->P_Node = C_Node->P_Node;
                free(C_Node);
                return 1;
            }
        }
        return 0;
    }
    return 0;
}

// Search Value and return the index of the node
// Time Complexity => O(N)
int DLList::Search(int val){
    int pos = 0;
    C_Node = Head;
    if(IsEmpty()==0){
        while(C_Node->data != val && C_Node->N_Node != nullptr){
            C_Node = C_Node->N_Node;
            pos++;
        }
        if(C_Node->data == val){
            return pos;
        }
        else{
            return -1;
        }
    }
    return -1;
}