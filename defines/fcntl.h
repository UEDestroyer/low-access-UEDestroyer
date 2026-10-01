#pragma once

// ============================================================
//  file flags and access constants — linux (all architectures)
//  used with:  open(2), openat(2), openat2(2)
//  source:     linux/include/uapi/asm-generic/fcntl.h
//              linux/arch/*/include/uapi/asm/fcntl.h
//
//  note: most flags are architecture-independent (asm-generic).
//        arch-specific values are marked and grouped below.
//        always use the SYS_openat syscall on arm64 (no SYS_open).
// ============================================================

// ─── access mode (mutually exclusive, mask with O_ACCMODE) ───
//  passed as the low 2 bits of flags
#define O_ACCMODE           0x0003  // mask to extract access mode from flags
#define O_RDONLY            0x0000  // open for reading only
#define O_WRONLY            0x0001  // open for writing only
#define O_RDWR              0x0002  // open for reading and writing

// ─── file creation flags ─────────────────────────────────────
//  control what happens when the file does/doesn't exist
#define O_CREAT             0x0040  // create file if it does not exist (requires mode arg)
#define O_EXCL              0x0080  // error if O_CREAT and file already exists (atomic check+create)
#define O_NOCTTY            0x0100  // do not assign controlling terminal if path is a tty
#define O_TRUNC             0x0200  // truncate file to zero length on open (requires write access)

// ─── file status flags ───────────────────────────────────────
//  affect subsequent i/o operations on the fd
#define O_APPEND            0x0400  // writes always append to end of file (atomic, avoids races)
#define O_NONBLOCK          0x0800  // non-blocking i/o; operations return EAGAIN instead of blocking
#define O_NDELAY            O_NONBLOCK // alias for O_NONBLOCK
#define O_DSYNC             0x1000  // write waits until data is physically written (no metadata)
#define O_ASYNC             0x2000  // enable signal-driven i/o (SIGIO on data ready)
#define O_DIRECT            0x4000  // bypass page cache — i/o goes directly to/from userspace buffer
#define O_LARGEFILE         0x8000  // allow opening files > 2GB on 32-bit (implicit on 64-bit)
#define O_DIRECTORY         0x10000 // fail if path is not a directory (used by opendir internals)
#define O_NOFOLLOW          0x20000 // fail if the final path component is a symlink
#define O_NOATIME           0x40000 // do not update atime on read (requires ownership or CAP_FOWNER)
#define O_CLOEXEC           0x80000 // set close-on-exec flag; fd closed automatically on execve
#define O_SYNC              (0x101000) // write waits until data AND metadata are physically written
#define O_FSYNC             O_SYNC  // alias for O_SYNC
#define O_PATH              0x200000 // open fd for path operations only (no read/write); see below
#define O_TMPFILE           (0x400000 | O_DIRECTORY) // create unnamed temp file (unlinked, no name in fs)

// ─── O_PATH details ──────────────────────────────────────────
//  O_PATH fd can be used with:
//    fstat, fchdir, dup, close, linkat (AT_EMPTY_PATH), openat, readlinkat
//  cannot be used with: read, write, fchmod, fchown, fgetxattr, mmap
//  useful for: safely traversing directories, passing fds across execve

// ─── O_TMPFILE details ───────────────────────────────────────
//  creates an unlinked regular file in the given directory.
//  to give it a name later: linkat(fd, "", dirfd, "name", AT_EMPTY_PATH)
//  requires kernel 3.11+ and filesystem support (ext4, xfs, tmpfs, etc.)

// ─── at-flags (used with openat, fstatat, unlinkat, etc.) ────
#define AT_FDCWD            (-100)  // use cwd as dirfd (magic value, not a real fd)
#define AT_SYMLINK_NOFOLLOW 0x100   // do not follow symlink in the last path component
#define AT_REMOVEDIR        0x200   // remove directory instead of file (used by unlinkat)
#define AT_SYMLINK_FOLLOW   0x400   // follow symlinks (used by linkat)
#define AT_NO_AUTOMOUNT     0x800   // do not trigger automount on the last component
#define AT_EMPTY_PATH       0x1000  // operate on fd itself if path is empty string (requires O_PATH or root)
#define AT_STATX_SYNC_TYPE  0x6000  // mask for statx sync flags
#define AT_STATX_SYNC_AS_STAT 0x0000 // sync behaviour matches stat
#define AT_STATX_FORCE_SYNC 0x2000  // force attributes to be synced with server (nfs etc.)
#define AT_STATX_DONT_SYNC  0x4000  // use cached attributes without syncing
#define AT_RECURSIVE        0x8000  // apply operation recursively (used by fanotify_mark)
#define AT_EACCESS          0x200   // use effective uid/gid for access check (faccessat)

