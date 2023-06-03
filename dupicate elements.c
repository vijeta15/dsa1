#include <stdio.h>

void findDuplicates(int arr[], int size) {
    int i, j;
    int count;

    printf("Duplicate elements:\n");

    for (i = 0; i < size; i++) {
        count = 1;
        for (j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }

        if (count > 1 && arr[i] != -1) {
            printf("%d occurs %d times\n", arr[i], count);
        }
    }
}
void countDigits(int arr[], int size) {
    int i, j;
    int count[10] = {0};

    printf("Digit count:\n");

    for (i = 0; i < size; i++) {
        int num = arr[i];

        while (num != 0) {
            int digit = num % 10;
            count[digit]++;
            num /= 10;
        }
    }

    for (i = 0; i < 10; i++) {
        if (count[i] > 0) {
            printf("Digit %d occurs %d times\n", i, count[i]);
        }
    }
}

int main() {
    int arr[20];
    int i;

    printf("Enter elements:\n");

    for (i = 0; i < 20; i++) {
        scanf("%d", &arr[i]);

    }


    findDuplicates(arr, 20);
    countDigits(arr, 20);

    return 0;
}
