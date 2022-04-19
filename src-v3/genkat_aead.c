//
// NIST-developed software is provided by NIST as a public service.
// You may use, copy and distribute copies of the software in any medium,
// provided that you keep intact this entire notice. You may improve,
// modify and create derivative works of the software or any portion of
// the software, and you may copy and distribute such modifications or
// works. Modified works should carry a notice stating that you changed
// the software and should note the date and nature of any such change.
// Please explicitly acknowledge the National Institute of Standards and
// Technology as the source of the software.
//
// NIST-developed software is expressly provided "AS IS." NIST MAKES NO
// WARRANTY OF ANY KIND, EXPRESS, IMPLIED, IN FACT OR ARISING BY OPERATION
// OF LAW, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTY OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, NON-INFRINGEMENT AND DATA
// ACCURACY. NIST NEITHER REPRESENTS NOR WARRANTS THAT THE OPERATION OF THE
// SOFTWARE WILL BE UNINTERRUPTED OR ERROR-FREE, OR THAT ANY DEFECTS WILL BE
// CORRECTED. NIST DOES NOT WARRANT OR MAKE ANY REPRESENTATIONS REGARDING THE
// USE OF THE SOFTWARE OR THE RESULTS THEREOF, INCLUDING BUT NOT LIMITED TO THE
// CORRECTNESS, ACCURACY, RELIABILITY, OR USEFULNESS OF THE SOFTWARE.
//
// You are solely responsible for determining the appropriateness of using and
// distributing the software and you assume all risks associated with its use,
// including but not limited to the risks and costs of program errors,
// compliance with applicable laws, damage to or loss of data, programs or
// equipment, and the unavailability or interruption of operation. This software
// is not intended to be used in any situation where a failure could cause risk
// of injury or damage to property. The software developed by NIST employees is
// not subject to copyright protection within the United States.
//

// disable deprecation for sprintf and fopen
#include "ascon.h"
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <string.h>

#define STATE 2
#define DECRYPT 1
#define FULL 10
#define ENCRYPT 3

#define CHECK ENCRYPT

#include "api.h"
#include "crypto_aead.h"

#define KAT_SUCCESS 0
#define KAT_FILE_OPEN_ERROR -1
#define KAT_DATA_ERROR -3
#define KAT_CRYPTO_FAILURE -4

#define MAX_FILE_NAME 256

void init_buffer(u8 *buffer, u64 numbytes);

void fprint_bstr(FILE *fp, const char *label, const u8 *data,
                 u64 length);

int generate_test_vectors();

int main() {
    s32 ret = generate_test_vectors();
    if (ret != KAT_SUCCESS) {
        fprintf(stderr, "test vector generation failed with code %d\n", ret);
    }
    return ret;
}

