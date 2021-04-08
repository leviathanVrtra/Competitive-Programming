#include <iostream>
using namespace std;

#define TREE_SIZE 100
#define INF 1000000

int heapSize;

void Swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int getRightChild(int arr[], int idx) {
    if ((((2 * idx) + 1) < TREE_SIZE) && idx >= 0) {
        return ((2 * idx) + 1);
    }
    return -1;
}

int getLeftChild(int arr[], int idx) {
    if ((((2 * idx) + 2) < TREE_SIZE) && idx >= 0) {
        return (2 * idx);
    }
    return -1;
}

int getParent(int arr[], int idx) {
    if ((idx > 0) && (idx < TREE_SIZE)) {
        return (idx / 2);
    }
    return -1;
}

int getMaximum(int arr[]) {
    return arr[0];
}

void maxHeapify(int arr[], int idx) {
    int lChild = getLeftChild(arr, idx);
    int rChild = getRightChild(arr, idx);
    int largest = idx;

    if ((lChild <= heapSize) && (lChild > 0)) {
        if (arr[lChild] > arr[largest]) {
            largest = lChild;
        }
    }

    if ((rChild <= heapSize) && (rChild > 0)) {
        if (arr[rChild] > arr[largest]) {
            largest = rChild;
        }
    }

    if (largest != idx) {
        Swap(&arr[idx], &arr[largest]);
        maxHeapify(arr, largest);
    }
}

int extractMax(int arr[]) {
    int mx = arr[0];
    arr[0] = arr[heapSize];
    heapSize--;
    maxHeapify(arr, 0);
    return mx;
}

void increaseKey(int arr[], int idx, int key) {
    arr[idx] = key;
    while ((idx >= 1) && (arr[getParent(arr, idx)] < arr[idx])) {
        Swap(&arr[idx], &arr[getParent(arr, idx)]);
        idx = getParent(arr, idx);
    }
}

void decreaseKey(int arr[], int idx, int key) {
    arr[idx] = key;
    maxHeapify(arr, idx);
}

void Insert(int arr[], int key) {
    arr[heapSize] = -1 * INF;
    increaseKey(arr, heapSize, key);
    heapSize++;
}

void Print(int arr[]) {
    for (int i = 0; i <= heapSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    int arr[1000];
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        Insert(arr, x);
    }
    Print(arr);
    return 0;
}

/*
10
20 6 8 1 5 7 15 2 9 10
*/