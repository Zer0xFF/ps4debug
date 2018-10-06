// golden
// 6/12/2018
//

#ifndef _KDEBUGGER_H
#define _KDEBUGGER_H

#include <ps4.h>
#include "kdbg_struct.h"
#include <stdarg.h>

void prefault(void *address, size_t size);
void *pfmalloc(size_t size);
void hexdump(void *data, size_t size);

// custom syscall 107
int sys_proc_list(struct proc_list_entry *procs, uint64_t *num);

// custom syscall 108
int sys_proc_rw(uint64_t pid, uint64_t address, void *data, uint64_t length, uint64_t write);

// custom syscall 109
int sys_proc_cmd(uint64_t pid, uint64_t cmd, void *data);

// custom syscall 110
int sys_kern_base(uint64_t *kbase);

// custom syscall 111
int sys_kern_rw(uint64_t address, void *data, uint64_t length, uint64_t write);

// custom syscall 112
int sys_console_cmd(uint64_t cmd, void *data);

#define uprintf(fmt, ...) { char buffer[256]; snprintf(buffer, 256, fmt, ##__VA_ARGS__); sys_console_cmd(SYS_CONSOLE_CMD_PRINT, buffer); }

#endif
