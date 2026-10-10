#pragma once

// ============================================================
//  syscall numbers — x86_64 linux (amd64 system v abi)
//  calling convention: rax=nr, rdi,rsi,rdx,r10,r8,r9=args
//  entry:              syscall instruction
//  return:             rax (negative = -errno)
//  source:             linux/arch/x86/entry/syscalls/syscall_64.tbl
// ============================================================
#define LINUX_SIGSET_SIZE 8
// ─── file i/o ────────────────────────────────────────────────
#define SYS_read                0    // read(fd, buf, count)               — read bytes from fd into buf
#define SYS_write               1    // write(fd, buf, count)              — write bytes from buf to fd
#define SYS_open                2    // open(path, flags, mode)            — open or create a file, returns fd
#define SYS_close               3    // close(fd)                          — close a file descriptor
#define SYS_stat                4    // stat(path, statbuf)                — file metadata by path
#define SYS_fstat               5    // fstat(fd, statbuf)                 — file metadata by fd
#define SYS_lstat               6    // lstat(path, statbuf)               — stat without following symlink
#define SYS_poll                7    // poll(fds, nfds, timeout_ms)        — wait for events on a set of fds
#define SYS_lseek               8    // lseek(fd, offset, whence)          — reposition file offset
#define SYS_pread64             17   // pread64(fd, buf, count, off)       — read at offset, no position change
#define SYS_pwrite64            18   // pwrite64(fd, buf, count, off)      — write at offset, no position change
#define SYS_readv               19   // readv(fd, iov, iovcnt)             — scatter read into multiple buffers
#define SYS_writev              20   // writev(fd, iov, iovcnt)            — gather write from multiple buffers
#define SYS_preadv              295  // preadv(fd, iov, iovcnt, off_lo, off_hi)
#define SYS_pwritev             296  // pwritev(fd, iov, iovcnt, off_lo, off_hi)
#define SYS_preadv2             327  // preadv2(fd, iov, iovcnt, off_lo, off_hi, flags)
#define SYS_pwritev2            328  // pwritev2(fd, iov, iovcnt, off_lo, off_hi, flags)
#define SYS_pipe                22   // pipe(pipefd[2])                    — create a unidirectional pipe
#define SYS_pipe2               293  // pipe2(pipefd[2], flags)            — pipe with flags (O_CLOEXEC etc.)   since 2.6.27
#define SYS_dup                 32   // dup(oldfd)                         — duplicate fd to lowest free number
#define SYS_dup2                33   // dup2(oldfd, newfd)                 — duplicate fd to specific number
#define SYS_dup3                292  // dup3(oldfd, newfd, flags)          — dup2 with flags                    since 2.6.27
#define SYS_fcntl               72   // fcntl(fd, cmd, ...)                — manipulate file descriptor
#define SYS_ioctl               16   // ioctl(fd, request, ...)            — device-specific control
#define SYS_fsync               74   // fsync(fd)                          — flush data and metadata to disk
#define SYS_fdatasync           75   // fdatasync(fd)                      — flush data only, skip metadata
#define SYS_truncate            76   // truncate(path, length)             — set file size by path
#define SYS_ftruncate           77   // ftruncate(fd, length)              — set file size by fd
#define SYS_getdents            78   // getdents(fd, dirent, count)        — read directory entries (legacy)
#define SYS_getdents64          217  // getdents64(fd, dirent, count)      — read directory entries (64-bit)
#define SYS_getcwd              79   // getcwd(buf, size)                  — get current working directory
#define SYS_chdir               80   // chdir(path)                        — change working directory
#define SYS_fchdir              81   // fchdir(fd)                         — change working directory via fd
#define SYS_rename              82   // rename(oldpath, newpath)           — rename or move a file
#define SYS_mkdir               83   // mkdir(path, mode)                  — create a directory
#define SYS_rmdir               84   // rmdir(path)                        — remove an empty directory
#define SYS_creat               85   // creat(path, mode)                  — create/truncate (= open O_WRONLY|O_CREAT|O_TRUNC)
#define SYS_link                86   // link(oldpath, newpath)             — create a hard link
#define SYS_unlink              87   // unlink(path)                       — remove filename (file deleted when no links remain)
#define SYS_symlink             88   // symlink(target, linkpath)          — create a symbolic link
#define SYS_readlink            89   // readlink(path, buf, bufsiz)        — read symlink target path
#define SYS_chmod               90   // chmod(path, mode)                  — change file permissions by path
#define SYS_fchmod              91   // fchmod(fd, mode)                   — change file permissions by fd
#define SYS_chown               92   // chown(path, uid, gid)              — change file owner by path
#define SYS_fchown              93   // fchown(fd, uid, gid)               — change file owner by fd
#define SYS_lchown              94   // lchown(path, uid, gid)             — chown without following symlink
#define SYS_umask               95   // umask(mask)                        — set file creation permission mask
#define SYS_access              21   // access(path, mode)                 — check file access (uses real uid)
#define SYS_flock               73   // flock(fd, operation)               — apply or remove advisory file lock
#define SYS_select              23   // select(n, rfd, wfd, efd, tv)       — i/o multiplexing (legacy)
#define SYS_pselect6            270  // pselect6(n,r,w,e,ts,sigmask)       — select with nanoseconds and sigmask
#define SYS_ppoll               271  // ppoll(fds, nfds, ts, sigmask)      — poll with nanoseconds and sigmask
#define SYS_epoll_create        213  // epoll_create(size)                 — create epoll fd (size hint, ignored)
#define SYS_epoll_create1       291  // epoll_create1(flags)               — epoll_create with flags             since 2.6.27
#define SYS_epoll_ctl           233  // epoll_ctl(epfd, op, fd, event)     — add/modify/remove fd in epoll set
#define SYS_epoll_wait          232  // epoll_wait(epfd, evts, max, to)    — wait for epoll events
#define SYS_epoll_pwait         281  // epoll_pwait(epfd,evts,max,to,sm)   — epoll_wait with sigmask
#define SYS_epoll_pwait2        441  // epoll_pwait2(epfd,evts,max,ts,sm)  — epoll_pwait with timespec          since 5.11
#define SYS_sendfile            40   // sendfile(outfd, infd, off, cnt)    — zero-copy transfer between fds in kernel
#define SYS_openat              257  // openat(dirfd, path, flags, mode)   — open relative to dirfd
#define SYS_openat2             437  // openat2(dirfd, path, how, size)    — open with extended options          since 5.6
#define SYS_mkdirat             258  // mkdirat(dirfd, path, mode)         — mkdir relative to dirfd
#define SYS_mknodat             259  // mknodat(dirfd, path, mode, dev)    — mknod relative to dirfd
#define SYS_fchownat            260  // fchownat(dirfd, path, uid, gid, flags)
#define SYS_futimesat           261  // futimesat(dirfd, path, times)      — deprecated, use utimensat
#define SYS_newfstatat          262  // newfstatat(dirfd, path, buf, fl)   — fstat relative to dirfd
#define SYS_unlinkat            263  // unlinkat(dirfd, path, flags)       — unlink or rmdir relative to dirfd
#define SYS_renameat            264  // renameat(od, op, nd, np)           — rename relative to dirfd
#define SYS_renameat2           316  // renameat2(od,op,nd,np,flags)       — rename with atomic swap flag        since 3.15
#define SYS_linkat              265  // linkat(ofd, op, nfd, np, flags)    — link relative to dirfd
#define SYS_symlinkat           266  // symlinkat(target, newdirfd, lp)    — symlink relative to dirfd
#define SYS_readlinkat          267  // readlinkat(dirfd, path, buf, sz)   — readlink relative to dirfd
#define SYS_fchmodat            268  // fchmodat(dirfd, path, mode, fl)    — chmod relative to dirfd
#define SYS_faccessat           269  // faccessat(dirfd, path, mode, fl)   — access relative to dirfd
#define SYS_faccessat2          439  // faccessat2(dirfd, path, mode, fl)  — faccessat with proper flags        since 5.8
#define SYS_inotify_init        253  // inotify_init()                     — create inotify instance
#define SYS_inotify_init1       294  // inotify_init1(flags)               — inotify_init with flags             since 2.6.27
#define SYS_inotify_add_watch   254  // inotify_add_watch(fd, path, mask)  — watch a path for events
#define SYS_inotify_rm_watch    255  // inotify_rm_watch(fd, wd)           — remove a watch
#define SYS_utimes              235  // utimes(path, times)                — set file access/modification times
#define SYS_utimensat           280  // utimensat(dfd, path, times, fl)    — set timestamps with nanosecond precision
#define SYS_utime               132  // utime(path, times)                 — deprecated, use utimes
#define SYS_statfs              137  // statfs(path, buf)                  — filesystem statistics by path
#define SYS_fstatfs             138  // fstatfs(fd, buf)                   — filesystem statistics by fd
#define SYS_statx               332  // statx(dirfd,path,fl,mask,statx)    — extended stat with extra fields    since 4.11
#define SYS_sync                162  // sync()                             — flush all filesystem caches to disk
#define SYS_syncfs              306  // syncfs(fd)                         — flush specific filesystem           since 2.6.39
#define SYS_sync_file_range     277  // sync_file_range(fd, off, nb, fl)   — partially flush file data to disk
#define SYS_fallocate           285  // fallocate(fd, mode, off, len)      — preallocate disk space for a file   since 2.6.23
#define SYS_fadvise64           221  // fadvise64(fd, off, len, adv)       — hint kernel about file access pattern
#define SYS_readahead           187  // readahead(fd, offset, count)       — prefetch file data into page cache
#define SYS_splice              275  // splice(fdin, offin, fdout, offout, len, fl) — move data between fd and pipe
#define SYS_tee                 276  // tee(fdin, fdout, len, flags)       — duplicate pipe data without consuming
#define SYS_vmsplice            278  // vmsplice(fd, iov, cnt, fl)         — splice userspace memory into pipe
#define SYS_copy_file_range     326  // copy_file_range(fin,offin,fout,offout,len,fl) — kernel copy-on-write    since 4.5
#define SYS_mount               165  // mount(src, tgt, fs, fl, data)      — mount a filesystem
#define SYS_umount2             166  // umount2(target, flags)             — unmount a filesystem
#define SYS_pivot_root          155  // pivot_root(new_root, put_old)      — change root filesystem
#define SYS_chroot              161  // chroot(path)                       — change filesystem root for process
#define SYS_quotactl            179  // quotactl(cmd, special, id, addr)   — manage disk quotas
#define SYS_fanotify_init       300  // fanotify_init(flags, event_f_flags) — filesystem event monitor          since 2.6.37
#define SYS_fanotify_mark       301  // fanotify_mark(fd, fl, mask, dfd, path)
#define SYS_name_to_handle_at   303  // name_to_handle_at(dfd,path,...)    — get opaque file handle
#define SYS_open_by_handle_at   304  // open_by_handle_at(mfd,fh,flags)    — open file by opaque handle
#define SYS_setxattr            188  // setxattr(path, name, val, sz, fl)  — set extended attribute
#define SYS_lsetxattr           189  // lsetxattr(path, name, val, sz, fl) — setxattr without following symlink
#define SYS_fsetxattr           190  // fsetxattr(fd, name, val, sz, fl)
#define SYS_getxattr            191  // getxattr(path, name, val, sz)      — get extended attribute value
#define SYS_lgetxattr           192  // lgetxattr(path, name, val, sz)
#define SYS_fgetxattr           193  // fgetxattr(fd, name, val, sz)
#define SYS_listxattr           194  // listxattr(path, list, sz)          — list all extended attribute names
#define SYS_llistxattr          195  // llistxattr(path, list, sz)
#define SYS_flistxattr          196  // flistxattr(fd, list, sz)
#define SYS_removexattr         197  // removexattr(path, name)            — remove extended attribute
#define SYS_lremovexattr        198  // lremovexattr(path, name)
#define SYS_fremovexattr        199  // fremovexattr(fd, name)

