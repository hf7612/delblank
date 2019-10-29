char *s;
#define STEP (1024*1024*10)
int main(int argc, char *argv[]){
    if(argc == 2){
        int i = 0;
        int l = atoi(argv[1]);
        s=malloc(l);
        int maxStep=l/STEP; printf(" %d \n", maxStep);
        char c = 0;
        for(i=0; i<maxStep; i++){
                memset(s+STEP*i, c++, STEP); }
        if(l>maxStep*STEP)
            memset(s+STEP*i, c++, l-maxStep*STEP);
        while (1){
            for(i=0; i<maxStep; i++){
                memset(s+STEP*i, c++, STEP); }
            if(l>maxStep*STEP)
                memset(s+STEP*i, c++, l-maxStep*STEP);
            sleep(1);
        } 
    }else if(argc == 3){
        int unit=atoi(argv[1]);
        int blks=atoi(argv[2]);
        char *s1=malloc(unit*blks);
        char c = 0;
        for(int i=0; i<blks; i++){
            memset(s1+unit*i, c++, unit); }
        while (1){
            for(int i=0; i<blks; i++){
                memset(s1+unit*i, c++, unit); } 
            sleep(1); }
    }else printf("memeater blockunit blocks \n")    ;
}