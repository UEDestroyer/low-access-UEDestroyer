#pragma once

// ============================================================
//  flags_linux.h — universal linux flag constants
//  all values are architecture-independent (asm-generic)
//  covers: mount, umount, signal, epoll, socket, poll,
//          clone/unshare, prctl, ioctl, ptrace, syslog,
//          reboot, rlimit, wait, clock ids, cap, memfd,
//          io_uring, bpf, seccomp, landlock, pidfd
// ============================================================

// ─── mount flags (SYS_mount — flags arg) ─────────────────────
#define MS_RDONLY           1        // mount read-only
#define MS_NOSUID           2        // ignore suid/sgid bits on executables
#define MS_NODEV            4        // disallow access to device special files
#define MS_NOEXEC           8        // disallow executing programs
#define MS_SYNCHRONOUS      16       // all writes are synchronous (like O_SYNC on every fd)
#define MS_REMOUNT          32       // change flags of already-mounted filesystem
#define MS_MANDLOCK         64       // allow mandatory file locks (deprecated)
#define MS_DIRSYNC          128      // directory changes are written synchronously
#define MS_NOSYMFOLLOW      256      // disallow following symlinks (since 5.10)
#define MS_NOATIME          1024     // do not update atime on file access
#define MS_NODIRATIME       2048     // do not update atime on directory access
#define MS_BIND             4096     // bind-mount: expose subtree at another point
#define MS_MOVE             8192     // atomically move a mounted subtree to a new location
#define MS_REC              16384    // apply operation recursively to all submounts
#define MS_SILENT           32768    // suppress printk warnings from filesystem
#define MS_POSIXACL         (1<<16)  // filesystem uses posix acl (set by kernel, not user)
#define MS_UNBINDABLE       (1<<17)  // mark mount as unbindable (cannot be bind-mounted)
#define MS_PRIVATE          (1<<18)  // mark mount as private (no propagation)
#define MS_SLAVE            (1<<19)  // receive propagation from master, do not propagate back
#define MS_SHARED           (1<<20)  // propagate mount events to peer group
#define MS_RELATIME         (1<<21)  // update atime only if mtime/ctime is newer than atime
#define MS_KERNMOUNT        (1<<22)  // internal kernel flag (not for userspace)
#define MS_I_VERSION        (1<<23)  // update i_version on each change
#define MS_STRICTATIME      (1<<24)  // always update atime (disables relatime/noatime)
#define MS_LAZYTIME         (1<<25)  // defer atime/mtime/ctime writes to disk (batch updates)
#define MS_ACTIVE           (1<<30)  // internal kernel flag
#define MS_NOUSER           (1<<31)  // internal: cannot be mounted by unprivileged user

// ─── umount2 flags (SYS_umount2 — flags arg) ─────────────────
#define MNT_FORCE           1        // force unmount even if device is busy (may corrupt data)
#define MNT_DETACH          2        // lazy unmount: detach now, clean up when last user leaves
#define MNT_EXPIRE          4        // mark as expired; second call with MNT_EXPIRE unmounts
#define UMOUNT_NOFOLLOW     8        // do not follow symlink in target path

// ─── signal numbers ───────────────────────────────────────────
#define SIGHUP              1        // hangup — terminal disconnected or controlling process died
#define SIGINT              2        // interrupt — sent by Ctrl+C
#define SIGQUIT             3        // quit — sent by Ctrl+\, produces core dump
#define SIGILL              4        // illegal instruction — invalid cpu instruction executed
#define SIGTRAP             5        // trace/breakpoint trap — used by debuggers
#define SIGABRT             6        // abort — sent by abort(3), produces core dump
#define SIGIOT              SIGABRT  // alias for SIGABRT (legacy)
#define SIGBUS              7        // bus error — misaligned memory access or hardware fault
#define SIGFPE              8        // floating point exception — divide by zero, overflow, etc.
#define SIGKILL             9        // kill — cannot be caught or ignored, always terminates
#define SIGUSR1             10       // user-defined signal 1 — application use
#define SIGSEGV             11       // segmentation fault — invalid memory access
#define SIGUSR2             12       // user-defined signal 2 — application use
#define SIGPIPE             13       // broken pipe — write to pipe/socket with no reader
#define SIGALRM             14       // alarm — sent by alarm(2) or setitimer(2)
#define SIGTERM             15       // termination — polite shutdown request (can be caught)
#define SIGSTKFLT           16       // stack fault on coprocessor (unused, kept for compat)
#define SIGCHLD             17       // child stopped or terminated — sent to parent
#define SIGCLD              SIGCHLD  // alias for SIGCHLD (sysv compat)
#define SIGCONT             18       // continue — resume process stopped by SIGSTOP/SIGTSTP
#define SIGSTOP             19       // stop — cannot be caught or ignored, always suspends
#define SIGTSTP             20       // terminal stop — sent by Ctrl+Z, can be caught
#define SIGTTIN             21       // background read from tty — sent to background process group
#define SIGTTOU             22       // background write to tty — sent to background process group
#define SIGURG              23       // urgent condition on socket — out-of-band data arrived
#define SIGXCPU             24       // cpu time limit exceeded (see RLIMIT_CPU)
#define SIGXFSZ             25       // file size limit exceeded (see RLIMIT_FSIZE)
#define SIGVTALRM           26       // virtual timer expired (ITIMER_VIRTUAL)
#define SIGPROF             27       // profiling timer expired (ITIMER_PROF)
#define SIGWINCH            28       // terminal window size changed
#define SIGIO               29       // i/o now possible on fd (async i/o, O_ASYNC)
#define SIGPOLL             SIGIO    // alias for SIGIO (sysv compat)
#define SIGPWR              30       // power failure — sent by init on ups events
#define SIGSYS              31       // bad system call argument — seccomp also uses this
#define SIGUNUSED           SIGSYS   // alias (historical)
#define SIGRTMIN            32       // first real-time signal (real-time signals: 32..64)
#define SIGRTMAX            64       // last real-time signal

// ─── signal action flags (sa_flags in struct sigaction) ──────
#define SA_NOCLDSTOP        0x00000001 // do not send SIGCHLD when child stops (only on termination)
#define SA_NOCLDWAIT        0x00000002 // do not create zombie — auto-reap children
#define SA_SIGINFO          0x00000004 // handler takes 3 args: sig, siginfo_t*, ucontext_t*
#define SA_ONSTACK          0x08000000 // deliver signal on alternate stack (sigaltstack)
#define SA_RESTART          0x10000000 // automatically restart slow syscalls after signal
#define SA_NODEFER          0x40000000 // do not block signal while handler runs
#define SA_RESETHAND        0x80000000 // reset handler to SIG_DFL after first delivery
#define SA_NOMASK           SA_NODEFER // alias
#define SA_ONESHOT          SA_RESETHAND // alias

