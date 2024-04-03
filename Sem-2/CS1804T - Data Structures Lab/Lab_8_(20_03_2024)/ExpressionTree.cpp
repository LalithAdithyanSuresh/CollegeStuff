#include <stdio.h>
#include <stdlib.h>
#include "Tree_Stack.h"
int main(){
    Tree T;
    Stack S;
    char array[100],in;
    int opt = 0,c;
    char *ptr = &array[0];
    while(1==1){
        printf("Options\n\t1. Postfix Expression\n\t2. Construct Expression Tree\n\t3. Preorder\n\t4. Inorder\n\t5. Postorder\n\t6. Exit\n>>>");
        scanf("%d",&opt);
        switch (opt)
        {
        case 1:
            getchar();
            c=-1;
            while((in = getchar()) != EOF && in!='\n'){
                c++;
                array[c] = in;
            }
            c++;
            printf("Got IT !");
            break;
        case 2:
            if(T.ConstructExp(ptr,c,&S)==1){
                printf("Construction Of Expression Tree is COMPLETE !");
            }else{
                printf("The post Fix Expression is INVALID.");
            }
            break;
        case 3:
            T.PreOrder();
            break;
        case 4:
            T.InOrder();
            break;
        case 5:
            T.PostOrder();
            break;
        case 6:
            printf("Exiting !");
            return 1;
        default:
            break;
        }
    }
    return 1;
}