// ─── memory ──────────────────────────────────────────────────
#define SYS_mmap                9    // mmap(addr,len,prot,flags,fd,off)   — map file or anonymous memory
#define SYS_mprotect            10   // mprotect(addr, len, prot)          — change memory region permissions
#define SYS_munmap              11   // munmap(addr, len)                  — unmap memory region
#define SYS_brk                 12   // brk(addr)                          — change data segment end (heap growth)
#define SYS_mremap              216  // mremap(old,osz,nsz,flags,new)      — resize or relocate a mapping
#define SYS_msync               26   // msync(addr, len, flags)            — sync mapping to underlying file
#define SYS_mincore             27   // mincore(addr, len, vec)            — check which pages are in ram
#define SYS_madvise             28   // madvise(addr, len, advice)         — give kernel hint about memory usage
#define SYS_mlock               149  // mlock(addr, len)                   — lock pages in ram (prevent swap)
#define SYS_munlock             150  // munlock(addr, len)                 — unlock pages
#define SYS_mlockall            151  // mlockall(flags)                    — lock all process memory
#define SYS_munlockall          152  // munlockall()                       — unlock all process memory
#define SYS_mlock2              325  // mlock2(addr, len, flags)           — mlock with flags                   since 4.4
#define SYS_memfd_create        319  // memfd_create(name, flags)          — create anonymous file in ram        since 3.17
#define SYS_memfd_secret        447  // memfd_secret(flags)                — create inaccessible secret memory   since 5.14
#define SYS_process_vm_readv    310  // process_vm_readv(pid,...)          — read memory of another process      since 3.2
#define SYS_process_vm_writev   311  // process_vm_writev(pid,...)         — write memory of another process
#define SYS_process_madvise     440  // process_madvise(pidfd,iov,cnt,beh,fl) — madvise for another process     since 5.10
#define SYS_mbind               237  // mbind(addr, len, mode, nodemask, max, fl) — set numa memory policy
#define SYS_get_mempolicy       239  // get_mempolicy(mode, nodemask, max, addr, fl)
#define SYS_set_mempolicy       238  // set_mempolicy(mode, nodemask, maxnode)
#define SYS_migrate_pages       256  // migrate_pages(pid, maxnode, from, to) — move pages to different numa nodes
#define SYS_move_pages          239  // move_pages(pid, nr, pages, nodes, status, fl)
#define SYS_membarrier          324  // membarrier(cmd, flags)             — issue memory barriers between threads since 4.3

