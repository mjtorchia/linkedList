#include "Node.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
int Node::size = 0;
using namespace std;
void Node::editMenu(Node *temp)
{
	int choice = 0;
	while (choice != 3){
		cout << "Press 1 to edit the string of this node." << endl;
		cout << "Press 2 to edit the int value of this node." << endl;
		cout << "Press 3 to exit." << endl;
		cin >> choice;
		while (choice<0 ||choice>3)
		{
			cout << "Invalid. Please try again: ";
			cin >> choice;
			cin.clear();
		}
		if (choice == 1)
		{
			cin.ignore(1000, '\n');
			cout << "Enter the new string for the node: "<<flush;
			std::getline(std::cin, temp->text);
			cin.clear();
		}
		if (choice == 2)
		{
			cout << "Enter the new number for the node: ";
			cin >> temp->num;
		}
	}
}
Node::Node()
{
	text = "";
	num = 0.0;
	next = NULL;
	size++;

}
Node::Node(std::string text = "", double num = 0.0)
{
	this->text = text;
	this->num = num;
	next = NULL;
	size++;
	
}
void Node::addNode(std::string text = "", double num = 0.0)
{
	Node *temp = this;
	while (temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = new Node(text, num);
}
void Node::printList()
{	
	int nodeNum = size - (size - 1);
	Node *temp = this;
	cout << "_______________________" << endl;
	cout << "Node " << nodeNum-1 << " text: " << temp->text <<endl;
	cout << "Node " << nodeNum - 1 << " number: " << temp->num <<  endl;
	cout << "_______________________" << endl;
	nodeNum++;
	 while (temp->next != NULL){
		temp = temp->next;
		cout << "_______________________" << endl;
		cout << "Node " << nodeNum - 1 << " text: " << temp->text  << endl;
		cout << "Node " << nodeNum - 1 << " number: " << temp->num  << endl;
		cout << "_______________________" << endl;
		nodeNum++;
		
	}
}

void Node::editNode(int location)
{
	if (location > size)
	{
		cout << "The size you entered is larger than the list" << endl;
		return;
	}
	Node *temp = this;
	if (location == 0)
	{
		editMenu(temp);
		return;
	}
	for (int i = 0; i < location; i++){
		if (temp->next != NULL){
			temp = temp->next;

		}
	}
	editMenu(temp);
}

void Node::removeNode(int location)
{
	if (location > size)
	{
		cout << "The size you entered is larger than the list" << endl;
		return;
	}
	Node *temp = this;
	Node *temp2 = this;
	if (location == 0)
	{
		*this = *this->next;
		size--;
		return;
	}
	for (int i = 0; i < location-1; i++){
		if (temp->next != NULL){
			temp = temp->next;
		}
	}
	size--;
	temp->next = temp->next->next;
}

void Node::menu(Node* node)
{
	int choice = 0;
	while (choice != 5)
	{
		cout << endl;
		cout << "----------Node Menu----------" << endl;
		cout << "---Please Select an option---" << endl;
		cout << "1. Add Node" << endl;
		cout << "2. Edit Node" << endl;
		cout << "3. Remove Node" << endl; 
		cout << "4. Print Nodes" << endl;
		cout << "5. Exit" << endl;
		cout << "(Current Number of Nodes: "<<node->getSize()<<")"<< endl;
		
		cout << endl;
		cout << "Your Choice Here: ";
		cin >> choice;
		while (choice < 0 || choice>5)
		{
			cout << "Invalid Choice. Please try again: ";
			cin.ignore(1000, '\n');
			cin >> choice;
		}
		switch (choice)
		{
		case(1) :
		{
			std::string tempS;
			int tempN;
			cout << "Enter the name of the node "<<node->getSize()<<": ";
			cin.ignore(1000, '\n');
			getline(cin, tempS);
			cout << endl;
			srand(time(NULL));
			tempN = rand() % 1000 + 1;
			node->addNode(tempS, tempN);
			break;
		}
		case(2):
		{
			int tempL;
			cin.ignore(1000, '\n');
			cout << "Enter location of the node you'd like to edit: ";
			cin >> tempL;
			node->editNode(tempL);
			break;
		}
		case(3):
		{
			int tempL;
			cin.ignore(1000, '\n');
			cout << "Enter location of the node you'd like to remove: ";
			cin >> tempL;
			node->removeNode(tempL);
			break;
		}
		case(4) : {node->printList(); break; }
		case(5) : {return; break; }
		}
	}
}