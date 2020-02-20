#pragma once
/*IntQueue(header)*/
#ifndef ___IntQueue
#define ___IntQueue


/*queue structure*/
typedef struct {
	int max;
	int num;/*data number*/
	int* que;/*pointer about queue's first data*/
}IntQueue;


/*Initialize queue*/
int Initialize(IntQueue* s, int max);


/*put in data to queue*/
int Enqueue(IntQueue* s,int x);


/*put out data to queue*/
int Dequeue(IntQueue* s, int* x);


/*peek data in queue*/
int Peek(const IntQueue* s, int* x);


/*Clear data*/
void Clear(IntQueue* s);


/*queue's max capacity*/
int Capacity(const IntQueue* s);


/*queue's data size*/
int Size(const IntQueue* s);


/*is empty this queue*/
int isEmpty(const IntQueue* s);


/*Is full this queue*/
int isFull(const IntQueue* s);


/*Print all data*/
void Print(const IntQueue* s);


/*end to queue*/
void Terminate(IntQueue* s);


#endif // !___IntQueue

