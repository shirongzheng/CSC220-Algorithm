//
//  main.cpp
//  CSc220_Programing_Exercise#1
//
// Write a software using an O(nlogn)algorithm to find the average of maximum 3 elements in an array size N
//and also the average of minimum 3 elements
//
//  Created by Shirong Zheng on 09/10/16.



#include <iostream>
using namespace std;
#include <stdio.h>
#include <cmath>

void merge(int *,int, int , int );
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
    int size, j, k, c[20];
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


int main()
{
    int a[20], size;
    cout<<"Please enter some elements(ex.enter 7 elements)\n";
    for (size = 0; size < 7; size++)
    {
        cin>>a[size];
    }
    mergesort(a, 0, 6);
    cout<<"After sorted array\n";
    for (size = 0; size < 7; size++)
    {
        cout<<a[size]<<" ";
    }
   
    cout<<endl;
    
    float average_min= (a[0]+a[1]+a[2])/3;
    cout<<"The average of the minimum 3 elements is: "<<average_min<<endl;
    float average_max= (a[size]+a[size-1]+a[size-2])/3;
    cout<<"The average of the maximum 3 elements is: "<<average_max<<endl;
    return 0;
}

