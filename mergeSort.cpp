#include<iostream>
using namespace std;

void merge(int* arr, int low, int mid, int high){
    int lengthLeft = mid - low + 1;
    int lengthRight = high - mid;

    int larr[lengthLeft], rarr[lengthRight];

    for(int i = 0; i< lengthLeft; i++){
        larr[i] = arr[low+i];
    }

    for(int i = 0; i < lengthRight; i++){
        rarr[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = low;

    while(i < lengthLeft && j < lengthRight){
        if(larr[i] <= rarr[j]){
            arr[k] = larr[i];
            i++;
        }
        else{
            arr[k] = rarr[j];
            j++;
        }
        k++;
    }

    while(i<lengthLeft){
        arr[k] = larr[i];
        i++;
        k++;
    }

    while(j<lengthRight){
        arr[k] = rarr[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int low, int high){
    if(low<high){
        int mid = (low + high)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

void printArray(int* arr, int n){
    for(int i = 0; i<n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){
    int arr[] = {9, 14, 4, 6, 5, 8, 7};

    int length = sizeof(arr) / sizeof(int);

    cout << "Array, before calling the mergeSort() : ";
    printArray(arr, length);

    mergeSort(arr, 0, length - 1);

    cout << "Array, after calling the mergeSort() : ";
    printArray(arr, length);
    
    return 0;
}