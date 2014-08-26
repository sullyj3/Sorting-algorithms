#include <stdio.h>
#include "int_array_tools.h"

void int_swap(int *p1, int *p2) {
	int tmp;

	/* tmp becomes number pointed to by p1 (*p1) */
	tmp = *p1;
	/* number pointed to by p1 becomes number pointed to by p2 */
	*p1 = *p2;
	/* number pointed to by p2 becomes number stored in tmp */
	*p2 = tmp;
}

int intsort2(int *p1, int *p2) {
	/* returns 1 if it swaps the numbers */

	if (*p2<*p1) {
		int_swap(p1, p2);
		return 1;
	}
	return 0;
}

int read_int_array(int A[], int maxvals) {
	int n, excess, next;
	printf("Enter as many as %d values, ^D to end\n",
			maxvals);
	n = 0; excess = 0;
	while (scanf("%d", &next)==1) {
		if (n==maxvals) {
			excess = excess+1;
		} else {
			A[n] = next;
			n += 1;
		}
	}
	printf("%d values read into array", n);
	if (excess) {
		printf(", %d excess values discarded", excess);
	}
	printf("\n");
	return n;
}

void fprint_int_array(FILE *stream, int A[], int N) {
	int i;
	
	for (i=0; i<N; i++) {
		fprintf(stream, "%d ", A[i]);
	}
	fprintf(stream, "\n");
}
