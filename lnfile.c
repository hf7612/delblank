 #include <string.h>
 #include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "pthread.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <error.h>
#include <sys/types.h>
#include <dirent.h> 
#define MAX_PATH 256
extern int errno;
int mkdirR(char *dirN) { char tmp[MAX_PATH];
	sprintf(tmp, "%s", dirN); int i = 1;
	while (tmp[i]) {
		if (tmp[i] == '/') {
			tmp[i] = 0;
			if (access(tmp, F_OK) != 0) {
				if (mkdir(tmp, 0777) == -1) {
					perror(tmp);
					return -1; } }
			tmp[i] = '/'; }
		i++; }
	return 0; }
int Symlink_Recurse(char *file1, char *file2) { //printf("%s -> %s\n", file1, file2); //return 0;
	if (symlink(file1, file2) != 0) {
		if (ENOENT == errno) {
			if (!mkdirR(file2)) {				
				if (symlink(file1, file2)) {
					perror("link");
					printf("\n%s -> %s", file1, file2);
					return -1; }
			} else
				return -1;
		} else {		
			perror("link");
			printf("\n%s -> %s", file1, file2); } }
	return 0; }
int main1(char *file, char *srcDir, char *dstDir) { int r = 0;
	FILE *pF = fopen(file, "rb");
	if (pF) { int i = 0; int recn = 0; int noExitSum = 0; char buf[MAX_PATH] = { 0 };
		while (fgets(buf, MAX_PATH, pF)) {
			if (strlen(buf) > 1) {
				recn++;
				buf[strlen(buf) - 1] = 0; char src[MAX_PATH] = { 0 }; char dst[MAX_PATH] = { 0 }; 
				if(!srcDir[0]){// if(buf[0]=='/')
						strcpy(src, buf); }
				else sprintf(src, "%s/%s", srcDir, buf);
				sprintf(dst, "%s/%s", dstDir, buf);
				char *lnSrc = src[0]?src:buf;//char *lnSrc = srcDir?src:buf;
				if(access(lnSrc, F_OK) != 0) {
					noExitSum++;
					printf("%s not exist \n", lnSrc);
				}else{
					r = Symlink_Recurse(lnSrc, dst);
					if(!r)
						i++; } } }
		printf("\nrecord:%d linkSum:%d noExitSum:%d\n", recn, i, noExitSum);
		if(recn-noExitSum == i)
			printf(" normal\n");
		else
			printf(" exception\n");
		fclose(pF);
	}else{
		perror(file); }
	return 0; }
#include <unistd.h>
#include <stdio.h>
#include <getopt.h>
int do_name, do_gf_name;
char *l_opt_arg;
struct option longopts[] = { /*  { "name",         no_argument,             NULL,                 'n'     }, { "gf_name",     no_argument,             NULL,                 'g'     }, { "love",         required_argument,     NULL,                 'l'     },*/
     { "dstDir",         required_argument,     NULL,                 'd'     },
     { "file",         required_argument,     NULL,                 'f'     },
     { "srcDir",         required_argument,     NULL,                 's'     }, {      0,     0,     0,     0}, };// { "srcDir",         required_argument optional_argument,     NULL,                 's'     }, 
// bool has_child(string path)
// {
//     if(!boost::filesystem::is_directory(path))
//         return false; 
//     boost::filesystem::directory_iterator end_it;
//     boost::filesystem::directory_iterator it(path);
//     if(it == end_it)
//         return false;
//     else
//         return true;
// }
int isDirectoryEmpty(char *dirname) { int n = 0; struct dirent *d; DIR *dir = opendir(dirname);
  if (dir == NULL) //Not a directory or doesn't exist
    return 1;
  while ((d = readdir(dir)) != NULL) {
    if(++n > 2)
      break; } closedir(dir);
  if (n <= 2) //Directory Empty
    return 1;
  else
    return 0; }
int main(int argc, char *argv[]) { int c; char *dstDir = 0; char *srcDir = NULL; char *file = NULL;
    while((c = getopt_long(argc, argv, ":l:d:s:f:h", longopts, NULL)) != -1){
         switch (c){
         case 'd': dstDir = optarg;
        	 if(access(dstDir, F_OK) == 0){
				 if(!dstDir[0]){
					if(isDirectoryEmpty)
        		 printf("%s have exist\n", optarg);
        		 return -1; } break;
         case 'f': file = optarg;
        	 if(access(file, F_OK)){
				 printf("%s not exist\n", file);
				 return -1; } break;
         case 's': srcDir = optarg; break;
         case 'h': default:
        	 printf("-f file -s srcDir -d dstDir\n"); return 0; break; } }}
	if(!srcDir){
		srcDir = "";
	}
	if(!dstDir){
		dstDir = "./";
		if(!isDirectoryEmpty(dstDir)){
			printf(" %s no empty \n", dstDir);
			return -1;
		}
	}
    if(dstDir&&file){
		main1(file, srcDir, dstDir);
	}else
    	printf("please specify dstDir\n");
    return 0; }
