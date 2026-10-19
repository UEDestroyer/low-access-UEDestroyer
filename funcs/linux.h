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
typedef int32_t  ue_timer_t;
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
typedef int      ue_idtype_t;
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
struct ue_stat;
struct ue_stat64;
struct ue_statx;
struct ue_statfs;
struct ue_statfs64;
struct ue_pollfd;
struct ue_iovec;
struct ue_timeval;
struct ue_timespec;
struct ue_kernel_timespec;
struct ue_timezone;
struct ue_itimerval;
struct ue_itimerspec;
struct ue_utimbuf;
struct ue_timex;
struct ue_tms;
struct ue_rusage;
struct ue_rlimit;
struct ue_rlimit64;
struct ue_sched_param;
struct ue_sched_attr;
struct ue_clone_args;
struct ue_robust_list_head;
struct ue_rseq;
struct ue_sigaction;
struct ue_sigevent;
struct ue_mq_attr;
struct ue_sockaddr;
struct ue_msghdr;
struct ue_mmsghdr;
struct ue_epoll_event;
struct ue_io_event;
struct ue_iocb;
struct ue_io_uring_params;
struct ue_utsname;
struct ue_sysinfo;
struct ue_open_how;
struct linux_dirent;
struct linux_dirent64;
struct ue_mount_attr;
struct ue_statmount;
struct ue_shmid_ds;
struct ue_msqid_ds;
struct ue_sembuf;
struct ue_perf_event_attr;
struct ue_getcpu_cache;
struct ue_cachestat_range;
struct ue_cachestat;
struct ue_file_handle;
struct ue_namespace_entry;
struct ue_futex_waitv;
union ue_bpf_attr;

#ifndef _SIGSET_T_DEFINED
typedef struct { unsigned long __val[1024 / (8 * sizeof(unsigned long))]; } ue_sigset_t;
#define _SIGSET_T_DEFINED
#endif

#ifndef _FD_SET_DEFINED
typedef struct { unsigned long __fds_bits[1024 / (8 * sizeof(unsigned long))]; } ue_fd_set;
#define _FD_SET_DEFINED
#endif

#ifndef _CPU_SET_T_DEFINED
typedef struct { unsigned long __bits[1024 / (8 * sizeof(unsigned long))]; } ue_cpu_set_t;
#define _CPU_SET_T_DEFINED
#endif

#ifndef _SIGINFO_T_DEFINED
typedef struct ue_siginfo ue_siginfo_t;
#define _SIGINFO_T_DEFINED
#endif

#ifndef _STACK_T_DEFINED
typedef struct ue_sigaltstack ue_stack_t;
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
LINUX_SYSCALL_API ssize_t ue_read(int fd, void *buf, size_t count);
LINUX_SYSCALL_API ssize_t ue_write(int fd, const void *buf, size_t count);
LINUX_SYSCALL_API int     ue_open(const char *pathname, int flags, mode_t mode);
LINUX_SYSCALL_API int     ue_openat(int dirfd, const char *pathname, int flags, mode_t mode);
LINUX_SYSCALL_API int     ue_openat2(int dirfd, const char *pathname, struct ue_open_how *how, size_t size);
LINUX_SYSCALL_API int     ue_creat(const char *pathname, mode_t mode);
LINUX_SYSCALL_API int     ue_close(int fd);
LINUX_SYSCALL_API int     ue_close_range(unsigned int fd, unsigned int max_fd, unsigned int flags);
LINUX_SYSCALL_API off_t   ue_lseek(int fd, off_t offset, int whence);
LINUX_SYSCALL_API ssize_t ue_pread(int fd, void *buf, size_t count, off_t offset);
LINUX_SYSCALL_API ssize_t ue_pwrite(int fd, const void *buf, size_t count, off_t offset);
LINUX_SYSCALL_API ssize_t ue_pread64(int fd, void *buf, size_t count, off_t offset);
LINUX_SYSCALL_API ssize_t ue_pwrite64(int fd, const void *buf, size_t count, off_t offset);
LINUX_SYSCALL_API ssize_t ue_readv(int fd, const struct ue_iovec *iov, int iovcnt);
LINUX_SYSCALL_API ssize_t ue_writev(int fd, const struct ue_iovec *iov, int iovcnt);
LINUX_SYSCALL_API ssize_t ue_preadv(int fd, const struct ue_iovec *iov, int iovcnt, off_t offset);
LINUX_SYSCALL_API ssize_t ue_pwritev(int fd, const struct ue_iovec *iov, int iovcnt, off_t offset);
LINUX_SYSCALL_API ssize_t ue_preadv2(int fd, const struct ue_iovec *iov, int iovcnt, off_t offset, int flags);
LINUX_SYSCALL_API ssize_t ue_pwritev2(int fd, const struct ue_iovec *iov, int iovcnt, off_t offset, int flags);
LINUX_SYSCALL_API int     ue_pipe(int pipefd[2]);
LINUX_SYSCALL_API int     ue_pipe2(int pipefd[2], int flags);
LINUX_SYSCALL_API int     ue_dup(int oldfd);
LINUX_SYSCALL_API int     ue_dup2(int oldfd, int newfd);
LINUX_SYSCALL_API int     ue_dup3(int oldfd, int newfd, int flags);
LINUX_SYSCALL_API int     ue_flock(int fd, int operation);
LINUX_SYSCALL_API int     ue_fsync(int fd);
LINUX_SYSCALL_API int     ue_fdatasync(int fd);
LINUX_SYSCALL_API void    ue_sync(void);
LINUX_SYSCALL_API int     ue_syncfs(int fd);
LINUX_SYSCALL_API int     ue_sync_file_range(int fd, off_t offset, off_t nbytes, unsigned int flags);
LINUX_SYSCALL_API int     ue_fallocate(int fd, int mode, off_t offset, off_t len);
LINUX_SYSCALL_API ssize_t ue_readahead(int fd, off_t offset, size_t count);
LINUX_SYSCALL_API ssize_t ue_sendfile(int out_fd, int in_fd, off_t *offset, size_t count);
LINUX_SYSCALL_API ssize_t ue_copy_file_range(int fd_in, off_t *off_in, int fd_out, off_t *off_out, size_t len, unsigned int flags);
LINUX_SYSCALL_API ssize_t ue_splice(int fd_in, off_t *off_in, int fd_out, off_t *off_out, size_t len, unsigned int flags);
LINUX_SYSCALL_API ssize_t ue_tee(int fd_in, int fd_out, size_t len, unsigned int flags);
LINUX_SYSCALL_API ssize_t ue_vmsplice(int fd, const struct ue_iovec *iov, size_t nr_segs, unsigned int flags);
LINUX_SYSCALL_API int     ue_fcntl(int fd, int cmd, ...);
LINUX_SYSCALL_API int     ue_ioctl_raw(unsigned long fd, unsigned long request, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4);