// ─── signal mask operations (how arg to rt_sigprocmask) ──────
#define SIG_BLOCK           0        // add signals in set to current mask
#define SIG_UNBLOCK         1        // remove signals in set from current mask
#define SIG_SETMASK         2        // replace current mask with set

// ─── special signal handler values ───────────────────────────
#define SIG_DFL             ((void*)0)   // restore default handler
#define SIG_IGN             ((void*)1)   // ignore signal
#define SIG_ERR             ((void*)-1)  // error return from signal()

// ─── epoll events (events field in struct epoll_event) ───────
#define EPOLLIN             0x00000001 // fd is readable
#define EPOLLPRI            0x00000002 // urgent/out-of-band data available
#define EPOLLOUT            0x00000004 // fd is writable
#define EPOLLERR            0x00000008 // error condition (always monitored even if not set)
#define EPOLLHUP            0x00000010 // hang up — peer closed connection (always monitored)
#define EPOLLRDNORM         0x00000040 // normal data available (same as EPOLLIN on linux)
#define EPOLLRDBAND         0x00000080 // priority data available
#define EPOLLWRNORM         0x00000100 // normal data can be written
#define EPOLLWRBAND         0x00000200 // priority data can be written
#define EPOLLMSG            0x00000400 // ignored (compat)
#define EPOLLRDHUP          0x00002000 // peer half-closed the connection (read returns 0)
#define EPOLLEXCLUSIVE      (1u<<28)   // exclusive wake-up — only one waiter woken per event (since 4.5)
#define EPOLLWAKEUP         (1u<<29)   // prevent system suspend while event is pending
#define EPOLLONESHOT        (1u<<30)   // disable fd after one event; re-arm with EPOLL_CTL_MOD
#define EPOLLET             (1u<<31)   // edge-triggered mode (default is level-triggered)

// ─── epoll_ctl operations ─────────────────────────────────────
#define EPOLL_CTL_ADD       1        // add fd to epoll set
#define EPOLL_CTL_DEL       2        // remove fd from epoll set
#define EPOLL_CTL_MOD       3        // change events monitored for fd

// ─── poll / ppoll event flags (events/revents in struct pollfd) ──
#define POLLIN              0x0001   // data available to read
#define POLLPRI             0x0002   // urgent/out-of-band data available
#define POLLOUT             0x0004   // writing will not block
#define POLLERR             0x0008   // error condition (output only)
#define POLLHUP             0x0010   // hang up (output only)
#define POLLNVAL            0x0020   // invalid request: fd not open (output only)
#define POLLRDNORM          0x0040   // equivalent to POLLIN
#define POLLRDBAND          0x0080   // priority data available
#define POLLWRNORM          0x0100   // equivalent to POLLOUT
#define POLLWRBAND          0x0200   // priority data can be written
#define POLLMSG             0x0400   // ignored
#define POLLREMOVE          0x1000   // remove fd from pollset (used by some kernel interfaces)
#define POLLRDHUP           0x2000   // peer half-closed connection

// ─── socket domain (family) ───────────────────────────────────
#define AF_UNSPEC           0        // unspecified
#define AF_UNIX             1        // unix domain sockets (local ipc)
#define AF_LOCAL            AF_UNIX  // alias for AF_UNIX
#define AF_INET             2        // ipv4
#define AF_AX25             3        // amateur radio ax.25
#define AF_IPX              4        // novell ipx
#define AF_APPLETALK        5        // appletalk
#define AF_NETROM           6        // amateur radio net/rom
#define AF_BRIDGE           7        // multiprotocol bridge
#define AF_ATMPVC           8        // atm pvc
#define AF_X25              9        // x.25
#define AF_INET6            10       // ipv6
#define AF_ROSE             11       // amateur radio x.25 pls
#define AF_DECnet           12       // decnet
#define AF_NETBEUI          13       // 802.2llc
#define AF_SECURITY         14       // security callback pseudo af
#define AF_KEY              15       // pfkey key management
#define AF_NETLINK          16       // kernel netlink interface
#define AF_ROUTE            AF_NETLINK // alias: routing netlink
#define AF_PACKET           17       // low-level packet interface (raw ethernet)
#define AF_ASH              18       // ash
#define AF_ECONET           19       // acorn econet
#define AF_ATMSVC           20       // atm svcs
#define AF_RDS              21       // reliable datagram sockets
#define AF_SNA              22       // linux sna
#define AF_IRDA             23       // irda sockets
#define AF_PPPOX            24       // pppox sockets
#define AF_WANPIPE          25       // wanpipe api sockets
#define AF_LLC              26       // linux llc
#define AF_IB               27       // native infiniband address
#define AF_MPLS             28       // mpls
#define AF_CAN              29       // controller area network
#define AF_TIPC             30       // tipc sockets
#define AF_BLUETOOTH        31       // bluetooth sockets
#define AF_IUCV             32       // iucv sockets
#define AF_RXRPC            33       // rxrpc sockets
#define AF_ISDN             34       // mISDN sockets
#define AF_PHONET           35       // phonet sockets
#define AF_IEEE802154       36       // ieee 802.15.4 sockets
#define AF_CAIF             37       // caif sockets
#define AF_ALG              38       // algorithm sockets (kernel crypto api)
#define AF_NFC              39       // nfc sockets
#define AF_VSOCK            40       // vsock sockets (vm↔host communication)
#define AF_KCM              41       // kernel connection multiplexor
#define AF_QIPCRTR          42       // qualcomm ipc router
#define AF_SMC              43       // smc sockets
#define AF_XDP              44       // xdp sockets (kernel bypass networking)
#define AF_MCTP             45       // management component transport protocol
#define AF_MAX              46

// ─── socket type ─────────────────────────────────────────────
#define SOCK_STREAM         1        // reliable byte stream (tcp)
#define SOCK_DGRAM          2        // unreliable datagrams (udp)
#define SOCK_RAW            3        // raw protocol access
#define SOCK_RDM            4        // reliable datagram (no ordering)
#define SOCK_SEQPACKET      5        // reliable sequenced datagrams
#define SOCK_DCCP           6        // datagram congestion control protocol
#define SOCK_PACKET         10       // linux specific — raw packets at device level
#define SOCK_NONBLOCK       O_NONBLOCK // set O_NONBLOCK on new socket (combine with type)
#define SOCK_CLOEXEC        O_CLOEXEC  // set FD_CLOEXEC on new socket (combine with type)

