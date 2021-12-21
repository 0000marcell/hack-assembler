#include <stdio.h>
#include <assert.h>

int main(int argc, const char * argv[])
{
    FILE *file = fopen("./testfile", "r");
    char currentline[100];

    assert(file != NULL);

    while (fgets(currentline, sizeof(currentline), file) != NULL) {
        fprintf(stderr, "got line: %s\n", currentline);
        /* Do something with `currentline` */
    }

    fclose(file);
}
