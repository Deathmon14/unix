#include<stdio.h>
#include<stdlib.h>
#include<unistd.h> // for dup2 and STDOUT_FILENO

int main() {
    FILE *f = fopen("f1", "w");
    if (f == NULL) {
        perror("fopen");
        return 1;
    }

    // Redirect stdout to the file
    if (dup2(fileno(f), STDOUT_FILENO) == -1) {
        perror("dup2");
        fclose(f);
        return 1;
    }

    // Execute the ls command
    system("ls");

    fclose(f);
    return 0;
}

