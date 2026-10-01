/*
 * linux_impl.h
 *
 * Raw Linux syscall implementations matching linux.h.
 * Include this file AFTER defining:
 *   - raw_syscall(long num, ...)
 *   - SYS_* constants (for example from <asm/unistd.h>)
 *
 * No libc implementation is used here.
 */

#ifndef _LINUX_IMPL_H
#define _LINUX_IMPL_H

#include "linux.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef SYS_read
LINUX_SYSCALL_API ssize_t read(int fd, void *buf, size_t count)
{
    return (ssize_t)raw_syscall(SYS_read, fd, buf, count);
}
#endif

#ifdef SYS_write
LINUX_SYSCALL_API ssize_t write(int fd, const void *buf, size_t count)
{
    return (ssize_t)raw_syscall(SYS_write, fd, buf, count);
}
#endif

#ifdef SYS_open
LINUX_SYSCALL_API int open(const char *pathname, int flags, mode_t mode)
{
    return (int)raw_syscall(SYS_open, pathname, flags, mode);
}
#endif

#ifdef SYS_openat
LINUX_SYSCALL_API int openat(int dirfd, const char *pathname, int flags, mode_t mode)
{
    return (int)raw_syscall(SYS_openat, dirfd, pathname, flags, mode);
}
#endif

#ifdef SYS_openat2
LINUX_SYSCALL_API int openat2(int dirfd, const char *pathname, struct open_how *how, size_t size)
{
    return (int)raw_syscall(SYS_openat2, dirfd, pathname, how, size);
}
#endif

#ifdef SYS_creat
LINUX_SYSCALL_API int creat(const char *pathname, mode_t mode)
{
    return (int)raw_syscall(SYS_creat, pathname, mode);
}
#endif

#ifdef SYS_close
LINUX_SYSCALL_API int close(int fd)
{
    return (int)raw_syscall(SYS_close, fd);
}
#endif

#ifdef SYS_close_range
LINUX_SYSCALL_API int close_range(unsigned int fd, unsigned int max_fd, unsigned int flags)
{
    return (int)raw_syscall(SYS_close_range, fd, max_fd, flags);
}
#endif

#ifdef SYS_lseek
LINUX_SYSCALL_API off_t lseek(int fd, off_t offset, int whence)
{
    return (off_t)raw_syscall(SYS_lseek, fd, offset, whence);
}
#endif

#ifdef SYS_pread64
LINUX_SYSCALL_API ssize_t pread(int fd, void *buf, size_t count, off_t offset)
{
    return (ssize_t)raw_syscall(SYS_pread64, fd, buf, count, offset);
}
#endif

#ifdef SYS_pwrite64
LINUX_SYSCALL_API ssize_t pwrite(int fd, const void *buf, size_t count, off_t offset)
{
    return (ssize_t)raw_syscall(SYS_pwrite64, fd, buf, count, offset);
}
#endif

#ifdef SYS_pread64
LINUX_SYSCALL_API ssize_t pread64(int fd, void *buf, size_t count, off_t offset)
{
    return (ssize_t)raw_syscall(SYS_pread64, fd, buf, count, offset);
}
#endif

#ifdef SYS_pwrite64
LINUX_SYSCALL_API ssize_t pwrite64(int fd, const void *buf, size_t count, off_t offset)
{
    return (ssize_t)raw_syscall(SYS_pwrite64, fd, buf, count, offset);
}
#endif

#ifdef SYS_readv
LINUX_SYSCALL_API ssize_t readv(int fd, const struct iovec *iov, int iovcnt)
{
    return (ssize_t)raw_syscall(SYS_readv, fd, iov, iovcnt);
}
#endif

#ifdef SYS_writev
LINUX_SYSCALL_API ssize_t writev(int fd, const struct iovec *iov, int iovcnt)
{
    return (ssize_t)raw_syscall(SYS_writev, fd, iov, iovcnt);
}
#endif

#ifdef SYS_preadv
LINUX_SYSCALL_API ssize_t preadv(int fd, const struct iovec *iov, int iovcnt, off_t offset)
{
    return (ssize_t)raw_syscall(SYS_preadv, fd, iov, iovcnt, offset);
}
#endif

#ifdef SYS_pwritev
LINUX_SYSCALL_API ssize_t pwritev(int fd, const struct iovec *iov, int iovcnt, off_t offset)
{
    return (ssize_t)raw_syscall(SYS_pwritev, fd, iov, iovcnt, offset);
}
#endif

#ifdef SYS_preadv2
LINUX_SYSCALL_API ssize_t preadv2(int fd, const struct iovec *iov, int iovcnt, off_t offset, int flags)
{
    return (ssize_t)raw_syscall(SYS_preadv2, fd, iov, iovcnt, offset, flags);
}
#endif

#ifdef SYS_pwritev2
LINUX_SYSCALL_API ssize_t pwritev2(int fd, const struct iovec *iov, int iovcnt, off_t offset, int flags)
{
    return (ssize_t)raw_syscall(SYS_pwritev2, fd, iov, iovcnt, offset, flags);
}
#endif

#ifdef SYS_pipe
LINUX_SYSCALL_API int pipe(int pipefd[2])
{
    return (int)raw_syscall(SYS_pipe, pipefd);
}
#endif

#ifdef SYS_pipe2
LINUX_SYSCALL_API int pipe2(int pipefd[2], int flags)
{
    return (int)raw_syscall(SYS_pipe2, pipefd, flags);
}
#endif

#ifdef SYS_dup
LINUX_SYSCALL_API int dup(int oldfd)
{
    return (int)raw_syscall(SYS_dup, oldfd);
}
#endif

#if defined(SYS_dup2)
LINUX_SYSCALL_API int dup2(int oldfd, int newfd)
{
    return (int)raw_syscall(SYS_dup2, oldfd, newfd);
}
#elif defined(SYS_dup3)
LINUX_SYSCALL_API int dup2(int oldfd, int newfd)
{
    if (oldfd == newfd) return newfd;
    return (int)raw_syscall(SYS_dup3, oldfd, newfd, 0);
}
#endif

#ifdef SYS_dup3
LINUX_SYSCALL_API int dup3(int oldfd, int newfd, int flags)
{
    return (int)raw_syscall(SYS_dup3, oldfd, newfd, flags);
}
#endif

#ifdef SYS_flock
LINUX_SYSCALL_API int flock(int fd, int operation)
{
    return (int)raw_syscall(SYS_flock, fd, operation);
}
#endif

#ifdef SYS_fsync
LINUX_SYSCALL_API int fsync(int fd)
{
    return (int)raw_syscall(SYS_fsync, fd);
}
#endif

#ifdef SYS_fdatasync
LINUX_SYSCALL_API int fdatasync(int fd)
{
    return (int)raw_syscall(SYS_fdatasync, fd);
}
#endif

#ifdef SYS_sync
LINUX_SYSCALL_API void sync(void)
{
    raw_syscall(SYS_sync);
}
#endif

#ifdef SYS_syncfs
LINUX_SYSCALL_API int syncfs(int fd)
{
    return (int)raw_syscall(SYS_syncfs, fd);
}
#endif

#ifdef SYS_sync_file_range
LINUX_SYSCALL_API int sync_file_range(int fd, off_t offset, off_t nbytes, unsigned int flags)
{
    return (int)raw_syscall(SYS_sync_file_range, fd, offset, nbytes, flags);
}
#endif

#ifdef SYS_fallocate
LINUX_SYSCALL_API int fallocate(int fd, int mode, off_t offset, off_t len)
{
    return (int)raw_syscall(SYS_fallocate, fd, mode, offset, len);
}
#endif

#ifdef SYS_readahead
LINUX_SYSCALL_API ssize_t readahead(int fd, off_t offset, size_t count)
{
    return (ssize_t)raw_syscall(SYS_readahead, fd, offset, count);
}
#endif

#ifdef SYS_sendfile
LINUX_SYSCALL_API ssize_t sendfile(int out_fd, int in_fd, off_t *offset, size_t count)
{
    return (ssize_t)raw_syscall(SYS_sendfile, out_fd, in_fd, offset, count);
}
#endif

#ifdef SYS_copy_file_range
LINUX_SYSCALL_API ssize_t copy_file_range(int fd_in, off_t *off_in, int fd_out, off_t *off_out, size_t len, unsigned int flags)
{
    return (ssize_t)raw_syscall(SYS_copy_file_range, fd_in, off_in, fd_out, off_out, len, flags);
}
#endif

#ifdef SYS_splice
LINUX_SYSCALL_API ssize_t splice(int fd_in, off_t *off_in, int fd_out, off_t *off_out, size_t len, unsigned int flags)
{
    return (ssize_t)raw_syscall(SYS_splice, fd_in, off_in, fd_out, off_out, len, flags);
}
#endif

#ifdef SYS_tee
LINUX_SYSCALL_API ssize_t tee(int fd_in, int fd_out, size_t len, unsigned int flags)
{
    return (ssize_t)raw_syscall(SYS_tee, fd_in, fd_out, len, flags);
}
#endif

#ifdef SYS_vmsplice
LINUX_SYSCALL_API ssize_t vmsplice(int fd, const struct iovec *iov, size_t nr_segs, unsigned int flags)
{
    return (ssize_t)raw_syscall(SYS_vmsplice, fd, iov, nr_segs, flags);
}
#endif

#ifdef SYS_fcntl
LINUX_SYSCALL_API int fcntl(int fd, int cmd, ...)
{
    /* fcntl() has an optional third syscall argument. */
    __builtin_va_list ap;
    unsigned long arg = 0;
    __builtin_va_start(ap, cmd);
    arg = __builtin_va_arg(ap, unsigned long);
    __builtin_va_end(ap);
    return (int)raw_syscall(SYS_fcntl, fd, cmd, arg);
}
#endif

#ifdef SYS_ioctl
LINUX_SYSCALL_API int ioctl_raw(unsigned long fd, unsigned long request, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4)
{
    return (int)raw_syscall(SYS_ioctl, fd, request, arg1, arg2, arg3, arg4);
}
#endif

#ifdef SYS_stat
LINUX_SYSCALL_API int stat(const char *pathname, struct stat *statbuf)
{
    return (int)raw_syscall(SYS_stat, pathname, statbuf);
}
#endif

#ifdef SYS_fstat
LINUX_SYSCALL_API int fstat(int fd, struct stat *statbuf)
{
    return (int)raw_syscall(SYS_fstat, fd, statbuf);
}
#endif

#ifdef SYS_lstat
LINUX_SYSCALL_API int lstat(const char *pathname, struct stat *statbuf)
{
    return (int)raw_syscall(SYS_lstat, pathname, statbuf);
}
#endif

