org 100h

.data
    Numbers db 60,30,40,50,20,70,10;
    ArraySize equ 7;
 
.code
    MOV Si, 0;

SelectSort:
    MOV Di, Si;
    INC Di;

    CMP Si, ArraySize;
    JGE end;

InnerLoop:
    CMP Di, ArraySize;
    JGE NextElem;

    MOV Al, [Numbers + Si];
    MOV Bl, [Numbers + Di];

    CMP Al, Bl;
    JLE NoSwap;

    MOV [Numbers + Si], Bl;
    MOV [Numbers + Di], Al;

NoSwap:
    INC Di;
    JMP InnerLoop;

NextElem:
    INC Si;
    JMP SelectSort;
end:     
    HLT

ret




