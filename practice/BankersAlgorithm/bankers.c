#include<stdio.h>
#include<stdlib.h>

int i,j,k, n,r,idx =0;
int available[10], state[10], maxClaim[10][10],allocRes[10][10], need[10][10];
int sequence[10];

void main() {
	int change;

	printf("Reading the number of processes... ");
	scanf("%d", &n);

	printf("Reading the number of resources... ");
	scanf("%d", &r);

	printf("Reading the max claim table for each process... \n");
	for (i=0; i<n; i++) {
		printf("---PROCESS %d---\n", i+1);
		for (j=0; j<r; j++) {
			scanf("%d", &maxClaim[i][j]);
		}
	}
	printf("Reading the allocated resources for each process... \n");
        for (i=0; i<n; i++) {
                printf("---PROCESS %d---\n", i+1);
                for (j=0; j<r; j++) {
                        scanf("%d", &allocRes[i][j]);
                }
		state[i] = 0;
        }

	printf("Reading the available resources... \n");
	for (i=0; i<r; i++) {
		scanf("%d", &available[i]);
	}

	//	calculating the need matrix
	
	for (i=0; i<n; i++) {
		for (j=0; j<r; j++) {
			need[i][j] = maxClaim[i][j] - allocRes[i][j];
		}
	}

	printf("\t--- NEED MATRIX ---\n");
	for (i=0; i<n; i++) {
		for (j=0; j<r; j++) {
			printf("%d\t", need[i][j]);
		}
		printf("\n");
	}

	//	running the safety algorithm
	
	for (k=0; k<r; k++) {
		for (i=0; i<n; i++) {
			if (state[i] == 0) {
				change = 0;
				for (j=0; j<r; j++) {
					if (need[i][j] > available[j]) {
						change = 1;
						break;
					}
				}
				if (change == 0) {
					sequence[idx++] = i;
					for (j=0; j<r; j++) {
						available[j] += allocRes[i][j];
					}
					state[i] = 1;
				}
			}
		}
	}

	change = 0;
	for (i=0; i<n; i++) {
		if (state[i] == 0) {
			change = 1;
			printf("\nThe system is in UNSAFE STATE!\n");
			break;
		}
	}

	if (change == 0) {
		printf("\nThe system is in SAFE STATE!\n");
		printf("The Safe Sequence : ");
		for (i=0; i<n-1; i++) {
			printf("P%d ->", sequence[i]);
		}
		printf("P%d\n\n", sequence[n-1]);
	}
}
