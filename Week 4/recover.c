#include <stdint.h>
#include <stdio.h>
int main(int argc, char *argv[]) {
    if (argc != 2) return 1;
    FILE *f = fopen(argv[1], "r");
    unsigned char b[512]; FILE *img = NULL; char n[8]; int c = 0;
    while (fread(b, 1, 512, f) == 512) {
        if (b[0]==0xff && b[1]==0xd8 && b[2]==0xff && (b[3]&0xf0)==0xe0) {
            if (img) fclose(img);
            sprintf(n, "%03i.jpg", c++); img = fopen(n, "w");
        }
        if (img) fwrite(b, 1, 512, img);
    }
    if (img) fclose(img); fclose(f);
}
