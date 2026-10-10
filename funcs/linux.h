/*
 * linux.h
 * 
 * POSIX / glibc-compatible Linux system call wrapper declarations.
 * Independent of standard libc; relies only on kernel ABI types.
 */

#ifndef _LINUX_H
#define _LINUX_H

#include <stddef.h>  
#include <stdint.h>  
#include <stdbool.h>

/* Project-local Linux ABI types */
#include "../defines/types/linux.h"

#ifdef __cplusplus
extern "C" {
#endif

/* --- Standard POSIX / C types fallback definitions --- */
#ifndef _SSIZE_T_DEFINED
typedef intptr_t ssize_t;
#define _SSIZE_T_DEFINED
#endif

#ifndef _OFF_T_DEFINED
typedef int64_t  off_t;
typedef int64_t  loff_t;
typedef int64_t  off64_t;
#define _OFF_T_DEFINED
#endif

#ifndef _PID_T_DEFINED
typedef int32_t  pid_t;
#define _PID_T_DEFINED
#endif

#ifndef _MODE_T_DEFINED
typedef uint32_t mode_t;
#define _MODE_T_DEFINED
#endif

#ifndef _UID_GID_T_DEFINED
typedef uint32_t uid_t;
typedef uint32_t gid_t;
#define _UID_GID_T_DEFINED
#endif

#ifndef _SOCKLEN_T_DEFINED
typedef uint32_t socklen_t;
#define _SOCKLEN_T_DEFINED
#endif

#ifndef _CLOCK_TYPES_DEFINED
typedef int32_t  clockid_t;
typedef int32_t  timer_t;
typedef int64_t  time_t;
typedef int64_t  clock_t;
#define _CLOCK_TYPES_DEFINED
#endif

#ifndef _NFDS_T_DEFINED
typedef unsigned long nfds_t;
#define _NFDS_T_DEFINED
#endif

#ifndef _ID_T_DEFINED
typedef uint32_t id_t;
typedef int      idtype_t;
#define _ID_T_DEFINED
#endif

#ifndef _IPC_TYPES_DEFINED
typedef int32_t       key_serial_t;
typedef int32_t       key_t;
typedef int32_t       mqd_t;
typedef unsigned long aio_context_t;
#define _IPC_TYPES_DEFINED
#endif

#ifndef _DEV_T_DEFINED
typedef uint64_t dev_t;
#define _DEV_T_DEFINED
#endif

/* Forward declarations for structures */
struct stat;
struct stat64;
struct statx;
struct statfs;
struct statfs64;
struct pollfd;
struct iovec;
struct timeval;
struct timespec;
struct __kernel_timespec;
struct timezone;
struct itimerval;
struct itimerspec;
struct utimbuf;
struct timex;
struct tms;
struct rusage;
struct rlimit;
struct rlimit64;
struct sched_param;
struct sched_attr;
struct clone_args;
struct robust_list_head;
struct rseq;
struct sigaction;
struct sigevent;
struct mq_attr;
struct sockaddr;
struct msghdr;
struct mmsghdr;
struct epoll_event;
struct io_event;
struct iocb;
struct io_uring_params;
struct utsname;
struct sysinfo;
struct open_how;
struct linux_dirent;
struct linux_dirent64;
struct mount_attr;
struct statmount;
struct shmid_ds;
struct msqid_ds;
struct sembuf;
struct perf_event_attr;
struct getcpu_cache;
struct cachestat_range;
struct cachestat;
struct file_handle;
struct namespace_entry;
struct futex_waitv;
union bpf_attr;

#ifndef _SIGSET_T_DEFINED
typedef struct { unsigned long __val[1024 / (8 * sizeof(unsigned long))]; } sigset_t;
#define _SIGSET_T_DEFINED
#endif

#ifndef _FD_SET_DEFINED
typedef struct { unsigned long __fds_bits[1024 / (8 * sizeof(unsigned long))]; } fd_set;
#define _FD_SET_DEFINED
#endif

#ifndef _CPU_SET_T_DEFINED
typedef struct { unsigned long __bits[1024 / (8 * sizeof(unsigned long))]; } cpu_set_t;
#define _CPU_SET_T_DEFINED
#endif

#ifndef _SIGINFO_T_DEFINED
typedef struct siginfo siginfo_t;
#define _SIGINFO_T_DEFINED
#endif

#ifndef _STACK_T_DEFINED
typedef struct sigaltstack stack_t;
#define _STACK_T_DEFINED
#endif

#ifndef _CAP_USER_TYPES_DEFINED
typedef void *cap_user_header_t;
typedef void *cap_user_data_t;
#define _CAP_USER_TYPES_DEFINED
#endif

#define LINUX_SYSCALL_API

#ifndef LINUX_SYSCALL_API
#  define LINUX_SYSCALL_API static inline
#endif

/* --- File I/O & Descriptors --- */
LINUX_SYSCALL_API ssize_t read(int fd, void *buf, size_t count);
LINUX_SYSCALL_API ssize_t write(int fd, const void *buf, size_t count);
LINUX_SYSCALL_API int     open(const char *pathname, int flags, mode_t mode);
LINUX_SYSCALL_API int     openat(int dirfd, const char *pathname, int flags, mode_t mode);
LINUX_SYSCALL_API int     openat2(int dirfd, const char *pathname, struct open_how *how, size_t size);
LINUX_SYSCALL_API int     creat(const char *pathname, mode_t mode);
LINUX_SYSCALL_API int     close(int fd);
LINUX_SYSCALL_API int     close_range(unsigned int fd, unsigned int max_fd, unsigned int flags);
LINUX_SYSCALL_API off_t   lseek(int fd, off_t offset, int whence);
LINUX_SYSCALL_API ssize_t pread(int fd, void *buf, size_t count, off_t offset);
LINUX_SYSCALL_API ssize_t pwrite(int fd, const void *buf, size_t count, off_t offset);
LINUX_SYSCALL_API ssize_t pread64(int fd, void *buf, size_t count, off_t offset);
LINUX_SYSCALL_API ssize_t pwrite64(int fd, const void *buf, size_t count, off_t offset);
LINUX_SYSCALL_API ssize_t readv(int fd, const struct iovec *iov, int iovcnt);
LINUX_SYSCALL_API ssize_t writev(int fd, const struct iovec *iov, int iovcnt);
LINUX_SYSCALL_API ssize_t preadv(int fd, const struct iovec *iov, int iovcnt, off_t offset);
LINUX_SYSCALL_API ssize_t pwritev(int fd, const struct iovec *iov, int iovcnt, off_t offset);
LINUX_SYSCALL_API ssize_t preadv2(int fd, const struct iovec *iov, int iovcnt, off_t offset, int flags);
LINUX_SYSCALL_API ssize_t pwritev2(int fd, const struct iovec *iov, int iovcnt, off_t offset, int flags);
LINUX_SYSCALL_API int     pipe(int pipefd[2]);
LINUX_SYSCALL_API int     pipe2(int pipefd[2], int flags);
LINUX_SYSCALL_API int     dup(int oldfd);
LINUX_SYSCALL_API int     dup2(int oldfd, int newfd);
LINUX_SYSCALL_API int     dup3(int oldfd, int newfd, int flags);
LINUX_SYSCALL_API int     flock(int fd, int operation);
LINUX_SYSCALL_API int     fsync(int fd);
LINUX_SYSCALL_API int     fdatasync(int fd);
LINUX_SYSCALL_API void    sync(void);
LINUX_SYSCALL_API int     syncfs(int fd);
LINUX_SYSCALL_API int     sync_file_range(int fd, off_t offset, off_t nbytes, unsigned int flags);
LINUX_SYSCALL_API int     fallocate(int fd, int mode, off_t offset, off_t len);
LINUX_SYSCALL_API ssize_t readahead(int fd, off_t offset, size_t count);
LINUX_SYSCALL_API ssize_t sendfile(int out_fd, int in_fd, off_t *offset, size_t count);
LINUX_SYSCALL_API ssize_t copy_file_range(int fd_in, off_t *off_in, int fd_out, off_t *off_out, size_t len, unsigned int flags);
LINUX_SYSCALL_API ssize_t splice(int fd_in, off_t *off_in, int fd_out, off_t *off_out, size_t len, unsigned int flags);
LINUX_SYSCALL_API ssize_t tee(int fd_in, int fd_out, size_t len, unsigned int flags);
LINUX_SYSCALL_API ssize_t vmsplice(int fd, const struct iovec *iov, size_t nr_segs, unsigned int flags);
LINUX_SYSCALL_API int     fcntl(int fd, int cmd, ...);
LINUX_SYSCALL_API int     ioctl_raw(unsigned long fd, unsigned long request, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4);

/* --- File Status, Attributes & Filesystems --- */
LINUX_SYSCALL_API int     stat(const char *pathname, struct stat *statbuf);
LINUX_SYSCALL_API int     fstat(int fd, struct stat *statbuf);
LINUX_SYSCALL_API int     lstat(const char *pathname, struct stat *statbuf);
LINUX_SYSCALL_API int     fstatat(int dirfd, const char *pathname, struct stat *statbuf, int flags);
LINUX_SYSCALL_API int     fstatat64(int dirfd, const char *pathname, struct stat64 *statbuf, int flags);
LINUX_SYSCALL_API int     statx(int dirfd, const char *pathname, int flags, unsigned int mask, struct statx *statxbuf);
LINUX_SYSCALL_API int     statfs(const char *path, struct statfs *buf);
LINUX_SYSCALL_API int     fstatfs(int fd, struct statfs *buf);
LINUX_SYSCALL_API int     statfs64(const char *path, size_t sz, struct statfs64 *buf);
LINUX_SYSCALL_API int     fstatfs64(int fd, size_t sz, struct statfs64 *buf);
LINUX_SYSCALL_API int     access(const char *pathname, int mode);
LINUX_SYSCALL_API int     faccessat2(int dirfd, const char *pathname, int mode, int flags);
LINUX_SYSCALL_API int     truncate(const char *path, off_t length);
LINUX_SYSCALL_API int     ftruncate(int fd, off_t length);
LINUX_SYSCALL_API int     truncate64(const char *path, off64_t length);
LINUX_SYSCALL_API int     ftruncate64(int fd, off64_t length);
LINUX_SYSCALL_API int     chdir(const char *path);
LINUX_SYSCALL_API int     fchdir(int fd);
LINUX_SYSCALL_API char   *getcwd(char *buf, size_t size);
LINUX_SYSCALL_API int     rename(const char *oldpath, const char *newpath);
LINUX_SYSCALL_API int     renameat(int olddirfd, const char *oldpath, int newdirfd, const char *newpath);
LINUX_SYSCALL_API int     renameat2(int olddirfd, const char *oldpath, int newdirfd, const char *newpath, unsigned int flags);
LINUX_SYSCALL_API int     mkdir(const char *pathname, mode_t mode);
LINUX_SYSCALL_API int     mkdirat(int dirfd, const char *pathname, mode_t mode);
LINUX_SYSCALL_API int     rmdir(const char *pathname);
LINUX_SYSCALL_API int     link(const char *oldpath, const char *newpath);
LINUX_SYSCALL_API int     linkat(int olddirfd, const char *oldpath, int newdirfd, const char *newpath, int flags);
LINUX_SYSCALL_API int     unlink(const char *pathname);
LINUX_SYSCALL_API int     unlinkat(int dirfd, const char *pathname, int flags);
LINUX_SYSCALL_API int     symlink(const char *target, const char *linkpath);
LINUX_SYSCALL_API int     symlinkat(const char *target, int newdirfd, const char *linkpath);
LINUX_SYSCALL_API ssize_t readlink(const char *pathname, char *buf, size_t bufsiz);
LINUX_SYSCALL_API ssize_t readlinkat(int dirfd, const char *pathname, char *buf, size_t bufsiz);
LINUX_SYSCALL_API int     chmod(const char *pathname, mode_t mode);
LINUX_SYSCALL_API int     fchmod(int fd, mode_t mode);
LINUX_SYSCALL_API int     fchmodat(int dirfd, const char *pathname, mode_t mode, int flags);
LINUX_SYSCALL_API int     fchmodat2(int dfd, const char *filename, mode_t mode, unsigned int flags);
LINUX_SYSCALL_API int     chown(const char *pathname, uid_t owner, gid_t group);
LINUX_SYSCALL_API int     fchown(int fd, uid_t owner, gid_t group);
LINUX_SYSCALL_API int     lchown(const char *pathname, uid_t owner, gid_t group);
LINUX_SYSCALL_API int     fchownat(int dirfd, const char *pathname, uid_t owner, gid_t group, int flags);
LINUX_SYSCALL_API mode_t  umask(mode_t mask);
LINUX_SYSCALL_API int     chroot(const char *path);
LINUX_SYSCALL_API int     mknod(const char *pathname, mode_t mode, dev_t dev);
LINUX_SYSCALL_API int     mknodat(int dirfd, const char *pathname, mode_t mode, dev_t dev);
LINUX_SYSCALL_API int     getdents(unsigned int fd, struct linux_dirent *dirp, unsigned int count);
LINUX_SYSCALL_API int     getdents64(unsigned int fd, struct linux_dirent64 *dirp, unsigned int count);
LINUX_SYSCALL_API int     lookup_dcookie(uint64_t cookie64, char *buf, size_t len);

/* --- Extended Attributes (xattr) --- */
LINUX_SYSCALL_API int     setxattr(const char *path, const char *name, const void *value, size_t size, int flags);
LINUX_SYSCALL_API int     lsetxattr(const char *path, const char *name, const void *value, size_t size, int flags);
LINUX_SYSCALL_API int     fsetxattr(int fd, const char *name, const void *value, size_t size, int flags);
LINUX_SYSCALL_API ssize_t getxattr(const char *path, const char *name, void *value, size_t size);
LINUX_SYSCALL_API ssize_t lgetxattr(const char *path, const char *name, void *value, size_t size);
LINUX_SYSCALL_API ssize_t fgetxattr(int fd, const char *name, void *value, size_t size);
LINUX_SYSCALL_API ssize_t listxattr(const char *path, char *list, size_t size);
LINUX_SYSCALL_API ssize_t llistxattr(const char *path, char *list, size_t size);
LINUX_SYSCALL_API ssize_t flistxattr(int fd, char *list, size_t size);
LINUX_SYSCALL_API int     removexattr(const char *path, const char *name);
LINUX_SYSCALL_API int     lremovexattr(const char *path, const char *name);
LINUX_SYSCALL_API int     fremovexattr(int fd, const char *name);
LINUX_SYSCALL_API int     setxattrat(int dfd, const char *pathname, const char *name, const void *value, size_t size, int flags);
LINUX_SYSCALL_API ssize_t getxattrat(int dfd, const char *pathname, const char *name, void *value, size_t size);
LINUX_SYSCALL_API ssize_t listxattrat(int dfd, const char *pathname, char *list, size_t size);
LINUX_SYSCALL_API int     removexattrat(int dfd, const char *pathname, const char *name);

/* --- Mount & VFS Namespaces --- */
LINUX_SYSCALL_API int     mount(const char *source, const char *target, const char *filesystemtype, unsigned long mountflags, const void *data);
LINUX_SYSCALL_API int     umount2(const char *target, int flags);
LINUX_SYSCALL_API int     pivot_root(const char *new_root, const char *put_old);
LINUX_SYSCALL_API int     swapon(const char *path, int swapflags);
LINUX_SYSCALL_API int     swapoff(const char *path);
LINUX_SYSCALL_API int     quotactl(int cmd, const char *special, int id, void *addr);
LINUX_SYSCALL_API int     quotactl_fd(unsigned int fd, unsigned int cmd, int id, void *addr);
LINUX_SYSCALL_API int     open_tree(int dfd, const char *filename, unsigned int flags);
LINUX_SYSCALL_API int     move_mount(int from_dfd, const char *from_pathname, int to_dfd, const char *to_pathname, unsigned int flags);
LINUX_SYSCALL_API int     fsopen(const char *fs_name, unsigned int flags);
LINUX_SYSCALL_API int     fsconfig(int fd, unsigned int cmd, const char *key, const void *value, int aux);
LINUX_SYSCALL_API int     fsmount(int fs_fd, unsigned int flags, unsigned int ms_flags);
LINUX_SYSCALL_API int     fspick(int dfd, const char *path, unsigned int flags);
LINUX_SYSCALL_API int     mount_setattr(int dfd, const char *path, unsigned int flags, struct mount_attr *uattr, size_t usize);
LINUX_SYSCALL_API int     statmount(int dfd, const char *pathname, struct statmount *buf, size_t size, unsigned int flags);
LINUX_SYSCALL_API ssize_t listmount(uint64_t *mnt_id, uint64_t *list, size_t num, unsigned int flags);
LINUX_SYSCALL_API int     open_tree_attr(int dfd, const char *path, unsigned int flags, struct open_how *how, size_t size);

/* --- Memory Management --- */
LINUX_SYSCALL_API void   *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);
LINUX_SYSCALL_API void   *mmap2(void *addr, size_t length, int prot, int flags, int fd, off_t pgoffset);
LINUX_SYSCALL_API int     mprotect(void *addr, size_t len, int prot);
LINUX_SYSCALL_API int     munmap(void *addr, size_t length);
LINUX_SYSCALL_API void   *mremap(void *old_address, size_t old_size, size_t new_size, int flags, void *new_address);
LINUX_SYSCALL_API int     msync(void *addr, size_t length, int flags);
LINUX_SYSCALL_API int     mincore(void *addr, size_t length, unsigned char *vec);
LINUX_SYSCALL_API int     madvise(void *addr, size_t length, int advice);
LINUX_SYSCALL_API int     mlock(const void *addr, size_t len);
LINUX_SYSCALL_API int     munlock(const void *addr, size_t len);
LINUX_SYSCALL_API int     mlockall(int flags);
LINUX_SYSCALL_API int     munlockall(void);
LINUX_SYSCALL_API int     mlock2(const void *addr, size_t len, unsigned int flags);
LINUX_SYSCALL_API int     brk(void *addr);
LINUX_SYSCALL_API int     memfd_create(const char *name, unsigned int flags);
LINUX_SYSCALL_API int     memfd_secret(unsigned int flags);
LINUX_SYSCALL_API int     pkey_mprotect(void *addr, size_t len, int prot, int pkey);
LINUX_SYSCALL_API int     pkey_alloc(unsigned int flags, unsigned int access_rights);
LINUX_SYSCALL_API int     pkey_free(int pkey);
LINUX_SYSCALL_API int     mseal(void *addr, size_t len, unsigned int flags);
LINUX_SYSCALL_API unsigned long map_shadow_stack(unsigned long addr, unsigned long len, unsigned int flags);

