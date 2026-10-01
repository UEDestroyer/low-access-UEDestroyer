#pragma once

// ============================================================
//  syscall numbers — arm (32-bit) linux (eabi)
//  calling convention: r7=nr, r0..r6=args
//  entry:              svc #0  (eabi)  /  swi #0 (oabi, deprecated)
//  return:             r0 (negative = -errno)
//  thumb mode:         same registers, svc #0
//  source:             linux/arch/arm/tools/syscall.tbl
//  note:               arm-specific calls use range 0xF0000+
//                      *_time64 variants (403+) are y2038-safe
// ============================================================

// ─── arm-specific ────────────────────────────────────────────
#define SYS_ARM_BASE            0xF0000
#define SYS_ARM_breakpoint      (SYS_ARM_BASE + 1)  // breakpoint()                  — software breakpoint trap
#define SYS_ARM_cacheflush      (SYS_ARM_BASE + 2)  // cacheflush(start, end, flags) — flush instruction/data cache (required after jit codegen)
#define SYS_ARM_usr26           (SYS_ARM_BASE + 3)  // usr26()                       — switch to 26-bit mode (legacy kernels only)
#define SYS_ARM_usr32           (SYS_ARM_BASE + 4)  // usr32()                       — switch to 32-bit mode
#define SYS_ARM_set_tls         (SYS_ARM_BASE + 5)  // set_tls(val)                  — set tls pointer via TPIDRURW register
#define SYS_ARM_get_tls         (SYS_ARM_BASE + 6)  // get_tls()                     — read tls pointer via TPIDRURO (fast, no kernel entry)

