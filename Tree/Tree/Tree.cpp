

#include <iostream>
#include "BinaryTree.h"
#include "BST.h"


using namespace std;

int main()
{
	typedef BST<int> intBST;
	typedef intBST* intBSTPtr;

	intBSTPtr b(new intBST);
	cout << "BST 삽입 및 서치" << endl;


	b->insert(17);
	b->insert(10);
	b->insert(26);
	b->insert(6);
	b->insert(14);
	b->insert(20);
	b->insert(28);
	b->insert(11);
	b->insert(31);
	b->insert(37);
	b->insert(12);
	cout << b->getData() << endl;
	cout << b->left()->getData() << " " << b->right()->getData() << endl;
	cout << b->left()->left()->getData() <<" "<< b->left()->right()->getData() << " " << b->right()->left()->getData() << " " << b->right()->right()->getData() << endl;
	cout << b->left()->right()->left()->getData() << " " << b->right()->right()->right()->getData() << endl;
	cout << b->left()->right()->left()->right()->getData() << " " << b->right()->right()->right()->right()->getData() << endl;
	  
	b->deleteNode(20);
	cout << b->getData() << endl;
	cout << b->left()->getData() << " " << b->right()->getData() << endl;
	cout << b->left()->left()->getData() << " " << b->left()->right()->getData() << " " << b->right()->right()->getData() << endl;
	cout << b->left()->right()->left()->getData() << " " << b->right()->right()->right()->getData() << endl;
	cout << b->left()->right()->left()->right()->getData() << " " << b->right()->right()->right()->right()->getData() << endl;
	intBSTPtr get20((BST<int>*)b->retrieve(20));
	if (get20->isEmpty())
		cout << "11 not found.\n";
	else
		cout << "11 found.\n";

	
	return 0;
}


