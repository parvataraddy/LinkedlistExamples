/*
 * linklist.c
 *
 *  Created on: 07-Jun-2019
 *      Author: parwath
 */

#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
typedef struct node {
	int data;
	struct node * next;
} Node;
/*
   Printing the linked list node
   */
void printnode(Node *head) {
	Node *ptr = head;
	while (ptr != NULL) {
		printf("%d->", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

Node *Newnode(int data) {
	Node *newnode = (Node *) malloc(sizeof(Node));
	newnode->data = data;
	newnode->next = NULL;
	return newnode;
}
/*
   Adding new node to the list 
   */

void addnode(int data, Node **head) {
	if (*head == NULL) {
		*head = (Node *) Newnode(data);
		return;
	}
	Node *tmp = *head;
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = (Node *) Newnode(data);
}
/*
   Adding Node at the first
   */
void addnodeatfirst(int data, Node **head) {
	if (*head == NULL) {
		*head = (Node *) Newnode(data);
		return;
	} else {
		Node *tmp = (Node *) Newnode(data);
		tmp->next = *head;
		*head = tmp;
	}
}
/*
   Adding node at the possition given by the user
   */
void addnodeatpoint(int pos, int data, Node **head) {
	int i = 0;
	Node *tmp = *head;
	Node *prev = NULL;
	while (i <= pos - 1) {
		if (tmp == NULL)
			return;
		prev = tmp;
		tmp = tmp->next;
		i++;
	}
	prev->next = (Node *) Newnode(data);
	prev->next->next = tmp;
}
/*
   Adding node from last at given possition
   */
void addnodefromlast(int pos, int data, Node **head) {
	Node *tmp = *head;
	Node *prev = *head;
	while (pos > 0) {
		if (tmp != NULL) {
			tmp = tmp->next;
		} else
			return;
		pos--;
	}
	while (tmp != NULL) {
		prev = prev->next;
		tmp = tmp->next;
	}
	Node *new = prev->next;
	prev->next = (Node *) Newnode(data);
	prev->next->next = new;

}
/*
   Adding node at the middle of list
   */
void addnodeatmiddle(int data, Node **head) {
	Node *tmp = *head;
	Node *prev = *head;
	if (tmp == NULL | tmp->next == NULL) {
		return;
	} else
		tmp = tmp->next->next;
	while (tmp != NULL && tmp->next != NULL) {
		prev = prev->next;
		tmp = tmp->next->next;
	}
	Node *new = prev->next;
	prev->next = (Node *) Newnode(data);
	prev->next->next = new;
}
/*
   Delete the node at the possition
   */
void deletenode(int pos, Node **head) {
	Node *tmp = *head;
	Node *prev = NULL;
	while (tmp != NULL && pos) {
		prev = tmp;
		tmp = tmp->next;
		pos--;
	}
	if (pos)
		return;
	prev->next = tmp->next;

}
/*
   deleting the middle Node in the list
   */
void deletemiddlenode(Node **head) {
	Node *tmp = *head;
	Node *prev = *head;
	if (tmp == NULL && tmp->next == NULL)
		return;
	else
		tmp = tmp->next->next;
	while (tmp != NULL && tmp->next != NULL) {
		prev = prev->next;
		tmp = tmp->next->next;
	}
	prev->next = prev->next->next;

}
/*
 * Reverse the lisked list
 */
void reverse_list(Node **head)
{
	Node *current=*head;
	Node *Next;
	Node *prev=NULL;
	while(current !=NULL)
	{
		Next=current->next;
		current->next=prev;
		prev=current;
		current=Next;
	}
	*head=prev;
}
/*
 * Finding the meeting node of two linked lists given length m and n is the lengths of linked list
 */
Node *meetNodex(int m, int n, Node *ptrm, Node *ptrn) {
	int i = 0;
	if (m > n) {
		for (i = 0; i < m - n; i++)
			ptrm = ptrm->next;
	}
	if (n > m) {
		for (i = 0; i < n - m; i++)
			ptrn = ptrn->next;
	}
	while (ptrn != NULL && ptrm != NULL && ptrn != ptrm) {
		ptrn = ptrn->next;
		ptrm = ptrm->next;
	}
	return ptrn;
}

int main() {
	Node *head = NULL;
	addnode(2, &head);
	addnode(4, &head);
	addnode(6, &head);
	addnode(8, &head);
	addnode(10, &head);
	addnodeatfirst(12, &head);
	addnodeatfirst(14, &head);
	addnodeatpoint(4, 16, &head);
	addnodeatpoint(3, 18, &head);
	addnodefromlast(3, 20, &head);
	addnodefromlast(3, 22, &head);
	addnodeatmiddle(1, &head);
	addnodeatmiddle(26, &head);
	printnode(head);
	deletenode(3, &head);
	printnode(head);
	deletenode(3, &head);
	printnode(head);
	deletemiddlenode(&head);
	printnode(head);
	reverse_list(&head);
	printnode(head);
}
