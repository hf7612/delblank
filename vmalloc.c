#include "stdio.h"
#include "stdlib.h"
#include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>

enum {     MEMINFO_TOTAL,     MEMINFO_FREE,     MEMINFO_BUFFERS,     MEMINFO_CACHED,     MEMINFO_SHMEM,     MEMINFO_SLAB,     MEMINFO_SLAB_RECLAIMABLE,     MEMINFO_SLAB_UNRECLAIMABLE,     MEMINFO_SWAP_TOTAL,     MEMINFO_SWAP_FREE,     MEMINFO_ZRAM_TOTAL,     MEMINFO_MAPPED,
    MEMINFO_VMALLOC_USED,     MEMINFO_PAGE_TABLES,     MEMINFO_KERNEL_STACK,     MEMINFO_ION_CACHED,     MEMINFO_GPU_CACHED,     MEMINFO_ION_DISP,     MEMINFO_TRACE,     MEMINFO_CMA_USAGE,     MEMINFO_COUNT };
static long get_allocated_vmalloc_memory() { char line[1024];     // Ignored tags that don't actually consume memory (ie remappings)
printf(" ccccccccc %ld ", 11);
    static const char* const ignored_tags[] = { "ioremap",             "map_lowmem",             "vm_map_ram",             NULL }; long size, vmalloc_allocated_size = 0; // UniqueFile fp = MakeUniqueFile("/proc/vmallocinfo", "re"); if (fp == nullptr) { return 0; }
    FILE *pF = fopen("/proc/vmallocinfo", "r");
    while (1) { if (fgets(line, 1024, pF) == NULL) { break; } int valid_line = 1; int i = 0;
        while (ignored_tags[i]) { if (strstr(line, ignored_tags[i]) != NULL) { valid_line = 0; break; }
            i++; }
        if (valid_line && (sscanf(line, "%*x-%*x %ld", &size) == 1)) { 
            // printf(" \nbbbbbbbbbbbbb44 %ld ", size);
            vmalloc_allocated_size += size; } }
    return vmalloc_allocated_size; } //   int MEMINFO_TOTAL = 0; //       int MEMINFO_FREE = 1; //       int MEMINFO_BUFFERS = 2; //       int MEMINFO_CACHED = 3; //       int MEMINFO_SHMEM = 4; //       int MEMINFO_SLAB = 5; //       int MEMINFO_SLAB_RECLAIMABLE = 6; //       int MEMINFO_SLAB_UNRECLAIMABLE = 7; //       int MEMINFO_SWAP_TOTAL = 8; //       int MEMINFO_SWAP_FREE = 9; //       int MEMINFO_ZRAM_TOTAL = 10; //       int MEMINFO_MAPPED = 11;      
      int MEMINFO_VM_ALLOC_USED = 12; //       int MEMINFO_PAGE_TABLES = 13; //       int MEMINFO_KERNEL_STACK = 14; //       int MEMINFO_ION_CACHED = 15; //       int MEMINFO_GPU_CACHED = 16; //       int MEMINFO_ION_DISP = 17; //       int MEMINFO_TRACE = 18; //       int MEMINFO_CMA_USAGE = 19; //       int MEMINFO_COUNT = 20; 
static long android_os_Debug_getMemInfo( ) { char buffer[4096]; size_t numFound = 0; //if (out == NULL) { jniThrowNullPointerException(env, "out == null"); return; }
    int fd = open("/proc/meminfo", O_RDONLY | O_CLOEXEC); //if (fd < 0) { ALOGW("Unable to open /proc/meminfo: %s\n", strerror(errno)); return; }
    int len = read(fd, buffer, sizeof(buffer)-1); close(fd); //if (len < 0) { ALOGW("Empty /proc/meminfo"); return; } 
    buffer[len] = 0; static const char* const tags[] = { "MemTotal:",             "MemFree:",             "Buffers:",             "Cached:",             "Shmem:",             "Slab:",             "SReclaimable:",             "SUnreclaim:",             "SwapTotal:",             "SwapFree:",             "ZRam:",             "Mapped:",             "VmallocUsed:",             "PageTables:",             "KernelStack:",             NULL }; static const int tagsLen[] = { 9,             8,             8,             7,             6,             5,             13,             11,             10,             9,             5,             7,             12,             11,             12,             0 };
    long mem[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; char* p = buffer;
    while (*p && numFound < (sizeof(tagsLen) / sizeof(tagsLen[0]))) { int i = 0;
        while (tags[i]) {
            if (strncmp(p, tags[i], tagsLen[i]) == 0) { p += tagsLen[i]; while (*p == ' ') p++; char* num = p;
                while (*p >= '0' && *p <= '9') p++; if (*p != 0) { *p = 0; p++; }
                mem[i] = atoll(num); numFound++; break; }
            i++; }
        while (*p && *p != '\n') { p++; }
        if (*p) p++; }
    // mem[MEMINFO_ZRAM_TOTAL] = get_zram_mem_used() / 1024;     // Recompute Vmalloc Used since the value in meminfo     // doesn't account for I/O remapping which doesn't use RAM.
    mem[MEMINFO_VMALLOC_USED] = get_allocated_vmalloc_memory() / 1024;// android_os_Debug_getCached(mem); android_os_Debug_getTrace(mem); android_os_Debug_getIONDISP(mem); android_os_Debug_getCmaUsage(mem);
    // int maxNum = env->GetArrayLength(out); if (maxNum > MEMINFO_COUNT) { maxNum = MEMINFO_COUNT; }       jlong* outArray = env->GetLongArrayElements(out, 0);
    // if (outArray != NULL) { for (int i=0; i<maxNum; i++) { outArray[i] = mem[i]; } } env->ReleaseLongArrayElements(out, outArray, 0); 

    return mem[MEMINFO_SHMEM] + mem[MEMINFO_SLAB_UNRECLAIMABLE] + mem[MEMINFO_VM_ALLOC_USED] + mem[MEMINFO_PAGE_TABLES] + mem[MEMINFO_KERNEL_STACK];
    }
// long getKernelUsedSizeKb() { return mem[MEMINFO_SHMEM] + mem[MEMINFO_SLAB_UNRECLAIMABLE] + mem[MEMINFO_VM_ALLOC_USED] + mem[MEMINFO_PAGE_TABLES] + mem[MEMINFO_KERNEL_STACK]; }
int main(int c,char *v[]){ //printf(" aaaaaaaaaaaa  %l ", 11); // printf(" bbbbbbbbbbbbb %ld ", get_allocated_vmalloc_memory());
    printf(" aaa:%ld \n", android_os_Debug_getMemInfo());
}