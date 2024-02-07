#include <stdio.h>
#define List_Size_Given 5

class List{
    private:
        int List_Size = List_Size_Given;
        int CurrentIndex = -1;
        int TempCurrent = 0;
        int listArray[List_Size_Given] ={0};

    public: 
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
        void Append(int val){
            if(IsFull()==0){
                for(TempCurrent = CurrentIndex;TempCurrent > -1;TempCurrent--){
                    listArray[TempCurrent+1]=listArray[TempCurrent];
                }
                listArray[0]=val;
                CurrentIndex++;
                // Display();
                // printf("\nInserted %d\n",val);
            }
        }
        void Display(){
            for(TempCurrent=CurrentIndex;TempCurrent>-1;TempCurrent--){
                printf("%d,",listArray[TempCurrent]);
            }
        }
};

int main(){
    List a;
    int opt,var;
    while(1==1){
        printf("\n\nOptions : \n\t1-Append\n\t2-Display\n>>>");
        scanf("%d",&opt);
        switch (opt)
        {
        case 0:
            return 0;
        case 1:
            printf("\nValue : ");
            scanf("%d",&var);
            a.Append(var);
            break;
        case 2:
            printf("Values in List : ");
            a.Display();
            break;
        default:
            printf("Invalid Choise\n");
            break;
        }
    }
}