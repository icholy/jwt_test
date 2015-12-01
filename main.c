#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "hmac_sha2.h"
#include "base64.h"

#define HS256_HMAC_LEN 32

int main() {

  const char *jwt_text = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJzdWIiOiIxMjM0NTY3ODkwIiwibmFtZSI6IkpvaG4gRG9lIiwiYWRtaW4iOnRydWV9.TJVA95OrM7E2cBab30RMHrHDcEfxjoYZgeFONFh7HgQ";

  const char *last_dot = strrchr(jwt_text, '.');
  if (!last_dot) {
    return 1;
  }
  size_t singing_input_len = last_dot - jwt_text;
  const char *jwt_signature = last_dot + 1;

  printf("Signing Input: %.*s\n", (int)singing_input_len, jwt_text);

  // destination
  char digest[HS256_HMAC_LEN];

  const char *key = "secret";

  hmac_sha256(
      key,      (unsigned int) strlen(key),
      jwt_text, (unsigned int) singing_input_len,
      digest,   HS256_HMAC_LEN
  );

  size_t encoded_len = base64_encode_len(HS256_HMAC_LEN);
  char *encoded = malloc(sizeof(char) * encoded_len);
  if (!encoded) {
    return 1;
  }

  base64_encode(encoded, digest, HS256_HMAC_LEN);

  printf("Signature: %s\n", jwt_signature);
  printf("Digest:    %.*s\n", (int)encoded_len, encoded);

  return 0;
}
