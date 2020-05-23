#include <stdio.h>     /* for printf */ 
#include <stdlib.h>    /* for exit */ 
#include <getopt.h> 
#include <ctype.h>
#include <string.h> // char *map="\n\x1\r\x2";
#include <unistd.h>
#include <sys/types.h>
char *copyRight[] ={"/*",
" * Copyright ",
" *",
" * Licensed under the ",
" * you may not use this ",
" * You may obtain a copy of the License at",
" *",
" *      ",
" *",
" * Unless required by",
" * distributed under the License",
" * WITHOUT WARRANTIES OR CONDITIONS",
" * See the License for",
" * limitations under the License",
" */", 0};
// int trim(char *s, int *lenI, int *chg) { int len = *lenI; int beg=0; int end=0; *chg = 0;//printf("%s\n", s);
//     while ( beg < len ) {
//         if( !isblank(s[beg])){
//             break;
//         }
//         if(s[beg] == '\n'){
//             s[beg] = 1;
//             *chg = 1;
//         }
//         beg++;
//     }
//     while(beg < len){
//         if(s[beg] == '\n'){ end = beg+1;
//             while(end < len){
//                 if(s[end] == '\n'||s[end] == '\r'){
//                     s[end] = ' ';
//                     *chg = 1;
//                 }
//                 if( !isblank(s[end])){
//                     break;
//                 } 
//                 end++;
//             }
//             beg = end+1;
//         }else{
//             beg++;
//         }
//     }
//     // printf("%s\n", s);
// }
// int trimRevers(char *s, int *lenI, int *chg) { int len = *lenI; int beg=0; int end=len; *chg = 0;//printf("%s\n", s);
//     s[len] = '\n';
//     while(end >= 0){
//         if(s[end] == '\n'){ int end2 = end-1;
//             while(end2 >= 1){
//                 if( !isblank(s[end2]) && !isspace(s[end2])){
//                     break; } 
//                 //if(s[end2] == '\n'||s[end] == '\r'){
//                     s[end2] = 0;
//                     *chg = 1; //}
//                 end2--; }
//             end = end2;
//         }
//         end--; } // printf("%s\n", s);
//     if(*chg){
//         int i =0; int a =0;
//         for(i=0; i<len; i++){
//             if(s[i])
//                 s[a++] = s[i];
//         }
//         *lenI = a;
//     }
// }
#define deB do{ printf("\n%s %d \n", __FUNCTION__, __LINE__);}while(0);
#define deBV(fmt, ...) do{printf("\n%s %d " fmt "\n", __FUNCTION__, __LINE__,##__VA_ARGS__);}while(0)
int DelBlank(char *f){
    #define MAX_BUF_LEN 1024*1024*50
    if(!f && !f[0]) return -1; FILE *pF = fopen(f, "r+");
    if(pF){ char *s = (char *)malloc(MAX_BUF_LEN);//deB
        if(s){ char *t;
            int r = fread(s, 1, MAX_BUF_LEN-1, pF); int chg=1;//deB
            char *s2=s; int n=0;
            while(copyRight[n] && (t=strchr(s2, '\n')) ){ t[0]=0;
                if(!strstr(s2, copyRight[n])){
                    s2=s; t[0]='\n'; chg=0;
                    break;} // printf("%s", s2);
                t[0]='\n';
                s2=t+1;
                n++; } // printf("%s", s2); // if(r>0) trimRevers(s, &r, &chg);//trim(s, &r, &chg);
            if(r>0 && chg){ fseek(pF, 0L, SEEK_SET); int len=strlen(s)-(s2-s); fprintf(stdout, "%s\n", f); //deBV("%s", f);
                fwrite(s2, 1, len, pF); truncate(f, len); 
            } free(s); 
        }else{ deBV("err malloc"); } fclose(pF); } }// trim // while (fgets(buf, MAX_PATH, pF1)) { // 	char *t = NULL; // 	if ((t = strchr(buf, '\n'))) { // 		t[0] = 0; // 	} // 	FILE *pF2 = fopen(buf, "rb"); // 	if (pF2) { // 		strcat(buf, "XXXXXX"); // 		int fd = mkstemp(buf); // 		char buf1[MAX_BUF_LEN] = { 0 }; // 		while (fgets(buf1, MAX_BUF_LEN, pF2)) { // 			if(IsChar(buf1) >= 0){ // 				write(fd, buf1, strlen(buf1)); // 			} // 		} // 		close(fd); // 		fclose(pF2); // 		sprintf(buf1, "%s", buf); // 		buf1[strlen(buf1)-6] = 0; // 		rename(buf, buf1); // 	} // } // fclose(pF1); // unlink(OUT_FILE); 
int main1(char *fL) {  //deBV("%s", fL);
	char c = '\r'; c = '\n';
    #define MAX_LEN 4096
	char r[MAX_LEN] = {0};//char b[MAX_LEN] = {0}; sprintf(b, "dos2unix %s 2>/dev/null", fL); system(b);
    FILE *pF = fopen(fL, "rb");
    if(pF){ char *t = 0;//fgets(r, MAX_LEN, pF);
        while(fgets(r, MAX_LEN, pF)){
            int l = strlen(r);
            if(r[l-1]=='\n')
                r[l-1]=0;            
            DelBlank(r); }
        fclose(pF); } }
int main(int argc, char **argv) { int c; int digit_optind = 0; //deB
    while (1) { int this_option_optind = optind ? optind : 1; int option_index = 0;
        static struct option long_options[] = { {"add",     required_argument, 0,  0 }, {"append",  no_argument,       0,  0 }, {"delete",  required_argument, 0,  0 },
            {"verbose", no_argument,       0,  0 }, {"create",  required_argument, 0, 'f'}, {"file",    required_argument, 0,  0 }, {0,         0,                 0,  0 } }; 
        c = getopt_long(argc, argv, "f:", long_options, &option_index); if (c == -1) break; // c = getopt_long(argc, argv, "abf:d:012", long_options, &option_index); if (c == -1) break; 
        switch (c) { //case 0: printf("option %s", long_options[option_index].name); if (optarg) printf(" with arg %s", optarg); printf("\n"); break; case '0': case '1': case '2': if (digit_optind != 0 && digit_optind != this_option_optind) printf("digits occur in two different argv-elements.\n"); digit_optind = this_option_optind; printf("option %c\n", c); break; case 'a': printf("option a\n"); break; case 'b': printf("option b\n"); break; case 'd': printf("option d with value '%s'\n", optarg); break; 
        case 'f': /*printf("option f with value '%s'\n", optarg); */  DelBlank(optarg);   break; case '?': break; default: printf("?? getopt returned character code 0%o ??\n", c); } } 
    if (optind < argc) { // printf("non-option ARGV-elements: "); 
        while (optind < argc) { //printf(" f:%s ", argv[optind]);
            main1(argv[optind++]);
            // printf(" v:%s ", argv[optind++]);
        } printf("\n"); }  }