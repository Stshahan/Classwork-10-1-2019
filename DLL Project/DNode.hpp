/*
 * DNode.hpp
 *
 *  Created on: Sep 29, 2019
 *      Author: Debra
 */

#ifndef DNODE_HPP_
#define DNODE_HPP_

class DNode {
	friend class DLL;
	int data;
	DNode *prev;
	DNode *next;
public:
	DNode();
	DNode(int x);
};

#endif /* DNODE_HPP_ */
