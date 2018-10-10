#include <stdio.h>

int next(int n)
{	
	int x,y,z,nextTerm;
	x = n%10; // stores units place value
	n /= 10;
	y = n%10; // stores tens place value
	n/= 10;
	z = n%10; // stores hundreds place value
	nextTerm = y*y + x*x + z*z; // sums squares of individual digits
	return nextTerm;
}

int isInsipid(int val)
{ 
	int nextTerm;
	int returnVal;
	nextTerm = next(val);	
	if (nextTerm == 58)
	{ // if nextTerm hits 58, number is not insipid
		return 0; 
	}
	else if (nextTerm == 1)
	{ // if nextTerm hits 1, number is insipid
		return 1;
	}
	else
	{
		return isInsipid(nextTerm); // recurse
	}
}

int main()
{
	for(int i = 1; i < 99; i++)
	{ // checks which numbers between 1-99 are insipid
		if (isInsipid(i))
			printf("%d is insipid\n", i);
	}		
	return 0; // program runs without error
}