int generate_test_vectors() {
    FILE *fp;
    char fileName[MAX_FILE_NAME];
    u8 key[CRYPTO_KEYBYTES];
    u8 nonce[CRYPTO_NPUBBYTES];
    u8 msg[MAX_MESSAGE_LENGTH];
    u8 cmsg2[MAX_MESSAGE_LENGTH];
    u8 hmsg2[MAX_MESSAGE_LENGTH];
    u8 ad[MAX_ASSOCIATED_DATA_LENGTH];
    u8 cct[MAX_MESSAGE_LENGTH + CRYPTO_ABYTES];
    u8 hct[MAX_MESSAGE_LENGTH + CRYPTO_ABYTES];
    u64 cclen, hclen, cmlen2, hmlen2;
    s32 count = 1;
    s32 func_ret, ret_val = KAT_SUCCESS;
    u64 c_state[5], h_state[5];

    init_buffer(key, sizeof(key));
    init_buffer(nonce, sizeof(nonce));
    init_buffer(msg, sizeof(msg));
    init_buffer(ad, sizeof(ad));
    init_buffer((u8*) c_state, sizeof(state_t));
    init_buffer((u8*) h_state, sizeof(state_t));

    sprintf(fileName, "LWC_AEAD_KAT_%d_%d.txt", (CRYPTO_KEYBYTES * 8),
            (CRYPTO_NPUBBYTES * 8));
    if ((fp = fopen(fileName, "w")) == NULL) {
        fprintf(stderr, "Couldn't open <%s> for write\n", fileName);
        return KAT_FILE_OPEN_ERROR;
    }

    for (u64 mlen = 0;
       (mlen <= MAX_MESSAGE_LENGTH) && (ret_val == KAT_SUCCESS); mlen++) {
        for (u64 adlen = 0; adlen <= MAX_ASSOCIATED_DATA_LENGTH;
            adlen++) {
            fprintf(fp, "Count = %d\n", count++);
            fprint_bstr(fp, "Key = ", key, CRYPTO_KEYBYTES);
            fprint_bstr(fp, "Nonce = ", nonce, CRYPTO_NPUBBYTES);
            fprint_bstr(fp, "PT = ", msg, mlen);
            fprint_bstr(fp, "AD = ", ad, adlen);

            crypto_aead_encrypt_c(cct, &cclen, msg, mlen, ad, adlen, NULL, nonce, key/*, c_state*/);
            fprint_bstr(fp, "CT = ", cct, cclen);

            #if CHECK == STATE
                crypto_aead_encrypt_h(hct, &hclen, msg, mlen, ad, adlen, NULL, nonce, key, h_state);
                if(memcmp(c_state, h_state, sizeof(state_t))){
                    fprintf(stdout, "STATE ERROR: in cycle %d:\n", count);
    				fprint_bstr(stdout, "CST = ", c_state, sizeof(c_state));
    				fprint_bstr(stdout, "HST = ", h_state, sizeof(h_state));
                    ret_val = KAT_CRYPTO_FAILURE;
                }else{
                	fprintf(stdout, "cycle %d: state check OK\n", count);
                }
            #endif
            #if CHECK==ENCRYPT
            crypto_aead_encrypt_h(hct, &hclen, msg, mlen, ad, adlen, NULL, nonce, key/*, h_state*/);
                if(memcmp(cct, hct, sizeof(cct))){
                    fprintf(stdout, "ENCRYPT ERROR: in cycle %d:\n", count);
    				fprint_bstr(stdout, "cct = ", cct, sizeof(cct));
    				fprint_bstr(stdout, "hct = ", hct, sizeof(hct));
                    ret_val = KAT_CRYPTO_FAILURE;
                }else{
                	fprintf(stdout, "cycle %d: state check OK\n", count);
                }
            #endif
            if ((func_ret = crypto_aead_decrypt_c(cmsg2, &cmlen2, NULL, cct, cclen, ad,
                                                adlen, nonce, key/*, h_state*/)) != 0) {
                fprintf(fp, "C crypto_aead_decrypt_c returned <%d>\n", func_ret);
                fprintf(stdout, "C DECRYPT ERROR: in cycle %d:\n", count);
                ret_val = KAT_CRYPTO_FAILURE;
                break;
            }else{
              	fprintf(stdout, "C cycle %d: decrypt check OK\n", count);
            }
            #if CHECK == DECRYPT
                if ((func_ret = crypto_aead_decrypt_h(hmsg2, &hmlen2, NULL, cct, cclen, ad,
                                                    adlen, nonce, key, h_state)) != 0) {
                    fprintf(fp, "H crypto_aead_decrypt_h returned <%d>\n", func_ret);
                    fprintf(stdout, "H DECRYPT ERROR: in cycle %d:\n", count);
                    ret_val = KAT_CRYPTO_FAILURE;
                    break;
                }else{
                	fprintf(stdout, "H cycle %d: decrypt check OK\n", count);
                }
                if(cmlen2 != hmlen2) {
                    fprintf(stdout, "H ERROR BAD LEN: in cycle %d\n",conut);
                    ret_val = KAT_CRYPTO_FAILURE;
                    break;
                }
                if(memcmp(cmsg2, hmsg2, cmlen2)){
                    fprintf(stdout, "H ERROR: BAD HLS DECRYPT: in cycle %d\n", count);
                    ret_val = KAT_CRYPTO_FAILURE;
                    break;
                }
            #endif

            #if CHECK <= FULL
                if (mlen != cmlen2) {
                    fprintf(fp,
                            "crypto_aead_decrypt returned bad 'mlen': Got <%llu>, expected <%llu>\n",
                            (u64)cmlen2, (u64)mlen);
                    fprintf(stdout, "MSG OUTPUT ERROR (length): in cycle %d:\n", count);
                    ret_val = KAT_CRYPTO_FAILURE;
                    break;
                }
                if (memcmp(msg, cmsg2, mlen)) {
                    fprintf(fp, "crypto_aead_decrypt did not recover the plaintext\n");
                    fprintf(stdout, "MSG OUTPUT ERROR (content): in cycle %d:\n", count);
                    ret_val = KAT_CRYPTO_FAILURE;
                    break;
                }else{
                	fprintf(stdout, "cycle %d: msg output check OK\n", count);
                }
            #endif
            fprintf(fp, "\n");
        }
    }
    fclose(fp);
    return ret_val;
}

void fprint_bstr(FILE *fp, const char *label, const u8 *data,
                 u64 length) {
    fprintf(fp, "%s", label);
    for (u64 i = 0; i < length; i++) fprintf(fp, "%02X", data[i]);
    fprintf(fp, "\n");
}

void init_buffer(u8 *buffer, u64 numbytes) {
    for (u64 i = 0; i < numbytes; i++)
        buffer[i] = (u8)i;
}
