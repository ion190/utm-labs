#include <stdio.h>
#include <stdlib.h>

void kulevTask(int n, int m, int option, int** array) {
    switch (option) {
        case 0:

        break;
        
        case 1:
            array = (int**)malloc(n * sizeof(int*));
            
            for (int i = 0; i < n; i++) {
                    array[i] = (int*)malloc(m * sizeof(int));
            }
            printf("Dynamical memory allocated successfully\n");
            
            printf("\nMenu:\n");
            printf("1 - Allocate dynamical memory for bidimensional array\n");
            printf("2 - Input array elements from keyboard\n");
            printf("3 - Input array with random values\n");
            printf("4 - Sort odd columns in descendence order via liniar selection\n");
            printf("5 - Ouput array elements of screen\n");
            printf("6 - Free memory allocated for array\n");
            printf("0 - Exit program\n\n");
            
            printf("Enter choice: ");
            scanf("%d", &option);
            
            kulevTask(n, m, option, array);
        break;
        
        case 2:
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    printf("Row %d, Column %d: ", i+1, j+1);
                    scanf("%d", &array[i][j]);
                }
            }
            printf("Array elements assigned successfully\n");
            
            printf("\nMenu:\n");
            printf("1 - Allocate dynamical memory for bidimensional array\n");
            printf("2 - Input array elements from keyboard\n");
            printf("3 - Input array with random values\n");
            printf("4 - Sort odd columns in descendence order via liniar selection\n");
            printf("5 - Ouput array elements of screen\n");
            printf("6 - Free memory allocated for array\n");
            printf("0 - Exit program\n\n");
            
            printf("Enter choice: ");
            scanf("%d", &option);
            
            kulevTask(n, m, option, array);
        break;
        
        case 3:
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    array[i][j] = rand() % 100;
                    printf("Row %d, Column %d: %d\n", i+1, j+1, array[i][j]);
                }
            }
            printf("Random values assigned successfully\n");
            
            printf("\nMenu:\n");
            printf("1 - Allocate dynamical memory for bidimensional array\n");
            printf("2 - Input array elements from keyboard\n");
            printf("3 - Input array with random values\n");
            printf("4 - Sort odd columns in descendence order via liniar selection\n");
            printf("5 - Ouput array elements of screen\n");
            printf("6 - Free memory allocated for array\n");
            printf("0 - Exit program\n\n");
            
            printf("Enter choice: ");
            scanf("%d", &option);
            
            kulevTask(n, m, option, array);
        break;
        
        case 4:
            for (int countOddColumns = 1; countOddColumns < m; countOddColumns+=2) {
                int column[n];
                // push all elements of current column in array
                for (int i = 0; i < n; i++) {
                    column[i] = array[i][countOddColumns];
                }
                // sort the elements of the column array
                for (int i = 0; i < n - 1; i++) {
                    int minIndex = i;
                    // Find the index of the minimum element in the unsorted part
                    for (int j = i + 1; j < n; j++) {
                        if (column[j] < column[minIndex]) {
                            minIndex = j;
                        }
                    }
                    int x = column[i];
                    column[i] = column[minIndex];
                    column[minIndex] = x;
                }
                // change column elements of whole array in descending order
                for (int i = 0; i < n; i++) {
                    array[i][countOddColumns] = column[n-1-i];
                }
            }
            printf("Odd columns ordered in descendence successfully\n");
            
            printf("\nMenu:\n");
            printf("1 - Allocate dynamical memory for bidimensional array\n");
            printf("2 - Input array elements from keyboard\n");
            printf("3 - Input array with random values\n");
            printf("4 - Sort odd columns in descendence order via liniar selection\n");
            printf("5 - Ouput array elements of screen\n");
            printf("6 - Free memory allocated for array\n");
            printf("0 - Exit program\n\n");
            
            printf("Enter choice: ");
            scanf("%d", &option);
            
            kulevTask(n, m, option, array);
        break;
        
        case 5:
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    printf("Row %d, Column %d: %d\n", i+1, j+1, array[i][j]);
                }
            }
            printf("Elements shown successfully\n");
            
            printf("\nMenu:\n");
            printf("1 - Allocate dynamical memory for bidimensional array\n");
            printf("2 - Input array elements from keyboard\n");
            printf("3 - Input array with random values\n");
            printf("4 - Sort odd columns in descendence order via liniar selection\n");
            printf("5 - Ouput array elements of screen\n");
            printf("6 - Free memory allocated for array\n");
            printf("0 - Exit program\n\n");
            
            printf("Enter choice: ");
            scanf("%d", &option);
            
            kulevTask(n, m, option, array);
        break;
        
        case 6:
            free(array);
        break;
        
        default:
            printf("Invalid option");
    }

}

void findIndex(int* arr, int length) {
    int target;
    int index = -1;
    printf("Target value = ");
    scanf("%d", &target);
    
    for (int i = 0; i < length; i++) {
        if (*arr == target) {
            index = i;
            break;
        }
        arr++; // Move pointer the next element
    }
    
    if (index == -1) {
        printf("%d not found in the array.\n\n", target);
    } else {
        printf("The first occurrence of %d is at index %d.\n\n", target, index);
    }
}

void countTarget(int* arr, int length) {
    int target;
    int count = 0;
    printf("Target value = ");
    scanf("%d", &target);
    
    for (int i = 0; i < length; i++) {
        if (*arr == target) {
            count++;
        }
        arr++; // Move pointer the next element
    }
    
    printf("Value %d found %d times\n\n", target, count);
}


int main() {
    printf("Medium Tasks:\n\n");
    int k;
    printf("Length of 1D array = ");
    scanf("%d", &k);
    
    int* arr = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        printf("Element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    
    // Medium - implement a function that accepts the 1D integer array and returns the index of the first occurrence of a specific value(to be read from console when the function is called). Use pointers for the search
    findIndex(arr, k);
    
    // Medium - implement a function that receives the 1D array of integers and a target value. The function should count how many times the target value(to be read from console when the function is called) appears in the array using pointers
    countTarget(arr, k);
    
    printf("Kulev Task:\n\n");
    // Kulev task
    int n, m, option;
    printf("n = ");
    scanf("%d", &n);
    printf("m = ");
    scanf("%d", &m);
    int** array;
    
    printf("\nMenu:\n");
    printf("1 - Allocate dynamical memory for bidimensional array\n");
    printf("2 - Input array elements from keyboard\n");
    printf("3 - Input array with random values\n");
    printf("4 - Sort odd columns in descendence order via liniar selection\n");
    printf("5 - Ouput array elements of screen\n");
    printf("6 - Free memory allocated for array\n");
    printf("0 - Exit program\n\n");
    
    printf("Enter choice: ");
    scanf("%d", &option);
    
    kulevTask(n, m, option, array);
    
    return 0;
}
