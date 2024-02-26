
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

.data
    Numbers db 4,2,3,5,6,7;
    Size equ 6;
    
.code
    MOV Si,0;     
    SILOOP:
        CMP Si,Size;
        JGE End;
   
        MOV Di,Si;
        INC Di;
        
        DILOOP:
            CMP Di,Size;
            JGE NextSI;
            
            MOV Ah,[Numbers + Si];
            MOV Al,[Numbers + Di];
            
            CMP Ah,Al;
            JLE NextDI;
            
            MOV [Numbers + Si],Al;
            MOV [Numbers + Di],Ah;
            
            
            NextDI:
                INC Di;
                JMP DILOOP;
            
        NextSI:
            INC Si;
            JMP SILOOP;
   
    End:
        HLT