/* --- File Status, Attributes & Filesystems --- */
LINUX_SYSCALL_API int     ue_stat(const char *pathname, struct ue_stat *statbuf);
LINUX_SYSCALL_API int     ue_fstat(int fd, struct ue_stat *statbuf);
LINUX_SYSCALL_API int     ue_lstat(const char *pathname, struct ue_stat *statbuf);
LINUX_SYSCALL_API int     ue_fstatat(int dirfd, const char *pathname, struct ue_stat *statbuf, int flags);
LINUX_SYSCALL_API int     ue_fstatat64(int dirfd, const char *pathname, struct ue_stat64 *statbuf, int flags);
LINUX_SYSCALL_API int     ue_statx(int dirfd, const char *pathname, int flags, unsigned int mask, struct ue_statx *statxbuf);
LINUX_SYSCALL_API int     ue_statfs(const char *path, struct ue_statfs *buf);
LINUX_SYSCALL_API int     ue_fstatfs(int fd, struct ue_statfs *buf);
LINUX_SYSCALL_API int     ue_statfs64(const char *path, size_t sz, struct ue_statfs64 *buf);
LINUX_SYSCALL_API int     ue_fstatfs64(int fd, size_t sz, struct ue_statfs64 *buf);
LINUX_SYSCALL_API int     ue_access(const char *pathname, int mode);
LINUX_SYSCALL_API int     ue_faccessat2(int dirfd, const char *pathname, int mode, int flags);
LINUX_SYSCALL_API int     ue_truncate(const char *path, off_t length);
LINUX_SYSCALL_API int     ue_ftruncate(int fd, off_t length);
LINUX_SYSCALL_API int     ue_truncate64(const char *path, off64_t length);
LINUX_SYSCALL_API int     ue_ftruncate64(int fd, off64_t length);
LINUX_SYSCALL_API int     ue_chdir(const char *path);
LINUX_SYSCALL_API int     ue_fchdir(int fd);
LINUX_SYSCALL_API char   *ue_getcwd(char *buf, size_t size);
LINUX_SYSCALL_API int     ue_rename(const char *oldpath, const char *newpath);
LINUX_SYSCALL_API int     ue_renameat(int olddirfd, const char *oldpath, int newdirfd, const char *newpath);
LINUX_SYSCALL_API int     ue_renameat2(int olddirfd, const char *oldpath, int newdirfd, const char *newpath, unsigned int flags);
LINUX_SYSCALL_API int     ue_mkdir(const char *pathname, mode_t mode);
LINUX_SYSCALL_API int     ue_mkdirat(int dirfd, const char *pathname, mode_t mode);
LINUX_SYSCALL_API int     ue_rmdir(const char *pathname);
LINUX_SYSCALL_API int     ue_link(const char *oldpath, const char *newpath);
LINUX_SYSCALL_API int     ue_linkat(int olddirfd, const char *oldpath, int newdirfd, const char *newpath, int flags);
LINUX_SYSCALL_API int     ue_unlink(const char *pathname);
LINUX_SYSCALL_API int     ue_unlinkat(int dirfd, const char *pathname, int flags);
LINUX_SYSCALL_API int     ue_symlink(const char *target, const char *linkpath);
LINUX_SYSCALL_API int     ue_symlinkat(const char *target, int newdirfd, const char *linkpath);
LINUX_SYSCALL_API ssize_t ue_readlink(const char *pathname, char *buf, size_t bufsiz);
LINUX_SYSCALL_API ssize_t ue_readlinkat(int dirfd, const char *pathname, char *buf, size_t bufsiz);
LINUX_SYSCALL_API int     ue_chmod(const char *pathname, mode_t mode);
LINUX_SYSCALL_API int     ue_fchmod(int fd, mode_t mode);
LINUX_SYSCALL_API int     ue_fchmodat(int dirfd, const char *pathname, mode_t mode, int flags);
LINUX_SYSCALL_API int     ue_fchmodat2(int dfd, const char *filename, mode_t mode, unsigned int flags);
LINUX_SYSCALL_API int     ue_chown(const char *pathname, uid_t owner, gid_t group);
LINUX_SYSCALL_API int     ue_fchown(int fd, uid_t owner, gid_t group);
LINUX_SYSCALL_API int     ue_lchown(const char *pathname, uid_t owner, gid_t group);
LINUX_SYSCALL_API int     ue_fchownat(int dirfd, const char *pathname, uid_t owner, gid_t group, int flags);
LINUX_SYSCALL_API mode_t  ue_umask(mode_t mask);
LINUX_SYSCALL_API int     ue_chroot(const char *path);
LINUX_SYSCALL_API int     ue_mknod(const char *pathname, mode_t mode, dev_t dev);
LINUX_SYSCALL_API int     ue_mknodat(int dirfd, const char *pathname, mode_t mode, dev_t dev);
LINUX_SYSCALL_API int     ue_getdents(unsigned int fd, struct linux_dirent *dirp, unsigned int count);
LINUX_SYSCALL_API int     ue_getdents64(unsigned int fd, struct linux_dirent64 *dirp, unsigned int count);
LINUX_SYSCALL_API int     ue_lookup_dcookie(uint64_t cookie64, char *buf, size_t len);

