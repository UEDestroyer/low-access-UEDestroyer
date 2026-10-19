#ifndef DEFINES_TYPES_LINUX_H
#define DEFINES_TYPES_LINUX_H

/*
 * Linux userspace ABI types.
 *
 * This file deliberately includes NOTHING from libc, libstdc++, or Linux
 * headers.  The layouts below are the UAPI layouts used by the syscalls
 * wrapped by ../linux.h.  Fixed-width scalar types are expressed with C
 * builtin types so this header also works with -ffreestanding -nostdinc.
 *
 * Pointer-valued ABI members are represented by unsigned long where the
 * kernel ABI stores a userspace pointer.  Therefore the layout follows the
 * native Linux userspace ABI: 32-bit on ILP32/32-bit targets and 64-bit on
 * LP64 targets.
 */

/* ---------- scalar ABI types ---------- */
typedef signed char          linux_s8;
typedef unsigned char        linux_u8;
typedef short                linux_s16;
typedef unsigned short       linux_u16;
typedef int                  linux_s32;
typedef unsigned int         linux_u32;
typedef long long            linux_s64;
typedef unsigned long long   linux_u64;
typedef long                 linux_long;
typedef unsigned long        linux_ulong;

#if defined(__SIZEOF_POINTER__) && __SIZEOF_POINTER__ == 4
typedef linux_u32 linux_ptr;
#else
typedef linux_u64 linux_ptr;
#endif

/* Kernel fixed-width spellings, useful to code consuming these structs. */
typedef linux_s8  __s8;
typedef linux_u8  __u8;
typedef linux_s16 __s16;
typedef linux_u16 __u16;
typedef linux_s32 __s32;
typedef linux_u32 __u32;
typedef linux_s64 __s64;
typedef linux_u64 __u64;
typedef linux_long __kernel_long_t;
typedef linux_ulong __kernel_ulong_t;
typedef linux_long __kernel_ssize_t;
typedef linux_ulong __kernel_size_t;
typedef linux_s64 __kernel_time64_t;
typedef linux_s64 __kernel_loff_t;

/* Kernel fsid_t is two 32-bit integers in the syscall ABI. */
typedef struct {
    __s32 val[2];
} ue_kernel_fsid_t;

typedef linux_long linux_time_t;

/* ---------- vectors / polling ---------- */
struct ue_iovec {
    linux_ptr iov_base;
    linux_ulong iov_len;
};

struct ue_pollfd {
    int fd;
    short events;
    short revents;
};

struct ue_epoll_event {
    linux_u32 events;
    union {
        linux_u64 data;
        linux_ptr ptr;
        int fd;
        linux_u32 u32;
        linux_u64 u64;
    } data;
};

/* ---------- time ---------- */
struct ue_timespec {
    linux_long tv_sec;
    linux_long tv_nsec;
};

struct ue_kernel_timespec {
    linux_s64 tv_sec;
    linux_s64 tv_nsec;
};

struct ue_timeval {
    linux_long tv_sec;
    linux_long tv_usec;
};

struct ue_timezone {
    int tz_minuteswest;
    int tz_dsttime;
};

struct ue_itimerspec {
    struct ue_timespec it_interval;
    struct ue_timespec it_value;
};

struct ue_itimerval {
    struct ue_timeval it_interval;
    struct ue_timeval it_value;
};

struct ue_tms {
    linux_long tms_utime;
    linux_long tms_stime;
    linux_long tms_cutime;
    linux_long tms_cstime;
};

struct ue_utimbuf {
    linux_time_t actime;
    linux_time_t modtime;
};

/* linux/timex.h ABI. */
struct ue_timex {
    unsigned int modes;
    linux_long offset;
    linux_long freq;
    linux_long maxerror;
    linux_long esterror;
    int status;
    linux_long constant;
    linux_long precision;
    linux_long tolerance;
    struct ue_timeval time;
    linux_long tick;
    linux_long ppsfreq;
    linux_long jitter;
    int shift;
    linux_long stabil;
    linux_long jitcnt;
    linux_long calcnt;
    linux_long errcnt;
    linux_long stbcnt;
    int tai;
    int __padding[11];
};

/* ---------- scheduling / resource limits ---------- */
struct ue_sched_param {
    int ue_sched_priority;
};

struct ue_sched_attr {
    linux_u32 size;
    linux_u32 sched_policy;
    linux_u64 sched_flags;
    linux_s32 sched_nice;
    linux_u32 ue_sched_priority;
    linux_u64 sched_runtime;
    linux_u64 sched_deadline;
    linux_u64 sched_period;
    linux_u32 sched_util_min;
    linux_u32 sched_util_max;
};

