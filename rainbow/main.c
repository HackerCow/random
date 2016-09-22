#include <stdio.h>
#include <string.h>

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

int print_usage(char* progname)
{
    printf("Usage: %s <text>\n", progname);
    return 1;
}

int main(int argc, char** argv)
{
    if(argc < 2) {
       return print_usage(argv[0]); 
    }

    char* text = argv[1];
    size_t textlen = strlen(text);
    
    for(int i = 0; i < textlen; i++) {
        switch(i%7) {
            case 0: fputs(KRED, stdout); break;
            case 1: fputs(KGRN, stdout); break;
            case 2: fputs(KYEL, stdout); break;
            case 3: fputs(KBLU, stdout); break;
            case 4: fputs(KMAG, stdout); break;
            case 5: fputs(KCYN, stdout); break;
            case 6: fputs(KWHT, stdout); break;
        }
        putchar(text[i]);
    }
    puts(KNRM);
    return 0;
}
