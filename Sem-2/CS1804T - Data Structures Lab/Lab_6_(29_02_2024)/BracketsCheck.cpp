#include "StackADTUsingSLL.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    Stack stack;
    int o=0,opt,n;
    while (1==1)
    {
        printf("\n--------------------------------\nOPTIONS\n\t1 - Check Balance\n\t2 - Exit\n>>>");
        scanf("%d",&opt);
        getchar();
        switch (opt)
        {
        case 1:
            printf("Enter the number of characters : ");
            scanf("%d",&n);
            getchar();
            while(n>0){
                char Ch;
                Ch = getchar();
                if(Ch == '(' || Ch == ')'){
                    stack.Insert_Beg_Node(Ch);
                }
                n--;
            }
            while(stack.Display() != '_'){
                if(stack.Display()==')')o++;
                else o--;
                if(o<0){
                    printf("\nThe paranthesis are not balanced");
                    break;
                }
                stack.Delete_Beg_Node();
            }
            if(o == 0){
                printf("\nThe Check is valid");
            }else{
                printf("The Paranthesis are not balanced");
            }
            break;
        
        default:
            break;
        }
    }
    
}