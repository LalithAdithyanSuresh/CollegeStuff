#include <stdio.h>
#include "ListADT.h"
#include "StackADTUsingSLL.h"
#include <stdlib.h>

struct Variable{
    char var;
    int val;
};

int Valueof(char vari,int *VarCount,struct Variable **vars);
int ChangeValueof(char vari,int value,int *VarCount,struct Variable **vars);

int main(){
    struct Variable *Vars=nullptr;
    int opt=1,tempPrec,stackPrec,EXPlen=0;
    int VarCount = 0;
    char temp,c;
    List Exp,Pfix;
    Stack OpStack;
    INTStack Answer;
    enum Prec {assign,addsub,muldivmod};
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
                    EXPlen++;
            }
            printf("Getting values of variables >>\n");
            while(EXPlen>0){
                temp = Exp.DisplayFront();
                Exp.Append_Node(temp);
                Exp.Delete_Beg_Node();
                if(!(temp=='*' || temp=='/' || temp=='%' || temp=='+' || temp=='-' || temp == '=')){
                    if(Valueof(temp,&VarCount,&Vars) == 0){
                        printf("Value of %c : ",temp);
                        scanf("%d",&opt);
                        ChangeValueof(temp,opt,&VarCount,&Vars);
                    }
                }
                EXPlen--;
            }
            printf("\nSaved Variables\n\n");
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
                if(temp=='*' || temp=='/' || temp=='%' || temp=='+' || temp=='-'){

                    stackPrec=Answer.Display();
                    Answer.Delete_Beg_Node();
                    tempPrec = Answer.Display();
                    Answer.Delete_Beg_Node();
                }else if(temp=='='){
                    stackPrec = Answer.Display();
                    Answer.Delete_Beg_Node();
                }
                switch (temp)
                {
                case '*':
                    ans = tempPrec * stackPrec;
                    break;
                case '/':
                    ans = tempPrec / stackPrec;
                    break;
                case '%':
                    ans = tempPrec % stackPrec;
                    break;
                case '+':
                    ans = tempPrec + stackPrec;
                    break;
                case '-':
                    ans = tempPrec - stackPrec;
                    break;
                case '=':
                    ans = stackPrec;
                default:
                    ans = Valueof(temp,&VarCount,&Vars);
                    break;
                }
                Answer.Insert_Beg_Node(ans);
                Pfix.Delete_Beg_Node();
            }
            printf("%d",Answer.Display());
            break;
        default:
            break;
        }
        printf("\n");
    }
    


}

// To get the value of a variable if it is available
int Valueof(char vari,int *VarCount,struct Variable **vars){
    for (int i = 0; i < *VarCount; i++) {
        if ((*vars)[i].var == vari) {
            return (*vars)[i].val;
        }
    }
    return 0;
}

// To change a variables value if it exists else create a new variable structure and store value
int ChangeValueof(char vari,int value,int *VarCount,struct Variable **vars){
    for (int i = 0; i < *VarCount; i++) {
        if ((*vars)[i].var == vari) {
            (*vars)[i].val = value;
            return 1;
        }
    }
    (*VarCount)++;
    *vars = (struct Variable *)realloc(*vars, (*VarCount) * sizeof(struct Variable));
    if (*vars == nullptr) {
        return 0;
    }
    (*vars)[*VarCount - 1].var = vari;
    (*vars)[*VarCount - 1].val = value;
    return 1;
}