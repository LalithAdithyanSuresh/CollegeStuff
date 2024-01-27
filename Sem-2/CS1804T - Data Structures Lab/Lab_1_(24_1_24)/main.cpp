//To find the sum of n numbers given by the user
#include <stdio.h>
#include <stdlib.h>

int main(){
	int *sum,*n,*temp;
	n = (int *)malloc(sizeof(int));
	sum = (int *)malloc(sizeof(int));
	temp = (int *)malloc(sizeof(int));
	*sum = 0;
	printf("\n Enter the value of n : ");
	scanf("%d",n);
	printf("Enter the integers : ");
	while(*n != 0){
		scanf("%d", temp);
		*sum += *temp;
		*n-=1;
	}
	printf("\n The sum is : %d\n",*sum);
	return 0;
}