// ─── socket shutdown how ─────────────────────────────────────
#define SHUT_RD             0        // disallow further reads
#define SHUT_WR             1        // disallow further writes
#define SHUT_RDWR           2        // disallow reads and writes

// ─── socket level (sol_*) for getsockopt/setsockopt ──────────
#define SOL_SOCKET          1        // socket-level options
#define SOL_IP              0        // ip-level options (same as IPPROTO_IP)
#define SOL_TCP             6        // tcp-level options (same as IPPROTO_TCP)
#define SOL_UDP             17       // udp-level options
#define SOL_IPV6            41       // ipv6-level options
#define SOL_ICMPV6          58       // icmpv6-level options
#define SOL_RAW             255      // raw socket options
#define SOL_PACKET          263      // packet socket options
#define SOL_NETLINK         270      // netlink socket options

// ─── SOL_SOCKET options ───────────────────────────────────────
#define SO_DEBUG            1        // enable socket debugging
#define SO_REUSEADDR        2        // allow reuse of local address (avoids TIME_WAIT issues)
#define SO_TYPE             3        // get socket type (read-only)
#define SO_ERROR            4        // get and clear pending socket error (read-only)
#define SO_DONTROUTE        5        // bypass routing table — send only to directly connected hosts
#define SO_BROADCAST        6        // allow sending broadcast datagrams
#define SO_SNDBUF           7        // set send buffer size in bytes
#define SO_RCVBUF           8        // set receive buffer size in bytes
#define SO_SNDBUFFORCE      32       // set send buffer size bypassing cap (root only)
#define SO_RCVBUFFORCE      33       // set recv buffer size bypassing cap (root only)
#define SO_KEEPALIVE        9        // enable tcp keepalive probes
#define SO_OOBINLINE        10       // receive out-of-band data inline
#define SO_NO_CHECK         11       // disable udp checksum (dangerous)
#define SO_PRIORITY         12       // set socket priority (affects queueing discipline)
#define SO_LINGER           13       // block close until data sent or timeout (struct linger)
#define SO_BSDCOMPAT        14       // enable bsd socket compat (deprecated)
#define SO_REUSEPORT        15       // allow multiple sockets on same port (load balancing)
#define SO_PASSCRED         16       // receive SCM_CREDENTIALS on unix sockets
#define SO_PEERCRED         17       // get peer credentials (uid/gid/pid) on unix sockets
#define SO_RCVLOWAT         18       // minimum bytes before recv returns
#define SO_SNDLOWAT         19       // minimum bytes before send returns
#define SO_RCVTIMEO         20       // receive timeout (struct timeval)
#define SO_SNDTIMEO         21       // send timeout (struct timeval)
#define SO_SECURITY_AUTHENTICATION 22
#define SO_SECURITY_ENCRYPTION_TRANSPORT 23
#define SO_SECURITY_ENCRYPTION_NETWORK  24
#define SO_BINDTODEVICE     25       // bind socket to a specific network interface by name
#define SO_ATTACH_FILTER    26       // attach bpf filter (for packet capture etc.)
#define SO_DETACH_FILTER    27       // detach bpf filter
#define SO_GET_FILTER       SO_ATTACH_FILTER
#define SO_PEERNAME         28       // get peer address (unix sockets)
#define SO_TIMESTAMP        29       // receive timestamp with each datagram
#define SO_ACCEPTCONN       30       // is socket in listening state? (read-only)
#define SO_PEERSEC          31       // get peer security context (selinux)
#define SO_PASSSEC          34       // receive selinux security context on unix sockets
#define SO_MARK             36       // set fwmark on all packets from this socket (routing/iptables)
#define SO_TIMESTAMPNS      35       // receive nanosecond timestamp
#define SO_RXQ_OVFL         40       // receive count of dropped packets
#define SO_WIFI_STATUS      41       // receive wifi status for each packet
#define SO_PEEK_OFF         42       // set peek offset for unix sockets
#define SO_NOFCS            43       // disable ethernet fcs (hardware offload testing)
#define SO_LOCK_FILTER      44       // lock attached filter (prevent removal)
#define SO_SELECT_ERR_QUEUE 45       // report errors via select/poll/epoll
#define SO_BUSY_POLL        46       // busy-poll for low-latency networking
#define SO_MAX_PACING_RATE  47       // max bytes/sec pacing rate
#define SO_BPF_EXTENSIONS   48       // query available bpf extensions
#define SO_INCOMING_CPU     49       // get cpu the last packet was received on
#define SO_ATTACH_BPF       50       // attach ebpf program as socket filter
#define SO_DETACH_BPF       SO_DETACH_FILTER
#define SO_ATTACH_REUSEPORT_CBPF 51  // attach cbpf for reuseport socket selection
#define SO_ATTACH_REUSEPORT_EBPF 52  // attach ebpf for reuseport socket selection
#define SO_CNX_ADVICE       53       // transport layer advice about connection quality
#define SO_COOKIE           57       // get socket cookie (unique per-socket id)
#define SO_ZEROCOPY         60       // enable zero-copy send (MSG_ZEROCOPY)
#define SO_TXTIME           61       // schedule packet transmission time (SO_TXTIME)
#define SO_BINDTOIFINDEX    62       // bind to interface by index instead of name
#define SO_RCVTIMEO_NEW     66       // receive timeout (64-bit timespec, y2038-safe)
#define SO_SNDTIMEO_NEW     67       // send timeout (64-bit timespec, y2038-safe)
#define SO_TIMESTAMPNS_NEW  64       // nanosecond timestamp (y2038-safe)
#define SO_TIMESTAMPING_NEW 65       // timestamping (y2038-safe)
#define SO_NETNS_COOKIE     71       // get network namespace cookie (since 5.14)
#define SO_BUF_LOCK         72       // lock send/recv buffer size against reduction

