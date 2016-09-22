#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

int print_usage(char* progname) 
{
    printf("Usage: %s [-i <delay>] <text>\n", progname);
    printf("\t-i\tDelay between characters in milliseconds\n");
    return 1;
}

int main(int argc, char** argv)
{
    if(argc < 2) {
        return print_usage(argv[0]);
    }

    int delay = 500;

    int opt;
    while((opt = getopt(argc, argv, "hi:")) != -1) {
        switch(opt) {
            case 'h':
                return print_usage(argv[0]);
            case 'i':
                delay = atoi(optarg);
                break;
            default:
                return print_usage(argv[0]);
        }
    }

    if(optind >= argc) {
        return print_usage(argv[0]);
    }

    char* text = argv[optind];

    size_t textlen = strlen(text);

    struct timespec sleeptime, time2;
    sleeptime.tv_sec = delay/1000;
    sleeptime.tv_nsec = (delay%1000)*1000000;


    for(int i = 0; i < textlen; i++) {
        putchar(text[i]);
        fflush(stdout);
        nanosleep(&sleeptime, NULL); 
    }
    putchar('\n');
    return 0;
}
