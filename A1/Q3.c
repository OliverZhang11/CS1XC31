int main() {
    int i;
    int arr[] = {1, 2, 2, 2, 3, 3, 4, 2, 4, 5, 6, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: ");
    for (i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    removeDups(arr, size);
    printf("Modified array: ");
    for (i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