// ─── file i/o ────────────────────────────────────────────────
#define SYS_restart_syscall     0    // restart_syscall()                  — restart interrupted syscall after signal
#define SYS_exit                1    // exit(status)                       — terminate current thread
#define SYS_fork                2    // fork()                             — duplicate process
#define SYS_read                3    // read(fd, buf, count)               — read bytes from fd
#define SYS_write               4    // write(fd, buf, count)              — write bytes to fd
#define SYS_open                5    // open(path, flags, mode)            — open or create file (use openat where possible)
#define SYS_close               6    // close(fd)                          — close file descriptor
#define SYS_creat               8    // creat(path, mode)                  — create/truncate file
#define SYS_link                9    // link(oldpath, newpath)             — create hard link
#define SYS_unlink              10   // unlink(path)                       — remove filename
#define SYS_execve              11   // execve(path, argv, envp)           — replace process image
#define SYS_chdir               12   // chdir(path)                        — change working directory
#define SYS_mknod               14   // mknod(path, mode, dev)             — create special file
#define SYS_chmod               15   // chmod(path, mode)                  — change file permissions
#define SYS_lchown              16   // lchown(path, uid, gid)             — change owner without following symlink
#define SYS_lseek               19   // lseek(fd, offset, whence)          — reposition offset (32-bit, use _llseek for 64-bit)
#define SYS_getpid              20   // getpid()                           — get process id
#define SYS_mount               21   // mount(src, tgt, fs, fl, data)      — mount filesystem
#define SYS_umount              22   // umount(target)                     — unmount (deprecated, use umount2)
#define SYS_setuid              23   // setuid(uid)                        — set user id
#define SYS_getuid              24   // getuid()                           — get real user id
#define SYS_ptrace              26   // ptrace(request, pid, addr, data)   — trace/debug process
#define SYS_pause               29   // pause()                            — wait for any signal
#define SYS_utime               30   // utime(path, times)                 — set file timestamps (deprecated)
#define SYS_access              33   // access(path, mode)                 — check file access permissions
#define SYS_nice                34   // nice(inc)                          — adjust priority (deprecated, use setpriority)
#define SYS_sync                36   // sync()                             — flush all filesystem caches
#define SYS_kill                37   // kill(pid, sig)                     — send signal to process or group
#define SYS_rename              38   // rename(oldpath, newpath)           — rename or move file
#define SYS_mkdir               39   // mkdir(path, mode)                  — create directory
#define SYS_rmdir               40   // rmdir(path)                        — remove empty directory
#define SYS_dup                 41   // dup(fd)                            — duplicate fd
#define SYS_pipe                42   // pipe(pipefd)                       — create pipe
#define SYS_times               43   // times(tbuf)                        — get process cpu times
#define SYS_brk                 45   // brk(addr)                          — change data segment end
#define SYS_setgid              46   // setgid(gid)
#define SYS_getgid              47   // getgid()
#define SYS_geteuid             49   // geteuid()
#define SYS_getegid             50   // getegid()
#define SYS_acct                51   // acct(path)                         — process accounting
#define SYS_umount2             52   // umount2(target, flags)             — unmount with flags
#define SYS_ioctl               54   // ioctl(fd, request, ...)            — device-specific control
#define SYS_fcntl               55   // fcntl(fd, cmd, ...)                — manipulate file descriptor
#define SYS_setpgid             57   // setpgid(pid, pgid)
#define SYS_umask               60   // umask(mask)
#define SYS_chroot              61   // chroot(path)
#define SYS_dup2                63   // dup2(oldfd, newfd)
#define SYS_getppid             64   // getppid()
#define SYS_getpgrp             65   // getpgrp()
#define SYS_setsid              66   // setsid()                           — create new session
#define SYS_sigaction           67   // sigaction(sig, act, oact)          — signal handler (old abi, use rt_sigaction)
#define SYS_setreuid            70   // setreuid(ruid, euid)
#define SYS_setregid            71   // setregid(rgid, egid)
#define SYS_sigsuspend          72   // sigsuspend(mask)                   — old abi
#define SYS_sigpending          73   // sigpending(set)                    — old abi
#define SYS_sethostname         74   // sethostname(name, len)
#define SYS_setrlimit           75   // setrlimit(res, rlim)
#define SYS_getrusage           77   // getrusage(who, rusage)
#define SYS_gettimeofday        78   // gettimeofday(tv, tz)
#define SYS_settimeofday        79   // settimeofday(tv, tz)
#define SYS_getgroups           80   // getgroups(size, list)
#define SYS_setgroups           81   // setgroups(size, list)
#define SYS_symlink             83   // symlink(target, linkpath)
#define SYS_readlink            85   // readlink(path, buf, bufsiz)
#define SYS_swapon              87   // swapon(path, swapflags)
#define SYS_reboot              88   // reboot(magic, magic2, cmd, arg)
#define SYS_munmap              91   // munmap(addr, len)
#define SYS_truncate            92   // truncate(path, length)
#define SYS_ftruncate           93   // ftruncate(fd, length)
#define SYS_fchmod              94   // fchmod(fd, mode)
#define SYS_fchown              95   // fchown(fd, uid, gid)
#define SYS_getpriority         96   // getpriority(which, who)
#define SYS_setpriority         97   // setpriority(which, who, prio)
#define SYS_statfs              99   // statfs(path, buf)
#define SYS_fstatfs             100  // fstatfs(fd, buf)
#define SYS_stat                106  // stat(path, statbuf)
#define SYS_lstat               107  // lstat(path, statbuf)               — stat without following symlink
#define SYS_fstat               108  // fstat(fd, statbuf)
#define SYS_vhangup             111  // vhangup()                          — hang up terminal
#define SYS_wait4               114  // wait4(pid, wstatus, opts, rusage)
#define SYS_swapoff             115  // swapoff(path)
#define SYS_sysinfo             116  // sysinfo(info)
#define SYS_ipc                 117  // ipc(call, ...)                     — sysv ipc multiplexer (sem/shm/msg in one nr)
#define SYS_fsync               118  // fsync(fd)
#define SYS_sigreturn           119  // sigreturn(...)                     — return from signal handler (old abi)
#define SYS_clone               120  // clone(flags, stack, ptid, tls, ctid) — create thread or process
#define SYS_setdomainname       121  // setdomainname(name, len)
#define SYS_uname               122  // uname(buf)
#define SYS_adjtimex            124  // adjtimex(buf)                      — tune kernel clock (ntp)
#define SYS_mprotect            125  // mprotect(addr, len, prot)
#define SYS_sigprocmask         126  // sigprocmask(how, set, oset)        — old abi, use rt_sigprocmask
#define SYS_init_module         128  // init_module(umod, len, uargs)
#define SYS_delete_module       129  // delete_module(name, flags)
#define SYS_quotactl            131  // quotactl(cmd, special, id, addr)
#define SYS_getpgid             132  // getpgid(pid)
#define SYS_fchdir              133  // fchdir(fd)
#define SYS_personality         136  // personality(persona)
#define SYS_setfsuid            138  // setfsuid(uid)
#define SYS_setfsgid            139  // setfsgid(gid)
#define SYS__llseek             140  // _llseek(fd, hi, lo, result, whence) — 64-bit seek on 32-bit system
#define SYS_getdents            141  // getdents(fd, dirent, count)        — deprecated, use getdents64
#define SYS__newselect          142  // _newselect(n, r, w, e, tv)         — select()
#define SYS_flock               143  // flock(fd, operation)               — advisory file lock
#define SYS_msync               144  // msync(addr, len, flags)
#define SYS_readv               145  // readv(fd, iov, iovcnt)
#define SYS_writev              146  // writev(fd, iov, iovcnt)
#define SYS_getsid              147  // getsid(pid)
#define SYS_fdatasync           148  // fdatasync(fd)
#define SYS_mlock               150  // mlock(addr, len)
#define SYS_munlock             151  // munlock(addr, len)
#define SYS_mlockall            152  // mlockall(flags)
#define SYS_munlockall          153  // munlockall()
#define SYS_sched_setparam      154  // sched_setparam(pid, param)
#define SYS_sched_getparam      155  // sched_getparam(pid, param)
#define SYS_sched_setscheduler  156  // sched_setscheduler(pid, pol, param)
#define SYS_sched_getscheduler  157  // sched_getscheduler(pid)
#define SYS_sched_yield         158  // sched_yield()                      — voluntarily give up cpu
#define SYS_sched_get_priority_max 159
#define SYS_sched_get_priority_min 160
#define SYS_sched_rr_get_interval  161
#define SYS_nanosleep           162  // nanosleep(req, rem)
#define SYS_mremap              163  // mremap(old, osz, nsz, flags, new)
#define SYS_setresuid           164  // setresuid(ruid, euid, suid)
#define SYS_getresuid           165  // getresuid(ruid, euid, suid)
#define SYS_poll                168  // poll(fds, nfds, timeout)
#define SYS_setresgid           170  // setresgid(rgid, egid, sgid)
#define SYS_getresgid           171  // getresgid(rgid, egid, sgid)
#define SYS_prctl               172  // prctl(option, ...)                 — control process attributes
#define SYS_rt_sigreturn        173  // rt_sigreturn()                     — return from signal handler (eabi)
#define SYS_rt_sigaction        174  // rt_sigaction(sig, act, oact, sz)   — install signal handler
#define SYS_rt_sigprocmask      175  // rt_sigprocmask(how, set, oset, sz)
#define SYS_rt_sigpending       176  // rt_sigpending(set, sz)
#define SYS_rt_sigtimedwait     177  // rt_sigtimedwait(set, info, ts, sz)
#define SYS_rt_sigqueueinfo     178  // rt_sigqueueinfo(pid, sig, info)
#define SYS_rt_sigsuspend       179  // rt_sigsuspend(mask, sz)
#define SYS_pread64             180  // pread64(fd, buf, count, off)
#define SYS_pwrite64            181  // pwrite64(fd, buf, count, off)
#define SYS_chown               182  // chown(path, uid, gid)
#define SYS_getcwd              183  // getcwd(buf, size)
#define SYS_capget              184  // capget(hdr, data)
#define SYS_capset              185  // capset(hdr, data)
#define SYS_sigaltstack         186  // sigaltstack(ss, oss)               — alternate signal stack
#define SYS_sendfile            187  // sendfile(outfd, infd, off, count)  — zero-copy file send
#define SYS_vfork               190  // vfork()                            — fork without memory copy
#define SYS_ugetrlimit          191  // ugetrlimit(resource, rlim)         — get resource limit
#define SYS_mmap2               192  // mmap2(addr, len, prot, fl, fd, pgoff) — mmap with offset in pages (not bytes!)
#define SYS_truncate64          193  // truncate64(path, length)           — 64-bit file size truncate
#define SYS_ftruncate64         194  // ftruncate64(fd, length)
#define SYS_stat64              195  // stat64(path, statbuf)              — 64-bit file metadata
#define SYS_lstat64             196  // lstat64(path, statbuf)
#define SYS_fstat64             197  // fstat64(fd, statbuf)
#define SYS_lchown32            198  // lchown32(path, uid, gid)           — 32-bit uid variant
#define SYS_getuid32            199  // getuid32()
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
#define SYS_getdents64          217  // getdents64(fd, dirent, count)      — read directory entries (64-bit)
#define SYS_pivot_root          218  // pivot_root(new_root, put_old)      — change root filesystem
#define SYS_mincore             219  // mincore(addr, len, vec)            — check which pages are in ram
#define SYS_madvise             220  // madvise(addr, len, advice)         — hint about memory usage
#define SYS_fcntl64             221  // fcntl64(fd, cmd, ...)              — 64-bit fcntl
#define SYS_gettid              224  // gettid()                           — get thread id
#define SYS_readahead           225  // readahead(fd, offset, count)       — prefetch file data
#define SYS_setxattr            226  // setxattr(path, name, val, sz, fl)  — set extended attribute
#define SYS_lsetxattr           227  // lsetxattr(path, name, val, sz, fl)
#define SYS_fsetxattr           228  // fsetxattr(fd, name, val, sz, fl)
#define SYS_getxattr            229  // getxattr(path, name, val, sz)
#define SYS_lgetxattr           230  // lgetxattr(path, name, val, sz)
#define SYS_fgetxattr           231  // fgetxattr(fd, name, val, sz)
#define SYS_listxattr           232  // listxattr(path, list, sz)
#define SYS_llistxattr          233  // llistxattr(path, list, sz)
#define SYS_flistxattr          234  // flistxattr(fd, list, sz)
#define SYS_removexattr         235  // removexattr(path, name)
#define SYS_lremovexattr        236  // lremovexattr(path, name)
#define SYS_fremovexattr        237  // fremovexattr(fd, name)
#define SYS_tkill               238  // tkill(tid, sig)                    — send signal to specific thread
#define SYS_sendfile64          239  // sendfile64(outfd, infd, off, count) — sendfile with 64-bit offset
#define SYS_futex               240  // futex(uaddr, op, val, to, uaddr2, v3) — fast userspace mutex
#define SYS_sched_setaffinity   241  // sched_setaffinity(pid, sz, mask)
#define SYS_sched_getaffinity   242  // sched_getaffinity(pid, sz, mask)
#define SYS_io_setup            245  // io_setup(nr_events, ctxp)          — initialize aio context
#define SYS_io_destroy          246  // io_destroy(ctx)
#define SYS_io_getevents        247  // io_getevents(ctx, min, max, evs, to)
#define SYS_io_submit           248  // io_submit(ctx, nr, iocbpp)
#define SYS_io_cancel           249  // io_cancel(ctx, iocb, result)
#define SYS_fadvise64           250  // fadvise64(fd, off, len, advice)    — hint about file access pattern
#define SYS_exit_group          252  // exit_group(status)                 — terminate all threads
#define SYS_epoll_create        254  // epoll_create(size)
#define SYS_epoll_ctl           255  // epoll_ctl(epfd, op, fd, event)
#define SYS_epoll_wait          256  // epoll_wait(epfd, evts, max, to)
#define SYS_set_tid_address     256  // set_tid_address(tidptr)            — set address cleared on thread exit
#define SYS_timer_create        257  // timer_create(clkid, evp, tid)
#define SYS_timer_settime       258  // timer_settime(tid, fl, new, old)
#define SYS_timer_gettime       259  // timer_gettime(tid, curr)
#define SYS_timer_getoverrun    260  // timer_getoverrun(tid)
#define SYS_timer_delete        261  // timer_delete(tid)
#define SYS_clock_settime       262  // clock_settime(clkid, tp)
#define SYS_clock_gettime       263  // clock_gettime(clkid, tp)
#define SYS_clock_getres        264  // clock_getres(clkid, res)
#define SYS_clock_nanosleep     265  // clock_nanosleep(clk, fl, req, rem)
#define SYS_statfs64            266  // statfs64(path, sz, buf)
#define SYS_fstatfs64           267  // fstatfs64(fd, sz, buf)
#define SYS_tgkill              268  // tgkill(tgid, tid, sig)             — signal to thread with group check
#define SYS_utimes              269  // utimes(path, times)
#define SYS_fadvise64_64        270  // fadvise64_64(fd, off, len, advice) — 64-bit fadvise
#define SYS_waitid              280  // waitid(type, id, infop, opts)
#define SYS_socket              281  // socket(domain, type, protocol)
#define SYS_bind                282  // bind(sockfd, addr, addrlen)
#define SYS_connect             283  // connect(sockfd, addr, addrlen)
#define SYS_listen              284  // listen(sockfd, backlog)
#define SYS_accept              285  // accept(sockfd, addr, addrlen)
#define SYS_getsockname         286  // getsockname(sockfd, addr, len)
#define SYS_getpeername         287  // getpeername(sockfd, addr, len)
#define SYS_socketpair          288  // socketpair(dom, type, proto, sv)
#define SYS_send                289  // send(s, buf, len, flags)
#define SYS_sendto              290  // sendto(s, buf, len, fl, to, tlen)
#define SYS_recv                291  // recv(s, buf, len, flags)
#define SYS_recvfrom            292  // recvfrom(s, buf, len, fl, from, fromlen)
#define SYS_shutdown            293  // shutdown(sockfd, how)
#define SYS_setsockopt          294  // setsockopt(s, lvl, opt, val, len)
#define SYS_getsockopt          295  // getsockopt(s, lvl, opt, val, len)
#define SYS_sendmsg             296  // sendmsg(sockfd, msg, flags)
#define SYS_recvmsg             297  // recvmsg(sockfd, msg, flags)
#define SYS_semop               298  // semop(semid, sops, nsops)
#define SYS_semget              299  // semget(key, nsems, semflg)
#define SYS_semctl              300  // semctl(semid, semnum, cmd, ...)
#define SYS_msgsnd              301  // msgsnd(msqid, msgp, msgsz, fl)
#define SYS_msgrcv              302  // msgrcv(msqid, msgp, msgsz, ...)
#define SYS_msgget              303  // msgget(key, msgflg)
#define SYS_msgctl              304  // msgctl(msqid, cmd, buf)
#define SYS_shmat               305  // shmat(shmid, addr, fl)
#define SYS_shmdt               306  // shmdt(shmaddr)
#define SYS_shmget              307  // shmget(key, size, fl)
#define SYS_shmctl              308  // shmctl(shmid, cmd, buf)
#define SYS_add_key             309  // add_key(type, desc, payload, plen, ring)
#define SYS_request_key         310  // request_key(type, desc, info, ring)
#define SYS_keyctl              311  // keyctl(cmd, ...)
#define SYS_semtimedop          312  // semtimedop(semid, sops, n, ts)     — semop with timeout
#define SYS_ioprio_set          314  // ioprio_set(which, who, ioprio)     — set i/o priority
#define SYS_ioprio_get          315  // ioprio_get(which, who)
#define SYS_inotify_init        316  // inotify_init()                     — create inotify instance
#define SYS_inotify_add_watch   317  // inotify_add_watch(fd, path, mask)
#define SYS_inotify_rm_watch    318  // inotify_rm_watch(fd, wd)
#define SYS_mbind               319  // mbind(addr, len, mode, nodemask, max, fl) — numa memory policy
#define SYS_get_mempolicy       320  // get_mempolicy(mode, nodemask, max, addr, fl)
#define SYS_set_mempolicy       321  // set_mempolicy(mode, nodemask, maxnode)
#define SYS_openat              322  // openat(dirfd, path, flags, mode)   — open relative to dirfd
#define SYS_mkdirat             323  // mkdirat(dirfd, path, mode)
#define SYS_mknodat             324  // mknodat(dirfd, path, mode, dev)
#define SYS_fchownat            325  // fchownat(dirfd, path, uid, gid, fl)
#define SYS_futimesat           326  // futimesat(dirfd, path, times)      — deprecated, use utimensat
#define SYS_fstatat64           327  // fstatat64(dirfd, path, statbuf, fl) — stat relative to dirfd
#define SYS_unlinkat            328  // unlinkat(dirfd, path, flags)
#define SYS_renameat            329  // renameat(oldfd, oldpath, newfd, newpath)
#define SYS_linkat              330  // linkat(oldfd, oldp, newfd, newp, fl)
#define SYS_symlinkat           331  // symlinkat(target, newdirfd, linkpath)
#define SYS_readlinkat          332  // readlinkat(dirfd, path, buf, sz)
#define SYS_fchmodat            333  // fchmodat(dirfd, path, mode, fl)
#define SYS_faccessat           334  // faccessat(dirfd, path, mode, fl)
#define SYS_pselect6            335  // pselect6(n, r, w, e, ts, sigmask)
#define SYS_ppoll               336  // ppoll(fds, nfds, ts, sigmask)
#define SYS_unshare             337  // unshare(flags)                     — disassociate namespaces
#define SYS_set_robust_list     338  // set_robust_list(head, len)
#define SYS_get_robust_list     339  // get_robust_list(pid, head, len)
#define SYS_splice              340  // splice(fdin, offin, fdout, offout, len, fl)
#define SYS_sync_file_range2    341  // sync_file_range2(fd, fl, off, nb)  — note: arg order differs from x86!
#define SYS_tee                 342  // tee(fdin, fdout, len, flags)
#define SYS_vmsplice            343  // vmsplice(fd, iov, cnt, fl)
#define SYS_move_pages          344  // move_pages(pid, nr, pages, nodes, status, fl)
#define SYS_getcpu              345  // getcpu(cpup, nodep, tcache)        — get current cpu and numa node
#define SYS_epoll_pwait         346  // epoll_pwait(epfd, evts, max, to, sm)
#define SYS_kexec_load          347  // kexec_load(entry, nr, segs, fl)
#define SYS_utimensat           348  // utimensat(dirfd, path, times, fl)  — nanosecond timestamp precision
#define SYS_signalfd            349  // signalfd(fd, mask, sz)
#define SYS_timerfd_create      350  // timerfd_create(clockid, flags)
#define SYS_eventfd             351  // eventfd(initval)
#define SYS_fallocate           352  // fallocate(fd, mode, off, len)      — preallocate disk space
#define SYS_timerfd_settime     353  // timerfd_settime(fd, fl, new, old)
#define SYS_timerfd_gettime     354  // timerfd_gettime(fd, curr)
#define SYS_signalfd4           355  // signalfd4(fd, mask, sz, flags)
#define SYS_eventfd2            356  // eventfd2(initval, flags)
#define SYS_epoll_create1       357  // epoll_create1(flags)
#define SYS_dup3                358  // dup3(oldfd, newfd, flags)
#define SYS_pipe2               359  // pipe2(pipefd, flags)
#define SYS_inotify_init1       360  // inotify_init1(flags)
#define SYS_preadv              361  // preadv(fd, iov, iovcnt, off_lo, off_hi)
#define SYS_pwritev             362  // pwritev(fd, iov, iovcnt, off_lo, off_hi)
#define SYS_rt_tgsigqueueinfo   363  // rt_tgsigqueueinfo(tgid, tid, sig, info)
#define SYS_perf_event_open     364  // perf_event_open(attr, pid, cpu, gfd, fl)
#define SYS_recvmmsg            365  // recvmmsg(sockfd, msgvec, vlen, fl, to)
#define SYS_accept4             366  // accept4(sockfd, addr, addrlen, fl)
#define SYS_fanotify_init       367  // fanotify_init(flags, event_f_flags)
#define SYS_fanotify_mark       368  // fanotify_mark(fd, fl, mask, dfd, path)
#define SYS_prlimit64           369  // prlimit64(pid, res, new, old)
#define SYS_name_to_handle_at   370  // name_to_handle_at(dfd, path, fh, mnt_id, fl)
#define SYS_open_by_handle_at   371  // open_by_handle_at(mfd, fh, flags)
#define SYS_clock_adjtime       372  // clock_adjtime(clkid, tx)
#define SYS_syncfs              373  // syncfs(fd)                         — flush specific filesystem
#define SYS_sendmmsg            374  // sendmmsg(sockfd, msgvec, vlen, fl)
#define SYS_setns               375  // setns(fd, nstype)                  — join namespace
#define SYS_process_vm_readv    376  // process_vm_readv(pid, ...)         — read another process memory
#define SYS_process_vm_writev   377  // process_vm_writev(pid, ...)
#define SYS_kcmp                378  // kcmp(pid1, pid2, type, idx1, idx2)
#define SYS_finit_module        379  // finit_module(fd, uargs, flags)     — load kernel module from fd
#define SYS_sched_setattr       380  // sched_setattr(pid, attr, flags)
#define SYS_sched_getattr       381  // sched_getattr(pid, attr, sz, flags)
#define SYS_renameat2           382  // renameat2(odfd, op, ndfd, np, flags) — rename with atomic swap
#define SYS_seccomp             383  // seccomp(op, flags, uargs)          — restrict available syscalls
#define SYS_getrandom           384  // getrandom(buf, count, flags)       — get cryptographic random bytes
#define SYS_memfd_create        385  // memfd_create(name, flags)          — anonymous file in ram
#define SYS_bpf                 386  // bpf(cmd, attr, size)               — load/manage ebpf programs
#define SYS_execveat            387  // execveat(dirfd, path, argv, envp, fl)
#define SYS_userfaultfd         388  // userfaultfd(flags)                 — handle page faults in userspace
#define SYS_membarrier          389  // membarrier(cmd, flags)             — memory barriers between threads
#define SYS_mlock2              390  // mlock2(addr, len, flags)
#define SYS_copy_file_range     391  // copy_file_range(fdin, offin, fdout, offout, len, fl)
#define SYS_preadv2             392  // preadv2(fd, iov, iovcnt, off_lo, off_hi, fl)
#define SYS_pwritev2            393  // pwritev2(fd, iov, iovcnt, off_lo, off_hi, fl)
#define SYS_pkey_mprotect       394  // pkey_mprotect(addr, len, prot, pkey) — mprotect with protection key
#define SYS_pkey_alloc          395  // pkey_alloc(flags, access_rights)
#define SYS_pkey_free           396  // pkey_free(pkey)
#define SYS_statx               397  // statx(dirfd, path, flags, mask, statxbuf) — extended stat
#define SYS_rseq                398  // rseq(rseq, rseq_len, flags, sig)   — restartable sequences
#define SYS_io_pgetevents       399  // io_pgetevents(ctx, min, max, evs, to, usig)
#define SYS_migrate_pages       400  // migrate_pages(pid, maxnode, from, to)
#define SYS_kexec_file_load     401  // kexec_file_load(kfd, ifd, ncmds, cmds, fl)

