

///        L0 TO L4 ARE USED UP
///        ARGUMENTS : COUNT OF NUMBER OF BLOCKS REQUIRED BY GETCOUNT
///        RESULT : ADDRESS 

ALLOCATION:
PUSH BP
MOV BP,SP
PUSH R0
PUSH R0
MOV R1,BP
MOV R2,2
SUB R1,R2
MOV R2,1
SUB R1,R2
MOV R0,[R1]
MOV R2,BP
MOV R1,1
ADD R2,R1
MOV [R2],R0
MOV R0 , 1
MOV R2,BP
MOV R1,2
ADD R2,R1
MOV [R2],R0
L0:
MOV R1,BP
MOV R0,1
ADD R1,R0
MOV R0,[R1]
MOV R1 , 0
GT R0 , R1
JZ R0 , L1
MOV R1,BP
MOV R0,2
ADD R1,R0
MOV R0,[R1]
MOV R0, [R0]///
MOV R1,BP
MOV R0,1
ADD R1,R0
MOV R0,[R1]
MOV R1 , 1
SUB R0 ,R1
MOV R2,BP
MOV R1,1
ADD R2,R1
MOV [R2],R0
JMP L0
L1:
MOV R1,[BP]
MOV R0,2
ADD R1, R0
MOV R0,[R1]
MOV R1, [256]
MOV [256],R0
MOV R0, [R1]
MOV R1,BP
MOV R2,2
SUB R1,R2
MOV [R1],R0
POP R0
POP R0
MOV BP,[SP]
POP R0
RET