/* --- Extended Attributes (xattr) --- */
LINUX_SYSCALL_API int     ue_setxattr(const char *path, const char *name, const void *value, size_t size, int flags);
LINUX_SYSCALL_API int     ue_lsetxattr(const char *path, const char *name, const void *value, size_t size, int flags);
LINUX_SYSCALL_API int     ue_fsetxattr(int fd, const char *name, const void *value, size_t size, int flags);
LINUX_SYSCALL_API ssize_t ue_getxattr(const char *path, const char *name, void *value, size_t size);
LINUX_SYSCALL_API ssize_t ue_lgetxattr(const char *path, const char *name, void *value, size_t size);
LINUX_SYSCALL_API ssize_t ue_fgetxattr(int fd, const char *name, void *value, size_t size);
LINUX_SYSCALL_API ssize_t ue_listxattr(const char *path, char *list, size_t size);
LINUX_SYSCALL_API ssize_t ue_llistxattr(const char *path, char *list, size_t size);
LINUX_SYSCALL_API ssize_t ue_flistxattr(int fd, char *list, size_t size);
LINUX_SYSCALL_API int     ue_removexattr(const char *path, const char *name);
LINUX_SYSCALL_API int     ue_lremovexattr(const char *path, const char *name);
LINUX_SYSCALL_API int     ue_fremovexattr(int fd, const char *name);
LINUX_SYSCALL_API int     ue_setxattrat(int dfd, const char *pathname, const char *name, const void *value, size_t size, int flags);
LINUX_SYSCALL_API ssize_t ue_getxattrat(int dfd, const char *pathname, const char *name, void *value, size_t size);
LINUX_SYSCALL_API ssize_t ue_listxattrat(int dfd, const char *pathname, char *list, size_t size);
LINUX_SYSCALL_API int     ue_removexattrat(int dfd, const char *pathname, const char *name);

/* --- Mount & VFS Namespaces --- */
LINUX_SYSCALL_API int     ue_mount(const char *source, const char *target, const char *filesystemtype, unsigned long mountflags, const void *data);
LINUX_SYSCALL_API int     ue_umount2(const char *target, int flags);
LINUX_SYSCALL_API int     ue_pivot_root(const char *new_root, const char *put_old);
LINUX_SYSCALL_API int     ue_swapon(const char *path, int swapflags);
LINUX_SYSCALL_API int     ue_swapoff(const char *path);
LINUX_SYSCALL_API int     ue_quotactl(int cmd, const char *special, int id, void *addr);
LINUX_SYSCALL_API int     ue_quotactl_fd(unsigned int fd, unsigned int cmd, int id, void *addr);
LINUX_SYSCALL_API int     ue_open_tree(int dfd, const char *filename, unsigned int flags);
LINUX_SYSCALL_API int     ue_move_mount(int from_dfd, const char *from_pathname, int to_dfd, const char *to_pathname, unsigned int flags);
LINUX_SYSCALL_API int     ue_fsopen(const char *fs_name, unsigned int flags);
LINUX_SYSCALL_API int     ue_fsconfig(int fd, unsigned int cmd, const char *key, const void *value, int aux);
LINUX_SYSCALL_API int     ue_fsmount(int fs_fd, unsigned int flags, unsigned int ms_flags);
LINUX_SYSCALL_API int     ue_fspick(int dfd, const char *path, unsigned int flags);
LINUX_SYSCALL_API int     ue_mount_setattr(int dfd, const char *path, unsigned int flags, struct ue_mount_attr *uattr, size_t usize);
LINUX_SYSCALL_API int     ue_statmount(int dfd, const char *pathname, struct ue_statmount *buf, size_t size, unsigned int flags);
LINUX_SYSCALL_API ssize_t ue_listmount(uint64_t *mnt_id, uint64_t *list, size_t num, unsigned int flags);
LINUX_SYSCALL_API int     ue_open_tree_attr(int dfd, const char *path, unsigned int flags, struct ue_open_how *how, size_t size);

