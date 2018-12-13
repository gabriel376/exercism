#include "isogram.h"
#include <string.h>
#include <ctype.h>

#define END_OF_STRING '\0'
#define A 65
#define Z 90

bool is_equal(const char a, const char b) {
	return toupper(a) == toupper(b);
}

bool is_alphanumeric(const char a) {
	char b = toupper(a);
	return b >= A && b <= Z;
}

bool is_isogram(const char phrase[]) {
	if (strlen(phrase) == 0) {
		return true;
	}

	for (int i = 0; phrase[i] != END_OF_STRING; i++) {
		for (int j = i + 1; phrase[j] != END_OF_STRING; j++) {
			if (is_equal(phrase[i], phrase[j]) && is_alphanumeric(phrase[i])) {
				return false;
			}
		}
	}

	return true;
}
