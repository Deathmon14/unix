#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char buff[512];
    int f1, f2, n;

    if (argc != 3) {
        printf("USAGE: %s FROM TO\n", argv[0]);
        return 1; // Added return statement for error case
    }

    if ((f1 = open(argv[1], O_RDONLY)) < 0) {
        perror("ERROR IN OPENING");
        return 1;
    }

    if ((f2 = creat(argv[2], 0644)) < 0) {
        perror("ERROR IN CREATING");
        close(f1); // Close f1 before returning
        return 1;
    }

    while ((n = read(f1, buff, sizeof(buff))) > 0) {
        if (write(f2, buff, n) != n) {
            perror("WRITE ERROR");
            close(f1);
            close(f2);
            return 1;
        }
    }

    if (n < 0) {
        perror("READ ERROR");
    }

    close(f1);
    close(f2);

    if (remove(argv[1]) < 0) {
        perror("ERROR IN REMOVING");
        return 1;
    }

    return 0; // Added return statement for successful execution
}

