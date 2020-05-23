#include <string.h>
int main(){
    char s[1024*1024];char c=0;
    while(1){
        memset(s, c++, sizeof(s));
    }
    return 0;
}