/* --- Memory Management --- */
LINUX_SYSCALL_API void   *ue_mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);
LINUX_SYSCALL_API void   *ue_mmap2(void *addr, size_t length, int prot, int flags, int fd, off_t pgoffset);
LINUX_SYSCALL_API int     ue_mprotect(void *addr, size_t len, int prot);
LINUX_SYSCALL_API int     ue_munmap(void *addr, size_t length);
LINUX_SYSCALL_API void   *ue_mremap(void *old_address, size_t old_size, size_t new_size, int flags, void *new_address);
LINUX_SYSCALL_API int     ue_msync(void *addr, size_t length, int flags);
LINUX_SYSCALL_API int     ue_mincore(void *addr, size_t length, unsigned char *vec);
LINUX_SYSCALL_API int     ue_madvise(void *addr, size_t length, int advice);
LINUX_SYSCALL_API int     ue_mlock(const void *addr, size_t len);
LINUX_SYSCALL_API int     ue_munlock(const void *addr, size_t len);
LINUX_SYSCALL_API int     ue_mlockall(int flags);
LINUX_SYSCALL_API int     ue_munlockall(void);
LINUX_SYSCALL_API int     ue_mlock2(const void *addr, size_t len, unsigned int flags);
LINUX_SYSCALL_API int     ue_brk(void *addr);
LINUX_SYSCALL_API int     ue_memfd_create(const char *name, unsigned int flags);
LINUX_SYSCALL_API int     ue_memfd_secret(unsigned int flags);
LINUX_SYSCALL_API int     ue_pkey_mprotect(void *addr, size_t len, int prot, int pkey);
LINUX_SYSCALL_API int     ue_pkey_alloc(unsigned int flags, unsigned int access_rights);
LINUX_SYSCALL_API int     ue_pkey_free(int pkey);
LINUX_SYSCALL_API int     ue_mseal(void *addr, size_t len, unsigned int flags);
LINUX_SYSCALL_API unsigned long ue_map_shadow_stack(unsigned long addr, unsigned long len, unsigned int flags);

/* --- Process & Thread Lifecycle --- */
LINUX_SYSCALL_API pid_t   ue_fork(void);
LINUX_SYSCALL_API pid_t   ue_vfork(void);
LINUX_SYSCALL_API int     ue_clone(unsigned long flags, void *child_stack, void *ptid, void *ctid, unsigned long tls);
LINUX_SYSCALL_API int     ue_clone3(struct ue_clone_args *cl_args, size_t size);
LINUX_SYSCALL_API int     ue_execve(const char *pathname, char *const argv[], char *const envp[]);
LINUX_SYSCALL_API int     ue_execveat(int dirfd, const char *pathname, char *const argv[], char *const envp[], int flags);
LINUX_SYSCALL_API void    ue_exit(int status);
LINUX_SYSCALL_API void    ue_exit_group(int status);
LINUX_SYSCALL_API pid_t   ue_wait4(pid_t pid, int *wstatus, int options, struct ue_rusage *rusage);
LINUX_SYSCALL_API int     ue_waitid(ue_idtype_t idtype, id_t id, ue_siginfo_t *infop, int options);
LINUX_SYSCALL_API pid_t   ue_waitpid(pid_t pid, int *wstatus, int options);
LINUX_SYSCALL_API pid_t   ue_getpid(void);
LINUX_SYSCALL_API pid_t   ue_getppid(void);
LINUX_SYSCALL_API pid_t   ue_gettid(void);
LINUX_SYSCALL_API pid_t   ue_getpgid(pid_t pid);
LINUX_SYSCALL_API pid_t   ue_getpgrp(void);
LINUX_SYSCALL_API pid_t   ue_getsid(pid_t pid);
LINUX_SYSCALL_API int     ue_setpgid(pid_t pid, pid_t pgid);
LINUX_SYSCALL_API pid_t   ue_setsid(void);
LINUX_SYSCALL_API pid_t   ue_set_tid_address(int *tidptr);
LINUX_SYSCALL_API int     ue_prctl(int option, unsigned long arg2, unsigned long arg3, unsigned long arg4, unsigned long arg5);
LINUX_SYSCALL_API int     ue_arch_prctl(int code, unsigned long addr);
LINUX_SYSCALL_API int     ue_setns(int fd, int nstype);
LINUX_SYSCALL_API int     ue_unshare(int flags);
LINUX_SYSCALL_API int     ue_pidfd_open(pid_t pid, unsigned int flags);
LINUX_SYSCALL_API int     ue_pidfd_getfd(int pidfd, int targetfd, unsigned int flags);
LINUX_SYSCALL_API int     ue_pidfd_send_signal(int pidfd, int sig, ue_siginfo_t *info, unsigned int flags);
LINUX_SYSCALL_API int     ue_kcmp(pid_t pid1, pid_t pid2, int type, unsigned long idx1, unsigned long idx2);
LINUX_SYSCALL_API ssize_t ue_process_vm_readv(pid_t pid, const struct ue_iovec *local_iov, unsigned long liovcnt, const struct ue_iovec *remote_iov, unsigned long riovcnt, unsigned long flags);
LINUX_SYSCALL_API ssize_t ue_process_vm_writev(pid_t pid, const struct ue_iovec *local_iov, unsigned long liovcnt, const struct ue_iovec *remote_iov, unsigned long riovcnt, unsigned long flags);
LINUX_SYSCALL_API ssize_t ue_process_madvise(int pidfd, const struct ue_iovec *iovec, size_t vlen, int advice, unsigned int flags);

