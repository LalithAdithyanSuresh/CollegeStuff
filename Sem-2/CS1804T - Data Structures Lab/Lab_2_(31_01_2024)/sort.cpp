// Program to sort a list in either ascending or descending form
//This program uses selection sort
#include <stdio.h>
#include <stdlib.h>


void ascending(int *arr,int *n){
    int *first,*second,*tmp;
    first = (int *)malloc(sizeof(int));
    second = (int *)malloc(sizeof(int));
    tmp = (int *)malloc(sizeof(int));
    for(*first = 0;*first <*n -1;(*first)++){
        for(*second = *first + 1;*second < *n;(*second)++){
            if(*(arr + (*first)) > *(arr + (*second))){
                *tmp = *(arr + (*first)) ;
                *(arr + (*first)) = *(arr + (*second));
                *(arr + (*second)) = *tmp;
            }
        }
    }
}
void descending(int *arr,int *n){
    int *first,*second,*tmp;
    first = (int *)malloc(sizeof(int));
    second = (int *)malloc(sizeof(int));
    tmp = (int *)malloc(sizeof(int));
    for(*first = 0;*first <*n -1;(*first)++){
        for(*second = *first + 1;*second < *n;(*second)++){
            if(*(arr + (*first)) < *(arr + (*second))){
                *tmp = *(arr + (*first)) ;
                *(arr + (*first)) = *(arr + (*second));
                *(arr + (*second)) = *tmp;
            }
        }
    }
}

int main(){
    int *n,*Array,*var;
    n = (int *)malloc(sizeof(int));
    var = (int *)malloc(sizeof(int));
    printf("Enter the number of elements in the array : ");
    scanf("%d",n);
    Array = (int *)malloc(sizeof(int) * (*n));
    for(*var = 0; *var < *n;(*var)++){
        printf("Enter the element - %d : ",*var + 1);
        scanf("%d",Array + (*var));
    }
    printf("1-Ascending\n2-Descending\n>>");
    scanf("%d",var);
    if(*var == 1){
        ascending(Array,n);
    }else{
        descending(Array,n);
    }
    printf("Sorted array = ");
    for(*var = 0; *var < *n;(*var)++){
        printf("%d ",*(Array + (*var)));
    }
    printf("\n");
    return 0;
}