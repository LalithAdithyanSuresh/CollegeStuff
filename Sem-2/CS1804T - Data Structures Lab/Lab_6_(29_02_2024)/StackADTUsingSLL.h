class Stack{
    private:
        struct Node{
            char data;
            struct Node *Next;
        };
        struct Node *Head;
        struct Node *CurrentPoint;
        struct Node *NewNode;
    public:
        Stack(){
            Head = nullptr;
        }
        struct Node * CreateNode();
        void DeleteNode(struct Node *del);
        int IsEmpty();
        int Insert_Beg_Node(char val);
        int Delete_Beg_Node();
        char Display();
};
// Create New Node And return Pointer
struct Stack::Node * Stack::CreateNode(){
    return (struct Node *)malloc(sizeof(struct Node));
}

// Delete and free memoryof the Node
void Stack::DeleteNode(struct Node *del){
    free(del);
}

// Check if the Stack is empty
int Stack::IsEmpty(){
    if (Head==nullptr){
        return 1;
    }else{
        return 0;
    }
    
}

// Insert a New Node in the beginning
int Stack::Insert_Beg_Node(char val){
    NewNode = CreateNode();
    NewNode->data = val;
    NewNode->Next = Head;
    Head = NewNode;
    return 1;
}

// Delete the beginning Node
int Stack::Delete_Beg_Node(){
    if(IsEmpty()==0){
        CurrentPoint = Head;
        Head = CurrentPoint->Next;
        DeleteNode(CurrentPoint);
        return 1;

    }else{
        return 0;
    }
}
// Display the top of the Stack of the Stack
char Stack::Display(){
    if(IsEmpty()==0){
        return Head->data;
    }else{
        return '~';
    }
}


// ----------------------------------------------------INTEGER STACK-------------------------------------------

class INTStack{
    private:
        struct Node{
            int data;
            struct Node *Next;
        };
        struct Node *Head;
        struct Node *CurrentPoint;
        struct Node *NewNode;
    public:
        INTStack(){
            Head = nullptr;
        }
        struct Node * CreateNode();
        void DeleteNode(struct Node *del);
        int IsEmpty();
        int Insert_Beg_Node(int val);
        int Delete_Beg_Node();
        int Display();
};
// Create New Node And return Pointer
struct INTStack::Node * INTStack::CreateNode(){
    return (struct Node *)malloc(sizeof(struct Node));
}

// Delete and free memoryof the Node
void INTStack::DeleteNode(struct Node *del){
    free(del);
}

// Check if the Stack is empty
int INTStack::IsEmpty(){
    if (Head==nullptr){
        return 1;
    }else{
        return 0;
    }
    
}

// Insert a New Node in the beginning
int INTStack::Insert_Beg_Node(int val){
    NewNode = CreateNode();
    NewNode->data = val;
    NewNode->Next = Head;
    Head = NewNode;
    return 1;
}

// Delete the beginning Node
int INTStack::Delete_Beg_Node(){
    if(IsEmpty()==0){
        CurrentPoint = Head;
        Head = CurrentPoint->Next;
        DeleteNode(CurrentPoint);
        return 1;

    }else{
        return 0;
    }
}
// Display the top of the Stack of the Stack
int INTStack::Display(){
    if(IsEmpty()==0){
        return Head->data;
    }else{
        return 0;
    }
}