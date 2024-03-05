// Doubly Linked list implementation in c++ for the usage of browser hhistory management

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
        struct DNode *CurrentWebPage;
        int ID=0;
    public:
        DLList(){
            Head = nullptr;
        }
        struct DNode * CreateNode();
        int IsEmpty();
        int NewWebPage();
        int Delete_nodes_After();
        int Go_Prev();
        int Go_Next();
        void Display();
};


int main(){
    DLList list;
    int ID=0,val,opt=1;
    while(opt!=0){
        system("cls");
        printf("Enter your option\n\t1 - New Webpage\n\t2 - Go Back\n\t3 - Go Front\n\t4 - Exit\n>>>");
        scanf("%d",&opt);
        system("cls");
        switch (opt)
        {
        case 1:
            printf("Inserting New Web Page : ");
            printf(">>%d",list.NewWebPage());
            ID++;
            break;
        case 2:
            printf("Go Back");
            val = list.Go_Prev();
            if(val == -1){
                printf("Cannot go back in history");
            }else{
                printf("Moved back > Current page : %d",val);
            }
            break;
        case 3:
            printf("Go Front");
            val = list.Go_Next();
            if(val == -1){
                printf("Cannot go front in history");
            }else{
                printf("Moved front > Current page : %d",val);
            }
            break;
        case 4:
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
int DLList::NewWebPage(){
    C_Node = CreateNode();
    C_Node->data = ID;
    ID++;
    C_Node->N_Node = nullptr;
    C_Node->P_Node = nullptr;
    if(IsEmpty()==0){
        New_Node = C_Node;
        Delete_nodes_After();
        C_Node = New_Node;
        CurrentWebPage->N_Node = C_Node;
        C_Node->P_Node = CurrentWebPage;
    }else{
        Head = C_Node;
    }
    Tail = C_Node;
    CurrentWebPage = C_Node;
    return ID-1;
}

// Delete the last node
// Time Complexity => O(N)
int DLList::Delete_nodes_After(){
    if(IsEmpty()==0){
        C_Node = CurrentWebPage;
            printf("%d",C_Node->data);
        while(C_Node->N_Node != nullptr){
            C_Node = C_Node->N_Node;
            if(C_Node->P_Node !=CurrentWebPage){
                free(C_Node->P_Node);
            }
        }
        if(C_Node != CurrentWebPage){
            free(C_Node);
        }
        return 1;
    }
    return 0;
}

// Move Back
int DLList::Go_Prev(){
    if(CurrentWebPage!=nullptr && CurrentWebPage->P_Node !=nullptr){
        CurrentWebPage = CurrentWebPage->P_Node;
        return CurrentWebPage->data;
    }
    return -1;
}
// Move LFront
int DLList::Go_Next(){
    if(CurrentWebPage!=nullptr && CurrentWebPage->N_Node !=nullptr){
        CurrentWebPage = CurrentWebPage->N_Node;
        return CurrentWebPage->data;
    }
    return -1;
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