#ifdef SYS_newfstatat
LINUX_SYSCALL_API int fstatat(int dirfd, const char *pathname, struct stat *statbuf, int flags)
{
    return (int)raw_syscall(SYS_newfstatat, dirfd, pathname, statbuf, flags);
}
#endif

#ifdef SYS_fstatat64
LINUX_SYSCALL_API int fstatat64(int dirfd, const char *pathname, struct stat64 *statbuf, int flags)
{
    return (int)raw_syscall(SYS_fstatat64, dirfd, pathname, statbuf, flags);
}
#endif

#ifdef SYS_statx
LINUX_SYSCALL_API int statx(int dirfd, const char *pathname, int flags, unsigned int mask, struct statx *statxbuf)
{
    return (int)raw_syscall(SYS_statx, dirfd, pathname, flags, mask, statxbuf);
}
#endif

#ifdef SYS_statfs
LINUX_SYSCALL_API int statfs(const char *path, struct statfs *buf)
{
    return (int)raw_syscall(SYS_statfs, path, buf);
}
#endif

#ifdef SYS_fstatfs
LINUX_SYSCALL_API int fstatfs(int fd, struct statfs *buf)
{
    return (int)raw_syscall(SYS_fstatfs, fd, buf);
}
#endif

#ifdef SYS_statfs64
LINUX_SYSCALL_API int statfs64(const char *path, size_t sz, struct statfs64 *buf)
{
    return (int)raw_syscall(SYS_statfs64, path, sz, buf);
}
#endif

#ifdef SYS_fstatfs64
LINUX_SYSCALL_API int fstatfs64(int fd, size_t sz, struct statfs64 *buf)
{
    return (int)raw_syscall(SYS_fstatfs64, fd, sz, buf);
}
#endif

#ifdef SYS_access
LINUX_SYSCALL_API int access(const char *pathname, int mode)
{
    return (int)raw_syscall(SYS_access, pathname, mode);
}
#endif

#ifdef SYS_faccessat2
LINUX_SYSCALL_API int faccessat2(int dirfd, const char *pathname, int mode, int flags)
{
    return (int)raw_syscall(SYS_faccessat2, dirfd, pathname, mode, flags);
}
#endif

#ifdef SYS_truncate
LINUX_SYSCALL_API int truncate(const char *path, off_t length)
{
    return (int)raw_syscall(SYS_truncate, path, length);
}
#endif

#ifdef SYS_ftruncate
LINUX_SYSCALL_API int ftruncate(int fd, off_t length)
{
    return (int)raw_syscall(SYS_ftruncate, fd, length);
}
#endif

#ifdef SYS_truncate64
LINUX_SYSCALL_API int truncate64(const char *path, off64_t length)
{
    return (int)raw_syscall(SYS_truncate64, path, length);
}
#endif

#ifdef SYS_ftruncate64
LINUX_SYSCALL_API int ftruncate64(int fd, off64_t length)
{
    return (int)raw_syscall(SYS_ftruncate64, fd, length);
}
#endif

#ifdef SYS_chdir
LINUX_SYSCALL_API int chdir(const char *path)
{
    return (int)raw_syscall(SYS_chdir, path);
}
#endif

#ifdef SYS_fchdir
LINUX_SYSCALL_API int fchdir(int fd)
{
    return (int)raw_syscall(SYS_fchdir, fd);
}
#endif

#ifdef SYS_getcwd
LINUX_SYSCALL_API char *getcwd(char *buf, size_t size)
{
    long r = raw_syscall(SYS_getcwd, buf, size);
    return r < 0 ? (char *)0 : buf;
}
#endif

#ifdef SYS_rename
LINUX_SYSCALL_API int rename(const char *oldpath, const char *newpath)
{
    return (int)raw_syscall(SYS_rename, oldpath, newpath);
}
#endif

#ifdef SYS_renameat
LINUX_SYSCALL_API int renameat(int olddirfd, const char *oldpath, int newdirfd, const char *newpath)
{
    return (int)raw_syscall(SYS_renameat, olddirfd, oldpath, newdirfd, newpath);
}
#endif

#ifdef SYS_renameat2
LINUX_SYSCALL_API int renameat2(int olddirfd, const char *oldpath, int newdirfd, const char *newpath, unsigned int flags)
{
    return (int)raw_syscall(SYS_renameat2, olddirfd, oldpath, newdirfd, newpath, flags);
}
#endif

#ifdef SYS_mkdir
LINUX_SYSCALL_API int mkdir(const char *pathname, mode_t mode)
{
    return (int)raw_syscall(SYS_mkdir, pathname, mode);
}
#endif

#ifdef SYS_mkdirat
LINUX_SYSCALL_API int mkdirat(int dirfd, const char *pathname, mode_t mode)
{
    return (int)raw_syscall(SYS_mkdirat, dirfd, pathname, mode);
}
#endif

#ifdef SYS_rmdir
LINUX_SYSCALL_API int rmdir(const char *pathname)
{
    return (int)raw_syscall(SYS_rmdir, pathname);
}
#endif

#ifdef SYS_link
LINUX_SYSCALL_API int link(const char *oldpath, const char *newpath)
{
    return (int)raw_syscall(SYS_link, oldpath, newpath);
}
#endif

#ifdef SYS_linkat
LINUX_SYSCALL_API int linkat(int olddirfd, const char *oldpath, int newdirfd, const char *newpath, int flags)
{
    return (int)raw_syscall(SYS_linkat, olddirfd, oldpath, newdirfd, newpath, flags);
}
#endif

#ifdef SYS_unlink
LINUX_SYSCALL_API int unlink(const char *pathname)
{
    return (int)raw_syscall(SYS_unlink, pathname);
}
#endif

#ifdef SYS_unlinkat
LINUX_SYSCALL_API int unlinkat(int dirfd, const char *pathname, int flags)
{
    return (int)raw_syscall(SYS_unlinkat, dirfd, pathname, flags);
}
#endif

#ifdef SYS_symlink
LINUX_SYSCALL_API int symlink(const char *target, const char *linkpath)
{
    return (int)raw_syscall(SYS_symlink, target, linkpath);
}
#endif

#ifdef SYS_symlinkat
LINUX_SYSCALL_API int symlinkat(const char *target, int newdirfd, const char *linkpath)
{
    return (int)raw_syscall(SYS_symlinkat, target, newdirfd, linkpath);
}
#endif

#ifdef SYS_readlink
LINUX_SYSCALL_API ssize_t readlink(const char *pathname, char *buf, size_t bufsiz)
{
    return (ssize_t)raw_syscall(SYS_readlink, pathname, buf, bufsiz);
}
#endif

#ifdef SYS_readlinkat
LINUX_SYSCALL_API ssize_t readlinkat(int dirfd, const char *pathname, char *buf, size_t bufsiz)
{
    return (ssize_t)raw_syscall(SYS_readlinkat, dirfd, pathname, buf, bufsiz);
}
#endif

#ifdef SYS_chmod
LINUX_SYSCALL_API int chmod(const char *pathname, mode_t mode)
{
    return (int)raw_syscall(SYS_chmod, pathname, mode);
}
#endif

#ifdef SYS_fchmod
LINUX_SYSCALL_API int fchmod(int fd, mode_t mode)
{
    return (int)raw_syscall(SYS_fchmod, fd, mode);
}
#endif

#ifdef SYS_fchmodat
LINUX_SYSCALL_API int fchmodat(int dirfd, const char *pathname, mode_t mode, int flags)
{
    return (int)raw_syscall(SYS_fchmodat, dirfd, pathname, mode, flags);
}
#endif

#ifdef SYS_fchmodat2
LINUX_SYSCALL_API int fchmodat2(int dfd, const char *filename, mode_t mode, unsigned int flags)
{
    return (int)raw_syscall(SYS_fchmodat2, dfd, filename, mode, flags);
}
#endif

#ifdef SYS_chown
LINUX_SYSCALL_API int chown(const char *pathname, uid_t owner, gid_t group)
{
    return (int)raw_syscall(SYS_chown, pathname, owner, group);
}
#endif

#ifdef SYS_fchown
LINUX_SYSCALL_API int fchown(int fd, uid_t owner, gid_t group)
{
    return (int)raw_syscall(SYS_fchown, fd, owner, group);
}
#endif

#ifdef SYS_lchown
LINUX_SYSCALL_API int lchown(const char *pathname, uid_t owner, gid_t group)
{
    return (int)raw_syscall(SYS_lchown, pathname, owner, group);
}
#endif

#ifdef SYS_fchownat
LINUX_SYSCALL_API int fchownat(int dirfd, const char *pathname, uid_t owner, gid_t group, int flags)
{
    return (int)raw_syscall(SYS_fchownat, dirfd, pathname, owner, group, flags);
}
#endif

#ifdef SYS_umask
LINUX_SYSCALL_API mode_t umask(mode_t mask)
{
    return (mode_t)raw_syscall(SYS_umask, mask);
}
#endif

#ifdef SYS_chroot
LINUX_SYSCALL_API int chroot(const char *path)
{
    return (int)raw_syscall(SYS_chroot, path);
}
#endif

#ifdef SYS_mknod
LINUX_SYSCALL_API int mknod(const char *pathname, mode_t mode, dev_t dev)
{
    return (int)raw_syscall(SYS_mknod, pathname, mode, dev);
}
#endif

#ifdef SYS_mknodat
LINUX_SYSCALL_API int mknodat(int dirfd, const char *pathname, mode_t mode, dev_t dev)
{
    return (int)raw_syscall(SYS_mknodat, dirfd, pathname, mode, dev);
}
#endif

#ifdef SYS_getdents
LINUX_SYSCALL_API int getdents(unsigned int fd, struct linux_dirent *dirp, unsigned int count)
{
    return (int)raw_syscall(SYS_getdents, fd, dirp, count);
}
#endif

#ifdef SYS_getdents64
LINUX_SYSCALL_API int getdents64(unsigned int fd, struct linux_dirent64 *dirp, unsigned int count)
{
    return (int)raw_syscall(SYS_getdents64, fd, dirp, count);
}
#endif

#ifdef SYS_lookup_dcookie
LINUX_SYSCALL_API int lookup_dcookie(uint64_t cookie64, char *buf, size_t len)
{
    return (int)raw_syscall(SYS_lookup_dcookie, cookie64, buf, len);
}
#endif

#ifdef SYS_setxattr
LINUX_SYSCALL_API int setxattr(const char *path, const char *name, const void *value, size_t size, int flags)
{
    return (int)raw_syscall(SYS_setxattr, path, name, value, size, flags);
}
#endif

#ifdef SYS_lsetxattr
LINUX_SYSCALL_API int lsetxattr(const char *path, const char *name, const void *value, size_t size, int flags)
{
    return (int)raw_syscall(SYS_lsetxattr, path, name, value, size, flags);
}
#endif

