#include <iostream>
#include<stdio.h>
using namespace std;


//Зад.1

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





//Зад.2


void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {

        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}


void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {

        int pi = partition(arr, low, high);


        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

    int main()
{

    int arr[] = {24, 23, 25, 8, 9, 10};
    int n = sizeof(arr)/sizeof(arr[0]);

    heapSort(arr, n);

    cout << "Sorted array is \n";

    printArray(arr, n);


    int arr_[] = {10, 7, 8, 9, 1, 5};
    int p = sizeof(arr_)/sizeof(arr_[0]);
    quickSort(arr, 0, p-1);
    printf("Sorted array: \n");
    printArray(arr_, p);
    return 0;
}