/* --- Process & Thread Lifecycle --- */
LINUX_SYSCALL_API pid_t   fork(void);
LINUX_SYSCALL_API pid_t   vfork(void);
LINUX_SYSCALL_API int     clone(unsigned long flags, void *child_stack, void *ptid, void *ctid, unsigned long tls);
LINUX_SYSCALL_API int     clone3(struct clone_args *cl_args, size_t size);
LINUX_SYSCALL_API int     execve(const char *pathname, char *const argv[], char *const envp[]);
LINUX_SYSCALL_API int     execveat(int dirfd, const char *pathname, char *const argv[], char *const envp[], int flags);
LINUX_SYSCALL_API void    _exit(int status);
LINUX_SYSCALL_API void    exit_group(int status);
LINUX_SYSCALL_API pid_t   wait4(pid_t pid, int *wstatus, int options, struct rusage *rusage);
LINUX_SYSCALL_API int     waitid(idtype_t idtype, id_t id, siginfo_t *infop, int options);
LINUX_SYSCALL_API pid_t   waitpid(pid_t pid, int *wstatus, int options);
LINUX_SYSCALL_API pid_t   getpid(void);
LINUX_SYSCALL_API pid_t   getppid(void);
LINUX_SYSCALL_API pid_t   gettid(void);
LINUX_SYSCALL_API pid_t   getpgid(pid_t pid);
LINUX_SYSCALL_API pid_t   getpgrp(void);
LINUX_SYSCALL_API pid_t   getsid(pid_t pid);
LINUX_SYSCALL_API int     setpgid(pid_t pid, pid_t pgid);
LINUX_SYSCALL_API pid_t   setsid(void);
LINUX_SYSCALL_API pid_t   set_tid_address(int *tidptr);
LINUX_SYSCALL_API int     prctl(int option, unsigned long arg2, unsigned long arg3, unsigned long arg4, unsigned long arg5);
LINUX_SYSCALL_API int     arch_prctl(int code, unsigned long addr);
LINUX_SYSCALL_API int     setns(int fd, int nstype);
LINUX_SYSCALL_API int     unshare(int flags);
LINUX_SYSCALL_API int     pidfd_open(pid_t pid, unsigned int flags);
LINUX_SYSCALL_API int     pidfd_getfd(int pidfd, int targetfd, unsigned int flags);
LINUX_SYSCALL_API int     pidfd_send_signal(int pidfd, int sig, siginfo_t *info, unsigned int flags);
LINUX_SYSCALL_API int     kcmp(pid_t pid1, pid_t pid2, int type, unsigned long idx1, unsigned long idx2);
LINUX_SYSCALL_API ssize_t process_vm_readv(pid_t pid, const struct iovec *local_iov, unsigned long liovcnt, const struct iovec *remote_iov, unsigned long riovcnt, unsigned long flags);
LINUX_SYSCALL_API ssize_t process_vm_writev(pid_t pid, const struct iovec *local_iov, unsigned long liovcnt, const struct iovec *remote_iov, unsigned long riovcnt, unsigned long flags);
LINUX_SYSCALL_API ssize_t process_madvise(int pidfd, const struct iovec *iovec, size_t vlen, int advice, unsigned int flags);

