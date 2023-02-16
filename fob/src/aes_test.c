#include "aes_test.h"


/**
 * @brief Function that encrypt a string with AES encryption
 *
 * @param in pointer to the beginning of a string
 */
void encrypt(uint8_t *in)
{
    struct AES_ctx ctx;
    AES_init_ctx_iv(&ctx, secret_key, secret_iv);
    AES_CBC_encrypt_buffer(&ctx, in, 64);
    
}


/**
 * @brief Function that decrypt a string with AES encryption
 *
 * @param in pointer to the beginning of an encrypted string
 */
void decrypt(uint8_t *in)
{
    struct AES_ctx ctx;
    AES_init_ctx_iv(&ctx, secret_key, secret_iv);
    AES_CBC_decrypt_buffer(&ctx, in, 64);
    
}