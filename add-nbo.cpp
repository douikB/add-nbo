#include <stdint.h>

uint32_t ntohl(uint32_t a) {
	uint32_t b = (a & 0x000000ff) << 24;
	uint32_t c = (a & 0x0000ff00) << 8;
	uint32_t d = (a & 0x00ff0000) >> 8;
	uint32_t e = (a & 0xff000000) >> 24;
	return b | c | d | e;
}