// ─── processes ───────────────────────────────────────────────
#define SYS_clone               56   // clone(flags, stack, ptid, ctid, regs) — create thread or process
#define SYS_clone3              435  // clone3(args, size)                 — extended clone with struct args     since 5.3
#define SYS_fork                57   // fork()                             — duplicate process (child gets SIGCHLD)
#define SYS_vfork               58   // vfork()                            — fork without copying memory, parent blocks
#define SYS_execve              59   // execve(path, argv, envp)           — replace process image
#define SYS_execveat            322  // execveat(dirfd, path, argv, envp, flags) — execve relative to dirfd    since 3.19
#define SYS_exit                60   // exit(status)                       — terminate current thread
#define SYS_exit_group          231  // exit_group(status)                 — terminate all threads in process
#define SYS_wait4               61   // wait4(pid, wstatus, opts, rusage)  — wait for child state change
#define SYS_waitid              247  // waitid(type, id, infop, opts)      — wait with extended state info
#define SYS_getpid              39   // getpid()                           — get process id
#define SYS_getppid             110  // getppid()                          — get parent process id
#define SYS_gettid              186  // gettid()                           — get thread id
#define SYS_getpgid             121  // getpgid(pid)                       — get process group id
#define SYS_setpgid             109  // setpgid(pid, pgid)                 — set process group id
#define SYS_getsid              124  // getsid(pid)                        — get session id
#define SYS_setsid              112  // setsid()                           — create new session, detach from terminal
#define SYS_getuid              102  // getuid()                           — get real user id
#define SYS_geteuid             107  // geteuid()                          — get effective user id
#define SYS_getgid              104  // getgid()                           — get real group id
#define SYS_getegid             108  // getegid()                          — get effective group id
#define SYS_setuid              105  // setuid(uid)                        — set user id
#define SYS_setgid              106  // setgid(gid)                        — set group id
#define SYS_setreuid            113  // setreuid(ruid, euid)               — set real and effective uid
#define SYS_setregid            114  // setregid(rgid, egid)               — set real and effective gid
#define SYS_getgroups           115  // getgroups(size, list)              — get supplementary group list
#define SYS_setgroups           116  // setgroups(size, list)              — set supplementary group list
#define SYS_getresuid           118  // getresuid(ruid, euid, suid)        — get real/effective/saved uid
#define SYS_setresuid           117  // setresuid(ruid, euid, suid)        — set real/effective/saved uid
#define SYS_getresgid           120  // getresgid(rgid, egid, sgid)        — get real/effective/saved gid
#define SYS_setresgid           119  // setresgid(rgid, egid, sgid)        — set real/effective/saved gid
#define SYS_setfsuid            122  // setfsuid(uid)                      — set filesystem uid (for vfs checks)
#define SYS_setfsgid            123  // setfsgid(gid)                      — set filesystem gid
#define SYS_prctl               157  // prctl(option, arg2..5)             — control process attributes
#define SYS_arch_prctl          158  // arch_prctl(code, addr)             — x86-specific process attributes (fs/gs base)
#define SYS_ptrace              101  // ptrace(request, pid, addr, data)   — trace and debug a process
#define SYS_kill                62   // kill(pid, sig)                     — send signal to process or group
#define SYS_tkill               200  // tkill(tid, sig)                    — send signal to specific thread
#define SYS_tgkill              234  // tgkill(tgid, tid, sig)             — tkill with group validation
#define SYS_getpriority         140  // getpriority(which, who)            — get scheduling priority (nice)
#define SYS_setpriority         141  // setpriority(which, who, prio)      — set scheduling priority (nice)
#define SYS_sched_yield         124  // sched_yield()                      — voluntarily give up cpu
#define SYS_sched_getparam      143  // sched_getparam(pid, param)         — get scheduler parameters
#define SYS_sched_setparam      142  // sched_setparam(pid, param)         — set scheduler parameters
#define SYS_sched_getscheduler  145  // sched_getscheduler(pid)            — get current scheduling policy
#define SYS_sched_setscheduler  144  // sched_setscheduler(pid,pol,par)    — set scheduling policy
#define SYS_sched_get_priority_max 146 // sched_get_priority_max(pol)      — max priority value for policy
#define SYS_sched_get_priority_min 147 // sched_get_priority_min(pol)      — min priority value for policy
#define SYS_sched_rr_get_interval  148 // sched_rr_get_interval(pid,ts)   — round-robin time quantum
#define SYS_sched_setaffinity   203  // sched_setaffinity(pid,sz,mask)     — bind process to set of cpus
#define SYS_sched_getaffinity   204  // sched_getaffinity(pid,sz,mask)     — get cpu affinity mask
#define SYS_sched_setattr       314  // sched_setattr(pid, attr, flags)    — set extended scheduler attrs       since 3.14
#define SYS_sched_getattr       315  // sched_getattr(pid, attr, sz, fl)   — get extended scheduler attrs
#define SYS_capget              125  // capget(hdrp, datap)                — get process capabilities
#define SYS_capset              126  // capset(hdrp, datap)                — set process capabilities
#define SYS_prlimit64           302  // prlimit64(pid,res,new,old)         — get/set resource limits            since 2.6.36
#define SYS_getrlimit           97   // getrlimit(resource, rlim)          — get resource limit
#define SYS_setrlimit           160  // setrlimit(resource, rlim)          — set resource limit
#define SYS_getrusage           98   // getrusage(who, rusage)             — get resource usage stats
#define SYS_pidfd_open          434  // pidfd_open(pid, flags)             — get fd referring to a process       since 5.3
#define SYS_pidfd_send_signal   424  // pidfd_send_signal(pidfd,sig,info,fl) — send signal via pidfd           since 5.1
#define SYS_pidfd_getfd         438  // pidfd_getfd(pidfd, targetfd, fl)   — duplicate fd from another process
#define SYS_set_tid_address     218  // set_tid_address(tidptr)            — set address to clear on thread exit
#define SYS_personality         135  // personality(persona)               — change process execution domain
#define SYS_uname               63   // uname(buf)                         — get kernel and os name/version
#define SYS_sysinfo             99   // sysinfo(info)                      — overall system stats (ram, swap, uptime)
#define SYS_syslog              103  // syslog(type, buf, len)             — read or control kernel ring buffer
#define SYS_sethostname         170  // sethostname(name, len)             — set hostname (requires cap_sys_admin)
#define SYS_setdomainname       171  // setdomainname(name, len)           — set nis domain name
#define SYS_reboot              169  // reboot(magic, magic2, cmd, arg)    — reboot, power off, or kexec (root)

