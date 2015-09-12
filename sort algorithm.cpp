/*
*------------------------------------quick sort
*
*/

int partition(int ary[],int low, int high){
	
	int pivot = ary[high];
	int i = low;
	int j;
	for(j=low;j<high;j++){
		//put all emlments less than pivot into front part
		if(ary[j] <= pivot){
			swap(ary[i],ary[j]);
			i++;			
		}
	}
	swap(ary[i],ary[high]);
	return i;
}

void quicksort(int ary[],int low,int high){
	
	int p = partition(ary,low,high);
	quicksort(ary,low,p-1);
	quicksort(ary,p+1,high);
	
}
//*********************************************************************




// ------------------binary search 
//两种方法 回归和迭代， 迭代用while
// A iterative binary search function. It returns location of x in
// given array arr[l..r] if present, otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
  while (l <= r)
  {
    int m = l + (r-l)/2;
 
    if (arr[m] == x) return m;  // Check if x is present at mid
 
    if (arr[m] < x) l = m + 1; // If x greater, ignore left half
 
    else r = m - 1; // If x is smaller, ignore right half
  }
  return -1; // if we reach here, then element was not present
}

// A recursive binary search function. It returns location of x in
// given array arr[l..r] is present, otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
   if (r >= l)
   {
        int mid = l + (r - l)/2;
 
        // If the element is present at the middle itself
        if (arr[mid] == x)  return mid;
 
        // If element is smaller than mid, then it can only be present
        // in left subarray
        if (arr[mid] > x) return binarySearch(arr, l, mid-1, x);
 
        // Else the element can only be present in right subarray
        return binarySearch(arr, mid+1, r, x);
   }
 
   // We reach here when element is not present in array
   return -1;
}


//-------------------------merge sort 
/*
Time complexity of Merge Sort is O(nLogn) in all 3 cases (worst, average and best) as merge sort always divides the array in two halves and take linear time to merge two halves.
Auxiliary Space: O(n)
Stable: Yes
*/

void merge(int arr[], int l, int m, int r){
	int i,j,k;
	int n1 = m-l+1;
	int n2 = r-m;
	
	/* creat temp arrays*/
	int L[n1],R[n2];
	
	/* copy data to temp arays L[n1]  R[n2]*/
	for(i=0;i<n1;i++)	 L[i] = arr[l+i];
	for(j = 0;j<n2;j++)   R[j] = arr[m+1+j];
	/*merge the temp arrays back into arr[l..r]*/
	i = 0;j=0; k = l;
	while(i<n1 && j<n2){
		
		if(L[i]<R[j]) {
			arr[k] = L[i];	
			i++;
		}
		els{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	/* Copy the remaining elements of L[], if there are any */
	while(i<n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	  /* Copy the remaining elements of R[], if there are any */
	while(j<n2){
		arr[k] = R[j];
		j++;
		k++;
	}
}

/* l is for left index and r is right index of the sub-array
  of arr to be sorted */
void mergesort(int array[],int left, int right){
	if(l<r){
		int m = left + (right-left)/2;
		mergesort(array,left ,m);
		mergesort(array,m+1, right);
		merge(array,left,m, right);
	}
}


//----------------insert sort
/*
for i ← 1 to length(A) - 1
    j ← i
    while j > 0 and A[j-1] > A[j]
        swap A[j] and A[j-1]
        j ← j - 1
    end while
end for
*/
void insertsort(int a[],int size){
    for(int i=1;i<size;i++){
        for(int j=i;j>0;j--){
            if(a[j-1]>a[j])
            {
				//swap a[j] and a[j-1]
			   int tmp = a[j-1];
                a[j-1]= a[j];
                a[j]= tmp;
                }
            }
        }
    }
	
//*************************************************************************************************************	

/*                                              shell sort */
//Time Complexity: Time complexity of above implementation of shellsort is O(n2).
/* function to sort arr using shellSort */
int shellSort(int arr[], int n)
{
    // Start with a big gap, then reduce the gap
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted 
        for (int i = gap; i < n; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];
 
            // shift earlier gap-sorted elements up until the correct 
            // location for a[i] is found
            int j;            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
             
            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
    return 0;
}
	
	
	
//*************************************************************************************************************		
	
	
	
	
	
	
	
// -----------------------------------------heap sort -------------------------------------------
// C implementation of Heap Sort
#include <stdio.h>
#include <stdlib.h>
 
// A heap has current size and array of elements
struct MaxHeap
{
    int size;
    int* array;
};
 
// A utility function to swap to integers
void swap(int* a, int* b) { int t = *a; *a = *b;  *b = t; }
 
// The main function to heapify a Max Heap. The function 
// assumes that everything under given root (element at 
// index idx) is already heapified
void maxHeapify(struct MaxHeap* maxHeap, int idx)
{
    int largest = idx;  // Initialize largest as root
    int left = (idx << 1) + 1;  // left = 2*idx + 1
    int right = (idx + 1) << 1; // right = 2*idx + 2
 
    // See if left child of root exists and is greater than
    // root
    if (left < maxHeap->size && 
        maxHeap->array[left] > maxHeap->array[largest])
        largest = left;
 
    // See if right child of root exists and is greater than
    // the largest so far
    if (right < maxHeap->size && 
        maxHeap->array[right] > maxHeap->array[largest])
        largest = right;
 
    // Change root, if needed
    if (largest != idx)
    {
        swap(&maxHeap->array[largest], &maxHeap->array[idx]);
        maxHeapify(maxHeap, largest);
    }
}
 
// A utility function to create a max heap of given capacity
struct MaxHeap* createAndBuildHeap(int *array, int size)
{
    int i;
    struct MaxHeap* maxHeap = 
              (struct MaxHeap*) malloc(sizeof(struct MaxHeap));
    maxHeap->size = size;   // initialize size of heap
    maxHeap->array = array; // Assign address of first element of array
 
    // Start from bottommost and rightmost internal mode and heapify all
    // internal modes in bottom up way
    for (i = (maxHeap->size - 2) / 2; i >= 0; --i)
        maxHeapify(maxHeap, i);
    return maxHeap;
}
 
// The main function to sort an array of given size
void heapSort(int* array, int size)
{
    // Build a heap from the input data.
    struct MaxHeap* maxHeap = createAndBuildHeap(array, size);
 
    // Repeat following steps while heap size is greater than 1. 
    // The last element in max heap will be the minimum element
    while (maxHeap->size > 1)
    {
        // The largest item in Heap is stored at the root. Replace
        // it with the last item of the heap followed by reducing the
        // size of heap by 1.
        swap(&maxHeap->array[0], &maxHeap->array[maxHeap->size - 1]);
        --maxHeap->size;  // Reduce heap size
 
        // Finally, heapify the root of tree.
        maxHeapify(maxHeap, 0);
    }
}
 
// A utility function to print a given array of given size
void printArray(int* arr, int size)
{
    int i;
    for (i = 0; i < size; ++i)
        printf("%d ", arr[i]);
}
 
/* Driver program to test above functions */
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr)/sizeof(arr[0]);
 
    printf("Given array is \n");
    printArray(arr, size);
 
    heapSort(arr, size);
 
    printf("\nSorted array is \n");
    printArray(arr, size);
    return 0;
}
// ----------------------------------------- -------------------------------------------