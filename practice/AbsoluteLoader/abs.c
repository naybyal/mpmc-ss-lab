#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void main() {
	FILE *fp1, *fp2, *fp3;
	int i,j,hexaddr;
	char ch, line[100], addr[10];
	printf("---MEMORY ADDRESS C0NTENT---")
	fp1 =  fopen("input.txt", "r");\
	do {
		fscanf(fp1, "%s", line);
		if (line[0] == 'T') {
			for (i=1,j=0; i<=6; i++,j++) 
				addr[j] = line[i];
			addr[j] = '\0';

			fp2 = fopen("temp.txt", "r+");
			fprintf(fp2, "%s", addr);
			rewind(fp2);
			fscanf(fp2, "%x", &hexaddr);
			

			i=9;
			
			fopen(fp3, "w");
			while (line[i] != '\0') {
				printf("%x \t %c%c\n", hexaddr, line[i], line[i+1]);
				hexaddr += 1;
				i += 2;
			}
			fclose(fp2);
		}
	} while(!feof(fp1));
	fclose(fp1);
}
