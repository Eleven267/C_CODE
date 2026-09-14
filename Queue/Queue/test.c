#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

void test()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);

	int head = QueueFront(&q);
	int tail = QueueBack(&q);
	printf("%d\n%d\n", head, tail);

	int size = QueueSize(&q);
	printf("%d", size);

	QueueDestroy(&q);
}

int main()
{
	test();
	return 0;
}