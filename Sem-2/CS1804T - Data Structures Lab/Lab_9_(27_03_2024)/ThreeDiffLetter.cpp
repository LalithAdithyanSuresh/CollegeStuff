#include <stdio.h>
#include <stdlib.h>
#include "SLL.h"

int main(){
    List L;
    struct List::First3 *a;
    char in;
    int c=0;
    getchar();
    while((in = getchar()) != EOF && in!='\n'){
        L.Append_Node(in);
    }
    while((a = L.firstThree()) != nullptr){
        if(a->F != a->L && a->F != a->M && a->L!= a->M){
            c++;
        }  
        L.Delete_Beg_Node();
    }
    printf("Total number of unique Sub Strings = %d",c);

}