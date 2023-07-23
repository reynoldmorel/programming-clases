#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Map Map;
typedef struct Key Key;
typedef struct Value Value;

struct Key
{
    char *key;
    int hash_code;
};

struct Value
{
    char *value;
    int key_index;
};

struct Map
{
    Key **keys;
    Value **values;
    int size;
    int values_size;
    Value *(*get)(Map *self, char *key);
    void (*put)(Map *self, char *key, char *value);
    void (*delete)(Map *self, char *key);
    void (*print_items)(Map *self);
};

int generate_hash_code(char *value);

Map *initialize_map();
void release_map(Map *map);
Key *initialize_key(char *str_key, int hash_code);
Value *initialize_value(char *str_value, int key_index);
Value **realloc_and_initialize(Value **values, int old_size, int size);

void put(Map *self, char *key, char *value);
Value *get(Map *self, char *key);
void print_items(Map *self);
void delete(Map *self, char *key);

int main()
{

    printf("\nThe key is 'juan' and the hash_code is: %d", generate_hash_code("juan"));
    printf("\nThe key is 'alberto' and the hash_code is: %d", generate_hash_code("alberto"));
    printf("\nThe key is 'como' and the hash_code is: %d", generate_hash_code("como"));
    printf("\nThe key is 'pedro' and the hash_code is: %d", generate_hash_code("pedro"));

    Map *map = initialize_map();

    map->put(map, "alberto", "pasteles");
    map->put(map, "juan", "klk");
    map->put(map, "pedro", "hola");
    map->put(map, "como", "adios");
    map->put(map, "jose", "cuidate");

    map->print_items(map);

    map->put(map, "pedro", "repetido");

    map->print_items(map);

    Value *value = map->get(map, "pedro");
    printf("\n\nGetting pedro's value: %s", value->value);

    map->delete (map, "pedro");

    map->print_items(map);

    release_map(map);

    return 0;
}

int generate_hash_code(char *value)
{
    int valueLength = strlen(value);
    int asciiResult = 0;

    for (int i = 0; i < valueLength; i++)
    {
        char c = value[i];
        int ascii_code = (int)c;

        asciiResult = asciiResult + (ascii_code * i) + ascii_code;
    }

    return asciiResult / (2 * valueLength);
}

Map *initialize_map()
{
    Map *map = malloc(sizeof(Map));

    map->size = 0;
    map->values_size = 0;
    map->keys = malloc(sizeof(Key));
    map->values = malloc(sizeof(Value));

    map->put = &put;
    map->get = &get;
    map->print_items = &print_items;
    map->delete = &delete;

    return map;
}

void release_map(Map *map)
{
    for (int i = 0; i < map->size; i++)
    {
        Key *key = map->keys[i];
        Value *value = map->values[key->hash_code];

        free(key);
        free(value);
    }

    free(map->keys);
    free(map->values);
    free(map);
}

Key *initialize_key(char *str_key, int hash_code)
{
    Key *key = malloc(sizeof(Key));
    key->key = str_key;
    key->hash_code = hash_code;

    return key;
}

Value *initialize_value(char *str_value, int key_index)
{
    Value *value = malloc(sizeof(Value));
    value->value = str_value;
    value->key_index = key_index;

    return value;
}

Value **realloc_and_initialize(Value **values, int old_size, int size)
{
    Value **new_values = realloc(values, size * sizeof(Value));

    // Setting default NULL values to new buckets
    for (int i = old_size; i < size; i++)
    {
        new_values[i] = NULL;
    }

    return new_values;
}

// O(1) = time complexity;
void put(Map *self, char *str_key, char *str_value)
{
    Value *existing_value = self->get(self, str_key);

    if (existing_value == NULL)
    {
        int hash_code = generate_hash_code(str_key);
        int new_size = self->size + 1;

        // Create key
        Key *key = initialize_key(str_key, hash_code);

        // Add Key to keys array
        self->keys = realloc(self->keys, new_size * sizeof(Key));
        self->keys[new_size - 1] = key;
        self->size = new_size;

        // Create value
        Value *value = initialize_value(str_value, new_size - 1);

        // Verify if the hash_code fits in the values array
        // if not then we need to reallocate memory,
        // so that the value can be stored in a bucket.
        if (hash_code > self->values_size - 1)
        {
            self->values = realloc_and_initialize(self->values, self->values_size, hash_code + 1);
            self->values[hash_code] = value;
            self->values_size = hash_code + 1;
        }
        else
        {
            self->values[hash_code] = value;
        }
    }
    else
    {
        existing_value->value = str_value;
    }
}

// O(1) = time complexity
Value *get(Map *self, char *str_key)
{
    int hash_code = generate_hash_code(str_key);

    return hash_code > self->values_size - 1 ? NULL : self->values[hash_code];
}

// O(n) = time complexity
void delete(Map *self, char *str_key)
{
    Value *value = self->get(self, str_key);
    Key *key = self->keys[value->key_index];

    for (int i = value->key_index + 1; i < self->size; i++)
    {
        self->keys[i - 1] = self->keys[i];
    }

    free(value);
    self->values[key->hash_code] = NULL;

    free(key);
    self->keys = realloc(self->keys, (self->size - 1) * sizeof(Key));
    self->size = self->size - 1;
}

// // O(n) = time complexity
void print_items(Map *self)
{
    printf("\n ----- MAP -------\n");
    for (int i = 0; i < self->size; i++)
    {
        Key *key = self->keys[i];
        Value *value = self->values[key->hash_code];

        printf("\npair (%s, %s)", key->key, value->value);
    }
}

// Implement the map using either the List / Linked List data structure.
// Implement the map that does not use a hash code and instead generates a sequence or any kind of UID.
