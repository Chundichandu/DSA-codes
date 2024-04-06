/*
	Course:		CS2130 DSA Lab
	Semester:	2024 Jan-Apr
	Lab:		03 | Linked Lists
	Task Set:	2 | Doubly Linked Lists (dLL)

	Aim: 		Implement a doubly linked list with some basic functions.
	Assume:		All data to be stored are integers
*/

#include <limits.h> // For INT_MAX
#include <stdio.h>
#include <stdlib.h> // Needed for malloc, free etc

/* 	Unlike a singly linked list, it is not easy to define a doubly linked
	list in a recursive style. So we need two stucts -
		(a) One struct for node, which holds the data and two pointers -
			one to the next node and one to the previous node.
		(b)	One struct for the list itself - which contains two pointers -
			one to the fist node in the list and one to the last.
	When implementing a dLL the following two additional functionalities
	(one transparent one opaque) are needed to make a dLL useful.
		(a) insert_at_pos(), get_from_pos(), and delete_at_pos() functions
			should accept negative integers also as position argument.
			-1 : last node (tail), -2 is previous to -1 and so on.
		(b) if the given position is negative, the list should be traversed
			backwards from the tail. This speeds up data access in the
			second half of large lists
*/
typedef struct node
{
	int data;		   // The data stored in the node
	struct node *prev; // Pointer to previous node
	struct node *next; // Pointer to next node
} node;

typedef struct dLL
{
	struct node *head; // Pointer to first node in the list
	struct node *tail; // Pointer to last node in the list
} dLL;

node *create_node(int data, node *next, node *prev)
{
	/*
		Inputs:
			1. 	Data for the new node to be inserted
			2.	A node pointer to be set as the next pointer of the new node
			2.	A node pointer to be set as the prev pointer of the new node
		Actions:
			1.	Memory required for a new node is allotted.
			2.	The data and the two pointers of the new node are set from the inputs
		Error Response:
			1.	Prints "Error: Memory allocation for new node failed." to stderr if
				malloc fails.
			2.	Returns NULL if the new node cannot be created
	*/
	node *new = (node *)malloc(sizeof(node));
	if (new == NULL)
	{
		fprintf(stderr, "Error: Memory allocation for new node failed\n");
		return NULL;
	}
	new->data = data;
	new->next = next;
	new->prev = prev;
	return new;
}

dLL *create_dLL(node *head, node *tail)
{
	/*
		Inputs:
			2.	A pointer to the head of the list (NULL is allowed)
			2.	A pointer to the tail of the list (NULL is allowed)
		Actions:
			1. 	A new dLL struct with the given head and tail is returned
	*/
	dLL *list = (dLL *)malloc(sizeof(dLL));
	if (list == NULL)
	{
		fprintf(stderr, "Error: Memory allocation for dLL failed\n");
		return NULL;
	}
	list->head = head;
	list->tail = tail;
	return list;
}

/* Task 6.
	Copy all the functions (including main) that you have in simple-linked-list.c
	here and edit all the COMMENTS to reflect the changes needed.
*/

/* Task 7.
	Edit the code inside of each function to implement the functionality on doubly
	linked lists. You can assume that position indices will still be non-negative.
	Hence you need to do forward traversal for this Task. (Negative indices and
	reverse traversals is the next Task.
*/

dLL *insert_at_start(int data, dLL *list)
{
	/*
		Inputs:
			1. 	Data for the new node to be inserted
			2.	A list
		Actions:
			1.	A new node with the received data is inserted at the head of the
				received list
			2.	The pointer to this new node (which is effectively the new head of
				the list) is returned.
		Error Response:
			1.	Prints "Error: Insertion at start failed." to stderr
			2.	Returns NULL if the new node cannot be created
	*/
	// Task 1 - Edit one line below to solve Task 1
	if (list == NULL)
	{
		node *new = NULL;
		new = create_node(data, NULL, NULL);
		if (new == NULL)
		{
			fprintf(stderr, "Error: Insertion at start failed\n");
			return NULL;
		}
		else
		{
			dLL *newdll = create_dLL(new, new);
			return newdll;
		}
	}
	node *new = NULL;
	new = create_node(data, list->head, NULL);
	list->head->prev = new;
	if (new == NULL)
	{
		fprintf(stderr, "Error: Insertion at start failed\n");
		return NULL;
	}
	else
	{
		dLL *newdll = create_dLL(new, list->tail);
		return newdll;
	}
}
dLL *insert_at_end(int data, dLL *list)
{
	/*
		Inputs:
			1. 	Data for the new node to be inserted
			2.	A list
		Actions:
			1.	A new node with the received data is inserted at the tail of the
				received list
			2.	The pointer to this new node (which is effectively the new tail of
				the list) is returned.
		Error Response:
			1.	Prints "Error: Insertion at end failed." to stderr
			2.	Returns NULL if the new node cannot be created
	*/

	if (list == NULL)
	{
		node *new = NULL;
		new = create_node(data, NULL, NULL);
		if (new == NULL)
		{
			fprintf(stderr, "Error: Insertion at end failed\n");
			return NULL;
		}
		else
		{
			dLL *newdll = create_dLL(new, new);
			return newdll;
		}
	}
	node *new = NULL;
	new = create_node(data, NULL, list->tail->prev);
	list->tail = new;
	if (new == NULL)
	{
		fprintf(stderr, "Error: Insertion at end failed\n");
		return NULL;
	}
	else
	{
		dLL *newdll = create_dLL(list->head, new);
		return newdll;
	}
}