struct ue_rlimit {
    linux_ulong rlim_cur;
    linux_ulong rlim_max;
};

struct ue_rlimit64 {
    linux_u64 rlim_cur;
    linux_u64 rlim_max;
};

struct ue_rusage {
    struct ue_timeval ru_utime;
    struct ue_timeval ru_stime;
    linux_long ru_maxrss;
    linux_long ru_ixrss;
    linux_long ru_idrss;
    linux_long ru_isrss;
    linux_long ru_minflt;
    linux_long ru_majflt;
    linux_long ru_nswap;
    linux_long ru_inblock;
    linux_long ru_oublock;
    linux_long ru_msgsnd;
    linux_long ru_msgrcv;
    linux_long ru_nsignals;
    linux_long ru_nvcsw;
    linux_long ru_nivcsw;
};

/* ---------- process / clone ---------- */
struct ue_clone_args {
    linux_u64 flags;
    linux_u64 pidfd;
    linux_u64 child_tid;
    linux_u64 parent_tid;
    linux_u64 exit_signal;
    linux_u64 stack;
    linux_u64 stack_size;
    linux_u64 tls;
    linux_u64 set_tid;
    linux_u64 set_tid_size;
    linux_u64 cgroup;
};

struct ue_robust_list {
    linux_ptr next;
};

struct ue_robust_list_head {
    struct ue_robust_list list;
    linux_long futex_offset;
    linux_ptr list_op_pending;
};

struct ue_futex_waitv {
    linux_u64 val;
    linux_u64 uaddr;
    linux_u32 flags;
    linux_u32 __reserved;
};

struct ue_rseq {
    linux_u32 cpu_id_start;
    linux_u32 cpu_id;
    linux_u64 rseq_cs;
    linux_u32 flags;
    linux_u32 __pad;
    linux_u64 __extension[0];
};

/* ---------- signals ---------- */
typedef struct {
    linux_ulong sig[2];
} linux_sigset_t;

#if defined(__i386__) || defined(__arm__)
struct ue_sigaction {
    linux_ptr ue_sa_handler;
    linux_u32 sa_flags;
    linux_ptr sa_restorer;
    linux_u32 sa_mask[2];
};
#else
struct ue_sigaction {
    linux_ptr ue_sa_handler;
    linux_ulong sa_flags;
    linux_ptr sa_restorer;
    linux_ulong sa_mask[2];
};
#endif

struct ue_sigevent {
    linux_u64 sigev_value;
    linux_s32 sigev_signo;
    linux_s32 sigev_notify;
    union {
        linux_ptr _function;
        linux_ptr _attribute;
        linux_u32 _tid;
        linux_u32 _pad[12];
    } _sigev_un;
};

/* ---------- sockets ---------- */
struct ue_sockaddr {
    unsigned short sa_family;
    char sa_data[14];
};

struct ue_msghdr {
    linux_ptr msg_name;
    linux_u32 msg_namelen;
    linux_ptr msg_iov;
    linux_ulong msg_iovlen;
    linux_ptr msg_control;
    linux_ulong msg_controllen;
    unsigned int msg_flags;
};

struct ue_mmsghdr {
    struct ue_msghdr msg_hdr;
    unsigned int msg_len;
};

/* ---------- filesystem / directory ---------- */
struct linux_dirent {
    linux_ulong d_ino;
    linux_ulong d_off;
    unsigned short d_reclen;
    char d_name[1];
};

struct linux_dirent64 {
    linux_u64 d_ino;
    linux_s64 d_off;
    unsigned short d_reclen;
    unsigned char d_type;
    char d_name[1];
};

struct ue_file_handle {
    unsigned int handle_bytes;
    int handle_type;
    unsigned char f_handle[0];
};

/* stat is ABI-specific; definitions below cover the architectures supported
 * by this project. */
