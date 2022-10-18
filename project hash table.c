#include <stdio.h>
#include <string.h>
#include <singly linked string list.h>


int main() {
    int hash, choice;
    int mass[p];

    printf("Enter your choice:\n");
    printf("1 - add new element to the hash table\n");
    printf("2 - delete the element from the hash table\n");
    printf("3 - find the element at the hash table\n");
    printf("4 - change the element\n");
    printf("5 - exit the program\n");

    while(true){
        scanf("%d\n", &choice);
        if(choice < 1 || choice > 5) {
            printf("Wrong input. Enter your choice again\n");
            continue;
        }
        switch (choice) {
            case 1:
                printf("Enter new element: ");
                scanf("%s", &element);
                addElement(element);
            case 2:
                printf("Enter the element: ");
                scanf("%s", &element);
                deleteElement(element);
            case 3:
                printf("Enter the element: ");
                scanf("%s", &element);
                hash = hashFunction(element);
                int flag = findElement(element);
                if (flag) {
                    printf("The element is found. Its hash is %d.", hash);
                } else {
                    printf("There is no such element.");
                }
            case 4:
                printf("Enter old element: ");
                scanf("%s", &element);
                int flag = findElement(element);
                if (!flag) {
                    printf("There is no such element.");
                } else {
                    deleteElement(element);
                    printf("Enter new element: ");
                    scanf("%s", &element);
                    addElement(element);
                    printf("The element is changed.");
                }
            case 5:
                return 0;
        }
    }

    return 0;
}
