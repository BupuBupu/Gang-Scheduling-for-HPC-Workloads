#ifndef _RESOURCE_TRACKER_H
#define _RESOURCE_TRACKER_H

#include <linux/list.h>
#include <linux/types.h>
#include <linux/spinlock.h>

extern struct list_head monitored_list;
extern spinlock_t monitored_list_lock;
struct per_proc_resource {
    pid_t pid;
    unsigned long heapsize; /*
	Total memory allocated by a process through the brk system call, and the mmap system call when used with  the MAP_ANONYMOUS | MAP_PRIVATE flags. */
    unsigned long openfile_count; /*
	Total number of open files of a process using the open, openat, and openat2 system calls*/
};

struct pid_node {
	struct per_proc_resource *proc_resource; /*
	Resource utilisation of a process*/
	struct list_head list; /*
	Contains pointers to previous and next elements*/
};
#endif