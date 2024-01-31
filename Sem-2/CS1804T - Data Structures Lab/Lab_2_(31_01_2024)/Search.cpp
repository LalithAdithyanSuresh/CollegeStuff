// Program to find a number in an array
#include <stdio.h>
#include <stdlib.h>

int main(){
    int *Array,*n,*search,*var;
    n = (int *)malloc(sizeof(int));
    search = (int *)malloc(sizeof(int));
    var = (int *)malloc(sizeof(int));
    printf("Enter the number of elements in the array : ");
    scanf("%d",n);
    Array = (int *)malloc(sizeof(int) * (*n));
    
    for(*var  = 0;*var<*n;(*var)++){
        printf("Enter the number - %d : ",(*var) + 1);
        scanf("%d",(Array + (*var)));
    }
    printf("Enter the number to search for : ");
    scanf("%d",search);
    for(*var = 0;*var < *n;(*var)++){
        if(*(Array+ (*var)) == *search){
            printf("Found The Element at index : %d\n",*var);
            return 0;
        }
    }
    printf("Element not found in list\n");
    return 0;
}