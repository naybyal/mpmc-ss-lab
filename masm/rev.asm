ASSUME CS:CODE, DS:DATA, SS:STACK
DATA SEGMENT 
	STR DB "hello$"
DATA ENDS

STACK SEGMENT
		
STACK ENDS

CODE SEGMENT
START:	MOV AX, DATA
	MOV DS, AX
	LEA SI, STR
	MOV AL, 0
	MOV CL, 6
AGAIN:	MOV BL, [SI]
	PUSH BL
	INC SI
	CMP AL, CL
	JL AGAIN
	
PRINT:	POP DL
	MOV AH, 02H
	INT 21H
	DEC CL
	JNZ PRINT
	HLT
	MOV AH, 4CH 
	INT 21H
CODE ENDS
END START
