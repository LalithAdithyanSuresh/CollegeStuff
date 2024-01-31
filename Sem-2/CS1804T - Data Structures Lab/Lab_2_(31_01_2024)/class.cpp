// Program to sort,insert,find student roll numbers

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

int *search(int *array,int *n,int *find){
    int *Start,*End,*mid;
    Start = (int *)malloc(sizeof(int));
    End = (int *)malloc(sizeof(int));
    *Start = 0;
    *End = *n;
    while(*Start <= *End){
        *mid = (int)((*Start + *End) /2);
        if(*(array + *mid) == *find){
            printf("Found the Roll Number in pos - %d\n",*mid + 1);
            return mid;
        }else {
            if(*(array + *mid) < *find){
                *Start = *mid  + 1;
            }else{
                *End = *mid - 1;
            }
        }
    }
    printf("Roll number not found :(\n");
    return mid;
}


int main(){
    int *n,*array,*var,*find;
    n = (int *)malloc(sizeof(int));
    printf("Enter the number of students : ");
    scanf("%d",n);
    var = (int *)malloc(sizeof(int));
    find = (int *)malloc(sizeof(int));
    array = (int *)malloc(sizeof(int) * (*n));
    for(*var  = 0;*var<*n;(*var)++){
        printf("Enter the roll - %d : ",(*var) + 1);
        scanf("%d",(array + (*var)));
    }
    ascending(array,n);
    printf("Sorted Roll Numbers = ");
    for(*var = 0; *var < *n;(*var)++){
        printf("%d ,",*(array + (*var)));
    }
    printf("\nEnter the Roll of the Person to search for : ");
    scanf("%d",find);
    search(array,n,find);
    return 0;

}