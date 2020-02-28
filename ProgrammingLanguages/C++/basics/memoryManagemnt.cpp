#include <iostream>


int main()
{
	int *iptr = NULL;
	double *dptr = NULL;

	iptr = new int[2];
	*iptr = 20;
	*(iptr+1) = 30;
	dptr = new double(5.0);
	
	printf("%d %f\n", *(iptr+1), *dptr);

	delete iptr;
	delete dptr;

	return 0;
}

