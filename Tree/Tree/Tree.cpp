

#include <iostream>
#include "BinaryTree.h"
#include "BST.h"


using namespace std;

int main()
{
	typedef BST<int> intBST;
	typedef intBST* intBSTPtr;

	intBSTPtr b(new intBST);

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

	intBSTPtr get11((BST<int>*)b->retrieve(11));
	intBSTPtr get13((BST<int>*)b->retrieve(13));

	if (get11->isEmpty()) {
		cout << "Not Found" << endl;
	}
	else
	{
		cout << "Found" << endl;
	}

	if (get13->isEmpty()) {
		cout << "Not Found" << endl;
	}
	else
	{
		cout << "Found" << endl;
	}

	return 0;
}


