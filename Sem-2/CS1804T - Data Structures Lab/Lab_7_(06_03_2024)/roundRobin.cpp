#include <stdio.h>
#include <stdlib.h>
#include "CircularPriorityQueue_Program.h"
#include "CircularQueue_Program.h"

struct Node{
    int A_time;
    int B_time;
    int P_Num;
    struct Node *Next;
};



int CPU_Time = 0; //Clock time for the CPU
int Q_Time = 0;  // Max Time a program can run consecutively in the CPU
int E_Time = 0;  // Current Program's CPU time
int P_Count = 0;
struct Node * E_P = nullptr; // A pointer to the Program that is currently being executed in the CPU
struct Node * T_P = nullptr; // Temporary pointer
P_Queue ProgramList;
Queue WaitQueue;


// Function that Performs instruction of the next Clock Cycle
void NextClockCycle(){
    while(ProgramList.peek()!= -1 && ProgramList.peek() <= CPU_Time){
        T_P = (struct Node*)ProgramList.dequeue();
        printf("\nAdding P-%d to the wait queue",T_P->P_Num);
        WaitQueue.enqueue(T_P->A_time,T_P->B_time,T_P->P_Num);
    }
    if(E_P!=nullptr && (E_Time == Q_Time || E_P->B_time-1 <=0)){
        if(E_P->B_time-1 <= 0){
            printf("\nP-%d has completed Execution",E_P->P_Num);
            free(E_P);
            E_P = nullptr;
        }else{
            E_P->B_time--;
            printf("\nP-%d has used its Quota with remaining Burst : %d",E_P->P_Num,E_P->B_time);
            WaitQueue.enqueue(E_P->A_time,E_P->B_time,E_P->P_Num);
            E_P = nullptr;
        }
        E_Time = 1;
    }else if(E_P!=nullptr){
        E_P->B_time--;
        E_Time++;
        
    }
    if(WaitQueue.peek() != -1 && E_P == nullptr){
        E_P = (struct Node*)WaitQueue.dequeue();
        printf("\nP-%d has started its Quota",E_P->P_Num);
        E_Time = 1;

    }
    printf("\n>>>>CPU TIME : %d",CPU_Time);
    CPU_Time++;
}






int main(){
    int a,b,opt=1;
    system("cls");
    system("cls");
    printf("Enter Time Quantum: ");
    scanf("%d",&Q_Time);
    printf("Creating Program List\n\n");
    while(opt!=0){
        printf("Do you want to enter a new Program ? (y - 1 / n - 0) : ");
        scanf("%d",&opt);
        switch (opt)
        {
        case 1:
            system("cls");
            system("cls");
            P_Count++;
            printf("Enter Details of P-%d",P_Count);
            printf("\n\tAccess Time : ");
            scanf("%d",&a);
            printf("\tBurst Time : ");
            scanf("%d",&b);
            ProgramList.enqueue(a,b,P_Count);
            break;
        default:
            break;
        }
        system("cls");
        system("cls");
    }
    printf("Press ENTER key to start execution\n\n");
    getchar();
    getchar();
    while(true){
        NextClockCycle();
        if (ProgramList.peek() == -1 && WaitQueue.peek() == -1 && E_P == nullptr) {
        break;
        }
    }
    CPU_Time--;
    printf("\n\nProgram executed in %d Clock cycles\n",CPU_Time);
    printf("Execution Complete");
    

}
