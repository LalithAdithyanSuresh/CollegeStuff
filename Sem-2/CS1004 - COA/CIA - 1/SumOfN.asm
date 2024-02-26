
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

.data
    Array db 10,20,30,40;
    ArraySize equ 4;
   
.code
    MOV Si,0;  
    MOV AX,0;
    MOV Bx,0;
    
    SILOOP:
        CMP Si,ArraySize;
        JGE End;   
        
        MOV Bl,[ArraySize + Si];
        
        ADD Al,Bl;
        
        JMP SILOOP;
        
        
    End:
        HLT;

ret




