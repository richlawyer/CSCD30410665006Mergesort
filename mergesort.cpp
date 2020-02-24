#include <iostream>
 
using namespace std;
 

void Merge(int *a, int low, int high, int mid)
{
	
	int b, y, k, temp[high-low+1];
	b = low;
	k = 0;
	y = mid + 1;
 
	
	while (b <= mid && y <= high)
	{
		if (a[b] < a[y])
		{
			temp[k] = a[b];
			k++;
			b++;
		}
		else
		{
			temp[k] = a[y];
			k++;
			y++;
		}
	}
 
	
	while (b <= mid)
	{
		temp[k] = a[b];
		k++;
		b++;
	}
 
	
	while (y <= high)
	{
		temp[k] = a[y];
		k++;
		y++;
	}
 
 
	
	for (b = low; b <= high; b++)
	{
		a[b] = temp[b-low];
	}
}
 

void MergeSort(int *a, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid=(low+high)/2;
	
		MergeSort(a, low, mid);
		MergeSort(a, mid+1, high);
 
		
		Merge(a, low, high, mid);
	}
}
 
int main()
{
	int n, b;
	cout<<"\nEnter the number of data element to be sorted: ";
	cin>>n;
 
	int arr[n];
	for(b = 0; b < n; b++)
	{
		cout<<"Enter element "<<b+1<<": ";
		cin>>arr[b];
	}
 
	MergeSort(arr, 0, n-1);
 
	
	cout<<"\nSorted Data ";
	for (b = 0; b < n; b++)
        cout<<"->"<<arr[b];
 
	return 0;
}
