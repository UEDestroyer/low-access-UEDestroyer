#pragma once

// ============================================================
//  syscall numbers — aarch64 (arm64) linux
//  calling convention: x8=nr, x0..x5=args
//  entry:              svc #0
//  return:             x0 (negative = -errno)
//  source:             linux/include/uapi/asm-generic/unistd.h
//  note:               arm64 uses the asm-generic shared table.
//                      SYS_open does not exist — use SYS_openat.
//                      SYS_fork does not exist — use SYS_clone.
// ============================================================
#define NULL ((void *)0)
// ─── file i/o ────────────────────────────────────────────────
#define SYS_io_setup            0    // io_setup(nr_events, ctxp)          — initialize posix aio context
#define SYS_io_destroy          1    // io_destroy(ctx)                    — destroy aio context
#define SYS_io_submit           2    // io_submit(ctx, nr, iocbpp)         — submit aio requests
#define SYS_io_cancel           3    // io_cancel(ctx, iocb, result)       — cancel an aio request
#define SYS_io_getevents        4    // io_getevents(ctx,min,max,evs,to)   — collect completed aio events
#define SYS_setxattr            5    // setxattr(path, name, val, sz, fl)  — set extended attribute
#define SYS_lsetxattr           6    // lsetxattr(path, name, val, sz, fl) — setxattr without following symlink
#define SYS_fsetxattr           7    // fsetxattr(fd, name, val, sz, fl)
#define SYS_getxattr            8    // getxattr(path, name, val, sz)      — get extended attribute value
#define SYS_lgetxattr           9    // lgetxattr(path, name, val, sz)
#define SYS_fgetxattr           10   // fgetxattr(fd, name, val, sz)
#define SYS_listxattr           11   // listxattr(path, list, sz)          — list all extended attribute names
#define SYS_llistxattr          12   // llistxattr(path, list, sz)
#define SYS_flistxattr          13   // flistxattr(fd, list, sz)
#define SYS_removexattr         14   // removexattr(path, name)            — remove extended attribute
#define SYS_lremovexattr        15   // lremovexattr(path, name)
#define SYS_fremovexattr        16   // fremovexattr(fd, name)
#define SYS_getcwd              17   // getcwd(buf, size)                  — get current working directory
#define SYS_lookup_dcookie      18   // lookup_dcookie(cookie64, buf, len) — get path from dcache cookie
#define SYS_eventfd2            19   // eventfd2(initval, flags)           — event counter via fd
#define SYS_epoll_create1       20   // epoll_create1(flags)               — create epoll fd
#define SYS_epoll_ctl           21   // epoll_ctl(epfd, op, fd, event)     — add/modify/remove fd in epoll
#define SYS_epoll_pwait         22   // epoll_pwait(epfd, evts, max, to, sm) — wait for epoll events with sigmask
#define SYS_dup                 23   // dup(fd)                            — duplicate fd to lowest free number
#define SYS_dup3                24   // dup3(oldfd, newfd, flags)          — duplicate fd to specific number with flags
#define SYS_fcntl               25   // fcntl(fd, cmd, ...)                — manipulate file descriptor
#define SYS_inotify_init1       26   // inotify_init1(flags)               — create inotify instance
#define SYS_inotify_add_watch   27   // inotify_add_watch(fd, path, mask)  — watch path for filesystem events
#define SYS_inotify_rm_watch    28   // inotify_rm_watch(fd, wd)           — remove watch
#define SYS_ioctl               29   // ioctl(fd, request, ...)            — device-specific control
#define SYS_ioprio_set          30   // ioprio_set(which, who, ioprio)     — set i/o scheduling priority
#define SYS_ioprio_get          31   // ioprio_get(which, who)             — get i/o scheduling priority
#define SYS_flock               32   // flock(fd, operation)               — apply advisory file lock
#define SYS_mknodat             33   // mknodat(dirfd, path, mode, dev)    — create special file relative to dirfd
#define SYS_mkdirat             34   // mkdirat(dirfd, path, mode)         — create directory relative to dirfd
#define SYS_unlinkat            35   // unlinkat(dirfd, path, flags)       — unlink or rmdir relative to dirfd
#define SYS_symlinkat           36   // symlinkat(target, newdirfd, linkp) — symlink relative to dirfd
#define SYS_linkat              37   // linkat(odfd, op, ndfd, np, flags)  — hard link relative to dirfd
#define SYS_renameat            38   // renameat(oldfd, oldpath, newfd, newpath) — rename relative to dirfds
#define SYS_umount2             39   // umount2(target, flags)             — unmount filesystem
#define SYS_mount               40   // mount(src, tgt, fs, fl, data)      — mount filesystem
#define SYS_pivot_root          41   // pivot_root(new_root, put_old)      — change root filesystem
#define SYS_statfs              43   // statfs(path, buf)                  — filesystem statistics by path
#define SYS_fstatfs             44   // fstatfs(fd, buf)                   — filesystem statistics by fd
#define SYS_truncate            45   // truncate(path, length)             — set file size by path
#define SYS_ftruncate           46   // ftruncate(fd, length)              — set file size by fd
#define SYS_fallocate           47   // fallocate(fd, mode, offset, len)   — preallocate disk space
#define SYS_faccessat           48   // faccessat(dirfd, path, mode, fl)   — check access relative to dirfd
#define SYS_chdir               49   // chdir(path)                        — change working directory
#define SYS_fchdir              50   // fchdir(fd)                         — change directory via fd
#define SYS_chroot              51   // chroot(path)                       — change filesystem root
#define SYS_fchmod              52   // fchmod(fd, mode)                   — change permissions by fd
#define SYS_fchmodat            53   // fchmodat(dirfd, path, mode, fl)    — chmod relative to dirfd
#define SYS_fchownat            54   // fchownat(dirfd, path, uid, gid, fl)
#define SYS_fchown              55   // fchown(fd, uid, gid)               — change owner by fd
#define SYS_openat              56   // openat(dirfd, path, flags, mode)   — primary file open syscall on arm64
#define SYS_close               57   // close(fd)                          — close file descriptor
#define SYS_vhangup             58   // vhangup()                          — hang up current terminal
#define SYS_pipe2               59   // pipe2(pipefd, flags)               — create pipe with flags
#define SYS_quotactl            60   // quotactl(cmd, special, id, addr)   — manage disk quotas
#define SYS_getdents64          61   // getdents64(fd, dirent, count)      — read directory entries (64-bit)
#define SYS_lseek               62   // lseek(fd, offset, whence)          — reposition file offset
#define SYS_read                63   // read(fd, buf, count)               — read bytes from fd
#define SYS_write               64   // write(fd, buf, count)              — write bytes to fd
#define SYS_readv               65   // readv(fd, iov, iovcnt)             — scatter read
#define SYS_writev              66   // writev(fd, iov, iovcnt)            — gather write
#define SYS_pread64             67   // pread64(fd, buf, count, pos)       — read at offset without changing pos
#define SYS_pwrite64            68   // pwrite64(fd, buf, count, pos)      — write at offset
#define SYS_preadv              69   // preadv(fd, iov, iovcnt, off_lo, off_hi)
#define SYS_pwritev             70   // pwritev(fd, iov, iovcnt, off_lo, off_hi)
#define SYS_sendfile            71   // sendfile(outfd, infd, offset, cnt) — zero-copy file transfer
#define SYS_pselect6            72   // pselect6(n, r, w, e, ts, sigmask)
#define SYS_ppoll               73   // ppoll(fds, nfds, ts, sigmask)
#define SYS_signalfd4           74   // signalfd4(fd, mask, sz, flags)     — receive signals via fd
#define SYS_vmsplice            75   // vmsplice(fd, iov, cnt, fl)         — splice userspace memory into pipe
#define SYS_splice              76   // splice(fdin, offin, fdout, offout, len, fl) — move data between fd and pipe
#define SYS_tee                 77   // tee(fdin, fdout, len, flags)       — duplicate pipe data
#define SYS_readlinkat          78   // readlinkat(dirfd, path, buf, sz)   — read symlink relative to dirfd
#define SYS_newfstatat          79   // newfstatat(dirfd, path, statbuf, fl) — stat relative to dirfd
#define SYS_fstat               80   // fstat(fd, statbuf)                 — file metadata by fd
#define SYS_sync                81   // sync()                             — flush all filesystem caches
#define SYS_fsync               82   // fsync(fd)                          — flush file data and metadata
#define SYS_fdatasync           83   // fdatasync(fd)                      — flush data only
#define SYS_sync_file_range     84   // sync_file_range(fd, off, nb, fl)   — partial file sync to disk
#define SYS_timerfd_create      85   // timerfd_create(clockid, flags)     — timer delivered via fd
#define SYS_timerfd_settime     86   // timerfd_settime(fd, fl, new, old)  — arm/disarm timerfd
#define SYS_timerfd_gettime     87   // timerfd_gettime(fd, curr)          — query timerfd value
#define SYS_utimensat           88   // utimensat(dirfd, path, times, fl)  — set timestamps (nanosecond precision)
#define SYS_acct                89   // acct(path)                         — enable/disable process accounting
#define SYS_capget              90   // capget(hdr, data)                  — get process capabilities
#define SYS_capset              91   // capset(hdr, data)                  — set process capabilities
#define SYS_personality         92   // personality(persona)               — change process execution domain
#define SYS_exit                93   // exit(status)                       — terminate current thread
#define SYS_exit_group          94   // exit_group(status)                 — terminate all threads in process
#define SYS_waitid              95   // waitid(type, id, infop, opts)      — wait for child state change
#define SYS_set_tid_address     96   // set_tid_address(tidptr)            — set address cleared on thread exit
#define SYS_unshare             97   // unshare(flags)                     — disassociate namespaces
#define SYS_futex               98   // futex(uaddr, op, val, to, uaddr2, v3) — fast userspace mutex/condvar
#define SYS_set_robust_list     99   // set_robust_list(head, len)         — register robust futex list
#define SYS_get_robust_list     100  // get_robust_list(pid, head, len)    — get robust futex list
#define SYS_nanosleep           101  // nanosleep(req, rem)                — sleep with nanosecond precision
#define SYS_getitimer           102  // getitimer(which, itv)              — get interval timer
#define SYS_setitimer           103  // setitimer(which, itv, oitv)        — set interval timer
#define SYS_kexec_load          104  // kexec_load(entry, nr, segs, fl)    — load new kernel
#define SYS_init_module         105  // init_module(umod, len, uargs)      — load kernel module from memory
#define SYS_delete_module       106  // delete_module(name, flags)         — unload kernel module
#define SYS_timer_create        107  // timer_create(clkid, evp, tid)      — create posix timer
#define SYS_timer_gettime       108  // timer_gettime(tid, curr)           — query posix timer
#define SYS_timer_getoverrun    109  // timer_getoverrun(tid)              — get missed expirations
#define SYS_timer_settime       110  // timer_settime(tid, fl, new, old)   — arm posix timer
#define SYS_timer_delete        111  // timer_delete(tid)                  — delete posix timer
#define SYS_clock_settime       112  // clock_settime(clkid, tp)           — set clock (root)
#define SYS_clock_gettime       113  // clock_gettime(clkid, tp)           — get high-resolution time
#define SYS_clock_getres        114  // clock_getres(clkid, res)           — get clock resolution
#define SYS_clock_nanosleep     115  // clock_nanosleep(clk, fl, req, rem) — sleep against specific clock
#define SYS_syslog              116  // syslog(type, buf, len)             — read or control kernel ring buffer
#define SYS_ptrace              117  // ptrace(request, pid, addr, data)   — trace/debug process
#define SYS_sched_setparam      118  // sched_setparam(pid, param)         — set scheduler parameters
#define SYS_sched_setscheduler  119  // sched_setscheduler(pid, pol, param)
#define SYS_sched_getscheduler  120  // sched_getscheduler(pid)            — get current scheduling policy
#define SYS_sched_getparam      121  // sched_getparam(pid, param)
#define SYS_sched_setaffinity   122  // sched_setaffinity(pid, sz, mask)   — bind process to cpu set
#define SYS_sched_getaffinity   123  // sched_getaffinity(pid, sz, mask)   — get cpu affinity mask
#define SYS_sched_yield         124  // sched_yield()                      — voluntarily give up cpu
#define SYS_sched_get_priority_max 125
#define SYS_sched_get_priority_min 126
#define SYS_sched_rr_get_interval  127
#define SYS_restart_syscall     128  // restart_syscall()                  — restart interrupted syscall
#define SYS_kill                129  // kill(pid, sig)                     — send signal to process or group
#define SYS_tkill               130  // tkill(tid, sig)                    — send signal to specific thread
#define SYS_tgkill              131  // tgkill(tgid, tid, sig)             — tkill with group validation
#define SYS_sigaltstack         132  // sigaltstack(ss, oss)               — set alternate signal stack
#define SYS_rt_sigsuspend       133  // rt_sigsuspend(mask, sz)            — replace mask and wait for signal
#define SYS_rt_sigaction        134  // rt_sigaction(sig, act, oact, sz)   — install signal handler
#define SYS_rt_sigprocmask      135  // rt_sigprocmask(how, set, oset, sz) — get/set blocked signals
#define SYS_rt_sigpending       136  // rt_sigpending(set, sz)             — query pending signals
#define SYS_rt_sigtimedwait     137  // rt_sigtimedwait(set, info, ts, sz) — wait for signal with timeout
#define SYS_rt_sigqueueinfo     138  // rt_sigqueueinfo(pid, sig, info)    — send signal with extra data
#define SYS_rt_sigreturn        139  // rt_sigreturn()                     — return from signal handler (kernel use)
#define SYS_setpriority         140  // setpriority(which, who, prio)      — set scheduling priority (nice)
#define SYS_getpriority         141  // getpriority(which, who)            — get scheduling priority
#define SYS_reboot              142  // reboot(magic, magic2, cmd, arg)    — reboot or power off
#define SYS_setregid            143  // setregid(rgid, egid)
#define SYS_setgid              144  // setgid(gid)
#define SYS_setreuid            145  // setreuid(ruid, euid)
#define SYS_setuid              146  // setuid(uid)
#define SYS_setresuid           147  // setresuid(ruid, euid, suid)
#define SYS_getresuid           148  // getresuid(ruid, euid, suid)
#define SYS_setresgid           149  // setresgid(rgid, egid, sgid)
#define SYS_getresgid           150  // getresgid(rgid, egid, sgid)
#define SYS_setfsuid            151  // setfsuid(uid)                      — set filesystem uid
#define SYS_setfsgid            152  // setfsgid(gid)                      — set filesystem gid
#define SYS_times               153  // times(tbuf)                        — get process cpu times
#define SYS_setpgid             154  // setpgid(pid, pgid)
#define SYS_getpgid             155  // getpgid(pid)
#define SYS_getsid              156  // getsid(pid)                        — get session id
#define SYS_setsid              157  // setsid()                           — create new session
#define SYS_getgroups           158  // getgroups(size, list)
#define SYS_setgroups           159  // setgroups(size, list)
#define SYS_uname               160  // uname(buf)                         — get kernel/os information
#define SYS_sethostname         161  // sethostname(name, len)
#define SYS_setdomainname       162  // setdomainname(name, len)
#define SYS_getrlimit           163  // getrlimit(resource, rlim)          — get resource limit
#define SYS_setrlimit           164  // setrlimit(resource, rlim)          — set resource limit
#define SYS_getrusage           165  // getrusage(who, rusage)             — get resource usage stats
#define SYS_umask               166  // umask(mask)                        — set file creation mask
#define SYS_prctl               167  // prctl(option, ...)                 — control process attributes
#define SYS_getcpu              168  // getcpu(cpup, nodep, tcache)        — get current cpu and numa node
#define SYS_gettimeofday        169  // gettimeofday(tv, tz)               — get wall clock time
#define SYS_settimeofday        170  // settimeofday(tv, tz)               — set wall clock time
#define SYS_adjtimex            171  // adjtimex(buf)                      — tune kernel clock (ntp)
#define SYS_getpid              172  // getpid()                           — get process id
#define SYS_getppid             173  // getppid()                          — get parent process id
#define SYS_getuid              174  // getuid()                           — get real user id
#define SYS_geteuid             175  // geteuid()                          — get effective user id
#define SYS_getgid              176  // getgid()                           — get real group id
#define SYS_getegid             177  // getegid()                          — get effective group id
#define SYS_gettid              178  // gettid()                           — get thread id
#define SYS_sysinfo             179  // sysinfo(info)                      — system stats (ram, swap, uptime)
#define SYS_mq_open             180  // mq_open(name, flags, mode, attr)   — open posix message queue
#define SYS_mq_unlink           181  // mq_unlink(name)                    — delete posix message queue
#define SYS_mq_timedsend        182  // mq_timedsend(mqdes, msg, len, prio, ts)
#define SYS_mq_timedreceive     183  // mq_timedreceive(mqdes, buf, len, prio, ts)
#define SYS_mq_notify           184  // mq_notify(mqdes, sevp)             — notify on message arrival
#define SYS_mq_getsetattr       185  // mq_getsetattr(mqdes, new, old)
#define SYS_msgget              186  // msgget(key, msgflg)                — get or create sysv message queue
#define SYS_msgctl              187  // msgctl(msqid, cmd, buf)
#define SYS_msgrcv              188  // msgrcv(msqid, msgp, msgsz, ...)
#define SYS_msgsnd              189  // msgsnd(msqid, msgp, msgsz, fl)
#define SYS_semget              190  // semget(key, nsems, semflg)         — get or create sysv semaphore set
#define SYS_semctl              191  // semctl(semid, semnum, cmd, ...)
#define SYS_semtimedop          192  // semtimedop(semid, sops, n, ts)     — semaphore ops with timeout
#define SYS_semop               193  // semop(semid, sops, nsops)          — atomic semaphore operations
#define SYS_shmget              194  // shmget(key, size, fl)              — get or create shared memory
#define SYS_shmctl              195  // shmctl(shmid, cmd, buf)
#define SYS_shmat               196  // shmat(shmid, addr, fl)             — attach shared memory to process
#define SYS_shmdt               197  // shmdt(shmaddr)                     — detach shared memory
#define SYS_socket              198  // socket(domain, type, protocol)     — create socket
#define SYS_socketpair          199  // socketpair(dom, type, proto, sv)   — pair of connected sockets
#define SYS_bind                200  // bind(sockfd, addr, addrlen)        — assign address to socket
#define SYS_listen              201  // listen(sockfd, backlog)            — mark socket as passive
#define SYS_accept              202  // accept(sockfd, addr, addrlen)      — accept incoming connection
#define SYS_connect             203  // connect(sockfd, addr, addrlen)     — initiate connection
#define SYS_getsockname         204  // getsockname(sockfd, addr, len)     — get local socket address
#define SYS_getpeername         205  // getpeername(sockfd, addr, len)     — get remote socket address
#define SYS_sendto              206  // sendto(s, buf, len, fl, to, tlen)
#define SYS_recvfrom            207  // recvfrom(s, buf, len, fl, fr, fl2)
#define SYS_setsockopt          208  // setsockopt(s, lvl, opt, val, len)
#define SYS_getsockopt          209  // getsockopt(s, lvl, opt, val, len)
#define SYS_shutdown            210  // shutdown(sockfd, how)
#define SYS_sendmsg             211  // sendmsg(sockfd, msg, flags)
#define SYS_recvmsg             212  // recvmsg(sockfd, msg, flags)
#define SYS_readahead           213  // readahead(fd, offset, count)       — prefetch into page cache
#define SYS_brk                 214  // brk(addr)                          — change data segment end
#define SYS_munmap              215  // munmap(addr, len)                  — unmap memory region
#define SYS_mremap              216  // mremap(old, osz, nsz, flags, new)  — resize mapping
#define SYS_add_key             217  // add_key(type, desc, payload, plen, ring) — add key to keyring
#define SYS_request_key         218  // request_key(type, desc, info, ring) — search keyrings for key
#define SYS_keyctl              219  // keyctl(cmd, ...)                   — key management operations
#define SYS_clone               220  // clone(flags, stack, ptid, tls, ctid) — create thread or process
#define SYS_execve              221  // execve(path, argv, envp)           — replace process image
#define SYS_mmap                222  // mmap(addr, len, prot, fl, fd, off) — map file or anonymous memory
#define SYS_fadvise64           223  // fadvise64(fd, off, len, advice)    — hint about file access pattern
#define SYS_swapon              224  // swapon(path, swapflags)            — enable swap area
#define SYS_swapoff             225  // swapoff(path)                      — disable swap area
#define SYS_mprotect            226  // mprotect(addr, len, prot)          — change memory region permissions
#define SYS_msync               227  // msync(addr, len, flags)            — sync mapping to file
#define SYS_mlock               228  // mlock(addr, len)                   — lock pages in ram
#define SYS_munlock             229  // munlock(addr, len)                 — unlock pages
#define SYS_mlockall            230  // mlockall(flags)                    — lock all process memory
#define SYS_munlockall          231  // munlockall()                       — unlock all process memory
#define SYS_mincore             232  // mincore(addr, len, vec)            — check which pages are in ram
#define SYS_madvise             233  // madvise(addr, len, advice)         — hint about memory usage
#define SYS_mbind               235  // mbind(addr, len, mode, nodemask, max, fl) — set numa memory policy
#define SYS_get_mempolicy       236  // get_mempolicy(mode, nodemask, max, addr, fl)
#define SYS_set_mempolicy       237  // set_mempolicy(mode, nodemask, maxnode)
#define SYS_migrate_pages       238  // migrate_pages(pid, maxnode, from, to)
#define SYS_move_pages          239  // move_pages(pid, nr, pages, nodes, status, fl)
#define SYS_rt_tgsigqueueinfo   240  // rt_tgsigqueueinfo(tgid, tid, sig, info) — send signal with data to thread
#define SYS_perf_event_open     241  // perf_event_open(attr, pid, cpu, gfd, fl) — performance counters
#define SYS_accept4             242  // accept4(sockfd, addr, addrlen, fl) — accept with flags
#define SYS_recvmmsg            243  // recvmmsg(sockfd, msgvec, vlen, fl, to) — receive multiple messages
#define SYS_wait4               260  // wait4(pid, wstatus, opts, rusage)  — wait for child
#define SYS_prlimit64           261  // prlimit64(pid, res, new, old)      — get/set resource limits
#define SYS_fanotify_init       262  // fanotify_init(flags, event_f_flags) — filesystem event monitor
#define SYS_fanotify_mark       263  // fanotify_mark(fd, fl, mask, dfd, path)
#define SYS_name_to_handle_at   264  // name_to_handle_at(dfd, path, fh, mnt_id, fl)
#define SYS_open_by_handle_at   265  // open_by_handle_at(mfd, fh, flags)
#define SYS_clock_adjtime       266  // clock_adjtime(clkid, tx)           — fine-tune clock
#define SYS_syncfs              267  // syncfs(fd)                         — flush specific filesystem
#define SYS_setns               268  // setns(fd, nstype)                  — join namespace
#define SYS_sendmmsg            269  // sendmmsg(sockfd, msgvec, vlen, fl) — send multiple messages
#define SYS_process_vm_readv    270  // process_vm_readv(pid, ...)         — read another process memory
#define SYS_process_vm_writev   271  // process_vm_writev(pid, ...)        — write another process memory
#define SYS_kcmp                272  // kcmp(pid1, pid2, type, idx1, idx2) — compare process resources
#define SYS_finit_module        273  // finit_module(fd, uargs, flags)     — load kernel module from fd
#define SYS_sched_setattr       274  // sched_setattr(pid, attr, flags)    — set extended scheduler attrs
#define SYS_sched_getattr       275  // sched_getattr(pid, attr, sz, flags)
#define SYS_renameat2           276  // renameat2(odfd, op, ndfd, np, flags) — rename with atomic swap
#define SYS_seccomp             277  // seccomp(op, flags, uargs)          — restrict available syscalls
#define SYS_getrandom           278  // getrandom(buf, count, flags)       — fill with cryptographic random bytes
#define SYS_memfd_create        279  // memfd_create(name, flags)          — create anonymous file in ram
#define SYS_bpf                 280  // bpf(cmd, attr, size)               — load/manage ebpf programs
#define SYS_execveat            281  // execveat(dirfd, path, argv, envp, fl) — execve relative to dirfd
#define SYS_userfaultfd         282  // userfaultfd(flags)                 — handle page faults in userspace
#define SYS_membarrier          283  // membarrier(cmd, flags)             — memory barriers between threads
#define SYS_mlock2              284  // mlock2(addr, len, flags)           — mlock with flags
#define SYS_copy_file_range     285  // copy_file_range(fin,offin,fout,offout,len,fl) — copy-on-write file copy
#define SYS_preadv2             286  // preadv2(fd, iov, iovcnt, off_lo, off_hi, fl)
#define SYS_pwritev2            287  // pwritev2(fd, iov, iovcnt, off_lo, off_hi, fl)
#define SYS_pkey_mprotect       288  // pkey_mprotect(addr, len, prot, pkey) — mprotect with protection key
#define SYS_pkey_alloc          289  // pkey_alloc(flags, access_rights)   — allocate memory protection key
#define SYS_pkey_free           290  // pkey_free(pkey)
#define SYS_statx               291  // statx(dirfd, path, flags, mask, statxbuf) — extended stat
#define SYS_io_pgetevents       292  // io_pgetevents(ctx, min, max, evs, to, usig)
#define SYS_rseq                293  // rseq(rseq, rseq_len, flags, sig)   — register restartable sequences
#define SYS_kexec_file_load     294  // kexec_file_load(kfd, ifd, ncmds, cmds, fl)
#define SYS_pidfd_send_signal   424  // pidfd_send_signal(pidfd, sig, info, fl) — send signal via pidfd
#define SYS_io_uring_setup      425  // io_uring_setup(entries, params)    — create io_uring instance
#define SYS_io_uring_enter      426  // io_uring_enter(fd, to_submit, ...)  — submit and/or wait for cqes
#define SYS_io_uring_register   427  // io_uring_register(fd, op, arg, nr) — register resources with ring
#define SYS_open_tree           428  // open_tree(dfd, path, flags)        — open a mount object
#define SYS_move_mount          429  // move_mount(from_dfd, from_path, to_dfd, to_path, fl)
#define SYS_fsopen              430  // fsopen(fsname, flags)              — open filesystem for configuration
#define SYS_fsconfig            431  // fsconfig(fs_fd, cmd, key, value, aux)
#define SYS_fsmount             432  // fsmount(fs_fd, flags, attr_flags)
#define SYS_fspick              433  // fspick(dfd, path, flags)
#define SYS_pidfd_open          434  // pidfd_open(pid, flags)             — get fd for process
#define SYS_clone3              435  // clone3(args, size)                 — extended clone
#define SYS_close_range         436  // close_range(first, last, flags)    — close range of fds
#define SYS_openat2             437  // openat2(dirfd, path, how, size)    — open with extended options
#define SYS_pidfd_getfd         438  // pidfd_getfd(pidfd, targetfd, flags) — copy fd from another process
#define SYS_faccessat2          439  // faccessat2(dirfd, path, mode, flags)
#define SYS_process_madvise     440  // process_madvise(pidfd, iov, cnt, behav, fl) — madvise for another process
#define SYS_epoll_pwait2        441  // epoll_pwait2(epfd, evts, max, ts, mask)
#define SYS_mount_setattr       442  // mount_setattr(dfd, path, flags, uattr, usize)
#define SYS_quotactl_fd         443  // quotactl_fd(fd, cmd, id, addr)
#define SYS_landlock_create_ruleset 444
#define SYS_landlock_add_rule   445
#define SYS_landlock_restrict_self 446
#define SYS_memfd_secret        447  // memfd_secret(flags)                — secret memory region
#define SYS_process_mrelease    448  // process_mrelease(pidfd, flags)     — release memory of dying process
#define SYS_futex_waitv         449  // futex_waitv(waiters, nr, fl, to, clk) — wait on multiple futexes
#define SYS_set_mempolicy_home_node 450 // set_mempolicy_home_node(start, len, home_node, flags)


// signals
#define SIG_CHLD    17
// Самописный uintptr_t для безопасного приведения любых типов и указателей
typedef unsigned long uintptr_t;

// Вспомогательный макрос приведения к long для регистров ARM64
#define __SYS_ARG(x) ((long)(uintptr_t)(x))

// ─── Базовый ассемблерный сисколл ARM64 ───────────────
static inline long raw_syscall6_impl(long n, long a0, long a1, long a2,
                                      long a3, long a4, long a5) {
    register long x8 __asm__("x8") = n;
    register long x0 __asm__("x0") = a0;
    register long x1 __asm__("x1") = a1;
    register long x2 __asm__("x2") = a2;
    register long x3 __asm__("x3") = a3;
    register long x4 __asm__("x4") = a4;
    register long x5 __asm__("x5") = a5;
    __asm__ volatile ("svc #0"
        : "+r"(x0)
        : "r"(x8), "r"(x1), "r"(x2), "r"(x3), "r"(x4), "r"(x5)
        : "memory");
    return x0;
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
