#include <stdio.h>
#include <stdlib.h>


#define List_Size_Given 5
class List{
    private:
        int C_Ind;
        int T_Ind = 0;
        char L_arr[List_Size_Given];

    public: 
        List(){
            C_Ind = -1;
        }
        int IsEmpty();
        int IsFull();
        int Append(char val);
        int Pop();
        void Display();
};

int main(){
    List a;
    char var;
    int opt;
    while(1==1){
        system("clear");
        printf("\n-------------------------------------------------\nOptions : \n\t0-Exit\n\t1 - PUSH\n\t2 - POP\n\t3 - PEEK\n>>> ");
        scanf("%d",&opt);
        getchar();
        system("clear");
        switch (opt)
        {
        case 0:
            return 0;
        case 1:
            printf("\nValue : ");
            scanf("%c",&var);
            if(a.Append(var)==1){
                printf("\nInserted Successful");
            }else{
                printf("\nList is Full :(");
            }
            break;
        case 2:
            if(a.Pop()==1){
                printf("\nDeleted Successfully");
            }else{
                printf("\nList is Empty :(");
            }
            break;
        case 3:
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

// Function to Check if the array is empty
int List::IsEmpty(){
    if (C_Ind == -1){
        return 1;
    }else{
        return 0;
    }
}

// Funciton to check if array is full
int List::IsFull(){
    if(C_Ind == List_Size_Given-1){
        return 1;
    }else{
        return 0;
    }
}

// Function to Add an element to that last of the array
int List::Append(char val){
    if(IsFull()==0){
        C_Ind++;
        L_arr[C_Ind] = val;
        return 1;
    }
    return 0;
}

// Function to Pop the last element of the array
int List::Pop(){
    if(IsEmpty()==0){
        C_Ind--;
        return 1;
    }
    return 0;
}
// Function to display the top of the list
void List::Display(){
    printf("\n TOP => ");
    if(C_Ind>=0){
        printf("%c\n",L_arr[0]);
    }else{
        printf("Stack is empty\n");
    }
}