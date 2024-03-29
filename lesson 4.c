#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *value;
    struct node *next;
} node;

node *head = NULL;

void showAll() {
	node *cur = head;
	if (cur == NULL) {
		puts("List is empty. \n");
		return;
	}
	else {
		puts("Elements are: \n");
		while (cur != NULL) {
			printf("%s\n", cur->value);
			cur = cur->next;
		}
	}
}

void addElement() {
    char* value = (char*)malloc(sizeof(char)*50);
    puts("Enter the element: ");
    scanf("%s", value);

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
        cur->next = newNode;
    }
    return;
}

void deleteLast() {
    if (head == NULL) {
        puts("List is empty.");
        return;
    }
    else if (head->next == NULL) {
        printf("%d is deleted", head->value);
        free(head);
        head = NULL;
        return;
    }
    else {
        node *cur, *nextCur = NULL;
        cur = head;
        while (cur->next != NULL) {
            nextCur = cur;
            cur = cur->next;
        }
        nextCur->next = NULL;
        free(cur);
    }
    return;
}


void deleteList() {
    if (head == NULL) {
        puts("List is empty.");
        return;
    }
    node *cur = head;
    if (head->next == NULL) {
        free(cur);
        head = NULL;
        return;
    }

    node *nextCur;
    while (cur->next->next != NULL) {
		nextCur = cur->next;
		free(cur);
		cur = nextCur;
	}
	free(cur->next);
	head = NULL;
	return;
}

void findElement() {
    char value[50];
    puts("Enter the element: ");
    scanf("%s", value);
    if (head ==  NULL){
        puts("List is empty. \n");
        return;
    }
    node *cur;
    cur = head;
    int i = 1;
    while (strcmp(cur->value, value) != 0) {
        if (cur->next == NULL) {
            puts("There is no such element. \n");
            return;
        }
        i++;
        cur = cur->next;
    }
    printf("This is the element on position %d  \n", i);
}

void createList() {
    addElement();
    return;
}


int main() {
	int input;
	while (1) {
		puts("1 - create linked list");
		puts("2 - add element to the end of the list");
		puts("3 - delete the last element of the list");
		puts("4 - print the list");
		puts("5 - delete the list");
		puts("6 - find the position of the element");
		puts("7 - exit\n");
		scanf("%d", &input);
		if ((input < 1) || (input > 7)) {
            puts("Wrong input.\n");
		};
		switch (input) {
		case 1:
			createList();
			puts("\n");
			continue;
		case 2:
			addElement();
			puts("\n");
			continue;
		case 3:
			deleteLast();
			puts("\n");
			continue;
		case 4:
			showAll();
			puts("\n");
			continue;
		case 5:
			deleteList();
			puts("\n");
			continue;
		case 6:
			findElement();
			puts("\n");
			continue;
		case 7:
			return;
		}
	}
	return 0;
}