// ─── signals ─────────────────────────────────────────────────
#define SYS_rt_sigaction        13   // rt_sigaction(sig, act, oact, sz)   — install signal handler
#define SYS_rt_sigprocmask      14   // rt_sigprocmask(how, set, oset)     — get/set blocked signal mask
#define SYS_rt_sigreturn        15   // rt_sigreturn()                     — return from signal handler (kernel use)
#define SYS_rt_sigpending       127  // rt_sigpending(set, sz)             — query pending signals
#define SYS_rt_sigtimedwait     128  // rt_sigtimedwait(set,info,ts,sz)    — wait for signal with timeout
#define SYS_rt_sigqueueinfo     129  // rt_sigqueueinfo(pid,sig,info)      — send signal with extra data
#define SYS_rt_sigsuspend       130  // rt_sigsuspend(mask, sz)            — atomically replace mask and wait
#define SYS_rt_tgsigqueueinfo   240  // rt_tgsigqueueinfo(tgid,tid,sig,info) — send signal with data to thread
#define SYS_sigaltstack         131  // sigaltstack(ss, oss)               — set alternate signal stack
#define SYS_signalfd            282  // signalfd(fd, mask, sz)             — receive signals as fd reads         since 2.6.22
#define SYS_signalfd4           289  // signalfd4(fd, mask, sz, flags)     — signalfd with flags                 since 2.6.27
#define SYS_eventfd             284  // eventfd(initval)                   — event counter notification via fd   since 2.6.22
#define SYS_eventfd2            290  // eventfd2(initval, flags)           — eventfd with flags                  since 2.6.27
#define SYS_timerfd_create      283  // timerfd_create(clock, flags)       — timer notification via fd           since 2.6.25
#define SYS_timerfd_settime     286  // timerfd_settime(fd,fl,new,old)     — arm or disarm a timerfd
#define SYS_timerfd_gettime     287  // timerfd_gettime(fd, curr)          — query current timerfd value
#define SYS_alarm               37   // alarm(seconds)                     — schedule SIGALRM in n seconds
#define SYS_pause               34   // pause()                            — wait for any signal to arrive

