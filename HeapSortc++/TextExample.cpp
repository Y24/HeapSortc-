#include<iostream>
#include<cstdlib>
#include"Heap.h"
int main()
{
	int TextExampleInt;
	std::cin >> TextExampleInt;
	HEAP<int> TextExampleI(TextExampleInt);
	TextExampleI.CIN();
	TextExampleI.BUILD_MAX_HEAP();
	TextExampleI.HEAPSORT();
	TextExampleI.COUT(TextExampleInt);
	system("pause");
	return 0;
}