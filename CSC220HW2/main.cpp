//
//  main.cpp
//  CSC22000-D  HW#2-SortList
//
//  Shirong Zheng    2016/10/11.
//  
//

#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define random(x) (rand()%x)


void merge(int *,int, int , int );
void mergesort(int *a, int low, int high);
void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);
void printArray(int arr[], int n);
int partition(int *a,int p,int r);
void quickSortV1(int *a,int p,int r);
int random_partition(int* arr, int start, int end);
void quickSortV2(int* arr, int start, int end);


// Insertion Sort
void insertionSort (int arr[], int length){
    int j, temp;
    
    for (int i = 0; i < length; i++){
        j = i;
        
        while (j > 0 && arr[j] < arr[j-1]){
            temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }
}


// Merge Sort
void mergesort(int *a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,high,mid);
    }
    return;
}

void merge(int *a, int low, int high, int mid)
{
    int size, j, k, c[1000000];
    size = low; k = low;
    j = mid + 1;
    while (size <= mid && j <= high)
    {
        if (a[size] < a[j])
        {
            c[k] = a[size];
            k++; size++;
        }
        else
        {
            c[k] = a[j];
            k++; j++;
        }
    }
    while (size <= mid)
    {
        c[k] = a[size];
        k++; size++;
    }
    while (j <= high)
    {
        c[k] = a[j];
        k++; j++;
    }
    for (size = low; size < k; size++)
    {
        a[size] = c[size];
    }
}


// Heap Sort
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    
    if (l < n && arr[l] > arr[largest])
        largest = l;
    
    if (r < n && arr[r] > arr[largest])
        largest = r;
    
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    
    for (int i=n-1; i>=0; i--)
    {
        
        swap(arr[0], arr[i]);
        
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}


//Quick Sort V1:Pick A pivot from beginning to the end
int partition(int *a,int p,int r)
{
    srand(time(0));
    int pivot = rand()%(r-p);
    pivot += p;
    swap(a[r],a[pivot]);
    pivot = r;
    int temp = a[r];
    int i = p-1;
    for (int j = p; j < r ;j++) {
        if ( a[j] <  temp ) {
            i++;
            swap (a[i],a[j]);
        }
    }
    i++;
    swap (a[r],a[i]);
    return i;
}

void quickSortV1(int *a,int p,int r)
{
    if (p < r)
    {
        int q = partition(a,p,r);
        quickSortV1(a,p,q);
        quickSortV1(a,q+1,r);
    }
}


//Quick Sort V2:Pick A Random Pivot
int random_partition(int* arr, int start, int end)
{
    srand(time(NULL));
    int pivotIdx = start + rand() % (end-start+1);
    int pivot = arr[pivotIdx];
    swap(arr[pivotIdx], arr[end]); // move pivot element to the end
    pivotIdx = end;
    int i = start -1;
    
    for(int j=start; j<=end-1; j++)
    {
        if(arr[j] <= pivot)
        {
            i = i+1;
            swap(arr[i], arr[j]);
        }
    }
    
    swap(arr[i+1], arr[pivotIdx]);
    return i+1;
}

void quickSortV2(int* arr, int start, int end)
{
    if(start < end) {
        int mid = random_partition(arr, start, end);
        quickSortV2(arr, start, mid-1);
        quickSortV2(arr, mid+1, end);
    }
}


int main(){
    clock_t starttime=clock();
    srand(unsigned(time(0)));
    int max;
    cout<<"Please input the size of array (ex.10,100,1000,10000,100000...): ";
    cin>>max;
    int arr[max];
    cout<<"The random numbers of currently array size are:"<<endl;
    for(int i=0;i<max;i++){
        arr[i]=rand()%max;
        cout<<arr[i]<<" ";
    }
    cout<<"\n"<<"Numbers after insertionsort:";
    insertionSort(arr,max-1);
    for(int k=0;k<max;k++){
        cout<<arr[k]<<" ";
    }
    cout<<"\n"<<"Running Time of insertionSort:"<<double(clock()-starttime)/CLOCKS_PER_SEC<<'s'<<endl;
    cout<<"\n"<<"Numbers after mergesort: "<<endl;
    mergesort(arr,0,max-1);
    for(int j=0; j<max;j++){
        cout<<arr[j]<<" ";
    }
    cout<<"\n"<<"Running Time of mergesort:"<<double(clock()-starttime)/CLOCKS_PER_SEC<<'s'<<endl;
    
    heapSort(arr,max-1);
    cout<<"\n"<<"Numbers after heapsort:"<<endl;
    printArray(arr, max);
    cout<<"Running Time of heapSort:"<<double(clock()-starttime)/CLOCKS_PER_SEC<<'s'<<endl;
    cout<<"\n"<<"Numbers after QuickSort V1:"<<endl;
    quickSortV1(arr,0,max-1);
    for(int i=0; i<max;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n"<<"Running Time of QuickSort V1:"<<double(clock()-starttime)/CLOCKS_PER_SEC<<'s'<<endl;
    cout<<"\n"<<"Numbers after QuickSort V2:"<<endl;
    quickSortV2(arr,0,max-1);
    for(int i=0; i<max;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n"<<"Running Time of QuickSort V2:"<<double(clock()-starttime)/CLOCKS_PER_SEC<<'s'<<endl;
    return 0;
}
    
