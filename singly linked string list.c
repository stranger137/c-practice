#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


typedef struct node {
    char *value;
    struct node *next;
} node;


void addElement(char *value) {
    hash = hashFunction(element);
    node *head = mass[hash];

    node *newNode, *cur;
    newNode = (node*)malloc(sizeof(node));
    newNode->value = value;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    }
    else {
        cur = head;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
    }
    printf("The element is added.");
    return;
}

void deleteElement(char *value) {
    hash = hashFunction(element);
    node *head = mass[hash];

    if (head == NULL) {
        printf("There is no such element.");
        return;
    } else if (head->value == element) {
        free(head);
        return;
    } else {
        node *cur, *prevCur = NULL;
        cur = head;
        while (cur->next != NULL && cur->value != value) {
            prevCur = cur;
            cur = cur->next;
        }
        if(cur->value == value) {
            prevCur->next = cur->next;
            free(cur);
            printf("The element is deleted.");
        } else {
            printf("There is no such element.");
        }
    }
    return;
}


int findElement(char *value) {
    hash = hashFunction(element);
    node *head = mass[hash];

    if (head ==  NULL){
        return 0;
    }
    node *cur;
    cur = head;
    while (strcmp(cur->value, value) != 0) {
        if (cur->next == NULL) {
            return 0;
        }
        cur = cur->next;
    }
    return 1;
}