#ifdef SYS_fsetxattr
LINUX_SYSCALL_API int fsetxattr(int fd, const char *name, const void *value, size_t size, int flags)
{
    return (int)raw_syscall(SYS_fsetxattr, fd, name, value, size, flags);
}
#endif

#ifdef SYS_getxattr
LINUX_SYSCALL_API ssize_t getxattr(const char *path, const char *name, void *value, size_t size)
{
    return (ssize_t)raw_syscall(SYS_getxattr, path, name, value, size);
}
#endif

#ifdef SYS_lgetxattr
LINUX_SYSCALL_API ssize_t lgetxattr(const char *path, const char *name, void *value, size_t size)
{
    return (ssize_t)raw_syscall(SYS_lgetxattr, path, name, value, size);
}
#endif

#ifdef SYS_fgetxattr
LINUX_SYSCALL_API ssize_t fgetxattr(int fd, const char *name, void *value, size_t size)
{
    return (ssize_t)raw_syscall(SYS_fgetxattr, fd, name, value, size);
}
#endif

#ifdef SYS_listxattr
LINUX_SYSCALL_API ssize_t listxattr(const char *path, char *list, size_t size)
{
    return (ssize_t)raw_syscall(SYS_listxattr, path, list, size);
}
#endif

#ifdef SYS_llistxattr
LINUX_SYSCALL_API ssize_t llistxattr(const char *path, char *list, size_t size)
{
    return (ssize_t)raw_syscall(SYS_llistxattr, path, list, size);
}
#endif

#ifdef SYS_flistxattr
LINUX_SYSCALL_API ssize_t flistxattr(int fd, char *list, size_t size)
{
    return (ssize_t)raw_syscall(SYS_flistxattr, fd, list, size);
}
#endif

#ifdef SYS_removexattr
LINUX_SYSCALL_API int removexattr(const char *path, const char *name)
{
    return (int)raw_syscall(SYS_removexattr, path, name);
}
#endif

#ifdef SYS_lremovexattr
LINUX_SYSCALL_API int lremovexattr(const char *path, const char *name)
{
    return (int)raw_syscall(SYS_lremovexattr, path, name);
}
#endif

#ifdef SYS_fremovexattr
LINUX_SYSCALL_API int fremovexattr(int fd, const char *name)
{
    return (int)raw_syscall(SYS_fremovexattr, fd, name);
}
#endif

#ifdef SYS_setxattrat
LINUX_SYSCALL_API int setxattrat(int dfd, const char *pathname, const char *name, const void *value, size_t size, int flags)
{
    return (int)raw_syscall(SYS_setxattrat, dfd, pathname, name, value, size, flags);
}
#endif

#ifdef SYS_getxattrat
LINUX_SYSCALL_API ssize_t getxattrat(int dfd, const char *pathname, const char *name, void *value, size_t size)
{
    return (ssize_t)raw_syscall(SYS_getxattrat, dfd, pathname, name, value, size);
}
#endif

#ifdef SYS_listxattrat
LINUX_SYSCALL_API ssize_t listxattrat(int dfd, const char *pathname, char *list, size_t size)
{
    return (ssize_t)raw_syscall(SYS_listxattrat, dfd, pathname, list, size);
}
#endif

#ifdef SYS_removexattrat
LINUX_SYSCALL_API int removexattrat(int dfd, const char *pathname, const char *name)
{
    return (int)raw_syscall(SYS_removexattrat, dfd, pathname, name);
}
#endif

#ifdef SYS_mount
LINUX_SYSCALL_API int mount(const char *source, const char *target, const char *filesystemtype, unsigned long mountflags, const void *data)
{
    return (int)raw_syscall(SYS_mount, source, target, filesystemtype, mountflags, data);
}
#endif

#ifdef SYS_umount2
LINUX_SYSCALL_API int umount2(const char *target, int flags)
{
    return (int)raw_syscall(SYS_umount2, target, flags);
}
#endif

#ifdef SYS_pivot_root
LINUX_SYSCALL_API int pivot_root(const char *new_root, const char *put_old)
{
    return (int)raw_syscall(SYS_pivot_root, new_root, put_old);
}
#endif

#ifdef SYS_swapon
LINUX_SYSCALL_API int swapon(const char *path, int swapflags)
{
    return (int)raw_syscall(SYS_swapon, path, swapflags);
}
#endif

#ifdef SYS_swapoff
LINUX_SYSCALL_API int swapoff(const char *path)
{
    return (int)raw_syscall(SYS_swapoff, path);
}
#endif

#ifdef SYS_quotactl
LINUX_SYSCALL_API int quotactl(int cmd, const char *special, int id, void *addr)
{
    return (int)raw_syscall(SYS_quotactl, cmd, special, id, addr);
}
#endif

#ifdef SYS_quotactl_fd
LINUX_SYSCALL_API int quotactl_fd(unsigned int fd, unsigned int cmd, int id, void *addr)
{
    return (int)raw_syscall(SYS_quotactl_fd, fd, cmd, id, addr);
}
#endif

#ifdef SYS_open_tree
LINUX_SYSCALL_API int open_tree(int dfd, const char *filename, unsigned int flags)
{
    return (int)raw_syscall(SYS_open_tree, dfd, filename, flags);
}
#endif

#ifdef SYS_move_mount
LINUX_SYSCALL_API int move_mount(int from_dfd, const char *from_pathname, int to_dfd, const char *to_pathname, unsigned int flags)
{
    return (int)raw_syscall(SYS_move_mount, from_dfd, from_pathname, to_dfd, to_pathname, flags);
}
#endif

#ifdef SYS_fsopen
LINUX_SYSCALL_API int fsopen(const char *fs_name, unsigned int flags)
{
    return (int)raw_syscall(SYS_fsopen, fs_name, flags);
}
#endif

#ifdef SYS_fsconfig
LINUX_SYSCALL_API int fsconfig(int fd, unsigned int cmd, const char *key, const void *value, int aux)
{
    return (int)raw_syscall(SYS_fsconfig, fd, cmd, key, value, aux);
}
#endif

#ifdef SYS_fsmount
LINUX_SYSCALL_API int fsmount(int fs_fd, unsigned int flags, unsigned int ms_flags)
{
    return (int)raw_syscall(SYS_fsmount, fs_fd, flags, ms_flags);
}
#endif

#ifdef SYS_fspick
LINUX_SYSCALL_API int fspick(int dfd, const char *path, unsigned int flags)
{
    return (int)raw_syscall(SYS_fspick, dfd, path, flags);
}
#endif

#ifdef SYS_mount_setattr
LINUX_SYSCALL_API int mount_setattr(int dfd, const char *path, unsigned int flags, struct mount_attr *uattr, size_t usize)
{
    return (int)raw_syscall(SYS_mount_setattr, dfd, path, flags, uattr, usize);
}
#endif

#ifdef SYS_statmount
LINUX_SYSCALL_API int statmount(int dfd, const char *pathname, struct statmount *buf, size_t size, unsigned int flags)
{
    return (int)raw_syscall(SYS_statmount, dfd, pathname, buf, size, flags);
}
#endif

#ifdef SYS_listmount
LINUX_SYSCALL_API ssize_t listmount(uint64_t *mnt_id, uint64_t *list, size_t num, unsigned int flags)
{
    return (ssize_t)raw_syscall(SYS_listmount, mnt_id, list, num, flags);
}
#endif

#ifdef SYS_open_tree_attr
LINUX_SYSCALL_API int open_tree_attr(int dfd, const char *path, unsigned int flags, struct open_how *how, size_t size)
{
    return (int)raw_syscall(SYS_open_tree_attr, dfd, path, flags, how, size);
}
#endif

#ifdef SYS_mmap
LINUX_SYSCALL_API void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
    return (void *)raw_syscall(SYS_mmap, addr, length, prot, flags, fd, offset);
}
#endif

#ifdef SYS_mmap2
LINUX_SYSCALL_API void *mmap2(void *addr, size_t length, int prot, int flags, int fd, off_t pgoffset)
{
    return (void *)raw_syscall(SYS_mmap2, addr, length, prot, flags, fd, pgoffset);
}
#endif


#ifdef SYS_mprotect
LINUX_SYSCALL_API int mprotect(void *addr, size_t len, int prot)
{
    return (int)raw_syscall(SYS_mprotect, addr, len, prot);
}
#endif

#ifdef SYS_munmap
LINUX_SYSCALL_API int munmap(void *addr, size_t length)
{
    return (int)raw_syscall(SYS_munmap, addr, length);
}
#endif

#ifdef SYS_mremap
LINUX_SYSCALL_API void *mremap(void *old_address, size_t old_size, size_t new_size, int flags, void *new_address)
{
    return (void *)raw_syscall(SYS_mremap, old_address, old_size, new_size, flags, new_address);
}
#endif


#ifdef SYS_msync
LINUX_SYSCALL_API int msync(void *addr, size_t length, int flags)
{
    return (int)raw_syscall(SYS_msync, addr, length, flags);
}
#endif

#ifdef SYS_mincore
LINUX_SYSCALL_API int mincore(void *addr, size_t length, unsigned char *vec)
{
    return (int)raw_syscall(SYS_mincore, addr, length, vec);
}
#endif

#ifdef SYS_madvise
LINUX_SYSCALL_API int madvise(void *addr, size_t length, int advice)
{
    return (int)raw_syscall(SYS_madvise, addr, length, advice);
}
#endif

#ifdef SYS_mlock
LINUX_SYSCALL_API int mlock(const void *addr, size_t len)
{
    return (int)raw_syscall(SYS_mlock, addr, len);
}
#endif

#ifdef SYS_munlock
LINUX_SYSCALL_API int munlock(const void *addr, size_t len)
{
    return (int)raw_syscall(SYS_munlock, addr, len);
}
#endif

#ifdef SYS_mlockall
LINUX_SYSCALL_API int mlockall(int flags)
{
    return (int)raw_syscall(SYS_mlockall, flags);
}
#endif

#ifdef SYS_munlockall
LINUX_SYSCALL_API int munlockall(void)
{
    return (int)raw_syscall(SYS_munlockall);
}
#endif

#ifdef SYS_mlock2
LINUX_SYSCALL_API int mlock2(const void *addr, size_t len, unsigned int flags)
{
    return (int)raw_syscall(SYS_mlock2, addr, len, flags);
}
#endif

#ifdef SYS_brk
LINUX_SYSCALL_API int brk(void *addr)
{
    return (int)raw_syscall(SYS_brk, addr);
}
#endif

#ifdef SYS_memfd_create
LINUX_SYSCALL_API int memfd_create(const char *name, unsigned int flags)
{
    return (int)raw_syscall(SYS_memfd_create, name, flags);
}
#endif

