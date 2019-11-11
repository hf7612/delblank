//  gcc compact_c.c -std=c99 -o /home/user/bin/compact_c    # // #include <stdio.h> // #include <stdlib.h> // #include <openssl/md5.h> // #define BUFSIZE 1024*16
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>     /* for printf */
#include <stdlib.h>    /* for exit */
#include <getopt.h>
#include <ctype.h>
#include <string.h>
#define deB do{ printf("\n%s %d \n", __FUNCTION__, __LINE__);}while(0);
#define deBV(fmt, ...) do{printf("\n%s %d " fmt "\n", __FUNCTION__, __LINE__,##__VA_ARGS__);}while(0)
// int main7(int argc, char **argv)
// {
//     int i,err=0;
//     FILE *IN;
//     if (argc == 1)
//             {
//             do_md5(stdin);
//             }
//     else
//             {
//             for (i=1; i<argc; i++)
//                     {
//                     IN=fopen(argv[i],"r");
//                     if (IN == NULL)
//                             {
//                             perror(argv[i]);
//                             err++;
//                             continue;
//                             }
//                     printf("MD5(%s)= ",argv[i]);
//                     do_md5(IN);
//                     fclose(IN);
//                     }
//             }
//     exit(err);
// }
//  unsigned char md[MD5_DIGEST_LENGTH];
// void do_md5(char *s, int len)//FILE *f)
// {
//     MD5_CTX c; // int fd;
//     int i;
//     static unsigned char buf[BUFSIZE];
//     // fd=fileno(f);
//     MD5_Init(&c);
//     // for (;;)
//     {
//         // i=read(fd,buf,BUFSIZE);
//         // if (i <= 0) break;
//         MD5_Update(&c,s,(unsigned long)len);//MD5_Update(&c,buf,(unsigned long)i);
//     }
//     MD5_Final(&(md[0]),&c);
//     // pt(md);
// }
// void pt(unsigned char *md)
// {
//     int i;
//     for (i=0; i<MD5_DIGEST_LENGTH; i++)
//         printf("%02x",md[i]);
//     printf("/n");
// }
// char *gets2(char *s)
// {
//     char *r = 0;
//     int i = 0;
//     int l = strlen(s);
//     for(i=0; i<l; i++){
//         if(s[i] == '\n'){ s[i] = 0;
//             r = s;
//             break;
//         }
//     }
//     return r;
// }
// // char *map="\n\x1\r\x2"; char *ge ts(char *s);
// int trim(char *s, int *lenI, int *chg) { int len = *lenI; int beg=0; int end=0; *chg = 0; //deB//printf("%s\n", s);
//     char *t = 0;//g ets(s);
//     char *s0=s;
//     while( (t = gets2(s0)) ){
//         int i =0;
//         int l = strlen(t);
//         while(i<l){
//             if(t[i]==']'){
//                 printf("%s\n", t+i+1);
//                 break;
//             }
//             i++;
//         }
//         s0=t+l+1;
//     }
// }
// int trimKmsg(char *f){
//     #define MAX_BUF_LEN 1024*1024*50
//     if(!f && !f[0]) return -1;
//     FILE *pF = fopen(f, "r+");
//     if(pF){ //deB
//         char *s = (char *)malloc(MAX_BUF_LEN);//deB
//         if(s){ //deB
//             int r = fread(s, 1, MAX_BUF_LEN, pF); //deB
//             int chg=0;
//             trim(s, &r, &chg); //if(chg){ fseek(pF, 0L, SEEK_SET); printf("%s\n", f);//deBV("%s", f); fwrite(s, 1, r, pF); }
//             free(s);
//         }else{
//             deBV("err malloc");
//         }
//         fclose(pF); } // trim // while (fgets(buf, MAX_PATH, pF1)) { // 	char *t = NULL; // 	if ((t = strchr(buf, '\n'))) { // 		t[0] = 0; // 	} // 	FILE *pF2 = fopen(buf, "rb"); // 	if (pF2) { // 		strcat(buf, "XXXXXX"); // 		int fd = mkstemp(buf); // 		char buf1[MAX_BUF_LEN] = { 0 }; // 		while (fgets(buf1, MAX_BUF_LEN, pF2)) { // 			if(IsChar(buf1) >= 0){ // 				write(fd, buf1, strlen(buf1)); // 			} // 		} // 		close(fd); // 		fclose(pF2); // 		sprintf(buf1, "%s", buf); // 		buf1[strlen(buf1)-6] = 0; // 		rename(buf, buf1); // 	} // } // fclose(pF1); // unlink(OUT_FILE);
// }
// static char *gets2b(char *s) { char *r = 0; int i = 0;
//     int l = strlen(s);
//     for(i=0; i<l; i++){
//         if(s[i] == '\n'){ s[i] = 0;
//             r = s;
//             break;
//         }
//     }
//     return r;
// }
// static trret2null(char *s, int beg, int end){
//     for(int i=beg;i<=end; i++){
//         if(s[i]=='\n'){
//             s[i] = 0;
//         }
//     }
// }
// static tranRet2Nullb(char *s, int len, int *chg){ //*chg = 0;
//     for(int i=0;i<len; i++){
//         if(s[i]=='\n'){
//             s[i] = ' ';
//             *chg = 1;// s[i] = 0;
//         } } }
// static int trimBlockComment(char *s, int *lenI, int *chg) { int len = *lenI; int beg=0; int end=0; //*chg = 0; //deB//printf("%s\n", s);
//     char *t = 0;//g ets(s);
//     char *t2 = 0; int ind0=0,ind1=0,ind2=0,ind3=0;
//     char *sR = s;
//     while(t = strchr(sR, '/')){ //printf(" %d ", t-s);
//         sR = t+1;
//         if(t[1]=='*'){ // find first /* // ind0 = ;
//             sR = t+2;
//             char *sR2 = t+1;
//             while( (t2 = strchr(sR2, '*')) ){
//                  sR2 = sR2+1;
//                 if(t2[1]=='/'){  // find first */ // fwrite("\n\n\n", 1, 3, stdout); fwrite(t, 1, 10, stdout);
//                     sR = t2+2;
//                     tranRet2Nullb(t+2, t2-t-2, chg);
//                     for(int i=t-s-1; i>0; i--){//trim prefix \n,\t,\b... 
//                         if(isspace(s[i])){//s[i]=='\n'||s[i]=='\t' || ){
//                             if(s[i] != ' '){
//                                 s[i] = ' ';
//                                 *chg = 1;}
//                         }else break; }
//                     break; } } } } } // compact ) {  unsigned long
static int compact0(char *s, int *lenI, int *chg) { int len = *lenI; int beg=0; int end=0; //*chg = 0; //deB//printf("%s\n", s);
    char *t = 0;//g ets(s);
    char *t2 = 0; int ind0=0,ind1=0,ind2=0,ind3=0;
    char * SYM1 = ")\n{";
    char *sR = s; int offL = strlen(SYM1);
    while(t = strchr(sR, '\n')){ //printf(" %d ", t-s);
        sR = t+1;
        for(int i=t-s-1; i>=0; i--){
            if(isspace(s[i])){
                if(s[i]!=' '){ s[i] = ' '; *chg = 1; }
            }else break; }
         }}
