#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Key
{
	char *val;
	int index;
} Key;

typedef struct Pair
{
	Key *key;
	char *value;
} Pair;

typedef struct Map
{
	int itemsSize;
	int size;
	Pair **items;
	Key **keys;
	char *(*get)(struct Map *self, char *key);
	void (*put)(struct Map *self, char *key, char *value);
	void (*delete)(struct Map *self, char *key);
	void (*print_pairs)(struct Map *self);
} Map;

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

int find_key_index(Map *self, int hash_code)
{
	for (int i = 0; i < self->size; i++)
	{
		Key *key = self->keys[i];

		if (key->index == hash_code)
		{
			return i;
		}
	}

	return -1;
}

// Time Complexity = O(1)
char *get(Map *self, char *key)
{
	int hash_code = hash(key);
	return self->items[hash_code]->value;
}

// Time Complexity = O(1)
void put(Map *self, char *key, char *value)
{
	int hash_code = hash(key);

	Key *k = malloc(sizeof(Key));
	k->val = key;
	k->index = hash_code;

	self->size++;

	if (self->size == 1)
	{
		self->keys = malloc(self->size * sizeof(Key));
	}
	else
	{
		self->keys = realloc(self->keys, self->size * sizeof(Key));
	}

	self->keys[self->size - 1] = k;

	if (hash_code > self->itemsSize - 1)
	{
		if (self->itemsSize == 0)
		{
			self->items = malloc(hash_code * sizeof(Pair));
		}
		else
		{
			self->items = realloc(self->items, hash_code * sizeof(Pair));
		}

		self->itemsSize = hash_code;
	}

	Pair *pair = malloc(sizeof(Pair));
	pair->key = k;
	pair->value = value;

	self->items[hash_code] = pair;
}

void delete_key(Map *self, int index)
{
	for (int i = index + 1; i < self->size - 1; i++)
	{
		self->keys[i - 1] = self->keys[i];
	}

	self->size--;
	Key **tmp = malloc(self->size * sizeof(Key *));
	memcpy(tmp, self->keys, self->size * sizeof(Key *));

	free(self->keys);

	self->keys = tmp;
}

// Time Complexity = O(n)
void delete (Map *self, char *key)
{
	int hash_code = hash(key);
	int key_index_to_delete = find_key_index(self, hash_code);

	delete_key(self, key_index_to_delete);

	free(self->items[hash_code]->key);
	free(self->items[hash_code]);

	self->items[hash_code] = NULL;
}

void print_pairs(Map *self)
{
	printf("key-values = [\n");
	for (int i = 0; i < self->size - 1; i++)
	{
		Key *key = self->keys[i];
		Pair *pair = self->items[key->index];

		printf("{ key = %s, value = %s },\n", key->val, pair->value);
	}

	Key *key = self->keys[self->size - 1];
	Pair *pair = self->items[key->index];
	printf("{ key = %s, value = %s }\n]\n\n", key->val, pair->value);
}

Map *map;

Map *initialize_map()
{
	Map *map = malloc(sizeof(Map));

	map->size = 0;
	map->itemsSize = 0;

	map->get = get;
	map->put = put;
	map->delete = delete;
	map->print_pairs = print_pairs;

	return map;
}

void *release_map(Map *map)
{
	for (int i = map->size - 1; i >= 0; i--)
	{
		Key *key = map->keys[i];

		map->delete (map, key->val);
	}

	free(map);
}

int main(int argc, char *argv[])
{
	map = initialize_map();

	map->put(map, "Reynold", "Morel");
	map->put(map, "Kelvin", "Reyes");
	map->put(map, "Diana", "Monegro");

	map->print_pairs(map);

	char *last_name = map->get(map, "Kelvin");
	printf("The last name of Kelvin is %s \n\n", last_name);

	printf("Deleting Diana from the map \n\n");
	map->delete (map, "Diana");
	map->print_pairs(map);

	release_map(map);

	return 0;
}