/* --- Credentials & Groups --- */
LINUX_SYSCALL_API uid_t   getuid(void);
LINUX_SYSCALL_API gid_t   getgid(void);
LINUX_SYSCALL_API uid_t   geteuid(void);
LINUX_SYSCALL_API gid_t   getegid(void);
LINUX_SYSCALL_API int     setuid(uid_t uid);
LINUX_SYSCALL_API int     setgid(gid_t gid);
LINUX_SYSCALL_API int     setreuid(uid_t ruid, uid_t euid);
LINUX_SYSCALL_API int     setregid(gid_t rgid, gid_t egid);
LINUX_SYSCALL_API int     setresuid(uid_t ruid, uid_t euid, uid_t suid);
LINUX_SYSCALL_API int     getresuid(uid_t *ruid, uid_t *euid, uid_t *suid);
LINUX_SYSCALL_API int     setresgid(gid_t rgid, gid_t egid, gid_t sgid);
LINUX_SYSCALL_API int     getresgid(gid_t *rgid, gid_t *egid, gid_t *sgid);
LINUX_SYSCALL_API int     getgroups(int size, gid_t list[]);
LINUX_SYSCALL_API int     setgroups(size_t size, const gid_t *list);
LINUX_SYSCALL_API int     setfsuid(uid_t fsuid);
LINUX_SYSCALL_API int     setfsgid(gid_t fsgid);
LINUX_SYSCALL_API int     capget(cap_user_header_t hdrp, cap_user_data_t datap);
LINUX_SYSCALL_API int     capset(cap_user_header_t hdrp, const cap_user_data_t datap);