#ifdef SYS_memfd_secret
LINUX_SYSCALL_API int memfd_secret(unsigned int flags)
{
    return (int)raw_syscall(SYS_memfd_secret, flags);
}
#endif

#ifdef SYS_pkey_mprotect
LINUX_SYSCALL_API int pkey_mprotect(void *addr, size_t len, int prot, int pkey)
{
    return (int)raw_syscall(SYS_pkey_mprotect, addr, len, prot, pkey);
}
#endif

#ifdef SYS_pkey_alloc
LINUX_SYSCALL_API int pkey_alloc(unsigned int flags, unsigned int access_rights)
{
    return (int)raw_syscall(SYS_pkey_alloc, flags, access_rights);
}
#endif

#ifdef SYS_pkey_free
LINUX_SYSCALL_API int pkey_free(int pkey)
{
    return (int)raw_syscall(SYS_pkey_free, pkey);
}
#endif

#ifdef SYS_mseal
LINUX_SYSCALL_API int mseal(void *addr, size_t len, unsigned int flags)
{
    return (int)raw_syscall(SYS_mseal, addr, len, flags);
}
#endif

#ifdef SYS_map_shadow_stack
LINUX_SYSCALL_API unsigned long map_shadow_stack(unsigned long addr, unsigned long len, unsigned int flags)
{
    return (unsigned long)raw_syscall(SYS_map_shadow_stack, addr, len, flags);
}
#endif

#ifdef SYS_fork
LINUX_SYSCALL_API pid_t fork(void)
{
    return (pid_t)raw_syscall(SYS_fork);
}
#endif

#ifdef SYS_vfork
LINUX_SYSCALL_API pid_t vfork(void)
{
    return (pid_t)raw_syscall(SYS_vfork);
}
#endif

#ifdef SYS_clone
LINUX_SYSCALL_API int clone(unsigned long flags, void *child_stack, void *ptid, void *ctid, unsigned long tls)
{
    return (int)raw_syscall(SYS_clone, flags, child_stack, ptid, ctid, tls);
}
#endif

#ifdef SYS_clone3
LINUX_SYSCALL_API int clone3(struct clone_args *cl_args, size_t size)
{
    return (int)raw_syscall(SYS_clone3, cl_args, size);
}
#endif

#ifdef SYS_execve
LINUX_SYSCALL_API int execve(const char *pathname, char *const argv[], char *const envp[])
{
    return (int)raw_syscall(SYS_execve, pathname, argv, envp);
}
#endif

#ifdef SYS_execveat
LINUX_SYSCALL_API int execveat(int dirfd, const char *pathname, char *const argv[], char *const envp[], int flags)
{
    return (int)raw_syscall(SYS_execveat, dirfd, pathname, argv, envp, flags);
}
#endif

#ifdef SYS_exit
LINUX_SYSCALL_API void _exit(int status)
{
    raw_syscall(SYS_exit, status);
    for (;;) ;
}
#endif

#ifdef SYS_exit_group
LINUX_SYSCALL_API void exit_group(int status)
{
    raw_syscall(SYS_exit_group, status);
    for (;;) ;
}
#endif

#ifdef SYS_wait4
LINUX_SYSCALL_API pid_t wait4(pid_t pid, int *wstatus, int options, struct rusage *rusage)
{
    return (pid_t)raw_syscall(SYS_wait4, pid, wstatus, options, rusage);
}
#endif

#ifdef SYS_waitid
LINUX_SYSCALL_API int waitid(idtype_t idtype, id_t id, siginfo_t *infop, int options)
{
    return (int)raw_syscall(SYS_waitid, idtype, id, infop, options);
}
#endif

#if defined(SYS_waitpid)
LINUX_SYSCALL_API pid_t waitpid(pid_t pid, int *wstatus, int options)
{
    return (pid_t)raw_syscall(SYS_waitpid, pid, wstatus, options);
}
#elif defined(SYS_wait4)
LINUX_SYSCALL_API pid_t waitpid(pid_t pid, int *wstatus, int options)
{
    return (pid_t)raw_syscall(SYS_wait4, pid, wstatus, options, (struct rusage *)0);
}
#endif

#ifdef SYS_getpid
LINUX_SYSCALL_API pid_t getpid(void)
{
    return (pid_t)raw_syscall(SYS_getpid);
}
#endif

#ifdef SYS_getppid
LINUX_SYSCALL_API pid_t getppid(void)
{
    return (pid_t)raw_syscall(SYS_getppid);
}
#endif

#ifdef SYS_gettid
LINUX_SYSCALL_API pid_t gettid(void)
{
    return (pid_t)raw_syscall(SYS_gettid);
}
#endif

#ifdef SYS_getpgid
LINUX_SYSCALL_API pid_t getpgid(pid_t pid)
{
    return (pid_t)raw_syscall(SYS_getpgid, pid);
}
#endif

#ifdef SYS_getpgrp
LINUX_SYSCALL_API pid_t getpgrp(void)
{
    return (pid_t)raw_syscall(SYS_getpgrp);
}
#elif defined(SYS_getpgid)
LINUX_SYSCALL_API pid_t getpgrp(void)
{
    return (pid_t)raw_syscall(SYS_getpgid, 0);
}
#endif

#ifdef SYS_getsid
LINUX_SYSCALL_API pid_t getsid(pid_t pid)
{
    return (pid_t)raw_syscall(SYS_getsid, pid);
}
#endif

#ifdef SYS_setpgid
LINUX_SYSCALL_API int setpgid(pid_t pid, pid_t pgid)
{
    return (int)raw_syscall(SYS_setpgid, pid, pgid);
}
#endif

#ifdef SYS_setsid
LINUX_SYSCALL_API pid_t setsid(void)
{
    return (pid_t)raw_syscall(SYS_setsid);
}
#endif

#ifdef SYS_set_tid_address
LINUX_SYSCALL_API pid_t set_tid_address(int *tidptr)
{
    return (pid_t)raw_syscall(SYS_set_tid_address, tidptr);
}
#endif

#ifdef SYS_prctl
LINUX_SYSCALL_API int prctl(int option, unsigned long arg2, unsigned long arg3, unsigned long arg4, unsigned long arg5)
{
    return (int)raw_syscall(SYS_prctl, option, arg2, arg3, arg4, arg5);
}
#endif

#ifdef SYS_arch_prctl
LINUX_SYSCALL_API int arch_prctl(int code, unsigned long addr)
{
    return (int)raw_syscall(SYS_arch_prctl, code, addr);
}
#endif

#ifdef SYS_setns
LINUX_SYSCALL_API int setns(int fd, int nstype)
{
    return (int)raw_syscall(SYS_setns, fd, nstype);
}
#endif

#ifdef SYS_unshare
LINUX_SYSCALL_API int unshare(int flags)
{
    return (int)raw_syscall(SYS_unshare, flags);
}
#endif

#ifdef SYS_pidfd_open
LINUX_SYSCALL_API int pidfd_open(pid_t pid, unsigned int flags)
{
    return (int)raw_syscall(SYS_pidfd_open, pid, flags);
}
#endif

#ifdef SYS_pidfd_getfd
LINUX_SYSCALL_API int pidfd_getfd(int pidfd, int targetfd, unsigned int flags)
{
    return (int)raw_syscall(SYS_pidfd_getfd, pidfd, targetfd, flags);
}
#endif

#ifdef SYS_pidfd_send_signal
LINUX_SYSCALL_API int pidfd_send_signal(int pidfd, int sig, siginfo_t *info, unsigned int flags)
{
    return (int)raw_syscall(SYS_pidfd_send_signal, pidfd, sig, info, flags);
}
#endif

#ifdef SYS_kcmp
LINUX_SYSCALL_API int kcmp(pid_t pid1, pid_t pid2, int type, unsigned long idx1, unsigned long idx2)
{
    return (int)raw_syscall(SYS_kcmp, pid1, pid2, type, idx1, idx2);
}
#endif

#ifdef SYS_process_vm_readv
LINUX_SYSCALL_API ssize_t process_vm_readv(pid_t pid, const struct iovec *local_iov, unsigned long liovcnt, const struct iovec *remote_iov, unsigned long riovcnt, unsigned long flags)
{
    return (ssize_t)raw_syscall(SYS_process_vm_readv, pid, local_iov, liovcnt, remote_iov, riovcnt, flags);
}
#endif

#ifdef SYS_process_vm_writev
LINUX_SYSCALL_API ssize_t process_vm_writev(pid_t pid, const struct iovec *local_iov, unsigned long liovcnt, const struct iovec *remote_iov, unsigned long riovcnt, unsigned long flags)
{
    return (ssize_t)raw_syscall(SYS_process_vm_writev, pid, local_iov, liovcnt, remote_iov, riovcnt, flags);
}
#endif

#ifdef SYS_process_madvise
LINUX_SYSCALL_API ssize_t process_madvise(int pidfd, const struct iovec *iovec, size_t vlen, int advice, unsigned int flags)
{
    return (ssize_t)raw_syscall(SYS_process_madvise, pidfd, iovec, vlen, advice, flags);
}
#endif

#ifdef SYS_getuid
LINUX_SYSCALL_API uid_t getuid(void)
{
    return (uid_t)raw_syscall(SYS_getuid);
}
#endif

#ifdef SYS_getgid
LINUX_SYSCALL_API gid_t getgid(void)
{
    return (gid_t)raw_syscall(SYS_getgid);
}
#endif

#ifdef SYS_geteuid
LINUX_SYSCALL_API uid_t geteuid(void)
{
    return (uid_t)raw_syscall(SYS_geteuid);
}
#endif

#ifdef SYS_getegid
LINUX_SYSCALL_API gid_t getegid(void)
{
    return (gid_t)raw_syscall(SYS_getegid);
}
#endif

#ifdef SYS_setuid
LINUX_SYSCALL_API int setuid(uid_t uid)
{
    return (int)raw_syscall(SYS_setuid, uid);
}
#endif

#ifdef SYS_setgid
LINUX_SYSCALL_API int setgid(gid_t gid)
{
    return (int)raw_syscall(SYS_setgid, gid);
}
#endif

#ifdef SYS_setreuid
LINUX_SYSCALL_API int setreuid(uid_t ruid, uid_t euid)
{
    return (int)raw_syscall(SYS_setreuid, ruid, euid);
}
#endif

#ifdef SYS_setregid
LINUX_SYSCALL_API int setregid(gid_t rgid, gid_t egid)
{
    return (int)raw_syscall(SYS_setregid, rgid, egid);
}
#endif

#ifdef SYS_setresuid
LINUX_SYSCALL_API int setresuid(uid_t ruid, uid_t euid, uid_t suid)
{
    return (int)raw_syscall(SYS_setresuid, ruid, euid, suid);
}
#endif