// ─── seek whence values (used with lseek / _llseek) ──────────
#define SEEK_SET            0       // seek to absolute offset from start of file
#define SEEK_CUR            1       // seek relative to current file position
#define SEEK_END            2       // seek relative to end of file (can be negative)
#define SEEK_DATA           3       // seek to next data region (skips holes in sparse files)
#define SEEK_HOLE           4       // seek to next hole (or EOF if no holes) in sparse file

// ─── fcntl commands (cmd arg to fcntl syscall) ───────────────
#define F_DUPFD             0       // duplicate fd to lowest available >= arg
#define F_GETFD             1       // get fd flags (only FD_CLOEXEC currently)
#define F_SETFD             2       // set fd flags
#define F_GETFL             3       // get file status flags (O_RDONLY, O_NONBLOCK, etc.)
#define F_SETFL             4       // set file status flags (only O_APPEND, O_ASYNC, O_DIRECT, O_NOATIME, O_NONBLOCK)
#define F_GETLK             5       // get first lock that would block the given flock struct
#define F_SETLK             6       // set or clear file lock (non-blocking; returns EAGAIN if conflict)
#define F_SETLKW            7       // set or clear file lock (blocking; waits until lock acquired)
#define F_SETOWN            8       // set pid or pgid to receive SIGIO/SIGURG for async i/o
#define F_GETOWN            9       // get pid or pgid set by F_SETOWN
#define F_SETSIG            10      // set signal sent for async i/o (default: SIGIO)
#define F_GETSIG            11      // get signal set by F_SETSIG
#define F_GETLK64           12      // same as F_GETLK but uses flock64 struct
#define F_SETLK64           13      // same as F_SETLK but uses flock64
#define F_SETLKW64          14      // same as F_SETLKW but uses flock64
#define F_SETOWN_EX         15      // extended F_SETOWN: set target type (pid/pgid/tid)
#define F_GETOWN_EX         16      // extended F_GETOWN
#define F_GETOWNER_UIDS     17      // get uids of sown owner
#define F_OFD_GETLK         36      // get open-file-description lock (shared across dup/fork)
#define F_OFD_SETLK         37      // set open-file-description lock (non-blocking)
#define F_OFD_SETLKW        38      // set open-file-description lock (blocking)
#define F_DUPFD_CLOEXEC     1030    // like F_DUPFD but sets FD_CLOEXEC atomically
#define F_SETPIPE_SZ        1031    // set pipe capacity in bytes (see /proc/sys/fs/pipe-max-size)
#define F_GETPIPE_SZ        1032    // get current pipe capacity in bytes
#define F_ADD_SEALS         1033    // add seals to memfd (prevents size change/write/seal)
#define F_GET_SEALS         1034    // get current seals on a memfd
#define F_GET_RW_HINT       1035    // get i/o lifetime hint on file
#define F_SET_RW_HINT       1036    // set i/o lifetime hint (hint to storage layer, not guaranteed)
#define F_GET_FILE_RW_HINT  1037    // get per-file rw hint
#define F_SET_FILE_RW_HINT  1038    // set per-file rw hint

// ─── fd flags (used with F_GETFD / F_SETFD) ──────────────────
#define FD_CLOEXEC          1       // close fd automatically on execve; avoids fd leaks into child

// ─── flock lock type (l_type field in struct flock) ──────────
#define F_RDLCK             0       // shared (read) lock — multiple readers allowed
#define F_WRLCK             1       // exclusive (write) lock — blocks all other locks
#define F_UNLCK             2       // unlock (release lock)

// ─── memfd seals (used with F_ADD_SEALS / F_GET_SEALS) ───────
#define F_SEAL_SEAL         0x0001  // prevent adding further seals
#define F_SEAL_SHRINK       0x0002  // prevent reducing file size (ftruncate to smaller)
#define F_SEAL_GROW         0x0004  // prevent increasing file size (write beyond end, ftruncate to larger)
#define F_SEAL_WRITE        0x0008  // prevent any writes (all write/pwrite/mmap-write fail)
#define F_SEAL_FUTURE_WRITE 0x0010  // prevent future writable mmap; existing ones still work  since 5.1

