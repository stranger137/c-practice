#include <stdio.h>
#include <string.h>
#include <singly linked string list.h>

const int k = 53;
const int p = 7;

int hashFunction(char s[]) {
    int n = strlen(s);
    int i, curNum;
    int ans = 0;
    int curPower = 1;
    char c;
    for(i = 0; i < n; i++) {
        c = s[i];
        curNum = (int)(c - "a" + 1);
        curPower = (curPower * k) % p;
        ans = (ans + curNum * curPower) % p;
    }
    return ans;
}

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
                hash = hashFunction(element);
                addElement(mass[hash], element);
            case 2:
                printf("Enter the element: ");
                scanf("%s", &element);
                hash = hashFunction(element);
                deleteElement(element);
            case 3:
                printf("Enter the element: ");
                scanf("%s", &element);
                hash = hashFunction(element);
                int flag = findElement(mass[hash], element);
                if (flag) {
                    printf("The element is found. Its hash is %d.", hash);
                } else {
                    printf("There is no such element.");
                }
            case 4:
                printf("Enter old element: ");
                scanf("%s", &element);
                hash = hashFunction(element);
                int flag = findElement(mass[hash], element);
                if (!flag) {
                    printf("There is no such element.");
                } else {
                    deleteElement(mass[hash], element);
                    printf("Enter new element: ");
                    scanf("%s", &element);
                    hash = hashFunction(element);
                    addElement(mass[hash], element);
                    printf("The element is changed.");
                }
            case 5:
                return 0;
        }
    }

    return 0;
}
