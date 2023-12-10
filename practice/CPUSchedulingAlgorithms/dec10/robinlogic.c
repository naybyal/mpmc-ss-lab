#include<stdio.h>

struct process {
	int rbt, bt, id, tat, wt;
} p[50], x[50];

void main() {
	int i,j,n, qt, cmp=0, netBurst=0, k=1;

	printf("Reading the number of processes... ");
	scanf("%d", &n);

	printf("Reading the burst times of each process...\n");
	for (i=0; i<n; i++) {
		printf("PROCESS %d\t->\t", i+1);
		p[i].id = i+1;
		scanf("%d", &p[i].bt);
		p[i].rbt = p[i].bt;
	}

	printf("Reading time quanta... ");
	scanf("%d", &qt);

	p[0].tat = 0;

	while (cmp != netBurst) {
		for (i=0; i<n; i++) {
			if (p[i].rbt != 0) {
				x[k].id = i+1;
				if (p[i].rbt - qt <= 0) {
					x[k].wt = x[k-1].tat;
					x[k].bt = p[i].rbt;
					x[k].tat = x[k].wt + x[k].bt;

					p[i].rbt = 0;
					p[i].tat = x[k].tat;
					p[i].wt = p[i].tat - p[i].bt;

					cmp = x[k].tat;
					k++;
				} else {
					x[k].wt = x[k-1].tat;
					x[k].tat = x[k].wt + qt;
					p[i].rbt -= qt;

					cmp = x[k].tat;
					k++;
				}
			}
		}
	}
}
