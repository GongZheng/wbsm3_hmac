/*
The header file of white-box SM3 HMAC function
*/
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define SM3_DIGEST_LENGTH	32
#define SM3_BLOCK_SIZE		64
#define SM3_CBLOCK		(SM3_BLOCK_SIZE)
#define SM3_HMAC_SIZE		(SM3_DIGEST_LENGTH)

typedef struct {
	uint32_t digest[8];
	uint64_t nblocks;
	unsigned char block[64];
	int num;
} sm3_ctx_t;

void sm3_init(sm3_ctx_t *ctx);
void sm3_update(sm3_ctx_t *ctx, const unsigned char* data, size_t data_len);
void sm3_final(sm3_ctx_t *ctx, unsigned char digest[SM3_DIGEST_LENGTH]);
void sm3_compress(uint32_t digest[8], const unsigned char block[SM3_BLOCK_SIZE]);
void sm3(const unsigned char *data, size_t datalen,
	unsigned char digest[SM3_DIGEST_LENGTH]);

typedef struct {
	sm3_ctx_t sm3_ctx;
	wbsm3_hmac_key_ctx_t wbsm3_hmac_key_ctx;
} sm3_hmac_ctx_t;

typedef struct {

} wbsm3_hmac_key_ctx_t;



void sm3_hmac_init(sm3_hmac_ctx_t *ctx, wbsm3_hmac_key_ctx_t *wbkey_ctx, size_t key_len);
void sm3_hmac_update(sm3_hmac_ctx_t *ctx, const unsigned char *data, size_t data_len);
void sm3_hmac_final(sm3_hmac_ctx_t *ctx, unsigned char mac[SM3_HMAC_SIZE]);
void sm3_hmac(const unsigned char *data, size_t data_len,
	wbsm3_hmac_key_ctx_t *wbkey_ctx, size_t key_len, unsigned char mac[SM3_HMAC_SIZE]);