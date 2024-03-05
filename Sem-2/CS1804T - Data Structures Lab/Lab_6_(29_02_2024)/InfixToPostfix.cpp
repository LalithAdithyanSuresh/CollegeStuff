#include <stdio.h>
#include "ListADT.h"
#include "StackADTUsingSLL.h"
#include <stdlib.h>



int main(){
    int opt=1,tempPrec,stackPrec;
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
                        Exp.Delete_Beg_Node();
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
                    OpStack.Insert_Beg_Node((char)(tempPrec * stackPrec));
                    break;
                case '/':
                    OpStack.Insert_Beg_Node((char)(tempPrec / stackPrec));
                    break;
                case '%':
                    OpStack.Insert_Beg_Node((char)(tempPrec % stackPrec));
                    break;
                case '+':
                    OpStack.Insert_Beg_Node((char)(tempPrec + stackPrec));
                    break;
                case '-':
                    OpStack.Insert_Beg_Node((char)(tempPrec - stackPrec));
                    break;
                default:
                    OpStack.Insert_Beg_Node(temp);
                    break;
                }
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
