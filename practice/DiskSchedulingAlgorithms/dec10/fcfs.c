#include<stdio.h>

void main() {
	int n, i,j, hd, a[20],x;

	printf("Reading the number of requests... ");
	scanf("%d", &n);

	printf("Reading the requesting sequence... \n");
	for (i=0; i<n; i++) {
		scanf("%d", &a[i]);
	}

	printf("Reading the current head position... ");
	scanf("%d", &hd);
	int tst = 0;
	for (i=0; i<n; i++) {
		x = a[i]-hd;
		if (x < 0)
			x = -x;
		tst += x;
	}

	printf("\nThe sequence is :");
	for (i=0; i<n; i++)
		printf("%d\t", a[i]);
	printf("\nTotal seek time\t->\t%d ms\n", tst);
}
