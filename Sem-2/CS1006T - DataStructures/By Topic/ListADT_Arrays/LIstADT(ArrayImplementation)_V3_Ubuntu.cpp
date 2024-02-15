#include <stdio.h>
#include <stdlib.h>


#define List_Size_Given 10

class List{
    private:
        int C_Ind;
        int T_Ind = 0;
        int L_arr[List_Size_Given] ={0};

    public: 
        List(){
            C_Ind = -1;
        }
        // Function to Check if the array is empty
        int IsEmpty(){
            if (C_Ind == -1){
                return 1;
            }else{
                return 0;
            }
        }

        // Funciton to check if array is full
        int IsFull(){
            if(C_Ind == List_Size_Given-1){
                return 1;
            }else{
                return 0;
            }
        }

        // Function to shift all elements to the right and insert a new value in index : 0
        int InsertBeg(int val){
            if(IsFull()==0){
                for(T_Ind = C_Ind;T_Ind > -1;T_Ind--){
                    L_arr[T_Ind+1]=L_arr[T_Ind];
                }
                L_arr[0]=(int)val;
                C_Ind++;
                return 1;
            }
            return 0;
        }

        // Function to Add an element to that last of the array
        int Append(int val){
            if(IsFull()==0){
                C_Ind++;
                L_arr[C_Ind] = val;
                return 1;
            }
            return 0;
        }

        // Function to insert an element in the given position
        int Insert(int val,int pos){
            if(IsFull()==0){
                if(pos<=C_Ind){
                    for(T_Ind = C_Ind;T_Ind >= pos;T_Ind--){
                        L_arr[T_Ind+1]=L_arr[T_Ind];
                    }
                    L_arr[pos]=val;
                    C_Ind++;
                    return 1;
                }
                return(-1);
            }
            return 0;
        }

        // Function To Delete Beginning element of the array
        int DeleteBeg(){
            if(IsEmpty()==0){
                for(T_Ind = 1;T_Ind <= C_Ind;T_Ind++){
                    L_arr[T_Ind-1]=L_arr[T_Ind];
                }
                C_Ind--;
                return 1;
            }
            return 0;
        }

        // Function to Pop the last element of the array
        int Pop(){
            if(IsEmpty()==0){
                C_Ind--;
                return 1;
            }
            return 0;
        }

        // Function to delete theelement in the given position
        int Delete(int pos){
            if(IsEmpty()==0){
                for(T_Ind = pos+1;T_Ind <= C_Ind;T_Ind++){
                    L_arr[T_Ind-1]=L_arr[T_Ind];
                }
                C_Ind--;
                return 1;
            }
            return 0;
        }

        // Function to search for an element and return the index of that element
        int Search(int val){
            if(IsEmpty()==0){
                for(T_Ind = 0;T_Ind<=C_Ind;T_Ind++){
                    if(L_arr[T_Ind]==val){
                        return T_Ind;
                    }
                }
            }
            return -1;
        }

        // Function to display all the elements of the list
        void Display(){
            printf("\n[");
            for(T_Ind=0;T_Ind<C_Ind;T_Ind++){
                printf("%d,",L_arr[T_Ind]);
            }
            printf("%d]",L_arr[C_Ind]);
        }
};

int main(){
    List a;
    int opt,var,pos,variable;
    while(1==1){
        system("clear");
        printf("\n-------------------------------------------------\nOptions : \n\t0-Exit\n\t1-Insert At Beginning\n\t2-Appending\n\t3-Insertion\n\t4-Delete beginning\n\t5-Pop\n\t6-Deletetion\n\t7-Search\n\t8-Display\n>>> ");
        scanf("%d",&opt);
        system("clear");
        switch (opt)
        {
        case 0:
            return 0;
        case 1:
            printf("\nValue : ");
            scanf("%d",&var);
            if(a.InsertBeg(var)==1){
                printf("\nInserted Successful");
            }else{
                printf("\nList is Full :(");
            }
            break;
        case 2:
            printf("Value to append :  ");
            scanf("%d",&var);
            if(a.Append(var)==1){
                printf("\nInserted Successful");
            }else{
                printf("\nList is Full :(");
            }
            break;
        case 3:
            printf("Value to Insert :  ");
            scanf("%d",&var);
            printf("Position to Insert :  ");
            scanf("%d",&pos);
            variable = a.Insert(var,pos);
            if(variable==1){
                printf("\nInserted Successful");
            }else if(variable==0){
                printf("\nList is Full :(");
            }else{
                printf("Invalid Position");
            }
            break;
        case 4:
            if(a.DeleteBeg()==1){
                printf("\nDeleted Successfully");
            }else{
                printf("\nList is Empty :(");
            }
            break;
        case 5:
            if(a.Pop()==1){
                printf("\nPopped Successfully");
            }else{
                printf("\nList is Empty :(");
            }
            break;
        case 6:
            printf("Position to Remove :  ");
            scanf("%d",&pos);
            if(a.Delete(pos)==1){
                printf("\nDeleted Successfully");
            }else{
                printf("\nList is Empty :(");
            }
            break;
        case 7:
            printf("Element to search :  ");
            scanf("%d",&var);
            pos = a.Search(var);
            if(pos!=-1){
                printf("\nFound Element In index :%d",pos);
            }else{
                printf("\nElement Not Found in List");
            }
            break;
        case 8:
            printf("Values in List : ");
            a.Display();
            break;
        default:
            printf("Invalid Choise\n");
            break;
        }
        printf("\n(Press any key to continue)");
        getchar();
        getchar();
    }
}