#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Map Map;
typedef struct Key Key;
typedef struct Value Value;

struct Map
{
    Key **keys;
    Value **values;
    int size;
    int values_size;
    char *(*get)(Map *self, char *key);
    void (*add)(Map *self, char *key, char *value);
    void (*delete)(Map *self, char *key);
    void (*print_items)(Map *self);
};

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

Map *initialize_map();
void release_map(Map *map);
Key *initialize_key(char *key, int hash_code);
Value *initialize_value(char *value, int key_index);
int generate_hash_code(char *key);
Value **realloc_and_initialize(Value **values, int old_size, int new_size);
Value *get_value(Map *self, char *key);
char *get(Map *self, char *key);
void add(Map *self, char *key, char *value);
void delete(Map *self, char *key);
void print_items(Map *self);

int main()
{
    Map *map = initialize_map();

    map->add(map, "Reynold", "Morel");
    map->add(map, "Cristopher", "Luciano");
    map->add(map, "Luis", "Henriquez");
    map->add(map, "Rancell", "Tapia");

    printf("Printing map ...\n");
    map->print_items(map);

    printf("map->get(map, 'Reynold') = '%s'\n", map->get(map, "Reynold"));

    printf("Deleting 'Reynold' entry ...\n");
    map->delete(map, "Reynold");

    printf("Printing map after deleting 'Reynold' entry ...\n");
    map->print_items(map);

    printf("Update 'Cristopher's last name to be 'Almonte' ...\n");
    map->add(map, "Cristopher", "Almonte");

    printf("Printing map ...\n");
    map->print_items(map);

    release_map(map);

    return 0;
}

Map *initialize_map()
{
    Map *map = malloc(sizeof(Map));

    map->size = 0;
    map->values_size = 0;
    map->keys = malloc(sizeof(Key));
    map->values = malloc(sizeof(Value));

    map->add = &add;
    map->get = &get;
    map->delete = &delete;
    map->print_items = &print_items;

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
};

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

int generate_hash_code(char *key)
{
    int key_length = strlen(key);
    int hash_code_result = 0;

    for (int i = 0; i < key_length; i++)
    {
        char c = key[i];
        int ascii_code = (int)c;

        hash_code_result = hash_code_result + (ascii_code * i) + ascii_code;
    }

    return hash_code_result;
}

Value *get_value(Map *self, char *key)
{
    int hash_code = generate_hash_code(key);

    Value *value = hash_code > self->values_size - 1 ? NULL : self->values[hash_code];

    return value;
}

Value **realloc_and_initialize(Value **values, int old_size, int new_size)
{
    Value **new_values = realloc(values, sizeof(Value) * new_size);

    for (int i = old_size; i < new_size; i++)
    {
        new_values[i] = NULL;
    }

    return new_values;
}

char *get(Map *self, char *key)
{
    Value *value = get_value(self, key);

    return value == NULL ? NULL : value->value;
}

void add(Map *self, char *str_key, char *str_value)
{
    Value *existing_value = get_value(self, str_key);

    if (existing_value == NULL)
    {
        int hash_code = generate_hash_code(str_key);
        int new_size = self->size + 1;
        int new_index = new_size - 1;

        Key *key = initialize_key(str_key, hash_code);

        self->keys = realloc(self->keys, sizeof(Key) * new_size);
        self->keys[new_index] = key;
        self->size = new_size;

        Value *value = initialize_value(str_value, new_index);

        if (hash_code > self->values_size - 1)
        {
            int new_values_size = hash_code + 1;
            self->values = realloc_and_initialize(self->values, self->values_size, new_values_size);
            self->values[hash_code] = value;
            self->values_size = new_values_size;
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

void delete(Map *self, char *str_key)
{
    Value *existing_value = get_value(self, str_key);
    Key *key = self->keys[existing_value->key_index];

    for (int i = existing_value->key_index + 1; i < self->size; i++)
    {
        self->keys[i - 1] = self->keys[i];
    }

    self->values[existing_value->key_index] = NULL;
    free(existing_value);

    free(key);
    int new_size = self->size - 1;
    self->keys = realloc(self->keys, sizeof(Key) * new_size);
    self->size = new_size;
}

void print_items(Map *self)
{
    for (int i = 0; i < self->size; i++)
    {
        Key *key = self->keys[i];
        Value *value = self->values[key->hash_code];
        printf("{%s, %s, hash_code = %d},\n", key->key, value->value, key->hash_code);
    }

    printf("\n");
}

/*
    Hacer que el mapa de arriba soporte colisiones de keys cuando el hash es el mismo pero el key diferente.
    
    Hint:
    El time complexity en el get podría tornarse horriblemente O(n) en peor caso que todos los keys colisionen.
*/
