#include <stdint.h>
#include <stdio.h>
#include "add-nbo.h"


int main(int argc, char *argv[]) {
	if (argc < 3) {
		printf("2개의 파일이 필요합니다.\n");
		return 1;
	}

	FILE* fp1, * fp2;
	uint32_t a, b, c, fs1, fs2;

	fp1 = fopen(argv[1], "rb");
	fp2 = fopen(argv[2], "rb");

	if (fp1 == NULL || fp2 == NULL){
		printf("파일을 여는 것에 실패했습니다.\n");
		return 1;
	}

	fseek(fp1, 0, SEEK_END);
	fs1 = ftell(fp1);
	fseek(fp1, 0, SEEK_SET);

	fseek(fp2, 0, SEEK_END);
	fs2 = ftell(fp2);
	fseek(fp2, 0, SEEK_SET);

	if (fs1 < 4 || fs2 < 4) {
		printf("파일의 크기가 4byte보다 작아서 읽을 수 없습니다.\n");
		return 1;
	}	

	fread(&a, 4, 1, fp1);
	fread(&b, 4, 1, fp2);

	a = ntohl(a);
	b = ntohl(b);

	c = a + b;

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", a, a, b, b, c, c);

	fclose(fp1);
	fclose(fp2);
}