static int compact1(char *s, int *lenI, int *chg) { int len = *lenI; int beg=0; int end=0; //*chg = 0; //deB//printf("%s\n", s);
    char *t = 0;//g ets(s);
    char *t2 = 0; int ind0=0,ind1=0,ind2=0,ind3=0;
    char * SYM1 = ")\n{";
    char *sR = s; int offL = strlen(SYM1);
    while(t = strstr(sR, ")\n{") ){ //printf(" %d ", t-s);
        t[1] = ' ';
        sR = t+offL;
        *chg = 1; }}
static int compact2(char *s, int *lenI, int *chg) { int len = *lenI; int beg=0; int end=0; //*chg = 0; //deB//printf("%s\n", s);
    char *t = 0;//g ets(s);
    char *t2 = 0; int ind0=0,ind1=0,ind2=0,ind3=0;
    char * SYM2 = "\n}";
    char *sR = s; int offL = strlen(SYM2);
    while(t = strstr(sR, SYM2) ){ //printf(" %d ", t-s);
        t[0] = ' ';
        sR = t+offL;
        *chg = 1; }}// #include <   or  #include "
static int compact3(char *s, int *lenI, int *chg) { int len = *lenI; int beg=0; int end=0; //*chg = 0; //deB//printf("%s\n", s);
    char *t = 0;//g ets(s);
    char *t2 = 0; int ind0=0,ind1=0,ind2=0,ind3=0;
    char * SYM3 = "\n#include ";
    char *sR = s; int offL = strlen(SYM3);
    while(t = strstr(sR, SYM3) ){ //printf(" %d ", t-s);
        t[0] = ' ';
        sR = t+offL;
        *chg = 1; }}// compact &	
