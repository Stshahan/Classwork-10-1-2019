/*
 * Coder.cpp
 *
 *  Created on: Sep 30, 2019
 *      Author: Debra
 */
#include "Coder.hpp"
//#include <DLL.hpp>
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

Coder::Coder() {
	cout
			<< "***************************************************************************"
			<< endl;
	cout << "Part 1:" << endl;
//		Part 1:  In the DLL.cpp class, get push, pop, and addAtFront working for a doubly linked list.
//     I've given you the test cases.  You should get the output I've given you for part 1.
//		When you get those methods working, running this will decode the secret code 1
	for (int i = 1; i < 4; i++) {
		codelist.push(i);
	}
	codelist.printList();
	codelist.addAtFront(0);
	codelist.printList();
	codelist.push(5);
	codelist.printList();
	cout << "Size of list is: " << codelist.size << endl;
	int x = codelist.size;
	for (int i = 0; i < x; i++) {
		codelist.pop();
		codelist.printList();
	}
	cout << "PART 1 Secret Code: " << endl;
	int arrb[10] = { 30, 35, 27, 44, 32, 27, 26, 39, 57, 8 };
	int arrc[24] = { 26, 8, 26, 29, 27, 40, 57, 46, 26, 30, 41, 26, 46, 34, 27,
			46, 26, 3, 27, 48, 31, 12, 17, 2 };
	for (int i = 0; i < 10; i++) {
		codelist.push(arrc[i]);
		codelist.addAtFront(arrb[i]);
	}
	for (int i = 0; i < 14; i++) {
		codelist.push(arrc[i + 10]);
	}
	for (int i = 0; i < 3; i++) {
		codelist.pop();
	}
	codelist.printCode();
	cout
			<< "***************************************************************************"
			<< endl;
	cout << "Part 2: " << endl;
//		Part 2: Get  the DLL.cpp methods addFirst, insertAt and removeAtK methods working for a doubly linked list.
//		I've given you the test cases and the output.  When you get them working, you should be able to run
//		this and decode the second secret code

	codelist.addFirst(0);
	codelist.printList();
	codelist.insertAt(1, 1);
	codelist.printList();
	codelist.insertAt(2, 3);
	codelist.printList();
	codelist.insertAt(2, 2);
	codelist.printList();
	codelist.push(4);
	codelist.printList();
	codelist.insertAt(2, 42);
	codelist.printList();
	codelist.removeAtK(2);
	codelist.printList();
	codelist.removeAtK(0);
	codelist.printList();
	codelist.removeAtK(3);
	codelist.printList();
	codelist.removeAtK(0);
	codelist.printList();
	codelist.removeAtK(1);
	codelist.printList();
	codelist.removeAtK(0);
	codelist.printList();
	cout << "PART 2 Secret Code: " << endl;
	int arrd[19] = { 20, 45, 31, 26, 46, 34, 31, 26, 32, 41, 44, 29, 31, 53, 26,
			11, 47, 37, 31 };
	codelist.addFirst(32);
	for (int i = 0; i < 10; i++) {
		codelist.push(i);
	}
	for (int i = 1; i < 11; i++) {
		codelist.insertAt(i * 2, arrd[i]);
	}
	for (int i = 11; i < 19; i++) {
		codelist.push(arrd[i]);
	}
	codelist.removeAtK(0);
	codelist.insertAt(0, 20);
	for (int i = 19; i >= 1; i -= 2) {
		codelist.removeAtK(i);
	}
	codelist.printCode();
	cout << "*****************************************************************"
			<< endl;
	cout << "Part 3: " << endl;
//		Part 3: For this part, you will get the method skip working for the DLL doubly linked list class.
//		This method deletes every other node starting with the second node in the list.  In other words,
//		if the list was 3<->2<->4<->5<->1<->7, the list that would result after the skip method was
//		called would be: 3<->4<->1
//		NOTE:  For efficiency's sake, this method SHOULD NOT call removeAtK
	int k = codelist.size;
	for (int i = 0; i < k; i++) {
		codelist.pop();
	}
	for (int i = 0; i < 10; i++) {
		codelist.push(i);
	}
	codelist.printList();
	codelist.skip();
	codelist.printList();
	codelist.skip();
	codelist.printList();

	cout << "PART 3 Secret Code: " << endl;
	int arre[126] = { 19, 12, 34, 17, 31, 16, 26, 34, 45, 42, 34, 51, 35, 8, 42,
			1, 26, 13, 34, 16, 47, 27, 40, 17, 33, 12, 26, 19, 35, 34, 40, 42,
			26, 39, 46, 17, 34, 18, 31, 21, 26, 51, 45, 23, 37, 13, 51, 2, 26,
			18, 35, 19, 40, 33, 26, 27, 39, 49, 47, 51, 29, 3, 34, 4, 26, 17,
			46, 1, 34, 19, 31, 22, 26, 25, 45, 24, 27, 22, 39, 18, 31, 14, 26,
			11, 49, 9, 27, 7, 51, 3, 26, 50, 46, 48, 34, 44, 27, 43, 46, 42, 26,
			38, 28, 36, 44, 38, 35, 32, 29, 17, 37, 14, 45, 12, 26, 8, 30, 6,
			41, 4, 40, 2, 57, 42, 46, 42 };
	for (int i = 0; i < 3; i++) {
		codelist.pop();
	}
	for (int i = 0; i < 126; i++) {
		codelist.push(arre[i]);
	}
	codelist.skip();
	codelist.printCode();

	cout << "*****************************************************************"
			<< endl;
	cout << "Part 4: " << endl;
	//		Part 4: For this part, you will get the method reverse working for the DLL doubly linked list class.
	//		This method reverses the list.  Note: it doesn't just print out the list in reverse order, it actually
	//		reverses the list, so if the original list was 3<->2<->4<->8, with 3 being first and 8 being last, the
	//		reversed list would be 8<->4<->2<->3 with 8 being first and 3 being last.
	int xx = codelist.size;
	for (int i = 0; i < xx; i++) {
		codelist.pop();
	}
	for (int i = 0; i < 7; i++) {
		codelist.push(i);
	}
	codelist.printList();
	codelist.reverse();
	codelist.printList();
	codelist.reverse();
	codelist.printList();

	cout << "PART 4 Secret Code: " << endl;
	for (int i = 0; i < 7; i++) {
		codelist.pop();
	}
	int arrf[13] = { 54, 46, 41, 41, 44, 6, 26, 31, 44, 27, 26, 31, 22 };
	for (int i = 0; i < 13; i++) {
		codelist.push(arrf[i]);
	}
	codelist.reverse();
	codelist.printCode();
	cout << "*****************************************************************"
			<< endl;
}

