ASSUME CS:CODE, DS:DATA

DATA SEGMENT
	LIST DB 1,9,5,4,2
	KEY DB 2
	MSG1 DB 0AH, 0DH, "ELEMENT NOT FOUND$"
	MSG2 DB 0AH, 0DH, "ELEMENT FOUND$"
DATA ENDS

PRINT MACRO MSG
	LEA DX, MSG
	MOV AH, 09H
	INT 21H
	INT 3
ENDM

CODE SEGMENT 
START:	MOV AX, DATA
	MOV DS, AX
	MOV CL, 5
	MOV BL, KEY
	LEA SI, LIST
	MOV AL, [SI]
REPEAT:	CMP AL, BL
	JZ DOWN
	INC SI
	DEC CL
	JNZ REPEAT

	PRINT MSG1
	JMP STOP
	
DOWN:	PRINT MSG2	
STOP:	MOV AH, 4CH
	INT 21H
CODE ENDS
END START
