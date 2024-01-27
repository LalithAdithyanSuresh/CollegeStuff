#include "calculator.h"

int main(){
    int num1=1,num2=1,opt = 1;
    while(opt !=6){
        printf("\nChoose Your Option : \n\t1.Set\n\t2.Add\n\t3.Subtract\n\t4.Multiply\n\t5.Divide\n\t6.Exit\n>>");
        scanf("%d",&opt);
        switch (opt)
        {
        case 1:
            printf("Set the value of Num 1 : ");
            scanf("%d",&num1);
            printf("Set the value of Num 2 : ");
            scanf("%d",&num2);
            break;
        case 2:
            printf("Sum Of %d and %d is %d",num1,num2,Add(&num1,&num2));
            break;
        case 3:
            printf("Difference Of %d and %d is %d",num1,num2,Sub(&num1,&num2));
            break;
        case 4:
            printf("Product Of %d and %d is %d",num1,num2,Mul(&num1,&num2));
            break;
        case 5:
            printf("Quotient Of %d and %d is %f",num1,num2,Div(&num1,&num2));
            break;
        case 6:
        printf("Program ended\n");
            return 0;
            break;
        
        default:
            printf("Incorrect Option");
            break;
        }
    }

}