#incude "backtrace/Backtrace.h"
int btdump()
{
    void * libbacktrace = dlopen("/system/lib/libbacktrace.so",RTLD_LOCAL);
    if(!libbacktrace)
    {
        return -1;
    }

    Backtrace* (*create)(int,int,void*);
    *(void**) &create = dlsym(libbacktrace,"_ZN9Backtrace6CreateEiiP12BacktraceMap");
    if(!create)
    {
        return -1;
    }
    Backtrace* t = create(-1,-1,NULL);
    if(!t)
    {
        return -1;
    }
    int ret = t->Unwind(0);
    if(!ret)
    {
        return -1;
    }
    int count = t->NumFrames();
    printf("Backtrace:\n")
    for(i = 0; i < count; i++)
    {
        std::string line = t->FormatFrameData(i);
        print("\t%s",line.c_str());
    }
    return 0;
}