#if defined(__aarch64__) || defined(__x86_64__)
struct ue_stat {
    linux_ulong st_dev;
    linux_ulong st_ino;
    linux_ulong st_nlink;
    unsigned int st_mode;
    unsigned int st_uid;
    unsigned int st_gid;
    unsigned int __pad0;
    linux_ulong st_rdev;
    linux_long st_size;
    linux_long st_blksize;
    linux_long st_blocks;
    linux_ulong ue_st_atime;
    linux_ulong st_atime_nsec;
    linux_ulong ue_st_mtime;
    linux_ulong st_mtime_nsec;
    linux_ulong ue_st_ctime;
    linux_ulong st_ctime_nsec;
    linux_long __unused[3];
};
#elif defined(__arm__)
struct ue_stat {
    linux_ulong st_dev;
    linux_ulong st_ino;
    unsigned short st_mode;
    unsigned short st_nlink;
    unsigned short st_uid;
    unsigned short st_gid;
    linux_ulong st_rdev;
    linux_ulong st_size;
    linux_ulong st_blksize;
    linux_ulong st_blocks;
    linux_ulong ue_st_atime;
    linux_ulong st_atime_nsec;
    linux_ulong ue_st_mtime;
    linux_ulong st_mtime_nsec;
    linux_ulong ue_st_ctime;
    linux_ulong st_ctime_nsec;
    linux_ulong __unused4;
    linux_ulong __unused5;
};
#else
struct ue_stat {
    linux_ulong st_dev;
    linux_ulong st_ino;
    unsigned int st_mode;
    unsigned int st_nlink;
    unsigned int st_uid;
    unsigned int st_gid;
    linux_ulong st_rdev;
    linux_ulong __pad1;
    linux_long st_size;
    int st_blksize;
    int __pad2;
    linux_long st_blocks;
    linux_long ue_st_atime;
    linux_ulong st_atime_nsec;
    linux_long ue_st_mtime;
    linux_ulong st_mtime_nsec;
    linux_long ue_st_ctime;
    linux_ulong st_ctime_nsec;
    unsigned int __unused4;
    unsigned int __unused5;
};
#endif

#if defined(__arm__)
struct ue_stat64 {
    linux_u64 st_dev;
    unsigned char __pad0[4];
    linux_ulong __st_ino;
    linux_u32 st_mode;
    linux_u32 st_nlink;
    linux_ulong st_uid;
    linux_ulong st_gid;
    linux_u64 st_rdev;
    unsigned char __pad3[4];
    linux_s64 st_size;
    linux_ulong st_blksize;
    linux_u64 st_blocks;
    linux_ulong ue_st_atime;
    linux_ulong st_atime_nsec;
    linux_ulong ue_st_mtime;
    linux_ulong st_mtime_nsec;
    linux_ulong ue_st_ctime;
    linux_ulong st_ctime_nsec;
    linux_u64 st_ino;
};
#elif defined(__i386__)
struct ue_stat64 {
    linux_u64 st_dev;
    unsigned char __pad0[4];
    linux_ulong __st_ino;
    linux_u32 st_mode;
    linux_u32 st_nlink;
    linux_ulong st_uid;
    linux_ulong st_gid;
    linux_u64 st_rdev;
    unsigned char __pad3[4];
    linux_s64 st_size;
    linux_ulong st_blksize;
    linux_u64 st_blocks;
    linux_ulong ue_st_atime;
    linux_ulong st_atime_nsec;
    linux_ulong ue_st_mtime;
    linux_ulong st_mtime_nsec;
    linux_ulong ue_st_ctime;
    linux_ulong st_ctime_nsec;
    linux_u64 st_ino;
};
#else
struct ue_stat64 {
    linux_u64 st_dev;
    linux_u64 st_ino;
    linux_u32 st_mode;
    linux_u32 st_nlink;
    linux_u32 st_uid;
    linux_u32 st_gid;
    linux_u64 st_rdev;
    linux_u64 __pad1;
    linux_s64 st_size;
    linux_s32 st_blksize;
    linux_s32 __pad2;
    linux_s64 st_blocks;
    linux_s32 ue_st_atime;
    linux_u32 st_atime_nsec;
    linux_s32 ue_st_mtime;
    linux_u32 st_mtime_nsec;
    linux_s32 ue_st_ctime;
    linux_u32 st_ctime_nsec;
    linux_u32 __unused4;
    linux_u32 __unused5;
};
#endif

/* asm-generic statfs ABI. */
#if defined(__aarch64__) || defined(__x86_64__)
typedef linux_long linux_statfs_word;
#else
typedef linux_u32 linux_statfs_word;
#endif

struct ue_statfs {
    linux_statfs_word f_type;
    linux_statfs_word f_bsize;
    linux_statfs_word f_blocks;
    linux_statfs_word f_bfree;
    linux_statfs_word f_bavail;
    linux_statfs_word f_files;
    linux_statfs_word f_ffree;
    ue_kernel_fsid_t f_fsid;
    linux_statfs_word f_namelen;
    linux_statfs_word f_frsize;
    linux_statfs_word f_flags;
    linux_statfs_word f_spare[4];
};

