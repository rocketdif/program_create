#include <stdio.h>

int main(int argc, char *argv[]){
    FILE *fp = fopen(argv[1], "w");
    fclose(fp);
    return 0;
}
