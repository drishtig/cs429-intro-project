#include "hashmap.h"
#include <stdio.h>
#include <stdbool.h>

int main(int argc, char** argv){
	//while(true){
		struct IntToIntHashMap* h1 = createIntToIntHashMap(10);
		printf("initial hashtable\n\n");
		printHashTable(h1);
		printf("inserting some stuff\n");
		intToIntHashMapInsert(h1, 4, 4);
		intToIntHashMapInsert(h1, 9, 9);
		intToIntHashMapInsert(h1, 8, 8);
		intToIntHashMapInsert(h1, 11, 11);
		intToIntHashMapInsert(h1, 60, 60);
		printHashTable(h1);

		int key = 4;
		int value = intToIntHashMapGet(h1, key);
		if (value != 0){
			printf("Found here is the key value pair!: {%d, %d}\n", key, value);
		}
		else {
			printf("Not Found!");
		}
		printf("\n");
		printf("removing some stuff\n");
		key = 4;
		intToIntHashMapRemove(h1, key);
		printHashTable(h1);
		destroyIntToIntHashMap(h1);


		
		//TODO: fill this in
	//}
}
