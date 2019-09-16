// #include <stdio.h>
// #include <stdlib.h>
// #include <openssl/md5.h>
// #define BUFSIZE 1024*16
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
#if 0
)
{
#endif
static int shrinkConcatnate(char *s, int *lenI, int *chg) { int len = *lenI; int beg=0; int end=0; //*chg = 0; //deB//printf("%s\n", s);
    char *t = 0; char *sR = s;
    while( (t = strchr(sR, '\n'))) {
        sR = sR+1;
        if(s[t-s-1]=='\\'){ // find first /* // ind0 = ; 
            s[t-s-1] = ' ';
            t[0] = ' ';
            *chg = 1;} } }
static int trimLargeBlock(char *f){ struct stat statbuf; //deB
    if(!f && !f[0]) return -1;// const char pathname[256];
    if(!stat(f, &statbuf)){ //printf(" size:%d ", statbuf.st_size);// lstat(f, &statbuf); printf(" size:%d ", statbuf.st_size);
        int fSz = statbuf.st_size;
        if(fSz > 0){
            FILE *pF = fopen(f, "r+");
            if(pF){ //deB 
                char *s = (char *)malloc(fSz+2);//deB// char *s = (char *)malloc(MAX_BUF_LEN);//deB
                s[0] = ' '; s[fSz+1] = 0;//memset(s+fSz, 0, 2); 
                if(s){ //deB
                    int r = fread(s+1, 1, fSz, pF); int chg=0;//deB // memset(s, 0, 100);//for test 0 str
                    shrinkConcatnate(s, &r, &chg); 
                    if(chg){// do_md5(s, r);
                        fseek(pF, 0L, SEEK_SET); printf(" %s\n", f);//deBV("%s", f);
                        fwrite(s+1, 1, r, pF); } // int ftruncate(int fd, off_t length); // printf(" %s ", s); // fwrite(s, 1, statbuf.st_size, stdout);
                    free(s);
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