// ─── clone / unshare namespace flags ─────────────────────────
#define CLONE_VM            0x00000100 // share virtual memory with parent
#define CLONE_FS            0x00000200 // share filesystem info (cwd, root, umask)
#define CLONE_FILES         0x00000400 // share open file descriptor table
#define CLONE_SIGHAND       0x00000800 // share signal handlers and blocked signals
#define CLONE_PIDFD         0x00001000 // create pidfd for child (since 5.2)
#define CLONE_PTRACE        0x00002000 // parent is being ptraced; child also traced
#define CLONE_VFORK         0x00004000 // parent blocks until child calls execve or exit
#define CLONE_PARENT        0x00008000 // child has same parent as calling process
#define CLONE_THREAD        0x00010000 // same thread group as parent (for pthreads)
#define CLONE_NEWNS         0x00020000 // create new mount namespace
#define CLONE_SYSVSEM       0x00040000 // share sysv semaphore undo values
#define CLONE_SETTLS        0x00080000 // set tls descriptor (passed via arg)
#define CLONE_PARENT_SETTID 0x00100000 // write child tid to parent's address
#define CLONE_CHILD_CLEARTID 0x00200000 // clear child tid on exit (futex wake)
#define CLONE_DETACHED      0x00400000 // unused (historical)
#define CLONE_UNTRACED      0x00800000 // prevent forcing CLONE_PTRACE on child
#define CLONE_CHILD_SETTID  0x01000000 // write child tid to child's address
#define CLONE_NEWCGROUP     0x02000000 // create new cgroup namespace
#define CLONE_NEWUTS        0x04000000 // create new uts namespace (hostname/domainname)
#define CLONE_NEWIPC        0x08000000 // create new ipc namespace (sysv, mqueues)
#define CLONE_NEWUSER       0x10000000 // create new user namespace (uid/gid mapping)
#define CLONE_NEWPID        0x20000000 // create new pid namespace
#define CLONE_NEWNET        0x40000000 // create new network namespace
#define CLONE_IO            0x80000000 // clone i/o context (ionice/io scheduler class)

// ─── prctl operations (option arg to SYS_prctl) ──────────────
#define PR_SET_PDEATHSIG        1    // set signal sent to this process when parent dies
#define PR_GET_PDEATHSIG        2    // get death signal
#define PR_GET_DUMPABLE         3    // get dumpable flag (coredump enabled?)
#define PR_SET_DUMPABLE         4    // enable/disable coredump and ptrace
#define PR_GET_UNALIGN          5    // get unaligned access control bits
#define PR_SET_UNALIGN          6    // set unaligned access control
#define PR_GET_KEEPCAPS         7    // get keep-capabilities-on-setuid flag
#define PR_SET_KEEPCAPS         8    // keep capabilities when dropping uid to non-root
#define PR_GET_FPEMU            9    // get floating-point emulation control
#define PR_SET_FPEMU            10   // set floating-point emulation control
#define PR_GET_FPEXC            11   // get floating-point exception mode
#define PR_SET_FPEXC            12   // set floating-point exception mode
#define PR_GET_TIMING           13   // get timing mode (statistical or accurate)
#define PR_SET_TIMING           14   // set timing mode
#define PR_SET_NAME             15   // set thread name (max 16 bytes including null)
#define PR_GET_NAME             16   // get thread name into buf[16]
#define PR_GET_ENDIAN           19   // get endianness (powerpc)
#define PR_SET_ENDIAN           20   // set endianness
#define PR_GET_SECCOMP          21   // get seccomp mode (0=off, 1=strict, 2=filter)
#define PR_SET_SECCOMP          22   // set seccomp mode (use seccomp(2) instead)
#define PR_CAPBSET_READ         23   // check if capability is in bounding set
#define PR_CAPBSET_DROP         24   // drop capability from bounding set (permanent)
#define PR_GET_TSC              25   // get tsc access permission (x86)
#define PR_SET_TSC              26   // allow/deny userspace rdtsc (x86)
#define PR_GET_SECUREBITS       27   // get securebit flags (SECBIT_*)
#define PR_SET_SECUREBITS       28   // set securebit flags
#define PR_SET_TIMERSLACK       29   // set timer slack in nanoseconds (affects nanosleep)
#define PR_GET_TIMERSLACK       30   // get timer slack
#define PR_TASK_PERF_EVENTS_DISABLE 31 // disable performance counters for this process
#define PR_TASK_PERF_EVENTS_ENABLE  32 // enable performance counters
#define PR_MCE_KILL             33   // set memory corruption kill policy
#define PR_MCE_KILL_GET         34   // get memory corruption kill policy
#define PR_SET_MM               35   // modify mm fields (mm_struct) — root only
#define PR_SET_CHILD_SUBREAPER  36   // make process a subreaper for orphaned children
#define PR_GET_CHILD_SUBREAPER  37   // get subreaper status
#define PR_SET_NO_NEW_PRIVS     38   // prevent future execve from gaining privileges (irreversible)
#define PR_GET_NO_NEW_PRIVS     39   // get no-new-privs flag
#define PR_GET_TID_ADDRESS      40   // get address set by set_tid_address
#define PR_SET_THP_DISABLE      41   // disable transparent huge pages for this process
#define PR_GET_THP_DISABLE      42   // get thp disable flag
#define PR_MPX_ENABLE_MANAGEMENT  43 // enable mpx bounds management (x86, deprecated)
#define PR_MPX_DISABLE_MANAGEMENT 44 // disable mpx bounds management
#define PR_SET_FP_MODE          45   // set floating-point mode (mips)
#define PR_GET_FP_MODE          46   // get floating-point mode
#define PR_CAP_AMBIENT          47   // manage ambient capability set
#define PR_SET_SPECULATION_CTRL 53   // control speculative execution (spectre/meltdown mitigations)
#define PR_GET_SPECULATION_CTRL 52   // get speculative execution control flags
#define PR_PAC_RESET_KEYS       54   // reset pointer authentication keys (arm64)
#define PR_SET_TAGGED_ADDR_CTRL 55   // enable arm64 tagged address abi
#define PR_GET_TAGGED_ADDR_CTRL 56   // get tagged address abi status
#define PR_SET_IO_FLUSHER       57   // mark as memory reclaim path (avoids deadlock, since 5.6)
#define PR_GET_IO_FLUSHER       58   // get io_flusher status
#define PR_SET_SYSCALL_USER_DISPATCH 59 // configure syscall user dispatch (since 5.11)
#define PR_PAC_SET_ENABLED_KEYS 60   // select which pac keys are enabled (arm64, since 5.13)
#define PR_PAC_GET_ENABLED_KEYS 61
#define PR_SCHED_CORE           62   // manage core scheduling cookies (since 5.14)
#define PR_SME_SET_VL           63   // set sme vector length (arm64 sme, since 5.17)
#define PR_SME_GET_VL           64
#define PR_SVE_SET_VL           50   // set sve vector length (arm64 sve)
#define PR_SVE_GET_VL           51

