#include <random>
#include <time.h>
#include <conio.h>

void qsort1(int* A, int low, int high)
{
	int i = low;                
	int j = high;
	int x = A[(low+high)/2];  
	do 
	{
		while(A[i] < x) ++i;  
		while(A[j] > x) --j;  
		if(i <= j)
		{           
			int d = A[i];
			A[i] = A[j];
			A[j] = d;
			i++;
			j--;
		}
	} while(i < j);
	if(low < j) qsort1(A, low, j);
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