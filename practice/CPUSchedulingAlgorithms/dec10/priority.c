#include<stdio.h>

struct process {
	int bt, wt, tat, prio, id;
} p[50], temp;

void main() {
	int i,j,n;
	int totalTAT = 0, totalWT = 0;
	float avgTAT = 0, avgWT = 0;
	printf("Reading the number of processes... ");
	scanf("%d", &n);

	printf("Reading the burst times of each process... \n");
	for (i=0; i<n; i++) {
		printf("PROCESS %d\t->\t", i+1);
		p[i].id = i+1;
		scanf("%d", &p[i].bt);
	}
	printf("\nReading the priority of each process... \n");
	for (i=0; i<n; i++) {
                printf("PROCESS %d\t->\t", p[i].id);
                scanf("%d", &p[i].prio);
        }

	// sort by priority
	for (i=0; i<n; i++) {
		for (j=0; j<n-i-1; j++) {
			if (p[j].prio > p[j+1].prio) {
				temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			}
		}
	}
	
	p[0].wt = 0;
	
	// computing the wt of each process
	for (i=1; i<n; i++) {
		p[i].wt = p[i-1].wt + p[i-1].bt;
		totalWT += p[i].wt;
	}	

	// computing the tat
	for (i=0; i<n; i++) {
		p[i].tat = p[i].wt + p[i].bt;
		totalTAT += p[i].tat;
	}


	printf("\n\nPROCESS\tBT\tWT\tTAT\tPRIORITY\n");
	for (i=0; i<n; i++) 
		printf("%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].bt, p[i].wt, p[i].tat, p[i].prio);

	//	displaying the Gantt chart
	
	printf("\n\n---  	GANTT CHART  	  ---\n");
	for (i=0; i<n; i++)	
		printf("|\tP%d\t", p[i].id);
	printf("|\n");
	printf("0\t\t");
	for (i=0; i<n; i++) {
		printf("%d\t\t", p[i].tat);
	}
	avgTAT = (float)totalTAT/n;
	avgWT = (float)totalWT/n;
	printf("\n\n");
	printf("Average Waiting Time\t->\t%.1f ms\n", avgWT);
	printf("Average Turnaround Time\t->\t%.1f ms", avgTAT);
	printf("\n");
}