// ─── ptrace request values ────────────────────────────────────
#define PTRACE_TRACEME          0    // child: declare itself traceable by parent
#define PTRACE_PEEKTEXT         1    // read word from child text segment
#define PTRACE_PEEKDATA         2    // read word from child data segment
#define PTRACE_PEEKUSR          3    // read word from child user area (registers)
#define PTRACE_POKETEXT         4    // write word to child text segment
#define PTRACE_POKEDATA         5    // write word to child data segment
#define PTRACE_POKEUSR          6    // write word to child user area (registers)
#define PTRACE_CONT             7    // restart stopped child; optional signal delivery
#define PTRACE_KILL             8    // send SIGKILL to child (deprecated, use kill(2))
#define PTRACE_SINGLESTEP       9    // restart stopped child; single-step one instruction
#define PTRACE_ATTACH           16   // attach to a running process (sends SIGSTOP)
#define PTRACE_DETACH           17   // detach from child, optionally delivering signal
#define PTRACE_GETREGS          12   // get child general-purpose registers (struct user_regs_struct)
#define PTRACE_SETREGS          13   // set child general-purpose registers
#define PTRACE_GETFPREGS        14   // get child floating-point registers
#define PTRACE_SETFPREGS        15   // set child floating-point registers
#define PTRACE_GETREGSET        0x4204 // get register set by nt_* type (portable)
#define PTRACE_SETREGSET        0x4205 // set register set by nt_* type
#define PTRACE_GETSIGINFO       0x4202 // get siginfo_t for the signal that stopped child
#define PTRACE_SETSIGINFO       0x4203 // set siginfo_t before delivery
#define PTRACE_GETSIGMASK       0x420a // get child signal mask
#define PTRACE_SETSIGMASK       0x420b // set child signal mask
#define PTRACE_SETOPTIONS       0x4200 // set ptrace options (PTRACE_O_*)
#define PTRACE_GETEVENTMSG      0x4201 // get message associated with last event
#define PTRACE_SEIZE            0x4206 // attach without stopping child (use PTRACE_INTERRUPT)
#define PTRACE_INTERRUPT        0x4207 // stop a seized child
#define PTRACE_LISTEN           0x4208 // restart seized child in a listened state
#define PTRACE_PEEKSIGINFO      0x4209 // peek at pending signals in child
#define PTRACE_SECCOMP_GET_FILTER 0x420c // retrieve attached seccomp bpf filter
#define PTRACE_SECCOMP_GET_METADATA 0x420d
#define PTRACE_GET_SYSCALL_INFO 0x420e // get syscall info at stop (since 5.3)

// ptrace event options (PTRACE_SETOPTIONS)
#define PTRACE_O_TRACESYSGOOD   0x00000001 // set bit 7 of signo on syscall-stop
#define PTRACE_O_TRACEFORK      0x00000002 // trace forks (stop before fork returns)
#define PTRACE_O_TRACEVFORK     0x00000004 // trace vforks
#define PTRACE_O_TRACECLONE     0x00000008 // trace clones (threads)
#define PTRACE_O_TRACEEXEC      0x00000010 // stop child on execve
#define PTRACE_O_TRACEVFORKDONE 0x00000020 // stop after vfork child calls exec or exits
#define PTRACE_O_TRACEEXIT      0x00000040 // stop child before it exits
#define PTRACE_O_TRACESECCOMP   0x00000080 // stop on seccomp filter match
#define PTRACE_O_EXITKILL       0x00100000 // send SIGKILL to child if tracer exits
#define PTRACE_O_SUSPEND_SECCOMP 0x00200000 // suspend child seccomp filter

// ptrace events (returned via WSTOPSIG after PTRACE_GETEVENTMSG)
#define PTRACE_EVENT_FORK       1
#define PTRACE_EVENT_VFORK      2
#define PTRACE_EVENT_CLONE      3
#define PTRACE_EVENT_EXEC       4
#define PTRACE_EVENT_VFORK_DONE 5
#define PTRACE_EVENT_EXIT       6
#define PTRACE_EVENT_SECCOMP    7
#define PTRACE_EVENT_STOP       128

// ─── wait / waitid options ────────────────────────────────────
#define WNOHANG             1        // return immediately if no child has changed state
#define WUNTRACED           2        // also report stopped children (not just terminated)
#define WSTOPPED            2        // alias for WUNTRACED
#define WCONTINUED          8        // also report children resumed by SIGCONT
#define WNOWAIT             0x01000000 // leave child in waitable state (peek, not consume)
#define WEXITED             4        // wait for terminated children (waitid)
#define WALL                0x40000000 // wait for any child regardless of type
#define WCLONE              0x80000000 // wait only for clone children (no SIGCHLD parent)

// wait status macros
#define WIFEXITED(s)        (((s) & 0x7f) == 0)           // child exited normally
#define WEXITSTATUS(s)      (((s) >> 8) & 0xff)           // exit code if WIFEXITED
#define WIFSIGNALED(s)      (((s) & 0x7f) != 0 && ((s) & 0x7f) != 0x7f) // killed by signal
#define WTERMSIG(s)         ((s) & 0x7f)                  // signal that killed child
#define WCOREDUMP(s)        ((s) & 0x80)                  // core was dumped
#define WIFSTOPPED(s)       (((s) & 0xff) == 0x7f)        // child is stopped
#define WSTOPSIG(s)         (((s) >> 8) & 0xff)           // signal that stopped child
#define WIFCONTINUED(s)     ((s) == 0xffff)               // child was resumed by SIGCONT

// ─── resource ids (resource arg to getrlimit/setrlimit/prlimit64) ──
#define RLIMIT_CPU          0        // max cpu time in seconds (SIGXCPU then SIGKILL)
#define RLIMIT_FSIZE        1        // max file size in bytes (SIGXFSZ on exceed)
#define RLIMIT_DATA         2        // max data segment size in bytes
#define RLIMIT_STACK        3        // max stack size in bytes
#define RLIMIT_CORE         4        // max core dump size in bytes (0 = no core)
#define RLIMIT_RSS          5        // max resident set size in bytes (not enforced on linux)
#define RLIMIT_NPROC        6        // max number of processes/threads (per uid)
#define RLIMIT_NOFILE       7        // max number of open file descriptors
#define RLIMIT_MEMLOCK      8        // max locked-in-memory bytes (mlock)
#define RLIMIT_AS           9        // max virtual address space size in bytes
#define RLIMIT_LOCKS        10       // max number of file locks
#define RLIMIT_SIGPENDING   11       // max number of queued signals (per uid)
#define RLIMIT_MSGQUEUE     12       // max bytes for posix message queues (per uid)
#define RLIMIT_NICE         13       // ceiling for nice value (20 - rlim = min nice)
#define RLIMIT_RTPRIO       14       // ceiling for real-time priority
#define RLIMIT_RTTIME       15       // max real-time cpu time in microseconds
#define RLIM_INFINITY       (~0UL)   // no limit

