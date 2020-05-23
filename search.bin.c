#include <stdio.h>
#include <string.h>
#include <stdio.h>     /* for printf */ 
#include <stdlib.h>    /* for exit */ 
#include <getopt.h> 
#include <ctype.h>
#include <string.h> // char *map="\n\x1\r\x2";
#include <unistd.h>
#include <sys/types.h>
#define MAX_L 1024
#define MAX_L2 102400
int main2(char *path){ 
    FILE *pF2 = fopen(path, "rb");
    if(pF2){  char s2[MAX_L2]={0};
        size_t t = fread(s2, 1, MAX_L2, pF2);
        int sum = 0;
        if(t>0){ int i;
            for(i=0;i<t; i++){
                if(!s2[i])
                    sum++; } }
        if(sum > 10){
            printf("%s\n", path); }
        fclose(pF2); } return 0; }
int main1(char *path){
    FILE *pF = fopen(path, "rb");
    if(pF){ char s[MAX_L+1]={0};
        while(fgets(s, MAX_L, pF)){ int l = strlen(s);
            if(l>0)
                if(s[l-1]=='\n')
                    s[l-1] = 0;// printf(" file:%s \n", s);
            FILE *pF2 = fopen(s, "rb");
            if(pF2){  char s2[MAX_L2]={0};
                size_t t = fread(s2, 1, MAX_L2, pF2);
                int sum = 0;
                if(t>0){ int i;
                   for(i=0;i<t; i++){
                        if(!s2[i])
                            sum++; } }
                if(sum > 10){
                    printf("%s\n", s); }
                fclose(pF2); } }
        fclose(pF); }
    return 0;
}
int main(int argc, char **argv) { int c; int digit_optind = 0; //deB
    while (1) { int this_option_optind = optind ? optind : 1; int option_index = 0;
        static struct option long_options[] = { {"add",     required_argument, 0,  0 }, {"append",  no_argument,       0,  0 }, {"delete",  required_argument, 0,  0 },
            {"verbose", no_argument,       0,  0 }, {"create",  required_argument, 0, 'f'}, {"file",    required_argument, 0,  0 }, {0,         0,                 0,  0 } }; 
        c = getopt_long(argc, argv, "f:", long_options, &option_index); if (c == -1) break; // c = getopt_long(argc, argv, "abf:d:012", long_options, &option_index); if (c == -1) break; 
        switch (c) { //case 0: printf("option %s", long_options[option_index].name); if (optarg) printf(" with arg %s", optarg); printf("\n"); break; case '0': case '1': case '2': if (digit_optind != 0 && digit_optind != this_option_optind) printf("digits occur in two different argv-elements.\n"); digit_optind = this_option_optind; printf("option %c\n", c); break; case 'a': printf("option a\n"); break; case 'b': printf("option b\n"); break; case 'd': printf("option d with value '%s'\n", optarg); break; 
        case 'f': /*printf("option f with value '%s'\n", optarg); */  main2(optarg);   break; case '?': break; default: printf("?? getopt returned character code 0%o ??\n", c); } } 
    if (optind < argc) { // printf("non-option ARGV-elements: "); 
        while (optind < argc) { //printf(" f:%s ", argv[optind]);
            main1(argv[optind++]);
            // printf(" v:%s ", argv[optind++]);
        } printf("\n"); }   }