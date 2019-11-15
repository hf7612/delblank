#include "stdio.h"
#include "stdlib.h"
static long get_allocated_vmalloc_memory() { char line[1024];     // Ignored tags that don't actually consume memory (ie remappings)
printf(" ccccccccc %ld ", 11);
    static const char* const ignored_tags[] = { "ioremap",             "map_lowmem",             "vm_map_ram",             NULL }; long size, vmalloc_allocated_size = 0; // UniqueFile fp = MakeUniqueFile("/proc/vmallocinfo", "re"); if (fp == nullptr) { return 0; }
    FILE *pF = fopen("/proc/vmallocinfo", "r");
    while (1) { if (fgets(line, 1024, pF) == NULL) { break; } int valid_line = 1; int i = 0;
        while (ignored_tags[i]) { if (strstr(line, ignored_tags[i]) != NULL) { valid_line = 0; break; }
            i++; }
        if (valid_line && (sscanf(line, "%*x-%*x %ld", &size) == 1)) { 
            printf(" \nbbbbbbbbbbbbb44 %ld ", size);
            vmalloc_allocated_size += size; } }
    return vmalloc_allocated_size; }
int main(int c,char *v[]){ printf(" aaaaaaaaaaaa  %l ", 11);
    printf(" bbbbbbbbbbbbb %ld ", get_allocated_vmalloc_memory());
}