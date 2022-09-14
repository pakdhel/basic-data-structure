#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct SinglyLinkedList SinglyLinkedList;
typedef struct SinglyLinkedListNode SinglyLinkedListNode;

struct SinglyLinkedList {
    SinglyLinkedListNode* head;
    SinglyLinkedListNode* tail;
};

struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
};

SinglyLinkedListNode* node(int data) {
    SinglyLinkedListNode* newNode = malloc(sizeof(SinglyLinkedListNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void create_singly_list(SinglyLinkedList** singly_list, int data) {
    SinglyLinkedListNode* newNode = node(data);
    if (!(*singly_list)->head) {(*singly_list)->head = newNode;}
    else {
        (*singly_list)->tail->next = newNode;
    }

    (*singly_list)->tail = newNode;
}

// print the fill of list
void print_list(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

// comparing list function
bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* temp1 = head1;
    SinglyLinkedListNode* temp2 = head2;
    bool found = false;
    while ((temp1 != NULL && temp2 != NULL) && !found) {
        if (temp1->data != temp2->data) {
            found = true;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
        if ((temp1 == NULL && temp2 != NULL) || (temp1 != NULL && temp2 == NULL)) {
            found = true;
        }
    }
    return !found;
}

// delete Node function
SinglyLinkedListNode* deleteNode(SinglyLinkedListNode *head, int position) {
    SinglyLinkedListNode* temp2 = NULL;
    SinglyLinkedListNode* temp1 = head;

    int i = 0;

    while (i < position) {
        temp2 = temp1;
        temp1 = temp1->next;
        i++;
    }
    temp2->next = temp1->next;
    
    free(temp1);
    return head;
}

// get Node function
int getNode(SinglyLinkedListNode* llist, int positionFromTail) {
    SinglyLinkedListNode* temp = llist;
    int i = 0, j = 0;
    while (temp != NULL) {
        temp = temp->next;
        i++;
    }
    temp = llist;
    while (j < (i - positionFromTail - 1)) {
        temp = temp->next;
        j++;
    }
    return temp->data;
}

// insert a node at tail of list function
SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    SinglyLinkedListNode* newNode = malloc(sizeof(SinglyLinkedListNode));
    SinglyLinkedListNode* temp = head;
    newNode->data = data;
    newNode->next = NULL;
    if(head == NULL) {
        head = newNode;
    } else {
        temp->next = newNode;
    }
    temp = newNode;
    return head;
}

// insert a node at head of list function
SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data) {
    
    SinglyLinkedListNode* newNode = malloc(sizeof(SinglyLinkedListNode));
    newNode->data = data;
    newNode->next = llist;
    llist = newNode;
    return llist;
}

// merge two lists function
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    
    SinglyLinkedListNode* temp1 = head1;
    SinglyLinkedListNode* temp2 = head2;

    SinglyLinkedListNode* temp3;
    SinglyLinkedListNode* newNode = NULL;

    if (temp1 && temp2) {
        if (temp1->data < temp2->data) {
            temp3 = temp1;
            temp1 = temp3->next;
        } else {
            temp3 = temp2;
            temp2 = temp3->next;
        }
    }

    newNode = temp3;

    while (temp1 != NULL && temp2 != NULL) {

        if (temp1->data < temp2->data) {
            temp3->next = temp1;
            temp3 = temp1;
            temp1 = temp1->next;
        } else {
            temp3->next = temp2;
            temp3 = temp2;
            temp2 = temp1->next;
        }

    }
    
    return newNode;
}

int main(int argc, char const *argv[])
{
    SinglyLinkedList* llist1 = malloc (sizeof(SinglyLinkedList));
    SinglyLinkedList* llist2 = malloc (sizeof(SinglyLinkedList));
    llist1->head = NULL;
    llist2->head = NULL;

    int data;
    
    // adding some data to first linked list
    for (int i = 0; i < 4; i++) {
        printf("data : "); scanf("%d", &data);
        create_singly_list(&llist1, data);
    }

    // print the data 
    printf("\n");
    print_list(llist1->head);


    // adding some data to second linked list
    for (int i = 0; i < 4; i++) {
        printf("data : "); scanf("%d", &data);
        create_singly_list(&llist2, data);
    }

    // print the data 
    printf("\n");
    print_list(llist2->head);

    // comparing first and second linked list
    if (compare_lists(llist1->head, llist2->head)) printf("Equal\n");
    else printf("Not equal\n");
    return 0;
}