static int compact4(char *s, int *lenI, int *chg) { int len = *lenI; int beg=0; int end=0; //*chg = 0; //deB//printf("%s\n", s);
    char *t = 0;//g ets(s);
    char *t2 = 0; int ind0=0,ind1=0,ind2=0,ind3=0;
    char * SYM4 = "\nextern ";
    char *sR = s; int offL = strlen(SYM4);
    while(t = strstr(sR, SYM4) ){ //printf(" %d ", t-s);
        t[0] = ' ';
        sR = t+offL;
        *chg = 1; }}
static int compact5(char *s, int *lenI, int *chg) { int len = *lenI; int beg=0; int end=0; //*chg = 0; //deB//printf("%s\n", s);
    char *t = 0;//g ets(s); char *t2 = 0; int ind0=0,ind1=0,ind2=0,ind3=0;
    char * SYM5 = "//";
    char *sR = s; int offL = strlen(SYM5);
    while(t = strstr(sR, SYM5) ){ //printf(" %d ", t-s); 
        for(int i=t-s-1; i>=0; i--){
            if(isspace(s[i])){
                if(s[i]!=' '){ s[i] = ' '; *chg = 1; }
            }else break; } 
        sR = t+offL; }}//
static int compact5b(char *s, int *lenI, int *chg) { //int len = *lenI; int beg=0; int end=0; //*chg = 0; //deB//printf("%s\n", s);// spin_lock_ spin_unlock_
    char *t = 0; char * SYM[] = {"raw_spin_", "spin_lock_", "spin_unlock_", "local_irq_", "raw_spin_lock", "spin_unlock(", "spin_lock(",  "local_bh_disable", "mutex_lock", "mutex_unlock", 0}; int i=0; //g ets(s); char *t2 = 0; int ind0=0,ind1=0,ind2=0,ind3=0; 
    while(SYM[i]){ char *sR = s; int offL = strlen(SYM[i]);
        while(t = strstr(sR, SYM[i]) ){ //printf(" %d ", t-s); 
            for(int i=t-s-1; i>=0; i--){
                if(isspace(s[i])){
                    if(s[i]!=' '){ s[i] = ' '; *chg = 1; }
                }else break; } 
            sR = t+offL; }
        i++; } }
static int compact6(char *s, int *lenI, int *chg) { //int len = *lenI; int beg=0; int end=0; //*chg = 0; //deB//printf("%s\n", s);
    char *t = 0;//g ets(s); char *t2 = 0; //int ind0=0,ind1=0,ind2=0,ind3=0;
    char * SYM = "\nimport ";
    char *sR = s; int offL = strlen(SYM);
    while(t = strstr(sR, SYM) ){ //printf(" %d ", t-s);
        t[0] = ' ';
        sR = t+offL;
        *chg = 1; }}//import  MODULE_LICENSE  MODULE_DESCRIPTION  MODULE_AUTHOR

static int compact7(char *s, int *lenI, int *chg) { //int len = *lenI; int beg=0; int end=0; //*chg = 0; //deB//printf("%s\n", s);
    char *t = 0;//g ets(s); char *t2 = 0; //int ind0=0,ind1=0,ind2=0,ind3=0;
    char * SYM[] = {"\nMODULE_LICENSE(", "\nMODULE_DESCRIPTION(","\nMODULE_AUTHOR(", "\nextern ",  0}; int i=0;
    while(SYM[i]){
        char *sR = s; int offL = strlen(SYM[i]);
        while(t = strstr(sR, SYM[i]) ){ //printf(" %d ", t-s);
            t[0] = ' ';
            sR = t+offL;
            *chg = 1; }
        i++; }} //static inline
