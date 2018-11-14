#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
/*
 * Linked list
 * 2 -> 4 -> 10 -> 8 -> 5 -> 6 -> null
 */

void printList(struct node *n);
struct node* create(int data);
void push(struct node **head, int data);
void insert_after(struct node* prev_node, int data);
void append(struct node **head, int data);
void delete_node(struct node **head, int key);
void pop(struct node **head);

int main(void)
{
    struct node *head = create(1);

    push(&head, 10);

    append(&head, 100);

    insert_after(head->next, 50);

    delete_node(&head, 50);

    pop(&head);

    printList(head);

    return 0;
}

void printList(struct node *n)
{
    while (n != NULL)
    {
        printf("%d\n", n->data);
        n = n->next;
    }
}

struct node* create(int data)
{
    struct node *node = malloc(sizeof(struct node));

    if (!node)
    {
        fprintf(stderr, "Fail to set merroy of the lists\n");
    }

    node->data = data;
    node->next = NULL;

    return node;
}

// Push new node infront of head node
void push(struct node **head, int data)
{
    // 1. allocate new node
    struct node *new_node = malloc(sizeof(struct node));
    if (!new_node)
    {
        fprintf(stderr, "Fail to allocate merroy to node");
    }

    // 2. put data in the new node
    new_node->data = data;

    // 3. set the next pointer of new node to first node
    new_node->next = *head;

    // 4. set pointer to first node to new node
    *head = new_node;
}

void insert_after(struct node* prev_node, int data)
{
    // 1. check if the previous node is null or not
    if (!prev_node)
    {
        fprintf(stderr, "The previous node cannot be NULL");
    }

    // 2. allocate new node
    struct node* new_node = malloc(sizeof(struct node));
    if (!new_node)
    {
        fprintf(stderr, "Fail to allocate merroy to node");
    }

    // 3. set new data to new node and pointer to next node
    new_node->data = data;
    new_node->next = prev_node->next;

    // 4. set the next pointer of previous node to new node
    prev_node->next = new_node;
}

void append(struct node **head, int data)
{
    // 1. allocate new node and set new data to node
    struct node *new_node = malloc(sizeof(struct node));
    if (!new_node)
    {
        fprintf(stderr, "Fail to allocate merroy to node");
    }
    new_node->data = data;
    new_node->next = NULL;

    // 2. from first node traverse till the last node
    struct node *last_node = *head;
    while (last_node->next != NULL)
    {
        last_node = last_node->next;
    }

    // 3. set the next pointer of the last node to new node
    last_node->next = new_node;
}

void delete_node(struct node **head, int key)
{
    struct node *temp = *head;

    // If first node has the key
    if (temp->data == key)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    // Otherwise

    struct node *pre = malloc(sizeof(struct node));

    if (!pre)
    {
        fprintf(stderr, "Fail to allocate merroy to node");
    }

    while (temp->data != key)
    {
        if (!temp)
        {
            free(temp);
            fprintf(stderr, "There is not a node that has the data");
            return;
        }

        pre = temp;
        temp = temp->next;
    }

    pre->next = temp->next;

    free(temp);
    return;
}

// Delete last node of linked list
void pop(struct node **head)
{
    struct node *temp = *head;
    struct node *prev = malloc(sizeof(struct node));

    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
    return;
}