// ─── clock ids (clkid arg to clock_gettime etc.) ─────────────
#define CLOCK_REALTIME              0  // wall clock time (can jump on ntp/settimeofday)
#define CLOCK_MONOTONIC             1  // monotonic since boot (no jumps, affected by adjtime)
#define CLOCK_PROCESS_CPUTIME_ID    2  // cpu time consumed by calling process
#define CLOCK_THREAD_CPUTIME_ID     3  // cpu time consumed by calling thread
#define CLOCK_MONOTONIC_RAW         4  // monotonic, not affected by ntp or adjtime (since 2.6.28)
#define CLOCK_REALTIME_COARSE       5  // fast low-resolution realtime (jiffy granularity)
#define CLOCK_MONOTONIC_COARSE      6  // fast low-resolution monotonic
#define CLOCK_BOOTTIME              7  // monotonic + time suspended (includes sleep/hibernate)
#define CLOCK_REALTIME_ALARM        8  // like CLOCK_REALTIME but wakes system from suspend
#define CLOCK_BOOTTIME_ALARM        9  // like CLOCK_BOOTTIME but wakes system from suspend
#define CLOCK_TAI                   11 // international atomic time (no leap seconds)

// ─── syslog action types (type arg to SYS_syslog) ────────────
#define SYSLOG_ACTION_CLOSE         0  // close the log (no-op on linux)
#define SYSLOG_ACTION_OPEN          1  // open the log (no-op on linux)
#define SYSLOG_ACTION_READ          2  // read from log (blocks until data available)
#define SYSLOG_ACTION_READ_ALL      3  // read all messages in ring buffer
#define SYSLOG_ACTION_READ_CLEAR    4  // read all messages and clear buffer
#define SYSLOG_ACTION_CLEAR         5  // clear ring buffer
#define SYSLOG_ACTION_CONSOLE_OFF   6  // disable printing to console
#define SYSLOG_ACTION_CONSOLE_ON    7  // enable printing to console
#define SYSLOG_ACTION_CONSOLE_LEVEL 8  // set console log level (arg: 1..8)
#define SYSLOG_ACTION_SIZE_UNREAD   9  // return number of unread bytes in ring buffer
#define SYSLOG_ACTION_SIZE_BUFFER   10 // return size of ring buffer

// ─── reboot magic values and commands ────────────────────────
#define LINUX_REBOOT_MAGIC1         0xfee1dead  // first magic (always required)
#define LINUX_REBOOT_MAGIC2         672274793   // second magic (one of four valid values)
#define LINUX_REBOOT_MAGIC2A        85072278
#define LINUX_REBOOT_MAGIC2B        369367448
#define LINUX_REBOOT_MAGIC2C        537993216
#define LINUX_REBOOT_CMD_RESTART    0x01234567  // restart system
#define LINUX_REBOOT_CMD_HALT       0xcdef0123  // stop os, halt (no power off)
#define LINUX_REBOOT_CMD_CAD_ON     0x89abcdef  // ctrl+alt+del triggers reboot
#define LINUX_REBOOT_CMD_CAD_OFF    0x00000000  // ctrl+alt+del sends SIGINT to init
#define LINUX_REBOOT_CMD_POWER_OFF  0x4321fedc  // stop os and power off
#define LINUX_REBOOT_CMD_RESTART2   0xa1b2c3d4  // restart with arg (e.g. bootloader command)
#define LINUX_REBOOT_CMD_SW_SUSPEND 0xd000fce2  // hibernate to disk
#define LINUX_REBOOT_CMD_KEXEC      0x45584543  // kexec to loaded kernel

// ─── timerfd flags (SYS_timerfd_settime — flags arg) ─────────
#define TFD_TIMER_ABSTIME           (1 << 0)  // use absolute time instead of relative
#define TFD_TIMER_CANCEL_ON_SET     (1 << 1)  // cancel on clock discontinuity (realtime jump)
#define TFD_CLOEXEC                 O_CLOEXEC // set close-on-exec on the timerfd
#define TFD_NONBLOCK                O_NONBLOCK // set non-blocking on the timerfd

// ─── eventfd flags (SYS_eventfd2 — flags arg) ────────────────
#define EFD_SEMAPHORE               (1 << 0)  // semaphore mode: each read decrements by 1
#define EFD_CLOEXEC                 O_CLOEXEC
#define EFD_NONBLOCK                O_NONBLOCK

// ─── signalfd flags (SYS_signalfd4 — flags arg) ──────────────
#define SFD_CLOEXEC                 O_CLOEXEC
#define SFD_NONBLOCK                O_NONBLOCK

// ─── inotify flags ───────────────────────────────────────────
// inotify_init1 flags
#define IN_CLOEXEC                  O_CLOEXEC
#define IN_NONBLOCK                 O_NONBLOCK

// inotify_add_watch mask events
#define IN_ACCESS               0x00000001  // file was accessed (read)
#define IN_MODIFY               0x00000002  // file was modified (write)
#define IN_ATTRIB               0x00000004  // metadata changed (chmod, chown, link count, etc.)
#define IN_CLOSE_WRITE          0x00000008  // writable file closed
#define IN_CLOSE_NOWRITE        0x00000010  // non-writable file closed
#define IN_CLOSE                (IN_CLOSE_WRITE | IN_CLOSE_NOWRITE)
#define IN_OPEN                 0x00000020  // file opened
#define IN_MOVED_FROM           0x00000040  // file moved out of watched directory
#define IN_MOVED_TO             0x00000080  // file moved into watched directory
#define IN_MOVE                 (IN_MOVED_FROM | IN_MOVED_TO)
#define IN_CREATE               0x00000100  // file/dir created in watched directory
#define IN_DELETE               0x00000200  // file/dir deleted from watched directory
#define IN_DELETE_SELF          0x00000400  // watched file/dir itself deleted
#define IN_MOVE_SELF            0x00000800  // watched file/dir itself moved
#define IN_ALL_EVENTS           0x00000fff  // all of the above events
// inotify_add_watch control flags
#define IN_UNMOUNT              0x00002000  // filesystem containing watched object was unmounted
#define IN_Q_OVERFLOW           0x00004000  // event queue overflowed
#define IN_IGNORED              0x00008000  // watch was removed (auto or explicit)
#define IN_ONLYDIR              0x01000000  // only watch if path is a directory
#define IN_DONT_FOLLOW          0x02000000  // do not follow symlinks
#define IN_EXCL_UNLINK          0x04000000  // exclude events for unlinked files
#define IN_MASK_CREATE          0x10000000  // fail if watch already exists
#define IN_MASK_ADD             0x20000000  // add events to existing watch instead of replacing
#define IN_ISDIR                0x40000000  // event occurred on a directory
#define IN_ONESHOT              0x80000000  // remove watch after one event

