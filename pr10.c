#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 1024

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }

    FILE *src = fopen(argv[1], "rb");
    if (src == NULL) {
        perror("Unable to open source file");
        return 1;
    }

    FILE *dst = fopen(argv[2], "wb");
    if (dst == NULL) {
        perror("Unable to create destination file");
        fclose(src);
        return 1;
    }

    char buf[BUFSIZE];
    size_t amount;
    while ((amount = fread(buf, 1, BUFSIZE, src)) > 0) {
        fwrite(buf, 1, amount, dst);
    }

    fclose(src);
    fclose(dst);

    return 0;
}

