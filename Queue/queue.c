/*ENQUEUE 를 하면 값이 들어가질 않음*/
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int Initialize(IntQueue* s, int max) {
	s->num = 0;
	if ((s->que = calloc(max, sizeof(int)))== NULL) {
		s->max = 0;
		return -1;
	}
	s->max = max;
	return 0;
}


int Enqueue(IntQueue* s, int x) {
	if (s->num >= s->max) return -1;
	s->que[s->num++] = x;
	return 0;
}


int Dequeue(IntQueue* s, int* x) {
	if (s->num == 0) return -1;
	int i;
	*x = s->que[--s->num];
	s->max -= 1;
	for (i = 0;i <= (s->max); i++) {
		s->que[i] = s->que[++i];
	}
	return 0;
}


int Peek(const IntQueue* s, int* x) {
	if (s->num < 0) return 0;
	*x = s->que[s->num - 1];
	return 0;
}


void Clear(IntQueue* s) {
	s->num = 0;
}


int Capacity(const IntQueue* s) {
	return s->max;
}


int Size(const IntQueue* s) {
	return s->num;
}


int isEmpty(const IntQueue* s) {
	return s->num <= 0;
}


int isFull(const IntQueue* s) {
	return s->num >= s->max;
}


void Print(const IntQueue* s) {
	int i;
	for (i = 0; i < s->num; i++)
		printf("%d ", s->que[i]);
	putchar('\n');
}


void Terminate(IntQueue* s) {
	if (s->que != NULL)
		free(s->que);
	s->max = s->num = 0;
}


int main(void) {
	IntQueue s;
	int menu, x;

	if (Initialize(&s, 64) == -1) {
		puts("fail to make queue");
		return 1;
	}
	while (1) {
		IntQueue* s;
		Initialize(&s, 64);

		printf("Now data number First : %d / %d\n", Size(&s), Capacity(&s));
		printf("1.Push 2.Pop 3.Peek 4.Print 5.Clear 0.End :  ");
		scanf_s("%d", &menu);

		if (menu == 0) break;
		switch (menu) {
		case 1:
			printf("Data is : ");
			scanf_s("%d", &x);
			if (Enqueue(&s, x) == -1)
				puts("\a Eroor : fail to push");
			break;
		case 2:

			if (Dequeue(&s, &x) == -1)
				puts("\a Error : fail to pop");
			else
				printf("Pop data is %d\n", x);
			break;
		case 3:
			if (Peek(&s,&x) == -1)
				puts("\a Error : fail to Peek");
			else
				printf("Peek data is %d\n", x);
			break;
		case 4:
			Print(&s);
			break;
		case 5:
			printf("Clear");
			Clear(&s);
			break;
		}
	}
	Terminate(&s);
	return 0;
}










