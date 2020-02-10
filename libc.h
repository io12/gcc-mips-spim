





static double sin(double d)  ;
static double cos(double d)  ;
static double tan(double d)  ;

static double sinh(double d)  ;
static double cosh(double d)  ;
static double tanh(double d)  ;

static double asin(double d)  ;
static double acos(double d)  ;
static double atan(double d)  ;

static double asinh(double d)  ;
static double acosh(double d)  ;
static double atanh(double d)  ;

static double exp(double d)  ;
static double exp10(double d)  ;
static double log(double d)  ;
static double log10(double d)  ;

static double exp2(double d)  ;
static double log2(double d)  ;

static double pow(double x, double y)  ;

static double sqrt(double x)  ;
static double fabs(double x)  ;
static double fmod(double x, double y)  ;

static double floor(double x) ;
static double ceil(double x) ;

static double expm1(double x)  ;
static double hypot(double x, double y)  ;
static double atan2(double x, double y)  ;

static double copysign(double value, double sign) ;
static int isnan(double d) ;
static int isinf(double d) ;
static int finite(double d) ;

static double j0(double x);
static double j1(double x);
static double jn(int n, double x);
static double y0(double x);
static double y1(double x);
static double yn(int n, double x);
static double erf(double x);
static double erfc(double x);
static double lgamma(double x);

static double rint(double x);

static double modf(double x, double * iptr);

static double frexp(double x, int *exp);
static double ldexp(double x, int exp);




static int finite(double d) {
  return isinf(d)==0 && isnan(d)==0;
}

static int __finite(double d) __attribute__((const, alias("finite")));






static int *__errno_location(void);

















typedef signed char int8_t;



typedef signed short int16_t;




typedef signed int int32_t;


typedef unsigned char uint8_t;



typedef unsigned short uint16_t;




typedef unsigned int uint32_t;
typedef signed long long int64_t;
typedef unsigned long long uint64_t;
typedef signed long long int intmax_t;
typedef unsigned long long int uintmax_t;



typedef int intptr_t;
typedef unsigned int uintptr_t;





static intmax_t strtoimax (const char *nptr, char **endptr, int base);
static uintmax_t strtoumax (const char *nptr, char **endptr, int base);

static intmax_t imaxabs(intmax_t j) __attribute__((const));
typedef struct { intmax_t quot,rem; } imaxdiv_t;
static imaxdiv_t imaxdiv(intmax_t numerator, intmax_t denominator) __attribute__((const));












typedef int ptrdiff_t;
typedef unsigned int size_t;

typedef int wchar_t;




typedef unsigned long int blkcnt_t;
typedef unsigned long int blksize_t;
typedef unsigned long int clock_t;



typedef uint64_t fsblkcnt_t;
typedef uint64_t fsfilcnt_t;
    typedef uint32_t dev_t;
    typedef int32_t gid_t;
    typedef uint32_t mode_t;
    typedef int32_t nlink_t;
    typedef int32_t uid_t;
typedef int32_t id_t;


typedef unsigned long ino_t;
typedef int32_t key_t;
typedef int32_t pid_t;



typedef signed int ssize_t;
typedef signed long suseconds_t;
typedef signed long useconds_t;




typedef signed long time_t;



typedef signed long long loff_t;

typedef signed long long off64_t;







typedef signed long off_t;



typedef unsigned long long ino64_t;
typedef signed long long blkcnt64_t;

typedef uint32_t uid32_t;
typedef uint32_t gid32_t;

typedef int32_t clockid_t;
typedef int32_t timer_t;

typedef long int fpos_t;


typedef uint32_t socklen_t;
typedef uint16_t sa_family_t;




struct timespec {
  time_t tv_sec;
  long tv_nsec;
};

struct timeval {
  time_t tv_sec;
  suseconds_t tv_usec;
};

struct timezone {
  int tz_minuteswest;
  int tz_dsttime;
};












static char *strcpy(char* __restrict__ dest, const char* __restrict__ src)  ;

static void *memccpy(void* __restrict__ dest, const void* __restrict__ src, int c, size_t n)  ;
static void *memmove(void* dest, const void *src, size_t n)  ;

static int memccmp(const void* s1, const void* s2, int c, size_t n)   ;

static void* memset(void* s, int c, size_t n)  __attribute__ ((__nonnull__ (1)));
static int memcmp(const void* s1, const void* s2, size_t n)   ;
static void* memcpy(void* __restrict__ dest, const void* __restrict__ src, size_t n)  ;

static char *strncpy(char* __restrict__ dest, const char* __restrict__ src, size_t n)  ;
static int strncmp(const char* s1, const char* s2, size_t n)   ;

static char *strcat(char* __restrict__ dest, const char* __restrict__ src)  ;
static char *strncat(char* __restrict__ dest, const char* __restrict__ src, size_t n)  ;

static int strcmp(const char *s1, const char *s2)   ;

static size_t strlen(const char *s)   __attribute__ ((__nonnull__ (1)));
static size_t strnlen(const char *s,size_t maxlen)   __attribute__ ((__nonnull__ (1)));





static char *strstr(const char *haystack, const char *needle)   ;

static char *strdup(const char *s)  __attribute__((__malloc__)) __attribute__ ((__nonnull__ (1)));

static char *strchr(const char *s, int c)   __attribute__ ((__nonnull__ (1)));
static char *strrchr(const char *s, int c)   __attribute__ ((__nonnull__ (1)));

static size_t strspn(const char *s, const char *_accept)  ;
static size_t strcspn(const char *s, const char *reject)  ;

static char *strpbrk(const char *s, const char *_accept)  ;
static char *strsep(char ** __restrict__ stringp, const char * __restrict__ delim)  ;

static void* memchr(const void *s, int c, size_t n)   __attribute__ ((__nonnull__ (1)));






static char *strerror(int errnum)  __attribute__((const));


static int strerror_r(int errnum,char* buf,size_t n)  __attribute__((__deprecated__));
static char *strtok(char * __restrict__ s, const char * __restrict__ delim)  __attribute__ ((__nonnull__ (2)));
static char *strtok_r(char * __restrict__ s, const char * __restrict__ delim, char ** __restrict__ ptrptr)  __attribute__ ((__nonnull__ (2,3)));

static size_t strlcpy(char * __restrict__ dst, const char * __restrict__ src, size_t size)  ;
static size_t strlcat(char * __restrict__ dst, const char * __restrict__ src, size_t size)  ;

static int strcoll(const char *s1, const char *s2)  ;
static size_t strxfrm(char *dest, const char * __restrict__ src, size_t n)  ;





static char *stpcpy(char * __restrict__ dest, const char * __restrict__ src)  ;
static char* stpncpy(char* __restrict__ dest, const char* __restrict__ src, size_t n)  ;
static void explicit_bzero(void*, size_t)  __attribute__((noinline));





static int timingsafe_memcmp(const void* s1, const void* s2, size_t n)   __attribute__((noinline));
static int timingsafe_bcmp(const void* s1, const void* s2, size_t n)   __attribute__((noinline));



static int consttime_memequal(void *b1, void *b2, size_t len)   __attribute__((noinline));


static void* explicit_memset(void *b, int c, size_t len)  __attribute__ ((__nonnull__ (1))) __attribute__((noinline));








typedef int sig_atomic_t;

typedef void (*sighandler_t)(int);
typedef union sigval {
  int sival_int;
  void *sival_ptr;
} sigval_t;
typedef long __band_t;


typedef struct siginfo {
  int32_t si_signo;
  int32_t si_errno;
  int32_t si_code;
  union {
    int32_t _pad[((128/sizeof(int32_t)) - 3)];

    struct {
      pid_t _pid;
      uid_t _uid;
    } _kill;

    struct {
      uint32_t _timer1;
      uint32_t _timer2;
    } _timer;

    struct {
      pid_t _pid;
      uid_t _uid;
      sigval_t _sigval;
    } _rt;

    struct {
      pid_t _pid;
      uid_t _uid;
      int32_t _status;
      clock_t _utime;
      clock_t _stime;
    } _sigchld;

    struct {
      void *_addr;
    } _sigfault;

    struct {
      __band_t _band;
      int32_t _fd;
    } _sigpoll;
  } _sifields;
} siginfo_t;
enum {
  SI_ASYNCNL = -6,

  SI_SIGIO,

  SI_ASYNCIO,

  SI_MESGQ,

  SI_TIMER,

  SI_QUEUE,

  SI_USER,

  SI_KERNEL = 0x80

};



enum {
  ILL_ILLOPC = 1,

  ILL_ILLOPN,

  ILL_ILLADR,

  ILL_ILLTRP,

  ILL_PRVOPC,

  ILL_PRVREG,

  ILL_COPROC,

  ILL_BADSTK

};


enum {
  FPE_INTDIV = 1,

  FPE_INTOVF,

  FPE_FLTDIV,

  FPE_FLTOVF,

  FPE_FLTUND,

  FPE_FLTRES,

  FPE_FLTINV,

  FPE_FLTSUB

};


enum {
  SEGV_MAPERR = 1,

  SEGV_ACCERR

};


enum {
  BUS_ADRALN = 1,

  BUS_ADRERR,

  BUS_OBJERR

};


enum {
  TRAP_BRKPT = 1,

  TRAP_TRACE

};


enum {
  CLD_EXITED = 1,

  CLD_KILLED,

  CLD_DUMPED,

  CLD_TRAPPED,

  CLD_STOPPED,

  CLD_CONTINUED

};


enum {
  POLL_IN = 1,

  POLL_OUT,

  POLL_MSG,

  POLL_ERR,

  POLL_PRI,

  POLL_HUP

};



typedef struct {
  unsigned long sig[(1024 / (8 * sizeof (unsigned long int)))];
} sigset_t;

struct sigaction {
  unsigned long sa_flags;
  union {
    sighandler_t _sa_handler;
    void (*_sa_sigaction)(int, siginfo_t*, void*);
  } _u;
  sigset_t sa_mask;
  void (*sa_restorer)(void);
  int32_t sa_resv[1];
};
typedef struct sigevent {
  sigval_t sigev_value;
  int32_t sigev_signo;
  int32_t sigev_notify;
  union {
    int32_t _pad[((64/sizeof(int32_t)) - 3)];
    int32_t _tid;

    struct {
      void(*_function)(sigval_t);
      void*_attribute;
    } _sigev_thread;
  } _sigev_un;
} sigevent_t;





typedef struct sigaltstack {

  void *ss_sp;
  size_t ss_size;
  int32_t ss_flags;





} stack_t;

static int sigaltstack(const struct sigaltstack *newstack, struct sigaltstack *oldstack) ;

static int sigemptyset(sigset_t *set) ;
static int sigfillset(sigset_t *set) ;
static int sigaddset(sigset_t *set, int signum) ;
static int sigdelset(sigset_t *set, int signum) ;
static int sigismember(const sigset_t *set, int signo) ;
static int sigsuspend(const sigset_t *mask) ;
static int sigpending(sigset_t *set) ;
static int sigprocmask(int how, const sigset_t *set, sigset_t *oldset) ;







static sighandler_t signal(int signum, sighandler_t action);

static int raise (int sig) ;
static int kill(pid_t pid, int sig) ;

static int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact) ;


static int sigtimedwait(const sigset_t *mask, siginfo_t *info, const struct timespec *ts) ;
static int sigqueueinfo(pid_t pid, int sig, siginfo_t *info) ;
static int siginterrupt(int sig, int flag) ;

static int killpg(pid_t pgrp, int sig) ;




static int sigwait(const sigset_t* set,int* sig) ;

static const char *const* sys_siglist;
















struct sigcontext {
 unsigned int sc_regmask;
 unsigned int sc_status;
 unsigned long long sc_pc;
 unsigned long long sc_regs[32];
 unsigned long long sc_fpregs[32];
 unsigned int sc_ownedfp;
 unsigned int sc_fpc_csr;
 unsigned int sc_fpc_eir;
 unsigned int sc_ssflags;
 unsigned long long sc_mdhi;
 unsigned long long sc_mdlo;

 unsigned int sc_cause;
 unsigned int sc_badvaddr;

 unsigned long sc_sigset[4];
};





typedef struct sigcontext mcontext_t;



struct ucontext {
  unsigned long uc_flags;
  struct ucontext *uc_link;
  stack_t uc_stack;
  struct sigcontext uc_mcontext;
  sigset_t uc_sigmask;



};
typedef struct ucontext ucontext_t;







typedef long int fd_mask;







typedef struct {
  unsigned long fds_bits [(1024/(8 * sizeof(unsigned long)))];
} fd_set;







static int select(int n, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout) ;

static int pselect(int n, fd_set* readfds, fd_set* writefds, fd_set* exceptfds,
            const struct timespec *timeout, const sigset_t *sigmask) ;







struct itimerspec {
  struct timespec it_interval;
  struct timespec it_value;
};

struct itimerval {
  struct timeval it_interval;
  struct timeval it_value;
};




typedef void *__timezone_ptr_t;


static int getitimer(int which, struct itimerval *value) ;
static int setitimer(int which, const struct itimerval *value, struct itimerval *ovalue) ;

static int gettimeofday(struct timeval *tv, struct timezone *tz) ;
static int settimeofday(const struct timeval *tv , const struct timezone *tz) ;

static int adjtime (const struct timeval *delta, struct timeval *olddelta) ;

struct tm {
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;

  long int tm_gmtoff;
  const char *tm_zone;
};
static int utimes(const char * filename, struct timeval * tvp) ;







struct stat {
 uint32_t st_dev;
 long st_pad1[3];
 ino_t st_ino;
 uint32_t st_mode;
 int32_t st_nlink;
 int32_t st_uid;
 int32_t st_gid;
 uint32_t st_rdev;
 long st_pad2[2];
 long st_size;
 long st_pad3;




 time_t st_atime;
 long st_atime_nsec;
 time_t st_mtime;
 long st_mtime_nsec;
 time_t st_ctime;
 long st_ctime_nsec;
 long st_blksize;
 long st_blocks;
 char st_fstype[16];
 long st_pad4[14];
};

struct stat64 {
 unsigned long st_dev;
 unsigned long st_pad0[3];
__extension__ unsigned long long st_ino;
 uint32_t st_mode;
 uint32_t st_nlink;
 uint32_t st_uid;
 uint32_t st_gid;
 unsigned long st_rdev;
 unsigned long st_pad1[3];
__extension__ long long st_size;




 time_t st_atime;
 unsigned long reserved0;
 time_t st_mtime;
 unsigned long reserved1;
 time_t st_ctime;
 unsigned long reserved2;
 unsigned long st_blksize;
 unsigned long st_pad2;
__extension__ long long st_blocks;
};
static int stat(const char *__file, struct stat *__buf) ;
static int fstat(int __fd, struct stat *__buf) ;
static int lstat(const char *__file, struct stat *__buf) ;




static int stat64(const char *__file, struct stat64 *__buf) ;
static int fstat64(int __fd, struct stat64 *__buf) ;
static int lstat64(const char *__file, struct stat64 *__buf) ;
static int chmod (const char *__file, mode_t __mode) ;
static int fchmod (int __fd, mode_t __mode) ;
static mode_t umask (mode_t __mask) ;
static int mkdir (const char *__path, mode_t __mode) ;
static int mknod (const char *__path, mode_t __mode, dev_t __dev) ;
static int mkfifo (const char *__path, mode_t __mode) ;
static int fchmodat(int dirfd, const char *pathname, mode_t mode, int flags) ;
static int fstatat(int dirfd, const char *pathname, struct stat *buf, int flags) ;
static int mkdirat(int dirfd, const char *pathname, mode_t mode) ;
static int mknodat(int dirfd, const char *pathname, mode_t mode, dev_t dev) ;
static int mkfifoat(int dirfd, const char *pathname, mode_t mode) ;
static int utimensat(int dirfd, const char *pathname, struct timespec* t,int flags) ;
























static int setfsuid(uid_t uid);
static int setfsgid(gid_t gid);
static int setfsuid32(uid32_t fsuid) ;
static int setfsgid32(gid32_t fsgid) ;






static int optind,opterr,optopt;
static char *optarg;
static int getopt(int argc, char *const argv[], const char *options);
static int access (const char *__name, int __type) ;
static off_t lseek(int fildes, off_t offset, int whence) ;

static loff_t lseek64(int fildes, loff_t offset, int whence) ;







static int chdir(const char *path) ;
static int fchdir(int fd) ;
static int rmdir(const char *pathname) ;
static char *getcwd(char *buf, size_t size)  __attribute__((__warn_unused_result__));







static int open(const char* pathname,int flags, ...) ;
static int open64(const char* pathname,int flags, ...) ;
static int creat(const char* pathname,mode_t mode) ;
static int creat64(const char* pathname,mode_t mode) ;
static ssize_t write(int fd,const void* buf,size_t len) ;
static ssize_t read(int fd,void* buf,size_t len) ;
static int close(int fd) ;

static int unlink(const char *pathname) ;

static ssize_t pread(int fd, void *buf, size_t count, off_t offset);
static ssize_t pwrite(int fd, const void *buf, size_t count, off_t offset);
static ssize_t pread64(int fd, void *buf, size_t count, off64_t offset);
static ssize_t pwrite64(int fd, const void *buf, size_t count, off64_t offset);

static int execve(const char *filename, char *const argv [], char *const envp[]) ;
static int execlp(const char *file, const char *arg, ...) ;
static int execv(const char *path, char *const argv[]) ;
static int execvp(const char *file, char *const argv[]) ;
static int execl(const char *path, const char* arg, ...) ;
static int execle(const char *path, const char* arg, ...) ;

static pid_t getpid(void)  ;

static pid_t getppid(void) ;

static int setpgid (pid_t pid,pid_t pgid) ;
static pid_t getpgid (pid_t pid) ;
static int setpgrp (void) ;
static pid_t getpgrp (void) ;
static pid_t getsid(pid_t pid) ;
static pid_t setsid (void) ;
static int dup (int oldfd) ;
static int dup2 (int oldfd,int newfd) ;
struct dirent;
struct dirent64;
static int getdents(int fd, struct dirent *dirp, unsigned int count) ;
static int getdents64(int fd, struct dirent64 *dirp, unsigned int count) ;

static pid_t fork(void) ;
static pid_t vfork(void) ;

static int readlink(const char *path, char *buf, size_t bufsiz) ;
static int symlink(const char *oldpath, const char *newpath) ;
static int link(const char *oldpath, const char *newpath) ;

static int chown(const char *path, uid_t owner, gid_t group) ;
static int fchown(int fd, uid_t owner, gid_t group) ;
static int lchown(const char *path, uid_t owner, gid_t group) ;

static int fsync(int fd) ;

static int fdatasync(int fd) ;

static int pipe(int filedes[2]) ;

static char *ttyname (int desc) ;

static int brk(void *end_data_segment) ;
static void *sbrk(ptrdiff_t increment) ;

static int gethostname(char *name, size_t len) ;
static int sethostname(const char *name, size_t len) ;

static int usleep(unsigned long useconds) ;
static unsigned int sleep(unsigned int seconds) ;

static unsigned int alarm(unsigned int seconds) ;
static int sync(void) ;

static int isatty(int desc) ;

static void _exit(int status)  __attribute__((__noreturn__));

static int daemon(int nochdir,int noclose) ;

static int pause(void) ;

static char* getlogin(void) ;


static int chroot(const char *path) ;

static uid_t getuid(void) ;
static uid_t geteuid(void) ;
static gid_t getgid(void) ;
static gid_t getegid(void) ;
static int setuid(uid_t uid) ;

static int setgid(gid_t gid) ;

static int setregid(gid_t rgid, gid_t egid) ;
static int setreuid(uid_t ruid, uid_t euid) ;



static int truncate(const char *path, off_t length) ;
static int ftruncate(int fd, off_t length) ;

static int truncate64(const char *path, loff_t length) ;
static int ftruncate64(int fd, loff_t length) ;


static int nice(int inc) ;

static char *crypt(const char *key, const char *salt) ;
static void encrypt(char block[64], int edflag) ;
static void setkey(const char *key) ;







static int getpagesize(void)  ;

static int getdomainname(char *name, size_t len) ;
static int setdomainname(const char *name, size_t len) ;

static int getgroups(int size, gid_t list[]) ;
static int getdtablesize(void) ;
static char *getpass(const char * prompt) ;


static int llseek(int fildes, unsigned long hi, unsigned long lo, loff_t* result,int whence) ;


struct __sysctl_args;
static int _sysctl(struct __sysctl_args *args) ;


static size_t confstr(int name,char*buf,size_t len) ;
static long sysconf(int name) ;



static pid_t tcgetpgrp(int fd) ;
static int tcsetpgrp(int fd, pid_t pgrpid) ;

static int profil(unsigned short *buf, size_t bufsiz, size_t offset, unsigned int scale);


static int getresuid(uid_t *ruid, uid_t *euid, uid_t *suid) ;
static int getresgid(gid_t *rgid, gid_t *egid, gid_t *sgid) ;
static int setresuid(uid_t ruid, uid_t euid, uid_t suid) ;
static int setresgid(gid_t rgid, gid_t egid, gid_t sgid) ;


static int chown32(const char *path, uid32_t owner, gid32_t group) ;
static int fchown32(int fd, uid32_t owner, gid32_t group) ;
static int lchown32(const char *path, uid32_t owner, gid32_t group) ;
static uid32_t getuid32(void) ;
static uid32_t geteuid32(void) ;
static gid32_t getgid32(void) ;
static gid32_t getegid32(void) ;
static int setuid32(uid32_t uid) ;
static int setgid32(gid32_t gid) ;
static int setreuid32(uid32_t ruid, uid32_t euid) ;
static int setregid32(gid32_t rgid, gid32_t egid) ;


static int getgroups32(int size, gid32_t list[]) ;
static int getresuid32(uid32_t *ruid, uid32_t *euid, uid32_t *suid);
static int getresgid32(gid32_t *rgid, gid32_t *egid, gid32_t *sgid);
static int setresuid32(uid32_t ruid, uid32_t euid, uid32_t suid) ;
static int setresgid32(gid32_t rgid, gid32_t egid, gid32_t sgid) ;
static char* cuserid(char * string);
static int lockf (int __fd, int __cmd, off_t __len) ;
static int lockf64 (int __fd, int __cmd, off64_t __len) ;

static void swab(const void *src, void *dest, ssize_t nbytes) ;

static int vhangup(void) ;

static char **__environ;
static int faccessat(int dirfd, const char *pathname, int mode, int flags) ;
static int fchownat(int dirfd, const char *pathname, uid_t owner, gid_t group, int flags) ;
static int linkat(int olddirfd, const char *oldpath, int newdirfd, const char *newpath, int flags) ;
static int readlinkat(int dirfd, const char *pathname, char *buf, size_t bufsiz) ;
















struct sockaddr {
  sa_family_t sa_family;
  char sa_data[14];
};

struct linger {
  int32_t l_onoff;
  int32_t l_linger;
};

struct msghdr {
  void* msg_name;
  socklen_t msg_namelen;
  struct iovec* msg_iov;
  size_t msg_iovlen;
  void* msg_control;
  size_t msg_controllen;
  uint32_t msg_flags;
};

struct cmsghdr {
  size_t cmsg_len;
  int32_t cmsg_level;
  int32_t cmsg_type;
};
struct ucred {
  pid_t pid;
  uid_t uid;
  gid_t gid;
};
static inline struct cmsghdr* __cmsg_nxthdr(void *__ctl, size_t __size, struct cmsghdr *__cmsg)
{
  struct cmsghdr * __ptr;
  __ptr = (struct cmsghdr*)(((unsigned char *) __cmsg) + ( ((__cmsg->cmsg_len)+sizeof(long)-1) & ~(sizeof(long)-1) ));
  if ((unsigned long)((char*)(__ptr+1) - (char *) __ctl) > __size)
    return (struct cmsghdr *)0;
  return __ptr;
}

static inline struct cmsghdr* cmsg_nxthdr (struct msghdr *__msg, struct cmsghdr *__cmsg)
{
  return __cmsg_nxthdr(__msg->msg_control, __msg->msg_controllen, __cmsg);
}
struct sockaddr_storage {
  sa_family_t ss_family;
  uint32_t __ss_align;
  char __ss_padding[(128 - (2 * sizeof (uint32_t ))) ];
};

static int socket(int domain, int type, int protocol) ;
static int accept(int s, void *addr, void *addrlen) ;
static int connect(int sockfd, void *serv_addr, int addrlen) ;
static int bind(int sockfd, void *my_addr, int addrlen) ;
static int recv(int s, void *buf, size_t len, int flags) ;
static int recvfrom(int s, void *buf, size_t len, int flags, struct sockaddr *from, socklen_t *fromlen) ;
static int recvmsg(int s, struct msghdr *msg, int flags) ;
static int send(int s, const void *msg, size_t len, int flags) ;
static int sendto(int s, const void *msg, size_t len, int flags, const struct sockaddr *to, socklen_t tolen) ;
static int sendmsg(int s, const struct msghdr *msg, int flags) ;

static int getpeername(int s, struct sockaddr *name, socklen_t *namelen) ;
static int getsockname(int s , struct sockaddr * name , socklen_t * namelen) ;

static int getsockopt(int s, int level, int optname, void *optval, socklen_t *optlen) ;
static int setsockopt(int s, int level, int optname, const void *optval, socklen_t optlen) ;

static int listen(int s, int backlog) ;




static int shutdown(int s, int how) ;

static int socketpair(int d, int type, int protocol, int sv[2]) ;
struct addrinfo {
  int ai_flags;
  int ai_family;
  int ai_socktype;
  int ai_protocol;
  size_t ai_addrlen;
  struct sockaddr *ai_addr;
  char *ai_canonname;
  struct addrinfo *ai_next;
};

static int getnameinfo(const struct sockaddr *sa, socklen_t salen, char *host,
  size_t hostlen, char *serv, size_t servlen, int flags) ;
static int getaddrinfo(const char *node, const char *service, const struct
  addrinfo *hints, struct addrinfo **res) ;
static void freeaddrinfo(struct addrinfo *res) ;
static const char *gai_strerror(int errcode) ;




struct iovec {
  void* iov_base;
  size_t iov_len;
};


static ssize_t readv(int filedes, const struct iovec *vector, int count) ;
static ssize_t writev(int filedes, const struct iovec *vector, int count) ;

static ssize_t preadv(int fd, const struct iovec *iov, int iovcnt, off_t offset) ;
static ssize_t pwritev(int fd, const struct iovec *iov, int iovcnt, off_t offset) ;




struct flock {
  int16_t l_type;
  int16_t l_whence;
  off_t l_start;
  off_t l_len;
  long l_sysid;
  pid_t l_pid;
  long pad[4];
};
struct flock64 {
  int16_t l_type;
  int16_t l_whence;
  loff_t l_start;
  loff_t l_len;
  pid_t l_pid;
};
static int fcntl (int __fd, int __cmd, ...) ;

static int fcntl64 (int __fd, int __cmd, ...) ;
static int fstatat64(int dirfd, const char *pathname, struct stat64 *buf, int flags) ;
struct f_owner_ex {
 int type;
 int pid;
};
static int openat(int dirfd, const char *pathname, int flags, ...) ;
static int futimesat(int dirfd, const char *pathname, const struct timeval times[2]) ;
static int unlinkat(int dirfd, const char *pathname, int flags) ;









static int fstatat(int dirfd, const char* pathname, struct stat *buf, int flags) {
  struct stat64 ss;
  if (fstatat64(dirfd,pathname,&ss,flags)==0) {
    buf->st_dev=ss.st_dev;
    buf->st_ino=ss.st_ino;
    buf->st_mode=ss.st_mode;
    buf->st_nlink=ss.st_nlink;
    buf->st_uid=ss.st_uid;
    buf->st_gid=ss.st_gid;
    buf->st_rdev=ss.st_rdev;
    buf->st_size=ss.st_size;
    buf->st_blksize=ss.st_blksize;
    buf->st_blocks=ss.st_blocks;
    buf->st_atime=ss.st_atime;
    buf->st_mtime=ss.st_mtime;
    buf->st_ctime=ss.st_ctime;
    if (buf->st_uid!=ss.st_uid || buf->st_gid!=ss.st_gid || buf->st_size!=ss.st_size || buf->st_ino!=ss.st_ino || buf->st_blocks!=ss.st_blocks)
      
     (*__errno_location())
          =
           79
                    ;
  }
  return 0;
}














typedef struct {
  int32_t __val[2];
} __kernel_fsid_t;
struct statfs {
  int32_t f_type;

  int32_t f_bsize;
  int32_t f_frsize;
  int32_t f_blocks;
  int32_t f_bfree;
  int32_t f_files;
  int32_t f_ffree;
  int32_t f_bavail;


  __kernel_fsid_t f_fsid;
  int32_t f_namelen;
  int32_t f_spare[6];
};

struct statfs64 {
  uint32_t f_type;
  uint32_t f_bsize;
  uint32_t f_frsize;
  uint32_t __pad;
  uint64_t f_blocks;
  uint64_t f_bfree;
  uint64_t f_files;
  uint64_t f_ffree;
  uint64_t f_bavail;
  __kernel_fsid_t f_fsid;
  uint32_t f_namelen;
  uint32_t f_spare[6];
};
static int statfs(const char *path, struct statfs *buf) ;
static int fstatfs(int fd, struct statfs *buf) ;


static int statfs64(const char *path, struct statfs64 *buf) ;
static int fstatfs64(int fd, struct statfs64 *buf) ;












static int __dietlibc_fstatfs64(int fd, size_t bufsize, struct statfs64 *__buf);
static void __statfs64_cvt(const struct statfs *src,struct statfs64 *dest);

static int fstatfs64(int fd, struct statfs64 *__buf) {

  if (__dietlibc_fstatfs64(fd,sizeof(*__buf),__buf)) {
    struct statfs temp;
    if (
       (*__errno_location())
            !=
              89
                    ) return -1;
    if (fstatfs(fd,&temp)) return -1;
    __statfs64_cvt(&temp,__buf);
  }
  return 0;



}









static int __dietlibc_ftruncate64(int fd, loff_t o);

static int ftruncate64(int fd, loff_t o) {
  int tmp;
  if ((tmp=__dietlibc_ftruncate64(fd,o))==-1) {
    if (
       (*__errno_location())
            !=
              89
                    ) return -1;
    if (o>0x7fffffff) { 
                       (*__errno_location())
                            =
                             79
                                      ; return -1; }
    return ftruncate(fd,o);
  }
  return tmp;
}











typedef union dtv
{
  size_t counter;
  struct {
    void *val;
    _Bool is_static;
  } pointer;
} dtv_t;

typedef struct
{
  void *tcb;
  dtv_t *dtv;
  void *self;
  int multiple_threads;



  uintptr_t sysinfo;
  uintptr_t stack_guard;
  uintptr_t pointer_guard;



} tcbhead_t;

static tcbhead_t* __get_cur_tcb(void) ;


static tcbhead_t* __get_cur_tcb(void) {




  register void* cur=0;
  return cur;
}



























static void *calloc(size_t nmemb, size_t size)  __attribute__((__malloc__));
static void *malloc(size_t size)  __attribute__((__malloc__));
static void free(void *ptr) ;
static void *realloc(void *ptr, size_t size)  __attribute__((__malloc__));


static void* reallocarray(void* ptr, size_t nmemb, size_t size)  __attribute__((__malloc__)) __attribute__((alloc_size(2,3)));

static char *getenv(const char *name)  ;
static int putenv(const char *string) ;
static int setenv(const char *name, const char *value, int overwrite) ;
static int unsetenv(const char *name) ;

static int system (const char * string) ;
static int atexit(void (*function)(void)) ;

static float strtof(const char *nptr, char **endptr) ;
static double strtod(const char *nptr, char **endptr) ;
static long double strtold(const char *nptr, char **endptr) ;
static long int strtol(const char *nptr, char **endptr, int base) ;
static unsigned long int strtoul(const char *nptr, char **endptr, int base) ;

static int __ltostr(char *s, unsigned int size, unsigned long i, unsigned int base, int UpCase) ;
static int __dtostr(double d,char *buf,unsigned int maxlen,unsigned int prec,unsigned int prec2,int flags) ;


static long long int strtoll(const char *nptr, char **endptr, int base) ;
static unsigned long long int strtoull(const char *nptr, char **endptr, int base) ;
static int __lltostr(char *s, unsigned int size, unsigned long long i, unsigned int base, int UpCase) ;


static int atoi(const char *nptr) ;
static long int atol(const char *nptr) ;
static double atof(const char *nptr) ;
static long long int atoll(const char *nptr);

static void exit(int status)  __attribute__((__noreturn__));
static void abort(void)  __attribute__((__noreturn__));

static int rand(void) ;
static int rand_r(unsigned int *seed) ;
static void srand(unsigned int seed) ;





typedef unsigned short randbuf[3];
static double drand48(void) ;
static long lrand48(void) ;
static long mrand48(void) ;
static void srand48(long seed) ;
static unsigned short *seed48(randbuf buf) ;
static void lcong48(unsigned short param[7]) ;
static long jrand48(randbuf buf) ;
static long nrand48(randbuf buf) ;
static double erand48(randbuf buf) ;

static void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));
static void *bsearch(const void *key, const void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));



static char *realpath(const char *path, char *resolved_path) ;

static int mkstemp(char *_template);
static char* mkdtemp(char *_template);

static char* mktemp(char *_template);

static int abs(int i)  ;
static long int labs(long int i)  ;
static long long int llabs(long long int i)  ;
typedef struct { int quot,rem; } div_t;
typedef struct { long quot,rem; } ldiv_t;

static div_t div(int numerator, int denominator);
static ldiv_t ldiv(long numerator, long denominator);

typedef struct { long long quot,rem; } lldiv_t;
static lldiv_t lldiv(long long numerator, long long denominator);






static int mbtowc(wchar_t *pwc, const char *s, size_t n) ;
static int wctomb(char *s, wchar_t wc) ;
static size_t mbstowcs(wchar_t *dest, const char *src, size_t n) ;
static int mblen(const char* s,size_t n)  ;

static size_t wcstombs(char *dest, const wchar_t *src, size_t n) ;


static uint32_t arc4random(void) ;
static void arc4random_buf(void* buf, size_t n) ;
static uint32_t arc4random_uniform(uint32_t upper_bound) ;
static void arc4random_stir(void) ;
static void arc4random_addrandom(unsigned char* dat,size_t datlen) ;





static int __syscall_getcwd(char* buf, size_t size);

static char *getcwd(char *buf, size_t size) {
  if (
     __builtin_expect((long)((
     !size
     )),0)
                      ) {
    
   (*__errno_location())
        =
         22
               ;
    buf=0;
  } else {
    int tmp;
    if ((tmp=__syscall_getcwd(buf,size-1))<0) return 0;
    buf[tmp]=0;
  }
  return buf;
}







struct inotify_event {
  int32_t wd;
  uint32_t mask,
    cookie,
    len;
  char name[0];
};


static int inotify_init(void) ;
static int inotify_init1(int flags) ;
static int inotify_add_watch(int fd,const char* path,unsigned long mask) ;
static int inotify_rm_watch(int fd,int wd) ;



static int isinf(double d) {
  union {
    unsigned long long l;
    double d;
  } u;
  u.d=d;
  return (u.l==0x7FF0000000000000ll?1:u.l==0xFFF0000000000000ll?-1:0);
}
static int __isinf(double d) __attribute__((const, alias("isinf")));
static int isnan(double d) {
  union {
    unsigned long long l;
    double d;
  } u;
  u.d=d;
  return (u.l==0x7FF8000000000000ll || u.l==0x7FF0000000000000ll || u.l==0xfff8000000000000ll);
}
static int __isnan(double d) __attribute__((const, alias("isnan")));
static int __lltostr(char *s, unsigned int size, unsigned long long i, unsigned int base, int UpCase);

static int __lltostr(char *s, unsigned int size, unsigned long long i, unsigned int base, int UpCase)
{
  char *tmp;
  unsigned int j=0;

  s[--size]=0;

  tmp=s+size;

  if ((base==0)||(base>36)) base=10;

  j=0;
  if (!i)
  {
    *(--tmp)='0';
    j=1;
  }

  while((tmp>s)&&(i))
  {
    tmp--;
    if ((*tmp=i%base+'0')>'9') *tmp+=(UpCase?'A':'a')-'9'-1;
    i=i/base;
    j++;
  }
  memmove(s,tmp,j+1);

  return j;
}






static int __dietlibc_lstat64(const char *__file, struct stat64 *__buf);
static void __stat64_cvt(const struct stat *src,struct stat64 *dest);

static int lstat64(const char *__file, struct stat64 *__buf) {
  if (__dietlibc_lstat64(__file,__buf)) {
    struct stat temp;
    if (
       (*__errno_location())
            !=
              89
                    ) return -1;
    if (lstat(__file,&temp)) return -1;
    __stat64_cvt(&temp,__buf);
  }
  return 0;
}





static int __ltostr(char *s, unsigned int size, unsigned long i, unsigned int base, int UpCase)
{
  char *tmp;
  unsigned int j=0;

  s[--size]=0;

  tmp=s+size;

  if ((base==0)||(base>36)) base=10;

  j=0;
  if (!i)
  {
    *(--tmp)='0';
    j=1;
  }

  while((tmp>s)&&(i))
  {
    tmp--;
    if ((*tmp=i%base+'0')>'9') *tmp+=(UpCase?'A':'a')-'9'-1;
    i=i/base;
    j++;
  }
  memmove(s,tmp,j+1);

  return j;
}










static void *mmap (void *__addr, size_t __len, int __prot,
                   int __flags, int __fd, off_t __offset);

static int munmap (void *__addr, size_t __len) ;
static int mprotect (void *__addr, size_t __len, int __prot) ;
static int msync (void *__addr, size_t __len, int __flags) ;
static void *mremap (void *__addr, size_t __old_len, size_t __new_len,
       unsigned long __may_move) ;
static int mincore (void *__start, size_t __len, unsigned char *__vec);

static void *mmap64 (void *__addr, size_t __len, int __prot,
       int __flags, int __fd, off64_t __offset) ;







static int mlockall(int flags) ;
static int mlock(const void *addr, size_t len) ;
static int munlock(const void *addr, size_t len) ;
static int munlockall(void) ;
static int mlock2(const void *addr, size_t len, int flags) ;

static int madvise(void *start, size_t length, int advice) ;








struct pt_regs {

  unsigned long pad0[6];

  unsigned long regs[32];

  unsigned long lo;
  unsigned long hi;

  unsigned long cp0_epc;
  unsigned long cp0_badvaddr;
  unsigned long cp0_status;
  unsigned long cp0_cause;
};
static long int 
               fnord
                     (int request, ...) ;







static int __diet_ptrace(int request, pid_t pid, void *addr, void *data);
static int ptrace(int request, pid_t pid, void *addr, void *data);

static int ptrace(int request, pid_t pid, void *addr, void *data) {
  
 (*__errno_location())
      =0;
  switch (request) {
    case 
        0
                      : case 
                             8
                                        : case 
                                               0x10
                                                            :
    case 
        0x11
                     :
      return (__diet_ptrace (request, pid, 
                                          (void*)0
                                              , 
                                                (void*)0
                                                    ));
    case 
        2
                       : case 
                              3
                                             : case 
                                                    1
                                                                   :
      {
 long result;
 if (__diet_ptrace (request, pid, addr, &result) == -1)
  return (-1);
 return (result);
      }
    default:
      return (__diet_ptrace (request, pid, addr, data));
  }
}







static int __isleap(int year);
static int clock_settime(clockid_t clock_id,const struct timespec*tp);
static int clock_gettime(clockid_t clock_id,struct timespec*tp);
static int clock_getres(clockid_t clock_id,struct timespec*res);
static int clock_nanosleep(clockid_t clock_id, int flags,const struct timespec *rqtp, struct timespec *rmtp);



static int timer_create(clockid_t clock_id,struct sigevent*evp,timer_t*timerid) ;
static int timer_delete(timer_t timerid) ;
static int timer_settime(timer_t timerid,int flags,const struct itimerspec*ival,struct itimerspec*oval) ;
static int timer_gettime(timer_t timerid,const struct itimerspec*val) ;
static int timer_getoverrun(timer_t timerid) ;

static int nanosleep(const struct timespec *req, struct timespec *rem) ;

static time_t mktime(struct tm *timeptr)  ;

static char *asctime(const struct tm *timeptr) ;
static char *asctime_r(const struct tm *timeptr, char *buf) ;

static char *ctime(const time_t *timep) ;
static char *ctime_r(const time_t *timep, char* buf) ;

static size_t strftime(char *s, size_t max, const char *format, const struct tm *tm)  __attribute__((__format__(__strftime__,3,0)));
static time_t time(time_t *t) ;

static int stime(time_t *t) ;

static double difftime(time_t time1, time_t time0)  ;



static long int timezone;
static int daylight;
static char* tzname[2];

static void tzset (void) ;

struct tm* localtime(const time_t* t) ;
struct tm* gmtime(const time_t* t) ;
struct tm* localtime_r(const time_t* t, struct tm* r) ;
struct tm* gmtime_r(const time_t* t, struct tm* r) ;

static clock_t clock(void);

static char *strptime(const char *s, const char *format, struct tm *tm);


static time_t timegm(struct tm *timeptr)  __attribute__((__deprecated__))  ;
static time_t timelocal(struct tm *timeptr)  __attribute__((__deprecated__)) ;








struct sched_param {
  int sched_priority;
};



static int __sched_setparam(pid_t pid, const struct sched_param* p) ;
static int sched_setparam(pid_t pid, const struct sched_param* p) ;

static int __sched_getparam(pid_t pid, struct sched_param* p) ;
static int sched_getparam(pid_t pid, struct sched_param* p) ;

static int __sched_getscheduler(pid_t pid) ;
static int sched_getscheduler(pid_t pid) ;

static int __sched_setscheduler(pid_t pid, int policy, const struct sched_param* p) ;
static int sched_setscheduler(pid_t pid, int policy, const struct sched_param* p) ;

static int __sched_yield(void) ;
static int sched_yield(void) ;

static int __sched_get_priority_max(int policy) ;
static int sched_get_priority_max(int policy) ;

static int __sched_get_priority_min(int policy) ;
static int sched_get_priority_min(int policy) ;

static int __sched_rr_get_interval(pid_t pid, struct timespec* tp) ;
static int sched_rr_get_interval(pid_t pid, struct timespec* tp) ;
static int clone(int (*fn)(void*),void* stack,int flags,void* arg, ...) ;

static int unshare(int flags) ;

static long set_tid_address(int* tid) ;







typedef unsigned long cpu_set_t;

static inline void CPU_ZERO(cpu_set_t *set) {*set = 0;}
static inline void CPU_SET(int cpu, cpu_set_t *set) {*set |= (1UL << cpu);}
static inline void CPU_CLR(int cpu, cpu_set_t *set) {*set &= ~(1UL << cpu);}
static inline int CPU_ISSET(int cpu, cpu_set_t *set) {
 return !!(*set & (1UL << cpu));
}

static inline int CPU_COUNT(cpu_set_t *set)
{
 int c;
 unsigned long v;


 for (c = 0, v = *set; v; c++)
  v &= v - 1;
 return c;
}

static inline void CPU_AND(cpu_set_t *dest, cpu_set_t *s1, cpu_set_t *s2){
 *dest = *s1 & *s2;
}

static inline void CPU_OR(cpu_set_t *dest, cpu_set_t *s1, cpu_set_t *s2){
 *dest = *s1 | *s2;
}

static inline void CPU_XOR(cpu_set_t *dest, cpu_set_t *s1, cpu_set_t *s2){
 *dest = *s1 ^ *s2;
}

static inline int CPU_EQUAL(cpu_set_t *s1, cpu_set_t *s2){
 return *s1 == *s2;
}

static int sched_setaffinity(pid_t pid, size_t size, cpu_set_t *mask) ;
static int sched_getaffinity(pid_t pid, size_t size, cpu_set_t *mask) ;



static int setns(int fd,int nstype) ;






static int __syscall_sched_getaffinity(pid_t, size_t, cpu_set_t*);

static int sched_getaffinity(pid_t pid, size_t size, cpu_set_t *mask)
{
 int ret;

 *mask = 0;
 ret = __syscall_sched_getaffinity(pid, size, mask);
 if (ret > 0)
  return 0;
 return ret;
}













static ssize_t sendfile (int out_fd, int in_fd, off_t* offset,
    size_t count) ;


static ssize_t sendfile64 (int out_fd, int in_fd, loff_t* offset,
      size_t count) ;










static ssize_t __dietlibc_sendfile64 (int out_fd, int in_fd, loff_t* offset,
      size_t count);

static ssize_t sendfile64 (int out_fd, int in_fd, loff_t* offset, size_t count) {
  static int havesendfile64=1;
  ssize_t r = -1;
  if (havesendfile64) {
    r=__dietlibc_sendfile64(out_fd,in_fd,offset,count);
    if (r==-1 && 
                (*__errno_location())
                     ==
                       89
                             )
      havesendfile64=0;
  }
  if (!havesendfile64) {
    off_t o=*offset;
    if (*offset>0x7fffffff) { 
                             (*__errno_location())
                                  =
                                   22
                                         ; return -1; }
    r=sendfile(out_fd,in_fd,&o,count);
    *offset=o;
    return r;
  }
  return r;
}






static void __setup_tls(tcbhead_t* mainthread);


static 
       
                 unsigned long __guard;


static void __setup_tls(tcbhead_t* mainthread) {
  mainthread->tcb=mainthread;
  mainthread->dtv=0;
  mainthread->self=0;
  mainthread->multiple_threads=0;

  mainthread->stack_guard=__guard;
}






static int __dietlibc_stat64(const char *__file, struct stat64 *__buf);
static void __stat64_cvt(const struct stat *src,struct stat64 *dest);

static int stat64(const char *__file, struct stat64 *__buf) {
  if (__dietlibc_stat64(__file,__buf)) {
    struct stat temp;
    if (
       (*__errno_location())
            !=
              89
                    ) return -1;
    if (stat(__file,&temp)) return -1;
    __stat64_cvt(&temp,__buf);
  }
  return 0;
}





static void __stat64_cvt(const struct stat *src,struct stat64 *dest);

static void __stat64_cvt(const struct stat *src,struct stat64 *dest) {
  dest->st_dev=src->st_dev;
  dest->st_ino=src->st_ino;
  dest->st_mode=src->st_mode;
  dest->st_nlink=src->st_nlink;
  dest->st_uid=src->st_uid;
  dest->st_gid=src->st_gid;
  dest->st_rdev=src->st_rdev;
  dest->st_size=src->st_size;
  dest->st_blksize=src->st_blksize;
  dest->st_blocks=src->st_blocks;
  dest->st_atime=src->st_atime;
  dest->st_mtime=src->st_mtime;
  dest->st_ctime=src->st_ctime;
}







static int __dietlibc_statfs64(const char *path, size_t bufsize, struct statfs64 *__buf);
static void __statfs64_cvt(const struct statfs *src,struct statfs64 *dest);

static int statfs64(const char *__file, struct statfs64 *__buf) {

  if (__dietlibc_statfs64(__file,sizeof(*__buf),__buf)) {
    struct statfs temp;
    if (
       (*__errno_location())
            !=
              89
                    ) return -1;
    if (statfs(__file,&temp)) return -1;
    __statfs64_cvt(&temp,__buf);
  }
  return 0;



}




struct __sysctl_args {
 int *name;
 int nlen;
 void *oldval;
 size_t *oldlenp;
 void *newval;
 size_t newlen;
 unsigned long __unused[4];
};

static int sysctl (int *, int, void *, size_t *, void *, size_t);

static int
sysctl (int *name, int nlen, void *oldval, size_t *oldlenp, void *newval, size_t newlen)
{
 struct __sysctl_args args;
 args.name = name;
 args.nlen = nlen;
 args.oldval = oldval;
 args.oldlenp = oldlenp;
 args.newval = newval;
 args.newlen = newlen;
 return (_sysctl (&args));
}






static int __dietlibc_truncate64(const char* f, loff_t o);

static int truncate64(const char* f, loff_t o) {
  int tmp;
  if ((tmp=__dietlibc_truncate64(f,o))==-1) {
    if (
       (*__errno_location())
            !=
              89
                    ) return -1;
    if (o>0x7fffffff) { 
                       (*__errno_location())
                            =
                             79
                                      ; return -1; }
    return truncate(f,o);
  }
  return tmp;
}



















enum
{
  MS_RDONLY = 1,

  MS_NOSUID = 2,

  MS_NODEV = 4,

  MS_NOEXEC = 8,

  MS_SYNCHRONOUS = 16,

  MS_REMOUNT = 32,

  MS_MANDLOCK = 64,

  S_WRITE = 128,

  S_APPEND = 256,

  S_IMMUTABLE = 512,

  MS_NOATIME = 1024,

  MS_NODIRATIME = 2048,

  MS_BIND = 4096,


  MS_MOVE = 8192,


  MS_REC = 16384,


  MS_SILENT = 32768,



  MS_POSIXACL = (1<<16),


  MS_UNBINDABLE = (1<<17),

  MS_PRIVATE = (1<<18),


  MS_SLAVE = (1<<19),


  MS_SHARED = (1<<20),


  MS_RELATIME = (1<<21),


  MS_KERNMOUNT = (1<<22),


  MS_I_VERSION = (1<<23),

  MS_STRICTATIME = (1<<24),

  MS_NOSEC = (1<<28),

  MS_BORN = (1<<29),

  MS_ACTIVE = (1<<30),

  MS_NOUSER = (1<<31),


};
enum
{
  MNT_FORCE = 1,

  MNT_DETACH = 2

};

static int mount(const char* specialfile, const char* dir, const char* filesystemtype,
    unsigned long rwflag, const void * data) ;

static int umount(const char *specialfile) ;
static int umount2(const char *specialfile, int mflag) ;












struct utimbuf {
  time_t actime;
  time_t modtime;
};

static int utime(const char* filename, const struct utimbuf* buf) ;












typedef __builtin_va_list va_list;

















typedef struct
  {
    void * __pc;
    void * __sp;
    long __regs[8];
    void * __fp;
    void * __gp;
    int __fpc_csr;



    double __fpregs[6];

  } __jmp_buf[1];
typedef struct __jmp_buf_tag {



  __jmp_buf __jmpbuf;
  int __mask_was_saved;
  sigset_t __saved_mask;
} jmp_buf[1];

static int __sigsetjmp(jmp_buf __env,int __savemask) ;

static void longjmp(jmp_buf __env,int __val)
     __attribute__((__nothrow__)) __attribute__((__noreturn__));

typedef jmp_buf sigjmp_buf;

static void siglongjmp(sigjmp_buf __env,int __val)
     __attribute__((__nothrow__)) __attribute__((__noreturn__));



typedef struct _pthread_descr_struct*_pthread_descr;
typedef int pthread_t;
struct _pthread_fastlock { int __spinlock; };






typedef struct {
  struct _pthread_fastlock lock;
  _pthread_descr owner;
  int kind;
  unsigned int count;
} pthread_mutex_t;

enum {
  PTHREAD_MUTEX_FAST_NP,

  PTHREAD_MUTEX_RECURSIVE_NP,

  PTHREAD_MUTEX_ERRORCHECK_NP,

};

enum {
  PTHREAD_PROCESS_PRIVATE,

  PTHREAD_PROCESS_SHARED

};
typedef struct {
  int __mutexkind;
} pthread_mutexattr_t;

static int pthread_mutexattr_init(pthread_mutexattr_t*attr);
static int pthread_mutexattr_destroy(pthread_mutexattr_t*attr);

static int pthread_mutexattr_getkind_np(const pthread_mutexattr_t*attr,int*kind);
static int pthread_mutexattr_setkind_np(pthread_mutexattr_t*attr,int kind);

static int pthread_mutex_init(pthread_mutex_t*mutex,
  const pthread_mutexattr_t*mutexattr);
static int pthread_mutex_lock(pthread_mutex_t*mutex);
static int pthread_mutex_unlock(pthread_mutex_t*mutex);
static int pthread_mutex_trylock(pthread_mutex_t*mutex);
static int pthread_mutex_destroy(pthread_mutex_t*mutex);


typedef void* pthread_condattr_t;

typedef struct {
  struct _pthread_fastlock lock;
  _pthread_descr wait_chain;
} pthread_cond_t;




static int pthread_cond_init(pthread_cond_t*cond,pthread_condattr_t*cond_attr);
static int pthread_cond_destroy(pthread_cond_t*cond);
static int pthread_cond_signal(pthread_cond_t*cond);
static int pthread_cond_broadcast(pthread_cond_t*cond);
static int pthread_cond_timedwait(pthread_cond_t*cond,pthread_mutex_t*mutex,
      const struct timespec*abstime);
static int pthread_cond_wait(pthread_cond_t*cond,pthread_mutex_t*mutex);


static int pthread_condattr_init(pthread_condattr_t*attr);
static int pthread_condattr_destroy(pthread_condattr_t*attr);
static int pthread_condattr_getpshared(const pthread_condattr_t*attr,int*pshared);
static int pthread_condattr_setpshared(pthread_condattr_t*attr,int pshared);


typedef unsigned int pthread_key_t;

static int pthread_key_create(pthread_key_t*key,void(*destructor)(void*));
static int pthread_key_delete(pthread_key_t key);
static int pthread_setspecific(pthread_key_t key,const void*value);
static void*pthread_getspecific(pthread_key_t key);



typedef struct {
  int __detachstate;
  int __schedpolicy;
  struct sched_param __schedparam;
  int __inheritsched;
  int __scope;
  void * __stackaddr;
  unsigned long __stacksize;
} pthread_attr_t;

enum {
  PTHREAD_CREATE_JOINABLE,

  PTHREAD_CREATE_DETACHED

};

enum {
  PTHREAD_EXPLICIT_SCHED,

  PTHREAD_INHERIT_SCHED

};

enum {
  PTHREAD_SCOPE_SYSTEM,

  PTHREAD_SCOPE_PROCESS

};

static int pthread_attr_init(pthread_attr_t*attr);
static int pthread_attr_destroy(pthread_attr_t*attr);

static int pthread_attr_setdetachstate(pthread_attr_t*attr,const int detachstate);
static int pthread_attr_getdetachstate(const pthread_attr_t*attr,int*detachstate);

static int pthread_attr_setschedpolicy(pthread_attr_t*attr,const int policy);
static int pthread_attr_getschedpolicy(const pthread_attr_t*attr,int*policy);

static int pthread_attr_setschedparam(pthread_attr_t*attr,
    const struct sched_param*param);
static int pthread_attr_getschedparam(const pthread_attr_t*attr,
    struct sched_param*param);

static int pthread_attr_setinheritsched(pthread_attr_t*attr,const int inherit);
static int pthread_attr_getinheritsched(const pthread_attr_t*attr,int*inherit);

static int pthread_attr_setscope(pthread_attr_t*attr,const int scope);
static int pthread_attr_getscope(const pthread_attr_t*attr,int*scope);

static int pthread_attr_setstackaddr(pthread_attr_t*attr,void*stack);
static int pthread_attr_getstackaddr(const pthread_attr_t*attr,void**stack);

static int pthread_attr_setstacksize(pthread_attr_t*attr,const size_t stacksize);
static int pthread_attr_getstacksize(const pthread_attr_t*attr,size_t*stacksize);

static int pthread_setschedparam(const pthread_t target_thread,const int policy,
     const struct sched_param*param);
static int pthread_getschedparam(const pthread_t target_thread,int*policy,
     struct sched_param*param);


typedef int pthread_once_t;


static int pthread_once(pthread_once_t*once_control,void(*init_routine)(void));



enum {
  PTHREAD_CANCEL_ENABLE,

  PTHREAD_CANCEL_DISABLE,

};

enum {
  PTHREAD_CANCEL_DEFERRED,

  PTHREAD_CANCEL_ASYNCHRONOUS,

};



static int pthread_kill(pthread_t thread,int sig);
static int pthread_cancel(pthread_t thread);
static int pthread_setcancelstate(int state,int*oldstate);

static int pthread_setcanceltype(int type,int*oldtype);

static void pthread_testcancel(void);



static void pthread_cleanup_push(void(*routine)(void*),void*arg);
static void pthread_cleanup_pop(int execute);

static void pthread_cleanup_push_defer_np(void(*routine)(void*),void*arg);
static void pthread_cleanup_pop_restore_np(int execute);



static int pthread_atfork(void(*prepare)(void),void(*parent)(void),
       void(*child)(void));


static pthread_t pthread_self(void);

static int pthread_create(pthread_t*__threadarg,
  const pthread_attr_t*__attr,
  void*(*__start_routine)(void *),
  void*__arg);

static void pthread_exit(void*__retval) __attribute__((__noreturn__));

static int pthread_join(pthread_t __th,void**__thread_return);

static int pthread_detach(pthread_t __th);
static int pthread_equal(pthread_t __thread1,pthread_t __thread2);

static int pthread_sigmask(int how,const sigset_t*newset,sigset_t*oldset);


static int pthread_mutexattr_gettype(const pthread_mutexattr_t *__restrict__ attr, int *__restrict__ type);
static int pthread_mutexattr_settype(pthread_mutexattr_t *attr, int type);

typedef struct {
  unsigned int n;
} pthread_rwlock_t;

typedef struct {
  int dummy;
} pthread_rwlockattr_t;



static int pthread_rwlock_init(pthread_rwlock_t *rwlock, const pthread_rwlockattr_t *attr);
static int pthread_rwlock_destroy(pthread_rwlock_t *rwlock);

static int pthread_rwlock_rdlock(pthread_rwlock_t *rwlock);
static int pthread_rwlock_tryrdlock(pthread_rwlock_t *rwlock);
static int pthread_rwlock_wrlock(pthread_rwlock_t *rwlock);
static int pthread_rwlock_trywrlock(pthread_rwlock_t *rwlock);
static int pthread_rwlockattr_init(pthread_rwlockattr_t *attr);
static int pthread_rwlockattr_destroy(pthread_rwlockattr_t *attr);
static int pthread_rwlock_unlock(pthread_rwlock_t *rwlock);



struct __stdio_file {
  int fd;
  int flags;
  uint32_t bs;
  uint32_t bm;
  uint32_t buflen;
  char *buf;
  struct __stdio_file *next;
  pid_t popen_kludge;
  unsigned char ungetbuf;
  char ungotten;

  pthread_mutex_t m;

};



struct __stdio_file;
typedef struct __stdio_file FILE;

static FILE *stdin, *stdout, *stderr;

static FILE *fopen (const char *path, const char *mode) ;
static FILE *fdopen (int fildes, const char *mode) ;
static FILE *freopen (const char *path, const char *mode, FILE *stream) ;

static int printf(const char *format, ...)  __attribute__((__format__(__printf__,1,2)));
static int fprintf(FILE *stream, const char *format, ...)  __attribute__((__format__(__printf__,2,3)));
static int sprintf(char *str, const char *format, ...)  __attribute__((__format__(__printf__,2,3)));
static int snprintf(char *str, size_t size, const char *format, ...)  __attribute__((__format__(__printf__,3,4)));
static int asprintf(char **ptr, const char* format, ...)  __attribute__((__format__(__printf__,2,3)));

static int scanf(const char *format, ...)  __attribute__((__format__(__scanf__,1,2)));
static int fscanf(FILE *stream, const char *format, ...)  __attribute__((__format__(__scanf__,2,3)));
static int sscanf(const char *str, const char *format, ...)  __attribute__((__format__(__scanf__,2,3)));

static int vprintf(const char *format, va_list ap)  __attribute__((__format__(__printf__,1,0)));
static int vfprintf(FILE *stream, const char *format, va_list ap)  __attribute__((__format__(__printf__,2,0)));
static int vsprintf(char *str, const char *format, va_list ap)  __attribute__((__format__(__printf__,2,0)));
static int vsnprintf(char *str, size_t size, const char *format, va_list ap)  __attribute__((__format__(__printf__,3,0)));

static int fdprintf(int fd, const char *format, ...)  __attribute__((__format__(__printf__,2,3)));
static int vfdprintf(int fd, const char *format, va_list ap)  __attribute__((__format__(__printf__,2,0)));

static int vscanf(const char *format, va_list ap)  __attribute__((__format__(__scanf__,1,0)));
static int vsscanf(const char *str, const char *format, va_list ap)  __attribute__((__format__(__scanf__,2,0)));
static int vfscanf(FILE *stream, const char *format, va_list ap)  __attribute__((__format__(__scanf__,2,0)));

static int fgetc(FILE *stream) ;
static int fgetc_unlocked(FILE *stream) ;
static char *fgets(char *s, int size, FILE *stream) ;
static char *fgets_unlocked(char *s, int size, FILE *stream) ;

static char *gets(char *s) ;
static int ungetc(int c, FILE *stream) ;
static int ungetc_unlocked(int c, FILE *stream) ;

static int fputc(int c, FILE *stream) ;
static int fputc_unlocked(int c, FILE *stream) ;
static int fputs(const char *s, FILE *stream) ;
static int fputs_unlocked(const char *s, FILE *stream) ;

static int getc(FILE *stream) ;
static int getchar(void) ;
static int putchar(int c) ;
static int putchar_unlocked(int c) ;
static int puts(const char *s) ;

static int fseek(FILE *stream, long offset, int whence) ;
static int fseek_unlocked(FILE *stream, long offset, int whence) ;
static long ftell(FILE *stream) ;
static long ftell_unlocked(FILE *stream) ;
static int fseeko(FILE *stream, off_t offset, int whence) ;
static int fseeko_unlocked(FILE *stream, off_t offset, int whence) ;
static off_t ftello(FILE *stream) ;
static off_t ftello_unlocked(FILE *stream) ;


static int fseeko64(FILE *stream, loff_t offset, int whence) ;
static int fseeko64_unlocked(FILE *stream, loff_t offset, int whence) ;
static loff_t ftello64(FILE *stream) ;
static loff_t ftello64_unlocked(FILE *stream) ;
static void rewind(FILE *stream) ;
static int fgetpos(FILE *stream, fpos_t *pos) ;
static int fsetpos(FILE *stream, fpos_t *pos) ;

static size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream) ;
static size_t fread_unlocked(void *ptr, size_t size, size_t nmemb, FILE *stream) ;

static size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream) ;
static size_t fwrite_unlocked(const void *ptr, size_t size, size_t nmemb, FILE *stream) ;

static int fflush(FILE *stream) ;
static int fflush_unlocked(FILE *stream) ;

static int fclose(FILE *stream) ;
static int fclose_unlocked(FILE *stream) ;

static int feof(FILE *stream) ;
static int feof_unlocked(FILE *stream) ;
static int ferror(FILE *stream) ;
static int ferror_unlocked(FILE *stream) ;
static int fileno(FILE *stream) ;
static int fileno_unlocked(FILE *stream) ;
static void clearerr(FILE *stream) ;
static void clearerr_unlocked(FILE *stream) ;

static int remove(const char *pathname) ;
static int rename(const char *oldpath, const char *newpath) ;

static void perror(const char *s) ;
static int setvbuf(FILE *stream, char *buf, int mode , size_t size) ;
static int setvbuf_unlocked(FILE *stream, char *buf, int mode , size_t size) ;
static FILE *popen(const char *command, const char *type) ;
static int pclose(FILE *stream) ;
static char* tmpnam(char *s) ;
static char* tempnam(char* dir,char* _template);
static FILE* tmpfile(void) ;
static FILE* tmpfile_unlocked(void) ;
static char* ctermid(char* s);

static void flockfile(FILE* f) ;
static void funlockfile(FILE* f) ;
static int ftrylockfile (FILE *__stream) ;


static int vasprintf(char **strp, const char *fmt, va_list ap) ;
static ssize_t getline(char **lineptr, size_t *n, FILE *stream) ;
static ssize_t getdelim(char **lineptr, size_t *n, int delim, FILE *stream) ;





static int symlinkat(const char *oldpath, int newdirfd, const char *newpath);
static int renameat(int olddirfd, const char *oldpath, int newdirfd, const char *newpath) ;








static int __fflush4(FILE *stream,int next);
static int __buffered_outs(const char *s,size_t len);


struct arg_scanf {
  void *data;
  int (*getch)(void*);
  int (*putch)(int,void*);
};

static int __v_scanf(struct arg_scanf* fn, const char *format, va_list arg_ptr);

struct arg_printf {
  void *data;
  int (*put)(const void*,size_t,void*);
};

static int __v_printf(struct arg_printf* fn, const char *format, va_list arg_ptr);

static FILE *__stdio_root;

static int __fflush_stdin(void);
static int __fflush_stdout(void);
static int __fflush_stderr(void);

static FILE* __stdio_init_file(int fd,int closeonerror,int mode);
static int __stdio_parse_mode(const char *mode) __attribute__((__pure__));
static void __stdio_flushall(void);


static int __libc_close(int fd);
static int __libc_open(const char*fn,int flags,...);
static ssize_t __libc_read(int fd,void*buf,size_t len);
static ssize_t __libc_write(int fd,const void*buf,size_t len);


static FILE *fopen_unlocked(const char *path, const char *mode) 
                                                        
                                                               ;
static FILE *fdopen_unlocked(int fildes, const char *mode) 
                                                   
                                                          ;
static FILE *freopen_unlocked(const char *path, const char *mode, FILE *stream) 
                                                                        
                                                                               ;

static int __stdout_is_tty(void);
static int __stdin_is_tty(void);



static inline unsigned long skip_to(const char *format) {
  unsigned long nr;
  for (nr=0; format[nr] && (format[nr]!='%'); ++nr);
  return nr;
}




static const char pad_line[2][16]= { "                ", "0000000000000000", };
static int write_pad(unsigned int* dlen,struct arg_printf* fn, unsigned int len, int padwith) {
  int nr=0;
  if ((int)len<=0) return 0;
  if(*dlen+len<len) return -1;
  for (;len>15;len-=16,nr+=16) {
    ((fn)->put((void*)(pad_line[(padwith=='0')?1:0]),(16),(fn)->data));
  }
  if (len>0) {
    ((fn)->put((void*)(pad_line[(padwith=='0')?1:0]),((unsigned int)len),(fn)->data)); nr+=len;
  }
  *dlen += nr;
  return 0;
}

static int __v_printf(struct arg_printf* fn, const char *format, va_list arg_ptr)
{
  unsigned int len=0;




  while (*format) {
    unsigned long sz = skip_to(format);
    if (sz) {
      { if ((unsigned long)(sz) > (((unsigned long)(int)(-1))>>1) || len+(int)(sz)<len) return -1; ((fn)->put((void*)(format),(sz),(fn)->data)); } while (0);
      len+=sz;
      format+=sz;
    }
    if (*format=='%') {
      char buf[128];
      union { char*s; } u_str;


      int retval;
      unsigned char ch, padwith=' ', precpadwith=' ';

      char flag_in_sign=0;
      char flag_upcase=0;
      char flag_hash=0;
      char flag_left=0;
      char flag_space=0;
      char flag_sign=0;
      char flag_dot=0;
      signed char flag_long=0;

      unsigned int base;
      unsigned int width=0, preci=0;

      long number=0;

      long long llnumber=0;


      ++format;
inn_printf:
      switch(ch=*format++) {
      case 0:
 return -1;
 break;


      case '#':
 flag_hash=-1;


      case 'h':
 --flag_long;
 goto inn_printf;

      case 'j':

      case 'q':
      case 'L':
 ++flag_long;

 __attribute__((fallthrough));





      case 'z':
      case 'l':
 ++flag_long;
 goto inn_printf;

      case '-':
 flag_left=1;
 goto inn_printf;

      case ' ':
 flag_space=1;
 goto inn_printf;

      case '+':
 flag_sign=1;
 goto inn_printf;

      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
 if(flag_dot) return -1;
 width=strtoul(format-1,(char**)&u_str.s,10);
 if (width>10*1024) return -1;
 if (ch=='0' && !flag_left) padwith='0';
 format=u_str.s;
 goto inn_printf;

      case '*':
 {



   int tmp;
   if ((tmp=
           __builtin_va_arg
                 (arg_ptr,int))<0) {
     flag_left=1;
     tmp=-tmp;
   }
   if ((width=(unsigned long)tmp)>10*1024) return -1;
   goto inn_printf;
 }

      case '.':
 flag_dot=1;
 if (*format=='*') {
   int tmp=
          __builtin_va_arg
                (arg_ptr,int);
   preci=tmp<0?0:tmp;
   ++format;
 } else {
   long int tmp=strtol(format,(char**)&u_str.s,10);
   preci=tmp<0?0:tmp;
   format=u_str.s;
 }
 if (preci>10*1024) return -1;
 goto inn_printf;


      case 'c':
 ch=(char)
         __builtin_va_arg
               (arg_ptr,int);

      case '%':
 { if ((unsigned long)(1) > (((unsigned long)(int)(-1))>>1) || len+(int)(1)<len) return -1; ((fn)->put((void*)(&ch),(1),(fn)->data)); } while (0);
 ++len;
 break;
      case 's':
 u_str.s=
  __builtin_va_arg
        (arg_ptr,char *);

 if (!u_str.s) u_str.s="(null)";

 sz = strlen(u_str.s);
 if (flag_dot && sz>preci) sz=preci;
 preci=0;
 flag_dot^=flag_dot;
 padwith=precpadwith=' ';

print_out:
      {
 char *sign=u_str.s;
 int todo=0;
 int vs;

 if (! (width||preci) ) {
   { if ((unsigned long)(sz) > (((unsigned long)(int)(-1))>>1) || len+(int)(sz)<len) return -1; ((fn)->put((void*)(u_str.s),(sz),(fn)->data)); } while (0);
   len+=sz;
   break;
 }

 if (flag_in_sign) todo=1;
 if (flag_hash>0) todo=flag_hash;
 if (todo) {
   u_str.s+=todo;
   sz-=todo;
   width-=todo;
 }
 if (flag_dot && width==0) width=preci;
 if (!flag_dot) preci=sz;
 if (!flag_left && padwith==' ') {
   if (write_pad(&len,fn,width-preci,padwith))
     return -1;
 }
 if (todo) {
   { if ((unsigned long)(todo) > (((unsigned long)(int)(-1))>>1) || len+(int)(todo)<len) return -1; ((fn)->put((void*)(sign),(todo),(fn)->data)); } while (0);
   len+=todo;
 }
 if (!flag_left && padwith!=' ') {
   if (write_pad(&len,fn,width-preci,padwith))
     return -1;
 }

 if (write_pad(&len,fn,preci-sz,precpadwith))
   return -1;

 { if ((unsigned long)(sz) > (((unsigned long)(int)(-1))>>1) || len+(int)(sz)<len) return -1; ((fn)->put((void*)(u_str.s),(sz),(fn)->data)); } while (0);
 len+=sz;
 if (flag_left) {
   if (write_pad(&len,fn,width-preci,padwith))
     return -1;
 }

 break;
      }


      case 'b':
 base=2;
 sz=0;
 goto num_printf;
      case 'p':
 flag_hash=2;
 flag_long=1;
 ch='x';

      case 'X':
 flag_upcase=(ch=='X');

      case 'x':
 base=16;
 sz=0;
 if (flag_hash) {
   buf[1]='0';
   buf[2]=ch;
   flag_hash=2;
   sz=2;
 }
 if (preci>width) width=preci;
 goto num_printf;
      case 'd':
      case 'i':
 flag_in_sign=1;

      case 'u':
 base=10;
 sz=0;
 goto num_printf;
      case 'o':
 base=8;
 sz=0;
 if (flag_hash) {
   buf[1]='0';
   flag_hash=1;
   ++sz;
 }

num_printf:
 u_str.s=buf+1;

 if (flag_long>0) {

   if (flag_long>1)
     llnumber=
             __builtin_va_arg
                   (arg_ptr,long long);
   else

     number=
           __builtin_va_arg
                 (arg_ptr,long);
 }
 else {
   number=
         __builtin_va_arg
               (arg_ptr,int);
   if (sizeof(int) != sizeof(long) && !flag_in_sign)
     number&=((unsigned int)-1);
 }

 if (flag_in_sign) {

   if ((flag_long>1)&&(llnumber<0)) {
     llnumber=-llnumber;
     flag_in_sign=2;
   } else

     if (number<0) {
       number=-number;
       flag_in_sign=2;
     }
 }
 if (flag_long<0) number&=0xffff;
 if (flag_long<-1) number&=0xff;

 if (flag_long>1)
   retval = __lltostr(u_str.s+sz,sizeof(buf)-5,(unsigned long long) llnumber,base,flag_upcase);
 else

   retval = __ltostr(u_str.s+sz,sizeof(buf)-5,(unsigned long) number,base,flag_upcase);


 if (flag_dot && retval == 1 && u_str.s[sz] == '0') {
   if (preci == 0||flag_hash > 0) {
     sz = 0;
   }
   flag_hash = 0;
 } else sz += retval;

 if (flag_in_sign==2) {
   *(--u_str.s)='-';
   ++sz;
 } else if ((flag_in_sign)&&(flag_sign || flag_space)) {
   *(--u_str.s)=(flag_sign)?'+':' ';
   ++sz;
 } else flag_in_sign=0;

 precpadwith='0';

 goto print_out;



      case 'f':
      case 'F':
      case 'g':
      case 'G':
 {
   int flags=(((ch&0x5f)=='G') ? 0x01 : 0x00) | ((ch&0x20) ? 0x00 : 0x02);
   double d=
           __builtin_va_arg
                 (arg_ptr,double);
   u_str.s=buf+1;
   if (width==0) width=1;
   if (!flag_dot) preci=6;
   if (flag_sign || d < +0.0) flag_in_sign=1;

   sz=__dtostr(d,u_str.s,sizeof(buf)-1,width,preci,flags);

   if (!isnan(d) && !isinf(d)) {
     if (flag_dot) {
       char *tmp;
       if ((tmp=strchr(u_str.s,'.'))) {
  if (preci || flag_hash) ++tmp;
  while (preci>0 && *++tmp) --preci;
  *tmp=0;
       } else if (flag_hash) {
  u_str.s[sz]='.';
  u_str.s[++sz]='\0';
       }
     }

     if ((flags&0x01)) {
       char *tmp,*tmp1;
       if ((tmp=strchr(u_str.s,'.'))) {
  tmp1=strchr(tmp,'e');
  while (*tmp) ++tmp;
  if (tmp1) tmp=tmp1;
  while (*--tmp=='0') ;
  if (*tmp!='.' || flag_hash) ++tmp;
  *tmp=0;
  if (tmp1) strcpy(tmp,tmp1);
       }
     }

     if ((flag_sign || flag_space) && d>=0) {
       *(--u_str.s)=(flag_sign)?'+':' ';
       ++sz;
     }
   }

   sz=strlen(u_str.s);
   if (width<sz) width=sz;
   precpadwith='0';
   flag_dot=0;
   flag_hash=0;
   goto print_out;
 }


      default:
 break;
      }
    }
  }
  return len;
}



asm (".section .gnu.warning." "__v_printf" "\n\t.string \"" "warning: the printf functions add several kilobytes of bloat." "\"\n\t.previous");











static int isascii (int c)  ;
static int isblank (int c)  ;
static int isalnum (int c)  ;
static int isalpha (int c)  ;
static int isdigit (int c)  ;
static int isspace (int c)  ;

static int isupper (int c)  ;
static int islower (int c)  ;

static int toascii(int c)  ;
static int tolower(int c)  ;
static int toupper(int c)  ;

static int isprint(int c)  ;
static int ispunct(int c)  ;
static int iscntrl(int c)  ;


static int isxdigit(int c)  ;

static int isgraph(int c)  ;











static int __v_scanf(struct arg_scanf* fn, const char *format, va_list arg_ptr)
{
  unsigned int ch;
  int n=0;



  double *pd;
  float *pf;


  long long *pll;

  long *pl;
  short *ph;
  int *pi;
  char *s;

  unsigned int consumed=0;


  int tpch= (++consumed,(fn)->getch((fn)->data));


  while (*format)
  {
    ch=*format++;
    switch (ch) {

    case 0: return 0;


    case ' ':
    case '\f':
    case '\t':
    case '\v':
    case '\n':
    case '\r':
      while((*format)&&(isspace(*format))) ++format;
      while(isspace(tpch)) tpch=(++consumed,(fn)->getch((fn)->data));
      break;


    case '%':
      {
 unsigned int _div=0;
 int width=-1;
 char flag_width=0;
 char flag_discard=0;
 char flag_half=0;
 char flag_long=0;
 char flag_longlong=0;

in_scan:
 ch=*format++;
 if(ch!='n' && tpch==-1) goto err_out;
 switch (ch) {

 case 0: return 0;


 case '%':
   if ((unsigned char)tpch != ch) goto err_out;
   tpch=(++consumed,(fn)->getch((fn)->data));
   break;


 case '*':
   flag_discard=1;
   goto in_scan;
 case 'h':
   flag_half=1;
   goto in_scan;
 case 'l':
   if (flag_long) flag_longlong=1;
   flag_long=1;
   goto in_scan;
 case 'q':
 case 'L':
   flag_longlong=1;
   goto in_scan;


 case '0':
 case '1':
 case '2':
 case '3':
 case '4':
 case '5':
 case '6':
 case '7':
 case '8':
 case '9':
   width=strtol(format-1,&s,10);
   format=s;
   flag_width=1;
   goto in_scan;


 case 'p':
 case 'X':
 case 'x':
   _div+=6;

 case 'd':
   _div+=2;

 case 'o':
   _div+=8;

 case 'u':
 case 'i':
   {

     unsigned long long v=0;



     unsigned int consumedsofar;
     int neg=0;
     while(isspace(tpch)) tpch=(++consumed,(fn)->getch((fn)->data));
     if (tpch=='-') {
       tpch=(++consumed,(fn)->getch((fn)->data));
       neg=1;
     }

     if (tpch=='+') tpch=(++consumed,(fn)->getch((fn)->data));

     if (tpch==-1) return n;
     consumedsofar=consumed;

     if (!flag_width) {
       if ((_div==16) && (tpch=='0')) goto scan_hex;
       if (!_div) {
  _div=10;
  if (tpch=='0') {
    _div=8;
scan_hex:
    tpch=(++consumed,(fn)->getch((fn)->data));
    if ((tpch|32)=='x') {
      tpch=(++consumed,(fn)->getch((fn)->data));
      _div=16;
    }
  }
       }
     }
     while ((width)&&(tpch!=-1)) {
       register unsigned long c=tpch&0xff;

       register unsigned long long d=c|0x20;



       c=(d>='a'?d-'a'+10:c<='9'?c-'0':0xff);
       if (c>=_div) break;
       d=v*_div;

       v=(d<v)?
              (~0ull)
                        :d+c;



       --width;
       tpch=(++consumed,(fn)->getch((fn)->data));
     }

     if (consumedsofar==consumed) return n;

     if ((ch|0x20)<'p') {

       register long long l=v;
       if (v>=-((unsigned long long)
                                   (-1ll - 0x7fffffffffffffffll)
                                            )) {
  l=(neg)?
         (-1ll - 0x7fffffffffffffffll)
                  :
                   0x7fffffffffffffffll
                            ;
       }
       else {
  if (neg) v*=-1;
       }
     }
     if (!flag_discard) {

       if (flag_longlong) {
  pll=(long long *)
                  __builtin_va_arg
                        (arg_ptr,long long*);
  *pll=v;
       } else

       if (flag_long) {
  pl=(long *)
            __builtin_va_arg
                  (arg_ptr,long*);
  *pl=v;
       } else if (flag_half) {
  ph=(short*)
            __builtin_va_arg
                  (arg_ptr,short*);
  *ph=v;
       } else {
  pi=(int *)
           __builtin_va_arg
                 (arg_ptr,int*);
  *pi=v;
       }
       if(consumedsofar<consumed) ++n;
     }
   }
   break;




 case 'e':
 case 'E':
 case 'f':
 case 'g':
   {
     double d=0.0;
     int neg=0;
     unsigned int consumedsofar;

     while(isspace(tpch)) tpch=(++consumed,(fn)->getch((fn)->data));

     if (tpch=='-') {
       tpch=(++consumed,(fn)->getch((fn)->data));
       neg=1;
     }
     if (tpch=='+') tpch=(++consumed,(fn)->getch((fn)->data));

     consumedsofar=consumed;

     while (isdigit(tpch)) {
       d=d*10+(tpch-'0');
       tpch=(++consumed,(fn)->getch((fn)->data));
     }
     if (tpch=='.') {
       double factor=.1;
       consumedsofar++;
       tpch=(++consumed,(fn)->getch((fn)->data));
       while (isdigit(tpch)) {
  d=d+(factor*(tpch-'0'));
  factor/=10;
  tpch=(++consumed,(fn)->getch((fn)->data));
       }
     }
     if (consumedsofar==consumed) return n;
     if ((tpch|0x20)=='e') {
       int exp=0, prec=tpch;
       double factor=10;
       tpch=(++consumed,(fn)->getch((fn)->data));
       if (tpch=='-') {
  factor=0.1;
  tpch=(++consumed,(fn)->getch((fn)->data));
       } else if (tpch=='+') {
  tpch=(++consumed,(fn)->getch((fn)->data));
       } else {
  d=0;
  if (tpch!=-1) (--consumed,(fn)->putch((tpch),(fn)->data));
  tpch=prec;
  goto exp_out;
       }
       consumedsofar=consumed;
       while (isdigit(tpch)) {
  exp=exp*10+(tpch-'0');
  tpch=(++consumed,(fn)->getch((fn)->data));
       }
       if (consumedsofar==consumed) return n;
       while (exp) {
  d*=factor; --exp;
       }
     }
exp_out:
     if (neg) d = -d;
     if (!flag_discard) {
       if (flag_long) {
  pd=(double *)
              __builtin_va_arg
                    (arg_ptr,double*);
  *pd=d;
       } else {
  pf=(float *)
             __builtin_va_arg
                   (arg_ptr,float*);
  *pf=d;
       }
       ++n;
     }
   }
   break;



 case 'c':
   if (!flag_discard) {
     s=(char *)
              __builtin_va_arg
                    (arg_ptr,char*);
     ++n;
   }
   if (!flag_width) width=1;
   while (width && (tpch!=-1)) {
     if (!flag_discard) *(s++)=tpch;
     --width;
     tpch=(++consumed,(fn)->getch((fn)->data));
   }
   break;


 case 's':
   if (!flag_discard) s=(char *)
                               __builtin_va_arg
                                     (arg_ptr,char*);
   while(isspace(tpch)) tpch=(++consumed,(fn)->getch((fn)->data));
   if (tpch==-1) break;
   while (width && (tpch!=-1) && (!isspace(tpch))) {
     if (!flag_discard) *s=tpch;
     if (tpch) ++s; else break;
     --width;
     tpch=(++consumed,(fn)->getch((fn)->data));
   }
   if (!flag_discard) { *s=0; ++n; }
   break;


 case 'n':
   if (!flag_discard) {
     pi=(int *)
              __builtin_va_arg
                    (arg_ptr,int *);

            *pi=consumed-1;
   }
   break;


 case '[':
   {
     char cset[256];
     int flag_not=0;
     int flag_dash=0;
     int matched=0;
     memset(cset,0,sizeof(cset));
     ch=*format++;

     if (ch=='^') {
       flag_not=1;
       ch=*format++;
     }
     if ((ch=='-')||(ch==']')) {
       cset[ch]=1;
       ch=*format++;
     }

     for (;(*format) && (*format!=']');++format) {
       if (flag_dash) {
  register unsigned char tmp=*format;
  for (;ch<=tmp;++ch) cset[ch]=1;
  flag_dash=0;
  ch=*format;
       }
       else if (*format=='-') flag_dash=1;
       else {
  cset[ch]=1;
  ch=*format;
       }
     }

     if (flag_dash) cset['-']=1;
     else cset[ch]=1;


     if (!flag_discard)
       s=(char *)
                __builtin_va_arg
                      (arg_ptr,char*);
     while (width && (tpch>=0) && (cset[tpch]^flag_not)) {
       if (!flag_discard) *s=tpch;
       if (tpch) ++s; else break;
       --width;
       tpch=(++consumed,(fn)->getch((fn)->data));
       matched=1;
     }
     if (!flag_discard) *s=0;
     ++format;
     if (matched && !flag_discard)
       ++n;
   }
   break;

 default:
   goto err_out;
 }
      }
      break;


    default:
      if ((unsigned char)tpch != ch) goto err_out;
      tpch=(++consumed,(fn)->getch((fn)->data));
      break;
    }
  }


  if(*format) {
    while(isspace(*format)) format++;
    if(format[0] == '%' && format[1] == 'n') {
      pi = (int *) 
                  __builtin_va_arg
                        (arg_ptr, int *);
      *pi = consumed - 1;
    }
  }

err_out:
  if (tpch<0 && n==0) return 
                            (-1)
                               ;
  (--consumed,(fn)->putch((tpch),(fn)->data));
  return n;
}

asm (".section .gnu.warning." "__v_scanf" "\n\t.string \"" "warning: the scanf functions add several kilobytes of bloat." "\"\n\t.previous");;
static int __valgrind=0;


static void* __diet_brk(void *end_data_segment);

static void* __curbrk=0;

static int __libc_brk(void *end_data_segment);

static int __libc_brk(void *end_data_segment) {
  return ((__curbrk=__diet_brk(end_data_segment))==(void*)-1?-1:0);
}

static int brk(void *end_data_segment) __attribute__((alias("__libc_brk")));













struct rusage {
  struct timeval ru_utime;
  struct timeval ru_stime;
  long ru_maxrss;
  long ru_ixrss;
  long ru_idrss;
  long ru_isrss;
  long ru_minflt;
  long ru_majflt;
  long ru_nswap;
  long ru_inblock;
  long ru_oublock;
  long ru_msgsnd;
  long ru_msgrcv;
  long ru_nsignals;
  long ru_nvcsw;
  long ru_nivcsw;
};

struct rlimit {
  unsigned long rlim_cur;
  unsigned long rlim_max;
};
static int getpriority(int which, int who) ;
static int setpriority(int which, int who, int prio) ;

static int getrlimit (int resource, struct rlimit *rlim);
static int getrusage (int who, struct rusage *usage);
static int setrlimit (int resource, const struct rlimit *rlim);

typedef unsigned long rlim_t;




static int __syscall_getpriority(int which, int who);

static int getpriority(int which, int who) {
  int r;

  r = __syscall_getpriority(which, who);
  if (r >= 0) r = 20 - r;
  return r;
}







static void __stdio_flushall(void) ;
static void __stdio_flushall(void) { }




static void abort() {
  sigset_t t;
  __stdio_flushall();
  if (!sigemptyset(&t) && !sigaddset(&t, 
                                        6
                                               ))
    sigprocmask(
               2
                          , &t, 0);
  while (1)
    if (raise(
             6
                    ))
      exit(127);
}



int abs(int i) { return i>=0?i:-i; }

static long labs(long i) __attribute__((alias("abs")));




static int socketcall(int callno,long* args);

static int __libc_accept(int a, void * addr, void * addr2);

static int __libc_accept(int a, void * addr, void * addr2) {
  long args[] = { a, (long) addr, (long) addr2 };
  return socketcall(5, args);
}

static int accept(int a, void * addr, void * addr2) __attribute__((alias("__libc_accept")));












struct timex {
  uint32_t modes;
  long int offset;
  long int freq;
  long int maxerror;
  long int esterror;
  int32_t status;
  long int constant;
  long int precision;
  long int tolerance;
  struct timeval time;
  long int tick;

  long int ppsfreq;
  long int jitter;
  int32_t shift;
  long int stabil;
  long int jitcnt;
  long int calcnt;
  long int errcnt;
  long int stbcnt;


  int32_t :32; int32_t :32; int32_t :32; int32_t :32;
  int32_t :32; int32_t :32; int32_t :32; int32_t :32;
  int32_t :32; int32_t :32; int32_t :32; int32_t :32;
};
static int adjtimex(struct timex *buf);




static int adjtime (const struct timeval *itv, struct timeval *otv) {
  struct timex tmp;
  if (itv) {
    tmp.offset = (itv->tv_usec % 1000000L) + (itv->tv_sec + itv->tv_usec / 1000000L) * 1000000L;
    tmp.modes = 
               0x8001
                                    ;
  } else
    tmp.modes = 0;
  if (adjtimex(&tmp)==-1)
    return -1;
  if (otv) {
    otv->tv_usec = tmp.offset % 1000000;
    otv->tv_sec = tmp.offset / 1000000;
  }
  return 0;
}











struct ipc_perm {
  key_t key;
  uid_t uid;
  gid_t gid;
  uid_t cuid;
  gid_t cgid;
  mode_t mode;
  uint16_t seq;
};


static key_t ftok(const char *pathname, int proj_id);











struct shmid_ds {
  struct ipc_perm shm_perm;
  int32_t shm_segsz;
  time_t shm_atime;
  time_t shm_dtime;
  time_t shm_ctime;
  pid_t shm_cpid;
  pid_t shm_lpid;
  uint16_t shm_nattch;
  uint16_t shm_unused;
  void *shm_unused2;
  void *shm_unused3;
};
struct shminfo {
  int32_t shmmax;
  int32_t shmmin;
  int32_t shmmni;
  int32_t shmseg;
  int32_t shmall;
};

struct shm_info {
  int32_t used_ids;
  unsigned long shm_tot;
  unsigned long shm_rss;
  unsigned long shm_swp;
  unsigned long swap_attempts;
  unsigned long swap_successes;
};
static int shmget(key_t key, int size, int shmflg) ;
static void *shmat(int shmid, const void *shmaddr, int shmflg) ;
static int shmdt (const void *shmaddr) ;
static int shmctl(int shmid, int cmd, struct shmid_ds *buf) ;



typedef struct {
  void* next;
  size_t size;
} __alloc_t;
static void *do_mmap(size_t size) {
  return mmap(0, size, 
                      0x1
                               |
                                0x2
                                          , 
                                            0x0800
                                                         |
                                                          0x02
                                                                     , -1, (size_t)0);
}



static __alloc_t* __small_mem[8];
static inline int __ind_shift() { return (
                                         4096UL
                                                       ==4096)?4:5; }

static size_t get_index(size_t _size) {
  register size_t idx=0;

    register size_t size=((_size-1)&(
                                    4096UL
                                                  -1))>>__ind_shift();
    while(size) { size>>=1; ++idx; }

  return idx;
}


static void __small_free(void*_ptr,size_t _size) ;

static void __small_free(void*_ptr,size_t _size) {
  __alloc_t* ptr=(((void*)(_ptr))-sizeof(__alloc_t));
  size_t size=_size;
  size_t idx=get_index(size);




  memset(ptr,0,size);


  ptr->next=__small_mem[idx];
  __small_mem[idx]=ptr;
}

static void* __small_malloc(size_t _size) {
  __alloc_t *ptr;
  size_t size=_size;
  size_t idx;

  idx=get_index(size);
  ptr=__small_mem[idx];

  if (ptr==0) {
    register int i,nr;
    ptr=do_mmap(
               4096UL
                             );
    if (ptr==
            ((void *) -1)
                      ) return 
                               ((void *) -1)
                                         ;

    __small_mem[idx]=ptr;

    nr=(
      4096UL
      /(size))-1;
    for (i=0;i<nr;i++) {
      ptr->next=(((void*)ptr)+size);
      ptr=ptr->next;
    }
    ptr->next=0;

    ptr=__small_mem[idx];
  }


  __small_mem[idx]=ptr->next;
  ptr->next=0;

  return ptr;
}



static void _alloc_libc_free(void *ptr) {
  register size_t size;
  if (ptr) {
    size=((__alloc_t*)(((void*)(ptr))-sizeof(__alloc_t)))->size;
    if (size) {
      if (size<=(
               4096UL
               /(2)))
 __small_free(ptr,size);
      else
 munmap((((void*)(ptr))-sizeof(__alloc_t)),size);
    }
  }
}
static void __libc_free(void *ptr) __attribute__((alias("_alloc_libc_free")));
static void free(void *ptr) __attribute__((alias("_alloc_libc_free")));





static void* _alloc_libc_malloc(size_t size) {
  __alloc_t* ptr;
  size_t need;



  if (!size) goto err_out;

  size+=sizeof(__alloc_t);
  if (size<sizeof(__alloc_t)) goto err_out;
  if (size<=(
           4096UL
           /(2))) {
    need=((
        4096UL
        /(256))<<get_index((size)));
    ptr=__small_malloc(need);
  }
  else {
    need=(((size)+
        4096UL
        -1)&(unsigned long)(~(
        4096UL
        -1)));
    if (!need) ptr=
                  ((void *) -1)
                            ; else ptr=do_mmap(need);
  }
  if (ptr==
          ((void *) -1)
                    ) goto err_out;
  ptr->size=need;
  return (((void*)(ptr))+sizeof(__alloc_t));
err_out:
  (*__errno_location())=
                       12
                             ;
  return 0;
}
static void* __libc_malloc(size_t size) __attribute__((alias("_alloc_libc_malloc")));
static void* malloc(size_t size) __attribute__((alias("_alloc_libc_malloc")));

static void* __libc_calloc(size_t nmemb, size_t _size);
static void* __libc_calloc(size_t nmemb, size_t _size) {
  size_t size;

  if (__builtin_mul_overflow(_size,nmemb,&size)) {
    (*__errno_location())=
                         12
                               ;
    return 0;
  }
  return malloc(size);
}
static void* calloc(size_t nmemb, size_t _size) __attribute__((alias("__libc_calloc")));

static void* __libc_realloc(void* ptr, size_t _size);
static void* __libc_realloc(void* ptr, size_t _size) {
  register size_t size=_size;
  if (ptr) {
    if (size) {
      __alloc_t* tmp=(((void*)(ptr))-sizeof(__alloc_t));
      size+=sizeof(__alloc_t);
      if (size<sizeof(__alloc_t)) goto retzero;
      size=(size<=(
                 4096UL
                 /(2)))?((
                                   4096UL
                                   /(256))<<get_index((size))):(((size)+
                                                  4096UL
                                                  -1)&(unsigned long)(~(
                                                  4096UL
                                                  -1)));
      if (tmp->size!=size) {
 if ((tmp->size<=(
                4096UL
                /(2)))) {
   void *new=_alloc_libc_malloc(_size);
   if (new) {
     register __alloc_t* foo=(((void*)(new))-sizeof(__alloc_t));
     size=foo->size;
     if (size>tmp->size) size=tmp->size;
     if (size) memcpy(new,ptr,size-sizeof(__alloc_t));
     _alloc_libc_free(ptr);
   }
   ptr=new;
 }
 else {
   register __alloc_t* foo;
   size=(((size)+
       4096UL
       -1)&(unsigned long)(~(
       4096UL
       -1)));
   foo=mremap(tmp,tmp->size,size,
                                1UL
                                              );
   if (foo==
           ((void *) -1)
                     ) {
retzero:
     (*__errno_location())=
                          12
                                ;
     ptr=0;
   }
   else {
     foo->size=size;
     ptr=(((void*)(foo))+sizeof(__alloc_t));
   }
 }
      }
    }
    else {
      _alloc_libc_free(ptr);
      ptr = 
           (void*)0
               ;
    }
  }
  else {
    if (size) {
      ptr=_alloc_libc_malloc(size);
    }
  }
  return ptr;
}
static void* realloc(void* ptr, size_t size) __attribute__((alias("__libc_realloc")));












enum {
  GRND_NONBLOCK=1,

  GRND_RANDOM=2

};

static int getrandom(void* buf, size_t buflen, unsigned int flags) ;
static int getentropy(void* buf,size_t buflen) ;







static uint32_t buf[256];
static unsigned int n;


static uint32_t arc4random(void) {
  if (n==0) arc4random_stir();
  uint32_t r=buf[n];
  if (++n > sizeof(buf)/sizeof(buf[0])) n=0;
  return r;
}

static void arc4random_buf(void* Buf, size_t N) {
  int r;
  if ((size_t)(r=getrandom(Buf,N,
                                GRND_NONBLOCK
                                             )) != N) {
    if (r==-1 && 
                (*__errno_location())
                     ==
                       89
                             ) {
      int fd=open("/dev/urandom",
                                0x0000
                                        );
      if (fd==-1) abort();
      r=read(fd,Buf,N);
      close(fd);
    }
    if ((size_t)r != N)
      abort();
  }
}

static uint32_t arc4random_uniform(uint32_t upper_bound) {
  uint32_t r, min;

  if (upper_bound < 2)
    return 0;


  min = -upper_bound % upper_bound;







  for (;;) {
    r = arc4random();
    if (r >= min)
      break;
  }

  return r % upper_bound;
}

static void arc4random_stir(void) {
  n=0;
  arc4random_buf(buf,sizeof(buf));
}

static void arc4random_addrandom(unsigned char* dat,size_t datlen) {
}










static ssize_t __write1 ( const char* s ) __attribute__ (( ));
static ssize_t __write2 ( const char* s ) __attribute__ (( ));




static void __assert_fail (const char *assertion, const char *file, unsigned int line, const char *function);

static void __assert_fail (const char *assertion, const char *file, unsigned int line, const char *function)
{
  unsigned int alen=strlen(assertion);
  unsigned int flen=strlen(file);
  unsigned int fulen=function?strlen(function):0;
  char *buf=(char*)
                  __builtin_alloca(
                  alen+flen+fulen+50
                  )
                                            ;
  if (buf) {
    char *tmp;
    *buf=0;
    if (file) strcat(strcat(buf,file),":");
    tmp=buf+strlen(buf);
    __ltostr(tmp,10,line,10,0);
    strcat(buf,": ");
    if (function) strcat(strcat(buf,function),": ");
    strcat(buf,"Assertion `");
    strcat(buf,assertion);
    strcat(buf,"' failed.\n");
    __write2(buf);
  }
  abort();
}

asm (".section .gnu.warning." "__assert_fail" "\n\t.string \"" "warning: your code still has assertions enabled!" "\"\n\t.previous");



typedef void (*function)(void);



static function __atexitlist[32];
static int atexit_counter;

static int atexit(function t) {
  if (atexit_counter<32) {
    __atexitlist[atexit_counter]=t;
    ++atexit_counter;
    return 0;
  }
  return -1;
}

static void __thread_doexit(int doexit);

static void __libc_exit(int code);
static void __libc_exit(int code) {
  register int i=atexit_counter;
  __thread_doexit(code);
  while(i) {
    __atexitlist[--i]();
  }
  _exit(code);
}
static void exit(int code) __attribute__((alias("__libc_exit")));


static double atof(const char *nptr) {



  double tmp=strtod(nptr,0);
  return tmp;

}
static long int atol(const char* s) {
  long int v=0;
  int sign=0;
  while ( *s == ' ' || (unsigned int)(*s - 9) < 5u) ++s;
  switch (*s) {
  case '-': sign=-1;
  case '+': ++s;
  }
  while ((unsigned int) (*s - '0') < 10u) {
    v=v*10+*s-'0'; ++s;
  }
  return sign?-v:v;
}




static int atoi(const char* s) __attribute__((alias("atol")));






static long long int atoll(const char* s) {
  long long int v=0;
  int sign=1;
  while ( *s == ' ' || (unsigned int)(*s - 9) < 5u) ++s;
  switch (*s) {
  case '-': sign=-1;
  case '+': ++s;
  }
  while ((unsigned int) (*s - '0') < 10u) {
    v=v*10+*s-'0'; ++s;
  }
  return sign==-1?-v:v;
}




static int socketcall(int callno,long* args);

static int __libc_bind(int a, void * b, int c);
static int __libc_bind(int a, void * b, int c) {
  long args[] = { a, (long) b, c };
  return socketcall(2, args);
}

static int bind(int a, void * b, int c) __attribute__((alias("__libc_bind")));



static const char __binsh [8];

static const char __binsh [] = "/bin/sh";









static void __assert_fail (const char *__assertion, const char *__file,
      unsigned int __line, const char *__function)
      __attribute__ ((__noreturn__));




static void *bsearch(const void *key, const void *base, size_t nmemb, size_t size, int (*compar)(const void* , const void* )) {
  size_t m;
  while (
        __builtin_expect((long)((
        nmemb
        )),1)
                       ) {
    int tmp;
    void *p;
    m=nmemb/2;
    p=(void *) (((const char *) base) + (m * size));
    if ((tmp=(*compar)(key,p))<0) {
      nmemb=m;
    } else if (tmp>0) {
      base=p+size;
      nmemb-=m+1;
    } else
      return p;
  }
  return 0;
}




typedef unsigned int wint_t;



typedef int (*wctype_t)(wint_t);
struct tm;

typedef struct {
  int count;
  wchar_t sofar;
} mbstate_t;

static wint_t btowc(int);
static wint_t fgetwc(FILE *);
static wchar_t* fgetws(wchar_t *__restrict__, int, FILE *__restrict__);
static wint_t fputwc(wchar_t, FILE *);
static int fputws(const wchar_t *__restrict__, FILE *__restrict__);
static int fwide(FILE *, int);
static int fwprintf(FILE *__restrict__, const wchar_t *__restrict__, ...);
static int fwscanf(FILE *__restrict__, const wchar_t *__restrict__, ...);
static wint_t getwc(FILE *);
static wint_t getwchar(void);

static size_t mbrlen(const char *__restrict__, size_t, mbstate_t *__restrict__);
static size_t mbrtowc(wchar_t *__restrict__, const char *__restrict__, size_t, mbstate_t *__restrict__);
static int mbsinit(const mbstate_t *);
static size_t mbsrtowcs(wchar_t *__restrict__, const char **__restrict__, size_t, mbstate_t *__restrict__);
static wint_t putwc(wchar_t, FILE *);
static wint_t putwchar(wchar_t);
static int swprintf(wchar_t *__restrict__, size_t, const wchar_t *__restrict__, ...);
static int swscanf(const wchar_t *__restrict__, const wchar_t *__restrict__, ...);

static wint_t ungetwc(wint_t, FILE *);
static int vfwprintf(FILE *__restrict__, const wchar_t *__restrict__, va_list);
static int vfwscanf(FILE *__restrict__, const wchar_t *__restrict__, va_list);
static int vwprintf(const wchar_t *__restrict__, va_list);
static int vswprintf(wchar_t *__restrict__, size_t, const wchar_t *__restrict__, va_list);
static int vswscanf(const wchar_t *__restrict__, const wchar_t *__restrict__, va_list);
static int vwscanf(const wchar_t *__restrict__, va_list);
static size_t wcrtomb(char *__restrict__, wchar_t, mbstate_t *__restrict__);
static wchar_t *wcscat(wchar_t *__restrict__, const wchar_t *__restrict__);
static wchar_t *wcschr(const wchar_t *, wchar_t);
static int wcscmp(const wchar_t *, const wchar_t *);
static int wcscoll(const wchar_t *, const wchar_t *);
static wchar_t* wcscpy(wchar_t *__restrict__, const wchar_t *__restrict__);
static size_t wcscspn(const wchar_t *, const wchar_t *);
static size_t wcsftime(wchar_t *__restrict__, size_t, const wchar_t *__restrict__, const struct tm *__restrict__);
static size_t wcslen(const wchar_t *) ;
static wchar_t *wcsncat(wchar_t *__restrict__, const wchar_t *__restrict__, size_t);
static int wcsncmp(const wchar_t *, const wchar_t *, size_t);
static wchar_t *wcsncpy(wchar_t *__restrict__, const wchar_t *__restrict__, size_t);
static wchar_t *wcspbrk(const wchar_t *, const wchar_t *);
static wchar_t *wcsrchr(const wchar_t *, wchar_t);
static size_t wcsrtombs(char *__restrict__, const wchar_t **__restrict__, size_t, mbstate_t *__restrict__);
static size_t wcsspn(const wchar_t *, const wchar_t *);
static wchar_t *wcsstr(const wchar_t *__restrict__, const wchar_t *__restrict__);
static double wcstod(const wchar_t *__restrict__, wchar_t **__restrict__);
static float wcstof(const wchar_t *__restrict__, wchar_t **__restrict__);
static wchar_t *wcstok(wchar_t *__restrict__, const wchar_t *__restrict__, wchar_t **__restrict__);
static long wcstol(const wchar_t *__restrict__, wchar_t **__restrict__, int);
static long double wcstold(const wchar_t *__restrict__, wchar_t **__restrict__);
static long long wcstoll(const wchar_t *__restrict__, wchar_t **__restrict__, int);
static unsigned long wcstoul(const wchar_t *__restrict__, wchar_t **__restrict__, int);
static unsigned long long wcstoull(const wchar_t *__restrict__, wchar_t **__restrict__, int);

static size_t wcsxfrm(wchar_t *__restrict__, const wchar_t *__restrict__, size_t);
static int wctob(wint_t);

static wchar_t *wmemchr(const wchar_t *, wchar_t, size_t);
static int wmemcmp(const wchar_t *, const wchar_t *, size_t);
static wchar_t *wmemcpy(wchar_t *__restrict__, const wchar_t *__restrict__, size_t);
static wchar_t *wmemmove(wchar_t *, const wchar_t *, size_t);
static wchar_t *wmemset(wchar_t *, wchar_t, size_t);
static int wprintf(const wchar_t *__restrict__, ...);
static int wscanf(const wchar_t *__restrict__, ...);











static enum __encoding {
  CT_8BIT,
  CT_UTF8,
} lc_ctype;

static wint_t btowc(int c) {
  if (c==0) return 0;
  if (c==
        (-1)
           ) return 
                    0xffffffffu
                        ;
  switch (lc_ctype) {
  case CT_8BIT:
    return c>0xff?
                 0xffffffffu
                     :1;
  case CT_UTF8:
    return c>0x7f?
                 0xffffffffu
                     :1;
  }
  return 
        0xffffffffu
            ;
}







typedef struct __thrd_t {
  char* memstart;
  size_t memsize;
  pid_t tid;

  int (*func)(void*);
  void* arg;

  int res;



  int flags;
  int join_futex,join_wait_futex;
}* thrd_t;

enum {
  thrd_success = 0,
  thrd_timedout,
  thrd_busy,
  thrd_nomem,
  thrd_error
};

typedef int (*thrd_start_t)(void* arg);

static int thrd_create(thrd_t *thr, thrd_start_t func, void *arg);
static thrd_t thrd_current(void);
static int thrd_detach(thrd_t thr);
static int thrd_equal(thrd_t thr0, thrd_t thr1);
static void thrd_exit(int res);
static int thrd_join(thrd_t thr, int* res);
static int thrd_sleep(const struct timespec* time_point, struct timespec* remaining);
static void thrd_yield(void);

typedef struct __mtx_t {
  int lock, type;
  thrd_t owner;
} mtx_t;

enum {
  mtx_plain = 0,
  mtx_timed = 1,
  mtx_recursive = 2
};

static int mtx_init(mtx_t* mutex, int type);
static int mtx_lock(mtx_t* mutex);
static int mtx_timedlock(mtx_t *__restrict__ mutex, const struct timespec *__restrict__ time_point);
static int mtx_trylock(mtx_t* mutex);
static int mtx_unlock(mtx_t* mutex);
static void mtx_destroy(mtx_t* mutex);





typedef int once_flag;


static void call_once(once_flag* flag, void (*func)(void));

typedef struct __cnd_t {
  int sem;
} cnd_t;

static int cnd_init(cnd_t* cond);
static int cnd_signal(cnd_t *cond);
static int cnd_broadcast(cnd_t *cond);
static int cnd_wait(cnd_t* cond, mtx_t* mutex);
static int cnd_timedwait(cnd_t* __restrict__ cond, mtx_t* __restrict__ mutex, const struct timespec* __restrict__ time_point);
static void cnd_destroy(cnd_t* cond);



typedef void (*tss_dtor_t)(void*);
typedef struct __tss_t {
  void* data;
  tss_dtor_t dtor;
  struct __tss_t* next;
}* tss_t;


static int tss_create(tss_t* tss_id, tss_dtor_t destructor);
static void *tss_get(tss_t tss_id);
static int tss_set(tss_t tss_id, void *val);
static void tss_delete(tss_t tss_id);


static void call_once(once_flag* flag, void (*func)(void)) {
  if (__sync_bool_compare_and_swap(flag,0,1))
    func();
}









struct winsize {
  uint16_t ws_row;
  uint16_t ws_col;
  uint16_t ws_xpixel;
  uint16_t ws_ypixel;
};


struct termio {
  uint16_t c_iflag;
  uint16_t c_oflag;
  uint16_t c_cflag;
  uint16_t c_lflag;
  unsigned char c_line;
  unsigned char c_cc[8];
};
typedef unsigned char cc_t;
typedef uint32_t speed_t;
typedef uint32_t tcflag_t;
struct termios {
 tcflag_t c_iflag;
 tcflag_t c_oflag;
 tcflag_t c_cflag;
 tcflag_t c_lflag;



 cc_t c_line;
 cc_t c_cc[23];
};
static int tcgetattr(int fd, struct termios *termios_p) ;
static int tcsetattr(int fd, int optional_actions, struct termios *termios_p) ;
static speed_t cfgetospeed(const struct termios *termios_p) ;
static int cfsetospeed(struct termios *termios_p, speed_t speed) ;
static speed_t cfgetispeed(const struct termios *termios_p) ;
static int cfsetispeed(struct termios *termios_p, speed_t speed) ;
static void cfmakeraw(struct termios *t) ;

static int tcflush(int fd, int queue_selector) ;
static int tcdrain(int fd) ;
static int tcflow (int fd,int action) ;
static int tcsendbreak (int fd,int duration) ;
static pid_t tcgetsid(int fildes) ;





static speed_t cfgetospeed(const struct termios *termios_p) {
  return ((termios_p->c_cflag & (
                                0010017
                                     |
                                      0010000
                                             )));
}

static speed_t cfgetispeed(const struct termios *termios_p) __attribute__((alias("cfgetospeed")));








static int ioctl(int d, long int request, ...) ;




static void cfmakeraw(struct termios *t) {
     t->c_iflag &= ~(
                    0000001
                          |
                           0000002
                                 |
                                  0000010
                                        |
                                         0000040
                                               |
                                                0000100
                                                     |
                                                      0000200
                                                           |
                                                            0000400
                                                                 |
                                                                  0002000
                                                                      );
     t->c_oflag &= ~
                   0000001
                        ;
     t->c_lflag &= ~(
                    0000010
                        |
                         0000100
                               |
                                0000002
                                      |
                                       0000001
                                           |
                                            0000400
                                                  );
     t->c_cflag &= ~(
                    0000060
                         |
                          0000400
                                );
     t->c_cflag |= 
                  0000060
                     ;
     t->c_cc[
            4
                ] = 1;
     t->c_cc[
            5
                 ] = 0;
}







static int cfsetispeed(struct termios *termios_p, speed_t speed)
{
  if ((speed & (speed_t)~
                        0010017
                             ) != 0 && (speed < 
                                                0010001 
                                                       || speed > 
                                                                  0010004
                                                                         )) {
    
   (*__errno_location())
        =
         22
               ;
    return -1;
  }
  if (speed == 0)
    termios_p->c_iflag |= 020000000000;
  else {
    termios_p->c_iflag &= ~020000000000;
    termios_p->c_cflag &= ~(
                           0010017 
                                 | 
                                   0010000
                                          );
    termios_p->c_cflag |= speed;
  }
  return 0;
}





static int cfsetospeed(struct termios *termios_p, speed_t speed) {
  if ((speed & (speed_t)~
                        0010017
                             ) != 0 && (speed < 
                                                0010001 
                                                       || speed > 
                                                                  0010004
                                                                         )) {
    
   (*__errno_location())
        =
         22
               ;
    return -1;
  }
  termios_p->c_cflag &= ~(
                         0010017 
                               | 
                                 0010000
                                        );
  termios_p->c_cflag |= speed;
  return 0;
}






struct __dirstream {
  char buf[
          4096UL
                   -(sizeof (int)*3)];
  int fd;
  unsigned int num;
  unsigned int cur;
};












struct dirent {
  long d_ino;
  off_t d_off;
  uint16_t d_reclen;
  unsigned char d_type;
  char d_name[256];
};


struct dirent64 {
  uint64_t d_ino;
  int64_t d_off;
  uint16_t d_reclen;
  unsigned char d_type;
  char d_name[256];
};
typedef struct __dirstream DIR;

static DIR *opendir (const char *__name) ;
static DIR *fdopendir (int fd) ;
static int closedir (DIR *__dirp) ;
struct dirent *readdir (DIR *__dirp) ;

static int readdir_r (DIR* __dirp, struct dirent* entry, struct dirent** result) ;

struct dirent64 *readdir64 (DIR *__dirp) ;
static void rewinddir (DIR *__dirp) ;
static void seekdir (DIR *__dirp, off_t __pos) ;
static off_t telldir (DIR *__dirp) ;

static int scandir(const char *dir, struct dirent ***namelist,
      int (*selection)(const struct dirent *),
      int (*compar)(const struct dirent **, const struct dirent **));
static int scandir64(const char *dir, struct dirent64 ***namelist,
      int (*selection)(const struct dirent64 *),
      int (*compar)(const struct dirent64 **, const struct dirent64 **));

static int alphasort(const struct dirent **a, const struct dirent **b)  __attribute__((const));
static int alphasort64(const struct dirent64 **a, const struct dirent64 **b)  __attribute__((const));




static int dirfd(DIR *dirp)  __attribute__((__deprecated__));
enum
  {
    DT_UNKNOWN = 0,

    DT_FIFO = 1,

    DT_CHR = 2,

    DT_DIR = 4,

    DT_BLK = 6,

    DT_REG = 8,

    DT_LNK = 10,

    DT_SOCK = 12,

    DT_WHT = 14

  };




static int closedir (DIR* d) {
  int res=close(d->fd);
  munmap (d, 
            4096UL
                     );
  return res;
}










enum {
  FUTEX_WAIT=0,
  FUTEX_WAKE=1,
  FUTEX_FD=2,
  FUTEX_REQUEUE=3,
  FUTEX_CMP_REQUEUE=4,
};

static long futex(int* uaddr,int op,int val,const struct timespec* timeout,int* uaddr2,int val3);




static int cnd_broadcast(cnd_t* cond) {
  cond->sem=1;
  futex(&cond->sem,FUTEX_WAKE,0x7fffffff,0,0,0);
  return thrd_success;
}


static void cnd_destroy(cnd_t* cond) {

  (void)cond;
}


static int cnd_init(cnd_t* cond) {
  cond->sem=0;
  return thrd_success;
}



static int cnd_signal(cnd_t* cond) {
  cond->sem=1;
  futex(&cond->sem,FUTEX_WAKE,1,0,0,0);
  return thrd_success;
}




static int cnd_timedwait(cnd_t* cond, mtx_t* mutex, const struct timespec* time_point) {
  int r;
  do {
    r=futex(&cond->sem,FUTEX_WAIT,0,time_point,0,0);
    if (r==-1) {
      if (
         (*__errno_location())
              ==
                11
                           ) break;
      else if (
              (*__errno_location())
                   ==
                     4
                          ) continue;
    } else
      break;
  } while (r==0);
  cond->sem=0;
  return mtx_timedlock(mutex,time_point);
}




static int cnd_wait(cnd_t* cond, mtx_t* mutex) {
  return cnd_timedwait(cond,mutex,0);
}



static int socketcall(int callno,long* args);

static int __libc_connect(int a, void * b, int c);
static int __libc_connect(int a, void * b, int c) {
  long args[] = { a, (long) b, c };
  return socketcall(3, args);
}

static int connect(int a, void * b, int c) __attribute__((alias("__libc_connect")));




static int __libc_creat(const char *file,mode_t mode);
static int __libc_creat(const char *file,mode_t mode) {
  return open(file,
                  0x0001
                          |
                           0x0100
                                  |
                                   0x0200
                                          ,mode);
}
static int creat(const char *file,mode_t mode) __attribute__((alias("__libc_creat")));






static int creat64(const char *file,mode_t mode) {
  return open(file,
                  0x0001
                          |
                           0x0100
                                  |
                                   0x0200
                                          |
                                           0x2000
                                                      ,mode);
}


static div_t div(int numerator, int denominator) {
  div_t x;
  x.quot=numerator/denominator;
  x.rem=numerator-x.quot*denominator;
  return x;
}

asm (".section .gnu.warning." "div" "\n\t.string \"" "warning: your code uses div(), which is completely superfluous!" "\"\n\t.previous");;




static const char __sys_err_unknown [] = "[unknown error]";



 
    int (*__errno_location());




 __thread int errno;



 int *__errno_location(void) { return &errno; }














enum {
  EFD_CLOEXEC = 0x80000,

  EFD_NONBLOCK = 0x0080,

  EFD_SEMAPHORE = 1

};

typedef uint64_t eventfd_t;

static int eventfd(unsigned int initval, int flags) ;



 
      int __eventfd(unsigned int count);
 int __eventfd2(unsigned int count,int flags);

static int eventfd(unsigned int count,int flags) {
  int r=__eventfd2(count,flags);
  if (r==-1 && errno==
                     89
                           ) {
    r=__eventfd(count);
    if (r!=-1 && flags) {
      int x;
      x=fcntl(r,
               2
                      ,flags);
      if (x==-1)
 close(r);
    }
  }
  return r;
}



 char **environ;

static int __exec_shell(const char *file, char *const argv[]);
static int __exec_shell(const char *file, char *const argv[]) {
  int i;
  const char** shell_argv;

  for (i = 0; argv[i]; ++i);
  ++i;

  shell_argv=
            __builtin_alloca(
            sizeof(char*)*(i+1)
            )
                                       ;
  shell_argv[0] = 
                 "/bin/sh"
                             ;
  shell_argv[1] = file;
  for (; i > 1; i--)
    shell_argv[i] = argv[i - 1];
  return execve(
               "/bin/sh"
                           , (char*const*)shell_argv, environ);
}







static int execl( const char *path, const char* arg, ...) {
  va_list ap,bak;
  int n,i;
  char **argv,*tmp;
  (void)arg;
  
 __builtin_va_start((
 ap
 ),(
 arg
 ))
                  ;
  
 __builtin_va_copy((
 bak
 ),(
 ap
 ))
                ;
  n=2;
  while ((tmp=
             __builtin_va_arg
                   (ap,char *)))
    ++n;
  
 __builtin_va_end 
        (ap);
  if ((argv=(char **)
                    __builtin_alloca(
                    n*sizeof(char*)
                    )
                                           )) {
    argv[0]=(char*)arg;
    for (i=1; i<n; ++i)
      argv[i]=
             __builtin_va_arg
                   (bak,char *);
    
   __builtin_va_end 
          (bak);
    return execve(path,argv,environ);
  }
  
 __builtin_va_end 
        (bak);
  errno=
       12
             ;
  return -1;
}






static int execle( const char *path, const char* arg, ...) {
  va_list ap;
  int n,i;
  char **argv,*tmp, **env;
  
 __builtin_va_start((
 ap
 ),(
 arg
 ))
                  ;
  (void)arg;
  n=2;
  while ((tmp=
             __builtin_va_arg
                   (ap,char *)))
    ++n;
  
 __builtin_va_end 
        (ap);
  if ((argv=(char **)
                    __builtin_alloca(
                    n*sizeof(char*)
                    )
                                           )) {
    
   __builtin_va_start((
   ap
   ),(
   arg
   ))
                    ;
    argv[0]=(char*)arg;
    for (i=1; i<n; ++i)
      argv[i]=
             __builtin_va_arg
                   (ap,char *);
    env=
       __builtin_va_arg
             (ap, char **);
    
   __builtin_va_end 
          (ap);
    return execve(path,argv,env);
  }
  errno=
       12
             ;
  return -1;
}






static int execlp(const char* file, const char *arg,...) {
  va_list ap,bak;
  int n,i;
  char **argv,*tmp;
  
 __builtin_va_start((
 ap
 ),(
 arg
 ))
                  ;
  
 __builtin_va_copy((
 bak
 ),(
 ap
 ))
                ;
  n=2;
  while ((tmp=
             __builtin_va_arg
                   (ap,char *)))
    ++n;
  
 __builtin_va_end 
        (ap);
  if ((argv=(char **)
                    __builtin_alloca(
                    n*sizeof(char*)
                    )
                                           )) {
    argv[0]=(char*)arg;
    for (i=0; i<n; ++i)
      argv[i+1]=
               __builtin_va_arg
                     (bak,char *);
    
   __builtin_va_end 
          (bak);
    return execvp(file,argv);
  }
  
 __builtin_va_end 
        (bak);
  errno=
       12
             ;
  return -1;
}










 int __exec_shell(const char *file, char *const argv[]);


static int execv(const char *file, char *const argv[]) {
  if (execve(file,argv,environ)==-1) {
    if (errno==
              8
                     )
      __exec_shell(file,argv);
  }
  return -1;
}
static int execvp(const char *file, char *const argv[]) {
  const char *path=getenv("PATH");
  char *cur,*next;
  char buf[
          4095
                  ];
  if (strchr((char*)file,'/')) {
    if (execve(file,argv,environ)==-1) {
      if (errno==
                8
                       )
 __exec_shell(file,argv);
      return -1;
    }
  }
  if (!path) path=
                 "/bin:/usr/bin:"
                              ;
  for (cur=(char*)path; cur; cur=next) {
    next=strchr(cur,':');
    if (!next)
      next=cur+strlen(cur);
    if (next==cur) {
      buf[0]='.';
      cur--;
    } else {
      if (next-cur>=
                   4095
                           -3) { error: errno=
                                              22
                                                    ; return -1; }
      memmove(buf,cur,(size_t)(next-cur));
    }
    buf[next-cur]='/';
    {
      int len=strlen(file);
      if (len+(next-cur)>=
                         4095
                                 -2) goto error;
      memmove(&buf[next-cur+1],file,strlen(file)+1);
    }
    if (execve(buf,argv,environ)==-1) {
      if (errno==
                8
                       )
 return __exec_shell(buf,argv);
      if ((errno!=
                 13
                       ) && (errno!=
                                    2
                                          ) && (errno!=
                                                       20
                                                              )) return -1;
    }
    if (*next==0) break;
    next++;
  }
  return -1;
}


static void explicit_bzero(void* dest,size_t len) {
  memset(dest,0,len);
  asm volatile("": : "r"(dest) : "memory");
}


static void* explicit_memset(void* dest, int c, size_t len) {
  memset(dest,c,len);
  asm volatile("": : "r"(dest) : "memory");
  return dest;
}







static DIR* fdopendir ( int fd ) {
  DIR* t = 
            (void*)0
                ;

  if ( fd >= 0 ) {
    t = (DIR *) mmap (
                     (void*)0
                         , 
                           4096UL
                                    , 
                                      0x1 
                                                | 
                                                  0x2
                                                            ,
  
 0x02 
             | 
               0x0800
                            , -1, 0);
    if (t != 
            ((void *) -1)
                      )
      t->fd = fd;
  }


  return t;
}









static int strcasecmp(const char *s1, const char *s2)  ;
static int strncasecmp(const char *s1, const char *s2, size_t n)  ;
static int ffs(int i)  ;

static int bcmp(const void *, const void *, size_t)   __attribute__((__deprecated__));
static void bcopy(const void *, void *, size_t)  __attribute__((__deprecated__));
static void bzero(void *, size_t)  __attribute__((__deprecated__));
static char *index(const char *, int)   __attribute__((__deprecated__));
static char *rindex(const char *, int)   __attribute__((__deprecated__));










static int ffs(int i) {
  int plus=0;
  if ((i&0xffff)==0) {
    plus+=16;
    i>>=16;
  }
  if ((i&0xff)==0) {
    plus+=8;
    i>>=8;
  }
  if ((i&0xf)==0) {
    plus+=4;
    i>>=4;
  }
  if (i&1) return plus+1;
  if (i&2) return plus+2;
  if (i&4) return plus+3;
  if (i&8) return plus+4;
  return 0;
}










struct statvfs {
  unsigned long f_bsize;
  unsigned long f_frsize;
  fsblkcnt_t f_blocks;
  fsblkcnt_t f_bfree;
  fsblkcnt_t f_bavail;
  fsfilcnt_t f_files;
  fsfilcnt_t f_ffree;
  fsfilcnt_t f_favail;
  unsigned long f_fsid;
  unsigned long f_flag;
  unsigned long f_namemax;
};

static int statvfs(const char *path, struct statvfs *buf) ;
static int fstatvfs(int fd, struct statvfs *buf) ;



enum
{
  ST_RDONLY = 1,

  ST_NOSUID = 2
};




 
      void __statvfs_cvt(struct statfs* from,struct statvfs* to);

static int fstatvfs(int fd, struct statvfs *sv) {
  struct statfs ss;
  if (fstatfs(fd,&ss)==-1) return -1;
  __statvfs_cvt(&ss,sv);
  return 0;
}







static unsigned long getauxval(unsigned long type);



enum {
  AT_BASE=7,
  AT_BASE_PLATFORM=24,
  AT_CLKTCK=17,
  AT_DCACHEBSIZE=19,
  AT_EGID=14,
  AT_ENTRY=9,
  AT_EUID=12,
  AT_EXECFD=2,
  AT_EXECFN=31,
  AT_FLAGS=8,
  AT_FPUCW=18,
  AT_GID=13,
  AT_HWCAP=16,
  AT_HWCAP2=26,
  AT_ICACHEBSIZE=20,
  AT_PAGESZ=6,
  AT_PHDR=3,
  AT_PHENT=4,
  AT_PHNUM=5,
  AT_PLATFORM=15,
  AT_RANDOM=25,
  AT_SECURE=23,
  AT_SYSINFO=32,
  AT_SYSINFO_EHDR=33,
  AT_UCACHEBSIZE=21,
  AT_UID=11
};


static void* find_in_auxvec(long* x,long what) {
  while (*x) {
    if (*x==what)
      return (void*)x[1];
    x+=2;
  }
  return 
        (void*)0
            ;
}

static long* _auxvec;

static unsigned long getauxval(unsigned long type) {
  return (long)find_in_auxvec(_auxvec,type);
}











struct utsname {

  char sysname[65];


  char nodename[65];


  char release[65];

  char version[65];


  char machine[65];


  char domainname[65];
};

 int uname (struct utsname *__name) ;





static int getdomainname(char *name,size_t len) {
  struct utsname u;
  int res=uname(&u);
  if (res==0) {
    size_t i;
    if (len>=
            65
                                  )
      len=
         65
                               ;
    for (i=0; i<len; i++)
      name[i]=u.domainname[i];
  }
  return res;
}




static int getentropy(void* buf,size_t buflen) {
  int r;
  if (buflen>256) {
    errno=
         5
            ;
    return -1;
  }
  r=getrandom(buf,buflen,
                        GRND_NONBLOCK
                                     );
  if (r==-1 && errno==
                     89
                           ) {
    int fd=open("/dev/urandom",
                              0x0000
                                      );
    if (fd==-1) return -1;
    r=read(fd,buf,buflen);
    close(fd);
  }
  if (r<(int)buflen)
    return -1;
  return 0;
}



 char *getenv(const char *s)
{
  int i;
  unsigned int len;

  if (!environ || !s) return 0;
  len = strlen(s);
  for (i = 0;environ[i];++i)
    if ((memcmp(environ[i],s,len)==0) && (environ[i][len] == '='))
      return environ[i] + len + 1;
  return 0;
}







static int gethostname(char *name,size_t len) {
  struct utsname u;
  int res=uname(&u);
  if (res==0) {
    size_t i;
    if (len>=
            65
                                    )
      len=
         65
                                 ;
    for (i=0; i<len; i++)
      name[i]=u.nodename[i];
  }
  return res;
}










struct option {
  const char* name;
  int has_arg;
  int* flag;
  int val;
};





 int getopt_long(int argc, char *const *argv,
         const char *shortopts, const struct option *longopts,
         int *longind);

 int getopt_long_only(int argc, char *const *argv,
       const char *shortopts, const struct option *longopts,
       int *longind);




static void getopterror(int which) {
  static char error1[]="Unknown option `-x'.\n";
  static char error2[]="Missing argument for `-x'.\n";
  if (opterr) {
    if (which) {
      error2[23]=optopt;
      write(2,error2,28);
    } else {
      error1[17]=optopt;
      write(2,error1,22);
    }
  }
}

static int getopt(int argc, char * const argv[], const char *optstring) {
  static int lastidx,lastofs;
  char *tmp;
  if (optind==0) { optind=1; lastidx=0; }
again:
  if (optind>argc || !argv[optind] || *argv[optind]!='-' || argv[optind][1]==0)
    return -1;
  if (argv[optind][1]=='-' && argv[optind][2]==0) {
    ++optind;
    return -1;
  }
  if (lastidx!=optind) {
    lastidx=optind; lastofs=0;
  }
  optopt=argv[optind][lastofs+1];
  if ((tmp=strchr(optstring,optopt))) {
    if (*tmp==0) {
      ++optind;
      goto again;
    }
    if (tmp[1]==':') {
      if (tmp[2]==':' || argv[optind][lastofs+2]) {
 if (!*(optarg=argv[optind]+lastofs+2)) optarg=0;
 goto found;
      }
      optarg=argv[optind+1];
      if (!optarg) {
 ++optind;
 if (*optstring==':') return ':';
 getopterror(1);
 return ':';
      }
      ++optind;
    } else {
      ++lastofs;
      return optopt;
    }
found:
    ++optind;
    return optopt;
  } else {
    getopterror(0);
    ++optind;
    return '?';
  }
}




 int socketcall(int callno,long* args);

static int __libc_getpeername(int a, void * b, int *c);
static int __libc_getpeername(int a, void * b, int *c) {
  long args[] = { a, (long) b, (long) c };
  return socketcall(7, args);
}

static int getpeername(int a, struct sockaddr* b, socklen_t *c) __attribute__((alias("__libc_getpeername")));




static pid_t getpgrp()
{
  return getpgid(0);
}




 int socketcall(int callno,long* args);

static int __libc_getsockname(int a, void * b, int c);
static int __libc_getsockname(int a, void * b, int c) {
  long args[] = { a, (long) b, c };
  return socketcall(6, args);
}

static int getsockname(int a, struct sockaddr* b, socklen_t* c) __attribute__((alias("__libc_getsockname")));






 int socketcall(int callno,long* args);

static int __libc_getsockopt(int a, int b, int c, void *d, int e);
static int __libc_getsockopt(int a, int b, int c, void *d, int e) {
  long args[] = { a, b, c, (long)d, e };
  return socketcall(15, args);
}

static int getsockopt(int s, int level, int optname, void * optval, socklen_t *optlen) __attribute__((alias("__libc_getsockopt")));














enum {
  IPPROTO_IP = 0,

  IPPROTO_ICMP = 1,

  IPPROTO_IGMP = 2,

  IPPROTO_IPIP = 4,

  IPPROTO_TCP = 6,

  IPPROTO_EGP = 8,

  IPPROTO_PUP = 12,

  IPPROTO_UDP = 17,

  IPPROTO_IDP = 22,

  IPPROTO_RSVP = 46,

  IPPROTO_GRE = 47,

  IPPROTO_IPV6 = 41,

  IPPROTO_PIM = 103,

  IPPROTO_ESP = 50,

  IPPROTO_AH = 51,

  IPPROTO_COMP = 108,

    IPPROTO_SCTP = 132,

    IPPROTO_UDPLITE = 136,

  IPPROTO_RAW = 255,

  IPPROTO_MAX
};
 const struct in6_addr in6addr_any;
 const struct in6_addr in6addr_loopback;

typedef uint16_t in_port_t;
typedef uint32_t in_addr_t;

struct in_addr {
  in_addr_t s_addr;
};

struct ip_mreq {
  struct in_addr imr_multiaddr;
  struct in_addr imr_interface;
};

struct ip_mreqn {
  struct in_addr imr_multiaddr;
  struct in_addr imr_address;
  int32_t imr_ifindex;
};

struct in_pktinfo {
  int32_t ipi_ifindex;
  struct in_addr ipi_spec_dst;
  struct in_addr ipi_addr;
};



struct sockaddr_in {
  sa_family_t sin_family;
  in_port_t sin_port;
  struct in_addr sin_addr;

  unsigned char sin_zero[16 - sizeof(int16_t) -
   sizeof(uint16_t) - sizeof(struct in_addr)];
};
struct in6_addr {
  union {
    uint8_t u6_addr8[16];
    uint16_t u6_addr16[8];
    uint32_t u6_addr32[4];
  } in6_u;



};

struct sockaddr_in6 {
  uint16_t sin6_family;
  uint16_t sin6_port;
  uint32_t sin6_flowinfo;
  struct in6_addr sin6_addr;
  uint32_t sin6_scope_id;
};

struct sockaddr_in_pad {
  sa_family_t sin_family;
  in_port_t sin_port;
  struct in_addr sin_addr;

  unsigned char sin_zero[sizeof(struct sockaddr_in6) - sizeof(int16_t) -
   sizeof(uint16_t) - sizeof(struct in_addr)];
};

struct ipv6_mreq {

  struct in6_addr ipv6mr_multiaddr;

  int32_t ipv6mr_interface;
};

struct in6_flowlabel_req {
  struct in6_addr flr_dst;
  uint32_t flr_label;
  uint8_t flr_action;
  uint8_t flr_share;
  uint16_t flr_flags;
  uint16_t flr_expires;
  uint16_t flr_linger;
  uint32_t __flr_pad;

};
struct in6_pktinfo {
  struct in6_addr ipi6_addr;
  int32_t ipi6_ifindex;
};

struct in6_ifreq {
  struct in6_addr ifr6_addr;
  uint32_t ifr6_prefixlen;
  int32_t ifr6_ifindex;
};





struct ipv6_rt_hdr {
  uint8_t nexthdr;
  uint8_t hdrlen;
  uint8_t type;
  uint8_t segments_left;

};

struct ipv6_opt_hdr {
  uint8_t nexthdr;
  uint8_t hdrlen;

};







struct rt0_hdr {
  struct ipv6_rt_hdr rt_hdr;
  uint32_t bitmap;
  struct in6_addr addr[0];

};


struct ipv6hdr {





  uint32_t version:4,
   priority:8,
   flow_lbl:20;


  uint16_t payload_len;
  uint8_t nexthdr;
  uint8_t hop_limit;

  struct in6_addr saddr;
  struct in6_addr daddr;
};
static uint32_t htonl(uint32_t hostlong) __attribute__((const));
static uint16_t htons(uint16_t hostshort) __attribute__((const));
static uint32_t ntohl(uint32_t netlong) __attribute__((const));
static uint16_t ntohs(uint16_t netshort) __attribute__((const));
static int bindresvport(int sd, struct sockaddr_in* _sin);



static uint32_t htonl(uint32_t hostlong) {




  return hostlong;

}

static uint32_t ntohl(uint32_t hostlong) __attribute__((alias("htonl")));



static uint16_t htons(uint16_t hostshort) {



  return hostshort;

}

static uint16_t ntohs(uint16_t hostshort) __attribute__((alias("htons")));








struct ifmap {
  unsigned long mem_start;
  unsigned long mem_end;
  uint16_t base_addr;
  unsigned char irq;
  unsigned char dma;
  unsigned char port;

};

struct ifreq {



  union
  {
    char ifrn_name[16];
  } ifr_ifrn;
  union {
    struct sockaddr ifru_addr;
    struct sockaddr ifru_dstaddr;
    struct sockaddr ifru_broadaddr;
    struct sockaddr ifru_netmask;
    struct sockaddr ifru_hwaddr;
    int16_t ifru_flags;
    int32_t ifru_ivalue;
    int32_t ifru_mtu;
    struct ifmap ifru_map;
    char ifru_slave[16];
    char ifru_newname[16];
    char* ifru_data;
  } ifr_ifru;
};
struct ifconf {
  int32_t ifc_len;
  union {
    char * ifcu_buf;
    struct ifreq *ifcu_req;
  } ifc_ifcu;
};




static unsigned int if_nametoindex (const char *ifname) ;
static char *if_indextoname (unsigned int ifindex, char *ifname) ;

struct if_nameindex {
  uint32_t if_index;
  char *if_name;
};

struct if_nameindex* if_nameindex(void) ;
static void if_freenameindex(struct if_nameindex* ptr) ;





static void if_freenameindex(struct if_nameindex* ptr) {
  free(ptr);
}







struct if_nameindex* if_nameindex(void) {
  struct ifconf ic;
  int fd,len,i;
  struct if_nameindex* x=0,* y;
  char *dest;
  fd=socket(
           10
                   ,
                    1
                              ,0);
  if (fd<0) fd=socket(
                     2
                            ,
                             1
                                       ,0);
  ic.
    ifc_ifcu.ifcu_buf
           =0;
  ic.ifc_len=0;
  if (ioctl(fd,
              0x8912
                         ,&ic)<0) goto b0rken;
  ic.
    ifc_ifcu.ifcu_buf
           =
            __builtin_alloca(
            (size_t)ic.ifc_len
            )
                                      ;
  if (ioctl(fd,
              0x8912
                         ,&ic)<0) goto b0rken;
  len=(ic.ifc_len/sizeof(struct ifreq));
  x=(struct if_nameindex*)malloc((len+1)*sizeof(struct if_nameindex)+len*
                                                                        16
                                                                                );
  if (!x) goto b0rken;
  dest=(char*)(x+len+1);
  y=x;
  for (i=0; i<len; ++i) {
    struct ifreq* ir=(struct ifreq*)&ic.
                                       ifc_ifcu.ifcu_req
                                              [i];
    y->if_name=dest;
    memcpy(dest,ir->
                   ifr_ifrn.ifrn_name
                           ,
                            16
                                    );
    if (ioctl(fd,
                0x8933
                            ,ir)==-1) continue;
    y->if_index=ir->
                   ifr_ifru.ifru_ivalue
                              ;
    dest+=
         16
                 ;
    ++y;
  }
  y->if_name=0; y->if_index=0;
b0rken:
  close(fd);
  return x;
}
static char* if_indextoname(unsigned int interface,char* blub) {
  struct ifreq ifr;
  int fd;

  fd=socket(
           10
                   ,
                    1
                              ,0);
  if (fd<0) fd=socket(
                     2
                            ,
                             1
                                       ,0);
  ifr.
     ifr_ifru.ifru_ivalue
                =interface;
  if (ioctl(fd,
              0x8910
                         ,&ifr)==0) {
    int i;
    close(fd);
    for (i=0; i<
               16
                       -1; i++)
      if (!(blub[i]=ifr.
                       ifr_ifrn.ifrn_name
                               [i]))
 return blub;
    blub[i]=0;
    return blub;
  }
  close(fd);
  return 0;
}


static int isalnum(int ch) {
  return (unsigned int)((ch | 0x20) - 'a') < 26u ||
  (unsigned int)( ch - '0') < 10u;
}
static unsigned int if_nametoindex(const char* blub) {
  struct ifreq ifr;
  int fd;
  int ret=0;
  char *tmp;
  int len=sizeof(ifr.
                    ifr_ifrn.ifrn_name
                            );
  fd=socket(
           10
                   ,
                    1
                              ,0);
  if (fd<0) fd=socket(
                     2
                            ,
                             1
                                       ,0);
  for (tmp=ifr.
              ifr_ifrn.ifrn_name
                      ; len>0; --len) {
    if ((*tmp++=*blub++)==0) break;
  }
  if (ioctl(fd,
              0x8933
                          ,&ifr)==0)
    ret=ifr.
           ifr_ifru.ifru_ivalue
                      ;
  close(fd);
  return ret;
}


static int isalpha(int ch) {
  return (unsigned int)((ch | 0x20) - 'a') < 26u;
}


static int isascii ( int ch )
{
    return (unsigned int)ch < 128u;
}
static int isatty(int fd) {
  int save;
  int is_tty;
  struct termios term;

  save = errno;
  is_tty = ioctl(fd, 
                    0x540d
                          , &term) == 0;
  errno = save;

  return is_tty;
}



static int isblank ( int ch )
{
    return ch == ' ' || ch == '\t';
}


static int __iscntrl_ascii ( int ch );
static int __iscntrl_ascii ( int ch ) {
    return (unsigned int)ch < 32u || ch == 127;
}

static int iscntrl ( int ch ) __attribute__((alias("__iscntrl_ascii")));


static int __isdigit_ascii ( int ch );
static int __isdigit_ascii ( int ch ) {
    return (unsigned int)(ch - '0') < 10u;
}

static int isdigit ( int ch ) __attribute__((alias("__isdigit_ascii")));
static int __isgraph_ascii ( int ch );
static int __isgraph_ascii ( int ch ) {
  return (unsigned int)(ch - '!') < 127u - '!';
}

static int isgraph ( int ch ) __attribute__((alias("__isgraph_ascii")));


static int __islower_ascii ( int ch );
static int __islower_ascii ( int ch ) {
    return (unsigned int) (ch - 'a') < 26u;
}

static int islower ( int ch ) __attribute__((alias("__islower_ascii")));



static int isprint (int ch) {
  ch&=0x7f;
  return (ch>=32 && ch<127);
}


static int __ispunct_ascii ( int ch );
static int __ispunct_ascii ( int ch )
{
    return isprint (ch) && !isalnum (ch) && !isspace (ch);
}

static int ispunct ( int ch ) __attribute__((alias("__ispunct_ascii")));


static int __isspace_ascii ( int ch );
static int __isspace_ascii ( int ch )
{
    return (unsigned int)(ch - 9) < 5u || ch == ' ';
}

static int isspace ( int ch ) __attribute__((alias("__isspace_ascii")));


static int __isupper_ascii ( int ch );
static int __isupper_ascii ( int ch )
{
    return (unsigned int)(ch - 'A') < 26u;
}

static int isupper ( int ch ) __attribute__((alias("__isupper_ascii")));








typedef const int32_t* wctrans_t;

static int iswalnum(wint_t)  ;
static int iswalpha(wint_t)  ;
static int iswblank(wint_t)  ;
static int iswcntrl(wint_t)  ;
static int iswdigit(wint_t)  ;
static int iswgraph(wint_t)  ;
static int iswlower(wint_t)  ;
static int iswprint(wint_t)  ;
static int iswpunct(wint_t)  ;
static int iswspace(wint_t)  ;
static int iswupper(wint_t)  ;
static int iswxdigit(wint_t)  ;
static int iswctype(wint_t, wctype_t)  ;
static wint_t towctrans(wint_t, wctrans_t) ;
static wint_t towlower(wint_t) ;
static wint_t towupper(wint_t) ;
static wctrans_t wctrans(const char *) ;
static wctype_t wctype(const char *) ;


static int __iswalnum_ascii(wint_t c);
static int __iswalnum_ascii(wint_t c) {
  return (((unsigned char)c == c)?isalnum(c):0);
}

static int iswalnum(wint_t c) __attribute__((alias("__iswalnum_ascii")));



static int __iswalpha_ascii(wint_t c);
static int __iswalpha_ascii(wint_t c) {
  return (((unsigned char)c == c)?isalpha(c):0);
}

static int iswalpha(wint_t c) __attribute__((alias("__iswalpha_ascii")));


static int __iswblank_ascii(wint_t c);
static int __iswblank_ascii(wint_t c) {
  return (c == ' ' || c == '\t');
}

static int iswblank(wint_t c) __attribute__((alias("__iswblank_ascii")));


static int __iswcntrl_ascii(wint_t c);
static int __iswcntrl_ascii(wint_t c) {
  return ((unsigned int)c < 32u || c == 127);
}

static int iswcntrl(wint_t c) __attribute__((alias("__iswcntrl_ascii")));


static int iswdigit(wint_t c) {
    return (unsigned int)(c - '0') < 10u;
}


static int __iswgraph_ascii(wint_t c);
static int __iswgraph_ascii(wint_t c) {
  return (unsigned int)(c - '!') < 127u - '!';
}

static int iswgraph(wint_t c) __attribute__((alias("__iswgraph_ascii")));


static int __iswlower_ascii(wint_t c);
static int __iswlower_ascii(wint_t c) {
  return (unsigned int) (c - 'a') < 26u;
}

static int iswlower ( wint_t ch ) __attribute__((alias("__iswlower_ascii")));


static int __iswprint_ascii(wint_t c);
static int __iswprint_ascii(wint_t c) {
    return (unsigned int)(c - ' ') < 127u - ' ';
}

static int iswprint(wint_t c) __attribute__((alias("__iswprint_ascii")));


static int __iswpunct_ascii(wint_t c);
static int __iswpunct_ascii(wint_t c)
{
  return iswprint (c) && !iswalnum(c) && !iswspace(c);
}

static int iswpunct(wint_t c) __attribute__((alias("__iswpunct_ascii")));


static int __iswspace_ascii(wint_t c);
static int __iswspace_ascii(wint_t c) {
  return (unsigned int)(c - 9) < 5u || c == ' ';
}

static int iswspace(wint_t c) __attribute__((alias("__iswspace_ascii")));


static int __iswupper_ascii ( wint_t c );
static int __iswupper_ascii ( wint_t c )
{
    return (unsigned int)(c - 'A') < 26u;
}

static int iswupper ( wint_t c ) __attribute__((alias("__iswupper_ascii")));


static int __iswxdigit_ascii(wint_t c);
static int __iswxdigit_ascii(wint_t c)
{
    return (unsigned int)( c - '0') < 10u ||
           (unsigned int)((c | 0x20) - 'a') < 6u;
}

static int iswxdigit(wint_t c) __attribute__((alias("__iswxdigit_ascii")));
static int __isxdigit_ascii ( int ch );
static int __isxdigit_ascii ( int ch )
{
    return (unsigned int)( ch - '0') < 10u ||
           (unsigned int)((ch | 0x20) - 'a') < 6u;
}

static int isxdigit ( int ch ) __attribute__((alias("__isxdigit_ascii")));
static ldiv_t ldiv(long numerator, long denominator) {
  ldiv_t x;
  x.quot=numerator/denominator;
  x.rem=numerator-x.quot*denominator;
  return x;
}




 int socketcall(int callno,long* args);

static int __libc_listen(int a, int b);
static int __libc_listen(int a, int b) {
  long args[] = { a, b, 0 };
  return socketcall(4, args);
}

static int listen(int s, int backlog) __attribute__((alias("__libc_listen")));







static long long int llabs(long long int i) { if (i<0) i=-i; return i; }
static intmax_t imaxabs(intmax_t i) __attribute__((alias("llabs")));





static lldiv_t lldiv(long long numerator, long long denominator) {
  lldiv_t x;
  x.quot=numerator/denominator;
  x.rem=numerator-x.quot*denominator;
  return x;
}

static imaxdiv_t imaxdiv(intmax_t numerator, intmax_t denominator) __attribute__((alias("lldiv")));






static int lockf(int fd, int cmd, off_t len) {
  struct flock fl;
  fl.l_whence=
             1
                     ;
  fl.l_start=0;
  fl.l_len=len;
  fl.l_pid=0;
  switch (cmd) {
  case 
      3
            :
    if (fcntl(fd,
                14
                       ,&fl)<0)
      return -1;
    if (fl.l_type == 
                    2 
                            || fl.l_pid == getpid ())
      return 0;
    errno=
         13
               ;
    return -1;
  case 
      0
             :
    fl.l_type=
             2
                    ;
    cmd=
       6
              ;
    break;
  case 
      1
            :
    fl.l_type = 
               1
                      ;
    cmd = 
         7
                 ;
    break;
  case 
      2
             :
    fl.l_type = 
               1
                      ;
    cmd = 
         6
                ;
    break;
  default:
    errno=
         22
               ;
    return -1;
  }
  return fcntl(fd,cmd,&fl);
}



static void __longjmp(void*env,int val);

static void __libc_longjmp(sigjmp_buf env,int val);
static void __libc_longjmp(sigjmp_buf env,int val) {
  if (env[0].__mask_was_saved) {
    sigprocmask(
               3
                          ,(sigset_t*)&env[0].__saved_mask,0);
  }
  if (val==0) val=1;
  __longjmp(env[0].__jmpbuf,val);
}
static void __siglongjmp(sigjmp_buf env,int val) __attribute__((alias("__libc_longjmp")));
static void longjmp(sigjmp_buf env,int val) __attribute__((alias("__libc_longjmp")));
static void siglongjmp(sigjmp_buf env,int val) __attribute__((alias("__libc_longjmp")));







static loff_t lseek64(int fildes, loff_t offset, int whence) {
  loff_t tmp;
  if (llseek(fildes,(unsigned long)(offset>>32),(unsigned long)offset&0xffffffff,&tmp,whence)) {
    if (errno!=
              89
                    ) return -1;
    return (loff_t)lseek(fildes,(off_t)offset,whence);
  }
  return tmp;
}




static int mblen(const char* s,size_t n) {
  return mbrlen(s,n,
                   (void*)0
                       );
}



static size_t mbrlen(const char *s, size_t n, mbstate_t *ps) {
  static mbstate_t internal;
  return mbrtowc (
                 (void*)0
                     , s, n, ps ?: &internal);
}




static mbstate_t internal;

static size_t mbrtowc(wchar_t *pwc, const char *s, size_t n, mbstate_t *ps) {
  size_t i;
  if (!ps) ps=&internal;
  if (!s) {
    if (ps->count) {
      errno=
           88
                 ;
      return (size_t)-1;
    } else {
      ps->count=0;
      ps->sofar=0;
      return 0;
    }
  }
  for (i=0; i<n; ++i) {
    unsigned char c=s[i];
    switch (lc_ctype) {
    case CT_8BIT:
      if (pwc) { *pwc=c; ++pwc; }
      return (!!c);
    case CT_UTF8:
      if (ps->count) {

 if ((c&0xc0)!=0x80) {

kaputt:
   errno=
        88
              ;
   ps->count=0;
   return (size_t)-1;
 }
 ps->sofar=(ps->sofar << 6) + (c & 0x3f);
 if (!--ps->count) {
complete:
   if (pwc) { *pwc=ps->sofar; ++pwc; }
   if (ps->sofar) {
     ps->sofar=0;
     return i+1;
   } else {
     ps->count=0; ps->sofar=0;
     return 0;
   }
 }
      } else {
 if (c&0x80) {
   unsigned char x=c<<1;
   unsigned char cnt=0;
   while (x&0x80) {
     x<<=1;
     ++cnt;
   }
   if (!cnt || cnt>5) goto kaputt;
   ps->sofar=x>>(cnt+1);
   ps->count=cnt;
 } else {
   ps->sofar=c;
   goto complete;
 }
      }
    }
  }
  return n;
}


static int mbsinit(const mbstate_t* s) {
  return (!s || s->sofar);
}


static size_t mbsrtowcs(wchar_t *dest, const char **src, size_t len, mbstate_t *ps) {
  size_t i;
  if (!dest) len=(size_t)-1;
  for (i=0; i<len; ++i) {
    size_t n=mbrtowc(dest?dest+i:0,*src,len,ps);
    if (n==(size_t)-1) return -1;
    if (!n) break;
    *src+=n;
  }
  return i;
}



static size_t mbstowcs(wchar_t *dest, const char *src, size_t n) {
  const char** s=&src;
  return mbsrtowcs(dest,s,n,
                           (void*)0
                               );
}



static int mbtowc(wchar_t *pwc, const char *s, size_t n) {
  return mbrtowc(pwc,s,n,
                        (void*)0
                            );
}





static void *memccpy(void *dst, const void *src, int c, size_t count)
{
  char *a = dst;
  const char *b = src;
  while (count--)
  {
    *a++ = *b;
    if (*b==c)
    {
      return (void *)a;
    }
    b++;
  }
  return 0;
}



static void* memchr(const void *s, int c, size_t n) {
  const unsigned char *pc = (unsigned char *) s;
  for (;n--;pc++)
    if (*pc == c)
      return ((void *) pc);
  return 0;
}





static int memcmp(const void *dst, const void *src, size_t count) {
  register int r;
  register const unsigned char *d=dst;
  register const unsigned char *s=src;
  ++count;
  while (
        __builtin_expect((long)((
        --count
        )),1)
                         ) {
    if (
       __builtin_expect((long)((
       r=(*d - *s)
       )),0)
                              )
      return r;
    ++d;
    ++s;
  }
  return 0;
}

static int 
   memcmp(
   const char *a
   ,
   const char *b
   ,
   size_t c
   ) 
                                              __attribute__((alias("memcmp")));






static void *
static memcpy (void *dst, const void *src, size_t n)
{
    void *res = dst;
    unsigned char *c1, *c2;






    int tmp;
    unsigned long *lx1 = 
                         (void*)0
                             ;
    const unsigned long *lx2 = 
                              (void*)0
                                  ;

    if (!(((unsigned long)dst & (sizeof (unsigned long)-1)) ^ ((unsigned long)src & (sizeof (unsigned long)-1))) && n > sizeof(unsigned long)) {

 if ((tmp = ((((uintptr_t)dst+sizeof(long)-1)&(-sizeof(long)))-(uintptr_t)dst))) {
     c1 = (unsigned char *) dst;
     c2 = (unsigned char *) src;
     while (tmp-- && n--)
  *c1++ = *c2++;
     if (n == (size_t) - 1)
  return (res);
     dst = c1;
     src = c2;
 }

 lx1 = (unsigned long *) dst;
 lx2 = (unsigned long *) src;

 for (; n >= sizeof(unsigned long); n -= sizeof(unsigned long))
     *lx1++ = *lx2++;
    }

    if (n) {
 c1 = (unsigned char *) (lx1?lx1:dst);
 c2 = (unsigned char *) (lx1?lx2:src);
 while (n--)
     *c1++ = *c2++;
    }

    return (res);

}




static void *memmem(const void* haystack, size_t hl, const void* needle, size_t nl) {
  int i;
  if (nl>hl) return 0;
  for (i=hl-nl+1; i; --i) {
    if (!memcmp(haystack,needle,nl))
      return (char*)haystack;
    ++haystack;
  }
  return 0;
}





static void *memmove(void *dst, const void *src, size_t count)
{
  char *a = dst;
  const char *b = src;
  if (src!=dst)
  {
    if (src>dst)
    {
      while (count--) *a++ = *b++;
    }
    else
    {
      a+=count-1;
      b+=count-1;
      while (count--) *a-- = *b--;
    }
  }
  return dst;
}




static void* memrchr(const void *s, int c, size_t n) {
  register const char* t=s;
  register const char* last=0;
  int i;
  for (i=n; i; --i) {
    if (*t==c)
      last=t;
    ++t;
  }
  return (void*)last;
}



static int mkfifo(const char *fn,mode_t mode) {
  return mknod(fn,(mode_t)(mode|
                               0010000
                                      ),0);
}





static void* memset(void * dst, int s, size_t count) {
    register char * a = dst;
    count++;
    while (--count)
 *a++ = s;
    return dst;
}





static void*__mmap2(void*start,size_t length,int prot,int flags,int fd,off_t pgoffset);

static void*__libc_mmap64(void*addr,size_t len,int prot,int flags,int fd,off64_t offset);
static void*__libc_mmap64(void*addr,size_t len,int prot,int flags,int fd,off64_t offset) {
  if (offset&(
             4096UL
                      -1)) {
    errno=-
          22
                ;
    return 
          ((void *) -1)
                    ;
  }
  return __mmap2(addr,len,prot,flags,fd,offset>>
                                               12
                                                         );
}

static void*mmap64(void*addr,size_t len,int prot,int flags,int fd,off64_t offset)
static __attribute__((alias("__libc_mmap64")));


typedef int mqd_t;
struct mq_attr {
  long mq_flags;
  long mq_maxmsg;
  long mq_msgsize;
  long mq_curmsgs;
  long __reserved[4];
};









static mqd_t mq_open(const char *name, int oflag, ...) ;
static int mq_unlink(const char *name) ;
static int mq_send(mqd_t mqdes, const char *msg_ptr, size_t msg_len, unsigned msg_prio) ;
static int mq_timedsend(mqd_t mqdes, const char *msg_ptr, size_t msg_len, unsigned msg_prio,
   const struct timespec *abs_timeout) ;
static ssize_t mq_receive(mqd_t mqdes, char *msg_ptr, size_t msg_len, unsigned *msg_prio) ;
static ssize_t mq_timedreceive(mqd_t mqdes, char *__restrict__ msg_ptr, size_t msg_len,
   unsigned *__restrict__ msg_prio, const struct timespec *__restrict__ abs_timeout) ;
static int mq_notify(mqd_t mqdes, const struct sigevent *notification) ;
static int mq_getattr(mqd_t mqdes, struct mq_attr *mqstat) ;
static int mq_setattr(mqd_t mqdes, const struct mq_attr *__restrict__ mqstat, struct mq_attr *__restrict__ omqstat) ;




static int mq_getattr(mqd_t mqdes, struct mq_attr *mqstat) {
  return mq_setattr(mqdes, 
                          (void*)0
                              , mqstat);
}



static ssize_t mq_receive(mqd_t mqdes, char *msg_ptr, size_t msg_len, unsigned int *msg_prio) {
  return mq_timedreceive(mqdes, msg_ptr, msg_len, msg_prio, 
                                                           (void*)0
                                                               );
}



static int mq_send (mqd_t mqdes, const char *msg_ptr, size_t msg_len, unsigned int msg_prio) {
  return mq_timedsend(mqdes, msg_ptr, msg_len, msg_prio, 
                                                        (void*)0
                                                            );
}










struct msqid_ds {
  struct ipc_perm msg_perm;
  struct msg *msg_first;
  struct msg *msg_last;
  time_t msg_stime;
  time_t msg_rtime;
  time_t msg_ctime;
  unsigned long msg_lcbytes;
  unsigned long msg_lqbytes;
  unsigned short msg_cbytes;
  unsigned short msg_qnum;
  unsigned short msg_qbytes;
  pid_t msg_lspid;
  pid_t msg_lrpid;
};


struct msgbuf {
 long mtype;
 char mtext[1];
};


struct msginfo {
 int msgpool;
 int msgmap;
 int msgmax;
 int msgmnb;
 int msgmni;
 int msgssz;
 int msgtql;
 unsigned short msgseg;
};





 int msgctl (int msqid, int cmd, struct msqid_ds *buf) ;
 int msgget (key_t key, int msgflg) ;
 int msgrcv (int msqid, void *msgp, size_t msgsz, long int msgtyp, int msgflg) ;
 int msgsnd (int msqid, const void *msgp, size_t msgsz, int msgflg) ;



 
      int __ipc(int,int,int,int,void*);

static int msgctl(int msqid, int cmd, struct msqid_ds *buf) {
  return __ipc(
              14
                    ,msqid,cmd,0,buf);
}




 int __ipc(int,key_t,int,int,int);

static int msgget(key_t key,int flag) {
  return __ipc(
              13
                    ,key,flag,0,0);
}




 int __ipc(int,int,size_t,int,void*);

struct ipc_kludge {
  struct msgbuf *msgp;
  long msgtyp;
};

static int msgrcv(int msqid, void *msgp, size_t msgsz, long int msgtyp, int msgflg) {
  struct ipc_kludge tmp;
  tmp.msgp = msgp;
  tmp.msgtyp = msgtyp;
  return __ipc(
              12
                    ,msqid, msgsz, msgflg, &tmp);
}




 int __ipc(int,int,size_t,int,const void*);

static int msgsnd (int msqid, const void *msgp, size_t msgsz, int msgflg) {
  return __ipc(
              11
                    ,msqid, msgsz, msgflg, msgp);
}


static void mtx_destroy(mtx_t* mutex) {

  (void)mutex;
}


static int mtx_init(mtx_t* mutex, int type) {
  mutex->lock=0;
  mutex->type=type;
  return thrd_success;
}





static int mtx_lock(mtx_t* mutex) {
  return mtx_timedlock(mutex,0);
}






static int mtx_timedlock(mtx_t* mutex, const struct timespec* time_point) {
  int i,r;
  do {
    r=__mtx_trylock(mutex,&i);
    if (r!=thrd_busy) return r;
    for (;;) {
      r=futex(&mutex->lock,FUTEX_WAIT,i,time_point,0,0);
      if (r==-1) {
 if (errno==
           11
                      ) { r=0; break; } else
 if (errno==
           145
                    ) return thrd_timedout; else
 if (errno==
           4
                ) continue;
      } else
 break;
    }
  } while (r==0);
  return thrd_error;
}






static int __mtx_trylock(mtx_t* mutex,int* lockval) {
  int i;
  thrd_t me=thrd_current();

  if ((i=__sync_val_compare_and_swap(&mutex->lock,0,1))==0) {
    mutex->owner=me;
    return thrd_success;
  }
  if ((mutex->type&mtx_recursive) && mutex->owner==me) {
    if (__sync_add_and_fetch(&mutex->lock,1)>1000) {
      __sync_add_and_fetch(&mutex->lock,-1);
      return thrd_error;
    }
    return thrd_success;
  }
  if (lockval) *lockval=i;
  return thrd_busy;
}

static int mtx_trylock(mtx_t* mutex) {
  return __mtx_trylock(mutex,
                            (void*)0
                                );
}





static int mtx_unlock(mtx_t* mutex) {
  int i,r;
  thrd_t me=thrd_current();
  if (mutex->lock==0) return thrd_error;
  if ((mutex->type&mtx_recursive) && mutex->owner==me) {
    if (__sync_add_and_fetch(&mutex->lock,-1)==0) {


      mutex->owner=0;
      futex(&mutex->lock,FUTEX_WAKE,1,0,0,0);
    }
    return thrd_success;
  }
  if (__sync_val_compare_and_swap(&mutex->lock,1,0)==1)
    futex(&mutex->lock,FUTEX_WAKE,1,0,0,0);
  return thrd_success;
}







static int nice(int incr) {
  int prio;
  int res;
  errno=0;
  prio = getpriority(
                    0
                                ,0) + incr;
  if (prio < 
            (-20)
                    ) prio=
                           (-20)
                                   ;
  if (prio >= 
             20
                     ) prio=
                            20
                                    -1;
  if (setpriority (
                  0
                              , 0, prio)==-1) {
    if (errno==
              13
                    ) errno=
                            1
                                 ;
    return -1;
  } else
    return getpriority(
                      0
                                  , 0);
}







static int __libc_open64(const char* file,int oflag,int mode);
static int __libc_open64(const char* file,int oflag,int mode) {
  return open(file,oflag|
                        0x2000
                                   ,mode);
}

static int open64(const char* file,int oflag,...) __attribute__((alias("__libc_open64")));







static DIR* opendir ( const char* name ) {
  int fd = open (name, 
                        0x0000 
                                 | 
                                   0x10000
                                              );
  DIR* t = 
            (void*)0
                ;

  if ( fd >= 0 ) {
    if (fcntl (fd, 
                  2
                         , 
                           1
                                     ) < 0)
      goto lose;
    t = (DIR *) mmap (
                     (void*)0
                         , 
                           4096UL
                                    , 
                                      0x1 
                                                | 
                                                  0x2
                                                            ,
  
 0x02 
             | 
               0x0800
                            , -1, 0);
    if (t == 
            ((void *) -1)
                      )
lose:
      close (fd);
    else
      t->fd = fd;
  }


  return t;
}
 const char __sys_err_unknown [];

static void perror ( const char* prepend )
{
    register const char* message = __sys_err_unknown;

    if ( (unsigned int) errno < (unsigned int) 
                                              ((168) + 1) 
                                                         )
        message = sys_errlist [errno];

    if (prepend) {
      write ( 2, prepend, strlen(prepend) );
      write ( 2, ": ", 2 );
    }
    write ( 2, message, strlen(message) );
    write ( 2, "\n", 1 );
}



 size_t __pread(int fd, void *buf, size_t count, int dummy, off_t a, off_t b);

static size_t __libc_pread(int fd, void *buf, size_t count, off_t offset);
static size_t __libc_pread(int fd, void *buf, size_t count, off_t offset) {
  return __pread(fd,buf,count,0,0
                               , 
                               offset);
}

static int pread(int fd, void *buf, size_t count, off_t offset) __attribute__((alias("__libc_pread")));




static int posix_fallocate(int fd, off64_t offset, off64_t len) {
  return fallocate(fd,0,offset,len);
}




static int putenv(const char *string) {
  size_t len;
  size_t i, envc;
  int remove=0;
  char *tmp;
  const char **ep;
  char **newenv;
  static char **origenv;
  if (!origenv) origenv=environ;



  if (!(tmp=strchr(string,'='))) {
    len=strlen(string);
    remove=1;
  } else
    len=tmp-string;


  ep=(const char**)environ;
  if (!ep) return 0;
  for (i=envc=0, ep[i]; ep[i]; ++i) {


    if (*string == ep[i][0] && !memcmp(string,ep[i],len) && ep[i][len]=='=') {


      if (remove) continue;


      ep[envc++]=string;
      remove=1;
    } else
      ep[envc++]=ep[i];
  }
  if (remove==0) {


    newenv = (char**) realloc(environ==origenv?0:environ,
         (envc+2)*sizeof(char*));
    if (!newenv) return -1;
    if (envc && (environ==origenv)) {
      memcpy(newenv,origenv,envc*sizeof(char*));
    }
    newenv[envc++]=(char*)string;
    environ=newenv;
  }
  environ[envc]=0;
  return 0;
}
static int pselect(int n, fd_set* readfds, fd_set* writefds, fd_set* exceptfds,
            const struct timespec *timeout, const sigset_t *sigmask) {
  struct timeval t;
  sigset_t old;
  int r;
  if (timeout) {
    t.tv_sec=timeout->tv_sec;
    t.tv_usec=timeout->tv_nsec/1000;
    if (!t.tv_sec && !t.tv_usec && timeout->tv_nsec) ++t.tv_usec;
  }
  if (sigmask)
    sigprocmask(
               3
                          ,sigmask,&old);
  r=select(n,readfds,writefds,exceptfds,
    timeout?&t:0);
  if (sigmask)
    sigprocmask(
               3
                          ,&old,0);
  return r;
}



 size_t __pwrite(int fd, void *buf, size_t count, int dummy, off_t a, off_t b);

static size_t __libc_pwrite(int fd, void *buf, size_t count, off_t offset);
static size_t __libc_pwrite(int fd, void *buf, size_t count, off_t offset) {
  return __pwrite(fd,buf,count,0,0
                                , 
                                offset);
}

static int pwrite(int fd, void *buf, size_t count, off_t offset) __attribute__((alias("__libc_pwrite")));



 int rand_i(void) 
                       
                              ;

static void exch(char* base,size_t size,size_t a,size_t b) {
  char* x=base+a*size;
  char* y=base+b*size;
  while (size) {
    char z=*x;
    *x=*y;
    *y=z;
    --size; ++x; ++y;
  }
}






static void quicksort(char* base,size_t size,ssize_t l,ssize_t r,
        int (*compar)(const void*,const void*)) {
  ssize_t i=l-1, j=r, p=l-1, q=r, k;
  char* v=base+r*size;
  if (r<=l) return;
  exch(base,size,l+(rand_i()%(r-l)),r);
  for (;;) {
    while (++i != r && compar(base+i*size,v)<0) ;
    while (compar(v,base+(--j)*size)<0) if (j == l) break;
    if (i >= j) break;
    exch(base,size,i,j);
    if (compar(base+i*size,v)==0) exch(base,size,++p,i);
    if (compar(v,base+j*size)==0) exch(base,size,j,--q);
  }
  exch(base,size,i,r); j = i-1; ++i;
  for (k=l; k<p; k++, j--) exch(base,size,k,j);
  for (k=r-1; k>q; k--, i++) exch(base,size,i,k);
  quicksort(base,size,l,j,compar);
  quicksort(base,size,i,r,compar);
}

static void qsort(void* base,size_t nmemb,size_t size,int (*compar)(const void*,const void*)) {

  if (nmemb >= (((size_t)-1)>>1) ||
      size >= (((size_t)-1)>>1)) return;







  if (nmemb>1)
    quicksort(base,size,0,nmemb-1,compar);
}




static int raise(int sig) {
  return kill(getpid(),sig);
}


static unsigned int seed=1;

static int rand(void) {
  return rand_r(&seed);
}

void srand(unsigned int i) { seed=i?i:23; }

static int random(void) __attribute__((leaf, nothrow, alias("rand")));
static void srandom(unsigned int i) __attribute__((leaf, nothrow, alias("srand")));


static randbuf rand48buf;




static randbuf a = { 0xE66D, 0xDEEC, 0x5 };
static unsigned short c = 0xB;

static void calc_next(randbuf buf) {
 randbuf tmp;
 long t;
 t = buf[0] * a[0] + c;
 tmp[0] = t & 0xffff;
 tmp[1] = (t >> 16) & 0xffff;
 t = buf[1] * a[0] + buf[0] * a[1] + tmp[1];
 tmp[1] = t & 0xffff;
 tmp[2] = (t >> 16) & 0xffff;
 t = buf[2] * a[0] + buf[1] * a[1] + buf[0] * a[2] + tmp[2];
 tmp[2] = t & 0xffff;
 buf[0] = tmp[0];
 buf[1] = tmp[1];
 buf[2] = tmp[2];
}

static double drand48(void) {
 return erand48(rand48buf);
}

static long lrand48(void) {
 return nrand48(rand48buf);
}

static long mrand48(void) {
 return jrand48(rand48buf);
}

static void srand48(long seed) {
 rand48buf[1] = (seed >> 16) & 0xffff;
 rand48buf[2] = seed & 0xffff;
 rand48buf[0] = 0x330e;
 a[0] = 0xE66D;
 a[1] = 0xDEEC;
 a[2] = 0x5;
 c = 0xB;
}

static unsigned short *seed48(randbuf buf) {
 static randbuf oldx;
 int i;
 for (i = 0; i < 3; i++) {
  oldx[i] = rand48buf[i];
  rand48buf[i] = buf[i];
 }
 a[0] = 0xE66D;
 a[1] = 0xDEEC;
 a[2] = 0x5;
 c = 0xB;
 return (unsigned short *)&oldx;
}

static void lcong48(unsigned short param[7]) {
 int i;
 for (i = 0; i < 3; i++) {
  rand48buf[i] = param[i];
  a[i] = param[i + 3];
 }
 c = param[6];
}

static long jrand48(randbuf buf) {
 long ret;
 ret = buf[2] << 16 | buf[1];
 calc_next(buf);
 return ret;
}

static long nrand48(randbuf buf) {
 return jrand48(buf) & 0x7FFFFFFFL;
}

static double erand48(randbuf buf) {
 double ret;
 ret = ((buf[0] / 65536.0 + buf[1]) / 65536.0 + buf[2]) / 65536.0;
 calc_next(buf);
 return ret;
}




 int rand_i(void) 
                       
                              ;

static unsigned int seed;

static int rand_i(void) {
  if (seed==0) {
    const int* tmp=(const int*)getauxval(AT_RANDOM);
    if (tmp)
      seed=tmp[3];
    else
      seed=(uintptr_t)&seed;
  }
  return rand_r(&seed);
}









typedef int8_t int_least8_t;
typedef int16_t int_least16_t;
typedef int32_t int_least32_t;
typedef int64_t int_least64_t;

typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;
typedef uint32_t uint_least32_t;
typedef uint64_t uint_least64_t;

typedef signed char int_fast8_t;
typedef signed long int int_fast16_t;
typedef signed long int int_fast32_t;
typedef int64_t int_fast64_t;

typedef unsigned char uint_fast8_t;
typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef uint64_t uint_fast64_t;
typedef unsigned int wint_t;






static int rand_r(unsigned int* seed)
{ int32_t X;

    X = *seed;
    X = 48271*(X%44488) - 3399 * (int32_t) (X/44488);
    if (X < 0)
 X += ((1U<<31) -1);

    *seed = X;
    return X;
}






static struct dirent tmp;

struct dirent* readdir(DIR *d) {
  struct dirent* ld;
  if (readdir_r(d,&tmp,&ld)) return 0;
  return ld;
}







struct dirent64* readdir64(DIR *d) {

  static int trygetdents64=1;

  struct dirent* o;
  static struct dirent64 d64;

again:
  if (!trygetdents64) {

    if (!d->num || (d->cur += ((struct dirent*)(d->buf+d->cur))->d_reclen)>=d->num) {
      int res=getdents(d->fd,(struct dirent*)d->buf, sizeof (d->buf)-1);
      if (res<=0) return 0;
      d->num=res; d->cur=0;
    }
    o=(struct dirent*)(d->buf+d->cur);
    d64.d_ino=o->d_ino;
    d64.d_off=o->d_off;
    d64.d_reclen=o->d_reclen;
    strcpy(d64.d_name,o->d_name);
    d64.d_type=0;
    return &d64;

  }
  if (!d->num || (d->cur += ((struct dirent64*)(d->buf+d->cur))->d_reclen)>=d->num) {
    int res=getdents64(d->fd,(struct dirent64*)d->buf,sizeof (d->buf));
    if (res<=0) {
      if (errno==
                89
                      ) {
 trygetdents64=0;
 goto again;
      }
      return 0;
    }
    d->num=res; d->cur=0;
  }
  return (struct dirent64*)(d->buf+d->cur);

}
struct linux_dirent {
  uint32_t d_ino;
  off_t d_off;
  uint16_t d_reclen;
  char d_name[1];
};


static int readdir_r(DIR *d,struct dirent* entry, struct dirent** result) {
  struct linux_dirent* ld;
  *result=0;
  ld=(struct linux_dirent*)(d->buf+d->cur);
  if (!d->num || d->cur >= d->num || (d->cur += ld->d_reclen)>=d->num) {
    int res=getdents(d->fd,(struct dirent*)d->buf,sizeof (d->buf)-1);
    if (res<=0)
      return res<0;
    d->num=res; d->cur=0;
  }
  ld=(struct linux_dirent*)(d->buf+d->cur);

  if (ld->d_reclen < 
                    ((size_t) &((
                    struct linux_dirent
                    *)0)->
                    d_name
                    )
                                                        +1)
    return 0;
  *result=entry;
  entry->d_ino=ld->d_ino;
  entry->d_off=ld->d_off;
  entry->d_reclen=ld->d_reclen;



  entry->d_type=ld->d_name[ld->d_reclen-
                                       ((size_t) &((
                                       struct linux_dirent
                                       *)0)->
                                       d_name
                                       )
                                                                           -1];

  memcpy(entry->d_name,ld->d_name,ld->d_reclen-
                                              ((size_t) &((
                                              struct linux_dirent
                                              *)0)->
                                              d_name
                                              )
                                                                                  );
  return 0;
}






typedef uint64_t ulll;


static void* reallocarray(void* ptr, size_t nmemb, size_t size) {

  typedef char compile_time_assertion[(sizeof(ulll)>=sizeof(size_t)*2)-1];

  ulll l=(ulll)nmemb * size;
  if ((size_t)l != l) return 0;
  return realloc(ptr,(size_t)l);
}







static int reboot (int flag);



static int __reboot(unsigned int magic1, unsigned int magic2, int cmd);

static int reboot(int cmd)
{
  return __reboot(
                 0xfee1dead
                                    , 
                                      672274793
                                                         , cmd);
}




 int socketcall(int callno,long* args);

static int __libc_recv(int a, const void * b, size_t c, int flags);
static int __libc_recv(int a, const void * b, size_t c, int flags) {
  long args[] = { a, (long) b, c, flags };
  return socketcall(10, args);
}

static int recv(int a, const void * b, size_t c, int flags)
  __attribute__ (( alias("__libc_recv")));






 int socketcall(int callno,long* args);

static int __libc_recvfrom(int a, const void * b, size_t c, int flags, void *to, void *tolen);
static int __libc_recvfrom(int a, const void * b, size_t c, int flags, void *to, void *tolen) {
  long args[] = { a, (long) b, c, flags, (long) to, (long) tolen };
  return socketcall(12, args);
}

static int recvfrom(int a, const void * b, size_t c, int flags, void *to, void *tolen)
 __attribute__ ((alias("__libc_recvfrom"))) ;







static int remove(const char* filename) {
  if (unlink(filename)) {
    if (errno==
              21
                    )
      return rmdir(filename);
    return -1;
  }
  return 0;
}




 int socketcall(int callno,long* args);

static int __libc_recvmsg(int a, struct msghdr* msg, int flags);
static int __libc_recvmsg(int a, struct msghdr* msg, int flags) {
  long args[] = { a, (long) msg, flags };
  return socketcall(17, args);
}

static int recvmsg(int a, struct msghdr *msg, int flags)
 __attribute__ ((alias("__libc_recvmsg"))) ;




static void rewind( FILE *stream) {
  fseek(stream, 0L, 
                   0
                           );
}




static void rewinddir(DIR *d) {
  if (lseek(d->fd,0,
                   0
                           ) != (off_t)-1)
    d->num=d->cur=0;
}


 int __libc_brk(void *end_data_segment);

 void* __curbrk;

static void* __libc_sbrk(ptrdiff_t increment);
static void* __libc_sbrk(ptrdiff_t increment) {
  void* oldbrk;
  if (__curbrk==0)
    if (__libc_brk(0) < 0)
      return (void*)-1;
  if (increment==0)
    return __curbrk;
  oldbrk=__curbrk;
  if (__libc_brk((char*)oldbrk+increment)<0)
    return (void*)-1;
  return oldbrk;
}

static void* sbrk (ptrdiff_t increment) __attribute__((alias("__libc_sbrk")));




static char* secure_getenv(const char* name) {
  if (getauxval(AT_SECURE))
    return 
          (void*)0
              ;
  return getenv(name);
}




static void seekdir(DIR *d,off_t offset) {
  if (lseek(d->fd,offset,
                        0
                                ) != (off_t)-1) {
    d->num=d->cur=0;
    ((struct dirent *)(d->buf))->d_off = offset;
  }
}



 int __ipc(int,int,int,int,void*);

union semun {
  int val;
  struct semid_ds *buf;
  unsigned short *array;
  struct seminfo *__buf;
  void *__pad;
};

static int semctl(int semid, int semnum, int cmd, union semun arg);
static int semctl(int semid, int semnum, int cmd, union semun arg) {
  return __ipc(
              3
                    ,semid,semnum,cmd,&arg);
}









struct semid_ds {
  struct ipc_perm sem_perm;
  time_t sem_otime;
  time_t sem_ctime;
  struct sem *sem_base;
  struct sem_queue *sem_pending;
  struct sem_queue **sem_pending_last;
  struct sem_undo *undo;
  uint16_t sem_nsems;
};


struct sembuf {
  uint16_t sem_num;
  int16_t sem_op;
  int16_t sem_flg;
};
struct seminfo {
  int32_t semmap;
  int32_t semmni;
  int32_t semmns;
  int32_t semmnu;
  int32_t semmsl;
  int32_t semopm;
  int32_t semume;
  int32_t semusz;
  int32_t semvmx;
  int32_t semaem;
};







 int semget( key_t key, int nsems, int semflg) ;




 int semctl(int semid, int semnum, int cmd, ...) ;

 int semop(int semid, struct sembuf *sops, unsigned nsops) ;



 
      int __ipc(int,key_t,int,int,int);

static int semget(key_t key, int nsems, int semflg) {
  return __ipc(
              2
                    ,key,nsems,semflg,0);
}




 int __ipc(int,int,unsigned,int,void*);

static int semop(int semid,struct sembuf *sops,unsigned nsops) {
  return __ipc(
              1
                   ,semid,nsops,0,sops);
}




 int socketcall(int callno,long* args);

static int __libc_sendmsg(int a, const struct msghdr* msg, int flags);
static int __libc_sendmsg(int a, const struct msghdr* msg, int flags) {
  long args[] = { a, (long) msg, flags };
  return socketcall(16, args);
}

static int sendmsg(int a, const struct msghdr *msg, int flags)
 __attribute__ ((alias("__libc_sendmsg"))) ;






 int socketcall(int callno,long* args);

static int __libc_send(int a, const void * b, size_t c, int flags);
static int __libc_send(int a, const void * b, size_t c, int flags) {
  long args[] = { a, (long) b, c, flags };
  return socketcall(9, args);
}

static int send(int a, const void * b, size_t c, int flags)
  __attribute__ (( alias("__libc_send")));






 int socketcall(int callno,long* args);

static int __libc_sendto(int a, const void * b, size_t c, int flags, void *to, int tolen);
static int __libc_sendto(int a, const void * b, size_t c, int flags, void *to, int tolen) {
  long args[] = { a, (long) b, c, flags, (long) to, tolen };
  return socketcall(11, args);
}

static int sendto(int a, const void * b, size_t c, int flags, const struct sockaddr* to, socklen_t tolen)
  __attribute__ (( alias("__libc_sendto")));






static void setlinebuf(FILE* stream);

static void setlinebuf(FILE* stream) {
  setvbuf(stream,0,
                  1
                        ,
                         1024
                               );
}

asm (".section .gnu.warning." "setlinebuf" "\n\t.string \"" "warning: you used setlinebuf without including <stdio.h>" "\"\n\t.previous");


static int setpgrp()
{
  return setpgid(0,0);
}




 int socketcall(int callno,long* args);

static int __libc_setsockopt(int a, int b, int c, void *d, void *e);
static int __libc_setsockopt(int a, int b, int c, void *d, void *e) {
  long args[] = { a, b, c, (long)d, (long) e };
  return socketcall(14, args);
}

static int setsockopt(int s, int level, int optname, const void* optval, socklen_t optlen) __attribute__((alias("__libc_setsockopt")));






 void* __ipc(int,int,int,void*,const void*);

static void* shmat(int shmid,const void* shmaddr,int shmflg) {
  void* raddr;
  register void* result;
  result=__ipc(
              21
                   ,shmid,shmflg,&raddr,shmaddr);
  if ((unsigned long)result <= -(unsigned long)8196)
    result=raddr;
  return result;
}




 int __ipc(int,int,int,int,void*);

static int shmctl(int shmid, int cmd, struct shmid_ds *buf) {
  return __ipc(
              24
                    ,shmid,cmd,0,buf);
}




 int __ipc(int,int,int,int,const void*);

static int shmdt(const void* shmaddr) {
  return __ipc(
              22
                   ,0,0,0,shmaddr);
}




 int __ipc(int,key_t,int,int,int);

static int shmget(key_t key, int size, int shmflg) {
  return __ipc(
              23
                    ,key,size,shmflg,0);
}




 int socketcall(int callno,long* args);

static int __libc_shutdown(int s, int how);
static int __libc_shutdown(int s, int how) {
  long args[] = { s, (long) how, 0 };
  return socketcall(13, args);
}

static int shutdown(int s, int how) __attribute__((alias("__libc_shutdown")));




static int __rt_sigaction(int signum, const struct sigaction *act, struct sigaction *oldact, long nr);

static int __libc_sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
static int __libc_sigaction(int signum, const struct sigaction *act, struct sigaction *oldact) {
  return __rt_sigaction(signum, act, oldact, 
                                            128
                                                 /8);
}

static int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact)
static __attribute__((alias("__libc_sigaction")));






static int sigaddset(sigset_t *set, int signo) {
  if ((signo<1)||(signo>
                       (128 -1)
                               )) {
    (*__errno_location())=
                         22
                               ;
    return -1;
  } else {
    unsigned long __mask = ( ((unsigned long)1) << (((signo)-1) % (8*sizeof(unsigned long))) );
    unsigned long __word = ( ((signo)-1) / (8*sizeof(unsigned long)) );
    set->sig[__word]|=__mask;
    return 0;
  }
}



static int sigandset(sigset_t*set,const sigset_t*left,const sigset_t*right)
{
  set->sig[0]=left->sig[0]&right->sig[0];
  if (
     (1024 / (8 * sizeof (unsigned long int)))
                  >1) set->sig[1]=left->sig[1]&right->sig[1];
  if (
     (1024 / (8 * sizeof (unsigned long int)))
                  >2) {
    set->sig[2]=left->sig[2]&right->sig[2];
    set->sig[3]=left->sig[3]&right->sig[3];
  }
  return 0;
}






static int sigdelset(sigset_t *set, int signo) {
  if ((signo<1)||(signo>
                       (128 -1)
                               )) {
    (*__errno_location())=
                         22
                               ;
    return -1;
  } else {
    unsigned long __mask = ( ((unsigned long)1) << (((signo)-1) % (8*sizeof(unsigned long))) );
    unsigned long __word = ( ((signo)-1) / (8*sizeof(unsigned long)) );
    set->sig[__word]&=~__mask;
    return 0;
  }
}


static int sigemptyset(sigset_t *set) {
  set->sig[0]=0;
  if (
     (1024 / (8 * sizeof (unsigned long int)))
                  >1) set->sig[1]=0;
  if (
     (1024 / (8 * sizeof (unsigned long int)))
                  >2) {
    set->sig[2]=0;
    set->sig[3]=0;
  }
  return 0;
}



static int sigfillset(sigset_t *set) {
  set->sig[0]=(unsigned long)-1;
  if (
     (1024 / (8 * sizeof (unsigned long int)))
                  >1) set->sig[1]=(unsigned long)-1;
  if (
     (1024 / (8 * sizeof (unsigned long int)))
                  >2) {
    set->sig[2]=(unsigned long)-1;
    set->sig[3]=(unsigned long)-1;
  }
  return 0;
}


static int siginterrupt(int sig, int flag) {
  int ret;
  struct sigaction act;

  sigaction(sig, 0, &act);

  if (flag)
    act.sa_flags &= ~
                    0x10000000
                              ;
  else
    act.sa_flags |= 
                   0x10000000
                             ;

  ret = sigaction(sig, &act, 0);

  return ret;
}



static int sigisemptyset(const sigset_t*set)
{
  unsigned long ret;
  ret=set->sig[0];
  if (
     (1024 / (8 * sizeof (unsigned long int)))
                  >1) ret|=set->sig[1];
  if (
     (1024 / (8 * sizeof (unsigned long int)))
                  >2) {
    ret|=set->sig[2];
    ret|=set->sig[3];
  }
  return ret != 0;
}






static int sigismember(const sigset_t *set, int signo) {
  if ((signo<1)||(signo>
                       (128 -1)
                               )) {
    (*__errno_location())=
                         22
                               ;
    return -1;
  } else {
    unsigned long __mask = ( ((unsigned long)1) << (((signo)-1) % (8*sizeof(unsigned long))) );
    unsigned long __word = ( ((signo)-1) / (8*sizeof(unsigned long)) );
    return (set->sig[__word] & __mask)?1:0;
  }
}



static int __sigjmp_save(sigjmp_buf env,int savemask);
static int __sigjmp_save(sigjmp_buf env,int savemask) {
  env[0].__mask_was_saved = 0;
  if (savemask) {
    env[0].__mask_was_saved=(sigprocmask(
                                        1
                                                 ,(sigset_t*)0,&env[0].__saved_mask)==0);
  }
  return 0;
}


static sighandler_t signal(int signum, sighandler_t action) {
  struct sigaction sa,oa;
  sa.
    _u._sa_handler
              =action;
  sigemptyset(&sa.sa_mask);
  if (sigaddset(&sa.sa_mask,signum) != 0)
    return 
          ((sighandler_t)-1L)
                 ;
  sa.sa_flags = 
               0x40000000
                         ;
  if (sigaction(signum,&sa,&oa) != 0)
    return 
          ((sighandler_t)-1L)
                 ;
  return oa.
           _u._sa_handler
                     ;
}








struct signalfd_siginfo {
  uint32_t ssi_signo;
  int32_t ssi_errno;
  int32_t ssi_code;
  uint32_t ssi_pid;
  uint32_t ssi_uid;
  int32_t ssi_fd;
  uint32_t ssi_tid;
  uint32_t ssi_band;
  uint32_t ssi_overrun;
  uint32_t ssi_trapno;
  int32_t ssi_status;
  int32_t ssi_int;
  uint64_t ssi_ptr;
  uint64_t ssi_utime;
  uint64_t ssi_stime;
  uint64_t ssi_addr;
  uint8_t __pad[48];
};



 int signalfd (int __fd, const sigset_t *__mask, int __flags)
   __attribute__ ((__nonnull__ (2))) ;




 
      int __signalfd(int fd,const sigset_t* mask,size_t nsig);
 int __signalfd4(int fd,const sigset_t* mask,size_t nsig, int flags);

static int signalfd(int fd,const sigset_t* mask,int flags) {
  int r=__signalfd4(fd,mask,
                           128
                                /8,flags);
  if (r==-1 && errno==
                     89
                           ) {
    r=__signalfd(fd,mask,
                        32
                            /8);
    if (r!=-1 && flags) {
      int x;
      x=fcntl(r,
               2
                      ,flags);
      if (x==-1)
 close(r);
    }
  }
  return r;
}



static int sigorset(sigset_t*set,const sigset_t*left,const sigset_t*right)
{
  set->sig[0]=left->sig[0]|right->sig[0];
  if (
     (1024 / (8 * sizeof (unsigned long int)))
                  >1) set->sig[1]=left->sig[1]|right->sig[1];
  if (
     (1024 / (8 * sizeof (unsigned long int)))
                  >2) {
    set->sig[2]=left->sig[2]|right->sig[2];
    set->sig[3]=left->sig[3]|right->sig[3];
  }
  return 0;
}


static int __rt_sigpending(sigset_t *set, long nr);

static int sigpending(sigset_t *set) {
  return __rt_sigpending(set, 
                             128
                                  /8);
}


static int __rt_sigprocmask(int how, const sigset_t *set, sigset_t *oldsetm, long nr);

static int sigprocmask(int how, const sigset_t *set, sigset_t *oldset) {
  return __rt_sigprocmask(how, set, oldset, 
                                           128
                                                /8);
}


static int __rt_sigqueueinfo(pid_t pid, int sig, siginfo_t *info);

static int sigqueueinfo(pid_t pid, int sig, siginfo_t *info) {
  return __rt_sigqueueinfo(pid, sig, info);
}


static int __rt_sigsuspend(const sigset_t *mask, long nr);

static int __libc_sigsuspend(const sigset_t *mask);
static int __libc_sigsuspend(const sigset_t *mask) {
  return __rt_sigsuspend(mask, 
                              128
                                   /8);
}

static int sigsuspend(const sigset_t *mask) __attribute__((alias("__libc_sigsuspend")));


static int __rt_sigtimedwait(const sigset_t *set, siginfo_t *info, const struct timespec *ts, long nr);

static int sigtimedwait(const sigset_t *set, siginfo_t *info, const struct timespec *ts) {
  return __rt_sigtimedwait(set,info,ts,
                                      128
                                           /8);
}


static int sigwait(const sigset_t* set,int* sig) {
  siginfo_t si;
  int r=
       sigtimedwait((
       set
       ),(
       &si
       ),0)
                           ;
  if (r!=-1) *sig=si.si_signo;
  return r;
}








typedef enum { FIND, ENTER } ACTION;
typedef struct entry { char* key; void* data; } ENTRY;

 ENTRY* hsearch(ENTRY item, ACTION action) ;
 int hcreate(size_t count) ;
 void hdestroy(void) ;





struct bucket {
  struct bucket* next;
  struct entry e;
  size_t hv;
};




struct hsearch_data {
  struct bucket** table;
  size_t size, filled;
  unsigned char key[16];
};

 int hsearch_r(ENTRY item, ACTION action, ENTRY** retval, struct hsearch_data* htab) ;
 int hcreate_r(size_t count, struct hsearch_data* htab) ;
 void hdestroy_r(struct hsearch_data* htab) ;

 uint64_t siphash24(const unsigned char key[16], const unsigned char *in, size_t len) ;






static uint64_t
static U8TO64_LE(const unsigned char *p) {
 return *(const uint64_t *)p;
}

static uint64_t
static siphash24(const unsigned char key[16], const unsigned char *m, size_t len) {
 uint64_t v0, v1, v2, v3;
 uint64_t mi, k0, k1;
 uint64_t last7;
 size_t i, blocks;

 k0 = U8TO64_LE(key + 0);
 k1 = U8TO64_LE(key + 8);
 v0 = k0 ^ 0x736f6d6570736575ull;
 v1 = k1 ^ 0x646f72616e646f6dull;
 v2 = k0 ^ 0x6c7967656e657261ull;
 v3 = k1 ^ 0x7465646279746573ull;

 last7 = (uint64_t)(len & 0xff) << 56;
 for (i = 0, blocks = (len & ~7); i < blocks; i += 8) {
  mi = U8TO64_LE(m + i);
  v3 ^= mi;
  v0 += v1; v2 += v3; v1 = (((v1)<<(13))|((v1)>>(64-13))); v3 = (((v3)<<(16))|((v3)>>(64-16))); v1 ^= v0; v3 ^= v2; v0 = (((v0)<<(32))|((v0)>>(64-32))); v2 += v1; v0 += v3; v1 = (((v1)<<(17))|((v1)>>(64-17))); v3 = (((v3)<<(21))|((v3)>>(64-21))); v1 ^= v2; v3 ^= v0; v2 = (((v2)<<(32))|((v2)>>(64-32)));
  v0 += v1; v2 += v3; v1 = (((v1)<<(13))|((v1)>>(64-13))); v3 = (((v3)<<(16))|((v3)>>(64-16))); v1 ^= v0; v3 ^= v2; v0 = (((v0)<<(32))|((v0)>>(64-32))); v2 += v1; v0 += v3; v1 = (((v1)<<(17))|((v1)>>(64-17))); v3 = (((v3)<<(21))|((v3)>>(64-21))); v1 ^= v2; v3 ^= v0; v2 = (((v2)<<(32))|((v2)>>(64-32)));
  v0 ^= mi;
 }

 switch (len - blocks) {
  case 7: last7 |= (uint64_t)m[i + 6] << 48;
  case 6: last7 |= (uint64_t)m[i + 5] << 40;
  case 5: last7 |= (uint64_t)m[i + 4] << 32;
  case 4: last7 |= (uint64_t)m[i + 3] << 24;
  case 3: last7 |= (uint64_t)m[i + 2] << 16;
  case 2: last7 |= (uint64_t)m[i + 1] << 8;
  case 1: last7 |= (uint64_t)m[i + 0] ;
  case 0:
  default:;
 };
 v3 ^= last7;
 v0 += v1; v2 += v3; v1 = (((v1)<<(13))|((v1)>>(64-13))); v3 = (((v3)<<(16))|((v3)>>(64-16))); v1 ^= v0; v3 ^= v2; v0 = (((v0)<<(32))|((v0)>>(64-32))); v2 += v1; v0 += v3; v1 = (((v1)<<(17))|((v1)>>(64-17))); v3 = (((v3)<<(21))|((v3)>>(64-21))); v1 ^= v2; v3 ^= v0; v2 = (((v2)<<(32))|((v2)>>(64-32)));
 v0 += v1; v2 += v3; v1 = (((v1)<<(13))|((v1)>>(64-13))); v3 = (((v3)<<(16))|((v3)>>(64-16))); v1 ^= v0; v3 ^= v2; v0 = (((v0)<<(32))|((v0)>>(64-32))); v2 += v1; v0 += v3; v1 = (((v1)<<(17))|((v1)>>(64-17))); v3 = (((v3)<<(21))|((v3)>>(64-21))); v1 ^= v2; v3 ^= v0; v2 = (((v2)<<(32))|((v2)>>(64-32)));
 v0 ^= last7;
 v2 ^= 0xff;
 v0 += v1; v2 += v3; v1 = (((v1)<<(13))|((v1)>>(64-13))); v3 = (((v3)<<(16))|((v3)>>(64-16))); v1 ^= v0; v3 ^= v2; v0 = (((v0)<<(32))|((v0)>>(64-32))); v2 += v1; v0 += v3; v1 = (((v1)<<(17))|((v1)>>(64-17))); v3 = (((v3)<<(21))|((v3)>>(64-21))); v1 ^= v2; v3 ^= v0; v2 = (((v2)<<(32))|((v2)>>(64-32)));
 v0 += v1; v2 += v3; v1 = (((v1)<<(13))|((v1)>>(64-13))); v3 = (((v3)<<(16))|((v3)>>(64-16))); v1 ^= v0; v3 ^= v2; v0 = (((v0)<<(32))|((v0)>>(64-32))); v2 += v1; v0 += v3; v1 = (((v1)<<(17))|((v1)>>(64-17))); v3 = (((v3)<<(21))|((v3)>>(64-21))); v1 ^= v2; v3 ^= v0; v2 = (((v2)<<(32))|((v2)>>(64-32)));
 v0 += v1; v2 += v3; v1 = (((v1)<<(13))|((v1)>>(64-13))); v3 = (((v3)<<(16))|((v3)>>(64-16))); v1 ^= v0; v3 ^= v2; v0 = (((v0)<<(32))|((v0)>>(64-32))); v2 += v1; v0 += v3; v1 = (((v1)<<(17))|((v1)>>(64-17))); v3 = (((v3)<<(21))|((v3)>>(64-21))); v1 ^= v2; v3 ^= v0; v2 = (((v2)<<(32))|((v2)>>(64-32)));
 v0 += v1; v2 += v3; v1 = (((v1)<<(13))|((v1)>>(64-13))); v3 = (((v3)<<(16))|((v3)>>(64-16))); v1 ^= v0; v3 ^= v2; v0 = (((v0)<<(32))|((v0)>>(64-32))); v2 += v1; v0 += v3; v1 = (((v1)<<(17))|((v1)>>(64-17))); v3 = (((v3)<<(21))|((v3)>>(64-21))); v1 ^= v2; v3 ^= v0; v2 = (((v2)<<(32))|((v2)>>(64-32)));
 return v0 ^ v1 ^ v2 ^ v3;
}



static unsigned int sleep(unsigned int secs) {
  struct timespec t;
  t.tv_sec=secs;
  t.tv_nsec=0;
  nanosleep(&t,&t);
  return secs-t.tv_sec;
}




 int socketcall(int callno,long* args);

static int __libc_socket(int a, int b, int c);
static int __libc_socket(int a, int b, int c) {
  long args[] = { a, b, c };
  return socketcall(1, args);
}

static int socket(int a,int b,int c) __attribute__((alias("__libc_socket")));






static int snprintf(char *str,size_t size,const char *format,...)
{
  int n;
  va_list arg_ptr;
  
 __builtin_va_start((
 arg_ptr
 ),(
 format
 ))
                          ;
  n=vsnprintf(str,size,format,arg_ptr);
  
 __builtin_va_end 
        (arg_ptr);
  return n;
}



 int socketcall(int callno,long* args);

static int __libc_socketpair(int a, int type, int protocol, int sv[2]);
static int __libc_socketpair(int a, int type, int protocol, int sv[2]) {
  long args[] = { a, type, protocol, (long)sv };
  return socketcall(8, args);
}

static int socketpair(int d, int type, int protocol, int sv[2])
  __attribute__((alias("__libc_socketpair")));







static int sprintf(char *dest,const char *format,...)
{
  int n;
  va_list arg_ptr;
  
 __builtin_va_start((
 arg_ptr
 ),(
 format
 ))
                          ;
  n=vsprintf(dest,format,arg_ptr);
  
 __builtin_va_end 
        (arg_ptr);
  return n;
}



static int sscanf(const char *str, const char *format, ...)
{
  int n;
  va_list arg_ptr;
  
 __builtin_va_start((
 arg_ptr
 ),(
 format
 ))
                          ;
  n=vsscanf(str,format,arg_ptr);
  
 __builtin_va_end 
        (arg_ptr);
  return n;
}






static ssize_t __write1 ( const char* s ) __attribute__ (( ));
static ssize_t __write2 ( const char* s ) __attribute__ (( ));







static void __stack_smash_handler(char* func,unsigned int damaged);
static void __stack_smash_handler(char* func,unsigned int damaged) {
  char buf[sizeof(char*)*2+1];
  int i;
  for (i=0; i<(int)sizeof(buf)-1; ++i) {
    char c=damaged&0xf;
    c+=c<10?'0':'a';
    buf[sizeof(buf)-2-i]=c;
    damaged>>=4;
  }
  buf[sizeof(buf)-1]=0;
  __write2("stack smashed in ");
  __write2(func);
  __write2(" (value 0x");
  __write2(buf);
  __write2(")\n");
  _exit(127);
}









static ssize_t __write1 ( const char* s ) __attribute__ (( ));
static ssize_t __write2 ( const char* s ) __attribute__ (( ));




static void __stack_chk_fail(void);




static void __stack_chk_fail(void) {
  __write2("smashed stack detected, program terminated.\n");
  _exit(127);
}


 void __stack_chk_fail(void) __attribute__((noreturn));



static void __attribute__((noreturn)) __stack_chk_fail_local(void);




static void __attribute__((noreturn)) __stack_chk_fail_local(void)
{
  __stack_chk_fail ();
}







 char __executable_start;




typedef uint16_t Elf32_Half;
typedef uint16_t Elf64_Half;


typedef uint32_t Elf32_Word;
typedef int32_t Elf32_Sword;
typedef uint32_t Elf64_Word;
typedef int32_t Elf64_Sword;


typedef uint64_t Elf32_Xword;
typedef int64_t Elf32_Sxword;
typedef uint64_t Elf64_Xword;
typedef int64_t Elf64_Sxword;


typedef uint32_t Elf32_Addr;
typedef uint64_t Elf64_Addr;


typedef uint32_t Elf32_Off;
typedef uint64_t Elf64_Off;


typedef uint16_t Elf32_Section;
typedef uint16_t Elf64_Section;


typedef Elf32_Half Elf32_Versym;
typedef Elf64_Half Elf64_Versym;






typedef struct
{
  unsigned char e_ident[(16)];
  Elf32_Half e_type;
  Elf32_Half e_machine;
  Elf32_Word e_version;
  Elf32_Addr e_entry;
  Elf32_Off e_phoff;
  Elf32_Off e_shoff;
  Elf32_Word e_flags;
  Elf32_Half e_ehsize;
  Elf32_Half e_phentsize;
  Elf32_Half e_phnum;
  Elf32_Half e_shentsize;
  Elf32_Half e_shnum;
  Elf32_Half e_shstrndx;
} Elf32_Ehdr;

typedef struct
{
  unsigned char e_ident[(16)];
  Elf64_Half e_type;
  Elf64_Half e_machine;
  Elf64_Word e_version;
  Elf64_Addr e_entry;
  Elf64_Off e_phoff;
  Elf64_Off e_shoff;
  Elf64_Word e_flags;
  Elf64_Half e_ehsize;
  Elf64_Half e_phentsize;
  Elf64_Half e_phnum;
  Elf64_Half e_shentsize;
  Elf64_Half e_shnum;
  Elf64_Half e_shstrndx;
} Elf64_Ehdr;
typedef struct
{
  Elf32_Word sh_name;
  Elf32_Word sh_type;
  Elf32_Word sh_flags;
  Elf32_Addr sh_addr;
  Elf32_Off sh_offset;
  Elf32_Word sh_size;
  Elf32_Word sh_link;
  Elf32_Word sh_info;
  Elf32_Word sh_addralign;
  Elf32_Word sh_entsize;
} Elf32_Shdr;

typedef struct
{
  Elf64_Word sh_name;
  Elf64_Word sh_type;
  Elf64_Xword sh_flags;
  Elf64_Addr sh_addr;
  Elf64_Off sh_offset;
  Elf64_Xword sh_size;
  Elf64_Word sh_link;
  Elf64_Word sh_info;
  Elf64_Xword sh_addralign;
  Elf64_Xword sh_entsize;
} Elf64_Shdr;
typedef struct
{
  Elf32_Word st_name;
  Elf32_Addr st_value;
  Elf32_Word st_size;
  unsigned char st_info;
  unsigned char st_other;
  Elf32_Section st_shndx;
} Elf32_Sym;

typedef struct
{
  Elf64_Word st_name;
  unsigned char st_info;
  unsigned char st_other;
  Elf64_Section st_shndx;
  Elf64_Addr st_value;
  Elf64_Xword st_size;
} Elf64_Sym;




typedef struct
{
  Elf32_Half si_boundto;
  Elf32_Half si_flags;
} Elf32_Syminfo;

typedef struct
{
  Elf64_Half si_boundto;
  Elf64_Half si_flags;
} Elf64_Syminfo;
typedef struct
{
  Elf32_Addr r_offset;
  Elf32_Word r_info;
} Elf32_Rel;






typedef struct
{
  Elf64_Addr r_offset;
  Elf64_Xword r_info;
} Elf64_Rel;



typedef struct
{
  Elf32_Addr r_offset;
  Elf32_Word r_info;
  Elf32_Sword r_addend;
} Elf32_Rela;

typedef struct
{
  Elf64_Addr r_offset;
  Elf64_Xword r_info;
  Elf64_Sxword r_addend;
} Elf64_Rela;
typedef struct
{
  Elf32_Word p_type;
  Elf32_Off p_offset;
  Elf32_Addr p_vaddr;
  Elf32_Addr p_paddr;
  Elf32_Word p_filesz;
  Elf32_Word p_memsz;
  Elf32_Word p_flags;
  Elf32_Word p_align;
} Elf32_Phdr;

typedef struct
{
  Elf64_Word p_type;
  Elf64_Word p_flags;
  Elf64_Off p_offset;
  Elf64_Addr p_vaddr;
  Elf64_Addr p_paddr;
  Elf64_Xword p_filesz;
  Elf64_Xword p_memsz;
  Elf64_Xword p_align;
} Elf64_Phdr;



enum {
  PT_NULL = 0,
  PT_LOAD = 1,
  PT_DYNAMIC = 2,
  PT_INTERP = 3,
  PT_NOTE = 4,
  PT_SHLIB = 5,
  PT_PHDR = 6,
  PT_TLS = 7,
  PT_NUM = 8,
  PT_LOOS = 0x60000000,
  PT_GNU_EH_FRAME = 0x6474e550,
  PT_GNU_STACK = 0x6474e551,
  PT_LOSUNW = 0x6ffffffa,
  PT_SUNWBSS = 0x6ffffffa,
  PT_SUNWSTACK = 0x6ffffffb,
  PT_HISUNW = 0x6fffffff,
  PT_HIOS = 0x6fffffff,
  PT_LOPROC = 0x70000000,
  PT_HIPROC = 0x7fffffff
};
typedef struct
{
  Elf32_Sword d_tag;
  union
    {
      Elf32_Word d_val;
      Elf32_Addr d_ptr;
    } d_un;
} Elf32_Dyn;

typedef struct
{
  Elf64_Sxword d_tag;
  union
    {
      Elf64_Xword d_val;
      Elf64_Addr d_ptr;
    } d_un;
} Elf64_Dyn;
typedef struct
{
  Elf32_Half vd_version;
  Elf32_Half vd_flags;
  Elf32_Half vd_ndx;
  Elf32_Half vd_cnt;
  Elf32_Word vd_hash;
  Elf32_Word vd_aux;
  Elf32_Word vd_next;

} Elf32_Verdef;

typedef struct
{
  Elf64_Half vd_version;
  Elf64_Half vd_flags;
  Elf64_Half vd_ndx;
  Elf64_Half vd_cnt;
  Elf64_Word vd_hash;
  Elf64_Word vd_aux;
  Elf64_Word vd_next;

} Elf64_Verdef;
typedef struct
{
  Elf32_Word vda_name;
  Elf32_Word vda_next;

} Elf32_Verdaux;

typedef struct
{
  Elf64_Word vda_name;
  Elf64_Word vda_next;

} Elf64_Verdaux;




typedef struct
{
  Elf32_Half vn_version;
  Elf32_Half vn_cnt;
  Elf32_Word vn_file;

  Elf32_Word vn_aux;
  Elf32_Word vn_next;

} Elf32_Verneed;

typedef struct
{
  Elf64_Half vn_version;
  Elf64_Half vn_cnt;
  Elf64_Word vn_file;

  Elf64_Word vn_aux;
  Elf64_Word vn_next;

} Elf64_Verneed;
typedef struct
{
  Elf32_Word vna_hash;
  Elf32_Half vna_flags;
  Elf32_Half vna_other;
  Elf32_Word vna_name;
  Elf32_Word vna_next;

} Elf32_Vernaux;

typedef struct
{
  Elf64_Word vna_hash;
  Elf64_Half vna_flags;
  Elf64_Half vna_other;
  Elf64_Word vna_name;
  Elf64_Word vna_next;

} Elf64_Vernaux;
typedef struct
{
  int32_t a_type;
  union
    {
      long int a_val;
      void *a_ptr;
      void (*a_fcn) (void);
    } a_un;
} Elf32_auxv_t;

typedef struct
{
  long int a_type;
  union
    {
      long int a_val;
      void *a_ptr;
      void (*a_fcn) (void);
    } a_un;
} Elf64_auxv_t;
typedef struct
{
  Elf32_Word n_namesz;
  Elf32_Word n_descsz;
  Elf32_Word n_type;
} Elf32_Nhdr;

typedef struct
{
  Elf64_Word n_namesz;
  Elf64_Word n_descsz;
  Elf64_Word n_type;
} Elf64_Nhdr;
typedef struct
{
  Elf32_Xword m_value;
  Elf32_Word m_info;
  Elf32_Word m_poffset;
  Elf32_Half m_repeat;
  Elf32_Half m_stride;
} Elf32_Move;

typedef struct
{
  Elf64_Xword m_value;
  Elf64_Xword m_info;
  Elf64_Xword m_poffset;
  Elf64_Half m_repeat;
  Elf64_Half m_stride;
} Elf64_Move;
typedef union
{
  struct
    {
      Elf32_Word gt_current_g_value;
      Elf32_Word gt_unused;
    } gt_header;
  struct
    {
      Elf32_Word gt_g_value;
      Elf32_Word gt_bytes;
    } gt_entry;
} Elf32_gptab;



typedef struct
{
  Elf32_Word ri_gprmask;
  Elf32_Word ri_cprmask[4];
  Elf32_Sword ri_gp_value;
} Elf32_RegInfo;



typedef struct
{
  unsigned char kind;

  unsigned char size;
  Elf32_Section section;

  Elf32_Word info;
} Elf_Options;
typedef struct
{
  Elf32_Word hwp_flags1;
  Elf32_Word hwp_flags2;
} Elf_Options_Hw;
typedef struct
{
  Elf32_Word l_name;
  Elf32_Word l_time_stamp;
  Elf32_Word l_checksum;
  Elf32_Word l_version;
  Elf32_Word l_flags;
} Elf32_Lib;

typedef struct
{
  Elf64_Word l_name;
  Elf64_Word l_time_stamp;
  Elf64_Word l_checksum;
  Elf64_Word l_version;
  Elf64_Word l_flags;
} Elf64_Lib;
typedef Elf32_Addr Elf32_Conflict;
typedef uint32_t Elf_Symndx;






static char* program_invocation_name;
static char* program_invocation_short_name;


static void* __vdso;

 int main(int argc,char* argv[],char* envp[]);


 
       
                 unsigned long __guard;






 int __valgrind;
static size_t __tdatasize, __tmemsize;
static void* __tdataptr;

static void findtlsdata(long* auxvec) {



  Elf32_Phdr* x=0;

  size_t i,n=0;
  while (*auxvec) {
    if (auxvec[0]==3) {
      x=(void*)auxvec[1];
      if (n) break;
    } else if (auxvec[0]==5) {
      n=auxvec[1];
      if (x) break;
    }
    auxvec+=2;
  }
  if (!x || !n) return;
  for (i=0; i<n; ++i)
    if (x[i].p_type==
                    PT_TLS
                          ) {
      __tdataptr=(void*)x[i].p_vaddr;
      __tdatasize=x[i].p_filesz;
      __tmemsize=x[i].p_memsz;
      if (__tmemsize&15)
 __tmemsize=(__tmemsize+15)&~15;
      break;
    }


}



static tcbhead_t* __tcb_mainthread;

 void __setup_tls(tcbhead_t*);
 long* _auxvec;

typedef void(*funcptr)(void);


 funcptr __CTOR_LIST__[];
 funcptr __CTOR_END__[];
 funcptr __DTOR_LIST__[];
 funcptr __DTOR_END__[];



 const char __EH_FRAME_BEGIN__[];

struct object { void* x[7]; };
 void __register_frame_info (const void *, struct object *);
 void __deregister_frame_info (const void *);


static __attribute__((optimize("no-stack-protector")))
static int stackgap(int argc,char* argv[],char* envp[], funcptr fp);
static int stackgap(int argc,char* argv[],char* envp[], funcptr fp) {



  long* auxvec=(long*)envp;

  char* rand=(char*)&auxvec;
  char* tlsdata;

  while (*auxvec) ++auxvec;
  ++auxvec;

  _auxvec=auxvec;
  volatile char* gap;
  rand=(char*)getauxval(25);
  memcpy(&__guard,rand,sizeof(__guard));







  __vdso=(void*)getauxval(33);





  findtlsdata(auxvec);
  if (
     __builtin_expect((long)((
     __tmemsize+sizeof(tcbhead_t)<sizeof(tcbhead_t)
     )),0) 
                                                                ||
      
     __builtin_expect((long)((
     __tmemsize>512*1024*1024
     )),0) 
                                          ||
      
     __builtin_expect((long)((
     __tmemsize<__tdatasize
     )),0)
                                       )
    return 111;
  tlsdata=
         __builtin_alloca(
         __tmemsize+sizeof(tcbhead_t)
         )
                                             ;
  memcpy(tlsdata,__tdataptr,__tdatasize);
  memset(tlsdata+__tdatasize,0,__tmemsize-__tdatasize);
  __setup_tls(__tcb_mainthread=(tcbhead_t*)(tlsdata+__tmemsize));
  __tcb_mainthread->sysinfo=(uintptr_t)getauxval(32);
  {
    const char* v=getenv("LD_PRELOAD");
    __valgrind=(v && strstr(v,"valgrind"));
  }



  program_invocation_name=argv[0];
  {
    char* c;
    for (c=program_invocation_short_name=program_invocation_name; *c; ++c)
      if (*c=='/') program_invocation_short_name=c+1;
  }


  {
    static struct object ob;
    __register_frame_info(__EH_FRAME_BEGIN__, &ob);
  }


  {
    funcptr* f;
    for (f=__CTOR_LIST__; f<__CTOR_END__; ++f) (*f)();
  }

  int r=main(argc,argv,envp);

  if (fp) fp();
  {
    funcptr* f;
    for (f=__DTOR_LIST__; f<__DTOR_END__; ++f) (*f)();
  }


  __deregister_frame_info(__EH_FRAME_BEGIN__);

  exit(r);
}





static void __statfs64_cvt(const struct statfs *src,struct statfs64 *dest);
static void __statfs64_cvt(const struct statfs *src,struct statfs64 *dest) {
  dest->f_type=src->f_type;
  dest->f_bsize=src->f_bsize;
  dest->f_frsize=src->f_frsize;
  dest->f_blocks=src->f_blocks;
  dest->f_bfree=src->f_bfree;
  dest->f_files=src->f_files;
  dest->f_ffree=src->f_ffree;
  dest->f_bavail=src->f_bavail;
  dest->f_fsid=src->f_fsid;
  dest->f_namelen=src->f_namelen;
}






 void __statvfs_cvt(struct statfs* from,struct statvfs* to);

static int statvfs(const char *path, struct statvfs *sv) {
  struct statfs ss;
  if (statfs(path,&ss)==-1) return -1;
  __statvfs_cvt(&ss,sv);
  return 0;
}





static void __statvfs_cvt(struct statfs* from,struct statvfs* to);

static void __statvfs_cvt(struct statfs* from,struct statvfs* to) {
  to->f_bsize=from->f_bsize;
  to->f_frsize=from->f_frsize;
  to->f_blocks=from->f_blocks;
  to->f_bfree=from->f_bfree;
  to->f_bavail=from->f_bavail;
  to->f_files=from->f_files;
  to->f_ffree=from->f_ffree;
  to->f_favail=from->f_ffree;
  to->f_fsid=from->f_fsid.__val[0];
  to->f_flag=0;
  to->f_namemax=from->f_namelen;
}


static char * stpcpy (char *dst, const char *src) {
  while ((*dst++ = *src++));
  return (dst-1);
}




static char* stpncpy(char* dest, const char* src, size_t n) {
  char* x=memccpy(dest,src,0,n);
  if (x) {



    return x-1;
  } else
    return dest+n;
}


static int strcasecmp ( const char* s1, const char* s2 )
{
    register unsigned int x2;
    register unsigned int x1;

    while (1) {
        x2 = *s2 - 'A'; if (
                           __builtin_expect((long)((
                           x2 < 26u
                           )),0)
                                               ) x2 += 32;
        x1 = *s1 - 'A'; if (
                           __builtin_expect((long)((
                           x1 < 26u
                           )),0)
                                               ) x1 += 32;
 s1++; s2++;
        if ( 
            __builtin_expect((long)((
            x2 != x1
            )),0) 
                                 )
            break;
        if ( 
            __builtin_expect((long)((
            x1 == (unsigned int)-'A'
            )),0) 
                                                 )
            break;
    }

    return x1 - x2;
}



static char* strcat(register char* s,register const char* t)
{
  char *dest=s;
  s+=strlen(s);
  for (;;) {
    if (!(*s = *t)) break;
                           ++s; ++t;

    if (!(*s = *t)) break;
                           ++s; ++t;
    if (!(*s = *t)) break;
                           ++s; ++t;
    if (!(*s = *t)) break;
                           ++s; ++t;

  }
  return dest;
}




static char *strchr(register const char *t, int c) {
  register char ch;

  ch = c;
  for (;;) {
    if (
       __builtin_expect((long)((
       *t == ch
       )),0)
                           ) break;
         if (
            __builtin_expect((long)((
            !*t
            )),0)
                           ) return 0;
            ++t;

    if (
       __builtin_expect((long)((
       *t == ch
       )),0)
                           ) break;
         if (
            __builtin_expect((long)((
            !*t
            )),0)
                           ) return 0;
            ++t;
    if (
       __builtin_expect((long)((
       *t == ch
       )),0)
                           ) break;
         if (
            __builtin_expect((long)((
            !*t
            )),0)
                           ) return 0;
            ++t;
    if (
       __builtin_expect((long)((
       *t == ch
       )),0)
                           ) break;
         if (
            __builtin_expect((long)((
            !*t
            )),0)
                           ) return 0;
            ++t;

  }
  return (char*)t;
}

static char *
     strchr(
     char *t
     ,
     int c
     ) 
                          __attribute__((alias("strchr")));






 int __valgrind;


static int
static strcmp (const char *s1, const char *s2)
{





    const unsigned long *lx1, *lx2;
    unsigned long l1, l2;
    int tmp;

    if ((((unsigned long)s1 & (sizeof (unsigned long)-1)) ^ ((unsigned long)s2 & (sizeof (unsigned long)-1)))

        || 
          __builtin_expect((long)((
          __valgrind
          )),0)

    
   ) {
        while (*s1 && *s1 == *s2) s1++, s2++;
        return (*s1 - *s2);
    }

    if ((tmp = ((((uintptr_t)s1+sizeof(long)-1)&(-sizeof(long)))-(uintptr_t)s1)))
        for (; tmp--; s1++, s2++)
            if (!*s1 || *s1 != *s2)
                return (*s1 - *s2);

    lx1 = (unsigned long *) s1;
    lx2 = (unsigned long *) s2;

    while (1) {
        l1 = *lx1++;
        l2 = *lx2++;
        if ((((l1 - ((unsigned long)0x1ul*0x0101010101010101)) & ~l1) & ((unsigned long)0x80ul*0x0101010101010101)) ||
            ((((l2 - ((unsigned long)0x1ul*0x0101010101010101)) & ~l2) & ((unsigned long)0x80ul*0x0101010101010101))) || l1 != l2) {
            unsigned char c1, c2;
            while (1) {
  c1 = (((l1)>>(sizeof(l1)*8-8))&0xff);
                c2 = (((l2)>>(sizeof(l2)*8-8))&0xff);
                if (!c1 || c1 != c2)
                    return (c1 - c2);
                do { l1 <<= 8; } while (0);
                do { l2 <<= 8; } while (0);
            }
        }
    }

}

static int strcoll(const char *s,const char* t) __attribute__((alias("strcmp")));






 int __valgrind;


static char *
static strcpy (char *s1, const char *s2)
{
    char *res = s1;




    int tmp;
    unsigned long l;

    if ((((unsigned long)s1 & (sizeof (unsigned long)-1)) ^ ((unsigned long)s2 & (sizeof (unsigned long)-1)))

        || 
          __builtin_expect((long)((
          __valgrind
          )),0)

    
   ) {
 while ((*s1++ = *s2++));
 return (res);
    }
    if ((tmp = ((((uintptr_t)s1+sizeof(long)-1)&(-sizeof(long)))-(uintptr_t)s1))) {
 while (tmp-- && (*s1++ = *s2++));
 if (tmp != -1) return (res);
    }

    while (1) {
 l = *(const unsigned long *) s2;
 if (((l - ((unsigned long)0x1ul*0x0101010101010101)) & ~l) & ((unsigned long)0x80ul*0x0101010101010101)) {
     while ((*s1++ = (((l)>>(sizeof(l)*8-8))&0xff))) do { l <<= 8; } while (0);
     return (res);
 }
 *(unsigned long *) s1 = l;
 s2 += sizeof(unsigned long);
 s1 += sizeof(unsigned long);
    }

}



static size_t strcspn(const char *s, const char *reject)
{
  size_t l=0;
  int i;

  for (; *s; ++s) {
    for (i=0; reject[i]; ++i)
      if (*s==reject[i]) return l;
    ++l;
  }
  return l;
}



static char *strdup(const char *s) {
  size_t l=strlen(s)+1;
  char *tmp=(char *)malloc(l);
  if (!tmp) return 0;
  return memcpy(tmp,s,l);
}
 const char __sys_err_unknown[];

static char*
    strerror
            (int errnum) {
  register const char*message=__sys_err_unknown;

  if ( (unsigned int)errnum < (unsigned int)
                                           ((168) + 1) 
                                                      )
    message=sys_errlist[errnum];

  if ( errnum == 1133 )
    message="Quota exceeded";

  return (char*)message;
}
static size_t strlcat(dst, src, siz)
 char *dst;
 const char *src;
 size_t siz;
{
 register char *d = dst;
 register const char *s = src;
 register size_t n = siz;
 size_t dlen;


 while (*d != '\0' && n-- != 0)
  d++;
 dlen = d - dst;
 n = siz - dlen;

 if (n == 0)
  return(dlen + strlen(s));
 while (*s != '\0') {
  if (n != 1) {
   *d++ = *s;
   n--;
  }
  s++;
 }
 *d = '\0';

 return(dlen + (s - src));
}
static size_t strlcpy(dst, src, siz)
 char *dst;
 const char *src;
 size_t siz;
{
 register char *d = dst;
 register const char *s = src;
 register size_t n = siz;


 if (n != 0 && --n != 0) {
  do {
   if ((*d++ = *s++) == 0)
    break;
  } while (--n != 0);
 }


 if (n == 0) {
  if (siz != 0)
   *d = '\0';
  while (*s++)
   ;
 }

 return(s - src - 1);
}
typedef uint32_t word_t;




static word_t const magic = (word_t)(0x0101010101010101ull);


 int __valgrind;


static size_t strlen(const char *s)
{
  const char *t = s;
  word_t word;
  word_t mask;

  word_t orig_word;


  if (
     __builtin_expect((long)((
     !s
     )),0)
                   ) return 0;


  if (
     __builtin_expect((long)((
     __valgrind
     )),0)
                           ) {
    register size_t i;
    for (i=0; 
             __builtin_expect((long)((
             *s
             )),1)
                         ; ++s) ++i;
    return i;
  }



  for (; ((unsigned long) t & (sizeof(magic)-1)); t++)
    if (!*t) return t - s;


  do {
    word = *((word_t const *) t); t += sizeof word;

    orig_word = word;

    word = (word - magic) &~ word;
    word &= (magic << 7);
  } while (
          __builtin_expect((long)((
          word == 0
          )),1)
                             );
  if (
     __builtin_expect((long)((
     orig_word < magic
     )),0)
                                  ) {
    for (t -= sizeof(word); 
                           __builtin_expect((long)((
                           *t
                           )),0)
                                         ; t++);
    return t - s;
  }

  mask = (magic << 7);

  switch (sizeof(word)) {
  case 8:
    mask <<= 4*8;
    if ((word & mask) == 0) {
      t += 4;
      word <<= 4*8;
    }


  case 4:
    mask <<= 2*8;
    if ((word & mask) == 0) {
      t += 2;
      word <<= 2*8;
    }


  case 2:
    mask <<= 1*8;
    if ((word & mask) == 0) {
      t += 1;
      word <<= 1*8;
    }
    break;

  default: { char exc[sizeof(word)==8]; (void)exc; }
  }

  return t - sizeof(word) - s;
}




static int strncasecmp ( const char* s1, const char* s2, size_t len )
{
    register unsigned int x2;
    register unsigned int x1;
    register const char* end = s1 + len;

    while (1) {
        if ( 
            __builtin_expect((long)((
            s1 >= end
            )),0) 
                                  )
            return 0;
        x2 = *s2 - 'A'; if (
                           __builtin_expect((long)((
                           x2 < 26u
                           )),0)
                                               ) x2 += 32;
        x1 = *s1 - 'A'; if (
                           __builtin_expect((long)((
                           x1 < 26u
                           )),0)
                                               ) x1 += 32;
 s1++; s2++;
        if ( 
            __builtin_expect((long)((
            x2 != x1
            )),0) 
                                 )
            break;
        if ( 
            __builtin_expect((long)((
            x1 == (unsigned int)-'A'
            )),0) 
                                                 )
            break;
    }

    return x1 - x2;
}





static char *strncat(char *s, const char *t, size_t n) {
  char *dest=s;
  register char *max;
  s+=strlen(s);
  if (
     __builtin_expect((long)((
     (max=s+n)==s
     )),0)
                             ) goto fini;
  for (;;) {
    if (
       __builtin_expect((long)((
       !(*s = *t)
       )),0)
                             ) break;
                                       if (
                                          __builtin_expect((long)((
                                          ++s==max
                                          )),0)
                                                              ) break;
                                                                        ++t;

    if (
       __builtin_expect((long)((
       !(*s = *t)
       )),0)
                             ) break;
                                       if (
                                          __builtin_expect((long)((
                                          ++s==max
                                          )),0)
                                                              ) break;
                                                                        ++t;
    if (
       __builtin_expect((long)((
       !(*s = *t)
       )),0)
                             ) break;
                                       if (
                                          __builtin_expect((long)((
                                          ++s==max
                                          )),0)
                                                              ) break;
                                                                        ++t;
    if (
       __builtin_expect((long)((
       !(*s = *t)
       )),0)
                             ) break;
                                       if (
                                          __builtin_expect((long)((
                                          ++s==max
                                          )),0)
                                                              ) break;
                                                                        ++t;

  }
  *s=0;
fini:
  return dest;
}





static int strncmp(const char *s1, const char *s2, size_t n) {
  register const unsigned char* a=(const unsigned char*)s1;
  register const unsigned char* b=(const unsigned char*)s2;
  register const unsigned char* fini=a+n;
  while (a!=fini) {
    register int res=*a-*b;
    if (res) return res;
    if (!*a) return 0;
    ++a; ++b;
  }
  return 0;
}
static char *strncpy(char *dest, const char *src, size_t n) {



  memccpy(dest,src,0,n);



  return dest;
}


static size_t strnlen(const char *s,size_t maxlen) {
  const char* x=memchr(s,0,maxlen);
  if (!x) x=s+maxlen;
  return x-s;
}




static char *strpbrk(const char *s, const char *accept) {
  register unsigned int i;
  for (; *s; s++)
    for (i=0; accept[i]; i++)
      if (*s == accept[i])
 return (char*)s;
  return 0;
}



static char *strrchr(const char *t, int c) {
  register char ch;
  register const char *l=0;

  ch = c;
  for (;;) {
    if (
       __builtin_expect((long)((
       *t == ch
       )),0)
                           ) l=t;
                                   if (
                                      __builtin_expect((long)((
                                      !*t
                                      )),0)
                                                     ) return (char*)l;
                                                                         ++t;

    if (
       __builtin_expect((long)((
       *t == ch
       )),0)
                           ) l=t;
                                   if (
                                      __builtin_expect((long)((
                                      !*t
                                      )),0)
                                                     ) return (char*)l;
                                                                         ++t;
    if (
       __builtin_expect((long)((
       *t == ch
       )),0)
                           ) l=t;
                                   if (
                                      __builtin_expect((long)((
                                      !*t
                                      )),0)
                                                     ) return (char*)l;
                                                                         ++t;
    if (
       __builtin_expect((long)((
       *t == ch
       )),0)
                           ) l=t;
                                   if (
                                      __builtin_expect((long)((
                                      !*t
                                      )),0)
                                                     ) return (char*)l;
                                                                         ++t;

  }
  return (char*)l;
}

static char *
     strrchr(
     const char *t
     ,
     int c
     ) 
                                 __attribute__((alias("strrchr")));


static char *strsep(char **stringp, const char *delim) {
  register char *tmp=*stringp;
  register char *tmp2;
  register const char *tmp3;
  if (!*stringp) return 0;
  for (tmp2=tmp; *tmp2; ++tmp2) {
    for (tmp3=delim; *tmp3; ++tmp3)
      if (*tmp2==*tmp3) {
 *tmp2=0;
 *stringp=tmp2+1;
 return tmp;
      }
  }
  *stringp=0;
  return tmp;
}



static size_t strspn(const char *s, const char *accept)
{
  size_t l = 0;
  const char *a;

  for (; *s; s++) {
    for (a = accept; *a && *s != *a; a++);

    if (!*a)
      break;
    else
     l++;
  }

  return l;
}



static char *strstr(const char *haystack, const char *needle) {
  size_t nl=strlen(needle);
  size_t hl=strlen(haystack);
  size_t i;
  if (!nl) goto found;
  if (nl>hl) return 0;
  for (i=hl-nl+1; 
                 __builtin_expect((long)((
                 i
                 )),1)
                            ; --i) {
    if (*haystack==*needle && !memcmp(haystack,needle,nl))
found:
      return (char*)haystack;
    ++haystack;
  }
  return 0;
}




static float strtof(const char* s, char** endptr) {
    register const char* p = s;
    register float value = 0.;
    int sign = +1;
    float factor;
    unsigned int expo;

    while ( isspace(*p) )
        p++;

    switch (*p) {
    case '-': sign = -1;
    case '+': p++;
    default : break;
    }

    while ( (unsigned int)(*p - '0') < 10u )
        value = value*10 + (*p++ - '0');

    if ( *p == '.' ) {
        factor = 1.;

        p++;
        while ( (unsigned int)(*p - '0') < 10u ) {
            factor *= 0.1;
            value += (*p++ - '0') * factor;
        }
    }

    if ( (*p | 32) == 'e' ) {
        expo = 0;
        factor = 10.L;

        switch (*++p) {
        case '-': factor = 0.1;
        case '+': p++;
                  break;
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
                  break;
        default : value = 0.L;
                  p = s;
                  goto done;
        }

        while ( (unsigned int)(*p - '0') < 10u )
            expo = 10 * expo + (*p++ - '0');

        while ( 1 ) {
            if ( expo & 1 )
                value *= factor;
            if ( (expo >>= 1) == 0 )
                break;
            factor *= factor;
        }
    }

done:
    if ( endptr != 
                  (void*)0 
                       )
        *endptr = (char*)p;

    return value * sign;
}
static double strtod(const char* s, char** endptr) {
    register const char* p = s;
    register long double value = 0.;
    int sign = +1;
    long double factor;
    unsigned int expo;

    while ( isspace(*p) )
        p++;

    switch (*p) {
    case '-': sign = -1;
    case '+': p++;
    default : break;
    }

    while ( (unsigned int)(*p - '0') < 10u )
        value = value*10 + (*p++ - '0');

    if ( *p == '.' ) {
        factor = 1.;

        p++;
        while ( (unsigned int)(*p - '0') < 10u ) {
            factor *= 0.1;
            value += (*p++ - '0') * factor;
        }
    }

    if ( (*p | 32) == 'e' ) {
        expo = 0;
        factor = 10.;

        switch (*++p) {
        case '-': factor = 0.1;
        case '+': p++;
                  break;
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
                  break;
        default : value = 0.;
                  p = s;
                  goto done;
        }

        while ( (unsigned int)(*p - '0') < 10u )
            expo = 10 * expo + (*p++ - '0');

        while ( 1 ) {
            if ( expo & 1 )
                value *= factor;
            if ( (expo >>= 1) == 0 )
                break;
            factor *= factor;
        }
    }

done:
    if ( endptr != 
                  (void*)0 
                       )
        *endptr = (char*)p;

    return value * sign;
}


static char *strtok_pos;

static char *strtok(char *s, const char *delim)
{
  return strtok_r(s,delim,&strtok_pos);
}


static char*strtok_r(char*s,const char*delim,char**ptrptr) {
  char*tmp=0;

  if (s==0) s=*ptrptr;
  s+=strspn(s,delim);
  if (
     __builtin_expect((long)((
     *s
     )),1)
                 ) {
    tmp=s;
    s+=strcspn(s,delim);
    if (
       __builtin_expect((long)((
       *s
       )),1)
                   ) *s++=0;
  }
  *ptrptr=s;
  return tmp;
}
static long int strtol(const char *nptr, char **endptr, int base)
{
  int neg=0;
  unsigned long int v;
  const char*orig=nptr;

  while(isspace(*nptr)) nptr++;

  if (*nptr == '-' && isalnum(nptr[1])) { neg=-1; ++nptr; }
  v=strtoul(nptr,endptr,base);
  if (endptr && *endptr==nptr) *endptr=(char *)orig;
  if (v>=2147483648UL) {
    if (v==2147483648UL && neg) {
      errno=0;
      return v;
    }
    errno=
         34
               ;
    return (neg?
               (-1l - (0x7fffffffL))
                       :
                        (0x7fffffffL)
                                );
  }
  return (neg?-v:v);
}




static long double strtold(const char* s, char** endptr) {
    register const char* p = s;
    register long double value = 0.L;
    int sign = +1;
    long double factor;
    unsigned int expo;

    while ( isspace(*p) )
        p++;

    switch (*p) {
    case '-': sign = -1;
    case '+': p++;
    default : break;
    }

    while ( (unsigned int)(*p - '0') < 10u )
        value = value*10 + (*p++ - '0');

    if ( *p == '.' ) {
        factor = 1.;

        p++;
        while ( (unsigned int)(*p - '0') < 10u ) {
            factor *= 0.1;
            value += (*p++ - '0') * factor;
        }
    }

    if ( (*p | 32) == 'e' ) {
        expo = 0;
        factor = 10.L;

        switch (*++p) {
        case '-': factor = 0.1;
        case '+': p++;
                  break;
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
                  break;
        default : value = 0.L;
                  p = s;
                  goto done;
        }

        while ( (unsigned int)(*p - '0') < 10u )
            expo = 10 * expo + (*p++ - '0');

        while ( 1 ) {
            if ( expo & 1 )
                value *= factor;
            if ( (expo >>= 1) == 0 )
                break;
            factor *= factor;
        }
    }

done:
    if ( endptr != 
                  (void*)0 
                       )
        *endptr = (char*)p;

    return value * sign;
}






static long long int strtoll(const char *nptr, char **endptr, int base)
{
  int neg=0;
  unsigned long long int v;
  const char*orig=nptr;

  while(isspace(*nptr)) nptr++;

  if (*nptr == '-' && isalnum(nptr[1])) { neg=-1; nptr++; }
  v=strtoull(nptr,endptr,base);
  if (endptr && *endptr==nptr) *endptr=(char *)orig;
  if (v>
       0x7fffffffffffffffll
                ) {
    if (v==0x8000000000000000ull && neg) {
      errno=0;
      return v;
    }
    errno=
         34
               ;
    return (neg?
               (-1ll - 0x7fffffffffffffffll)
                        :
                         0x7fffffffffffffffll
                                  );
  }
  return (neg?-v:v);
}

static intmax_t strtoimax(const char *nptr, char **endptr, int base)
 __attribute__((alias("strtoll")));





static unsigned long int strtoul(const char *ptr, char **endptr, int base)
{
  int neg = 0, overflow = 0;
  unsigned long int v=0;
  const char* orig;
  const char* nptr=ptr;

  while(isspace(*nptr)) ++nptr;

  if (*nptr == '-') { neg=1; nptr++; }
  else if (*nptr == '+') ++nptr;
  orig=nptr;
  if (base==16 && nptr[0]=='0') goto skip0x;
  if (base) {
    register unsigned int b=base-2;
    if (
       __builtin_expect((long)((
       b>34
       )),0)
                       ) { errno=
                                 22
                                       ; return 0; }
  } else {
    if (*nptr=='0') {
      base=8;
skip0x:
      if ((nptr[1]=='x'||nptr[1]=='X') && isxdigit(nptr[2])) {
 nptr+=2;
 base=16;
      }
    } else
      base=10;
  }
  while(
       __builtin_expect((long)((
       *nptr
       )),1)
                      ) {
    register unsigned char c=*nptr;
    c=(c>='a'?c-'a'+10:c>='A'?c-'A'+10:c<='9'?c-'0':0xff);
    if (
       __builtin_expect((long)((
       c>=base
       )),0)
                          ) break;
    {
      register unsigned long x=(v&0xff)*base+c;
      register unsigned long w=(v>>8)*base+(x>>8);
      if (w>(
            ((0x7fffffffL) * 2ul + 1)
                     >>8)) overflow=1;
      v=(w<<8)+(x&0xff);
    }
    ++nptr;
  }
  if (
     __builtin_expect((long)((
     nptr==orig
     )),0)
                           ) {
    nptr=ptr;
    errno=
         22
               ;
    v=0;
  }
  if (endptr) *endptr=(char *)nptr;
  if (overflow) {
    errno=
         34
               ;
    return 
          ((0x7fffffffL) * 2ul + 1)
                   ;
  }
  return (neg?-v:v);
}






static unsigned long long int strtoull(const char *ptr, char **endptr, int base)
{
  int neg = 0, overflow = 0;
  long long int v=0;
  const char* orig;
  const char* nptr=ptr;

  while(isspace(*nptr)) ++nptr;

  if (*nptr == '-') { neg=1; nptr++; }
  else if (*nptr == '+') ++nptr;
  orig=nptr;
  if (base==16 && nptr[0]=='0') goto skip0x;
  if (base) {
    register unsigned int b=base-2;
    if (
       __builtin_expect((long)((
       b>34
       )),0)
                       ) { errno=
                                 22
                                       ; return 0; }
  } else {
    if (*nptr=='0') {
      base=8;
skip0x:
      if (((*(nptr+1)=='x')||(*(nptr+1)=='X')) && isxdigit(nptr[2])) {
 nptr+=2;
 base=16;
      }
    } else
      base=10;
  }
  while(
       __builtin_expect((long)((
       *nptr
       )),1)
                      ) {
    register unsigned char c=*nptr;
    c=(c>='a'?c-'a'+10:c>='A'?c-'A'+10:c<='9'?c-'0':0xff);
    if (
       __builtin_expect((long)((
       c>=base
       )),0)
                          ) break;
    {
      register unsigned long x=(v&0xff)*base+c;
      register unsigned long long w=(v>>8)*base+(x>>8);
      if (w>(
            (~0ull)
                      >>8)) overflow=1;
      v=(w<<8)+(x&0xff);
    }
    ++nptr;
  }
  if (
     __builtin_expect((long)((
     nptr==orig
     )),0)
                           ) {
    nptr=ptr;
    errno=
         22
               ;
    v=0;
  }
  if (endptr) *endptr=(char *)nptr;
  if (overflow) {
    errno=
         34
               ;
    return 
          (~0ull)
                    ;
  }
  return (neg?-v:v);
}


static unsigned long long int strtouq(const char *nptr, char **endptr, int base)
 __attribute__((leaf, nothrow, alias("strtoull")));

static uintmax_t strtoumax(const char *nptr, char **endptr, int base)
 __attribute__((leaf, nothrow, alias("strtoull")));




static int strverscmp(const char* s1, const char* s2)
{
  size_t i,j;
  long long a,b;
  b=0;
  for (i=0; s1[i]==s2[i]; ++i) {
    if (!s1[i]) return 0;
  }



  if (!isdigit(s1[i]) || !isdigit(s2[i]))
    return s1[i]-s2[i];
  for (j=i; j>0 && isdigit(s1[j-1]); --j) ;
  for (a=0; j<i; ++j) {
    a=a*10+s1[j]-'0';
  }
  b=a;
  while (isdigit(s1[i])) {
    a=a*10+s1[i]-'0';
    ++i;
  }
  while (isdigit(s2[j])) {
    b=b*10+s2[j]-'0';
    ++j;
  }
  return a<b ? -1 : 1;
}




static size_t strxfrm(char *dest, const char *src, size_t n) {



  memccpy(dest,src,0,n);
  return strlen(dest);
}



static void swab(const void *src, void *dest, ssize_t nbytes)
{
  ssize_t i;
  const char *s=src;
  char *d=dest;
  nbytes&=~1;
  for (i=0; i<nbytes; i+=2) {
    d[i]=s[i+1];
    d[i+1]=s[i];
  }
}







 
      int getcontext (ucontext_t *c) ;
 int setcontext (const ucontext_t *c) ;
 int swapcontext (ucontext_t *__restrict o,
   const ucontext_t *__restrict n) __attribute__((__nothrow__));
 void makecontext (ucontext_t *c, void (*__func) (void),
    int argc, ...) ;





static int swapcontext(ucontext_t* o,const ucontext_t* n) {
  volatile int once=0;
  if (getcontext(o)==-1) return -1;
  if (!once) {
    ++once;
    return setcontext(n);
  }
  return 0;
}
static const char *const __sys_siglist[] = {
  "Signal 0",
  "Hangup",
  "Interrupt",
  "Quit",
  "Illegal instruction",
  "Trace/breakpoint trap",
  "ABRT/IOT trap",

  "EMT trap",



  "Floating point exception",
  "Killed",

  "Bus error",



  "Segmentation fault",

  "Bad system call",



  "Broken pipe",
  "Alarm clock",
  "Terminated",
  "User defined signal 1",
  "User defined signal 2",
  "Child exited",
  "Power lost",
  "Window changed",
  "Urgent I/O condition",
  "I/O possible",
  "Stopped (signal)",
  "Stopped",
  "Continued",
  "Stopped (tty input)",
  "Stopped (tty output)",
  "Virtual timer expired",
  "Profiling timer expired",
  "CPU time limit exceeded",
  "File size limit exceeded",
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",

  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",

  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",

  0
};

static const char *const* sys_siglist=__sys_siglist;


static int __libc_tcdrain(int fd);
static int __libc_tcdrain(int fd)
{
  return ioctl(fd, 
                  0x5405
                        , 1);
}

static int tcdrain(int fd) __attribute__((alias("__libc_tcdrain")));





static int tcflow ( int fd, int action )
{


    if ( (unsigned int)action < 4u )
 return ioctl ( fd, 
                   0x5406
                         , action );

    errno = 
           22
                 ;
    return -1;
}


static int __libc_tcflush(int fd, int queue_selector);
static int __libc_tcflush(int fd, int queue_selector)
{
  return ioctl(fd, 
                  0x5407
                        , queue_selector);
}

static int tcflush(int fd, int queue_selector) __attribute__((alias("__libc_tcflush")));



static int tcgetattr(int fildes, struct termios *termios_p)
{
  return ioctl(fildes, 
                      0x540d
                            , termios_p);
}




static pid_t tcgetpgrp(int fildes)
{
  int32_t foo = -1;
  if (ioctl(fildes, 
                   (((2U) << (((0 +8)+8)+13)) | ((('t')) << (0 +8)) | (((119)) << 0) | (((sizeof(int)) & 0xff) << ((0 +8)+8)))
                            , &foo)==-1)
    return -1;
  else
    return foo;
}



static pid_t tcgetsid(int fildes) {
  pid_t pid;
  return ioctl(fildes, 
                      0x7416
                              , &pid)==-1?-1:pid;
}






static int tcsendbreak (int fd,int duration)
{
  if (duration <= 0) return (ioctl (fd,
                                      0x5486
                                             ,0));
  errno = 
         22
               ;
  return (-1);
}
static int tcsetattr ( int fildes, int optional_actions, struct termios* termios_p )
{
    switch ( optional_actions ) {
    case 
        0x540e
               :
        return ioctl ( fildes, 
                              0x540e 
                                     , termios_p );
    case 
        0x540f
                 :
        return ioctl ( fildes, 
                              0x540f
                                     , termios_p );
    case 
        0x5410
                 :
        return ioctl ( fildes, 
                              0x5410
                                     , termios_p );
    default:
        errno = 
               22
                     ;
        return -1;
    }


}




static int tcsetpgrp(int fildes, pid_t pgrpid)
{
  return ioctl(fildes, 
                      (((4U) << (((0 +8)+8)+13)) | ((('t')) << (0 +8)) | (((118)) << 0) | (((sizeof(int)) & 0xff) << ((0 +8)+8)))
                               , &pgrpid);
}




static off_t telldir(DIR *d) {
  off_t result = 0;
  if (lseek(d->fd,0,
                   1
                           ))
    result=((struct dirent*)(d->buf+d->cur))->d_off;
  return result;
}
 thrd_t _thrd_root;
 size_t _thrd_stacksize;


 size_t __tdatasize, __tmemsize;
 void* __tdataptr;
 tcbhead_t* __tcb_mainthread;




static int launch(void* p) {
  thrd_t self=p;
  thrd_exit(self->func(self->arg));
  return 0;
}

static int thrd_create(thrd_t *thr, thrd_start_t func, void *arg) {
  size_t stacksize=_thrd_stacksize;
  char* stack=mmap(0,stacksize+4096+__tmemsize+sizeof(tcbhead_t)+sizeof(**thr),
                                                                              0x0
                                                                                       ,
                                                                                        0x02
                                                                                                   |
                                                                                                    0x0800
                                                                                                                 |
                                                                                                                  0x40000
                                                                                                                           |
                                                                                                                            0x1000
                                                                                                                                         ,-1,0);
  thrd_t t;
  tcbhead_t* tcb;

  if (stack==
            ((void *) -1)
                      ) return thrd_nomem;
  if (mprotect(stack+4096,stacksize+__tmemsize+sizeof(tcbhead_t)+sizeof(**thr),
                                                                              0x1
                                                                                       |
                                                                                        0x2
                                                                                                  )) {
    munmap(stack,stacksize+4096+__tmemsize+sizeof(tcbhead_t)+sizeof(**thr));
    return thrd_error;
  }
  tcb=(tcbhead_t*)(stack+stacksize+4096+__tmemsize);
  tcb->tcb=tcb;
  tcb->dtv=0;
  t=(thrd_t)(tcb+1);
  tcb->self=t;
  tcb->multiple_threads=1;

  tcb->sysinfo=__tcb_mainthread->sysinfo;
  if (getrandom(&tcb->stack_guard,sizeof(tcb->stack_guard),
                                                          GRND_NONBLOCK
                                                                       ) != sizeof(tcb->stack_guard))
    tcb->stack_guard=__tcb_mainthread->stack_guard ^ gettid() ^ (uintptr_t)t;
  __tcb_mainthread->multiple_threads=1;

  t->memstart=stack;
  t->memsize=stacksize+4096+__tmemsize;
  t->res=0;
  t->func=func;
  t->arg=arg;
  t->flags=0;
  t->join_futex=0;


  memcpy(stack+stacksize+4096,__tdataptr,__tdatasize);
  memset(stack+stacksize+4096+__tdatasize,0,__tmemsize-__tdatasize);


  t->tid=clone(launch,stack+4096+stacksize,
                                          0x00000400
                                                     |
                                                      0x00000200
                                                              |
                                                               0x80000000
                                                                       |
                                                                        0x00008000
                                                                                    |
                                                                                     0x00000800
                                                                                                  |
                                                                                                   0x00040000
                                                                                                                |
                                                                                                                 0x00010000
                                                                                                                             |
                                                                                                                              0x00000100
                                                                                                                                      |
                                                                                                                                       0x00080000
                                                                                                                                                   |
                                                                                                                                                    0x00100000
                                                                                                                                                                       ,t,&t->tid,stack+stacksize+4096+__tmemsize);
  if (t->tid==-1) {
    munmap(stack,stacksize+4096+__tmemsize+sizeof(tcbhead_t)+sizeof(**thr));
    return thrd_error;
  }
  *thr=t;
  return thrd_success;
}



static thrd_t thrd_current(void) {
  tcbhead_t* x=__get_cur_tcb();
  if (x->multiple_threads==0) return 
                                    (void*)0
                                        ;
  return (thrd_t)(x+1);
}




static int thrd_detach(thrd_t thr) {
  int flags=thr->flags;
  do {
    if (flags&4) return thrd_error;
    if (flags&2) {
      munmap(thr->memstart+thr->memsize,sizeof(tcbhead_t)+sizeof(*thr));
      return thrd_success;
    }
    if (flags&1) return thrd_success;
    flags=__sync_val_compare_and_swap(&thr->flags,flags,flags|1);
  } while (1);
}
 void __munmap_and_exit(void* map,size_t len) __attribute__((noreturn));


static __thread 
            tss_t tss_dtor_list;

static void thrd_exit(int res) {
  thrd_t t=thrd_current();
  int flags;

  size_t len;

  while (tss_dtor_list) {
    tss_t cur=tss_dtor_list;
    tss_dtor_list=tss_dtor_list->next;
    if (cur->dtor) cur->dtor(cur);
  }
  if (!t) exit(res);
  t->res=res;
  if ((flags=__sync_fetch_and_or(&t->flags,4))&4) return;
  if (t->join_futex) {
    t->join_wait_futex=0;



    while (futex(&t->join_futex,FUTEX_WAKE,1,0,0,0)==1) {


      int r;
      do {
 r=futex(&t->join_wait_futex,FUTEX_WAIT,0,0,0,0);
      } while (r==
                 4
                      );
      t->join_wait_futex=0;
    }
    flags|=1;
  }

  len=t->memsize;
  if (flags&1) {


    len += sizeof(tcbhead_t)+sizeof(*t);
  } else {


    __sync_fetch_and_or(&t->flags,2);
    len&=~4095;
    t->arg=t->memstart+len;
    t->memsize=t->memsize+sizeof(tcbhead_t)+sizeof(*t)-len;
  }




  __munmap_and_exit(t->memstart,len);
}







static int thrd_join(thrd_t thr, int* res) {
  int flags=thr->flags;
  int r;
  while ((flags&6) == 4) {



    __sync_synchronize();
    flags=thr->flags;
  }
  if ((flags&2)==0) {
    if (flags&5)

      return thrd_error;
    if (!__sync_bool_compare_and_swap(&thr->join_futex,0,1))

      return thrd_error;
    do {
      r=futex(&thr->join_futex,FUTEX_WAIT,1,0,0,0);
    } while (r==-1 && errno==
                            4
                                 );
    if (res) *res=thr->res;
    thr->join_wait_futex=1;
    futex(&thr->join_wait_futex,FUTEX_WAKE,1,0,0,0);
  } else {

    if (res) *res=thr->res;
    munmap(thr->arg,thr->memsize);
  }
  return thrd_success;
}



static thrd_t _thrd_root;
static size_t _thrd_stacksize=16*1024;






enum { TFD_TIMER_ABSTIME = 1 };



static int timerfd_create (clockid_t clock_id, int flags) ;
static int timerfd_settime (int ufd, int flags, const struct itimerspec *utmr, struct itimerspec *otmr) ;
static int timerfd_gettime (int ufd, struct itimerspec *otmr) ;



 
      int __timerfd(int ufd, int clockid, int flags, const struct itimerspec *utmr);

static int timerfd_create (clockid_t __clock_id, int __flags) {
  return __timerfd(-1,__clock_id,__flags,0);
}


static int timingsafe_bcmp(const void* a,const void* b,size_t n) {
  size_t i;
  const unsigned char* x = a;
  const unsigned char* y = b;
  int r;
  for (i=r=0; i<n; ++i)
    r |= x[i] ^ y[i];
  return !!r;
}


static int timingsafe_memcmp(const void* a,const void* b,size_t n) {


  register const unsigned char *x=a;
  register const unsigned char *y=b;
  int r=0,done=0;


  size_t i;
  for (i=0; i<n; ++i) {
    int t=x[i]-y[i];

    int minusone = (t|-t)>>(sizeof(int)-1);



    r |= t & ~done;
    done |= minusone;
  }
  return r;
}


static int tolower(int ch) {
  if ( (unsigned int)(ch - 'A') < 26u )
    ch += 'a' - 'A';
  return ch;
}



static inline int toupper(int ch) {
  if ( (unsigned int)(ch - 'a') < 26u )
    ch += 'A' - 'a';
  return ch;
}



static wint_t towlower(wint_t c) {
  if ( (unsigned int)(c - 'A') < 26u )
    c += 'a' - 'A';
  return c;
}




 
    
                   tss_t tss_dtor_list;

static int tss_create(tss_t* tss_id, tss_dtor_t destructor) {
  *tss_id=malloc(sizeof(**tss_id));
  if (!*tss_id) return thrd_nomem;
  (*tss_id)->dtor=destructor;
  (*tss_id)->next=tss_dtor_list;
  (*tss_id)->data=0;
  tss_dtor_list=*tss_id;
  return thrd_success;
}


static wint_t towupper(wint_t c) {
  if ( (unsigned int)(c - 'a') < 26u )
    c += 'A' - 'a';
  return c;
}



 
    
                   tss_t tss_dtor_list;

static void tss_delete(tss_t tss_id) {
  tss_t* cur;
  for (cur=&tss_dtor_list; *cur; cur=&((*cur)->next)) {
    if (*cur==tss_id)
      *cur=tss_id->next;
  }
  tss_id->dtor=0;
  tss_id->data=0;
  tss_id->next=0;
}


static void* tss_get(tss_t tss_id) {
  return tss_id->data;
}


static int tss_set(tss_t tss_id, void* val) {
  tss_id->data=val;
  return thrd_success;
}
static int usleep(unsigned long usecs) {
  struct timespec t;
  t.tv_sec=usecs/1000000;
  t.tv_nsec=(usecs%1000000)*1000;
  return nanosleep(&t,&t);
}

static const void* vdso_dlsym(const char* elfimage,const char* symbol);
static const void* vdso_dlsym(const char* elfimage,const char* symbol) {





  const Elf32_Ehdr* eh=(Elf32_Ehdr*)elfimage;
  const char* dynstringtable=0;

  {
    size_t i;



    for (i=0; i<eh->e_shnum; ++i) {
      const Elf32_Shdr* sh=(Elf32_Shdr*)(elfimage + eh->e_shoff + i*eh->e_shentsize);
      if (sh->sh_type==3 && (sh->sh_flags&2)) {
 dynstringtable = elfimage + sh->sh_offset;
 break;
      }
    }
  }


  if (dynstringtable) {
    size_t i;
    for (i=0; i<eh->e_shnum; ++i) {
      const Elf32_Shdr* sh=(Elf32_Shdr*)(elfimage + eh->e_shoff + i*eh->e_shentsize);
      if (sh->sh_type==11) {
 size_t j;

 for (j=0; j*sh->sh_entsize < sh->sh_size; ++j) {
   const Elf32_Sym* es=(Elf32_Sym*)(elfimage + sh->sh_offset + j*sh->sh_entsize);

   if (!strcmp(dynstringtable+es->st_name,symbol)) {
     const Elf32_Shdr* sec=(Elf32_Shdr*)(elfimage + eh->e_shoff + es->st_shndx*eh->e_shentsize);
     size_t ofs=es->st_value-sec->sh_addr+sec->sh_offset;


     return elfimage + ofs;
   }
 }
      }
      sh = (Elf32_Shdr*)((char*)sh + eh->e_shentsize);
    }
  }
  return 0;
}



static pid_t vfork() { return fork(); }
struct str_data {
  char* str;
  size_t len;
  size_t size;
};

static int swrite(const void*ptr, size_t nmemb, void* cookie) {
  struct str_data* sd=cookie;
  size_t tmp=sd->size-sd->len;
  if (tmp>0) {
    size_t len=nmemb;
    if (len>tmp) len=tmp;
    if (sd->str) {
      memcpy(sd->str+sd->len,ptr,len);
      sd->str[sd->len+len]=0;
    }
    sd->len+=len;
  }
  return nmemb;
}

static int vsnprintf(char* str, size_t size, const char *format, va_list arg_ptr) {
  int n;
  struct str_data sd = { str, 0, size?size-1:0 };
  struct arg_printf ap = { &sd, swrite };
  n=__v_printf(&ap,format,arg_ptr);
  if (str && size && n>=0) {
    if (size!=(size_t)-1 && ((size_t)n>=size)) str[size-1]=0;
    else str[n]=0;
  }
  return n;
}





static int vsprintf(char *dest,const char *format, va_list arg_ptr)
{
  return vsnprintf(dest,(size_t)-1-(uintptr_t)dest,format,arg_ptr);
}

asm (".section .gnu.warning." "vsprintf" "\n\t.string \"" "warning: Avoid *sprintf; use *snprintf. It is more secure." "\"\n\t.previous");






struct str_data {
  unsigned char* str;
};

static int sgetc(struct str_data* sd) {
  register unsigned int ret = *(sd->str++);
  return (ret)?(int)ret:-1;
}

static int sputc(int c, struct str_data* sd) {
  return (*(--sd->str)==c)?c:-1;
}

static int vsscanf(const char* str, const char* format, va_list arg_ptr)
{
  struct str_data fdat = { (unsigned char*)str };
  struct arg_scanf farg = { (void*)&fdat, (int(*)(void*))sgetc, (int(*)(int,void*))sputc };
  return __v_scanf(&farg,format,arg_ptr);
}









static pid_t wait(int *status);
static pid_t waitpid(pid_t pid, int *status, int options);

static pid_t wait3(int *status, int options, struct rusage *rusage) __attribute__((__nothrow__));

static pid_t wait4(pid_t pid, int *status, int options, struct rusage *rusage) __attribute__((__nothrow__));

typedef enum {
  P_ALL,
  P_PID,
  P_PGID
} idtype_t;

static int waitid(idtype_t idtype, id_t id, siginfo_t *infop, int options);




static pid_t wait(int *status) {
  return waitpid(-1,status,0);
}


static pid_t wait3(int* status,int opts,struct rusage* rusage) {
  return wait4(-1,status,opts,rusage);
}



static mbstate_t internal;

static size_t wcrtomb(char *s, wchar_t wc, mbstate_t *ps) {
  if (!ps) ps=&internal;
  switch (lc_ctype) {
  case CT_8BIT:
    if (!s) return 0;
    *s=wc;
    return 1;
  case CT_UTF8:
    if (!s) return (wc>=0x80);
    {
      char c;
      unsigned int bits,j,k;
      if (wc>=0x04000000) { bits=30; c=0xFC; j=6; } else
      if (wc>=0x00200000) { bits=24; c=0xF8; j=5; } else
      if (wc>=0x00010000) { bits=18; c=0xF0; j=4; } else
      if (wc>=0x00000800) { bits=12; c=0xE0; j=3; } else
      if (wc>=0x00000080) { bits=6; c=0xC0; j=2; } else
   { *s=wc; return 1; }
      c |= (unsigned char)(wc>>bits);
      if (s) {
 *s=c;
 for (k=1; k<j; ++k) {
   bits-=6;
   s[k]=0x80+((wc>>bits)&0x3f);
 }
      }
      return j;
    }
  }
  return 0;
}


static wchar_t* wcscat(wchar_t *__restrict__ dest, const wchar_t *__restrict__ src) {
  wchar_t* orig=dest;
  for (; *dest; ++dest) ;
  for (; (*dest=*src); ++src,++dest) ;
  return orig;
}


static wchar_t* wcschr(const wchar_t *wcs, wchar_t wc) {
  for (; *wcs; ++wcs)
    if (*wcs == wc)
      return (wchar_t*)wcs;
  return 0;
}


static int wcscmp(const wchar_t* a,const wchar_t* b) {
  while (*a && *a == *b)
    a++, b++;
  return (*a - *b);
}

static int wcscoll(const wchar_t *s,const wchar_t* t) __attribute__((alias("wcscmp")));


static wchar_t* wcscpy(wchar_t *__restrict__ dest, const wchar_t *__restrict__ src) {
  wchar_t* orig=dest;
  for (; (*dest=*src); ++src,++dest) ;
  return orig;
}


static size_t wcslen(const wchar_t* s) {
  size_t i;
  for (i=0; s[i]; ++i) ;
  return i;
}


static wchar_t* wcsncat(wchar_t *__restrict__ dest, const wchar_t *__restrict__ src,size_t n) {
  wchar_t* orig=dest;
  size_t i;
  while (*dest) ++dest;
  for (i=0; i<n && src[i]; ++i) dest[i]=src[i];
  dest[i]=0;
  return orig;
}


static int wcsncmp(const wchar_t *s1, const wchar_t *s2, size_t n) {
  size_t i;
  for (i=0; i<n && s1[i]==s2[i]; ++i) ;
  return s1[i]-s2[i];
}


static wchar_t* wcsncpy(wchar_t *__restrict__ dest, const wchar_t *__restrict__ src,size_t n) {
  wchar_t* orig=dest;
  for (; dest<orig+n && (*dest=*src); ++src,++dest) ;
  for (; dest<orig+n; ++dest) *dest=0;
  return orig;
}


static wchar_t* wcsrchr(const wchar_t *wcs, wchar_t wc) {
  wchar_t* last=0;
  for (; *wcs; ++wcs)
    if (*wcs == wc)
      last=(wchar_t*)wcs;
  return last;
}







static size_t wcsrtombs(char *dest, const wchar_t **src, size_t len, mbstate_t *ps) {
  wchar_t c;
  char buf[
          5
                    ];
  size_t cur;
  if (!src || !*src) {
inval:
    errno=
         22
               ;
    return -1;
  }
  if (!dest) {
    len=-1;
  }
  for (cur=0; (c=**src); ++*src) {
    size_t n;
    char* s=
           __builtin_expect((long)((
           len-cur>=
           5)),1)
                                        ?(dest?dest+cur:
                                                        (void*)0
                                                            ):buf;
    n=wcrtomb(s,c,ps);
    if (n==(size_t)-1) return -1;
    if (dest && s==buf) {

      if (len<n) return cur;
      memcpy(dest+cur,buf,n);
    }
    cur+=n;
  }
  if (dest && len>cur) dest[cur]=0;
keinplatz:
  return cur;
}



static wchar_t *wcsstr(const wchar_t *haystack, const wchar_t *needle) {
  size_t i,j;
  for (i=0; haystack[i]; ++i) {
    for (j=0; haystack[i+j]==needle[j]; ++j) ;
    if (!needle[j]) return (wchar_t*)haystack+i;
  }
  return 0;
}
static size_t wcstombs(char *dest, const wchar_t *src, size_t len) {
  return wcsrtombs(dest,&src,len,
                                (void*)0
                                    );
}
static int wcswidth(const wchar_t *pwcs, size_t n)
{
  int w, width = 0;

  for (;*pwcs && n-- > 0; pwcs++)
    if ((w = wcwidth(*pwcs)) < 0)
      return -1;
    else
      width += w;

  return width;
}




static int wctomb(char *pwc, wchar_t s) {
  return wcrtomb(pwc,s,
                      (void*)0
                          );
}
struct interval {
  int first;
  int last;
};


static int bisearch(wchar_t ucs, const struct interval *table, int max) {
  int min = 0;
  int mid;

  if (ucs < table[0].first || ucs > table[max].last)
    return 0;
  while (max >= min) {
    mid = (min + max) / 2;
    if (ucs > table[mid].last)
      min = mid + 1;
    else if (ucs < table[mid].first)
      max = mid - 1;
    else
      return 1;
  }

  return 0;
}
static int wcwidth(wchar_t ucs)
{


  static const struct interval combining[] = {
    { 0x0300, 0x036F }, { 0x0483, 0x0486 }, { 0x0488, 0x0489 },
    { 0x0591, 0x05BD }, { 0x05BF, 0x05BF }, { 0x05C1, 0x05C2 },
    { 0x05C4, 0x05C5 }, { 0x05C7, 0x05C7 }, { 0x0600, 0x0603 },
    { 0x0610, 0x0615 }, { 0x064B, 0x065E }, { 0x0670, 0x0670 },
    { 0x06D6, 0x06E4 }, { 0x06E7, 0x06E8 }, { 0x06EA, 0x06ED },
    { 0x070F, 0x070F }, { 0x0711, 0x0711 }, { 0x0730, 0x074A },
    { 0x07A6, 0x07B0 }, { 0x07EB, 0x07F3 }, { 0x0901, 0x0902 },
    { 0x093C, 0x093C }, { 0x0941, 0x0948 }, { 0x094D, 0x094D },
    { 0x0951, 0x0954 }, { 0x0962, 0x0963 }, { 0x0981, 0x0981 },
    { 0x09BC, 0x09BC }, { 0x09C1, 0x09C4 }, { 0x09CD, 0x09CD },
    { 0x09E2, 0x09E3 }, { 0x0A01, 0x0A02 }, { 0x0A3C, 0x0A3C },
    { 0x0A41, 0x0A42 }, { 0x0A47, 0x0A48 }, { 0x0A4B, 0x0A4D },
    { 0x0A70, 0x0A71 }, { 0x0A81, 0x0A82 }, { 0x0ABC, 0x0ABC },
    { 0x0AC1, 0x0AC5 }, { 0x0AC7, 0x0AC8 }, { 0x0ACD, 0x0ACD },
    { 0x0AE2, 0x0AE3 }, { 0x0B01, 0x0B01 }, { 0x0B3C, 0x0B3C },
    { 0x0B3F, 0x0B3F }, { 0x0B41, 0x0B43 }, { 0x0B4D, 0x0B4D },
    { 0x0B56, 0x0B56 }, { 0x0B82, 0x0B82 }, { 0x0BC0, 0x0BC0 },
    { 0x0BCD, 0x0BCD }, { 0x0C3E, 0x0C40 }, { 0x0C46, 0x0C48 },
    { 0x0C4A, 0x0C4D }, { 0x0C55, 0x0C56 }, { 0x0CBC, 0x0CBC },
    { 0x0CBF, 0x0CBF }, { 0x0CC6, 0x0CC6 }, { 0x0CCC, 0x0CCD },
    { 0x0CE2, 0x0CE3 }, { 0x0D41, 0x0D43 }, { 0x0D4D, 0x0D4D },
    { 0x0DCA, 0x0DCA }, { 0x0DD2, 0x0DD4 }, { 0x0DD6, 0x0DD6 },
    { 0x0E31, 0x0E31 }, { 0x0E34, 0x0E3A }, { 0x0E47, 0x0E4E },
    { 0x0EB1, 0x0EB1 }, { 0x0EB4, 0x0EB9 }, { 0x0EBB, 0x0EBC },
    { 0x0EC8, 0x0ECD }, { 0x0F18, 0x0F19 }, { 0x0F35, 0x0F35 },
    { 0x0F37, 0x0F37 }, { 0x0F39, 0x0F39 }, { 0x0F71, 0x0F7E },
    { 0x0F80, 0x0F84 }, { 0x0F86, 0x0F87 }, { 0x0F90, 0x0F97 },
    { 0x0F99, 0x0FBC }, { 0x0FC6, 0x0FC6 }, { 0x102D, 0x1030 },
    { 0x1032, 0x1032 }, { 0x1036, 0x1037 }, { 0x1039, 0x1039 },
    { 0x1058, 0x1059 }, { 0x1160, 0x11FF }, { 0x135F, 0x135F },
    { 0x1712, 0x1714 }, { 0x1732, 0x1734 }, { 0x1752, 0x1753 },
    { 0x1772, 0x1773 }, { 0x17B4, 0x17B5 }, { 0x17B7, 0x17BD },
    { 0x17C6, 0x17C6 }, { 0x17C9, 0x17D3 }, { 0x17DD, 0x17DD },
    { 0x180B, 0x180D }, { 0x18A9, 0x18A9 }, { 0x1920, 0x1922 },
    { 0x1927, 0x1928 }, { 0x1932, 0x1932 }, { 0x1939, 0x193B },
    { 0x1A17, 0x1A18 }, { 0x1B00, 0x1B03 }, { 0x1B34, 0x1B34 },
    { 0x1B36, 0x1B3A }, { 0x1B3C, 0x1B3C }, { 0x1B42, 0x1B42 },
    { 0x1B6B, 0x1B73 }, { 0x1DC0, 0x1DCA }, { 0x1DFE, 0x1DFF },
    { 0x200B, 0x200F }, { 0x202A, 0x202E }, { 0x2060, 0x2063 },
    { 0x206A, 0x206F }, { 0x20D0, 0x20EF }, { 0x302A, 0x302F },
    { 0x3099, 0x309A }, { 0xA806, 0xA806 }, { 0xA80B, 0xA80B },
    { 0xA825, 0xA826 }, { 0xFB1E, 0xFB1E }, { 0xFE00, 0xFE0F },
    { 0xFE20, 0xFE23 }, { 0xFEFF, 0xFEFF }, { 0xFFF9, 0xFFFB },
    { 0x10A01, 0x10A03 }, { 0x10A05, 0x10A06 }, { 0x10A0C, 0x10A0F },
    { 0x10A38, 0x10A3A }, { 0x10A3F, 0x10A3F }, { 0x1D167, 0x1D169 },
    { 0x1D173, 0x1D182 }, { 0x1D185, 0x1D18B }, { 0x1D1AA, 0x1D1AD },
    { 0x1D242, 0x1D244 }, { 0xE0001, 0xE0001 }, { 0xE0020, 0xE007F },
    { 0xE0100, 0xE01EF }
  };


  if (ucs == 0)
    return 0;
  if (ucs < 32 || (ucs >= 0x7f && ucs < 0xa0))
    return -1;


  if (bisearch(ucs, combining,
        sizeof(combining) / sizeof(struct interval) - 1))
    return 0;



  return 1 +
    (ucs >= 0x1100 &&
     (ucs <= 0x115f ||
      ucs == 0x2329 || ucs == 0x232a ||
      (ucs >= 0x2e80 && ucs <= 0xa4cf &&
       ucs != 0x303f) ||
      (ucs >= 0xac00 && ucs <= 0xd7a3) ||
      (ucs >= 0xf900 && ucs <= 0xfaff) ||
      (ucs >= 0xfe10 && ucs <= 0xfe19) ||
      (ucs >= 0xfe30 && ucs <= 0xfe6f) ||
      (ucs >= 0xff00 && ucs <= 0xff60) ||
      (ucs >= 0xffe0 && ucs <= 0xffe6) ||
      (ucs >= 0x20000 && ucs <= 0x2fffd) ||
      (ucs >= 0x30000 && ucs <= 0x3fffd)));
}









static ssize_t __write1 ( const char* s ) __attribute__ (( ));
static ssize_t __write2 ( const char* s ) __attribute__ (( ));










static ssize_t __write1 (const char* s) {
  return write(1, s, strlen(s));
}

static ssize_t __write2 (const char* s) {
  return write(2, s, strlen(s));
}





 size_t __pread(int fd, void *buf, size_t count, int dummy, off_t a, off_t b);

static size_t __libc_pread64(int fd, void *buf, size_t count, off64_t offset);
static size_t __libc_pread64(int fd, void *buf, size_t count, off64_t offset) {
  return __pread(fd,buf,count,0,(off_t)(offset>>32)
                               , 
                               (off_t)(offset&0xffffffff));
}

static int pread64(int fd, void *buf, size_t count, off_t offset) __attribute__((alias("__libc_pread64")));






 size_t __pwrite(int fd, void *buf, size_t count, int dummy, off_t a, off_t b);

static size_t __libc_pwrite64(int fd, void *buf, size_t count, off64_t offset);
static size_t __libc_pwrite64(int fd, void *buf, size_t count, off64_t offset) {
  return __pwrite(fd,buf,count,0,(off_t)(offset>>32)
                                , 
                                (off_t)(offset&0xffffffff));
}

static int pwrite64(int fd, void *buf, size_t count, off_t offset) __attribute__((alias("__libc_pwrite64")));
static const
static unsigned char __clz_tab[] =
{
  0,1,2,2,3,3,3,3,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
  6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,
  7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
  7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
  8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
  8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
  8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
  8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
};


typedef unsigned int UQItype __attribute__ ((mode (QI)));
typedef int SItype __attribute__ ((mode (SI)));
typedef unsigned int USItype __attribute__ ((mode (SI)));
typedef int DItype __attribute__ ((mode (DI)));
typedef unsigned int UDItype __attribute__ ((mode (DI)));
struct DWstruct { SItype high, low;};





typedef union { struct DWstruct s; DItype ll; } DWunion;


 DItype __divdi3 (DItype u, DItype v);
 DItype __moddi3 (DItype u, DItype v);
 UDItype __udivdi3 (UDItype u, UDItype v);
 UDItype __umoddi3 (UDItype u, UDItype v);

static UDItype
static __udivmoddi4 (UDItype n, UDItype d, UDItype *rp)
{
  DWunion ww;
  DWunion nn, dd;
  DWunion rr;
  USItype d0, d1, n0, n1, n2;
  USItype q0, q1;
  USItype b, bm;

  nn.ll = n;
  dd.ll = d;

  d0 = dd.s.low;
  d1 = dd.s.high;
  n0 = nn.s.low;
  n1 = nn.s.high;
  if (d1 == 0)
    {
      if (d0 > n1)
 {


   do { USItype __xr = (d0); USItype __a; if (32 <= 32) { __a = __xr < ((USItype)1<<2*(32 / 4)) ? (__xr < ((USItype)1<<(32 / 4)) ? 0 : (32 / 4)) : (__xr < ((USItype)1<<3*(32 / 4)) ? 2*(32 / 4) : 3*(32 / 4)); } else { for (__a = 32 - 8; __a > 0; __a -= 8) if (((__xr >> __a) & 0xff) != 0) break; } (bm) = 32 - (__clz_tab[__xr >> __a] + __a); } while (0);

   if (bm != 0)
     {



       d0 = d0 << bm;
       n1 = (n1 << bm) | (n0 >> (32 - bm));
       n0 = n0 << bm;
     }

   do { USItype __d1, __d0, __q1, __q0; USItype __r1, __r0, __m; __d1 = ((USItype) (d0) >> (32 / 2)); __d0 = ((USItype) (d0) & (((USItype) 1 << (32 / 2)) - 1)); __r1 = (n1) % __d1; __q1 = (n1) / __d1; __m = (USItype) __q1 * __d0; __r1 = __r1 * ((USItype) 1 << (32 / 2)) | ((USItype) (n0) >> (32 / 2)); if (__r1 < __m) { __q1--, __r1 += (d0); if (__r1 >= (d0)) if (__r1 < __m) __q1--, __r1 += (d0); } __r1 -= __m; __r0 = __r1 % __d1; __q0 = __r1 / __d1; __m = (USItype) __q0 * __d0; __r0 = __r0 * ((USItype) 1 << (32 / 2)) | ((USItype) (n0) & (((USItype) 1 << (32 / 2)) - 1)); if (__r0 < __m) { __q0--, __r0 += (d0); if (__r0 >= (d0)) if (__r0 < __m) __q0--, __r0 += (d0); } __r0 -= __m; (q0) = (USItype) __q1 * ((USItype) 1 << (32 / 2)) | __q0; (n0) = __r0; } while (0);
   q1 = 0;


 }
      else
 {


   if (d0 == 0)
     d0 = 1 / d0;

   do { USItype __xr = (d0); USItype __a; if (32 <= 32) { __a = __xr < ((USItype)1<<2*(32 / 4)) ? (__xr < ((USItype)1<<(32 / 4)) ? 0 : (32 / 4)) : (__xr < ((USItype)1<<3*(32 / 4)) ? 2*(32 / 4) : 3*(32 / 4)); } else { for (__a = 32 - 8; __a > 0; __a -= 8) if (((__xr >> __a) & 0xff) != 0) break; } (bm) = 32 - (__clz_tab[__xr >> __a] + __a); } while (0);

   if (bm == 0)
     {







       n1 -= d0;
       q1 = 1;
     }
   else
     {


       b = 32 - bm;

       d0 = d0 << bm;
       n2 = n1 >> b;
       n1 = (n1 << bm) | (n0 >> b);
       n0 = n0 << bm;

       do { USItype __d1, __d0, __q1, __q0; USItype __r1, __r0, __m; __d1 = ((USItype) (d0) >> (32 / 2)); __d0 = ((USItype) (d0) & (((USItype) 1 << (32 / 2)) - 1)); __r1 = (n2) % __d1; __q1 = (n2) / __d1; __m = (USItype) __q1 * __d0; __r1 = __r1 * ((USItype) 1 << (32 / 2)) | ((USItype) (n1) >> (32 / 2)); if (__r1 < __m) { __q1--, __r1 += (d0); if (__r1 >= (d0)) if (__r1 < __m) __q1--, __r1 += (d0); } __r1 -= __m; __r0 = __r1 % __d1; __q0 = __r1 / __d1; __m = (USItype) __q0 * __d0; __r0 = __r0 * ((USItype) 1 << (32 / 2)) | ((USItype) (n1) & (((USItype) 1 << (32 / 2)) - 1)); if (__r0 < __m) { __q0--, __r0 += (d0); if (__r0 >= (d0)) if (__r0 < __m) __q0--, __r0 += (d0); } __r0 -= __m; (q1) = (USItype) __q1 * ((USItype) 1 << (32 / 2)) | __q0; (n1) = __r0; } while (0);
     }



   do { USItype __d1, __d0, __q1, __q0; USItype __r1, __r0, __m; __d1 = ((USItype) (d0) >> (32 / 2)); __d0 = ((USItype) (d0) & (((USItype) 1 << (32 / 2)) - 1)); __r1 = (n1) % __d1; __q1 = (n1) / __d1; __m = (USItype) __q1 * __d0; __r1 = __r1 * ((USItype) 1 << (32 / 2)) | ((USItype) (n0) >> (32 / 2)); if (__r1 < __m) { __q1--, __r1 += (d0); if (__r1 >= (d0)) if (__r1 < __m) __q1--, __r1 += (d0); } __r1 -= __m; __r0 = __r1 % __d1; __q0 = __r1 / __d1; __m = (USItype) __q0 * __d0; __r0 = __r0 * ((USItype) 1 << (32 / 2)) | ((USItype) (n0) & (((USItype) 1 << (32 / 2)) - 1)); if (__r0 < __m) { __q0--, __r0 += (d0); if (__r0 >= (d0)) if (__r0 < __m) __q0--, __r0 += (d0); } __r0 -= __m; (q0) = (USItype) __q1 * ((USItype) 1 << (32 / 2)) | __q0; (n0) = __r0; } while (0);


 }

      if (rp != 0)
 {
   rr.s.low = n0 >> bm;
   rr.s.high = 0;
   *rp = rr.ll;
 }
    }


  else
    {
      if (d1 > n1)
 {


   q0 = 0;
   q1 = 0;


   if (rp != 0)
     {
       rr.s.low = n0;
       rr.s.high = n1;
       *rp = rr.ll;
     }
 }
      else
 {


   do { USItype __xr = (d1); USItype __a; if (32 <= 32) { __a = __xr < ((USItype)1<<2*(32 / 4)) ? (__xr < ((USItype)1<<(32 / 4)) ? 0 : (32 / 4)) : (__xr < ((USItype)1<<3*(32 / 4)) ? 2*(32 / 4) : 3*(32 / 4)); } else { for (__a = 32 - 8; __a > 0; __a -= 8) if (((__xr >> __a) & 0xff) != 0) break; } (bm) = 32 - (__clz_tab[__xr >> __a] + __a); } while (0);
   if (bm == 0)
     {
       if (n1 > d1 || n0 >= d0)
  {
    q0 = 1;
    do { USItype __x; __x = (n0) - (d0); (n1) = (n1) - (d1) - (__x > (n0)); (n0) = __x; } while (0);
  }
       else
  q0 = 0;

       q1 = 0;

       if (rp != 0)
  {
    rr.s.low = n0;
    rr.s.high = n1;
    *rp = rr.ll;
  }
     }
   else
     {
       USItype m1, m0;


       b = 32 - bm;

       d1 = (d1 << bm) | (d0 >> b);
       d0 = d0 << bm;
       n2 = n1 >> b;
       n1 = (n1 << bm) | (n0 >> b);
       n0 = n0 << bm;

       do { USItype __d1, __d0, __q1, __q0; USItype __r1, __r0, __m; __d1 = ((USItype) (d1) >> (32 / 2)); __d0 = ((USItype) (d1) & (((USItype) 1 << (32 / 2)) - 1)); __r1 = (n2) % __d1; __q1 = (n2) / __d1; __m = (USItype) __q1 * __d0; __r1 = __r1 * ((USItype) 1 << (32 / 2)) | ((USItype) (n1) >> (32 / 2)); if (__r1 < __m) { __q1--, __r1 += (d1); if (__r1 >= (d1)) if (__r1 < __m) __q1--, __r1 += (d1); } __r1 -= __m; __r0 = __r1 % __d1; __q0 = __r1 / __d1; __m = (USItype) __q0 * __d0; __r0 = __r0 * ((USItype) 1 << (32 / 2)) | ((USItype) (n1) & (((USItype) 1 << (32 / 2)) - 1)); if (__r0 < __m) { __q0--, __r0 += (d1); if (__r0 >= (d1)) if (__r0 < __m) __q0--, __r0 += (d1); } __r0 -= __m; (q0) = (USItype) __q1 * ((USItype) 1 << (32 / 2)) | __q0; (n1) = __r0; } while (0);
       do { UDItype __x = (UDItype) (USItype) (q0) * (USItype) (d0); (m1) = (USItype) (__x >> 32); (m0) = (USItype) (__x); } while (0);

       if (m1 > n1 || (m1 == n1 && m0 > n0))
  {
    q0--;
    do { USItype __x; __x = (m0) - (d0); (m1) = (m1) - (d1) - (__x > (m0)); (m0) = __x; } while (0);
  }

       q1 = 0;


       if (rp != 0)
  {
    do { USItype __x; __x = (n0) - (m0); (n1) = (n1) - (m1) - (__x > (n0)); (n0) = __x; } while (0);
    rr.s.low = (n1 << b) | (n0 >> bm);
    rr.s.high = n1 >> bm;
    *rp = rr.ll;
  }
     }
 }
    }

  ww.s.low = q0;
  ww.s.high = q1;
  return ww.ll;
}

static DItype
static __divdi3 (DItype u, DItype v)
{
  SItype c = 0;
  DItype w;

  if (u < 0)
    {
      c = ~c;
      u = -u;
    }
  if (v < 0)
    {
      c = ~c;
      v = -v;
    }
  w = __udivmoddi4 (u, v, 
                         (void*)0
                             );
  if (c)
    w = -w;
  return w;
}

static DItype
static __moddi3 (DItype u, DItype v)
{
  SItype c = 0;
  DItype w;

  if (u < 0)
    {
      c = ~c;
      u = -u;
    }
  if (v < 0)
    v = -v;
  __udivmoddi4 (u, v, (UDItype *) &w);
  if (c)
    w = -w;
  return w;
}

static UDItype
static __udivdi3 (UDItype u, UDItype v)
{
  return __udivmoddi4 (u, v, 
                            (void*)0
                                );
}

static UDItype
static __umoddi3 (UDItype u, UDItype v)
{
  UDItype w;

  __udivmoddi4 (u, v, &w);
  return w;
}










static size_t __fbufsize(FILE *stream);
static size_t __fpending(FILE *stream);
static int __flbf(FILE *stream);
static int __freadable(FILE *stream);
static int __fwritable(FILE *stream);
static int __freading(FILE *stream);
static int __fwriting(FILE *stream);
static int __fsetlocking(FILE *stream, int type);
static void _flushlbf(void);
static void __fpurge(FILE *stream);





static size_t __fbufsize(FILE* stream) {
  return stream->buflen;
}



static int __flbf(FILE* stream) {
  return !!(stream->flags&8);
}



static size_t __fpending(FILE* stream) {
  return stream->bm;
}



static void __fpurge(FILE* stream) {
  stream->ungotten=0;
  stream->bs=stream->bm=0;
}



static int __freadable(FILE* stream) {
  return !!(stream->flags&128);
}



static int __freading(FILE* stream) {
  return !(stream->flags&256);
}



static int __fwritable(FILE* stream) {
  return !!(stream->flags&256);
}


static void clearerr_unlocked(FILE *stream) {
  stream->flags&=~(1|2);
}

static void clearerr(FILE *stream) __attribute__((alias("clearerr_unlocked")));




static int fclose_unlocked(FILE *stream) {
  int res;
  FILE *f,*fl;
  res=fflush_unlocked(stream);
  res|=__libc_close(stream->fd);
  for (fl=0,f=__stdio_root; f; fl=f,f=f->next)
    if (f==stream) {
      if (fl)
 fl->next=f->next;
      else
 __stdio_root=f->next;
      break;
    }
  if ((!(stream->flags&32))&&(stream->buf))
    free(stream->buf);
  free(stream);
  return res;
}

static int fclose(FILE *stream) __attribute__((alias("fclose_unlocked")));
static int __stdio_parse_mode(const char *mode) {
  int f=0;
  for (;;) {
    switch (*mode) {
    case 0: return f;
    case 'b': break;
    case 'r': f|=
                0x0000
                        ; break;
    case 'w': f|=
                0x0001
                        |
                         0x0100
                                |
                                 0x0200
                                        ; break;
    case 'a': f|=
                0x0001
                        |
                         0x0100
                                |
                                 0x0008
                                         ; break;
    case 'x': f|=
                0x0400
                      ; break;
    case '+': f=(f&(~
                    0x0001
                            ))|
                               0x0002
                                     ; break;
    }
    ++mode;
  }
}
 int __stdio_atexit;

static FILE*__stdio_init_file(int fd,int closeonerror,int mode) {
  FILE *tmp=(FILE*)malloc(sizeof(FILE));
  if (!tmp) goto err_out;
  tmp->buf=(char*)malloc(2048);
  if (!tmp->buf) {
    free(tmp);
err_out:
    if (closeonerror) __libc_close(fd);
    errno=
         12
               ;
    return 0;
  }
  tmp->fd=fd;
  tmp->bm=0;
  tmp->bs=0;
  tmp->buflen=2048;
  {
    struct stat st;
    fstat(fd,&st);
    tmp->flags=(
               (((
               st.st_mode
               ) & 00170000) == 0010000)
                                   )?64:0;
  }
  switch (mode&3) {
  case 
      0x0002
            : tmp->flags|=256;
  case 
      0x0000
              : tmp->flags|=128|4; break;
  case 
      0x0001
              : tmp->flags|=256;
  }
  tmp->popen_kludge=0;
  if (__stdio_atexit==0) {
    __stdio_atexit=1;
    atexit(__stdio_flushall);
  }
  tmp->next=__stdio_root;
  __stdio_root=tmp;
  tmp->ungotten=0;
  return tmp;
}

static FILE* __stdio_init_file_nothreads(int fd,int closeonerror,int mode) __attribute__((alias("__stdio_init_file")));






static FILE *fdopen_unlocked(int filedes, const char *mode) {
  int f=0;

  f=__stdio_parse_mode(mode);
  if (filedes<0) { errno=
                        9
                             ; return 0; }
  return __stdio_init_file(filedes,0,f);
}

static FILE *fdopen(int filedes, const char *mode) __attribute__((alias("fdopen_unlocked")));


static int feof_unlocked(FILE*stream) {

  if (stream->ungotten) return 0;
  return (stream->flags&2);
}
static int feof(FILE*stream)
static __attribute__((alias("feof_unlocked")));





static int fdprintf(int fd,const char *format,...) {
  int n;
  va_list arg_ptr;
  
 __builtin_va_start((
 arg_ptr
 ),(
 format
 ))
                         ;
  n=vfdprintf(fd,format,arg_ptr);
  
 __builtin_va_end
       (arg_ptr);
  return n;
}


static int ferror_unlocked(FILE*stream) {
  return (stream->flags&1);
}
static int ferror(FILE*stream)
static __attribute__((alias("ferror_unlocked")));




static FILE *__stdio_root;

static int __stdio_atexit=0;

static int fflush(FILE *stream) __attribute__((alias("fflush_unlocked")));

static void __stdio_flushall(void) {
  fflush(0);
}

static int fflush_unlocked(FILE *stream) {
  if (stream==0) {
    int res;
    FILE *f;
    __fflush_stdout();
    __fflush_stderr();
    for (res=0, f=__stdio_root; f; f=f->next)
      if (fflush(f))
 res=-1;
    return res;
  }

  if (stream->flags&4) {
    register int tmp;
    if ((tmp=stream->bm-stream->bs)) {
      if (tmp && stream->ungotten) --tmp;
      lseek(stream->fd,tmp,
                          1
                                  );
    }
    stream->bs=stream->bm=0;
  } else {
    if (stream->bm && write(stream->fd,stream->buf,stream->bm)!=(ssize_t)stream->bm) {
      stream->flags|=1;
      return -1;
    }
    stream->bm=0;
  }
  stream->ungotten=0;
  return 0;
}

static int __fflush4(FILE *stream,int next) {
  if (
     __builtin_expect((long)((
     !__stdio_atexit
     )),0)
                                ) {
    __stdio_atexit=1;
    atexit(__stdio_flushall);
  }
  if (
     __builtin_expect((long)((
     (stream->flags&4)!=next
     )),0)
                                               ) {
    int res=fflush_unlocked(stream);
    stream->flags=(stream->flags&~4)|next;
    return res;
  }
  if (stream->fd==0 && __stdin_is_tty()) __fflush_stdout();
  return 0;
}



static int __stdio_outs(const char *s,size_t len);
static int __stdio_outs(const char *s,size_t len) {
  return fwrite(s,1,(size_t)len,stdout)==len?1:0;
}

asm (".section .gnu.warning." "fflush" "\n\t.string \"" "warning: your code uses stdio (7+k bloat)." "\"\n\t.previous");



static int fgetc_unlocked(FILE *stream) {
  unsigned char c;
  if (
     __builtin_expect((long)((
     !(stream->flags&128)
     )),0)
                                         ) goto kaputt;
  if (
     __builtin_expect((long)((
     stream->ungotten
     )),0)
                                 ) {
    stream->ungotten=0;
    return stream->ungetbuf;
  }


  if (
     __builtin_expect((long)((
     stream->bm<stream->bs
     )),1)
                                    )
    return (unsigned char)stream->buf[stream->bm++];

  if (
     __builtin_expect((long)((
     feof_unlocked(stream)
     )),0)
                                      )
    return 
          (-1)
             ;
  if (__fflush4(stream,4)) return 
                                        (-1)
                                           ;
  if (
     __builtin_expect((long)((
     stream->bm>=stream->bs
     )),0)
                                       ) {
    ssize_t len=__libc_read(stream->fd,stream->buf,stream->buflen);
    if (len==0) {
      stream->flags|=2;
      return 
            (-1)
               ;
    } else if (len<0) {
kaputt:
      stream->flags|=1;
      return 
            (-1)
               ;
    }
    stream->bm=0;
    stream->bs=len;
  }
  c=stream->buf[stream->bm];
  ++stream->bm;
  return c;
}

static int fgetc(FILE* stream) __attribute__((alias("fgetc_unlocked")));


static int fgetpos(FILE *stream, fpos_t *pos) {
  long l=ftell(stream);
  if (l==-1) return -1;
  *pos=l;
  return 0;
}


static char *fgets_unlocked(char *s, int size, FILE *stream) {
  int l;
  if (size<=0) return 0;
  for (l=0; l+1<size; ) {
    register int c;
    if (l && 
            __builtin_expect((long)((
            stream->bm<stream->bs
            )),1)
                                           ) {

      c=(unsigned char)stream->buf[stream->bm++];
    } else {
      c=fgetc_unlocked(stream);
      if (
         __builtin_expect((long)((
         c==
         (-1))),0)
                           ) {
 if (!l) return 0;
 break;
      }
    }
    s[l]=c;
    ++l;
    if (c=='\n') break;
  }
  s[l]=0;
  return s;
}

static char*fgets(char*s,int size,FILE*stream) __attribute__((alias("fgets_unlocked")));


static int fileno_unlocked(FILE*stream) {
  return stream->fd;
}
static int fileno(FILE*stream)
static __attribute__((alias("fileno_unlocked")));




 int __stdio_atexit;




static FILE *fopen_unlocked(const char *path, const char *mode) {
  int f=0;
  int fd;

  f=__stdio_parse_mode(mode);
  if ((fd=__libc_open(path,f,0666))<0)
    return 0;
  return __stdio_init_file(fd,1,f);
}

static FILE *fopen(const char *path, const char *mode) __attribute__((alias("fopen_unlocked")));





static int fprintf(FILE *f,const char *format,...) {
  int n;
  va_list arg_ptr;
  
 __builtin_va_start((
 arg_ptr
 ),(
 format
 ))
                         ;
  n=vfprintf(f,format,arg_ptr);
  
 __builtin_va_end
       (arg_ptr);
  return n;
}




static int fputc_unlocked(int c, FILE *stream) {
  if (!
      __builtin_expect((long)((
      stream->flags&256
      )),1) 
                                       || __fflush4(stream,0)) {
kaputt:
    stream->flags|=1;
    return 
          (-1)
             ;
  }
  if (
     __builtin_expect((long)((
     stream->bm>=stream->buflen-1
     )),0)
                                             )
    if (fflush_unlocked(stream)) goto kaputt;
  if (stream->flags&16) {



    if (__libc_write(stream->fd,(char*)&c+sizeof(c)-1,1) != 1)

      goto kaputt;
    return (unsigned char)c;
  }
  stream->buf[stream->bm]=c;
  ++stream->bm;
  if (((stream->flags&8) && c=='\n') ||
      ((stream->flags&16)))
    if (fflush_unlocked(stream)) goto kaputt;
  return (unsigned char)c;
}

static int fputc(int c,FILE* stream) __attribute__((alias("fputc_unlocked")));



static int fputs_unlocked(const char*s,FILE*stream) {
  return fwrite_unlocked(s,strlen(s),1,stream);
}

static int fputs(const char*s,FILE*stream) __attribute__((alias("fputs_unlocked")));




static size_t fread_unlocked(void *ptr, size_t size, size_t nmemb, FILE *stream) {
  unsigned long i,j;
  j=size*nmemb;
  i=0;

  if (!(stream->flags&128)) {
    stream->flags|=1;
    return 0;
  }
  if (!j || j/nmemb!=size) return 0;
  if (
     __builtin_expect((long)((
     stream->ungotten
     )),0)
                                 ) {
    stream->ungotten=0;
    *(char*)ptr=stream->ungetbuf;
    ++i;
    if (j==1) return 1;
  }


  if (
     __builtin_expect((long)((
     feof_unlocked(stream)
     )),0)
                                      )
    return 0;
  if (__fflush4(stream,4)) return 0;

  size_t inbuf=stream->bs-stream->bm;
  if (
     __builtin_expect((long)((
     !inbuf
     )),0)
                       ) {
    stream->bm=0;
    ssize_t res=__libc_read(stream->fd,stream->buf,stream->buflen);
    if (res<1) {
      stream->flags |= (res==0 ? 2 : 1);
      return i/size;
    }
    inbuf=stream->bs=res;
  }
  if (inbuf) {
    size_t tocopy=j>inbuf ? inbuf : j;
    memcpy(ptr+i,stream->buf+stream->bm,tocopy);
    i+=tocopy;
    stream->bm+=tocopy;
    if (stream->bm==stream->bs)
      stream->bm=stream->bs=0;
    if (i==j) return nmemb;
  }
  if ( !(stream->flags&64) && (j>stream->buflen)) {
    size_t tmp=j-i;
    ssize_t res;

    while ((res=__libc_read(stream->fd,ptr+i,tmp))<(ssize_t)tmp) {
      if (res==-1) {
 stream->flags|=1;
 goto exit;
      } else if (!res) {
 stream->flags|=2;
 goto exit;
      }
      i+=res; tmp-=res;
    }
    return nmemb;
  }

  for (; i<j; ++i) {
    int res;
    res=fgetc_unlocked(stream);
    if (res==
            (-1)
               )
exit:
      return i/size;
    else
      ((unsigned char*)ptr)[i]=(unsigned char)res;
  }
  return nmemb;
}

static size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream) __attribute__((alias("fread_unlocked")));
static FILE *freopen_unlocked(const char *path, const char *mode, FILE *stream) {
  if (stream) {
    int f=__stdio_parse_mode(mode);
    fflush_unlocked(stream);
    __libc_close(stream->fd);
    if ((stream->fd=__libc_open(path,f,0666))!=-1) {
      struct stat st;
      fstat(stream->fd,&st);
      stream->flags=(
                    (((
                    st.st_mode
                    ) & 00170000) == 0010000)
                                        )?64:0;
      switch (f&3) {
      case 
          0x0002
                : stream->flags|=256;
      case 
          0x0000
                  : stream->flags|=128; break;
      case 
          0x0001
                  : stream->flags|=256;
      }
    }
  } else errno=
              22
                    ;
  return stream;
}

static FILE *freopen(const char *path, const char *mode, FILE *stream) __attribute__((alias("freopen_unlocked")));






static int fscanf(FILE *stream, const char *format, ...) {
  int n;
  va_list arg_ptr;
  
 __builtin_va_start((
 arg_ptr
 ),(
 format
 ))
                          ;
  n=vfscanf(stream,format,arg_ptr);
  
 __builtin_va_end 
        (arg_ptr);
  return n;
}



static int fseek_unlocked(FILE *stream, long offset, int whence) {
  fflush_unlocked(stream);
  stream->bm=0; stream->bs=0;
  stream->flags&=~(1|2);
  stream->ungotten=0;
  return lseek(stream->fd,offset,whence)!=-1?0:-1;
}

static int fseek(FILE *stream, long offset, int whence) __attribute__((alias("fseek_unlocked")));



static int fseeko_unlocked(FILE *stream, off_t offset, int whence) {
  fflush(stream);
  stream->bm=0; stream->bs=0;
  stream->flags&=~(1|2);
  stream->ungotten=0;
  return lseek(stream->fd,offset,whence)!=-1?0:-1;
}

static int fseeko(FILE *stream, off_t offset, int whence) __attribute__((alias("fseeko_unlocked")));





static int fseeko64_unlocked(FILE *stream, off64_t offset, int whence) {
  fflush_unlocked(stream);
  stream->bm=0; stream->bs=0;
  stream->flags&=~(1|2);
  stream->ungotten=0;
  return lseek64(stream->fd,offset,whence)!=-1?0:-1;
}

static int fseeko64(FILE *stream, off64_t offset, int whence) __attribute__((alias("fseeko64_unlocked")));



static int fsetpos(FILE *stream, fpos_t *pos) {
  if (fseek(stream,*pos,
                       0
                               )==-1)
    return -1;
  return 0;
}




static long ftell_unlocked(FILE *stream) {
  off_t l;
  if (stream->flags&1 || (l=lseek(stream->fd,0,
                                              1
                                                      ))==-1) return -1;
  if (stream->flags&4)
    return l-(stream->bs-stream->bm)-stream->ungotten;
  else
    return l+stream->bm;
}

static long ftell(FILE *stream) __attribute__((alias("ftell_unlocked")));



static off_t ftello_unlocked(FILE *stream) {
  off_t l;
  if (fflush_unlocked(stream)) return -1;
  return ((l=lseek(stream->fd,0,
                               1
                                       ))==-1?-1:l-stream->ungotten);
}

static off_t ftello(FILE *stream) __attribute__((alias("ftello_unlocked")));





static off64_t ftello64_unlocked(FILE *stream) {
  off64_t l;
  if (fflush_unlocked(stream)) return -1;
  return ((l=lseek64(stream->fd,0ull,
                                    1
                                            ))==-1?-1:l-stream->ungotten);
}

static off64_t ftello64(FILE *stream) __attribute__((alias("ftello64_unlocked")));






static size_t fwrite_unlocked(const void *ptr, size_t size, size_t nmemb, FILE *stream) {
  ssize_t res;
  size_t len=size*nmemb;
  size_t i,done;
  if (!
      __builtin_expect((long)((
      stream->flags&256
      )),1) 
                                       || __fflush4(stream,0)) {
kaputt:
    stream->flags|=1;
    return 0;
  }
  if (!nmemb || len/nmemb!=size) return 0;
  if (
     __builtin_expect((long)((
     len>stream->buflen || (stream->flags&16)
     )),0)
                                                            ) {
    if (fflush_unlocked(stream)) return 0;
    do {
      res=__libc_write(stream->fd,ptr,len);
    } while (res==-1 && errno==
                              4
                                   );
  } else
again:
         {

    size_t todo=stream->buflen-stream->bm;
    if (todo>len) todo=len;

    if (todo) {
      if (stream->flags&8) {
 if (
    __builtin_expect((long)((
    (stream->flags&512)!=0
    )),0)
                                                ) {
   stream->flags&=~512;



   if (!isatty(stream->fd)) {
     stream->flags&=~8;
     goto notlinewise;
   }
 }
 for (i=0; i<todo; ++i) {
   if ((stream->buf[stream->bm++]=((char*)ptr)[i])=='\n') {
     if (fflush_unlocked(stream)) goto kaputt;
   }
 }
      } else {
notlinewise:
 memcpy(stream->buf+stream->bm,ptr,todo);
 stream->bm+=todo;
 if (stream->bm==stream->buflen) {
   if (fflush_unlocked(stream)) return 0;

   len-=todo;
   if (!len) return nmemb;
   ptr+=todo;
   goto again;
 } else
   return nmemb;
      }
      done=todo;
    } else
      done=0;
    for (i=done; i<len; ++i)
      if (fputc_unlocked(((char*)ptr)[i],stream) == 
                                                   (-1)
                                                      ) {
 res=len-i;
 goto abort;
      }
    res=len;
  }
  if (res<0) {
    stream->flags|=1;
    return 0;
  }
abort:
  return size?res/size:0;
}

static size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream) __attribute__((alias("fwrite_unlocked")));






static int printf(const char *format,...)
{
  int n;
  va_list arg_ptr;
  
 __builtin_va_start((
 arg_ptr
 ),(
 format
 ))
                          ;
  n=vprintf(format, arg_ptr);
  
 __builtin_va_end
       (arg_ptr);
  return n;
}



static int putchar(int c) {
  return fputc(c,stdout);
}





static int __stdio_outs(const char *s,size_t len) ;
static int __stdio_outs(const char *s,size_t len) {
  return (write(1,s,len)==(ssize_t)len)?1:0;
}

static int puts(const char *s) {
  return (__stdio_outs(s,strlen(s)) && __stdio_outs("\n",1))?0:-1;
}







static int scanf(const char *format, ...) {
  int n;
  va_list arg_ptr;
  
 __builtin_va_start((
 arg_ptr
 ),(
 format
 ))
                          ;
  n=vfscanf(stdin,format,arg_ptr);
  
 __builtin_va_end 
        (arg_ptr);
  return n;
}





static int set_flags(FILE *stream, int flags) {
  switch (flags) {
    case 
        0
              : stream->flags = (stream->flags & ~(8)) | 16; break;
    case 
        1
              : stream->flags = (stream->flags & ~(16)) | 8; break;
    case 
        2
              : stream->flags = stream->flags & ~(16 | 8); break;
    default: return -1;
  }
  return 0;
}

static int setvbuf_unlocked(FILE *stream, char *buf, int flags, size_t size) {
  if (buf) {
    if (!(stream->flags&32)) free(stream->buf);
    stream->buf=buf;
  }
  else {
    char *tmp;
    if (!size) {
      return set_flags(stream,flags);
    }
    if (!(tmp=malloc(size))) return -1;
    if (!(stream->flags&32)) free(stream->buf);
    stream->buf=tmp;
  }
  stream->flags &= ~32;
  stream->buflen=size;
  stream->bm=stream->bs=0;
  return set_flags(stream,flags);
}

static int setvbuf(FILE *stream, char *buf, int flags, size_t size) __attribute__((alias("setvbuf_unlocked")));


static FILE __stderr = {
  .fd=2,
  .flags=16|256,
  .bs=0, .bm=0,
  .buflen=0,
  .buf=0,
  .next=0,
  .popen_kludge=0,
  .ungetbuf=0,
  .ungotten=0,

  .m=
    {{0},0,PTHREAD_MUTEX_RECURSIVE_NP,0}
                                          ,

};

static FILE *stderr=&__stderr;

static int __fflush_stderr(void) {
  return fflush(stderr);
}


static char __stdin_buf[2048];
static FILE __stdin = {
  .fd=0,
  .flags=4|8|32|128,
  .bs=0, .bm=0,
  .buflen=2048,
  .buf=__stdin_buf,
  .next=0,
  .popen_kludge=0,
  .ungetbuf=0,
  .ungotten=0,

  .m=
    {{0},0,PTHREAD_MUTEX_RECURSIVE_NP,0}
                                          ,

};

static int __stdin_is_tty() {
  static int iknow;
  if (!iknow) iknow=isatty(0)+1;
  return (iknow-1);
}

static FILE *stdin=&__stdin;

static int __fflush_stdin(void) {
  return fflush(stdin);
}


static char __stdout_buf[2048];
static FILE __stdout = {
  .fd=1,
  .flags=8|32|256|512,
  .bs=0, .bm=0,
  .buflen=2048,
  .buf=__stdout_buf,
  .next=0,
  .popen_kludge=0,
  .ungetbuf=0,
  .ungotten=0,

  .m=
    {{0},0,PTHREAD_MUTEX_RECURSIVE_NP,0}
                                          ,

};

static FILE *stdout=&__stdout;

static int __fflush_stdout(void) {
  return fflush(stdout);
}
static FILE *tmpfile_unlocked(void) {
  int fd;
  char template[20] = "/tmp/tmpfile-XXXXXX";
  if ((fd=mkstemp(template))<0)
    return 0;
  unlink(template);
  return __stdio_init_file(fd,1,
                               0x0002
                                     );
}

static FILE *tmpfile(void) __attribute__((alias("tmpfile_unlocked")));


static int ungetc_unlocked(int c, FILE *stream) {
  if (stream->ungotten || c<0 || c>255)
    return 
          (-1)
             ;



  if (stream->bm && stream->buf[stream->bm-1]==c) {
    --stream->bm;
  } else {
    stream->ungotten=1;
    stream->ungetbuf=(unsigned char)c;
  }
  stream->flags&=~(1|2);
  return c;
}

static int ungetc(int c, FILE *stream) __attribute__((alias("ungetc_unlocked")));






static int __fwrite(const void*ptr, size_t nmemb, void* cookie) {
  return write((uintptr_t)cookie,ptr,nmemb);
}

static int vfdprintf(int fd, const char *format, va_list arg_ptr)
{
  struct arg_printf ap = { (void*)(long)fd, __fwrite };
  return __v_printf(&ap,format,arg_ptr);
}






static int __fwrite(const void*ptr, size_t nmemb, void* cookie) {
  return fwrite(ptr,1,nmemb,(FILE*)cookie);
}

static int vfprintf(FILE *stream, const char *format, va_list arg_ptr)
{
  struct arg_printf ap = { stream, __fwrite };
  return __v_printf(&ap,format,arg_ptr);
}






static int vfscanf(FILE *stream, const char *format, va_list arg_ptr)
{
  struct arg_scanf farg = { (void*)stream, (int(*)(void*))fgetc, (int(*)(int,void*))ungetc };
  return __v_scanf(&farg,format,arg_ptr);
}




static int __stdio_outs(const void *s,size_t len,void* cookie) ;
static int __stdio_outs(const void *s,size_t len,void* cookie) {
  (void)cookie;
  return (write(1,s,len)==(ssize_t)len)?1:0;
}

static int vprintf(const char *format, va_list ap)
{
  struct arg_printf _ap = { 0, __stdio_outs };
  return __v_printf(&_ap,format,ap);
}







static int vscanf(const char *format, va_list arg_ptr)
{
  return vfscanf(stdin,format,arg_ptr);
}
static sigset_t *__utmp_block_signals (sigset_t *oldset);

static sigset_t *
static __utmp_block_signals (sigset_t *oldset)
{
    sigset_t blockset;



    sigfillset (&blockset);




    sigdelset (&blockset, 
                         4
                               );
    sigdelset (&blockset, 
                         5
                                );
    sigdelset (&blockset, 
                         6
                                );
    sigdelset (&blockset, 
                         6
                               );
    sigdelset (&blockset, 
                         8
                               );
    sigdelset (&blockset, 
                         11
                                );



    sigdelset (&blockset, 
                         10
                               );


    sigdelset (&blockset, 
                         7
                               );


    sigdelset (&blockset, 
                         12
                               );


    if (sigprocmask (
                    1
                             , &blockset, oldset) < 0)
 oldset = (sigset_t *)0;

    return oldset;
}




static void *__utmp_io(int fd, void *ut, ssize_t len, off_t *offset, int type);


static void *
static __utmp_io(int fd, void *ut, ssize_t len, off_t *offset, int type) {
  int e, ret;
  struct flock fl;
  off_t newoffset;

  fl.l_whence = 
               1
                       ;
  fl.l_start = 0;
  fl.l_len = len;
  fl.l_pid = 0;
  fl.l_type = type;

  if (fcntl(fd, 
               7
                       , &fl)) return 0;
  if (type == 
             1
                    ) {
      ret = write(fd, ut, len);
      e = errno;
      fsync (fd);

      newoffset = lseek (fd, 0, 
                               1
                                       );
   } else {
      newoffset = lseek (fd, 0, 
                               1
                                       );
      ret = read(fd, ut, len);
      e = errno;
  }

  fl.l_start = -(len);
  fl.l_type = 
             2
                    ;

  fcntl(fd, 
           6
                  , &fl);



  if (offset)
      *offset = newoffset;

  errno = e;
  if (ret != len)
      return (void *)0;
  return ut;
}






struct mntent
  {
    char *mnt_fsname;
    char *mnt_dir;
    char *mnt_type;
    char *mnt_opts;
    int mnt_freq;
    int mnt_passno;
  };




 FILE *setmntent (const char *file, const char *mode) ;




 struct mntent *getmntent (FILE* stream) ;
 int addmntent (FILE* stream,
        const struct mntent* mnt) ;


 int endmntent (FILE *stream) ;



 char *hasmntopt (const struct mntent *__mnt,
   const char *opt) ;











static int addmntent(FILE*filep,const struct mntent*mnt) {
  struct mntent m=*mnt;
  char buf[2048];
  if (strlen(m.mnt_opts)==0) m.mnt_opts="rw";
  if (snprintf(buf,sizeof(buf),"%s %s %s %s %d %d\n",
  m.mnt_fsname,m.mnt_dir,m.mnt_type,m.mnt_opts,
  m.mnt_freq,m.mnt_passno)>=(int)sizeof(buf)) return 1;
  if (fputs(buf,filep)==
                       (-1)
                          ) return 1;
  return 0;
}



static char buf[26];

static char *asctime(const struct tm *timeptr) {
  return asctime_r(timeptr,buf);
}


static const char days[] = "Sun Mon Tue Wed Thu Fri Sat ";
static const char months[] = "Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec ";

static void num2str(char *c,int i) {
  c[0]=i/10+'0';
  c[1]=i%10+'0';
}

static char *asctime_r(const struct tm *t, char *buf) {

  *(int*)buf=*(int*)(days+(t->tm_wday<<2));
  *(int*)(buf+4)=*(int*)(months+(t->tm_mon<<2));
  num2str(buf+8,t->tm_mday);
  if (buf[8]=='0') buf[8]=' ';
  buf[10]=' ';
  num2str(buf+11,t->tm_hour);

  buf[13]=':';
  num2str(buf+14,t->tm_min);
  buf[16]=':';
  num2str(buf+17,t->tm_sec);
  buf[19]=' ';
  num2str(buf+20,(t->tm_year+1900)/100);
  num2str(buf+22,(t->tm_year+1900)%100);
  buf[24]='\n';
  buf[25]='\0';
  return buf;
}





static int asprintf(char **s, const char *format,...)
{
  int n;
  va_list arg_ptr;
  char tmp[8];
  
 __builtin_va_start((
 arg_ptr
 ),(
 format
 ))
                          ;
  n=vsnprintf(tmp,0,format,arg_ptr);
  
 __builtin_va_start((
 arg_ptr
 ),(
 format
 ))
                           ;
  if ((*s=malloc(n+1))) {
    n=vsnprintf(*s,n+1,format,arg_ptr);
    return n;
  }
  return -1;
}


static char *ctime(const time_t *timep) {
  return asctime(localtime(timep));
}


static char *ctime_r(const time_t *timep, char* buf) {
  return asctime_r(localtime(timep),buf);
}


static double difftime(time_t time1, time_t time2) {
    return (double)time1 - (double)time2;
}

asm (".section .gnu.warning." "difftime" "\n\t.string \"" "warning: difftime introduces an unnecessary floating point dependency. Don't use it!" "\"\n\t.previous");





static int dirfd(DIR* dirp) {
  return dirp->fd;
}



static int endmntent(FILE *filep) {
  fclose(filep);
  return 1;
}









static void openlog (const char *ident, int option, int facility);

static void closelog (void) ;

static int setlogmask (int mask) ;

static void syslog (int priority, const char *format, ...) ;

static void vsyslog (int priority, const char *format, va_list arg_ptr) ;


typedef struct _code {
  const char *const c_name;
  int c_val;
} CODE;

 CODE prioritynames[];
 CODE facilitynames[];








static CODE facilitynames[] =
  {
    { "auth", 
             (4<<3) 
                      },
    { "authpriv", 
                 (10<<3) 
                              },
    { "cron", 
             (9<<3) 
                      },
    { "daemon", 
               (3<<3) 
                          },
    { "ftp", 
            (11<<3) 
                    },
    { "kern", 
             (0<<3) 
                      },
    { "lpr", 
            (6<<3) 
                    },
    { "mail", 
             (2<<3) 
                      },
    { "mark", 0x300 },
    { "news", 
             (7<<3) 
                      },
    { "security", 
                 (4<<3) 
                          },
    { "syslog", 
               (5<<3) 
                          },
    { "user", 
             (1<<3) 
                      },
    { "uucp", 
             (8<<3) 
                      },
    { "local0", 
               (16<<3) 
                          },
    { "local1", 
               (17<<3) 
                          },
    { "local2", 
               (18<<3) 
                          },
    { "local3", 
               (19<<3) 
                          },
    { "local4", 
               (20<<3) 
                          },
    { "local5", 
               (21<<3) 
                          },
    { "local6", 
               (22<<3) 
                          },
    { "local7", 
               (23<<3) 
                          },
    { 0, -1 }
  };



static void freeaddrinfo(struct addrinfo *res) {
  while (res) {
    struct addrinfo *duh;
    duh=res;
    res=res->ai_next;
    free(duh);
  }
}









struct timeb {
  time_t time;
  unsigned short millitm;
  short timezone;
  short dstflag;
};

static int ftime(struct timeb *tp);





static int ftime(struct timeb *tp) {
  struct timeval tv;
  struct timezone tz;
  int ret=gettimeofday(&tv,&tz);
  tp->time = tv.tv_sec;
  tp->millitm = tv.tv_usec/1000;
  tp->timezone = tz.tz_minuteswest;
  tp->dstflag = tz.tz_dsttime;
  return ret;
}



static const char* gai_strerror(int error) {
  switch (error) {
  case 
      -1
                : return "family not supported";
  case 
      -2
                  : return "socket type not supported";
  case 
      -4
                : return "unknown host";
  case 
      -5
                 : return "unknown service";
  case 
      -8
                : return "memory allocation failure";
  case 
      -10
               : return "temporary failure";
  }
  return "DNS error. Sorry.";
}













struct servent {
  char *s_name;
  char **s_aliases;
  int s_port;
  char *s_proto;
};

 void endservent (void) ;
 void setservent(int stayopen) ;

 int getservent_r(struct servent *res, char *buf, size_t buflen,
    struct servent **res_sig) ;
 int getservbyname_r(const char* name,const char* proto,
      struct servent *res, char *buf, size_t buflen,
      struct servent **res_sig) ;
 int getservbyport_r(int port,const char* proto,
      struct servent *res, char *buf, size_t buflen,
      struct servent **res_sig) ;

 struct servent *getservent(void) ;
 struct servent *getservbyname (const char *__name,
          const char *__proto) ;
 struct servent *getservbyport (int __port, const char *__proto)
     ;

struct hostent {
  char *h_name;
  char **h_aliases;
  int h_addrtype;
  socklen_t h_length;
  char **h_addr_list;

};

 void endhostent (void) ;
 struct hostent *gethostent (void) ;
 struct hostent *gethostent_r (char* buf,int len) ;
 struct hostent *gethostbyaddr (const void *__addr, socklen_t __len,
          int __type) ;
 struct hostent *gethostbyname (const char *__name) ;
 struct hostent *gethostbyname2 (const char *__name, int __af) ;



 int gethostbyname_r(const char* NAME, struct hostent* RESULT_BUF,char* BUF,
      size_t BUFLEN, struct hostent** RESULT,
      int* H_ERRNOP) ;







 int gethostbyaddr_r(const char* addr, size_t length, int format,
      struct hostent* result, char *buf, size_t buflen,
      struct hostent **RESULT, int *h_errnop) ;

static int gethostbyname2_r(const char* name, int AF, struct hostent* result,
      char *buf, size_t buflen,
      struct hostent **RESULT, int *h_errnop) ;

struct protoent {
  char *p_name;
  char **p_aliases;
  int p_proto;
};

struct protoent *getprotoent(void) ;
struct protoent *getprotobyname(const char *name) ;
struct protoent *getprotobynumber(int proto) ;
static void setprotoent(int stayopen) ;
static void endprotoent(void) ;

static int getprotoent_r(struct protoent *res, char *buf, size_t buflen,
    struct protoent **res_sig) ;
static int getprotobyname_r(const char* name,
       struct protoent *res, char *buf, size_t buflen,
       struct protoent **res_sig) ;
static int getprotobynumber_r(int proto,
        struct protoent *res, char *buf, size_t buflen,
        struct protoent **res_sig) ;


static void sethostent(int stayopen) ;


 int h_errno;

struct netent {
  char *n_name;
  char **n_aliases;
  int n_addrtype;
  unsigned long int n_net;
};

struct netent *getnetbyaddr(unsigned long net, int type) ;
static void endnetent(void) ;
static void setnetent(int stayopen) ;
struct netent *getnetbyname(const char *name) ;
struct netent *getnetent(void) ;

 const char *hstrerror (int err_num) ;
static void herror(const char *s) ;















static int inet_aton(const char* cp, struct in_addr* inp) ;
static unsigned long int inet_addr(const char* cp) ;
static unsigned long int inet_network(const char* cp) ;
static char* inet_ntoa(struct in_addr in) ;
static char* inet_ntoa_r(struct in_addr in,char* buf) ;
struct in_addr inet_makeaddr(int net, int host) ;
static unsigned long int inet_lnaof(struct in_addr in) ;
static unsigned long int inet_netof(struct in_addr in) ;

static int inet_pton (int AF, const char* CP, void* BUF) ;
static const char* inet_ntop (int AF, const void* CP, char* BUF, size_t LEN) ;





 
      int __dns_plugplay_interface;




static int getaddrinfo(const char *node, const char *service, const struct addrinfo *hints, struct addrinfo **res) {
  struct addrinfo **tmp;
  int family;
  int error=
           -4
                     ;
  int flags=0;
  tmp=res; *res=0;
  if (hints) {
    if (hints->ai_family && hints->ai_family != 
                                               10 
                                                        && hints->ai_family != 
                                                                               2
                                                                                      ) return 
                                                                                               -1
                                                                                                         ;
    if (hints->ai_socktype && hints->ai_socktype != 
                                                   2 
                                                               && hints->ai_socktype != 
                                                                                        1
                                                                                                  ) return 
                                                                                                           -2
                                                                                                                       ;
    flags=hints->ai_flags;
    if ((flags&
              32
                         ) && hints->ai_family!=
                                                10
                                                        ) flags&=~(
                                                                   32
                                                                              |
                                                                               64
                                                                                     );
  }
  for (family=
             10
                     ; ; family=
                                2
                                       ) {
    if (!hints || hints->ai_family==family || hints->ai_family==
                                                               0 
                                                                         || (flags&(
                                                                                    32
                                                                                               |
                                                                                                64
                                                                                                      ))) {
      struct hostent h;
      struct hostent *H;
      int herrno=0;
      char buf[4096];
      int lookupok=0, i;
      char* interface;
      h.h_addr_list=(char**)buf+16;
      h.h_addr_list[1]=0;
      if (node) {
 if ((interface=strchr(node,'%'))) ++interface;
 if (family==
            10 
                     && inet_pton(
                                  2
                                         ,node,buf)) continue;
 if (inet_pton(family,node,buf)>0) {
   h.h_name=(char*)node;
   h.h_addr_list[0]=buf;
   lookupok=1;
 } else if (!(flags&
                   1
                                 ) &&
     !gethostbyname2_r(node,family,&h,buf,4096,&H,&herrno)) {
   lookupok=1;
 } else {
   if (herrno==
              2
                       ) { freeaddrinfo(*res); return 
                                                      -10
                                                               ; }
 }
      } else {
 h.h_name=0;
 h.h_addr_list[0]=buf;
 interface=0;
 memset(buf,0,16);
 if (!(flags&
            4
                      )) {
   if (family==
              2
                     ) {
     buf[0]=127; buf[3]=1;
   } else
     buf[15]=1;
 }
 lookupok=1;
      }
      if (lookupok) {

 for (i=0; h.h_addr_list[i]; ++i) {
   struct ai_v6 {
     struct addrinfo ai;
     union {
       struct sockaddr_in6 ip6;
       struct sockaddr_in ip4;
     } ip;
     char name[1];
   } *foo;
   unsigned short port;
   int len;

   len=sizeof(struct ai_v6)+(h.h_name?strlen(h.h_name):0);

   if (!(foo=malloc(len))) goto error;
   foo->ai.ai_next=0;
   foo->ai.ai_addrlen=family==
                             10
                                     ?sizeof(struct sockaddr_in6):sizeof(struct sockaddr_in);
   foo->ai.ai_addr=(struct sockaddr*)&foo->ip;
   memset(&foo->ip,0,sizeof(foo->ip));
   foo->ip.ip6.sin6_family=foo->ai.ai_family=family;
   if (family==
              10
                      ) {
     memmove(&foo->ip.ip6.sin6_addr,h.h_addr_list[i],16);
     if (interface) foo->ip.ip6.sin6_scope_id=if_nametoindex(interface);
   } else {

     if (flags&
              32
                         ) {
       foo->ai.ai_addrlen=sizeof(struct sockaddr_in6);
       foo->ip.ip6.sin6_addr.
                            in6_u.u6_addr8
                                   [10]=foo->ip.ip6.sin6_addr.
                                                              in6_u.u6_addr8
                                                                     [11]=0xff;
       memmove(foo->ip.ip6.sin6_addr.
                                    in6_u.u6_addr8
                                           +12,h.h_addr_list[i],4);
       foo->ip.ip6.sin6_family=foo->ai.ai_family=
                                                10
                                                        ;
     } else
       memmove(&foo->ip.ip4.sin_addr,h.h_addr_list[i],4);
   }

   if (family==
              10 
                       && node) {
     int l=strlen(node);
     if ((l>6 && !strcmp(node+l-6,".local")) || !strchr(node,'.'))
       foo->ip.ip6.sin6_scope_id=__dns_plugplay_interface;
   }

   if (h.h_name) {
     foo->ai.ai_canonname=foo->name;
     memmove(foo->name,h.h_name,strlen(h.h_name)+1);
   } else
     foo->ai.ai_canonname=0;

   for (foo->ai.ai_socktype=
                           2
                                      ; ; foo->ai.ai_socktype=
                                                              1
                                                                        ) {
     char* type,* x;
     if (foo->ai.ai_socktype==
                             2
                                        ) {
       if (hints && hints->ai_socktype==
                                       1
                                                 ) continue;
       foo->ai.ai_protocol=
                          IPPROTO_TCP
                                     ;
       type="tcp";
     } else {
       if (hints && hints->ai_socktype==
                                       2
                                                  ) break;
       foo->ai.ai_protocol=
                          IPPROTO_UDP
                                     ;
       type="udp";
     }
     port=htons(strtol(service?service:"0",&x,0));
     if (*x) {
       struct servent* se;
       if (!(flags&
                  8
                                ) &&
    (se=getservbyname(service,type)))
  port=se->s_port;
       else {

  error=
       -5
                  ;
  if (foo->ai.ai_socktype==
                          1
                                    ) break;
  continue;
       }
     }
     if (foo->ai.ai_family==
                           10
                                   )
       foo->ip.ip6.sin6_port=port;
     else
       foo->ip.ip4.sin_port=port;
     if (!*tmp) *tmp=&(foo->ai); else (*tmp)->ai_next=&(foo->ai);
     if (!(foo=malloc(len))) goto error;
     memmove(foo,*tmp,len);
     tmp=&(*tmp)->ai_next;
     foo->ai.ai_addr=(struct sockaddr*)&foo->ip;
     if (foo->ai.ai_canonname)
       foo->ai.ai_canonname=foo->name;
     if (foo->ai.ai_socktype==
                             1
                                       ) break;
   }
   free(foo);
 }
      }
    }
    if (hints && hints->ai_family==
                                  10 
                                           && (flags&
                                                     32
                                                                ) && *res==0)
      flags|=
            64
                  ;
    if (family==
               2
                      ) break;
  }
  if (*res==0) return error;
  return 0;
error:
  freeaddrinfo(*res);
  return 
        -8
                  ;
}
static char* hostmap;
static unsigned int hostlen;

static char *cur;


struct hostent* gethostent_r(char* buf, int len) {
  char *dest;
  struct hostent* pe=(struct hostent*)buf;
  char* last;
  char* max=buf+len;
  int aliasidx;
  if (!hostmap) {
    int hostfd=open(
                   "/etc/hosts"
                              ,
                               0x0000
                                       );
    if (hostfd<0) return 0;
    hostlen=lseek(hostfd,0,
                          2
                                  );
    hostmap=mmap(0,hostlen,
                          0x1
                                   |
                                    0x2
                                              ,
                                               0x02
                                                          ,hostfd,0);
    if ((long)hostmap==(-1)) { close(hostfd); hostmap=0; goto error; }
    close(hostfd);
    cur=hostmap;
  }
  last=hostmap+hostlen;
again:
  if ((size_t)len<sizeof(struct hostent)+11*sizeof(char*)) goto nospace;
  dest=buf+sizeof(struct hostent);
  pe->h_name=0;
  pe->h_aliases=(char**)dest; pe->h_aliases[0]=0; dest+=10*sizeof(char*);
  pe->h_addr_list=(char**)dest; dest+=2*sizeof(char**);
  if (cur>=last) return 0;
  if (*cur=='#' || *cur=='\n') goto parseerror;

  pe->h_name=cur;
  while (cur<last && !isspace(*cur)) cur++;
  if (cur>=last) return 0;
  if (*cur=='\n') goto parseerror;
  {
    char save=*cur;
    *cur=0;
    pe->h_addr_list[0]=dest;
    pe->h_addr_list[1]=0;
    if (max-dest<16) goto nospace;
    if (inet_pton(
                 10
                         ,pe->h_name,dest)>0) {
      pe->h_addrtype=
                    10
                            ;
      pe->h_length=16;
      dest+=16;
    } else if (inet_pton(
                        2
                               ,pe->h_name,dest)>0) {
      pe->h_addrtype=
                    2
                           ;
      pe->h_length=4;
      dest+=4;
    } else {
      *cur=save;
      goto parseerror;
    }
    *cur=save;
  }
  ++cur;

  for (aliasidx=0;aliasidx<9;++aliasidx) {
    while (cur<last && isblank(*cur)) ++cur;
    pe->h_aliases[aliasidx]=cur;
    while (cur<last && !isspace(*cur)) ++cur;
    {
      char *from=pe->h_aliases[aliasidx];
      int l=cur-from;
      if (max-dest<l+2) goto nospace;
      pe->h_aliases[aliasidx]=dest;
      memmove(dest,from,(size_t)(cur-from));
      dest+=l;
      *dest=0; ++dest;
    }
    if (*cur=='\n') { ++cur; ++aliasidx; break; }
    if (cur>=last || !isblank(*cur)) break;
    cur++;
  }
  pe->h_aliases[aliasidx]=0;
  pe->h_name=pe->h_aliases[0];
  pe->h_aliases++;
  return pe;
parseerror:
  while (cur<last && *cur!='\n') cur++;
  cur++;
  goto again;
nospace:
  errno=
       34
             ;
  goto __error;
error:
  errno=
       12
             ;
__error:
  if (hostmap!=(char*)-1) munmap(hostmap,hostlen);
  hostmap=(char*)-1;
  return 0;
}

static void sethostent(int stayopen) {
  (void)stayopen;
  cur=hostmap;
}

static void endhostent(void) {
  if (hostmap!=(char*)-1) munmap(hostmap,hostlen);
  hostmap=0;
}



static char hostentbuf[1024];

struct hostent* gethostent() {
  return gethostent_r(hostentbuf,sizeof(hostentbuf));
}





struct mntent *getmntent(FILE *filep) {
  static struct mntent m;
  static char buf[1024];
  do {
    char *tmp=buf;
    int num;
    if (!fgets(buf,1024,filep)) return 0;

    for (num=0; num<6; ++num) {
      switch (num) {
      case 0: m.mnt_fsname=tmp; break;
      case 1: m.mnt_dir=tmp; break;
      case 2: m.mnt_type=tmp; break;
      case 3: m.mnt_opts=tmp; break;
      case 4: m.mnt_freq=strtol(tmp,&tmp,0); if (*tmp!=' ' && *tmp!='\t') continue; break;
      case 5: m.mnt_passno=strtol(tmp,&tmp,0); if (*tmp=='\n') return &m; break;
      }
      while (*tmp && *tmp!=' ' && *tmp!='\n' && *tmp!='\t') ++tmp;
      if (*tmp) {
 if (num<4) *tmp++=0;
 while (*tmp==' ' || *tmp=='\t') ++tmp;
      } else
 continue;
    }
  } while (1);
}







static int getnameinfo(const struct sockaddr *sa, socklen_t salen, char *host,
  size_t hostlen, char *serv, size_t servlen, int flags) {
  sa_family_t f=((struct sockaddr_storage *)sa)->ss_family;
  (void)salen;
  if (host && hostlen>0) {
    register const char*addr=(f==
                                10
                                        )?(char*)&((struct sockaddr_in6*)sa)->sin6_addr:
        (char*)&((struct sockaddr_in*)sa)->sin_addr;
    if (flags&
             2
                           ) {
      if (!inet_ntop(f,addr,host,hostlen))
 return 
       -4
                 ;
    } else {
      char buf[4096];
      struct hostent h;
      struct hostent *H;
      int herrno;
      if (gethostbyaddr_r(addr,f==
                                 10
                                         ?16:4,f,&h,buf,4096,&H,&herrno)) {
 switch (herrno) {
 case 
     2
              : return 
                       -10
                                ;
 case 
     5
            :
 case 
     1
                   : return 
                            -4
                                      ;
 }
      }
      strncpy(host,h.h_name,hostlen-1);
      host[hostlen-1]=0;
    }
  }
  if (serv && servlen>0) {
    register short int port=(f==
                               10
                                       )?((struct sockaddr_in6*)sa)->sin6_port:((struct sockaddr_in*)sa)->sin_port;
    if (flags&
             8
                           ) {
      __ltostr(serv,servlen,ntohs(port),10,0);
    } else {
      struct servent *s;
      if (!(s=getservbyport(port,flags&
                                      16
                                              ?"udp":"tcp")))
 return 
       -5
                  ;
      strncpy(serv,s->s_name,servlen-1);
      serv[servlen-1]=0;
    }
  }
  return 0;
}



 struct protoent __protoent_pw;
 char __protoent_buf[1000];

struct protoent *getprotobyname(const char *name) {
  struct protoent* tmp;
  if (getprotobyname_r(name,&__protoent_pw,__protoent_buf,sizeof(__protoent_buf),&tmp)==0)
    return tmp;
  return 0;
}



 int getprotobyname_r(const char* name,
       struct protoent *res, char *buf, size_t buflen,
       struct protoent **res_sig) {
  while (!getprotoent_r(res,buf,buflen,res_sig)) {
    int i;
    if (!strcmp(res->p_name,name)) goto found;
    for (i=0; res->p_aliases[i]; ++i)
      if (!strcmp(res->p_aliases[i],name)) goto found;
  }
  *res_sig=0;
found:
  endprotoent();
  return *res_sig?0:-1;
}



 struct protoent __protoent_pw;
 char __protoent_buf[1000];

struct protoent *getprotobynumber(int proto) {
  struct protoent* tmp;
  if (getprotobynumber_r(proto,&__protoent_pw,__protoent_buf,sizeof(__protoent_buf),&tmp)==0)
    return tmp;
  return 0;
}


 struct protoent __protoent_pw;
 char __protoent_buf[1000];

struct protoent *getprotoent(void) {
  struct protoent* tmp;
  getprotoent_r(&__protoent_pw,__protoent_buf,sizeof(__protoent_buf),&tmp);
  return tmp;
}



 int getprotobynumber_r(int proto,
      struct protoent *res, char *buf, size_t buflen,
      struct protoent **res_sig) {
  while (!getprotoent_r(res,buf,buflen,res_sig))
    if (proto==res->p_proto) goto found;
  *res_sig=0;
found:
  endprotoent();
  return *res_sig?0:-1;
}










struct state {
  const char* buffirst;
  size_t buflen;
  size_t cur;
};


static void __prepare_parse(const char* filename,struct state* s);

static void __fprepare_parse(int fd, struct state* s);

static void __end_parse(struct state* s);



static size_t __parse(struct state* s,int (*pred)(int ch));

static size_t __parse_ws(struct state* s);
static size_t __parse_nws(struct state* s);
static size_t __parse_1(struct state* s,char c) __attribute__((__pure__));

static size_t scan_ulong(const char* s,unsigned long* l);

static struct state __ps;

static void setprotoent(int stayopen) {
  (void)stayopen;
  __prepare_parse(
                 "/etc/protocols"
                                ,&__ps);
}

static void endprotoent(void) {
  __end_parse(&__ps);
}




static int getprotoent_r(struct protoent *res, char *buf, size_t buflen,
    struct protoent **res_sig) {
  size_t i,j,n,g;
  unsigned long l;
  if (!__ps.buffirst) setprotoent(0);
  if (!__ps.buffirst) goto error;
  if (__ps.cur>=__ps.buflen) goto error;
  res->p_aliases=(char**)buf;

again:
  n=16*sizeof(char*); g=0;
  for (i=0; i<3; ++i) {
    char found;
    __ps.cur+=__parse_ws(&__ps);
    if (__ps.cur>=__ps.buflen) { if (i==2) break; else goto error; }
    j=__parse_nws(&__ps);
    if (!isblank(found=__ps.buffirst[__ps.cur+j])) {
      if (i==2) break;
parseerror:
      while (__ps.cur+j<__ps.buflen) {
 if (__ps.buffirst[__ps.cur+j]=='\n') {
   __ps.cur+=j+1;
   goto again;
 }
 ++j;
      }
    }
    switch (i) {
    case 0:
      res->p_name=buf+n;
copy:
      if ((size_t)buflen<=n+j) goto error;
      memcpy(buf+n,__ps.buffirst+__ps.cur,j);
      buf[n+j]=0;
      n+=j+1;
      if ((found=='\n' || found=='#') && i==1) i=3;
      break;
    case 1:
      if (scan_ulong(__ps.buffirst+__ps.cur,&l)!=j) goto parseerror;
      res->p_proto=l;
      break;
    case 2:
      res->p_aliases[g]=buf+n;
      ++g;
      if (g==(16 -1)) break;
      --i;
      goto copy;
    }
    __ps.cur+=j+1;
  }
  res->p_aliases[g]=0;
  *res_sig=res;
  return 0;
error:
  *res_sig=0;
  return -1;
}



 struct servent __servent_pw;
 char __servent_buf[1000];

struct servent *getservbyname(const char *name, const char *proto) {
  struct servent* tmp;
  if (getservbyname_r(name,proto,&__servent_pw,__servent_buf,sizeof(__servent_buf),&tmp)==0)
    return tmp;
  return 0;
}



 int getservbyname_r(const char* name,const char* proto,
      struct servent *res, char *buf, size_t buflen,
      struct servent **res_sig) {
  while (!getservent_r(res,buf,buflen,res_sig)) {
    int i;
    if (proto && strcmp(res->s_proto,proto)) continue;
    if (!strcmp(res->s_name,name)) goto found;
    for (i=0; res->s_aliases[i]; ++i)
      if (!strcmp(res->s_aliases[i],name)) goto found;
  }
  *res_sig=0;
found:
  endservent();
  return *res_sig?0:-1;
}



 struct servent __servent_pw;
 char __servent_buf[1000];

struct servent *getservbyport(int port, const char *proto) {
  struct servent* tmp;
  if (getservbyport_r(port,proto,&__servent_pw,__servent_buf,sizeof(__servent_buf),&tmp)==0)
    return tmp;
  return 0;
}



 int getservbyport_r(int port,const char* proto,
      struct servent *res, char *buf, size_t buflen,
      struct servent **res_sig) {
  while (!getservent_r(res,buf,buflen,res_sig))
    if (port==res->s_port && !strcmp(res->s_proto,proto)) goto ok;
  *res_sig=0;
ok:
  endservent();
  return *res_sig?0:-1;
}


 struct servent __servent_pw;
 char __servent_buf[1000];

struct servent *getservent(void) {
  struct servent* tmp;
  getservent_r(&__servent_pw,__servent_buf,sizeof(__servent_buf),&tmp);
  return tmp;
}











struct state {
  const char* buffirst;
  size_t buflen;
  size_t cur;
};


static void __prepare_parse(const char* filename,struct state* s);

static void __fprepare_parse(int fd, struct state* s);

static void __end_parse(struct state* s);



static size_t __parse(struct state* s,int (*pred)(int ch));

static size_t __parse_ws(struct state* s);
static size_t __parse_nws(struct state* s);
static size_t __parse_1(struct state* s,char c) __attribute__((__pure__));

static size_t scan_ulong(const char* s,unsigned long* l);

static struct state __ps;

static void setservent(int stayopen) {
  (void)stayopen;
  __prepare_parse(
                 "/etc/services"
                               ,&__ps);
}

static void endservent(void) {
  __end_parse(&__ps);
}




static int getservent_r(struct servent *res, char *buf, size_t buflen,
   struct servent **res_sig) {
  size_t i,j,n,g;
  unsigned long l;
  if (!__ps.buffirst) setservent(0);
  if (!__ps.buffirst) goto error;
  if (__ps.cur>=__ps.buflen) goto error;
  res->s_aliases=(char**)buf;

again:
  n=16*sizeof(char*); g=0;
  for (i=0; i<3; ++i) {
    char found;
    __ps.cur+=__parse_ws(&__ps);
    if (__ps.cur>=__ps.buflen) { if (i==2) break; else goto error; }
    j=__parse_nws(&__ps);
    if (i==2 && j==0) break;
    if (!isblank(found=__ps.buffirst[__ps.cur+j])) {
      if (found=='#' || (i>1 && found!='\n')) {
parseerror:
 while (__ps.cur+j<__ps.buflen) {
   if (__ps.buffirst[__ps.cur+j]=='\n') {
     __ps.cur+=j+1;
     goto again;
   }
   ++j;
 }
 goto error;
      }
    }
    switch (i) {
    case 0:
      res->s_name=buf+n;
copy:
      if (!j) goto parseerror;
      if ((size_t)buflen<=n+j) goto error;
      memcpy(buf+n,__ps.buffirst+__ps.cur,j);
      buf[n+j]=0;
      n+=j+1;
      if ((found=='\n' || found=='#') && i==1) i=3;
      break;
    case 1:
      {
 int k;
 k=scan_ulong(__ps.buffirst+__ps.cur,&l);
 if (__ps.buffirst[__ps.cur+k]!='/') {
   goto parseerror;
 }
 res->s_port=htons(l);
 res->s_proto=buf+n;
 j-=k+1; __ps.cur+=k+1;
 goto copy;
      }
    case 2:
      res->s_aliases[g]=buf+n;
      ++g;
      if (g==(16 -1)) break;
      --i;
      goto copy;
    }
    __ps.cur+=j+1;
  }
  res->s_aliases[g]=0;
  *res_sig=res;
  return 0;
error:
  *res_sig=0;
  return -1;
}


struct tm* gmtime(const time_t *t) {
  static struct tm tmp;
  return gmtime_r(t,&tmp);
}





 short __spm[];

struct tm *gmtime_r(const time_t *timep, struct tm *r) {
  time_t i;
  register time_t work=*timep%(24*60*60);
  r->tm_sec=work%60; work/=60;
  r->tm_min=work%60; r->tm_hour=work/60;
  work=*timep/(24*60*60);
  r->tm_wday=(4+work)%7;
  for (i=1970; ; ++i) {
    register time_t k=__isleap(i)?366:365;
    if (work>=k)
      work-=k;
    else
      break;
  }
  r->tm_year=i-1900;
  r->tm_yday=work;

  r->tm_mday=1;
  if (__isleap(i) && (work>58)) {
    if (work==59) r->tm_mday=2;
    work-=1;
  }

  for (i=11; i && (__spm[i]>work); --i) ;
  r->tm_mon=i;
  r->tm_mday+=work-__spm[i];
  return r;
}






static int grantpt (int fd) {
  struct stat st;
  if ((fstat(fd, &st))<0) return -1;
  if ((chmod((char*)ptsname(fd), st.st_mode | 
                                             00400 
                                                     | 
                                                       00200 
                                                               | 
                                                                 00020
                                                                        ))<0)
    return -1;
  return 0;
}



static char *hasmntopt(const struct mntent *mnt, const char *opt) {
  char *s=mnt->mnt_opts;
  char *c;
  int len=strlen(opt);
  if (!s) return 0;
  for (c=s;;) {
    if (!(c=strstr(c,opt))) break;
    if (c==s || c[-1]==',') {
      if (c[len]==0 || c[len]==',' || c[len]=='=')
 return c;
    }
    c+=len+1;
  }
  return 0;
}


enum charset {
  INVALID=0,
  ISO_8859_1,
  UTF_8,
  UCS_2,
  UCS_4,
  UTF_16_BE,
  UTF_16_LE,
  UTF_16
};














typedef uint32_t iconv_t;



 iconv_t iconv_open (const char *tocode, const char *fromcode) ;




 size_t iconv (iconv_t cd, char** inbuf,
       size_t* inbytesleft,
       char** outbuf,
       size_t* outbytesleft) ;


 int iconv_close (iconv_t cd) ;





static unsigned int utf8bounds[]={0x7f,0x7ff,0xffff,0x1fffff,0x3ffffff,0x7fffffff};

static size_t iconv(iconv_t cd, char* * inbuf, size_t *
      inbytesleft, char* * outbuf, size_t * outbytesleft) {
  size_t result=0,i,j,k;
  int bits;
  unsigned char* in,* out;
  enum charset from=(((cd) )&0xffff);
  enum charset to=(((cd)>>16)&0xffff);
  if (!inbuf || !*inbuf) return 0;
  in=(unsigned char*)(*inbuf);
  out=(unsigned char*)(*outbuf);
  while (*inbytesleft) {
    unsigned int v;
    v=*in;
    i=j=1;
    switch (from) {
    case UCS_2:
      if (*inbytesleft<2) {
starve:
 errno=
      22
            ;
 return (size_t)-1;
      }
      v=(((unsigned long)in[0])<<8) |
        ((unsigned long)in[1]);
      i=2;
      break;
    case UCS_4:
      if (*inbytesleft<4) goto starve;
      v=(((unsigned long)in[0])<<24) |
        (((unsigned long)in[1])<<16) |
        (((unsigned long)in[2])<<8) |
        ((unsigned long)in[3]);
      i=4;
    case ISO_8859_1:
      break;
    case UTF_8:
      if (!(v&0x80)) break;
      if (v>=0xfe) goto ABEND;
      for (i=0xC0; i!=0xFC; i=(i>>1)+0x80)
 if ((v&((i>>1)|0x80))==i) {
   v&=~i;
   break;
 }
      for (i=1; (in[i]&0xc0)==0x80; ++i) {
 if (i>*inbytesleft) goto starve;
 v=(v<<6)|(in[i]&0x3f);
      }

      if (i>6 || (i>1 && v<utf8bounds[i-1])) goto ABEND;

      break;
    case UTF_16:
      if (*inbytesleft<2) goto starve;
      if (v==0xff && in[1]==0xfe) {
 from=UTF_16_LE; *inbytesleft-=2; in+=2; goto utf16le;
      } else if (v==0xfe && in[1]==0xff) {
 from=UTF_16_BE; *inbytesleft-=2; in+=2; goto utf16be;
      }
ABEND:
      errno=
           88
                 ;
      return (size_t)-1;
    case UTF_16_BE:
utf16be:
      if (*inbytesleft<2) goto starve;
      v=((unsigned long)in[0]<<8) | in[1];
joined:
      i=2;
      if (v>=0xd800 && v<=0xdfff) {
 long w;
 if (v>0xdbff) goto ABEND;
 if (*inbytesleft<4) goto starve;
 if (from==UTF_16_BE)
   w=((unsigned long)in[2]<<8) | in[3];
 else
   w=((unsigned long)in[3]<<8) | in[2];
 if (w<0xdc00 || w>0xdfff) goto ABEND;
 v=0x10000+(((v-0xd800) << 10) | (w-0xdc00));
 i=4;
      }
      break;
    case UTF_16_LE:
utf16le:
      v=((unsigned long)in[1]<<8) | in[0];
      goto joined;
    }
    if (v>=0xd800 && v<=0xd8ff) goto ABEND;
    switch (to) {
    case ISO_8859_1:
      if (*outbytesleft<1) goto bloat;
      if (v>0xff) ++result;
      *out=(unsigned char)v;
      break;
    case UCS_2:
      if (*outbytesleft<2) goto bloat;
      if (v>0xffff) ++result;
      out[0]=v>>8;
      out[1]=v&0xff;
      j=2;
      break;
    case UCS_4:
      if (*outbytesleft<4) goto bloat;
      out[0]=(v>>23)&0xff;
      out[1]=(v>>16)&0xff;
      out[2]=(v>>8)&0xff;
      out[3]=v&0xff;
      j=4;
      break;
    case UTF_8:
      if (v>=0x04000000) { bits=30; *out=0xFC; j=6; } else
      if (v>=0x00200000) { bits=24; *out=0xF8; j=5; } else
      if (v>=0x00010000) { bits=18; *out=0xF0; j=4; } else
      if (v>=0x00000800) { bits=12; *out=0xE0; j=3; } else
      if (v>=0x00000080) { bits=6; *out=0xC0; j=2; } else
   { bits=0; *out=0; }
      *out|= (unsigned char)(v>>bits);
      if (*outbytesleft<j) {
bloat:
 errno=
      7
           ;
 return (size_t)-1;
      }
      for (k=1; k<j; ++k) {
 bits-=6;
 out[k]=0x80+((v>>bits)&0x3F);
      }
      break;
    case UTF_16:
      if (*outbytesleft<4) goto bloat;
      to=UTF_16_LE;
      out[0]=0xff;
      out[1]=0xfe;
      out+=2; *outbytesleft-=2;

    case UTF_16_LE:
      if (v>0xffff) {
 long a,b;
 if (*outbytesleft<(j=4)) goto bloat;
 v-=0x10000;
 if (v>0xfffff) result++;
 a=0xd800+(v>>10); b=0xdc00+(v&0x3ff);
 out[1]=a>>8;
 out[0]=a&0xff;
 out[3]=b>>8;
 out[2]=b&0xff;
      } else {
 if (*outbytesleft<(j=2)) goto bloat;
 out[1]=(v>>8)&0xff;
 out[0]=v&0xff;
      }
      break;
    case UTF_16_BE:
      if (v>0xffff) {
 long a,b;
 if (*outbytesleft<(j=4)) goto bloat;
 v-=0x10000;
 if (v>0xfffff) result++;
 a=0xd800+(v>>10); b=0xdc00+(v&0x3ff);
 out[0]=a>>8;
 out[1]=a&0xff;
 out[2]=b>>8;
 out[3]=b&0xff;
      } else {
 if (*outbytesleft<(j=2)) goto bloat;
 out[0]=(v>>8)&0xff;
 out[1]=v&0xff;
      }
      break;
    }
    in+=i; *inbytesleft-=i;
    out+=j; *outbytesleft-=j;
  }
  *inbuf=(char*)in; *outbuf=(char*)out;
  return result;
}





enum charset {
  INVALID=0,
  ISO_8859_1,
  UTF_8,
  UCS_2,
  UCS_4,
  UTF_16_BE,
  UTF_16_LE,
  UTF_16
};

static enum charset parsecharset(const char* s) {
  if (!strcasecmp(s,"UTF-8")) return UTF_8; else
  if (!strcasecmp(s,"UCS-2") || !strcasecmp(s,"UCS2")) return UCS_2; else
  if (!strcasecmp(s,"UCS-4") || !strcasecmp(s,"UCS4")) return UCS_4; else
  if (!strcasecmp(s,"ISO-8859-1") || !strcasecmp(s,"LATIN1")) return ISO_8859_1; else
  if (!strcasecmp(s,"US-ASCII")) return ISO_8859_1; else
  if (!strcasecmp(s,"UTF-16")) return UTF_16; else
  if (!strcasecmp(s,"UTF-16BE")) return UTF_16_BE; else
  if (!strcasecmp(s,"UTF-16LE")) return UTF_16_LE; else
  return INVALID;
}

static iconv_t iconv_open(const char* tocode, const char* fromcode) {
  int f,t;

  f=parsecharset(fromcode);
  t=parsecharset(tocode);

  if (f==INVALID || t==INVALID) {
    errno=
         22
               ;
    return (iconv_t)(-1);
  }
  return (f|t<<16);
}

enum charset {
  INVALID=0,
  ISO_8859_1,
  UTF_8,
  UCS_2,
  UCS_4,
  UTF_16_BE,
  UTF_16_LE,
  UTF_16
};

static int iconv_close(iconv_t cd) {
  (void)cd;
  return 0;
}


static int __isleap(int year) {



  return (!(year%4) && ((year%100) || !(year%400)));
}



static int iswctype(wint_t wc, wctype_t desc) {
  return desc(wc);
}


struct tm* localtime(const time_t* t) {
  static struct tm tmp;
  return localtime_r(t,&tmp);
}





 void __maplocaltime(void);
 time_t __tzfile_map(time_t t, int *isdst, int forward);





struct tm* localtime_r(const time_t* t, struct tm* r) {
  time_t tmp;

  __maplocaltime();
  tmp=__tzfile_map(*t,&r->tm_isdst,1);






  return gmtime_r(&tmp,r);
}
static int __libc_open(const char*name,int flags, ...);
static ssize_t __libc_write(int fd,void*buf,size_t len);
static int __libc_fcntl(int fd,int op,...);
static int __libc_close(int fd);


static volatile int connected;
static volatile int LogMask = 0xff;
static char LogTag[1000];
static int LogFile = -1;
static int LogType = 
                     1
                               ;
static int LogFacility = 
                         (1<<3)
                                 ;
static int LogStat;
 char *__progname;
static struct sockaddr SyslogAddr;

static void closelog_intern(void)
{
  if (!connected) return;
  __libc_close(LogFile);
  LogFile = -1;
  connected = 0;
}

static void __libc_closelog(void);
static void __libc_closelog(void)
{
  closelog_intern();

  LogTag[0]=0;
  LogType = 
           1
                     ;
}
static void closelog(void) __attribute__((alias("__libc_closelog")));

static void openlog_intern(int option, int facility)
{
  LogStat = option;
  if (facility && ((facility & ~
                               0x03f8
                                          ) == 0))
    LogFacility = facility;


  while(1) {
    if (LogFile == -1) {
      SyslogAddr.sa_family = 
                            1
                                   ;
      strncpy(SyslogAddr.sa_data, 
                                 "/dev/log"
                                          , sizeof(SyslogAddr.sa_data));
      if (LogStat & 
                   0x08
                             )
      {
 if ((LogFile = socket(
                      1
                             , LogType, 0)) == -1) return;
 __libc_fcntl(LogFile, 
                      2
                             , 1);
      }
    }
    if ((LogFile != -1) && !connected) {
      int old_errno=errno;
      if(connect(LogFile, &SyslogAddr, sizeof(SyslogAddr)) == -1) {
 int saved_errno=errno;
 __libc_close(LogFile);
 LogFile = -1;
 if((LogType == 
               1
                         ) && (saved_errno == 
                                              98
                                                        )) {

   LogType = 
            2
                       ;
   errno=old_errno;
   continue;
 }
      }
      else connected = 1;
    }
    break;
  }
}


static void __libc_openlog(const char *ident, int option, int facility);
static void __libc_openlog(const char *ident, int option, int facility)
{
  if (ident) {
    strncpy(LogTag,ident,1000);
    LogTag[1000 -1]=0;
  }
  openlog_intern(option, facility);
}
static void openlog(const char *ident, int option, int facility) __attribute__((alias("__libc_openlog")));

static int setlogmask(int mask)
{
  int old = LogMask;
  if (mask) LogMask = mask;
  return old;
}

static void __libc_vsyslog(int priority, const char *format, va_list arg_ptr);
static void __libc_vsyslog(int priority, const char *format, va_list arg_ptr)
{
  char buffer[2048];
  char time_buf[20];
  int buflen, headerlen;
  time_t now;
  struct tm now_tm;
  pid_t pid;
  int fd;
  int sigpipe;
  struct sigaction action, oldaction;
  int saved_errno = errno;


  if (priority & ~(
                  0x07
                             |
                              0x03f8
                                         )) {
    syslog(
          3
                 |
                  0x02
                          |
                           0x20
                                     |
                                      0x01
                                             , "syslog: unknown facility/priorityority: %x", priority);
    priority &= 
               0x07
                          |
                           0x03f8
                                      ;
  }


  if ((
      (1 << (((
      priority
      ) & 0x07))) 
                                  && LogMask) == 0) return;


  if ((priority & 
                 0x03f8
                            ) == 0) priority |= LogFacility;

  pid = getpid();
  time(&now);
  strftime(time_buf, 20, "%h %e %T", localtime_r (&now, &now_tm));

  if (LogStat & 
               0x01
                      )
    headerlen = snprintf(buffer, 130, "<%d>%s %s[%ld]: ", priority, time_buf, LogTag, (long) pid);
  else
    headerlen = snprintf(buffer, 130, "<%d>%s %s: ", priority, time_buf, LogTag);

  if (!LogTag[0]) {
    if ((LogStat & 
                  0x01
                         ) != 
                              0x01
                                     )
      headerlen = snprintf(buffer, 130, "<%d>%s (unknown)[%ld]: ", priority, time_buf, (long) pid);
    strcat(buffer+headerlen, "syslog without openlog w/ ident, please check code!");
    buflen = 41;
  }
  else {
    errno=saved_errno;
    buflen = vsnprintf(buffer+headerlen, 2048 - headerlen, format, arg_ptr);
  }
  if (LogStat & 
               0x20
                         ) {
    __libc_write(1, buffer+headerlen, buflen);
    if (buffer[headerlen+buflen] != '\n') __libc_write(1,"\n", 1);
  }


  memset(&action, 0, sizeof(action));
  action.
        _u._sa_handler 
                   = 
                     ((sighandler_t)1L)
                            ;
  sigemptyset(&action.sa_mask);

  sigpipe = sigaction (
                      13
                             , &action, &oldaction);

  if (!connected) openlog_intern(LogStat | 
                                          0x08
                                                    , 0);



  if (LogType == 
                2
                           ) buflen++;

  if (!connected || (send(LogFile, buffer, buflen+headerlen, 0) != buflen+headerlen)) {
    if (LogType == 
                  2
                             ) buflen--;
    closelog_intern();





    if ((LogStat & 
                  0x02
                          ) &&
       ((fd = __libc_open("/dev/console", 
                                        0x0001
                                                |
                                                 0x0800
                                                         , 0)) >= 0))
    {
      __libc_write(fd, buffer, buflen+headerlen);
      __libc_write(fd, "\r\n", 2);
      __libc_close(fd);
    }
  }

  if (sigpipe == 0)
    sigaction(
             13
                    , &oldaction, (struct sigaction *) 
                                                       (void*)0
                                                           );
}
static void vsyslog(int priority, const char *format, va_list arg_ptr) __attribute__((alias("__libc_vsyslog")));

static void syslog(int priority, const char *format, ...)
{
  va_list arg_ptr;
  
 __builtin_va_start((
 arg_ptr
 ),(
 format
 ))
                          ;
  vsyslog(priority, format, arg_ptr);
  
 __builtin_va_end
       (arg_ptr);
}
 void __maplocaltime(void);
 time_t __tzfile_map(time_t t, int *isdst, int forward);





static time_t mktime(register struct tm* const t) {
  time_t x=timegm(t);

  int isdst;
  time_t y;
  __maplocaltime();
  x=__tzfile_map(x,&isdst,0);






  return x;
}

static time_t timelocal(struct tm* const t) __attribute__((alias("mktime")));
static int netfd=-1;
static char* netmap;
static unsigned int netlen;

static char* aliases[10];

static char *cur;


struct netent *getnetent(void) {
  static struct netent ne;
  char *last;
  int aliasidx;
  if (netfd<0) {
    netfd=open(
              "/etc/networks"
                            ,
                             0x0000
                                     );
    if (netfd<0) return 0;
    fcntl (netfd, 
                 2
                        , 
                          1
                                    );
    netlen=lseek(netfd,0,
                        2
                                );
    netmap=mmap(0,netlen,
                        0x1
                                 |
                                  0x2
                                            ,
                                             0x02
                                                        ,netfd,0);
    if ((long)netmap==(-1)) goto error;
    cur=netmap;
  }
  last=netmap+netlen;
again:
  ne.n_name=0;
  ne.n_aliases=aliases; aliases[0]=0;
  ne.n_addrtype=
               2
                      ;
  ne.n_net=0;
  if (cur>=last) return 0;
  if (*cur=='#' || *cur=='\n') goto parseerror;

  if (!isalpha(*cur)) goto parseerror;
  ne.n_name=cur;
  ne.n_aliases=aliases;
  while (cur<last && isalnum(*cur)) cur++;
  if (cur>=last) return 0;
  if (*cur=='\n') goto parseerror;
  *cur=0; cur++;

  while (cur<last && isblank(*cur)) cur++;
  {
    const char *tmp=cur;
    char save;
    while (cur<last && (isdigit(*cur) || *cur=='.')) ++cur;
    save=*cur; *cur=0;
    if (inet_aton(tmp,(struct in_addr*)&ne.n_net)==0) goto parseerror;
    *cur=save;
  }
  if (cur>=last) return 0;

  for (aliasidx=0;aliasidx<10;++aliasidx) {
    while (cur<last && isblank(*cur)) ++cur;
    aliases[aliasidx]=cur;
    while (cur<last && isalpha(*cur)) ++cur;
    if (*cur=='\n') { *cur++=0; ++aliasidx; break; }
    if (cur>=last || !isblank(*cur)) break;
    *cur++=0;
  }
  aliases[aliasidx]=0;
  return &ne;
parseerror:
  while (cur<last && *cur!='\n') cur++;
  cur++;
  goto again;
error:
  if (netmap!=(char*)-1) munmap(netmap,netlen);
  if (netfd!=-1) close(netfd);
  netmap=(char*)-1;
  netfd=-1;
  errno=
       12
             ;
  return 0;
}

struct netent *getnetbyaddr(unsigned long net, int type) {
  struct netent *s;
  for (s=getnetent(); s; s=getnetent()) {
    if (net==s->n_net && type==s->n_addrtype)
      return s;
  }
  return 0;
}

static void endnetent(void) {
  if (netmap!=(char*)-1) munmap(netmap,netlen);
  if (netfd!=-1) close(netfd);
  netmap=(char*)-1;
  netfd=-1;
}

static void setnetent(int stayopen) {
  (void)stayopen;
  endnetent();
}

struct netent *getnetbyname(const char *name) {
  struct netent *s;
  setnetent(0);
  for (s=getnetent(); s; s=getnetent()) {
    char **tmp;
    if (!strcmp(name,s->n_name))
      return s;
    tmp=s->n_aliases;
    while (*tmp)
      if (!strcmp(name,*tmp++)) return s;
  }
  return 0;
}













 
      int openpty (int *__amaster, int *__aslave, char *__name, struct
      termios *__termp, struct winsize *__winp) ;










static int openpty(int *amaster, int *aslave, char *name, struct termios
     *termp, struct winsize *winp) {
  int fd;
  char buf[20];
  if ((fd=open("/dev/ptmx",
                          0x0002
                                ))<0) return -1;



  {
    int unlock=0;
    while (ioctl(fd,
                   (((4U) << (((0 +8)+8)+13)) | ((('T')) << (0 +8)) | (((0x31)) << 0) | (((sizeof(int)) & 0xff) << ((0 +8)+8)))
                             , &unlock)<0) if (errno!=
                                                      4
                                                           ) goto kaputt;
  }
  {
    int ptyno;
    while (ioctl(fd,
                   (((2U) << (((0 +8)+8)+13)) | ((('T')) << (0 +8)) | (((0x30)) << 0) | (((sizeof(unsigned int)) & 0xff) << ((0 +8)+8)))
                           ,&ptyno)<0) if (errno!=
                                                  4
                                                       ) goto kaputt;
    strcpy(buf,"/dev/pts/");
    __ltostr(buf+9,10,ptyno,10,0);
  }
  *aslave=open(buf,
                  0x0002
                        |
                         0x0800
                                 );
  if (*aslave<0) goto kaputt;
  *amaster=fd;
  if (name) strcpy(name,buf);
  if (termp)
    while (tcsetattr(*aslave,
                            0x5410
                                     ,termp) && errno==
                                                       4
                                                            );
  if (winp) while (ioctl(*aslave, 
                                 (((4U) << (((0 +8)+8)+13)) | ((('t')) << (0 +8)) | (((103)) << 0) | (((sizeof(struct winsize)) & 0xff) << ((0 +8)+8)))
                                           , winp) && errno==
                                                             4
                                                                  );
  return 0;
kaputt:
  close(fd);
  return -1;
}




static int pclose(FILE *f) {
  int status;
  pid_t pid=f->popen_kludge;
  fclose(f);
  if (waitpid(pid,&status,0)>=0)
    return status;
  return -1;
}




 const char __binsh [8];

 char **environ;

static FILE *popen(const char *command, const char *type) {
  int pfd[2];
  int fd0;
  FILE* f;
  pid_t pid;

  if (pipe(pfd)<0) return 0;
  fd0=(*type=='r');
  if ((!(f=fdopen(pfd[!fd0],type))) ||
      ((pid=fork())<0)) {
    close(pfd[0]);
    close(pfd[1]);
    return 0;
  }
  if (!pid) {
    const char *argv[]={(__binsh + 5 ),"-c",0,0};
    close(pfd[!fd0]); close(fd0);
    dup2(pfd[fd0],fd0); close(pfd[fd0]);
    argv[2]=command;
    execve(__binsh,(char*const*)argv,environ);
    _exit(127);
  }
  close(pfd[fd0]);
  fcntl (pfd[!fd0], 
                   2
                          , 
                            1
                                      );
  f->popen_kludge=pid;
  return f;
}






static CODE prioritynames[] =
  {
    { "alert", 
              1 
                        },
    { "crit", 
             2 
                      },
    { "debug", 
              7 
                        },
    { "emerg", 
              0 
                        },
    { "err", 
            3 
                    },
    { "error", 
              3 
                      },
    { "info", 
             6 
                      },
    { "none", 0x10 },
    { "notice", 
               5 
                          },
    { "panic", 
              0 
                        },
    { "warn", 
             4 
                         },
    { "warning", 
                4 
                            },
    { 0, -1 }
  };


struct protoent __protoent_pw;
static char __protoent_buf[1000];
static char *ptsname(int fd) {
  static char buffer[9+4];
  int pty;

  strcpy(buffer,"/dev/pts/");
  if ((ioctl(fd, 
                (((2U) << (((0 +8)+8)+13)) | ((('T')) << (0 +8)) | (((0x30)) << 0) | (((sizeof(unsigned int)) & 0xff) << ((0 +8)+8)))
                        , &pty)) == -1) return 0;
  __ltostr(buffer+9, 4, pty, 10, 0);
  return buffer;
}












struct passwd {
  char *pw_name;
  char *pw_passwd;
  uid_t pw_uid;
  gid_t pw_gid;
  char *pw_gecos;
  char *pw_dir;
  char *pw_shell;
};

 struct passwd *getpwuid (uid_t uid) ;
 struct passwd *getpwnam (const char *name) ;

 struct passwd *getpwent(void) ;
 void setpwent(void) ;
 void endpwent(void) ;
 int putpwent(const struct passwd *p, FILE *stream)  ;

static int getpwent_r(struct passwd *res, char *buf, size_t buflen,
        struct passwd **res_sig) ;
static int getpwnam_r(const char* name,
        struct passwd *res, char *buf, size_t buflen,
        struct passwd **res_sig) ;
static int getpwuid_r(uid_t uid,
        struct passwd *res, char *buf, size_t buflen,
        struct passwd **res_sig) ;


 struct passwd *fgetpwent(FILE * fp);
 void fsetpwent(int fd) ;
 int fgetpwent_r(int fd,struct passwd *res,
  char *buf, size_t buflen,
         struct passwd **res_sig);







static int putpwent(const struct passwd *p, FILE *stream) {
  if (p && stream) {
    fprintf(stream,"%s:%s:%d:%d:%s:%s:%s\n", p->pw_name, p->pw_passwd,
     p->pw_uid, p->pw_gid, p->pw_gecos, p->pw_dir, p->pw_shell);
    return 0;
  }
  (*__errno_location())=
                       22
                             ;
  return -1;
}

static asm (".section .gnu.warning." "putpwent" "\n\t.string \"" "putpwent is garbage, don't use!" "\"\n\t.previous");


struct servent __servent_pw;
static char __servent_buf[1000];




static asm (".section .gnu.warning." "setenv" "\n\t.string \"" "setenv calls malloc.  Avoid it in small programs." "\"\n\t.previous");;

static int setenv(const char *name, const char *value, int overwrite) {
  if (getenv(name)) {
    if (!overwrite) return 0;
    unsetenv(name);
  }
  {
    char *c=malloc(strlen(name)+strlen(value)+2);
    strcpy(c,name);
    strcat(c,"=");
    strcat(c,value);
    return putenv(c);
  }
}



static FILE *setmntent(const char *filename, const char *type) {
  return fopen(filename,type);
}







static char *strndup(const char *s,size_t n) {





  char *tmp=(char *)malloc(n+1);

  if (!tmp) return 0;
  strncpy(tmp,s,n);
  tmp[n]=0;
  return tmp;
}




static const char sweekdays [7] [4] = {
    "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
};
static const char weekdays [7] [10] = {
    "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
};
static const char smonths [12] [4] = {
    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};
static const char* months [12] = {
    "January", "February", "March", "April", smonths[5-1], "June",
    "July", "August", "September", "October", "November", "December"
};
static const char ampm [4] [3] = {
    "am", "pm",
    "AM", "PM"
};

static void i2a ( char* dest,unsigned long x )
{
    int div = 10;
    *dest++ = x/div + '0';
    *dest++ = x%div + '0';
    *dest++ = '\0';
}

static size_t strftime ( char* dst, size_t max, const char* format, const struct tm* tm )
{
    char* p = dst;
    const char* src;
    unsigned long no;
    char buf [5];

    if (!max) return 0;
    for ( ; *format != '\0'; format++ ) {
 if (*format == '%') {
     if (*++format == '%') {
         *p++ = '%';
     }
     else
again:
     switch (*format) {

     case 'n': *p++ = '\n'; break;
     case 't': *p++ = '\t'; break;
     case 'O': case 'E': ++format; goto again;
     case 'c': src = "%b %a %d %k:%M:%S %Z %Y"; goto _strf;
     case 'r': src = "%I:%M:%S %p"; goto _strf;
     case 'R': src = "%H:%M"; goto _strf;
     case 'x': src = "%b %a %d"; goto _strf;
     case 'X': src = "%k:%M:%S"; goto _strf;
     case 'D': src = "%m/%d/%y"; goto _strf;
     case 'F': src = "%Y-%m-%d"; goto _strf;
     case 'T': src = "%H:%M:%S";
        _strf: p += strftime (p, (size_t)(dst+max-p), src, tm); break;
     case 'a': src = sweekdays [tm->tm_wday]; goto _str;
     case 'A': src = weekdays [tm->tm_wday]; goto _str;
     case 'h':
     case 'b': src = smonths [tm->tm_mon]; goto _str;
     case 'B': src = months [tm->tm_mon]; goto _str;
     case 'p': src = ampm [tm->tm_hour > 12 ? 3 : 2]; goto _str;
     case 'P': src = ampm [tm->tm_hour > 12 ? 1 : 0]; goto _str;
     case 'C': no = tm->tm_year/100 + 19; goto _no;
     case 'd': no = tm->tm_mday; goto _no;
     case 'e': no = tm->tm_mday; goto _nos;
     case 'H': no = tm->tm_hour; goto _no;
     case 'I': no = tm->tm_hour % 12; goto _no;
     case 'j': no = tm->tm_yday; goto _no;
     case 'k': no = tm->tm_hour; goto _nos;
     case 'l': no = tm->tm_hour % 12; goto _nos;
     case 'm': no = tm->tm_mon + 1; goto _no;
     case 'M': no = tm->tm_min; goto _no;
     case 'S': no = tm->tm_sec; goto _no;
     case 'u': no = tm->tm_wday ? tm->tm_wday : 7; goto _no;
     case 'w': no = tm->tm_wday; goto _no;
     case 'U': no = (tm->tm_yday - tm->tm_wday + 7) / 7; goto _no;
     case 'W': no = (tm->tm_yday - (tm->tm_wday - 1 + 7) % 7 + 7) / 7; goto _no;
     case 's': {
   time_t t = mktime((struct tm*)tm);
   char sbuf[101];
   char* c;
   sbuf[100]=0;
   for (c=sbuf+99; c>sbuf; --c) {
     *c=(t%10)+'0';
     t/=10;
     if (!t) break;
   }
   src=c;
   goto _str;
        }
     case 'Z':

        tzset(); src = tzname[0];



        goto _str;
     case 'Y': i2a ( buf+0, (unsigned int)(tm->tm_year / 100 + 19) );
        i2a ( buf+2, (unsigned int)(tm->tm_year % 100) );
        src = buf;
        goto _str;
     case 'y': no = tm->tm_year % 100; goto _no;
   _no: i2a ( buf, no );
        src = buf;
        goto _str;
  _nos: i2a ( buf, no );
        if (buf[0] == '0')
     buf[0] = ' ';
        src = buf;
  _str: while (*src && p < dst+max)
     *p++ = *src++;
        break;
     };
 } else {
     *p++ = *format;
 }

 if (p >= dst+max)
     break;
    }

    if ((size_t)(p-dst)>=max) {
      if (max) p[-1]=0;
    } else
      *p = '\0';
    return p - dst;
}







 const short __spm [];

static const char* months [12] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

static int getint(const char** s,int max) {
  int i,j;
  for (i=j=0; j<max; ++j) {
    if (!isdigit(**s)) {
      if (j==0) return -1; else break;
    }
    i=i*10+**s-'0';
    ++*s;
  }
  return i;
}

static char* strptime(const char* s,const char* format, struct tm* tm) {
  int i,j;
  register time_t day;
  while (*format) {
    switch (*format) {
    case ' ': case '\t':

      while (isblank(*s)) ++s;
      ++format;
      break;
    case '%':
      ++format;
      switch (*format) {
      case '%': if (*s=='%') ++s; else return 0; break;
      case 'a': case 'A':
 for (i=0; i<3; ++i)
   if (isalpha(*s)) ++s;
 break;
      case 'b': case 'B': case 'h':
 for (i=0; i<12; ++i) {
   if (strncasecmp(s,months[i],j=strlen(months[i])))
     if (strncasecmp(s,months[i],j=3))
       j=0;
   if (j) break;
 }
 if (!j) return 0;
 s+=j;
 tm->tm_mon=i;
 break;
      case 'c':
 s=strptime(s,"%b %a %d %k:%M:%S %Z %Y",tm);
 break;
      case 'C':
 i=getint(&s,2);
 if (i==-1) return 0;
 tm->tm_year=(tm->tm_year%100)+(i*100);
 break;
      case 'd': case 'e':
 i=getint(&s,2);
 if (i==-1 || i>31) return 0;
 tm->tm_mday=i;
 break;
      case 'D':
 s=strptime(s,"%m/%d/%y",tm);
 break;
      case 'H': case 'k':
 i=getint(&s,2);
 if (i==-1 || i>23) return 0;
 tm->tm_hour=i;
 break;
      case 'I': case 'l':
 i=getint(&s,2);
 if (i==-1 || i>12) return 0;
 tm->tm_hour=(tm->tm_hour/12)*12+i;
 break;
      case 'j':
 getint(&s,3);
 break;
      case 'm':
 i=getint(&s,2);
 if (i<=0 || i>12) return 0;
 tm->tm_mon=i-1;
 break;
      case 'M':
 i=getint(&s,2);
 if (i==-1 || i>59) return 0;
 tm->tm_min=i;
 break;
      case 'n': case 't':
 while (isblank(*s)) ++s;
 break;
      case 'p': case 'P':
 if (*s=='p' || *s=='P') tm->tm_hour=(tm->tm_hour%12)+12;
 s+=2;
 break;
      case 'r':
 s=strptime(s,"%I:%M:%S %p",tm);
 break;
      case 'R':
 s=strptime(s,"%H:%M",tm);
 break;
      case 'S':
 i=getint(&s,2);
 if (i==-1 || i>60) return 0;
 tm->tm_sec=i;
 break;
      case 'T':
 s=strptime(s,"%H:%M:%S",tm);
 break;
      case 'U': case 'W':
 if (getint(&s,2)==-1) return 0;
 break;
      case 'w':
 if (*s<'0' || *s>'6') return 0;
 ++s;
 break;
      case 'x':
 s=strptime(s,"%m/%d/%y",tm);
 break;
      case 'X':
 s=strptime(s,"%H:%M:%S",tm);
 break;
      case 'y':
 i=getint(&s,2);
 if (i<0) return 0;
 tm->tm_year=(i<69)?i+100:i;
 break;
      case 'Y':
 i=getint(&s,4);
 if (i==-1) return 0;
 tm->tm_year=i-1900;
 break;
      case 'Z':


 while (*s!=' ' && *s!='\t') ++s;
 break;
      }
      ++format;
      break;
    default:
      if (*s != *format) return 0;
      ++format; ++s;
      break;
    }
  }

  day = (tm->tm_year - 70) * 365 + (tm->tm_year - 69) / 4;
  day += tm->tm_yday = __spm [tm->tm_mon] + tm->tm_mday-1 + (__isleap (tm->tm_year+1900) & (tm->tm_mon > 1));
  tm->tm_wday = (day + 4) % 7;

  return (char*)s;
}




static char* strsignal(int sig) {
  if ((unsigned int)sig<=
                        (128 -1)
                                )
    return (char*)sys_siglist[sig];
  else
    return (char*)"(unknown signal)";
}






 const char __binsh [8];

 char **environ;

static int __libc_system (const char *line);

static int __libc_system (const char *line)
{
  struct sigaction sa, intr, quit;
  sigset_t block,omask;
  int save,pid,ret=-1;

  if (line == 0) return __libc_system("exit 0") == 0;

  sa.
    _u._sa_handler 
               = 
                 ((sighandler_t)1L)
                        ;
  sa.sa_flags = 0;
  sigemptyset (&sa.sa_mask);

  if (sigaction(
               2
                     , &sa, &intr)<0) return -1;
  if (sigaction(
               3
                      , &sa, &quit)<0) {
    save = errno;
undo:
    sigaction (
              2
                    , &intr, (struct sigaction*)0);
    errno=save;
    return -1;
  }
  sigemptyset(&block);
  sigaddset(&block,
                  18
                         );
  if (sigprocmask(
                 1
                          ,&block,&omask)<0) {
    save=errno;
    sigaction (
              3
                     , &quit, (struct sigaction*)0);
    goto undo;
  }

  pid=fork();
  if (pid>0)
  {
    int n;
    do
      n=waitpid(pid, &ret, 0);
    while ((n==-1) && (errno==
                             4
                                  ));
    if (n!=pid) ret=-1;
  }
  else if (!pid)
  {
    const char *nargs[4];
    nargs[0] = (__binsh + 5 );
    nargs[1] = "-c";
    nargs[2] = line;
    nargs[3] = 0;

    sigaction(
             2
                   , &intr, (struct sigaction*)0);
    sigaction(
             3
                    , &quit, (struct sigaction*)0);
    sigprocmask(
               3
                          ,&omask,0);

    execve(__binsh,(char *const *)nargs, environ);
    _exit(127);
  }
  save = errno;
  sigaction (
            2
                  , &intr, (struct sigaction *)0);
  sigaction (
            3
                   , &quit, (struct sigaction *)0);
  sigprocmask(
             3
                        ,&omask,0);
  errno=save;
  return ret;
}

static int system (const char *line) __attribute__((alias("__libc_system")));

asm (".section .gnu.warning." "system" "\n\t.string \"" "warning: system() is a security risk.  Use fork and execvp instead!" "\"\n\t.previous");



static const short __spm[13] =
  { 0,
    (31),
    (31+28),
    (31+28+31),
    (31+28+31+30),
    (31+28+31+30+31),
    (31+28+31+30+31+30),
    (31+28+31+30+31+30+31),
    (31+28+31+30+31+30+31+31),
    (31+28+31+30+31+30+31+31+30),
    (31+28+31+30+31+30+31+31+30+31),
    (31+28+31+30+31+30+31+31+30+31+30),
    (31+28+31+30+31+30+31+31+30+31+30+31),
  };






 const short __spm [];

static time_t timegm(struct tm *const t) {
  register time_t day;
  register time_t i;
  register time_t years = t->tm_year - 70;

  if (t->tm_sec>60) { t->tm_min += t->tm_sec/60; t->tm_sec%=60; }
  if (t->tm_min>60) { t->tm_hour += t->tm_min/60; t->tm_min%=60; }
  if (t->tm_hour>60) { t->tm_mday += t->tm_hour/60; t->tm_hour%=60; }
  if (t->tm_mon>12) { t->tm_year += t->tm_mon/12; t->tm_mon%=12; }
  if (t->tm_mon<0) t->tm_mon=0;
  while (t->tm_mday>__spm[1+t->tm_mon]) {
    if (t->tm_mon==1 && __isleap(t->tm_year+1900)) {
      if (t->tm_mon==31+29) break;
      --t->tm_mday;
    }
    t->tm_mday-=__spm[t->tm_mon];
    ++t->tm_mon;
    if (t->tm_mon>11) { t->tm_mon=0; ++t->tm_year; }
  }

  if (t->tm_year < 70)
    return (time_t) -1;


  day = years * 365 + (years + 1) / 4;





  if ((years -= 131) >= 0) {
    years /= 100;
    day -= (years >> 2) * 3 + 1;
    if ((years &= 3) == 3) years--;
    day -= years;
  }

  day += t->tm_yday = __spm [t->tm_mon] + t->tm_mday-1 + ( __isleap (t->tm_year+1900) & (t->tm_mon > 1) );


  i = 7;
  t->tm_wday = (day + 4) % i;

  i = 24;
  day *= i;
  i = 60;
  return ((day + t->tm_hour) * i + t->tm_min) * i + t->tm_sec;
}


static long int timezone;
static int daylight;
static char* tzname[2]={"GMT","GMT"};


static unsigned char *tzfile;
static int tzlen=-1;

static void __maplocaltime(void);
static void __maplocaltime(void) {
  int fd;
  unsigned int len;
  if (tzlen>=0) return;
  tzlen=0;
  if ((fd=open("/etc/localtime",
                               0x0000
                                       ))<0) return;
  len=lseek(fd,0,
                2
                        );
  if ((tzfile=mmap(0,len,
                        0x1
                                 ,
                                  0x02
                                             ,fd,0))==
                                                      ((void *) -1)
                                                                ) {
    close(fd);
    return;
  }
  close(fd);
  if (len<44 || ntohl(*(int*)tzfile) != 0x545a6966) {
    munmap(tzfile,len);
    tzfile=0;
    return;
  }
  tzlen=len;
}

static int32_t __myntohl(const unsigned char* c) {
  return (((uint32_t)c[0])<<24) +
         (((uint32_t)c[1])<<16) +
         (((uint32_t)c[2])<<8) +
         ((uint32_t)c[3]);
}

static time_t __tzfile_map(time_t t, int *isdst, int forward);
static time_t __tzfile_map(time_t t, int *isdst, int forward) {

  unsigned char *tmp;
  int i;
  int tzh_timecnt, tzh_typecnt;
  *isdst=0;
  if (!tzfile) return t;
  tzh_timecnt=ntohl(*(int*)(tzfile+32));
  tzh_typecnt=ntohl(*(int*)(tzfile+36));
  tmp=tzfile+20+6*4;
  daylight=(tzh_timecnt>0);
  if (forward) {
    for (i=0; i<tzh_timecnt; ++i) {
      if ((time_t)__myntohl(tmp+i*4) >= t) {
 unsigned char* tz=tmp;

 tmp+=tzh_timecnt*4;
 i=tmp[i-1];

 tmp+=tzh_timecnt;
 tz+=tzh_timecnt*5+tzh_typecnt*6;
 tmp+=i*6;

 *isdst=tmp[4];
 tzname[0]=(char*)(tz+tmp[5]);
 timezone=__myntohl(tmp);
 return t+timezone;
      }
    }
  } else {
    time_t nexttz=0,lastval=0;

    for (i=1; i<tzh_timecnt-1; ++i) {
      unsigned char* x, j;
      long k=0;

      x=tmp+tzh_timecnt*4;
      j=x[i-1];
      nexttz=__myntohl(x+tzh_timecnt+j*6);

      if (lastval <= t && (k=(__myntohl(tmp+i*4)-nexttz)) > t) {

 return t-nexttz;
      }
      lastval=k;
    }
  }
  return t;
}

static void tzset(void) {
  int isdst;
  __maplocaltime();
  __tzfile_map(time(0),&isdst,1);
}
static int unlockpt (int fd) {
  int foo=0;

  return (ioctl (fd, 
                    (((4U) << (((0 +8)+8)+13)) | ((('T')) << (0 +8)) | (((0x31)) << 0) | (((sizeof(int)) & 0xff) << ((0 +8)+8)))
                              , &foo));
}


static int unsetenv(const char *name) {
  return putenv(name);
}













struct lastlog
  {



    time_t ll_time;

    char ll_line[32];
    char ll_host[256];
  };



struct exit_status
  {
    short int e_termination;
    short int e_exit;
  };


struct utmp
{
  short int ut_type;
  pid_t ut_pid;
  char ut_line[32];
  char ut_id[4];
  char ut_user[32];
  char ut_host[256];

  struct exit_status ut_exit;
  long int ut_session;
  struct timeval ut_tv;



  int32_t ut_addr_v6[4];
  char __unused[20];
};
struct utmp *getutent(void) ;
struct utmp *getutid(struct utmp *ut) ;
struct utmp *getutline(struct utmp *ut) ;

static void pututline(struct utmp *ut) ;

static void setutent(void) ;
static void endutent(void) ;

static void utmpname(const char *file) ;

static void updwtmp(const char *wtmp_file, const struct utmp *ut);
static void logwtmp(const char *line, const char *name, const char *host);




static const char *utmp_file_name = 
                                   "/var/run/utmp"
                                             ;
static int fd = -1;
static off_t utmp_current = 0;

static int lock_record(int type) {
  struct flock fl;
  fl.l_whence = 
               1
                       ;
  fl.l_start = 0;
  fl.l_len = sizeof(struct utmp);
  fl.l_pid = 0;
  fl.l_type = type;
  return fcntl(fd, 
                  7
                          , &fl);
}

static int unlock_record() {
  struct flock fl;
  fl.l_whence = 
               1
                       ;
  fl.l_start = -sizeof(struct utmp);
  fl.l_len = sizeof(struct utmp);
  fl.l_pid = 0;
  fl.l_type = 
             2
                    ;
  return fcntl(fd, 
                  6
                         , &fl);
}

static void utmpname(const char *file) {
  if (file)
    utmp_file_name = file;
  else
    utmp_file_name = 
                    "/var/run/utmp"
                              ;
}

static void setutent() {
  if (fd<0) fd = open(utmp_file_name,
                                    0x0002
                                          );
  if (fd<0) fd = open(utmp_file_name,
                                    0x0000
                                            );
  fcntl (fd, 
            2
                   , 
                     1
                               );
  utmp_current = lseek(fd,0,
                           0
                                   );
}

static void endutent() {
  if (fd<0) return;
  close(fd); fd=-1;
  utmp_current = 0;
}

struct utmp *getutent(void) {
  static struct utmp getutent_tmp;
  ssize_t ret;

  if (fd<0) {
    setutent();
    if (fd<0) return 0;
  }
  utmp_current = lseek (fd, 0, 
                              1
                                      );
  if (lock_record(
                 0
                        )) return 0;
  ret=read(fd, &getutent_tmp, sizeof(struct utmp));
  unlock_record();
  if (ret<1) return 0;
  return &getutent_tmp;
}

struct utmp *getutid(struct utmp *ut) {
  struct utmp *tmp;

  while ((tmp = getutent())) {
    if (ut->ut_type && (ut->ut_type <= 
                                      4
                                              )) {
      if (ut->ut_type == tmp->ut_type) break;
    }
    if ((ut->ut_type >= 
                       5
                                   ) && (ut->ut_type <= 
                                                        8
                                                                    )) {
      if (!strncmp(ut->ut_id,tmp->ut_id,4)) break;
    }
  }
  return tmp;
}

struct utmp *getutline(struct utmp *ut) {
  struct utmp *tmp;

  while ((tmp = getutent())) {
    if ((tmp->ut_type == 
                        7
                                    ) || (tmp->ut_type == 
                                                          6
                                                                       )) {
      if (!strncmp(ut->ut_line,tmp->ut_line,
                                           32
                                                      )) break;
    }
  }
  return tmp;
}

static void pututline(struct utmp *ut) {
  struct utmp *tmp;


  lseek (fd, utmp_current, 
                          0
                                  );
  if ((tmp = getutid(ut))) {
    lseek(fd, - (off_t)sizeof(struct utmp), 
                                           1
                                                   );
    if (lock_record(
                   1
                          )) return;
    write(fd, ut, sizeof(struct utmp));
    utmp_current += sizeof(struct utmp);
  }
  else {
    utmp_current = lseek(fd, 0, 
                               2
                                       );
    if (lock_record(
                   1
                          )) return;
    write(fd, ut, sizeof(struct utmp));
  }
  unlock_record();
}






struct utmp;










struct __exit_status
  {
    short int e_termination;
    short int e_exit;
  };


struct utmpx
{
  short int ut_type;
  pid_t ut_pid;
  char ut_line[32];
  char ut_id[4];
  char ut_user[32];
  char ut_host[256];
  struct __exit_status ut_exit;
  long int ut_session;
  struct timeval ut_tv;

  int32_t ut_addr_v6[4];
  char __unused[20];
};
struct utmpx *getutxent(void);
struct utmpx *getutxid(struct utmpx *ut);
struct utmpx *getutxline(struct utmpx *ut);

struct utmpx *pututxline(struct utmpx *ut);

static void setutxent(void);
static void endutxent(void);


static void utmpxname (const char *file);
static void updwtmpx (const char *wtmpx_file, const struct utmpx *utmpx);
static void getutmp (const struct utmpx *utmpx, struct utmp *utmp);
static void getutmpx (const struct utmp *utmp, struct utmpx *utmpx);






static const char *utmp_file_name = 
                                   "/var/run/utmp"
                                              ;
static int fd = -1;
static off_t utmp_current = 0;


static void *__utmp_io(int fd, void *ut, ssize_t len, off_t *offset, int type);
static sigset_t *__utmp_block_signals (sigset_t *oldset);


static void __utmpxname(const char *file);
static void __utmpxname(const char *file) {
  if (file)
    utmp_file_name = file;
  else
    utmp_file_name = 
                    "/var/run/utmp"
                               ;
}

static void setutxent() {
  sigset_t oldset, *savedset;

  savedset = __utmp_block_signals(&oldset);
  if (fd<0) fd = open(utmp_file_name,
                                    0x0002
                                          );
  if (fd<0) fd = open(utmp_file_name,
                                    0x0000
                                            );
  fcntl (fd, 
            2
                   , 
                     1
                               );
  utmp_current = lseek(fd,0,
                           0
                                   );
  if (savedset)
      sigprocmask (
                  3
                             , savedset, 0);
}

static void endutxent() {
  if (fd<0) return;
  close(fd); fd=-1;
  utmp_current = 0;
}

struct utmpx *getutxent(void) {
  static struct utmpx getutent_tmp, *retval;
  ssize_t ret;
  sigset_t oldset, *savedset;

  if (fd<0) {
    setutxent();
    if (fd<0) return 0;
  }
  savedset = __utmp_block_signals (&oldset);

  retval = __utmp_io(fd, &getutent_tmp, sizeof(struct utmpx),
       &utmp_current, 
                     0
                            );

  if (savedset)
      sigprocmask (
                  3
                             , savedset, 0);

  return retval;
}

struct utmpx *getutxid(struct utmpx *ut) {
  struct utmpx *tmp;

  while ((tmp = getutxent())) {
    if (ut->ut_type && (ut->ut_type <= 
                                      4
                                              )) {
      if (ut->ut_type == tmp->ut_type) break;
    }
    if ((ut->ut_type >= 
                       5
                                   ) && (ut->ut_type <= 
                                                        8
                                                                    )) {
      if (!strncmp(ut->ut_id,tmp->ut_id,4)) break;
    }
  }
  return tmp;
}

struct utmpx *getutxline(struct utmpx *ut) {
  struct utmpx *tmp;

  while ((tmp = getutxent())) {
    if ((tmp->ut_type == 
                        7
                                    ) || (tmp->ut_type == 
                                                          6
                                                                       )) {
      if (!strncmp(ut->ut_line,tmp->ut_line,
                                           32
                                                        )) break;
    }
  }
  return tmp;
}

struct utmpx *pututxline(struct utmpx *ut) {
  struct utmpx *tmp, ut_copy, *retval = 0, *result;
  int e;
  ssize_t bytes_written;
  sigset_t oldset, *savedset;




  memcpy (&ut_copy, ut, sizeof (struct utmpx));

  savedset = __utmp_block_signals (&oldset);


  lseek (fd, utmp_current, 
                          0
                                  );
  if ((tmp = getutxid(&ut_copy))) {
    lseek(fd, - (off_t)sizeof(struct utmpx), 
                                            1
                                                    );
    result = __utmp_io (fd, &ut_copy, sizeof(struct utmpx),
     &utmp_current, 
                   1
                          );
    e = errno;
  } else {
    utmp_current = lseek(fd, 0, 
                               2
                                       );
    result = __utmp_io (fd, &ut_copy, sizeof(struct utmpx),
     &utmp_current, 
                   1
                          );
    e = errno;
  }
  if (savedset)
      sigprocmask (
                  3
                             , savedset, 0);

  if (result) {
      retval = ut;
  }

  memcpy (ut, &ut_copy, sizeof (struct utmpx));
  errno = e;
  return retval;
}







static int vasprintf(char **s, const char *format, va_list ap)
{
  int n;
  va_list arg_ptr;
  char tmp[8];
  
 __builtin_va_copy((
 arg_ptr
 ),(
 ap
 ))
                    ;
  n=vsnprintf(tmp,0,format,arg_ptr);
  
 __builtin_va_end
       (arg_ptr);
  if ((*s=malloc(n+1))) {
    n=vsnprintf(*s,n+1,format,ap);
    return n;
  }
  return -1;
}



struct { const char* name; wctype_t func; } types[]={
  { "alnum", iswalnum },
  { "alpha", iswalpha },
  { "blank", iswblank },
  { "cntrl", iswcntrl },
  { "digit", iswdigit },
  { "graph", iswgraph },
  { "lower", iswlower },
  { "print", iswprint },
  { "punct", iswpunct },
  { "space", iswspace },
  { "upper", iswupper },
  { "xdigit", iswxdigit },
};

static wctype_t wctype(const char* name) {
  size_t i;
  for (i=0; i<sizeof(types)/sizeof(types[0]); ++i)
    if (!strcmp(name,types[i].name)) return types[i].func;
  return (wctype_t)0;
}


static int wmemcmp(const wchar_t *s1, const wchar_t *s2, size_t n) {
  size_t i;
  for (i=0; i<n; ++i) {
    wint_t x=s1[i]-s2[i];
    if (x) return x;
  }
  return 0;
}


static wchar_t *wmemcpy(wchar_t *dest, const wchar_t *src, size_t n) {
  size_t i;
  for (i=0; i<n; ++i)
    dest[i]=src[i];
  return dest;
}


static wchar_t *wmemmove(wchar_t *dest, const wchar_t *src, size_t n) {
  size_t i;
  if (src<dest && dest<src+n)
    for (i=0; i<n; ++i)
      dest[n-i-1]=src[n-i-1];
  else
    for (i=0; i<n; ++i)
      dest[i]=src[i];
  return dest;
}


static wchar_t *wmemset(wchar_t *wcs, wchar_t wc, size_t n) {
  size_t i;
  for (i=0; i<n; ++i) wcs[i]=wc;
  return wcs;
}





static void updwtmp(const char *wtmp_file, const struct utmp *ut) {
  int fd = open(wtmp_file, 
                          0x0001
                                  |
                                   0x0008
                                           );
  if (fd<0) return;
  fcntl (fd, 
            2
                   , 
                     1
                               );
  write(fd, ut, sizeof(struct utmp));
  close(fd);
}

static void logwtmp(const char *line, const char *name, const char *host) {
  struct utmp ut;

  memset(&ut, 0, sizeof(struct utmp));

  ut.ut_pid = getpid ();
  ut.ut_type = name[0] ? 
                        7 
                                     : 
                                       8
                                                   ;

  memccpy (ut.ut_line, line, 0, sizeof ut.ut_line);
  memccpy (ut.
             ut_user
                    , name, 0, sizeof ut.
                                         ut_user
                                                );
  memccpy (ut.ut_host, host, 0, sizeof ut.ut_host);

  if (sizeof(ut.ut_tv) == sizeof(struct timeval))
    gettimeofday((struct timeval *)&ut.ut_tv, 
                                             (void*)0
                                                 );
  else {
 struct timeval tv;
 gettimeofday(&tv, 
                  (void*)0
                      );
 ut.ut_tv.tv_sec = tv.tv_sec;
 ut.ut_tv.tv_usec = tv.tv_usec;
  }

  updwtmp (
          "/var/log/wtmp"
                    , &ut);
}










struct state {
  const char* buffirst;
  size_t buflen;
  size_t cur;
};


static void __prepare_parse(const char* filename,struct state* s);

static void __fprepare_parse(int fd, struct state* s);

static void __end_parse(struct state* s);



static size_t __parse(struct state* s,int (*pred)(int ch));

static size_t __parse_ws(struct state* s);
static size_t __parse_nws(struct state* s);
static size_t __parse_1(struct state* s,char c) __attribute__((__pure__));

static size_t scan_ulong(const char* s,unsigned long* l);

static void __end_parse(struct state* s) {
  munmap((void*)(s->buffirst),s->buflen);
  s->buffirst=0;
}









struct state {
  const char* buffirst;
  size_t buflen;
  size_t cur;
};


static void __prepare_parse(const char* filename,struct state* s);

static void __fprepare_parse(int fd, struct state* s);

static void __end_parse(struct state* s);



static size_t __parse(struct state* s,int (*pred)(int ch));

static size_t __parse_ws(struct state* s);
static size_t __parse_nws(struct state* s);
static size_t __parse_1(struct state* s,char c) __attribute__((__pure__));

static size_t scan_ulong(const char* s,unsigned long* l);

static void __fprepare_parse(int fd,struct state* s) {
  s->cur=0;
  if (s->buffirst) return;
  if (fd>=0) {
    s->buflen=lseek(fd,0,
                        2
                                );
    s->buffirst=mmap(0,s->buflen,
                                0x1
                                         ,
                                          0x02
                                                     ,fd,0);
    if (s->buffirst==(const char*)-1)
      s->buffirst=0;
  }
}







struct state {
  const char* buffirst;
  size_t buflen;
  size_t cur;
};


static void __prepare_parse(const char* filename,struct state* s);

static void __fprepare_parse(int fd, struct state* s);

static void __end_parse(struct state* s);



static size_t __parse(struct state* s,int (*pred)(int ch));

static size_t __parse_ws(struct state* s);
static size_t __parse_nws(struct state* s);
static size_t __parse_1(struct state* s,char c) __attribute__((__pure__));

static size_t scan_ulong(const char* s,unsigned long* l);

static size_t __parse(struct state* s,int (*pred)(int ch)) {
  size_t n;
  for (n=s->cur; n<s->buflen && s->buffirst[n]!='\n' && pred(s->buffirst[n]); ++n) ;
  return n-s->cur;
}







struct state {
  const char* buffirst;
  size_t buflen;
  size_t cur;
};


static void __prepare_parse(const char* filename,struct state* s);

static void __fprepare_parse(int fd, struct state* s);

static void __end_parse(struct state* s);



static size_t __parse(struct state* s,int (*pred)(int ch));

static size_t __parse_ws(struct state* s);
static size_t __parse_nws(struct state* s);
static size_t __parse_1(struct state* s,char c) __attribute__((__pure__));

static size_t scan_ulong(const char* s,unsigned long* l);

static size_t __parse_1(struct state* s,char c) {
  size_t n;
  for (n=s->cur; n<s->buflen && s->buffirst[n]!='\n' && s->buffirst[n]!=c; ++n) ;
  return n-s->cur;
}







struct state {
  const char* buffirst;
  size_t buflen;
  size_t cur;
};


static void __prepare_parse(const char* filename,struct state* s);

static void __fprepare_parse(int fd, struct state* s);

static void __end_parse(struct state* s);



static size_t __parse(struct state* s,int (*pred)(int ch));

static size_t __parse_ws(struct state* s);
static size_t __parse_nws(struct state* s);
static size_t __parse_1(struct state* s,char c) __attribute__((__pure__));

static size_t scan_ulong(const char* s,unsigned long* l);

static int __isnonblank(int ch) {
  return (ch!=' ' && ch!='\t' && ch!='#');
}

static size_t __parse_nws(struct state* s) {
  return __parse(s,__isnonblank);
}







struct state {
  const char* buffirst;
  size_t buflen;
  size_t cur;
};


static void __prepare_parse(const char* filename,struct state* s);

static void __fprepare_parse(int fd, struct state* s);

static void __end_parse(struct state* s);



static size_t __parse(struct state* s,int (*pred)(int ch));

static size_t __parse_ws(struct state* s);
static size_t __parse_nws(struct state* s);
static size_t __parse_1(struct state* s,char c) __attribute__((__pure__));

static size_t scan_ulong(const char* s,unsigned long* l);

static int __isblank(int ch) {
  return (ch==' ' || ch=='\t');
}

static size_t __parse_ws(struct state* s) {
  return __parse(s,__isblank);
}









struct state {
  const char* buffirst;
  size_t buflen;
  size_t cur;
};


static void __prepare_parse(const char* filename,struct state* s);

static void __fprepare_parse(int fd, struct state* s);

static void __end_parse(struct state* s);



static size_t __parse(struct state* s,int (*pred)(int ch));

static size_t __parse_ws(struct state* s);
static size_t __parse_nws(struct state* s);
static size_t __parse_1(struct state* s,char c) __attribute__((__pure__));

static size_t scan_ulong(const char* s,unsigned long* l);

static void __prepare_parse(const char* filename,struct state* s) {
  int fd;
  s->cur=0;
  if (s->buffirst) return;
  fd=open(filename,
                  0x0000
                          );
  if (fd>=0) {
    s->buflen=lseek(fd,0,
                        2
                                );
    s->buffirst=mmap(0,s->buflen,
                                0x1
                                         ,
                                          0x02
                                                     ,fd,0);
    if (s->buffirst==(const char*)-1)
      s->buffirst=0;
    close(fd);
  } else {
    s->buflen=0;
    s->buffirst=0;
  }
}



static int alphasort(const struct dirent **a, const struct dirent **b) {
  return strcmp((*a)->d_name,(*b)->d_name);
}



static int alphasort64(const struct dirent64 **a, const struct dirent64 **b) {
  return strcmp((*a)->d_name,(*b)->d_name);
}





static void bcopy(const void *src, void *dest, size_t n) {
  memmove(dest,src,n);
}

asm (".section .gnu.warning." "bcopy" "\n\t.string \"" "warning: you used bcopy without including dietlibc <string.h> w/ _BSD_SOURCE!" "\"\n\t.previous");













enum {
  LC_CTYPE = 0,

  LC_NUMERIC = 1,

  LC_TIME = 2,

  LC_COLLATE = 3,

  LC_MONETARY = 4,

  LC_MESSAGES = 5,

  LC_ALL = 6,

  LC_PAPER = 7,

  LC_NAME = 8,

  LC_ADDRESS = 9,

  LC_TELEPHONE = 10,

  LC_MEASUREMENT = 11,

  LC_IDENTIFICATION = 12

};


struct lconv {

  char *decimal_point;
  char *thousands_sep;





  char *grouping;





  char *int_curr_symbol;
  char *currency_symbol;
  char *mon_decimal_point;
  char *mon_thousands_sep;
  char *mon_grouping;
  char *positive_sign;
  char *negative_sign;
  char int_frac_digits;
  char frac_digits;

  char p_cs_precedes;

  char p_sep_by_space;

  char n_cs_precedes;

  char n_sep_by_space;






  char p_sign_posn;
  char n_sign_posn;

  char int_p_cs_precedes;

  char int_p_sep_by_space;

  char int_n_cs_precedes;

  char int_n_sep_by_space;






  char int_p_sign_posn;
  char int_n_sign_posn;
};

static char *setlocale (int category, const char *locale) ;
struct lconv *localeconv (void) ;





static char* gettext(const char* msgid) ;
static char* dgettext(const char* domainname, const char* msgid) ;
static char* dcgettext(const char *domainname, const char *msgid, int category) ;

static char* ngettext (const char* msgid, const char* msgid_plural, unsigned long int n) ;
static char* dngettext (const char* domainname, const char* msgid, const char* msgid_plural, unsigned long int n) ;
static char* dcngettext(const char* domainname,
   const char* msgid1, const char* msgid2,
   unsigned long int n, int __category) ;

static char* textdomain(const char *domainname) ;
static char* bindtextdomain(const char *domainname, const char *dirname) ;
static char* bind_textdomain_codeset(const char *domainname, const char *codeset) ;





static char* dir;

static char* bindtextdomain(const char* domainname,const char* dirname) {
  (void)domainname;
  if (dir) free(dir);
  if (!(dir=strdup(dirname))) return 0;
  return dir;
}





static void bzero(void *s, size_t n) {
  memset(s,0,n);
}

asm (".section .gnu.warning." "bzero" "\n\t.string \"" "warning: you used bzero without including dietlibc's <string.h> w/ _BSD_SOURCE!" "\"\n\t.previous");









struct tms {
 clock_t tms_utime;
 clock_t tms_stime;
 clock_t tms_cutime;
 clock_t tms_cstime;
};

static clock_t times(struct tms *buf) ;






static clock_t clock(void) {
  struct tms buf;
  times(&buf);






  return ((unsigned long) buf.tms_utime + buf.tms_stime) * (
                                                           1000000l 
                                                                          / 
                                                                            100
                                                                              );





}
static size_t confstr(int name,char*buf,size_t len) {
  switch (name) {
  case 
      1
              :
    if (buf) strncpy(buf,"/bin:/usr/bin",len);
    return sizeof("/bin:/usr/bin");
    break;
  }
  errno=
       22
             ;
  return 0;
}


static char* dcgettext(const char *domainname, const char *msgid, int category) {
  (void)domainname;
  (void)category;
  return (char*)msgid;
}



static char* dgettext(const char* domainname, const char* x) { (void)domainname; return (char*)x; }
struct dl_phdr_info
{
    Elf32_Addr dlpi_addr;
    const char *dlpi_name;
    const Elf32_Phdr *dlpi_phdr;
    Elf32_Half dlpi_phnum;
};



 Elf32_Phdr *_dl_phdr;
 size_t _dl_phnum;


static int dl_iterate_phdr(int (*callback) (struct dl_phdr_info *info, size_t size, void *data),
                    void *data);
static int dl_iterate_phdr(int (*callback) (struct dl_phdr_info *info, size_t size, void *data),
                    void *data)
{
    int ret;
    struct dl_phdr_info info;

    if (_dl_phnum != 0)
    {

        info.dlpi_addr = 0;
        info.dlpi_name = "";
        info.dlpi_phdr = _dl_phdr;
        info.dlpi_phnum = _dl_phnum;
        ret = (*callback) (&info, sizeof(info), data);
        if (ret != 0)
            return ret;
    }

    return 0;
}
 Elf32_Phdr *_dl_phdr;
 size_t _dl_phnum;

static Elf32_Phdr *_dl_phdr = 
                      (void*)0
                          ;
static size_t _dl_phnum = 0;


static void _dl_aux_init(Elf32_auxv_t *av);
static void _dl_aux_init(Elf32_auxv_t *av)
{
    for ( ; av->a_type != 
                         0
                                ; ++av)
    {
 switch (av->a_type)
 {
 case 
     3
            :
            _dl_phdr = av->a_un.a_ptr;
            break;
 case 
     5
             :
            _dl_phnum = av->a_un.a_val;
            break;
 }
    }
}


static void _dl_aux_init_from_envp(char **envp);
static void _dl_aux_init_from_envp(char **envp)
{
    if (envp == 
               (void*)0
                   )
        return;
    while (*envp)
 ++envp;

    _dl_aux_init((Elf32_auxv_t *) (envp + 1));
}











typedef enum __ns_type {
 ns_t_invalid = 0,
 ns_t_a = 1,
 ns_t_ns = 2,
 ns_t_md = 3,
 ns_t_mf = 4,
 ns_t_cname = 5,
 ns_t_soa = 6,
 ns_t_mb = 7,
 ns_t_mg = 8,
 ns_t_mr = 9,
 ns_t_null = 10,
 ns_t_wks = 11,
 ns_t_ptr = 12,
 ns_t_hinfo = 13,
 ns_t_minfo = 14,
 ns_t_mx = 15,
 ns_t_txt = 16,
 ns_t_rp = 17,
 ns_t_afsdb = 18,
 ns_t_x25 = 19,
 ns_t_isdn = 20,
 ns_t_rt = 21,
 ns_t_nsap = 22,
 ns_t_nsap_ptr = 23,
 ns_t_sig = 24,
 ns_t_key = 25,
 ns_t_px = 26,
 ns_t_gpos = 27,
 ns_t_aaaa = 28,
 ns_t_loc = 29,
 ns_t_nxt = 30,
 ns_t_eid = 31,
 ns_t_nimloc = 32,
 ns_t_srv = 33,
 ns_t_atma = 34,
 ns_t_naptr = 35,
 ns_t_kx = 36,
 ns_t_cert = 37,
 ns_t_a6 = 38,
 ns_t_dname = 39,
 ns_t_sink = 40,
 ns_t_opt = 41,
 ns_t_tsig = 250,
 ns_t_ixfr = 251,
 ns_t_axfr = 252,
 ns_t_mailb = 253,
 ns_t_maila = 254,
 ns_t_any = 255,
 ns_t_zxfr = 256,
 ns_t_max = 65536
} ns_type;




typedef enum __ns_class {
 ns_c_invalid = 0,
 ns_c_in = 1,
 ns_c_2 = 2,
 ns_c_chaos = 3,
 ns_c_hs = 4,

 ns_c_none = 254,
 ns_c_any = 255,
 ns_c_max = 65536
} ns_class;




typedef enum __ns_opcode {
 ns_o_query = 0,
 ns_o_iquery = 1,
 ns_o_status = 2,

 ns_o_notify = 4,
 ns_o_update = 5,
 ns_o_max = 6
} ns_opcode;




typedef enum __ns_rcode {
 ns_r_noerror = 0,
 ns_r_formerr = 1,
 ns_r_servfail = 2,
 ns_r_nxdomain = 3,
 ns_r_notimpl = 4,
 ns_r_refused = 5,

 ns_r_yxdomain = 6,
 ns_r_yxrrset = 7,
 ns_r_nxrrset = 8,
 ns_r_notauth = 9,
 ns_r_notzone = 10,
 ns_r_max = 11,

 ns_r_badsig = 16,
 ns_r_badkey = 17,
 ns_r_badtime = 18
} ns_rcode;

typedef struct {
        unsigned id :16;


        unsigned qr: 1;
        unsigned opcode: 4;
        unsigned aa: 1;
        unsigned tc: 1;
        unsigned rd: 1;

        unsigned ra: 1;
        unsigned unused :1;
        unsigned ad: 1;
        unsigned cd: 1;
        unsigned rcode :4;
        unsigned qdcount :16;
        unsigned ancount :16;
        unsigned nscount :16;
        unsigned arcount :16;
} HEADER;


typedef struct __res_state {
  int retrans;
  int retry;
  unsigned long options;
  int nscount;
  struct sockaddr_in_pad
   nsaddr_list[8];

  unsigned short id;
  char *dnsrch[6 +1];
  char defdname[256];
  unsigned long pfcode;
  unsigned ndots:4;
  unsigned nsort:4;
  char unused[3];
  struct {
    struct in_addr addr;
    uint32_t mask;
  } sort_list[10];
  char pad[72];
} * res_state;
struct res_sym {
 int number;
 char * name;
 char * humanname;
};

 struct __res_state _res;
 const struct res_sym __p_class_syms[];
 const struct res_sym __p_type_syms[];

static int res_init(void) ;

static int res_query(const char *dname, int _class, int type,
      unsigned char *answer, int anslen) ;

static int res_search(const char *dname, int _class, int type,
      unsigned char *answer, int anslen) ;

static int res_querydomain(const char *name, const char *domain,
      int _class, int type, unsigned char *answer,
      int anslen) ;

static int res_mkquery(int op, const char *dname, int _class,
      int type, char *data, int datalen, const unsigned char* newrr,
      char *buf, int buflen) ;

static int res_send(const char *msg, int msglen, char *answer,
      int anslen) ;

static int dn_comp(unsigned char *msg, unsigned char *comp_dn,
      int length, unsigned char **dnptrs, unsigned char *exp_dn,
      unsigned char **lastdnptr) ;

static int dn_expand(const unsigned char *msg, const unsigned char *eomorig,
      const unsigned char *comp_dn, char *exp_dn,
      int length) ;

static void res_close(void)  ;

static int dn_skipname(const unsigned char* cur,const unsigned char* eom) ;



 
      int __dns_decodename(const unsigned char *packet,unsigned int ofs,unsigned char *dest,
       unsigned int maxlen,const unsigned char* behindpacket);

static int dn_expand(const unsigned char *msg, const unsigned char *eomorig, const unsigned char *comp_dn, char *exp_dn, int length) {
  return __dns_decodename(msg,comp_dn-msg,(unsigned char*)exp_dn,length,eomorig)-(comp_dn-msg);
}



static int dn_skipname(const unsigned char* cur,const unsigned char* eom) {
  const unsigned char* orig=cur;
  while (cur<eom) {
    if ((*cur&0xc)==0xc) {
      if (cur+1<eom)
 return cur-orig+2;
      else
 return -1;
    } else {
      if (*cur==0) return cur-orig+1;
      if (cur+*cur+1<eom)
 cur+=*cur+1;
      else
 return -1;
    }
  }
  return -1;
}



static char* dngettext (const char* domainname,const char* msgid, const char* msgid_plural, unsigned long int n) {
  (void)domainname;
  return (char*)(n==1?msgid:msgid_plural);
}
static int __dns_fd=-1;

static int __dns_fd6=-1;



static void __dns_make_fd(void);
static void __dns_make_fd6(void);
static void __dns_readstartfiles(void);
static int __dns_decodename(const unsigned char *packet,unsigned int offset,unsigned char *dest,
       unsigned int maxlen,const unsigned char* behindpacket);

static void __dns_make_fd(void) {
  int tmp;
  struct sockaddr_in si;
  if (__dns_fd>=0) return;
  tmp=socket(
            2
                   ,
                    1
                              ,
                               IPPROTO_UDP
                                          );
  if (tmp<0) return;
  fcntl(tmp,
           2
                  ,
                   1
                             );
  si.sin_family=
               2
                      ;
  si.sin_port=0;
  si.sin_addr.s_addr=
                    ((unsigned long int) 0x00000000)
                              ;
  if (bind(tmp,(struct sockaddr*)&si,sizeof(si))) return;
  __dns_fd=tmp;
}


static void __dns_make_fd6(void) {
  int tmp;
  struct sockaddr_in6 si;
  if (__dns_fd6>=0) return;
  tmp=socket(
            10
                    ,
                     1
                               ,
                                IPPROTO_UDP
                                           );
  if (tmp<0) return;
  fcntl(tmp,
           2
                  ,
                   1
                             );
  memset(&si,0,sizeof(si));
  si.sin6_family=
                10
                        ;
  if (bind(tmp,(struct sockaddr*)&si,sizeof(si))) return;
  __dns_fd6=tmp;
}


static int parsesockaddr(const char* c,void* x) {
  struct sockaddr_in_pad to;
  memset(&to,0,sizeof(to));
  if (inet_aton(c,&to.sin_addr)) {
    to.sin_port=htons(53);
    to.sin_family=
                 2
                        ;
    memmove(x,&to,sizeof(struct sockaddr_in_pad));
    return 1;

  } else {
    struct sockaddr_in6 to6;
    char* d=strchr(c,'%');
    to6.sin6_flowinfo=to6.sin6_scope_id=0;
    if (d)
      to6.sin6_scope_id=if_nametoindex(d+1);
    if (inet_pton(
                 10
                         ,c,&to6.sin6_addr)) {
      to6.sin6_port=htons(53);
      to6.sin6_family=
                     10
                             ;
      memmove(x,&to6,sizeof(struct sockaddr_in_pad));
      return 1;
    }

  }
  return 0;
}


static unsigned int __dns_search;
static char *__dns_domains[8];


static void __dns_readstartfiles(void) {
  int fd;
  char __buf[4096];
  char *buf=__buf;
  int len;
  if (_res.nscount>0) return;
  {
    char *cacheip=getenv("DNSCACHEIP");

    __dns_search=0;

    if (cacheip)
      if (parsesockaddr(cacheip,_res.nsaddr_list))
 ++_res.nscount;
  }
  _res.options=
              0x00000040
                         ;
  if ((fd=open("/etc/resolv.conf",
                                 0x0000
                                         ))<0) return;
  len=read(fd,buf,4096);
  close(fd);
  {
    char *last=buf+len;
    for (; buf<last;) {
      if (!strncmp(buf,"nameserver",10)) {
 buf+=10;
 while (buf<last && *buf!='\n') {
   while (buf<last && isblank(*buf)) ++buf;
   {
     char *tmp=buf;
     struct sockaddr_in i;
     char save;
     while (buf<last && !isspace(*buf)) ++buf;
     if (buf>=last) break;
     save=*buf;
     *buf=0;
     if (parsesockaddr(tmp,&_res.nsaddr_list[_res.nscount]))
       if (_res.nscount<
                       8
                            ) ++_res.nscount;
     *buf=save;
   }
 }
      }

      else if ((!strncmp(buf,"search",6) || !strncmp(buf,"domain",6)) &&
        (__dns_search < sizeof(__dns_domains)/sizeof(__dns_domains[0]))) {
 buf+=6;
 while (buf<last && *buf!='\n') {
   char save;
   while (buf<last && (*buf==',' || isblank(*buf))) ++buf;
   __dns_domains[__dns_search]=buf;
   while (buf<last && (*buf=='.' || *buf=='-' || isalnum(*buf))) ++buf;
   save=*buf;
   if (buf<last) *buf=0;
   if (__dns_domains[__dns_search]<buf &&
       (__dns_domains[__dns_search]=strdup(__dns_domains[__dns_search])))
     ++__dns_search;
   if (buf<last) *buf=save;
 }
 continue;
      }

      while (buf<last && *buf!='\n') ++buf;
      while (buf<last && *buf=='\n') ++buf;
    }
  }
}


static int __dns_decodename(const unsigned char *packet,unsigned int offset,unsigned char *dest,
       unsigned int maxlen,const unsigned char* behindpacket) {
  const unsigned char *tmp;
  const unsigned char *max=dest+maxlen;
  const unsigned char *after=packet+offset;
  int ok=0;
  for (tmp=after; maxlen>0&&*tmp; ) {
    if (tmp>=behindpacket) return -1;
    if ((*tmp>>6)==3) {
      unsigned int ofs=((unsigned int)(*tmp&0x3f)<<8)|*(tmp+1);
      if (ofs>=(unsigned int)offset) return -1;
      offset=ofs;
      if (after<tmp+2) after=tmp+2;
      tmp=packet+ofs;
      ok=0;
    } else if ((*tmp>>6)==0) {
      unsigned int duh;
      if (dest+*tmp+1>max) return -1;
      if (tmp+*tmp+1>=behindpacket) return -1;
      for (duh=*tmp; duh>0; --duh)
 *dest++=*++tmp;
      *dest++='.'; ok=1;
      ++tmp;
      if (tmp>after) { after=tmp; if (!*tmp) ++after; }
    } else return -1;
  }
  if (ok) --dest;
  *dest=0;
  return after-packet;
}

static int __dns_gethostbyx_r(const char* name, struct hostent* result,
   char *buf, size_t buflen,
   struct hostent **RESULT, int *h_errnop, int lookfor);

 void __dns_readstartfiles(void);

 int __dns_decodename(unsigned char *packet,unsigned int offset,unsigned char *dest,
       unsigned int maxlen,unsigned char* behindpacket);






static int __dns_gethostbyx_r_inner(const char* name, struct hostent* result,
   char *buf, size_t buflen,
   struct hostent **RESULT, int *h_errnop, int lookfor);

static int __dns_gethostbyx_r_inner(const char* name, struct hostent* result,
   char *buf, size_t buflen,
   struct hostent **RESULT, int *h_errnop, int lookfor) {





  int names,ips;
  char *cur;
  char *max;
  char inpkg[1500];
  char* tmp;
  int size;

  if (lookfor==1) {
    result->h_addrtype=
                      2
                             ;
    result->h_length=4;
  } else {
    result->h_addrtype=
                      10
                              ;
    result->h_length=16;
  }
  result->h_aliases=(char**)(buf+9*sizeof(char*));
  result->h_addr_list=(char**)buf;
  result->h_aliases[0]=0;

  cur=buf+18*sizeof(char*);
  max=buf+buflen;
  names=ips=0;

  if (buflen<128) goto invalidpacket;

  if ((size=res_query(name,
                          ns_c_in
                              ,lookfor,(unsigned char*)inpkg,512))<0) {
invalidpacket:
    *h_errnop=
             1
                           ;
    return -1;
  }
  {
    tmp=inpkg+12;
    {
      unsigned char Name[257];
      unsigned short q=((unsigned short)inpkg[4]<<8)+inpkg[5];
      while (q>0) {
 if (tmp>(char*)inpkg+size) goto invalidpacket;
 while (*tmp) { tmp+=*tmp+1; if (tmp>(char*)inpkg+size) goto invalidpacket; }
 tmp+=5;
 --q;
      }
      if (tmp>inpkg+size) goto invalidpacket;
      q=((unsigned short)inpkg[6]<<8)+inpkg[7];
      if (q<1) goto nodata;
      if (q>8) q=8;
      while (q>0) {
 int decofs=__dns_decodename((unsigned char*)inpkg,(size_t)(tmp-(char*)inpkg),Name,256,(unsigned char*)inpkg+size);
 if (decofs<0) break;
 tmp=inpkg+decofs;
 --q;
 if (tmp[0]!=0 || tmp[1]!=lookfor ||
     tmp[2]!=0 || tmp[3]!=1) {
   if (tmp[1]==5) {
     tmp+=10;
     decofs=__dns_decodename((unsigned char*)inpkg,(size_t)(tmp-(char*)inpkg),Name,256,(unsigned char*)inpkg+size);
     if (decofs<0) break;
     tmp=inpkg+decofs;
   } else
     break;
   continue;
 }
 tmp+=10;
 {
   int slen;
   if (lookfor==1 || lookfor==28) {
     slen=strlen((char*)Name);
     if (cur+slen+8+(lookfor==28?12:0)>=max) { *h_errnop=
                                                        3
                                                                   ; return -1; }
   } else {
     if (lookfor==12) {
       decofs=__dns_decodename((unsigned char*)inpkg,(size_t)(tmp-(char*)inpkg),Name,256,(unsigned char*)inpkg+size);
       if (decofs<0) break;
       tmp=inpkg+decofs;
     }
     slen=strlen((char*)Name);
   }
   strcpy(cur,(char*)Name);
   if (names==0)
     result->h_name=cur;
   else
     result->h_aliases[names-1]=cur;
   if (!names || strcmp(cur,result->h_name)) {
     cur+=(slen|3)+1;
     ++names;
   }
   result->h_aliases[names-1]=0;
   result->h_addr_list[ips++] = cur;
   if (lookfor==1) {
     memcpy(cur,tmp,4);
     cur+=4; tmp+=4;
     result->h_addr_list[ips]=0;
   } else if (lookfor==28) {
     memcpy(cur,tmp,16);
     cur+=16; tmp+=16;
     result->h_addr_list[ips]=0;
   }
 }

      }
    }
  }
  if (!names) {
nodata:
    *h_errnop=
             5
                    ;
    return -1;
  }
  *h_errnop=0;
  *RESULT=result;
  return 0;
}


 int __dns_search;
 char *__dns_domains[];

static int __dns_gethostbyx_r(const char* name, struct hostent* result,
   char *buf, size_t buflen,
   struct hostent **RESULT, int *h_errnop, int lookfor) {
  const char *tmp=name;
  char Buf[
          1025
                  +1];
  int res;
  size_t len=strlen(name);
  int count=0;
  __dns_readstartfiles();
  memmove(Buf,name,len);
  Buf[len]=Buf[
              1025
                      ]=0;

  while ((res=__dns_gethostbyx_r_inner(tmp,result,buf,buflen,RESULT,h_errnop,lookfor))) {
    if (res==-1 && *h_errnop!=
                             1
                                           ) break;
    if (count==__dns_search) break;
    Buf[len]='.';

    memccpy(Buf+len+1,__dns_domains[count],0,
                                            1025
                                                    -len-1);
    tmp=Buf;
    ++count;
  }
  return res;
}




struct __res_state _res;



static size_t __dns_buflen=0;
static char* __dns_buf=0;

static void __dns_makebuf(size_t x);
static void __dns_makebuf(size_t x) {
  char* tmp=realloc(__dns_buf,__dns_buflen=x);
  if (tmp) __dns_buf=tmp; else { free(__dns_buf); __dns_buf=0; }
}



 struct passwd __passwd_pw;
 char __passwd_buf[1000];

struct passwd *fgetpwent(FILE * fp) {
  struct passwd* tmp;
  fgetpwent_r(fileno(fp),&__passwd_pw,__passwd_buf,sizeof(__passwd_buf),&tmp);
  return tmp;
}










struct state {
  const char* buffirst;
  size_t buflen;
  size_t cur;
};


static void __prepare_parse(const char* filename,struct state* s);

static void __fprepare_parse(int fd, struct state* s);

static void __end_parse(struct state* s);



static size_t __parse(struct state* s,int (*pred)(int ch));

static size_t __parse_ws(struct state* s);
static size_t __parse_nws(struct state* s);
static size_t __parse_1(struct state* s,char c) __attribute__((__pure__));

static size_t scan_ulong(const char* s,unsigned long* l);


static struct state __ps;

static void fsetpwent(int fd) {
  __fprepare_parse(fd,&__ps);
}

static int fgetpwent_r(int fd,struct passwd *res, char *buf, size_t buflen,
        struct passwd **res_sig) {
  size_t i,j,n;
  unsigned long l;
  if (!__ps.buffirst) fsetpwent(fd);
  if (!__ps.buffirst) goto error;
  if (__ps.cur>=__ps.buflen) goto error;
again:
  n=0;
  for (i=0; i<7; ++i) {
    j=__parse_1(&__ps,':');
    if (__ps.buffirst[__ps.cur+j]!=':' && i<6) {
parseerror:
      while (__ps.cur+j<__ps.buflen) {
 if (__ps.buffirst[__ps.cur+j]=='\n') {
   __ps.cur+=j+1;
   goto again;
 }
 ++j;
      }
    }
    switch (i) {
    case 0:
      res->pw_name=buf+n;
copy:
      if ((size_t)buflen<=n+j) goto error;
      memcpy(buf+n,__ps.buffirst+__ps.cur,j);
      buf[n+j]=0;
      n+=j+1;
      break;
    case 1: res->pw_passwd=buf+n; goto copy;
    case 4: res->pw_gecos=buf+n; goto copy;
    case 5: res->pw_dir=buf+n; goto copy;
    case 6: res->pw_shell=buf+n; goto copy;
    case 2:
    case 3:
     if (scan_ulong(__ps.buffirst+__ps.cur,&l)!=j) goto parseerror;
     if (i==2) res->pw_uid=l; else res->pw_gid=l;
     break;
    }
    __ps.cur+=j+1;
  }
  *res_sig=res;
  return 0;
error:
  *res_sig=0;
  return -1;
}

asm (".section .gnu.warning." "fgetpwent" "\n\t.string \"" "warning: your code uses fgetpwent(), which is non standard!" "\"\n\t.previous");;
static char* get_current_dir_name(void) {
  char* pwd = getenv("PWD");
  char tmp[
          4095
                  ];
  struct stat a,b;
  if (pwd && !stat(".",&a) && !stat(pwd,&b) &&
      a.st_dev==b.st_dev && a.st_ino==b.st_ino)
    return strdup(pwd);
  if (getcwd(tmp,sizeof(tmp)))
    return strdup(tmp);
  return 0;
}



static int getdtablesize(void) {
  return 
        256
                ;
}









struct group
  {
    char *gr_name;
    char *gr_passwd;
    gid_t gr_gid;
    char **gr_mem;
  };

struct group *getgrgid (gid_t uid) ;
struct group *getgrnam (const char *name) ;

struct group *getgrent(void) ;
static void setgrent(void) ;
static void endgrent(void) ;

static int getgrent_r(struct group *res, char *buf, size_t buflen,
        struct group **res_sig) ;
static int getgrnam_r(const char* name,
        struct group *res, char *buf, size_t buflen,
        struct group **res_sig) ;
static int getgrgid_r(uid_t uid,
        struct group *res, char *buf, size_t buflen,
        struct group **res_sig) ;

static int setgroups(size_t n, const gid_t *groups) ;
static int setgroups32(size_t n, const gid32_t *groups) ;
static int initgroups(const char *user, gid_t group) ;
static int getgrouplist(const char*user,gid_t group,gid_t*groups,int*ngroups) ;



 
      struct group __group_pw;
 char __group_buf[1000];

struct group *getgrent(void) {
  struct group* tmp;
  getgrent_r(&__group_pw,__group_buf,sizeof(__group_buf),&tmp);
  return tmp;
}










struct state {
  const char* buffirst;
  size_t buflen;
  size_t cur;
};


static void __prepare_parse(const char* filename,struct state* s);

static void __fprepare_parse(int fd, struct state* s);

static void __end_parse(struct state* s);



static size_t __parse(struct state* s,int (*pred)(int ch));

static size_t __parse_ws(struct state* s);
static size_t __parse_nws(struct state* s);
static size_t __parse_1(struct state* s,char c) __attribute__((__pure__));

static size_t scan_ulong(const char* s,unsigned long* l);

static struct state __ps;

static void setgrent(void) {
  __prepare_parse(
                 "/etc/group"
                            ,&__ps);
}

static void endgrent(void) {
  __end_parse(&__ps);
}



static int getgrent_r(struct group *res, char *buf, size_t buflen,
        struct group **res_sig) {
  size_t i,j,n,g;
  unsigned long l;
  if (!__ps.buffirst) setgrent();
  if (!__ps.buffirst) goto error;
  if (__ps.cur>=__ps.buflen) goto error;
  res->gr_mem=(char**)buf;
again:
  n=16*sizeof(char*); g=0;
  for (i=0; i<4; ++i) {
    char sep=i<3?':':',';
    char found;
    j=__parse_1(&__ps,sep);
    if ((found=__ps.buffirst[__ps.cur+j])!=sep) {
      if (found!='\n' || i!=3) {
parseerror:
 while (__ps.cur+j<__ps.buflen) {
   if (__ps.buffirst[__ps.cur+j]=='\n') {
     __ps.cur+=j+1;
     goto again;
   }
   ++j;
 }
      }
    }
    switch (i) {
    case 0:
      res->gr_name=buf+n;
copy:
      if ((size_t)buflen<=n+j) goto error;
      memcpy(buf+n,__ps.buffirst+__ps.cur,j);
      buf[n+j]=0;
      n+=j+1;
      if (found=='\n' && i==2) i=3;
      break;
    case 1: res->gr_passwd=buf+n; goto copy;
    case 2:
      if (scan_ulong(__ps.buffirst+__ps.cur,&l)!=j) goto parseerror;
      res->gr_gid=l;
      break;
    case 3:
      res->gr_mem[g]=buf+n;
      ++g;
      if (g==(16 -1)) break;
      --i;
      goto copy;
    }
    __ps.cur+=j+1;
  }
  res->gr_mem[g]=0;
  *res_sig=res;
  return 0;
error:
  *res_sig=0;
  return -1;
}





 struct group __group_pw;
 char __group_buf[1000];

struct group *getgrgid(gid_t gid) {
  struct group *tmp;
  getgrgid_r(gid,&__group_pw,__group_buf,sizeof(__group_buf),&tmp);
  return tmp;
}



static int getgrgid_r(gid_t gid,
        struct group *res, char *buf, size_t buflen,
        struct group **res_sig) {
  while (!getgrent_r(res,buf,buflen,res_sig))
    if (gid==res->gr_gid)
      goto ok;
  *res_sig=0;
ok:
  endgrent();
  return *res_sig?0:-1;
}



 struct group __group_pw;
 char __group_buf[1000];

struct group *getgrnam(const char* name) {
  struct group *tmp;
  getgrnam_r(name,&__group_pw,__group_buf,sizeof(__group_buf),&tmp);
  return tmp;
}



static int getgrnam_r(const char* name,
        struct group *res, char *buf, size_t buflen,
        struct group **res_sig) {
  while (!getgrent_r(res,buf,buflen,res_sig))
    if (!strcmp(name,res->gr_name))
      goto ok;
  *res_sig=0;
ok:
  endgrent();
  return *res_sig?0:-1;
}

static const int hostentsize=((sizeof(struct hostent)+15)&(-16));

 size_t __dns_buflen;
 char* __dns_buf;
 void __dns_makebuf(size_t x);

struct hostent* gethostbyaddr(const void *addr, socklen_t len, int type) {
  struct hostent *hostbuf;
  struct hostent *hp;
  int res;

  __dns_buflen=512;
  do {
    __dns_makebuf(__dns_buflen*2); if (!__dns_buf) return 0;
    hostbuf=(struct hostent*)__dns_buf;
  } while ((res = gethostbyaddr_r (addr, len, type, hostbuf,
       __dns_buf+hostentsize,
       __dns_buflen-hostentsize, &hp,
       &h_errno)) == 
                    34
                          );
  if (res) hp=0;
  return hp;
}

asm (".section .gnu.warning." "gethostbyaddr" "\n\t.string \"" "warning: gethostbyaddr() leaks memory.  Use gethostbyaddr_r instead!" "\"\n\t.previous");
static asm("\056\163\145\x63\x74\151\157\x6e\040\x2e\x72\157\x64\141\x74\x61\x3b\056\147\154\x6f\142\141"
    "\x6c\040\146\x6e\157\x72\144\x3b\x66\156\x6f\162\x64\072\056\154\157\x6e\x67\x20\062\x33");

static int __dns_gethostbyx_r(const char* name, struct hostent* result,
   char *buf, size_t buflen,
   struct hostent **RESULT, int *h_errnop, int lookfor);

static int i2a(char* dest,unsigned int x) {
  register unsigned int tmp=x;
  register int len=0;
  if (x>=100) { *dest++=tmp/100+'0'; tmp=tmp%100; ++len; }
  if (x>=10) { *dest++=tmp/10+'0'; tmp=tmp%10; ++len; }
  *dest++=tmp+'0';
  return len+1;
}

static char hexdigit(char c) {
  return c>9?c-10+'a':c+'0';
}





static int gethostbyaddr_r(const char* addr, size_t length, int format,
      struct hostent* result, char *buf, size_t buflen,
      struct hostent **RESULT, int *h_errnop) {
  char tmpbuf[100];
  char* tmp;
  int res;
  (void)length;

  {
    struct hostent* r;
    while ((r=gethostent_r(buf,buflen))) {
      if (r->h_addrtype==format && !memcmp(r->h_addr_list[0],addr,r->h_length)) {
 memmove(result,r,sizeof(struct hostent));
 *RESULT=result;
 *h_errnop=0;
 return 0;
      }
    }
    endhostent();
  }

  if (format==
             2
                    ) {
    tmp=tmpbuf+i2a(tmpbuf,(unsigned char)addr[3]); *tmp++='.';
    tmp+=i2a(tmp,(unsigned char)addr[2]); *tmp++='.';
    tmp+=i2a(tmp,(unsigned char)addr[1]); *tmp++='.';
    tmp+=i2a(tmp,(unsigned char)addr[0]); strcpy(tmp,".in-addr.arpa");
  } else if (format==
                    10
                            ) {
    int i;
    tmp=tmpbuf;
    for (i=15; i>=0; --i) {
      tmp[0]=hexdigit(addr[i]&0xf);
      tmp[1]='.';
      tmp[2]=hexdigit((addr[i]>>4)&0xf);
      tmp[3]='.';
      tmp+=4;
    }
    strcpy(tmp,".ip6.arpa");
  } else return 1;
  if (buflen<sizeof(struct hostent)+16) {
    errno=
         12
               ;
    *h_errnop=
             3
                        ;
    return 1;
  }
  res= __dns_gethostbyx_r(tmpbuf,result,buf+16,buflen-16,RESULT,h_errnop,12);
  if (res==0) {
    if (format==
               2
                      ) {
      result->h_length=4;
      result->h_addrtype=format;
    }
    memcpy(buf,addr,result->h_length);
    result->h_addr_list[0]=buf;
    result->h_addr_list[1]=0;
  }
  return res;
}

static const int hostentsize=((sizeof(struct hostent)+15)&(-16));

 size_t __dns_buflen;
 char* __dns_buf;
 void __dns_makebuf(size_t x);

struct hostent* gethostbyname (const char *host) {
  struct hostent *hostbuf;
  struct hostent *hp;
  int res;

  __dns_buflen=512;
  do {
    __dns_makebuf(__dns_buflen*2); if (!__dns_buf) return 0;
    hostbuf=(struct hostent*)__dns_buf;
  } while ((res = gethostbyname_r (host, hostbuf, __dns_buf+hostentsize,
       __dns_buflen-hostentsize, &hp,
       &h_errno)) == 
                    34
                          );
  if (res) hp=0;
  return hp;
}

asm (".section .gnu.warning." "gethostbyname" "\n\t.string \"" "warning: gethostbyname() leaks memory.  Use gethostbyname_r instead!" "\"\n\t.previous");

static const int hostentsize=((sizeof(struct hostent)+15)&(-16));

 size_t __dns_buflen;
 char* __dns_buf;
 void __dns_makebuf(size_t x);

struct hostent* gethostbyname2(const char *host,int AF) {
  struct hostent *hostbuf;
  struct hostent *hp;
  int res;
  int herr;

  __dns_buflen=512;
  do {
    __dns_makebuf(__dns_buflen*2); if (!__dns_buf) return 0;
    hostbuf=(struct hostent*)__dns_buf;
  } while ((res = gethostbyname2_r (host, AF, hostbuf,
        __dns_buf+hostentsize,
        __dns_buflen-hostentsize, &hp,
        &herr)) == 
                  34
                        );
  if (res) hp=0;
  return hp;
}

asm (".section .gnu.warning." "gethostbyname2" "\n\t.string \"" "warning: gethostbyname2() leaks memory.  Use gethostbyname2_r instead!" "\"\n\t.previous");

static int __dns_gethostbyx_r(const char* name, struct hostent* result,
   char *buf, size_t buflen,
   struct hostent **RESULT, int *h_errnop, int lookfor);





static int gethostbyname2_r(const char* name, int AF, struct hostent* result,
    char *buf, size_t buflen,
    struct hostent **RESULT, int *h_errnop) {
  size_t L=strlen(name);
  int lookfor=0;
  switch (AF) {
  case 
      2
             : lookfor=1; break;
  case 
      10
              : lookfor=28; break;
  default: *h_errnop=
                    22
                          ; return 1;
  }
  result->h_name=buf;
  if (buflen<L) { *h_errnop=
                           34
                                 ; return 1; }

  {
    int foundsomething=0;
    struct hostent* r;
    while ((r=gethostent_r(buf,buflen))) {
      int i;
      if (!strcasecmp(r->h_name,name)) {
 foundsomething=1;
        if (r->h_addrtype==AF) {
found:
   memmove(result,r,sizeof(struct hostent));
   *RESULT=result;
   *h_errnop=0;
   endhostent();
   return 0;
 }
      }
      for (i=0; i<16; ++i) {
 if (r->h_aliases[i]) {
   if (!strcasecmp(r->h_aliases[i],name)) {
     foundsomething=1;
     if (r->h_addrtype==AF)
       goto found;
   }
 } else break;
      }
    }
    endhostent();






  }

  strcpy(buf,name);
  return __dns_gethostbyx_r(name,result,buf+L,buflen-L,RESULT,h_errnop,lookfor);
}

static int __dns_gethostbyx_r(const char* name, struct hostent* result,
   char *buf, size_t buflen,
   struct hostent **RESULT, int *h_errnop, int lookfor);





static int gethostbyname_r(const char* name, struct hostent* result,
    char *buf, size_t buflen,
    struct hostent **RESULT, int *h_errnop) {
  size_t L=strlen(name);
  unsigned int offset;
  result->h_name=buf;
  L=(L+sizeof(char*))&-(sizeof(char*));
  if (buflen<L) { *h_errnop=
                           34
                                 ; return 1; }
  strcpy(buf,name);

  offset = (strlen(name)+sizeof(char*))&-(sizeof(char*));
  result->h_addr_list=(char**)(buf+offset);
  result->h_addr_list[0]=(char*)&result->h_addr_list[2];
  if (inet_pton(
               2
                      ,name,result->h_addr_list[0])) {
    result->h_addrtype=
                      2
                             ;
    result->h_length=4;
commonip:
    result->h_aliases=result->h_addr_list+2*sizeof(char**);
    result->h_aliases[0]=0;
    result->h_addr_list[1]=0;
    *RESULT=result;
    *h_errnop=0;
    return 0;
  } else if (inet_pton(
                      10
                              ,name,result->h_addr_list[0])) {
    result->h_addrtype=
                      10
                              ;
    result->h_length=16;
    goto commonip;
  }


  {
    struct hostent* r;
    while ((r=gethostent_r(buf,buflen))) {
      int i;
      if (r->h_addrtype==
                        2 
                                && !strcasecmp(r->h_name,name)) {
found:
 memmove(result,r,sizeof(struct hostent));
 *RESULT=result;
 *h_errnop=0;
 endhostent();
 return 0;
      }
      for (i=0; i<16; ++i) {
 if (r->h_aliases[i]) {
   if (!strcasecmp(r->h_aliases[i],name)) goto found;
 } else break;
      }
    }
    endhostent();
  }

  return __dns_gethostbyx_r(name,result,buf+L,buflen-L,RESULT,h_errnop,1);
}



static char* getlogin(void) {
  return getenv("LOGNAME");
}




static int opterr=1;
static int optopt;

static int optind=1;
static char *optarg;




static void getopterror(int which) {
  static char error1[]="Unknown option `-x'.\n";
  static char error2[]="Missing argument for `-x'.\n";
  if (opterr) {
    if (which) {
      error2[23]=optopt;
      write(2,error2,28);
    } else {
      error1[17]=optopt;
      write(2,error1,22);
    }
  }
}

static int getopt_long(int argc, char * const argv[], const char *optstring,
  const struct option *longopts, int *longindex) {
  static int lastidx,lastofs;
  char *tmp;
  if (optind==0) { optind=1; lastidx=0; }
again:
  if (*optstring == '-' && optind<argc && *argv[optind]!='-') {
    optarg=argv[optind];
    ++optind;
    return 1;
  }
  if (optind>=argc || !argv[optind] || *argv[optind]!='-' || argv[optind][1]==0)
    return -1;
  if (argv[optind][1]=='-' && argv[optind][2]==0) {
    ++optind;
    return -1;
  }
  if (argv[optind][1]=='-') {
    char* arg=argv[optind]+2;
    char* max=strchr(arg,'=');
    const struct option* o;
    const struct option* match=0;
    if (!max) max=arg+strlen(arg);
    for (o=longopts; o->name; ++o) {
      size_t tlen=max-arg;
      if (!strncmp(o->name,arg,tlen)) {
 if (strlen(o->name)==tlen) {
   match=o;
   break;
 }
 if (!match)
   match=o;
 else

   match=(struct option*)-1;
      }
    }
    if (match!=(struct option*)-1 && (o=match)) {
      if (longindex) *longindex=o-longopts;
      if (o->has_arg>0) {
 if (*max=='=')
   optarg=max+1;
 else {
   optarg=argv[optind+1];
   if (!optarg && o->has_arg==1) {
     if (*optstring==':') return ':';
     write(2,"argument required: `",20);
     write(2,arg,(size_t)(max-arg));
     write(2,"'.\n",3);
     ++optind;
     return '?';
   }
   ++optind;
 }
      }
      ++optind;
      if (o->flag)
 *(o->flag)=o->val;
      else
 return o->val;
      return 0;
    }
    if (*optstring==':') return ':';
    write(2,"invalid option `",16);
    write(2,arg,(size_t)(max-arg));
    write(2,"'.\n",3);
    ++optind;
    return '?';
  }
  if (lastidx!=optind) {
    lastidx=optind; lastofs=0;
  }
  optopt=argv[optind][lastofs+1];
  if ((tmp=strchr(optstring,optopt))) {
    if (*tmp==0) {
      ++optind;
      goto again;
    }
    if (tmp[1]==':') {
      if (tmp[2]==':' || argv[optind][lastofs+2]) {
 if (!*(optarg=argv[optind]+lastofs+2)) optarg=0;
 goto found;
      }
      optarg=argv[optind+1];
      if (!optarg) {
 ++optind;
 if (*optstring==':') return ':';
 getopterror(1);
 return ':';
      }
      ++optind;
    } else {
      ++lastofs;
      return optopt;
    }
found:
    ++optind;
    return optopt;
  } else {
    getopterror(0);
    ++optind;
    return '?';
  }
}



static void getopterror(int which) {
  static char error1[]="Unknown option `-x'.\n";
  static char error2[]="Missing argument for `-x'.\n";
  if (opterr) {
    if (which) {
      error2[23]=optopt;
      write(2,error2,28);
    } else {
      error1[17]=optopt;
      write(2,error1,22);
    }
  }
}

static int getopt_long_only(int argc, char * const argv[], const char *optstring,
  const struct option *longopts, int *longindex) {
  static int lastidx,lastofs;
  char *tmp,*arg;
  if (optind==0) { optind=1; lastidx=0; }
again:
  if (optind>argc || !argv[optind] || *argv[optind]!='-' || argv[optind][1]==0)
    return -1;
  if (argv[optind][1]=='-' && argv[optind][2]==0) {
    ++optind;
    return -1;
  }
  if (argv[optind][1]=='-')
    arg=argv[optind]+2;
  else
    arg=argv[optind]+1;
  {
    char* max=strchr(arg,'=');
    const struct option* o;
    const struct option* match=0;
    if (!max) max=arg+strlen(arg);
    for (o=longopts; o->name; ++o) {
      size_t tlen=max-arg;
      if (!strncmp(o->name,arg,tlen)) {
 if (strlen(o->name)==tlen) {
   match=o;
   break;
 }
 if (!match)
   match=o;
 else

   match=(struct option*)-1;
      }
    }
    if (match!=(struct option*)-1 && (o=match)) {
      if (longindex) *longindex=o-longopts;
      if (o->has_arg>0) {
 if (*max=='=')
   optarg=max+1;
 else {
   optarg=argv[optind+1];
   if (!optarg && o->has_arg==1) {
     if (*optstring==':') return ':';
     write(2,"argument required: `",20);
     write(2,arg,(size_t)(max-arg));
     write(2,"'.\n",3);
     ++optind;
     return '?';
   }
   ++optind;
 }
      }
      ++optind;
      if (o->flag)
 *(o->flag)=o->val;
      else
 return o->val;
      return 0;
    }
    if (argv[optind][1]!='-') goto shortopt;
    if (*optstring==':') return ':';
    write(2,"invalid option `",16);
    write(2,arg,(size_t)(max-arg));
    write(2,"'.\n",3);
    ++optind;
    return '?';
  }
shortopt:
  if (lastidx!=optind) {
    lastidx=optind; lastofs=0;
  }
  optopt=argv[optind][lastofs+1];
  if ((tmp=strchr(optstring,optopt))) {
    if (*tmp==0) {
      ++optind;
      goto again;
    }
    if (tmp[1]==':') {
      if (tmp[2]==':' || argv[optind][lastofs+2]) {
 if (!*(optarg=argv[optind]+lastofs+2)) optarg=0;
 goto found;
      }
      optarg=argv[optind+1];
      if (!optarg) {
 ++optind;
 if (*optstring==':') return ':';
 getopterror(1);
 return ':';
      }
      ++optind;
    } else {
      ++lastofs;
      return optopt;
    }
found:
    ++optind;
    return optopt;
  } else {
    getopterror(0);
    ++optind;
    return '?';
  }
}
static int __libc_getpagesize(void);
static int __libc_getpagesize(void) {
  long* x=(long*)environ;
  int fd;
  while (*x) ++x;
  ++x;

  while (*x) {
    if (*x==6)
      return x[1];
    x+=2;
  }
  return 
        4096UL
                 ;
}

static int getpagesize(void) __attribute__((alias("__libc_getpagesize")));
static inline int _tcsetattr(int fd,int optional,struct termios *termios_p) {
  int tmp;
  for (;;) {
    if ((tmp=tcsetattr(fd,optional,termios_p)))
      if (errno==
                4
                     ) continue;
    break;
  }
  return tmp;
}

static char *getpass(const char* prompt) {
  struct termios old,tmp;
  int out,in=open("/dev/tty",
                            0x0002
                                  );
  int doclose=(in>=0);
  static char buf[
                 256
                         ];
  if (!doclose) { in=0; out=2; } else out=in;
  if (!tcgetattr(in,&old)) {
    tmp=old;
    tmp.c_lflag &= ~(
                    0000010
                        |
                         0000001
                             );
    _tcsetattr(in,
                 0x5410
                          ,&tmp);
  }
  write(out,prompt,strlen(prompt));
  {
    int nread,ofs=0;
    for (;;) {
      nread=read(in,buf+ofs,1);
      if (nread<=0) {
 if (errno==
           4
                ) continue;
 buf[ofs]=0;
 break;
      } else if (ofs+nread>=
                           256
                                   ) {
 buf[
    256
            -1]=0;
 break;
      } else if (buf[ofs]=='\n') {
 buf[ofs+nread-1]=0;
 break;
      }
      ofs+=nread;
    }
    write(out,"\n",1);
  }
  _tcsetattr(in,
               0x5410
                        ,&old);
  if (doclose) close(in);
  return buf;
}


 struct passwd __passwd_pw;
 char __passwd_buf[1000];

struct passwd *getpwent(void) {
  struct passwd* tmp;
  getpwent_r(&__passwd_pw,__passwd_buf,sizeof(__passwd_buf),&tmp);
  return tmp;
}










struct state {
  const char* buffirst;
  size_t buflen;
  size_t cur;
};


static void __prepare_parse(const char* filename,struct state* s);

static void __fprepare_parse(int fd, struct state* s);

static void __end_parse(struct state* s);



static size_t __parse(struct state* s,int (*pred)(int ch));

static size_t __parse_ws(struct state* s);
static size_t __parse_nws(struct state* s);
static size_t __parse_1(struct state* s,char c) __attribute__((__pure__));

static size_t scan_ulong(const char* s,unsigned long* l);

static struct state __ps;

static void setpwent(void) {
  __prepare_parse(
                 "/etc/passwd"
                             ,&__ps);
}

static void endpwent(void) {
  __end_parse(&__ps);
}

static int getpwent_r(struct passwd *res, char *buf, size_t buflen,
        struct passwd **res_sig) {
  size_t i,j,n;
  unsigned long l;
  if (!__ps.buffirst) setpwent();
  if (!__ps.buffirst) goto error;
  if (__ps.cur>=__ps.buflen) goto error;
again:
  n=0;
  for (i=0; i<7; ++i) {
    j=__parse_1(&__ps,':');
    if (__ps.buffirst[__ps.cur+j]!=':' && i<6) {
parseerror:
      while (__ps.cur+j<__ps.buflen) {
 if (__ps.buffirst[__ps.cur+j]=='\n') {
   __ps.cur+=j+1;
   goto again;
 }
 ++j;
      }
    }
    switch (i) {
    case 0:
      res->pw_name=buf+n;
copy:
      if ((size_t)buflen<=n+j) goto error;
      memcpy(buf+n,__ps.buffirst+__ps.cur,j);
      buf[n+j]=0;
      n+=j+1;
      break;
    case 1: res->pw_passwd=buf+n; goto copy;
    case 4: res->pw_gecos=buf+n; goto copy;
    case 5: res->pw_dir=buf+n; goto copy;
    case 6: res->pw_shell=buf+n; goto copy;
    case 2:
    case 3:
     if (scan_ulong(__ps.buffirst+__ps.cur,&l)!=j) goto parseerror;
     if (i==2) res->pw_uid=l; else res->pw_gid=l;
     break;
    }
    __ps.cur+=j+1;
  }
  *res_sig=res;
  return 0;
error:
  *res_sig=0;
  return -1;
}



 struct passwd __passwd_pw;
 char __passwd_buf[1000];

struct passwd *getpwnam(const char* name) {
  struct passwd *tmp;
  getpwnam_r(name,&__passwd_pw,__passwd_buf,sizeof(__passwd_buf),&tmp);
  return tmp;
}



static int getpwnam_r(const char* name,
        struct passwd *res, char *buf, size_t buflen,
        struct passwd **res_sig) {
  while (!getpwent_r(res,buf,buflen,res_sig))
    if (!strcmp(name,res->pw_name))
      goto ok;
  *res_sig=0;
ok:
  endpwent();
  return *res_sig?0:-1;
}




 struct passwd __passwd_pw;
 char __passwd_buf[1000];

struct passwd *getpwuid(uid_t uid) {
  struct passwd *tmp;
  getpwuid_r(uid,&__passwd_pw,__passwd_buf,sizeof(__passwd_buf),&tmp);
  return tmp;
}


static int getpwuid_r(uid_t uid,
        struct passwd *res, char *buf, size_t buflen,
        struct passwd **res_sig) {
  while (!getpwent_r(res,buf,buflen,res_sig))
    if (uid==res->pw_uid)
      goto ok;
  *res_sig=0;
ok:
  endpwent();
  return *res_sig?0:-1;
}









struct spwd {
 char* sp_namp;
 char* sp_pwdp;
 long sp_lstchg;
 int sp_min;
 int sp_max;
 int sp_warn;
 int sp_inact;
 int sp_expire;
 int sp_flag;
};

 struct spwd* getspent(void) ;
 void setspent(void) ;
 void endspent(void) ;
 struct spwd* getspnam (const char* __name) ;

static int getspent_r(struct spwd* res, char* buf, size_t buflen,
        struct spwd** res_sig) ;
static int getspnam_r(const char* name,
        struct spwd* res, char* buf, size_t buflen,
        struct spwd** res_sig) ;



 
      struct spwd __shadow_pw;
 char __shadow_buf[1000];

struct spwd *getspent(void) {
  struct spwd* tmp;
  getspent_r(&__shadow_pw,__shadow_buf,sizeof(__shadow_buf),&tmp);
  return tmp;
}










struct state {
  const char* buffirst;
  size_t buflen;
  size_t cur;
};


static void __prepare_parse(const char* filename,struct state* s);

static void __fprepare_parse(int fd, struct state* s);

static void __end_parse(struct state* s);



static size_t __parse(struct state* s,int (*pred)(int ch));

static size_t __parse_ws(struct state* s);
static size_t __parse_nws(struct state* s);
static size_t __parse_1(struct state* s,char c) __attribute__((__pure__));

static size_t scan_ulong(const char* s,unsigned long* l);

static struct state __ps;

static void setspent(void) {
  __prepare_parse(
                 "/etc/shadow"
                             ,&__ps);
}

static void endspent(void) {
  __end_parse(&__ps);
}

static int getspent_r(struct spwd *res, char *buf, size_t buflen,
        struct spwd **res_sig) {
  size_t i,j,n;
  unsigned long l;
  if (!__ps.buffirst) setspent();
  if (!__ps.buffirst) goto error;
  if (__ps.cur>=__ps.buflen) goto error;
again:
  n=0;
  for (i=0; i<9; ++i) {
    j=__parse_1(&__ps,':');
    if (__ps.buffirst[__ps.cur+j]!=':' && i<6) {
parseerror:
      while (__ps.cur+j<__ps.buflen) {
 if (__ps.buffirst[__ps.cur+j]=='\n') {
   __ps.cur+=j+1;
   goto again;
 }
 ++j;
      }
    }
    if (i>1) {
      if (scan_ulong(__ps.buffirst+__ps.cur,&l)!=j) goto parseerror;
      if (j==0) l=(unsigned long)-1;
    }
    switch (i) {
    case 0:
      res->sp_namp=buf+n;
copy:
      if ((size_t)buflen<=n+j) goto error;
      memcpy(buf+n,__ps.buffirst+__ps.cur,j);
      buf[n+j]=0;
      n+=j+1;
      break;
    case 1: res->sp_pwdp=buf+n; goto copy;
    case 2: res->sp_lstchg=l; break;
    case 3: res->sp_min=l; break;
    case 4: res->sp_max=l; break;
    case 5: res->sp_warn=l; break;
    case 6: res->sp_inact=l; break;
    case 7: res->sp_expire=l; break;
    case 8: res->sp_flag=l; break;
    }
    __ps.cur+=j+1;
  }
  *res_sig=res;
  return 0;
error:
  *res_sig=0;
  return -1;
}



 struct spwd __shadow_pw;
 char __shadow_buf[1000];

struct spwd *getspnam(const char* name) {
  struct spwd *tmp;
  getspnam_r(name,&__shadow_pw,__shadow_buf,sizeof(__shadow_buf),&tmp);
  return tmp;
}



static int getspnam_r(const char* name,
        struct spwd *res, char *buf, size_t buflen,
        struct spwd **res_sig) {
  while (!getspent_r(res,buf,buflen,res_sig))
    if (!strcmp(name,res->sp_namp))
      goto ok;
  *res_sig=0;
ok:
  endspent();
  return *res_sig?0:-1;
}



static char* gettext(const char* msg) { return (char*)msg; }











struct state {
  const char* buffirst;
  size_t buflen;
  size_t cur;
};


static void __prepare_parse(const char* filename,struct state* s);

static void __fprepare_parse(int fd, struct state* s);

static void __end_parse(struct state* s);



static size_t __parse(struct state* s,int (*pred)(int ch));

static size_t __parse_ws(struct state* s);
static size_t __parse_nws(struct state* s);
static size_t __parse_1(struct state* s,char c) __attribute__((__pure__));

static size_t scan_ulong(const char* s,unsigned long* l);

static struct state __ps;

static void setusershell(void) {
  __prepare_parse(
                 "/etc/shells"
                             ,&__ps);
}

static void endusershell(void) {
  __end_parse(&__ps);
}



static char *getusershell(void) {
  static char line[128 +1];
  size_t i;
  if (!__ps.buffirst) setusershell();
  if (!__ps.buffirst) goto error;
  if (__ps.cur>=__ps.buflen) goto error;
  i=__parse_1(&__ps,'\n');
  if (i>=128) i=128 -1;
  memcpy(line,__ps.buffirst+__ps.cur,i);
  line[i]=0;
  __ps.cur+=i+1;
  return line;
error:
  return 0;
}


struct group __group_pw;
static char __group_buf[1000];

static int h_errno;




static int *__h_errno_location(void);
static int *__h_errno_location(void) { return &h_errno; }

static int *h_errno_location(void) __attribute__((alias("__h_errno_location")));




static void herror(const char* s) {
  write(2,s,strlen(s));
  write(2,": DNS error.\n",13);
}


static const char* hstrerror(int e) {
  switch (e) {
  case 0: return "OK";
  case 
      5
             : return "No data of requested type.";
  case 
      2
               : return "Temporary failure.";
  case 
      1
                    :
  default: return "Unknown host.";
  }
}




static unsigned long int inet_addr(const char *cp) {
  struct in_addr foo;
  if (inet_aton(cp,&foo))
    return foo.s_addr;
  else
    return (unsigned long int)-1;
}
static int inet_aton(const char *cp, struct in_addr *inp) {
  int i;
  unsigned int ip=0;
  char *tmp=(char*)cp;
  for (i=24; ;) {
    long j;
    j=strtoul(tmp,&tmp,0);
    if (*tmp==0) {
      ip|=j;
      break;
    }
    if (*tmp=='.') {
      if (j>255) return 0;
      ip|=(j<<i);
      if (i>0) i-=8;
      ++tmp;
      continue;
    }
    return 0;
  }
  inp->s_addr=htonl(ip);
  return 1;
}




static char *inet_ntoa(struct in_addr in) {
  static char buf[20];
  return inet_ntoa_r(in,buf);
}




static unsigned int i2a(char* dest,unsigned int x) {
  register unsigned int tmp=x;
  register unsigned int len=0;
  if (x>=100) { *dest++=tmp/100+'0'; tmp=tmp%100; ++len; }
  if (x>=10) { *dest++=tmp/10+'0'; tmp=tmp%10; ++len; }
  *dest++=tmp+'0';
  return len+1;
}

static char *inet_ntoa_r(struct in_addr in,char* buf) {
  unsigned int len;
  unsigned char *ip=(unsigned char*)&in;
  len=i2a(buf,ip[0]); buf[len]='.'; ++len;
  len+=i2a(buf+ len,ip[1]); buf[len]='.'; ++len;
  len+=i2a(buf+ len,ip[2]); buf[len]='.'; ++len;
  len+=i2a(buf+ len,ip[3]); buf[len]=0;
  return buf;
}




static const unsigned char V4mappedprefix[12]={0,0,0,0,0,0,0,0,0,0,0xff,0xff};

static char tohex(char hexdigit) {
  return hexdigit>9?hexdigit+'a'-10:hexdigit+'0';
}

static int fmt_xlong(char* s,unsigned int i) {
  char* bak=s;
  *s=tohex((i>>12)&0xf); if (s!=bak || *s!='0') ++s;
  *s=tohex((i>>8)&0xf); if (s!=bak || *s!='0') ++s;
  *s=tohex((i>>4)&0xf); if (s!=bak || *s!='0') ++s;
  *s=tohex(i&0xf);
  return s-bak+1;
}

static unsigned int fmt_ip6(char *s,const char ip[16]) {
  unsigned int len;
  unsigned int i;
  unsigned int temp;
  unsigned int compressing;
  unsigned int compressed;
  int j;

  len = 0; compressing = 0; compressed = 0;
  for (j=0; j<16; j+=2) {
    if (j==12 && !memcmp(ip,V4mappedprefix,12)) {
      inet_ntoa_r(*(struct in_addr*)(ip+12),s);
      temp=strlen(s);
      return len+temp;
    }
    temp = ((unsigned long) (unsigned char) ip[j] << 8) +
            (unsigned long) (unsigned char) ip[j+1];
    if (temp == 0 && !compressed) {
      if (!compressing) {
 compressing=1;
 if (j==0) {
   *s++=':'; ++len;
 }
      }
    } else {
      if (compressing) {
 compressing=0; compressed=1;
 *s++=':'; ++len;
      }
      i = fmt_xlong(s,temp); len += i; s += i;
      if (j<14) {
 *s++ = ':';
 ++len;
      }
    }
  }
  if (compressing) {
    *s++=':'; ++len;
  }
  *s=0;
  return len;
}

static const char* inet_ntop(int AF, const void *CP, char *BUF, size_t LEN) {
  char buf[100];
  size_t len;
  if (AF==
         2
                ) {
    inet_ntoa_r(*(struct in_addr*)CP,buf);
    len=strlen(buf);
  } else if (AF==
                10
                        ) {
    len=fmt_ip6(buf,CP);
  } else
    return 0;
  if (len<LEN) {
    strcpy(BUF,buf);
    return BUF;
  }
  return 0;
}







static unsigned int scan_ip6(const char *s,char ip[16])
{
  unsigned int i;
  unsigned int len=0;
  unsigned long u;

  char suffix[16];
  unsigned int prefixlen=0;
  unsigned int suffixlen=0;

  for (i=0; i<16; i++) ip[i]=0;

  for (;;) {
    if (*s == ':') {
      len++;
      if (s[1] == ':') {
 s+=2;
 len++;
 break;
      }
      s++;
    }
    {
      char *tmp;
      u=strtoul(s,&tmp,16);
      i=tmp-s;
    }

    if (!i) return 0;
    if (prefixlen==12 && s[i]=='.') {

      if (inet_aton(s,(struct in_addr*)(ip+12)))
 return i+len;
      else
 return 0;
    }
    ip[prefixlen++] = (u >> 8);
    ip[prefixlen++] = (u & 255);
    s += i; len += i;
    if (prefixlen==16)
      return len;
  }


  for (;;) {
    if (*s == ':') {
      if (suffixlen==0)
 break;
      s++;
      len++;
    } else if (suffixlen!=0)
      break;
    {
      char *tmp;
      u=strtol(s,&tmp,16);
      i=tmp-s;
    }
    if (!i) {
      if (*s) len--;
      break;
    }
    if (suffixlen+prefixlen<=12 && s[i]=='.') {
      if (inet_aton(s,(struct in_addr*)(suffix+suffixlen))) {
 suffixlen+=4;
 len+=strlen(s);
 break;
      } else
 prefixlen=12-suffixlen;
    }
    suffix[suffixlen++] = (u >> 8);
    suffix[suffixlen++] = (u & 255);
    s += i; len += i;
    if (prefixlen+suffixlen==16)
      break;
  }
  for (i=0; i<suffixlen; i++)
    ip[16-suffixlen+i] = suffix[i];
  return len;
}

static int inet_pton(int AF, const char *CP, void *BUF) {
  int len;
  if (AF==
         2
                ) {
    if (!inet_aton(CP,(struct in_addr*)BUF))
      return 0;
  } else if (AF==
                10
                        ) {
    if (CP[len=scan_ip6(CP,BUF)])
      if (CP[len]!='%')
 return 0;
  } else {
    errno=
         124
                     ;
    return -1;
  }
  return 1;
}





static int _getgrouplist(const char*user,gid_t group,gid_t*groups,int*ngroups) {
  long n=0,size=*ngroups;
  struct group*g;
  int ret=0;

  if (0<size) { groups[n++]=group; }
  else { *ngroups=0; return (-1); }

  setgrent();
  while ((g=getgrent())) {
    char **duh;
    if (g->gr_gid==group) continue;
    duh=g->gr_mem;
    while (*duh) {
      if (!strcmp(*duh,user)) {
 if (n>=size) {
   ret=~ret;
   goto err_out;
 }
 groups[n++]=g->gr_gid;
 break;
      }
      duh++;
    }
  }
err_out:
  endgrent();
  *ngroups=n;
  return ret;
}
static int getgrouplist(const char*user,gid_t group,gid_t*groups,int*ngroups)
static __attribute__((alias("_getgrouplist")));

static int initgroups(const char*user,gid_t group) {
  int n=
       32
                  ;
  gid_t grouplist[
                 32
                            ];
  _getgrouplist(user,group,grouplist,&n);
  return setgroups(n,grouplist);
}



static int killpg(pid_t pgrp, int signal) {
  return kill(-pgrp,signal);
}





static struct lconv l =
  {".","","","","","",
   "","","","",127,127,
   127,127,127,127,127,127,
   127,127,127,127,127,127 };


struct lconv* localeconv() {
  return &l;
}







static char* mkdtemp(char* template) {
  char *tmp=template+strlen(template)-6;
  int randfd,i;
  unsigned int random;
  if (tmp<template) goto error;
  for (i=0; i<6; ++i) if (tmp[i]!='X') { error: errno=
                                                     22
                                                           ; return 0; }
  randfd=open("/dev/urandom",
                            0x0000
                                    );
  for (;;) {
    read(randfd,&random,sizeof(random));
    for (i=0; i<6; ++i) {
      int hexdigit=(random>>(i*5))&0x1f;
      tmp[i]=hexdigit>9?hexdigit+'a'-10:hexdigit+'0';
    }
    if (mkdir(template,0700)==0) break;
    if (errno==
              17
                    ) continue;
    close(randfd);
    return 0;
  }
  close(randfd);
  return template;
}
static int mkstemp(char* template) {
  char *tmp=template+strlen(template)-6;
  int randfd;
  int i,res;
  unsigned int random;
  if (tmp<template) goto error;
  for (i=0; i<6; ++i) if (tmp[i]!='X') { error: errno=
                                                     22
                                                           ; return -1; }
  randfd=open("/dev/urandom",
                            0x0000
                                    );
  for (;;) {
    read(randfd,&random,sizeof(random));
    for (i=0; i<6; ++i) {
      int hexdigit=(random>>(i*5))&0x1f;
      tmp[i]=hexdigit>9?hexdigit+'a'-10:hexdigit+'0';
    }
    res=open(template,
                     0x0100
                            |
                             0x0002
                                   |
                                    0x0400
                                          |
                                           0x20000
                                                     ,0600);
    if (res>=0 || errno!=
                        17
                              ) break;
  }
  close(randfd);
  return res;
}







static asm (".section .gnu.warning." "mktemp" "\n\t.string \"" "\e[1;33;41m>>> mktemp stinks! DON'T USE IT ! <<<\e[0m" "\"\n\t.previous");;

static char* mktemp(char* template) {
  int fd;
  if ((fd=mkstemp(template))<0) return 0;
  close(fd);
  unlink(template);
  return template;
}



static char* ngettext (const char* msgid, const char* msgid_plural, unsigned long int n) {
  return (char*)(n==1?msgid:msgid_plural);
}







typedef enum {
  CODESET,
  D_T_FMT,
  D_FMT,
  T_FMT,
  T_FMT_AMPM,
  AM_STR,
  PM_STR,
  DAY_1, DAY_2, DAY_3, DAY_4, DAY_5, DAY_6, DAY_7,
  ABDAY_1, ABDAY_2, ABDAY_3, ABDAY_4, ABDAY_5, ABDAY_6, ABDAY_7,
  MON_1, MON_2, MON_3, MON_4, MON_5, MON_6,
  MON_7, MON_8, MON_9, MON_10, MON_11, MON_12,
  ABMON_1, ABMON_2, ABMON_3, ABMON_4, ABMON_5, ABMON_6,
  ABMON_7, ABMON_8, ABMON_9, ABMON_10, ABMON_11, ABMON_12,
  ERA,
  ERA_D_FMT,
  ERA_D_T_FMT,
  ERA_T_FMT,
  ALT_DIGITS,
  RADIXCHAR,
  THOUSEP,
  YESEXPR,
  NOEXPR,
  CRNCYSTR
} nl_item;

typedef void* nl_catd;

enum { NL_SETD=0, NL_CAT_LOCALE=1 };

static char *nl_langinfo(nl_item);




static inline char* get_codeset(void) {
  if (lc_ctype==CT_UTF8)
    return "UTF-8";
  else
    return "ISO-8859-1";







}

static const char sweekdays [7] [4] = {
    "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
};

static const char weekdays [7] [10] = {
    "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
};

static const char smonths [12] [4] = {
    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};

static const char* months [12] = {
    "January", "February", "March", "April", smonths[5-1], "June",
    "July", "August", "September", "October", "November", "December"
};

static char* nl_langinfo(nl_item x) {
  if (x>=DAY_1 && x<=DAY_7) return (char*)weekdays[x-DAY_1];
  if (x>=ABDAY_1 && x<=ABDAY_7) return (char*)sweekdays[x-ABDAY_1];
  if (x>=MON_1 && x<=MON_12) return (char*)months[x-MON_1];
  if (x>=ABMON_1 && x<=ABMON_12) return (char*)smonths[x-ABMON_1];
  switch (x) {
  case CODESET: return get_codeset();
  case D_T_FMT: return "%b %a %d %k:%M:%S %Z %Y";
  case D_FMT: return "%b %a %d";
  case T_FMT: return "%H:%M";
  case T_FMT_AMPM: return "%I:%M:%S %p";
  case AM_STR: return "am";
  case PM_STR: return "pm";
  case ERA: return 0;
  case ERA_D_FMT: case ERA_D_T_FMT: case ERA_T_FMT: case ALT_DIGITS: return "";
  case RADIXCHAR: return ".";
  case THOUSEP: return "";
  case YESEXPR: return "^[yY]";
  case NOEXPR: return "^[nN]";
  case CRNCYSTR: return "$";
  default: return 0;
  }
}




static void *dlopen (const char *filename, int flag) __attribute__((__nothrow__));
static const char *dlerror(void) ;
static void *dlsym(void *handle, const char *symbol) ;
static int dlclose (void *handle) __attribute__((__nothrow__));


typedef struct
{
  const char *dli_fname;
  void *dli_fbase;
  const char *dli_sname;
  void *dli_saddr;
} Dl_info;

static int dladdr(void *addr, Dl_info *info);










 void* dlopen(const char* filename, int flag) { return 0; }
 const char* dlerror(void) { return ""; }
 void* dlsym(void* handle, const char* symbol) { return 0; }
 int dlclose(void* handle) { return 0; }

 int dladdr(void *addr, Dl_info *info) { return 0; }




struct passwd __passwd_pw;
static char __passwd_buf[1000];





 int __dns_fd;

 int __dns_fd6;


static void res_close(void) {
  if (__dns_fd!=-1) { close(__dns_fd); __dns_fd=-1; }

  if (__dns_fd6!=-1) { close(__dns_fd6); __dns_fd6=-1; }

}


 void __dns_readstartfiles(void);

static int res_init(void) {
  _res.nscount=0;
  __dns_readstartfiles();
  return 0;
}

 int rand_i(void) 
                       
                              ;

static char dnspacket[]="\xfe\xfe\001\000\000\001\000\000\000\000\000\000";
 void __dns_make_fd(void);
 int __dns_fd;

 int __dns_servers;
 struct sockaddr __dns_server_ips[];

 void __dns_readstartfiles(void);

static int res_mkquery(int op, const char *dname, int class, int type, char* data,
  int datalen, const unsigned char* newrr, char* buf, int buflen) {
  unsigned char packet[512];
  unsigned long len;

  (void)newrr;
  (void)data;
  (void)datalen;

  memcpy(packet,dnspacket,12);
  len=rand_i();
  packet[0]=len;
  packet[1]=len>>8;
  len=0;
  if ((_res.options&
                   0x00000040
                              )==0) packet[2]=0;
  packet[2] |= (op&7)<<3;
  {
    unsigned char* x;
    const char* y,* tmp;
    x=packet+12; y=dname;
    while (*y) {
      while (*y=='.') ++y;
      for (tmp=y; *tmp && *tmp!='.'; ++tmp) ;
      if (tmp-y > 63) return -1;
      *x=tmp-y;
      if (!(tmp-y)) break;
      if ((len+=*x+1) > 254) return -1;
      ++x;

      memmove(x,y,tmp-y);
      x+=tmp-y;
      if (!*tmp) {
 *x=0;
 break;
      }
      y=tmp;
    }
    *++x= 0; *++x= type;
    *++x= 0; *++x= class;
    ++x;
    if (x-packet>buflen) return -1;
    memmove(buf,packet,x-packet);
    return x-packet;
  }
}








enum {
  POLLIN = 0x0001,

  POLLPRI = 0x0002,

  POLLOUT = 0x0004,

  POLLERR = 0x0008,

  POLLHUP = 0x0010,

  POLLNVAL = 0x0020,

  POLLRDNORM = 0x0040,

  POLLRDBAND = 0x0080,

  POLLWRBAND = 0x0200,

  POLLMSG = 0x0400,



  POLLREMOVE = 0x1000,

};







struct pollfd {
  int fd;
  short events;
  short revents;
};

typedef unsigned int nfds_t;

 int poll(struct pollfd *ufds, nfds_t nfds, int timeout) ;



static int ppoll(struct pollfd *fds, nfds_t nfds, const struct timespec *timeout, const sigset_t *sigmask) ;









 
      void __dns_make_fd(void);
 int __dns_fd;

 void __dns_make_fd6(void);
 int __dns_fd6;


 void __dns_readstartfiles(void);


static int __dns_plugplay_interface;


static int res_query(const char *dname, int class, int type, unsigned char *answer, int anslen) {
  unsigned char packet[512];
  int size;
  struct pollfd duh[2];




  __dns_readstartfiles();
  if ((size=res_mkquery(
                       ns_o_query
                            ,dname,class,type,0,0,0,(char*)packet,512))<0) { h_errno=
                                                                                     3
                                                                                                ; return -1; }
  {
    {
      int i;
      int j;
      struct timeval last,now;

      struct timeval first;
      static int pnpfd=-1;

      static struct sockaddr_in6 pnpsa6;

      static struct sockaddr_in pnpsa4;
      static int v4pnp=0;
      int islocal=0;

      gettimeofday(&first,0);
      {
 char* x=strchr(dname,'.');
 if (x) {
   if (!memcmp(x,".local",6))
     if (x[6]==0 || (x[6]=='.' && x[7]==0))
       islocal=1;
 } else
   islocal=1;
      }
      if (islocal) {
 if (pnpfd<0) {
   pnpfd=socket(
               10
                       ,
                        1
                                  ,
                                   IPPROTO_UDP
                                              );
   if (pnpfd==-1 && errno==
                          124
                                      ) {
     pnpfd=socket(
                 2
                        ,
                         1
                                   ,
                                    IPPROTO_UDP
                                               );
     v4pnp=1;
   }
   if (pnpfd>=0) {
     int one=1;
     fcntl(pnpfd,
                2
                       ,
                        1
                                  );
     if (!v4pnp)
       setsockopt(pnpfd,
                       IPPROTO_IPV6
                                   ,
                                    8
                                                 ,&one,sizeof one);
     setsockopt(pnpfd,
                     0
                           ,
                            12
                                      ,&one,sizeof one);
     setsockopt(pnpfd,
                     0
                           ,
                            8
                                      ,&one,sizeof one);
   }
 }

 if (!v4pnp) {
   memset(&pnpsa6,0,sizeof(pnpsa6));
   pnpsa6.sin6_family=
                     10
                             ;
   if (pnpfd!=-1) bind(pnpfd,(struct sockaddr*)&pnpsa6,sizeof(pnpsa6));
   pnpsa6.sin6_port=htons(5353);
   memcpy(&pnpsa6.sin6_addr,"\xff\x02\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xfb",16);
 }

 memset(&pnpsa4,0,sizeof(pnpsa4));
 pnpsa4.sin_family=
                  2
                         ;
 if (pnpfd!=-1) bind(pnpfd,(struct sockaddr*)&pnpsa4,sizeof(pnpsa4));
 pnpsa4.sin_port=htons(5353);
 memcpy(&pnpsa4.sin_addr,"\xe0\x00\x00\xfb",4);

 duh[1].events=
              POLLIN
                    ;
 duh[1].fd=pnpfd;
      } else {
 duh[1].fd=-1;
 duh[1].events=0;
      }


      i=0;
      duh[0].events=
                   POLLIN
                         ;
      duh[0].fd=0;
      last.tv_sec=0;

      if (duh[1].fd!=-1) {
 packet[2]=0;

 packet[size-2]=0x80;
 sendto(pnpfd,packet,size,0,(struct sockaddr*)(&pnpsa4),sizeof(pnpsa4));
 if (!v4pnp)
   sendto(pnpfd,packet,size,0,(struct sockaddr*)(&pnpsa6),sizeof(pnpsa6));
 packet[size-2]=0;


 pnpsa4.sin_port=htons(5355);
 memcpy(&pnpsa4.sin_addr,"\xe0\x00\x00\xfc",4);
 pnpsa6.sin6_port=htons(5355);
 memcpy(&pnpsa6.sin6_addr,"\xff\x02\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x03",16);
 sendto(pnpfd,packet,size,0,(struct sockaddr*)(&pnpsa4),sizeof(pnpsa4));
 if (!v4pnp)
   sendto(pnpfd,packet,size,0,(struct sockaddr*)(&pnpsa6),sizeof(pnpsa6));

 packet[2]=1;
      }


      for (j=20; j>0; --j) {
 gettimeofday(&now,0);
 if (now.tv_sec-last.tv_sec>10) {

   int tmpfd;
   struct sockaddr* s=(struct sockaddr*)&(_res.nsaddr_list[i]);
   if (s->sa_family==
                    10
                            ) {
     __dns_make_fd6();
     tmpfd=__dns_fd6;
   } else {
     __dns_make_fd();
     tmpfd=__dns_fd;
   }

   if (duh[0].fd!=-1) {

   duh[0].fd=tmpfd;
   if (sendto(tmpfd,packet,size,0,s,sizeof(struct sockaddr_in6))!=-1)
     gettimeofday(&last,0);
   else
     goto nxdomain;

   }






   last=now;
 }
 if (++i >= _res.nscount) i=0;

 if (now.tv_sec>first.tv_sec && duh[0].fd==-1) goto nxdomain;
 if (duh[0].fd==-1 && duh[1].fd==-1) goto nxdomain;
 duh[0].revents=0;
 if (poll(duh[0].fd==-1?duh+1:duh,duh[0].fd==-1?1:2,1000) > 0) {




   unsigned char inpkg[1500];

   int len;
   struct msghdr mh;
   struct iovec iv;
   char abuf[100];
   struct cmsghdr* x;
   int ttl=0;
   int fd;
   struct sockaddr_in6 tmpsa;
   mh.msg_name=&tmpsa;
   mh.msg_namelen=sizeof(tmpsa);
   mh.msg_iov=&iv;
   mh.msg_iovlen=1;
   iv.iov_base=inpkg;
   iv.iov_len=sizeof(inpkg);
   mh.msg_control=abuf;
   mh.msg_controllen=sizeof(abuf);
   __dns_plugplay_interface=0;
   len=recvmsg(fd=(duh[0].revents&
                                 POLLIN
                                       ?duh[0].fd:duh[1].fd),&mh,
                                                                 0x40
                                                                             );
   if (fd==duh[1].fd) {
     unsigned short peerport;
     if (tmpsa.sin6_family==
                           10
                                   ) {
       __dns_plugplay_interface=tmpsa.sin6_scope_id;
       peerport=tmpsa.sin6_port;
     } else {
       peerport=((struct sockaddr_in*)&tmpsa)->sin_port;
     }
     for (x=
           (((
           &mh
           )->msg_controllen) >= sizeof(struct cmsghdr) ? (struct cmsghdr *)((
           &mh
           )->msg_control) : (struct cmsghdr *)(void*)0)
                             ; x; x=
                                    cmsg_nxthdr((
                                    &mh
                                    ), (
                                    x
                                    ))
                                                      )
       if ((x->cmsg_level==
                          0 
                                 && x->cmsg_type==
                                                  2
                                                        ) ||
    (x->cmsg_level==
                   IPPROTO_IPV6 
                                && x->cmsg_type==
                                                 8
                                                              )) {
  ttl=*(int*)
            ((void *)((char *)(
            x
            ) + ( ((sizeof(struct cmsghdr))+sizeof(long)-1) & ~(sizeof(long)-1) )))
                        ;
  break;
       } else if ((x->cmsg_level==
                                 0 
                                        && x->cmsg_type==
                                                         8
                                                                   ))
  __dns_plugplay_interface=((struct in_pktinfo*)(
                                                ((void *)((char *)(
                                                x
                                                ) + ( ((sizeof(struct cmsghdr))+sizeof(long)-1) & ~(sizeof(long)-1) )))
                                                            ))->ipi_ifindex;

     if ((peerport==5353 && ttl != 255) || (peerport==5355 && ttl != 1))




       continue;

     inpkg[2]=(inpkg[2]&~0x1) | (packet[2]&0x1);
   }




   if (inpkg[0]!=packet[0] || inpkg[1]!=packet[1]) continue;
   if ((inpkg[2]&0xf9) != (_res.options&
                                       0x00000040
                                                  ?0x81:0x80)) continue;
   if ((inpkg[3]&0x0f) != 0) {


     if (duh[0].revents&
                       POLLIN
                             ) {
       duh[0].fd=-1;
       if (duh[1].fd!=-1) {
  if (j>10) j=10;
  continue;
       }
     } else
       continue;


nxdomain:
     h_errno=
            1
                          ;
     return -1;
   }
   if (len>anslen) {
     h_errno=
            3
                       ;
     return -1;
   }
   memcpy(answer,inpkg,len);
   return len;
 }

      }
    }

    if (duh[1].fd==-1)
      goto nxdomain;

  }
  h_errno=
         2
                  ;
  return -1;
}
 int __dns_search;
 char *__dns_domains[];

static int res_search(const char *dname, int class, int type, unsigned char *answer, int anslen) {
  const char *tmp=dname;
  char Buf[
          1025
                  +1];
  int res;
  int len=strlen(dname);
  int count=0;
  memmove(Buf,dname,len);
  Buf[len]=Buf[
              1025
                      ]=0;

  while ((res=res_query(tmp,class,type,answer,anslen))<0) {
    if (count==__dns_search) break;
    Buf[len]='.';

    memccpy(Buf+len+1,__dns_domains[count],0,
                                            1025
                                                    -len-1);
    tmp=Buf;
    ++count;
  }
  return res;
}








struct state {
  const char* buffirst;
  size_t buflen;
  size_t cur;
};


static void __prepare_parse(const char* filename,struct state* s);

static void __fprepare_parse(int fd, struct state* s);

static void __end_parse(struct state* s);



static size_t __parse(struct state* s,int (*pred)(int ch));

static size_t __parse_ws(struct state* s);
static size_t __parse_nws(struct state* s);
static size_t __parse_1(struct state* s,char c) __attribute__((__pure__));

static size_t scan_ulong(const char* s,unsigned long* l);

static size_t scan_ulong(const char* s,unsigned long* l) {
  size_t n;
  unsigned long x;
  unsigned int digit;
  for (x=n=0; (digit=(s[n]-'0'))<10u; ++n)
    x=x*10+digit;
  *l=x;
  return n;
}




static int scandir(const char *dir, struct dirent ***namelist,
     int (*select)(const struct dirent *),
     int (*compar)(const struct dirent **, const struct dirent **)) {
  DIR* d;
  struct dirent *D;
  size_t num=0;
  if (!(d=opendir(dir)))
    return -1;
  *namelist=0;
  while ((D=readdir(d))) {
    if (select==0 || select(D)) {
      struct dirent **tmp;

      if (!(tmp=reallocarray(*namelist,(num+1),sizeof(struct dirent*))) ||
   !(tmp[num]=malloc(sizeof(struct dirent)))) {
 size_t i;
 for (i=0; i<num; ++i) free((*namelist)[i]);
 free(*namelist);
 closedir(d);
 return -1;
      }
      memccpy(tmp[num]->d_name,D->d_name,0,
                                          255
                                                  );
      tmp[num]->d_off=D->d_off;
      tmp[num]->d_reclen=D->d_reclen;
      ++num;
      *namelist=tmp;

    }
  }
  closedir(d);
  if (compar)
    qsort(*namelist,num,sizeof(struct dirent*),(int (*)(const void*,const void*))(compar));
  return num;
}




static int scandir64(const char *dir, struct dirent64 ***namelist,
     int (*select)(const struct dirent64 *),
     int (*compar)(const struct dirent64 **, const struct dirent64 **)) {
  DIR* d;
  struct dirent64 *D;
  size_t num=0;
  if (!(d=opendir(dir)))
    return -1;
  *namelist=0;
  while ((D=readdir64(d))) {
    if (select==0 || select(D)) {
      struct dirent64 **tmp;
      ++num;

      if (!(tmp=reallocarray(*namelist,num,sizeof(struct dirent64*))) ||
   !(tmp[num-1]=malloc(sizeof(struct dirent64)))) {
 size_t i;
 for (i=0; i<num-1; ++i) free(tmp[i]);
 free(*namelist);
 closedir(d);
 return -1;
      }
      memccpy(tmp[num-1]->d_name,D->d_name,0,
                                            255
                                                    );
      tmp[num-1]->d_off=D->d_off;
      tmp[num-1]->d_reclen=D->d_reclen;
      tmp[num-1]->d_type=D->d_type;
      *namelist=tmp;

    }
  }
  closedir(d);
  if (compar)
    qsort(*namelist,num,sizeof(struct dirent64*),(int (*)(const void*,const void*))(compar));
  return num;
}




static int setegid(gid_t gid);
static int setegid(gid_t gid) {
  return setregid((gid_t)-1,gid);
}

asm (".section .gnu.warning." "setegid" "\n\t.string \"" "warning: you used setegid without including <unistd.h>" "\"\n\t.previous");




static int seteuid(uid_t uid);
static int seteuid(uid_t uid) {
  return setreuid((uid_t)-1,uid);
}

asm (".section .gnu.warning." "setegid" "\n\t.string \"" "warning: you used setegid without including <unistd.h>" "\"\n\t.previous");





static char *setlocale (int category, const char *locale) {
  lc_ctype=CT_8BIT;
  if (locale && (category==
                          LC_ALL 
                                 || category==
                                              LC_CTYPE
                                                      )) {
    if (!*locale) {
      const char* x;
      x=getenv("LC_CTYPE");
      if (!x) x=getenv("LC_ALL");
      if (!x) x="C";
      locale=x;
    }
  }
  if (locale) {
    if (strstr(locale,".UTF-8") || strstr(locale,".UTF8")) lc_ctype=CT_UTF8;
    if (locale[0]!='C' || locale[1]) return 0;
  }
  return "C";
}


struct spwd __shadow_pw;
static char __shadow_buf[1000];



 const char __sys_err_unknown[];

static int strerror_r(int errnum, char *buf, size_t n) {
  const char* x=
               strerror
                       (errnum);
  if (x==__sys_err_unknown || n<1) return -1;
  strncpy(buf,
             strerror
                     (errnum),n);
  buf[n-1]=0;
  return 0;
}
 int __sc_nr_cpus();

static long physpages() {
  int fd=open("/proc/meminfo",
                             0x0000
                                     );
  char buf[2048];
  size_t l;
  if (fd==-1) { errno=
                     89
                           ; return -1; }
  l=read(fd,buf,sizeof(buf));
  if (l!=(size_t)-1) {
    char* c;
    buf[l]=0;
    c=strstr(buf,"\nMemTotal:");
    if (c) {
      c+=10; while (*c==' ' || *c=='\t') ++c;
      l=0;
      while (*c>='0' && *c<='9') {
 l=l*10+*c-'0';
 ++c;
      }
    }
  }
  close(fd);
  return l*1024;
}

static long sysconf(int name)
{
  switch(name)
  {
  case 
      4
                  :
    {
      struct rlimit limit;
      getrlimit(
               5
                            , &limit);
      return limit.rlim_cur;
    }
  case 
      1
                 :



    return 100;


  case 
      5
                  :



    return 4096;


  case 
      7
                    :
    return physpages();

  case 
      2
                 :
    return 
          131072
                 ;

  case 
      3
                     :
    return 
          32
                     ;

  case 
      6
                          :
    {
      cpu_set_t m;
      if (sched_getaffinity(0, sizeof(m), &m))
 return __sc_nr_cpus();
      return CPU_COUNT(&m);
    }

  }
  errno=
       89
             ;
  return -1;
}
static int __sc_nr_cpus(void);
static int __sc_nr_cpus() {



  int fd;
  fd = open("/proc/cpuinfo", 
                            0x0000
                                    );
  if (fd==-1) return 1;
  else {
    int n,nr=0;
    char buf[2048];

    while((n=read(fd,buf,sizeof(buf)))>0) {
      register int i=0;
      while (i<n) {
 if ((buf[i]=='p')&&(!memcmp(buf+i,"processor",9))) {
   ++nr;
   i+=9;
 }

 while(i<n && buf[i++]!='\n');
      }
    }
    close(fd);
    return nr;
  }

}

static asm (".section .gnu.warning." "tempnam" "\n\t.string \"" "\e[1;33;41m>>> tempnam stinks! NEVER ! NEVER USE IT ! <<<\e[0m" "\"\n\t.previous");;

static char* tempnam(char* dir,char* template) {
  char buf[1024];
  int len=sizeof(buf)-2,fd;
  buf[len]=0;
  if ((dir)&&(*dir)) {
    char* c=memccpy(buf,dir,0,len);
    if (!c) return 0;
    memcpy(c-1,"/",2);
  }
  else
    strncpy(buf,"/tmp/",len);
  len=(sizeof(buf)-1)-strlen(buf);
  if (len<1) return 0;
  if (template)
    strncat(buf,template, --len);
  else
    strncat(buf,"temp_", --len);
  len=(sizeof(buf)-1)-strlen(buf);
  strncat(buf,"XXXXXX",len);
  if ((fd=mkstemp(buf))<0) return 0;
  close(fd);
  unlink(buf);
  return strdup(buf);
}




static char* dom;

static char* textdomain(const char* domainname) {
  if (dom) free(dom);
  if (!(dom=strdup(domainname))) return 0;
  return dom;
}









 int rand_i(void) 
                       
                              ;

static asm (".section .gnu.warning." "tmpnam" "\n\t.string \"" "\e[1;33;41m>>> tmpnam stinks! NEVER ! NEVER USE IT ! <<<\e[0m" "\"\n\t.previous");;

static char* tmpnam(char* s) {
  static char buf[100];
  char *tmp;
  if (s) tmp=s; else tmp=buf;
  strcpy(tmp,"/tmp/temp_");
  for (;;) {
    struct stat ss;
    int i,j;
    i=rand_i();
    for (j=0; j<8; ++j) {
      char c=i&0xf;
      tmp[9+j]=c>9?c+'a'-10:c+'0';
      i>>=4;
    }
    tmp[17]=0;
    if (lstat(tmp,&ss)==-1 && errno==
                                    2
                                          ) break;
  }
  return tmp;
}











typedef struct {
  uint32_t state[4];
  uint32_t count[2];
  uint8_t buffer[64];
} MD5_CTX;

static void MD5Init(MD5_CTX* ctx);
static void MD5Update(MD5_CTX* ctx, const uint8_t* buf, size_t len);
static void MD5Final(uint8_t digest[16], MD5_CTX* ctx);

static char* md5crypt(const char* pw, const char* salt);





static const char IP[] = {
  57,49,41,33,25,17, 9, 1,
  59,51,43,35,27,19,11, 3,
  61,53,45,37,29,21,13, 5,
  63,55,47,39,31,23,15, 7,
  56,48,40,32,24,16, 8, 0,
  58,50,42,34,26,18,10, 2,
  60,52,44,36,28,20,12, 4,
  62,54,46,38,30,22,14, 6
};


static const char FP[] = {
  39, 7,47,15,55,23,63,31,
  38, 6,46,14,54,22,62,30,
  37, 5,45,13,53,21,61,29,
  36, 4,44,12,52,20,60,28,
  35, 3,43,11,51,19,59,27,
  34, 2,42,10,50,18,58,26,
  33, 1,41, 9,49,17,57,25,
  32, 0,40, 8,48,16,56,24
};




static const char PC1_C[] = {
  56,48,40,32,24,16, 8,
   0,57,49,41,33,25,17,
   9, 1,58,50,42,34,26,
  18,10, 2,59,51,43,35
};

static const char PC1_D[] = {
  62,54,46,38,30,22,14,
   6,61,53,45,37,29,21,
  13, 5,60,52,44,36,28,
  20,12, 4,27,19,11, 3
};


static const char shifts[] = { 1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1 };





static const char PC2_C[] = {
  13, 16, 10, 23, 0, 4, 2, 27, 14, 5, 20, 9,
  22, 18, 11, 3, 25, 7, 15, 6, 26, 19, 12, 1
};

static const char PC2_D[] = {
  12, 23, 2, 8, 18, 26, 1, 11, 22, 16, 4, 19,
  15, 20, 10, 27, 5, 24, 17, 13, 21, 7, 0, 3
};



static char 0xB[28];
static char D[28];

static char KS[16][48];


static char E[48];
static const char e2[] = {
  32, 1, 2, 3, 4, 5, 4, 5, 6, 7, 8, 9,
   8, 9, 10, 11, 12, 13, 12, 13, 14, 15, 16, 17,
  16, 17, 18, 19, 20, 21, 20, 21, 22, 23, 24, 25,
  24, 25, 26, 27, 28, 29, 28, 29, 30, 31, 32, 1
};


static void setkey(const char *key)
{
  register int i, j, k;
  int t;
  int s;




  for(i=0; i < 28; i++) {
    0xB[i] = key[(int)PC1_C[i]];
    D[i] = key[(int)PC1_D[i]];
  }



  for(i=0; i < 16; i++) {

    s = shifts[i];
    for(k=0; k < s; k++) {
      t = 0xB[0];
      for(j=0; j < 27; j++)
 0xB[j] = 0xB[j+1];
      0xB[27] = t;
      t = D[0];
      for(j=0; j < 27; j++)
 D[j] = D[j+1];
      D[27] = t;
    }

    for(j=0; j < 24; j++) {
      KS[i][j] = 0xB[(int)PC2_C[j]];
      KS[i][j+24] = D[(int)PC2_D[j]];
    }
  }

  for(i=0; i < 48; i++)
    E[i] = e2[i];
}




static const char S[8][64] = {
  {
    14, 4,13, 1, 2,15,11, 8, 3,10, 6,12, 5, 9, 0, 7,
     0,15, 7, 4,14, 2,13, 1,10, 6,12,11, 9, 5, 3, 8,
     4, 1,14, 8,13, 6, 2,11,15,12, 9, 7, 3,10, 5, 0,
    15,12, 8, 2, 4, 9, 1, 7, 5,11, 3,14,10, 0, 6,13
  },

  {
    15, 1, 8,14, 6,11, 3, 4, 9, 7, 2,13,12, 0, 5,10,
     3,13, 4, 7,15, 2, 8,14,12, 0, 1,10, 6, 9,11, 5,
     0,14, 7,11,10, 4,13, 1, 5, 8,12, 6, 9, 3, 2,15,
    13, 8,10, 1, 3,15, 4, 2,11, 6, 7,12, 0, 5,14, 9
  },

  {
    10, 0, 9,14, 6, 3,15, 5, 1,13,12, 7,11, 4, 2, 8,
    13, 7, 0, 9, 3, 4, 6,10, 2, 8, 5,14,12,11,15, 1,
    13, 6, 4, 9, 8,15, 3, 0,11, 1, 2,12, 5,10,14, 7,
     1,10,13, 0, 6, 9, 8, 7, 4,15,14, 3,11, 5, 2,12
  },

  {
     7,13,14, 3, 0, 6, 9,10, 1, 2, 8, 5,11,12, 4,15,
    13, 8,11, 5, 6,15, 0, 3, 4, 7, 2,12, 1,10,14, 9,
    10, 6, 9, 0,12,11, 7,13,15, 1, 3,14, 5, 2, 8, 4,
     3,15, 0, 6,10, 1,13, 8, 9, 4, 5,11,12, 7, 2,14
  },

  {
     2,12, 4, 1, 7,10,11, 6, 8, 5, 3,15,13, 0,14, 9,
    14,11, 2,12, 4, 7,13, 1, 5, 0,15,10, 3, 9, 8, 6,
     4, 2, 1,11,10,13, 7, 8,15, 9,12, 5, 6, 3, 0,14,
    11, 8,12, 7, 1,14, 2,13, 6,15, 0, 9,10, 4, 5, 3
  },

  {
    12, 1,10,15, 9, 2, 6, 8, 0,13, 3, 4,14, 7, 5,11,
    10,15, 4, 2, 7,12, 9, 5, 6, 1,13,14, 0,11, 3, 8,
     9,14,15, 5, 2, 8,12, 3, 7, 0, 4,10, 1,13,11, 6,
     4, 3, 2,12, 9, 5,15,10,11,14, 1, 7, 6, 0, 8,13
  },

  {
     4,11, 2,14,15, 0, 8,13, 3,12, 9, 7, 5,10, 6, 1,
    13, 0,11, 7, 4, 9, 1,10,14, 3, 5,12, 2,15, 8, 6,
     1, 4,11,13,12, 3, 7,14,10,15, 6, 8, 0, 5, 9, 2,
     6,11,13, 8, 1, 4,10, 7, 9, 5, 0,15,14, 2, 3,12
  },

  {
    13, 2, 8, 4, 6,15,11, 1,10, 9, 3,14, 5, 0,12, 7,
     1,15,13, 8,10, 3, 7, 4,12, 5, 6,11, 0,14, 9, 2,
     7,11, 4, 1, 9,12,14, 2, 0, 6,10,13,15, 3, 5, 8,
     2, 1,14, 7, 4,10, 8,13,15,12, 9, 0, 3, 5, 6,11
  }
};


static const char P[] = {
  15, 6,19,20, 28,11,27,16, 0,14,22,25, 4,17,30, 9,
   1, 7,23,13, 31,26, 2, 8, 18,12,29, 5, 21,10, 3,24
};


static char L[64];

static char tempL[32];
static char f[32];


static char preS[48];


static void encrypt(char block[64],int edflag)
{
  int i, ii;
  register int t, j, k;

  (void)edflag;

  for(j=0; j < 64; j++)
    L[j] = block[(int)IP[j]];

  for(ii=0; ii < 16; ii++) {
    i = ii;

    for(j=0; j < 32; j++)
      tempL[j] = (L+32)[j];



    for(j=0; j < 48; j++)
      preS[j] = (L+32)[E[j]-1] ^ KS[i][j];






    for(j=0; j < 8; j++) {
      t = ((j<<1)+j)<<1;
      k = S[j][(preS[t]<<5)+
  (preS[t+1]<<3)+
  (preS[t+2]<<2)+
  (preS[t+3]<<1)+
  (preS[t+4] )+
  (preS[t+5]<<4)];
      t = j << 2;
      f[t ] = (k>>3)&01;
      f[t+1] = (k>>2)&01;
      f[t+2] = (k>>1)&01;
      f[t+3] = (k )&01;
    }

    for(j=0; j < 32; j++)
      (L+32)[j] = L[j] ^ f[(int)P[j]];

    for(j=0; j < 32; j++)
      L[j] = tempL[j];
  }

  for(j=0; j < 32; j++) {
    L[j] ^= (L+32)[j];
    (L+32)[j] ^= L[j];
    L[j] ^= (L+32)[j];
  }

  for(j=0; j < 64; j++)
    block[j] = L[(int)FP[j]];
}

static char * crypt(const char *pw, const char *salt)
{
  register int i, j, c;
  static char block[66], iobuf[16];

  if (salt[0]=='$' && salt[1]=='1' && salt[2]=='$')
    return md5crypt(pw,salt);


  if (salt[0]=='$' && salt[1]=='5' && salt[2]=='$')
    return sha256_crypt(pw,salt);


  if (salt[0]=='$' && salt[1]=='6' && salt[2]=='$')
    return sha512_crypt(pw,salt);

  for(i=0; i < 66; i++)
    block[i] = 0;
  for(i=0; (c= *pw) && i < 64; pw++) {
    for(j=0; j < 7; j++, i++)
      block[i] = (c>>(6-j)) & 01;
    i++;
  }

  setkey(block);

  for(i=0; i < 66; i++)
    block[i] = 0;

  for(i=0; i < 2; i++) {
    c = *salt++;
    iobuf[i] = c;
    if(c > 'Z')
      c -= 6;
    if(c > '9')
      c -= 7;
    c -= '.';
    for(j=0; j < 6; j++) {
      if((c>>j) & 01) {
 int ind1 = (((i<<1)+i)<< 1) + j;
 int ind2 = ind1 + 24;
 E[ind1] ^= E[ind2];
 E[ind2] ^= E[ind1];
 E[ind1] ^= E[ind2];
      }
    }
  }

  for(i=0; i < 25; i++)
    encrypt(block,0);

  for(i=0; i < 11; i++) {
    c = 0;
    for(j=0; j < 6; j++) {
      c <<= 1;
      c |= block[(((i<<1)+i)<<1)+j];
    }
    c += '.';
    if(c > '9')
      c += 7;
    if(c > 'Z')
      c += 6;
    iobuf[i+2] = c;
  }
  iobuf[i+2] = 0;
  if(iobuf[1] == 0)
    iobuf[1] = iobuf[0];
  return(iobuf);
}
static void CopyToLittleEndian (uint32_t *dst, const uint8_t *src, int length) {
  while (length--) {
    *dst=(((uint32_t)src[3])<<24) |
  (((uint32_t)src[2])<<16) |
  (((uint32_t)src[1])<< 8) |
    (uint32_t)src[0];
    src+=4;
    dst++;
  }
}
static void MD5Init (MD5_CTX* context) {
   context->count[0] = 0;
   context->count[1] = 0;

   context->state[0] = 0x67452301;
   context->state[1] = 0xefcdab89;
   context->state[2] = 0x98badcfe;
   context->state[3] = 0x10325476;
}
static void __MD5Transform (uint32_t state[4], const uint8_t *in, int repeat) {
   const uint32_t *x;

   uint32_t a = state[0];
   uint32_t b = state[1];
   uint32_t c = state[2];
   uint32_t d = state[3];

   for ( ; repeat; repeat--) {
      uint32_t tempBuffer[16];


      CopyToLittleEndian (tempBuffer, in, 16);
      x = tempBuffer;
      { (a) += (d ^ (b & (c ^ d))) + (x[ 0]) + (uint32_t)(0xd76aa478); (a) = ((a << 7) | (a >> (32-7))); (a) += (b); };
      { (d) += (c ^ (a & (b ^ c))) + (x[ 1]) + (uint32_t)(0xe8c7b756); (d) = ((d << 12) | (d >> (32-12))); (d) += (a); };
      { (c) += (b ^ (d & (a ^ b))) + (x[ 2]) + (uint32_t)(0x242070db); (c) = ((c << 17) | (c >> (32-17))); (c) += (d); };
      { (b) += (a ^ (c & (d ^ a))) + (x[ 3]) + (uint32_t)(0xc1bdceee); (b) = ((b << 22) | (b >> (32-22))); (b) += (c); };
      { (a) += (d ^ (b & (c ^ d))) + (x[ 4]) + (uint32_t)(0xf57c0faf); (a) = ((a << 7) | (a >> (32-7))); (a) += (b); };
      { (d) += (c ^ (a & (b ^ c))) + (x[ 5]) + (uint32_t)(0x4787c62a); (d) = ((d << 12) | (d >> (32-12))); (d) += (a); };
      { (c) += (b ^ (d & (a ^ b))) + (x[ 6]) + (uint32_t)(0xa8304613); (c) = ((c << 17) | (c >> (32-17))); (c) += (d); };
      { (b) += (a ^ (c & (d ^ a))) + (x[ 7]) + (uint32_t)(0xfd469501); (b) = ((b << 22) | (b >> (32-22))); (b) += (c); };
      { (a) += (d ^ (b & (c ^ d))) + (x[ 8]) + (uint32_t)(0x698098d8); (a) = ((a << 7) | (a >> (32-7))); (a) += (b); };
      { (d) += (c ^ (a & (b ^ c))) + (x[ 9]) + (uint32_t)(0x8b44f7af); (d) = ((d << 12) | (d >> (32-12))); (d) += (a); };
      { (c) += (b ^ (d & (a ^ b))) + (x[10]) + (uint32_t)(0xffff5bb1); (c) = ((c << 17) | (c >> (32-17))); (c) += (d); };
      { (b) += (a ^ (c & (d ^ a))) + (x[11]) + (uint32_t)(0x895cd7be); (b) = ((b << 22) | (b >> (32-22))); (b) += (c); };
      { (a) += (d ^ (b & (c ^ d))) + (x[12]) + (uint32_t)(0x6b901122); (a) = ((a << 7) | (a >> (32-7))); (a) += (b); };
      { (d) += (c ^ (a & (b ^ c))) + (x[13]) + (uint32_t)(0xfd987193); (d) = ((d << 12) | (d >> (32-12))); (d) += (a); };
      { (c) += (b ^ (d & (a ^ b))) + (x[14]) + (uint32_t)(0xa679438e); (c) = ((c << 17) | (c >> (32-17))); (c) += (d); };
      { (b) += (a ^ (c & (d ^ a))) + (x[15]) + (uint32_t)(0x49b40821); (b) = ((b << 22) | (b >> (32-22))); (b) += (c); };

      { (a) += (c ^ (d & (b ^ c))) + (x[ 1]) + (uint32_t)(0xf61e2562); (a) = ((a << 5) | (a >> (32-5))); (a) += (b); };
      { (d) += (b ^ (c & (a ^ b))) + (x[ 6]) + (uint32_t)(0xc040b340); (d) = ((d << 9) | (d >> (32-9))); (d) += (a); };
      { (c) += (a ^ (b & (d ^ a))) + (x[11]) + (uint32_t)(0x265e5a51); (c) = ((c << 14) | (c >> (32-14))); (c) += (d); };
      { (b) += (d ^ (a & (c ^ d))) + (x[ 0]) + (uint32_t)(0xe9b6c7aa); (b) = ((b << 20) | (b >> (32-20))); (b) += (c); };
      { (a) += (c ^ (d & (b ^ c))) + (x[ 5]) + (uint32_t)(0xd62f105d); (a) = ((a << 5) | (a >> (32-5))); (a) += (b); };
      { (d) += (b ^ (c & (a ^ b))) + (x[10]) + (uint32_t)(0x02441453); (d) = ((d << 9) | (d >> (32-9))); (d) += (a); };
      { (c) += (a ^ (b & (d ^ a))) + (x[15]) + (uint32_t)(0xd8a1e681); (c) = ((c << 14) | (c >> (32-14))); (c) += (d); };
      { (b) += (d ^ (a & (c ^ d))) + (x[ 4]) + (uint32_t)(0xe7d3fbc8); (b) = ((b << 20) | (b >> (32-20))); (b) += (c); };
      { (a) += (c ^ (d & (b ^ c))) + (x[ 9]) + (uint32_t)(0x21e1cde6); (a) = ((a << 5) | (a >> (32-5))); (a) += (b); };
      { (d) += (b ^ (c & (a ^ b))) + (x[14]) + (uint32_t)(0xc33707d6); (d) = ((d << 9) | (d >> (32-9))); (d) += (a); };
      { (c) += (a ^ (b & (d ^ a))) + (x[ 3]) + (uint32_t)(0xf4d50d87); (c) = ((c << 14) | (c >> (32-14))); (c) += (d); };
      { (b) += (d ^ (a & (c ^ d))) + (x[ 8]) + (uint32_t)(0x455a14ed); (b) = ((b << 20) | (b >> (32-20))); (b) += (c); };
      { (a) += (c ^ (d & (b ^ c))) + (x[13]) + (uint32_t)(0xa9e3e905); (a) = ((a << 5) | (a >> (32-5))); (a) += (b); };
      { (d) += (b ^ (c & (a ^ b))) + (x[ 2]) + (uint32_t)(0xfcefa3f8); (d) = ((d << 9) | (d >> (32-9))); (d) += (a); };
      { (c) += (a ^ (b & (d ^ a))) + (x[ 7]) + (uint32_t)(0x676f02d9); (c) = ((c << 14) | (c >> (32-14))); (c) += (d); };
      { (b) += (d ^ (a & (c ^ d))) + (x[12]) + (uint32_t)(0x8d2a4c8a); (b) = ((b << 20) | (b >> (32-20))); (b) += (c); };

      { (a) += (b ^ c ^ d) + (x[ 5]) + (uint32_t)(0xfffa3942); (a) = ((a << 4) | (a >> (32-4))); (a) += (b); };
      { (d) += (a ^ b ^ c) + (x[ 8]) + (uint32_t)(0x8771f681); (d) = ((d << 11) | (d >> (32-11))); (d) += (a); };
      { (c) += (d ^ a ^ b) + (x[11]) + (uint32_t)(0x6d9d6122); (c) = ((c << 16) | (c >> (32-16))); (c) += (d); };
      { (b) += (c ^ d ^ a) + (x[14]) + (uint32_t)(0xfde5380c); (b) = ((b << 23) | (b >> (32-23))); (b) += (c); };
      { (a) += (b ^ c ^ d) + (x[ 1]) + (uint32_t)(0xa4beea44); (a) = ((a << 4) | (a >> (32-4))); (a) += (b); };
      { (d) += (a ^ b ^ c) + (x[ 4]) + (uint32_t)(0x4bdecfa9); (d) = ((d << 11) | (d >> (32-11))); (d) += (a); };
      { (c) += (d ^ a ^ b) + (x[ 7]) + (uint32_t)(0xf6bb4b60); (c) = ((c << 16) | (c >> (32-16))); (c) += (d); };
      { (b) += (c ^ d ^ a) + (x[10]) + (uint32_t)(0xbebfbc70); (b) = ((b << 23) | (b >> (32-23))); (b) += (c); };
      { (a) += (b ^ c ^ d) + (x[13]) + (uint32_t)(0x289b7ec6); (a) = ((a << 4) | (a >> (32-4))); (a) += (b); };
      { (d) += (a ^ b ^ c) + (x[ 0]) + (uint32_t)(0xeaa127fa); (d) = ((d << 11) | (d >> (32-11))); (d) += (a); };
      { (c) += (d ^ a ^ b) + (x[ 3]) + (uint32_t)(0xd4ef3085); (c) = ((c << 16) | (c >> (32-16))); (c) += (d); };
      { (b) += (c ^ d ^ a) + (x[ 6]) + (uint32_t)(0x04881d05); (b) = ((b << 23) | (b >> (32-23))); (b) += (c); };
      { (a) += (b ^ c ^ d) + (x[ 9]) + (uint32_t)(0xd9d4d039); (a) = ((a << 4) | (a >> (32-4))); (a) += (b); };
      { (d) += (a ^ b ^ c) + (x[12]) + (uint32_t)(0xe6db99e5); (d) = ((d << 11) | (d >> (32-11))); (d) += (a); };
      { (c) += (d ^ a ^ b) + (x[15]) + (uint32_t)(0x1fa27cf8); (c) = ((c << 16) | (c >> (32-16))); (c) += (d); };
      { (b) += (c ^ d ^ a) + (x[ 2]) + (uint32_t)(0xc4ac5665); (b) = ((b << 23) | (b >> (32-23))); (b) += (c); };

      { (a) += (c ^ (b | ~d)) + (x[ 0]) + (uint32_t)(0xf4292244); (a) = ((a << 6) | (a >> (32-6))); (a) += (b); };
      { (d) += (b ^ (a | ~c)) + (x[ 7]) + (uint32_t)(0x432aff97); (d) = ((d << 10) | (d >> (32-10))); (d) += (a); };
      { (c) += (a ^ (d | ~b)) + (x[14]) + (uint32_t)(0xab9423a7); (c) = ((c << 15) | (c >> (32-15))); (c) += (d); };
      { (b) += (d ^ (c | ~a)) + (x[ 5]) + (uint32_t)(0xfc93a039); (b) = ((b << 21) | (b >> (32-21))); (b) += (c); };
      { (a) += (c ^ (b | ~d)) + (x[12]) + (uint32_t)(0x655b59c3); (a) = ((a << 6) | (a >> (32-6))); (a) += (b); };
      { (d) += (b ^ (a | ~c)) + (x[ 3]) + (uint32_t)(0x8f0ccc92); (d) = ((d << 10) | (d >> (32-10))); (d) += (a); };
      { (c) += (a ^ (d | ~b)) + (x[10]) + (uint32_t)(0xffeff47d); (c) = ((c << 15) | (c >> (32-15))); (c) += (d); };
      { (b) += (d ^ (c | ~a)) + (x[ 1]) + (uint32_t)(0x85845dd1); (b) = ((b << 21) | (b >> (32-21))); (b) += (c); };
      { (a) += (c ^ (b | ~d)) + (x[ 8]) + (uint32_t)(0x6fa87e4f); (a) = ((a << 6) | (a >> (32-6))); (a) += (b); };
      { (d) += (b ^ (a | ~c)) + (x[15]) + (uint32_t)(0xfe2ce6e0); (d) = ((d << 10) | (d >> (32-10))); (d) += (a); };
      { (c) += (a ^ (d | ~b)) + (x[ 6]) + (uint32_t)(0xa3014314); (c) = ((c << 15) | (c >> (32-15))); (c) += (d); };
      { (b) += (d ^ (c | ~a)) + (x[13]) + (uint32_t)(0x4e0811a1); (b) = ((b << 21) | (b >> (32-21))); (b) += (c); };
      { (a) += (c ^ (b | ~d)) + (x[ 4]) + (uint32_t)(0xf7537e82); (a) = ((a << 6) | (a >> (32-6))); (a) += (b); };
      { (d) += (b ^ (a | ~c)) + (x[11]) + (uint32_t)(0xbd3af235); (d) = ((d << 10) | (d >> (32-10))); (d) += (a); };
      { (c) += (a ^ (d | ~b)) + (x[ 2]) + (uint32_t)(0x2ad7d2bb); (c) = ((c << 15) | (c >> (32-15))); (c) += (d); };
      { (b) += (d ^ (c | ~a)) + (x[ 9]) + (uint32_t)(0xeb86d391); (b) = ((b << 21) | (b >> (32-21))); (b) += (c); };

      state[0] = a = a + state[0];
      state[1] = b = b + state[1];
      state[2] = c = c + state[2];
      state[3] = d = d + state[3];

      in += 64;
   }
}






static void MD5Update (MD5_CTX *context, const uint8_t *input, size_t inputBytes) {
   int i;
   int byteIndex;
   unsigned int partLen;
   int len;


   byteIndex = (context->count[0] >> 3) & 0x3F;


   if ((context->count[0] += inputBytes << 3) < (inputBytes << 3))
      context->count[1]++;
   context->count[1] += (inputBytes >> (32-3));

   partLen = (64 - byteIndex);


   if (inputBytes >= partLen) {
      memcpy (context->buffer + byteIndex, input, partLen);
      __MD5Transform (context->state, (const uint8_t *) context->buffer, 1);
      len = (inputBytes - partLen) / 64;
      __MD5Transform (context->state, &input[partLen], len);
      i = partLen + 64 * len;
      byteIndex = 0;
   } else
      i = 0;


   memcpy (&context->buffer[byteIndex], &input[i], inputBytes - i);
}




static void MD5Final (uint8_t digest[16], MD5_CTX* context) {
   static uint8_t finalBlock[64];

   uint32_t bits[2];
   int byteIndex;
   int finalBlockLength;

   byteIndex = (context->count[0] >> 3) & 0x3F;
   finalBlockLength = ((byteIndex < 56) ? 56 : 120) - byteIndex;
   finalBlock[0] = 0x80;


   CopyToLittleEndian (bits, (const uint8_t *) context->count, 2);




   MD5Update (context, finalBlock, finalBlockLength);
   MD5Update (context, (const uint8_t *) bits, 8);


   CopyToLittleEndian ((uint32_t *) digest, (const uint8_t *) context->state, 4);




   memset(context, 0, sizeof(*context));
}
static unsigned char itoa64[] =
 "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

static void to64 (char *, uint32_t, int);

static void
static to64(s, v, n)
 char *s;
 uint32_t v;
 int n;
{
 while (--n >= 0) {
  *s++ = itoa64[v&0x3f];
  v >>= 6;
 }
}







static char *
static md5crypt(pw, salt)
 register const char *pw;
 register const char *salt;
{




 static unsigned char *magic = (unsigned char *)"$1$";

 static char passwd[120], *p;
 static const unsigned char *sp,*ep;
 unsigned char final[16];
 int sl,pl,i;
 MD5_CTX ctx,ctx1;
 uint32_t l;


 sp = (const unsigned char *)salt;


 if(!strncmp((const char *)sp,(const char *)magic,strlen((const char *)magic)))
  sp += strlen((const char *)magic);


 for(ep=sp;*ep && *ep != '$' && ep < (sp+8);ep++)
  continue;


 sl = ep - sp;

 MD5Init(&ctx);


 MD5Update(&ctx,(const unsigned char *)pw,strlen(pw));


 MD5Update(&ctx,magic,strlen((const char *)magic));


 MD5Update(&ctx,sp,sl);


 MD5Init(&ctx1);
 MD5Update(&ctx1,(const unsigned char *)pw,strlen(pw));
 MD5Update(&ctx1,sp,sl);
 MD5Update(&ctx1,(const unsigned char *)pw,strlen(pw));
 MD5Final(final,&ctx1);
 for(pl = strlen(pw); pl > 0; pl -= 16)
  MD5Update(&ctx,final,pl>16 ? 16 : pl);


 memset(final,0,sizeof final);


 for (i = strlen(pw); i ; i >>= 1)
  if(i&1)
      MD5Update(&ctx, final, 1);
  else
      MD5Update(&ctx, (const unsigned char *)pw, 1);


 strcpy(passwd,(const char *)magic);
 memcpy(passwd+3,sp,sl);
 passwd[sl+3]='$';
 passwd[sl+4]=0;

 MD5Final(final,&ctx);






 for(i=0;i<1000;i++) {
  MD5Init(&ctx1);
  if(i & 1)
   MD5Update(&ctx1,(const unsigned char *)pw,strlen(pw));
  else
   MD5Update(&ctx1,final,16);

  if(i % 3)
   MD5Update(&ctx1,sp,sl);

  if(i % 7)
   MD5Update(&ctx1,(const unsigned char *)pw,strlen(pw));

  if(i & 1)
   MD5Update(&ctx1,final,16);
  else
   MD5Update(&ctx1,(const unsigned char *)pw,strlen(pw));
  MD5Final(final,&ctx1);
 }

 p = passwd + strlen(passwd);

 l = (final[ 0]<<16) | (final[ 6]<<8) | final[12]; to64(p,l,4); p += 4;
 l = (final[ 1]<<16) | (final[ 7]<<8) | final[13]; to64(p,l,4); p += 4;
 l = (final[ 2]<<16) | (final[ 8]<<8) | final[14]; to64(p,l,4); p += 4;
 l = (final[ 3]<<16) | (final[ 9]<<8) | final[15]; to64(p,l,4); p += 4;
 l = (final[ 4]<<16) | (final[10]<<8) | final[ 5]; to64(p,l,4); p += 4;
 l = final[11] ; to64(p,l,2); p += 2;
 *p = '\0';


 memset(final,0,sizeof final);

 return passwd;
}
struct sha256_ctx
{
  uint32_t H[8];

  uint32_t total[2];
  uint32_t buflen;
  char buffer[128];
};
static const unsigned char fillbuf[64] = { 0x80, 0 };



static const uint32_t K[64] =
  {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
    0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
    0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
    0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
    0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
    0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
    0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
    0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
    0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
  };




static void
static sha256_process_block (const void *buffer, size_t len, struct sha256_ctx *ctx)
{
  const uint32_t *words = buffer;
  size_t nwords = len / sizeof (uint32_t);
  uint32_t a = ctx->H[0];
  uint32_t b = ctx->H[1];
  uint32_t c = ctx->H[2];
  uint32_t d = ctx->H[3];
  uint32_t e = ctx->H[4];
  uint32_t f = ctx->H[5];
  uint32_t g = ctx->H[6];
  uint32_t h = ctx->H[7];




  ctx->total[0] += len;
  if (ctx->total[0] < len)
    ++ctx->total[1];



  while (nwords > 0)
    {
      uint32_t W[64];
      uint32_t a_save = a;
      uint32_t b_save = b;
      uint32_t c_save = c;
      uint32_t d_save = d;
      uint32_t e_save = e;
      uint32_t f_save = f;
      uint32_t g_save = g;
      uint32_t h_save = h;

      unsigned int t;
      for (t = 0; t < 16; ++t)
 {
   W[t] = (*words);
   ++words;
 }
      for (t = 16; t < 64; ++t)
 W[t] = (((W[t - 2] >> 17) | (W[t - 2] << (32 - 17))) ^ ((W[t - 2] >> 19) | (W[t - 2] << (32 - 19))) ^ (W[t - 2] >> 10)) + W[t - 7] + (((W[t - 15] >> 7) | (W[t - 15] << (32 - 7))) ^ ((W[t - 15] >> 18) | (W[t - 15] << (32 - 18))) ^ (W[t - 15] >> 3)) + W[t - 16];


      for (t = 0; t < 64; ++t)
 {
   uint32_t T1 = h + (((e >> 6) | (e << (32 - 6))) ^ ((e >> 11) | (e << (32 - 11))) ^ ((e >> 25) | (e << (32 - 25)))) + ((e & f) ^ (~e & g)) + K[t] + W[t];
   uint32_t T2 = (((a >> 2) | (a << (32 - 2))) ^ ((a >> 13) | (a << (32 - 13))) ^ ((a >> 22) | (a << (32 - 22)))) + ((a & b) ^ (a & c) ^ (b & c));
   h = g;
   g = f;
   f = e;
   e = d + T1;
   d = c;
   c = b;
   b = a;
   a = T1 + T2;
 }



      a += a_save;
      b += b_save;
      c += c_save;
      d += d_save;
      e += e_save;
      f += f_save;
      g += g_save;
      h += h_save;


      nwords -= 16;
    }


  ctx->H[0] = a;
  ctx->H[1] = b;
  ctx->H[2] = c;
  ctx->H[3] = d;
  ctx->H[4] = e;
  ctx->H[5] = f;
  ctx->H[6] = g;
  ctx->H[7] = h;
}




static void
static sha256_init_ctx (struct sha256_ctx *ctx)
{
  ctx->H[0] = 0x6a09e667;
  ctx->H[1] = 0xbb67ae85;
  ctx->H[2] = 0x3c6ef372;
  ctx->H[3] = 0xa54ff53a;
  ctx->H[4] = 0x510e527f;
  ctx->H[5] = 0x9b05688c;
  ctx->H[6] = 0x1f83d9ab;
  ctx->H[7] = 0x5be0cd19;

  ctx->total[0] = ctx->total[1] = 0;
  ctx->buflen = 0;
}







static void *
static sha256_finish_ctx (struct sha256_ctx *ctx, void *resbuf)
{

  uint32_t bytes = ctx->buflen;
  size_t pad;
  unsigned int i;


  ctx->total[0] += bytes;
  if (ctx->total[0] < bytes)
    ++ctx->total[1];

  pad = bytes >= 56 ? 64 + 56 - bytes : 56 - bytes;
  memcpy (&ctx->buffer[bytes], fillbuf, pad);


  *(uint32_t *) &ctx->buffer[bytes + pad + 4] = (ctx->total[0] << 3);
  *(uint32_t *) &ctx->buffer[bytes + pad] = ((ctx->total[1] << 3) | (ctx->total[0] >> 29))
                              ;


  sha256_process_block (ctx->buffer, bytes + pad + 8, ctx);


  for (i = 0; i < 8; ++i)
    ((uint32_t *) resbuf)[i] = (ctx->H[i]);

  return resbuf;
}


static void
static sha256_process_bytes (const void *buffer, size_t len, struct sha256_ctx *ctx)
{


  if (ctx->buflen != 0)
    {
      size_t left_over = ctx->buflen;
      size_t add = 128 - left_over > len ? len : 128 - left_over;

      memcpy (&ctx->buffer[left_over], buffer, add);
      ctx->buflen += add;

      if (ctx->buflen > 64)
 {
   sha256_process_block (ctx->buffer, ctx->buflen & ~63, ctx);

   ctx->buflen &= 63;

   memcpy (ctx->buffer, &ctx->buffer[(left_over + add) & ~63],
    ctx->buflen);
 }

      buffer = (const char *) buffer + add;
      len -= add;
    }


  if (len >= 64)
    {







      if ((((uintptr_t) buffer) % __alignof__ (uint32_t) != 0))
 while (len > 64)
   {
     sha256_process_block (memcpy (ctx->buffer, buffer, 64), 64, ctx);
     buffer = (const char *) buffer + 64;
     len -= 64;
   }
      else
 {
   sha256_process_block (buffer, len & ~63, ctx);
   buffer = (const char *) buffer + (len & ~63);
   len &= 63;
 }
    }


  if (len > 0)
    {
      size_t left_over = ctx->buflen;

      memcpy (&ctx->buffer[left_over], buffer, len);
      left_over += len;
      if (left_over >= 64)
 {
   sha256_process_block (ctx->buffer, 64, ctx);
   left_over -= 64;
   memcpy (ctx->buffer, &ctx->buffer[64], left_over);
 }
      ctx->buflen = left_over;
    }
}




static const char sha256_salt_prefix[] = "$5$";


static const char sha256_rounds_prefix[] = "rounds=";
static const char b64t[64] =
static "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";


static char *
static sha256_crypt_r (const char *key, const char *salt, char *buffer, int buflen)
{
  unsigned char alt_result[32]
    __attribute__ ((__aligned__ (__alignof__ (uint32_t))));
  unsigned char temp_result[32]
    __attribute__ ((__aligned__ (__alignof__ (uint32_t))));
  struct sha256_ctx ctx;
  struct sha256_ctx alt_ctx;
  size_t salt_len;
  size_t key_len;
  size_t cnt;
  char *cp;
  char *copied_key = 
                    (void*)0
                        ;
  char *copied_salt = 
                     (void*)0
                         ;
  char *p_bytes;
  char *s_bytes;

  size_t rounds = 5000;
  
 _Bool 
      rounds_custom = 
                      0
                           ;



  if (strncmp (sha256_salt_prefix, salt, sizeof (sha256_salt_prefix) - 1) == 0)

    salt += sizeof (sha256_salt_prefix) - 1;

  if (strncmp (salt, sha256_rounds_prefix, sizeof (sha256_rounds_prefix) - 1)
      == 0)
    {
      const char *num = salt + sizeof (sha256_rounds_prefix) - 1;
      char *endp;
      unsigned long int srounds = strtoul (num, &endp, 10);
      if (*endp == '$')
 {
   salt = endp + 1;
   rounds = 
           (((
           1000
           )>((((
           srounds
           )<(
           999999999
           ))?(
           srounds
           ):(
           999999999
           ))))?(
           1000
           ):((((
           srounds
           )<(
           999999999
           ))?(
           srounds
           ):(
           999999999
           ))))
                                                      ;
   rounds_custom = 
                  1
                      ;
 }
    }

  salt_len = 
            (((
            strcspn (salt, "$")
            )<(
            16
            ))?(
            strcspn (salt, "$")
            ):(
            16
            ))
                                                   ;
  key_len = strlen (key);

  if ((key - (char *) 0) % __alignof__ (uint32_t) != 0)
    {
      char *tmp = (char *) 
                          __builtin_alloca(
                          key_len + __alignof__ (uint32_t)
                          )
                                                                   ;
      key = copied_key =
 memcpy (tmp + __alignof__ (uint32_t)
  - (tmp - (char *) 0) % __alignof__ (uint32_t),
  key, key_len);
    }

  if ((salt - (char *) 0) % __alignof__ (uint32_t) != 0)
    {
      char *tmp = (char *) 
                          __builtin_alloca(
                          salt_len + __alignof__ (uint32_t)
                          )
                                                                    ;
      salt = copied_salt =
 memcpy (tmp + __alignof__ (uint32_t)
  - (tmp - (char *) 0) % __alignof__ (uint32_t),
  salt, salt_len);
    }


  sha256_init_ctx (&ctx);


  sha256_process_bytes (key, key_len, &ctx);




  sha256_process_bytes (salt, salt_len, &ctx);




  sha256_init_ctx (&alt_ctx);


  sha256_process_bytes (key, key_len, &alt_ctx);


  sha256_process_bytes (salt, salt_len, &alt_ctx);


  sha256_process_bytes (key, key_len, &alt_ctx);



  sha256_finish_ctx (&alt_ctx, alt_result);


  for (cnt = key_len; cnt > 32; cnt -= 32)
    sha256_process_bytes (alt_result, 32, &ctx);
  sha256_process_bytes (alt_result, cnt, &ctx);



  for (cnt = key_len; cnt > 0; cnt >>= 1)
    if ((cnt & 1) != 0)
      sha256_process_bytes (alt_result, 32, &ctx);
    else
      sha256_process_bytes (key, key_len, &ctx);


  sha256_finish_ctx (&ctx, alt_result);


  sha256_init_ctx (&alt_ctx);


  for (cnt = 0; cnt < key_len; ++cnt)
    sha256_process_bytes (key, key_len, &alt_ctx);


  sha256_finish_ctx (&alt_ctx, temp_result);


  cp = p_bytes = 
                __builtin_alloca(
                key_len
                )
                                ;
  for (cnt = key_len; cnt >= 32; cnt -= 32)
    cp = memcpy (cp, temp_result, 32) + 32;
  memcpy (cp, temp_result, cnt);


  sha256_init_ctx (&alt_ctx);


  for (cnt = 0; cnt < 16u + alt_result[0]; ++cnt)
    sha256_process_bytes (salt, salt_len, &alt_ctx);


  sha256_finish_ctx (&alt_ctx, temp_result);


  cp = s_bytes = 
                __builtin_alloca(
                salt_len
                )
                                 ;
  for (cnt = salt_len; cnt >= 32; cnt -= 32)
    cp = memcpy (cp, temp_result, 32) + 32;
  memcpy (cp, temp_result, cnt);



  for (cnt = 0; cnt < rounds; ++cnt)
    {

      sha256_init_ctx (&ctx);


      if ((cnt & 1) != 0)
 sha256_process_bytes (p_bytes, key_len, &ctx);
      else
 sha256_process_bytes (alt_result, 32, &ctx);


      if (cnt % 3 != 0)
 sha256_process_bytes (s_bytes, salt_len, &ctx);


      if (cnt % 7 != 0)
 sha256_process_bytes (p_bytes, key_len, &ctx);


      if ((cnt & 1) != 0)
 sha256_process_bytes (alt_result, 32, &ctx);
      else
 sha256_process_bytes (p_bytes, key_len, &ctx);


      sha256_finish_ctx (&ctx, alt_result);
    }



  cp = stpncpy (buffer, sha256_salt_prefix, 
                                           (((
                                           0
                                           )>(
                                           buflen
                                           ))?(
                                           0
                                           ):(
                                           buflen
                                           ))
                                                          );
  buflen -= sizeof (sha256_salt_prefix) - 1;

  if (rounds_custom)
    {
      int n = snprintf (cp, 
                           (((
                           0
                           )>(
                           buflen
                           ))?(
                           0
                           ):(
                           buflen
                           ))
                                          , "%s%zu$",
   sha256_rounds_prefix, rounds);
      cp += n;
      buflen -= n;
    }

  cp = stpncpy (cp, salt, 
                         (((
                         (size_t) 
                         (((
                         0
                         )>(
                         buflen
                         ))?(
                         0
                         ):(
                         buflen
                         )))<(
                         salt_len
                         ))?(
                         (size_t) 
                         (((
                         0
                         )>(
                         buflen
                         ))?(
                         0
                         ):(
                         buflen
                         ))):(
                         salt_len
                         ))
                                                                 );
  buflen -= 
           (((
           (size_t) 
           (((
           0
           )>(
           buflen
           ))?(
           0
           ):(
           buflen
           )))<(
           salt_len
           ))?(
           (size_t) 
           (((
           0
           )>(
           buflen
           ))?(
           0
           ):(
           buflen
           ))):(
           salt_len
           ))
                                                   ;

  if (buflen > 0)
    {
      *cp++ = '$';
      --buflen;
    }
  do { unsigned int w = ((alt_result[0]) << 16) | ((alt_result[10]) << 8) | (alt_result[20]); int n = (4); while (n-- > 0 && buflen > 0) { *cp++ = b64t[w & 0x3f]; --buflen; w >>= 6; } } while (0);
  do { unsigned int w = ((alt_result[21]) << 16) | ((alt_result[1]) << 8) | (alt_result[11]); int n = (4); while (n-- > 0 && buflen > 0) { *cp++ = b64t[w & 0x3f]; --buflen; w >>= 6; } } while (0);
  do { unsigned int w = ((alt_result[12]) << 16) | ((alt_result[22]) << 8) | (alt_result[2]); int n = (4); while (n-- > 0 && buflen > 0) { *cp++ = b64t[w & 0x3f]; --buflen; w >>= 6; } } while (0);
  do { unsigned int w = ((alt_result[3]) << 16) | ((alt_result[13]) << 8) | (alt_result[23]); int n = (4); while (n-- > 0 && buflen > 0) { *cp++ = b64t[w & 0x3f]; --buflen; w >>= 6; } } while (0);
  do { unsigned int w = ((alt_result[24]) << 16) | ((alt_result[4]) << 8) | (alt_result[14]); int n = (4); while (n-- > 0 && buflen > 0) { *cp++ = b64t[w & 0x3f]; --buflen; w >>= 6; } } while (0);
  do { unsigned int w = ((alt_result[15]) << 16) | ((alt_result[25]) << 8) | (alt_result[5]); int n = (4); while (n-- > 0 && buflen > 0) { *cp++ = b64t[w & 0x3f]; --buflen; w >>= 6; } } while (0);
  do { unsigned int w = ((alt_result[6]) << 16) | ((alt_result[16]) << 8) | (alt_result[26]); int n = (4); while (n-- > 0 && buflen > 0) { *cp++ = b64t[w & 0x3f]; --buflen; w >>= 6; } } while (0);
  do { unsigned int w = ((alt_result[27]) << 16) | ((alt_result[7]) << 8) | (alt_result[17]); int n = (4); while (n-- > 0 && buflen > 0) { *cp++ = b64t[w & 0x3f]; --buflen; w >>= 6; } } while (0);
  do { unsigned int w = ((alt_result[18]) << 16) | ((alt_result[28]) << 8) | (alt_result[8]); int n = (4); while (n-- > 0 && buflen > 0) { *cp++ = b64t[w & 0x3f]; --buflen; w >>= 6; } } while (0);
  do { unsigned int w = ((alt_result[9]) << 16) | ((alt_result[19]) << 8) | (alt_result[29]); int n = (4); while (n-- > 0 && buflen > 0) { *cp++ = b64t[w & 0x3f]; --buflen; w >>= 6; } } while (0);
  do { unsigned int w = ((0) << 16) | ((alt_result[31]) << 8) | (alt_result[30]); int n = (3); while (n-- > 0 && buflen > 0) { *cp++ = b64t[w & 0x3f]; --buflen; w >>= 6; } } while (0);
  if (buflen <= 0)
    {
      errno = 
             34
                   ;
      buffer = 
              (void*)0
                  ;
    }
  else
    *cp = '\0';





  sha256_init_ctx (&ctx);
  sha256_finish_ctx (&ctx, alt_result);
  memset (temp_result, '\0', sizeof (temp_result));
  memset (p_bytes, '\0', key_len);
  memset (s_bytes, '\0', salt_len);
  memset (&ctx, '\0', sizeof (ctx));
  memset (&alt_ctx, '\0', sizeof (alt_ctx));
  if (copied_key != 
                   (void*)0
                       )
    memset (copied_key, '\0', key_len);
  if (copied_salt != 
                    (void*)0
                        )
    memset (copied_salt, '\0', salt_len);

  return buffer;
}




static char *
static sha256_crypt (const char *key, const char *salt)
{




  static char *buffer;
  static int buflen;
  int needed = (sizeof (sha256_salt_prefix) - 1
  + sizeof (sha256_rounds_prefix) + 9 + 1
  + strlen (salt) + 1 + 43 + 1);

  if (buflen < needed)
    {
      char *new_buffer = (char *) realloc (buffer, needed);
      if (new_buffer == 
                       (void*)0
                           )
 return 
       (void*)0
           ;

      buffer = new_buffer;
      buflen = needed;
    }

  return sha256_crypt_r (key, salt, buffer, buflen);
}
struct sha512_ctx
{
  uint64_t H[8];

  uint64_t total[2];
  uint64_t buflen;
  char buffer[256];
};
static const unsigned char fillbuf[128] = { 0x80, 0 };



static const uint64_t K[80] =
  {
    0x428a2f98d728ae22ULL, 0x7137449123ef65cdULL,
    0xb5c0fbcfec4d3b2fULL, 0xe9b5dba58189dbbcULL,
    0x3956c25bf348b538ULL, 0x59f111f1b605d019ULL,
    0x923f82a4af194f9bULL, 0xab1c5ed5da6d8118ULL,
    0xd807aa98a3030242ULL, 0x12835b0145706fbeULL,
    0x243185be4ee4b28cULL, 0x550c7dc3d5ffb4e2ULL,
    0x72be5d74f27b896fULL, 0x80deb1fe3b1696b1ULL,
    0x9bdc06a725c71235ULL, 0xc19bf174cf692694ULL,
    0xe49b69c19ef14ad2ULL, 0xefbe4786384f25e3ULL,
    0x0fc19dc68b8cd5b5ULL, 0x240ca1cc77ac9c65ULL,
    0x2de92c6f592b0275ULL, 0x4a7484aa6ea6e483ULL,
    0x5cb0a9dcbd41fbd4ULL, 0x76f988da831153b5ULL,
    0x983e5152ee66dfabULL, 0xa831c66d2db43210ULL,
    0xb00327c898fb213fULL, 0xbf597fc7beef0ee4ULL,
    0xc6e00bf33da88fc2ULL, 0xd5a79147930aa725ULL,
    0x06ca6351e003826fULL, 0x142929670a0e6e70ULL,
    0x27b70a8546d22ffcULL, 0x2e1b21385c26c926ULL,
    0x4d2c6dfc5ac42aedULL, 0x53380d139d95b3dfULL,
    0x650a73548baf63deULL, 0x766a0abb3c77b2a8ULL,
    0x81c2c92e47edaee6ULL, 0x92722c851482353bULL,
    0xa2bfe8a14cf10364ULL, 0xa81a664bbc423001ULL,
    0xc24b8b70d0f89791ULL, 0xc76c51a30654be30ULL,
    0xd192e819d6ef5218ULL, 0xd69906245565a910ULL,
    0xf40e35855771202aULL, 0x106aa07032bbd1b8ULL,
    0x19a4c116b8d2d0c8ULL, 0x1e376c085141ab53ULL,
    0x2748774cdf8eeb99ULL, 0x34b0bcb5e19b48a8ULL,
    0x391c0cb3c5c95a63ULL, 0x4ed8aa4ae3418acbULL,
    0x5b9cca4f7763e373ULL, 0x682e6ff3d6b2b8a3ULL,
    0x748f82ee5defb2fcULL, 0x78a5636f43172f60ULL,
    0x84c87814a1f0ab72ULL, 0x8cc702081a6439ecULL,
    0x90befffa23631e28ULL, 0xa4506cebde82bde9ULL,
    0xbef9a3f7b2c67915ULL, 0xc67178f2e372532bULL,
    0xca273eceea26619cULL, 0xd186b8c721c0c207ULL,
    0xeada7dd6cde0eb1eULL, 0xf57d4f7fee6ed178ULL,
    0x06f067aa72176fbaULL, 0x0a637dc5a2c898a6ULL,
    0x113f9804bef90daeULL, 0x1b710b35131c471bULL,
    0x28db77f523047d84ULL, 0x32caab7b40c72493ULL,
    0x3c9ebe0a15c9bebcULL, 0x431d67c49c100d4cULL,
    0x4cc5d4becb3e42b6ULL, 0x597f299cfc657e2aULL,
    0x5fcb6fab3ad6faecULL, 0x6c44198c4a475817ULL
  };




static void
static sha512_process_block (const void *buffer, size_t len, struct sha512_ctx *ctx)
{
  const uint64_t *words = buffer;
  size_t nwords = len / sizeof (uint64_t);
  uint64_t a = ctx->H[0];
  uint64_t b = ctx->H[1];
  uint64_t c = ctx->H[2];
  uint64_t d = ctx->H[3];
  uint64_t e = ctx->H[4];
  uint64_t f = ctx->H[5];
  uint64_t g = ctx->H[6];
  uint64_t h = ctx->H[7];




  ctx->total[0] += len;
  if (ctx->total[0] < len)
    ++ctx->total[1];



  while (nwords > 0)
    {
      uint64_t W[80];
      uint64_t a_save = a;
      uint64_t b_save = b;
      uint64_t c_save = c;
      uint64_t d_save = d;
      uint64_t e_save = e;
      uint64_t f_save = f;
      uint64_t g_save = g;
      uint64_t h_save = h;
      unsigned int t;
      for (t = 0; t < 16; ++t)
 {
   W[t] = (*words);
   ++words;
 }
      for (t = 16; t < 80; ++t)
 W[t] = (((W[t - 2] >> 19) | (W[t - 2] << (64 - 19))) ^ ((W[t - 2] >> 61) | (W[t - 2] << (64 - 61))) ^ (W[t - 2] >> 6)) + W[t - 7] + (((W[t - 15] >> 1) | (W[t - 15] << (64 - 1))) ^ ((W[t - 15] >> 8) | (W[t - 15] << (64 - 8))) ^ (W[t - 15] >> 7)) + W[t - 16];


      for (t = 0; t < 80; ++t)
 {
   uint64_t T1 = h + (((e >> 14) | (e << (64 - 14))) ^ ((e >> 18) | (e << (64 - 18))) ^ ((e >> 41) | (e << (64 - 41)))) + ((e & f) ^ (~e & g)) + K[t] + W[t];
   uint64_t T2 = (((a >> 28) | (a << (64 - 28))) ^ ((a >> 34) | (a << (64 - 34))) ^ ((a >> 39) | (a << (64 - 39)))) + ((a & b) ^ (a & c) ^ (b & c));
   h = g;
   g = f;
   f = e;
   e = d + T1;
   d = c;
   c = b;
   b = a;
   a = T1 + T2;
 }



      a += a_save;
      b += b_save;
      c += c_save;
      d += d_save;
      e += e_save;
      f += f_save;
      g += g_save;
      h += h_save;


      nwords -= 16;
    }


  ctx->H[0] = a;
  ctx->H[1] = b;
  ctx->H[2] = c;
  ctx->H[3] = d;
  ctx->H[4] = e;
  ctx->H[5] = f;
  ctx->H[6] = g;
  ctx->H[7] = h;
}




static void
static sha512_init_ctx (struct sha512_ctx *ctx)
{
  ctx->H[0] = 0x6a09e667f3bcc908ULL;
  ctx->H[1] = 0xbb67ae8584caa73bULL;
  ctx->H[2] = 0x3c6ef372fe94f82bULL;
  ctx->H[3] = 0xa54ff53a5f1d36f1ULL;
  ctx->H[4] = 0x510e527fade682d1ULL;
  ctx->H[5] = 0x9b05688c2b3e6c1fULL;
  ctx->H[6] = 0x1f83d9abfb41bd6bULL;
  ctx->H[7] = 0x5be0cd19137e2179ULL;

  ctx->total[0] = ctx->total[1] = 0;
  ctx->buflen = 0;
}







static void *
static sha512_finish_ctx (struct sha512_ctx *ctx, void *resbuf)
{

  uint64_t bytes = ctx->buflen;
  size_t pad;
  unsigned int i;


  ctx->total[0] += bytes;
  if (ctx->total[0] < bytes)
    ++ctx->total[1];

  pad = bytes >= 112 ? 128 + 112 - bytes : 112 - bytes;
  memcpy (&ctx->buffer[bytes], fillbuf, pad);


  *(uint64_t *) &ctx->buffer[bytes + pad + 8] = (ctx->total[0] << 3);
  *(uint64_t *) &ctx->buffer[bytes + pad] = ((ctx->total[1] << 3) | (ctx->total[0] >> 61))
                              ;


  sha512_process_block (ctx->buffer, bytes + pad + 16, ctx);


  for (i = 0; i < 8; ++i)
    ((uint64_t *) resbuf)[i] = (ctx->H[i]);

  return resbuf;
}


static void
static sha512_process_bytes (const void *buffer, size_t len, struct sha512_ctx *ctx)
{


  if (ctx->buflen != 0)
    {
      size_t left_over = ctx->buflen;
      size_t add = 256 - left_over > len ? len : 256 - left_over;

      memcpy (&ctx->buffer[left_over], buffer, add);
      ctx->buflen += add;

      if (ctx->buflen > 128)
 {
   sha512_process_block (ctx->buffer, ctx->buflen & ~127, ctx);

   ctx->buflen &= 127;

   memcpy (ctx->buffer, &ctx->buffer[(left_over + add) & ~127],
    ctx->buflen);
 }

      buffer = (const char *) buffer + add;
      len -= add;
    }


  if (len >= 128)
    {
      if ((((uintptr_t) buffer) % __alignof__ (uint64_t) != 0))
 while (len > 128)
   {
     sha512_process_block (memcpy (ctx->buffer, buffer, 128), 128,
        ctx);
     buffer = (const char *) buffer + 128;
     len -= 128;
   }
      else

 {
   sha512_process_block (buffer, len & ~127, ctx);
   buffer = (const char *) buffer + (len & ~127);
   len &= 127;
 }
    }


  if (len > 0)
    {
      size_t left_over = ctx->buflen;

      memcpy (&ctx->buffer[left_over], buffer, len);
      left_over += len;
      if (left_over >= 128)
 {
   sha512_process_block (ctx->buffer, 128, ctx);
   left_over -= 128;
   memcpy (ctx->buffer, &ctx->buffer[128], left_over);
 }
      ctx->buflen = left_over;
    }
}




static const char sha512_salt_prefix[] = "$6$";


static const char sha512_rounds_prefix[] = "rounds=";
static const char b64t[64] =
static "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";


static char *
static sha512_crypt_r (const char *key, const char *salt, char *buffer, int buflen)
{
  unsigned char alt_result[64]
    __attribute__ ((__aligned__ (__alignof__ (uint64_t))));
  unsigned char temp_result[64]
    __attribute__ ((__aligned__ (__alignof__ (uint64_t))));
  struct sha512_ctx ctx;
  struct sha512_ctx alt_ctx;
  size_t salt_len;
  size_t key_len;
  size_t cnt;
  char *cp;
  char *copied_key = 
                    (void*)0
                        ;
  char *copied_salt = 
                     (void*)0
                         ;
  char *p_bytes;
  char *s_bytes;

  size_t rounds = 5000;
  
 _Bool 
      rounds_custom = 
                      0
                           ;



  if (strncmp (sha512_salt_prefix, salt, sizeof (sha512_salt_prefix) - 1) == 0)

    salt += sizeof (sha512_salt_prefix) - 1;

  if (strncmp (salt, sha512_rounds_prefix, sizeof (sha512_rounds_prefix) - 1)
      == 0)
    {
      const char *num = salt + sizeof (sha512_rounds_prefix) - 1;
      char *endp;
      unsigned long int srounds = strtoul (num, &endp, 10);
      if (*endp == '$')
 {
   salt = endp + 1;
   rounds = 
           (((
           1000
           )>((((
           srounds
           )<(
           999999999
           ))?(
           srounds
           ):(
           999999999
           ))))?(
           1000
           ):((((
           srounds
           )<(
           999999999
           ))?(
           srounds
           ):(
           999999999
           ))))
                                                      ;
   rounds_custom = 
                  1
                      ;
 }
    }

  salt_len = 
            (((
            strcspn (salt, "$")
            )<(
            16
            ))?(
            strcspn (salt, "$")
            ):(
            16
            ))
                                                   ;
  key_len = strlen (key);

  if ((key - (char *) 0) % __alignof__ (uint64_t) != 0)
    {
      char *tmp = (char *) 
                          __builtin_alloca(
                          key_len + __alignof__ (uint64_t)
                          )
                                                                   ;
      key = copied_key =
 memcpy (tmp + __alignof__ (uint64_t)
  - (tmp - (char *) 0) % __alignof__ (uint64_t),
  key, key_len);
    }

  if ((salt - (char *) 0) % __alignof__ (uint64_t) != 0)
    {
      char *tmp = (char *) 
                          __builtin_alloca(
                          salt_len + __alignof__ (uint64_t)
                          )
                                                                    ;
      salt = copied_salt =
 memcpy (tmp + __alignof__ (uint64_t)
  - (tmp - (char *) 0) % __alignof__ (uint64_t),
  salt, salt_len);
    }


  sha512_init_ctx (&ctx);


  sha512_process_bytes (key, key_len, &ctx);




  sha512_process_bytes (salt, salt_len, &ctx);




  sha512_init_ctx (&alt_ctx);


  sha512_process_bytes (key, key_len, &alt_ctx);


  sha512_process_bytes (salt, salt_len, &alt_ctx);


  sha512_process_bytes (key, key_len, &alt_ctx);



  sha512_finish_ctx (&alt_ctx, alt_result);


  for (cnt = key_len; cnt > 64; cnt -= 64)
    sha512_process_bytes (alt_result, 64, &ctx);
  sha512_process_bytes (alt_result, cnt, &ctx);



  for (cnt = key_len; cnt > 0; cnt >>= 1)
    if ((cnt & 1) != 0)
      sha512_process_bytes (alt_result, 64, &ctx);
    else
      sha512_process_bytes (key, key_len, &ctx);


  sha512_finish_ctx (&ctx, alt_result);


  sha512_init_ctx (&alt_ctx);


  for (cnt = 0; cnt < key_len; ++cnt)
    sha512_process_bytes (key, key_len, &alt_ctx);


  sha512_finish_ctx (&alt_ctx, temp_result);


  cp = p_bytes = 
                __builtin_alloca(
                key_len
                )
                                ;
  for (cnt = key_len; cnt >= 64; cnt -= 64)
    cp = memcpy (cp, temp_result, 64) + 64;
  memcpy (cp, temp_result, cnt);


  sha512_init_ctx (&alt_ctx);


  for (cnt = 0; cnt < 16u + alt_result[0]; ++cnt)
    sha512_process_bytes (salt, salt_len, &alt_ctx);


  sha512_finish_ctx (&alt_ctx, temp_result);


  cp = s_bytes = 
                __builtin_alloca(
                salt_len
                )
                                 ;
  for (cnt = salt_len; cnt >= 64; cnt -= 64)
    cp = memcpy (cp, temp_result, 64) + 64;
  memcpy (cp, temp_result, cnt);



  for (cnt = 0; cnt < rounds; ++cnt)
    {

      sha512_init_ctx (&ctx);


      if ((cnt & 1) != 0)
 sha512_process_bytes (p_bytes, key_len, &ctx);
      else
 sha512_process_bytes (alt_result, 64, &ctx);


      if (cnt % 3 != 0)
 sha512_process_bytes (s_bytes, salt_len, &ctx);


      if (cnt % 7 != 0)
 sha512_process_bytes (p_bytes, key_len, &ctx);


      if ((cnt & 1) != 0)
 sha512_process_bytes (alt_result, 64, &ctx);
      else
 sha512_process_bytes (p_bytes, key_len, &ctx);


      sha512_finish_ctx (&ctx, alt_result);
    }



  cp = stpncpy (buffer, sha512_salt_prefix, 
                                           (((
                                           0
                                           )>(
                                           buflen
                                           ))?(
                                           0
                                           ):(
                                           buflen
                                           ))
                                                          );
  buflen -= sizeof (sha512_salt_prefix) - 1;

  if (rounds_custom)
    {
      int n = snprintf (cp, 
                           (((
                           0
                           )>(
                           buflen
                           ))?(
                           0
                           ):(
                           buflen
                           ))
                                          , "%s%zu$",
   sha512_rounds_prefix, rounds);
      cp += n;
      buflen -= n;
    }

  cp = stpncpy (cp, salt, 
                         (((
                         (size_t) 
                         (((
                         0
                         )>(
                         buflen
                         ))?(
                         0
                         ):(
                         buflen
                         )))<(
                         salt_len
                         ))?(
                         (size_t) 
                         (((
                         0
                         )>(
                         buflen
                         ))?(
                         0
                         ):(
                         buflen
                         ))):(
                         salt_len
                         ))
                                                                 );
  buflen -= 
           (((
           (size_t) 
           (((
           0
           )>(
           buflen
           ))?(
           0
           ):(
           buflen
           )))<(
           salt_len
           ))?(
           (size_t) 
           (((
           0
           )>(
           buflen
           ))?(
           0
           ):(
           buflen
           ))):(
           salt_len
           ))
                                                   ;

  if (buflen > 0)
    {
      *cp++ = '$';
      --buflen;
    }
  do { unsigned int w = ((alt_result[0]) << 16) | ((alt_result[21]) << 8) | (alt_result[42]); int n = (4); while (n-- > 0 && buflen > 0) { *cp++ = b64t[w & 0x3f]; --buflen; w >>= 6; } } while (0);
  do { unsigned int w = ((alt_result[22]) << 16) | ((alt_result[43]) << 8) | (alt_result[1]); int n = (4); while (n-- > 0 && buflen > 0) { *cp++ = b64t[w & 0x3f]; --buflen; w >>= 6; } } while (0);
  do { unsigned int w = ((alt_result[44]) << 16) | ((alt_result[2]) << 8) | (alt_result[23]); int n = (4); while (n-- > 0 && buflen > 0) { *cp++ = b64t[w & 0x3f]; --buflen; w >>= 6; } } while (0);
  do { unsigned int w = ((alt_result[3]) << 16) | ((alt_result[24]) << 8) | (alt_result[45]); int n = (4); while (n-- > 0 && buflen > 0) { *cp++ = b64t[w & 0x3f]; --buflen; w >>= 6; } } while (0);
  do { unsigned int w = ((alt_result[25]) << 16) | ((alt_result[46]) << 8) | (alt_result[4]); int n = (4); while (n-- > 0 && buflen > 0) { *cp++ = b64t[w & 0x3f]; --buflen; w >>= 6; } } while (0);
  do { unsigned int w = ((alt_result[47]) << 16) | ((alt_result[5]) << 8) | (alt_result[26]); int n = (4); while (n-- > 0 && buflen > 0) { *cp++ = b64t[w & 0x3f]; --buflen; w >>= 6; } } while (0);
  do { unsigned int w = ((alt_result[6]) << 16) | ((alt_result[27]) << 8) | (alt_result[48]); int n = (4); while (n-- > 0 && buflen > 0) { *cp++ = b64t[w & 0x3f]; --buflen; w >>= 6; } } while (0);
  do { unsigned int w = ((alt_result[28]) << 16) | ((alt_result[49]) << 8) | (alt_result[7]); int n = (4); while (n-- > 0 && buflen > 0) { *cp++ = b64t[w & 0x3f]; --buflen; w >>= 6; } } while (0);
  do { unsigned int w = ((alt_result[50]) << 16) | ((alt_result[8]) << 8) | (alt_result[29]); int n = (4); while (n-- > 0 && buflen > 0) { *cp++ = b64t[w & 0x3f]; --buflen; w >>= 6; } } while (0);
  do { unsigned int w = ((alt_result[9]) << 16) | ((alt_result[30]) << 8) | (alt_result[51]); int n = (4); while (n-- > 0 && buflen > 0) { *cp++ = b64t[w & 0x3f]; --buflen; w >>= 6; } } while (0);
  do { unsigned int w = ((alt_result[31]) << 16) | ((alt_result[52]) << 8) | (alt_result[10]); int n = (4); while (n-- > 0 && buflen > 0) { *cp++ = b64t[w & 0x3f]; --buflen; w >>= 6; } } while (0);
  do { unsigned int w = ((alt_result[53]) << 16) | ((alt_result[11]) << 8) | (alt_result[32]); int n = (4); while (n-- > 0 && buflen > 0) { *cp++ = b64t[w & 0x3f]; --buflen; w >>= 6; } } while (0);
  do { unsigned int w = ((alt_result[12]) << 16) | ((alt_result[33]) << 8) | (alt_result[54]); int n = (4); while (n-- > 0 && buflen > 0) { *cp++ = b64t[w & 0x3f]; --buflen; w >>= 6; } } while (0);
  do { unsigned int w = ((alt_result[34]) << 16) | ((alt_result[55]) << 8) | (alt_result[13]); int n = (4); while (n-- > 0 && buflen > 0) { *cp++ = b64t[w & 0x3f]; --buflen; w >>= 6; } } while (0);
  do { unsigned int w = ((alt_result[56]) << 16) | ((alt_result[14]) << 8) | (alt_result[35]); int n = (4); while (n-- > 0 && buflen > 0) { *cp++ = b64t[w & 0x3f]; --buflen; w >>= 6; } } while (0);
  do { unsigned int w = ((alt_result[15]) << 16) | ((alt_result[36]) << 8) | (alt_result[57]); int n = (4); while (n-- > 0 && buflen > 0) { *cp++ = b64t[w & 0x3f]; --buflen; w >>= 6; } } while (0);
  do { unsigned int w = ((alt_result[37]) << 16) | ((alt_result[58]) << 8) | (alt_result[16]); int n = (4); while (n-- > 0 && buflen > 0) { *cp++ = b64t[w & 0x3f]; --buflen; w >>= 6; } } while (0);
  do { unsigned int w = ((alt_result[59]) << 16) | ((alt_result[17]) << 8) | (alt_result[38]); int n = (4); while (n-- > 0 && buflen > 0) { *cp++ = b64t[w & 0x3f]; --buflen; w >>= 6; } } while (0);
  do { unsigned int w = ((alt_result[18]) << 16) | ((alt_result[39]) << 8) | (alt_result[60]); int n = (4); while (n-- > 0 && buflen > 0) { *cp++ = b64t[w & 0x3f]; --buflen; w >>= 6; } } while (0);
  do { unsigned int w = ((alt_result[40]) << 16) | ((alt_result[61]) << 8) | (alt_result[19]); int n = (4); while (n-- > 0 && buflen > 0) { *cp++ = b64t[w & 0x3f]; --buflen; w >>= 6; } } while (0);
  do { unsigned int w = ((alt_result[62]) << 16) | ((alt_result[20]) << 8) | (alt_result[41]); int n = (4); while (n-- > 0 && buflen > 0) { *cp++ = b64t[w & 0x3f]; --buflen; w >>= 6; } } while (0);
  do { unsigned int w = ((0) << 16) | ((0) << 8) | (alt_result[63]); int n = (2); while (n-- > 0 && buflen > 0) { *cp++ = b64t[w & 0x3f]; --buflen; w >>= 6; } } while (0);

  if (buflen <= 0)
    {
      errno = 
             34
                   ;
      buffer = 
              (void*)0
                  ;
    }
  else
    *cp = '\0';





  sha512_init_ctx (&ctx);
  sha512_finish_ctx (&ctx, alt_result);
  memset (temp_result, '\0', sizeof (temp_result));
  memset (p_bytes, '\0', key_len);
  memset (s_bytes, '\0', salt_len);
  memset (&ctx, '\0', sizeof (ctx));
  memset (&alt_ctx, '\0', sizeof (alt_ctx));
  if (copied_key != 
                   (void*)0
                       )
    memset (copied_key, '\0', key_len);
  if (copied_salt != 
                    (void*)0
                        )
    memset (copied_salt, '\0', salt_len);

  return buffer;
}




static char *
static sha512_crypt (const char *key, const char *salt)
{




  static char *buffer;
  static int buflen;
  int needed = (sizeof (sha512_salt_prefix) - 1
  + sizeof (sha512_rounds_prefix) + 9 + 1
  + strlen (salt) + 1 + 86 + 1);

  if (buflen < needed)
    {
      char *new_buffer = (char *) realloc (buffer, needed);
      if (new_buffer == 
                       (void*)0
                           )
 return 
       (void*)0
           ;

      buffer = new_buffer;
      buflen = needed;
    }

  return sha512_crypt_r (key, salt, buffer, buflen);
}








static char *dirname(char *path) ;
static char *basename(char *path) ;



static char *basename(char *path) {
  char *c;
again:
  if (!(c=strrchr(path,'/'))) return path;
  if (c[1]==0) {
    if (c == path)
      return c;
    else {
      *c=0;
      goto again;
    }
  }
  return c+1;
}
static char *dot=".";


static char *dirname(char *path)
{
  char *c;
  if ( path == 
               (void*)0 
                    ) return dot;
  for(;;) {
    if ( !(c=strrchr(path,'/')) ) return dot;
    if ( c[1]==(char)0 && c!=path ) {
      while ( *c=='/' && c!=path ) *c--=(char)0;
      continue;
    }
    if ( c!=path )
      while ( *c=='/' && c>=path) *c--=(char)0;
    else
      path[1]=(char)0;
    return path;
  }
}









static int fnmatch(const char *pattern, const char *string, int flags) ;








static struct charclass {
  char * class;
  int (*istype)(int);
} allclasses[] = {
  { "alnum" , isalnum },
  { "alpha" , isalpha },
  { "blank" , isblank },
  { "cntrl" , iscntrl },
  { "digit" , isdigit },
  { "graph" , isgraph },
  { "lower" , islower },
  { "print" , isprint },
  { "punct" , ispunct },
  { "space" , isspace },
  { "upper" , isupper },
  { "xdigit" , isxdigit },
};


static struct charclass *charclass_lookup(const char *pattern) {
  unsigned int i;

  for (i = 0; i< sizeof(allclasses)/sizeof(*allclasses); i++) {
    int len = strlen(allclasses[i].class);
    if (!strncmp(pattern, allclasses[i].class, len)) {
      pattern += len;
      if (strncmp(pattern, ":]", 2)) goto noclass;
      return &allclasses[i];
    }
  }
noclass:
  return 
        (void*)0
            ;
}

static int match(char c,char d,int flags) {
  if (flags&
           16
                       )
    return (tolower(c)==tolower(d));
  else
    return (c==d);
}

static int fnmatch(const char *pattern, const char *string, int flags) {
  if (*string==0) {
    while (*pattern=='*') ++pattern;
    return (!!*pattern);
  }
  if (*string=='.' && *pattern!='.' && (flags&
                                             4
                                                       )) {

    if (!(flags&128))
      return 
            1
                       ;

    if ((flags&(
               2
                           )) && string[-1]=='/')
      return 
            1
                       ;
  }
  flags|=128;
  switch (*pattern) {
  case '[':
    {
      int neg=0;
      const char* start;

      ++pattern;
      if (*string=='/' && flags&
                               2
                                           ) return 
                                                    1
                                                               ;
      if (*pattern=='!') { neg=1; ++pattern; }
      start=pattern;
      while (*pattern) {
 int res=0;

 if (*pattern==']' && pattern!=start) break;
 if (*pattern=='[' && pattern[1]==':') {

   const struct charclass *cc;

   if (!(cc = charclass_lookup(pattern+2))) goto invalidclass;
   pattern += strlen(cc->class) + 4;
   if (flags&
            16
       
      && (cc->istype == isupper || cc->istype == islower)) {
     res = islower(tolower(*string));
   } else {
            res = ((*(cc->istype))(*string));
   }
 } else {
invalidclass:
   if (pattern[1]=='-' && pattern[2]!=']') {

     if (*string>=*pattern && *string<=pattern[2]) res=1;
     if (flags&
              16
                          ) {
       if (tolower(*string)>=tolower(*pattern) && tolower(*string)<=tolower(pattern[2])) res=1;
     }
     pattern+=3;
   } else {

     res=match(*pattern,*string,flags);
     ++pattern;
   }
 }
 if ((res&&!neg) || ((neg&&!res) && *pattern==']')) {
   while (*pattern && *pattern!=']') ++pattern;
   return fnmatch(pattern+!!*pattern,string+1,flags);
 } else if (res && neg)
   return 
         1
                    ;
      }
    }
    break;
  case '\\':
    if (flags&
             1
                         ) {
      if (*string=='\\')
 return fnmatch(pattern+1,string+1,flags);
    } else {
      if (*string==pattern[1])
 return fnmatch(pattern+2,string+1,flags);
    }
    break;
  case '*':
    if ((*string=='/' && flags&
                              2
                                          ) || fnmatch(pattern,string+1,flags))
      return fnmatch(pattern+1,string,flags);
    return 0;
  case 0:
    if (*string==0 || (*string=='/' && (flags&
                                             8
                                                            )))
      return 0;
    break;
  case '?':
    if (*string=='/' && flags&
                             2
                                         ) break;
    return fnmatch(pattern+1,string+1,flags);
  default:
    if (match(*pattern,*string,flags))
      return fnmatch(pattern+1,string+1,flags);
    break;
  }
  return 
        1
                   ;
}









typedef struct {
 size_t gl_pathc;
 char **gl_pathv;
 size_t gl_offs;
 int gl_flags;
} glob_t;


static int glob(const char *pattern, int flags,
  int errfunc(const char * epath, int eerrno),
  glob_t *pglob) ;

static void globfree(glob_t *pglob) ;






static int cmp_func(const void * a, const void * b)
{
 const char *const s1 = *(const char *const * const) a;
 const char *const s2 = *(const char *const * const) b;
 if (s1 == 
          (void*)0
              )
  return 1;
 if (s2 == 
          (void*)0
              )
  return -1;
 return strcoll(s1, s2);
}







static void close_dir_keep_errno(DIR* dp) {
  int save = errno;
  if (dp)
    closedir (dp);
  errno=save;
}

static int add_entry(const char* name,glob_t *pglob,int* nfound) {
  pglob->gl_pathv = (char **) realloc(pglob->gl_pathv,
     (pglob->gl_pathc + pglob->gl_offs + 2)
     * sizeof (char *));
  if (pglob->gl_pathv == 
                        (void*)0
                            )
    return 1;
  pglob->gl_pathv[pglob->gl_offs + pglob->gl_pathc] = strdup(name);
  pglob->gl_pathv[pglob->gl_offs + pglob->gl_pathc + 1] = 
                                                         (void*)0
                                                             ;
  pglob->gl_pathc++;
  (*nfound)++;
  return 0;
}

static void build_fullname(char * fullname, const char * directory, const char * filename) {
  char *dest=fullname;
  if (directory[0]=='/' && !directory[1]) {
    *dest='/'; ++dest;
  } else if (directory[0]!='.' || directory[1]) {
    strcpy(dest,directory);
    dest=strchr(dest,0);
    *dest='/'; ++dest;
  }
  strcpy(dest,filename);
}

static int glob_in_dir(const char *pattern, const char *directory, int flags,
         int errfunc(const char * epath, int eerrno),
         glob_t *pglob)
{
 DIR *dp = opendir(directory);
 int nfound = 0;

 int i;
 char * ptr;

 if (!dp) {
  if (errno != 
              20
      
     && ((errfunc != 
                     (void*)0 
                          && (*errfunc) (directory, errno))
   || (flags & 
              (1 << 0)
                      )))
        return 
              2
                          ;
 } else {
  int fnm_flags = ((!(flags & 
                             (1 << 7)
                                        ) ? 
                                            4 
                                                       : 0)
     | ((flags & 
                (1 << 6)
                             ) ? 
                                 1 
                                              : 0));
  struct dirent *ep;
  while ((ep = readdir(dp))) {
   i = strlen(directory) + strlen(ep->d_name) + 2;
   ptr = (char *) 
                 __builtin_alloca(
                 i
                 )
                          ;
   build_fullname(ptr, directory, ep->d_name);
   if (flags & 
              (1 << 13)
                          ) {
    struct stat statr;
    if (stat(ptr, &statr) || !
                             (((
                             statr.st_mode
                             ) & 00170000) == 0040000)
                                                   )
     continue;
   }
   if (fnmatch(pattern, ep->d_name, fnm_flags) == 0)
    if (add_entry(ptr,pglob,&nfound))
     goto memory_error;
  }
 }

 close_dir_keep_errno(dp);

 if (nfound != 0)
  pglob->gl_flags = flags;
 else if (flags & 
                 (1 << 4)
                             ) {

  i = strlen(directory) + strlen(pattern) + 2;
  ptr = (char *) 
                __builtin_alloca(
                i
                )
                         ;
  build_fullname(ptr, directory, pattern);
  if (add_entry(ptr,pglob,&nfound))
   goto memory_error;
 }

 return (nfound == 0) ? 
                       3 
                                    : 0;

 memory_error:



 close_dir_keep_errno(dp);
 return 
       1
                   ;
}



static int glob(const char *pattern, int flags, int errfunc(const char * epath, int eerrno), glob_t *pglob)
{
 char * pattern_;
 char * filename;
 char * dirname;
 size_t oldcount;
 struct stat statr;

 size_t i;
 int j, k;
 char * ptr, * ptr2;

 if (pattern == 
               (void*)0 
                    || pglob == 
                                (void*)0 
                                     || (flags & ~
                                                  ((1 << 0)|(1 << 1)|(1 << 2)|(1 << 3)| (1 << 6)|(1 << 4)|(1 << 5)| (1 << 7)|(1 << 9)|(1 << 10)| (1 << 11)|(1 << 12)|(1 << 13)|(1 << 14))
                                                              ) != 0) {
  errno=
       22
             ;
  return -1;
 }

 if (!(flags & 
              (1 << 3)
                         ))
  pglob->gl_offs = 0;





 pattern_ = 
           __builtin_alloca(
           strlen(pattern) + 1
           )
                                      ;
 strcpy(pattern_, pattern);


 if ((flags & (
              (1 << 12)
                        |
                         (1 << 14)
                                         )) && pattern_[0] == '~') {
  char * home_dir = 
                   (void*)0
                       ;
  if (pattern_[1] == '\0' || pattern_[1] == '/') {

   home_dir = getenv("HOME");
  } else {

   struct passwd * p;
   ptr2 = 
         __builtin_alloca(
         strlen(pattern_) + 1
         )
                                     ;
   strcpy(ptr2, pattern_ + 1);
   ptr = strchr(ptr2, '/');
   if (ptr != 
             (void*)0
                 )
    *ptr = '\0';
   if (((p = getpwnam(ptr2)) != 
                               (void*)0
                                   ))
    home_dir = p->pw_dir;
  }
  if (home_dir != 
                 (void*)0
                     ) {
   i = strlen(home_dir) + strlen(pattern_);
   ptr = 
        __builtin_alloca(
        i
        )
                 ;
   strncpy(ptr, home_dir, i);
   ptr2 = pattern_ + 1;
   while (*ptr2 != '/' && *ptr2 != '\0')
    ptr2++;
   strncat(ptr, ptr2, i);
   pattern_ = ptr;
  } else if (flags & 
                    (1 << 14)
                                    )
   return 
         3
                     ;
 }


 filename = strrchr(pattern_, '/');

 if (filename == 
                (void*)0
                    ) {

  filename = pattern_;
  dirname = (char*)".";
 } else if (filename == pattern_) {

  dirname = (char*)"/";
  filename++;
 } else {
  dirname = pattern_;
  filename++;

  *(filename-1) = '\0';

  if (filename[0] == '\0' && strcmp(pattern_, "/")) {

   j = glob(dirname, flags | 
                            (1 << 1)
                                     , errfunc, pglob);
   if (j == 0)
    pglob->gl_flags = ((pglob->gl_flags & ~
                                          (1 << 1)
                                                   )
         | (flags & 
                   (1 << 1)
                            ));
   return j;
  }
 }



 if (!(flags & 
              (1 << 5)
                         )) {
  pglob->gl_pathc = 0;
  if (!(flags & 
               (1 << 3)
                          ))
   pglob->gl_pathv = 
                    (void*)0
                        ;
  else {
   pglob->gl_pathv = (char **) malloc((pglob->gl_offs + 1) * sizeof (char *));
   if (pglob->gl_pathv == 
                         (void*)0
                             )
    return 
          1
                      ;
   for (i = 0; i <= pglob->gl_offs; i++)
    pglob->gl_pathv[i] = 
                        (void*)0
                            ;
  }
 }


 oldcount = pglob->gl_pathc + pglob->gl_offs;



 if (!strcmp(dirname, "/") || !strcmp(dirname, ".")
     || (!strchr(dirname, '*') && !strchr(dirname, '?') && !strchr(dirname, '['))) {

  j = glob_in_dir(filename, dirname, flags, errfunc, pglob);
  if (j != 0)
   return j;
 } else {



  glob_t dirs;

  j = glob(dirname, ((flags & (
                              (1 << 0) 
                                       | 
                                         (1 << 4) 
                                                      | 
                                                        (1 << 6) 
                                                                      | 
                                                                        (1 << 9)
                                                                                       ))
       | 
        (1 << 2) 
                    | 
                      (1 << 13)
                                  ),
    errfunc, &dirs);
  if (j != 0)
   return j;




  for (i = 0; i < dirs.gl_pathc; i++) {
   j = glob_in_dir(filename, dirs.gl_pathv[i], ((flags | 
                                                        (1 << 5)
                                                                   ) & ~
                                                                        (1 << 4)
                                                                                    ),
     errfunc, pglob);
   if (j == 
           3
                       )

    continue;
   if (j != 0) {
    globfree(&dirs);
    globfree(pglob);
    return j;
   }
  }





  if (pglob->gl_pathc + pglob->gl_offs == oldcount)
  {

   if (flags & 
              (1 << 4)
                          )
   {
    for (i = 0; i < dirs.gl_pathc; i++) {
     if (stat(dirs.gl_pathv[i], &statr) || !
                                           (((
                                           statr.st_mode
                                           ) & 00170000) == 0040000)
                                                                 )
      continue;


     j = pglob->gl_pathc + pglob->gl_offs;
     pglob->gl_pathv = (char **) realloc(pglob->gl_pathv, (j + 2) * sizeof (char *));
     if (pglob->gl_pathv == 
                           (void*)0
                               ) {
      globfree (&dirs);
      return 
            1
                        ;
     }


     k = strlen(dirs.gl_pathv[i]) + strlen(filename) + 2;
     if ((pglob->gl_pathv[j] = malloc(k)) == 
                                            (void*)0
                                                ) {
      globfree(&dirs);
      globfree(pglob);
      return 
            1
                        ;
     }
     build_fullname(pglob->gl_pathv[j], dirs.gl_pathv[i], filename);
     pglob->gl_pathc++;
     pglob->gl_pathv[j+1] = 
                           (void*)0
                               ;
    }
   } else {
    globfree(&dirs);
    return 
          3
                      ;
   }
  }

  globfree (&dirs);
 }


 if (flags & 
            (1 << 1)
                     ) {
  for (i = oldcount; i < pglob->gl_pathc + pglob->gl_offs; i++)
   if (!stat(pglob->gl_pathv[i], &statr) && 
                                           (((
                                           statr.st_mode
                                           ) & 00170000) == 0040000)
                                                                 ) {
    size_t len = strlen(pglob->gl_pathv[i]) + 2;
    ptr = realloc(pglob->gl_pathv[i], len);
    if (ptr == 
              (void*)0
                  ) {
     globfree(pglob);
     return 
           1
                       ;
    }
    strcpy(&ptr[len - 2], "/");
    pglob->gl_pathv[i] = ptr;
   }
 }

 if (!(flags & 
              (1 << 2)
                         )) {
  qsort(&pglob->gl_pathv[oldcount],
        pglob->gl_pathc + pglob->gl_offs - oldcount,
        sizeof(char *), cmp_func);
 }

 return 0;
}



static void globfree (glob_t * pglob)
{
  if (pglob->gl_pathv != 
                        (void*)0
                            ) {
      size_t i;
      for (i = 0; i < pglob->gl_pathc; i++)
       if (pglob->gl_pathv[pglob->gl_offs + i] != 
                                                 (void*)0
                                                     )
        free((void *) pglob->gl_pathv[pglob->gl_offs + i]);
      free((void *) pglob->gl_pathv);
  }
}
static char* myrealpath(const char* file, char* dest, int count) {

  char buf[
          4095
                  +1];
  char* c;
  int i;

  if (count<0) { errno=
                      31
                            ; return 0; }
  if (chdir(file)==0)

    return getcwd(dest,
                      4095
                              );

  c=strrchr(file,'/');
  if (c) {
    if (c-file>
              4095
                      ) return 0;
    memcpy(buf,file,c-file);
    buf[c-file]=0;
    if (chdir(buf)==-1) return 0;
    file=c+1;
  }
  if (readlink(file,buf,
                       4095
                               )==0)
    return myrealpath(buf,dest,count-1);
  if (getcwd(dest,
                 4095
                         )==0) return 0;
  i=strlen(dest); dest[i]='/'; ++i;
  for (; i<
          4095
                  -1; ++i) {
    if (!(dest[i]=*file)) break;
    ++file;
  }
  dest[i]=0;
  return dest;
}

static char* realpath(const char* file, char* dest) {
  int fd=open(".",
                 0x0000
                         );
  char* res;
  if (!dest) dest=malloc(
                        4095
                                +1);
  if (!dest) return 
                   (void*)0
                       ;
  res=myrealpath(file,dest,31);
  fchdir(fd);
  close(fd);
  return res;
}






static int copystring(char* buf,int maxlen, const char* s) {
  int i;
  for (i=0; i<maxlen; ++i) {
    buf[i]=s[i];
    if (!s[i])
      break;
  }
  return i;
}

static int __dtostr(double d,char *buf,unsigned int maxlen,unsigned int prec,unsigned int prec2,int flags) {

  union {
    unsigned long long l;
    double d;
  } u = { .d=d };

  signed long e=((u.l>>52)&((1<<11)-1))-1023;
  signed long e10;

  unsigned int i;
  double backup=d;
  double tmp;
  char *oldbuf=buf;

  if (isinf(d))
    return copystring(buf,maxlen,
        (d<0)?
        (flags&0x02?"-INF":"-inf"):
        (flags&0x02?"INF":"inf"));
  if (isnan(d)) return copystring(buf,maxlen,flags&0x02?"NAN":"nan");
  e10=1+(long)(e*0.30102999566398119802);






  if (d==0.0) {
    prec2=prec2==0?1:prec2+2;
    prec2=prec2>maxlen?8:prec2;
    i=0;
    if (prec2 && (long long)u.l<0) { buf[0]='-'; ++i; }
    for (; i<prec2; ++i) buf[i]='0';
    buf[buf[0]=='0'?1:2]='.'; buf[i]=0;
    return i;
  }

  if (d < 0.0) { d=-d; *buf='-'; --maxlen; ++buf; }






  tmp = 0.5;
  for (i = 0; i < prec2; i++) { tmp *= 0.1; }
  d += tmp;

  if (d < 1.0) { *buf='0'; --maxlen; ++buf; }

  if (e10>0) {
    int first=1;
    tmp = 10.0;
    i=e10;
    while (i>10) { tmp=tmp*1e10; i-=10; }
    while (i>1) { tmp=tmp*10; --i; }



    while (tmp>0.9) {
      char digit;
      double fraction=d/tmp;
 digit=(int)(fraction);
      if (!first || digit) {
 first=0;
 *buf=digit+'0'; ++buf;
 if (!maxlen) {

   int len=__dtostr(backup/tmp,oldbuf,maxlen,prec,prec2,0);
   int initial=1;
   if (len==0) return 0;
   maxlen-=len; buf+=len;
   if (maxlen>0) {
     *buf='e';
     ++buf;
   }
   --maxlen;
   for (len=1000; len>0; len/=10) {
     if (e10>=len || !initial) {
       if (maxlen>0) {
  *buf=(e10/len)+'0';
  ++buf;
       }
       --maxlen;
       initial=0;
       e10=e10%len;
     }
   }
   if (maxlen>0) goto fini;
   return 0;
 }
 d-=digit*tmp;
 --maxlen;
      }
      tmp/=10.0;
    }
  }
  else
  {
     tmp = 0.1;
  }

  if (buf==oldbuf) {
    if (!maxlen) return 0;
    --maxlen;
    *buf='0'; ++buf;
  }
  if (prec2 || prec>(unsigned int)(buf-oldbuf)+1) {
    if (!maxlen) return 0;
    --maxlen;
    *buf='.'; ++buf;
    if ((flags & 0x01)) {
      if (prec2) prec=prec2;
      prec-=buf-oldbuf-1;
    } else {
      prec-=buf-oldbuf-1;
      if (prec2) prec=prec2;
    }
    if (prec>maxlen) return 0;
    while (prec>0) {
      char digit;
      double fraction=d/tmp;
      digit=(int)(fraction);
      *buf=digit+'0'; ++buf;
      d-=digit*tmp;
      tmp/=10.0;
      --prec;
    }
  }
fini:
  *buf=0;
  return buf-oldbuf;
}


 int __dietlibc_fcntl64(int __fd, int cmd, ...);

static int fcntl64(int fd, int cmd, ...) {
  va_list va;
  
 __builtin_va_start((
 va
 ),(
 cmd
 ))
                 ;
  switch (cmd) {
  case 
      14
             :
  case 
      6
             :
  case 
      7
              :
    {
      struct flock64* x = 
                         __builtin_va_arg
                               (va,struct flock64*);
      struct flock tmp;
      int res;
      if ((res=__dietlibc_fcntl64(fd,cmd,x))) {
 if (errno!=
           89
                 ) return -1;
 tmp.l_type=x->l_type;
 tmp.l_whence=x->l_whence;
 tmp.l_start=x->l_start;
 tmp.l_len=x->l_len;
 tmp.l_pid=x->l_pid;
 if (tmp.l_len != x->l_len || tmp.l_start != x->l_start) {
   errno=
        79
                 ;
   return -1;
 }
 res=fcntl(fd,cmd,&tmp);
 if (cmd==
         14
                ) {
   x->l_type=tmp.l_type;
   x->l_whence=tmp.l_whence;
   x->l_start=tmp.l_start;
   x->l_len=tmp.l_len;
   x->l_pid=tmp.l_pid;
 }
      }
      return res;
    }

  default:
    {
      long arg = 
                __builtin_va_arg
                      (va,long);
      int res;
      if ((res=__dietlibc_fcntl64(fd,cmd,arg))==-1) {
 if (errno!=
           89
                 ) return -1;
 return fcntl(fd,cmd,arg);
      }
      return res;
    }
  }
}
 int __dietlibc_fstat64(int __fd, struct stat64 *__buf);
 void __stat64_cvt(const struct stat *src,struct stat64 *dest);

static int fstat64(int __fd, struct stat64 *__buf) {
  if (__dietlibc_fstat64(__fd,__buf)) {
    struct stat temp;
    if (errno!=
              89
                    ) return -1;
    if (fstat(__fd,&temp)) return -1;
    __stat64_cvt(&temp,__buf);
  }
  return 0;
}
