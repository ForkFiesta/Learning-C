#include <stdio.h>



int binary_search(int arr[], int arraySize, int target){
    int low =0;
    int high = arraySize-1;

    while (low <= high){
        int mid = low + (high-low) / 2;

        if (arr[mid] == target){
            return mid;
        }

        if (arr[mid] < target){
            low = mid + 1;
        }

        else {
            high = mid -1;
        }
    }
    return -1;
}

int binary_search_recursive(int arr[], int low, int high, int target) {
    if (low > high) {
        return -1; // Target not found
    }

    int mid = low + (high - low) / 2;

    // Check if target is present at mid
    if (arr[mid] == target) {
        return mid; // Target found
    }

    // If target is greater, recur in the right half
    if (arr[mid] < target) {
        return binary_search_recursive(arr, mid + 1, high, target);
    }
    // If target is smaller, recur in the left half
    else {
        return binary_search_recursive(arr, low, mid - 1, target);
    }
}


int main(void){

    int arr[] = {2, 3, 4, 10, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    int iterative_result = binary_search(arr, size, target);

    if (iterative_result != -1) {
        printf("Iterative: Element found at index %d\n", iterative_result);
    } else {
        printf("Iterative: Element not found\n");
    }

    int recursive_result = binary_search_recursive(arr, 0, size - 1, target);
    if (recursive_result != -1) {
        printf("Recursive: Element found at index %d\n", recursive_result);
    } else {
        printf("Recursive: Element not found\n");
    }



    return 0;

}