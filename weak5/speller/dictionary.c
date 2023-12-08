// Implements a dictionary's functionality
#include "dictionary.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
// should test another1000
const unsigned int N = 50;

// Hash table
node *table[N];

int dic_siz = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int hashh_value = hash(word);
    node *n = table[hashh_value];

    while (n != NULL)
    {
        if (strcasecmp(word, n->word) == 0)
        {
            return true;
        }
        n = n->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    long gamm = 0;
    for (int c = 0; c < strlen(word); c += 1)
    {
        gamm += tolower(word[c]);
    }
    return gamm % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *dic_poi = fopen(dictionary, "r");
    if (dictionary == NULL)
    {
        printf("Unable to open %s\n", dictionary);
        return false;
    }
    char nex_wor[LENGTH + 1];
    while (fscanf(dic_poi, "%s", nex_wor) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        strcpy(n->word, nex_wor);
        int hash_value = hash(nex_wor);

        n->next = table[hash_value];
        table[hash_value] = n;
        dic_siz += 1;
    }
    fclose(dic_poi);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{

    return dic_siz;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int g = 0; g < N; g += 1)
    {
        node *n = table[g];
        while (n != NULL)
        {
            node *temp = n;
            n = n->next;
            free(temp);
        }
        if (n == NULL && g == N - 1)
        {
            return true;
        }
    }
    return false;
}
