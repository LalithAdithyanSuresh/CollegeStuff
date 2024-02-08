// This program is using Singly linked lists

// Contenttents of node
//    - Data Part
//    - Address Part

// Each Linked list always have a head pointer to point to the Head node of the Linked List

//  [ ] -> Head (Stores the addresss of the first Node)
//  {<Data_Part>,<Address_Part>} -> Node (Contains the Value part and address part if there is more element)


// Each Nodes can be build up with Structures

// NODE : 
struct Node
{
    int data;  // Stores the Data Part of the Node
    struct Node *Node;   // Stores the Address of the next Node if needed
};