// ─── getrandom flags ──────────────────────────────────────────
#define GRND_NONBLOCK           0x0001  // fail with EAGAIN if entropy not available
#define GRND_RANDOM             0x0002  // draw from /dev/random pool (may block longer)
#define GRND_INSECURE           0x0004  // return best-effort random even if not fully seeded (since 5.6)

// ─── memfd_create flags ───────────────────────────────────────
#define MFD_CLOEXEC             0x0001  // set close-on-exec
#define MFD_ALLOW_SEALING       0x0002  // allow F_ADD_SEALS operations
#define MFD_HUGETLB             0x0004  // use huge pages (since 4.14)
#define MFD_NOEXEC_SEAL         0x0008  // seal as non-executable and add F_SEAL_EXEC (since 6.3)
#define MFD_EXEC                0x0010  // explicitly allow executable mapping (since 6.3)

// ─── pidfd flags (pidfd_open / pidfd_send_signal) ────────────
#define PIDFD_NONBLOCK          O_NONBLOCK // create non-blocking pidfd (since 5.10)

// ─── io_uring setup flags (struct io_uring_params — flags) ───
#define IORING_SETUP_IOPOLL     (1u << 0)  // use busy-polling for i/o (no irq, lower latency)
#define IORING_SETUP_SQPOLL     (1u << 1)  // kernel thread polls sq (no syscall for submit)
#define IORING_SETUP_SQ_AFF     (1u << 2)  // bind sqpoll thread to sq_thread_cpu
#define IORING_SETUP_CQSIZE     (1u << 3)  // use cq_entries as cq ring size
#define IORING_SETUP_CLAMP      (1u << 4)  // clamp sq/cq sizes to max instead of error
#define IORING_SETUP_ATTACH_WQ  (1u << 5)  // share worker pool with another ring
#define IORING_SETUP_R_DISABLED (1u << 6)  // start ring disabled (enable with IORING_REGISTER_ENABLE_RINGS)
#define IORING_SETUP_SUBMIT_ALL (1u << 7)  // continue submitting even if one sqe fails (since 5.18)
#define IORING_SETUP_COOP_TASKRUN (1u << 8) // defer task_work to io_uring_enter (since 5.19)
#define IORING_SETUP_TASKRUN_FLAG (1u << 9) // signal when task_work is pending
#define IORING_SETUP_SQE128     (1u << 10) // use 128-byte sqes
#define IORING_SETUP_CQE32      (1u << 11) // use 32-byte cqes
#define IORING_SETUP_SINGLE_ISSUER (1u << 12) // only one thread submits sqes (since 6.0)
#define IORING_SETUP_DEFER_TASKRUN (1u << 13) // defer all taskwork to io_uring_enter (since 6.1)

// ─── seccomp modes and flags ──────────────────────────────────
#define SECCOMP_MODE_DISABLED   0    // seccomp not active
#define SECCOMP_MODE_STRICT     1    // only allow read, write, exit, sigreturn
#define SECCOMP_MODE_FILTER     2    // use bpf filter (prctl PR_SET_SECCOMP or seccomp(2))

#define SECCOMP_SET_MODE_STRICT 0    // seccomp(op): set strict mode
#define SECCOMP_SET_MODE_FILTER 1    // seccomp(op): install bpf filter
#define SECCOMP_GET_ACTION_AVAIL 2   // seccomp(op): check if action is supported
#define SECCOMP_GET_NOTIF_SIZES  3   // seccomp(op): get notification struct sizes

#define SECCOMP_FILTER_FLAG_TSYNC       (1u << 0) // sync filter to all threads
#define SECCOMP_FILTER_FLAG_LOG         (1u << 1) // log allowed syscalls
#define SECCOMP_FILTER_FLAG_SPEC_ALLOW  (1u << 2) // disable spectre mitigations for filter
#define SECCOMP_FILTER_FLAG_NEW_LISTENER (1u << 3) // return listener fd for user notification
#define SECCOMP_FILTER_FLAG_TSYNC_ESRCH (1u << 4) // return ESRCH if tsync finds incompatible thread

// seccomp bpf return actions
#define SECCOMP_RET_KILL_PROCESS 0x80000000u // kill whole process (coredump)
#define SECCOMP_RET_KILL_THREAD  0x00000000u // kill only the calling thread
#define SECCOMP_RET_KILL         SECCOMP_RET_KILL_THREAD // alias
#define SECCOMP_RET_TRAP         0x00030000u // send SIGSYS to thread
#define SECCOMP_RET_ERRNO        0x00050000u // return error (low 16 bits = errno)
#define SECCOMP_RET_USER_NOTIF   0x7fc00000u // notify userspace supervisor (since 5.0)
#define SECCOMP_RET_TRACE        0x7ff00000u // notify ptrace tracer
#define SECCOMP_RET_LOG          0x7ffc0000u // log and allow
#define SECCOMP_RET_ALLOW        0x7fff0000u // allow the syscall

// ─── bpf commands (cmd arg to SYS_bpf) ───────────────────────
#define BPF_MAP_CREATE          0    // create a bpf map
#define BPF_MAP_LOOKUP_ELEM     1    // look up element in map
#define BPF_MAP_UPDATE_ELEM     2    // create or update element in map
#define BPF_MAP_DELETE_ELEM     3    // delete element from map
#define BPF_MAP_GET_NEXT_KEY    4    // iterate map keys
#define BPF_PROG_LOAD           5    // load bpf program
#define BPF_OBJ_PIN             6    // pin bpf object to filesystem
#define BPF_OBJ_GET             7    // get pinned bpf object
#define BPF_PROG_ATTACH         8    // attach bpf program to hook
#define BPF_PROG_DETACH         9    // detach bpf program
#define BPF_PROG_TEST_RUN       10   // run bpf program for testing
#define BPF_PROG_RUN            BPF_PROG_TEST_RUN
#define BPF_PROG_GET_NEXT_ID    11   // iterate loaded programs
#define BPF_MAP_GET_NEXT_ID     12
#define BPF_PROG_GET_FD_BY_ID   13   // get fd for program by id
#define BPF_MAP_GET_FD_BY_ID    14
#define BPF_OBJ_GET_INFO_BY_FD  15   // get info about program/map/etc.
#define BPF_PROG_QUERY          16   // query programs attached to hook
#define BPF_RAW_TRACEPOINT_OPEN 17   // open raw tracepoint
#define BPF_BTF_LOAD            18   // load btf type info
#define BPF_BTF_GET_FD_BY_ID    19
#define BPF_TASK_FD_QUERY       20   // query fd info for task
#define BPF_MAP_LOOKUP_AND_DELETE_ELEM 21
#define BPF_MAP_FREEZE          22   // make map read-only from userspace
#define BPF_BTF_GET_NEXT_ID     23
#define BPF_MAP_LOOKUP_BATCH    24   // batch map lookup
#define BPF_MAP_UPDATE_BATCH    25   // batch map update
#define BPF_MAP_DELETE_BATCH    26   // batch map delete
#define BPF_LINK_CREATE         28   // create bpf link
#define BPF_LINK_UPDATE         29   // update bpf link
#define BPF_LINK_GET_FD_BY_ID   30
#define BPF_LINK_GET_NEXT_ID    31
#define BPF_ENABLE_STATS        32   // enable bpf statistics
#define BPF_ITER_CREATE         33   // create bpf iterator
#define BPF_LINK_DETACH         34
#define BPF_PROG_BIND_MAP       35   // bind map lifetime to program

