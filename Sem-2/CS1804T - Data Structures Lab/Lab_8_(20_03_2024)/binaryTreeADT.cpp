#include <stdio.h>
#include <stdlib.h>

class binTree{
    private:
        struct Node{
            int data;
            struct Node *Left;
            struct Node *Right;
        };
        struct Node *temp;
        struct Node *newNode;
        struct Node *Root;
        void recInsert(int,int,struct Node*);
        void recInOrder(struct Node*);
    
    public:
        binTree(){
            Root = nullptr;
        }
        struct Node *CreateNode();
        void Insert(int);
        void InOrder();


};


int main(){
    binTree T1;
    int opt=1,data;
    while (opt!=0){
        system("cls");
        system("cls");
        printf("\nOptions : \n\t1 - Insert\n\t4 - Inorder\n\t0 - Exit\n>>>");
        scanf("%d",&opt);
        switch (opt)
        {
        case 1:
            printf("Enter data to insert : ");
            scanf("%d",&data);
            T1.Insert(data);
            break;
        case 4:
            T1.InOrder();
            break;
        case 0:
            break;
        default:
            break;
        }
        printf("\n\n(Press enter to continue)");
        getchar();
        getchar();
    }
}





// Method to allocate space for new node and return the pointer to it
struct binTree::Node * binTree::CreateNode(){
    return (struct Node*)malloc(sizeof(struct Node));
}

// A recursive method to insert a New Node
void binTree::recInsert(int val,int dir,struct Node*Root){
    switch (dir)
    {
    case 1:
        if(Root->Left == nullptr){
            newNode = CreateNode();
            newNode->data = val;
            Root->Left = newNode;
            newNode->Left = nullptr;
            newNode->Right = nullptr;
        }else{
            printf("\n--Currently at Node : ( %d )\n\nEnter the Direction : \n\t1 - Left\n\t2 - Right\n>>>",Root->data);
            scanf("%d",&dir);
            recInsert(val,dir,Root->Left);
        }
        break;
    case 2:
        if(Root->Right == nullptr){
            newNode = CreateNode();
            newNode->data = val;
            Root->Right = newNode;
            newNode->Left = nullptr;
            newNode->Right = nullptr;
        }else{
            printf("\n--Currently at Node : ( %d )\n\nEnter the Direction : \n\t1 - Left\n\t2 - Right\n>>>",Root->data);
            scanf("%d",&dir);
            recInsert(val,dir,Root->Right);
        }
        break;
    default:
        break;
    }
}



// Method to Insert A node into the tree
void binTree::Insert(int val){
    if(Root == nullptr){
        newNode = CreateNode();
        newNode->data = val;
        Root = newNode;
        newNode->Left = nullptr;
        newNode->Right = nullptr;
    }else{
        int dir = 0;
        printf("\n--Currently at Node : ( %d )\n\nEnter the Direction : \n\t1 - Left\n\t2 - Right\n>>>",Root->data);
        scanf("%d",&dir);
        recInsert(val,dir,Root);
    }
}

// Method to print data of the tree recursively and INORDER
void binTree::recInOrder(struct Node *Root){
    if(Root->Left != nullptr){
        recInOrder(Root->Left);
    }
    printf(" %d ",Root->data);
    if(Root->Right != nullptr){
        recInOrder(Root->Right);
    }
}


// Method to print data of tree INORDER
void binTree::InOrder(){
    if(Root != nullptr){
        recInOrder(Root);
    }
    else{
        printf("Tree is Empty");
    }
}