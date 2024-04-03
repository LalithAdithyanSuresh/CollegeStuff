#include <stdio.h>
#include <stdlib.h>
class Tree{
    public:
        struct T_Node{
            char data;
            struct T_Node* Left;
            struct T_Node* Right;
        };
        struct T_Node *Root;
        struct T_Node *NewNode;
        Tree(){
            Root = nullptr;
        }
        struct T_Node *CreateNode();
        int ConstructExp(char *,int,class Stack *);
        void PreOrderRec(struct T_Node *);
        void PreOrder();
        void InOrderRec(struct T_Node *);
        void InOrder();
        void PostOrderRec(struct T_Node *);
        void PostOrder();
};
class Stack{
    private:
        struct S_Node{
            struct Tree::T_Node *Data;
            struct S_Node* Next;
        };
        struct S_Node *Head;
        struct S_Node *NewNode;
    public:
        Stack(){
            Head = nullptr;
        }
        struct S_Node *CreateNode();
        int push(Tree::T_Node *);
        struct Tree::T_Node *pop();


};




// TREE OPERATIONS 

// Method to Create a new node
struct Tree::T_Node *Tree::CreateNode(){
    return (struct T_Node *)malloc(sizeof(struct T_Node));
}
// Method to Create the binary Tree form the post fix expression
// Time Complexity => O(n)
int Tree::ConstructExp(char *array,int n,class Stack *S){
    int Operators=0,Operands=0;
    for(int i = 0;i<n;i++){
        NewNode = CreateNode();
        NewNode->data = array[i];
        NewNode->Left=nullptr;
        NewNode->Right=nullptr;
        if(array[i] == '+' || array[i] == '-' || array[i] == '*' || array[i] == '/'){
            NewNode->Right = S->pop();
            NewNode->Left = S->pop();
            if(NewNode->Right == nullptr || NewNode->Left == nullptr){
                return 0;
            }
            Operators++;
            S->push(NewNode);
            continue;
        }else if(array[i] == '='){
            Operators++;
            NewNode->Right = S->pop();
            if(NewNode->Right==nullptr){
                return 0;
            }
            S->push(NewNode);
            continue;
        }else{
            Operands++;
            S->push(NewNode);

        }
    }
    if(Operators*2 - 1 !=Operands){
        return 0;
    }
    Root = S->pop();
    return 1;
}

// Method to recursively Print in PREORDER
// Time Complexity => O(n)

void Tree::PreOrderRec(struct T_Node *Root){
    printf(" %c ",Root->data);
    if(Root->Left != nullptr){
        PreOrderRec(Root->Left);
    }
    if(Root->Right != nullptr){
        PreOrderRec(Root->Right);
    }
}


// Method to print data of tree PreORDER
// Time Complexity => O(n)

void Tree::PreOrder(){
    if(Root != nullptr){
        PreOrderRec(Root);
    }
    else{
        printf("Tree is Empty");
    }
}

// Method to recursively Print in INORDER
// Time Complexity => O(n)

void Tree::InOrderRec(struct T_Node *Root){
    if(Root->Left != nullptr){
        InOrderRec(Root->Left);
    }
    printf(" %c ",Root->data);
    if(Root->Right != nullptr){
        InOrderRec(Root->Right);
    }
}

// Method to print data of tree InORDER
// Time Complexity => O(n)

void Tree::InOrder(){
    if(Root != nullptr){
        InOrderRec(Root);
    }
    else{
        printf("Tree is Empty");
    }
}

// Method to recursively Print in POSTORDER
// Time Complexity => O(n)

void Tree::PostOrderRec(struct T_Node *Root){
    if(Root->Left != nullptr){
        PostOrderRec(Root->Left);
    }
    if(Root->Right != nullptr){
        PostOrderRec(Root->Right);
    }
    printf(" %c ",Root->data);
}


// Method to print data of tree POSTORDER
// Time Complexity => O(n)

void Tree::PostOrder(){
    if(Root != nullptr){
        PostOrderRec(Root);
    }
    else{
        printf("Tree is Empty");
    }
}



// STACK OPERATIONS

// Method to Create New Node
struct Stack::S_Node * Stack::CreateNode(){
    return (struct S_Node*)malloc(sizeof(struct S_Node));
}

// Method to Push a new Node into stack
// Time Complexity => O(1)

int Stack::push(Tree::T_Node *TreeNode){
    NewNode = CreateNode();
    NewNode->Data = TreeNode;
    NewNode->Next = nullptr;
    if(Head!=nullptr){
        NewNode->Next = Head;
    }
    Head = NewNode;
    return 1;
}

// Method to Pop a Node from the stack
// Time Complexity => O(1)

struct Tree::T_Node* Stack::pop(){
    struct Tree::T_Node *data;
    data = nullptr;
    if(Head!=nullptr){
        data = Head->Data;
        NewNode = Head;
        Head = Head->Next;
        free(NewNode);
    }
    return data;
}