// ─── time ────────────────────────────────────────────────────
#define SYS_gettimeofday        96   // gettimeofday(tv, tz)               — get wall clock time (microseconds)
#define SYS_settimeofday        164  // settimeofday(tv, tz)               — set wall clock time (root)
#define SYS_clock_gettime       228  // clock_gettime(clkid, ts)           — get high-resolution clock time
#define SYS_clock_settime       227  // clock_settime(clkid, ts)           — set clock (root)
#define SYS_clock_getres        229  // clock_getres(clkid, res)           — get clock resolution
#define SYS_clock_nanosleep     230  // clock_nanosleep(clk,fl,req,rem)    — sleep against a specific clock
#define SYS_clock_adjtime       305  // clock_adjtime(clkid, tx)           — fine-tune clock (ntp use)
#define SYS_nanosleep           35   // nanosleep(req, rem)                — sleep with nanosecond precision
#define SYS_times               100  // times(tbuf)                        — get process and children cpu times
#define SYS_time                201  // time(tloc)                         — unix timestamp in seconds (deprecated)
#define SYS_timer_create        222  // timer_create(clkid, evp, tid)      — create posix per-process timer
#define SYS_timer_settime       223  // timer_settime(tid, fl, new, old)   — arm or disarm posix timer
#define SYS_timer_gettime       224  // timer_gettime(tid, curr)           — query posix timer
#define SYS_timer_getoverrun    225  // timer_getoverrun(tid)              — get missed expirations since last delivery
#define SYS_timer_delete        226  // timer_delete(tid)                  — delete posix timer
#define SYS_adjtimex            159  // adjtimex(buf)                      — tune kernel clock parameters (ntp)