struct ue_statfs64 {
    linux_statfs_word f_type;
    linux_statfs_word f_bsize;
    linux_u64 f_blocks;
    linux_u64 f_bfree;
    linux_u64 f_bavail;
    linux_u64 f_files;
    linux_u64 f_ffree;
    ue_kernel_fsid_t f_fsid;
    linux_statfs_word f_namelen;
    linux_statfs_word f_frsize;
    linux_statfs_word f_flags;
    linux_statfs_word f_spare[4];
};

struct ue_statx_timestamp {
    linux_s64 tv_sec;
    linux_u32 tv_nsec;
    linux_s32 __reserved;
};

struct ue_statx {
    linux_u32 stx_mask;
    linux_u32 stx_blksize;
    linux_u64 stx_attributes;
    linux_u32 stx_nlink;
    linux_u32 stx_uid;
    linux_u32 stx_gid;
    linux_u16 stx_mode;
    linux_u16 __spare0[1];
    linux_u64 stx_ino;
    linux_u64 stx_size;
    linux_u64 stx_blocks;
    linux_u64 stx_attributes_mask;
    struct ue_statx_timestamp stx_atime;
    struct ue_statx_timestamp stx_btime;
    struct ue_statx_timestamp stx_ctime;
    struct ue_statx_timestamp stx_mtime;
    linux_u32 stx_rdev_major;
    linux_u32 stx_rdev_minor;
    linux_u32 stx_dev_major;
    linux_u32 stx_dev_minor;
    linux_u64 stx_mnt_id;
    linux_u32 stx_dio_mem_align;
    linux_u32 stx_dio_offset_align;
    linux_u64 stx_subvol;
    linux_u32 stx_atomic_write_unit_min;
    linux_u32 stx_atomic_write_unit_max;
    linux_u32 stx_atomic_write_segments_max;
    linux_u32 __spare1[1];
    linux_u64 __spare3[9];
};

/* ---------- mount/open ABI ---------- */
struct ue_open_how {
    linux_u64 flags;
    linux_u64 mode;
    linux_u64 resolve;
};

struct ue_mount_attr {
    linux_u64 attr_set;
    linux_u64 attr_clr;
    linux_u64 propagation;
    linux_u64 userns_fd;
};

/* Linux 6.x statmount ABI.  Reserved space is retained exactly so the
 * structure can be passed back to the kernel without libc headers. */
struct ue_statmount {
    linux_u32 size;
    linux_u32 __spare1;
    linux_u64 mask;
    linux_u32 sb_dev_major;
    linux_u32 sb_dev_minor;
    linux_u64 mnt_id;
    linux_u64 mnt_parent_id;
    linux_u64 mnt_id_unique;
    linux_u64 mnt_parent_id_unique;
    linux_u64 propagation;
    linux_u32 mask2;
    linux_u32 __spare2;
    linux_u64 __spare3[48];
};

/* ---------- System V IPC ---------- */
struct ue_sembuf {
    unsigned short sem_num;
    short sem_op;
    short sem_flg;
};

struct ue_ipc_perm {
    linux_long __key;
    linux_u32 uid;
    linux_u32 gid;
    linux_u32 cuid;
    linux_u32 cgid;
    unsigned short mode;
    unsigned short __pad1;
    unsigned short __seq;
    unsigned short __pad2;
    linux_ulong __unused1;
    linux_ulong __unused2;
};

struct ue_msqid_ds {
    struct ue_ipc_perm msg_perm;
    linux_ulong msg_stime;
    linux_ulong msg_rtime;
    linux_ulong msg_ctime;
    linux_ulong msg_cbytes;
    linux_ulong msg_qnum;
    linux_ulong msg_qbytes;
    linux_s32 msg_lspid;
    linux_s32 msg_lrpid;
    linux_ulong __unused4;
    linux_ulong __unused5;
};

struct ue_shmid_ds {
    struct ue_ipc_perm shm_perm;
    linux_ulong shm_atime;
    linux_ulong shm_dtime;
    linux_ulong shm_ctime;
    linux_ulong shm_segsz;
    linux_s32 shm_cpid;
    linux_s32 shm_lpid;
    linux_ulong shm_nattch;
    linux_ulong __unused4;
    linux_ulong __unused5;
};

struct ue_mq_attr {
    linux_long mq_flags;
    linux_long mq_maxmsg;
    linux_long mq_msgsize;
    linux_long mq_curmsgs;
    linux_long __reserved[4];
};