/* Task 2.
	Implement a function to create a new node with the given data and add it to
	the specified position in the given list and return a pointer to the start
	of the bigger list.
	-	Do not change the function interface given below.
	-	Inputs, Actions and Error Responses have to be as in the comments below.
	-	Instead of directly using create_node() use insert_at_start() to insert
		the new node at the appropriate position.
*/

dLL *insert_at_pos(int data, dLL *list, unsigned int pos)
{
/*
	Inputs:
		1. Data for the new node to be inserted
		2. A list
		3. The position in the list where to insert the new node (0 = start)
	Actions:
		1.	If position is within range, a new node with the given data is
			inserted to the list at the specified position.
		2.	The head of the new list is returned. (The head will be different
			from the input list only if the insertion is at the start)
	Error Responses:
		1	If the position is larger than the current length of the list, an
			error message "Error: Position out of range." is printed and a NULL
			pointer is returned.
		2	Returns NULL pointer also if the new node could not be created
*/
// Task 2 Solution

	node *new = NULL;
	if (pos == 0)
	{
		return insert_at_start(data, list);
	}
	if(pos==-1){
		return insert_at_end(data,list);
	}
	if(list==NULL){
		fprintf(stderr, "Error: Position out of range.");
		return NULL;
	}
	if(pos>0){
		node *next_node = list->head;
		int i = 0;
		while (i < pos - 1)
		{
			if (next_node == NULL)
			{
				fprintf(stderr, "Error: Position out of range.");
				return NULL;
			}
			next_node = next_node->next;
			i++;
		}
		if (next_node->next == NULL)
		{
			fprintf(stderr, "Error: Position out of range.");
			return NULL;
		}
		else
		{
			new = create_node(data, next_node->next,next_node);
			next_node->next->prev = new;
			next_node->next = new;
			return list;
		}
	}
	else{
		if(list==NULL){
			fprintf(stderr, "Error: Position out of range.");
			return NULL;
		}
		node *prev_node = list->tail;
		int i = -1;
		while (i > pos)
		{
			if (prev_node == NULL)
			{
				fprintf(stderr, "Error: Position out of range.");
				return NULL;
			}
			prev_node = prev_node->prev;
			i--;
		}
		if (prev_node == NULL)
		{
			fprintf(stderr, "Error: Position out of range.");
			return NULL;
		}
		else
		{
			new = create_node(data, prev_node->next,prev_node);
			printf("%p\n",new);
			printf("%p\n",prev_node->next->prev );
			printf("%p\n",prev_node->next);
			prev_node->next->prev = new;
			prev_node->next= new;
			return list;
		}
	}
}

void print_list(node *start)
{
	/*
		Input:	A list
		Actions:
			Prints the data in the linked list from start to end
			in the format:  D0 - D1 - ... - Dn - NULL
	*/
	printf("%d - ", start->data);
	if (start->next == NULL)
	{
		printf("NULL\n");
		return;
	}
	else
		print_list(start->next);
}

int get_from_pos(dLL *list, unsigned int pos)
{
/*
	Inputs
		1. 	A list
		2. 	Position from which to read the data
	Action
		1.	Returns the data stored in the node at the given position (start = 0).
	Error Responses:
		1.	Prints an error message "Error: Attempt to read outside of the
			list." to stderr and returns INT_MAX if one tries to read from
			outside the index-range of the list
*/
// Task 3 Solution
	if(list==NULL){
		fprintf(stderr, "Error: Attempt to read outside of the list.\n");
		return INT_MAX;
	}
	node* node = list->head;
	int i=0;
	while(i<pos){
		if(node==NULL){
			fprintf(stderr, "Error: Attempt to read outside of the list.\n");
			return INT_MAX;
		}
		node = node->next;
		i++;
	}
	if(node == NULL){
		fprintf(stderr, "Error: Attempt to read outside of the list.\n");
		return INT_MAX;
	}
	else{
		return node->data;
	}
}

/* Task 4.
	Implement a function to search for a particular data in the given list and
	return the position of the first node in the list which contains that data.
	-	Do not change the function interface given below.
	-	Inputs, Actions and Error Responses have to be as in the comments below.
*/
int find(int data, dLL *list)
{
/*
	Inputs
		1. 	The data to search for
		2. 	A list.
	Action
		1. 	Returns the position of the first node with the given data.
		2.	Returns -1 if the given data is not in the list
	Error Response:
*/
// Task 4. Solution
	if(list == NULL){
		return -1;
	}
	node* node = list->head;
	int pos = 0;
	while(node->data != data){
		if(node->next == NULL){
			return -1;
		}
		node = node->next;
		pos++;
	}
	return pos;
}

