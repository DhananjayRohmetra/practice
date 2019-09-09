// C program to Count 
// Inversions in an array 
// using Merge Sort 
#include <bits/stdc++.h> 
using namespace std;

long long int _mergeSort(long long int arr[], long long int temp[], long long int left, long long int right); 
long long int merge(long long int arr[], long long int temp[], long long int left, long long int mid, long long int right); 

/* This function sorts the input array and returns the 
number of inversions in the array */
long long int mergeSort(long long int arr[], long long int array_size) 
{ 
	long long int* temp = (long long int*)malloc(sizeof(long long int) * array_size); 
	return _mergeSort(arr, temp, 0, array_size - 1); 
} 

/* An auxiliary recursive function that sorts the input array and 
returns the number of inversions in the array. */
long long int _mergeSort(long long int arr[], long long int temp[], long long int left, long long int right) 
{ 
	long long int mid, inv_count = 0; 
	if (right > left) { 
		/* Divide the array long long into two parts and call _mergeSortAndCountInv() 
	for each of the parts */
		mid = (right + left) / 2; 

		/* Inversion count will be sum of inversions in left-part, right-part 
	and number of inversions in merging */
		inv_count = _mergeSort(arr, temp, left, mid); 
		inv_count += _mergeSort(arr, temp, mid + 1, right); 

		/*Merge the two parts*/
		inv_count += merge(arr, temp, left, mid + 1, right); 
	} 
	return inv_count; 
} 

/* This funt merges two sorted arrays and returns inversion count in 
the arrays.*/
long long int merge(long long int arr[], long long int temp[], long long int left, long long int mid, long long int right) 
{ 
	long long int i, j, k; 
	long long int inv_count = 0; 

	i = left; /* i is index for left subarray*/
	j = mid; /* j is index for right subarray*/
	k = left; /* k is index for resultant merged subarray*/
	while ((i <= mid - 1) && (j <= right)) { 
		if (arr[i] <arr[j]) { 
			if(arr[i]<arr[j]){
			inv_count = inv_count + (right-j+1)*arr[i]; }
			temp[k++] = arr[i++];
		
			
		} 
		else { 
			temp[k++] = arr[j++]; 
		} 
	} 

	/* Copy the remaining elements of left subarray 
(if there are any) to temp*/
	while (i <= mid - 1) 
		temp[k++] = arr[i++]; 

	/* Copy the remaining elements of right subarray 
(if there are any) to temp*/
	while (j <= right) 
		temp[k++] = arr[j++]; 

	/*Copy back the merged elements to original array*/
	for (i = left; i <= right; i++) 
		arr[i] = temp[i]; 

	return inv_count; 
} 

/* Driver program to test above functions */
int main(int argv, char** args) 
{ 
	long long int t;
	cin>>t;
	while(t--)
	{
	long long int arr[100000]; 
	long long int n,i;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<mergeSort(arr, n)<<"\n"; 
	getchar(); 
	}
} 

