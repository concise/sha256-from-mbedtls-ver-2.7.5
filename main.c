#include "mbedtls_sha256.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

int main(void) {
    uint8_t buf[16384] = {0};
    uint64_t buflen = 0;

    while (true) {
        int c = getc(stdin);
        if (c != EOF) {
            if (buflen < 16384) {
                buf[buflen++] = (uint8_t) c;
            } else {
                fprintf(stderr, "ERROR: There are more than 16 KiB data from stdin.\n");
                return -1;
            }
        } else if (feof(stdin)) {
            break;
        } else if (ferror(stdin)) {
            fprintf(stderr, "ERROR: Encounter some file stream error on stdin.\n");
            return -1;
        } else {
            fprintf(stderr, "ERROR: Encounter some unknown error on stdin.\n");
            return -1;
        }
    }

    uint8_t obuf[32] = {0};

    int err = mbedtls_sha256_ret(buf, buflen, obuf, false);
    if (err) {
        fprintf(stderr, "ERROR: The SHA-256 function returns non-zero error code.\n");
        return -1;
    }

    bool write_err = fwrite(obuf, 32, 1, stdout) != 1;
    if (write_err) {
        fprintf(stderr, "ERROR: Failed to write result to stdout.\n");
        return -1;
    }

    return 0;
}
