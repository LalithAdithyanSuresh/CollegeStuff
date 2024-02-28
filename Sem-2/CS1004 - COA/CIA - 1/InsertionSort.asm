;Insertion Sort


org 100h

.data
    Values db 48, 127, 59, 98, 0, 111, 18, 89, 115, 73, 81, 49, 49, 58, 102, 6, 84, 36, 76, 95;
    length equ 20;

.code
    MOV Si,1;
    
    MainLoop:
        CMP Si,length;
        JGE End;
        
        MOV Di,Si;
        DEC Di;
        
        SubLoop:
            CMP Di,-1;
            JLE NextMain;
            INC Di;
            MOV Ah,[Values + Di];
            DEC Di;
            MOV Al,[Values + Di];
            
            CMP Ah,Al;
            JGE NextSub
            INC Di;
            MOV [Values + Di],Al; 
            DEC Di;
            MOV [Values + Di],Ah;
            
            NextSub:
                DEC Di;
                JMP SubLoop;
        NextMain:
            INC Si;
            JMP MainLoop;
    End:
        HLT;
   
ret