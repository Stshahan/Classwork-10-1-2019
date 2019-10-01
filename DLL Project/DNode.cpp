/*
 * DNode.cpp
 *
 *  Created on: Sep 29, 2019
 *      Author: Debra
 */
#include <stdlib.h>
#include <iostream>
#include "DNode.hpp"
using namespace std;

DNode::DNode() {
	data = -1;
	next = NULL;
	prev = NULL;
}
DNode::DNode(int x) {
	data = x;
	next = NULL;
	prev = NULL;
}

