#include <stdio.h>

void insertElement(int arr[], int *size, int element, int position) {
    if (position < 0 || position > *size) {
        printf("Invalid position\n");
        return;
    }
    
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    
    arr[position] = element;
    (*size)++;
    printf("Element inserted\n");
}

void deleteElement(int arr[], int *size, int position) {
    if (position < 0 || position >= *size) {
        printf("Invalid position\n");
        return;
    }
    
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    (*size)--;
    printf("Element deleted\n");
}

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

void traverseArray(int arr[], int size) {
    printf("Array Elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter size n: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int option;
    while (1) {
        printf("**MENU**\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Linear Search\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        int element, position, target, index;
        switch (option) {
            case 1:
                printf("Element to insert: ");
                scanf("%d", &element);
                printf("Enter Position: ");
                scanf("%d", &position);
                insertElement(arr, &n, element, position);
                break;
            case 2:
                printf("Position to delete: ");
                scanf("%d", &position);
                deleteElement(arr, &n, position);
                break;
            case 3:
                printf("Element to search: ");
                scanf("%d", &target);
                index = linearSearch(arr, n, target);
                if (index != -1) {
                    printf("Element %d found at position %d\n", target, index);
                } else {
                    printf("Element not found\n");
                }
                break;
            case 4:
                traverseArray(arr, n);
                break;
            case 5:
                printf("Exiting the program\n");
                return 0;
            default:
                printf("Invalid option\n");
        }
    }

    return 0;
}