/* --- Scheduling, Priority & Limits --- */
LINUX_SYSCALL_API int     sched_yield(void);
LINUX_SYSCALL_API int     sched_setparam(pid_t pid, const struct sched_param *param);
LINUX_SYSCALL_API int     sched_getparam(pid_t pid, struct sched_param *param);
LINUX_SYSCALL_API int     sched_setscheduler(pid_t pid, int policy, const struct sched_param *param);
LINUX_SYSCALL_API int     sched_getscheduler(pid_t pid);
LINUX_SYSCALL_API int     sched_get_priority_max(int policy);
LINUX_SYSCALL_API int     sched_get_priority_min(int policy);
LINUX_SYSCALL_API int     sched_rr_get_interval(pid_t pid, struct timespec *tp);
LINUX_SYSCALL_API int     sched_setaffinity(pid_t pid, size_t cpusetsize, const cpu_set_t *mask);
LINUX_SYSCALL_API int     sched_getaffinity(pid_t pid, size_t cpusetsize, cpu_set_t *mask);
LINUX_SYSCALL_API int     sched_setattr(pid_t pid, struct sched_attr *attr, unsigned int flags);
LINUX_SYSCALL_API int     sched_getattr(pid_t pid, struct sched_attr *attr, unsigned int size, unsigned int flags);
LINUX_SYSCALL_API int     nice(int inc);
LINUX_SYSCALL_API int     setpriority(int which, id_t who, int prio);
LINUX_SYSCALL_API int     getpriority(int which, id_t who);
LINUX_SYSCALL_API int     ioprio_set(int which, int who, int ioprio);
LINUX_SYSCALL_API int     ioprio_get(int which, int who);
LINUX_SYSCALL_API int     getrlimit(int resource, struct rlimit *rlim);
LINUX_SYSCALL_API int     setrlimit(int resource, const struct rlimit *rlim);
LINUX_SYSCALL_API int     prlimit64(pid_t pid, int resource, const struct rlimit64 *new_limit, struct rlimit64 *old_limit);
LINUX_SYSCALL_API int     getrusage(int who, struct rusage *usage);
LINUX_SYSCALL_API int     rseq(struct rseq *rseq, uint32_t rseq_len, int flags, uint32_t sig);
LINUX_SYSCALL_API int     rseq_slice_yield(struct rseq *rseq, unsigned int cpu_id, unsigned int flags);

