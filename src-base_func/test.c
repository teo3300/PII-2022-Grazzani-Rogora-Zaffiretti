#include "constants.h"
#include "ascon.h"
#include "load_test.h"
#include "types.h"

#include <stdio.h>
#include <string.h>

#define printLenOf(type)\
	fprintf(stdout, "Size of type %s: %d\n", #type, sizeof(type));

#define printSizeOf(type)\
	fprintf(stdout, "Size of type %s: %d\n", #type, sizeof(type)*8);

void fprint_bstr(FILE *fp, u8 *label, u8 *data,
                 u64 length) {
    fprintf(fp, "%s", label);
    for (u64 i = 0; i < length; i++) fprintf(fp, "%02X", data[i]);
    fprintf(fp, "\n");
}

void init_buffer(volatile u8 *buffer, u64 numbytes) {
    for (u64 i = 0; i < numbytes; i++)
        buffer[i] = (u8)i;
}

int generate_test_vectors();

int main() {
    int ret = generate_test_vectors();
    if (ret != KAT_SUCCESS) {
        fprintf(stderr, "test vector generation failed with code %d\n", ret);
    }
    return ret;
}

int generate_test_vectors() {
	u8 key[CRYPTO_KEYBYTES];
	u8 nonce[CRYPTO_NPUBBYTES];
    u64 count, ret_val = KAT_SUCCESS;
    u64 c_state[5], h_state[5];

    init_buffer(key, CRYPTO_KEYBYTES); printLenOf(key);
    init_buffer(nonce, CRYPTO_NPUBBYTES); printLenOf(nonce);

	load_test_c(key, nonce, c_state);
	load_test_h(key, nonce, h_state);

	fprint_bstr(stderr, "CST = ", (u8*)c_state, sizeof(c_state));
	fprint_bstr(stderr, "HST = ", (u8*)h_state, sizeof(h_state));
	if(memcmp(c_state, h_state, sizeof(c_state))){
		fprintf(stdout,"Caccaculomerda\n");
		return 1;
	}
    fprintf(stdout,"No errors\n");
    return 0;
}