#ifdef SYS_getresuid
LINUX_SYSCALL_API int getresuid(uid_t *ruid, uid_t *euid, uid_t *suid)
{
    return (int)raw_syscall(SYS_getresuid, ruid, euid, suid);
}
#endif

#ifdef SYS_setresgid
LINUX_SYSCALL_API int setresgid(gid_t rgid, gid_t egid, gid_t sgid)
{
    return (int)raw_syscall(SYS_setresgid, rgid, egid, sgid);
}
#endif

#ifdef SYS_getresgid
LINUX_SYSCALL_API int getresgid(gid_t *rgid, gid_t *egid, gid_t *sgid)
{
    return (int)raw_syscall(SYS_getresgid, rgid, egid, sgid);
}
#endif

#ifdef SYS_getgroups
LINUX_SYSCALL_API int getgroups(int size, gid_t list[])
{
    return (int)raw_syscall(SYS_getgroups, size, list);
}
#endif

#ifdef SYS_setgroups
LINUX_SYSCALL_API int setgroups(size_t size, const gid_t *list)
{
    return (int)raw_syscall(SYS_setgroups, size, list);
}
#endif

#ifdef SYS_setfsuid
LINUX_SYSCALL_API int setfsuid(uid_t fsuid)
{
    return (int)raw_syscall(SYS_setfsuid, fsuid);
}
#endif

#ifdef SYS_setfsgid
LINUX_SYSCALL_API int setfsgid(gid_t fsgid)
{
    return (int)raw_syscall(SYS_setfsgid, fsgid);
}
#endif

#ifdef SYS_capget
LINUX_SYSCALL_API int capget(cap_user_header_t hdrp, cap_user_data_t datap)
{
    return (int)raw_syscall(SYS_capget, hdrp, datap);
}
#endif

#ifdef SYS_capset
LINUX_SYSCALL_API int capset(cap_user_header_t hdrp, const cap_user_data_t datap)
{
    return (int)raw_syscall(SYS_capset, hdrp, datap);
}
#endif

#ifdef SYS_sched_yield
LINUX_SYSCALL_API int sched_yield(void)
{
    return (int)raw_syscall(SYS_sched_yield);
}
#endif

#ifdef SYS_sched_setparam
LINUX_SYSCALL_API int sched_setparam(pid_t pid, const struct sched_param *param)
{
    return (int)raw_syscall(SYS_sched_setparam, pid, param);
}
#endif

#ifdef SYS_sched_getparam
LINUX_SYSCALL_API int sched_getparam(pid_t pid, struct sched_param *param)
{
    return (int)raw_syscall(SYS_sched_getparam, pid, param);
}
#endif

#ifdef SYS_sched_setscheduler
LINUX_SYSCALL_API int sched_setscheduler(pid_t pid, int policy, const struct sched_param *param)
{
    return (int)raw_syscall(SYS_sched_setscheduler, pid, policy, param);
}
#endif

#ifdef SYS_sched_getscheduler
LINUX_SYSCALL_API int sched_getscheduler(pid_t pid)
{
    return (int)raw_syscall(SYS_sched_getscheduler, pid);
}
#endif

#ifdef SYS_sched_get_priority_max
LINUX_SYSCALL_API int sched_get_priority_max(int policy)
{
    return (int)raw_syscall(SYS_sched_get_priority_max, policy);
}
#endif

#ifdef SYS_sched_get_priority_min
LINUX_SYSCALL_API int sched_get_priority_min(int policy)
{
    return (int)raw_syscall(SYS_sched_get_priority_min, policy);
}
#endif

#ifdef SYS_sched_rr_get_interval
LINUX_SYSCALL_API int sched_rr_get_interval(pid_t pid, struct timespec *tp)
{
    return (int)raw_syscall(SYS_sched_rr_get_interval, pid, tp);
}
#endif

#ifdef SYS_sched_setaffinity
LINUX_SYSCALL_API int sched_setaffinity(pid_t pid, size_t cpusetsize, const cpu_set_t *mask)
{
    return (int)raw_syscall(SYS_sched_setaffinity, pid, cpusetsize, mask);
}
#endif

#ifdef SYS_sched_getaffinity
LINUX_SYSCALL_API int sched_getaffinity(pid_t pid, size_t cpusetsize, cpu_set_t *mask)
{
    return (int)raw_syscall(SYS_sched_getaffinity, pid, cpusetsize, mask);
}
#endif

#ifdef SYS_sched_setattr
LINUX_SYSCALL_API int sched_setattr(pid_t pid, struct sched_attr *attr, unsigned int flags)
{
    return (int)raw_syscall(SYS_sched_setattr, pid, attr, flags);
}
#endif

#ifdef SYS_sched_getattr
LINUX_SYSCALL_API int sched_getattr(pid_t pid, struct sched_attr *attr, unsigned int size, unsigned int flags)
{
    return (int)raw_syscall(SYS_sched_getattr, pid, attr, size, flags);
}
#endif

#ifdef SYS_nice
LINUX_SYSCALL_API int nice(int inc)
{
    return (int)raw_syscall(SYS_nice, inc);
}
#endif

#ifdef SYS_setpriority
LINUX_SYSCALL_API int setpriority(int which, id_t who, int prio)
{
    return (int)raw_syscall(SYS_setpriority, which, who, prio);
}
#endif

#ifdef SYS_getpriority
LINUX_SYSCALL_API int getpriority(int which, id_t who)
{
    return (int)raw_syscall(SYS_getpriority, which, who);
}
#endif

#ifdef SYS_ioprio_set
LINUX_SYSCALL_API int ioprio_set(int which, int who, int ioprio)
{
    return (int)raw_syscall(SYS_ioprio_set, which, who, ioprio);
}
#endif

#ifdef SYS_ioprio_get
LINUX_SYSCALL_API int ioprio_get(int which, int who)
{
    return (int)raw_syscall(SYS_ioprio_get, which, who);
}
#endif

#ifdef SYS_getrlimit
LINUX_SYSCALL_API int getrlimit(int resource, struct rlimit *rlim)
{
    return (int)raw_syscall(SYS_getrlimit, resource, rlim);
}
#endif

#ifdef SYS_setrlimit
LINUX_SYSCALL_API int setrlimit(int resource, const struct rlimit *rlim)
{
    return (int)raw_syscall(SYS_setrlimit, resource, rlim);
}
#endif

#ifdef SYS_prlimit64
LINUX_SYSCALL_API int prlimit64(pid_t pid, int resource, const struct rlimit64 *new_limit, struct rlimit64 *old_limit)
{
    return (int)raw_syscall(SYS_prlimit64, pid, resource, new_limit, old_limit);
}
#endif

#ifdef SYS_getrusage
LINUX_SYSCALL_API int getrusage(int who, struct rusage *usage)
{
    return (int)raw_syscall(SYS_getrusage, who, usage);
}
#endif

#ifdef SYS_rseq
LINUX_SYSCALL_API int rseq(struct rseq *rseq, uint32_t rseq_len, int flags, uint32_t sig)
{
    return (int)raw_syscall(SYS_rseq, rseq, rseq_len, flags, sig);
}
#endif

#ifdef SYS_rseq_slice_yield
LINUX_SYSCALL_API int rseq_slice_yield(struct rseq *rseq, unsigned int cpu_id, unsigned int flags)
{
    return (int)raw_syscall(SYS_rseq_slice_yield, rseq, cpu_id, flags);
}
#endif

#ifdef SYS_kill
LINUX_SYSCALL_API int kill(pid_t pid, int sig)
{
    return (int)raw_syscall(SYS_kill, pid, sig);
}
#endif

#ifdef SYS_tkill
LINUX_SYSCALL_API int tkill(pid_t tid, int sig)
{
    return (int)raw_syscall(SYS_tkill, tid, sig);
}
#endif

#ifdef SYS_tgkill
LINUX_SYSCALL_API int tgkill(pid_t tgid, pid_t tid, int sig)
{
    return (int)raw_syscall(SYS_tgkill, tgid, tid, sig);
}
#endif

#ifdef SYS_rt_sigaction
LINUX_SYSCALL_API int rt_sigaction(int signum, const struct sigaction *act, struct sigaction *oldact, size_t sigsetsize)
{
    return (int)raw_syscall(SYS_rt_sigaction, signum, act, oldact, sigsetsize);
}
#endif

#ifdef SYS_rt_sigprocmask
LINUX_SYSCALL_API int rt_sigprocmask(int how, const sigset_t *set, sigset_t *oldset, size_t sigsetsize)
{
    return (int)raw_syscall(SYS_rt_sigprocmask, how, set, oldset, sigsetsize);
}
#endif

#ifdef SYS_rt_sigreturn
LINUX_SYSCALL_API int rt_sigreturn(unsigned long __unused)
{
    return (int)raw_syscall(SYS_rt_sigreturn, __unused);
}
#endif

#ifdef SYS_rt_sigpending
LINUX_SYSCALL_API int rt_sigpending(sigset_t *set, size_t sigsetsize)
{
    return (int)raw_syscall(SYS_rt_sigpending, set, sigsetsize);
}
#endif

#ifdef SYS_rt_sigtimedwait
LINUX_SYSCALL_API int rt_sigtimedwait(const sigset_t *set, siginfo_t *info, const struct timespec *timeout, size_t sigsetsize)
{
    return (int)raw_syscall(SYS_rt_sigtimedwait, set, info, timeout, sigsetsize);
}
#endif

#ifdef SYS_rt_sigqueueinfo
LINUX_SYSCALL_API int rt_sigqueueinfo(pid_t pid, int sig, siginfo_t *info)
{
    return (int)raw_syscall(SYS_rt_sigqueueinfo, pid, sig, info);
}
#endif

#ifdef SYS_rt_tgsigqueueinfo
LINUX_SYSCALL_API int rt_tgsigqueueinfo(pid_t tgid, pid_t tid, int sig, siginfo_t *info)
{
    return (int)raw_syscall(SYS_rt_tgsigqueueinfo, tgid, tid, sig, info);
}
#endif

#ifdef SYS_rt_sigsuspend
LINUX_SYSCALL_API int rt_sigsuspend(const sigset_t *newset, size_t sigsetsize)
{
    return (int)raw_syscall(SYS_rt_sigsuspend, newset, sigsetsize);
}
#endif

#ifdef SYS_sigaltstack
LINUX_SYSCALL_API int sigaltstack(const stack_t *ss, stack_t *old_ss)
{
    return (int)raw_syscall(SYS_sigaltstack, ss, old_ss);
}
#endif

#ifdef SYS_signalfd
LINUX_SYSCALL_API int signalfd(int fd, const sigset_t *mask, int flags)
{
    return (int)raw_syscall(SYS_signalfd, fd, mask, flags);
}
#endif

