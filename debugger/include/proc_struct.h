// golden
// 6/12/2018
//

#ifndef _PROC_STRUCT_H
#define _PROC_STRUCT_H

#ifdef __PS4__
#include <ps4.h>
#else
#include <stdint.h>
#endif

struct proc_vm_map_entry {
    char name[32];
    uint64_t start;
    uint64_t end;
    uint64_t offset;
    uint16_t prot;
} __attribute__((packed));

#endif
