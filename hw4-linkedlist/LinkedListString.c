#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedListString.h"

/* Function to push a node */
void push(struct node **head_ref, char *new_data) {
    /* allocate node */
    struct node *new_node = malloc(sizeof(struct node));

    /* put in the data  */

    strcpy(new_node->data, new_data);


    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

/* Function to print linked list */
void printList(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%s  ", temp->data);
        temp = temp->next;
    }
}

/* Function to count the number of elements in the linked list */
int listCount(struct node *head) {
    struct node *temp = head;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

/* Function to reverse the linked list */
void reverseList(struct node **init_head, struct node **true_head) {
    struct node *curr = *init_head;
    struct node *next = curr->next;
    if (next != NULL) { //recursive check, stops at the end of the list
        reverseList(&next, true_head);
        next->next = curr;
    } else {
        (*true_head)->next = NULL; //set old head.next to NULL
        *true_head = curr; //set new head
    }

}

/*Function to delete all elements in a Linked List */
void listAllDelete(struct node **currP) {
    struct node *a = *currP; //node that progresses through list
    struct node *b = a; //prev node that sets each nodes next value to null
    while (a != NULL) { //End loop once a == null
        a = a->next;
        free(b);
        b = a; //when a becomes null, so does b at this step
    }
    *currP = NULL; //set head node to NULL
}

/*Function to delete a particular element or elements in a linked list*/
void deleteElement(struct node **currP, char *value) {
    struct node *head = *currP; //temp head
    struct node *curr = *currP;

    while (curr->next != NULL) {
        if (strcmp(head->data, value)==0) { //If the head is a node that needs to be removed
            *currP = head->next; //move actual list head forward
            free(head); //to free memory of removed node
            head = *currP;
        } else if (strcmp(curr->next->data, value)==0) { //if value of next nodes data is what we want to remove
            struct node *temp = curr->next;
            curr->next = curr->next->next; //skip over node
            free(temp); //To free the memory of removed node
        }
        curr = curr->next;
    }
}