// ─── networking ──────────────────────────────────────────────
#define SYS_socket              41   // socket(domain, type, protocol)     — create communication endpoint
#define SYS_bind                49   // bind(sockfd, addr, addrlen)        — assign address to socket
#define SYS_listen              50   // listen(sockfd, backlog)            — mark socket as passive (server)
#define SYS_accept              43   // accept(sockfd, addr, addrlen)      — accept incoming connection
#define SYS_accept4             288  // accept4(sockfd, addr, len, fl)     — accept with flags (e.g. O_NONBLOCK)  since 2.6.28
#define SYS_connect             42   // connect(sockfd, addr, addrlen)     — initiate connection to address
#define SYS_getsockname         51   // getsockname(sockfd, addr, len)     — get local bound address
#define SYS_getpeername         52   // getpeername(sockfd, addr, len)     — get remote address of connection
#define SYS_sendto              44   // sendto(s, buf, len, fl, to, tlen)  — send with explicit destination
#define SYS_recvfrom            45   // recvfrom(s, buf, len, fl, fr, fl2) — recv and get source address
#define SYS_sendmsg             46   // sendmsg(sockfd, msg, flags)        — send using msghdr (supports ancillary data)
#define SYS_recvmsg             47   // recvmsg(sockfd, msg, flags)        — recv using msghdr
#define SYS_sendmmsg            307  // sendmmsg(sockfd, msgvec, vlen, fl) — send multiple messages at once      since 3.0
#define SYS_recvmmsg            299  // recvmmsg(sockfd, msgvec, vlen,..)  — recv multiple messages at once      since 2.6.33
#define SYS_shutdown            48   // shutdown(sockfd, how)              — shut down part or all of connection
#define SYS_setsockopt          54   // setsockopt(s, lvl, opt, val, len)  — set socket option
#define SYS_getsockopt          55   // getsockopt(s, lvl, opt, val, len)  — get socket option
#define SYS_socketpair          53   // socketpair(dom, type, prot, sv)    — create pair of connected sockets

