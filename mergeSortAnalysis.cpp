#include <iostream>
#include <chrono>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace std::chrono;

// Merge function
void merge(int* arr, int low, int mid, int high) {
    int lengthLeft = mid - low + 1;
    int lengthRight = high - mid;

    vector<int> larr(lengthLeft), rarr(lengthRight);

    for (int i = 0; i < lengthLeft; i++) {
        larr[i] = arr[low + i];
    }

    for (int i = 0; i < lengthRight; i++) {
        rarr[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = low;

    while (i < lengthLeft && j < lengthRight) {
        if (larr[i] <= rarr[j]) {
            arr[k] = larr[i];
            i++;
        } else {
            arr[k] = rarr[j];
            j++;
        }
        k++;
    }

    while (i < lengthLeft) {
        arr[k] = larr[i];
        i++;
        k++;
    }

    while (j < lengthRight) {
        arr[k] = rarr[j];
        j++;
        k++;
    }
}

// Merge Sort function
void mergeSort(int* arr, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

// Function to generate an array of random numbers
void generateRandomArray(int* arr, int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }
}

// Function to perform time analysis
void timeAnalysis(int sizes[], int count) {
    for (int i = 0; i < count; i++) {
        int n = sizes[i];
        int* arr = new int[n];
        
        // Generate random array of size 'n'
        generateRandomArray(arr, n);
        
        // Measure the time taken by mergeSort
        auto start = high_resolution_clock::now();
        mergeSort(arr, 0, n - 1);
        auto stop = high_resolution_clock::now();
        
        // Calculate the duration
        auto duration = duration_cast<milliseconds>(stop - start);
        
        // Output the size and time taken
        cout << "Array Size: " << n << " Time Taken: " << duration.count() << " ms" << endl;
        
        delete[] arr;
    }
}

int main() {
    // Test case sizes up to 10^6 elements
    int sizes[] = {10, 100, 1000, 5000, 10000, 50000, 100000, 500000, 1000000, 10000000, 10000000};
    int testCount = sizeof(sizes) / sizeof(sizes[0]);
    
    // Perform time analysis
    timeAnalysis(sizes, testCount);
    
    return 0;
}
