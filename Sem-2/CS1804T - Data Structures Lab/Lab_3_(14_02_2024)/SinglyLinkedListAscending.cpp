#include <stdio.h>
#include "SLL_Ascending.h"

int main(){

    List NewList[3];
    int opt,var,listUse;
    while(1==1){
        system("cls");
        printf("\n-------------------------------------------------\nSelect List to Use:\n\t1 - List 1\n\t2 - List 2\n\t3 - List 3\n>>> ");
        scanf("%d",&listUse);
        if(!(listUse==1 || listUse == 2 || listUse == 3)){
            printf("Wrong Option : (");
            continue;
        }
        system("cls");
        printf("\n-------------------------------------------------\nOptions for List - %d : \n\t0-Exit\n\t1-Insert in Ascending\n\t2-Merge\n\t3-Display\n>>> ",listUse);
        scanf("%d",&opt);
        system("cls");
        listUse--;
        switch (opt)
        {
        case 0:
            return 0;
        case 1:
            printf("\nValue : ");
            scanf("%d",&var);
            if(NewList[listUse].Insert_asc(var)==1){
                printf("\nInserted Successful");
            }else{
                printf("\nList is Full : ");
            }
            break;
        case 2:
            if(listUse == 0){
                NewList[2] = NewList[listUse].Merge(&NewList[listUse+1]);
            }else if(listUse == 1){
                NewList[2] = NewList[listUse].Merge(&NewList[listUse-1]);
            }
            printf("Merged Lists :  ");
            break;
        case 3:
            printf("Values in List : ");
            NewList[listUse].Display();
            break;
        default:
            printf("Invalid Choise\n");
            break;
        }
        printf("\n\n(Press ENTER key to continue)");
        getchar();
        getchar();
    }
}