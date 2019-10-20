// Programmer: Aleksandra Sukhodolskaia
// Programmer's ID: 1651380

#include <iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

//prototypes of the functions
void merge(double[], int, int, int);
void mergeSort(double[], int, int);
void printArray(double[], int);

int main() {

    //create an array of running time
        double arr[] = {12.8, 11.2, 13.9, 5.8, 6.1,
                        7.8, 3.2, 1.9, 1.5, 6.2,
                        12.2, 11.5, 13.6, 5.1, 6.3,
                        7.5, 3.8, 1.5, 1.3, 6.6,
                        9.1, 6.7, 3.6, 2.2, 1.5};
        //calculate the size of an array
        int size = sizeof(arr)/sizeof(arr[0]);

        //printing unsorted array
        cout << "Given array is \n";
        printArray(arr, size);

        //sorting an array
        mergeSort(arr, 0, size - 1);

        //printing the sorted array
        cout<<"\nSorted array is \n";
        printArray(arr, size);
        return 0;
}

//function prints an array
void printArray(double arr[], int size)
{
    int i;
    for (i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(double arr[], int left, int middle, int right)
{
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 =  right - middle;

    // create temp arrays left and right ones
    double LArray[n1], RArray[n2];

    // Copy data to temp arrays
    for (int i = 0; i < n1; i++) {
        LArray[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        RArray[i] = arr[middle + 1 + i];
    }

    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = left; // Initial index of merged subarray

    // Merge the temp arrays back into arr[]
    while (i < n1 && j < n2)
    {
        //if the value in left array is less than right or equal
        //then it moves to arr[]
        if (LArray[i] <= RArray[j])
        {
            arr[k] = LArray[i];
            //since we already checked left array's value at index
            //'i' we move to next index
            i++;
        }
        else
        {
            //if the value in right array is less than left
            //then it moves to arr[]
            arr[k] = RArray[j];
            //since we already checked right array's value at index
            //'i' we move to next index
            j++;
        }
        //we move to the next value of arr[]
        k++;
    }

    //Copy the remaining elements of LArray[], if there are any
    while (i < n1)
    {
        arr[k] = LArray[i];
        i++;
        k++;
    }

    //Copy the remaining elements of RArray[], if there are any
    while (j < n2)
    {
        arr[k] = RArray[j];
        j++;
        k++;
    }
}

//"left" is for left index
// "right" is right index of the sub-array to be sorted
void mergeSort(double arr[], int left, int right)
{
    //controls that the left index does not intersect the right ones
    //otherwise, it would mean that the sorting is done.
    if (left < right)
    {
        //calculate the center of an array
        int middle = left+(right-left)/2;

        // Sort first and second halves of an array
        mergeSort(arr, left, middle);
        mergeSort(arr, middle+1, right);

        //when the sorting is done, the two arrays are merged together
        merge(arr, left, middle, right);
    }
}