// ─── ipc ─────────────────────────────────────────────────────
#define SYS_futex               202  // futex(uaddr,op,val,to,uaddr2,v3)   — fast userspace mutex/condvar
#define SYS_futex_waitv         449  // futex_waitv(waiters, nr, fl, to, clk) — wait on multiple futexes       since 5.16
#define SYS_set_robust_list     273  // set_robust_list(head, len)         — register list of robust futexes
#define SYS_get_robust_list     274  // get_robust_list(pid, head, len)    — get robust futex list of process
#define SYS_msgget              68   // msgget(key, msgflg)                — get or create sysv message queue
#define SYS_msgsnd              69   // msgsnd(msqid, msgp, msgsz, flg)   — send message to queue
#define SYS_msgrcv              70   // msgrcv(msqid, msgp, msgsz,...)    — receive message from queue
#define SYS_msgctl              71   // msgctl(msqid, cmd, buf)            — message queue control operations
#define SYS_semget              64   // semget(key, nsems, semflg)         — get or create sysv semaphore set
#define SYS_semop               65   // semop(semid, sops, nsops)          — atomic operations on semaphores
#define SYS_semtimedop          220  // semtimedop(semid, sops, n, ts)     — semop with timeout
#define SYS_semctl              66   // semctl(semid, semnum, cmd, ...)    — semaphore set control
#define SYS_shmget              29   // shmget(key, size, shmflg)          — get or create shared memory segment
#define SYS_shmat               30   // shmat(shmid, shmaddr, shmflg)      — attach shared memory segment to process
#define SYS_shmdt               67   // shmdt(shmaddr)                     — detach shared memory segment
#define SYS_shmctl              31   // shmctl(shmid, cmd, buf)            — shared memory control operations
#define SYS_mq_open             240  // mq_open(name, flags, mode, attr)   — open posix message queue
#define SYS_mq_unlink           241  // mq_unlink(name)                    — delete posix message queue
#define SYS_mq_timedsend        242  // mq_timedsend(mqdes,msg,len,prio,ts) — send message with timeout
#define SYS_mq_timedreceive     243  // mq_timedreceive(mqdes,buf,len,prio,ts) — recv message with timeout
#define SYS_mq_notify           244  // mq_notify(mqdes, sevp)             — notify on message arrival
#define SYS_mq_getsetattr       245  // mq_getsetattr(mqdes, new, old)     — get/set queue attributes

// ─── namespaces ──────────────────────────────────────────────
#define SYS_unshare             272  // unshare(flags)                     — disassociate namespaces from parent since 2.6.16
#define SYS_setns               308  // setns(fd, nstype)                  — join an existing namespace          since 3.0

// ─── kernel modules ──────────────────────────────────────────
#define SYS_init_module         175  // init_module(umod, len, uargs)      — load kernel module from memory
#define SYS_finit_module        313  // finit_module(fd, uargs, flags)     — load kernel module from fd          since 3.8
#define SYS_delete_module       176  // delete_module(name, flags)         — unload kernel module
#define SYS_kexec_load          246  // kexec_load(entry, nr, segs, fl)    — load new kernel for kexec
#define SYS_kexec_file_load     320  // kexec_file_load(kfd,ifd,ncmds,cmds,fl) — kexec_load from fd            since 3.17

// ─── security and bpf ────────────────────────────────────────
#define SYS_bpf                 321  // bpf(cmd, attr, size)               — load/manage ebpf programs and maps  since 3.18
#define SYS_perf_event_open     298  // perf_event_open(attr,pid,cpu,gfd,fl) — performance monitoring counters  since 2.6.31
#define SYS_userfaultfd         323  // userfaultfd(flags)                 — handle page faults from userspace   since 4.3
#define SYS_seccomp             317  // seccomp(op, flags, uargs)          — restrict available syscalls          since 3.17
#define SYS_getrandom           318  // getrandom(buf, count, flags)       — fill buffer with random bytes        since 3.17
#define SYS_landlock_create_ruleset 444 // landlock_create_ruleset(attr,sz,fl)  since 5.13
#define SYS_landlock_add_rule   445  // landlock_add_rule(ruleset_fd, rule_type, rule_attr, flags)
#define SYS_landlock_restrict_self 446 // landlock_restrict_self(ruleset_fd, flags)

// ─── async i/o (classic) ─────────────────────────────────────
#define SYS_io_setup            206  // io_setup(nr_events, ctxp)          — initialize posix aio context
#define SYS_io_destroy          207  // io_destroy(ctx)                    — destroy aio context
#define SYS_io_getevents        208  // io_getevents(ctx,min,max,evs,to)   — collect completed aio events
#define SYS_io_submit           209  // io_submit(ctx, nr, iocbpp)         — submit aio requests
#define SYS_io_cancel           210  // io_cancel(ctx, iocb, result)       — cancel an aio request

// ─── async i/o (io_uring) ────────────────────────────────────
#define SYS_io_uring_setup      425  // io_uring_setup(entries, params)    — create io_uring instance            since 5.1
#define SYS_io_uring_enter      426  // io_uring_enter(fd,to_submit,...)   — submit sqes and/or wait for cqes
#define SYS_io_uring_register   427  // io_uring_register(fd,op,arg,nr)    — register buffers or files with ring

