//To find the sum of first n numbers
#include <stdio.h>
#include <stdlib.h>

int main(){
	int *sum,*n;
	n = (int *)malloc(sizeof(int));
	sum = (int *)malloc(sizeof(int));
	printf("\n Enter the value of n : ");
	scanf("%d",n);
	while(*n != 0){
		*sum += *n;
		*n-=1;
	}
	printf("\n The sum is : %d\n",*sum);
	return 0;
}
