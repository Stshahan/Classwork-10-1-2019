/*
 * DLL.cpp
 *
 *  Created on: Sep 30, 2019
 *      Author: Debra
 */
#include "DNode.hpp"
#include "DLL.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

//		Part 1:  In the DLL.cpp class, get push, pop, and addAtFront working for a doubly linked list.
//     I've given you the test cases.  You should get the output I've given you for part 1.
//		When you get those methods working, running this will decode the secret code 1

//once you have that working, start on part 2 (note you will have to go into Coder.cpp and toggle
//comments for lines 49-95 to run part 2)

//		Part 2: Get  the DLL.cpp methods addFirst, insertAt and removeAtK methods working for a doubly linked list.
//		I've given you the test cases and the output.  When you get them working, you should be able to run
//		this and decode the second secret code

//once you have that working, start on part 3 (note that you will have to go to Coder.cpp and toggle
//comments for lines 96-125 to run part 3)

//		Part 3: For this part, you will get the method skip working for the DLL doubly linked list class.
//		This method deletes every other node starting with the second node in the list.  In other words,
//		if the list was 3<->2<->4<->5<->1<->7, the list that would result after the skip method was
//		called would be: 3<->4<->1
//		NOTE:  For efficiency's sake, this method SHOULD NOT call removeAtK

//once you have that working, start on part 4 (note that you will have to go to Coder.cpp and toggle
//comments for lines 129-157 to run part 4)

//		Part 4: For this part, you will get the method reverse working for the DLL doubly linked list class.
//		This method reverses the list.  Note: it doesn't just print out the list in reverse order, it actually
//		reverses the list, so if the original list was 3<->2<->4<->8, with 3 being first and 8 being last, the
//		reversed list would be 8<->4<->2<->3 with 8 being first and 3 being last.

DLL::DLL() {  // constructor - initializes an empty list
	last = NULL;
	first = NULL;
	size = 0;
}
DLL::DLL(int x) { // constructor, initializes a list with one new node with data x
	DNode *n = new DNode(x);
	first = n;
	last = n;
	size = 1;
}
/***************************************************************************************************/
/*Part 1																				           */
/***************************************************************************************************/
void DLL::push(int x) {  // does what you'd think - write for part 1
	size++;
	DNode *newN = new DNode(x);
	if(last == NULL){
		first = newN;
		last = newN;
	}
	else{
		last->next = newN;
		newN->prev = last;
		newN->next = NULL;
		last = newN;
	}
}




int DLL::pop() { //does what you'd think - write for part 1

	DNode *temporary = last;
	int x = temporary->data;
	last = last->prev;
	delete temporary;
	last->next = NULL;
	size--;
	return x;


}

void DLL::addAtFront(int x) { // add a node to the beginning of the list (this should work whether
// there's a node already in the list or the list is empty
	DNode *nNode = new DNode(x);
	if(size == 0){
		first = nNode;
	}
	else{
		first->prev = nNode;
		nNode->next = first;
		first = nNode;
	}
}

/***************************************************************************************************/
/*Part 2		                                                                                   */
/***************************************************************************************************/
void DLL::addFirst(int x) {	// add the very first node to the list (Do for part 2)
	size++;
	first = new DNode(x);
	last=first;

}
void DLL::insertAt(int ind, int x) { //insert x at index ind (so ind 3 is the 4th element, after element 0, 1, 2, and 3)
	DNode *temp = first;
	int i=1;
	while (i < ind ) { // left out check for end of list
		temp = temp->next;
		i++;
	}
	DNode *n = new DNode(x);
	n->prev = temp->prev;
	temp->prev->next = n;
	n->next = temp;
	temp->prev = n;
	size ++;
}
int DLL::removeAtK(int ind) { // remove the node at index ind and returns its data
	//indices start at 0
	DNode *tmp;

	for (tmp = first; tmp != NULL; tmp = tmp->next) {
		if (tmp->data== ind) {
			if (tmp->prev== NULL) {
				first = tmp->next;
			}
			else if(tmp->next== NULL) {
				tmp->prev->next = NULL;
			}
			else { /* Remove from middle */
				tmp->prev->next=tmp->next;
			/* Fix previous node's next to skip over the removed node. */
				tmp->next->prev = tmp->prev;
				}
			delete tmp;
			return true;
		}
	 }
	return false;

}
/****************************************************************************************/
/* Part 3                                                                               */
/****************************************************************************************/
void DLL::skip() { // remove every other node - first stays, second is removed, third stays, fourth removed, etc. to end of list (see comments at top of file for more details)

}
/****************************************************************************************/
/* Part 4                                                                               */
/****************************************************************************************/
void DLL::reverse() { // reverse the list - doesn't just print a reversed list, actually reverses the list!

}

/***************************************************************************************************/
/*End of your part		                                                                           */
/***************************************************************************************************/

void DLL::printList() {
	DNode *tmp = first;
	while (tmp != NULL) {
		cout << tmp->data << ", ";
		tmp = tmp->next;
	}
	cout << endl;
}
void DLL::printCode() {
	DNode *tmp = first;
	while (tmp != NULL) {
		cout << alpha[tmp->data];
		tmp = tmp->next;
	}
	cout << endl;
}
DLL::~DLL() {
	DNode *tmp = first;
	DNode *tmp2 = first->next;
	while (tmp != NULL) {
		delete tmp;
		tmp = tmp2;
		tmp2 = tmp2->next;
	}
}