// ─── misc ────────────────────────────────────────────────────
#define SYS_kcmp                312  // kcmp(pid1,pid2,type,idx1,idx2)     — compare kernel resources of two processes since 3.5
#define SYS_close_range         436  // close_range(first, last, flags)    — close a range of file descriptors   since 5.9
#define SYS_rseq                334  // rseq(rseq, rseq_len, flags, sig)   — register restartable sequences      since 4.18
#define SYS_iopl                172  // iopl(level)                        — change i/o privilege level (root)
#define SYS_ioperm              173  // ioperm(from, num, turn_on)         — set i/o port access permissions
#define SYS_ioprio_set          251  // ioprio_set(which, who, ioprio)     — set i/o scheduling priority
#define SYS_ioprio_get          252  // ioprio_get(which, who)             — get i/o scheduling priority
#define SYS_add_key             248  // add_key(type, desc, payload, plen, ring) — add key to kernel keyring
#define SYS_request_key         249  // request_key(type, desc, info, ring) — search for key in keyrings
#define SYS_keyctl              250  // keyctl(cmd, ...)                   — manipulate kernel key management
// Самописный uintptr_t для безопасного приведения любых типов и указателей
typedef unsigned long uintptr_t;

// Вспомогательный макрос приведения к long для регистров ARM64
#define __SYS_ARG(x) ((long)(uintptr_t)(x))

#include <stddef.h>

// Вспомогательный макрос приведения типов для аргументов
#define __SYS_ARG(x) ((long)(x))

// ─── Базовый ассемблерный сисколл x86_64 ───────────────
static inline long raw_syscall6_impl(long n, long a0, long a1, long a2,
                                     long a3, long a4, long a5) {
    register long rax __asm__("rax") = n;
    register long rdi __asm__("rdi") = a0;
    register long rsi __asm__("rsi") = a1;
    register long rdx __asm__("rdx") = a2;
    register long r10 __asm__("r10") = a3; // Важно: r10 вместо rcx для 4-го аргумента
    register long r8  __asm__("r8")  = a4;
    register long r9  __asm__("r9")  = a5;

    __asm__ volatile (
        "syscall"
        : "+r"(rax)
        : "r"(rdi), "r"(rsi), "r"(rdx), "r"(r10), "r"(r8), "r"(r9)
        : "rcx", "r11", "memory" // rcx и r11 затираются инструкцией syscall
    );

    return rax;
}

// ─── Макросы-обертки с автоматическим кастом ───────────
#define raw_syscall0(n) \
    raw_syscall6_impl(__SYS_ARG(n), 0, 0, 0, 0, 0, 0)

#define raw_syscall1(n, a0) \
    raw_syscall6_impl(__SYS_ARG(n), __SYS_ARG(a0), 0, 0, 0, 0, 0)

#define raw_syscall2(n, a0, a1) \
    raw_syscall6_impl(__SYS_ARG(n), __SYS_ARG(a0), __SYS_ARG(a1), 0, 0, 0, 0)

#define raw_syscall3(n, a0, a1, a2) \
    raw_syscall6_impl(__SYS_ARG(n), __SYS_ARG(a0), __SYS_ARG(a1), __SYS_ARG(a2), 0, 0, 0)

#define raw_syscall4(n, a0, a1, a2, a3) \
    raw_syscall6_impl(__SYS_ARG(n), __SYS_ARG(a0), __SYS_ARG(a1), __SYS_ARG(a2), __SYS_ARG(a3), 0, 0)

#define raw_syscall5(n, a0, a1, a2, a3, a4) \
    raw_syscall6_impl(__SYS_ARG(n), __SYS_ARG(a0), __SYS_ARG(a1), __SYS_ARG(a2), __SYS_ARG(a3), __SYS_ARG(a4), 0)

#define raw_syscall6(n, a0, a1, a2, a3, a4, a5) \
    raw_syscall6_impl(__SYS_ARG(n), __SYS_ARG(a0), __SYS_ARG(a1), __SYS_ARG(a2), __SYS_ARG(a3), __SYS_ARG(a4), __SYS_ARG(a5))

#define RAW_SYSCALL_PICK(_0,_1,_2,_3,_4,_5,_6,NAME,...) NAME
#define raw_syscall(...) \
    RAW_SYSCALL_PICK(__VA_ARGS__,raw_syscall6,raw_syscall5,raw_syscall4,raw_syscall3,raw_syscall2,raw_syscall1,raw_syscall0)(__VA_ARGS__)
