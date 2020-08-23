#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LENGTH 1000

int split_word_count = 0;

typedef struct Key
{
	char *val;
	int hash;
} Key;

typedef struct Value
{
	int count;
} Value;

typedef struct Map
{
	Value **values;
	Key **keys;
	int valuesSize;
	int size;
	int (*get)(struct Map *self, char *key);
	int (*containsKey)(struct Map *self, char *key);
	void (*put)(struct Map *self, char *key, int value);
	void (*print_key_values)(struct Map *self);
	void (*sort_keys)(struct Map *self);
} Map;

void local_memset_values_to_null(Value **values, int from, int end)
{
	for (int i = from; i < end; i++)
	{
		values[i] = NULL;
	}
}

char **split_words(char *text)
{
	char **result = malloc(MAX_TEXT_LENGTH * sizeof(char *));
	int result_index = 0;

	result[result_index] = malloc(MAX_TEXT_LENGTH * sizeof(char));

	int text_length = strlen(text);
	int last_word_index = 0;
	int text_index = 0;

	for (; text_index < text_length; text_index++)
	{
		char c = text[text_index];

		if (c == ' ')
		{
			split_word_count++;
			result[result_index][text_index - last_word_index] = '\0';
			result_index++;
			last_word_index = text_index + 1;
			result[result_index] = malloc(MAX_TEXT_LENGTH * sizeof(char));
		}
		else
		{
			result[result_index][text_index - last_word_index] = c;
		}
	}

	split_word_count++;
	result[result_index][text_index - last_word_index] = '\0';

	return result;
}

char *filter_characters(char *text)
{
	int text_length = strlen(text);
	char *result = malloc(text_length * sizeof(char));
	int result_index = 0;

	for (int text_index = 0; text_index < text_length; text_index++)
	{
		char c = text[text_index];

		if (c == ' ' || (c >= 97 && c <= 122))
		{
			result[result_index++] = c;
		}
	}

	result[result_index] = '\0';

	return result;
}

int hash(char *key)
{
	int result = 0;
	int key_length = strlen(key);

	for (int i = 0; i < key_length; i++)
	{
		result += key[i];

		if (i > 0)
		{
			result += key[0] / key_length;
		}
	}

	result *= key_length;

	return result;
}

int containsKey(Map *self, char *key)
{
	int hash_code = hash(key);
	return self->size != 0 && self->valuesSize >= hash_code && self->values[hash_code] != NULL;
}

int get(Map *self, char *key)
{
	int hash_code = hash(key);
	return self->values[hash_code]->count;
}

void put(Map *self, char *key, int value)
{
	int hash_code = hash(key);

	if (containsKey(self, key))
	{
		self->values[hash_code]->count = value;
		return;
	}

	Key *k = malloc(sizeof(Key));
	k->val = key;
	k->hash = hash_code;

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

	if (hash_code > self->valuesSize)
	{
		int size = hash_code + 1;

		if (self->valuesSize == 0)
		{
			self->values = malloc(size * sizeof(Value *));
			local_memset_values_to_null(self->values, 0, size);
		}
		else
		{
			self->values = realloc(self->values, size * sizeof(Value *));
			local_memset_values_to_null(self->values, self->valuesSize, size);
		}

		self->valuesSize = size;
	}

	Value *v = malloc(sizeof(Value));
	v->count = value;

	self->values[hash_code] = v;
}

void print_key_values(Map *self)
{
	printf("key-values = [\n");
	for (int i = 0; i < self->size - 1; i++)
	{
		Key *key = self->keys[i];
		Value *value = self->values[key->hash];

		printf("{ key = %s, value = %d },\n", key->val, value->count);
	}

	Key *key = self->keys[self->size - 1];
	Value *value = self->values[key->hash];
	printf("{ key = %s, value = %d }\n]\n\n", key->val, value->count);
}

void swap(Key *a, Key *b)
{
	Key tmp = *a;
	*a = *b;
	*b = tmp;
}

int partion(Map *map, Key **keys, int low, int high)
{
	Key *pivot = keys[high];
	int i = low - 1;

	for (int j = low; j < high; j++)
	{
		if (map->get(map, keys[j]->val) > map->get(map, pivot->val))
		{
			i++;
			swap(keys[i], keys[j]);
		}
	}

	swap(keys[i + 1], keys[high]);

	return i + 1;
}

void quick_sort(Map *self, Key **keys, int low, int high)
{
	if (low < high)
	{
		int pi = partion(self, self->keys, low, high);

		quick_sort(self, keys, low, pi - 1);
		quick_sort(self, keys, pi + 1, high);
	}
}

void sort_keys(Map *self)
{
	quick_sort(self, self->keys, 0, self->size - 1);
}

Map *words_count_map;

Map *initialize_map()
{
	Map *map = malloc(sizeof(Map));

	map->size = 0;
	map->valuesSize = 0;

	map->get = get;
	map->put = put;
	map->print_key_values = print_key_values;
	map->containsKey = containsKey;
	map->sort_keys = sort_keys;

	return map;
}

int main(int argc, char *argv[])
{
	char *text = "in the beginning god created the heaven and the earth and the earth was without form and void and darkness was upon the face of the deep and the spirit of god moved upon the face of the waters and god said let there be light and there was light and god saw the light that it was good and god divided the light from the darkness and god called the light day and the darkness he called night and the evening and the morning were the first day";
	char *filtered_text = filter_characters(text);
	char **words = split_words(filtered_text);

	words_count_map = initialize_map();

	for (int i = 0; i < split_word_count; i++)
	{
		char *word = words[i];

		if (words_count_map->containsKey(words_count_map, word))
		{
			int count = words_count_map->get(words_count_map, word);
			count++;
			words_count_map->put(words_count_map, word, count);
		}
		else
		{
			words_count_map->put(words_count_map, word, 1);
		}
	}

	words_count_map->sort_keys(words_count_map);
	words_count_map->print_key_values(words_count_map);

	return 0;
}