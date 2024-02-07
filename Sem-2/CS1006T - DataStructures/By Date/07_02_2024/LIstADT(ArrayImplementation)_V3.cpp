// DISCLAIMER : this program is written to work in sync with Windows OS
// for the program that works in Ubuntu please refer the program : https://github.com/LalithAdithyanSuresh/CollegeStuff/blob/main/Sem-2/CS1006T%20-%20DataStructures/By%20Date/07_02_2024/LIstADT(ArrayImplementation)_V3_Ubuntu.cpp

#include <stdio.h>
#include <stdlib.h>


#define List_Size_Given 5

class List{
    private:
        int List_Size = List_Size_Given;
        int CurrentIndex;
        int TempCurrent = 0;
        int listArray[List_Size_Given] ={0};

    public: 
        List(){
            CurrentIndex = -1;
        }
        int IsEmpty(){
            if (CurrentIndex == -1){
                return 1;
            }else{
                return 0;
            }
        }
        int IsFull(){
            if(CurrentIndex == List_Size-1){
                return 1;
            }else{
                return 0;
            }
        }
        int Append(int val){
            if(IsFull()==0){
                for(TempCurrent = CurrentIndex;TempCurrent > -1;TempCurrent--){
                    listArray[TempCurrent+1]=listArray[TempCurrent];
                }
                listArray[0]=val;
                CurrentIndex++;
                return 1;
            }
            return 0;
        }
        void Display(){
            printf("\n[");
            for(TempCurrent=CurrentIndex;TempCurrent>0;TempCurrent--){
                printf("%d,",listArray[TempCurrent]);
            }
            printf("%d]",listArray[0]);
        }
};

int main(){
    List a;
    int opt,var;
    while(1==1){
        system("cls");
        printf("\n-------------------------------------------------\nOptions : \n\t0-Exit\n\t1-Append\n\t2-Display\n>>> ");
        scanf("%d",&opt);
        system("cls");
        switch (opt)
        {
        case 0:
            return 0;
        case 1:
            printf("\nValue : ");
            scanf("%d",&var);
            if(a.Append(var)==1){
                printf("\nInserted Successful");
            }else{
                printf("\nList is Full :(");
            }
            break;
        case 2:
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