// ─── file permission bits (mode arg to open/creat/chmod) ─────
#define S_ISUID             04000   // set-user-id on execution
#define S_ISGID             02000   // set-group-id on execution
#define S_ISVTX             01000   // sticky bit (directory: only owner can delete entry)

#define S_IRWXU             00700   // owner: read + write + execute
#define S_IRUSR             00400   // owner: read
#define S_IWUSR             00200   // owner: write
#define S_IXUSR             00100   // owner: execute (or search for directory)

#define S_IRWXG             00070   // group: read + write + execute
#define S_IRGRP             00040   // group: read
#define S_IWGRP             00020   // group: write
#define S_IXGRP             00010   // group: execute

#define S_IRWXO             00007   // others: read + write + execute
#define S_IROTH             00004   // others: read
#define S_IWOTH             00002   // others: write
#define S_IXOTH             00001   // others: execute

// common permission combos
#define S_IRUGO             (S_IRUSR | S_IRGRP | S_IROTH)  // 0444 — readable by all
#define S_IWUGO             (S_IWUSR | S_IWGRP | S_IWOTH)  // 0222 — writable by all
#define S_IXUGO             (S_IXUSR | S_IXGRP | S_IXOTH)  // 0111 — executable by all

// ─── file type test macros (for stat.st_mode) ────────────────
#define S_IFMT              0xF000  // bitmask for file type field
#define S_IFSOCK            0xC000  // socket
#define S_IFLNK             0xA000  // symbolic link
#define S_IFREG             0x8000  // regular file
#define S_IFBLK             0x6000  // block device
#define S_IFDIR             0x4000  // directory
#define S_IFCHR             0x2000  // character device
#define S_IFIFO             0x1000  // fifo / named pipe

#define S_ISSOCK(m)         (((m) & S_IFMT) == S_IFSOCK)
#define S_ISLNK(m)          (((m) & S_IFMT) == S_IFLNK)
#define S_ISREG(m)          (((m) & S_IFMT) == S_IFREG)
#define S_ISBLK(m)          (((m) & S_IFMT) == S_IFBLK)
#define S_ISDIR(m)          (((m) & S_IFMT) == S_IFDIR)
#define S_ISCHR(m)          (((m) & S_IFMT) == S_IFCHR)
#define S_ISFIFO(m)         (((m) & S_IFMT) == S_IFIFO)

// ─── fadvise hints (posix_fadvise / SYS_fadvise64) ───────────
#define POSIX_FADV_NORMAL       0   // no special access pattern (default)
#define POSIX_FADV_RANDOM       1   // expect random access — disable readahead
#define POSIX_FADV_SEQUENTIAL   2   // expect sequential access — aggressive readahead
#define POSIX_FADV_WILLNEED     3   // expect access soon — prefetch pages into cache
#define POSIX_FADV_DONTNEED     4   // will not access soon — kernel may drop cached pages
#define POSIX_FADV_NOREUSE      5   // access once and discard — bypass cache after use

// ─── madvise hints (SYS_madvise) ─────────────────────────────
#define MADV_NORMAL             0   // no special treatment (default)
#define MADV_RANDOM             1   // expect random access — disable readahead
#define MADV_SEQUENTIAL         2   // expect sequential access — aggressive readahead
#define MADV_WILLNEED           3   // prefetch this range into memory
#define MADV_DONTNEED           4   // release pages; next access causes page fault
#define MADV_FREE               8   // pages can be reclaimed lazily (contents undefined after reclaim)  since 4.5
#define MADV_REMOVE             9   // remove mapping and backing store (for tmpfs/shmfs)
#define MADV_DONTFORK           10  // do not copy this range into child on fork
#define MADV_DOFORK             11  // undo MADV_DONTFORK
#define MADV_MERGEABLE          12  // enable KSM page merging for this range
#define MADV_UNMERGEABLE        13  // disable KSM merging and split any merged pages
#define MADV_HUGEPAGE           14  // enable transparent huge pages for this range
#define MADV_NOHUGEPAGE         15  // disable transparent huge pages
#define MADV_DONTDUMP           16  // exclude range from core dump
#define MADV_DODUMP             17  // undo MADV_DONTDUMP
#define MADV_HWPOISON           100 // simulate hardware memory corruption (testing, root only)
#define MADV_SOFT_OFFLINE       101 // soft-offline a page for memory error recovery (root)
#define MADV_WIPEONFORK         18  // zero this range in child on fork (for secret data)  since 4.14
#define MADV_KEEPONFORK         19  // undo MADV_WIPEONFORK
#define MADV_COLD               20  // deactivate pages — move to inactive list  since 5.4
#define MADV_PAGEOUT            21  // reclaim pages immediately (write dirty, drop clean)  since 5.4
#define MADV_POPULATE_READ      22  // prefault pages for read (no cow breaking)  since 5.14
#define MADV_POPULATE_WRITE     23  // prefault pages for write (triggers cow)  since 5.14
#define MADV_DONTNEED_LOCKED    24  // MADV_DONTNEED that works on mlocked pages  since 5.18

