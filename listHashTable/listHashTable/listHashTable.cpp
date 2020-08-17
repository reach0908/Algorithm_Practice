
#include <iostream>
#include "HashTable.h"
using namespace std;

int main()
{
	HashTable<int,string> h;
	h.insert(11, "KIM");
	h.insert(12, "LEE");
	h.insert(13, "PARK");
	h.insert(14, "SEONG");
	h.insert(15, "HONG");
	h.insert(16, "YOON");
	h.insert(17, "JEONG");
	h.insert(1111, "SHIN");

	


	h.dump();
	
	h.deleteKey(1111);

	h.dump();

}

