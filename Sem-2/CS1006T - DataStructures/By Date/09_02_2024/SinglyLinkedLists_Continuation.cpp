// This program is using Singly linked lists

// Contenttents of node
//    - Data Part
//    - Address Part

// Each Linked list always have a head pointer to point to the Head node of the Linked List

//  [ ] -> Head (Stores the addresss of the first Node)
//  {<Data_Part>,<Address_Part>} -> Node (Contains the Value part and address part if there is more element)


// Each Nodes can be build up with Structures

// NODE : 
// struct Node
// {
//     int data;  // Stores the Data Part of the Node
//     struct Node *Next;   // Stores the Address of the next Node (if needed)
// };

// Singly Linked List Visual

// [HEAD]  -->  [Node 1]  -->  [Node 2]
//    |             |               |
//    |             |               ---------------------------|
//    -------       |                                          |
//     _____|____   -----------------|                         |
//   /            \            ______|____________             |
// [Address(Node 1)] ---|     /                    \           |
//                      |-> [Data 1 , Address(Node 2)]    _____|_________
//                                              |       /                 |
//                                              |--> [Data 2, Address(Node 3)]


// Program

#include <stdio.h>
#include <stdlib.h>

class List{
    private:
        struct Node{
            int data;
            struct Node *Next;
        };
        struct Node *Head;
        struct Node *CurrentPoint;
        struct Node *NewNode;
    public:
        List(){
            Head = nullptr;
        }
        struct Node * CreateNode(){
            return (struct Node *)malloc(sizeof(struct Node));
        }
        int IsEmpty(){
            if (Head==nullptr){
                return 1;
            }else{
                return 0;
            }
            
        }
        int Insert_Beg_Node(int val){
            NewNode = CreateNode();
            NewNode->data = val;
            NewNode->Next = Head;
            Head = NewNode;
            return 1;
        }
        int Append_Node(int val){
            if(IsEmpty()==0){
                CurrentPoint = Head;
                while(CurrentPoint->Next !=nullptr){
                    CurrentPoint= CurrentPoint->Next;
                }
                NewNode = CreateNode();
                NewNode->data = val;
                NewNode->Next = nullptr;
                CurrentPoint->Next = NewNode;
                return 1;
            }return 0;
            
        }
        int Insert_Pos_Node(int val ,int pos){
            if(pos == 0){
                Insert_Beg_Node(val);
                return 1;
            }
            if(IsEmpty()==0){
                pos--;

                CurrentPoint = Head;
                while(pos >0){
                    CurrentPoint = CurrentPoint->Next;
                    pos--;
                }
                printf("%d",CurrentPoint->data);
                NewNode = CreateNode();
                NewNode->data = val;
                NewNode->Next = CurrentPoint->Next;
                CurrentPoint->Next = NewNode;
                return 1;
            }return 0;
        }
        void Display(){
            CurrentPoint = Head;
            printf("[");
            while(CurrentPoint->Next != nullptr){
                printf("%d,",CurrentPoint->data);
                CurrentPoint = CurrentPoint->Next;
            }
            printf("%d]",CurrentPoint->data);
        }

};

// i )  Insert At Beginning
int main(){

    List NewList;

    NewList.Insert_Beg_Node(2);
    NewList.Insert_Beg_Node(3);
    NewList.Insert_Beg_Node(4);
    NewList.Append_Node(5);
    NewList.Append_Node(6);
    NewList.Append_Node(7);
    NewList.Insert_Pos_Node(10,1);
    NewList.Insert_Pos_Node(30,0);
    NewList.Display();
}
