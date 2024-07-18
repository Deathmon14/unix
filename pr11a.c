#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int fd, n;
    char buff[512];

    if (argc != 2) {
        printf("ENTER CORRECT ARGUMENTS\n");
        return 1; // Added return statement for error case
    }

    fd = open(argv[1], O_RDONLY); // Corrected file open mode
    if (fd < 0) {
        perror("ERROR"); // Using perror to print detailed error message
        return 1;
    }

    while ((n = read(fd, buff, sizeof(buff))) > 0) { // Fixed parentheses for read condition
        if (write(1, buff, n) != n) { // Check if write successfully writes n bytes
            perror("Write error");
            close(fd);
            return 1;
        }
    }

    if (n < 0) {
        perror("Read error"); // Handling read error
    }

    close(fd);
    return 0; // Added return statement for successful execution
}