#ifdef SYS_signalfd4
LINUX_SYSCALL_API int signalfd4(int fd, const sigset_t *mask, size_t sizemask, int flags)
{
    return (int)raw_syscall(SYS_signalfd4, fd, mask, sizemask, flags);
}
#endif

#ifdef SYS_pause
LINUX_SYSCALL_API int pause(void)
{
    return (int)raw_syscall(SYS_pause);
}
#endif

#ifdef SYS_alarm
LINUX_SYSCALL_API unsigned int alarm(unsigned int seconds)
{
    return (unsigned int)raw_syscall(SYS_alarm, seconds);
}
#endif

#ifdef SYS_restart_syscall
LINUX_SYSCALL_API int restart_syscall(void)
{
    return (int)raw_syscall(SYS_restart_syscall);
}
#endif

#ifdef SYS_gettimeofday
LINUX_SYSCALL_API int gettimeofday(struct timeval *tv, struct timezone *tz)
{
    return (int)raw_syscall(SYS_gettimeofday, tv, tz);
}
#endif

#ifdef SYS_settimeofday
LINUX_SYSCALL_API int settimeofday(const struct timeval *tv, const struct timezone *tz)
{
    return (int)raw_syscall(SYS_settimeofday, tv, tz);
}
#endif

#ifdef SYS_time
LINUX_SYSCALL_API time_t time(time_t *tloc)
{
    return (time_t)raw_syscall(SYS_time, tloc);
}
#endif

#ifdef SYS_times
LINUX_SYSCALL_API clock_t times(struct tms *buf)
{
    return (clock_t)raw_syscall(SYS_times, buf);
}
#endif

#ifdef SYS_nanosleep
LINUX_SYSCALL_API int nanosleep(const struct timespec *req, struct timespec *rem)
{
    return (int)raw_syscall(SYS_nanosleep, req, rem);
}
#endif

#ifdef SYS_clock_nanosleep
LINUX_SYSCALL_API int clock_nanosleep(clockid_t clockid, int flags, const struct timespec *request, struct timespec *remain)
{
    return (int)raw_syscall(SYS_clock_nanosleep, clockid, flags, request, remain);
}
#endif

#ifdef SYS_clock_settime
LINUX_SYSCALL_API int clock_settime(clockid_t clockid, const struct timespec *tp)
{
    return (int)raw_syscall(SYS_clock_settime, clockid, tp);
}
#endif

#ifdef SYS_clock_gettime
LINUX_SYSCALL_API int clock_gettime(clockid_t clockid, struct timespec *tp)
{
    return (int)raw_syscall(SYS_clock_gettime, clockid, tp);
}
#endif

#ifdef SYS_clock_getres
LINUX_SYSCALL_API int clock_getres(clockid_t clockid, struct timespec *res)
{
    return (int)raw_syscall(SYS_clock_getres, clockid, res);
}
#endif

#ifdef SYS_clock_adjtime
LINUX_SYSCALL_API int clock_adjtime(clockid_t clk_id, struct timex *buf)
{
    return (int)raw_syscall(SYS_clock_adjtime, clk_id, buf);
}
#endif

#ifdef SYS_adjtimex
LINUX_SYSCALL_API int adjtimex(struct timex *buf)
{
    return (int)raw_syscall(SYS_adjtimex, buf);
}
#endif

#ifdef SYS_timer_create
LINUX_SYSCALL_API int timer_create(clockid_t clockid, struct sigevent *sevp, timer_t *timerid)
{
    return (int)raw_syscall(SYS_timer_create, clockid, sevp, timerid);
}
#endif

#ifdef SYS_timer_settime
LINUX_SYSCALL_API int timer_settime(timer_t timerid, int flags, const struct itimerspec *new_value, struct itimerspec *old_value)
{
    return (int)raw_syscall(SYS_timer_settime, timerid, flags, new_value, old_value);
}
#endif

#ifdef SYS_timer_gettime
LINUX_SYSCALL_API int timer_gettime(timer_t timerid, struct itimerspec *curr_value)
{
    return (int)raw_syscall(SYS_timer_gettime, timerid, curr_value);
}
#endif

#ifdef SYS_timer_getoverrun
LINUX_SYSCALL_API int timer_getoverrun(timer_t timerid)
{
    return (int)raw_syscall(SYS_timer_getoverrun, timerid);
}
#endif

#ifdef SYS_timer_delete
LINUX_SYSCALL_API int timer_delete(timer_t timerid)
{
    return (int)raw_syscall(SYS_timer_delete, timerid);
}
#endif

#ifdef SYS_getitimer
LINUX_SYSCALL_API int getitimer(int which, struct itimerval *curr_value)
{
    return (int)raw_syscall(SYS_getitimer, which, curr_value);
}
#endif

#ifdef SYS_setitimer
LINUX_SYSCALL_API int setitimer(int which, const struct itimerval *new_value, struct itimerval *old_value)
{
    return (int)raw_syscall(SYS_setitimer, which, new_value, old_value);
}
#endif

#ifdef SYS_timerfd_create
LINUX_SYSCALL_API int timerfd_create(int clockid, int flags)
{
    return (int)raw_syscall(SYS_timerfd_create, clockid, flags);
}
#endif

#ifdef SYS_timerfd_settime
LINUX_SYSCALL_API int timerfd_settime(int fd, int flags, const struct itimerspec *new_value, struct itimerspec *old_value)
{
    return (int)raw_syscall(SYS_timerfd_settime, fd, flags, new_value, old_value);
}
#endif

#ifdef SYS_timerfd_gettime
LINUX_SYSCALL_API int timerfd_gettime(int fd, struct itimerspec *curr_value)
{
    return (int)raw_syscall(SYS_timerfd_gettime, fd, curr_value);
}
#endif

#ifdef SYS_utime
LINUX_SYSCALL_API int utime(const char *filename, const struct utimbuf *times)
{
    return (int)raw_syscall(SYS_utime, filename, times);
}
#endif

#ifdef SYS_utimes
LINUX_SYSCALL_API int utimes(const char *filename, const struct timeval times[2])
{
    return (int)raw_syscall(SYS_utimes, filename, times);
}
#endif

#ifdef SYS_poll
LINUX_SYSCALL_API int poll(struct pollfd *fds, nfds_t nfds, int timeout)
{
    return (int)raw_syscall(SYS_poll, fds, nfds, timeout);
}
#endif

#ifdef SYS_ppoll
LINUX_SYSCALL_API int ppoll(struct pollfd *fds, nfds_t nfds, const struct timespec *tmo_p, const sigset_t *sigmask)
{
    return (int)raw_syscall(SYS_ppoll, fds, nfds, tmo_p, sigmask);
}
#endif

#ifdef SYS_select
LINUX_SYSCALL_API int select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout)
{
    return (int)raw_syscall(SYS_select, nfds, readfds, writefds, exceptfds, timeout);
}
#endif

#ifdef SYS_pselect
LINUX_SYSCALL_API int pselect(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, const struct timespec *timeout, const sigset_t *sigmask)
{
    return (int)raw_syscall(SYS_pselect, nfds, readfds, writefds, exceptfds, timeout, sigmask);
}
#endif

#ifdef SYS_epoll_create
LINUX_SYSCALL_API int epoll_create(int size)
{
    return (int)raw_syscall(SYS_epoll_create, size);
}
#endif

#ifdef SYS_epoll_create1
LINUX_SYSCALL_API int epoll_create1(int flags)
{
    return (int)raw_syscall(SYS_epoll_create1, flags);
}
#endif

#ifdef SYS_epoll_ctl
LINUX_SYSCALL_API int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event)
{
    return (int)raw_syscall(SYS_epoll_ctl, epfd, op, fd, event);
}
#endif

#ifdef SYS_epoll_wait
LINUX_SYSCALL_API int epoll_wait(int epfd, struct epoll_event *events, int maxevents, int timeout)
{
    return (int)raw_syscall(SYS_epoll_wait, epfd, events, maxevents, timeout);
}
#endif

#ifdef SYS_epoll_pwait
LINUX_SYSCALL_API int epoll_pwait(int epfd, struct epoll_event *events, int maxevents, int timeout, const sigset_t *sigmask)
{
    return (int)raw_syscall(SYS_epoll_pwait, epfd, events, maxevents, timeout, sigmask);
}
#endif

#ifdef SYS_epoll_pwait2
LINUX_SYSCALL_API int epoll_pwait2(int epfd, struct epoll_event *events, int maxevents, const struct timespec *timeout, const sigset_t *sigmask)
{
    return (int)raw_syscall(SYS_epoll_pwait2, epfd, events, maxevents, timeout, sigmask);
}
#endif

#ifdef SYS_eventfd
LINUX_SYSCALL_API int eventfd(unsigned int initval, int flags)
{
    return (int)raw_syscall(SYS_eventfd, initval, flags);
}
#endif

#ifdef SYS_eventfd2
LINUX_SYSCALL_API int eventfd2(unsigned int initval, int flags)
{
    return (int)raw_syscall(SYS_eventfd2, initval, flags);
}
#endif

#ifdef SYS_socket
LINUX_SYSCALL_API int socket(int domain, int type, int protocol)
{
    return (int)raw_syscall(SYS_socket, domain, type, protocol);
}
#endif

#ifdef SYS_socketpair
LINUX_SYSCALL_API int socketpair(int domain, int type, int protocol, int sv[2])
{
    return (int)raw_syscall(SYS_socketpair, domain, type, protocol, sv);
}
#endif

#ifdef SYS_bind
LINUX_SYSCALL_API int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
    return (int)raw_syscall(SYS_bind, sockfd, addr, addrlen);
}
#endif

#ifdef SYS_listen
LINUX_SYSCALL_API int listen(int sockfd, int backlog)
{
    return (int)raw_syscall(SYS_listen, sockfd, backlog);
}
#endif

#ifdef SYS_accept
LINUX_SYSCALL_API int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
{
    return (int)raw_syscall(SYS_accept, sockfd, addr, addrlen);
}
#endif

#ifdef SYS_accept4
LINUX_SYSCALL_API int accept4(int sockfd, struct sockaddr *addr, socklen_t *addrlen, int flags)
{
    return (int)raw_syscall(SYS_accept4, sockfd, addr, addrlen, flags);
}
#endif

#ifdef SYS_connect
LINUX_SYSCALL_API int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
    return (int)raw_syscall(SYS_connect, sockfd, addr, addrlen);
}
#endif

#ifdef SYS_shutdown
LINUX_SYSCALL_API int shutdown(int sockfd, int how)
{
    return (int)raw_syscall(SYS_shutdown, sockfd, how);
}
#endif

