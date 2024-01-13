#include "hashmap.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* tokens [3]; 
void splitStringBySpace(char* input) {
    char* token = strtok(input, " ");
	int i = 0;
	//char* tokens [3];  
    while (token != NULL) {
		tokens[i] = token;
		i++;
		token = strtok(NULL, " ");
		
    }
}

int main(int argc, char** argv){
	struct IntToIntHashMap* h1 = createIntToIntHashMap(10);
	while (true){

		char command[20];
		int number1;
		int number2;

		printf("Get <Key> or Put <Key> <Value>. Examples include \"Get 9\" or \"Put 8 10\". If you want to exit, enter EXIT: \n");
		scanf("%s", command);
		if (strcmp(command, "Get") == 0){
			scanf("%d", &number1); 
			int value = intToIntHashMapGet(h1, number1);
			if (value != 0){
				printf("Found here is the key value pair!: {%d, %d}\n", number1, value);
			}
			else {
				fprintf(stderr, "The following key is not found in the hashmap!: %d\n", number1);
			}

		}
		else if (strcmp(command, "Put") == 0){
			scanf("%d%d", &number1, &number2); 
			intToIntHashMapInsert(h1, number1, number2);
			
		}
		else {
			return 0;
		}
	}





	}
	/*
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
	*/