/* --- Credentials & Groups --- */
LINUX_SYSCALL_API uid_t   ue_getuid(void);
LINUX_SYSCALL_API gid_t   ue_getgid(void);
LINUX_SYSCALL_API uid_t   ue_geteuid(void);
LINUX_SYSCALL_API gid_t   ue_getegid(void);
LINUX_SYSCALL_API int     ue_setuid(uid_t uid);
LINUX_SYSCALL_API int     ue_setgid(gid_t gid);
LINUX_SYSCALL_API int     ue_setreuid(uid_t ruid, uid_t euid);
LINUX_SYSCALL_API int     ue_setregid(gid_t rgid, gid_t egid);
LINUX_SYSCALL_API int     ue_setresuid(uid_t ruid, uid_t euid, uid_t suid);
LINUX_SYSCALL_API int     ue_getresuid(uid_t *ruid, uid_t *euid, uid_t *suid);
LINUX_SYSCALL_API int     ue_setresgid(gid_t rgid, gid_t egid, gid_t sgid);
LINUX_SYSCALL_API int     ue_getresgid(gid_t *rgid, gid_t *egid, gid_t *sgid);
LINUX_SYSCALL_API int     ue_getgroups(int size, gid_t list[]);
LINUX_SYSCALL_API int     ue_setgroups(size_t size, const gid_t *list);
LINUX_SYSCALL_API int     ue_setfsuid(uid_t fsuid);
LINUX_SYSCALL_API int     ue_setfsgid(gid_t fsgid);
LINUX_SYSCALL_API int     ue_capget(cap_user_header_t hdrp, cap_user_data_t datap);
LINUX_SYSCALL_API int     ue_capset(cap_user_header_t hdrp, const cap_user_data_t datap);

/* --- Scheduling, Priority & Limits --- */
LINUX_SYSCALL_API int     ue_sched_yield(void);
LINUX_SYSCALL_API int     ue_sched_setparam(pid_t pid, const struct ue_sched_param *param);
LINUX_SYSCALL_API int     ue_sched_getparam(pid_t pid, struct ue_sched_param *param);
LINUX_SYSCALL_API int     ue_sched_setscheduler(pid_t pid, int policy, const struct ue_sched_param *param);
LINUX_SYSCALL_API int     ue_sched_getscheduler(pid_t pid);
LINUX_SYSCALL_API int     ue_sched_get_priority_max(int policy);
LINUX_SYSCALL_API int     ue_sched_get_priority_min(int policy);
LINUX_SYSCALL_API int     ue_sched_rr_get_interval(pid_t pid, struct ue_timespec *tp);
LINUX_SYSCALL_API int     ue_sched_setaffinity(pid_t pid, size_t cpusetsize, const ue_cpu_set_t *mask);
LINUX_SYSCALL_API int     ue_sched_getaffinity(pid_t pid, size_t cpusetsize, ue_cpu_set_t *mask);
LINUX_SYSCALL_API int     ue_sched_setattr(pid_t pid, struct ue_sched_attr *attr, unsigned int flags);
LINUX_SYSCALL_API int     ue_sched_getattr(pid_t pid, struct ue_sched_attr *attr, unsigned int size, unsigned int flags);
LINUX_SYSCALL_API int     ue_nice(int inc);
LINUX_SYSCALL_API int     ue_setpriority(int which, id_t who, int prio);
LINUX_SYSCALL_API int     ue_getpriority(int which, id_t who);
LINUX_SYSCALL_API int     ue_ioprio_set(int which, int who, int ioprio);
LINUX_SYSCALL_API int     ue_ioprio_get(int which, int who);
LINUX_SYSCALL_API int     ue_getrlimit(int resource, struct ue_rlimit *rlim);
LINUX_SYSCALL_API int     ue_setrlimit(int resource, const struct ue_rlimit *rlim);
LINUX_SYSCALL_API int     ue_prlimit64(pid_t pid, int resource, const struct ue_rlimit64 *new_limit, struct ue_rlimit64 *old_limit);
LINUX_SYSCALL_API int     ue_getrusage(int who, struct ue_rusage *usage);
LINUX_SYSCALL_API int     ue_rseq(struct ue_rseq *rseq, uint32_t rseq_len, int flags, uint32_t sig);
LINUX_SYSCALL_API int     ue_rseq_slice_yield(struct ue_rseq *rseq, unsigned int cpu_id, unsigned int flags);

/* --- Signals --- */
LINUX_SYSCALL_API int     ue_kill(pid_t pid, int sig);
LINUX_SYSCALL_API int     ue_tkill(pid_t tid, int sig);
LINUX_SYSCALL_API int     ue_tgkill(pid_t tgid, pid_t tid, int sig);
LINUX_SYSCALL_API int     ue_rt_sigaction(int signum, const struct ue_sigaction *act, struct ue_sigaction *oldact, size_t sigsetsize);
LINUX_SYSCALL_API int     ue_rt_sigprocmask(int how, const ue_sigset_t *set, ue_sigset_t *oldset, size_t sigsetsize);
LINUX_SYSCALL_API int     ue_rt_sigreturn(unsigned long __unused);
LINUX_SYSCALL_API int     ue_rt_sigpending(ue_sigset_t *set, size_t sigsetsize);
LINUX_SYSCALL_API int     ue_rt_sigtimedwait(const ue_sigset_t *set, ue_siginfo_t *info, const struct ue_timespec *timeout, size_t sigsetsize);
LINUX_SYSCALL_API int     ue_rt_sigqueueinfo(pid_t pid, int sig, ue_siginfo_t *info);
LINUX_SYSCALL_API int     ue_rt_tgsigqueueinfo(pid_t tgid, pid_t tid, int sig, ue_siginfo_t *info);
LINUX_SYSCALL_API int     ue_rt_sigsuspend(const ue_sigset_t *newset, size_t sigsetsize);
LINUX_SYSCALL_API int     ue_sigaltstack(const ue_stack_t *ss, ue_stack_t *old_ss);
LINUX_SYSCALL_API int     ue_signalfd(int fd, const ue_sigset_t *mask, int flags);
LINUX_SYSCALL_API int     ue_signalfd4(int fd, const ue_sigset_t *mask, size_t sizemask, int flags);
LINUX_SYSCALL_API int     ue_pause(void);
LINUX_SYSCALL_API unsigned int ue_alarm(unsigned int seconds);
LINUX_SYSCALL_API int     ue_restart_syscall(void);

