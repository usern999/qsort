#include <random>
#include <time.h>
#include <conio.h>
/**
	\file qsort_w.cpp qsort file
*/


/**
 qsort
 */

/**
	\param A array
	\param low low index
	\param high high index
*/
void qsort1(int* A, int low, int high)		
{
	int i = low;                
	int j = high;
	int x = A[(low+high)/2];				/** selection of the reference element */
	do 
	{
		while(A[i] < x) ++i;				/** search for items to move */
		while(A[j] > x) --j;  
		if(i <= j)
		{           
			int d = A[i];					/** moving items */
			A[i] = A[j];
			A[j] = d;
			i++;
			j--;
		}
	} while(i < j);
	if(low < j) qsort1(A, low, j);			/** recursive call to the remaining parts of the array */
	if(i < high) qsort1(A, i, high);
}


void main()
{
	int a[10];
	srand(time(NULL));

	for(int i=0;i<10;++i)
	{
		a[i]=rand()%100;
	}

	for(int i=0;i<10;++i)
	{
		printf("%d ",a[i]);
	}
	
	printf("\n");

	qsort1(a,0,9);

	for(int i=0;i<10;++i)
	{
		printf("%d ",a[i]);
	}
	getch();
}