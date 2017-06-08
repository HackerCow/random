#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int has_conflicts(int *field, int line_len, int line_count, int sec_w, int sec_h)
{
    // check lines
    uint16_t presentl = 0;
    uint16_t presentc = 0;
    for(int j = 0; j < line_count; j++) {
        for(int i = 0; i < line_len; i++) {
            int nl = field[j * line_len + i];
            int nc = field[i * line_count + j];

            if (nl == 0) {
                goto skip_nl;
            }


            if (presentl & 1 << (nl-1)) {
                return 1;
            }
            presentl |= 1 << (nl-1);
skip_nl:
            if (nc == 0) {
                continue;
            }

            if (presentc & 1 << (nc-1)) {
                return 1;
            }
            presentc |= 1 << (nc-1);
        }
        presentl = 0;
        presentc = 0;
    }

    uint16_t present = 0;
    for(int y = 0; y < line_count; y+=sec_h) {
        for(int x = 0; x < line_len; x+=sec_w) {
            for(int j = 0; j < sec_h; j++) {
                for(int i = 0; i < sec_w; i++) {
                    int n = field[(y + j) * line_count + (x + i)];
                    if (n == 0) {
                        continue;
                    }
 
                    if (present & 1 << (n-1)) {
                        return 1;
                    }
                    present |= 1 << (n-1);
                }
            }
            present = 0;
        }
    }

    return 0;
}

int is_solved(int *field, int line_len, int line_count)
{
    for (int i = 0; i < line_len * line_count; i++) {
        if (field[i] == 0) {
            return 0;
        }
    }

    return 1;
}

int solve(int *field, int line_len, int line_count)
{
    int currentpos = 0;
    while (!is_solved(field, line_len, line_count)) {
        while(field[currentpos] != 0) {
            currentpos++;
            if (currentpos >= line_len * line_count) {
                return 0;
            }
        }

        
    }
}

int main()
{
    FILE *file = fopen("field.txt", "r");
    size_t n = 0;
    int c;

    if (file == NULL) {
        perror("file open");
    }

    int pos = 0;

    int line_length = 9;
    int n_lines = 9;

    int field[line_length*n_lines];

    while ((c = fgetc(file)) != EOF) {
        if (c >= '0' && c <= '9') {
            field[pos++] = c-'0';
        }
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            putchar(field[i*line_length+j]+'0');
        }
        putchar('\n');
    }

    if (has_conflicts(field, line_length, n_lines, 3, 3)) {
        puts("fucked\n");
    }
}
