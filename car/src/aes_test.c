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


static uint32_t lcg_seed = 0;

void srand(uint32_t seed) {
  lcg_seed = seed;
}

uint32_t rand(void) {
  lcg_seed = (lcg_seed * 1103515245 + 12345) % 4294967296;
  return lcg_seed;
}

void generate_challenge(uint8_t *challenge, uint32_t timer_count) {
  // Use timer counter to generate random seed
  uint32_t seed = timer_count;

  // Seed random number generator with timer counter value
  srand(seed);

  // Generate 64 random bytes to use as the challenge
  for (int i = 0; i < 64; i++) {
    challenge[i] = (uint8_t)rand();
  }
}