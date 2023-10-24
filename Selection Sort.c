//Selection sort
#include<stdio.h>

void selectionSort(int a[],int n);

int main()
{
	int a[100];
	int n,i;
	printf("How many elements are in your array: ");
	scanf("%d",&n);
	printf("Enter elements: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	selectionSort(a,n);
	printf("Sorted array is: ");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
		
	printf("\nTime Complexity: Selection Sort has a quadratic time complexity of O(n^2) in all cases, regardless of the initial order of elements in the array. This makes it less efficient than more advanced sorting algorithms for larger datasets.\n");
	printf("\nSelection Sort has a space complexity of O(1) because it sorts the array in-place, meaning it does not require additional memory proportional to the size of the input. The space complexity is constant, as it uses only a few extra variables to perform the swapping.");

}
void selectionSort(int a[],int n)
{
	int i,j,min;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
				min=j;
		}
		int temp;
		temp=a[min];
		a[min]=a[i];
		a[i]=temp;
	}
}
