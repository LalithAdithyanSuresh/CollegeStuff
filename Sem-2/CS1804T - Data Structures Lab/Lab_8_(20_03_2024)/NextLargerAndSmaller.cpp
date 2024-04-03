#include "SLL.h"
#include <stdio.h>

int main(){
    List L;
    int c,n,s,max,min;
    printf("Enter the count of numbers to be enetered : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter Number - %d : ",i+1);
        scanf("%d",&c);
        L.Append_Node(c);
    }
    printf("Enter number to find the next smallest and next greatest Number");
    scanf("%d",&s);
    int i = L.Delete_Beg_Node();
    max = i;
    min = i;
    for(int i=0;i<n;i++){
        c = L.Delete_Beg_Node();
        if(c < s && c > min){
            min = c;
        }
        if(max<s && c>s){
            max = c;
        }
        if(c > s && c < max){
            max = c;
        }
    }
    printf("The next smaller element than %d is %d and the next larger element is %d",s,min,max);
}