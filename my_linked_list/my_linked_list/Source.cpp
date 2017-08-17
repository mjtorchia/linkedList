#include "Node.h"
#include <iostream>
using namespace std;

int main(){ 

Node *myNode = new Node("Init",0);//0
myNode->menu(myNode);
system("PAUSE");
return 0;
}