// gcc trace_func.c -rdynamic -finstrument-functions 增加-rdynamic编译选项，该编译选项的含义是：使得程序中的共享库的全局符号可用  
// -finstrument-functions编译选项就会在每一个用户自定义函数中添加下面两个函数调用: 
// void __cyg_profile_func_enter(void *this, void *callsite);
// void __cyg_profile_func_exit(void *this, void *callsite);
// 其中this指针指向当前函数的地址，callsite是指向上一级调用函数的地址   https://wangfakang.github.io/c5/
#include <stdio.h>
#include <malloc.h>
#include <execinfo.h>


void __cyg_profile_func_exit(void* callee, void* callsite) __attribute__((no_instrument_function));
void __cyg_profile_func_enter(void* callee, void* callsite) __attribute__((no_instrument_function));


void __cyg_profile_func_enter(void* callee, void* callsite) {
    void    *funptr = callee;
    char **p = backtrace_symbols(&funptr, 1);
    printf("Entering: %s\n", *p);
    free(p);
}


void __cyg_profile_func_exit(void* callee, void* callsite) {
    void    *funptr = callee;
    char **p = backtrace_symbols(&funptr, 1);
    printf("Exiting: %s\n", *p);
    free(p);
}


void foo4() {
    printf("foo()\n");
}


void foo3() {
    foo4();
}


void foo2() {
    foo3();
}


void foo1() {
    foo2();
}


int main() {
    foo1();
    return 0;
}
