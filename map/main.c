#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Key Key;
typedef struct Value Value;
typedef struct Pair Pair;
typedef struct Map Map;

struct Key
{
    char *key;
    int hashcode;
    int index;
};

struct Value
{
    char *value;
};

struct Pair
{
    Key *key;
    Value *value;
};

struct Map
{
    Pair **pairs;
    int *hashcodes;
    int pairs_size;
    int hashcodes_size;
    char *(*get)(Map *self, char *key);
    void (*put)(Map *self, char *key, char *value);
    void (*delete)(Map *self, char *key);
    void (*print_pairs)(Map *self);
};

Map *initialize_map();
void release_map(Map *map);
void release_pair(Pair *pair);
void put(Map *self, char *key, char *value);
char *get(Map *self, char *key);
void delete (Map *self, char *key);
void print_pairs(Map *self);

int hash(char *val);

int main(int argc, char **argv)
{
    Map *map = initialize_map();

    printf("\n-------- Adding 5 items -------");

    map->put(map, "edwins", "samuel");
    map->put(map, "juan", "pablo");
    map->put(map, "reynold", "bernardo");
    map->put(map, "mario", "luigi");
    map->put(map, "bowser", "peach");
    map->print_pairs(map);

    printf("\n-------- Getting an item -------\n");

    printf("%s", map->get(map, "mario"));

    printf("\n-------- Deleting an item -------");

    map->delete (map, "mario");
    map->print_pairs(map);

    printf("\n-------- Verifying Mario was deleted -------\n");

    printf("%s", map->get(map, "mario"));

    release_map(map);
    return 0;
}

Map *initialize_map()
{
    Map *map = malloc(sizeof(Map));

    map->pairs_size = 0;
    map->hashcodes_size = 0;

    map->put = &put;
    map->get = &get;
    map->delete = &delete;
    map->print_pairs = &print_pairs;

    return map;
}

void release_map(Map *map)
{
    for (int i = 0; i < map->hashcodes_size; i++)
    {
        int hashcode = map->hashcodes[i];
        Pair *pair = map->pairs[hashcode];
        release_pair(pair);
    }
}

void release_pair(Pair *pair)
{
    free(pair->key);
    free(pair->value);
    free(pair);
}

// Space Complexity: O(1)
// Time Complexity: O(n)
int hash(char *val)
{
    int result = 0;
    int val_length = strlen(val);

    for (int i = 0; i < val_length; i++)
    {
        result += (int)val[i];
    }

    result *= val_length;

    return result;
}

// Space Complexity: O(n)
// Time Complexity: O(1)
void put(Map *self, char *key, char *value)
{
    int hashcode = hash(key);

    Key *key_struc = malloc(sizeof(Key));
    key_struc->key = key;
    key_struc->hashcode = hashcode;

    Value *value_struc = malloc(sizeof(Value));
    value_struc->value = value;

    Pair *pair = malloc(sizeof(Pair));
    pair->key = key_struc;
    pair->value = value_struc;

    int new_hashcodes_size = self->hashcodes_size + 1;
    int new_pairs_size = hashcode + 1;

    if (new_pairs_size > self->pairs_size || self->pairs[hashcode] == NULL)
    {
        if (self->hashcodes_size == 0)
        {
            self->hashcodes = malloc(new_hashcodes_size * (sizeof(int)));
        }
        else
        {
            self->hashcodes = realloc(self->hashcodes, new_hashcodes_size * (sizeof(int)));
        }

        int hashcode_index = new_hashcodes_size - 1;

        key_struc->index = hashcode_index;
        self->hashcodes[hashcode_index] = hashcode;
        self->hashcodes_size = new_hashcodes_size;
    }
    else
    {
        Pair *pair = self->pairs[hashcode];
        release_pair(pair);
    }

    if (new_pairs_size > self->pairs_size)
    {
        if (self->pairs_size == 0)
        {
            self->pairs = malloc(new_pairs_size * (sizeof(Pair)));
        }
        else
        {
            self->pairs = realloc(self->pairs, new_pairs_size * (sizeof(Pair)));
        }

        for (int i = self->pairs_size; i < new_pairs_size; i++)
        {
            self->pairs[i] = NULL;
        }

        self->pairs_size = new_pairs_size;
    }

    self->pairs[hashcode] = pair;
}

// Space Complexity: O(1)
// Time Complexity: O(1)
char *get(Map *self, char *key)
{
    int hashcode = hash(key);

    if (self->pairs[hashcode] != NULL)
    {
        return self->pairs[hashcode]->value->value;
    }

    return NULL;
}

// Space Complexity: O(1)
// Time Complexity: O(n)
void delete (Map *self, char *key)
{
    int hashcode = hash(key);

    Pair *pair = self->pairs[hashcode];
    int index = pair->key->index;

    int new_hashcodes_size = self->hashcodes_size - 1;

    for (int i = index + 1; i < self->hashcodes_size; i++)
    {
        self->hashcodes[i - 1] = self->hashcodes[i];
    }

    free(&self->hashcodes[new_hashcodes_size]);
    self->hashcodes = realloc(self->hashcodes, new_hashcodes_size * (sizeof(int)));

    self->hashcodes_size = new_hashcodes_size;

    release_pair(pair);
    self->pairs[hashcode] = NULL;
}

void print_pairs(Map *self)
{
    printf("\n-------- Pair Items -------\n");
    printf("[");

    for (int i = 0; i < self->hashcodes_size; i++)
    {
        int hashcode = self->hashcodes[i];
        Pair *pair = self->pairs[hashcode];
        printf("{%s, %s}, ", pair->key->key, pair->value->value);
    }

    printf("]");
}