static int compact8(char *s, int *lenI, int *chg) { //int len = *lenI; int beg=0; int end=0; //*chg = 0; //deB//printf("%s\n", s);
    char *t = 0;//g ets(s); char *t2 = 0; //int ind0=0,ind1=0,ind2=0,ind3=0; static void // char * SYM[] = {"\nstatic inline\n", "\nstatic void\n", "\nstatic inline void\n", "\t{\n", " long\n", " int\n", " void\n", 0}; int i=0;//unsigned long
    char * SYM[] = {" inline\n", " void\n", "\t{\n", " long\n", " int\n", ",\n", "enum {\n", 0}; int i=0;//unsigned long
    while(SYM[i]){
        char *sR = s; int offL = strlen(SYM[i]);
        while(t = strstr(sR, SYM[i]) ){ //printf(" %d ", t-s);
            t[offL-1] = ' ';
            sR = t+offL;
            *chg = 1; }
        i++; }} // extern 
// static int compact4(char *s, int *lenI, int *chg) { int len = *lenI; int beg=0; int end=0; //*chg = 0; //deB//printf("%s\n", s);
//     char *t = 0;//g ets(s);
//     char *t2 = 0; int ind0=0,ind1=0,ind2=0,ind3=0; // char * SYM4 = "&";
//     char *sR = s; //int offL = strlen(SYM3);
//     while(t = strchr(sR, '&') ){ //printf(" %d ", t-s);
//         sR = t+1;
//         for(int i=t-s+1; i<*lenI; i++){
//             if(isspace(s[i])){ sR++;
//                 if(s[i]!=' '){ s[i] = ' '; *chg = 1; }
//             }else break; } 
//         }}
char *gS = 0;
// static int trimLargeBlock(char *f){ struct stat statbuf; //deB
//     if(!f && !f[0]) return -1;// const char pathname[256];
//     if(!stat(f, &statbuf)){ //printf(" size:%d ", statbuf.st_size);// lstat(f, &statbuf); printf(" size:%d ", statbuf.st_size);
//         int fSz = statbuf.st_size;
//         if(fSz > 0){
//             FILE *pF = fopen(f, "r+");
//             if(pF){ //deB 
//                 gS = (char *)malloc(fSz+2);//deB// char *s = (char *)malloc(MAX_BUF_LEN);//deB
//                 gS[0] = ' '; gS[fSz+1] = 0;//memset(gS+fSz, 0, 2); 
//                 if(gS){ //deB
//                     int r = fread(gS+1, 1, fSz, pF); int chg=0;//deB // memset(gS, 0, 100);//for test 0 str
//                     trimBlockComment(gS, &r, &chg); 
//                     if(chg){// do_md5(gS, r);
//                         fseek(pF, 0L, SEEK_SET); printf(" %s\n", f);//deBV("%gS", f);
//                         fwrite(gS+1, 1, r, pF); } // int ftruncate(int fd, off_t length); // printf(" %s ", gS); // fwrite(gS, 1, statbuf.st_size, stdout);
//                     free(gS);
//                 }else{
//                     deBV("err malloc"); }
//                 fclose(pF); } }// trim // while (fgets(buf, MAX_PATH, pF1)) { // 	char *t = NULL; // 	if ((t = strchr(buf, '\n'))) { // 		t[0] = 0; // 	} // 	FILE *pF2 = fopen(buf, "rb"); // 	if (pF2) { // 		strcat(buf, "XXXXXX"); // 		int fd = mkstemp(buf); // 		char buf1[MAX_BUF_LEN] = { 0 }; // 		while (fgets(buf1, MAX_BUF_LEN, pF2)) { // 			if(IsChar(buf1) >= 0){ // 				write(fd, buf1, strlen(buf1)); // 			} // 		} // 		close(fd); // 		fclose(pF2); // 		sprintf(buf1, "%s", buf); // 		buf1[strlen(buf1)-6] = 0; // 		rename(buf, buf1); // 	} // } // fclose(pF1); // unlink(OUT_FILE);
//     }
// }
static int trimLargeBlock(char *f){ struct stat statbuf; //deB
    if(!f && !f[0]) return -1;// const char pathname[256];
    if(!stat(f, &statbuf)){ //printf(" size:%d ", statbuf.st_size);// lstat(f, &statbuf); printf(" size:%d ", statbuf.st_size);
        int fSz = statbuf.st_size;
        if(fSz > 0){
            FILE *pF = fopen(f, "r+");
            if(pF){ //deB 
                gS = (char *)malloc(fSz+2);//deB// char *s = (char *)malloc(MAX_BUF_LEN);//deB
                gS[0] = ' '; gS[fSz+1] = 0;//memset(gS+fSz, 0, 2); 
                if(gS){ //deB
                    int r = fread(gS+1, 1, fSz, pF); int chg=0;//deB // memset(gS, 0, 100);//for test 0 str
                    compact0(gS, &r, &chg);
                    compact1(gS, &r, &chg);
                    compact2(gS, &r, &chg);
                    compact3(gS, &r, &chg);
                    compact4(gS, &r, &chg);
                    compact5(gS, &r, &chg);
                    compact5b(gS, &r, &chg);
                    compact6(gS, &r, &chg);
                    compact7(gS, &r, &chg);
                    compact8(gS, &r, &chg);
                    if(chg){// do_md5(gS, r);
                        fseek(pF, 0L, SEEK_SET); printf(" %s\n", f);//deBV("%gS", f);
                        fwrite(gS+1, 1, r, pF); } // int ftruncate(int fd, off_t length); // printf(" %s ", gS); // fwrite(gS, 1, statbuf.st_size, stdout);
                    free(gS);
                }else{
                    deBV("err malloc"); }
                fclose(pF); } }// trim // while (fgets(buf, MAX_PATH, pF1)) { // 	char *t = NULL; // 	if ((t = strchr(buf, '\n'))) { // 		t[0] = 0; // 	} // 	FILE *pF2 = fopen(buf, "rb"); // 	if (pF2) { // 		strcat(buf, "XXXXXX"); // 		int fd = mkstemp(buf); // 		char buf1[MAX_BUF_LEN] = { 0 }; // 		while (fgets(buf1, MAX_BUF_LEN, pF2)) { // 			if(IsChar(buf1) >= 0){ // 				write(fd, buf1, strlen(buf1)); // 			} // 		} // 		close(fd); // 		fclose(pF2); // 		sprintf(buf1, "%s", buf); // 		buf1[strlen(buf1)-6] = 0; // 		rename(buf, buf1); // 	} // } // fclose(pF1); // unlink(OUT_FILE);
    }
}
/*
*/
// int main1(char *fL) {  //deBV("%s", fL);
// 	char c = '\r'; c = '\n';
//     #define MAX_LEN 4096
// 	char b[MAX_LEN] = {0}; char r[MAX_LEN] = {0};
//     sprintf(b, "dos2unix %s 2>/dev/null", fL);
//     system(b);
//     FILE *pF = fopen(fL, "rb");
//     if(pF){
//         char *t = 0;//fgets(r, MAX_LEN, pF);
//         while(fgets(r, MAX_LEN, pF)){
//             int l = strlen(r);
//             if(r[l-1]=='\n')
//                 r[l-1]=0;
//             trimKmsg(r);
//         }
//         fclose(pF);
//     }
// }
int main(int argc, char **argv) { int c; int digit_optind = 0; //deB
    while (1) { int this_option_optind = optind ? optind : 1; int option_index = 0;
        static struct option long_options[] = { {"add",     required_argument, 0,  0 }, {"append",  no_argument,       0,  0 }, {"delete",  required_argument, 0,  0 },
            {"verbose", no_argument,       0,  0 }, {"create",  required_argument, 0, 'f'}, {"file",    required_argument, 0,  0 }, {0,         0,                 0,  0 } };
        c = getopt_long(argc, argv, "f:", long_options, &option_index); if (c == -1) break; // c = getopt_long(argc, argv, "abf:d:012", long_options, &option_index); if (c == -1) break;
        switch (c) { //case 0: printf("option %s", long_options[option_index].name); if (optarg) printf(" with arg %s", optarg); printf("\n"); break; case '0': case '1': case '2': if (digit_optind != 0 && digit_optind != this_option_optind) printf("digits occur in two different argv-elements.\n"); digit_optind = this_option_optind; printf("option %c\n", c); break; case 'a': printf("option a\n"); break; case 'b': printf("option b\n"); break; case 'd': printf("option d with value '%s'\n", optarg); break;
        case 'f':  //printf("option f with value '%s'\n", optarg);
            trimLargeBlock(optarg); //trimKmsg(optarg);
            break; case '?': break; default: printf("?? getopt returned character code 0%o ??\n", c); } }
    // if (optind < argc) { // printf("non-option ARGV-elements: ");
    //     while (optind < argc) { //deB//printf(" f:%s ", argv[optind]);
    //         trimKmsg(argv[optind++]); //deB // printf(" v:%s ", argv[optind++]);
    //     } printf("\n"); }
    // exit(EXIT_SUCCESS); 
}