/* --- Signals --- */
LINUX_SYSCALL_API int     kill(pid_t pid, int sig);
LINUX_SYSCALL_API int     tkill(pid_t tid, int sig);
LINUX_SYSCALL_API int     tgkill(pid_t tgid, pid_t tid, int sig);
LINUX_SYSCALL_API int     rt_sigaction(int signum, const struct sigaction *act, struct sigaction *oldact, size_t sigsetsize);
LINUX_SYSCALL_API int     rt_sigprocmask(int how, const sigset_t *set, sigset_t *oldset, size_t sigsetsize);
LINUX_SYSCALL_API int     rt_sigreturn(unsigned long __unused);
LINUX_SYSCALL_API int     rt_sigpending(sigset_t *set, size_t sigsetsize);
LINUX_SYSCALL_API int     rt_sigtimedwait(const sigset_t *set, siginfo_t *info, const struct timespec *timeout, size_t sigsetsize);
LINUX_SYSCALL_API int     rt_sigqueueinfo(pid_t pid, int sig, siginfo_t *info);
LINUX_SYSCALL_API int     rt_tgsigqueueinfo(pid_t tgid, pid_t tid, int sig, siginfo_t *info);
LINUX_SYSCALL_API int     rt_sigsuspend(const sigset_t *newset, size_t sigsetsize);
LINUX_SYSCALL_API int     sigaltstack(const stack_t *ss, stack_t *old_ss);
LINUX_SYSCALL_API int     signalfd(int fd, const sigset_t *mask, int flags);
LINUX_SYSCALL_API int     signalfd4(int fd, const sigset_t *mask, size_t sizemask, int flags);
LINUX_SYSCALL_API int     pause(void);
LINUX_SYSCALL_API unsigned int alarm(unsigned int seconds);
LINUX_SYSCALL_API int     restart_syscall(void);

