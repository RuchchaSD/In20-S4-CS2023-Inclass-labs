#include <iostream>
using namespace std;
  
void heapify(int arr[], int n, int root) {
    int largest = root;
    int left_child = 2*root + 1;
    int right_child = 2*root + 2;
  
    if (left_child < n && arr[left_child] > arr[largest])
        largest = left_child;
  
    if (right_child < n && arr[right_child] > arr[largest])
        largest = right_child;
  
    if (largest != root) {
        swap(arr[root], arr[largest]);
        heapify(arr, n, largest);
    }
}
  
void heapSort(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);
  
    for (int i=n-1; i>=0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
  
void displayArray(int arr[], int n) {
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
  
int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int heap_arr[n];
    cout << "Enter the array elements:\n";
    for (int i = 0; i < n; i++)
        cin >> heap_arr[i];
  
    cout<<"Input array:"<<endl;
    displayArray(heap_arr, n);
  
    heapSort(heap_arr, n);
  
    cout << "Sorted array:"<<endl;
    displayArray(heap_arr, n);
    return 0;
}
