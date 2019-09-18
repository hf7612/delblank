char *s;
#define STEP 1024*1024*10
int main(int argc, char *argv[]){
    if(argc == 2){
        int i = 0;
        int l = atoi(argv[1]);
        s=malloc(l);
        int max=l/STEP;
        char c = 0;
        for(i=0; i<max; i++){
            memset(s, c++, STEP);
        }
    }    
}