#ifdef SYS_getsockname
LINUX_SYSCALL_API int getsockname(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
{
    return (int)raw_syscall(SYS_getsockname, sockfd, addr, addrlen);
}
#endif

#ifdef SYS_getpeername
LINUX_SYSCALL_API int getpeername(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
{
    return (int)raw_syscall(SYS_getpeername, sockfd, addr, addrlen);
}
#endif

#ifdef SYS_setsockopt
LINUX_SYSCALL_API int setsockopt(int sockfd, int level, int optname, const void *optval, socklen_t optlen)
{
    return (int)raw_syscall(SYS_setsockopt, sockfd, level, optname, optval, optlen);
}
#endif

#ifdef SYS_getsockopt
LINUX_SYSCALL_API int getsockopt(int sockfd, int level, int optname, void *optval, socklen_t *optlen)
{
    return (int)raw_syscall(SYS_getsockopt, sockfd, level, optname, optval, optlen);
}
#endif

#ifdef SYS_sendto
LINUX_SYSCALL_API ssize_t sendto(int sockfd, const void *buf, size_t len, int flags, const struct sockaddr *dest_addr, socklen_t addrlen)
{
    return (ssize_t)raw_syscall(SYS_sendto, sockfd, buf, len, flags, dest_addr, addrlen);
}
#endif

#ifdef SYS_recvfrom
LINUX_SYSCALL_API ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags, struct sockaddr *src_addr, socklen_t *addrlen)
{
    return (ssize_t)raw_syscall(SYS_recvfrom, sockfd, buf, len, flags, src_addr, addrlen);
}
#endif

#ifdef SYS_sendmsg
LINUX_SYSCALL_API ssize_t sendmsg(int sockfd, const struct msghdr *msg, int flags)
{
    return (ssize_t)raw_syscall(SYS_sendmsg, sockfd, msg, flags);
}
#endif

#ifdef SYS_recvmsg
LINUX_SYSCALL_API ssize_t recvmsg(int sockfd, struct msghdr *msg, int flags)
{
    return (ssize_t)raw_syscall(SYS_recvmsg, sockfd, msg, flags);
}
#endif

#ifdef SYS_sendmmsg
LINUX_SYSCALL_API int sendmmsg(int sockfd, struct mmsghdr *msgvec, unsigned int vlen, int flags)
{
    return (int)raw_syscall(SYS_sendmmsg, sockfd, msgvec, vlen, flags);
}
#endif

#ifdef SYS_recvmmsg
LINUX_SYSCALL_API int recvmmsg(int sockfd, struct mmsghdr *msgvec, unsigned int vlen, int flags, struct timespec *timeout)
{
    return (int)raw_syscall(SYS_recvmmsg, sockfd, msgvec, vlen, flags, timeout);
}
#endif

#ifdef SYS_socketcall
LINUX_SYSCALL_API int socketcall(int call, unsigned long *args)
{
    return (int)raw_syscall(SYS_socketcall, call, args);
}
#endif

#ifdef SYS_futex
LINUX_SYSCALL_API int futex(int *uaddr, int futex_op, int val, const struct timespec *timeout, int *uaddr2, int val3)
{
    return (int)raw_syscall(SYS_futex, uaddr, futex_op, val, timeout, uaddr2, val3);
}
#endif

#ifdef SYS_futex_waitv
LINUX_SYSCALL_API int futex_waitv(struct futex_waitv *waiters, unsigned int nr_futexes, unsigned int flags, struct timespec *timeout, clockid_t clockid)
{
    return (int)raw_syscall(SYS_futex_waitv, waiters, nr_futexes, flags, timeout, clockid);
}
#endif

#ifdef SYS_futex_wake
LINUX_SYSCALL_API int futex_wake(unsigned int *uaddr, unsigned int nr_wake, unsigned int mask, unsigned int flags)
{
    return (int)raw_syscall(SYS_futex_wake, uaddr, nr_wake, mask, flags);
}
#endif

#ifdef SYS_futex_wait
LINUX_SYSCALL_API int futex_wait(unsigned int *uaddr, unsigned int val, unsigned int mask, unsigned int flags, struct __kernel_timespec *timeout, clockid_t clockid)
{
    return (int)raw_syscall(SYS_futex_wait, uaddr, val, mask, flags, timeout, clockid);
}
#endif

#ifdef SYS_futex_requeue
LINUX_SYSCALL_API int futex_requeue(unsigned int *uaddr, unsigned int nr_wake, unsigned int nr_requeue, unsigned int *uaddr2, unsigned int flags)
{
    return (int)raw_syscall(SYS_futex_requeue, uaddr, nr_wake, nr_requeue, uaddr2, flags);
}
#endif

#ifdef SYS_set_robust_list
LINUX_SYSCALL_API int set_robust_list(struct robust_list_head *head, size_t len)
{
    return (int)raw_syscall(SYS_set_robust_list, head, len);
}
#endif

#ifdef SYS_get_robust_list
LINUX_SYSCALL_API int get_robust_list(int pid, struct robust_list_head **head_ptr, size_t *len_ptr)
{
    return (int)raw_syscall(SYS_get_robust_list, pid, head_ptr, len_ptr);
}
#endif

#ifdef SYS_shmget
LINUX_SYSCALL_API int shmget(key_t key, size_t size, int shmflg)
{
    return (int)raw_syscall(SYS_shmget, key, size, shmflg);
}
#endif

#ifdef SYS_shmat
LINUX_SYSCALL_API void *shmat(int shmid, const void *shmaddr, int shmflg)
{
    return (void *)raw_syscall(SYS_shmat, shmid, shmaddr, shmflg);
}
#endif


#ifdef SYS_shmctl
LINUX_SYSCALL_API int shmctl(int shmid, int cmd, struct shmid_ds *buf)
{
    return (int)raw_syscall(SYS_shmctl, shmid, cmd, buf);
}
#endif

#ifdef SYS_shmdt
LINUX_SYSCALL_API int shmdt(const void *shmaddr)
{
    return (int)raw_syscall(SYS_shmdt, shmaddr);
}
#endif

#ifdef SYS_msgget
LINUX_SYSCALL_API int msgget(key_t key, int msgflg)
{
    return (int)raw_syscall(SYS_msgget, key, msgflg);
}
#endif

#ifdef SYS_msgsnd
LINUX_SYSCALL_API int msgsnd(int msqid, const void *msgp, size_t msgsz, int msgflg)
{
    return (int)raw_syscall(SYS_msgsnd, msqid, msgp, msgsz, msgflg);
}
#endif

#ifdef SYS_msgrcv
LINUX_SYSCALL_API ssize_t msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp, int msgflg)
{
    return (ssize_t)raw_syscall(SYS_msgrcv, msqid, msgp, msgsz, msgtyp, msgflg);
}
#endif

#ifdef SYS_msgctl
LINUX_SYSCALL_API int msgctl(int msqid, int cmd, struct msqid_ds *buf)
{
    return (int)raw_syscall(SYS_msgctl, msqid, cmd, buf);
}
#endif

#ifdef SYS_semget
LINUX_SYSCALL_API int semget(key_t key, int nsems, int semflg)
{
    return (int)raw_syscall(SYS_semget, key, nsems, semflg);
}
#endif

#ifdef SYS_semop
LINUX_SYSCALL_API int semop(int semid, struct sembuf *sops, size_t nsops)
{
    return (int)raw_syscall(SYS_semop, semid, sops, nsops);
}
#endif

#ifdef SYS_semctl
LINUX_SYSCALL_API int semctl(int semid, int semnum, int cmd, unsigned long arg)
{
    return (int)raw_syscall(SYS_semctl, semid, semnum, cmd, arg);
}
#endif

#ifdef SYS_semtimedop
LINUX_SYSCALL_API int semtimedop(int semid, struct sembuf *sops, size_t nsops, const struct timespec *timeout)
{
    return (int)raw_syscall(SYS_semtimedop, semid, sops, nsops, timeout);
}
#endif

#ifdef SYS_ipc
LINUX_SYSCALL_API int ipc(unsigned int call, int first, unsigned long second, unsigned long third, void *ptr, long fifth)
{
    return (int)raw_syscall(SYS_ipc, call, first, second, third, ptr, fifth);
}
#endif

#ifdef SYS_mq_open
LINUX_SYSCALL_API mqd_t mq_open(const char *name, int oflag, mode_t mode, struct mq_attr *attr)
{
    return (mqd_t)raw_syscall(SYS_mq_open, name, oflag, mode, attr);
}
#endif

#ifdef SYS_mq_unlink
LINUX_SYSCALL_API int mq_unlink(const char *name)
{
    return (int)raw_syscall(SYS_mq_unlink, name);
}
#endif

#ifdef SYS_mq_timedsend
LINUX_SYSCALL_API int mq_timedsend(mqd_t mqdes, const char *msg_ptr, size_t msg_len, unsigned int msg_prio, const struct timespec *abs_timeout)
{
    return (int)raw_syscall(SYS_mq_timedsend, mqdes, msg_ptr, msg_len, msg_prio, abs_timeout);
}
#endif

#ifdef SYS_mq_timedreceive
LINUX_SYSCALL_API ssize_t mq_timedreceive(mqd_t mqdes, char *msg_ptr, size_t msg_len, unsigned int *msg_prio, const struct timespec *abs_timeout)
{
    return (ssize_t)raw_syscall(SYS_mq_timedreceive, mqdes, msg_ptr, msg_len, msg_prio, abs_timeout);
}
#endif

#ifdef SYS_mq_notify
LINUX_SYSCALL_API int mq_notify(mqd_t mqdes, const struct sigevent *sevp)
{
    return (int)raw_syscall(SYS_mq_notify, mqdes, sevp);
}
#endif

#ifdef SYS_mq_getsetattr
LINUX_SYSCALL_API int mq_getsetattr(mqd_t mqdes, const struct mq_attr *newattr, struct mq_attr *oldattr)
{
    return (int)raw_syscall(SYS_mq_getsetattr, mqdes, newattr, oldattr);
}
#endif

#ifdef SYS_io_setup
LINUX_SYSCALL_API int io_setup(unsigned int nr_events, aio_context_t *ctx_idp)
{
    return (int)raw_syscall(SYS_io_setup, nr_events, ctx_idp);
}
#endif

#ifdef SYS_io_destroy
LINUX_SYSCALL_API int io_destroy(aio_context_t ctx_id)
{
    return (int)raw_syscall(SYS_io_destroy, ctx_id);
}
#endif

#ifdef SYS_io_submit
LINUX_SYSCALL_API int io_submit(aio_context_t ctx_id, long nr, struct iocb **iocbpp)
{
    return (int)raw_syscall(SYS_io_submit, ctx_id, nr, iocbpp);
}
#endif

