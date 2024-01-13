#include <stdio.h>
#include <stdlib.h>
#include "hashmap.h"
#include <string.h>
#define TABLE_SIZE 10

int intToIntHashFunction(int key){
	//TODO: fill this in
	//return key % 10;
	return 5;
}

struct IntToIntHashMap* createIntToIntHashMap(int numBuckets){
	struct IntToIntHashMap* h1 = malloc(sizeof(struct IntToIntHashMap));
	h1->tableSize = numBuckets;

	for (int i = 0; i < numBuckets; i++){
		h1->hash_table[i] = NULL;
	}
	return h1;
}

void printHashTable(struct IntToIntHashMap* hmap){
	for (int i = 0; i < hmap->tableSize; i++){
		if (hmap->hash_table[i] == NULL){
			printf("----");
			printf("\n");
		}
		else {
			struct IntToIntHashItem* head = hmap->hash_table[i];
			while (head->next != NULL){
				//printf("{%d, %d}", head->key, head->value);
				//printf(" ");
				head = head->next;
			}
			//printf("{%d, %d}", head->key, head->value);
			//printf("\n");
		}
	}
}

void intToIntHashMapInsert(struct IntToIntHashMap* hmap, int key, int value){
	struct IntToIntHashItem* item = malloc(sizeof(struct IntToIntHashItem));
	item->key = key;
	item->value = value;
	item->next = NULL;
	int hash = intToIntHashFunction(key);
	//printf("hash: %d\n", hash);
	if (hmap->hash_table[hash] == NULL){
		hmap->hash_table[hash] = item;
	}
	else {
		
		struct IntToIntHashItem* head = hmap->hash_table[hash];
		while (head->next != NULL){
			//printf("HERE\n");
			head = head->next;
		}
		head->next = item;
		//printf("item->value %d\n", item->value);
	}
	//TODO: fill this in
}

int intToIntHashMapGet(struct IntToIntHashMap* hmap, int key){
	int hash = intToIntHashFunction(key);
	
	if (hmap->hash_table[hash] != NULL){
		struct IntToIntHashItem* head = hmap->hash_table[hash];
		head = hmap->hash_table[hash];
		while (head->key != key && head->next != NULL){
			head = head->next;
		}
		if (head->key == key){
			return head->value;
		}
		else {
			return 0;
		}
	}
	//TODO: fill this in
	return 0;
}

void intToIntHashMapRemove(struct IntToIntHashMap* hmap, int key){
	int find = intToIntHashMapGet(hmap, key);
	if (find == 0){
		printf("Item does not exist.");
	}
	else {
		int hash = intToIntHashFunction(key);
		if (hmap->hash_table[hash] != NULL){
			struct IntToIntHashItem* head = hmap->hash_table[hash];
			struct IntToIntHashItem* prev = NULL;
			head = hmap->hash_table[hash];
			while (head->key != key && head->next != NULL){
				prev = head;
				head = head->next;
			}
			if (head->key == key){
				if (prev == NULL && head->next != NULL){
					hmap->hash_table[hash] = head->next;
					free(head);
				}
				else if(prev == NULL && head->next == NULL){
					hmap->hash_table[hash] = NULL;
				}
				else if (head->next != NULL){
					prev->next = head->next;
					free(head);
				}
				else {
					prev->next = NULL;
				}
				
			}
		}

	}
	//TODO: fill this in
}

void destroyIntToIntHashMap(struct IntToIntHashMap* hmap){
	
	for (int i = 0; i < hmap->tableSize; i++){
		struct IntToIntHashItem* head = hmap->hash_table[i];
		while (head != NULL){
			struct IntToIntHashItem* temp = head;
			head = head->next;
			free(temp);
			printf("here");
		}
		
	}
	//for (int i = 0; i < hmap->tableSize; i++){
	//	free(hmap->hash_table[i]);
	//}
	
	//TODO: fill this in
}

void destroyIntToIntHashItem(struct IntToIntHashItem* item){
	free(item);
	//TODO: fill this in
}


int strToIntHashFunction(char* key){
	//TODO: fill this in
	int length = strlen(key);
	int hash_value = 0;
	for (int i = 0; i < length; i++){
		hash_value += key[i];
		hash_value = (hash_value * key[i]) % 10;
	}
	return hash_value;
}

struct StrToIntHashMap* createStrToIntHashMap(int numBuckets){
	struct StrToIntHashMap* h1 = malloc(sizeof(struct StrToIntHashMap));
	h1->tableSize = numBuckets;

	for (int i = 0; i < numBuckets; i++){
		h1->hash_table[i] = NULL;
	}
	return h1;
}

void strToIntHashMapInsert(struct StrToIntHashMap* hmap, char* key, int value){
	//TODO: fill this in
	struct StrToIntHashItem* item = malloc(sizeof(struct StrToIntHashItem));
	item->key = key;
	item->value = value;
	item->next = NULL;
	int hash = strToIntHashFunction(key);
	//printf("hash: %d\n", hash);
	if (hmap->hash_table[hash] == NULL){
		hmap->hash_table[hash] = item;
	}
	else {
		
		struct StrToIntHashItem* head = hmap->hash_table[hash];
		while (head->next != NULL){
			//printf("HERE\n");
			head = head->next;
		}
		head->next = item;
		//printf("item->value %d\n", item->value);
	}
}

int strToIntHashMapGet(struct StrToIntHashMap* hmap, char* key){
	int hash = strToIntHashFunction(key);
	
	if (hmap->hash_table[hash] != NULL){
		struct StrToIntHashItem* head = hmap->hash_table[hash];
		head = hmap->hash_table[hash];
		while (head->key != key && head->next != NULL){
			head = head->next;
		}
		if (head->key == key){
			return head->value;
		}
		else {
			return 0;
		}
	}
	//TODO: fill this in
	return 0;
}

void strToIntHashMapRemove(struct StrToIntHashMap* hmap, char* key){
	int find = strToIntHashMapGet(hmap, key);
	if (find == 0){
		printf("Item does not exist.");
	}
	else {
		int hash = strToIntHashFunction(key);
		if (hmap->hash_table[hash] != NULL){
			struct StrToIntHashItem* head = hmap->hash_table[hash];
			struct StrToIntHashItem* prev = NULL;
			head = hmap->hash_table[hash];
			while (head->key != key && head->next != NULL){
				prev = head;
				head = head->next;
			}
			if (head->key == key){
				if (prev == NULL && head->next != NULL){
					hmap->hash_table[hash] = head->next;
					free(head);
				}
				else if(prev == NULL && head->next == NULL){
					hmap->hash_table[hash] = NULL;
				}
				else if (head->next != NULL){
					prev->next = head->next;
					free(head);
				}
				else {
					prev->next = NULL;
				}
				
			}
		}

	}
}

/*
void destroyStrToIntHashMap(struct StrToIntHashMap* hmap){
	//TODO: fill this in

	for (int i = 0; i < hmap->tableSize; i++){
		free(hmap->hash_table[i]);
	}
}
*/
void destroyStrToIntHashMap(struct StrToIntHashMap* hmap){
	
	for (int i = 0; i < hmap->tableSize; i++){
		struct StrToIntHashItem* head = hmap->hash_table[i];
		while (head != NULL){
			struct StrToIntHashItem* temp = head;
			head = head->next;
			free(temp);
		}
		
	}
	//for (int i = 0; i < hmap->tableSize; i++){
	//	free(hmap->hash_table[i]);
	//}
	
	//TODO: fill this in
}
void destroyStrToIntHashItem(struct StrToIntHashItem* item){
	free(item);
}

