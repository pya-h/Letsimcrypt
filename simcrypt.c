/* This is a simple encrypt/decryption app
It just combines some elementry encrytion algorythms, */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROT_X 13
#define MAX_TEXT_LENGTH 10000
#define NOW time(NULL)

typedef unsigned short Int;
typedef unsigned char byte;

Int length(char text[])
{
    Int l = 0;
    for (; l < MAX_TEXT_LENGTH && text[l]; l++)
        ;
    return l;
}
void shift(char *raw, byte n); //, byte specials_count);
// void rotate(char *raw, byte n, byte specials_count);
char *set_substitute_table(char *actual_chars, char *replacements, char *table);

void substitute(char *, char *);
void its_not_this(char *);

int main()
{
    long start_time = 0, current_step_start = NOW;
    char mixed_alpha[] = "Yw:t,vA_IK uJyB;xz?d\'aZUT-XbCcn.oLMmlD{Vref}E(phWi)FgG\"Hj!kNQPSRqs";
    char actual_alpha[] = "abcdefghijklmnopqrstuvwxyz. !?:;,-_(){}\'\"ABCDEFGHIJKLMNOPQRSTUVWXZ";
    char signs[] = ".!?:;,-_(){}\'\"";
    printf("creating substitue table ... ");
    char subtitue_table[256] = {'\0'};

    set_substitute_table(actual_alpha, mixed_alpha, subtitue_table);
    printf("done! [%ld seconds]\n", NOW - current_step_start);
    char *text = (char *)calloc(MAX_TEXT_LENGTH, sizeof(char));
    scanf("%10000[^\n]", text);
    start_time = NOW;
    current_step_start = start_time;
    printf("subtituting ... ");
    substitute(text, subtitue_table);
    printf("done! [%ld seconds]\n", NOW - current_step_start);
    printf("after substitution: %s\n", text);
    // current_step_start = NOW;
    printf("shifting ... ");
    shift(text, ROT_X);
    printf("shifted: %s\n", text);
    printf("done! [%ld seconds]", NOW - current_step_start);
    printf("noting... ");
    its_not_this(text);
    printf("done! [%ld seconds] [total: %ld]", NOW - current_step_start, NOW - start_time);
    printf("result := %s\n", text);
}

void shift(char *text, byte n) //, byte specials_count)
{
    while (*text)
    {
        // TODO: Check if character is from the envrypting list (is it needed?)
        // *text += n;
        if(*text >= 'A' && *text <= 'z')
            *text = 'A' + (*text + n) % ('z' - 'A');
        text++;
    }
}

char *set_substitute_table(char *actual_chars, char *replacements, char *table)
{
    // this function creates a table that enhances the substitue operation
    // it uses each character ascii code as an array index and assigns that index with corresponding encode char
    // So for example when the program wants to substitue X character, it just needs to find ascii('X')[=93]th element of array table

    // ceeate the table: each character is matchex to its replacement via its ascii code
    for (byte i = 0; actual_chars[i]; i++)
        table[actual_chars[i]] = replacements[i];

    return table;
}

void substitute(char *string, char *table)
{

    while (*string)
    {
        if (table[*string])
            *string = table[*string];
        string++;
    }
}

void its_not_this(char *whatever)
{
    for (; *whatever; *whatever = ~*whatever, whatever++)
        ;
}