/* --- Time & Clocks --- */
LINUX_SYSCALL_API int     ue_gettimeofday(struct ue_timeval *tv, struct ue_timezone *tz);
LINUX_SYSCALL_API int     ue_settimeofday(const struct ue_timeval *tv, const struct ue_timezone *tz);
LINUX_SYSCALL_API time_t  ue_time(time_t *tloc);
LINUX_SYSCALL_API clock_t ue_times(struct ue_tms *buf);
LINUX_SYSCALL_API int     ue_nanosleep(const struct ue_timespec *req, struct ue_timespec *rem);
LINUX_SYSCALL_API int     ue_clock_nanosleep(clockid_t clockid, int flags, const struct ue_timespec *request, struct ue_timespec *remain);
LINUX_SYSCALL_API int     ue_clock_settime(clockid_t clockid, const struct ue_timespec *tp);
LINUX_SYSCALL_API int     ue_clock_gettime(clockid_t clockid, struct ue_timespec *tp);
LINUX_SYSCALL_API int     ue_clock_getres(clockid_t clockid, struct ue_timespec *res);
LINUX_SYSCALL_API int     ue_clock_adjtime(clockid_t clk_id, struct ue_timex *buf);
LINUX_SYSCALL_API int     ue_adjtimex(struct ue_timex *buf);
LINUX_SYSCALL_API int     ue_timer_create(clockid_t clockid, struct ue_sigevent *sevp, ue_timer_t *timerid);
LINUX_SYSCALL_API int     ue_timer_settime(ue_timer_t timerid, int flags, const struct ue_itimerspec *new_value, struct ue_itimerspec *old_value);
LINUX_SYSCALL_API int     ue_timer_gettime(ue_timer_t timerid, struct ue_itimerspec *curr_value);
LINUX_SYSCALL_API int     ue_timer_getoverrun(ue_timer_t timerid);
LINUX_SYSCALL_API int     ue_timer_delete(ue_timer_t timerid);
LINUX_SYSCALL_API int     ue_getitimer(int which, struct ue_itimerval *curr_value);
LINUX_SYSCALL_API int     ue_setitimer(int which, const struct ue_itimerval *new_value, struct ue_itimerval *old_value);
LINUX_SYSCALL_API int     ue_timerfd_create(int clockid, int flags);
LINUX_SYSCALL_API int     ue_timerfd_settime(int fd, int flags, const struct ue_itimerspec *new_value, struct ue_itimerspec *old_value);
LINUX_SYSCALL_API int     ue_timerfd_gettime(int fd, struct ue_itimerspec *curr_value);
LINUX_SYSCALL_API int     ue_utime(const char *filename, const struct ue_utimbuf *times);
LINUX_SYSCALL_API int     ue_utimes(const char *filename, const struct ue_timeval times[2]);

/* --- Multiplexing & Polling --- */
LINUX_SYSCALL_API int     ue_poll(struct ue_pollfd *fds, nfds_t nfds, int timeout);
LINUX_SYSCALL_API int     ue_ppoll(struct ue_pollfd *fds, nfds_t nfds, const struct ue_timespec *tmo_p, const ue_sigset_t *sigmask);
LINUX_SYSCALL_API int     ue_select(int nfds, ue_fd_set *readfds, ue_fd_set *writefds, ue_fd_set *exceptfds, struct ue_timeval *timeout);
LINUX_SYSCALL_API int     ue_pselect(int nfds, ue_fd_set *readfds, ue_fd_set *writefds, ue_fd_set *exceptfds, const struct ue_timespec *timeout, const ue_sigset_t *sigmask);
LINUX_SYSCALL_API int     ue_epoll_create(int size);
LINUX_SYSCALL_API int     ue_epoll_create1(int flags);
LINUX_SYSCALL_API int     ue_epoll_ctl(int epfd, int op, int fd, struct ue_epoll_event *event);
LINUX_SYSCALL_API int     ue_epoll_wait(int epfd, struct ue_epoll_event *events, int maxevents, int timeout);
LINUX_SYSCALL_API int     ue_epoll_pwait(int epfd, struct ue_epoll_event *events, int maxevents, int timeout, const ue_sigset_t *sigmask);
LINUX_SYSCALL_API int     ue_epoll_pwait2(int epfd, struct ue_epoll_event *events, int maxevents, const struct ue_timespec *timeout, const ue_sigset_t *sigmask);
LINUX_SYSCALL_API int     ue_eventfd(unsigned int initval, int flags);
LINUX_SYSCALL_API int     ue_eventfd2(unsigned int initval, int flags);

