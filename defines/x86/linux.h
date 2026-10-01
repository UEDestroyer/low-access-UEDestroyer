#pragma once

// ============================================================
//  syscall numbers — x86 (i386) linux (32-bit ia-32 abi)
//  calling convention: eax=nr, ebx,ecx,edx,esi,edi,ebp=args
//  entry:              int 0x80  (or sysenter on modern cpus)
//  return:             eax (negative = -errno)
//  source:             linux/arch/x86/entry/syscalls/syscall_32.tbl
//  note:               64-bit offsets use _llseek / mmap2 / *64 variants
// ============================================================

// ─── file i/o ────────────────────────────────────────────────
#define SYS_restart_syscall     0    // restart_syscall()                  — restart interrupted syscall after signal
#define SYS_exit                1    // exit(status)                       — terminate current thread
#define SYS_fork                2    // fork()                             — duplicate process
#define SYS_read                3    // read(fd, buf, count)               — read bytes from fd
#define SYS_write               4    // write(fd, buf, count)              — write bytes to fd
#define SYS_open                5    // open(path, flags, mode)            — open or create file
#define SYS_close               6    // close(fd)                          — close file descriptor
#define SYS_waitpid             7    // waitpid(pid, wstatus, opts)        — wait for child (deprecated, use wait4)
#define SYS_creat               8    // creat(path, mode)                  — create file (= open O_WRONLY|O_CREAT|O_TRUNC)
#define SYS_link                9    // link(oldpath, newpath)             — create hard link
#define SYS_unlink              10   // unlink(path)                       — remove filename
#define SYS_execve              11   // execve(path, argv, envp)           — replace process image
#define SYS_chdir               12   // chdir(path)                        — change working directory
#define SYS_time                13   // time(tloc)                         — get unix timestamp in seconds
#define SYS_mknod               14   // mknod(path, mode, dev)             — create special file
#define SYS_chmod               15   // chmod(path, mode)                  — change file permissions
#define SYS_lchown              16   // lchown(path, uid, gid)             — change owner without following symlink
#define SYS_lseek               19   // lseek(fd, offset, whence)          — reposition file offset (32-bit)
#define SYS_getpid              20   // getpid()                           — get process id
#define SYS_mount               21   // mount(src, tgt, fs, fl, data)      — mount filesystem
#define SYS_umount              22   // umount(target)                     — unmount (deprecated, use umount2)
#define SYS_setuid              23   // setuid(uid)                        — set user id
#define SYS_getuid              24   // getuid()                           — get real user id
#define SYS_alarm               27   // alarm(seconds)                     — schedule SIGALRM
#define SYS_pause               29   // pause()                            — wait for any signal
#define SYS_utime               30   // utime(path, times)                 — set file timestamps (deprecated)
#define SYS_access              33   // access(path, mode)                 — check file access permissions
#define SYS_nice                34   // nice(inc)                          — change process priority (deprecated, use setpriority)
#define SYS_sync                36   // sync()                             — flush all filesystem caches
#define SYS_kill                37   // kill(pid, sig)                     — send signal to process
#define SYS_rename              38   // rename(oldpath, newpath)           — rename or move file
#define SYS_mkdir               39   // mkdir(path, mode)                  — create directory
#define SYS_rmdir               40   // rmdir(path)                        — remove empty directory
#define SYS_dup                 41   // dup(fd)                            — duplicate fd to lowest free number
#define SYS_pipe                42   // pipe(pipefd)                       — create unidirectional pipe
#define SYS_times               43   // times(tbuf)                        — get process cpu times
#define SYS_brk                 45   // brk(addr)                          — change data segment end
#define SYS_setgid              46   // setgid(gid)                        — set group id
#define SYS_getgid              47   // getgid()                           — get real group id
#define SYS_geteuid             49   // geteuid()                          — get effective user id
#define SYS_getegid             50   // getegid()                          — get effective group id
#define SYS_acct                51   // acct(path)                         — enable/disable process accounting
#define SYS_umount2             52   // umount2(target, flags)             — unmount with flags
#define SYS_ioctl               54   // ioctl(fd, request, ...)            — device-specific control
#define SYS_fcntl               55   // fcntl(fd, cmd, ...)                — manipulate file descriptor
#define SYS_setpgid             57   // setpgid(pid, pgid)                 — set process group id
#define SYS_umask               60   // umask(mask)                        — set file creation mask
#define SYS_chroot              61   // chroot(path)                       — change filesystem root
#define SYS_dup2                63   // dup2(oldfd, newfd)                 — duplicate fd to specific number
#define SYS_getppid             64   // getppid()                          — get parent process id
#define SYS_getpgrp             65   // getpgrp()                          — get current process group
#define SYS_setsid              66   // setsid()                           — create new session
#define SYS_sigaction           67   // sigaction(sig, act, oact)          — signal handler (old abi, use rt_sigaction)
#define SYS_setreuid            70   // setreuid(ruid, euid)               — set real and effective uid
#define SYS_setregid            71   // setregid(rgid, egid)               — set real and effective gid
#define SYS_sigsuspend          72   // sigsuspend(mask)                   — wait for signal with mask (old abi)
#define SYS_sigpending          73   // sigpending(set)                    — get pending signals (old abi)
#define SYS_sethostname         74   // sethostname(name, len)             — set hostname
#define SYS_setrlimit           75   // setrlimit(res, rlim)               — set resource limit
#define SYS_old_getrlimit       76   // getrlimit(res, rlim)               — deprecated, use ugetrlimit
#define SYS_getrusage           77   // getrusage(who, rusage)             — get resource usage
#define SYS_gettimeofday        78   // gettimeofday(tv, tz)               — get current time (microseconds)
#define SYS_settimeofday        79   // settimeofday(tv, tz)               — set current time
#define SYS_getgroups           80   // getgroups(size, list)              — get supplementary groups
#define SYS_setgroups           81   // setgroups(size, list)              — set supplementary groups
#define SYS_symlink             83   // symlink(oldpath, newpath)          — create symbolic link
#define SYS_readlink            85   // readlink(path, buf, bufsiz)        — read symlink target
#define SYS_uselib              86   // uselib(lib)                        — load shared library (deprecated)
#define SYS_swapon              87   // swapon(path, swapflags)            — enable swap area
#define SYS_reboot              88   // reboot(magic, magic2, cmd, arg)    — reboot or power off
#define SYS_readdir             89   // readdir(fd, dirent, count)         — read directory entry (deprecated, use getdents)
#define SYS_mmap                90   // mmap(addr, len, prot, fl, fd, off) — map memory (32-bit offset)
#define SYS_munmap              91   // munmap(addr, len)                  — unmap memory region
#define SYS_truncate            92   // truncate(path, length)             — set file size
#define SYS_ftruncate           93   // ftruncate(fd, length)              — set file size by fd
#define SYS_fchmod              94   // fchmod(fd, mode)                   — change permissions by fd
#define SYS_fchown              95   // fchown(fd, uid, gid)               — change owner by fd
#define SYS_getpriority         96   // getpriority(which, who)            — get scheduling priority
#define SYS_setpriority         97   // setpriority(which, who, prio)      — set scheduling priority (nice)
#define SYS_stat                106  // stat(path, statbuf)                — get file metadata
#define SYS_fstat               108  // fstat(fd, statbuf)                 — get file metadata by fd
#define SYS_lstat               107  // lstat(path, statbuf)               — stat without following symlink
#define SYS_vhangup             111  // vhangup()                          — hang up current terminal
#define SYS_wait4               114  // wait4(pid, wstatus, opts, rusage)  — wait for child with resource usage
#define SYS_swapoff             115  // swapoff(path)                      — disable swap area
#define SYS_sysinfo             116  // sysinfo(info)                      — overall system statistics
#define SYS_ipc                 117  // ipc(call, ...)                     — sysv ipc multiplexer (sem/shm/msg via one nr)
#define SYS_fsync               118  // fsync(fd)                          — flush data and metadata to disk
#define SYS_sigreturn           119  // sigreturn()                        — return from signal handler (old abi)
#define SYS_clone               120  // clone(flags, stack, ptid, ctid)    — create thread or process
#define SYS_setdomainname       121  // setdomainname(name, len)           — set nis domain name
#define SYS_uname               122  // uname(buf)                         — get kernel/os information
#define SYS_mprotect            125  // mprotect(addr, len, prot)          — set memory region permissions
#define SYS_sigprocmask         126  // sigprocmask(how, set, oset)        — get/set signal mask (old abi)
#define SYS_init_module         128  // init_module(umod, len, uargs)      — load kernel module
#define SYS_delete_module       129  // delete_module(name, flags)         — unload kernel module
#define SYS_quotactl            131  // quotactl(cmd, special, id, addr)   — manage disk quotas
#define SYS_getpgid             132  // getpgid(pid)                       — get process group id
#define SYS_fchdir              133  // fchdir(fd)                         — change directory via fd
#define SYS_personality         136  // personality(persona)               — change process execution domain
#define SYS_setfsuid            138  // setfsuid(uid)                      — set filesystem uid
#define SYS_setfsgid            139  // setfsgid(gid)                      — set filesystem gid
#define SYS__llseek             140  // _llseek(fd, hi, lo, result, whence) — 64-bit seek on 32-bit system
#define SYS_getdents            141  // getdents(fd, dirent, count)        — read directory entries (deprecated)
#define SYS__newselect          142  // _newselect(n, r, w, e, tv)         — select() implementation
#define SYS_flock               143  // flock(fd, operation)               — advisory file lock
#define SYS_msync               144  // msync(addr, len, flags)            — sync mapping to file
#define SYS_readv               145  // readv(fd, iov, iovcnt)             — scatter read
#define SYS_writev              146  // writev(fd, iov, iovcnt)            — gather write
#define SYS_getsid              147  // getsid(pid)                        — get session id
#define SYS_fdatasync           148  // fdatasync(fd)                      — flush data without metadata
#define SYS_mlock               150  // mlock(addr, len)                   — lock pages in ram
#define SYS_munlock             151  // munlock(addr, len)                 — unlock pages
#define SYS_mlockall            152  // mlockall(flags)                    — lock all process memory
#define SYS_munlockall          153  // munlockall()                       — unlock all process memory
#define SYS_sched_setparam      154  // sched_setparam(pid, param)         — set scheduler parameters
#define SYS_sched_getparam      155  // sched_getparam(pid, param)
#define SYS_sched_setscheduler  156  // sched_setscheduler(pid, pol, param)
#define SYS_sched_getscheduler  157  // sched_getscheduler(pid)
#define SYS_sched_yield         158  // sched_yield()                      — voluntarily give up cpu
#define SYS_sched_get_priority_max 159
#define SYS_sched_get_priority_min 160
#define SYS_sched_rr_get_interval  161
#define SYS_nanosleep           162  // nanosleep(req, rem)                — sleep with nanosecond precision
#define SYS_mremap              163  // mremap(old, osz, nsz, flags, new)  — resize mapping
#define SYS_setresuid           164  // setresuid(ruid, euid, suid)
#define SYS_getresuid           165  // getresuid(ruid, euid, suid)
#define SYS_poll                168  // poll(fds, nfds, timeout)           — wait for events on fds
#define SYS_setresgid           170  // setresgid(rgid, egid, sgid)
#define SYS_getresgid           171  // getresgid(rgid, egid, sgid)
#define SYS_prctl               172  // prctl(option, ...)                 — control process attributes
#define SYS_rt_sigreturn        173  // rt_sigreturn()                     — return from signal handler (eabi)
#define SYS_rt_sigaction        174  // rt_sigaction(sig, act, oact, sz)   — install signal handler
#define SYS_rt_sigprocmask      175  // rt_sigprocmask(how, set, oset, sz) — get/set blocked signals
#define SYS_rt_sigpending       176  // rt_sigpending(set, sz)
#define SYS_rt_sigtimedwait     177  // rt_sigtimedwait(set, info, ts, sz)
#define SYS_rt_sigqueueinfo     178  // rt_sigqueueinfo(pid, sig, info)
#define SYS_rt_sigsuspend       179  // rt_sigsuspend(mask, sz)
#define SYS_pread64             180  // pread64(fd, buf, count, off)       — read at offset
#define SYS_pwrite64            181  // pwrite64(fd, buf, count, off)      — write at offset
#define SYS_chown               182  // chown(path, uid, gid)              — change file owner
#define SYS_getcwd              183  // getcwd(buf, size)                  — get current directory
#define SYS_capget              184  // capget(hdr, data)                  — get process capabilities
#define SYS_capset              185  // capset(hdr, data)
#define SYS_sigaltstack         186  // sigaltstack(ss, oss)               — alternate signal stack
#define SYS_sendfile            187  // sendfile(outfd, infd, off, count)  — zero-copy file send
#define SYS_vfork               190  // vfork()                            — fork without memory copy
#define SYS_ugetrlimit          191  // ugetrlimit(resource, rlim)         — get resource limit
#define SYS_mmap2               192  // mmap2(addr, len, prot, fl, fd, pgoff) — mmap with offset in pages (not bytes!)
#define SYS_truncate64          193  // truncate64(path, length)           — set file size (64-bit length)
#define SYS_ftruncate64         194  // ftruncate64(fd, length)
#define SYS_stat64              195  // stat64(path, statbuf)              — file metadata (64-bit sizes)
#define SYS_lstat64             196  // lstat64(path, statbuf)
#define SYS_fstat64             197  // fstat64(fd, statbuf)
#define SYS_lchown32            198  // lchown32(path, uid, gid)           — 32-bit uid/gid variant
#define SYS_getuid32            199  // getuid32()                         — get real uid (32-bit)
#define SYS_getgid32            200  // getgid32()
#define SYS_geteuid32           201  // geteuid32()
#define SYS_getegid32           202  // getegid32()
#define SYS_setreuid32          203  // setreuid32(ruid, euid)
#define SYS_setregid32          204  // setregid32(rgid, egid)
#define SYS_getgroups32         205  // getgroups32(size, list)
#define SYS_setgroups32         206  // setgroups32(size, list)
#define SYS_fchown32            207  // fchown32(fd, uid, gid)
#define SYS_setresuid32         208  // setresuid32(ruid, euid, suid)
#define SYS_getresuid32         209  // getresuid32(ruid, euid, suid)
#define SYS_setresgid32         210  // setresgid32(rgid, egid, sgid)
#define SYS_getresgid32         211  // getresgid32(rgid, egid, sgid)
#define SYS_chown32             212  // chown32(path, uid, gid)
#define SYS_setuid32            213  // setuid32(uid)
#define SYS_setgid32            214  // setgid32(gid)
#define SYS_setfsuid32          215  // setfsuid32(uid)
#define SYS_setfsgid32          216  // setfsgid32(gid)
#define SYS_getdents64          220  // getdents64(fd, dirent, count)      — read directory entries (64-bit)
#define SYS_gettid              224  // gettid()                           — get thread id
#define SYS_readahead           225  // readahead(fd, offset, count)       — prefetch file data
#define SYS_setxattr            226  // setxattr(path, name, val, sz, fl)  — set extended attribute
#define SYS_lsetxattr           227  // lsetxattr(path, name, val, sz, fl)
#define SYS_fsetxattr           228  // fsetxattr(fd, name, val, sz, fl)
#define SYS_getxattr            229  // getxattr(path, name, val, sz)      — get extended attribute
#define SYS_lgetxattr           230  // lgetxattr(path, name, val, sz)
#define SYS_fgetxattr           231  // fgetxattr(fd, name, val, sz)
#define SYS_listxattr           232  // listxattr(path, list, sz)          — list extended attribute names
#define SYS_llistxattr          233  // llistxattr(path, list, sz)
#define SYS_flistxattr          234  // flistxattr(fd, list, sz)
#define SYS_removexattr         235  // removexattr(path, name)            — remove extended attribute
#define SYS_lremovexattr        236  // lremovexattr(path, name)
#define SYS_fremovexattr        237  // fremovexattr(fd, name)
#define SYS_tkill               238  // tkill(tid, sig)                    — send signal to thread
#define SYS_sendfile64          239  // sendfile64(outfd, infd, off, count) — sendfile with 64-bit offset
#define SYS_futex               240  // futex(uaddr, op, val, to, uaddr2, v3) — fast userspace mutex
#define SYS_sched_setaffinity   241  // sched_setaffinity(pid, sz, mask)   — bind to cpu set
#define SYS_sched_getaffinity   242  // sched_getaffinity(pid, sz, mask)
#define SYS_set_thread_area     243  // set_thread_area(u_info)            — set tls segment (gs/fs)
#define SYS_get_thread_area     244  // get_thread_area(u_info)
#define SYS_io_setup            245  // io_setup(nr_events, ctxp)          — initialize aio context
#define SYS_io_destroy          246  // io_destroy(ctx)
#define SYS_io_getevents        247  // io_getevents(ctx, min, max, evs, to)
#define SYS_io_submit           248  // io_submit(ctx, nr, iocbpp)
#define SYS_io_cancel           249  // io_cancel(ctx, iocb, result)
#define SYS_fadvise64           250  // fadvise64(fd, off, len, advice)    — hint about file access pattern
#define SYS_exit_group          252  // exit_group(status)                 — terminate all threads in process
#define SYS_epoll_create        254  // epoll_create(size)                 — create epoll fd
#define SYS_epoll_ctl           255  // epoll_ctl(epfd, op, fd, event)
#define SYS_epoll_wait          256  // epoll_wait(epfd, evts, max, to)
#define SYS_set_tid_address     258  // set_tid_address(tidptr)            — set address to clear on exit
#define SYS_timer_create        259  // timer_create(clkid, evp, tid)      — create posix timer
#define SYS_timer_settime       260  // timer_settime(tid, fl, new, old)
#define SYS_timer_gettime       261  // timer_gettime(tid, curr)
#define SYS_timer_getoverrun    262  // timer_getoverrun(tid)
#define SYS_timer_delete        263  // timer_delete(tid)
#define SYS_clock_settime       264  // clock_settime(clkid, tp)
#define SYS_clock_gettime       265  // clock_gettime(clkid, tp)
#define SYS_clock_getres        266  // clock_getres(clkid, res)
#define SYS_clock_nanosleep     267  // clock_nanosleep(clk, fl, req, rem)
#define SYS_statfs64            268  // statfs64(path, sz, buf)            — filesystem stats (64-bit)
#define SYS_fstatfs64           269  // fstatfs64(fd, sz, buf)
#define SYS_tgkill              270  // tgkill(tgid, tid, sig)             — send signal to thread with group check
#define SYS_utimes              271  // utimes(path, times)                — set file timestamps
#define SYS_waitid              284  // waitid(type, id, infop, opts)      — wait with extended info
#define SYS_openat              295  // openat(dirfd, path, flags, mode)   — open relative to dirfd
#define SYS_mkdirat             296  // mkdirat(dirfd, path, mode)
#define SYS_mknodat             297  // mknodat(dirfd, path, mode, dev)
#define SYS_fchownat            298  // fchownat(dirfd, path, uid, gid, fl)
#define SYS_fstatat64           300  // fstatat64(dirfd, path, buf, fl)    — stat relative to dirfd
#define SYS_unlinkat            301  // unlinkat(dirfd, path, flags)
#define SYS_renameat            302  // renameat(odfd, op, ndfd, np)
#define SYS_linkat              303  // linkat(odfd, op, ndfd, np, fl)
#define SYS_symlinkat           304  // symlinkat(target, newdfd, linkp)
#define SYS_readlinkat          305  // readlinkat(dirfd, path, buf, sz)
#define SYS_fchmodat            306  // fchmodat(dirfd, path, mode, fl)
#define SYS_faccessat           307  // faccessat(dirfd, path, mode, fl)
#define SYS_pselect6            308  // pselect6(n, r, w, e, ts, sigmask)
#define SYS_ppoll               309  // ppoll(fds, nfds, ts, sigmask)
#define SYS_unshare             310  // unshare(flags)                     — disassociate namespaces
#define SYS_set_robust_list     311  // set_robust_list(head, len)         — register robust futex list
#define SYS_get_robust_list     312  // get_robust_list(pid, head, len)
#define SYS_splice              313  // splice(fdin, offin, fdout, offout, len, fl)
#define SYS_sync_file_range     314  // sync_file_range(fd, off, nb, fl)   — partial file sync
#define SYS_tee                 315  // tee(fdin, fdout, len, flags)
#define SYS_vmsplice            316  // vmsplice(fd, iov, cnt, fl)
#define SYS_move_pages          317  // move_pages(pid, nr, pages, nodes, status, fl)
#define SYS_getcpu              318  // getcpu(cpup, nodep, tcache)        — get current cpu and numa node
#define SYS_epoll_pwait         319  // epoll_pwait(epfd, evts, max, to, sm)
#define SYS_utimensat           320  // utimensat(dirfd, path, times, fl)  — set timestamps (nanosecond precision)
#define SYS_signalfd            321  // signalfd(fd, mask, sz)
#define SYS_timerfd_create      322  // timerfd_create(clockid, flags)
#define SYS_eventfd             323  // eventfd(initval)
#define SYS_fallocate           324  // fallocate(fd, mode, off, len)      — preallocate file space
#define SYS_timerfd_settime     325  // timerfd_settime(fd, fl, new, old)
#define SYS_timerfd_gettime     326  // timerfd_gettime(fd, curr)
#define SYS_signalfd4           327  // signalfd4(fd, mask, sz, flags)
#define SYS_eventfd2            328  // eventfd2(initval, flags)
#define SYS_epoll_create1       329  // epoll_create1(flags)
#define SYS_dup3                330  // dup3(oldfd, newfd, flags)
#define SYS_pipe2               331  // pipe2(pipefd, flags)
#define SYS_inotify_init1       332  // inotify_init1(flags)
#define SYS_preadv              333  // preadv(fd, iov, iovcnt, off_lo, off_hi)
#define SYS_pwritev             334  // pwritev(fd, iov, iovcnt, off_lo, off_hi)
#define SYS_rt_tgsigqueueinfo   335  // rt_tgsigqueueinfo(tgid, tid, sig, info)
#define SYS_perf_event_open     336  // perf_event_open(attr, pid, cpu, gfd, fl)
#define SYS_recvmmsg            337  // recvmmsg(sockfd, msgvec, vlen, fl, to)
#define SYS_accept4             338  // accept4(sockfd, addr, addrlen, fl)
#define SYS_fanotify_init       339  // fanotify_init(flags, event_f_flags)
#define SYS_fanotify_mark       340  // fanotify_mark(fd, fl, mask, dfd, path)
#define SYS_prlimit64           341  // prlimit64(pid, res, new, old)      — get/set resource limits
#define SYS_name_to_handle_at   342  // name_to_handle_at(dfd, path, fh, mnt_id, fl)
#define SYS_open_by_handle_at   343  // open_by_handle_at(mfd, fh, flags)
#define SYS_clock_adjtime       344  // clock_adjtime(clkid, tx)           — tune clock
#define SYS_syncfs              345  // syncfs(fd)                         — flush specific filesystem
#define SYS_sendmmsg            346  // sendmmsg(sockfd, msgvec, vlen, fl) — batch send
#define SYS_setns               347  // setns(fd, nstype)                  — join namespace
#define SYS_process_vm_readv    347  // process_vm_readv(pid, lvec, ...)   — read another process memory
#define SYS_process_vm_writev   348  // process_vm_writev(pid, ...)        — write another process memory
#define SYS_kcmp                349  // kcmp(pid1, pid2, type, idx1, idx2) — compare process resources
#define SYS_finit_module        350  // finit_module(fd, uargs, flags)     — load kernel module from fd
#define SYS_sched_setattr       351  // sched_setattr(pid, attr, flags)
#define SYS_sched_getattr       352  // sched_getattr(pid, attr, sz, flags)
#define SYS_renameat2           353  // renameat2(odfd, op, ndfd, np, flags)
#define SYS_seccomp             354  // seccomp(op, flags, uargs)          — restrict syscalls
#define SYS_getrandom           355  // getrandom(buf, count, flags)       — get random bytes
#define SYS_memfd_create        356  // memfd_create(name, flags)          — anonymous file in ram
#define SYS_bpf                 357  // bpf(cmd, attr, size)               — ebpf programs and maps
#define SYS_execveat            358  // execveat(dirfd, path, argv, envp, fl)
#define SYS_socket              359  // socket(domain, type, protocol)     — create socket (new socket abi)
#define SYS_socketpair          360  // socketpair(dom, type, proto, sv)
#define SYS_bind                361  // bind(s, addr, addrlen)
#define SYS_connect             362  // connect(s, name, namelen)
#define SYS_listen              363  // listen(s, backlog)
#define SYS_accept4             364  // accept4(s, addr, addrlen, fl)
#define SYS_getsockopt          365  // getsockopt(s, lvl, opt, val, len)
#define SYS_setsockopt          366  // setsockopt(s, lvl, opt, val, len)
#define SYS_getsockname         367  // getsockname(s, name, namelen)
#define SYS_getpeername         368  // getpeername(s, name, namelen)
#define SYS_sendto              369  // sendto(s, buf, len, fl, to, tlen)
#define SYS_sendmsg             370  // sendmsg(s, msg, flags)
#define SYS_recvfrom            371  // recvfrom(s, buf, len, fl, from, fromlen)
#define SYS_recvmsg             372  // recvmsg(s, msg, flags)
#define SYS_shutdown            373  // shutdown(s, how)
#define SYS_userfaultfd         374  // userfaultfd(flags)                 — handle page faults in userspace
#define SYS_membarrier          375  // membarrier(cmd, flags)             — memory barriers between threads
#define SYS_mlock2              376  // mlock2(addr, len, flags)
#define SYS_copy_file_range     377  // copy_file_range(fdin, offin, fdout, offout, len, fl)
#define SYS_preadv2             378  // preadv2(fd, iov, iovcnt, off_lo, off_hi, fl)
#define SYS_pwritev2            379  // pwritev2(fd, iov, iovcnt, off_lo, off_hi, fl)
#define SYS_pkey_mprotect       380  // pkey_mprotect(addr, len, prot, pkey) — mprotect with memory protection key
#define SYS_pkey_alloc          381  // pkey_alloc(flags, access_rights)   — allocate memory protection key
#define SYS_pkey_free           382  // pkey_free(pkey)
#define SYS_statx               383  // statx(dirfd, path, flags, mask, statxbuf) — extended stat
#define SYS_arch_prctl          384  // arch_prctl(code, addr)             — x86-specific process attributes
#define SYS_io_pgetevents       385  // io_pgetevents(ctx, min, max, evs, to, usig)
#define SYS_rseq                386  // rseq(rseq, rseq_len, flags, sig)   — restartable sequences
#define SYS_semget              393  // semget(key, nsems, semflg)         — sysv semaphore (new abi)
#define SYS_semctl              394  // semctl(semid, semnum, cmd, ...)
#define SYS_shmget              395  // shmget(key, size, fl)
#define SYS_shmctl              396  // shmctl(shmid, cmd, buf)
#define SYS_shmat               397  // shmat(shmid, addr, fl)
#define SYS_shmdt               398  // shmdt(shmaddr)
#define SYS_msgget              399  // msgget(key, msgflg)
#define SYS_msgsnd              400  // msgsnd(msqid, msgp, msgsz, fl)
#define SYS_msgrcv              401  // msgrcv(msqid, msgp, msgsz, ...)
#define SYS_msgctl              402  // msgctl(msqid, cmd, buf)
#define SYS_clock_gettime64     403  // clock_gettime64(clkid, tp)         — y2038-safe variant
#define SYS_clock_settime64     404  // clock_settime64(clkid, tp)
#define SYS_clock_adjtime64     405  // clock_adjtime64(clkid, tx)
#define SYS_clock_getres_time64 406  // clock_getres_time64(clkid, res)
#define SYS_clock_nanosleep_time64 407 // clock_nanosleep_time64(clk, fl, req, rem)
#define SYS_timer_gettime64     408  // timer_gettime64(tid, curr)
#define SYS_timer_settime64     409  // timer_settime64(tid, fl, new, old)
#define SYS_timerfd_gettime64   410  // timerfd_gettime64(fd, curr)
#define SYS_timerfd_settime64   411  // timerfd_settime64(fd, fl, new, old)
#define SYS_utimensat_time64    412  // utimensat_time64(dfd, path, times, fl)
#define SYS_pselect6_time64     413  // pselect6_time64(n, r, w, e, ts, sigmask)
#define SYS_ppoll_time64        414  // ppoll_time64(fds, nfds, ts, sigmask)
#define SYS_io_pgetevents_time64 416 // io_pgetevents_time64(...)
#define SYS_recvmmsg_time64     417  // recvmmsg_time64(...)
#define SYS_mq_timedsend_time64 418  // mq_timedsend_time64(...)
#define SYS_mq_timedreceive_time64 419 // mq_timedreceive_time64(...)
#define SYS_semtimedop_time64   420  // semtimedop_time64(...)
#define SYS_rt_sigtimedwait_time64 421 // rt_sigtimedwait_time64(...)
#define SYS_futex_time64        422  // futex_time64(...)                  — y2038-safe futex
#define SYS_sched_rr_get_interval_time64 423
#define SYS_pidfd_send_signal   424  // pidfd_send_signal(pidfd, sig, info, fl)
#define SYS_io_uring_setup      425  // io_uring_setup(entries, params)    — create io_uring instance
#define SYS_io_uring_enter      426  // io_uring_enter(fd, to_submit, min, fl, argp, argsz)
#define SYS_io_uring_register   427  // io_uring_register(fd, op, arg, nr)
#define SYS_pidfd_open          434  // pidfd_open(pid, flags)
#define SYS_clone3              435  // clone3(args, size)                 — extended clone
#define SYS_close_range         436  // close_range(first, last, flags)    — close range of fds
#define SYS_openat2             437  // openat2(dirfd, path, how, size)
#define SYS_pidfd_getfd         438  // pidfd_getfd(pidfd, targetfd, flags)
#define SYS_faccessat2          439  // faccessat2(dirfd, path, mode, flags)
#define SYS_process_madvise     440  // process_madvise(pidfd, iov, cnt, behav, fl)
#define SYS_epoll_pwait2        441  // epoll_pwait2(epfd, evts, max, ts, mask)
#define SYS_landlock_create_ruleset 444
#define SYS_landlock_add_rule   445
#define SYS_landlock_restrict_self 446
#define SYS_memfd_secret        447  // memfd_secret(flags)                — secret memory region
#define SYS_futex_waitv         449  // futex_waitv(waiters, nr, fl, to, clk)
