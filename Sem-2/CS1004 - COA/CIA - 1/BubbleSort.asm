
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

.data
    Integers db 50,25,100,8,78;
    NoOfElem equ 5;
    
    
.code
    MOV Si,0;
    
    MOV CX,NoOfElem;
    DEC CX;
    SILOOP:
        CMP Si,CX;
        JGE END;
    
        MOV Di,0;           
        MOV DX,NoOfElem;
        DEC DX;
        SUB DX,Si;
        DILOOP:    
            CMP Di,DX;
            JGE NextElem;
            MOV Ah,[Integers + Di];  
            INC Di; 
            MOV Al,[Integers + Di];  
            CMP Ah,Al;
            JLE Continue;   
        
            DEC Di;
            MOV [Integers + Di],Al;   
            INC Di;
            MOV [Integers + Di],Ah;
        
        
        
            Continue:
                JMP DILOOP;
            
        NextElem:
            INC Si;
            JMP SILOOP;
    END:
        HLT;
ret