#ifdef SYS_io_cancel
LINUX_SYSCALL_API int io_cancel(aio_context_t ctx_id, struct iocb *iocb, struct io_event *result)
{
    return (int)raw_syscall(SYS_io_cancel, ctx_id, iocb, result);
}
#endif

#ifdef SYS_io_getevents
LINUX_SYSCALL_API int io_getevents(aio_context_t ctx_id, long min_nr, long nr, struct io_event *events, struct timespec *timeout)
{
    return (int)raw_syscall(SYS_io_getevents, ctx_id, min_nr, nr, events, timeout);
}
#endif

#ifdef SYS_io_pgetevents
LINUX_SYSCALL_API int io_pgetevents(aio_context_t ctx_id, long min_nr, long nr, struct io_event *events, struct timespec *timeout, const sigset_t *sigmask)
{
    return (int)raw_syscall(SYS_io_pgetevents, ctx_id, min_nr, nr, events, timeout, sigmask);
}
#endif

#ifdef SYS_io_uring_setup
LINUX_SYSCALL_API int io_uring_setup(unsigned int entries, struct io_uring_params *p)
{
    return (int)raw_syscall(SYS_io_uring_setup, entries, p);
}
#endif

#ifdef SYS_io_uring_enter
LINUX_SYSCALL_API int io_uring_enter(unsigned int fd, unsigned int to_submit, unsigned int min_complete, unsigned int flags, sigset_t *sig)
{
    /* The kernel ABI has a sixth argsz argument; linux.h intentionally
       keeps the public wrapper compatible with the five-argument form. */
    return (int)raw_syscall(SYS_io_uring_enter, fd, to_submit, min_complete, flags, sig,
                            sig ? sizeof(sigset_t) : 0);
}
#endif

#ifdef SYS_io_uring_register
LINUX_SYSCALL_API int io_uring_register(unsigned int fd, unsigned int opcode, void *arg, unsigned int nr_args)
{
    return (int)raw_syscall(SYS_io_uring_register, fd, opcode, arg, nr_args);
}
#endif

#ifdef SYS_inotify_init
LINUX_SYSCALL_API int inotify_init(void)
{
    return (int)raw_syscall(SYS_inotify_init);
}
#endif

#ifdef SYS_inotify_init1
LINUX_SYSCALL_API int inotify_init1(int flags)
{
    return (int)raw_syscall(SYS_inotify_init1, flags);
}
#endif

#ifdef SYS_inotify_add_watch
LINUX_SYSCALL_API int inotify_add_watch(int fd, const char *pathname, uint32_t mask)
{
    return (int)raw_syscall(SYS_inotify_add_watch, fd, pathname, mask);
}
#endif

#ifdef SYS_inotify_rm_watch
LINUX_SYSCALL_API int inotify_rm_watch(int fd, int wd)
{
    return (int)raw_syscall(SYS_inotify_rm_watch, fd, wd);
}
#endif

#ifdef SYS_fanotify_init
LINUX_SYSCALL_API int fanotify_init(unsigned int flags, unsigned int event_f_flags)
{
    return (int)raw_syscall(SYS_fanotify_init, flags, event_f_flags);
}
#endif

#ifdef SYS_fanotify_mark
LINUX_SYSCALL_API int fanotify_mark(int fanotify_fd, unsigned int flags, uint64_t mask, int dirfd, const char *pathname)
{
    return (int)raw_syscall(SYS_fanotify_mark, fanotify_fd, flags, mask, dirfd, pathname);
}
#endif

#ifdef SYS_uname
LINUX_SYSCALL_API int uname(struct utsname *buf)
{
    return (int)raw_syscall(SYS_uname, buf);
}
#endif

#ifdef SYS_sysinfo
LINUX_SYSCALL_API int sysinfo(struct sysinfo *info)
{
    return (int)raw_syscall(SYS_sysinfo, info);
}
#endif

#ifdef SYS_syslog
LINUX_SYSCALL_API int syslog(int type, char *bufp, int len)
{
    return (int)raw_syscall(SYS_syslog, type, bufp, len);
}
#endif

#ifdef SYS_reboot
LINUX_SYSCALL_API int reboot(int magic, int magic2, int cmd, void *arg)
{
    return (int)raw_syscall(SYS_reboot, magic, magic2, cmd, arg);
}
#endif

#ifdef SYS_vhangup
LINUX_SYSCALL_API int vhangup(void)
{
    return (int)raw_syscall(SYS_vhangup);
}
#endif

#ifdef SYS_acct
LINUX_SYSCALL_API int acct(const char *filename)
{
    return (int)raw_syscall(SYS_acct, filename);
}
#endif

#ifdef SYS_personality
LINUX_SYSCALL_API int personality(unsigned long persona)
{
    return (int)raw_syscall(SYS_personality, persona);
}
#endif

#ifdef SYS_sethostname
LINUX_SYSCALL_API int sethostname(const char *name, size_t len)
{
    return (int)raw_syscall(SYS_sethostname, name, len);
}
#endif

#ifdef SYS_setdomainname
LINUX_SYSCALL_API int setdomainname(const char *name, size_t len)
{
    return (int)raw_syscall(SYS_setdomainname, name, len);
}
#endif

#ifdef SYS_iopl
LINUX_SYSCALL_API int iopl(int level)
{
    return (int)raw_syscall(SYS_iopl, level);
}
#endif

#ifdef SYS_ioperm
LINUX_SYSCALL_API int ioperm(unsigned long from, unsigned long num, int turn_on)
{
    return (int)raw_syscall(SYS_ioperm, from, num, turn_on);
}
#endif

#ifdef SYS_init_module
LINUX_SYSCALL_API int init_module(void *module_image, unsigned long len, const char *param_values)
{
    return (int)raw_syscall(SYS_init_module, module_image, len, param_values);
}
#endif

#ifdef SYS_finit_module
LINUX_SYSCALL_API int finit_module(int fd, const char *param_values, int flags)
{
    return (int)raw_syscall(SYS_finit_module, fd, param_values, flags);
}
#endif

#ifdef SYS_delete_module
LINUX_SYSCALL_API int delete_module(const char *name, int flags)
{
    return (int)raw_syscall(SYS_delete_module, name, flags);
}
#endif

#ifdef SYS_bpf
LINUX_SYSCALL_API int bpf(int cmd, union bpf_attr *attr, unsigned int size)
{
    return (int)raw_syscall(SYS_bpf, cmd, attr, size);
}
#endif

#ifdef SYS_userfaultfd
LINUX_SYSCALL_API int userfaultfd(int flags)
{
    return (int)raw_syscall(SYS_userfaultfd, flags);
}
#endif

#ifdef SYS_membarrier
LINUX_SYSCALL_API int membarrier(int cmd, unsigned int flags, int cpu_id)
{
    return (int)raw_syscall(SYS_membarrier, cmd, flags, cpu_id);
}
#endif

#ifdef SYS_add_key
LINUX_SYSCALL_API key_serial_t add_key(const char *type, const char *description, const void *payload, size_t plen, key_serial_t keyring)
{
    return (key_serial_t)raw_syscall(SYS_add_key, type, description, payload, plen, keyring);
}
#endif

#ifdef SYS_request_key
LINUX_SYSCALL_API key_serial_t request_key(const char *type, const char *description, const char *callout_info, key_serial_t dest_keyring)
{
    return (key_serial_t)raw_syscall(SYS_request_key, type, description, callout_info, dest_keyring);
}
#endif

#ifdef SYS_keyctl
LINUX_SYSCALL_API long keyctl(int operation, unsigned long arg2, unsigned long arg3, unsigned long arg4, unsigned long arg5)
{
    return (long)raw_syscall(SYS_keyctl, operation, arg2, arg3, arg4, arg5);
}
#endif

#ifdef SYS_seccomp
LINUX_SYSCALL_API int seccomp(unsigned int operation, unsigned int flags, void *args)
{
    return (int)raw_syscall(SYS_seccomp, operation, flags, args);
}
#endif

#ifdef SYS_landlock_restrict_self
LINUX_SYSCALL_API int landlock_restrict_self(int ruleset_fd, uint32_t flags)
{
    return (int)raw_syscall(SYS_landlock_restrict_self, ruleset_fd, flags);
}
#endif

#ifdef SYS_lsm_list_modules
LINUX_SYSCALL_API int lsm_list_modules(uint64_t *ids, size_t *size, uint32_t flags)
{
    return (int)raw_syscall(SYS_lsm_list_modules, ids, size, flags);
}
#endif

#ifdef SYS_getrandom
LINUX_SYSCALL_API ssize_t getrandom(void *buf, size_t buflen, unsigned int flags)
{
    return (ssize_t)raw_syscall(SYS_getrandom, buf, buflen, flags);
}
#endif

#ifdef SYS_ptrace
LINUX_SYSCALL_API long ptrace(int request, pid_t pid, void *addr, void *data)
{
    return (long)raw_syscall(SYS_ptrace, request, pid, addr, data);
}
#endif

#ifdef SYS_perf_event_open
LINUX_SYSCALL_API int perf_event_open(struct perf_event_attr *attr, pid_t pid, int cpu, int group_fd, unsigned long flags)
{
    return (int)raw_syscall(SYS_perf_event_open, attr, pid, cpu, group_fd, flags);
}
#endif

#ifdef SYS_getcpu
LINUX_SYSCALL_API int getcpu(unsigned int *cpu, unsigned int *node, struct getcpu_cache *tcache)
{
    return (int)raw_syscall(SYS_getcpu, cpu, node, tcache);
}
#endif

#ifdef SYS_cachestat
LINUX_SYSCALL_API int cachestat(unsigned int fd, struct cachestat_range *crange, struct cachestat *cstat, unsigned int flags)
{
    return (int)raw_syscall(SYS_cachestat, fd, crange, cstat, flags);
}
#endif

#ifdef SYS_file_getattr
LINUX_SYSCALL_API int file_getattr(int fd, unsigned int mask, struct file_handle *handle, size_t *handle_bytes)
{
    return (int)raw_syscall(SYS_file_getattr, fd, mask, handle, handle_bytes);
}
#endif

#ifdef SYS_file_setattr
LINUX_SYSCALL_API int file_setattr(int fd, unsigned int mask, struct file_handle *handle, size_t handle_bytes)
{
    return (int)raw_syscall(SYS_file_setattr, fd, mask, handle, handle_bytes);
}
#endif

#ifdef SYS_listns
LINUX_SYSCALL_API int listns(int nstype, struct namespace_entry *entries, unsigned int max_entries, unsigned int flags)
{
    return (int)raw_syscall(SYS_listns, nstype, entries, max_entries, flags);
}
#endif

#ifdef __cplusplus
}
#endif

#endif /* _LINUX_IMPL_H */
