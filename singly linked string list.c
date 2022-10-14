#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node {
    char *value;
    struct node *next;
} node;


void addElement(node *head, char *value) {
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

void deleteElement(node *head, char *value) {
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


int findElement(node *head, char *value) {
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
