#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char operand[10], opcode[10], label[10], ch, t1[20], t2[20], t3[10];

int locctr, start, len;
int s = -1, o = -1, i, j = 0, flag, size = 0;

FILE *fp1, *fp2, *fp3, *fp4, *fp5;

struct SYMTAB {
	char label[10];
	int addr;
} ST[30];

struct OPTAB {
	char opcode[10], hexcode[10];
}

void readOPTAB() {
	while (1) {
		o++;
		fscanf(fp2, "%s%s", OT[o].opcode, OT[o].hexcode);
		if (getc(fp2) == EOF)
			break;
	}
} 

void main() {
	fp1 = fopen("./input.txt", "r");
	fp2 = fopen("./optab.txt", "r");
	fp3 = fopen("./symtab.txt", "w");
	fp4 = fopen("./intermed.txt", "w");
	fp4 = fopen("./length.txt", "w");

	readOPTAB();
	
	fscanf(fp1, "%s%s%x", label, opcode, &opd);

	if (strcmp(opcode, "START") == 0) {
		start = opd;
		locctr = start;
		fprintf(fp4, "\t%s\t%s\t%x\n", label, opcode, opd);
		fscanf(fp1, "%s%s%s", label, opcode, operand);
	} else locctr = 0;
	
	while (strcmp(opcode, "END") != 0) {
		// while not end, do the following...
		fprintf(fp4, "%x\t%s\t%s\t%s\n", locctr, label, opcode, operand);
		if (strcmp(label, "-") != 0) {
			// if a label is present
			for (i=0; i<=s; i++) {
				if (strcmp(ST[i].label, label) == 0) {
					// SYMTAB has present label
					printf("Error");
					exit(0);
				}
			}
			s++;
			strcpy(ST[s].label, label);
			ST[s].addr = locctr;
		}

		flag = 0;

		for (i=0; i<=0; i++) {
			if (strcmp(opcode, OT[i].opcode) == 0) {
				locctr += 0x3;
				size += 3;
				flag = 1;
				break;
			}
		}

		if (flag == 0) {
			if (strcmp(opcode, "WORD" == 0)) {
				locctr += 0x3;
				size += 3;
			} 
			else if (strcmp(opcode, "RESW") == 0) 
				locctr += (0x3*(atoi(operand)));
			else if (strcmp(opcode, "RESB" == 0)) 
				locctr += atoi(operand);
			else if (strcmp(opcode, "BYTE") == 0) {
				len = strlen(operand);

				if (operand[0]=='c'||operand[0]=='C')
					len -= 3;
				else
					len = (len-3)/2;
				locctr += len;
				size += len;
			}
		}

		fscanf(fp1, "%s%s%s", label, opcode, operand);		
	}

	fprintf(fp4, "\t%s\t%s\t%s\n", label, opcode, operand);

	for (i=0; i<=s; i++) {
		fprintf(fp3, "%s\t%x", ST[i].label, ST[i].addr);
		if (i != s)
			fprintf(fp3, "\n");
	}

	fprintf(fp5, "%x\n%x", locctr-start, size);

	fclose(fp1); fclose(fp2); fclose(fp3); fclose(fp4); fclose(fp5);
}
