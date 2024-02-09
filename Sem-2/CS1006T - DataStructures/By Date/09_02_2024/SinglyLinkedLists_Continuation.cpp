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
//    |             |               ---------------------------
//    -------       |                                          |
//     _____|____   -----------------|                         |
//   /            \            ______|____________             |
// [Address(Node 1)] ---|     /                    \           |
//                      |-> [Data 1 , Address(Node 2)]    _____|_________
//                                              |       /                 \
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
    public:
        List(){
            Head = nullptr;
        }
        int Insert_Beg_Node(int val){
            struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));
            NewNode->data = val;
            NewNode->Next = Head;
            Head = NewNode;
            return 1;
        }

};

// i )  Insert At Beginning

