/*
	Course:		CS2024 DSA Lab 
	Semester:	2024 Jan-Apr
	Lab:		02
	Task Set:	02 (Tasks 5 to 8)
	
	Aim: 		Implement Queue ADT over Array Data Structure
	Assume:		All data to be stored are characters except '$' 
*/

#include <stdio.h>
#include <stdlib.h>	// Needed for malloc, free etc
#include <stdbool.h>

typedef struct {
	char* data;	// Pointer to the start of array. Space will be allocated by init()
	int size;	// Max size of queue
	int rear;	// Index of next empty location 
	int front;	// Index of next first element 
	int num;    // total number of elements in Queue
} Queue;

/* Initialize a stack */
void init(Queue* q, int size) {
	q->data = (char*) malloc(size * sizeof(char));
	if (q->data == NULL) {
		fprintf(stderr, "Memory Allocation Failed\n");
		exit(1);
	}
	q->size = size;
	q->rear = 0;	// index of next empty location 
	q->front = 0;
	q->num = 0;
}

/* 	### Enqueue function 
	Exit behaviour:
		- On success: returns 0
		- On error: Message to stderr and returns -1
*/
int enqueue(Queue* q, char c) {
	//Q5
	// if (q->rear >= q->size) {
	// 	fprintf(stderr, "Queue Overflow\n");
	// 	return -1;
	// }

	/* Task 5a.
		Fill in the required statements
	*/
	// q->data[q->rear++] = c;

	//Q6
	if(q->rear >= q->size){
		if(q->front == 0){
			fprintf(stderr, "Queue Overflow\n");
			return -1;
		}
		q->data[q->rear] = c;
		q->rear = 0;
		q->num++;
	}
	else{
		if(q->num == q->size){
			fprintf(stderr, "Queue Overflow\n");
			return -1;
		}
		else{
			q->data[q->rear++] = c;
			q->num++;
		}
	}

	return 0;
}

/* 	### Dequeue function 
	Exit behaviour:
		- On success: returns the character on the front of the queue
			(and shifts everyone in the queue one step forward)
		- On error: Message to stderr and returns '$'
*/
char dequeue(Queue *q) {
	//Q5
	// char head;
	// if (q->rear <= 0) {
	// 	fprintf(stderr, "Queue Empty\n");
	// 	return '$';
	// }
	/* Task 5b.
		Fill in the missing statements 
	*/
	// head = q->data[0];
	// q->rear--;
	// for (int i = 0; i < q->rear; i++)
	// 	q->data[i] = q->data[i+1];
	// return head;

	//Q6
	char head;
	if(q->num == 0) {
		fprintf(stderr, "Queue Underflow\n");
		return '$';
	}
	else{
		if(q->front >= q->size){
			head = q->data[q->front];
			q->front = 0;
			q->num--;
			return head;
		}
		else{
			head = q->data[q->front];
			q->front++;
			q->num--;
			return head;
		}
	}

}

//Q7
int is_empty(Queue q){
	if(q.num == 0){
		return 1;
	}
	else{
		return 0;
	}
}
int is_full(Queue q){
	if(q.num == q.size){
		return 1;
	}
	else{
		return 0;
	}
}

void print_queue(Queue q){
	if(q.front <= q.rear){
		for(int i=q.front;i<q.rear;i++){
			printf("%c,",q.data[i]);
		}
		printf("\n");
	}
	else{
		for(int i=q.front;i<q.size;i++){
			printf("%c,",q.data[i]);
		}
		for(int i=0;i<q.rear;i++){
			printf("%c,",q.data[i]);
		}
		printf("\n");
	}
}

//Q8

	
int main() {
	Queue q;
	int i, flag;
	char c;

	init(&q, 16);

	for(i = 0; i < 26; i++) {
		flag = enqueue(&q, 'a'+i);
		if(flag == -1)
			break;
		printf("Enqueued %c\n", 'a'+i);
	}

	//Q7
	printf("%d\n",is_empty(q));
	printf("%d\n",is_full(q));
	print_queue(q);


	for(i = 0;; i++) {
		c = dequeue(&q);
		if (c == '$') {
			printf("\n");
			break;
		}
		printf("Dequeued %c\n", c);
	}

	//Q7
	printf("%d\n",is_empty(q));
	printf("%d\n",is_full(q));

	return 0;
}	

/* Task 6. 	Queue using circular indexing of two pointers
	-	One main problem with the current implementation is that dequeue
		needs to shift all the remaining elements in the array and this
		is very inefficient.
	-	Modify the implementation to use two indexes q->rear and q->front
		together with a circular view of the array so that both enqueue and
		dequeue can be done in O(1) time.
	-	Warning: How do you identify the full and empty states of the queue?
*/

/* Task 7.	Helper functions
	-	Write the following helper functions for a queue
		a) int is_empty(Queue q) which return 1 if q is empty and 0 if not
		b) int is_full(Queue q) which return 1 if q is full and 0 if not
		c) print_queue(Queue q) which prints the queue from front to rear
		Note that we can use pass by value in these functions since they
		do not modify the contents of the queue.
*/

/* Task 8.	Buffering random service requests using a queue.
	Write a function to model the following scenario.
	 -  At each time-step a service request comes to a machine with 
	 	probability p = 1/5.
	-	The requests are stored in a buffer which can hold at most 10 requests
	 -	The machine takes 6 time steps to service each request. After finishing
	 	one requests it takes up the oldest pending request in the buffer.
	 -	Run this simulation for 10,000 time steps and count how many requests
	 	had to be dropped due to buffer overflow.
*/


