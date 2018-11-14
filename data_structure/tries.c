#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ALPHABET_SIZE (26)

typedef struct trie_node
{
    struct trie_node *children[ALPHABET_SIZE];
    bool is_end_of_word;

} trie_node;

trie_node* get_node(void);
void insert_node(trie_node *root_node, char value[]);
void search_node(trie_node *root_node, char value[]);
int char_to_index(char c);

int main(void)
{
    trie_node *root_node = get_node();

    insert_node(root_node, "bolsal");
    insert_node(root_node, "hiphop");
    insert_node(root_node, "music");
    search_node(root_node, "hiphop");
    search_node(root_node, "bolsal");
    search_node(root_node, "music");
    search_node(root_node, "boy");
}

trie_node* get_node(void)
{
    trie_node *temp_node = malloc(sizeof(struct trie_node));

    if (temp_node)
    {
        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            temp_node->children[i] = NULL;
        }

        temp_node->is_end_of_word = false;
    }

    return temp_node;
}

void insert_node(trie_node *root_node, char value[])
{
    int len = strlen(value);
    int level = 0;
    int index;

    trie_node *current_node = root_node;

    for (level = 0; level < len; level++)
    {
        index = char_to_index(value[level]);

        if (!current_node->children[index])
        {
            current_node->children[index] = get_node();
        }

        current_node = current_node->children[index];
    }

    current_node->is_end_of_word = true;
}

void search_node(trie_node *root_node, char value[])
{
    int len = strlen(value);
    int level = 0;
    int index;

    trie_node *current_node = root_node;

    for (level = 0; level < len; level++)
    {
        index = char_to_index(value[level]);

        if (!current_node->children[index])
        {
            printf("The value `%s` is not on the tries.\n", value);
            return;
        }

        current_node= current_node->children[index];
    }

    if (current_node != NULL && current_node->is_end_of_word)
    {
        printf("The value `%s` was founded.\n", value);
        return;
    }

    printf("The value `%s` is not on the tries.\n", value);
    return;

}

int char_to_index(char c)
{
    if(c >= 97 && c <= 122){
       c -= 97;
   }
   else if(c >= 65 && c <= 90){
       c = c - 65 + 32;
   }
   else
       return -1;
   return c;
}