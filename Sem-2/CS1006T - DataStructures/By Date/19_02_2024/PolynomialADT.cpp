// Each node will have a Coefficient Data value, a Degree Data value and a pointer to the next node


#include <stdio.h>
#include <stdlib.h>


class PolyList{
    private:
        struct Term{
            int Coe;
            int Deg;
            struct Term *N_Term;
        };
        struct Term *Head;
        struct Term *N_Node;
        struct Term *C_Node;
    public:
        PolyList(){
            Head = nullptr;
        }
        struct Term * CreateNode();
        int IsEmpty();
        int Insert_beg_node(int val);
        int Insert_end_node(int val);
        int Insert_pos_node(int val,int index);
        void Display();  
};


struct PolyList::Term * PolyList::CreateNode(){
    return (struct Term * ) malloc(sizeof(struct Term));
}
int PolyList::IsEmpty(){
    if(Head == nullptr){
        return 1;
    }
    else{
        return 0;
    }
}

// Insert at begining
int PolyList::Insert_beg_node(int val){
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