/* --- Time & Clocks --- */
LINUX_SYSCALL_API int     gettimeofday(struct timeval *tv, struct timezone *tz);
LINUX_SYSCALL_API int     settimeofday(const struct timeval *tv, const struct timezone *tz);
LINUX_SYSCALL_API time_t  time(time_t *tloc);
LINUX_SYSCALL_API clock_t times(struct tms *buf);
LINUX_SYSCALL_API int     nanosleep(const struct timespec *req, struct timespec *rem);
LINUX_SYSCALL_API int     clock_nanosleep(clockid_t clockid, int flags, const struct timespec *request, struct timespec *remain);
LINUX_SYSCALL_API int     clock_settime(clockid_t clockid, const struct timespec *tp);
LINUX_SYSCALL_API int     clock_gettime(clockid_t clockid, struct timespec *tp);
LINUX_SYSCALL_API int     clock_getres(clockid_t clockid, struct timespec *res);
LINUX_SYSCALL_API int     clock_adjtime(clockid_t clk_id, struct timex *buf);
LINUX_SYSCALL_API int     adjtimex(struct timex *buf);
LINUX_SYSCALL_API int     timer_create(clockid_t clockid, struct sigevent *sevp, timer_t *timerid);
LINUX_SYSCALL_API int     timer_settime(timer_t timerid, int flags, const struct itimerspec *new_value, struct itimerspec *old_value);
LINUX_SYSCALL_API int     timer_gettime(timer_t timerid, struct itimerspec *curr_value);
LINUX_SYSCALL_API int     timer_getoverrun(timer_t timerid);
LINUX_SYSCALL_API int     timer_delete(timer_t timerid);
LINUX_SYSCALL_API int     getitimer(int which, struct itimerval *curr_value);
LINUX_SYSCALL_API int     setitimer(int which, const struct itimerval *new_value, struct itimerval *old_value);
LINUX_SYSCALL_API int     timerfd_create(int clockid, int flags);
LINUX_SYSCALL_API int     timerfd_settime(int fd, int flags, const struct itimerspec *new_value, struct itimerspec *old_value);
LINUX_SYSCALL_API int     timerfd_gettime(int fd, struct itimerspec *curr_value);
LINUX_SYSCALL_API int     utime(const char *filename, const struct utimbuf *times);
LINUX_SYSCALL_API int     utimes(const char *filename, const struct timeval times[2]);

/* --- Multiplexing & Polling --- */
LINUX_SYSCALL_API int     poll(struct pollfd *fds, nfds_t nfds, int timeout);
LINUX_SYSCALL_API int     ppoll(struct pollfd *fds, nfds_t nfds, const struct timespec *tmo_p, const sigset_t *sigmask);
LINUX_SYSCALL_API int     select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout);
LINUX_SYSCALL_API int     pselect(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, const struct timespec *timeout, const sigset_t *sigmask);
LINUX_SYSCALL_API int     epoll_create(int size);
LINUX_SYSCALL_API int     epoll_create1(int flags);
LINUX_SYSCALL_API int     epoll_ctl(int epfd, int op, int fd, struct epoll_event *event);
LINUX_SYSCALL_API int     epoll_wait(int epfd, struct epoll_event *events, int maxevents, int timeout);
LINUX_SYSCALL_API int     epoll_pwait(int epfd, struct epoll_event *events, int maxevents, int timeout, const sigset_t *sigmask);
LINUX_SYSCALL_API int     epoll_pwait2(int epfd, struct epoll_event *events, int maxevents, const struct timespec *timeout, const sigset_t *sigmask);
LINUX_SYSCALL_API int     eventfd(unsigned int initval, int flags);
LINUX_SYSCALL_API int     eventfd2(unsigned int initval, int flags);

