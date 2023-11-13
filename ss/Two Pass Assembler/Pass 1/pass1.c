//Implement pass1 of 2-pass Assembler
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<curses.h>

char opcode[10],operand[10],label[10],ch,t1[20],t2[20],t3[10];
int locctr,start,len,s=-1,o=-1,i,j=0,flag,size=0,opd;
FILE *fp1,*fp2,*fp3,*fp4,*fp5;

struct SYMTAB
{
    char label[10];
    int addr;       
}ST[30];

struct OPTAB
{
    char opcode[10],hexcode[10];
}OT[30];

void read_OPTAB()
{
    while(1)
    {
            o++;
            fscanf(fp2,"%s%s",OT[o].opcode,OT[o].hexcode); 
            if(getc(fp2)==EOF)       
				break;                    
    }                  
}

int main()
{
	fp1=fopen("./input.txt","r");
	fp2=fopen("./optab.txt","r");
	fp3=fopen("./symtab.txt","w");
	fp4=fopen("./intermed.txt","w");
	fp5=fopen("./length.txt","w");
	read_OPTAB();    // read OPTAB
	
    //read_line();	// read the first line 
    fscanf(fp1,"%s%s%x",label,opcode,&opd);
	if(strcmp(opcode,"START")==0)
	{
		start=opd;
		locctr=start;
		fprintf(fp4,"\t%s\t%s\t%x\n",label,opcode,opd);
		fscanf(fp1,"%s%s%s",label,opcode,operand);	// read the next line 
	}
	else
		locctr=0;

	// do until END
	while(strcmp(opcode,"END")!=0)
	{
		fprintf(fp4,"%x\t%s\t%s\t%s\n",locctr,label,opcode,operand);  //Write this line into intermediate file
		if(strcmp(label,"-")!=0)   //if label present
		{
		  	for(i=0;i<=s;i++)
        	{
                if(strcmp(ST[i].label,label)==0)  //if SYMTAB contains the present label
                {
                    printf("Error");
                    exit(0);                                
                }           
            }
            s++;
            strcpy(ST[s].label,label);   ST[s].addr=locctr;   //if SYMTAB doesnot contains the present label
        }
		// Search OPTAB for opcode
		flag=0;
		for(i=0;i<=o;i++)
		{
			if(strcmp(opcode,OT[i].opcode)==0)  //if opcode is in OPTAB
			{
				locctr+=0x3;
				size=size+3;
				flag=1;
				break;
			}
		}
		if(flag==0)
    	{
        	if(strcmp(opcode,"WORD")==0)        //if opcode = "WORD"
        	{
        		locctr+=0x3;
				size=size+3;
			}	
    		else if(strcmp(opcode,"RESW")==0)   //if opcode = "RESW"
    			locctr+=(0x3*(atoi(operand)));
    		else if(strcmp(opcode,"RESB")==0)   //if opcode = "RESB"
    			locctr+=(atoi(operand));
    		else if(strcmp(opcode,"BYTE")==0)   //if opcode = "BYTE"
    		{
    			len=strlen(operand);
    			if(operand[0]=='C' || operand[0]=='c')
    				len=len-3;
    			else
    				len=(len-3)/2;
    			locctr+=len;
				size=size+len;
			}
        }
		
		fscanf(fp1,"%s%s%s",label,opcode,operand); //read the next line
	}
	fprintf(fp4,"\t%s\t%s\t%s\n",label,opcode,operand);	//Write last line into intermediate file
	//write the contents of ST to symboltab.txt
    for(i=0;i<=s;i++)
	{
        fprintf(fp3,"%s\t%x",ST[i].label,ST[i].addr); 
		if(i!=s) 
			fprintf(fp3,"\n");                           
    }
	fprintf(fp5,"%x\n%x",locctr-start,size);
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
    fclose(fp5);
}
