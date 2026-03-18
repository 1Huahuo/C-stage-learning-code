#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

/*

*/

int main(void) {
	Vector* vec = vector_create();
	for (int i = 0; i < 10; i++)
		vector_push_back(vec, i);
	vector_print(vec);

	return 0;
}