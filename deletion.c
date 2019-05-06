#include "stdlib.h"
#include "stdio.h"

struct node {
    int info;
    struct node *link;
};

struct node *createList(struct node *start);
struct node *insertInBeginning(struct node *start, int info);
struct node *insertAtEnd(struct node *start, int info);
void showList(struct node *start);
struct node *deleteNode(struct node *start, int info);

int main(){
    int choice, info;

    struct node *start = (struct node *)malloc(sizeof(struct node));
    start = NULL;

    start = createList(start);

    while(1){
        printf("Please select a choice by enter a number\n");
        printf("1. delete a node based on data\n");
        printf("2. insert a node at the end of list\n");
        printf("3. show the list\n");
        printf("4. quit\n");
        scanf("%d", &choice);

        if(choice == 4){
            break;
        }
        
        switch(choice){
            case 1: printf("Please enter the data that you would like to delete\n");
                    scanf("%d", &info);
                    start = deleteNode(start, info);
                    break;

            case 2: printf("Enter the data that you would like to insert at the end of the list\n");
                    scanf("%d", &info);
                    start = insertAtEnd(start, info);
                    break;
            case 3: showList(start);
                    break;
        }
        
    }

    return 0;
}

struct node *createList(struct node *start){
    int n, info;
    printf("Please enter the number of nodes the number of nodes that you would like to insert\n");
    scanf("%d", &n);

    printf("Please enter the data to be inserted into node 1:\n");
    scanf("%d", &info);
    start = insertInBeginning(start, info);

    for(int i = 1; i < n; i++){
        printf("Please enter the data to be inserted into node %d:\n", i + 1);
        scanf("%d", &info);
        start = insertAtEnd(start, info);
    }

    return start;
}

struct node *insertInBeginning(struct node *start, int info){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->info = info;
    temp->link = NULL;
    start = temp;
    return start;
}

struct node *insertAtEnd(struct node *start, int info){
    struct node *temp, *p;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = info;

    p = start;
    while(p->link != NULL){
        p = p->link;
    }

    temp->link = p->link;
    p->link = temp;
    return start;
}

void showList(struct node *start){
    struct node *p;
    p = start;
    while(p != NULL){
        printf("%d | ", p->info);
        p = p->link;
    }
    printf("\n");
} 

struct node *deleteNode(struct node *start, int info){
    struct node *temp, *p;
    //gaurd against an empty list
    if(start == NULL){
        printf("list is empty");
        return start;
    }

    if(start->info == info){
        temp = start;
        start = start->link;
        free(temp);
        return start;
    }

    p = start;
    while(p->link != NULL){
        if(p->link->info == info){
            break;
        }
        p = p->link;
    }
    
    if(p->link == NULL){
        printf("Element %d not found in the list", info);
    }
    else{
        temp = p->link;
        p->link = temp->link;
        free(temp);
    }

    return start;
}