/* Task 5.
	Implement a function to delete a single node from the given list at the
	given position and stitch the list back together.
	-	Do not change the function interface given below.
	-	Inputs, Actions and Error Responses have to be as in the comments below.
*/
dLL *delete_at_pos(dLL *list, unsigned int pos)
{
/*
	Inputs
		1. 	A list
		2. 	The position of the node to be deleted
	Actions
		1. 	Frees the memory allotted for the node at the specified position
		2.	Links the next pointer of the previous node to 	the next node.
		3.	Returns the start pointer of the list (this may change if the
			first node is deleted)
	Error Responses:
		1.	Prints an error message "Error: Attempt to delete outside of the
			list." to stderr and returns NULL if one tries to delete a node
			outside the index-range of the list.
*/
// Task 5 Solution
	if(list==NULL){
		fprintf(stderr,"Error: Attempt to delete outside of the list.\n");
		return NULL;
	}
	node* currnode = list->head;
	if(pos==0){
		currnode = currnode->next;
		currnode->prev = NULL;
		free(list->head);
		list->head = currnode;
		return list;
	}
	int i = 0;
	while(i<pos-1){
		if(currnode->next==NULL){
			fprintf(stderr,"Error: Attempt to delete outside of the list.\n");
			return NULL;
		}
		currnode = currnode->next;
		i++;
	}
	if(currnode->next==NULL){
		fprintf(stderr,"Error: Attempt to delete outside of the list.\n");
		return NULL;
	}
	node* nextNode = currnode->next;
	currnode->next->next->prev = currnode;
	currnode->next = currnode->next->next;
	free(nextNode);
	return list;
}

/* 	All the testing for the tasks are included in the main.
	Uncomment them one by one after you code the corresponding tasks in order.
*/
int main()
{
	unsigned int i;
	dLL *list = NULL, *tempList = NULL;

	// Test for Task 1: insert_at_start()
	printf("Testing Task 1: insert_at_start()\n");
	for (i = 0; i < 10; i++)
	{
		list = insert_at_start(i, list);
		print_list(list->head);
	}
	printf("============================\n");

	// Test for Task 2: insert_at_pos()
	printf("Testing Task 2: insert_at_pos()\n");
	for (i = 0; i < 10; i++)
	{
		list = insert_at_pos(i, list, i);
		print_list(list->head);
	}
	for (i = -1; i > -10; i--)
	{
		list = insert_at_pos(i, list, i);
		print_list(list->head);
	}
	// Testing insert outside of the range
	tempList = insert_at_pos(22, list, 22);
	if (tempList == NULL)
	{
		printf("NULL pointer returned.\n");
	}
	printf("============================\n");

	// Test for Task 3: get_from_pos()
	// printf("Testing Task 3: get_from_pos()\n");
	// print_list(list->head);
	// for(i = 0; i < 25; i += 4)
	// 	printf("Data at pos %d is %d\n", i, get_from_pos(list, i));
	// printf("============================\n");

	// // Test for Task 4: find()
	// printf("Testing Task 4: find()\n");
	// print_list(list->head);
	// for(i = 0; i < 16; i+=3)
	// 	printf("Position of %d is %d\n", i, find(i, list));
	// printf("============================\n");

	// Test for Task 5: delete_at_pos()
	// printf("Testing Task 5: delete_at_pos()\n\n");
	// print_list(list->head);
	// for(i = 0; i < 20; i += 5) {
	// 	printf("Deleting data (%d) at pos %d\n", get_from_pos(list, i), i);
	// 	list = delete_at_pos(list, i);
	// 	print_list(list->head);
	// }
	// Testing delete outside of the range
	// tempList = delete_at_pos(list, i);
	// if(tempList == NULL) {
	// 	printf("NULL pointer returned.\n");
	// }
	// printf("============================\n");

	// free(list);
	return 0;
}


/*
	Task 8. Allow negative indices and implement reverse traversal for them.
	(a) insert_at_pos(), get_from_pos(), and delete_at_pos() functions
		should accept negative integers also as position argument.
		-1 : last node (tail), -2 is previous to -1 and so on.
	(b) if the given position is negative, the list should be traversed
		backwards from the tail. This speeds up data access in the
		second half of large lists
	(c) Modify the Testing loops for these functions in main to test for
		negative indices also.
*/

/* 	This main() only contains stuff to test the data structures
	Replace this with the main from simple-linked-list.c
*/
// int main() {

// 	node 	*new = create_node(10, NULL, NULL);
// 	dLL	 	*list = create_dLL(new, new);

// 	printf("%d\n", new->data);
// 	printf("%d\n", list->head->data);
// 	printf("%d\n", list->tail->data);

// 	return 0;
// }
