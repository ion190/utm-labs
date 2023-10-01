#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

void bubbleSort(int arr[], int n);
void insertionSort(int arr[], int n);
void selectionSort(int arr[], int n);
void sortQuick(int arr[], int start, int end);
void cocktailSort(int arr[], int n);

int main() {
    int n; // length of array

    printf("n = ");
    scanf("%d", &n);

    int arr[n];

    printf("Array:\n");
    for(int i = 1; i <= n; i++) {
        printf("Element %d = ", i);
        scanf("%d", &arr[i-1]);
    }
    // output each sorting algorithm
    bubbleSort(arr, n);
    cocktailSort(arr, n);
    insertionSort(arr, n);
    selectionSort(arr, n);
    sortQuick(arr, 0, n);

return 0;
}


// BUBBLE SORT
void bubbleSort(int arr[], int n) {
    int i, j; // i - iterations through array, j - index of each array element
    bool swapped;

    clock_t start, end;
    int cpu_microseconds_used;
    start = clock();

for (i = 0; i < n - 1; i++) { // check for each integer whether to swap or not
    swapped = false;
    for (j = 0; j < n - 1 - i; j++) { // push the biggest integer at the beginning of the array
      if (arr[j] > arr[j + 1]) {
        int swap = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = swap;
        swapped = true; // A swap occurred
      }
    }
    if (swapped == false) break; // if no elements were swapped, then stop the loop
}

    end = clock();
    cpu_microseconds_used = (int) ((((double) (end - start)) * 1000000) / CLOCKS_PER_SEC);

    printf("\nBubbleSort: [");
    for(int i = 0; i < n; i++) {
        (i == n-1) ? printf("%d]", arr[i]) : printf("%d, ", arr[i]);
    }
    printf("\nExecution time: %d microseconds\n", cpu_microseconds_used);
}


// COCKTAIL SORT
void cocktailSort(int arr[], int n) {
    bool swapped = true;
    int start = 0;
    int end = n - 1;

    clock_t start1, end1;
    int cpu_microseconds_used;
    start1 = clock();

    while (swapped == true) {
        // reset the swapped flag on entering the loop, because it might be true from a previous iteration.
        swapped = false;

        // loop from left to right same as the bubble sort
        for (int i = start; i < end; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        // if nothing moved, then array is sorted
        if (swapped == false)
            break;

        // otherwise, reset the swapped flag so that it can be used in the next stage
        swapped = false;

        // move the end point back by one, because item at the end is in its rightful spot
        end--;

        // from right to left, doing the same comparison as in the previous stage
        for (int i = end - 1; i >= start; i--) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        // increase the starting point, because the last stage would have moved the next smallest number to its rightful spot.
        start++;
    }

    end1 = clock();
    cpu_microseconds_used = (int) ((((double) (end1 - start1)) * 1000000) / CLOCKS_PER_SEC);

    printf("\nCocktailSort: [");
    for(int i = 0; i < n; i++) {
        (i == n-1) ? printf("%d]", arr[i]) : printf("%d, ", arr[i]);
    }
    printf("\nExecution time: %d microseconds\n", cpu_microseconds_used);
}


// INSERTION SORT
void insertionSort(int arr[], int n) {
    int i, a, j; // i - the right element, j - the left element

    clock_t start, end;
    int cpu_microseconds_used;
    start = clock();

    for (i = 1; i < n; i++) { // iterate through array
        a = arr[i];
        j = i - 1;

        // swap the right and left elements if they are not in order
        while (j >= 0 && arr[j] > a) {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = a;
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
        // Select the minimum element
        if (arr[min] > arr[j])
            min = j;
        }

        // put min at the correct position
        int x = arr[min];
        arr[min] = arr[i];
        arr[i] = x;
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
void swap(int a, int b);
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
        int p = partition(arr, start, end);

        // recursive call on the left of pivot
        quickSort(arr, start, p - 1);
        // recursive call on the left of pivot
        quickSort(arr, p + 1, end);
    }
}

// use the last element as the pivot
    int partition(int arr[], int start, int end) {
        int pivot = arr[end];
        int i = (start - 1); // index of the smaller element

        for (int j = start; j <= end - 1; j++) {

            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[end]);
        return (i + 1);
    }

    // swap 2 elements:
    void swap(int a, int b) {
        int t = a;
        a = b;
        b = t;
    }