/* --- Sockets & Networking --- */
LINUX_SYSCALL_API int     socket(int domain, int type, int protocol);
LINUX_SYSCALL_API int     socketpair(int domain, int type, int protocol, int sv[2]);
LINUX_SYSCALL_API int     bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
LINUX_SYSCALL_API int     listen(int sockfd, int backlog);
LINUX_SYSCALL_API int     accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
LINUX_SYSCALL_API int     accept4(int sockfd, struct sockaddr *addr, socklen_t *addrlen, int flags);
LINUX_SYSCALL_API int     connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
LINUX_SYSCALL_API int     shutdown(int sockfd, int how);
LINUX_SYSCALL_API int     getsockname(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
LINUX_SYSCALL_API int     getpeername(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
LINUX_SYSCALL_API int     setsockopt(int sockfd, int level, int optname, const void *optval, socklen_t optlen);
LINUX_SYSCALL_API int     getsockopt(int sockfd, int level, int optname, void *optval, socklen_t *optlen);
LINUX_SYSCALL_API ssize_t sendto(int sockfd, const void *buf, size_t len, int flags, const struct sockaddr *dest_addr, socklen_t addrlen);
LINUX_SYSCALL_API ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags, struct sockaddr *src_addr, socklen_t *addrlen);
LINUX_SYSCALL_API ssize_t sendmsg(int sockfd, const struct msghdr *msg, int flags);
LINUX_SYSCALL_API ssize_t recvmsg(int sockfd, struct msghdr *msg, int flags);
LINUX_SYSCALL_API int     sendmmsg(int sockfd, struct mmsghdr *msgvec, unsigned int vlen, int flags);
LINUX_SYSCALL_API int     recvmmsg(int sockfd, struct mmsghdr *msgvec, unsigned int vlen, int flags, struct timespec *timeout);
LINUX_SYSCALL_API int     socketcall(int call, unsigned long *args);

/* --- IPC & Futexes --- */
LINUX_SYSCALL_API int     futex(int *uaddr, int futex_op, int val, const struct timespec *timeout, int *uaddr2, int val3);
LINUX_SYSCALL_API int     futex_waitv(struct futex_waitv *waiters, unsigned int nr_futexes, unsigned int flags, struct timespec *timeout, clockid_t clockid);
LINUX_SYSCALL_API int     futex_wake(unsigned int *uaddr, unsigned int nr_wake, unsigned int mask, unsigned int flags);
LINUX_SYSCALL_API int     futex_wait(unsigned int *uaddr, unsigned int val, unsigned int mask, unsigned int flags, struct __kernel_timespec *timeout, clockid_t clockid);
LINUX_SYSCALL_API int     futex_requeue(unsigned int *uaddr, unsigned int nr_wake, unsigned int nr_requeue, unsigned int *uaddr2, unsigned int flags);
LINUX_SYSCALL_API int     set_robust_list(struct robust_list_head *head, size_t len);
LINUX_SYSCALL_API int     get_robust_list(int pid, struct robust_list_head **head_ptr, size_t *len_ptr);
LINUX_SYSCALL_API int     shmget(key_t key, size_t size, int shmflg);
LINUX_SYSCALL_API void   *shmat(int shmid, const void *shmaddr, int shmflg);
LINUX_SYSCALL_API int     shmctl(int shmid, int cmd, struct shmid_ds *buf);
LINUX_SYSCALL_API int     shmdt(const void *shmaddr);
LINUX_SYSCALL_API int     msgget(key_t key, int msgflg);
LINUX_SYSCALL_API int     msgsnd(int msqid, const void *msgp, size_t msgsz, int msgflg);
LINUX_SYSCALL_API ssize_t msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp, int msgflg);
LINUX_SYSCALL_API int     msgctl(int msqid, int cmd, struct msqid_ds *buf);
LINUX_SYSCALL_API int     semget(key_t key, int nsems, int semflg);
LINUX_SYSCALL_API int     semop(int semid, struct sembuf *sops, size_t nsops);
LINUX_SYSCALL_API int     semctl(int semid, int semnum, int cmd, unsigned long arg);
LINUX_SYSCALL_API int     semtimedop(int semid, struct sembuf *sops, size_t nsops, const struct timespec *timeout);
LINUX_SYSCALL_API int     ipc(unsigned int call, int first, unsigned long second, unsigned long third, void *ptr, long fifth);
LINUX_SYSCALL_API mqd_t   mq_open(const char *name, int oflag, mode_t mode, struct mq_attr *attr);
LINUX_SYSCALL_API int     mq_unlink(const char *name);
LINUX_SYSCALL_API int     mq_timedsend(mqd_t mqdes, const char *msg_ptr, size_t msg_len, unsigned int msg_prio, const struct timespec *abs_timeout);
LINUX_SYSCALL_API ssize_t mq_timedreceive(mqd_t mqdes, char *msg_ptr, size_t msg_len, unsigned int *msg_prio, const struct timespec *abs_timeout);
LINUX_SYSCALL_API int     mq_notify(mqd_t mqdes, const struct sigevent *sevp);
LINUX_SYSCALL_API int     mq_getsetattr(mqd_t mqdes, const struct mq_attr *newattr, struct mq_attr *oldattr);

