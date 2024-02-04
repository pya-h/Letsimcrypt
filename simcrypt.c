/* This is a simple encrypt/decryption app
It just combines some elementry encrytion algorythms, */
#include <stdio.h>

#define ROT_X 13
#define MAX_TEXT_LENGTH 10000

typedef unsigned short Int;
typedef unsigned char byte;

Int length(char text[]) {
    Int l = 0;
    for(; l < MAX_TEXT_LENGTH && text[l]; l++);
    return l;
}
void rotate(char *raw, byte n, byte specials_count);
int main()
{
    char mixed_alpha[] = "w:t,v_uy;xz?d\'a-bcn.oml{ref}(phi)g\"j!kqs";
    char actual_alpha[] = "abcdefghijklmnopqrstuvwxyz.!?:;,-_(){}\'\"";
    char signs[] = ".!?:;,-_(){}\'\"";
    char x[] = ".!?:;,-_(){}\'\"";
    for(char *c = x; *c; c++) printf("%d ", *c);
    char text[MAX_TEXT_LENGTH] = {'\0'};
    scanf("%10000[^\n]", text);
    printf("%s", text);

}

void rotate(char *raw, byte n, byte specials_count) {
    for(char *c = raw; *c; c++) {
        // TODO: Check if character is from the envrypting list
        *c = (*c + n) % specials_count;
    }

}