/* ---------- POSIX AIO ---------- */
struct ue_iocb {
    linux_u64 aio_data;
    linux_u32 aio_key;
    linux_u32 aio_rw_flags;
    linux_u16 aio_lio_opcode;
    linux_s16 aio_reqprio;
    linux_u32 aio_fildes;
    linux_u64 aio_buf;
    linux_u64 aio_nbytes;
    linux_s64 aio_offset;
    linux_u64 aio_reserved2;
    linux_u32 aio_flags;
    linux_u32 aio_resfd;
};

struct ue_io_event {
    linux_u64 data;
    linux_u64 obj;
    linux_s64 res;
    linux_s64 res2;
};

/* ---------- io_uring ---------- */
struct ue_io_uring_params {
    linux_u32 sq_entries;
    linux_u32 cq_entries;
    linux_u32 flags;
    linux_u32 sq_thread_cpu;
    linux_u32 sq_thread_idle;
    linux_u32 features;
    linux_u32 wq_fd;
    linux_u32 resv[3];
    struct {
        linux_u32 head;
        linux_u32 tail;
        linux_u32 ring_mask;
        linux_u32 ring_entries;
        linux_u32 flags;
        linux_u32 dropped;
        linux_u32 array;
        linux_u32 resv1;
        linux_u64 resv2;
    } sq_off;
    struct {
        linux_u32 head;
        linux_u32 tail;
        linux_u32 ring_mask;
        linux_u32 ring_entries;
        linux_u32 overflow;
        linux_u32 cqes;
        linux_u32 flags;
        linux_u32 resv1;
        linux_u64 resv2;
    } cq_off;
};

/* ---------- performance ---------- */
struct ue_perf_event_attr {
    linux_u32 type;
    linux_u32 size;
    linux_u64 config;
    union { linux_u64 sample_period; linux_u64 sample_freq; } sample_period;
    linux_u64 sample_type;
    linux_u64 read_format;
    linux_u64 flags;
    union { linux_u64 wakeup_events; linux_u64 wakeup_watermark; } wakeup;
    linux_u64 bp_type;
    union { linux_u64 bp_addr; linux_u64 config1; } bp_addr;
    union { linux_u64 bp_len; linux_u64 config2; } bp_len;
    linux_u64 branch_sample_type;
    linux_u64 sample_regs_user;
    linux_u32 sample_stack_user;
    linux_s32 clockid;
    linux_u64 sample_regs_intr;
    linux_u32 aux_watermark;
    linux_u16 sample_max_stack;
    linux_u16 __reserved_2;
    linux_u32 aux_sample_size;
    linux_u32 __reserved_3;
    linux_u64 sig_data;
    linux_u64 config3;
    linux_u64 __reserved[3];
};

/* ---------- system information ---------- */
struct ue_sysinfo {
    linux_long uptime;
    linux_ulong loads[3];
    linux_ulong totalram;
    linux_ulong freeram;
    linux_ulong sharedram;
    linux_ulong bufferram;
    linux_ulong totalswap;
    linux_ulong freeswap;
    unsigned short procs;
    unsigned short pad;
    linux_ulong totalhigh;
    linux_ulong freehigh;
    unsigned int mem_unit;
    char _f[20 - 2 * sizeof(linux_ulong) - sizeof(unsigned int)];
};

struct ue_utsname {
    char sysname[65];
    char nodename[65];
    char release[65];
    char version[65];
    char machine[65];
    char domainname[65];
};

/* ---------- cachestat ---------- */
struct ue_cachestat_range {
    linux_u64 off;
    linux_u64 len;
};

struct ue_cachestat {
    linux_u64 nr_cache;
    linux_u64 nr_dirty;
    linux_u64 nr_writeback;
    linux_u64 nr_evicted;
    linux_u64 nr_recently_evicted;
};

/* ---------- rseq ---------- */
struct ue_rseq_cs {
    linux_u64 version;
    linux_u64 flags;
    linux_u64 start_ip;
    linux_u64 post_commit_offset;
    linux_u64 abort_ip;
};

/* ---------- misc kernel ABI ---------- */
struct ue_getcpu_cache {
    linux_u64 blob[2];
};

/* Linux does not expose a stable UAPI layout for this project-specific
 * namespace listing extension. Keep an explicit fixed record rather than
 * importing a libc/kernel declaration. */
struct ue_namespace_entry {
    linux_u64 id;
    linux_u64 flags;
    linux_u64 type;
    linux_u64 parent;
};

#endif /* DEFINES_TYPES_LINUX_H */
