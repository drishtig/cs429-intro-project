#ifndef HASHMAP_H
#define HASHMAP_H
//hashtable item definition
typedef struct IntToIntHashItem
{
    int key;
    int value;
	struct IntToIntHashItem *next;
} IntToIntHashItem;


struct IntToIntHashMap{
	int tableSize;
	IntToIntHashItem* hash_table[10];
};

void printHashTable(struct IntToIntHashMap* hmap);

struct IntToIntHashMap* createIntToIntHashMap(int numBuckets);

void intToIntHashMapInsert(struct IntToIntHashMap* hmap, int key, int value);

int intToIntHashMapGet(struct IntToIntHashMap* hmap, int key);

void intToIntHashMapRemove(struct IntToIntHashMap* hmap, int key);

void destroyIntToIntHashMap(struct IntToIntHashMap* hmap);

void destroyIntToIntHashItem(struct IntToIntHashItem* item);

typedef struct StrToIntHashItem
{
    char* key;
	int value;
	struct StrToIntHashItem *next;
} StrToIntHashItem;

struct StrToIntHashMap{
	int tableSize;
	StrToIntHashItem* hash_table[10];
	
};

struct StrToIntHashMap* createStrToIntHashMap(int numBuckets);

void strToIntHashMapInsert(struct StrToIntHashMap* hmap, char* key, int value);

int strToIntHashMapGet(struct StrToIntHashMap* hmap, char* key);

void strToIntHashMapRemove(struct StrToIntHashMap* hmap, char* key);

void destroyStrToIntHashMap(struct StrToIntHashMap* hmap);

void destroyStrToIntHashItem(struct StrToIntHashItem* item);

#endif // HASHMAP_H
