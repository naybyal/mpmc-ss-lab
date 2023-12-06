#include<stdio.h>
#include<string.h>
#include<curses.h>

int addr,w=0,start,ptaddr,length=0,end,count=0,k,taddr,addres,i=0,l;
char input[10],lbl[10];

FILE *f1,*f2;

void check() {
	count++;
	addres++;
	taddr=taddr+1;
	if(count==4) {
		fprintf(f2," ");
		i++;
		if(i==4) {
			fprintf(f2,"\n\n%x\t\t",taddr);
			i=0;
		}
		count=0;
	}
}

void main() {
	f1=fopen("input1.txt","r");
	f2=fopen("output1.txt","w");
	fscanf(f1,"%s",input);
	fprintf(f2,"........................................................\n");
	fprintf(f2,"MEMORY ADDRESS CONTENT\n");
	while(strcmp(input,"E")!=0) {
		if(strcmp(input,"H")==0) {
			fscanf(f1,"%s%x%x%s",lbl,&start,&end,input);
			addres=start; 
		}
		else if(strcmp(input,"T")==0) {
			l=length;
			ptaddr=addr;
			fscanf(f1,"%x%x%s",&taddr,&length,input);
			addr=taddr;
			if(w==0) {
				ptaddr=addres;
				w=1; 
			}
			for (k=0;k<(taddr-(ptaddr+1));k++){
				addres=addres+1;
				fprintf(f2,"xx");
				count++;
				if(count==4) {
					fprintf(f2," ");
					i++;
					if(i==4) {
						fprintf(f2,"\n\n%x\t\t",addres);
						i=0; 
					}
					count=0; 
				}
			}
			if(taddr==start)
				fprintf(f2,"\n\n%x\t\t",taddr);
			fprintf(f2,"%c%c",input[0],input[1]);
			check();
			fprintf(f2,"%c%c",input[2],input[3]);
			check();
			fprintf(f2,"%c%c",input[4],input[5]);
			check();
			fscanf(f1,"%s",input); 
		}
		else {
			fprintf(f2,"%c%c",input[0],input[1]);
			check();
			fprintf(f2,"%c%c",input[2],input[3]);
			check();
			fprintf(f2,"%c%c",input[4],input[5]);
			check();
			fscanf(f1,"%s",input); 
		}
	}
	fclose(f1);
	fclose(f2); 
}