// ─── bpf program types ────────────────────────────────────────
#define BPF_PROG_TYPE_UNSPEC            0
#define BPF_PROG_TYPE_SOCKET_FILTER     1   // classic socket filter (e.g. tcpdump)
#define BPF_PROG_TYPE_KPROBE            2   // kprobe/kretprobe
#define BPF_PROG_TYPE_SCHED_CLS         3   // tc classifier
#define BPF_PROG_TYPE_SCHED_ACT         4   // tc action
#define BPF_PROG_TYPE_TRACEPOINT        5   // static tracepoint
#define BPF_PROG_TYPE_XDP               6   // xdp — express data path (driver-level hook)
#define BPF_PROG_TYPE_PERF_EVENT        7   // perf event
#define BPF_PROG_TYPE_CGROUP_SKB        8   // cgroup socket buffer
#define BPF_PROG_TYPE_CGROUP_SOCK       9   // cgroup socket
#define BPF_PROG_TYPE_LWT_IN            10  // lightweight tunnel input
#define BPF_PROG_TYPE_LWT_OUT           11
#define BPF_PROG_TYPE_LWT_XMIT         12
#define BPF_PROG_TYPE_SOCK_OPS          13  // socket operations
#define BPF_PROG_TYPE_SK_SKB            14  // sockmap skb programs
#define BPF_PROG_TYPE_CGROUP_DEVICE     15  // cgroup device access control
#define BPF_PROG_TYPE_SK_MSG            16  // sockmap message programs
#define BPF_PROG_TYPE_RAW_TRACEPOINT    17  // raw tracepoint
#define BPF_PROG_TYPE_CGROUP_SOCK_ADDR  18  // cgroup socket address manipulation
#define BPF_PROG_TYPE_LWT_SEG6LOCAL     19
#define BPF_PROG_TYPE_LIRC_MODE2        20  // lirc (infrared)
#define BPF_PROG_TYPE_SK_REUSEPORT     21   // reuseport socket selection
#define BPF_PROG_TYPE_FLOW_DISSECTOR   22   // custom flow dissector
#define BPF_PROG_TYPE_CGROUP_SYSCTL    23   // cgroup sysctl access control
#define BPF_PROG_TYPE_RAW_TRACEPOINT_WRITABLE 24
#define BPF_PROG_TYPE_CGROUP_SOCKOPT   25   // cgroup setsockopt/getsockopt
#define BPF_PROG_TYPE_TRACING          26   // fentry/fexit/fmod_ret/tp_btf
#define BPF_PROG_TYPE_STRUCT_OPS       27   // replace kernel struct function pointers
#define BPF_PROG_TYPE_EXT              28   // bpf extension (wraps another program)
#define BPF_PROG_TYPE_LSM              29   // linux security module hooks
#define BPF_PROG_TYPE_SK_LOOKUP        30   // custom socket lookup
#define BPF_PROG_TYPE_SYSCALL          31   // privileged syscall program

// ─── bpf map types ────────────────────────────────────────────
#define BPF_MAP_TYPE_UNSPEC             0
#define BPF_MAP_TYPE_HASH               1   // hash table
#define BPF_MAP_TYPE_ARRAY              2   // fixed-size array (key = index)
#define BPF_MAP_TYPE_PROG_ARRAY         3   // array of bpf program fds (tail calls)
#define BPF_MAP_TYPE_PERF_EVENT_ARRAY   4   // array of perf event fds
#define BPF_MAP_TYPE_PERCPU_HASH        5   // per-cpu hash
#define BPF_MAP_TYPE_PERCPU_ARRAY       6   // per-cpu array
#define BPF_MAP_TYPE_STACK_TRACE        7   // store stack traces
#define BPF_MAP_TYPE_CGROUP_ARRAY       8   // array of cgroup fds
#define BPF_MAP_TYPE_LRU_HASH           9   // hash with lru eviction
#define BPF_MAP_TYPE_LRU_PERCPU_HASH    10
#define BPF_MAP_TYPE_LPM_TRIE           11  // longest prefix match trie (ip routing)
#define BPF_MAP_TYPE_ARRAY_OF_MAPS      12  // array of inner maps
#define BPF_MAP_TYPE_HASH_OF_MAPS       13  // hash of inner maps
#define BPF_MAP_TYPE_DEVMAP             14  // redirect to network device
#define BPF_MAP_TYPE_SOCKMAP            15  // sockmap (redirect between sockets)
#define BPF_MAP_TYPE_CPUMAP             16  // redirect to cpu for xdp
#define BPF_MAP_TYPE_XSKMAP             17  // af_xdp socket map
#define BPF_MAP_TYPE_SOCKHASH           18  // sockhash (hash-based sockmap)
#define BPF_MAP_TYPE_CGROUP_STORAGE     19  // per-cgroup storage
#define BPF_MAP_TYPE_REUSEPORT_SOCKARRAY 20
#define BPF_MAP_TYPE_PERCPU_CGROUP_STORAGE 21
#define BPF_MAP_TYPE_QUEUE              22  // fifo queue
#define BPF_MAP_TYPE_STACK              23  // lifo stack
#define BPF_MAP_TYPE_SK_STORAGE         24  // per-socket storage
#define BPF_MAP_TYPE_DEVMAP_HASH        25  // hash-based devmap
#define BPF_MAP_TYPE_STRUCT_OPS         26
#define BPF_MAP_TYPE_RINGBUF            27  // single-producer ring buffer (since 5.8)
#define BPF_MAP_TYPE_INODE_STORAGE      28  // per-inode storage
#define BPF_MAP_TYPE_TASK_STORAGE       29  // per-task storage
#define BPF_MAP_TYPE_BLOOM_FILTER       30  // probabilistic membership test (since 5.16)
