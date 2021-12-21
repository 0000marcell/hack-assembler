#include <stdio.h>
#include <string.h>

typedef struct 
{
    char *key; //or char name[100];
    int value;
} item;

static void insert(item *p, char *key, int value)
{
    p->key = key;
    p->value = value;
}

char *keys[7]= {"Simon", "Suzie", "Alfred", "Chip", "John", "Tim",
          "Harriet"};
int values[7]= {22, 24, 106, 6, 18, 32, 24};

int main()
{
    item items[100] = { {"marcell", 30}, { "joao", 27}};
    for (int i = 2; i < 7; i++)
    {
        insert(&items[i], keys[i], values[i]);
    }

    for (int i = 0; i < 7; i++)
    {
        printf("name: %s, age: %i\n", items[i].key, items[i].value);
    }
}
 
