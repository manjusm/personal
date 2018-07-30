#include <iostream>

void func (int &num)
{
	num++;
}	

int main()
{
	int num = 10;
	func(num);
	printf("%d\n", num);
	return 0;
}
