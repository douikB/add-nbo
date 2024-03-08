#include <stdint.h>
#include <stdio.h>
#include "add-nbo.h"


int main(int argc, char *argv[]) {
	FILE* fp1, * fp2;
	uint32_t a, b, c;

	fp1 = fopen(argv[1], "rb");
	fp2 = fopen(argv[2], "rb");

	fread(&a, 4, 1, fp1);
	fread(&b, 4, 1, fp2);

	a = ntohl(a);
	b = ntohl(b);

	c = a + b;

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", a, a, b, b, c, c);

	fclose(fp1);
	fclose(fp2);
}