/* --- Sockets & Networking --- */
LINUX_SYSCALL_API int     ue_socket(int domain, int type, int protocol);
LINUX_SYSCALL_API int     ue_socketpair(int domain, int type, int protocol, int sv[2]);
LINUX_SYSCALL_API int     ue_bind(int sockfd, const struct ue_sockaddr *addr, socklen_t addrlen);
LINUX_SYSCALL_API int     ue_listen(int sockfd, int backlog);
LINUX_SYSCALL_API int     ue_accept(int sockfd, struct ue_sockaddr *addr, socklen_t *addrlen);
LINUX_SYSCALL_API int     ue_accept4(int sockfd, struct ue_sockaddr *addr, socklen_t *addrlen, int flags);
LINUX_SYSCALL_API int     ue_connect(int sockfd, const struct ue_sockaddr *addr, socklen_t addrlen);
LINUX_SYSCALL_API int     ue_shutdown(int sockfd, int how);
LINUX_SYSCALL_API int     ue_getsockname(int sockfd, struct ue_sockaddr *addr, socklen_t *addrlen);
LINUX_SYSCALL_API int     ue_getpeername(int sockfd, struct ue_sockaddr *addr, socklen_t *addrlen);
LINUX_SYSCALL_API int     ue_setsockopt(int sockfd, int level, int optname, const void *optval, socklen_t optlen);
LINUX_SYSCALL_API int     ue_getsockopt(int sockfd, int level, int optname, void *optval, socklen_t *optlen);
LINUX_SYSCALL_API ssize_t ue_sendto(int sockfd, const void *buf, size_t len, int flags, const struct ue_sockaddr *dest_addr, socklen_t addrlen);
LINUX_SYSCALL_API ssize_t ue_recvfrom(int sockfd, void *buf, size_t len, int flags, struct ue_sockaddr *src_addr, socklen_t *addrlen);
LINUX_SYSCALL_API ssize_t ue_sendmsg(int sockfd, const struct ue_msghdr *msg, int flags);
LINUX_SYSCALL_API ssize_t ue_recvmsg(int sockfd, struct ue_msghdr *msg, int flags);
LINUX_SYSCALL_API int     ue_sendmmsg(int sockfd, struct ue_mmsghdr *msgvec, unsigned int vlen, int flags);
LINUX_SYSCALL_API int     ue_recvmmsg(int sockfd, struct ue_mmsghdr *msgvec, unsigned int vlen, int flags, struct ue_timespec *timeout);
LINUX_SYSCALL_API int     ue_socketcall(int call, unsigned long *args);

/* --- IPC & Futexes --- */
LINUX_SYSCALL_API int     ue_futex(int *uaddr, int futex_op, int val, const struct ue_timespec *timeout, int *uaddr2, int val3);
LINUX_SYSCALL_API int     ue_futex_waitv(struct ue_futex_waitv *waiters, unsigned int nr_futexes, unsigned int flags, struct ue_timespec *timeout, clockid_t clockid);
LINUX_SYSCALL_API int     ue_futex_wake(unsigned int *uaddr, unsigned int nr_wake, unsigned int mask, unsigned int flags);
LINUX_SYSCALL_API int     ue_futex_wait(unsigned int *uaddr, unsigned int val, unsigned int mask, unsigned int flags, struct ue_kernel_timespec *timeout, clockid_t clockid);
LINUX_SYSCALL_API int     ue_futex_requeue(unsigned int *uaddr, unsigned int nr_wake, unsigned int nr_requeue, unsigned int *uaddr2, unsigned int flags);
LINUX_SYSCALL_API int     ue_set_robust_list(struct ue_robust_list_head *head, size_t len);
LINUX_SYSCALL_API int     ue_get_robust_list(int pid, struct ue_robust_list_head **head_ptr, size_t *len_ptr);
LINUX_SYSCALL_API int     ue_shmget(key_t key, size_t size, int shmflg);
LINUX_SYSCALL_API void   *ue_shmat(int shmid, const void *shmaddr, int shmflg);
LINUX_SYSCALL_API int     ue_shmctl(int shmid, int cmd, struct ue_shmid_ds *buf);
LINUX_SYSCALL_API int     ue_shmdt(const void *shmaddr);
LINUX_SYSCALL_API int     ue_msgget(key_t key, int msgflg);
LINUX_SYSCALL_API int     ue_msgsnd(int msqid, const void *msgp, size_t msgsz, int msgflg);
LINUX_SYSCALL_API ssize_t ue_msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp, int msgflg);
LINUX_SYSCALL_API int     ue_msgctl(int msqid, int cmd, struct ue_msqid_ds *buf);
LINUX_SYSCALL_API int     ue_semget(key_t key, int nsems, int semflg);
LINUX_SYSCALL_API int     ue_semop(int semid, struct ue_sembuf *sops, size_t nsops);
LINUX_SYSCALL_API int     ue_semctl(int semid, int semnum, int cmd, unsigned long arg);
LINUX_SYSCALL_API int     ue_semtimedop(int semid, struct ue_sembuf *sops, size_t nsops, const struct ue_timespec *timeout);
LINUX_SYSCALL_API int     ue_ipc(unsigned int call, int first, unsigned long second, unsigned long third, void *ptr, long fifth);
LINUX_SYSCALL_API mqd_t   ue_mq_open(const char *name, int oflag, mode_t mode, struct ue_mq_attr *attr);
LINUX_SYSCALL_API int     ue_mq_unlink(const char *name);
LINUX_SYSCALL_API int     ue_mq_timedsend(mqd_t mqdes, const char *msg_ptr, size_t msg_len, unsigned int msg_prio, const struct ue_timespec *abs_timeout);
LINUX_SYSCALL_API ssize_t ue_mq_timedreceive(mqd_t mqdes, char *msg_ptr, size_t msg_len, unsigned int *msg_prio, const struct ue_timespec *abs_timeout);
LINUX_SYSCALL_API int     ue_mq_notify(mqd_t mqdes, const struct ue_sigevent *sevp);
LINUX_SYSCALL_API int     ue_mq_getsetattr(mqd_t mqdes, const struct ue_mq_attr *newattr, struct ue_mq_attr *oldattr);

