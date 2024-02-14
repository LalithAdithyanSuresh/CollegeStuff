#include <stdio.h>
#include <stdlib.h>

class List{
    private:
        struct Node{
            int data;
            struct Node *Next;
        };
        struct Node *CurrentPoint;
        struct Node *PrevPoint;
        struct Node *NewNode;
    public:
        struct Node *Head;
        List(){
            Head = nullptr;
        }
        struct Node * CreateNode(){
            return (struct Node *)malloc(sizeof(struct Node));
        }
        void DeleteNode(struct Node *del){
            free(del);
        }
        // Check if the List is empty
        int IsEmpty(){
            if (Head==nullptr){
                return 1;
            }else{
                return 0;
            }
            
        }

         // Insert a New Node in the beginning
        int Insert_Beg_Node(int val){
            NewNode = CreateNode();
            NewNode->data = val;
            NewNode->Next = Head;
            Head = NewNode;
            return 1;
        }

        
        // Insert Ascending
        int Insert_asc(int val){
            if(IsEmpty()==0){
                if(Head->data >= val){
                    Insert_Beg_Node(val);
                    return 1;
                }
                CurrentPoint = Head;
                PrevPoint = CurrentPoint;
                while(CurrentPoint->Next != nullptr){
                    PrevPoint = CurrentPoint;
                    CurrentPoint = CurrentPoint->Next;
                    if(CurrentPoint->data >= val){
                        NewNode = CreateNode();
                        NewNode->data = val;
                        NewNode->Next = PrevPoint->Next;
                        PrevPoint->Next = NewNode;
                        return 1;
                    }
                }
                NewNode = CreateNode();
                NewNode->data = val;
                NewNode->Next = CurrentPoint->Next;
                CurrentPoint->Next = NewNode;
                return 1;
                
                return 1;
            }else{
                Insert_Beg_Node(val);
                return 1;
            }
        }  


        // Merge in Ascending

        int Merge(List *b){
            struct Node *Cur_A = Head;
            struct Node *Cur_B =b->Head;
            struct Node *pre_A = Head;
            while(Cur_B->Next != nullptr){
                if(Cur_A->Next == nullptr){ //Insert at the end
                    NewNode = CreateNode();
                    NewNode->data = Cur_B->data;
                    NewNode->Next = nullptr;
                    Cur_A->Next = NewNode;
                    Cur_B= Cur_B->Next;
                }else if(Cur_A->data >= Cur_B->data){//Insert before
                    if(Cur_A == Head){ //start
                        Insert_Beg_Node(Cur_B->data);
                        Cur_B = Cur_B->Next;
                    }else{
                        NewNode = CreateNode(); //at pos
                        NewNode->data = Cur_B->data;
                        NewNode->Next = pre_A->Next;
                        pre_A->Next = NewNode;
                        Cur_B= Cur_B->Next;

                    }
                }else{
                    pre_A = Cur_A;
                    Cur_A = Cur_A->Next;
                }
            }
            return 1;
        }
        // Display
        void Display(){
            if(IsEmpty()==0){
                CurrentPoint = Head;
                printf("[");
                while(CurrentPoint->Next != nullptr){
                    printf("%d,",CurrentPoint->data);
                    CurrentPoint = CurrentPoint->Next;
                }
                printf("%d]",CurrentPoint->data);
            }else{
                printf("[]");
            }
        }
};


int main(){

    List NewList;
    int opt,var;
    while(1==1){
        system("clear");
        printf("\n-------------------------------------------------\nOptions : \n\t0-Exit\n\t1-Insert At Beginning\n\t2-Appending\n\t3-Insertion\n\t4-Delete beginning\n\t5-Pop\n\t6-Deletetion\n\t7-Search\n\t8-Display\n\t9-Reverse Display\n\t10-Reverse\n>>> ");
        scanf("%d",&opt);
        system("clear");
        switch (opt)
        {
        case 0:
            return 0;
        case 1:
            printf("\nValue : ");
            scanf("%d",&var);
            if(NewList.Insert_asc(var)==1){
                printf("\nInserted Successful");
            }else{
                printf("\nList is Full : ");
            }
            break;
        // case 2:
        //     printf("Value to append :  ");
        //     scanf("%d",&var);
        //     if(NewList.Append_Node(var)==1){
        //         printf("\nInserted Successful");
        //     }else{
        //         printf("\nList is Full :(");
        //     }
        //     break;
        case 3:
            printf("Values in List : ");
            NewList.Display();
            break;
        // case 4:
        //     if(NewList.Delete_Beg_Node()==1){
        //         printf("\nDeleted Successfully");
        //     }else{
        //         printf("\nList is Empty :(");
        //     }
        //     break;
        default:
            printf("Invalid Choise\n");
            break;
        }
        printf("\n\n(Press ENTER key to continue)");
        getchar();
        getchar();
    }
}
// int main(){
//     List a;
//     List b;
//     a.Insert_asc(10);
//     a.Insert_asc(20);
//     a.Insert_asc(30);
//     a.Insert_asc(40);
//     a.Insert_asc(50);
//     a.Insert_asc(60);
//     a.Insert_asc(70);
//     a.Insert_asc(80);
//     a.Insert_asc(90);
//     a.Insert_asc(100);
//     a.Insert_asc(110);
//     a.Insert_asc(120);

//     b.Insert_asc(15);
//     b.Insert_asc(25);
//     b.Insert_asc(55);
//     b.Insert_asc(75);
//     b.Insert_asc(85);
//     b.Insert_asc(35);
//     b.Insert_asc(45);
//     b.Insert_asc(65);
//     b.Insert_asc(55);
//     b.Insert_asc(15);
//     printf("\na = ");
//     a.Display();
//     printf("\nb = ");
//     b.Display();
//     printf("\na = ");
//     a.Merge(&b);
//     a.Display();
// }