// ─── y2038-safe *_time64 variants ────────────────────────────
//  these use 64-bit timespec on 32-bit kernels to avoid year 2038 overflow
#define SYS_clock_gettime64     403  // clock_gettime64(clkid, tp)
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

// ─── modern additions ────────────────────────────────────────
#define SYS_pidfd_send_signal   424  // pidfd_send_signal(pidfd, sig, info, fl)
#define SYS_io_uring_setup      425  // io_uring_setup(entries, params)    — create io_uring instance
#define SYS_io_uring_enter      426  // io_uring_enter(fd, to_submit, min, fl, argp, argsz)
#define SYS_io_uring_register   427  // io_uring_register(fd, op, arg, nr)
#define SYS_pidfd_open          434  // pidfd_open(pid, flags)
#define SYS_clone3              435  // clone3(args, size)                 — extended clone
#define SYS_close_range         436  // close_range(first, last, flags)    — close range of fds
#define SYS_openat2             437  // openat2(dirfd, path, how, size)    — open with extended options
#define SYS_pidfd_getfd         438  // pidfd_getfd(pidfd, targetfd, flags)
#define SYS_faccessat2          439  // faccessat2(dirfd, path, mode, flags)
#define SYS_process_madvise     440  // process_madvise(pidfd, iov, cnt, behav, fl)
#define SYS_epoll_pwait2        441  // epoll_pwait2(epfd, evts, max, ts, mask)
#define SYS_landlock_create_ruleset 444
#define SYS_landlock_add_rule   445
#define SYS_landlock_restrict_self  446
#define SYS_memfd_secret        447  // memfd_secret(flags)                — secret memory region
#define SYS_futex_waitv         449  // futex_waitv(waiters, nr, fl, to, clk) — wait on multiple futexes
