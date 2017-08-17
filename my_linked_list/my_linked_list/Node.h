#ifndef NODE_H
#define NODE_H
#include <string>
class Node
{
private:

std::string text;
double num;
Node *next;
static int size;
void editMenu(Node*);

public:
	Node();
	Node(std::string, double);
	void addNode(std::string, double); //add a node at the end of the list
	void printList(); //prints list
	void editNode(int);//What is edited will be decided in the definition
	void removeNode(int); //remove node at passed location
	int getSize(){ return size; };
	void menu(Node*);
};
#endif