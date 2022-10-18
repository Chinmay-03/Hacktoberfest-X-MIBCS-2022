
#include <iostream>
using namespace std;

// Function to insert element
// at a specific positison
void insertElement(int arr[], int n, int x, int pos)
{
    // shift elements to the right
    // which are on the right side of pos
    for (int i = n - 1; i >= pos; i--)
        arr[i + 1] = arr[i];

    arr[pos] = x;
}

// Function to display an error
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

// Function to implement search operation
int findElement(int arr[], int n, int key)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == key)
            return i;

    return -1;
}

// Function to update an element in array
void updateElement(int arr[], int n, int key, int newKey)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == key)
            arr[i] = newKey;
}

// Function to delete an element
int deleteElement(int arr[], int n, int key)
{
    // Find position of element to be deleted
    int pos = findElement(arr, n, key);

    if (pos == -1)
    {
        cout << "Element not found";
        return n;
    }

    // Deleting element
    int i;
    for (i = pos; i < n - 1; i++)
        arr[i] = arr[i + 1];

    return n - 1;
}

// Function to Sort the array
void sort(int arr[], int n)
{
    sort(arr, arr + n);
}

void mergeArrays(int arr1[], int arr2[], int n1, int n2, int arr3[])
{
    int i = 0, j = 0, k = 0;
    // traverse the arr1 and insert its element in arr3
    while (i < n1)
    {
        arr3[k++] = arr1[i++];
    }

    // now traverse arr2 and insert in arr3
    while (j < n2)
    {
        arr3[k++] = arr2[j++];
    }

    // sort the whole array arr3
    sort(arr3, arr3 + n1 + n2);
}

// Driver's code
int main()
{
    int arr[15] = {2, 4, 1, 8, 5};
    int n = 5;
    int arr2[3] = {12, 23, 22};
    int n2 = 3;
    int arr3[n + n2];
    mergeArrays(arr, arr2, n, n2, arr3);
    display(arr3, n + n2);
    return 0;
}