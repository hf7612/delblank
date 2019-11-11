char *s;
#define STEP (1024*1024*10)
int idle(){
    while (1){
        usleep(1000); }
}
int main(int argc, char *argv[]){
    // idle();
    if(argc == 2){
        int i = 0;
        int l = atoi(argv[1]);
        s=malloc(l);
        int maxStep=l/STEP; printf(" %d \n", maxStep);
        char c = 0;
        while (1){
            for(i=0; i<maxStep; i++){
                memset(s+STEP*i, c++, STEP); }
            if(l>maxStep*STEP)
                memset(s+STEP*i, c++, l-maxStep*STEP);
            // usleep(1000);
        } 
    }    

}