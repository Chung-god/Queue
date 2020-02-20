#include <stdio.h>
#include <stdlib.h>
#include "IntQueue.h"

int Initialize(IntQueue* q, int max) {
	q->num = q->front = q->rear = 0;
	if ((q->que = calloc(max, sizeof(int))) == NULL) {
		q->max = 0;
		return -1;
	}
	q->max = max;
	return 0;
}

int EnqueRear(IntQueue* q, int x) {
	if (q->num >= q->max)
		return -1;
	else {
		q->num++;
		q->que[q->rear++] = x;
		if (q->rear == q->max)
			q->rear = 0;
		return 0;
	}
}
int EnqueFront(IntQueue* q, int x) {
	if (q->num >= q->max)
		return -1;
	else {
		q->num++;
		if (q->front == 0) {
			int max = q->max;
			q->que[--max] = x;
			q->front = max;
		}
		else {
			q->front--;
			q->que[q->front] = x;
		}
		return 0;
	}
}

int DequeFront(IntQueue* q, int* x) {
	if (q->num <= 0) return -1;
	else {
		q->num--;
		*x = q->que[q->front++];
		if (q->front == q->max)
			q->front = 0;
		return 0;
	}
}

int DequeRear(IntQueue* q, int* x) {
	if (q->num <= 0) return -1;
	else {
		q->num--;
		*x = q->que[--q->rear];
		if (q->rear <= 0)
			q->rear = q->max;
	}
}
int Peek(IntQueue* q, int* x) {
	if (q->num <= 0) return -1;
	else {
		*x = q->que[q->front];
		return 0;
	}
}

void Clear(IntQueue* q) {
	q->num = q->front = q->rear = 0;
}

int Capacity(const IntQueue* q) {
	return q->max;
}

int Size(const IntQueue* q) {
	return q->num;
}

int IsEmpty(const IntQueue* q) {
	return q->num <= 0;
}

int IsFull(const IntQueue* q) {
	return q->num >= q->max;
}

int Search(const IntQueue* q, int x) {
	int i, idx;
	for (i = 0; i < q->num; i++) {
		if (q->que[idx=(i+q->front)%q->max] == x)
			return idx;
	}
	return -1;
}

int Search2(const IntQueue* q, int x) {
	int i, idx;
	for (i = 0; i < q->num; i++) {
		if (q->que[idx = (i + q->front) % q->max] == x) {
			printf("We search %d in array[%d]\n", x, i);
			return 0;
		}
	}
	puts("Error");
	
}

void Print(const IntQueue* q) {
	int i = 0;
	for (i = 0; i < q->num; i++)
		printf("%d ", q->que[(i+q->front)%q->max]);
	putchar('\n');
}

void Terminate(IntQueue* q) {
	if (q->que != NULL)
		free(q->que);
	q->max = q->num = q->front = q->rear = 0;
}

int main(void) {
	IntQueue que;

	if (Initialize(&que, 64) == -1) {
		puts("fail to make queue");
		return -1;
	}

	while (1) {
		int m, x;

		printf("Now data : %d / %d\n", Size(&que), Capacity(&que));
		printf("(1)EnqueRear (2)DequeFront (3)Peek (4)Print (5)Search (6)Search2 (7)EnqueFront (8)DequeRear (0)End : ");
		scanf_s("%d", &m);
		if (m == 0) break;

		switch (m) {
		case 1:
			printf("Data is ");
			scanf_s("%d", &x);
			if(EnqueRear(&que, x)==-1)
				puts("Error");
			break;
		case 2:
			if (DequeFront(&que, &x) == -1)
				puts("Error");
			else
				printf("Deque data is %d\n", x);
			break;
		case 3:
			if (Peek(&que, &x) == -1)
				puts("Error");
			else
				printf("Peek data is %d\n", x);
			break;
		case 4:
			Print(&que);
			break;
		case 5:
			printf("Data is : ");
			scanf_s("%d", &x);
			if (Search(&que, x) == -1)
				puts("Error");
			else
				printf("Search data is %d\n", x);
			break;
		case 6:
			printf("Data is : ");
			scanf_s("%d", &x);
			Search2(&que, x);
			break;
		case 7:
			printf("Data is : ");
			scanf_s("%d", &x);
			if (EnqueFront(&que, x) == -1)
				puts("Error");
			break;
		case 8:
			if (DequeRear(&que,&x) == -1)
				puts("Error");
			else
				printf("DequeRear data is %d\n", x);
			break;
		}
	}
	Terminate(&que);
	return 0;
}