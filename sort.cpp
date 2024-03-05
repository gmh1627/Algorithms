#include <bits/stdc++.h>

using namespace std;

// Bubble Sort
// Repeatedly swap the adjacent elements if they are in wrong order.
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++)     
        for (int j = 0; j < n-i-1; j++) 
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
}

// Selection Sort
// The smallest element is selected from the unsorted array and swapped with the leftmost element, and that element becomes a part of the sorted array.
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(arr[min_idx], arr[i]);
    }
}

// Insertion Sort
// Array is virtually split into a sorted and an unsorted region. Values from the unsorted region are picked and placed at the correct position in the sorted region.
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Merge Sort
// Merges two subarrays of arr[].First subarray is arr[l..m].Second subarray is arr[m+1..r]
void merge(vector<int>& arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // create temp arrays
    vector<int> L(n1), R(n2);

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// An example of divide and conquer algorithm. It continuously divides an array into two halves, sorts them separately and merges them.
void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Quick Sort
// An efficient sorting algorithm that works by selecting a 'pivot' element from the array and partitioning the other elements into two sub-arrays, according to whether they are less than or greater than the pivot.
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Shell Sort
// A generalization of insertion sort that allows the exchange of items that are far apart.
void shellSort(vector<int>& arr) {
    int n = arr.size();
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

// Heap Sort
// A comparison based sorting technique based on Binary Heap data structure.
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        for(int i : arr) 
        cout << i << " ";
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)//从最后一个非叶子节点开始构造最大堆
        heapify(arr, n, i);
    for (int i=n-1; i>=0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Bucket Sort
// A sorting technique that sorts the elements by first dividing the elements into several groups called buckets.
void bucketSort(vector<int>& arr) {
    int n = arr.size();
    int max_val = *max_element(arr.begin(), arr.end());
    max_val++;
    vector<int> bucket[max_val];
    for (int i = 0; i < n; i++) 
        bucket[arr[i]].push_back(arr[i]);
    int index = 0;
    for (int i = 0; i < max_val; i++) {
        while (!bucket[i].empty()) {
            arr[index++] = *(bucket[i].begin());
            bucket[i].erase(bucket[i].begin());
        }
    }
}

int main() {
    vector<int> arr1 = {64, 34, 25, 12, 22, 11, 90};
    bubbleSort(arr1);
    for(int i : arr1) 
        cout << i << " ";
    cout<<endl;
    vector<int> arr2 = {64, 34, 25, 12, 22, 11, 90};
    selectionSort(arr2);
    for(int i : arr2) 
        cout << i << " ";
    cout<<endl;
    vector<int> arr3 = {64, 34, 25, 12, 22, 11, 90};
    insertionSort(arr3);
    for(int i : arr3) 
        cout << i << " ";
    cout<<endl;
    vector<int> arr4= {64, 34, 25, 12, 22, 11, 90};
    mergeSort(arr4, 0, arr4.size()-1);
    for(int i : arr4) 
        cout << i << " ";
    cout<<endl;
    vector<int> arr5= {64, 34, 25, 12, 22, 11, 90};
    quickSort(arr5, 0, arr4.size()-1);
    for(int i : arr5) 
        cout << i << " ";
    cout<<endl;
    vector<int> arr6 = {64, 34, 25, 12, 22, 11, 90};
    shellSort(arr6);
    for(int i : arr6) 
        cout << i << " ";
    cout<<endl;
    vector<int> arr7 = {64, 34, 25, 12, 22, 11, 90};
    heapSort(arr7);
    for(int i : arr7) 
        cout << i << " ";
    cout<<endl;
    vector<int> arr8 = {64, 34, 25, 12, 22, 11, 90}; 
    bucketSort(arr8);
    for(int i : arr8) 
        cout << i << " ";
    cout<<endl;
    return 0;
}