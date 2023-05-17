#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_SIZE 100

void insert(int list[], int size, int num, int pos);
void delete(int list[], int size, int pos);
void display(int list[], int size);

int main() {
    int list[MAX_SIZE];
    int size = 0;
    int option = -1;

    while (option != 0) {
        printf("Menu:\n");
        printf("1. Insert a number\n");
        printf("2. Delete a number\n");
        printf("3. Display the list\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
        case 1:
        {
            int num, pos;
            printf("Enter the number to be inserted: ");
            scanf("%d", &num);
            printf("Enter the position to insert the number: ");
            scanf("%d", &pos);

            insert(list, size, num, pos);
            size++;
        }
        break;
        case 2:
        {
            int pos;
            printf("Enter the position to delete the number: ");
            scanf("%d", &pos);

            delete(list, size, pos);
            size--;
        }
        break;
        case 3:
            display(list, size);
            break;
        case 0:
            printf("Exiting the program...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }

        printf("\n");
    }

    return 0;
}

void insert(int list[], int size, int num, int pos) {
    int i;
    for (i = size; i > pos; i--) {
        list[i] = list[i - 1];
    }
    list[pos] = num;
    printf("Number of data movements: %d\n", size - pos);
}

void delete(int list[], int size, int pos) {
    int i;
    for (i = pos; i < size - 1; i++) {
        list[i] = list[i + 1];
    }
    printf("Number of data movements: %d\n", size - pos - 1);
}

void display(int list[], int size) {
    int i;
    if (size == 0) {
        printf("The list is empty.\n");
    }
    else {
        printf("List:\n");
        for (i = 0; i < size; i++) {
            printf("%d ", list[i]);
        }
        printf("\n");
    }
}
