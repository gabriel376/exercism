#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define END_OF_STRING '\0'
#define MAX_ARRAY 100

void add_letter(char *acronym, const char *letter) {
	int len = strlen(acronym);
	char *buffer = realloc(acronym, (len + 2) * sizeof(char));
	
	if (buffer == NULL) {
		printf("Error allocating memory\n");
		free(acronym);
		exit(1);
	}

	acronym = buffer;
	acronym[len] = toupper(*letter);
	acronym[len + 1] = END_OF_STRING;
}

char *abbreviate(const char *phrase) {
	char *acronym = malloc(0);
	int add = 1;

	if (phrase == NULL || phrase[0] == END_OF_STRING) {
		return NULL;
	}

	for (int i = 0; phrase[i] != END_OF_STRING; i++) {
		if (add) {
			add = 0;
			add_letter(acronym, &phrase[i]);
		}

		if (phrase[i] == ' '|| phrase[i] == '-') {
			add = 1;
		}
	}

	return acronym;
}
