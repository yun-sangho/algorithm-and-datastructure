#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char value[11];
    struct node *next;
} node;

int hash(char value[]);
node* make_node(char value[]);
void insert(node* hash_table[], char value[]);
int search(node* hash_table[], char value[]);
int delete(node* hash_table[], char value[]);

int main(void)
{
    node* hash_table[10];

    for (int i = 0; i < 10; i++)
    {
        hash_table[i] = NULL;
    }

    insert(hash_table, "bolsal");
    insert(hash_table, "hiphop");
    insert(hash_table, "music");
    search(hash_table, "hiphop");
    search(hash_table, "bolsal");
    search(hash_table, "music");
    search(hash_table, "boy");
    delete(hash_table, "hiphop");
    delete(hash_table, "bolsal");
    delete(hash_table, "music");
    delete(hash_table, "boy");

}

// Use simple hash fuction return value from 0 to 9 by value's length
int hash(char value[])
{
    return strlen(value) % 10;
}

node* make_node(char value[])
{
    struct node *temp = malloc(sizeof(struct node));

    if (!temp)
    {
        fprintf(stderr, "Fail to set merroy of the lists\n");
    }

    strcpy(temp->value, value);
    temp->next = NULL;

    return temp;
}

void insert(node* hash_table[], char value[])
{
    int index = hash(value);

    node *temp = make_node(value);

    // If there isn't any value on the index
    if (hash_table[index] == NULL)
    {
        hash_table[index] = temp;
    }
     // If there was a value on the index already
    else
    {
        temp->next = hash_table[index];
        hash_table[index] = temp;
    }
}

int search(node* hash_table[], char value[])
{
    int index = hash(value);

    node *head = hash_table[index];

    while(head != NULL)
    {
        if (strcmp(head->value, value) == 0)
        {
            printf("The value `%s` was founded\n", value);
            return 1;
        }

        head = head->next;
    }

    printf("There isn't value `%s` on the table\n", value);
    return 0;
}

int delete(node* hash_table[], char value[])
{
    int index = hash(value);

    node *head = hash_table[index];

    // There isn't any node on index
    if (head == NULL)
    {
        printf("There isn't value `%s` on the table\n", value);
        return 0;
    }

    // If the value to delete is first node on index 
    if (strcmp(head->value, value) == 0)
    {
        // There is not a chained node with first node.
        if (head->next == NULL)
        {
            hash_table[index] = NULL;
            free(head);
        }
        // There is a chained node with first node.
        else 
        {
            node *temp = head->next;
            hash_table[index] = temp;
            free(head);
        }
        printf("The value `%s` was deleted\n", value);
        return 1;
    }

    // The value is after fisrt node 
    while (head->next != NULL)
    {
        node *next_node = head->next;
        if (strcmp(next_node->value, value) == 0)
        {
            // There is not a chained node with first node.
            if (next_node->next == NULL)
            {
                head->next = NULL;
                free(next_node);
            }
            // There is a chained node with first node.
            else 
            {
                node *temp = next_node->next;
                head->next = temp;
                free(next_node);
            }
            printf("The value `%s` was deleted\n", value);
            return 1;
        }

        head = next_node;
    }
    
    printf("There isn't value `%s` on the table\n", value);
    return 0;
}