// ─── mmap protection flags (prot arg to mmap/mprotect) ───────
#define PROT_NONE               0x0  // pages cannot be accessed (used for guard pages)
#define PROT_READ               0x1  // pages can be read
#define PROT_WRITE              0x2  // pages can be written
#define PROT_EXEC               0x4  // pages can be executed
#define PROT_SEM                0x8  // pages can be used for atomic ops (futex)
#define PROT_GROWSDOWN          0x01000000 // apply to stack-like growing-down mapping
#define PROT_GROWSUP            0x02000000 // apply to growing-up mapping

// ─── mmap flags (flags arg to mmap) ──────────────────────────
#define MAP_SHARED              0x01   // share changes with other mappings of the same file
#define MAP_PRIVATE             0x02   // copy-on-write — changes not written back to file
#define MAP_SHARED_VALIDATE     0x03   // like MAP_SHARED but validates all flags  since 4.15
#define MAP_FIXED               0x10   // map exactly at addr; unmaps existing mapping there
#define MAP_ANONYMOUS           0x20   // not backed by a file; fd ignored, offset should be 0
#define MAP_ANON                MAP_ANONYMOUS // alias
#define MAP_GROWSDOWN           0x0100 // stack-like mapping that can grow downward
#define MAP_DENYWRITE           0x0800 // ignored (deprecated)
#define MAP_EXECUTABLE          0x1000 // ignored (deprecated)
#define MAP_LOCKED              0x2000 // lock pages in ram (like mlock, but at map time)
#define MAP_NORESERVE           0x4000 // do not reserve swap space (risky — SIGSEGV on write if oom)
#define MAP_POPULATE            0x8000 // prefault pages; read: populate now; write: writable prefault
#define MAP_NONBLOCK            0x10000 // with MAP_POPULATE: do not block on i/o (best effort)
#define MAP_STACK               0x20000 // hint that this mapping is for a thread stack
#define MAP_HUGETLB             0x40000 // use huge pages (see /sys/kernel/mm/hugepages)
#define MAP_SYNC                0x80000 // sync mapping to persistent storage (dax/pmem)  since 4.15
#define MAP_FIXED_NOREPLACE     0x100000 // like MAP_FIXED but fails if addr is already mapped  since 4.17
#define MAP_UNINITIALIZED       0x4000000 // do not zero anonymous pages (for performance, embedded)

// ─── splice / sendfile flags ─────────────────────────────────
#define SPLICE_F_MOVE           0x01  // attempt to move pages instead of copy (hint, may be ignored)
#define SPLICE_F_NONBLOCK       0x02  // do not block on pipe i/o (may still block on fd)
#define SPLICE_F_MORE           0x04  // more data will follow — hint for socket cork behaviour
#define SPLICE_F_GIFT           0x08  // user pages are gifted to the kernel (for vmsplice)

// ─── arch-specific O_* flag differences ──────────────────────
//  the values above match x86 / x86_64 / arm64 (asm-generic).
//  on arm 32-bit the values are also the same (uses asm-generic).
//  the only meaningful arch divergence in mainline linux is:
//    SPARC: O_APPEND=0x8, O_CREAT=0x200, etc. (completely different)
//    MIPS:  O_CREAT=0x100, O_TRUNC=0x200, O_APPEND=0x8 (different)
//    ALPHA, PARISC: also use different values
//  all four architectures covered by this project (x86, x86_64, arm, arm64)
//  use the asm-generic values defined above — no per-arch guards needed.
