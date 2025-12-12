#include <stdio.h>
#include <stdlib.h>

int upperBound(int arr[], int n, int target) {
    int left = 0, right = n;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] <= target)
            left = mid + 1;
        else
            right = mid;
    }

    return left;
}

int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n-1;

    while (left < right) {
        int mid = (left + right) / 2; 
        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    int n;
    scanf("%d", &n);
    int* arr = (int *) malloc(n * sizeof(int));

    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    int target;
    scanf("%d", &target);

    int result = binarySearch(arr, n, target);

    if(result == -1) {
        printf("%s", "Not found");
    }
    else {
        printf("%s %d", "Found at:", result);
    }

    return 0;
}