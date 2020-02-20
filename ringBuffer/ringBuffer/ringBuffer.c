#include <stdio.h>

#define N 10

int main() {
	int i;
	int a[N];
	int cnt = 0;
	int retry = 0;
	puts("put integer :");
	do {
		printf("%d th integer : ", cnt + 1);
		scanf_s("%d", &a[cnt++ % N]);
		printf("keep going?(Yes ....1/No.....0) :");
		scanf_s("%d", &retry);
	} while (retry == 1);
	i = cnt - N;
	if (i < 0) i = 0;
	for (; i < cnt; i++)
		printf("%2d th integer = %d\n", i + 1, a[i % N]);

	return 0;
}