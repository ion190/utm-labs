#include <stdio.h>
#include <math.h>
#include <time.h>

void bubbleSort(int arr[], int n);
void insertionSort(int arr[], int n);
void selectionSort(int arr[], int n);
void sortQuick(int arr[], int start, int end);

int main() {
    int n; // length of array

    printf("n = ");
    scanf("%d", &n);

    int arr[n];

    printf("Array:\n");
    for(int i = 1; i <= n; ++i) {
        printf("Element %d = ", i);
        scanf("%d", &arr[i-1]);
    }
    // output each sorting algorithm
    bubbleSort(arr, n);
    insertionSort(arr, n);
    selectionSort(arr, n);
    sortQuick(arr, 0, n);

return 0;
}


// BUBBLE SORT
void bubbleSort(int arr[], int n) {
    int i, j;
    clock_t start, end;
    int cpu_microseconds_used;

    start = clock();

for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - 1 - i; j++) {
      if (arr[j] > arr[j + 1]) {
        int swap = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = swap;
      }
    }
}

    end = clock();
    cpu_microseconds_used = (int) ((((double) (end - start)) * 1000000) / CLOCKS_PER_SEC);

    printf("\nBubbleSort: [");
    for(int i = 0; i < n; ++i) {
        (i == n-1) ? printf("%d]", arr[i]) : printf("%d, ", arr[i]);
    }
    printf("\nExecution time: %d microseconds\n", cpu_microseconds_used);
}


// INSERTION SORT
void insertionSort(int arr[], int n) {
    int i, a, j;
    clock_t start, end;
    int cpu_microseconds_used;

    start = clock();

    for (i = 1; i < n; i++) {
        a = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > a) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = a;
    }

    end = clock();
    cpu_microseconds_used = (int) ((((double) (end - start)) * 1000000) / CLOCKS_PER_SEC);

    printf("\nInsertionSort: [");
    for(int i = 0; i < n; ++i) {
        (i == n-1) ? printf("%d]", arr[i]) : printf("%d, ", arr[i]);
    }
    printf("\nExecution time: %d microseconds\n", cpu_microseconds_used);

}

// SELECTION SORT
void selectionSort(int arr[], int n) {
    clock_t start, end;
    int cpu_microseconds_used;

    start = clock();

    for (int i = 0; i < n - 1; i++) {
    int min = i;
    for (int j = i + 1; j < n; j++) {

      // To sort in descending order, change > to < in this line.
      // Select the minimum element in each loop.
      if (arr[j] < arr[min])
        min = j;
    }

    // put min at the correct position
    int s = arr[min];
    arr[min] = arr[i];
    arr[i] = s;
  }

    end = clock();
    cpu_microseconds_used = (int) ((((double) (end - start)) * 1000000) / CLOCKS_PER_SEC);

    printf("\nSelectionSort: [");
    for(int i = 0; i < n; ++i) {
        (i == n-1) ? printf("%d]", arr[i]) : printf("%d, ", arr[i]);
    }
    printf("\nExecution time: %d microseconds\n", cpu_microseconds_used);
}

// QUICK SORT
int partition(int arr[], int start, int end);
void swap(int* a, int* b);
void quickSort(int arr[], int start, int end);

void sortQuick(int arr[], int start, int end) {
    clock_t start1, end1;
    int cpu_microseconds_used;

    start1 = clock();

    quickSort(arr, start, end);

    end1 = clock();

    cpu_microseconds_used = (int) ((((double) (end1 - start1)) * 1000000) / CLOCKS_PER_SEC);

    printf("\nQuickSort: [");
    for(int i = 0; i < end; ++i) {
        (i == end-1) ? printf("%d]", arr[i]) : printf("%d, ", arr[i]);
    }
    printf("\nExecution time: %d microseconds\n", cpu_microseconds_used);

}

void quickSort(int arr[], int start, int end) {
    if (start < end) {
        // find the pivot element such that elements smaller than pivot are on left of pivot elements greater than pivot are on right of pivot
        int pi = partition(arr, start, end);

        // recursive call on the left of pivot
        quickSort(arr, start, pi - 1);
        // recursive call on the left of pivot
        quickSort(arr, pi + 1, end);
    }
}

// use the last element as the pivot:
    int partition(int arr[], int start, int end) {
        int pivot = arr[end];

        // Index of smaller element and indicates
        // the right position of pivot found so far
        int i = (start - 1);

        for (int j = start; j <= end - 1; j++) {

            if (arr[j] < pivot) {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[end]);
        return (i + 1);
    }

    // swap 2 elements:
    void swap(int* a, int* b) {
        int t = *a;
        *a = *b;
        *b = t;
    }
