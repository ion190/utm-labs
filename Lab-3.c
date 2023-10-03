#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

int[] sort2DMatrix(int arr[][], int n, int m);
int[][] mountainSort(int arr[], int n, int m);
int[] sortQuick(int arr[], int start, int end);


int[] sort2DMatrix(int arr[][], int n, int m) {
    int sorted1D[n*m];
    int index = 0;

    // push all elements from arr to sorted1D
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            sorted1D[index] = arr[n][m];
            index++;
        }
    }
    sorted1D = sortQuick(sorted1D, 0, n*m);
    
    return sorted1D;
}

int[][] mountainSort(int oldArr[], int n, int m) {
    int newArr[n][m];
    int indexOfOldArr = 0;
    int xStart = 0;
    int yStart = 0;
    int xEnd = m-1;
    int yEnd = n-1;

    while (indexOfOldArr < n*m) {
            // move right
            for (int i = xStart; i <= xEnd; i++) {
                newArr[yStart][i] = oldArr[indexOfOldArr];
                indexOfOldArr++;
            }
            yStart++;

        // move down
            for (int i = yStart; i <= yEnd; i++) {
                newArr[yStart][xEnd] = oldArr[indexOfOldArr];
                indexOfOldArr++;
            }
            xEnd--;

        // move left
                for (int i = xEnd; i >= xStart; i--) {
                    newArr[yEnd][xEnd] = oldArr[indexOfOldArr];
                    indexOfOldArr++;
                }
                yEnd--;

        // move up
            for (int i = yEnd; i >= yStart; i--) {
                newArr[yEnd][xStart] = oldArr[indexOfOldArr];
                indexOfOldArr++;
            }
            xStart++;
    }
                   
}


int main() {
    int n, m; // lengths of array
    printf("n (row) = ");
    scanf("%d", &n);
    printf("m (column) = ");
    scanf("%d", &m);
    
    int arr[n][m];
    printf("\nArray:\n");
    for(int i = 1; i <= n; i++) {
        printf("Row %d", i);
        for(int j = 1; j <= m; j++) {
            printf("Element %d = ", j);
            scanf("%d", &arr[i-1][j-1]);
        }
    }

    int[] sortedMatrix1D = sort2DMatrix(arr[][], n, m);
    int[][] sortedMatrix2D = mountainSort(sortedMatrix1D, n, m);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (j == m-1) {
                printf("%d\n", sortedMatrix2D[i][j]);
            } else {
                printf("%d ", sortedMatrix2D[i][j]);
            }
        }
    }

return 0;
}



// QUICK SORT
int partition(int arr[], int start, int end);
void swap(int a, int b);
void quickSort(int arr[], int start, int end);

int[] sortQuick(int arr[], int start, int end) {
    quickSort(arr, start, end);

    return arr;
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












#include <stdio.h>
#include <time.h>
#include <stdbool.h>

// Function prototypes
int* sort2DMatrix(int arr[][100], int n, int m);
void mountainSort(int oldArr[], int newArr[][100], int n, int m);
int* sortQuick(int arr[], int start, int end);

int main() {
    int n, m; // lengths of array
    printf("n (row) = ");
    scanf("%d", &n);
    printf("m (column) = ");
    scanf("%d", &m);
    
    int arr[n][m];
    printf("\nArray:\n");
    for(int i = 0; i < n; i++) {
        printf("Row %d:\n", i + 1);
        for(int j = 0; j < m; j++) {
            printf("Element %d = ", j + 1);
            scanf("%d", &arr[i][j]);
        }
    }

    int* sortedMatrix1D = sort2DMatrix(arr, n, m);
    int sortedMatrix2D[n][m];

    mountainSort(sortedMatrix1D, sortedMatrix2D, n, m);

    printf("\nSorted Array:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d ", sortedMatrix2D[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// Sorts a 2D matrix into a 1D array using quicksort
int* sort2DMatrix(int arr[][100], int n, int m) {
    int* sorted1D = (int*)malloc(sizeof(int) * n * m);
    int index = 0;

    // Push all elements from arr to sorted1D
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            sorted1D[index] = arr[i][j];
            index++;
        }
    }

    sortQuick(sorted1D, 0, n * m);

    return sorted1D;
}

// Sorts a 1D array using quicksort
int* sortQuick(int arr[], int start, int end) {
    if (start < end) {
        // Find the pivot element such that elements smaller than pivot are on the left, elements greater than pivot are on the right
        int p = partition(arr, start, end);

        // Recursive call on the left of pivot
        sortQuick(arr, start, p - 1);
        // Recursive call on the right of pivot
        sortQuick(arr, p + 1, end);
    }

    return arr;
}

// Rest of your code remains unchanged...