/* --- Asynchronous I/O & io_uring --- */
LINUX_SYSCALL_API int     ue_io_setup(unsigned int nr_events, aio_context_t *ctx_idp);
LINUX_SYSCALL_API int     ue_io_destroy(aio_context_t ctx_id);
LINUX_SYSCALL_API int     ue_io_submit(aio_context_t ctx_id, long nr, struct ue_iocb **iocbpp);
LINUX_SYSCALL_API int     ue_io_cancel(aio_context_t ctx_id, struct ue_iocb *iocb, struct ue_io_event *result);
LINUX_SYSCALL_API int     ue_io_getevents(aio_context_t ctx_id, long min_nr, long nr, struct ue_io_event *events, struct ue_timespec *timeout);
LINUX_SYSCALL_API int     ue_io_pgetevents(aio_context_t ctx_id, long min_nr, long nr, struct ue_io_event *events, struct ue_timespec *timeout, const ue_sigset_t *sigmask);
LINUX_SYSCALL_API int     ue_io_uring_setup(unsigned int entries, struct ue_io_uring_params *p);
LINUX_SYSCALL_API int     ue_io_uring_enter(unsigned int fd, unsigned int to_submit, unsigned int min_complete, unsigned int flags, ue_sigset_t *sig);
LINUX_SYSCALL_API int     ue_io_uring_register(unsigned int fd, unsigned int opcode, void *arg, unsigned int nr_args);

/* --- Inotify, Fanotify & Monitoring --- */
LINUX_SYSCALL_API int     ue_inotify_init(void);
LINUX_SYSCALL_API int     ue_inotify_init1(int flags);
LINUX_SYSCALL_API int     ue_inotify_add_watch(int fd, const char *pathname, uint32_t mask);
LINUX_SYSCALL_API int     ue_inotify_rm_watch(int fd, int wd);
LINUX_SYSCALL_API int     ue_fanotify_init(unsigned int flags, unsigned int event_f_flags);
LINUX_SYSCALL_API int     ue_fanotify_mark(int fanotify_fd, unsigned int flags, uint64_t mask, int dirfd, const char *pathname);

/* --- System Information, Modules & Security --- */
LINUX_SYSCALL_API int          ue_uname(struct ue_utsname *buf);
LINUX_SYSCALL_API int          ue_sysinfo(struct ue_sysinfo *info);
LINUX_SYSCALL_API int          ue_syslog(int type, char *bufp, int len);
LINUX_SYSCALL_API int          ue_reboot(int magic, int magic2, int cmd, void *arg);
LINUX_SYSCALL_API int          ue_vhangup(void);
LINUX_SYSCALL_API int          ue_acct(const char *filename);
LINUX_SYSCALL_API int          ue_personality(unsigned long persona);
LINUX_SYSCALL_API int          ue_sethostname(const char *name, size_t len);
LINUX_SYSCALL_API int          ue_setdomainname(const char *name, size_t len);
LINUX_SYSCALL_API int          ue_iopl(int level);
LINUX_SYSCALL_API int          ue_ioperm(unsigned long from, unsigned long num, int turn_on);
LINUX_SYSCALL_API int          ue_init_module(void *module_image, unsigned long len, const char *param_values);
LINUX_SYSCALL_API int          ue_finit_module(int fd, const char *param_values, int flags);
LINUX_SYSCALL_API int          ue_delete_module(const char *name, int flags);
LINUX_SYSCALL_API int          ue_bpf(int cmd, union ue_bpf_attr *attr, unsigned int size);
LINUX_SYSCALL_API int          ue_userfaultfd(int flags);
LINUX_SYSCALL_API int          ue_membarrier(int cmd, unsigned int flags, int cpu_id);
LINUX_SYSCALL_API key_serial_t ue_add_key(const char *type, const char *description, const void *payload, size_t plen, key_serial_t keyring);
LINUX_SYSCALL_API key_serial_t ue_request_key(const char *type, const char *description, const char *callout_info, key_serial_t dest_keyring);
LINUX_SYSCALL_API long         ue_keyctl(int operation, unsigned long arg2, unsigned long arg3, unsigned long arg4, unsigned long arg5);
LINUX_SYSCALL_API int          ue_seccomp(unsigned int operation, unsigned int flags, void *args);
LINUX_SYSCALL_API int          ue_landlock_restrict_self(int ruleset_fd, uint32_t flags);
LINUX_SYSCALL_API int          ue_lsm_list_modules(uint64_t *ids, size_t *size, uint32_t flags);
LINUX_SYSCALL_API ssize_t      ue_getrandom(void *buf, size_t buflen, unsigned int flags);
LINUX_SYSCALL_API long         ue_ptrace(int request, pid_t pid, void *addr, void *data);
LINUX_SYSCALL_API int          ue_perf_event_open(struct ue_perf_event_attr *attr, pid_t pid, int cpu, int group_fd, unsigned long flags);
LINUX_SYSCALL_API int          ue_getcpu(unsigned int *cpu, unsigned int *node, struct ue_getcpu_cache *tcache);
LINUX_SYSCALL_API int          ue_cachestat(unsigned int fd, struct ue_cachestat_range *crange, struct ue_cachestat *cstat, unsigned int flags);
LINUX_SYSCALL_API int          ue_file_getattr(int fd, unsigned int mask, struct ue_file_handle *handle, size_t *handle_bytes);
LINUX_SYSCALL_API int          ue_file_setattr(int fd, unsigned int mask, struct ue_file_handle *handle, size_t handle_bytes);
LINUX_SYSCALL_API int          ue_listns(int nstype, struct ue_namespace_entry *entries, unsigned int max_entries, unsigned int flags);

#ifdef __cplusplus
}
#endif


#endif /* _LINUX_H */