/* --- Asynchronous I/O & io_uring --- */
LINUX_SYSCALL_API int     io_setup(unsigned int nr_events, aio_context_t *ctx_idp);
LINUX_SYSCALL_API int     io_destroy(aio_context_t ctx_id);
LINUX_SYSCALL_API int     io_submit(aio_context_t ctx_id, long nr, struct iocb **iocbpp);
LINUX_SYSCALL_API int     io_cancel(aio_context_t ctx_id, struct iocb *iocb, struct io_event *result);
LINUX_SYSCALL_API int     io_getevents(aio_context_t ctx_id, long min_nr, long nr, struct io_event *events, struct timespec *timeout);
LINUX_SYSCALL_API int     io_pgetevents(aio_context_t ctx_id, long min_nr, long nr, struct io_event *events, struct timespec *timeout, const sigset_t *sigmask);
LINUX_SYSCALL_API int     io_uring_setup(unsigned int entries, struct io_uring_params *p);
LINUX_SYSCALL_API int     io_uring_enter(unsigned int fd, unsigned int to_submit, unsigned int min_complete, unsigned int flags, sigset_t *sig);
LINUX_SYSCALL_API int     io_uring_register(unsigned int fd, unsigned int opcode, void *arg, unsigned int nr_args);

/* --- Inotify, Fanotify & Monitoring --- */
LINUX_SYSCALL_API int     inotify_init(void);
LINUX_SYSCALL_API int     inotify_init1(int flags);
LINUX_SYSCALL_API int     inotify_add_watch(int fd, const char *pathname, uint32_t mask);
LINUX_SYSCALL_API int     inotify_rm_watch(int fd, int wd);
LINUX_SYSCALL_API int     fanotify_init(unsigned int flags, unsigned int event_f_flags);
LINUX_SYSCALL_API int     fanotify_mark(int fanotify_fd, unsigned int flags, uint64_t mask, int dirfd, const char *pathname);

/* --- System Information, Modules & Security --- */
LINUX_SYSCALL_API int          uname(struct utsname *buf);
LINUX_SYSCALL_API int          sysinfo(struct sysinfo *info);
LINUX_SYSCALL_API int          syslog(int type, char *bufp, int len);
LINUX_SYSCALL_API int          reboot(int magic, int magic2, int cmd, void *arg);
LINUX_SYSCALL_API int          vhangup(void);
LINUX_SYSCALL_API int          acct(const char *filename);
LINUX_SYSCALL_API int          personality(unsigned long persona);
LINUX_SYSCALL_API int          sethostname(const char *name, size_t len);
LINUX_SYSCALL_API int          setdomainname(const char *name, size_t len);
LINUX_SYSCALL_API int          iopl(int level);
LINUX_SYSCALL_API int          ioperm(unsigned long from, unsigned long num, int turn_on);
LINUX_SYSCALL_API int          init_module(void *module_image, unsigned long len, const char *param_values);
LINUX_SYSCALL_API int          finit_module(int fd, const char *param_values, int flags);
LINUX_SYSCALL_API int          delete_module(const char *name, int flags);
LINUX_SYSCALL_API int          bpf(int cmd, union bpf_attr *attr, unsigned int size);
LINUX_SYSCALL_API int          userfaultfd(int flags);
LINUX_SYSCALL_API int          membarrier(int cmd, unsigned int flags, int cpu_id);
LINUX_SYSCALL_API key_serial_t add_key(const char *type, const char *description, const void *payload, size_t plen, key_serial_t keyring);
LINUX_SYSCALL_API key_serial_t request_key(const char *type, const char *description, const char *callout_info, key_serial_t dest_keyring);
LINUX_SYSCALL_API long         keyctl(int operation, unsigned long arg2, unsigned long arg3, unsigned long arg4, unsigned long arg5);
LINUX_SYSCALL_API int          seccomp(unsigned int operation, unsigned int flags, void *args);
LINUX_SYSCALL_API int          landlock_restrict_self(int ruleset_fd, uint32_t flags);
LINUX_SYSCALL_API int          lsm_list_modules(uint64_t *ids, size_t *size, uint32_t flags);
LINUX_SYSCALL_API ssize_t      getrandom(void *buf, size_t buflen, unsigned int flags);
LINUX_SYSCALL_API long         ptrace(int request, pid_t pid, void *addr, void *data);
LINUX_SYSCALL_API int          perf_event_open(struct perf_event_attr *attr, pid_t pid, int cpu, int group_fd, unsigned long flags);
LINUX_SYSCALL_API int          getcpu(unsigned int *cpu, unsigned int *node, struct getcpu_cache *tcache);
LINUX_SYSCALL_API int          cachestat(unsigned int fd, struct cachestat_range *crange, struct cachestat *cstat, unsigned int flags);
LINUX_SYSCALL_API int          file_getattr(int fd, unsigned int mask, struct file_handle *handle, size_t *handle_bytes);
LINUX_SYSCALL_API int          file_setattr(int fd, unsigned int mask, struct file_handle *handle, size_t handle_bytes);
LINUX_SYSCALL_API int          listns(int nstype, struct namespace_entry *entries, unsigned int max_entries, unsigned int flags);

#ifdef __cplusplus
}
#endif


#endif /* _LINUX_H */
