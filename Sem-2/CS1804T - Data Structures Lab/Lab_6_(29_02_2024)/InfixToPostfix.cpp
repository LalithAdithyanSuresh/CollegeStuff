#include <stdio.h>
#include "ListADT.h"
#include "StackADTUsingSLL.h"
#include <stdlib.h>

struct Variable{
    char var;
    int val;
};

int Valueof(char vari,int *VarCount,struct Variable *vars);
int ChangeValueof(char vari,int value,int *VarCount,struct Variable *vars);

int main(){
    struct Variable *Vars=nullptr;
    int opt=1,tempPrec,stackPrec,*VarCount = 0;
    char temp,c;
    List Exp,Pfix;
    Stack OpStack;
    enum Prec {assign,addsub,muldivmod};
    enum Asso {LR,RL};
    while (opt!=0){
        printf("Options:\n\t1 - Input Expression\n\t2 - Infix to Postfix\n>>>");
        scanf("%d",&opt);
        switch (opt)
        {
        case 1:
            getchar();
            printf("Enter Your Expression >> ");
            while ((c = getchar()) != '\n' && c != EOF) {
                    Exp.Append_Node(c);
                }
            break;
            
        case 2:
            while((c = Exp.DisplayFront()) != '~'){
                if(c=='*' || c=='/' || c=='%')tempPrec=muldivmod;
                else if(c=='+' || c=='-')tempPrec=addsub;
                else if(c=='=')tempPrec=assign;
                else{
                    Pfix.Append_Node(c);
                    Exp.Delete_Beg_Node();
                    continue;
                }
                
                while(1==1){
                    if((temp=OpStack.Display())== '~'){
                        OpStack.Insert_Beg_Node(c);
                        Exp.Delete_Beg_Node();
                        break;
                    }
                    if(temp=='*' || temp=='/' || temp=='%')stackPrec=muldivmod;
                    else if(temp=='+' || temp=='-')stackPrec=addsub;
                    else stackPrec=assign;
                    
                    if(stackPrec == tempPrec){
                        if(stackPrec == muldivmod || stackPrec==addsub){
                            Pfix.Append_Node(temp);
                            OpStack.Delete_Beg_Node(); 
                        }
                        else{
                            OpStack.Insert_Beg_Node(temp);
                        }
                    }
                    else if(stackPrec < tempPrec){
                        OpStack.Insert_Beg_Node(c);
                        Exp.Delete_Beg_Node();
                        break;
                    }
                    else{
                        temp=OpStack.Display();
                        Pfix.Append_Node(temp);
                        OpStack.Delete_Beg_Node();
                    }

                }

            }   
            while((temp=OpStack.Display())!= '~'){
                Pfix.Append_Node(temp);
                OpStack.Delete_Beg_Node(); 
            }
            Pfix.Display();
            break;
        
        case 3:
        char ans;
            while((temp = Pfix.DisplayFront())!='~'){
                if(temp=='*' || temp=='/' || temp=='%' || temp=='+' || temp=='-' || temp == '='){

                    stackPrec=(int)OpStack.Display() - 48;
                    OpStack.Delete_Beg_Node();
                    tempPrec = (int)OpStack.Display() - 48;
                    OpStack.Delete_Beg_Node();
                }
                switch (temp)
                {
                case '*':
                    ans = (char)(tempPrec * stackPrec + 48);
                    break;
                case '/':
                    ans = (char)(tempPrec / stackPrec + 48);
                    break;
                case '%':
                    ans = (char)(tempPrec % stackPrec + 48);
                    break;
                case '+':
                    ans = (char)(tempPrec + stackPrec + 48);
                    break;
                case '-':
                    ans = (char)(tempPrec - stackPrec + 48);
                    break;
                default:
                    ans = temp;
                    break;
                }
                OpStack.Insert_Beg_Node(ans);
                Pfix.Delete_Beg_Node();
            }
            printf("%c",OpStack.Display());
            break;
        default:
            break;
        }
        printf("\n");
    }
    


}


int Valueof(char vari,int *VarCount,struct Variable *vars){
    for (int i = 0; i < *VarCount; i++) {
        if (vars[i].var == vari) {
            return vars[i].val;
        }
    }
    return 0;
}

int ChangeValueof(char vari,int value,int *VarCount,struct Variable *vars){
    for (int i = 0; i < *VarCount; i++) {
        if (vars[i].var == vari) {
            vars[i].val = value;
            return 1;
        }
    }
    (*VarCount)++;
    vars = (struct Variable *)realloc(vars, (*VarCount) * sizeof(struct Variable));
    if (vars == nullptr) {
        return 0;
    }
    vars[*VarCount - 1].var = vari;
    vars[*VarCount - 1].val = value;
    return 1;
}