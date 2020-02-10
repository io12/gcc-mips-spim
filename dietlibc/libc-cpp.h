# 1 "libc.h"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "libc.h"
# 1 "include/math.h" 1 3 4



# 1 "include/sys/cdefs.h" 1 3 4
# 5 "include/math.h" 2 3 4


# 36 "include/math.h" 3 4

# 36 "include/math.h" 3 4
double sin(double d) __attribute__((__nothrow__ , __leaf__)) __attribute__((__const__));
double cos(double d) __attribute__((__nothrow__ , __leaf__)) __attribute__((__const__));
double tan(double d) __attribute__((__nothrow__ , __leaf__)) __attribute__((__const__));

double sinh(double d) __attribute__((__nothrow__ , __leaf__)) __attribute__((__const__));
double cosh(double d) __attribute__((__nothrow__ , __leaf__)) __attribute__((__const__));
double tanh(double d) __attribute__((__nothrow__ , __leaf__)) __attribute__((__const__));

double asin(double d) __attribute__((__nothrow__ , __leaf__)) __attribute__((__const__));
double acos(double d) __attribute__((__nothrow__ , __leaf__)) __attribute__((__const__));
double atan(double d) __attribute__((__nothrow__ , __leaf__)) __attribute__((__const__));

double asinh(double d) __attribute__((__nothrow__ , __leaf__)) __attribute__((__const__));
double acosh(double d) __attribute__((__nothrow__ , __leaf__)) __attribute__((__const__));
double atanh(double d) __attribute__((__nothrow__ , __leaf__)) __attribute__((__const__));

double exp(double d) __attribute__((__nothrow__ , __leaf__)) __attribute__((__const__));
double exp10(double d) __attribute__((__nothrow__ , __leaf__)) __attribute__((__const__));
double log(double d) __attribute__((__nothrow__ , __leaf__)) __attribute__((__const__));
double log10(double d) __attribute__((__nothrow__ , __leaf__)) __attribute__((__const__));

double exp2(double d) __attribute__((__nothrow__ , __leaf__)) __attribute__((__const__));
double log2(double d) __attribute__((__nothrow__ , __leaf__)) __attribute__((__const__));

double pow(double x, double y) __attribute__((__nothrow__ , __leaf__)) __attribute__((__const__));

double sqrt(double x) __attribute__((__nothrow__ , __leaf__)) __attribute__((__const__));
double fabs(double x) __attribute__((__nothrow__ , __leaf__)) __attribute__((__const__));
double fmod(double x, double y) __attribute__((__nothrow__ , __leaf__)) __attribute__((__const__));

double floor(double x) __attribute__((__const__));
double ceil(double x) __attribute__((__const__));

double expm1(double x) __attribute__((__nothrow__ , __leaf__)) __attribute__((__const__));
double hypot(double x, double y) __attribute__((__nothrow__ , __leaf__)) __attribute__((__const__));
double atan2(double x, double y) __attribute__((__nothrow__ , __leaf__)) __attribute__((__const__));

double copysign(double value, double sign) __attribute__((__const__));
# 89 "include/math.h" 3 4
int isnan(double d) __attribute__((__const__));
int isinf(double d) __attribute__((__const__));
int finite(double d) __attribute__((__const__));

double j0(double x);
double j1(double x);
double jn(int n, double x);
double y0(double x);
double y1(double x);
double yn(int n, double x);
double erf(double x);
double erfc(double x);
double lgamma(double x);

double rint(double x);

double modf(double x, double * iptr);

double frexp(double x, int *exp);
double ldexp(double x, int exp);


# 2 "libc.h" 2


# 3 "libc.h"
int finite(double d) {
  return isinf(d)==0 && isnan(d)==0;
}

int __finite(double d) __attribute__((const, nothrow, leaf, alias("finite")));

# 1 "include/errno.h" 1 3 4
# 747 "include/errno.h" 3 4





# 751 "include/errno.h" 3 4
extern int *__errno_location(void);
# 768 "include/errno.h" 3 4

# 10 "libc.h" 2
# 1 "dietfeatures.h" 1
# 11 "libc.h" 2
# 1 "syscalls.h" 1
# 25 "syscalls.h"
# 1 "mips/syscalls.h" 1
# 719 "mips/syscalls.h"
# 1 "mips/mips-asm.h" 1
# 720 "mips/syscalls.h" 2
# 26 "syscalls.h" 2
# 12 "libc.h" 2
# 37 "libc.h"
# 1 "include/sys/stat.h" 1 3 4



# 1 "include/sys/time.h" 1 3 4




# 1 "include/sys/types.h" 1 3 4



# 1 "include/inttypes.h" 1 3 4




# 1 "include/endian.h" 1 3 4
# 6 "include/inttypes.h" 2 3 4


# 231 "include/inttypes.h" 3 4
typedef signed char int8_t;



typedef signed short int16_t;




typedef signed int int32_t;


typedef unsigned char uint8_t;



typedef unsigned short uint16_t;




typedef unsigned int uint32_t;
# 261 "include/inttypes.h" 3 4
__extension__ typedef signed long long int64_t;
__extension__ typedef unsigned long long uint64_t;
__extension__ typedef signed long long int intmax_t;
__extension__ typedef unsigned long long int uintmax_t;



typedef int intptr_t;
typedef unsigned int uintptr_t;





intmax_t strtoimax (const char *nptr, char **endptr, int base);
uintmax_t strtoumax (const char *nptr, char **endptr, int base);

intmax_t imaxabs(intmax_t j) __attribute__((const));
typedef struct { intmax_t quot,rem; } imaxdiv_t;
imaxdiv_t imaxdiv(intmax_t numerator, intmax_t denominator) __attribute__((const));


# 5 "include/sys/types.h" 2 3 4
# 1 "include/stddef.h" 1 3 4










typedef int ptrdiff_t;
typedef unsigned int size_t;

typedef int wchar_t;
# 36 "include/stddef.h" 3 4

# 6 "include/sys/types.h" 2 3 4



typedef unsigned long int blkcnt_t;
typedef unsigned long int blksize_t;
typedef unsigned long int clock_t;



typedef uint64_t fsblkcnt_t;
typedef uint64_t fsfilcnt_t;
# 60 "include/sys/types.h" 3 4
    typedef uint32_t dev_t;
    typedef int32_t gid_t;
    typedef uint32_t mode_t;
    typedef int32_t nlink_t;
    typedef int32_t uid_t;
# 79 "include/sys/types.h" 3 4
typedef int32_t id_t;


typedef unsigned long ino_t;
typedef int32_t key_t;
typedef int32_t pid_t;



typedef signed int ssize_t;
# 99 "include/sys/types.h" 3 4
typedef signed long suseconds_t;
typedef signed long useconds_t;




typedef signed long time_t;



__extension__ typedef signed long long loff_t;

__extension__ typedef signed long long off64_t;







typedef signed long off_t;



__extension__ typedef unsigned long long ino64_t;
__extension__ typedef signed long long blkcnt64_t;

typedef uint32_t uid32_t;
typedef uint32_t gid32_t;

typedef int32_t clockid_t;
typedef int32_t timer_t;

typedef long int fpos_t;


typedef uint32_t socklen_t;
typedef uint16_t sa_family_t;
# 176 "include/sys/types.h" 3 4

# 6 "include/sys/time.h" 2 3 4



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

# 1 "include/sys/select.h" 1 3 4



# 1 "include/string.h" 1 3 4








char *strcpy(char* __restrict__ dest, const char* __restrict__ src) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1,2)));

void *memccpy(void* __restrict__ dest, const void* __restrict__ src, int c, size_t n) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1,2)));
void *memmove(void* dest, const void *src, size_t n) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1,2)));

int memccmp(const void* s1, const void* s2, int c, size_t n) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1,2)));

void* memset(void* s, int c, size_t n) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
int memcmp(const void* s1, const void* s2, size_t n) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1,2)));
void* memcpy(void* __restrict__ dest, const void* __restrict__ src, size_t n) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1,2)));

char *strncpy(char* __restrict__ dest, const char* __restrict__ src, size_t n) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1,2)));
int strncmp(const char* s1, const char* s2, size_t n) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1,2)));

char *strcat(char* __restrict__ dest, const char* __restrict__ src) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1,2)));
char *strncat(char* __restrict__ dest, const char* __restrict__ src, size_t n) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1,2)));

int strcmp(const char *s1, const char *s2) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1,2)));

size_t strlen(const char *s) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
size_t strnlen(const char *s,size_t maxlen) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));





char *strstr(const char *haystack, const char *needle) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1,2)));

char *strdup(const char *s) __attribute__((__nothrow__ , __leaf__)) __attribute__((__malloc__)) __attribute__ ((__nonnull__ (1)));

char *strchr(const char *s, int c) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
char *strrchr(const char *s, int c) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));

size_t strspn(const char *s, const char *_accept) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1,2)));
size_t strcspn(const char *s, const char *reject) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1,2)));

char *strpbrk(const char *s, const char *_accept) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1,2)));
char *strsep(char ** __restrict__ stringp, const char * __restrict__ delim) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1,2)));

void* memchr(const void *s, int c, size_t n) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));






char *strerror(int errnum) __attribute__((__nothrow__ , __leaf__)) __attribute__((const));


int strerror_r(int errnum,char* buf,size_t n) __attribute__((__nothrow__ , __leaf__)) __attribute__((__deprecated__));
# 72 "include/string.h" 3 4
char *strtok(char * __restrict__ s, const char * __restrict__ delim) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
char *strtok_r(char * __restrict__ s, const char * __restrict__ delim, char ** __restrict__ ptrptr) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2,3)));

size_t strlcpy(char * __restrict__ dst, const char * __restrict__ src, size_t size) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1,2)));
size_t strlcat(char * __restrict__ dst, const char * __restrict__ src, size_t size) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1,2)));

int strcoll(const char *s1, const char *s2) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1,2)));
size_t strxfrm(char *dest, const char * __restrict__ src, size_t n) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1,2)));





char *stpcpy(char * __restrict__ dest, const char * __restrict__ src) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1,2)));
char* stpncpy(char* __restrict__ dest, const char* __restrict__ src, size_t n) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1,2)));
# 97 "include/string.h" 3 4
void explicit_bzero(void*, size_t) __attribute__((__nothrow__ , __leaf__)) __attribute__((noinline));





int timingsafe_memcmp(const void* s1, const void* s2, size_t n) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1,2))) __attribute__((noinline));
int timingsafe_bcmp(const void* s1, const void* s2, size_t n) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1,2))) __attribute__((noinline));



int consttime_memequal(void *b1, void *b2, size_t len) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1,2))) __attribute__((noinline));


void* explicit_memset(void *b, int c, size_t len) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__((noinline));


# 5 "include/sys/select.h" 2 3 4
# 1 "include/signal.h" 1 3 4






# 217 "include/signal.h" 3 4
typedef int sig_atomic_t;

typedef void (*sighandler_t)(int);
# 233 "include/signal.h" 3 4
typedef union sigval {
  int sival_int;
  void *sival_ptr;
} sigval_t;
# 248 "include/signal.h" 3 4
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
# 310 "include/signal.h" 3 4
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
# 443 "include/signal.h" 3 4
  unsigned long sa_flags;
  union {
    sighandler_t _sa_handler;
    void (*_sa_sigaction)(int, siginfo_t*, void*);
  } _u;
  sigset_t sa_mask;
  void (*sa_restorer)(void);
  int32_t sa_resv[1];
# 460 "include/signal.h" 3 4
};
# 476 "include/signal.h" 3 4
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

int sigaltstack(const struct sigaltstack *newstack, struct sigaltstack *oldstack) __attribute__((__nothrow__ , __leaf__));

int sigemptyset(sigset_t *set) __attribute__((__nothrow__ , __leaf__));
int sigfillset(sigset_t *set) __attribute__((__nothrow__ , __leaf__));
int sigaddset(sigset_t *set, int signum) __attribute__((__nothrow__ , __leaf__));
int sigdelset(sigset_t *set, int signum) __attribute__((__nothrow__ , __leaf__));
int sigismember(const sigset_t *set, int signo) __attribute__((__nothrow__ , __leaf__));
int sigsuspend(const sigset_t *mask) __attribute__((__nothrow__ , __leaf__));
int sigpending(sigset_t *set) __attribute__((__nothrow__ , __leaf__));
int sigprocmask(int how, const sigset_t *set, sigset_t *oldset) __attribute__((__nothrow__ , __leaf__));







sighandler_t signal(int signum, sighandler_t action);

int raise (int sig) __attribute__((__nothrow__ , __leaf__));
int kill(pid_t pid, int sig) __attribute__((__nothrow__ , __leaf__));

int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact) __attribute__((__nothrow__ , __leaf__));

# 1 "include/sys/time.h" 1 3 4
# 532 "include/signal.h" 2 3 4

int sigtimedwait(const sigset_t *mask, siginfo_t *info, const struct timespec *ts) __attribute__((__nothrow__ , __leaf__));
int sigqueueinfo(pid_t pid, int sig, siginfo_t *info) __attribute__((__nothrow__ , __leaf__));
int siginterrupt(int sig, int flag) __attribute__((__nothrow__ , __leaf__));

int killpg(pid_t pgrp, int sig) __attribute__((__nothrow__ , __leaf__));




int sigwait(const sigset_t* set,int* sig) __attribute__((__nothrow__ , __leaf__));

extern const char *const* sys_siglist;

# 1 "include/sys/ucontext.h" 1 3 4



# 1 "include/asm/sigcontext.h" 1 3 4






# 21 "include/asm/sigcontext.h" 3 4
# 1 "include/asm/mips-sigcontext.h" 1 3 4






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
# 22 "include/asm/sigcontext.h" 2 3 4
# 52 "include/asm/sigcontext.h" 3 4

# 5 "include/sys/ucontext.h" 2 3 4
# 1 "include/signal.h" 1 3 4
# 6 "include/sys/ucontext.h" 2 3 4




typedef struct sigcontext mcontext_t;



struct ucontext {
  unsigned long uc_flags;
  struct ucontext *uc_link;
  stack_t uc_stack;
  struct sigcontext uc_mcontext;
  sigset_t uc_sigmask;



};
# 126 "include/sys/ucontext.h" 3 4
typedef struct ucontext ucontext_t;


# 547 "include/signal.h" 2 3 4


# 6 "include/sys/select.h" 2 3 4



typedef long int fd_mask;







typedef struct {
  unsigned long fds_bits [(1024/(8 * sizeof(unsigned long)))];
} fd_set;







int select(int n, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout) __attribute__((__nothrow__ , __leaf__));

int pselect(int n, fd_set* readfds, fd_set* writefds, fd_set* exceptfds,
            const struct timespec *timeout, const sigset_t *sigmask) __attribute__((__nothrow__ , __leaf__));


# 25 "include/sys/time.h" 2 3 4





struct itimerspec {
  struct timespec it_interval;
  struct timespec it_value;
};

struct itimerval {
  struct timeval it_interval;
  struct timeval it_value;
};




typedef void *__timezone_ptr_t;


int getitimer(int which, struct itimerval *value) __attribute__((__nothrow__ , __leaf__));
int setitimer(int which, const struct itimerval *value, struct itimerval *ovalue) __attribute__((__nothrow__ , __leaf__));

int gettimeofday(struct timeval *tv, struct timezone *tz) __attribute__((__nothrow__ , __leaf__));
int settimeofday(const struct timeval *tv , const struct timezone *tz) __attribute__((__nothrow__ , __leaf__));

extern int adjtime (const struct timeval *delta, struct timeval *olddelta) __attribute__((__nothrow__ , __leaf__));

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
# 78 "include/sys/time.h" 3 4
int utimes(const char * filename, struct timeval * tvp) __attribute__((__nothrow__ , __leaf__));


# 5 "include/sys/stat.h" 2 3 4





# 235 "include/sys/stat.h" 3 4
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
# 692 "include/sys/stat.h" 3 4
extern int stat(const char *__file, struct stat *__buf) __attribute__((__nothrow__ , __leaf__));
extern int fstat(int __fd, struct stat *__buf) __attribute__((__nothrow__ , __leaf__));
extern int lstat(const char *__file, struct stat *__buf) __attribute__((__nothrow__ , __leaf__));




extern int stat64(const char *__file, struct stat64 *__buf) __attribute__((__nothrow__ , __leaf__));
extern int fstat64(int __fd, struct stat64 *__buf) __attribute__((__nothrow__ , __leaf__));
extern int lstat64(const char *__file, struct stat64 *__buf) __attribute__((__nothrow__ , __leaf__));
# 716 "include/sys/stat.h" 3 4
extern int chmod (const char *__file, mode_t __mode) __attribute__((__nothrow__ , __leaf__));
extern int fchmod (int __fd, mode_t __mode) __attribute__((__nothrow__ , __leaf__));
extern mode_t umask (mode_t __mask) __attribute__((__nothrow__ , __leaf__));
extern int mkdir (const char *__path, mode_t __mode) __attribute__((__nothrow__ , __leaf__));
extern int mknod (const char *__path, mode_t __mode, dev_t __dev) __attribute__((__nothrow__ , __leaf__));
extern int mkfifo (const char *__path, mode_t __mode) __attribute__((__nothrow__ , __leaf__));
# 730 "include/sys/stat.h" 3 4
int fchmodat(int dirfd, const char *pathname, mode_t mode, int flags) __attribute__((__nothrow__ , __leaf__));
int fstatat(int dirfd, const char *pathname, struct stat *buf, int flags) __attribute__((__nothrow__ , __leaf__));
int mkdirat(int dirfd, const char *pathname, mode_t mode) __attribute__((__nothrow__ , __leaf__));
int mknodat(int dirfd, const char *pathname, mode_t mode, dev_t dev) __attribute__((__nothrow__ , __leaf__));
int mkfifoat(int dirfd, const char *pathname, mode_t mode) __attribute__((__nothrow__ , __leaf__));
int utimensat(int dirfd, const char *pathname, struct timespec* t,int flags) __attribute__((__nothrow__ , __leaf__));



# 38 "libc.h" 2
# 1 "include/fcntl.h" 1 3 4







# 1 "include/unistd.h" 1 3 4






# 1 "include/sys/fsuid.h" 1 3 4








int setfsuid(uid_t uid);
int setfsgid(gid_t gid);
int setfsuid32(uid32_t fsuid) __attribute__((__nothrow__ , __leaf__));
int setfsgid32(gid32_t fsgid) __attribute__((__nothrow__ , __leaf__));


# 8 "include/unistd.h" 2 3 4




extern int optind,opterr,optopt;
extern char *optarg;
int getopt(int argc, char *const argv[], const char *options);
# 24 "include/unistd.h" 3 4
int access (const char *__name, int __type) __attribute__((__nothrow__ , __leaf__));
# 36 "include/unistd.h" 3 4
off_t lseek(int fildes, off_t offset, int whence) __attribute__((__nothrow__ , __leaf__));

loff_t lseek64(int fildes, loff_t offset, int whence) __attribute__((__nothrow__ , __leaf__));







int chdir(const char *path) __attribute__((__nothrow__ , __leaf__));
int fchdir(int fd) __attribute__((__nothrow__ , __leaf__));
int rmdir(const char *pathname) __attribute__((__nothrow__ , __leaf__));
char *getcwd(char *buf, size_t size) __attribute__((__nothrow__ , __leaf__)) __attribute__((__warn_unused_result__));







int open(const char* pathname,int flags, ...) __attribute__((__nothrow__ , __leaf__));
int open64(const char* pathname,int flags, ...) __attribute__((__nothrow__ , __leaf__));
int creat(const char* pathname,mode_t mode) __attribute__((__nothrow__ , __leaf__));
int creat64(const char* pathname,mode_t mode) __attribute__((__nothrow__ , __leaf__));
ssize_t write(int fd,const void* buf,size_t len) __attribute__((__nothrow__ , __leaf__));
ssize_t read(int fd,void* buf,size_t len) __attribute__((__nothrow__ , __leaf__));
int close(int fd) __attribute__((__nothrow__ , __leaf__));

int unlink(const char *pathname) __attribute__((__nothrow__ , __leaf__));

ssize_t pread(int fd, void *buf, size_t count, off_t offset);
ssize_t pwrite(int fd, const void *buf, size_t count, off_t offset);
ssize_t pread64(int fd, void *buf, size_t count, off64_t offset);
ssize_t pwrite64(int fd, const void *buf, size_t count, off64_t offset);

int execve(const char *filename, char *const argv [], char *const envp[]) __attribute__((__nothrow__ , __leaf__));
int execlp(const char *file, const char *arg, ...) __attribute__((__nothrow__ , __leaf__));
int execv(const char *path, char *const argv[]) __attribute__((__nothrow__ , __leaf__));
int execvp(const char *file, char *const argv[]) __attribute__((__nothrow__ , __leaf__));
int execl(const char *path, const char* arg, ...) __attribute__((__nothrow__ , __leaf__));
int execle(const char *path, const char* arg, ...) __attribute__((__nothrow__ , __leaf__));

pid_t getpid(void) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__pure__));

pid_t getppid(void) __attribute__((__nothrow__ , __leaf__));

int setpgid (pid_t pid,pid_t pgid) __attribute__((__nothrow__ , __leaf__));
pid_t getpgid (pid_t pid) __attribute__((__nothrow__ , __leaf__));
int setpgrp (void) __attribute__((__nothrow__ , __leaf__));
pid_t getpgrp (void) __attribute__((__nothrow__ , __leaf__));
pid_t getsid(pid_t pid) __attribute__((__nothrow__ , __leaf__));
pid_t setsid (void) __attribute__((__nothrow__ , __leaf__));
int dup (int oldfd) __attribute__((__nothrow__ , __leaf__));
int dup2 (int oldfd,int newfd) __attribute__((__nothrow__ , __leaf__));
# 103 "include/unistd.h" 3 4
struct dirent;
struct dirent64;
int getdents(int fd, struct dirent *dirp, unsigned int count) __attribute__((__nothrow__ , __leaf__));
int getdents64(int fd, struct dirent64 *dirp, unsigned int count) __attribute__((__nothrow__ , __leaf__));

pid_t fork(void) __attribute__((__nothrow__ , __leaf__));
pid_t vfork(void) __attribute__((__nothrow__ , __leaf__));

int readlink(const char *path, char *buf, size_t bufsiz) __attribute__((__nothrow__ , __leaf__));
int symlink(const char *oldpath, const char *newpath) __attribute__((__nothrow__ , __leaf__));
int link(const char *oldpath, const char *newpath) __attribute__((__nothrow__ , __leaf__));

int chown(const char *path, uid_t owner, gid_t group) __attribute__((__nothrow__ , __leaf__));
int fchown(int fd, uid_t owner, gid_t group) __attribute__((__nothrow__ , __leaf__));
int lchown(const char *path, uid_t owner, gid_t group) __attribute__((__nothrow__ , __leaf__));

int fsync(int fd) __attribute__((__nothrow__ , __leaf__));

int fdatasync(int fd) __attribute__((__nothrow__ , __leaf__));

int pipe(int filedes[2]) __attribute__((__nothrow__ , __leaf__));

char *ttyname (int desc) __attribute__((__nothrow__ , __leaf__));

int brk(void *end_data_segment) __attribute__((__nothrow__ , __leaf__));
void *sbrk(ptrdiff_t increment) __attribute__((__nothrow__ , __leaf__));

int gethostname(char *name, size_t len) __attribute__((__nothrow__ , __leaf__));
int sethostname(const char *name, size_t len) __attribute__((__nothrow__ , __leaf__));

int usleep(unsigned long useconds) __attribute__((__nothrow__ , __leaf__));
unsigned int sleep(unsigned int seconds) __attribute__((__nothrow__ , __leaf__));

unsigned int alarm(unsigned int seconds) __attribute__((__nothrow__ , __leaf__));
int sync(void) __attribute__((__nothrow__ , __leaf__));

int isatty(int desc) __attribute__((__nothrow__ , __leaf__));

void _exit(int status) __attribute__((__nothrow__ , __leaf__)) __attribute__((__noreturn__));

int daemon(int nochdir,int noclose) __attribute__((__nothrow__ , __leaf__));

int pause(void) __attribute__((__nothrow__ , __leaf__));

char* getlogin(void) __attribute__((__nothrow__ , __leaf__));


int chroot(const char *path) __attribute__((__nothrow__ , __leaf__));

uid_t getuid(void) __attribute__((__nothrow__ , __leaf__));
uid_t geteuid(void) __attribute__((__nothrow__ , __leaf__));
gid_t getgid(void) __attribute__((__nothrow__ , __leaf__));
gid_t getegid(void) __attribute__((__nothrow__ , __leaf__));
int setuid(uid_t uid) __attribute__((__nothrow__ , __leaf__));

int setgid(gid_t gid) __attribute__((__nothrow__ , __leaf__));

int setregid(gid_t rgid, gid_t egid) __attribute__((__nothrow__ , __leaf__));
int setreuid(uid_t ruid, uid_t euid) __attribute__((__nothrow__ , __leaf__));



int truncate(const char *path, off_t length) __attribute__((__nothrow__ , __leaf__));
int ftruncate(int fd, off_t length) __attribute__((__nothrow__ , __leaf__));

int truncate64(const char *path, loff_t length) __attribute__((__nothrow__ , __leaf__));
int ftruncate64(int fd, loff_t length) __attribute__((__nothrow__ , __leaf__));


int nice(int inc) __attribute__((__nothrow__ , __leaf__));

char *crypt(const char *key, const char *salt) __attribute__((__nothrow__ , __leaf__));
void encrypt(char block[64], int edflag) __attribute__((__nothrow__ , __leaf__));
void setkey(const char *key) __attribute__((__nothrow__ , __leaf__));







int getpagesize(void) __attribute__((__nothrow__ , __leaf__)) __attribute__((__const__,__pure__));

int getdomainname(char *name, size_t len) __attribute__((__nothrow__ , __leaf__));
int setdomainname(const char *name, size_t len) __attribute__((__nothrow__ , __leaf__));

int getgroups(int size, gid_t list[]) __attribute__((__nothrow__ , __leaf__));
int getdtablesize(void) __attribute__((__nothrow__ , __leaf__));
char *getpass(const char * prompt) __attribute__((__nothrow__ , __leaf__));


int llseek(int fildes, unsigned long hi, unsigned long lo, loff_t* result,int whence) __attribute__((__nothrow__ , __leaf__));


struct __sysctl_args;
int _sysctl(struct __sysctl_args *args) __attribute__((__nothrow__ , __leaf__));


size_t confstr(int name,char*buf,size_t len) __attribute__((__nothrow__ , __leaf__));
# 213 "include/unistd.h" 3 4
long sysconf(int name) __attribute__((__nothrow__ , __leaf__));



pid_t tcgetpgrp(int fd) __attribute__((__nothrow__ , __leaf__));
int tcsetpgrp(int fd, pid_t pgrpid) __attribute__((__nothrow__ , __leaf__));

int profil(unsigned short *buf, size_t bufsiz, size_t offset, unsigned int scale);


int getresuid(uid_t *ruid, uid_t *euid, uid_t *suid) __attribute__((__nothrow__ , __leaf__));
int getresgid(gid_t *rgid, gid_t *egid, gid_t *sgid) __attribute__((__nothrow__ , __leaf__));
int setresuid(uid_t ruid, uid_t euid, uid_t suid) __attribute__((__nothrow__ , __leaf__));
int setresgid(gid_t rgid, gid_t egid, gid_t sgid) __attribute__((__nothrow__ , __leaf__));


int chown32(const char *path, uid32_t owner, gid32_t group) __attribute__((__nothrow__ , __leaf__));
int fchown32(int fd, uid32_t owner, gid32_t group) __attribute__((__nothrow__ , __leaf__));
int lchown32(const char *path, uid32_t owner, gid32_t group) __attribute__((__nothrow__ , __leaf__));
uid32_t getuid32(void) __attribute__((__nothrow__ , __leaf__));
uid32_t geteuid32(void) __attribute__((__nothrow__ , __leaf__));
gid32_t getgid32(void) __attribute__((__nothrow__ , __leaf__));
gid32_t getegid32(void) __attribute__((__nothrow__ , __leaf__));
int setuid32(uid32_t uid) __attribute__((__nothrow__ , __leaf__));
int setgid32(gid32_t gid) __attribute__((__nothrow__ , __leaf__));
int setreuid32(uid32_t ruid, uid32_t euid) __attribute__((__nothrow__ , __leaf__));
int setregid32(gid32_t rgid, gid32_t egid) __attribute__((__nothrow__ , __leaf__));


int getgroups32(int size, gid32_t list[]) __attribute__((__nothrow__ , __leaf__));
int getresuid32(uid32_t *ruid, uid32_t *euid, uid32_t *suid);
int getresgid32(gid32_t *rgid, gid32_t *egid, gid32_t *sgid);
int setresuid32(uid32_t ruid, uid32_t euid, uid32_t suid) __attribute__((__nothrow__ , __leaf__));
int setresgid32(gid32_t rgid, gid32_t egid, gid32_t sgid) __attribute__((__nothrow__ , __leaf__));
# 256 "include/unistd.h" 3 4
char* cuserid(char * string);
# 265 "include/unistd.h" 3 4
int lockf (int __fd, int __cmd, off_t __len) __attribute__((__nothrow__ , __leaf__));
int lockf64 (int __fd, int __cmd, off64_t __len) __attribute__((__nothrow__ , __leaf__));

void swab(const void *src, void *dest, ssize_t nbytes) __attribute__((__nothrow__ , __leaf__));

int vhangup(void) __attribute__((__nothrow__ , __leaf__));

extern char **__environ;
# 304 "include/unistd.h" 3 4
int faccessat(int dirfd, const char *pathname, int mode, int flags) __attribute__((__nothrow__ , __leaf__));
int fchownat(int dirfd, const char *pathname, uid_t owner, gid_t group, int flags) __attribute__((__nothrow__ , __leaf__));
int linkat(int olddirfd, const char *oldpath, int newdirfd, const char *newpath, int flags) __attribute__((__nothrow__ , __leaf__));
int readlinkat(int dirfd, const char *pathname, char *buf, size_t bufsiz) __attribute__((__nothrow__ , __leaf__));





# 9 "include/fcntl.h" 2 3 4

# 1 "include/sys/uio.h" 1 3 4



# 1 "include/sys/socket.h" 1 3 4





# 1 "include/fcntl.h" 1 3 4
# 7 "include/sys/socket.h" 2 3 4
# 1 "include/sys/uio.h" 1 3 4
# 8 "include/sys/socket.h" 2 3 4


# 388 "include/sys/socket.h" 3 4
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
# 423 "include/sys/socket.h" 3 4
struct ucred {
  pid_t pid;
  uid_t uid;
  gid_t gid;
};
# 610 "include/sys/socket.h" 3 4
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
# 633 "include/sys/socket.h" 3 4
struct sockaddr_storage {
  sa_family_t ss_family;
  uint32_t __ss_align;
  char __ss_padding[(128 - (2 * sizeof (uint32_t ))) ];
};

int socket(int domain, int type, int protocol) __attribute__((__nothrow__ , __leaf__));
int accept(int s, void *addr, void *addrlen) __attribute__((__nothrow__ , __leaf__));
int connect(int sockfd, void *serv_addr, int addrlen) __attribute__((__nothrow__ , __leaf__));
int bind(int sockfd, void *my_addr, int addrlen) __attribute__((__nothrow__ , __leaf__));
int recv(int s, void *buf, size_t len, int flags) __attribute__((__nothrow__ , __leaf__));
int recvfrom(int s, void *buf, size_t len, int flags, struct sockaddr *from, socklen_t *fromlen) __attribute__((__nothrow__ , __leaf__));
int recvmsg(int s, struct msghdr *msg, int flags) __attribute__((__nothrow__ , __leaf__));
int send(int s, const void *msg, size_t len, int flags) __attribute__((__nothrow__ , __leaf__));
int sendto(int s, const void *msg, size_t len, int flags, const struct sockaddr *to, socklen_t tolen) __attribute__((__nothrow__ , __leaf__));
int sendmsg(int s, const struct msghdr *msg, int flags) __attribute__((__nothrow__ , __leaf__));

int getpeername(int s, struct sockaddr *name, socklen_t *namelen) __attribute__((__nothrow__ , __leaf__));
int getsockname(int s , struct sockaddr * name , socklen_t * namelen) __attribute__((__nothrow__ , __leaf__));

int getsockopt(int s, int level, int optname, void *optval, socklen_t *optlen) __attribute__((__nothrow__ , __leaf__));
int setsockopt(int s, int level, int optname, const void *optval, socklen_t optlen) __attribute__((__nothrow__ , __leaf__));

int listen(int s, int backlog) __attribute__((__nothrow__ , __leaf__));




int shutdown(int s, int how) __attribute__((__nothrow__ , __leaf__));

int socketpair(int d, int type, int protocol, int sv[2]) __attribute__((__nothrow__ , __leaf__));
# 685 "include/sys/socket.h" 3 4
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

int getnameinfo(const struct sockaddr *sa, socklen_t salen, char *host,
  size_t hostlen, char *serv, size_t servlen, int flags) __attribute__((__nothrow__ , __leaf__));
int getaddrinfo(const char *node, const char *service, const struct
  addrinfo *hints, struct addrinfo **res) __attribute__((__nothrow__ , __leaf__));
void freeaddrinfo(struct addrinfo *res) __attribute__((__nothrow__ , __leaf__));
const char *gai_strerror(int errcode) __attribute__((__nothrow__ , __leaf__));
# 814 "include/sys/socket.h" 3 4

# 5 "include/sys/uio.h" 2 3 4



struct iovec {
  void* iov_base;
  size_t iov_len;
};


ssize_t readv(int filedes, const struct iovec *vector, int count) __attribute__((__nothrow__ , __leaf__));
ssize_t writev(int filedes, const struct iovec *vector, int count) __attribute__((__nothrow__ , __leaf__));

ssize_t preadv(int fd, const struct iovec *iov, int iovcnt, off_t offset) __attribute__((__nothrow__ , __leaf__));
ssize_t pwritev(int fd, const struct iovec *iov, int iovcnt, off_t offset) __attribute__((__nothrow__ , __leaf__));


# 11 "include/fcntl.h" 2 3 4


# 251 "include/fcntl.h" 3 4
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
# 690 "include/fcntl.h" 3 4
extern int fcntl (int __fd, int __cmd, ...) __attribute__((__nothrow__ , __leaf__));

extern int fcntl64 (int __fd, int __cmd, ...) __attribute__((__nothrow__ , __leaf__));
extern int fstatat64(int dirfd, const char *pathname, struct stat64 *buf, int flags) __attribute__((__nothrow__ , __leaf__));
# 758 "include/fcntl.h" 3 4
struct f_owner_ex {
 int type;
 int pid;
};
# 773 "include/fcntl.h" 3 4
int openat(int dirfd, const char *pathname, int flags, ...) __attribute__((__nothrow__ , __leaf__));
int futimesat(int dirfd, const char *pathname, const struct timeval times[2]) __attribute__((__nothrow__ , __leaf__));
int unlinkat(int dirfd, const char *pathname, int flags) __attribute__((__nothrow__ , __leaf__));








# 39 "libc.h" 2

# 39 "libc.h"
int fstatat(int dirfd, const char* pathname, struct stat *buf, int flags) {
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
      
# 56 "libc.h" 3 4
     (*__errno_location())
# 56 "libc.h"
          =
# 56 "libc.h" 3 4
           79
# 56 "libc.h"
                    ;
  }
  return 0;
}




# 1 "include/sys/statfs.h" 1 3 4










# 10 "include/sys/statfs.h" 3 4
typedef struct {
  int32_t __val[2];
} __kernel_fsid_t;
# 51 "include/sys/statfs.h" 3 4
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
# 181 "include/sys/statfs.h" 3 4
int statfs(const char *path, struct statfs *buf) __attribute__((__nothrow__ , __leaf__));
int fstatfs(int fd, struct statfs *buf) __attribute__((__nothrow__ , __leaf__));


int statfs64(const char *path, struct statfs64 *buf) __attribute__((__nothrow__ , __leaf__));
int fstatfs64(int fd, struct statfs64 *buf) __attribute__((__nothrow__ , __leaf__));








# 65 "libc.h" 2




# 68 "libc.h"
extern int __dietlibc_fstatfs64(int fd, size_t bufsize, struct statfs64 *__buf);
extern void __statfs64_cvt(const struct statfs *src,struct statfs64 *dest);

int fstatfs64(int fd, struct statfs64 *__buf) {

  if (__dietlibc_fstatfs64(fd,sizeof(*__buf),__buf)) {
    struct statfs temp;
    if (
# 75 "libc.h" 3 4
       (*__errno_location())
# 75 "libc.h"
            !=
# 75 "libc.h" 3 4
              89
# 75 "libc.h"
                    ) return -1;
    if (fstatfs(fd,&temp)) return -1;
    __statfs64_cvt(&temp,__buf);
  }
  return 0;



}





# 1 "syscalls.h" 1
# 25 "syscalls.h"
# 1 "mips/syscalls.h" 1
# 26 "syscalls.h" 2
# 90 "libc.h" 2




extern int __dietlibc_ftruncate64(int fd, loff_t o);

int ftruncate64(int fd, loff_t o) {
  int tmp;
  if ((tmp=__dietlibc_ftruncate64(fd,o))==-1) {
    if (
# 99 "libc.h" 3 4
       (*__errno_location())
# 99 "libc.h"
            !=
# 99 "libc.h" 3 4
              89
# 99 "libc.h"
                    ) return -1;
    if (o>0x7fffffff) { 
# 100 "libc.h" 3 4
                       (*__errno_location())
# 100 "libc.h"
                            =
# 100 "libc.h" 3 4
                             79
# 100 "libc.h"
                                      ; return -1; }
    return ftruncate(fd,o);
  }
  return tmp;
}



# 1 "include/sys/tls.h" 1 3 4





# 1 "include/stdbool.h" 1 3 4
# 7 "include/sys/tls.h" 2 3 4



# 9 "include/sys/tls.h" 3 4
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

tcbhead_t* __get_cur_tcb(void) __attribute__((__nothrow__ , __leaf__));
# 109 "libc.h" 2


# 110 "libc.h"
tcbhead_t* __get_cur_tcb(void) {




  register void* cur=0;
# 132 "libc.h"
  return cur;
}

# 1 "include/stdlib.h" 1 3 4







# 1 "include/alloca.h" 1 3 4















# 9 "include/stdlib.h" 2 3 4




# 12 "include/stdlib.h" 3 4
void *calloc(size_t nmemb, size_t size) __attribute__((__nothrow__ , __leaf__)) __attribute__((__malloc__));
void *malloc(size_t size) __attribute__((__nothrow__ , __leaf__)) __attribute__((__malloc__));
void free(void *ptr) __attribute__((__nothrow__ , __leaf__));
void *realloc(void *ptr, size_t size) __attribute__((__nothrow__ , __leaf__)) __attribute__((__malloc__));


void* reallocarray(void* ptr, size_t nmemb, size_t size) __attribute__((__nothrow__ , __leaf__)) __attribute__((__malloc__)) __attribute__((alloc_size(2,3)));

char *getenv(const char *name) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__pure__));
int putenv(const char *string) __attribute__((__nothrow__ , __leaf__));
int setenv(const char *name, const char *value, int overwrite) __attribute__((__nothrow__ , __leaf__));
int unsetenv(const char *name) __attribute__((__nothrow__ , __leaf__));

int system (const char * string) __attribute__((__nothrow__ , __leaf__));
int atexit(void (*function)(void)) __attribute__((__nothrow__ , __leaf__));

float strtof(const char *nptr, char **endptr) __attribute__((__nothrow__ , __leaf__));
double strtod(const char *nptr, char **endptr) __attribute__((__nothrow__ , __leaf__));
long double strtold(const char *nptr, char **endptr) __attribute__((__nothrow__ , __leaf__));
long int strtol(const char *nptr, char **endptr, int base) __attribute__((__nothrow__ , __leaf__));
unsigned long int strtoul(const char *nptr, char **endptr, int base) __attribute__((__nothrow__ , __leaf__));

extern int __ltostr(char *s, unsigned int size, unsigned long i, unsigned int base, int UpCase) __attribute__((__nothrow__ , __leaf__));
extern int __dtostr(double d,char *buf,unsigned int maxlen,unsigned int prec,unsigned int prec2,int flags) __attribute__((__nothrow__ , __leaf__));


__extension__ long long int strtoll(const char *nptr, char **endptr, int base) __attribute__((__nothrow__ , __leaf__));
__extension__ unsigned long long int strtoull(const char *nptr, char **endptr, int base) __attribute__((__nothrow__ , __leaf__));
__extension__ int __lltostr(char *s, unsigned int size, unsigned long long i, unsigned int base, int UpCase) __attribute__((__nothrow__ , __leaf__));


int atoi(const char *nptr) __attribute__((__nothrow__ , __leaf__));
long int atol(const char *nptr) __attribute__((__nothrow__ , __leaf__));
double atof(const char *nptr) __attribute__((__nothrow__ , __leaf__));
__extension__ long long int atoll(const char *nptr);

void exit(int status) __attribute__((__nothrow__ , __leaf__)) __attribute__((__noreturn__));
void abort(void) __attribute__((__nothrow__ , __leaf__)) __attribute__((__noreturn__));

extern int rand(void) __attribute__((__nothrow__ , __leaf__));
extern int rand_r(unsigned int *seed) __attribute__((__nothrow__ , __leaf__));
extern void srand(unsigned int seed) __attribute__((__nothrow__ , __leaf__));





typedef unsigned short randbuf[3];
double drand48(void) __attribute__((__nothrow__ , __leaf__));
long lrand48(void) __attribute__((__nothrow__ , __leaf__));
long mrand48(void) __attribute__((__nothrow__ , __leaf__));
void srand48(long seed) __attribute__((__nothrow__ , __leaf__));
unsigned short *seed48(randbuf buf) __attribute__((__nothrow__ , __leaf__));
void lcong48(unsigned short param[7]) __attribute__((__nothrow__ , __leaf__));
long jrand48(randbuf buf) __attribute__((__nothrow__ , __leaf__));
long nrand48(randbuf buf) __attribute__((__nothrow__ , __leaf__));
double erand48(randbuf buf) __attribute__((__nothrow__ , __leaf__));

void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));
void *bsearch(const void *key, const void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));

extern char **environ;

char *realpath(const char *path, char *resolved_path) __attribute__((__nothrow__ , __leaf__));

int mkstemp(char *_template);
char* mkdtemp(char *_template);

char* mktemp(char *_template);

int abs(int i) __attribute__((__nothrow__ , __leaf__)) __attribute__((__const__));
long int labs(long int i) __attribute__((__nothrow__ , __leaf__)) __attribute__((__const__));
__extension__ long long int llabs(long long int i) __attribute__((__nothrow__ , __leaf__)) __attribute__((__const__));
# 104 "include/stdlib.h" 3 4
typedef struct { int quot,rem; } div_t;
typedef struct { long quot,rem; } ldiv_t;

div_t div(int numerator, int denominator);
ldiv_t ldiv(long numerator, long denominator);

typedef struct { long long quot,rem; } lldiv_t;
lldiv_t lldiv(long long numerator, long long denominator);






int mbtowc(wchar_t *pwc, const char *s, size_t n) __attribute__((__nothrow__ , __leaf__));
int wctomb(char *s, wchar_t wc) __attribute__((__nothrow__ , __leaf__));
size_t mbstowcs(wchar_t *dest, const char *src, size_t n) __attribute__((__nothrow__ , __leaf__));
int mblen(const char* s,size_t n) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__pure__));

size_t wcstombs(char *dest, const wchar_t *src, size_t n) __attribute__((__nothrow__ , __leaf__));


uint32_t arc4random(void) __attribute__((__nothrow__ , __leaf__));
void arc4random_buf(void* buf, size_t n) __attribute__((__nothrow__ , __leaf__));
uint32_t arc4random_uniform(uint32_t upper_bound) __attribute__((__nothrow__ , __leaf__));
void arc4random_stir(void) __attribute__((__nothrow__ , __leaf__));
void arc4random_addrandom(unsigned char* dat,size_t datlen) __attribute__((__nothrow__ , __leaf__));


# 136 "libc.h" 2



# 138 "libc.h"
extern int __syscall_getcwd(char* buf, size_t size);

char *getcwd(char *buf, size_t size) {
  if (
# 141 "libc.h" 3 4
     __builtin_expect((long)((
# 141 "libc.h"
     !size
# 141 "libc.h" 3 4
     )),0)
# 141 "libc.h"
                      ) {
    
# 142 "libc.h" 3 4
   (*__errno_location())
# 142 "libc.h"
        =
# 142 "libc.h" 3 4
         22
# 142 "libc.h"
               ;
    buf=0;
  } else {
    int tmp;
    if ((tmp=__syscall_getcwd(buf,size-1))<0) return 0;
    buf[tmp]=0;
  }
  return buf;
}
# 1 "include/sys/inotify.h" 1 3 4







# 7 "include/sys/inotify.h" 3 4
struct inotify_event {
  int32_t wd;
  uint32_t mask,
    cookie,
    len;
  char name[0];
};
# 59 "include/sys/inotify.h" 3 4


int inotify_init(void) __attribute__((__nothrow__ , __leaf__));
int inotify_init1(int flags) __attribute__((__nothrow__ , __leaf__));
int inotify_add_watch(int fd,const char* path,unsigned long mask) __attribute__((__nothrow__ , __leaf__));
int inotify_rm_watch(int fd,int wd) __attribute__((__nothrow__ , __leaf__));


# 152 "libc.h" 2
# 1 "syscalls.h" 1
# 25 "syscalls.h"
# 1 "mips/syscalls.h" 1
# 26 "syscalls.h" 2
# 153 "libc.h" 2
# 161 "libc.h"

# 161 "libc.h"
int isinf(double d) {
  union {
    unsigned long long l;
    double d;
  } u;
  u.d=d;
  return (u.l==0x7FF0000000000000ll?1:u.l==0xFFF0000000000000ll?-1:0);
}
int __isinf(double d) __attribute__((const, nothrow, leaf, alias("isinf")));
# 180 "libc.h"
int isnan(double d) {
  union {
    unsigned long long l;
    double d;
  } u;
  u.d=d;
  return (u.l==0x7FF8000000000000ll || u.l==0x7FF0000000000000ll || u.l==0xfff8000000000000ll);
}
int __isnan(double d) __attribute__((const, nothrow, leaf, alias("isnan")));
# 199 "libc.h"
int __lltostr(char *s, unsigned int size, unsigned long long i, unsigned int base, int UpCase);

int __lltostr(char *s, unsigned int size, unsigned long long i, unsigned int base, int UpCase)
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






extern int __dietlibc_lstat64(const char *__file, struct stat64 *__buf);
extern void __stat64_cvt(const struct stat *src,struct stat64 *dest);

int lstat64(const char *__file, struct stat64 *__buf) {
  if (__dietlibc_lstat64(__file,__buf)) {
    struct stat temp;
    if (
# 242 "libc.h" 3 4
       (*__errno_location())
# 242 "libc.h"
            !=
# 242 "libc.h" 3 4
              89
# 242 "libc.h"
                    ) return -1;
    if (lstat(__file,&temp)) return -1;
    __stat64_cvt(&temp,__buf);
  }
  return 0;
}





int __ltostr(char *s, unsigned int size, unsigned long i, unsigned int base, int UpCase)
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

# 1 "include/sys/mman.h" 1 3 4








# 263 "include/sys/mman.h" 3 4

# 263 "include/sys/mman.h" 3 4
extern void *mmap (void *__addr, size_t __len, int __prot,
                   int __flags, int __fd, off_t __offset);

extern int munmap (void *__addr, size_t __len) __attribute__((__nothrow__ , __leaf__));
extern int mprotect (void *__addr, size_t __len, int __prot) __attribute__((__nothrow__ , __leaf__));
extern int msync (void *__addr, size_t __len, int __flags) __attribute__((__nothrow__ , __leaf__));
extern void *mremap (void *__addr, size_t __old_len, size_t __new_len,
       unsigned long __may_move) __attribute__((__nothrow__ , __leaf__));
extern int mincore (void *__start, size_t __len, unsigned char *__vec);

extern void *mmap64 (void *__addr, size_t __len, int __prot,
       int __flags, int __fd, off64_t __offset) __attribute__((__nothrow__ , __leaf__));







int mlockall(int flags) __attribute__((__nothrow__ , __leaf__));
int mlock(const void *addr, size_t len) __attribute__((__nothrow__ , __leaf__));
int munlock(const void *addr, size_t len) __attribute__((__nothrow__ , __leaf__));
int munlockall(void) __attribute__((__nothrow__ , __leaf__));
int mlock2(const void *addr, size_t len, int flags) __attribute__((__nothrow__ , __leaf__));

int madvise(void *start, size_t length, int advice) __attribute__((__nothrow__ , __leaf__));
# 298 "include/sys/mman.h" 3 4

# 284 "libc.h" 2
# 1 "./syscalls.h" 1
# 25 "./syscalls.h"
# 1 "./mips/syscalls.h" 1
# 719 "./mips/syscalls.h"
# 1 "./mips/mips-asm.h" 1
# 720 "./mips/syscalls.h" 2
# 26 "./syscalls.h" 2
# 285 "libc.h" 2
# 308 "libc.h"
# 1 "include/sys/ptrace.h" 1 3 4







# 631 "include/sys/ptrace.h" 3 4
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
# 923 "include/sys/ptrace.h" 3 4
extern long int 
# 923 "include/sys/ptrace.h"
               fnord
# 923 "include/sys/ptrace.h" 3 4
                     (int request, ...) __attribute__((__nothrow__ , __leaf__));


# 309 "libc.h" 2





# 313 "libc.h"
extern int __diet_ptrace(int request, pid_t pid, void *addr, void *data);
int ptrace(int request, pid_t pid, void *addr, void *data);

int ptrace(int request, pid_t pid, void *addr, void *data) {
  
# 317 "libc.h" 3 4
 (*__errno_location())
# 317 "libc.h"
      =0;
  switch (request) {
    case 
# 319 "libc.h" 3 4
        0
# 319 "libc.h"
                      : case 
# 319 "libc.h" 3 4
                             8
# 319 "libc.h"
                                        : case 
# 319 "libc.h" 3 4
                                               0x10
# 319 "libc.h"
                                                            :
    case 
# 320 "libc.h" 3 4
        0x11
# 320 "libc.h"
                     :
      return (__diet_ptrace (request, pid, 
# 321 "libc.h" 3 4
                                          (void*)0
# 321 "libc.h"
                                              , 
# 321 "libc.h" 3 4
                                                (void*)0
# 321 "libc.h"
                                                    ));
    case 
# 322 "libc.h" 3 4
        2
# 322 "libc.h"
                       : case 
# 322 "libc.h" 3 4
                              3
# 322 "libc.h"
                                             : case 
# 322 "libc.h" 3 4
                                                    1
# 322 "libc.h"
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

# 1 "include/sched.h" 1 3 4



# 1 "include/time.h" 1 3 4
# 9 "include/time.h" 3 4



# 11 "include/time.h" 3 4
int __isleap(int year);
# 20 "include/time.h" 3 4
int clock_settime(clockid_t clock_id,const struct timespec*tp);
int clock_gettime(clockid_t clock_id,struct timespec*tp);
int clock_getres(clockid_t clock_id,struct timespec*res);
int clock_nanosleep(clockid_t clock_id, int flags,const struct timespec *rqtp, struct timespec *rmtp);



int timer_create(clockid_t clock_id,struct sigevent*evp,timer_t*timerid) __attribute__((__nothrow__ , __leaf__));
int timer_delete(timer_t timerid) __attribute__((__nothrow__ , __leaf__));
int timer_settime(timer_t timerid,int flags,const struct itimerspec*ival,struct itimerspec*oval) __attribute__((__nothrow__ , __leaf__));
int timer_gettime(timer_t timerid,const struct itimerspec*val) __attribute__((__nothrow__ , __leaf__));
int timer_getoverrun(timer_t timerid) __attribute__((__nothrow__ , __leaf__));

int nanosleep(const struct timespec *req, struct timespec *rem) __attribute__((__nothrow__ , __leaf__));

time_t mktime(struct tm *timeptr) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__pure__));

char *asctime(const struct tm *timeptr) __attribute__((__nothrow__ , __leaf__));
char *asctime_r(const struct tm *timeptr, char *buf) __attribute__((__nothrow__ , __leaf__));

char *ctime(const time_t *timep) __attribute__((__nothrow__ , __leaf__));
char *ctime_r(const time_t *timep, char* buf) __attribute__((__nothrow__ , __leaf__));

size_t strftime(char *s, size_t max, const char *format, const struct tm *tm) __attribute__((__nothrow__ , __leaf__)) __attribute__((__format__(__strftime__,3,0)));
time_t time(time_t *t) __attribute__((__nothrow__ , __leaf__));

int stime(time_t *t) __attribute__((__nothrow__ , __leaf__));

double difftime(time_t time1, time_t time0) __attribute__((__nothrow__ , __leaf__)) __attribute__((__const__));



extern long int timezone;
extern int daylight;
extern char* tzname[2];

void tzset (void) __attribute__((__nothrow__ , __leaf__));

struct tm* localtime(const time_t* t) __attribute__((__nothrow__ , __leaf__));
struct tm* gmtime(const time_t* t) __attribute__((__nothrow__ , __leaf__));
struct tm* localtime_r(const time_t* t, struct tm* r) __attribute__((__nothrow__ , __leaf__));
struct tm* gmtime_r(const time_t* t, struct tm* r) __attribute__((__nothrow__ , __leaf__));

clock_t clock(void);

char *strptime(const char *s, const char *format, struct tm *tm);


time_t timegm(struct tm *timeptr) __attribute__((__nothrow__ , __leaf__)) __attribute__((__deprecated__)) __attribute__ ((__pure__)) ;
time_t timelocal(struct tm *timeptr) __attribute__((__nothrow__ , __leaf__)) __attribute__((__deprecated__)) __attribute__ ((__pure__));





# 5 "include/sched.h" 2 3 4



# 22 "include/sched.h" 3 4
struct sched_param {
  int sched_priority;
};



int __sched_setparam(pid_t pid, const struct sched_param* p) __attribute__((__nothrow__ , __leaf__));
int sched_setparam(pid_t pid, const struct sched_param* p) __attribute__((__nothrow__ , __leaf__));

int __sched_getparam(pid_t pid, struct sched_param* p) __attribute__((__nothrow__ , __leaf__));
int sched_getparam(pid_t pid, struct sched_param* p) __attribute__((__nothrow__ , __leaf__));

int __sched_getscheduler(pid_t pid) __attribute__((__nothrow__ , __leaf__));
int sched_getscheduler(pid_t pid) __attribute__((__nothrow__ , __leaf__));

int __sched_setscheduler(pid_t pid, int policy, const struct sched_param* p) __attribute__((__nothrow__ , __leaf__));
int sched_setscheduler(pid_t pid, int policy, const struct sched_param* p) __attribute__((__nothrow__ , __leaf__));

int __sched_yield(void) __attribute__((__nothrow__ , __leaf__));
int sched_yield(void) __attribute__((__nothrow__ , __leaf__));

int __sched_get_priority_max(int policy) __attribute__((__nothrow__ , __leaf__));
int sched_get_priority_max(int policy) __attribute__((__nothrow__ , __leaf__));

int __sched_get_priority_min(int policy) __attribute__((__nothrow__ , __leaf__));
int sched_get_priority_min(int policy) __attribute__((__nothrow__ , __leaf__));

int __sched_rr_get_interval(pid_t pid, struct timespec* tp) __attribute__((__nothrow__ , __leaf__));
int sched_rr_get_interval(pid_t pid, struct timespec* tp) __attribute__((__nothrow__ , __leaf__));
# 83 "include/sched.h" 3 4
int clone(int (*fn)(void*),void* stack,int flags,void* arg, ...) __attribute__((__nothrow__ , __leaf__));

int unshare(int flags) __attribute__((__nothrow__ , __leaf__));

long set_tid_address(int* tid) __attribute__((__nothrow__ , __leaf__));







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

int sched_setaffinity(pid_t pid, size_t size, cpu_set_t *mask) __attribute__((__nothrow__ , __leaf__));
int sched_getaffinity(pid_t pid, size_t size, cpu_set_t *mask) __attribute__((__nothrow__ , __leaf__));



int setns(int fd,int nstype) __attribute__((__nothrow__ , __leaf__));




# 335 "libc.h" 2


# 336 "libc.h"
extern int __syscall_sched_getaffinity(pid_t, size_t, cpu_set_t*);

int sched_getaffinity(pid_t pid, size_t size, cpu_set_t *mask)
{
 int ret;

 *mask = 0;
 ret = __syscall_sched_getaffinity(pid, size, mask);
 if (ret > 0)
  return 0;
 return ret;
}



# 1 "include/sys/sendfile.h" 1 3 4










# 10 "include/sys/sendfile.h" 3 4
extern ssize_t sendfile (int out_fd, int in_fd, off_t* offset,
    size_t count) __attribute__((__nothrow__ , __leaf__));


extern ssize_t sendfile64 (int out_fd, int in_fd, loff_t* offset,
      size_t count) __attribute__((__nothrow__ , __leaf__));







# 352 "libc.h" 2



# 354 "libc.h"
extern ssize_t __dietlibc_sendfile64 (int out_fd, int in_fd, loff_t* offset,
      size_t count);

ssize_t sendfile64 (int out_fd, int in_fd, loff_t* offset, size_t count) {
  static int havesendfile64=1;
  ssize_t r = -1;
  if (havesendfile64) {
    r=__dietlibc_sendfile64(out_fd,in_fd,offset,count);
    if (r==-1 && 
# 362 "libc.h" 3 4
                (*__errno_location())
# 362 "libc.h"
                     ==
# 362 "libc.h" 3 4
                       89
# 362 "libc.h"
                             )
      havesendfile64=0;
  }
  if (!havesendfile64) {
    off_t o=*offset;
    if (*offset>0x7fffffff) { 
# 367 "libc.h" 3 4
                             (*__errno_location())
# 367 "libc.h"
                                  =
# 367 "libc.h" 3 4
                                   22
# 367 "libc.h"
                                         ; return -1; }
    r=sendfile(out_fd,in_fd,&o,count);
    *offset=o;
    return r;
  }
  return r;
}






void __setup_tls(tcbhead_t* mainthread);


extern 
# 383 "libc.h" 3 4
      __attribute__((visibility("hidden"))) 
# 383 "libc.h"
                 unsigned long __guard;


void __setup_tls(tcbhead_t* mainthread) {
  mainthread->tcb=mainthread;
  mainthread->dtv=0;
  mainthread->self=0;
  mainthread->multiple_threads=0;

  mainthread->stack_guard=__guard;
# 443 "libc.h"
}






extern int __dietlibc_stat64(const char *__file, struct stat64 *__buf);
extern void __stat64_cvt(const struct stat *src,struct stat64 *dest);

int stat64(const char *__file, struct stat64 *__buf) {
  if (__dietlibc_stat64(__file,__buf)) {
    struct stat temp;
    if (
# 456 "libc.h" 3 4
       (*__errno_location())
# 456 "libc.h"
            !=
# 456 "libc.h" 3 4
              89
# 456 "libc.h"
                    ) return -1;
    if (stat(__file,&temp)) return -1;
    __stat64_cvt(&temp,__buf);
  }
  return 0;
}





void __stat64_cvt(const struct stat *src,struct stat64 *dest);

void __stat64_cvt(const struct stat *src,struct stat64 *dest) {
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







extern int __dietlibc_statfs64(const char *path, size_t bufsize, struct statfs64 *__buf);
extern void __statfs64_cvt(const struct statfs *src,struct statfs64 *dest);

int statfs64(const char *__file, struct statfs64 *__buf) {

  if (__dietlibc_statfs64(__file,sizeof(*__buf),__buf)) {
    struct statfs temp;
    if (
# 498 "libc.h" 3 4
       (*__errno_location())
# 498 "libc.h"
            !=
# 498 "libc.h" 3 4
              89
# 498 "libc.h"
                    ) return -1;
    if (statfs(__file,&temp)) return -1;
    __statfs64_cvt(&temp,__buf);
  }
  return 0;



}




# 1 "./syscalls.h" 1
# 25 "./syscalls.h"
# 1 "./mips/syscalls.h" 1
# 26 "./syscalls.h" 2
# 512 "libc.h" 2
# 527 "libc.h"
struct __sysctl_args {
 int *name;
 int nlen;
 void *oldval;
 size_t *oldlenp;
 void *newval;
 size_t newlen;
 unsigned long __unused[4];
};

extern int sysctl (int *, int, void *, size_t *, void *, size_t);

int
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


# 1 "./syscalls.h" 1
# 25 "./syscalls.h"
# 1 "./mips/syscalls.h" 1
# 26 "./syscalls.h" 2
# 554 "libc.h" 2
# 570 "libc.h"
# 1 "syscalls.h" 1
# 25 "syscalls.h"
# 1 "mips/syscalls.h" 1
# 26 "syscalls.h" 2
# 571 "libc.h" 2




extern int __dietlibc_truncate64(const char* f, loff_t o);

int truncate64(const char* f, loff_t o) {
  int tmp;
  if ((tmp=__dietlibc_truncate64(f,o))==-1) {
    if (
# 580 "libc.h" 3 4
       (*__errno_location())
# 580 "libc.h"
            !=
# 580 "libc.h" 3 4
              89
# 580 "libc.h"
                    ) return -1;
    if (o>0x7fffffff) { 
# 581 "libc.h" 3 4
                       (*__errno_location())
# 581 "libc.h"
                            =
# 581 "libc.h" 3 4
                             79
# 581 "libc.h"
                                      ; return -1; }
    return truncate(f,o);
  }
  return tmp;
}



# 1 "include/sys/mount.h" 1 3 4
















# 16 "include/sys/mount.h" 3 4
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
# 114 "include/sys/mount.h" 3 4
enum
{
  MNT_FORCE = 1,

  MNT_DETACH = 2

};

int mount(const char* specialfile, const char* dir, const char* filesystemtype,
    unsigned long rwflag, const void * data) __attribute__((__nothrow__ , __leaf__));

int umount(const char *specialfile) __attribute__((__nothrow__ , __leaf__));
int umount2(const char *specialfile, int mflag) __attribute__((__nothrow__ , __leaf__));


# 590 "libc.h" 2
# 1 "syscalls.h" 1
# 25 "syscalls.h"
# 1 "mips/syscalls.h" 1
# 26 "syscalls.h" 2
# 591 "libc.h" 2
# 599 "libc.h"
# 1 "./syscalls.h" 1
# 25 "./syscalls.h"
# 1 "./mips/syscalls.h" 1
# 26 "./syscalls.h" 2
# 600 "libc.h" 2

# 1 "include/utime.h" 1 3 4









struct utimbuf {
  time_t actime;
  time_t modtime;
};

int utime(const char* filename, const struct utimbuf* buf) __attribute__((__nothrow__ , __leaf__));


# 602 "libc.h" 2
# 620 "libc.h"
# 1 "include/stdarg.h" 1 3 4










typedef __builtin_va_list va_list;
# 27 "include/stdarg.h" 3 4

# 621 "libc.h" 2





# 1 "dietstdio.h" 1
# 10 "dietstdio.h"
# 1 "include/pthread.h" 1 3 4





# 1 "include/setjmp.h" 1 3 4






# 88 "include/setjmp.h" 3 4
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
# 229 "include/setjmp.h" 3 4
typedef struct __jmp_buf_tag {



  __jmp_buf __jmpbuf;
  int __mask_was_saved;
  sigset_t __saved_mask;
} jmp_buf[1];

extern int __sigsetjmp(jmp_buf __env,int __savemask) __attribute__((__nothrow__ , __leaf__));

extern void longjmp(jmp_buf __env,int __val)
     __attribute__((__nothrow__)) __attribute__((__noreturn__));

typedef jmp_buf sigjmp_buf;

extern void siglongjmp(sigjmp_buf __env,int __val)
     __attribute__((__nothrow__)) __attribute__((__noreturn__));
# 257 "include/setjmp.h" 3 4

# 7 "include/pthread.h" 2 3 4


# 30 "include/pthread.h" 3 4
typedef struct _pthread_descr_struct*_pthread_descr;
typedef int pthread_t;
# 40 "include/pthread.h" 3 4
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
# 79 "include/pthread.h" 3 4
typedef struct {
  int __mutexkind;
} pthread_mutexattr_t;

int pthread_mutexattr_init(pthread_mutexattr_t*attr);
int pthread_mutexattr_destroy(pthread_mutexattr_t*attr);

int pthread_mutexattr_getkind_np(const pthread_mutexattr_t*attr,int*kind);
int pthread_mutexattr_setkind_np(pthread_mutexattr_t*attr,int kind);

int pthread_mutex_init(pthread_mutex_t*mutex,
  const pthread_mutexattr_t*mutexattr);
int pthread_mutex_lock(pthread_mutex_t*mutex);
int pthread_mutex_unlock(pthread_mutex_t*mutex);
int pthread_mutex_trylock(pthread_mutex_t*mutex);
int pthread_mutex_destroy(pthread_mutex_t*mutex);


typedef void* pthread_condattr_t;

typedef struct {
  struct _pthread_fastlock lock;
  _pthread_descr wait_chain;
} pthread_cond_t;




int pthread_cond_init(pthread_cond_t*cond,pthread_condattr_t*cond_attr);
int pthread_cond_destroy(pthread_cond_t*cond);
int pthread_cond_signal(pthread_cond_t*cond);
int pthread_cond_broadcast(pthread_cond_t*cond);
int pthread_cond_timedwait(pthread_cond_t*cond,pthread_mutex_t*mutex,
      const struct timespec*abstime);
int pthread_cond_wait(pthread_cond_t*cond,pthread_mutex_t*mutex);


int pthread_condattr_init(pthread_condattr_t*attr);
int pthread_condattr_destroy(pthread_condattr_t*attr);
int pthread_condattr_getpshared(const pthread_condattr_t*attr,int*pshared);
int pthread_condattr_setpshared(pthread_condattr_t*attr,int pshared);


typedef unsigned int pthread_key_t;

int pthread_key_create(pthread_key_t*key,void(*destructor)(void*));
int pthread_key_delete(pthread_key_t key);
int pthread_setspecific(pthread_key_t key,const void*value);
void*pthread_getspecific(pthread_key_t key);



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

int pthread_attr_init(pthread_attr_t*attr);
int pthread_attr_destroy(pthread_attr_t*attr);

int pthread_attr_setdetachstate(pthread_attr_t*attr,const int detachstate);
int pthread_attr_getdetachstate(const pthread_attr_t*attr,int*detachstate);

int pthread_attr_setschedpolicy(pthread_attr_t*attr,const int policy);
int pthread_attr_getschedpolicy(const pthread_attr_t*attr,int*policy);

int pthread_attr_setschedparam(pthread_attr_t*attr,
    const struct sched_param*param);
int pthread_attr_getschedparam(const pthread_attr_t*attr,
    struct sched_param*param);

int pthread_attr_setinheritsched(pthread_attr_t*attr,const int inherit);
int pthread_attr_getinheritsched(const pthread_attr_t*attr,int*inherit);

int pthread_attr_setscope(pthread_attr_t*attr,const int scope);
int pthread_attr_getscope(const pthread_attr_t*attr,int*scope);

int pthread_attr_setstackaddr(pthread_attr_t*attr,void*stack);
int pthread_attr_getstackaddr(const pthread_attr_t*attr,void**stack);

int pthread_attr_setstacksize(pthread_attr_t*attr,const size_t stacksize);
int pthread_attr_getstacksize(const pthread_attr_t*attr,size_t*stacksize);

int pthread_setschedparam(const pthread_t target_thread,const int policy,
     const struct sched_param*param);
int pthread_getschedparam(const pthread_t target_thread,int*policy,
     struct sched_param*param);


typedef int pthread_once_t;


int pthread_once(pthread_once_t*once_control,void(*init_routine)(void));



enum {
  PTHREAD_CANCEL_ENABLE,

  PTHREAD_CANCEL_DISABLE,

};

enum {
  PTHREAD_CANCEL_DEFERRED,

  PTHREAD_CANCEL_ASYNCHRONOUS,

};



int pthread_kill(pthread_t thread,int sig);
int pthread_cancel(pthread_t thread);
int pthread_setcancelstate(int state,int*oldstate);

int pthread_setcanceltype(int type,int*oldtype);

void pthread_testcancel(void);



void pthread_cleanup_push(void(*routine)(void*),void*arg);
void pthread_cleanup_pop(int execute);

void pthread_cleanup_push_defer_np(void(*routine)(void*),void*arg);
void pthread_cleanup_pop_restore_np(int execute);



int pthread_atfork(void(*prepare)(void),void(*parent)(void),
       void(*child)(void));


pthread_t pthread_self(void);

int pthread_create(pthread_t*__threadarg,
  const pthread_attr_t*__attr,
  void*(*__start_routine)(void *),
  void*__arg);

void pthread_exit(void*__retval) __attribute__((__noreturn__));

int pthread_join(pthread_t __th,void**__thread_return);

int pthread_detach(pthread_t __th);
int pthread_equal(pthread_t __thread1,pthread_t __thread2);

int pthread_sigmask(int how,const sigset_t*newset,sigset_t*oldset);


int pthread_mutexattr_gettype(const pthread_mutexattr_t *__restrict__ attr, int *__restrict__ type);
int pthread_mutexattr_settype(pthread_mutexattr_t *attr, int type);

typedef struct {
  unsigned int n;
} pthread_rwlock_t;

typedef struct {
  int dummy;
} pthread_rwlockattr_t;



int pthread_rwlock_init(pthread_rwlock_t *rwlock, const pthread_rwlockattr_t *attr);
int pthread_rwlock_destroy(pthread_rwlock_t *rwlock);

int pthread_rwlock_rdlock(pthread_rwlock_t *rwlock);
int pthread_rwlock_tryrdlock(pthread_rwlock_t *rwlock);
int pthread_rwlock_wrlock(pthread_rwlock_t *rwlock);
int pthread_rwlock_trywrlock(pthread_rwlock_t *rwlock);
int pthread_rwlockattr_init(pthread_rwlockattr_t *attr);
int pthread_rwlockattr_destroy(pthread_rwlockattr_t *attr);
int pthread_rwlock_unlock(pthread_rwlock_t *rwlock);


# 11 "dietstdio.h" 2
# 20 "dietstdio.h"

# 20 "dietstdio.h"
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
# 51 "dietstdio.h"
# 1 "include/stdio.h" 1 3 4
# 9 "include/stdio.h" 3 4



# 11 "include/stdio.h" 3 4
struct __stdio_file;
typedef struct __stdio_file FILE;

extern FILE *stdin, *stdout, *stderr;

FILE *fopen (const char *path, const char *mode) __attribute__((__nothrow__ , __leaf__));
FILE *fdopen (int fildes, const char *mode) __attribute__((__nothrow__ , __leaf__));
FILE *freopen (const char *path, const char *mode, FILE *stream) __attribute__((__nothrow__ , __leaf__));

int printf(const char *format, ...) __attribute__((__nothrow__ , __leaf__)) __attribute__((__format__(__printf__,1,2)));
int fprintf(FILE *stream, const char *format, ...) __attribute__((__nothrow__ , __leaf__)) __attribute__((__format__(__printf__,2,3)));
int sprintf(char *str, const char *format, ...) __attribute__((__nothrow__ , __leaf__)) __attribute__((__format__(__printf__,2,3)));
int snprintf(char *str, size_t size, const char *format, ...) __attribute__((__nothrow__ , __leaf__)) __attribute__((__format__(__printf__,3,4)));
int asprintf(char **ptr, const char* format, ...) __attribute__((__nothrow__ , __leaf__)) __attribute__((__format__(__printf__,2,3)));

int scanf(const char *format, ...) __attribute__((__nothrow__ , __leaf__)) __attribute__((__format__(__scanf__,1,2)));
int fscanf(FILE *stream, const char *format, ...) __attribute__((__nothrow__ , __leaf__)) __attribute__((__format__(__scanf__,2,3)));
int sscanf(const char *str, const char *format, ...) __attribute__((__nothrow__ , __leaf__)) __attribute__((__format__(__scanf__,2,3)));

int vprintf(const char *format, va_list ap) __attribute__((__nothrow__ , __leaf__)) __attribute__((__format__(__printf__,1,0)));
int vfprintf(FILE *stream, const char *format, va_list ap) __attribute__((__nothrow__ , __leaf__)) __attribute__((__format__(__printf__,2,0)));
int vsprintf(char *str, const char *format, va_list ap) __attribute__((__nothrow__ , __leaf__)) __attribute__((__format__(__printf__,2,0)));
int vsnprintf(char *str, size_t size, const char *format, va_list ap) __attribute__((__nothrow__ , __leaf__)) __attribute__((__format__(__printf__,3,0)));

int fdprintf(int fd, const char *format, ...) __attribute__((__nothrow__ , __leaf__)) __attribute__((__format__(__printf__,2,3)));
int vfdprintf(int fd, const char *format, va_list ap) __attribute__((__nothrow__ , __leaf__)) __attribute__((__format__(__printf__,2,0)));

int vscanf(const char *format, va_list ap) __attribute__((__nothrow__ , __leaf__)) __attribute__((__format__(__scanf__,1,0)));
int vsscanf(const char *str, const char *format, va_list ap) __attribute__((__nothrow__ , __leaf__)) __attribute__((__format__(__scanf__,2,0)));
int vfscanf(FILE *stream, const char *format, va_list ap) __attribute__((__nothrow__ , __leaf__)) __attribute__((__format__(__scanf__,2,0)));

int fgetc(FILE *stream) __attribute__((__nothrow__ , __leaf__));
int fgetc_unlocked(FILE *stream) __attribute__((__nothrow__ , __leaf__));
char *fgets(char *s, int size, FILE *stream) __attribute__((__nothrow__ , __leaf__));
char *fgets_unlocked(char *s, int size, FILE *stream) __attribute__((__nothrow__ , __leaf__));

char *gets(char *s) __attribute__((__nothrow__ , __leaf__));
int ungetc(int c, FILE *stream) __attribute__((__nothrow__ , __leaf__));
int ungetc_unlocked(int c, FILE *stream) __attribute__((__nothrow__ , __leaf__));

int fputc(int c, FILE *stream) __attribute__((__nothrow__ , __leaf__));
int fputc_unlocked(int c, FILE *stream) __attribute__((__nothrow__ , __leaf__));
int fputs(const char *s, FILE *stream) __attribute__((__nothrow__ , __leaf__));
int fputs_unlocked(const char *s, FILE *stream) __attribute__((__nothrow__ , __leaf__));

int getc(FILE *stream) __attribute__((__nothrow__ , __leaf__));
int getchar(void) __attribute__((__nothrow__ , __leaf__));
int putchar(int c) __attribute__((__nothrow__ , __leaf__));
int putchar_unlocked(int c) __attribute__((__nothrow__ , __leaf__));
# 81 "include/stdio.h" 3 4
int puts(const char *s) __attribute__((__nothrow__ , __leaf__));

int fseek(FILE *stream, long offset, int whence) __attribute__((__nothrow__ , __leaf__));
int fseek_unlocked(FILE *stream, long offset, int whence) __attribute__((__nothrow__ , __leaf__));
long ftell(FILE *stream) __attribute__((__nothrow__ , __leaf__));
long ftell_unlocked(FILE *stream) __attribute__((__nothrow__ , __leaf__));
int fseeko(FILE *stream, off_t offset, int whence) __attribute__((__nothrow__ , __leaf__));
int fseeko_unlocked(FILE *stream, off_t offset, int whence) __attribute__((__nothrow__ , __leaf__));
off_t ftello(FILE *stream) __attribute__((__nothrow__ , __leaf__));
off_t ftello_unlocked(FILE *stream) __attribute__((__nothrow__ , __leaf__));


int fseeko64(FILE *stream, loff_t offset, int whence) __attribute__((__nothrow__ , __leaf__));
int fseeko64_unlocked(FILE *stream, loff_t offset, int whence) __attribute__((__nothrow__ , __leaf__));
loff_t ftello64(FILE *stream) __attribute__((__nothrow__ , __leaf__));
loff_t ftello64_unlocked(FILE *stream) __attribute__((__nothrow__ , __leaf__));
# 106 "include/stdio.h" 3 4
void rewind(FILE *stream) __attribute__((__nothrow__ , __leaf__));
int fgetpos(FILE *stream, fpos_t *pos) __attribute__((__nothrow__ , __leaf__));
int fsetpos(FILE *stream, fpos_t *pos) __attribute__((__nothrow__ , __leaf__));

size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream) __attribute__((__nothrow__ , __leaf__));
size_t fread_unlocked(void *ptr, size_t size, size_t nmemb, FILE *stream) __attribute__((__nothrow__ , __leaf__));

size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream) __attribute__((__nothrow__ , __leaf__));
size_t fwrite_unlocked(const void *ptr, size_t size, size_t nmemb, FILE *stream) __attribute__((__nothrow__ , __leaf__));

int fflush(FILE *stream) __attribute__((__nothrow__ , __leaf__));
int fflush_unlocked(FILE *stream) __attribute__((__nothrow__ , __leaf__));

int fclose(FILE *stream) __attribute__((__nothrow__ , __leaf__));
int fclose_unlocked(FILE *stream) __attribute__((__nothrow__ , __leaf__));

int feof(FILE *stream) __attribute__((__nothrow__ , __leaf__));
int feof_unlocked(FILE *stream) __attribute__((__nothrow__ , __leaf__));
int ferror(FILE *stream) __attribute__((__nothrow__ , __leaf__));
int ferror_unlocked(FILE *stream) __attribute__((__nothrow__ , __leaf__));
int fileno(FILE *stream) __attribute__((__nothrow__ , __leaf__));
int fileno_unlocked(FILE *stream) __attribute__((__nothrow__ , __leaf__));
void clearerr(FILE *stream) __attribute__((__nothrow__ , __leaf__));
void clearerr_unlocked(FILE *stream) __attribute__((__nothrow__ , __leaf__));

int remove(const char *pathname) __attribute__((__nothrow__ , __leaf__));
int rename(const char *oldpath, const char *newpath) __attribute__((__nothrow__ , __leaf__));

void perror(const char *s) __attribute__((__nothrow__ , __leaf__));
# 144 "include/stdio.h" 3 4
int setvbuf(FILE *stream, char *buf, int mode , size_t size) __attribute__((__nothrow__ , __leaf__));
int setvbuf_unlocked(FILE *stream, char *buf, int mode , size_t size) __attribute__((__nothrow__ , __leaf__));
# 160 "include/stdio.h" 3 4
FILE *popen(const char *command, const char *type) __attribute__((__nothrow__ , __leaf__));
int pclose(FILE *stream) __attribute__((__nothrow__ , __leaf__));
# 171 "include/stdio.h" 3 4
char* tmpnam(char *s) __attribute__((__nothrow__ , __leaf__));
char* tempnam(char* dir,char* _template);
FILE* tmpfile(void) __attribute__((__nothrow__ , __leaf__));
FILE* tmpfile_unlocked(void) __attribute__((__nothrow__ , __leaf__));
# 183 "include/stdio.h" 3 4
char* ctermid(char* s);

void flockfile(FILE* f) __attribute__((__nothrow__ , __leaf__));
void funlockfile(FILE* f) __attribute__((__nothrow__ , __leaf__));
int ftrylockfile (FILE *__stream) __attribute__((__nothrow__ , __leaf__));


int vasprintf(char **strp, const char *fmt, va_list ap) __attribute__((__nothrow__ , __leaf__));
ssize_t getline(char **lineptr, size_t *n, FILE *stream) __attribute__((__nothrow__ , __leaf__));
ssize_t getdelim(char **lineptr, size_t *n, int delim, FILE *stream) __attribute__((__nothrow__ , __leaf__));





int symlinkat(const char *oldpath, int newdirfd, const char *newpath);
int renameat(int olddirfd, const char *oldpath, int newdirfd, const char *newpath) __attribute__((__nothrow__ , __leaf__));



# 52 "dietstdio.h" 2





# 56 "dietstdio.h"
extern int __fflush4(FILE *stream,int next);
extern int __buffered_outs(const char *s,size_t len);


struct arg_scanf {
  void *data;
  int (*getch)(void*);
  int (*putch)(int,void*);
};

int __v_scanf(struct arg_scanf* fn, const char *format, va_list arg_ptr);

struct arg_printf {
  void *data;
  int (*put)(const void*,size_t,void*);
};

int __v_printf(struct arg_printf* fn, const char *format, va_list arg_ptr);

extern FILE *__stdio_root;

int __fflush_stdin(void);
int __fflush_stdout(void);
int __fflush_stderr(void);

FILE* __stdio_init_file(int fd,int closeonerror,int mode);
int __stdio_parse_mode(const char *mode) __attribute__((__pure__));
void __stdio_flushall(void);


int __libc_close(int fd);
int __libc_open(const char*fn,int flags,...);
ssize_t __libc_read(int fd,void*buf,size_t len);
ssize_t __libc_write(int fd,const void*buf,size_t len);


FILE *fopen_unlocked(const char *path, const char *mode) 
# 92 "dietstdio.h" 3 4
                                                        __attribute__((__nothrow__ , __leaf__))
# 92 "dietstdio.h"
                                                               ;
FILE *fdopen_unlocked(int fildes, const char *mode) 
# 93 "dietstdio.h" 3 4
                                                   __attribute__((__nothrow__ , __leaf__))
# 93 "dietstdio.h"
                                                          ;
FILE *freopen_unlocked(const char *path, const char *mode, FILE *stream) 
# 94 "dietstdio.h" 3 4
                                                                        __attribute__((__nothrow__ , __leaf__))
# 94 "dietstdio.h"
                                                                               ;

int __stdout_is_tty(void);
int __stdin_is_tty(void);
# 627 "libc.h" 2
# 1 "dietwarning.h" 1
# 628 "libc.h" 2



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

int __v_printf(struct arg_printf* fn, const char *format, va_list arg_ptr)
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
# 762 "libc.h" 3 4
           __builtin_va_arg
# 762 "libc.h"
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
# 773 "libc.h" 3 4
          __builtin_va_arg
# 773 "libc.h"
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
# 786 "libc.h" 3 4
         __builtin_va_arg
# 786 "libc.h"
               (arg_ptr,int);

      case '%':
 { if ((unsigned long)(1) > (((unsigned long)(int)(-1))>>1) || len+(int)(1)<len) return -1; ((fn)->put((void*)(&ch),(1),(fn)->data)); } while (0);
 ++len;
 break;
# 803 "libc.h"
      case 's':
 u_str.s=
# 804 "libc.h" 3 4
  __builtin_va_arg
# 804 "libc.h"
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
# 853 "libc.h"
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
# 928 "libc.h" 3 4
             __builtin_va_arg
# 928 "libc.h"
                   (arg_ptr,long long);
   else

     number=
# 931 "libc.h" 3 4
           __builtin_va_arg
# 931 "libc.h"
                 (arg_ptr,long);
 }
 else {
   number=
# 934 "libc.h" 3 4
         __builtin_va_arg
# 934 "libc.h"
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
# 988 "libc.h" 3 4
           __builtin_va_arg
# 988 "libc.h"
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



# 1 "include/ctype.h" 1 3 4








# 8 "include/ctype.h" 3 4
extern int isascii (int c) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int isblank (int c) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int isalnum (int c) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int isalpha (int c) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int isdigit (int c) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int isspace (int c) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__const__));

extern int isupper (int c) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int islower (int c) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__const__));

extern int toascii(int c) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int tolower(int c) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int toupper(int c) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__const__));

extern int isprint(int c) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int ispunct(int c) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int iscntrl(int c) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern int isxdigit(int c) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__const__));

extern int isgraph(int c) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__const__));


# 1052 "libc.h" 2


# 1 "include/limits.h" 1 3 4
# 1055 "libc.h" 2


# 1 "dietwarning.h" 1
# 1058 "libc.h" 2





# 1062 "libc.h"
int __v_scanf(struct arg_scanf* fn, const char *format, va_list arg_ptr)
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
# 1219 "libc.h" 3 4
              (~0ull)
# 1219 "libc.h"
                        :d+c;



       --width;
       tpch=(++consumed,(fn)->getch((fn)->data));
     }

     if (consumedsofar==consumed) return n;

     if ((ch|0x20)<'p') {

       register long long l=v;
       if (v>=-((unsigned long long)
# 1232 "libc.h" 3 4
                                   (-1ll - 0x7fffffffffffffffll)
# 1232 "libc.h"
                                            )) {
  l=(neg)?
# 1233 "libc.h" 3 4
         (-1ll - 0x7fffffffffffffffll)
# 1233 "libc.h"
                  :
# 1233 "libc.h" 3 4
                   0x7fffffffffffffffll
# 1233 "libc.h"
                            ;
       }
       else {
  if (neg) v*=-1;
       }
# 1247 "libc.h"
     }
     if (!flag_discard) {

       if (flag_longlong) {
  pll=(long long *)
# 1251 "libc.h" 3 4
                  __builtin_va_arg
# 1251 "libc.h"
                        (arg_ptr,long long*);
  *pll=v;
       } else

       if (flag_long) {
  pl=(long *)
# 1256 "libc.h" 3 4
            __builtin_va_arg
# 1256 "libc.h"
                  (arg_ptr,long*);
  *pl=v;
       } else if (flag_half) {
  ph=(short*)
# 1259 "libc.h" 3 4
            __builtin_va_arg
# 1259 "libc.h"
                  (arg_ptr,short*);
  *ph=v;
       } else {
  pi=(int *)
# 1262 "libc.h" 3 4
           __builtin_va_arg
# 1262 "libc.h"
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
# 1336 "libc.h" 3 4
              __builtin_va_arg
# 1336 "libc.h"
                    (arg_ptr,double*);
  *pd=d;
       } else {
  pf=(float *)
# 1339 "libc.h" 3 4
             __builtin_va_arg
# 1339 "libc.h"
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
# 1351 "libc.h" 3 4
              __builtin_va_arg
# 1351 "libc.h"
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
# 1364 "libc.h" 3 4
                               __builtin_va_arg
# 1364 "libc.h"
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
# 1379 "libc.h" 3 4
              __builtin_va_arg
# 1379 "libc.h"
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
# 1423 "libc.h" 3 4
                __builtin_va_arg
# 1423 "libc.h"
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
# 1456 "libc.h" 3 4
                  __builtin_va_arg
# 1456 "libc.h"
                        (arg_ptr, int *);
      *pi = consumed - 1;
    }
  }

err_out:
  if (tpch<0 && n==0) return 
# 1462 "libc.h" 3 4
                            (-1)
# 1462 "libc.h"
                               ;
  (--consumed,(fn)->putch((tpch),(fn)->data));
  return n;
}

asm (".section .gnu.warning." "__v_scanf" "\n\t.string \"" "warning: the scanf functions add several kilobytes of bloat." "\"\n\t.previous");;
int __valgrind=0;


extern void* __diet_brk(void *end_data_segment);

void* __curbrk=0;

int __libc_brk(void *end_data_segment);

int __libc_brk(void *end_data_segment) {
  return ((__curbrk=__diet_brk(end_data_segment))==(void*)-1?-1:0);
}

int brk(void *end_data_segment) __attribute__((weak,alias("__libc_brk")));
# 1 "include/sys/resource.h" 1 3 4













# 13 "include/sys/resource.h" 3 4
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
# 89 "include/sys/resource.h" 3 4
int getpriority(int which, int who) __attribute__((__nothrow__ , __leaf__));
int setpriority(int which, int who, int prio) __attribute__((__nothrow__ , __leaf__));

int getrlimit (int resource, struct rlimit *rlim);
int getrusage (int who, struct rusage *usage);
int setrlimit (int resource, const struct rlimit *rlim);

typedef unsigned long rlim_t;


# 1483 "libc.h" 2


# 1484 "libc.h"
extern int __syscall_getpriority(int which, int who);

int getpriority(int which, int who) {
  int r;

  r = __syscall_getpriority(which, who);
  if (r >= 0) r = 20 - r;
  return r;
}







void __stdio_flushall(void) __attribute__((weak));
void __stdio_flushall(void) { }




void abort() {
  sigset_t t;
  __stdio_flushall();
  if (!sigemptyset(&t) && !sigaddset(&t, 
# 1509 "libc.h" 3 4
                                        6
# 1509 "libc.h"
                                               ))
    sigprocmask(
# 1510 "libc.h" 3 4
               2
# 1510 "libc.h"
                          , &t, 0);
  while (1)
    if (raise(
# 1512 "libc.h" 3 4
             6
# 1512 "libc.h"
                    ))
      exit(127);
}



int abs(int i) { return i>=0?i:-i; }

long labs(long i) __attribute__((alias("abs")));

# 1 "syscalls.h" 1
# 25 "syscalls.h"
# 1 "mips/syscalls.h" 1
# 26 "syscalls.h" 2
# 1523 "libc.h" 2


# 1 "./linuxnet.h" 1
# 1526 "libc.h" 2

extern int socketcall(int callno,long* args);

int __libc_accept(int a, void * addr, void * addr2);

int __libc_accept(int a, void * addr, void * addr2) {
  long args[] = { a, (long) addr, (long) addr2 };
  return socketcall(5, args);
}

int accept(int a, void * addr, void * addr2) __attribute__((weak,alias("__libc_accept")));



# 1 "include/sys/timex.h" 1 3 4









# 9 "include/sys/timex.h" 3 4
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
# 53 "include/sys/timex.h" 3 4
int adjtimex(struct timex *buf);


# 1541 "libc.h" 2


# 1542 "libc.h"
int adjtime (const struct timeval *itv, struct timeval *otv) {
  struct timex tmp;
  if (itv) {
    tmp.offset = (itv->tv_usec % 1000000L) + (itv->tv_sec + itv->tv_usec / 1000000L) * 1000000L;
    tmp.modes = 
# 1546 "libc.h" 3 4
               0x8001
# 1546 "libc.h"
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
# 1577 "libc.h"
# 1 "include/sys/shm.h" 1 3 4



# 1 "include/sys/ipc.h" 1 3 4







# 41 "include/sys/ipc.h" 3 4

# 41 "include/sys/ipc.h" 3 4
struct ipc_perm {
  key_t key;
  uid_t uid;
  gid_t gid;
  uid_t cuid;
  gid_t cgid;
  mode_t mode;
  uint16_t seq;
};


key_t ftok(const char *pathname, int proj_id);


# 5 "include/sys/shm.h" 2 3 4









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
# 46 "include/sys/shm.h" 3 4
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
# 79 "include/sys/shm.h" 3 4
extern int shmget(key_t key, int size, int shmflg) __attribute__((__nothrow__ , __leaf__));
extern void *shmat(int shmid, const void *shmaddr, int shmflg) __attribute__((__nothrow__ , __leaf__));
extern int shmdt (const void *shmaddr) __attribute__((__nothrow__ , __leaf__));
extern int shmctl(int shmid, int cmd, struct shmid_ds *buf) __attribute__((__nothrow__ , __leaf__));


# 1578 "libc.h" 2
# 1590 "libc.h"

# 1590 "libc.h"
typedef struct {
  void* next;
  size_t size;
} __alloc_t;
# 1608 "libc.h"
static void *do_mmap(size_t size) {
  return mmap(0, size, 
# 1609 "libc.h" 3 4
                      0x1
# 1609 "libc.h"
                               |
# 1609 "libc.h" 3 4
                                0x2
# 1609 "libc.h"
                                          , 
# 1609 "libc.h" 3 4
                                            0x0800
# 1609 "libc.h"
                                                         |
# 1609 "libc.h" 3 4
                                                          0x02
# 1609 "libc.h"
                                                                     , -1, (size_t)0);
}



static __alloc_t* __small_mem[8];
# 1625 "libc.h"
static inline int __ind_shift() { return (
# 1625 "libc.h" 3 4
                                         4096UL
# 1625 "libc.h"
                                                       ==4096)?4:5; }

static size_t get_index(size_t _size) {
  register size_t idx=0;

    register size_t size=((_size-1)&(
# 1630 "libc.h" 3 4
                                    4096UL
# 1630 "libc.h"
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
# 1664 "libc.h" 3 4
               4096UL
# 1664 "libc.h"
                             );
    if (ptr==
# 1665 "libc.h" 3 4
            ((void *) -1)
# 1665 "libc.h"
                      ) return 
# 1665 "libc.h" 3 4
                               ((void *) -1)
# 1665 "libc.h"
                                         ;

    __small_mem[idx]=ptr;

    nr=(
# 1669 "libc.h" 3 4
      4096UL
# 1669 "libc.h"
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
# 1693 "libc.h" 3 4
               4096UL
# 1693 "libc.h"
               /(2)))
 __small_free(ptr,size);
      else
 munmap((((void*)(ptr))-sizeof(__alloc_t)),size);
    }
  }
}
void __libc_free(void *ptr) __attribute__((alias("_alloc_libc_free")));
void free(void *ptr) __attribute__((weak,alias("_alloc_libc_free")));





static void* _alloc_libc_malloc(size_t size) {
  __alloc_t* ptr;
  size_t need;



  if (!size) goto err_out;

  size+=sizeof(__alloc_t);
  if (size<sizeof(__alloc_t)) goto err_out;
  if (size<=(
# 1717 "libc.h" 3 4
           4096UL
# 1717 "libc.h"
           /(2))) {
    need=((
# 1718 "libc.h" 3 4
        4096UL
# 1718 "libc.h"
        /(256))<<get_index((size)));
    ptr=__small_malloc(need);
  }
  else {
    need=(((size)+
# 1722 "libc.h" 3 4
        4096UL
# 1722 "libc.h"
        -1)&(unsigned long)(~(
# 1722 "libc.h" 3 4
        4096UL
# 1722 "libc.h"
        -1)));
    if (!need) ptr=
# 1723 "libc.h" 3 4
                  ((void *) -1)
# 1723 "libc.h"
                            ; else ptr=do_mmap(need);
  }
  if (ptr==
# 1725 "libc.h" 3 4
          ((void *) -1)
# 1725 "libc.h"
                    ) goto err_out;
  ptr->size=need;
  return (((void*)(ptr))+sizeof(__alloc_t));
err_out:
  (*__errno_location())=
# 1729 "libc.h" 3 4
                       12
# 1729 "libc.h"
                             ;
  return 0;
}
void* __libc_malloc(size_t size) __attribute__((alias("_alloc_libc_malloc")));
void* malloc(size_t size) __attribute__((weak,alias("_alloc_libc_malloc")));

void* __libc_calloc(size_t nmemb, size_t _size);
void* __libc_calloc(size_t nmemb, size_t _size) {
  size_t size;

  if (__builtin_mul_overflow(_size,nmemb,&size)) {
    (*__errno_location())=
# 1740 "libc.h" 3 4
                         12
# 1740 "libc.h"
                               ;
    return 0;
  }
# 1757 "libc.h"
  return malloc(size);
}
void* calloc(size_t nmemb, size_t _size) __attribute__((weak,alias("__libc_calloc")));

void* __libc_realloc(void* ptr, size_t _size);
void* __libc_realloc(void* ptr, size_t _size) {
  register size_t size=_size;
  if (ptr) {
    if (size) {
      __alloc_t* tmp=(((void*)(ptr))-sizeof(__alloc_t));
      size+=sizeof(__alloc_t);
      if (size<sizeof(__alloc_t)) goto retzero;
      size=(size<=(
# 1769 "libc.h" 3 4
                 4096UL
# 1769 "libc.h"
                 /(2)))?((
# 1769 "libc.h" 3 4
                                   4096UL
# 1769 "libc.h"
                                   /(256))<<get_index((size))):(((size)+
# 1769 "libc.h" 3 4
                                                  4096UL
# 1769 "libc.h"
                                                  -1)&(unsigned long)(~(
# 1769 "libc.h" 3 4
                                                  4096UL
# 1769 "libc.h"
                                                  -1)));
      if (tmp->size!=size) {
 if ((tmp->size<=(
# 1771 "libc.h" 3 4
                4096UL
# 1771 "libc.h"
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
# 1784 "libc.h" 3 4
       4096UL
# 1784 "libc.h"
       -1)&(unsigned long)(~(
# 1784 "libc.h" 3 4
       4096UL
# 1784 "libc.h"
       -1)));
   foo=mremap(tmp,tmp->size,size,
# 1785 "libc.h" 3 4
                                1UL
# 1785 "libc.h"
                                              );
   if (foo==
# 1786 "libc.h" 3 4
           ((void *) -1)
# 1786 "libc.h"
                     ) {
retzero:
     (*__errno_location())=
# 1788 "libc.h" 3 4
                          12
# 1788 "libc.h"
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
# 1800 "libc.h" 3 4
           (void*)0
# 1800 "libc.h"
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
void* realloc(void* ptr, size_t size) __attribute__((weak,alias("__libc_realloc")));



# 1 "include/sys/random.h" 1 3 4









# 9 "include/sys/random.h" 3 4
enum {
  GRND_NONBLOCK=1,

  GRND_RANDOM=2

};

int getrandom(void* buf, size_t buflen, unsigned int flags) __attribute__((__nothrow__ , __leaf__));
int getentropy(void* buf,size_t buflen) __attribute__((__nothrow__ , __leaf__));


# 1815 "libc.h" 2





# 1819 "libc.h"
static uint32_t buf[256];
static unsigned int n;


uint32_t arc4random(void) {
  if (n==0) arc4random_stir();
  uint32_t r=buf[n];
  if (++n > sizeof(buf)/sizeof(buf[0])) n=0;
  return r;
}

void arc4random_buf(void* Buf, size_t N) {
  int r;
  if ((size_t)(r=getrandom(Buf,N,
# 1832 "libc.h" 3 4
                                GRND_NONBLOCK
# 1832 "libc.h"
                                             )) != N) {
    if (r==-1 && 
# 1833 "libc.h" 3 4
                (*__errno_location())
# 1833 "libc.h"
                     ==
# 1833 "libc.h" 3 4
                       89
# 1833 "libc.h"
                             ) {
      int fd=open("/dev/urandom",
# 1834 "libc.h" 3 4
                                0x0000
# 1834 "libc.h"
                                        );
      if (fd==-1) abort();
      r=read(fd,Buf,N);
      close(fd);
    }
    if ((size_t)r != N)
      abort();
  }
}

uint32_t arc4random_uniform(uint32_t upper_bound) {
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

void arc4random_stir(void) {
  n=0;
  arc4random_buf(buf,sizeof(buf));
}

void arc4random_addrandom(unsigned char* dat,size_t datlen) {
}




# 1 "dietwarning.h" 1
# 1880 "libc.h" 2
# 1 "include/write12.h" 1 3 4






# 6 "include/write12.h" 3 4
ssize_t __write1 ( const char* s ) __attribute__ (( ));
ssize_t __write2 ( const char* s ) __attribute__ (( ));


# 1881 "libc.h" 2


# 1882 "libc.h"
void __assert_fail (const char *assertion, const char *file, unsigned int line, const char *function);

void __assert_fail (const char *assertion, const char *file, unsigned int line, const char *function)
{
  unsigned int alen=strlen(assertion);
  unsigned int flen=strlen(file);
  unsigned int fulen=function?strlen(function):0;
  char *buf=(char*)
# 1889 "libc.h" 3 4
                  __builtin_alloca(
# 1889 "libc.h"
                  alen+flen+fulen+50
# 1889 "libc.h" 3 4
                  )
# 1889 "libc.h"
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

int atexit(function t) {
  if (atexit_counter<32) {
    __atexitlist[atexit_counter]=t;
    ++atexit_counter;
    return 0;
  }
  return -1;
}

extern void __thread_doexit(int doexit);

void __libc_exit(int code);
void __libc_exit(int code) {
  register int i=atexit_counter;
  __thread_doexit(code);
  while(i) {
    __atexitlist[--i]();
  }
  _exit(code);
}
void exit(int code) __attribute__((alias("__libc_exit")));


double atof(const char *nptr) {



  double tmp=strtod(nptr,0);
  return tmp;

}
# 1971 "libc.h"
long int atol(const char* s) {
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




int atoi(const char* s) __attribute__((alias("atol")));






long long int atoll(const char* s) {
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

# 1 "syscalls.h" 1
# 25 "syscalls.h"
# 1 "mips/syscalls.h" 1
# 26 "syscalls.h" 2
# 2010 "libc.h" 2


# 1 "./linuxnet.h" 1
# 2013 "libc.h" 2

extern int socketcall(int callno,long* args);

int __libc_bind(int a, void * b, int c);
int __libc_bind(int a, void * b, int c) {
  long args[] = { a, (long) b, c };
  return socketcall(2, args);
}

int bind(int a, void * b, int c) __attribute__((weak,alias("__libc_bind")));


# 1 "binshstr.h" 1

extern const char __binsh [8];
# 2026 "libc.h" 2

const char __binsh [] = "/bin/sh";


# 1 "include/assert.h" 1 3 4






# 24 "include/assert.h" 3 4

# 24 "include/assert.h" 3 4
extern void __assert_fail (const char *__assertion, const char *__file,
      unsigned int __line, const char *__function)
     __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
# 51 "include/assert.h" 3 4

# 2031 "libc.h" 2



# 2033 "libc.h"
void *bsearch(const void *key, const void *base, size_t nmemb, size_t size, int (*compar)(const void* , const void* )) {
  size_t m;
  while (
# 2035 "libc.h" 3 4
        __builtin_expect((long)((
# 2035 "libc.h"
        nmemb
# 2035 "libc.h" 3 4
        )),1)
# 2035 "libc.h"
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
# 1 "include/wchar.h" 1 3 4
# 9 "include/wchar.h" 3 4




# 12 "include/wchar.h" 3 4
typedef unsigned int wint_t;



typedef int (*wctype_t)(wint_t);
# 26 "include/wchar.h" 3 4
struct tm;

typedef struct {
  int count;
  wchar_t sofar;
} mbstate_t;

wint_t btowc(int);
wint_t fgetwc(FILE *);
wchar_t* fgetws(wchar_t *__restrict__, int, FILE *__restrict__);
wint_t fputwc(wchar_t, FILE *);
int fputws(const wchar_t *__restrict__, FILE *__restrict__);
int fwide(FILE *, int);
int fwprintf(FILE *__restrict__, const wchar_t *__restrict__, ...);
int fwscanf(FILE *__restrict__, const wchar_t *__restrict__, ...);
wint_t getwc(FILE *);
wint_t getwchar(void);

size_t mbrlen(const char *__restrict__, size_t, mbstate_t *__restrict__);
size_t mbrtowc(wchar_t *__restrict__, const char *__restrict__, size_t, mbstate_t *__restrict__);
int mbsinit(const mbstate_t *);
size_t mbsrtowcs(wchar_t *__restrict__, const char **__restrict__, size_t, mbstate_t *__restrict__);
wint_t putwc(wchar_t, FILE *);
wint_t putwchar(wchar_t);
int swprintf(wchar_t *__restrict__, size_t, const wchar_t *__restrict__, ...);
int swscanf(const wchar_t *__restrict__, const wchar_t *__restrict__, ...);

wint_t ungetwc(wint_t, FILE *);
int vfwprintf(FILE *__restrict__, const wchar_t *__restrict__, va_list);
int vfwscanf(FILE *__restrict__, const wchar_t *__restrict__, va_list);
int vwprintf(const wchar_t *__restrict__, va_list);
int vswprintf(wchar_t *__restrict__, size_t, const wchar_t *__restrict__, va_list);
int vswscanf(const wchar_t *__restrict__, const wchar_t *__restrict__, va_list);
int vwscanf(const wchar_t *__restrict__, va_list);
size_t wcrtomb(char *__restrict__, wchar_t, mbstate_t *__restrict__);
wchar_t *wcscat(wchar_t *__restrict__, const wchar_t *__restrict__);
wchar_t *wcschr(const wchar_t *, wchar_t);
int wcscmp(const wchar_t *, const wchar_t *);
int wcscoll(const wchar_t *, const wchar_t *);
wchar_t* wcscpy(wchar_t *__restrict__, const wchar_t *__restrict__);
size_t wcscspn(const wchar_t *, const wchar_t *);
size_t wcsftime(wchar_t *__restrict__, size_t, const wchar_t *__restrict__, const struct tm *__restrict__);
size_t wcslen(const wchar_t *) __attribute__ ((__pure__));
wchar_t *wcsncat(wchar_t *__restrict__, const wchar_t *__restrict__, size_t);
int wcsncmp(const wchar_t *, const wchar_t *, size_t);
wchar_t *wcsncpy(wchar_t *__restrict__, const wchar_t *__restrict__, size_t);
wchar_t *wcspbrk(const wchar_t *, const wchar_t *);
wchar_t *wcsrchr(const wchar_t *, wchar_t);
size_t wcsrtombs(char *__restrict__, const wchar_t **__restrict__, size_t, mbstate_t *__restrict__);
size_t wcsspn(const wchar_t *, const wchar_t *);
wchar_t *wcsstr(const wchar_t *__restrict__, const wchar_t *__restrict__);
double wcstod(const wchar_t *__restrict__, wchar_t **__restrict__);
float wcstof(const wchar_t *__restrict__, wchar_t **__restrict__);
wchar_t *wcstok(wchar_t *__restrict__, const wchar_t *__restrict__, wchar_t **__restrict__);
long wcstol(const wchar_t *__restrict__, wchar_t **__restrict__, int);
long double wcstold(const wchar_t *__restrict__, wchar_t **__restrict__);
long long wcstoll(const wchar_t *__restrict__, wchar_t **__restrict__, int);
unsigned long wcstoul(const wchar_t *__restrict__, wchar_t **__restrict__, int);
unsigned long long wcstoull(const wchar_t *__restrict__, wchar_t **__restrict__, int);

size_t wcsxfrm(wchar_t *__restrict__, const wchar_t *__restrict__, size_t);
int wctob(wint_t);

wchar_t *wmemchr(const wchar_t *, wchar_t, size_t);
int wmemcmp(const wchar_t *, const wchar_t *, size_t);
wchar_t *wmemcpy(wchar_t *__restrict__, const wchar_t *__restrict__, size_t);
wchar_t *wmemmove(wchar_t *, const wchar_t *, size_t);
wchar_t *wmemset(wchar_t *, wchar_t, size_t);
int wprintf(const wchar_t *__restrict__, ...);
int wscanf(const wchar_t *__restrict__, ...);







# 2051 "libc.h" 2
# 1 "dietlocale.h" 1




# 4 "dietlocale.h"
extern enum __encoding {
  CT_8BIT,
  CT_UTF8,
} lc_ctype;
# 2052 "libc.h" 2

wint_t btowc(int c) {
  if (c==0) return 0;
  if (c==
# 2055 "libc.h" 3 4
        (-1)
# 2055 "libc.h"
           ) return 
# 2055 "libc.h" 3 4
                    0xffffffffu
# 2055 "libc.h"
                        ;
  switch (lc_ctype) {
  case CT_8BIT:
    return c>0xff?
# 2058 "libc.h" 3 4
                 0xffffffffu
# 2058 "libc.h"
                     :1;
  case CT_UTF8:
    return c>0x7f?
# 2060 "libc.h" 3 4
                 0xffffffffu
# 2060 "libc.h"
                     :1;
  }
  return 
# 2062 "libc.h" 3 4
        0xffffffffu
# 2062 "libc.h"
            ;
}
# 1 "include/threads.h" 1 3 4







# 7 "include/threads.h" 3 4
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

int thrd_create(thrd_t *thr, thrd_start_t func, void *arg);
thrd_t thrd_current(void);
int thrd_detach(thrd_t thr);
int thrd_equal(thrd_t thr0, thrd_t thr1);
void thrd_exit(int res);
int thrd_join(thrd_t thr, int* res);
int thrd_sleep(const struct timespec* time_point, struct timespec* remaining);
void thrd_yield(void);

typedef struct __mtx_t {
  int lock, type;
  thrd_t owner;
} mtx_t;

enum {
  mtx_plain = 0,
  mtx_timed = 1,
  mtx_recursive = 2
};

int mtx_init(mtx_t* mutex, int type);
int mtx_lock(mtx_t* mutex);
int mtx_timedlock(mtx_t *__restrict__ mutex, const struct timespec *__restrict__ time_point);
int mtx_trylock(mtx_t* mutex);
int mtx_unlock(mtx_t* mutex);
void mtx_destroy(mtx_t* mutex);





typedef int once_flag;


void call_once(once_flag* flag, void (*func)(void));

typedef struct __cnd_t {
  int sem;
} cnd_t;

int cnd_init(cnd_t* cond);
int cnd_signal(cnd_t *cond);
int cnd_broadcast(cnd_t *cond);
int cnd_wait(cnd_t* cond, mtx_t* mutex);
int cnd_timedwait(cnd_t* __restrict__ cond, mtx_t* __restrict__ mutex, const struct timespec* __restrict__ time_point);
void cnd_destroy(cnd_t* cond);



typedef void (*tss_dtor_t)(void*);
typedef struct __tss_t {
  void* data;
  tss_dtor_t dtor;
  struct __tss_t* next;
}* tss_t;


int tss_create(tss_t* tss_id, tss_dtor_t destructor);
void *tss_get(tss_t tss_id);
int tss_set(tss_t tss_id, void *val);
void tss_delete(tss_t tss_id);
# 2065 "libc.h" 2


# 2066 "libc.h"
void call_once(once_flag* flag, void (*func)(void)) {
  if (__sync_bool_compare_and_swap(flag,0,1))
    func();
}
# 1 "include/termios.h" 1 3 4









# 9 "include/termios.h" 3 4
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
# 77 "include/termios.h" 3 4
typedef unsigned char cc_t;
typedef uint32_t speed_t;
typedef uint32_t tcflag_t;
# 107 "include/termios.h" 3 4
struct termios {
 tcflag_t c_iflag;
 tcflag_t c_oflag;
 tcflag_t c_cflag;
 tcflag_t c_lflag;



 cc_t c_line;
 cc_t c_cc[23];
};
# 404 "include/termios.h" 3 4
int tcgetattr(int fd, struct termios *termios_p) __attribute__((__nothrow__ , __leaf__));
int tcsetattr(int fd, int optional_actions, struct termios *termios_p) __attribute__((__nothrow__ , __leaf__));
speed_t cfgetospeed(const struct termios *termios_p) __attribute__((__nothrow__ , __leaf__));
int cfsetospeed(struct termios *termios_p, speed_t speed) __attribute__((__nothrow__ , __leaf__));
speed_t cfgetispeed(const struct termios *termios_p) __attribute__((__nothrow__ , __leaf__));
int cfsetispeed(struct termios *termios_p, speed_t speed) __attribute__((__nothrow__ , __leaf__));
void cfmakeraw(struct termios *t) __attribute__((__nothrow__ , __leaf__));

int tcflush(int fd, int queue_selector) __attribute__((__nothrow__ , __leaf__));
int tcdrain(int fd) __attribute__((__nothrow__ , __leaf__));
int tcflow (int fd,int action) __attribute__((__nothrow__ , __leaf__));
int tcsendbreak (int fd,int duration) __attribute__((__nothrow__ , __leaf__));
pid_t tcgetsid(int fildes) __attribute__((__nothrow__ , __leaf__));


# 2071 "libc.h" 2



# 2073 "libc.h"
speed_t cfgetospeed(const struct termios *termios_p) {
  return ((termios_p->c_cflag & (
# 2074 "libc.h" 3 4
                                0010017
# 2074 "libc.h"
                                     |
# 2074 "libc.h" 3 4
                                      0010000
# 2074 "libc.h"
                                             )));
}

speed_t cfgetispeed(const struct termios *termios_p) __attribute__((weak,alias("cfgetospeed")));

# 1 "include/sys/ioctl.h" 1 3 4






# 19 "include/sys/ioctl.h" 3 4
# 1 "include/sys/mips-ioctl.h" 1 3 4
# 20 "include/sys/ioctl.h" 2 3 4
# 34 "include/sys/ioctl.h" 3 4

# 34 "include/sys/ioctl.h" 3 4
int ioctl(int d, long int request, ...) __attribute__((__nothrow__ , __leaf__));


# 2080 "libc.h" 2


# 2081 "libc.h"
void cfmakeraw(struct termios *t) {
     t->c_iflag &= ~(
# 2082 "libc.h" 3 4
                    0000001
# 2082 "libc.h"
                          |
# 2082 "libc.h" 3 4
                           0000002
# 2082 "libc.h"
                                 |
# 2082 "libc.h" 3 4
                                  0000010
# 2082 "libc.h"
                                        |
# 2082 "libc.h" 3 4
                                         0000040
# 2082 "libc.h"
                                               |
# 2082 "libc.h" 3 4
                                                0000100
# 2082 "libc.h"
                                                     |
# 2082 "libc.h" 3 4
                                                      0000200
# 2082 "libc.h"
                                                           |
# 2082 "libc.h" 3 4
                                                            0000400
# 2082 "libc.h"
                                                                 |
# 2082 "libc.h" 3 4
                                                                  0002000
# 2082 "libc.h"
                                                                      );
     t->c_oflag &= ~
# 2083 "libc.h" 3 4
                   0000001
# 2083 "libc.h"
                        ;
     t->c_lflag &= ~(
# 2084 "libc.h" 3 4
                    0000010
# 2084 "libc.h"
                        |
# 2084 "libc.h" 3 4
                         0000100
# 2084 "libc.h"
                               |
# 2084 "libc.h" 3 4
                                0000002
# 2084 "libc.h"
                                      |
# 2084 "libc.h" 3 4
                                       0000001
# 2084 "libc.h"
                                           |
# 2084 "libc.h" 3 4
                                            0000400
# 2084 "libc.h"
                                                  );
     t->c_cflag &= ~(
# 2085 "libc.h" 3 4
                    0000060
# 2085 "libc.h"
                         |
# 2085 "libc.h" 3 4
                          0000400
# 2085 "libc.h"
                                );
     t->c_cflag |= 
# 2086 "libc.h" 3 4
                  0000060
# 2086 "libc.h"
                     ;
     t->c_cc[
# 2087 "libc.h" 3 4
            4
# 2087 "libc.h"
                ] = 1;
     t->c_cc[
# 2088 "libc.h" 3 4
            5
# 2088 "libc.h"
                 ] = 0;
}







int cfsetispeed(struct termios *termios_p, speed_t speed)
{
  if ((speed & (speed_t)~
# 2099 "libc.h" 3 4
                        0010017
# 2099 "libc.h"
                             ) != 0 && (speed < 
# 2099 "libc.h" 3 4
                                                0010001 
# 2099 "libc.h"
                                                       || speed > 
# 2099 "libc.h" 3 4
                                                                  0010004
# 2099 "libc.h"
                                                                         )) {
    
# 2100 "libc.h" 3 4
   (*__errno_location())
# 2100 "libc.h"
        =
# 2100 "libc.h" 3 4
         22
# 2100 "libc.h"
               ;
    return -1;
  }
  if (speed == 0)
    termios_p->c_iflag |= 020000000000;
  else {
    termios_p->c_iflag &= ~020000000000;
    termios_p->c_cflag &= ~(
# 2107 "libc.h" 3 4
                           0010017 
# 2107 "libc.h"
                                 | 
# 2107 "libc.h" 3 4
                                   0010000
# 2107 "libc.h"
                                          );
    termios_p->c_cflag |= speed;
  }
  return 0;
}





int cfsetospeed(struct termios *termios_p, speed_t speed) {
  if ((speed & (speed_t)~
# 2118 "libc.h" 3 4
                        0010017
# 2118 "libc.h"
                             ) != 0 && (speed < 
# 2118 "libc.h" 3 4
                                                0010001 
# 2118 "libc.h"
                                                       || speed > 
# 2118 "libc.h" 3 4
                                                                  0010004
# 2118 "libc.h"
                                                                         )) {
    
# 2119 "libc.h" 3 4
   (*__errno_location())
# 2119 "libc.h"
        =
# 2119 "libc.h" 3 4
         22
# 2119 "libc.h"
               ;
    return -1;
  }
  termios_p->c_cflag &= ~(
# 2122 "libc.h" 3 4
                         0010017 
# 2122 "libc.h"
                               | 
# 2122 "libc.h" 3 4
                                 0010000
# 2122 "libc.h"
                                        );
  termios_p->c_cflag |= speed;
  return 0;
}

# 1 "dietdirent.h" 1





struct __dirstream {
  char buf[
# 7 "dietdirent.h" 3 4
          4096UL
# 7 "dietdirent.h"
                   -(sizeof (int)*3)];
  int fd;
  unsigned int num;
  unsigned int cur;
};
# 2128 "libc.h" 2


# 1 "include/dirent.h" 1 3 4










# 10 "include/dirent.h" 3 4
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
# 34 "include/dirent.h" 3 4
typedef struct __dirstream DIR;

DIR *opendir (const char *__name) __attribute__((__nothrow__ , __leaf__));
DIR *fdopendir (int fd) __attribute__((__nothrow__ , __leaf__));
int closedir (DIR *__dirp) __attribute__((__nothrow__ , __leaf__));
struct dirent *readdir (DIR *__dirp) __attribute__((__nothrow__ , __leaf__));

int readdir_r (DIR* __dirp, struct dirent* entry, struct dirent** result) __attribute__((__nothrow__ , __leaf__));

struct dirent64 *readdir64 (DIR *__dirp) __attribute__((__nothrow__ , __leaf__));
void rewinddir (DIR *__dirp) __attribute__((__nothrow__ , __leaf__));
void seekdir (DIR *__dirp, off_t __pos) __attribute__((__nothrow__ , __leaf__));
off_t telldir (DIR *__dirp) __attribute__((__nothrow__ , __leaf__));

int scandir(const char *dir, struct dirent ***namelist,
      int (*selection)(const struct dirent *),
      int (*compar)(const struct dirent **, const struct dirent **));
int scandir64(const char *dir, struct dirent64 ***namelist,
      int (*selection)(const struct dirent64 *),
      int (*compar)(const struct dirent64 **, const struct dirent64 **));

int alphasort(const struct dirent **a, const struct dirent **b) __attribute__((__nothrow__ , __leaf__)) __attribute__((const));
int alphasort64(const struct dirent64 **a, const struct dirent64 **b) __attribute__((__nothrow__ , __leaf__)) __attribute__((const));




extern int dirfd(DIR *dirp) __attribute__((__nothrow__ , __leaf__)) __attribute__((__deprecated__));
# 72 "include/dirent.h" 3 4
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
# 104 "include/dirent.h" 3 4

# 2131 "libc.h" 2



# 2133 "libc.h"
int closedir (DIR* d) {
  int res=close(d->fd);
  munmap (d, 
# 2135 "libc.h" 3 4
            4096UL
# 2135 "libc.h"
                     );
  return res;
}

# 1 "include/sys/futex.h" 1 3 4









# 9 "include/sys/futex.h" 3 4
enum {
  FUTEX_WAIT=0,
  FUTEX_WAKE=1,
  FUTEX_FD=2,
  FUTEX_REQUEUE=3,
  FUTEX_CMP_REQUEUE=4,
};

long futex(int* uaddr,int op,int val,const struct timespec* timeout,int* uaddr2,int val3);


# 2140 "libc.h" 2


# 2141 "libc.h"
int cnd_broadcast(cnd_t* cond) {
  cond->sem=1;
  futex(&cond->sem,FUTEX_WAKE,0x7fffffff,0,0,0);
  return thrd_success;
}


void cnd_destroy(cnd_t* cond) {

  (void)cond;
}


int cnd_init(cnd_t* cond) {
  cond->sem=0;
  return thrd_success;
}



int cnd_signal(cnd_t* cond) {
  cond->sem=1;
  futex(&cond->sem,FUTEX_WAKE,1,0,0,0);
  return thrd_success;
}




int cnd_timedwait(cnd_t* cond, mtx_t* mutex, const struct timespec* time_point) {
  int r;
  do {
    r=futex(&cond->sem,FUTEX_WAIT,0,time_point,0,0);
    if (r==-1) {
      if (
# 2175 "libc.h" 3 4
         (*__errno_location())
# 2175 "libc.h"
              ==
# 2175 "libc.h" 3 4
                11
# 2175 "libc.h"
                           ) break;
      else if (
# 2176 "libc.h" 3 4
              (*__errno_location())
# 2176 "libc.h"
                   ==
# 2176 "libc.h" 3 4
                     4
# 2176 "libc.h"
                          ) continue;
    } else
      break;
  } while (r==0);
  cond->sem=0;
  return mtx_timedlock(mutex,time_point);
}




int cnd_wait(cnd_t* cond, mtx_t* mutex) {
  return cnd_timedwait(cond,mutex,0);
}
# 1 "syscalls.h" 1
# 25 "syscalls.h"
# 1 "mips/syscalls.h" 1
# 26 "syscalls.h" 2
# 2191 "libc.h" 2


# 1 "./linuxnet.h" 1
# 2194 "libc.h" 2

extern int socketcall(int callno,long* args);

int __libc_connect(int a, void * b, int c);
int __libc_connect(int a, void * b, int c) {
  long args[] = { a, (long) b, c };
  return socketcall(3, args);
}

int connect(int a, void * b, int c) __attribute__((weak,alias("__libc_connect")));




int __libc_creat(const char *file,mode_t mode);
int __libc_creat(const char *file,mode_t mode) {
  return open(file,
# 2210 "libc.h" 3 4
                  0x0001
# 2210 "libc.h"
                          |
# 2210 "libc.h" 3 4
                           0x0100
# 2210 "libc.h"
                                  |
# 2210 "libc.h" 3 4
                                   0x0200
# 2210 "libc.h"
                                          ,mode);
}
int creat(const char *file,mode_t mode) __attribute__((weak,alias("__libc_creat")));






int creat64(const char *file,mode_t mode) {
  return open(file,
# 2220 "libc.h" 3 4
                  0x0001
# 2220 "libc.h"
                          |
# 2220 "libc.h" 3 4
                           0x0100
# 2220 "libc.h"
                                  |
# 2220 "libc.h" 3 4
                                   0x0200
# 2220 "libc.h"
                                          |
# 2220 "libc.h" 3 4
                                           0x2000
# 2220 "libc.h"
                                                      ,mode);
}
# 1 "dietwarning.h" 1
# 2223 "libc.h" 2


div_t div(int numerator, int denominator) {
  div_t x;
  x.quot=numerator/denominator;
  x.rem=numerator-x.quot*denominator;
  return x;
}

asm (".section .gnu.warning." "div" "\n\t.string \"" "warning: your code uses div(), which is completely superfluous!" "\"\n\t.previous");;




const char __sys_err_unknown [] = "[unknown error]";



# 1 "include/errno_definition.h" 1 3 4
 
# 1 "include/errno_definition.h" 3 4
      __thread int (*__errno_location());
# 2242 "libc.h" 2




# 1 "include/errno_definition.h" 1 3 4
 __thread int errno;
# 2247 "libc.h" 2



# 2249 "libc.h"
__attribute__((weak)) int *__errno_location(void) { return &errno; }




# 1 "include/sys/eventfd.h" 1 3 4










# 10 "include/sys/eventfd.h" 3 4
enum {
  EFD_CLOEXEC = 0x80000,

  EFD_NONBLOCK = 0x0080,

  EFD_SEMAPHORE = 1

};

typedef uint64_t eventfd_t;

int eventfd(unsigned int initval, int flags) __attribute__((__nothrow__ , __leaf__));


# 2255 "libc.h" 2

 
# 2256 "libc.h"
      int __eventfd(unsigned int count);
 int __eventfd2(unsigned int count,int flags);

int eventfd(unsigned int count,int flags) {
  int r=__eventfd2(count,flags);
  if (r==-1 && errno==
# 2261 "libc.h" 3 4
                     89
# 2261 "libc.h"
                           ) {
    r=__eventfd(count);
    if (r!=-1 && flags) {
      int x;
      x=fcntl(r,
# 2265 "libc.h" 3 4
               2
# 2265 "libc.h"
                      ,flags);
      if (x==-1)
 close(r);
    }
  }
  return r;
}

# 1 "include/paths.h" 1 3 4
# 2274 "libc.h" 2


 char **environ;

int __exec_shell(const char *file, char *const argv[]);
int __exec_shell(const char *file, char *const argv[]) {
  int i;
  const char** shell_argv;

  for (i = 0; argv[i]; ++i);
  ++i;

  shell_argv=
# 2286 "libc.h" 3 4
            __builtin_alloca(
# 2286 "libc.h"
            sizeof(char*)*(i+1)
# 2286 "libc.h" 3 4
            )
# 2286 "libc.h"
                                       ;
  shell_argv[0] = 
# 2287 "libc.h" 3 4
                 "/bin/sh"
# 2287 "libc.h"
                             ;
  shell_argv[1] = file;
  for (; i > 1; i--)
    shell_argv[i] = argv[i - 1];
  return execve(
# 2291 "libc.h" 3 4
               "/bin/sh"
# 2291 "libc.h"
                           , (char*const*)shell_argv, environ);
}







int execl( const char *path, const char* arg, ...) {
  va_list ap,bak;
  int n,i;
  char **argv,*tmp;
  (void)arg;
  
# 2305 "libc.h" 3 4
 __builtin_va_start((
# 2305 "libc.h"
 ap
# 2305 "libc.h" 3 4
 ),(
# 2305 "libc.h"
 arg
# 2305 "libc.h" 3 4
 ))
# 2305 "libc.h"
                  ;
  
# 2306 "libc.h" 3 4
 __builtin_va_copy((
# 2306 "libc.h"
 bak
# 2306 "libc.h" 3 4
 ),(
# 2306 "libc.h"
 ap
# 2306 "libc.h" 3 4
 ))
# 2306 "libc.h"
                ;
  n=2;
  while ((tmp=
# 2308 "libc.h" 3 4
             __builtin_va_arg
# 2308 "libc.h"
                   (ap,char *)))
    ++n;
  
# 2310 "libc.h" 3 4
 __builtin_va_end 
# 2310 "libc.h"
        (ap);
  if ((argv=(char **)
# 2311 "libc.h" 3 4
                    __builtin_alloca(
# 2311 "libc.h"
                    n*sizeof(char*)
# 2311 "libc.h" 3 4
                    )
# 2311 "libc.h"
                                           )) {
    argv[0]=(char*)arg;
    for (i=1; i<n; ++i)
      argv[i]=
# 2314 "libc.h" 3 4
             __builtin_va_arg
# 2314 "libc.h"
                   (bak,char *);
    
# 2315 "libc.h" 3 4
   __builtin_va_end 
# 2315 "libc.h"
          (bak);
    return execve(path,argv,environ);
  }
  
# 2318 "libc.h" 3 4
 __builtin_va_end 
# 2318 "libc.h"
        (bak);
  errno=
# 2319 "libc.h" 3 4
       12
# 2319 "libc.h"
             ;
  return -1;
}






int execle( const char *path, const char* arg, ...) {
  va_list ap;
  int n,i;
  char **argv,*tmp, **env;
  
# 2332 "libc.h" 3 4
 __builtin_va_start((
# 2332 "libc.h"
 ap
# 2332 "libc.h" 3 4
 ),(
# 2332 "libc.h"
 arg
# 2332 "libc.h" 3 4
 ))
# 2332 "libc.h"
                  ;
  (void)arg;
  n=2;
  while ((tmp=
# 2335 "libc.h" 3 4
             __builtin_va_arg
# 2335 "libc.h"
                   (ap,char *)))
    ++n;
  
# 2337 "libc.h" 3 4
 __builtin_va_end 
# 2337 "libc.h"
        (ap);
  if ((argv=(char **)
# 2338 "libc.h" 3 4
                    __builtin_alloca(
# 2338 "libc.h"
                    n*sizeof(char*)
# 2338 "libc.h" 3 4
                    )
# 2338 "libc.h"
                                           )) {
    
# 2339 "libc.h" 3 4
   __builtin_va_start((
# 2339 "libc.h"
   ap
# 2339 "libc.h" 3 4
   ),(
# 2339 "libc.h"
   arg
# 2339 "libc.h" 3 4
   ))
# 2339 "libc.h"
                    ;
    argv[0]=(char*)arg;
    for (i=1; i<n; ++i)
      argv[i]=
# 2342 "libc.h" 3 4
             __builtin_va_arg
# 2342 "libc.h"
                   (ap,char *);
    env=
# 2343 "libc.h" 3 4
       __builtin_va_arg
# 2343 "libc.h"
             (ap, char **);
    
# 2344 "libc.h" 3 4
   __builtin_va_end 
# 2344 "libc.h"
          (ap);
    return execve(path,argv,env);
  }
  errno=
# 2347 "libc.h" 3 4
       12
# 2347 "libc.h"
             ;
  return -1;
}






int execlp(const char* file, const char *arg,...) {
  va_list ap,bak;
  int n,i;
  char **argv,*tmp;
  
# 2360 "libc.h" 3 4
 __builtin_va_start((
# 2360 "libc.h"
 ap
# 2360 "libc.h" 3 4
 ),(
# 2360 "libc.h"
 arg
# 2360 "libc.h" 3 4
 ))
# 2360 "libc.h"
                  ;
  
# 2361 "libc.h" 3 4
 __builtin_va_copy((
# 2361 "libc.h"
 bak
# 2361 "libc.h" 3 4
 ),(
# 2361 "libc.h"
 ap
# 2361 "libc.h" 3 4
 ))
# 2361 "libc.h"
                ;
  n=2;
  while ((tmp=
# 2363 "libc.h" 3 4
             __builtin_va_arg
# 2363 "libc.h"
                   (ap,char *)))
    ++n;
  
# 2365 "libc.h" 3 4
 __builtin_va_end 
# 2365 "libc.h"
        (ap);
  if ((argv=(char **)
# 2366 "libc.h" 3 4
                    __builtin_alloca(
# 2366 "libc.h"
                    n*sizeof(char*)
# 2366 "libc.h" 3 4
                    )
# 2366 "libc.h"
                                           )) {
    argv[0]=(char*)arg;
    for (i=0; i<n; ++i)
      argv[i+1]=
# 2369 "libc.h" 3 4
               __builtin_va_arg
# 2369 "libc.h"
                     (bak,char *);
    
# 2370 "libc.h" 3 4
   __builtin_va_end 
# 2370 "libc.h"
          (bak);
    return execvp(file,argv);
  }
  
# 2373 "libc.h" 3 4
 __builtin_va_end 
# 2373 "libc.h"
        (bak);
  errno=
# 2374 "libc.h" 3 4
       12
# 2374 "libc.h"
             ;
  return -1;
}





# 1 "./lib/exec_lib.h" 1





 int __exec_shell(const char *file, char *const argv[]);
# 2383 "libc.h" 2


int execv(const char *file, char *const argv[]) {
  if (execve(file,argv,environ)==-1) {
    if (errno==
# 2387 "libc.h" 3 4
              8
# 2387 "libc.h"
                     )
      __exec_shell(file,argv);
  }
  return -1;
}
# 2400 "libc.h"
int execvp(const char *file, char *const argv[]) {
  const char *path=getenv("PATH");
  char *cur,*next;
  char buf[
# 2403 "libc.h" 3 4
          4095
# 2403 "libc.h"
                  ];
  if (strchr((char*)file,'/')) {
    if (execve(file,argv,environ)==-1) {
      if (errno==
# 2406 "libc.h" 3 4
                8
# 2406 "libc.h"
                       )
 __exec_shell(file,argv);
      return -1;
    }
  }
  if (!path) path=
# 2411 "libc.h" 3 4
                 "/bin:/usr/bin:"
# 2411 "libc.h"
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
# 2420 "libc.h" 3 4
                   4095
# 2420 "libc.h"
                           -3) { error: errno=
# 2420 "libc.h" 3 4
                                              22
# 2420 "libc.h"
                                                    ; return -1; }
      memmove(buf,cur,(size_t)(next-cur));
    }
    buf[next-cur]='/';
    {
      int len=strlen(file);
      if (len+(next-cur)>=
# 2426 "libc.h" 3 4
                         4095
# 2426 "libc.h"
                                 -2) goto error;
      memmove(&buf[next-cur+1],file,strlen(file)+1);
    }
    if (execve(buf,argv,environ)==-1) {
      if (errno==
# 2430 "libc.h" 3 4
                8
# 2430 "libc.h"
                       )
 return __exec_shell(buf,argv);
      if ((errno!=
# 2432 "libc.h" 3 4
                 13
# 2432 "libc.h"
                       ) && (errno!=
# 2432 "libc.h" 3 4
                                    2
# 2432 "libc.h"
                                          ) && (errno!=
# 2432 "libc.h" 3 4
                                                       20
# 2432 "libc.h"
                                                              )) return -1;
    }
    if (*next==0) break;
    next++;
  }
  return -1;
}


void explicit_bzero(void* dest,size_t len) {
  memset(dest,0,len);
  asm volatile("": : "r"(dest) : "memory");
}


void* explicit_memset(void* dest, int c, size_t len) {
  memset(dest,c,len);
  asm volatile("": : "r"(dest) : "memory");
  return dest;
}







DIR* fdopendir ( int fd ) {
  DIR* t = 
# 2460 "libc.h" 3 4
            (void*)0
# 2460 "libc.h"
                ;

  if ( fd >= 0 ) {
    t = (DIR *) mmap (
# 2463 "libc.h" 3 4
                     (void*)0
# 2463 "libc.h"
                         , 
# 2463 "libc.h" 3 4
                           4096UL
# 2463 "libc.h"
                                    , 
# 2463 "libc.h" 3 4
                                      0x1 
# 2463 "libc.h"
                                                | 
# 2463 "libc.h" 3 4
                                                  0x2
# 2463 "libc.h"
                                                            ,
  
# 2464 "libc.h" 3 4
 0x02 
# 2464 "libc.h"
             | 
# 2464 "libc.h" 3 4
               0x0800
# 2464 "libc.h"
                            , -1, 0);
    if (t != 
# 2465 "libc.h" 3 4
            ((void *) -1)
# 2465 "libc.h"
                      )
      t->fd = fd;
  }


  return t;
}
# 1 "include/strings.h" 1 3 4









# 9 "include/strings.h" 3 4
int strcasecmp(const char *s1, const char *s2) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__pure__));
int strncasecmp(const char *s1, const char *s2, size_t n) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__pure__));
int ffs(int i) __attribute__((__nothrow__ , __leaf__)) __attribute__((__const__));

int bcmp(const void *, const void *, size_t) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__((__deprecated__));
void bcopy(const void *, void *, size_t) __attribute__((__nothrow__ , __leaf__)) __attribute__((__deprecated__));
void bzero(void *, size_t) __attribute__((__nothrow__ , __leaf__)) __attribute__((__deprecated__));
char *index(const char *, int) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__((__deprecated__));
char *rindex(const char *, int) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__((__deprecated__));








# 2473 "libc.h" 2


# 2474 "libc.h"
int ffs(int i) {
  int plus=0;
# 2485 "libc.h"
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

# 1 "include/sys/statvfs.h" 1 3 4









# 9 "include/sys/statvfs.h" 3 4
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

int statvfs(const char *path, struct statvfs *buf) __attribute__((__nothrow__ , __leaf__));
int fstatvfs(int fd, struct statvfs *buf) __attribute__((__nothrow__ , __leaf__));



enum
{
  ST_RDONLY = 1,

  ST_NOSUID = 2
# 57 "include/sys/statvfs.h" 3 4
};


# 2505 "libc.h" 2


 
# 2507 "libc.h"
      void __statvfs_cvt(struct statfs* from,struct statvfs* to);

int fstatvfs(int fd, struct statvfs *sv) {
  struct statfs ss;
  if (fstatfs(fd,&ss)==-1) return -1;
  __statvfs_cvt(&ss,sv);
  return 0;
}

# 1 "include/sys/auxv.h" 1 3 4






# 6 "include/sys/auxv.h" 3 4
unsigned long getauxval(unsigned long type);



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
# 2517 "libc.h" 2


# 2518 "libc.h"
static void* find_in_auxvec(long* x,long what) {
  while (*x) {
    if (*x==what)
      return (void*)x[1];
    x+=2;
  }
  return 
# 2524 "libc.h" 3 4
        (void*)0
# 2524 "libc.h"
            ;
}

long* _auxvec;

unsigned long getauxval(unsigned long type) {
  return (long)find_in_auxvec(_auxvec,type);
}




# 1 "include/sys/utsname.h" 1 3 4






# 17 "include/sys/utsname.h" 3 4

# 17 "include/sys/utsname.h" 3 4
struct utsname {

  char sysname[65];


  char nodename[65];


  char release[65];

  char version[65];


  char machine[65];


  char domainname[65];
};

 int uname (struct utsname *__name) __attribute__((__nothrow__ , __leaf__));


# 2537 "libc.h" 2



# 2539 "libc.h"
int getdomainname(char *name,size_t len) {
  struct utsname u;
  int res=uname(&u);
  if (res==0) {
    size_t i;
    if (len>=
# 2544 "libc.h" 3 4
            65
# 2544 "libc.h"
                                  )
      len=
# 2545 "libc.h" 3 4
         65
# 2545 "libc.h"
                               ;
    for (i=0; i<len; i++)
      name[i]=u.domainname[i];
  }
  return res;
}




int getentropy(void* buf,size_t buflen) {
  int r;
  if (buflen>256) {
    errno=
# 2558 "libc.h" 3 4
         5
# 2558 "libc.h"
            ;
    return -1;
  }
  r=getrandom(buf,buflen,
# 2561 "libc.h" 3 4
                        GRND_NONBLOCK
# 2561 "libc.h"
                                     );
  if (r==-1 && errno==
# 2562 "libc.h" 3 4
                     89
# 2562 "libc.h"
                           ) {
    int fd=open("/dev/urandom",
# 2563 "libc.h" 3 4
                              0x0000
# 2563 "libc.h"
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







int gethostname(char *name,size_t len) {
  struct utsname u;
  int res=uname(&u);
  if (res==0) {
    size_t i;
    if (len>=
# 2599 "libc.h" 3 4
            65
# 2599 "libc.h"
                                    )
      len=
# 2600 "libc.h" 3 4
         65
# 2600 "libc.h"
                                 ;
    for (i=0; i<len; i++)
      name[i]=u.nodename[i];
  }
  return res;
}


# 1 "include/getopt.h" 1 3 4








# 8 "include/getopt.h" 3 4
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


# 2609 "libc.h" 2


# 2610 "libc.h"
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

int getopt(int argc, char * const argv[], const char *optstring) {
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
# 1 "syscalls.h" 1
# 25 "syscalls.h"
# 1 "mips/syscalls.h" 1
# 26 "syscalls.h" 2
# 2671 "libc.h" 2


# 1 "./linuxnet.h" 1
# 2674 "libc.h" 2


 int socketcall(int callno,long* args);

int __libc_getpeername(int a, void * b, int *c);
int __libc_getpeername(int a, void * b, int *c) {
  long args[] = { a, (long) b, (long) c };
  return socketcall(7, args);
}

int getpeername(int a, struct sockaddr* b, socklen_t *c) __attribute__((weak,alias("__libc_getpeername")));




pid_t getpgrp()
{
  return getpgid(0);
}
# 1 "syscalls.h" 1
# 25 "syscalls.h"
# 1 "mips/syscalls.h" 1
# 26 "syscalls.h" 2
# 2694 "libc.h" 2


# 1 "./linuxnet.h" 1
# 2697 "libc.h" 2


 int socketcall(int callno,long* args);

int __libc_getsockname(int a, void * b, int c);
int __libc_getsockname(int a, void * b, int c) {
  long args[] = { a, (long) b, c };
  return socketcall(6, args);
}

int getsockname(int a, struct sockaddr* b, socklen_t* c) __attribute__((weak,alias("__libc_getsockname")));


# 1 "syscalls.h" 1
# 25 "syscalls.h"
# 1 "mips/syscalls.h" 1
# 26 "syscalls.h" 2
# 2711 "libc.h" 2


# 1 "./linuxnet.h" 1
# 2714 "libc.h" 2


 int socketcall(int callno,long* args);

int __libc_getsockopt(int a, int b, int c, void *d, int e);
int __libc_getsockopt(int a, int b, int c, void *d, int e) {
  long args[] = { a, b, c, (long)d, e };
  return socketcall(15, args);
}

int getsockopt(int s, int level, int optname, void * optval, socklen_t *optlen) __attribute__((weak,alias("__libc_getsockopt")));



# 1 "include/netinet/in.h" 1 3 4











# 11 "include/netinet/in.h" 3 4
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
# 89 "include/netinet/in.h" 3 4
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
# 179 "include/netinet/in.h" 3 4
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
# 293 "include/netinet/in.h" 3 4
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
# 364 "include/netinet/in.h" 3 4
uint32_t htonl(uint32_t hostlong) __attribute__((const));
uint16_t htons(uint16_t hostshort) __attribute__((const));
uint32_t ntohl(uint32_t netlong) __attribute__((const));
uint16_t ntohs(uint16_t netshort) __attribute__((const));
# 409 "include/netinet/in.h" 3 4
int bindresvport(int sd, struct sockaddr_in* _sin);
# 431 "include/netinet/in.h" 3 4

# 2729 "libc.h" 2


# 2730 "libc.h"
uint32_t htonl(uint32_t hostlong) {




  return hostlong;

}

uint32_t ntohl(uint32_t hostlong) __attribute__((weak,alias("htonl")));



uint16_t htons(uint16_t hostshort) {



  return hostshort;

}

uint16_t ntohs(uint16_t hostshort) __attribute__((weak,alias("htons")));
# 1 "include/net/if.h" 1 3 4







# 38 "include/net/if.h" 3 4

# 38 "include/net/if.h" 3 4
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
# 89 "include/net/if.h" 3 4
struct ifconf {
  int32_t ifc_len;
  union {
    char * ifcu_buf;
    struct ifreq *ifcu_req;
  } ifc_ifcu;
};




unsigned int if_nametoindex (const char *ifname) __attribute__((__nothrow__ , __leaf__));
char *if_indextoname (unsigned int ifindex, char *ifname) __attribute__((__nothrow__ , __leaf__));

struct if_nameindex {
  uint32_t if_index;
  char *if_name;
};

struct if_nameindex* if_nameindex(void) __attribute__((__nothrow__ , __leaf__));
void if_freenameindex(struct if_nameindex* ptr) __attribute__((__nothrow__ , __leaf__));


# 2753 "libc.h" 2



# 2755 "libc.h"
void if_freenameindex(struct if_nameindex* ptr) {
  free(ptr);
}







struct if_nameindex* if_nameindex(void) {
  struct ifconf ic;
  int fd,len,i;
  struct if_nameindex* x=0,* y;
  char *dest;
  fd=socket(
# 2770 "libc.h" 3 4
           10
# 2770 "libc.h"
                   ,
# 2770 "libc.h" 3 4
                    1
# 2770 "libc.h"
                              ,0);
  if (fd<0) fd=socket(
# 2771 "libc.h" 3 4
                     2
# 2771 "libc.h"
                            ,
# 2771 "libc.h" 3 4
                             1
# 2771 "libc.h"
                                       ,0);
  ic.
# 2772 "libc.h" 3 4
    ifc_ifcu.ifcu_buf
# 2772 "libc.h"
           =0;
  ic.ifc_len=0;
  if (ioctl(fd,
# 2774 "libc.h" 3 4
              0x8912
# 2774 "libc.h"
                         ,&ic)<0) goto b0rken;
  ic.
# 2775 "libc.h" 3 4
    ifc_ifcu.ifcu_buf
# 2775 "libc.h"
           =
# 2775 "libc.h" 3 4
            __builtin_alloca(
# 2775 "libc.h"
            (size_t)ic.ifc_len
# 2775 "libc.h" 3 4
            )
# 2775 "libc.h"
                                      ;
  if (ioctl(fd,
# 2776 "libc.h" 3 4
              0x8912
# 2776 "libc.h"
                         ,&ic)<0) goto b0rken;
  len=(ic.ifc_len/sizeof(struct ifreq));
  x=(struct if_nameindex*)malloc((len+1)*sizeof(struct if_nameindex)+len*
# 2778 "libc.h" 3 4
                                                                        16
# 2778 "libc.h"
                                                                                );
  if (!x) goto b0rken;
  dest=(char*)(x+len+1);
  y=x;
  for (i=0; i<len; ++i) {
    struct ifreq* ir=(struct ifreq*)&ic.
# 2783 "libc.h" 3 4
                                       ifc_ifcu.ifcu_req
# 2783 "libc.h"
                                              [i];
    y->if_name=dest;
    memcpy(dest,ir->
# 2785 "libc.h" 3 4
                   ifr_ifrn.ifrn_name
# 2785 "libc.h"
                           ,
# 2785 "libc.h" 3 4
                            16
# 2785 "libc.h"
                                    );
    if (ioctl(fd,
# 2786 "libc.h" 3 4
                0x8933
# 2786 "libc.h"
                            ,ir)==-1) continue;
    y->if_index=ir->
# 2787 "libc.h" 3 4
                   ifr_ifru.ifru_ivalue
# 2787 "libc.h"
                              ;
    dest+=
# 2788 "libc.h" 3 4
         16
# 2788 "libc.h"
                 ;
    ++y;
  }
  y->if_name=0; y->if_index=0;
b0rken:
  close(fd);
  return x;
}
# 2805 "libc.h"
char* if_indextoname(unsigned int interface,char* blub) {
  struct ifreq ifr;
  int fd;

  fd=socket(
# 2809 "libc.h" 3 4
           10
# 2809 "libc.h"
                   ,
# 2809 "libc.h" 3 4
                    1
# 2809 "libc.h"
                              ,0);
  if (fd<0) fd=socket(
# 2810 "libc.h" 3 4
                     2
# 2810 "libc.h"
                            ,
# 2810 "libc.h" 3 4
                             1
# 2810 "libc.h"
                                       ,0);
  ifr.
# 2811 "libc.h" 3 4
     ifr_ifru.ifru_ivalue
# 2811 "libc.h"
                =interface;
  if (ioctl(fd,
# 2812 "libc.h" 3 4
              0x8910
# 2812 "libc.h"
                         ,&ifr)==0) {
    int i;
    close(fd);
    for (i=0; i<
# 2815 "libc.h" 3 4
               16
# 2815 "libc.h"
                       -1; i++)
      if (!(blub[i]=ifr.
# 2816 "libc.h" 3 4
                       ifr_ifrn.ifrn_name
# 2816 "libc.h"
                               [i]))
 return blub;
    blub[i]=0;
    return blub;
  }
  close(fd);
  return 0;
}


int isalnum(int ch) {
  return (unsigned int)((ch | 0x20) - 'a') < 26u ||
  (unsigned int)( ch - '0') < 10u;
}
# 2839 "libc.h"
unsigned int if_nametoindex(const char* blub) {
  struct ifreq ifr;
  int fd;
  int ret=0;
  char *tmp;
  int len=sizeof(ifr.
# 2844 "libc.h" 3 4
                    ifr_ifrn.ifrn_name
# 2844 "libc.h"
                            );
  fd=socket(
# 2845 "libc.h" 3 4
           10
# 2845 "libc.h"
                   ,
# 2845 "libc.h" 3 4
                    1
# 2845 "libc.h"
                              ,0);
  if (fd<0) fd=socket(
# 2846 "libc.h" 3 4
                     2
# 2846 "libc.h"
                            ,
# 2846 "libc.h" 3 4
                             1
# 2846 "libc.h"
                                       ,0);
  for (tmp=ifr.
# 2847 "libc.h" 3 4
              ifr_ifrn.ifrn_name
# 2847 "libc.h"
                      ; len>0; --len) {
    if ((*tmp++=*blub++)==0) break;
  }
  if (ioctl(fd,
# 2850 "libc.h" 3 4
              0x8933
# 2850 "libc.h"
                          ,&ifr)==0)
    ret=ifr.
# 2851 "libc.h" 3 4
           ifr_ifru.ifru_ivalue
# 2851 "libc.h"
                      ;
  close(fd);
  return ret;
}


int isalpha(int ch) {
  return (unsigned int)((ch | 0x20) - 'a') < 26u;
}


int isascii ( int ch )
{
    return (unsigned int)ch < 128u;
}
# 2874 "libc.h"
int isatty(int fd) {
  int save;
  int is_tty;
  struct termios term;

  save = errno;
  is_tty = ioctl(fd, 
# 2880 "libc.h" 3 4
                    0x540d
# 2880 "libc.h"
                          , &term) == 0;
  errno = save;

  return is_tty;
}



int isblank ( int ch )
{
    return ch == ' ' || ch == '\t';
}


int __iscntrl_ascii ( int ch );
int __iscntrl_ascii ( int ch ) {
    return (unsigned int)ch < 32u || ch == 127;
}

int iscntrl ( int ch ) __attribute__((weak,alias("__iscntrl_ascii")));


int __isdigit_ascii ( int ch );
int __isdigit_ascii ( int ch ) {
    return (unsigned int)(ch - '0') < 10u;
}

int isdigit ( int ch ) __attribute__((weak,alias("__isdigit_ascii")));
int __isgraph_ascii ( int ch );
int __isgraph_ascii ( int ch ) {
  return (unsigned int)(ch - '!') < 127u - '!';
}

int isgraph ( int ch ) __attribute__((weak,alias("__isgraph_ascii")));


int __islower_ascii ( int ch );
int __islower_ascii ( int ch ) {
    return (unsigned int) (ch - 'a') < 26u;
}

int islower ( int ch ) __attribute__((weak,alias("__islower_ascii")));



int isprint (int ch) {
  ch&=0x7f;
  return (ch>=32 && ch<127);
}


int __ispunct_ascii ( int ch );
int __ispunct_ascii ( int ch )
{
    return isprint (ch) && !isalnum (ch) && !isspace (ch);
}

int ispunct ( int ch ) __attribute__((weak,alias("__ispunct_ascii")));


int __isspace_ascii ( int ch );
int __isspace_ascii ( int ch )
{
    return (unsigned int)(ch - 9) < 5u || ch == ' ';
}

int isspace ( int ch ) __attribute__((weak,alias("__isspace_ascii")));


int __isupper_ascii ( int ch );
int __isupper_ascii ( int ch )
{
    return (unsigned int)(ch - 'A') < 26u;
}

int isupper ( int ch ) __attribute__((weak,alias("__isupper_ascii")));

# 1 "include/wctype.h" 1 3 4







# 7 "include/wctype.h" 3 4
typedef const int32_t* wctrans_t;

int iswalnum(wint_t) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__const__));
int iswalpha(wint_t) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__const__));
int iswblank(wint_t) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__const__));
int iswcntrl(wint_t) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__const__));
int iswdigit(wint_t) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__const__));
int iswgraph(wint_t) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__const__));
int iswlower(wint_t) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__const__));
int iswprint(wint_t) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__const__));
int iswpunct(wint_t) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__const__));
int iswspace(wint_t) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__const__));
int iswupper(wint_t) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__const__));
int iswxdigit(wint_t) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__const__));
int iswctype(wint_t, wctype_t) __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__const__));
wint_t towctrans(wint_t, wctrans_t) __attribute__((__nothrow__ , __leaf__));
wint_t towlower(wint_t) __attribute__((__nothrow__ , __leaf__));
wint_t towupper(wint_t) __attribute__((__nothrow__ , __leaf__));
wctrans_t wctrans(const char *) __attribute__((__nothrow__ , __leaf__));
wctype_t wctype(const char *) __attribute__((__nothrow__ , __leaf__));
# 2958 "libc.h" 2


# 2959 "libc.h"
int __iswalnum_ascii(wint_t c);
int __iswalnum_ascii(wint_t c) {
  return (((unsigned char)c == c)?isalnum(c):0);
}

int iswalnum(wint_t c) __attribute__((weak,alias("__iswalnum_ascii")));



int __iswalpha_ascii(wint_t c);
int __iswalpha_ascii(wint_t c) {
  return (((unsigned char)c == c)?isalpha(c):0);
}

int iswalpha(wint_t c) __attribute__((weak,alias("__iswalpha_ascii")));


int __iswblank_ascii(wint_t c);
int __iswblank_ascii(wint_t c) {
  return (c == ' ' || c == '\t');
}

int iswblank(wint_t c) __attribute__((weak,alias("__iswblank_ascii")));


int __iswcntrl_ascii(wint_t c);
int __iswcntrl_ascii(wint_t c) {
  return ((unsigned int)c < 32u || c == 127);
}

int iswcntrl(wint_t c) __attribute__((weak,alias("__iswcntrl_ascii")));


int iswdigit(wint_t c) {
    return (unsigned int)(c - '0') < 10u;
}


int __iswgraph_ascii(wint_t c);
int __iswgraph_ascii(wint_t c) {
  return (unsigned int)(c - '!') < 127u - '!';
}

int iswgraph(wint_t c) __attribute__((weak,alias("__iswgraph_ascii")));


int __iswlower_ascii(wint_t c);
int __iswlower_ascii(wint_t c) {
  return (unsigned int) (c - 'a') < 26u;
}

int iswlower ( wint_t ch ) __attribute__((weak,alias("__iswlower_ascii")));


int __iswprint_ascii(wint_t c);
int __iswprint_ascii(wint_t c) {
    return (unsigned int)(c - ' ') < 127u - ' ';
}

int iswprint(wint_t c) __attribute__((weak,alias("__iswprint_ascii")));


int __iswpunct_ascii(wint_t c);
int __iswpunct_ascii(wint_t c)
{
  return iswprint (c) && !iswalnum(c) && !iswspace(c);
}

int iswpunct(wint_t c) __attribute__((weak,alias("__iswpunct_ascii")));


int __iswspace_ascii(wint_t c);
int __iswspace_ascii(wint_t c) {
  return (unsigned int)(c - 9) < 5u || c == ' ';
}

int iswspace(wint_t c) __attribute__((weak,alias("__iswspace_ascii")));


int __iswupper_ascii ( wint_t c );
int __iswupper_ascii ( wint_t c )
{
    return (unsigned int)(c - 'A') < 26u;
}

int iswupper ( wint_t c ) __attribute__((weak,alias("__iswupper_ascii")));


int __iswxdigit_ascii(wint_t c);
int __iswxdigit_ascii(wint_t c)
{
    return (unsigned int)( c - '0') < 10u ||
           (unsigned int)((c | 0x20) - 'a') < 6u;
}

int iswxdigit(wint_t c) __attribute__((weak,alias("__iswxdigit_ascii")));
int __isxdigit_ascii ( int ch );
int __isxdigit_ascii ( int ch )
{
    return (unsigned int)( ch - '0') < 10u ||
           (unsigned int)((ch | 0x20) - 'a') < 6u;
}

int isxdigit ( int ch ) __attribute__((weak,alias("__isxdigit_ascii")));
# 3074 "libc.h"
ldiv_t ldiv(long numerator, long denominator) {
  ldiv_t x;
  x.quot=numerator/denominator;
  x.rem=numerator-x.quot*denominator;
  return x;
}
# 1 "syscalls.h" 1
# 25 "syscalls.h"
# 1 "mips/syscalls.h" 1
# 26 "syscalls.h" 2
# 3081 "libc.h" 2


# 1 "./linuxnet.h" 1
# 3084 "libc.h" 2


 int socketcall(int callno,long* args);

int __libc_listen(int a, int b);
int __libc_listen(int a, int b) {
  long args[] = { a, b, 0 };
  return socketcall(4, args);
}

int listen(int s, int backlog) __attribute__((weak,alias("__libc_listen")));







long long int llabs(long long int i) { if (i<0) i=-i; return i; }
intmax_t imaxabs(intmax_t i) __attribute__((alias("llabs")));





lldiv_t lldiv(long long numerator, long long denominator) {
  lldiv_t x;
  x.quot=numerator/denominator;
  x.rem=numerator-x.quot*denominator;
  return x;
}

imaxdiv_t imaxdiv(intmax_t numerator, intmax_t denominator) __attribute__((alias("lldiv")));






int lockf(int fd, int cmd, off_t len) {
  struct flock fl;
  fl.l_whence=
# 3125 "libc.h" 3 4
             1
# 3125 "libc.h"
                     ;
  fl.l_start=0;
  fl.l_len=len;
  fl.l_pid=0;
  switch (cmd) {
  case 
# 3130 "libc.h" 3 4
      3
# 3130 "libc.h"
            :
    if (fcntl(fd,
# 3131 "libc.h" 3 4
                14
# 3131 "libc.h"
                       ,&fl)<0)
      return -1;
    if (fl.l_type == 
# 3133 "libc.h" 3 4
                    2 
# 3133 "libc.h"
                            || fl.l_pid == getpid ())
      return 0;
    errno=
# 3135 "libc.h" 3 4
         13
# 3135 "libc.h"
               ;
    return -1;
  case 
# 3137 "libc.h" 3 4
      0
# 3137 "libc.h"
             :
    fl.l_type=
# 3138 "libc.h" 3 4
             2
# 3138 "libc.h"
                    ;
    cmd=
# 3139 "libc.h" 3 4
       6
# 3139 "libc.h"
              ;
    break;
  case 
# 3141 "libc.h" 3 4
      1
# 3141 "libc.h"
            :
    fl.l_type = 
# 3142 "libc.h" 3 4
               1
# 3142 "libc.h"
                      ;
    cmd = 
# 3143 "libc.h" 3 4
         7
# 3143 "libc.h"
                 ;
    break;
  case 
# 3145 "libc.h" 3 4
      2
# 3145 "libc.h"
             :
    fl.l_type = 
# 3146 "libc.h" 3 4
               1
# 3146 "libc.h"
                      ;
    cmd = 
# 3147 "libc.h" 3 4
         6
# 3147 "libc.h"
                ;
    break;
  default:
    errno=
# 3150 "libc.h" 3 4
         22
# 3150 "libc.h"
               ;
    return -1;
  }
  return fcntl(fd,cmd,&fl);
}



void __longjmp(void*env,int val);

void __libc_longjmp(sigjmp_buf env,int val);
void __libc_longjmp(sigjmp_buf env,int val) {
  if (env[0].__mask_was_saved) {
    sigprocmask(
# 3163 "libc.h" 3 4
               3
# 3163 "libc.h"
                          ,(sigset_t*)&env[0].__saved_mask,0);
  }
  if (val==0) val=1;
  __longjmp(env[0].__jmpbuf,val);
}
void __siglongjmp(sigjmp_buf env,int val) __attribute__((alias("__libc_longjmp")));
void longjmp(sigjmp_buf env,int val) __attribute__((weak,alias("__libc_longjmp")));
void siglongjmp(sigjmp_buf env,int val) __attribute__((weak,alias("__libc_longjmp")));







loff_t lseek64(int fildes, loff_t offset, int whence) {
  loff_t tmp;
  if (llseek(fildes,(unsigned long)(offset>>32),(unsigned long)offset&0xffffffff,&tmp,whence)) {
    if (errno!=
# 3181 "libc.h" 3 4
              89
# 3181 "libc.h"
                    ) return -1;
    return (loff_t)lseek(fildes,(off_t)offset,whence);
  }
  return tmp;
}




int mblen(const char* s,size_t n) {
  return mbrlen(s,n,
# 3191 "libc.h" 3 4
                   (void*)0
# 3191 "libc.h"
                       );
}



size_t mbrlen(const char *s, size_t n, mbstate_t *ps) {
  static mbstate_t internal;
  return mbrtowc (
# 3198 "libc.h" 3 4
                 (void*)0
# 3198 "libc.h"
                     , s, n, ps ?: &internal);
}




static mbstate_t internal;

size_t mbrtowc(wchar_t *pwc, const char *s, size_t n, mbstate_t *ps) {
  size_t i;
  if (!ps) ps=&internal;
  if (!s) {
    if (ps->count) {
      errno=
# 3211 "libc.h" 3 4
           88
# 3211 "libc.h"
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
# 3231 "libc.h" 3 4
        88
# 3231 "libc.h"
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


int mbsinit(const mbstate_t* s) {
  return (!s || s->sofar);
}


size_t mbsrtowcs(wchar_t *dest, const char **src, size_t len, mbstate_t *ps) {
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



size_t mbstowcs(wchar_t *dest, const char *src, size_t n) {
  const char** s=&src;
  return mbsrtowcs(dest,s,n,
# 3290 "libc.h" 3 4
                           (void*)0
# 3290 "libc.h"
                               );
}



int mbtowc(wchar_t *pwc, const char *s, size_t n) {
  return mbrtowc(pwc,s,n,
# 3296 "libc.h" 3 4
                        (void*)0
# 3296 "libc.h"
                            );
}





void *memccpy(void *dst, const void *src, int c, size_t count)
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


# 1 "dietstring.h" 1
# 3321 "libc.h" 2

void* memchr(const void *s, int c, size_t n) {
  const unsigned char *pc = (unsigned char *) s;
  for (;n--;pc++)
    if (*pc == c)
      return ((void *) pc);
  return 0;
}





int memcmp(const void *dst, const void *src, size_t count) {
  register int r;
  register const unsigned char *d=dst;
  register const unsigned char *s=src;
  ++count;
  while (
# 3339 "libc.h" 3 4
        __builtin_expect((long)((
# 3339 "libc.h"
        --count
# 3339 "libc.h" 3 4
        )),1)
# 3339 "libc.h"
                         ) {
    if (
# 3340 "libc.h" 3 4
       __builtin_expect((long)((
# 3340 "libc.h"
       r=(*d - *s)
# 3340 "libc.h" 3 4
       )),0)
# 3340 "libc.h"
                              )
      return r;
    ++d;
    ++s;
  }
  return 0;
}

int 
# 3348 "libc.h" 3 4
   memcmp(
# 3348 "libc.h"
   const char *a
# 3348 "libc.h" 3 4
   ,
# 3348 "libc.h"
   const char *b
# 3348 "libc.h" 3 4
   ,
# 3348 "libc.h"
   size_t c
# 3348 "libc.h" 3 4
   ) 
# 3348 "libc.h"
                                              __attribute__((weak,alias("memcmp")));






void *
memcpy (void *dst, const void *src, size_t n)
{
    void *res = dst;
    unsigned char *c1, *c2;






    int tmp;
    unsigned long *lx1 = 
# 3367 "libc.h" 3 4
                         (void*)0
# 3367 "libc.h"
                             ;
    const unsigned long *lx2 = 
# 3368 "libc.h" 3 4
                              (void*)0
# 3368 "libc.h"
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




void *memmem(const void* haystack, size_t hl, const void* needle, size_t nl) {
  int i;
  if (nl>hl) return 0;
  for (i=hl-nl+1; i; --i) {
    if (!memcmp(haystack,needle,nl))
      return (char*)haystack;
    ++haystack;
  }
  return 0;
}





void *memmove(void *dst, const void *src, size_t count)
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




void* memrchr(const void *s, int c, size_t n) {
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



int mkfifo(const char *fn,mode_t mode) {
  return mknod(fn,(mode_t)(mode|
# 3457 "libc.h" 3 4
                               0010000
# 3457 "libc.h"
                                      ),0);
}





void* memset(void * dst, int s, size_t count) {
    register char * a = dst;
    count++;
    while (--count)
 *a++ = s;
    return dst;
}
# 1 "./dietfeatures.h" 1
# 3472 "libc.h" 2


# 1 "./syscalls.h" 1
# 25 "./syscalls.h"
# 1 "./mips/syscalls.h" 1
# 26 "./syscalls.h" 2
# 3475 "libc.h" 2



void*__mmap2(void*start,size_t length,int prot,int flags,int fd,off_t pgoffset);

void*__libc_mmap64(void*addr,size_t len,int prot,int flags,int fd,off64_t offset);
void*__libc_mmap64(void*addr,size_t len,int prot,int flags,int fd,off64_t offset) {
  if (offset&(
# 3482 "libc.h" 3 4
             4096UL
# 3482 "libc.h"
                      -1)) {
    errno=-
# 3483 "libc.h" 3 4
          22
# 3483 "libc.h"
                ;
    return 
# 3484 "libc.h" 3 4
          ((void *) -1)
# 3484 "libc.h"
                    ;
  }
  return __mmap2(addr,len,prot,flags,fd,offset>>
# 3486 "libc.h" 3 4
                                               12
# 3486 "libc.h"
                                                         );
}

void*mmap64(void*addr,size_t len,int prot,int flags,int fd,off64_t offset)
__attribute__((weak,alias("__libc_mmap64")));

# 1 "include/mqueue.h" 1 3 4
# 11 "include/mqueue.h" 3 4

# 11 "include/mqueue.h" 3 4
typedef int mqd_t;
struct mq_attr {
  long mq_flags;
  long mq_maxmsg;
  long mq_msgsize;
  long mq_curmsgs;
  long __reserved[4];
};









mqd_t mq_open(const char *name, int oflag, ...) __attribute__((__nothrow__ , __leaf__));
int mq_unlink(const char *name) __attribute__((__nothrow__ , __leaf__));
int mq_send(mqd_t mqdes, const char *msg_ptr, size_t msg_len, unsigned msg_prio) __attribute__((__nothrow__ , __leaf__));
int mq_timedsend(mqd_t mqdes, const char *msg_ptr, size_t msg_len, unsigned msg_prio,
   const struct timespec *abs_timeout) __attribute__((__nothrow__ , __leaf__));
ssize_t mq_receive(mqd_t mqdes, char *msg_ptr, size_t msg_len, unsigned *msg_prio) __attribute__((__nothrow__ , __leaf__));
ssize_t mq_timedreceive(mqd_t mqdes, char *__restrict__ msg_ptr, size_t msg_len,
   unsigned *__restrict__ msg_prio, const struct timespec *__restrict__ abs_timeout) __attribute__((__nothrow__ , __leaf__));
int mq_notify(mqd_t mqdes, const struct sigevent *notification) __attribute__((__nothrow__ , __leaf__));
int mq_getattr(mqd_t mqdes, struct mq_attr *mqstat) __attribute__((__nothrow__ , __leaf__));
int mq_setattr(mqd_t mqdes, const struct mq_attr *__restrict__ mqstat, struct mq_attr *__restrict__ omqstat) __attribute__((__nothrow__ , __leaf__));


# 3493 "libc.h" 2


# 3494 "libc.h"
int mq_getattr(mqd_t mqdes, struct mq_attr *mqstat) {
  return mq_setattr(mqdes, 
# 3495 "libc.h" 3 4
                          (void*)0
# 3495 "libc.h"
                              , mqstat);
}



ssize_t mq_receive(mqd_t mqdes, char *msg_ptr, size_t msg_len, unsigned int *msg_prio) {
  return mq_timedreceive(mqdes, msg_ptr, msg_len, msg_prio, 
# 3501 "libc.h" 3 4
                                                           (void*)0
# 3501 "libc.h"
                                                               );
}



int mq_send (mqd_t mqdes, const char *msg_ptr, size_t msg_len, unsigned int msg_prio) {
  return mq_timedsend(mqdes, msg_ptr, msg_len, msg_prio, 
# 3507 "libc.h" 3 4
                                                        (void*)0
# 3507 "libc.h"
                                                            );
}



# 1 "include/sys/msg.h" 1 3 4






# 16 "include/sys/msg.h" 3 4

# 16 "include/sys/msg.h" 3 4
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





 int msgctl (int msqid, int cmd, struct msqid_ds *buf) __attribute__((__nothrow__ , __leaf__));
 int msgget (key_t key, int msgflg) __attribute__((__nothrow__ , __leaf__));
 int msgrcv (int msqid, void *msgp, size_t msgsz, long int msgtyp, int msgflg) __attribute__((__nothrow__ , __leaf__));
 int msgsnd (int msqid, const void *msgp, size_t msgsz, int msgflg) __attribute__((__nothrow__ , __leaf__));


# 3513 "libc.h" 2

 
# 3514 "libc.h"
      int __ipc(int,int,int,int,void*);

int msgctl(int msqid, int cmd, struct msqid_ds *buf) {
  return __ipc(
# 3517 "libc.h" 3 4
              14
# 3517 "libc.h"
                    ,msqid,cmd,0,buf);
}




 int __ipc(int,key_t,int,int,int);

int msgget(key_t key,int flag) {
  return __ipc(
# 3526 "libc.h" 3 4
              13
# 3526 "libc.h"
                    ,key,flag,0,0);
}




 int __ipc(int,int,size_t,int,void*);

struct ipc_kludge {
  struct msgbuf *msgp;
  long msgtyp;
};

int msgrcv(int msqid, void *msgp, size_t msgsz, long int msgtyp, int msgflg) {
  struct ipc_kludge tmp;
  tmp.msgp = msgp;
  tmp.msgtyp = msgtyp;
  return __ipc(
# 3543 "libc.h" 3 4
              12
# 3543 "libc.h"
                    ,msqid, msgsz, msgflg, &tmp);
}




 int __ipc(int,int,size_t,int,const void*);

int msgsnd (int msqid, const void *msgp, size_t msgsz, int msgflg) {
  return __ipc(
# 3552 "libc.h" 3 4
              11
# 3552 "libc.h"
                    ,msqid, msgsz, msgflg, msgp);
}


void mtx_destroy(mtx_t* mutex) {

  (void)mutex;
}


int mtx_init(mtx_t* mutex, int type) {
  mutex->lock=0;
  mutex->type=type;
  return thrd_success;
}





int mtx_lock(mtx_t* mutex) {
  return mtx_timedlock(mutex,0);
}






int mtx_timedlock(mtx_t* mutex, const struct timespec* time_point) {
  int i,r;
  do {
    r=__mtx_trylock(mutex,&i);
    if (r!=thrd_busy) return r;
    for (;;) {
      r=futex(&mutex->lock,FUTEX_WAIT,i,time_point,0,0);
      if (r==-1) {
 if (errno==
# 3589 "libc.h" 3 4
           11
# 3589 "libc.h"
                      ) { r=0; break; } else
 if (errno==
# 3590 "libc.h" 3 4
           145
# 3590 "libc.h"
                    ) return thrd_timedout; else
 if (errno==
# 3591 "libc.h" 3 4
           4
# 3591 "libc.h"
                ) continue;
      } else
 break;
    }
  } while (r==0);
  return thrd_error;
}






int __mtx_trylock(mtx_t* mutex,int* lockval) {
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

int mtx_trylock(mtx_t* mutex) {
  return __mtx_trylock(mutex,
# 3624 "libc.h" 3 4
                            (void*)0
# 3624 "libc.h"
                                );
}





int mtx_unlock(mtx_t* mutex) {
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







int nice(int incr) {
  int prio;
  int res;
  errno=0;
  prio = getpriority(
# 3659 "libc.h" 3 4
                    0
# 3659 "libc.h"
                                ,0) + incr;
  if (prio < 
# 3660 "libc.h" 3 4
            (-20)
# 3660 "libc.h"
                    ) prio=
# 3660 "libc.h" 3 4
                           (-20)
# 3660 "libc.h"
                                   ;
  if (prio >= 
# 3661 "libc.h" 3 4
             20
# 3661 "libc.h"
                     ) prio=
# 3661 "libc.h" 3 4
                            20
# 3661 "libc.h"
                                    -1;
  if (setpriority (
# 3662 "libc.h" 3 4
                  0
# 3662 "libc.h"
                              , 0, prio)==-1) {
    if (errno==
# 3663 "libc.h" 3 4
              13
# 3663 "libc.h"
                    ) errno=
# 3663 "libc.h" 3 4
                            1
# 3663 "libc.h"
                                 ;
    return -1;
  } else
    return getpriority(
# 3666 "libc.h" 3 4
                      0
# 3666 "libc.h"
                                  , 0);
}







int __libc_open64(const char* file,int oflag,int mode);
int __libc_open64(const char* file,int oflag,int mode) {
  return open(file,oflag|
# 3677 "libc.h" 3 4
                        0x2000
# 3677 "libc.h"
                                   ,mode);
}

int open64(const char* file,int oflag,...) __attribute__((weak,alias("__libc_open64")));







DIR* opendir ( const char* name ) {
  int fd = open (name, 
# 3689 "libc.h" 3 4
                        0x0000 
# 3689 "libc.h"
                                 | 
# 3689 "libc.h" 3 4
                                   0x10000
# 3689 "libc.h"
                                              );
  DIR* t = 
# 3690 "libc.h" 3 4
            (void*)0
# 3690 "libc.h"
                ;

  if ( fd >= 0 ) {
    if (fcntl (fd, 
# 3693 "libc.h" 3 4
                  2
# 3693 "libc.h"
                         , 
# 3693 "libc.h" 3 4
                           1
# 3693 "libc.h"
                                     ) < 0)
      goto lose;
    t = (DIR *) mmap (
# 3695 "libc.h" 3 4
                     (void*)0
# 3695 "libc.h"
                         , 
# 3695 "libc.h" 3 4
                           4096UL
# 3695 "libc.h"
                                    , 
# 3695 "libc.h" 3 4
                                      0x1 
# 3695 "libc.h"
                                                | 
# 3695 "libc.h" 3 4
                                                  0x2
# 3695 "libc.h"
                                                            ,
  
# 3696 "libc.h" 3 4
 0x02 
# 3696 "libc.h"
             | 
# 3696 "libc.h" 3 4
               0x0800
# 3696 "libc.h"
                            , -1, 0);
    if (t == 
# 3697 "libc.h" 3 4
            ((void *) -1)
# 3697 "libc.h"
                      )
lose:
      close (fd);
    else
      t->fd = fd;
  }


  return t;
}
# 3717 "libc.h"
 const char __sys_err_unknown [];

void perror ( const char* prepend )
{
    register const char* message = __sys_err_unknown;

    if ( (unsigned int) errno < (unsigned int) 
# 3723 "libc.h" 3 4
                                              ((168) + 1) 
# 3723 "libc.h"
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

size_t __libc_pread(int fd, void *buf, size_t count, off_t offset);
size_t __libc_pread(int fd, void *buf, size_t count, off_t offset) {
  return __pread(fd,buf,count,0,0
# 3740 "libc.h" 3 4
                               , 
# 3740 "libc.h"
                               offset);
}

int pread(int fd, void *buf, size_t count, off_t offset) __attribute__((weak,alias("__libc_pread")));




int posix_fallocate(int fd, off64_t offset, off64_t len) {
  return fallocate(fd,0,offset,len);
}




int putenv(const char *string) {
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
# 3845 "libc.h"
int pselect(int n, fd_set* readfds, fd_set* writefds, fd_set* exceptfds,
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
# 3856 "libc.h" 3 4
               3
# 3856 "libc.h"
                          ,sigmask,&old);
  r=select(n,readfds,writefds,exceptfds,
    timeout?&t:0);
  if (sigmask)
    sigprocmask(
# 3860 "libc.h" 3 4
               3
# 3860 "libc.h"
                          ,&old,0);
  return r;
}



 size_t __pwrite(int fd, void *buf, size_t count, int dummy, off_t a, off_t b);

size_t __libc_pwrite(int fd, void *buf, size_t count, off_t offset);
size_t __libc_pwrite(int fd, void *buf, size_t count, off_t offset) {
  return __pwrite(fd,buf,count,0,0
# 3870 "libc.h" 3 4
                                , 
# 3870 "libc.h"
                                offset);
}

int pwrite(int fd, void *buf, size_t count, off_t offset) __attribute__((weak,alias("__libc_pwrite")));


# 1 "rand_i.h" 1

 int rand_i(void) 
# 2 "rand_i.h" 3 4
                       __attribute__((__nothrow__ , __leaf__))
# 2 "rand_i.h"
                              ;
# 3877 "libc.h" 2

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
# 3907 "libc.h"
  exch(base,size,l+(rand_i()%(r-l)),r);
# 3918 "libc.h"
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

void qsort(void* base,size_t nmemb,size_t size,int (*compar)(const void*,const void*)) {

  if (nmemb >= (((size_t)-1)>>1) ||
      size >= (((size_t)-1)>>1)) return;







  if (nmemb>1)
    quicksort(base,size,0,nmemb-1,compar);
}




int raise(int sig) {
  return kill(getpid(),sig);
}


static unsigned int seed=1;

int rand(void) {
  return rand_r(&seed);
}

void srand(unsigned int i) { seed=i?i:23; }

int random(void) __attribute__((leaf, nothrow, alias("rand")));
void srandom(unsigned int i) __attribute__((leaf, nothrow, alias("srand")));


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

double drand48(void) {
 return erand48(rand48buf);
}

long lrand48(void) {
 return nrand48(rand48buf);
}

long mrand48(void) {
 return jrand48(rand48buf);
}

void srand48(long seed) {
 rand48buf[1] = (seed >> 16) & 0xffff;
 rand48buf[2] = seed & 0xffff;
 rand48buf[0] = 0x330e;
 a[0] = 0xE66D;
 a[1] = 0xDEEC;
 a[2] = 0x5;
 c = 0xB;
}

unsigned short *seed48(randbuf buf) {
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

void lcong48(unsigned short param[7]) {
 int i;
 for (i = 0; i < 3; i++) {
  rand48buf[i] = param[i];
  a[i] = param[i + 3];
 }
 c = param[6];
}

long jrand48(randbuf buf) {
 long ret;
 ret = buf[2] << 16 | buf[1];
 calc_next(buf);
 return ret;
}

long nrand48(randbuf buf) {
 return jrand48(buf) & 0x7FFFFFFFL;
}

double erand48(randbuf buf) {
 double ret;
 ret = ((buf[0] / 65536.0 + buf[1]) / 65536.0 + buf[2]) / 65536.0;
 calc_next(buf);
 return ret;
}



# 1 "rand_i.h" 1

 int rand_i(void) 
# 2 "rand_i.h" 3 4
                       __attribute__((__nothrow__ , __leaf__))
# 2 "rand_i.h"
                              ;
# 4058 "libc.h" 2

static unsigned int seed;

int rand_i(void) {
  if (seed==0) {
    const int* tmp=(const int*)getauxval(AT_RANDOM);
    if (tmp)
      seed=tmp[3];
    else
      seed=(uintptr_t)&seed;
  }
  return rand_r(&seed);
}
# 4081 "libc.h"
# 1 "include/stdint.h" 1 3 4









# 9 "include/stdint.h" 3 4
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
# 149 "include/stdint.h" 3 4
typedef unsigned int wint_t;





# 4082 "libc.h" 2
# 4091 "libc.h"

# 4091 "libc.h"
int rand_r(unsigned int* seed)
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







# 1 "syscalls.h" 1
# 25 "syscalls.h"
# 1 "mips/syscalls.h" 1
# 26 "syscalls.h" 2
# 4123 "libc.h" 2
# 4138 "libc.h"
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
# 4165 "libc.h" 3 4
                89
# 4165 "libc.h"
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
# 4190 "libc.h"
struct linux_dirent {
  uint32_t d_ino;
  off_t d_off;
  uint16_t d_reclen;
  char d_name[1];
};


int readdir_r(DIR *d,struct dirent* entry, struct dirent** result) {
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
# 4210 "libc.h" 3 4
                    ((size_t) &((
# 4210 "libc.h"
                    struct linux_dirent
# 4210 "libc.h" 3 4
                    *)0)->
# 4210 "libc.h"
                    d_name
# 4210 "libc.h" 3 4
                    )
# 4210 "libc.h"
                                                        +1)
    return 0;
  *result=entry;
  entry->d_ino=ld->d_ino;
  entry->d_off=ld->d_off;
  entry->d_reclen=ld->d_reclen;



  entry->d_type=ld->d_name[ld->d_reclen-
# 4219 "libc.h" 3 4
                                       ((size_t) &((
# 4219 "libc.h"
                                       struct linux_dirent
# 4219 "libc.h" 3 4
                                       *)0)->
# 4219 "libc.h"
                                       d_name
# 4219 "libc.h" 3 4
                                       )
# 4219 "libc.h"
                                                                           -1];

  memcpy(entry->d_name,ld->d_name,ld->d_reclen-
# 4221 "libc.h" 3 4
                                              ((size_t) &((
# 4221 "libc.h"
                                              struct linux_dirent
# 4221 "libc.h" 3 4
                                              *)0)->
# 4221 "libc.h"
                                              d_name
# 4221 "libc.h" 3 4
                                              )
# 4221 "libc.h"
                                                                                  );
  return 0;
}






typedef uint64_t ulll;


void* reallocarray(void* ptr, size_t nmemb, size_t size) {

  typedef char compile_time_assertion[(sizeof(ulll)>=sizeof(size_t)*2)-1];

  ulll l=(ulll)nmemb * size;
  if ((size_t)l != l) return 0;
  return realloc(ptr,(size_t)l);
}
# 1 "include/sys/reboot.h" 1 3 4






# 24 "include/sys/reboot.h" 3 4

# 24 "include/sys/reboot.h" 3 4
int reboot (int flag);
# 33 "include/sys/reboot.h" 3 4

# 4242 "libc.h" 2


# 4243 "libc.h"
int __reboot(unsigned int magic1, unsigned int magic2, int cmd);

int reboot(int cmd)
{
  return __reboot(
# 4247 "libc.h" 3 4
                 0xfee1dead
# 4247 "libc.h"
                                    , 
# 4247 "libc.h" 3 4
                                      672274793
# 4247 "libc.h"
                                                         , cmd);
}
# 1 "syscalls.h" 1
# 25 "syscalls.h"
# 1 "mips/syscalls.h" 1
# 26 "syscalls.h" 2
# 4250 "libc.h" 2



# 1 "./linuxnet.h" 1
# 4254 "libc.h" 2

 int socketcall(int callno,long* args);

int __libc_recv(int a, const void * b, size_t c, int flags);
int __libc_recv(int a, const void * b, size_t c, int flags) {
  long args[] = { a, (long) b, c, flags };
  return socketcall(10, args);
}

int recv(int a, const void * b, size_t c, int flags)
  __attribute__ ((weak, alias("__libc_recv")));


# 1 "syscalls.h" 1
# 25 "syscalls.h"
# 1 "mips/syscalls.h" 1
# 26 "syscalls.h" 2
# 4268 "libc.h" 2



# 1 "./linuxnet.h" 1
# 4272 "libc.h" 2

 int socketcall(int callno,long* args);

int __libc_recvfrom(int a, const void * b, size_t c, int flags, void *to, void *tolen);
int __libc_recvfrom(int a, const void * b, size_t c, int flags, void *to, void *tolen) {
  long args[] = { a, (long) b, c, flags, (long) to, (long) tolen };
  return socketcall(12, args);
}

int recvfrom(int a, const void * b, size_t c, int flags, void *to, void *tolen)
 __attribute__ ((weak,alias("__libc_recvfrom"))) ;







int remove(const char* filename) {
  if (unlink(filename)) {
    if (errno==
# 4292 "libc.h" 3 4
              21
# 4292 "libc.h"
                    )
      return rmdir(filename);
    return -1;
  }
  return 0;
}
# 1 "syscalls.h" 1
# 25 "syscalls.h"
# 1 "mips/syscalls.h" 1
# 26 "syscalls.h" 2
# 4299 "libc.h" 2



# 1 "./linuxnet.h" 1
# 4303 "libc.h" 2

 int socketcall(int callno,long* args);

int __libc_recvmsg(int a, struct msghdr* msg, int flags);
int __libc_recvmsg(int a, struct msghdr* msg, int flags) {
  long args[] = { a, (long) msg, flags };
  return socketcall(17, args);
}

int recvmsg(int a, struct msghdr *msg, int flags)
 __attribute__ ((weak,alias("__libc_recvmsg"))) ;


# 1 "./dietstdio.h" 1
# 4317 "libc.h" 2


void rewind( FILE *stream) {
  fseek(stream, 0L, 
# 4320 "libc.h" 3 4
                   0
# 4320 "libc.h"
                           );
}




void rewinddir(DIR *d) {
  if (lseek(d->fd,0,
# 4327 "libc.h" 3 4
                   0
# 4327 "libc.h"
                           ) != (off_t)-1)
    d->num=d->cur=0;
}


 int __libc_brk(void *end_data_segment);

 void* __curbrk;

void* __libc_sbrk(ptrdiff_t increment);
void* __libc_sbrk(ptrdiff_t increment) {
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

void* sbrk (ptrdiff_t increment) __attribute__((weak,alias("__libc_sbrk")));




char* secure_getenv(const char* name) {
  if (getauxval(AT_SECURE))
    return 
# 4357 "libc.h" 3 4
          (void*)0
# 4357 "libc.h"
              ;
  return getenv(name);
}




void seekdir(DIR *d,off_t offset) {
  if (lseek(d->fd,offset,
# 4365 "libc.h" 3 4
                        0
# 4365 "libc.h"
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

int semctl(int semid, int semnum, int cmd, union semun arg);
int semctl(int semid, int semnum, int cmd, union semun arg) {
  return __ipc(
# 4385 "libc.h" 3 4
              3
# 4385 "libc.h"
                    ,semid,semnum,cmd,&arg);
}


# 1 "include/sys/sem.h" 1 3 4






# 24 "include/sys/sem.h" 3 4

# 24 "include/sys/sem.h" 3 4
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
# 55 "include/sys/sem.h" 3 4
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







 int semget( key_t key, int nsems, int semflg) __attribute__((__nothrow__ , __leaf__));




 int semctl(int semid, int semnum, int cmd, ...) __attribute__((__nothrow__ , __leaf__));

 int semop(int semid, struct sembuf *sops, unsigned nsops) __attribute__((__nothrow__ , __leaf__));


# 4390 "libc.h" 2

 
# 4391 "libc.h"
      int __ipc(int,key_t,int,int,int);

int semget(key_t key, int nsems, int semflg) {
  return __ipc(
# 4394 "libc.h" 3 4
              2
# 4394 "libc.h"
                    ,key,nsems,semflg,0);
}




 int __ipc(int,int,unsigned,int,void*);

int semop(int semid,struct sembuf *sops,unsigned nsops) {
  return __ipc(
# 4403 "libc.h" 3 4
              1
# 4403 "libc.h"
                   ,semid,nsops,0,sops);
}
# 1 "syscalls.h" 1
# 25 "syscalls.h"
# 1 "mips/syscalls.h" 1
# 26 "syscalls.h" 2
# 4406 "libc.h" 2



# 1 "./linuxnet.h" 1
# 4410 "libc.h" 2

 int socketcall(int callno,long* args);

int __libc_sendmsg(int a, const struct msghdr* msg, int flags);
int __libc_sendmsg(int a, const struct msghdr* msg, int flags) {
  long args[] = { a, (long) msg, flags };
  return socketcall(16, args);
}

int sendmsg(int a, const struct msghdr *msg, int flags)
 __attribute__ ((weak,alias("__libc_sendmsg"))) ;


# 1 "syscalls.h" 1
# 25 "syscalls.h"
# 1 "mips/syscalls.h" 1
# 26 "syscalls.h" 2
# 4424 "libc.h" 2



# 1 "./linuxnet.h" 1
# 4428 "libc.h" 2

 int socketcall(int callno,long* args);

int __libc_send(int a, const void * b, size_t c, int flags);
int __libc_send(int a, const void * b, size_t c, int flags) {
  long args[] = { a, (long) b, c, flags };
  return socketcall(9, args);
}

int send(int a, const void * b, size_t c, int flags)
  __attribute__ ((weak, alias("__libc_send")));


# 1 "syscalls.h" 1
# 25 "syscalls.h"
# 1 "mips/syscalls.h" 1
# 26 "syscalls.h" 2
# 4442 "libc.h" 2



# 1 "./linuxnet.h" 1
# 4446 "libc.h" 2

 int socketcall(int callno,long* args);

int __libc_sendto(int a, const void * b, size_t c, int flags, void *to, int tolen);
int __libc_sendto(int a, const void * b, size_t c, int flags, void *to, int tolen) {
  long args[] = { a, (long) b, c, flags, (long) to, tolen };
  return socketcall(11, args);
}

int sendto(int a, const void * b, size_t c, int flags, const struct sockaddr* to, socklen_t tolen)
  __attribute__ ((weak, alias("__libc_sendto")));



# 1 "dietwarning.h" 1
# 4461 "libc.h" 2



void setlinebuf(FILE* stream);

void setlinebuf(FILE* stream) {
  setvbuf(stream,0,
# 4467 "libc.h" 3 4
                  1
# 4467 "libc.h"
                        ,
# 4467 "libc.h" 3 4
                         1024
# 4467 "libc.h"
                               );
}

asm (".section .gnu.warning." "setlinebuf" "\n\t.string \"" "warning: you used setlinebuf without including <stdio.h>" "\"\n\t.previous");


int setpgrp()
{
  return setpgid(0,0);
}
# 1 "syscalls.h" 1
# 25 "syscalls.h"
# 1 "mips/syscalls.h" 1
# 26 "syscalls.h" 2
# 4478 "libc.h" 2


# 1 "./linuxnet.h" 1
# 4481 "libc.h" 2


 int socketcall(int callno,long* args);

int __libc_setsockopt(int a, int b, int c, void *d, void *e);
int __libc_setsockopt(int a, int b, int c, void *d, void *e) {
  long args[] = { a, b, c, (long)d, (long) e };
  return socketcall(14, args);
}

int setsockopt(int s, int level, int optname, const void* optval, socklen_t optlen) __attribute__((weak,alias("__libc_setsockopt")));






 void* __ipc(int,int,int,void*,const void*);

void* shmat(int shmid,const void* shmaddr,int shmflg) {
  void* raddr;
  register void* result;
  result=__ipc(
# 4503 "libc.h" 3 4
              21
# 4503 "libc.h"
                   ,shmid,shmflg,&raddr,shmaddr);
  if ((unsigned long)result <= -(unsigned long)8196)
    result=raddr;
  return result;
}




 int __ipc(int,int,int,int,void*);

int shmctl(int shmid, int cmd, struct shmid_ds *buf) {
  return __ipc(
# 4515 "libc.h" 3 4
              24
# 4515 "libc.h"
                    ,shmid,cmd,0,buf);
}




 int __ipc(int,int,int,int,const void*);

int shmdt(const void* shmaddr) {
  return __ipc(
# 4524 "libc.h" 3 4
              22
# 4524 "libc.h"
                   ,0,0,0,shmaddr);
}




 int __ipc(int,key_t,int,int,int);

int shmget(key_t key, int size, int shmflg) {
  return __ipc(
# 4533 "libc.h" 3 4
              23
# 4533 "libc.h"
                    ,key,size,shmflg,0);
}
# 1 "syscalls.h" 1
# 25 "syscalls.h"
# 1 "mips/syscalls.h" 1
# 26 "syscalls.h" 2
# 4536 "libc.h" 2


# 1 "./linuxnet.h" 1
# 4539 "libc.h" 2


 int socketcall(int callno,long* args);

int __libc_shutdown(int s, int how);
int __libc_shutdown(int s, int how) {
  long args[] = { s, (long) how, 0 };
  return socketcall(13, args);
}

int shutdown(int s, int how) __attribute__((weak,alias("__libc_shutdown")));




int __rt_sigaction(int signum, const struct sigaction *act, struct sigaction *oldact, long nr);

int __libc_sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
int __libc_sigaction(int signum, const struct sigaction *act, struct sigaction *oldact) {
  return __rt_sigaction(signum, act, oldact, 
# 4558 "libc.h" 3 4
                                            128
# 4558 "libc.h"
                                                 /8);
}

int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact)
__attribute__((weak,alias("__libc_sigaction")));






int sigaddset(sigset_t *set, int signo) {
  if ((signo<1)||(signo>
# 4570 "libc.h" 3 4
                       (128 -1)
# 4570 "libc.h"
                               )) {
    (*__errno_location())=
# 4571 "libc.h" 3 4
                         22
# 4571 "libc.h"
                               ;
    return -1;
  } else {
    unsigned long __mask = ( ((unsigned long)1) << (((signo)-1) % (8*sizeof(unsigned long))) );
    unsigned long __word = ( ((signo)-1) / (8*sizeof(unsigned long)) );
    set->sig[__word]|=__mask;
    return 0;
  }
}



int sigandset(sigset_t*set,const sigset_t*left,const sigset_t*right)
{
  set->sig[0]=left->sig[0]&right->sig[0];
  if (
# 4586 "libc.h" 3 4
     (1024 / (8 * sizeof (unsigned long int)))
# 4586 "libc.h"
                  >1) set->sig[1]=left->sig[1]&right->sig[1];
  if (
# 4587 "libc.h" 3 4
     (1024 / (8 * sizeof (unsigned long int)))
# 4587 "libc.h"
                  >2) {
    set->sig[2]=left->sig[2]&right->sig[2];
    set->sig[3]=left->sig[3]&right->sig[3];
  }
  return 0;
}






int sigdelset(sigset_t *set, int signo) {
  if ((signo<1)||(signo>
# 4600 "libc.h" 3 4
                       (128 -1)
# 4600 "libc.h"
                               )) {
    (*__errno_location())=
# 4601 "libc.h" 3 4
                         22
# 4601 "libc.h"
                               ;
    return -1;
  } else {
    unsigned long __mask = ( ((unsigned long)1) << (((signo)-1) % (8*sizeof(unsigned long))) );
    unsigned long __word = ( ((signo)-1) / (8*sizeof(unsigned long)) );
    set->sig[__word]&=~__mask;
    return 0;
  }
}


int sigemptyset(sigset_t *set) {
  set->sig[0]=0;
  if (
# 4614 "libc.h" 3 4
     (1024 / (8 * sizeof (unsigned long int)))
# 4614 "libc.h"
                  >1) set->sig[1]=0;
  if (
# 4615 "libc.h" 3 4
     (1024 / (8 * sizeof (unsigned long int)))
# 4615 "libc.h"
                  >2) {
    set->sig[2]=0;
    set->sig[3]=0;
  }
  return 0;
}



int sigfillset(sigset_t *set) {
  set->sig[0]=(unsigned long)-1;
  if (
# 4626 "libc.h" 3 4
     (1024 / (8 * sizeof (unsigned long int)))
# 4626 "libc.h"
                  >1) set->sig[1]=(unsigned long)-1;
  if (
# 4627 "libc.h" 3 4
     (1024 / (8 * sizeof (unsigned long int)))
# 4627 "libc.h"
                  >2) {
    set->sig[2]=(unsigned long)-1;
    set->sig[3]=(unsigned long)-1;
  }
  return 0;
}


int siginterrupt(int sig, int flag) {
  int ret;
  struct sigaction act;

  sigaction(sig, 0, &act);

  if (flag)
    act.sa_flags &= ~
# 4642 "libc.h" 3 4
                    0x10000000
# 4642 "libc.h"
                              ;
  else
    act.sa_flags |= 
# 4644 "libc.h" 3 4
                   0x10000000
# 4644 "libc.h"
                             ;

  ret = sigaction(sig, &act, 0);

  return ret;
}



int sigisemptyset(const sigset_t*set)
{
  unsigned long ret;
  ret=set->sig[0];
  if (
# 4657 "libc.h" 3 4
     (1024 / (8 * sizeof (unsigned long int)))
# 4657 "libc.h"
                  >1) ret|=set->sig[1];
  if (
# 4658 "libc.h" 3 4
     (1024 / (8 * sizeof (unsigned long int)))
# 4658 "libc.h"
                  >2) {
    ret|=set->sig[2];
    ret|=set->sig[3];
  }
  return ret != 0;
}






int sigismember(const sigset_t *set, int signo) {
  if ((signo<1)||(signo>
# 4671 "libc.h" 3 4
                       (128 -1)
# 4671 "libc.h"
                               )) {
    (*__errno_location())=
# 4672 "libc.h" 3 4
                         22
# 4672 "libc.h"
                               ;
    return -1;
  } else {
    unsigned long __mask = ( ((unsigned long)1) << (((signo)-1) % (8*sizeof(unsigned long))) );
    unsigned long __word = ( ((signo)-1) / (8*sizeof(unsigned long)) );
    return (set->sig[__word] & __mask)?1:0;
  }
}



int __sigjmp_save(sigjmp_buf env,int savemask);
int __sigjmp_save(sigjmp_buf env,int savemask) {
  env[0].__mask_was_saved = 0;
  if (savemask) {
    env[0].__mask_was_saved=(sigprocmask(
# 4687 "libc.h" 3 4
                                        1
# 4687 "libc.h"
                                                 ,(sigset_t*)0,&env[0].__saved_mask)==0);
  }
  return 0;
}


sighandler_t signal(int signum, sighandler_t action) {
  struct sigaction sa,oa;
  sa.
# 4695 "libc.h" 3 4
    _u._sa_handler
# 4695 "libc.h"
              =action;
  sigemptyset(&sa.sa_mask);
  if (sigaddset(&sa.sa_mask,signum) != 0)
    return 
# 4698 "libc.h" 3 4
          ((sighandler_t)-1L)
# 4698 "libc.h"
                 ;
  sa.sa_flags = 
# 4699 "libc.h" 3 4
               0x40000000
# 4699 "libc.h"
                         ;
  if (sigaction(signum,&sa,&oa) != 0)
    return 
# 4701 "libc.h" 3 4
          ((sighandler_t)-1L)
# 4701 "libc.h"
                 ;
  return oa.
# 4702 "libc.h" 3 4
           _u._sa_handler
# 4702 "libc.h"
                     ;
}


# 1 "include/sys/signalfd.h" 1 3 4






# 6 "include/sys/signalfd.h" 3 4
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
  __attribute__((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) ;


# 4707 "libc.h" 2


 
# 4709 "libc.h"
      int __signalfd(int fd,const sigset_t* mask,size_t nsig);
 int __signalfd4(int fd,const sigset_t* mask,size_t nsig, int flags);

int signalfd(int fd,const sigset_t* mask,int flags) {
  int r=__signalfd4(fd,mask,
# 4713 "libc.h" 3 4
                           128
# 4713 "libc.h"
                                /8,flags);
  if (r==-1 && errno==
# 4714 "libc.h" 3 4
                     89
# 4714 "libc.h"
                           ) {
    r=__signalfd(fd,mask,
# 4715 "libc.h" 3 4
                        32
# 4715 "libc.h"
                            /8);
    if (r!=-1 && flags) {
      int x;
      x=fcntl(r,
# 4718 "libc.h" 3 4
               2
# 4718 "libc.h"
                      ,flags);
      if (x==-1)
 close(r);
    }
  }
  return r;
}



int sigorset(sigset_t*set,const sigset_t*left,const sigset_t*right)
{
  set->sig[0]=left->sig[0]|right->sig[0];
  if (
# 4731 "libc.h" 3 4
     (1024 / (8 * sizeof (unsigned long int)))
# 4731 "libc.h"
                  >1) set->sig[1]=left->sig[1]|right->sig[1];
  if (
# 4732 "libc.h" 3 4
     (1024 / (8 * sizeof (unsigned long int)))
# 4732 "libc.h"
                  >2) {
    set->sig[2]=left->sig[2]|right->sig[2];
    set->sig[3]=left->sig[3]|right->sig[3];
  }
  return 0;
}


int __rt_sigpending(sigset_t *set, long nr);

int sigpending(sigset_t *set) {
  return __rt_sigpending(set, 
# 4743 "libc.h" 3 4
                             128
# 4743 "libc.h"
                                  /8);
}


int __rt_sigprocmask(int how, const sigset_t *set, sigset_t *oldsetm, long nr);

int sigprocmask(int how, const sigset_t *set, sigset_t *oldset) {
  return __rt_sigprocmask(how, set, oldset, 
# 4750 "libc.h" 3 4
                                           128
# 4750 "libc.h"
                                                /8);
}


int __rt_sigqueueinfo(pid_t pid, int sig, siginfo_t *info);

int sigqueueinfo(pid_t pid, int sig, siginfo_t *info) {
  return __rt_sigqueueinfo(pid, sig, info);
}


int __rt_sigsuspend(const sigset_t *mask, long nr);

int __libc_sigsuspend(const sigset_t *mask);
int __libc_sigsuspend(const sigset_t *mask) {
  return __rt_sigsuspend(mask, 
# 4765 "libc.h" 3 4
                              128
# 4765 "libc.h"
                                   /8);
}

int sigsuspend(const sigset_t *mask) __attribute__((weak,alias("__libc_sigsuspend")));


int __rt_sigtimedwait(const sigset_t *set, siginfo_t *info, const struct timespec *ts, long nr);

int sigtimedwait(const sigset_t *set, siginfo_t *info, const struct timespec *ts) {
  return __rt_sigtimedwait(set,info,ts,
# 4774 "libc.h" 3 4
                                      128
# 4774 "libc.h"
                                           /8);
}


int sigwait(const sigset_t* set,int* sig) {
  siginfo_t si;
  int r=
# 4780 "libc.h" 3 4
       sigtimedwait((
# 4780 "libc.h"
       set
# 4780 "libc.h" 3 4
       ),(
# 4780 "libc.h"
       &si
# 4780 "libc.h" 3 4
       ),0)
# 4780 "libc.h"
                           ;
  if (r!=-1) *sig=si.si_signo;
  return r;
}
# 1 "include/search.h" 1 3 4








# 8 "include/search.h" 3 4
typedef enum { FIND, ENTER } ACTION;
typedef struct entry { char* key; void* data; } ENTRY;

 ENTRY* hsearch(ENTRY item, ACTION action) __attribute__((__nothrow__ , __leaf__));
 int hcreate(size_t count) __attribute__((__nothrow__ , __leaf__));
 void hdestroy(void) __attribute__((__nothrow__ , __leaf__));





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

 int hsearch_r(ENTRY item, ACTION action, ENTRY** retval, struct hsearch_data* htab) __attribute__((__nothrow__ , __leaf__));
 int hcreate_r(size_t count, struct hsearch_data* htab) __attribute__((__nothrow__ , __leaf__));
 void hdestroy_r(struct hsearch_data* htab) __attribute__((__nothrow__ , __leaf__));

 uint64_t siphash24(const unsigned char key[16], const unsigned char *in, size_t len) __attribute__((__nothrow__ , __leaf__));
# 4785 "libc.h" 2






# 4790 "libc.h"
static uint64_t
U8TO64_LE(const unsigned char *p) {
 return *(const uint64_t *)p;
}

uint64_t
siphash24(const unsigned char key[16], const unsigned char *m, size_t len) {
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
# 4821 "libc.h"
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



unsigned int sleep(unsigned int secs) {
  struct timespec t;
  t.tv_sec=secs;
  t.tv_nsec=0;
  nanosleep(&t,&t);
  return secs-t.tv_sec;
}

# 1 "syscalls.h" 1
# 25 "syscalls.h"
# 1 "mips/syscalls.h" 1
# 26 "syscalls.h" 2
# 4863 "libc.h" 2


# 1 "./linuxnet.h" 1
# 4866 "libc.h" 2

 int socketcall(int callno,long* args);

int __libc_socket(int a, int b, int c);
int __libc_socket(int a, int b, int c) {
  long args[] = { a, b, c };
  return socketcall(1, args);
}

int socket(int a,int b,int c) __attribute__((weak,alias("__libc_socket")));






int snprintf(char *str,size_t size,const char *format,...)
{
  int n;
  va_list arg_ptr;
  
# 4886 "libc.h" 3 4
 __builtin_va_start((
# 4886 "libc.h"
 arg_ptr
# 4886 "libc.h" 3 4
 ),(
# 4886 "libc.h"
 format
# 4886 "libc.h" 3 4
 ))
# 4886 "libc.h"
                          ;
  n=vsnprintf(str,size,format,arg_ptr);
  
# 4888 "libc.h" 3 4
 __builtin_va_end 
# 4888 "libc.h"
        (arg_ptr);
  return n;
}
# 1 "syscalls.h" 1
# 25 "syscalls.h"
# 1 "mips/syscalls.h" 1
# 26 "syscalls.h" 2
# 4892 "libc.h" 2


# 1 "./linuxnet.h" 1
# 4895 "libc.h" 2

 int socketcall(int callno,long* args);

int __libc_socketpair(int a, int type, int protocol, int sv[2]);
int __libc_socketpair(int a, int type, int protocol, int sv[2]) {
  long args[] = { a, type, protocol, (long)sv };
  return socketcall(8, args);
}

int socketpair(int d, int type, int protocol, int sv[2])
  __attribute__((weak,alias("__libc_socketpair")));







int sprintf(char *dest,const char *format,...)
{
  int n;
  va_list arg_ptr;
  
# 4917 "libc.h" 3 4
 __builtin_va_start((
# 4917 "libc.h"
 arg_ptr
# 4917 "libc.h" 3 4
 ),(
# 4917 "libc.h"
 format
# 4917 "libc.h" 3 4
 ))
# 4917 "libc.h"
                          ;
  n=vsprintf(dest,format,arg_ptr);
  
# 4919 "libc.h" 3 4
 __builtin_va_end 
# 4919 "libc.h"
        (arg_ptr);
  return n;
}



int sscanf(const char *str, const char *format, ...)
{
  int n;
  va_list arg_ptr;
  
# 4929 "libc.h" 3 4
 __builtin_va_start((
# 4929 "libc.h"
 arg_ptr
# 4929 "libc.h" 3 4
 ),(
# 4929 "libc.h"
 format
# 4929 "libc.h" 3 4
 ))
# 4929 "libc.h"
                          ;
  n=vsscanf(str,format,arg_ptr);
  
# 4931 "libc.h" 3 4
 __builtin_va_end 
# 4931 "libc.h"
        (arg_ptr);
  return n;
}
# 1 "include/write12.h" 1 3 4






# 6 "include/write12.h" 3 4
ssize_t __write1 ( const char* s ) __attribute__ (( ));
ssize_t __write2 ( const char* s ) __attribute__ (( ));


# 4935 "libc.h" 2





# 4939 "libc.h"
void __stack_smash_handler(char* func,unsigned int damaged);
void __stack_smash_handler(char* func,unsigned int damaged) {
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



# 1 "include/write12.h" 1 3 4






# 6 "include/write12.h" 3 4
ssize_t __write1 ( const char* s ) __attribute__ (( ));
ssize_t __write2 ( const char* s ) __attribute__ (( ));


# 4961 "libc.h" 2


# 4962 "libc.h"
void __stack_chk_fail(void);




void __stack_chk_fail(void) {
  __write2("smashed stack detected, program terminated.\n");
  _exit(127);
}


 void __stack_chk_fail(void) __attribute__((noreturn));



void __attribute__((noreturn)) __stack_chk_fail_local(void);




void __attribute__((noreturn)) __stack_chk_fail_local(void)
{
  __stack_chk_fail ();
}


# 1 "./lib/stackgap-common.h" 1





 char __executable_start;
# 23 "./lib/stackgap-common.h"
# 1 "include/elf.h" 1 3 4
# 9 "include/elf.h" 3 4




# 12 "include/elf.h" 3 4
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
# 247 "include/elf.h" 3 4
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
# 346 "include/elf.h" 3 4
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
# 459 "include/elf.h" 3 4
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
# 504 "include/elf.h" 3 4
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
# 606 "include/elf.h" 3 4
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
# 773 "include/elf.h" 3 4
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
# 815 "include/elf.h" 3 4
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
# 862 "include/elf.h" 3 4
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
# 896 "include/elf.h" 3 4
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
# 975 "include/elf.h" 3 4
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
# 1023 "include/elf.h" 3 4
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
# 1368 "include/elf.h" 3 4
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
# 1444 "include/elf.h" 3 4
typedef struct
{
  Elf32_Word hwp_flags1;
  Elf32_Word hwp_flags2;
} Elf_Options_Hw;
# 1583 "include/elf.h" 3 4
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
# 1614 "include/elf.h" 3 4
typedef Elf32_Addr Elf32_Conflict;
# 2463 "include/elf.h" 3 4
typedef uint32_t Elf_Symndx;





# 24 "./lib/stackgap-common.h" 2
# 35 "./lib/stackgap-common.h"

# 35 "./lib/stackgap-common.h"
char* program_invocation_name;
char* program_invocation_short_name;


void* __vdso;

 int main(int argc,char* argv[],char* envp[]);


 
# 44 "./lib/stackgap-common.h" 3 4
      __attribute__((visibility("hidden"))) 
# 44 "./lib/stackgap-common.h"
                 unsigned long __guard;






 int __valgrind;
# 65 "./lib/stackgap-common.h"
size_t __tdatasize, __tmemsize;
void* __tdataptr;

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
# 87 "./lib/stackgap-common.h" 3 4
                    PT_TLS
# 87 "./lib/stackgap-common.h"
                          ) {
      __tdataptr=(void*)x[i].p_vaddr;
      __tdatasize=x[i].p_filesz;
      __tmemsize=x[i].p_memsz;
      if (__tmemsize&15)
 __tmemsize=(__tmemsize+15)&~15;
      break;
    }


}



tcbhead_t* __tcb_mainthread;

 void __setup_tls(tcbhead_t*);
# 327 "./lib/stackgap-common.h"
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


__attribute__((optimize("no-stack-protector")))
int stackgap(int argc,char* argv[],char* envp[], funcptr fp);
int stackgap(int argc,char* argv[],char* envp[], funcptr fp) {



  long* auxvec=(long*)envp;

  char* rand=(char*)&auxvec;
  char* tlsdata;

  while (*auxvec) ++auxvec;
  ++auxvec;

  _auxvec=auxvec;
# 514 "./lib/stackgap-common.h"
  volatile char* gap;
  rand=(char*)getauxval(25);
# 536 "./lib/stackgap-common.h"
  memcpy(&__guard,rand,sizeof(__guard));







  __vdso=(void*)getauxval(33);





  findtlsdata(auxvec);
  if (
# 551 "./lib/stackgap-common.h" 3 4
     __builtin_expect((long)((
# 551 "./lib/stackgap-common.h"
     __tmemsize+sizeof(tcbhead_t)<sizeof(tcbhead_t)
# 551 "./lib/stackgap-common.h" 3 4
     )),0) 
# 551 "./lib/stackgap-common.h"
                                                                ||
      
# 552 "./lib/stackgap-common.h" 3 4
     __builtin_expect((long)((
# 552 "./lib/stackgap-common.h"
     __tmemsize>512*1024*1024
# 552 "./lib/stackgap-common.h" 3 4
     )),0) 
# 552 "./lib/stackgap-common.h"
                                          ||
      
# 553 "./lib/stackgap-common.h" 3 4
     __builtin_expect((long)((
# 553 "./lib/stackgap-common.h"
     __tmemsize<__tdatasize
# 553 "./lib/stackgap-common.h" 3 4
     )),0)
# 553 "./lib/stackgap-common.h"
                                       )
    return 111;
  tlsdata=
# 555 "./lib/stackgap-common.h" 3 4
         __builtin_alloca(
# 555 "./lib/stackgap-common.h"
         __tmemsize+sizeof(tcbhead_t)
# 555 "./lib/stackgap-common.h" 3 4
         )
# 555 "./lib/stackgap-common.h"
                                             ;
  memcpy(tlsdata,__tdataptr,__tdatasize);
  memset(tlsdata+__tdatasize,0,__tmemsize-__tdatasize);
  __setup_tls(__tcb_mainthread=(tcbhead_t*)(tlsdata+__tmemsize));
  __tcb_mainthread->sysinfo=(uintptr_t)getauxval(32);
# 585 "./lib/stackgap-common.h"
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
# 4989 "libc.h" 2





void __statfs64_cvt(const struct statfs *src,struct statfs64 *dest);
void __statfs64_cvt(const struct statfs *src,struct statfs64 *dest) {
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

int statvfs(const char *path, struct statvfs *sv) {
  struct statfs ss;
  if (statfs(path,&ss)==-1) return -1;
  __statvfs_cvt(&ss,sv);
  return 0;
}





void __statvfs_cvt(struct statfs* from,struct statvfs* to);

void __statvfs_cvt(struct statfs* from,struct statvfs* to) {
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


char * stpcpy (char *dst, const char *src) {
  while ((*dst++ = *src++));
  return (dst-1);
}




char* stpncpy(char* dest, const char* src, size_t n) {
  char* x=memccpy(dest,src,0,n);
  if (x) {



    return x-1;
  } else
    return dest+n;
}


int strcasecmp ( const char* s1, const char* s2 )
{
    register unsigned int x2;
    register unsigned int x1;

    while (1) {
        x2 = *s2 - 'A'; if (
# 5069 "libc.h" 3 4
                           __builtin_expect((long)((
# 5069 "libc.h"
                           x2 < 26u
# 5069 "libc.h" 3 4
                           )),0)
# 5069 "libc.h"
                                               ) x2 += 32;
        x1 = *s1 - 'A'; if (
# 5070 "libc.h" 3 4
                           __builtin_expect((long)((
# 5070 "libc.h"
                           x1 < 26u
# 5070 "libc.h" 3 4
                           )),0)
# 5070 "libc.h"
                                               ) x1 += 32;
 s1++; s2++;
        if ( 
# 5072 "libc.h" 3 4
            __builtin_expect((long)((
# 5072 "libc.h"
            x2 != x1
# 5072 "libc.h" 3 4
            )),0) 
# 5072 "libc.h"
                                 )
            break;
        if ( 
# 5074 "libc.h" 3 4
            __builtin_expect((long)((
# 5074 "libc.h"
            x1 == (unsigned int)-'A'
# 5074 "libc.h" 3 4
            )),0) 
# 5074 "libc.h"
                                                 )
            break;
    }

    return x1 - x2;
}



char* strcat(register char* s,register const char* t)
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




char *strchr(register const char *t, int c) {
  register char ch;

  ch = c;
  for (;;) {
    if (
# 5110 "libc.h" 3 4
       __builtin_expect((long)((
# 5110 "libc.h"
       *t == ch
# 5110 "libc.h" 3 4
       )),0)
# 5110 "libc.h"
                           ) break;
         if (
# 5111 "libc.h" 3 4
            __builtin_expect((long)((
# 5111 "libc.h"
            !*t
# 5111 "libc.h" 3 4
            )),0)
# 5111 "libc.h"
                           ) return 0;
            ++t;

    if (
# 5114 "libc.h" 3 4
       __builtin_expect((long)((
# 5114 "libc.h"
       *t == ch
# 5114 "libc.h" 3 4
       )),0)
# 5114 "libc.h"
                           ) break;
         if (
# 5115 "libc.h" 3 4
            __builtin_expect((long)((
# 5115 "libc.h"
            !*t
# 5115 "libc.h" 3 4
            )),0)
# 5115 "libc.h"
                           ) return 0;
            ++t;
    if (
# 5117 "libc.h" 3 4
       __builtin_expect((long)((
# 5117 "libc.h"
       *t == ch
# 5117 "libc.h" 3 4
       )),0)
# 5117 "libc.h"
                           ) break;
         if (
# 5118 "libc.h" 3 4
            __builtin_expect((long)((
# 5118 "libc.h"
            !*t
# 5118 "libc.h" 3 4
            )),0)
# 5118 "libc.h"
                           ) return 0;
            ++t;
    if (
# 5120 "libc.h" 3 4
       __builtin_expect((long)((
# 5120 "libc.h"
       *t == ch
# 5120 "libc.h" 3 4
       )),0)
# 5120 "libc.h"
                           ) break;
         if (
# 5121 "libc.h" 3 4
            __builtin_expect((long)((
# 5121 "libc.h"
            !*t
# 5121 "libc.h" 3 4
            )),0)
# 5121 "libc.h"
                           ) return 0;
            ++t;

  }
  return (char*)t;
}

char *
# 5128 "libc.h" 3 4
     strchr(
# 5128 "libc.h"
     char *t
# 5128 "libc.h" 3 4
     ,
# 5128 "libc.h"
     int c
# 5128 "libc.h" 3 4
     ) 
# 5128 "libc.h"
                          __attribute__((weak,alias("strchr")));






 int __valgrind;


int
strcmp (const char *s1, const char *s2)
{





    const unsigned long *lx1, *lx2;
    unsigned long l1, l2;
    int tmp;

    if ((((unsigned long)s1 & (sizeof (unsigned long)-1)) ^ ((unsigned long)s2 & (sizeof (unsigned long)-1)))

        || 
# 5152 "libc.h" 3 4
          __builtin_expect((long)((
# 5152 "libc.h"
          __valgrind
# 5152 "libc.h" 3 4
          )),0)

    
# 5154 "libc.h"
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

int strcoll(const char *s,const char* t) __attribute__((weak,alias("strcmp")));






 int __valgrind;


char *
strcpy (char *s1, const char *s2)
{
    char *res = s1;




    int tmp;
    unsigned long l;

    if ((((unsigned long)s1 & (sizeof (unsigned long)-1)) ^ ((unsigned long)s2 & (sizeof (unsigned long)-1)))

        || 
# 5209 "libc.h" 3 4
          __builtin_expect((long)((
# 5209 "libc.h"
          __valgrind
# 5209 "libc.h" 3 4
          )),0)

    
# 5211 "libc.h"
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



size_t strcspn(const char *s, const char *reject)
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



char *strdup(const char *s) {
  size_t l=strlen(s)+1;
  char *tmp=(char *)malloc(l);
  if (!tmp) return 0;
  return memcpy(tmp,s,l);
}
# 5265 "libc.h"
 const char __sys_err_unknown[];

char*
# 5267 "libc.h" 3 4
    strerror
# 5267 "libc.h"
            (int errnum) {
  register const char*message=__sys_err_unknown;

  if ( (unsigned int)errnum < (unsigned int)
# 5270 "libc.h" 3 4
                                           ((168) + 1) 
# 5270 "libc.h"
                                                      )
    message=sys_errlist[errnum];

  if ( errnum == 1133 )
    message="Quota exceeded";

  return (char*)message;
}
# 5321 "libc.h"
size_t strlcat(dst, src, siz)
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
# 5391 "libc.h"
size_t strlcpy(dst, src, siz)
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
# 5435 "libc.h"
typedef uint32_t word_t;




static word_t const magic = (word_t)(0x0101010101010101ull);


 int __valgrind;


size_t strlen(const char *s)
{
  const char *t = s;
  word_t word;
  word_t mask;

  word_t orig_word;


  if (
# 5455 "libc.h" 3 4
     __builtin_expect((long)((
# 5455 "libc.h"
     !s
# 5455 "libc.h" 3 4
     )),0)
# 5455 "libc.h"
                   ) return 0;


  if (
# 5458 "libc.h" 3 4
     __builtin_expect((long)((
# 5458 "libc.h"
     __valgrind
# 5458 "libc.h" 3 4
     )),0)
# 5458 "libc.h"
                           ) {
    register size_t i;
    for (i=0; 
# 5460 "libc.h" 3 4
             __builtin_expect((long)((
# 5460 "libc.h"
             *s
# 5460 "libc.h" 3 4
             )),1)
# 5460 "libc.h"
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
# 5477 "libc.h" 3 4
          __builtin_expect((long)((
# 5477 "libc.h"
          word == 0
# 5477 "libc.h" 3 4
          )),1)
# 5477 "libc.h"
                             );
# 5508 "libc.h"
  if (
# 5508 "libc.h" 3 4
     __builtin_expect((long)((
# 5508 "libc.h"
     orig_word < magic
# 5508 "libc.h" 3 4
     )),0)
# 5508 "libc.h"
                                  ) {
    for (t -= sizeof(word); 
# 5509 "libc.h" 3 4
                           __builtin_expect((long)((
# 5509 "libc.h"
                           *t
# 5509 "libc.h" 3 4
                           )),0)
# 5509 "libc.h"
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




int strncasecmp ( const char* s1, const char* s2, size_t len )
{
    register unsigned int x2;
    register unsigned int x1;
    register const char* end = s1 + len;

    while (1) {
        if ( 
# 5556 "libc.h" 3 4
            __builtin_expect((long)((
# 5556 "libc.h"
            s1 >= end
# 5556 "libc.h" 3 4
            )),0) 
# 5556 "libc.h"
                                  )
            return 0;
        x2 = *s2 - 'A'; if (
# 5558 "libc.h" 3 4
                           __builtin_expect((long)((
# 5558 "libc.h"
                           x2 < 26u
# 5558 "libc.h" 3 4
                           )),0)
# 5558 "libc.h"
                                               ) x2 += 32;
        x1 = *s1 - 'A'; if (
# 5559 "libc.h" 3 4
                           __builtin_expect((long)((
# 5559 "libc.h"
                           x1 < 26u
# 5559 "libc.h" 3 4
                           )),0)
# 5559 "libc.h"
                                               ) x1 += 32;
 s1++; s2++;
        if ( 
# 5561 "libc.h" 3 4
            __builtin_expect((long)((
# 5561 "libc.h"
            x2 != x1
# 5561 "libc.h" 3 4
            )),0) 
# 5561 "libc.h"
                                 )
            break;
        if ( 
# 5563 "libc.h" 3 4
            __builtin_expect((long)((
# 5563 "libc.h"
            x1 == (unsigned int)-'A'
# 5563 "libc.h" 3 4
            )),0) 
# 5563 "libc.h"
                                                 )
            break;
    }

    return x1 - x2;
}





char *strncat(char *s, const char *t, size_t n) {
  char *dest=s;
  register char *max;
  s+=strlen(s);
  if (
# 5578 "libc.h" 3 4
     __builtin_expect((long)((
# 5578 "libc.h"
     (max=s+n)==s
# 5578 "libc.h" 3 4
     )),0)
# 5578 "libc.h"
                             ) goto fini;
  for (;;) {
    if (
# 5580 "libc.h" 3 4
       __builtin_expect((long)((
# 5580 "libc.h"
       !(*s = *t)
# 5580 "libc.h" 3 4
       )),0)
# 5580 "libc.h"
                             ) break;
                                       if (
# 5581 "libc.h" 3 4
                                          __builtin_expect((long)((
# 5581 "libc.h"
                                          ++s==max
# 5581 "libc.h" 3 4
                                          )),0)
# 5581 "libc.h"
                                                              ) break;
                                                                        ++t;

    if (
# 5584 "libc.h" 3 4
       __builtin_expect((long)((
# 5584 "libc.h"
       !(*s = *t)
# 5584 "libc.h" 3 4
       )),0)
# 5584 "libc.h"
                             ) break;
                                       if (
# 5585 "libc.h" 3 4
                                          __builtin_expect((long)((
# 5585 "libc.h"
                                          ++s==max
# 5585 "libc.h" 3 4
                                          )),0)
# 5585 "libc.h"
                                                              ) break;
                                                                        ++t;
    if (
# 5587 "libc.h" 3 4
       __builtin_expect((long)((
# 5587 "libc.h"
       !(*s = *t)
# 5587 "libc.h" 3 4
       )),0)
# 5587 "libc.h"
                             ) break;
                                       if (
# 5588 "libc.h" 3 4
                                          __builtin_expect((long)((
# 5588 "libc.h"
                                          ++s==max
# 5588 "libc.h" 3 4
                                          )),0)
# 5588 "libc.h"
                                                              ) break;
                                                                        ++t;
    if (
# 5590 "libc.h" 3 4
       __builtin_expect((long)((
# 5590 "libc.h"
       !(*s = *t)
# 5590 "libc.h" 3 4
       )),0)
# 5590 "libc.h"
                             ) break;
                                       if (
# 5591 "libc.h" 3 4
                                          __builtin_expect((long)((
# 5591 "libc.h"
                                          ++s==max
# 5591 "libc.h" 3 4
                                          )),0)
# 5591 "libc.h"
                                                              ) break;
                                                                        ++t;

  }
  *s=0;
fini:
  return dest;
}





int strncmp(const char *s1, const char *s2, size_t n) {
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
# 5624 "libc.h"
char *strncpy(char *dest, const char *src, size_t n) {



  memccpy(dest,src,0,n);



  return dest;
}


size_t strnlen(const char *s,size_t maxlen) {
  const char* x=memchr(s,0,maxlen);
  if (!x) x=s+maxlen;
  return x-s;
}




char *strpbrk(const char *s, const char *accept) {
  register unsigned int i;
  for (; *s; s++)
    for (i=0; accept[i]; i++)
      if (*s == accept[i])
 return (char*)s;
  return 0;
}



char *strrchr(const char *t, int c) {
  register char ch;
  register const char *l=0;

  ch = c;
  for (;;) {
    if (
# 5662 "libc.h" 3 4
       __builtin_expect((long)((
# 5662 "libc.h"
       *t == ch
# 5662 "libc.h" 3 4
       )),0)
# 5662 "libc.h"
                           ) l=t;
                                   if (
# 5663 "libc.h" 3 4
                                      __builtin_expect((long)((
# 5663 "libc.h"
                                      !*t
# 5663 "libc.h" 3 4
                                      )),0)
# 5663 "libc.h"
                                                     ) return (char*)l;
                                                                         ++t;

    if (
# 5666 "libc.h" 3 4
       __builtin_expect((long)((
# 5666 "libc.h"
       *t == ch
# 5666 "libc.h" 3 4
       )),0)
# 5666 "libc.h"
                           ) l=t;
                                   if (
# 5667 "libc.h" 3 4
                                      __builtin_expect((long)((
# 5667 "libc.h"
                                      !*t
# 5667 "libc.h" 3 4
                                      )),0)
# 5667 "libc.h"
                                                     ) return (char*)l;
                                                                         ++t;
    if (
# 5669 "libc.h" 3 4
       __builtin_expect((long)((
# 5669 "libc.h"
       *t == ch
# 5669 "libc.h" 3 4
       )),0)
# 5669 "libc.h"
                           ) l=t;
                                   if (
# 5670 "libc.h" 3 4
                                      __builtin_expect((long)((
# 5670 "libc.h"
                                      !*t
# 5670 "libc.h" 3 4
                                      )),0)
# 5670 "libc.h"
                                                     ) return (char*)l;
                                                                         ++t;
    if (
# 5672 "libc.h" 3 4
       __builtin_expect((long)((
# 5672 "libc.h"
       *t == ch
# 5672 "libc.h" 3 4
       )),0)
# 5672 "libc.h"
                           ) l=t;
                                   if (
# 5673 "libc.h" 3 4
                                      __builtin_expect((long)((
# 5673 "libc.h"
                                      !*t
# 5673 "libc.h" 3 4
                                      )),0)
# 5673 "libc.h"
                                                     ) return (char*)l;
                                                                         ++t;

  }
  return (char*)l;
}

char *
# 5680 "libc.h" 3 4
     strrchr(
# 5680 "libc.h"
     const char *t
# 5680 "libc.h" 3 4
     ,
# 5680 "libc.h"
     int c
# 5680 "libc.h" 3 4
     ) 
# 5680 "libc.h"
                                 __attribute__((weak,alias("strrchr")));


char *strsep(char **stringp, const char *delim) {
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



size_t strspn(const char *s, const char *accept)
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



char *strstr(const char *haystack, const char *needle) {
  size_t nl=strlen(needle);
  size_t hl=strlen(haystack);
  size_t i;
  if (!nl) goto found;
  if (nl>hl) return 0;
  for (i=hl-nl+1; 
# 5727 "libc.h" 3 4
                 __builtin_expect((long)((
# 5727 "libc.h"
                 i
# 5727 "libc.h" 3 4
                 )),1)
# 5727 "libc.h"
                            ; --i) {
    if (*haystack==*needle && !memcmp(haystack,needle,nl))
found:
      return (char*)haystack;
    ++haystack;
  }
  return 0;
}




float strtof(const char* s, char** endptr) {
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
# 5796 "libc.h" 3 4
                  (void*)0 
# 5796 "libc.h"
                       )
        *endptr = (char*)p;

    return value * sign;
}
# 5811 "libc.h"
double strtod(const char* s, char** endptr) {
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
# 5868 "libc.h" 3 4
                  (void*)0 
# 5868 "libc.h"
                       )
        *endptr = (char*)p;

    return value * sign;
}


static char *strtok_pos;

char *strtok(char *s, const char *delim)
{
  return strtok_r(s,delim,&strtok_pos);
}


char*strtok_r(char*s,const char*delim,char**ptrptr) {
  char*tmp=0;

  if (s==0) s=*ptrptr;
  s+=strspn(s,delim);
  if (
# 5888 "libc.h" 3 4
     __builtin_expect((long)((
# 5888 "libc.h"
     *s
# 5888 "libc.h" 3 4
     )),1)
# 5888 "libc.h"
                 ) {
    tmp=s;
    s+=strcspn(s,delim);
    if (
# 5891 "libc.h" 3 4
       __builtin_expect((long)((
# 5891 "libc.h"
       *s
# 5891 "libc.h" 3 4
       )),1)
# 5891 "libc.h"
                   ) *s++=0;
  }
  *ptrptr=s;
  return tmp;
}
# 5907 "libc.h"
long int strtol(const char *nptr, char **endptr, int base)
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
# 5923 "libc.h" 3 4
         34
# 5923 "libc.h"
               ;
    return (neg?
# 5924 "libc.h" 3 4
               (-1l - (0x7fffffffL))
# 5924 "libc.h"
                       :
# 5924 "libc.h" 3 4
                        (0x7fffffffL)
# 5924 "libc.h"
                                );
  }
  return (neg?-v:v);
}




long double strtold(const char* s, char** endptr) {
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
# 5989 "libc.h" 3 4
                  (void*)0 
# 5989 "libc.h"
                       )
        *endptr = (char*)p;

    return value * sign;
}






long long int strtoll(const char *nptr, char **endptr, int base)
{
  int neg=0;
  unsigned long long int v;
  const char*orig=nptr;

  while(isspace(*nptr)) nptr++;

  if (*nptr == '-' && isalnum(nptr[1])) { neg=-1; nptr++; }
  v=strtoull(nptr,endptr,base);
  if (endptr && *endptr==nptr) *endptr=(char *)orig;
  if (v>
# 6011 "libc.h" 3 4
       0x7fffffffffffffffll
# 6011 "libc.h"
                ) {
    if (v==0x8000000000000000ull && neg) {
      errno=0;
      return v;
    }
    errno=
# 6016 "libc.h" 3 4
         34
# 6016 "libc.h"
               ;
    return (neg?
# 6017 "libc.h" 3 4
               (-1ll - 0x7fffffffffffffffll)
# 6017 "libc.h"
                        :
# 6017 "libc.h" 3 4
                         0x7fffffffffffffffll
# 6017 "libc.h"
                                  );
  }
  return (neg?-v:v);
}

intmax_t strtoimax(const char *nptr, char **endptr, int base)
 __attribute__((alias("strtoll")));





unsigned long int strtoul(const char *ptr, char **endptr, int base)
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
# 6044 "libc.h" 3 4
       __builtin_expect((long)((
# 6044 "libc.h"
       b>34
# 6044 "libc.h" 3 4
       )),0)
# 6044 "libc.h"
                       ) { errno=
# 6044 "libc.h" 3 4
                                 22
# 6044 "libc.h"
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
# 6056 "libc.h" 3 4
       __builtin_expect((long)((
# 6056 "libc.h"
       *nptr
# 6056 "libc.h" 3 4
       )),1)
# 6056 "libc.h"
                      ) {
    register unsigned char c=*nptr;
    c=(c>='a'?c-'a'+10:c>='A'?c-'A'+10:c<='9'?c-'0':0xff);
    if (
# 6059 "libc.h" 3 4
       __builtin_expect((long)((
# 6059 "libc.h"
       c>=base
# 6059 "libc.h" 3 4
       )),0)
# 6059 "libc.h"
                          ) break;
    {
      register unsigned long x=(v&0xff)*base+c;
      register unsigned long w=(v>>8)*base+(x>>8);
      if (w>(
# 6063 "libc.h" 3 4
            ((0x7fffffffL) * 2ul + 1)
# 6063 "libc.h"
                     >>8)) overflow=1;
      v=(w<<8)+(x&0xff);
    }
    ++nptr;
  }
  if (
# 6068 "libc.h" 3 4
     __builtin_expect((long)((
# 6068 "libc.h"
     nptr==orig
# 6068 "libc.h" 3 4
     )),0)
# 6068 "libc.h"
                           ) {
    nptr=ptr;
    errno=
# 6070 "libc.h" 3 4
         22
# 6070 "libc.h"
               ;
    v=0;
  }
  if (endptr) *endptr=(char *)nptr;
  if (overflow) {
    errno=
# 6075 "libc.h" 3 4
         34
# 6075 "libc.h"
               ;
    return 
# 6076 "libc.h" 3 4
          ((0x7fffffffL) * 2ul + 1)
# 6076 "libc.h"
                   ;
  }
  return (neg?-v:v);
}






unsigned long long int strtoull(const char *ptr, char **endptr, int base)
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
# 6101 "libc.h" 3 4
       __builtin_expect((long)((
# 6101 "libc.h"
       b>34
# 6101 "libc.h" 3 4
       )),0)
# 6101 "libc.h"
                       ) { errno=
# 6101 "libc.h" 3 4
                                 22
# 6101 "libc.h"
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
# 6113 "libc.h" 3 4
       __builtin_expect((long)((
# 6113 "libc.h"
       *nptr
# 6113 "libc.h" 3 4
       )),1)
# 6113 "libc.h"
                      ) {
    register unsigned char c=*nptr;
    c=(c>='a'?c-'a'+10:c>='A'?c-'A'+10:c<='9'?c-'0':0xff);
    if (
# 6116 "libc.h" 3 4
       __builtin_expect((long)((
# 6116 "libc.h"
       c>=base
# 6116 "libc.h" 3 4
       )),0)
# 6116 "libc.h"
                          ) break;
    {
      register unsigned long x=(v&0xff)*base+c;
      register unsigned long long w=(v>>8)*base+(x>>8);
      if (w>(
# 6120 "libc.h" 3 4
            (~0ull)
# 6120 "libc.h"
                      >>8)) overflow=1;
      v=(w<<8)+(x&0xff);
    }
    ++nptr;
  }
  if (
# 6125 "libc.h" 3 4
     __builtin_expect((long)((
# 6125 "libc.h"
     nptr==orig
# 6125 "libc.h" 3 4
     )),0)
# 6125 "libc.h"
                           ) {
    nptr=ptr;
    errno=
# 6127 "libc.h" 3 4
         22
# 6127 "libc.h"
               ;
    v=0;
  }
  if (endptr) *endptr=(char *)nptr;
  if (overflow) {
    errno=
# 6132 "libc.h" 3 4
         34
# 6132 "libc.h"
               ;
    return 
# 6133 "libc.h" 3 4
          (~0ull)
# 6133 "libc.h"
                    ;
  }
  return (neg?-v:v);
}


unsigned long long int strtouq(const char *nptr, char **endptr, int base)
 __attribute__((leaf, nothrow, alias("strtoull")));

uintmax_t strtoumax(const char *nptr, char **endptr, int base)
 __attribute__((leaf, nothrow, alias("strtoull")));




int strverscmp(const char* s1, const char* s2)
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




size_t strxfrm(char *dest, const char *src, size_t n) {



  memccpy(dest,src,0,n);
  return strlen(dest);
}



void swab(const void *src, void *dest, ssize_t nbytes)
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
# 1 "include/ucontext.h" 1 3 4







 
# 8 "include/ucontext.h" 3 4
      int getcontext (ucontext_t *c) __attribute__((__nothrow__ , __leaf__));
 int setcontext (const ucontext_t *c) __attribute__((__nothrow__ , __leaf__));
 int swapcontext (ucontext_t *__restrict o,
   const ucontext_t *__restrict n) __attribute__((__nothrow__));
 void makecontext (ucontext_t *c, void (*__func) (void),
    int argc, ...) __attribute__((__nothrow__ , __leaf__));


# 6202 "libc.h" 2



# 6204 "libc.h"
int swapcontext(ucontext_t* o,const ucontext_t* n) {
  volatile int once=0;
  if (getcontext(o)==-1) return -1;
  if (!once) {
    ++once;
    return setcontext(n);
  }
  return 0;
}
const char *const __sys_siglist[] = {
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
# 6265 "libc.h"
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
# 6317 "libc.h"
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

const char *const* sys_siglist=__sys_siglist;


int __libc_tcdrain(int fd);
int __libc_tcdrain(int fd)
{
  return ioctl(fd, 
# 6393 "libc.h" 3 4
                  0x5405
# 6393 "libc.h"
                        , 1);
}

int tcdrain(int fd) __attribute__((weak,alias("__libc_tcdrain")));





int tcflow ( int fd, int action )
{


    if ( (unsigned int)action < 4u )
 return ioctl ( fd, 
# 6407 "libc.h" 3 4
                   0x5406
# 6407 "libc.h"
                         , action );

    errno = 
# 6409 "libc.h" 3 4
           22
# 6409 "libc.h"
                 ;
    return -1;
# 6431 "libc.h"
}


int __libc_tcflush(int fd, int queue_selector);
int __libc_tcflush(int fd, int queue_selector)
{
  return ioctl(fd, 
# 6437 "libc.h" 3 4
                  0x5407
# 6437 "libc.h"
                        , queue_selector);
}

int tcflush(int fd, int queue_selector) __attribute__((weak,alias("__libc_tcflush")));



int tcgetattr(int fildes, struct termios *termios_p)
{
  return ioctl(fildes, 
# 6446 "libc.h" 3 4
                      0x540d
# 6446 "libc.h"
                            , termios_p);
}




pid_t tcgetpgrp(int fildes)
{
  int32_t foo = -1;
  if (ioctl(fildes, 
# 6455 "libc.h" 3 4
                   (((2U) << (((0 +8)+8)+13)) | ((('t')) << (0 +8)) | (((119)) << 0) | (((sizeof(int)) & 0xff) << ((0 +8)+8)))
# 6455 "libc.h"
                            , &foo)==-1)
    return -1;
  else
    return foo;
}



pid_t tcgetsid(int fildes) {
  pid_t pid;
  return ioctl(fildes, 
# 6465 "libc.h" 3 4
                      0x7416
# 6465 "libc.h"
                              , &pid)==-1?-1:pid;
}






int tcsendbreak (int fd,int duration)
{
  if (duration <= 0) return (ioctl (fd,
# 6475 "libc.h" 3 4
                                      0x5486
# 6475 "libc.h"
                                             ,0));
  errno = 
# 6476 "libc.h" 3 4
         22
# 6476 "libc.h"
               ;
  return (-1);
}
# 6490 "libc.h"
int tcsetattr ( int fildes, int optional_actions, struct termios* termios_p )
{
# 6502 "libc.h"
    switch ( optional_actions ) {
    case 
# 6503 "libc.h" 3 4
        0x540e
# 6503 "libc.h"
               :
        return ioctl ( fildes, 
# 6504 "libc.h" 3 4
                              0x540e 
# 6504 "libc.h"
                                     , termios_p );
    case 
# 6505 "libc.h" 3 4
        0x540f
# 6505 "libc.h"
                 :
        return ioctl ( fildes, 
# 6506 "libc.h" 3 4
                              0x540f
# 6506 "libc.h"
                                     , termios_p );
    case 
# 6507 "libc.h" 3 4
        0x5410
# 6507 "libc.h"
                 :
        return ioctl ( fildes, 
# 6508 "libc.h" 3 4
                              0x5410
# 6508 "libc.h"
                                     , termios_p );
    default:
        errno = 
# 6510 "libc.h" 3 4
               22
# 6510 "libc.h"
                     ;
        return -1;
    }


}




int tcsetpgrp(int fildes, pid_t pgrpid)
{
  return ioctl(fildes, 
# 6522 "libc.h" 3 4
                      (((4U) << (((0 +8)+8)+13)) | ((('t')) << (0 +8)) | (((118)) << 0) | (((sizeof(int)) & 0xff) << ((0 +8)+8)))
# 6522 "libc.h"
                               , &pgrpid);
}




off_t telldir(DIR *d) {
  off_t result = 0;
  if (lseek(d->fd,0,
# 6530 "libc.h" 3 4
                   1
# 6530 "libc.h"
                           ))
    result=((struct dirent*)(d->buf+d->cur))->d_off;
  return result;
}
# 6546 "libc.h"
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

int thrd_create(thrd_t *thr, thrd_start_t func, void *arg) {
  size_t stacksize=_thrd_stacksize;
  char* stack=mmap(0,stacksize+4096+__tmemsize+sizeof(tcbhead_t)+sizeof(**thr),
# 6565 "libc.h" 3 4
                                                                              0x0
# 6565 "libc.h"
                                                                                       ,
# 6565 "libc.h" 3 4
                                                                                        0x02
# 6565 "libc.h"
                                                                                                   |
# 6565 "libc.h" 3 4
                                                                                                    0x0800
# 6565 "libc.h"
                                                                                                                 |
# 6565 "libc.h" 3 4
                                                                                                                  0x40000
# 6565 "libc.h"
                                                                                                                           |
# 6565 "libc.h" 3 4
                                                                                                                            0x1000
# 6565 "libc.h"
                                                                                                                                         ,-1,0);
  thrd_t t;
  tcbhead_t* tcb;

  if (stack==
# 6569 "libc.h" 3 4
            ((void *) -1)
# 6569 "libc.h"
                      ) return thrd_nomem;
  if (mprotect(stack+4096,stacksize+__tmemsize+sizeof(tcbhead_t)+sizeof(**thr),
# 6570 "libc.h" 3 4
                                                                              0x1
# 6570 "libc.h"
                                                                                       |
# 6570 "libc.h" 3 4
                                                                                        0x2
# 6570 "libc.h"
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
# 6582 "libc.h" 3 4
                                                          GRND_NONBLOCK
# 6582 "libc.h"
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
# 6599 "libc.h" 3 4
                                          0x00000400
# 6599 "libc.h"
                                                     |
# 6599 "libc.h" 3 4
                                                      0x00000200
# 6599 "libc.h"
                                                              |
# 6599 "libc.h" 3 4
                                                               0x80000000
# 6599 "libc.h"
                                                                       |
# 6599 "libc.h" 3 4
                                                                        0x00008000
# 6599 "libc.h"
                                                                                    |
# 6599 "libc.h" 3 4
                                                                                     0x00000800
# 6599 "libc.h"
                                                                                                  |
# 6599 "libc.h" 3 4
                                                                                                   0x00040000
# 6599 "libc.h"
                                                                                                                |
# 6599 "libc.h" 3 4
                                                                                                                 0x00010000
# 6599 "libc.h"
                                                                                                                             |
# 6599 "libc.h" 3 4
                                                                                                                              0x00000100
# 6599 "libc.h"
                                                                                                                                      |
# 6599 "libc.h" 3 4
                                                                                                                                       0x00080000
# 6599 "libc.h"
                                                                                                                                                   |
# 6599 "libc.h" 3 4
                                                                                                                                                    0x00100000
# 6599 "libc.h"
                                                                                                                                                                       ,t,&t->tid,stack+stacksize+4096+__tmemsize);
  if (t->tid==-1) {
    munmap(stack,stacksize+4096+__tmemsize+sizeof(tcbhead_t)+sizeof(**thr));
    return thrd_error;
  }
  *thr=t;
  return thrd_success;
}



thrd_t thrd_current(void) {
  tcbhead_t* x=__get_cur_tcb();
  if (x->multiple_threads==0) return 
# 6612 "libc.h" 3 4
                                    (void*)0
# 6612 "libc.h"
                                        ;
  return (thrd_t)(x+1);
}




int thrd_detach(thrd_t thr) {
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
# 6641 "libc.h"
 void __munmap_and_exit(void* map,size_t len) __attribute__((noreturn));


# 6643 "libc.h" 3 4
__thread 
# 6643 "libc.h"
            tss_t tss_dtor_list;

void thrd_exit(int res) {
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
# 6670 "libc.h" 3 4
                 4
# 6670 "libc.h"
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







int thrd_join(thrd_t thr, int* res) {
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
# 6721 "libc.h" 3 4
                            4
# 6721 "libc.h"
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



thrd_t _thrd_root;
size_t _thrd_stacksize=16*1024;
# 1 "include/sys/timerfd.h" 1 3 4






# 6 "include/sys/timerfd.h" 3 4
enum { TFD_TIMER_ABSTIME = 1 };



int timerfd_create (clockid_t clock_id, int flags) __attribute__((__nothrow__ , __leaf__));
int timerfd_settime (int ufd, int flags, const struct itimerspec *utmr, struct itimerspec *otmr) __attribute__((__nothrow__ , __leaf__));
int timerfd_gettime (int ufd, struct itimerspec *otmr) __attribute__((__nothrow__ , __leaf__));


# 6738 "libc.h" 2

 
# 6739 "libc.h"
      int __timerfd(int ufd, int clockid, int flags, const struct itimerspec *utmr);

int timerfd_create (clockid_t __clock_id, int __flags) {
  return __timerfd(-1,__clock_id,__flags,0);
}


int timingsafe_bcmp(const void* a,const void* b,size_t n) {
  size_t i;
  const unsigned char* x = a;
  const unsigned char* y = b;
  int r;
  for (i=r=0; i<n; ++i)
    r |= x[i] ^ y[i];
  return !!r;
}


int timingsafe_memcmp(const void* a,const void* b,size_t n) {


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


int tolower(int ch) {
  if ( (unsigned int)(ch - 'A') < 26u )
    ch += 'a' - 'A';
  return ch;
}



inline int toupper(int ch) {
  if ( (unsigned int)(ch - 'a') < 26u )
    ch += 'A' - 'a';
  return ch;
}



wint_t towlower(wint_t c) {
  if ( (unsigned int)(c - 'A') < 26u )
    c += 'a' - 'A';
  return c;
}




 
# 6805 "libc.h" 3 4
      __thread 
# 6805 "libc.h"
                   tss_t tss_dtor_list;

int tss_create(tss_t* tss_id, tss_dtor_t destructor) {
  *tss_id=malloc(sizeof(**tss_id));
  if (!*tss_id) return thrd_nomem;
  (*tss_id)->dtor=destructor;
  (*tss_id)->next=tss_dtor_list;
  (*tss_id)->data=0;
  tss_dtor_list=*tss_id;
  return thrd_success;
}


wint_t towupper(wint_t c) {
  if ( (unsigned int)(c - 'a') < 26u )
    c += 'A' - 'a';
  return c;
}



 
# 6826 "libc.h" 3 4
      __thread 
# 6826 "libc.h"
                   tss_t tss_dtor_list;

void tss_delete(tss_t tss_id) {
  tss_t* cur;
  for (cur=&tss_dtor_list; *cur; cur=&((*cur)->next)) {
    if (*cur==tss_id)
      *cur=tss_id->next;
  }
  tss_id->dtor=0;
  tss_id->data=0;
  tss_id->next=0;
}


void* tss_get(tss_t tss_id) {
  return tss_id->data;
}


int tss_set(tss_t tss_id, void* val) {
  tss_id->data=val;
  return thrd_success;
}
# 6921 "libc.h"
int usleep(unsigned long usecs) {
  struct timespec t;
  t.tv_sec=usecs/1000000;
  t.tv_nsec=(usecs%1000000)*1000;
  return nanosleep(&t,&t);
}
# 6935 "libc.h"
# 1 "internal.h" 1

const void* vdso_dlsym(const char* elfimage,const char* symbol);
# 6936 "libc.h" 2
# 6953 "libc.h"
const void* vdso_dlsym(const char* elfimage,const char* symbol) {





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



pid_t vfork() { return fork(); }
# 7013 "libc.h"
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

int vsnprintf(char* str, size_t size, const char *format, va_list arg_ptr) {
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




# 1 "dietwarning.h" 1
# 7050 "libc.h" 2

int vsprintf(char *dest,const char *format, va_list arg_ptr)
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

int vsscanf(const char* str, const char* format, va_list arg_ptr)
{
  struct str_data fdat = { (unsigned char*)str };
  struct arg_scanf farg = { (void*)&fdat, (int(*)(void*))sgetc, (int(*)(int,void*))sputc };
  return __v_scanf(&farg,format,arg_ptr);
}

# 1 "include/sys/wait.h" 1 3 4







# 48 "include/sys/wait.h" 3 4

# 48 "include/sys/wait.h" 3 4
pid_t wait(int *status);
pid_t waitpid(pid_t pid, int *status, int options);

pid_t wait3(int *status, int options, struct rusage *rusage) __attribute__((__nothrow__));

pid_t wait4(pid_t pid, int *status, int options, struct rusage *rusage) __attribute__((__nothrow__));

typedef enum {
  P_ALL,
  P_PID,
  P_PGID
} idtype_t;

int waitid(idtype_t idtype, id_t id, siginfo_t *infop, int options);


# 7084 "libc.h" 2


# 7085 "libc.h"
pid_t wait(int *status) {
  return waitpid(-1,status,0);
}


pid_t wait3(int* status,int opts,struct rusage* rusage) {
  return wait4(-1,status,opts,rusage);
}



static mbstate_t internal;

size_t wcrtomb(char *s, wchar_t wc, mbstate_t *ps) {
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


wchar_t* wcscat(wchar_t *__restrict__ dest, const wchar_t *__restrict__ src) {
  wchar_t* orig=dest;
  for (; *dest; ++dest) ;
  for (; (*dest=*src); ++src,++dest) ;
  return orig;
}


wchar_t* wcschr(const wchar_t *wcs, wchar_t wc) {
  for (; *wcs; ++wcs)
    if (*wcs == wc)
      return (wchar_t*)wcs;
  return 0;
}


int wcscmp(const wchar_t* a,const wchar_t* b) {
  while (*a && *a == *b)
    a++, b++;
  return (*a - *b);
}

int wcscoll(const wchar_t *s,const wchar_t* t) __attribute__((weak,alias("wcscmp")));


wchar_t* wcscpy(wchar_t *__restrict__ dest, const wchar_t *__restrict__ src) {
  wchar_t* orig=dest;
  for (; (*dest=*src); ++src,++dest) ;
  return orig;
}


size_t wcslen(const wchar_t* s) {
  size_t i;
  for (i=0; s[i]; ++i) ;
  return i;
}


wchar_t* wcsncat(wchar_t *__restrict__ dest, const wchar_t *__restrict__ src,size_t n) {
  wchar_t* orig=dest;
  size_t i;
  while (*dest) ++dest;
  for (i=0; i<n && src[i]; ++i) dest[i]=src[i];
  dest[i]=0;
  return orig;
}


int wcsncmp(const wchar_t *s1, const wchar_t *s2, size_t n) {
  size_t i;
  for (i=0; i<n && s1[i]==s2[i]; ++i) ;
  return s1[i]-s2[i];
}


wchar_t* wcsncpy(wchar_t *__restrict__ dest, const wchar_t *__restrict__ src,size_t n) {
  wchar_t* orig=dest;
  for (; dest<orig+n && (*dest=*src); ++src,++dest) ;
  for (; dest<orig+n; ++dest) *dest=0;
  return orig;
}


wchar_t* wcsrchr(const wchar_t *wcs, wchar_t wc) {
  wchar_t* last=0;
  for (; *wcs; ++wcs)
    if (*wcs == wc)
      last=(wchar_t*)wcs;
  return last;
}







size_t wcsrtombs(char *dest, const wchar_t **src, size_t len, mbstate_t *ps) {
  wchar_t c;
  char buf[
# 7211 "libc.h" 3 4
          5
# 7211 "libc.h"
                    ];
  size_t cur;
  if (!src || !*src) {
inval:
    errno=
# 7215 "libc.h" 3 4
         22
# 7215 "libc.h"
               ;
    return -1;
  }
  if (!dest) {
    len=-1;
  }
  for (cur=0; (c=**src); ++*src) {
    size_t n;
    char* s=
# 7223 "libc.h" 3 4
           __builtin_expect((long)((
# 7223 "libc.h"
           len-cur>=
# 7223 "libc.h" 3 4
           5)),1)
# 7223 "libc.h"
                                        ?(dest?dest+cur:
# 7223 "libc.h" 3 4
                                                        (void*)0
# 7223 "libc.h"
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



wchar_t *wcsstr(const wchar_t *haystack, const wchar_t *needle) {
  size_t i,j;
  for (i=0; haystack[i]; ++i) {
    for (j=0; haystack[i+j]==needle[j]; ++j) ;
    if (!needle[j]) return (wchar_t*)haystack+i;
  }
  return 0;
}
# 7256 "libc.h"
size_t wcstombs(char *dest, const wchar_t *src, size_t len) {
  return wcsrtombs(dest,&src,len,
# 7257 "libc.h" 3 4
                                (void*)0
# 7257 "libc.h"
                                    );
}
# 7323 "libc.h"
int wcswidth(const wchar_t *pwcs, size_t n)
{
  int w, width = 0;

  for (;*pwcs && n-- > 0; pwcs++)
    if ((w = wcwidth(*pwcs)) < 0)
      return -1;
    else
      width += w;

  return width;
}




int wctomb(char *pwc, wchar_t s) {
  return wcrtomb(pwc,s,
# 7340 "libc.h" 3 4
                      (void*)0
# 7340 "libc.h"
                          );
}
# 7408 "libc.h"
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
# 7466 "libc.h"
int wcwidth(wchar_t ucs)
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



# 1 "include/write12.h" 1 3 4






# 6 "include/write12.h" 3 4
ssize_t __write1 ( const char* s ) __attribute__ (( ));
ssize_t __write2 ( const char* s ) __attribute__ (( ));


# 7553 "libc.h" 2








# 7560 "libc.h"
ssize_t __write1 (const char* s) {
  return write(1, s, strlen(s));
}

ssize_t __write2 (const char* s) {
  return write(2, s, strlen(s));
}





 size_t __pread(int fd, void *buf, size_t count, int dummy, off_t a, off_t b);

size_t __libc_pread64(int fd, void *buf, size_t count, off64_t offset);
size_t __libc_pread64(int fd, void *buf, size_t count, off64_t offset) {
  return __pread(fd,buf,count,0,(off_t)(offset>>32)
# 7576 "libc.h" 3 4
                               , 
# 7576 "libc.h"
                               (off_t)(offset&0xffffffff));
}

int pread64(int fd, void *buf, size_t count, off_t offset) __attribute__((weak,alias("__libc_pread64")));






 size_t __pwrite(int fd, void *buf, size_t count, int dummy, off_t a, off_t b);

size_t __libc_pwrite64(int fd, void *buf, size_t count, off64_t offset);
size_t __libc_pwrite64(int fd, void *buf, size_t count, off64_t offset) {
  return __pwrite(fd,buf,count,0,(off_t)(offset>>32)
# 7590 "libc.h" 3 4
                                , 
# 7590 "libc.h"
                                (off_t)(offset&0xffffffff));
}

int pwrite64(int fd, void *buf, size_t count, off_t offset) __attribute__((weak,alias("__libc_pwrite64")));
# 7620 "libc.h"
const
unsigned char __clz_tab[] =
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

# 1 "mips/longlong.h" 1
# 7634 "libc.h" 2

typedef unsigned int UQItype __attribute__ ((mode (QI)));
typedef int SItype __attribute__ ((mode (SI)));
typedef unsigned int USItype __attribute__ ((mode (SI)));
typedef int DItype __attribute__ ((mode (DI)));
typedef unsigned int UDItype __attribute__ ((mode (DI)));
# 7649 "libc.h"
struct DWstruct { SItype high, low;};





typedef union { struct DWstruct s; DItype ll; } DWunion;


 DItype __divdi3 (DItype u, DItype v);
 DItype __moddi3 (DItype u, DItype v);
 UDItype __udivdi3 (UDItype u, UDItype v);
 UDItype __umoddi3 (UDItype u, UDItype v);

static UDItype
__udivmoddi4 (UDItype n, UDItype d, UDItype *rp)
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
# 7716 "libc.h"
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
# 7822 "libc.h"
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

DItype
__divdi3 (DItype u, DItype v)
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
# 7896 "libc.h" 3 4
                         (void*)0
# 7896 "libc.h"
                             );
  if (c)
    w = -w;
  return w;
}

DItype
__moddi3 (DItype u, DItype v)
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

UDItype
__udivdi3 (UDItype u, UDItype v)
{
  return __udivmoddi4 (u, v, 
# 7924 "libc.h" 3 4
                            (void*)0
# 7924 "libc.h"
                                );
}

UDItype
__umoddi3 (UDItype u, UDItype v)
{
  UDItype w;

  __udivmoddi4 (u, v, &w);
  return w;
}


# 1 "include/stdio_ext.h" 1 3 4








# 8 "include/stdio_ext.h" 3 4
size_t __fbufsize(FILE *stream);
size_t __fpending(FILE *stream);
int __flbf(FILE *stream);
int __freadable(FILE *stream);
int __fwritable(FILE *stream);
int __freading(FILE *stream);
int __fwriting(FILE *stream);
int __fsetlocking(FILE *stream, int type);
void _flushlbf(void);
void __fpurge(FILE *stream);


# 7938 "libc.h" 2



# 7940 "libc.h"
size_t __fbufsize(FILE* stream) {
  return stream->buflen;
}



int __flbf(FILE* stream) {
  return !!(stream->flags&8);
}



size_t __fpending(FILE* stream) {
  return stream->bm;
}



void __fpurge(FILE* stream) {
  stream->ungotten=0;
  stream->bs=stream->bm=0;
}



int __freadable(FILE* stream) {
  return !!(stream->flags&128);
}



int __freading(FILE* stream) {
  return !(stream->flags&256);
}



int __fwritable(FILE* stream) {
  return !!(stream->flags&256);
}


void clearerr_unlocked(FILE *stream) {
  stream->flags&=~(1|2);
}

void clearerr(FILE *stream) __attribute__((weak,alias("clearerr_unlocked")));




int fclose_unlocked(FILE *stream) {
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

int fclose(FILE *stream) __attribute__((weak,alias("fclose_unlocked")));
# 8020 "libc.h"
int __stdio_parse_mode(const char *mode) {
  int f=0;
  for (;;) {
    switch (*mode) {
    case 0: return f;
    case 'b': break;
    case 'r': f|=
# 8026 "libc.h" 3 4
                0x0000
# 8026 "libc.h"
                        ; break;
    case 'w': f|=
# 8027 "libc.h" 3 4
                0x0001
# 8027 "libc.h"
                        |
# 8027 "libc.h" 3 4
                         0x0100
# 8027 "libc.h"
                                |
# 8027 "libc.h" 3 4
                                 0x0200
# 8027 "libc.h"
                                        ; break;
    case 'a': f|=
# 8028 "libc.h" 3 4
                0x0001
# 8028 "libc.h"
                        |
# 8028 "libc.h" 3 4
                         0x0100
# 8028 "libc.h"
                                |
# 8028 "libc.h" 3 4
                                 0x0008
# 8028 "libc.h"
                                         ; break;
    case 'x': f|=
# 8029 "libc.h" 3 4
                0x0400
# 8029 "libc.h"
                      ; break;
    case '+': f=(f&(~
# 8030 "libc.h" 3 4
                    0x0001
# 8030 "libc.h"
                            ))|
# 8030 "libc.h" 3 4
                               0x0002
# 8030 "libc.h"
                                     ; break;
    }
    ++mode;
  }
}
# 8046 "libc.h"
 int __stdio_atexit;

FILE*__stdio_init_file(int fd,int closeonerror,int mode) {
  FILE *tmp=(FILE*)malloc(sizeof(FILE));
  if (!tmp) goto err_out;
  tmp->buf=(char*)malloc(2048);
  if (!tmp->buf) {
    free(tmp);
err_out:
    if (closeonerror) __libc_close(fd);
    errno=
# 8056 "libc.h" 3 4
         12
# 8056 "libc.h"
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
# 8066 "libc.h" 3 4
               (((
# 8066 "libc.h"
               st.st_mode
# 8066 "libc.h" 3 4
               ) & 00170000) == 0010000)
# 8066 "libc.h"
                                   )?64:0;
  }
  switch (mode&3) {
  case 
# 8069 "libc.h" 3 4
      0x0002
# 8069 "libc.h"
            : tmp->flags|=256;
  case 
# 8070 "libc.h" 3 4
      0x0000
# 8070 "libc.h"
              : tmp->flags|=128|4; break;
  case 
# 8071 "libc.h" 3 4
      0x0001
# 8071 "libc.h"
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

FILE* __stdio_init_file_nothreads(int fd,int closeonerror,int mode) __attribute__((alias("__stdio_init_file")));






FILE *fdopen_unlocked(int filedes, const char *mode) {
  int f=0;

  f=__stdio_parse_mode(mode);
  if (filedes<0) { errno=
# 8095 "libc.h" 3 4
                        9
# 8095 "libc.h"
                             ; return 0; }
  return __stdio_init_file(filedes,0,f);
}

FILE *fdopen(int filedes, const char *mode) __attribute__((weak,alias("fdopen_unlocked")));


int feof_unlocked(FILE*stream) {

  if (stream->ungotten) return 0;
  return (stream->flags&2);
}
int feof(FILE*stream)
__attribute__((weak,alias("feof_unlocked")));





int fdprintf(int fd,const char *format,...) {
  int n;
  va_list arg_ptr;
  
# 8117 "libc.h" 3 4
 __builtin_va_start((
# 8117 "libc.h"
 arg_ptr
# 8117 "libc.h" 3 4
 ),(
# 8117 "libc.h"
 format
# 8117 "libc.h" 3 4
 ))
# 8117 "libc.h"
                         ;
  n=vfdprintf(fd,format,arg_ptr);
  
# 8119 "libc.h" 3 4
 __builtin_va_end
# 8119 "libc.h"
       (arg_ptr);
  return n;
}


int ferror_unlocked(FILE*stream) {
  return (stream->flags&1);
}
int ferror(FILE*stream)
__attribute__((weak,alias("ferror_unlocked")));


# 1 "dietwarning.h" 1
# 8132 "libc.h" 2


FILE *__stdio_root;

int __stdio_atexit=0;

int fflush(FILE *stream) __attribute__((weak,alias("fflush_unlocked")));

void __stdio_flushall(void) {
  fflush(0);
}

int fflush_unlocked(FILE *stream) {
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
# 8160 "libc.h" 3 4
                          1
# 8160 "libc.h"
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

int __fflush4(FILE *stream,int next) {
  if (
# 8175 "libc.h" 3 4
     __builtin_expect((long)((
# 8175 "libc.h"
     !__stdio_atexit
# 8175 "libc.h" 3 4
     )),0)
# 8175 "libc.h"
                                ) {
    __stdio_atexit=1;
    atexit(__stdio_flushall);
  }
  if (
# 8179 "libc.h" 3 4
     __builtin_expect((long)((
# 8179 "libc.h"
     (stream->flags&4)!=next
# 8179 "libc.h" 3 4
     )),0)
# 8179 "libc.h"
                                               ) {
    int res=fflush_unlocked(stream);
    stream->flags=(stream->flags&~4)|next;
    return res;
  }
  if (stream->fd==0 && __stdin_is_tty()) __fflush_stdout();
  return 0;
}



int __stdio_outs(const char *s,size_t len);
int __stdio_outs(const char *s,size_t len) {
  return fwrite(s,1,(size_t)len,stdout)==len?1:0;
}

asm (".section .gnu.warning." "fflush" "\n\t.string \"" "warning: your code uses stdio (7+k bloat)." "\"\n\t.previous");



int fgetc_unlocked(FILE *stream) {
  unsigned char c;
  if (
# 8201 "libc.h" 3 4
     __builtin_expect((long)((
# 8201 "libc.h"
     !(stream->flags&128)
# 8201 "libc.h" 3 4
     )),0)
# 8201 "libc.h"
                                         ) goto kaputt;
  if (
# 8202 "libc.h" 3 4
     __builtin_expect((long)((
# 8202 "libc.h"
     stream->ungotten
# 8202 "libc.h" 3 4
     )),0)
# 8202 "libc.h"
                                 ) {
    stream->ungotten=0;
    return stream->ungetbuf;
  }


  if (
# 8208 "libc.h" 3 4
     __builtin_expect((long)((
# 8208 "libc.h"
     stream->bm<stream->bs
# 8208 "libc.h" 3 4
     )),1)
# 8208 "libc.h"
                                    )
    return (unsigned char)stream->buf[stream->bm++];

  if (
# 8211 "libc.h" 3 4
     __builtin_expect((long)((
# 8211 "libc.h"
     feof_unlocked(stream)
# 8211 "libc.h" 3 4
     )),0)
# 8211 "libc.h"
                                      )
    return 
# 8212 "libc.h" 3 4
          (-1)
# 8212 "libc.h"
             ;
  if (__fflush4(stream,4)) return 
# 8213 "libc.h" 3 4
                                        (-1)
# 8213 "libc.h"
                                           ;
  if (
# 8214 "libc.h" 3 4
     __builtin_expect((long)((
# 8214 "libc.h"
     stream->bm>=stream->bs
# 8214 "libc.h" 3 4
     )),0)
# 8214 "libc.h"
                                       ) {
    ssize_t len=__libc_read(stream->fd,stream->buf,stream->buflen);
    if (len==0) {
      stream->flags|=2;
      return 
# 8218 "libc.h" 3 4
            (-1)
# 8218 "libc.h"
               ;
    } else if (len<0) {
kaputt:
      stream->flags|=1;
      return 
# 8222 "libc.h" 3 4
            (-1)
# 8222 "libc.h"
               ;
    }
    stream->bm=0;
    stream->bs=len;
  }
  c=stream->buf[stream->bm];
  ++stream->bm;
  return c;
}

int fgetc(FILE* stream) __attribute__((weak,alias("fgetc_unlocked")));


int fgetpos(FILE *stream, fpos_t *pos) {
  long l=ftell(stream);
  if (l==-1) return -1;
  *pos=l;
  return 0;
}


char *fgets_unlocked(char *s, int size, FILE *stream) {
  int l;
  if (size<=0) return 0;
  for (l=0; l+1<size; ) {
    register int c;
    if (l && 
# 8248 "libc.h" 3 4
            __builtin_expect((long)((
# 8248 "libc.h"
            stream->bm<stream->bs
# 8248 "libc.h" 3 4
            )),1)
# 8248 "libc.h"
                                           ) {

      c=(unsigned char)stream->buf[stream->bm++];
    } else {
      c=fgetc_unlocked(stream);
      if (
# 8253 "libc.h" 3 4
         __builtin_expect((long)((
# 8253 "libc.h"
         c==
# 8253 "libc.h" 3 4
         (-1))),0)
# 8253 "libc.h"
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

char*fgets(char*s,int size,FILE*stream) __attribute__((weak,alias("fgets_unlocked")));


int fileno_unlocked(FILE*stream) {
  return stream->fd;
}
int fileno(FILE*stream)
__attribute__((weak,alias("fileno_unlocked")));




 int __stdio_atexit;




FILE *fopen_unlocked(const char *path, const char *mode) {
  int f=0;
  int fd;

  f=__stdio_parse_mode(mode);
  if ((fd=__libc_open(path,f,0666))<0)
    return 0;
  return __stdio_init_file(fd,1,f);
}

FILE *fopen(const char *path, const char *mode) __attribute__((weak,alias("fopen_unlocked")));





int fprintf(FILE *f,const char *format,...) {
  int n;
  va_list arg_ptr;
  
# 8302 "libc.h" 3 4
 __builtin_va_start((
# 8302 "libc.h"
 arg_ptr
# 8302 "libc.h" 3 4
 ),(
# 8302 "libc.h"
 format
# 8302 "libc.h" 3 4
 ))
# 8302 "libc.h"
                         ;
  n=vfprintf(f,format,arg_ptr);
  
# 8304 "libc.h" 3 4
 __builtin_va_end
# 8304 "libc.h"
       (arg_ptr);
  return n;
}




int fputc_unlocked(int c, FILE *stream) {
  if (!
# 8312 "libc.h" 3 4
      __builtin_expect((long)((
# 8312 "libc.h"
      stream->flags&256
# 8312 "libc.h" 3 4
      )),1) 
# 8312 "libc.h"
                                       || __fflush4(stream,0)) {
kaputt:
    stream->flags|=1;
    return 
# 8315 "libc.h" 3 4
          (-1)
# 8315 "libc.h"
             ;
  }
  if (
# 8317 "libc.h" 3 4
     __builtin_expect((long)((
# 8317 "libc.h"
     stream->bm>=stream->buflen-1
# 8317 "libc.h" 3 4
     )),0)
# 8317 "libc.h"
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

int fputc(int c,FILE* stream) __attribute__((weak,alias("fputc_unlocked")));



int fputs_unlocked(const char*s,FILE*stream) {
  return fwrite_unlocked(s,strlen(s),1,stream);
}

int fputs(const char*s,FILE*stream) __attribute__((weak,alias("fputs_unlocked")));




size_t fread_unlocked(void *ptr, size_t size, size_t nmemb, FILE *stream) {
  unsigned long i,j;
  j=size*nmemb;
  i=0;

  if (!(stream->flags&128)) {
    stream->flags|=1;
    return 0;
  }
  if (!j || j/nmemb!=size) return 0;
  if (
# 8359 "libc.h" 3 4
     __builtin_expect((long)((
# 8359 "libc.h"
     stream->ungotten
# 8359 "libc.h" 3 4
     )),0)
# 8359 "libc.h"
                                 ) {
    stream->ungotten=0;
    *(char*)ptr=stream->ungetbuf;
    ++i;
    if (j==1) return 1;
  }


  if (
# 8367 "libc.h" 3 4
     __builtin_expect((long)((
# 8367 "libc.h"
     feof_unlocked(stream)
# 8367 "libc.h" 3 4
     )),0)
# 8367 "libc.h"
                                      )
    return 0;
  if (__fflush4(stream,4)) return 0;

  size_t inbuf=stream->bs-stream->bm;
  if (
# 8372 "libc.h" 3 4
     __builtin_expect((long)((
# 8372 "libc.h"
     !inbuf
# 8372 "libc.h" 3 4
     )),0)
# 8372 "libc.h"
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
# 8410 "libc.h" 3 4
            (-1)
# 8410 "libc.h"
               )
exit:
      return i/size;
    else
      ((unsigned char*)ptr)[i]=(unsigned char)res;
  }
  return nmemb;
}

size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream) __attribute__((weak,alias("fread_unlocked")));
# 8429 "libc.h"
FILE *freopen_unlocked(const char *path, const char *mode, FILE *stream) {
  if (stream) {
    int f=__stdio_parse_mode(mode);
    fflush_unlocked(stream);
    __libc_close(stream->fd);
    if ((stream->fd=__libc_open(path,f,0666))!=-1) {
      struct stat st;
      fstat(stream->fd,&st);
      stream->flags=(
# 8437 "libc.h" 3 4
                    (((
# 8437 "libc.h"
                    st.st_mode
# 8437 "libc.h" 3 4
                    ) & 00170000) == 0010000)
# 8437 "libc.h"
                                        )?64:0;
      switch (f&3) {
      case 
# 8439 "libc.h" 3 4
          0x0002
# 8439 "libc.h"
                : stream->flags|=256;
      case 
# 8440 "libc.h" 3 4
          0x0000
# 8440 "libc.h"
                  : stream->flags|=128; break;
      case 
# 8441 "libc.h" 3 4
          0x0001
# 8441 "libc.h"
                  : stream->flags|=256;
      }
    }
  } else errno=
# 8444 "libc.h" 3 4
              22
# 8444 "libc.h"
                    ;
  return stream;
}

FILE *freopen(const char *path, const char *mode, FILE *stream) __attribute__((weak,alias("freopen_unlocked")));






int fscanf(FILE *stream, const char *format, ...) {
  int n;
  va_list arg_ptr;
  
# 8458 "libc.h" 3 4
 __builtin_va_start((
# 8458 "libc.h"
 arg_ptr
# 8458 "libc.h" 3 4
 ),(
# 8458 "libc.h"
 format
# 8458 "libc.h" 3 4
 ))
# 8458 "libc.h"
                          ;
  n=vfscanf(stream,format,arg_ptr);
  
# 8460 "libc.h" 3 4
 __builtin_va_end 
# 8460 "libc.h"
        (arg_ptr);
  return n;
}



int fseek_unlocked(FILE *stream, long offset, int whence) {
  fflush_unlocked(stream);
  stream->bm=0; stream->bs=0;
  stream->flags&=~(1|2);
  stream->ungotten=0;
  return lseek(stream->fd,offset,whence)!=-1?0:-1;
}

int fseek(FILE *stream, long offset, int whence) __attribute__((weak,alias("fseek_unlocked")));



int fseeko_unlocked(FILE *stream, off_t offset, int whence) {
  fflush(stream);
  stream->bm=0; stream->bs=0;
  stream->flags&=~(1|2);
  stream->ungotten=0;
  return lseek(stream->fd,offset,whence)!=-1?0:-1;
}

int fseeko(FILE *stream, off_t offset, int whence) __attribute__((weak,alias("fseeko_unlocked")));





int fseeko64_unlocked(FILE *stream, off64_t offset, int whence) {
  fflush_unlocked(stream);
  stream->bm=0; stream->bs=0;
  stream->flags&=~(1|2);
  stream->ungotten=0;
  return lseek64(stream->fd,offset,whence)!=-1?0:-1;
}

int fseeko64(FILE *stream, off64_t offset, int whence) __attribute__((weak,alias("fseeko64_unlocked")));



int fsetpos(FILE *stream, fpos_t *pos) {
  if (fseek(stream,*pos,
# 8505 "libc.h" 3 4
                       0
# 8505 "libc.h"
                               )==-1)
    return -1;
  return 0;
}




long ftell_unlocked(FILE *stream) {
  off_t l;
  if (stream->flags&1 || (l=lseek(stream->fd,0,
# 8515 "libc.h" 3 4
                                              1
# 8515 "libc.h"
                                                      ))==-1) return -1;
  if (stream->flags&4)
    return l-(stream->bs-stream->bm)-stream->ungotten;
  else
    return l+stream->bm;
}

long ftell(FILE *stream) __attribute__((weak,alias("ftell_unlocked")));



off_t ftello_unlocked(FILE *stream) {
  off_t l;
  if (fflush_unlocked(stream)) return -1;
  return ((l=lseek(stream->fd,0,
# 8529 "libc.h" 3 4
                               1
# 8529 "libc.h"
                                       ))==-1?-1:l-stream->ungotten);
}

off_t ftello(FILE *stream) __attribute__((weak,alias("ftello_unlocked")));





off64_t ftello64_unlocked(FILE *stream) {
  off64_t l;
  if (fflush_unlocked(stream)) return -1;
  return ((l=lseek64(stream->fd,0ull,
# 8541 "libc.h" 3 4
                                    1
# 8541 "libc.h"
                                            ))==-1?-1:l-stream->ungotten);
}

off64_t ftello64(FILE *stream) __attribute__((weak,alias("ftello64_unlocked")));






size_t fwrite_unlocked(const void *ptr, size_t size, size_t nmemb, FILE *stream) {
  ssize_t res;
  size_t len=size*nmemb;
  size_t i,done;
  if (!
# 8555 "libc.h" 3 4
      __builtin_expect((long)((
# 8555 "libc.h"
      stream->flags&256
# 8555 "libc.h" 3 4
      )),1) 
# 8555 "libc.h"
                                       || __fflush4(stream,0)) {
kaputt:
    stream->flags|=1;
    return 0;
  }
  if (!nmemb || len/nmemb!=size) return 0;
  if (
# 8561 "libc.h" 3 4
     __builtin_expect((long)((
# 8561 "libc.h"
     len>stream->buflen || (stream->flags&16)
# 8561 "libc.h" 3 4
     )),0)
# 8561 "libc.h"
                                                            ) {
    if (fflush_unlocked(stream)) return 0;
    do {
      res=__libc_write(stream->fd,ptr,len);
    } while (res==-1 && errno==
# 8565 "libc.h" 3 4
                              4
# 8565 "libc.h"
                                   );
  } else
again:
         {

    size_t todo=stream->buflen-stream->bm;
    if (todo>len) todo=len;

    if (todo) {
      if (stream->flags&8) {
 if (
# 8575 "libc.h" 3 4
    __builtin_expect((long)((
# 8575 "libc.h"
    (stream->flags&512)!=0
# 8575 "libc.h" 3 4
    )),0)
# 8575 "libc.h"
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
# 8608 "libc.h" 3 4
                                                   (-1)
# 8608 "libc.h"
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

size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream) __attribute__((weak,alias("fwrite_unlocked")));






int printf(const char *format,...)
{
  int n;
  va_list arg_ptr;
  
# 8633 "libc.h" 3 4
 __builtin_va_start((
# 8633 "libc.h"
 arg_ptr
# 8633 "libc.h" 3 4
 ),(
# 8633 "libc.h"
 format
# 8633 "libc.h" 3 4
 ))
# 8633 "libc.h"
                          ;
  n=vprintf(format, arg_ptr);
  
# 8635 "libc.h" 3 4
 __builtin_va_end
# 8635 "libc.h"
       (arg_ptr);
  return n;
}



int putchar(int c) {
  return fputc(c,stdout);
}





int __stdio_outs(const char *s,size_t len) __attribute__((weak));
int __stdio_outs(const char *s,size_t len) {
  return (write(1,s,len)==(ssize_t)len)?1:0;
}

int puts(const char *s) {
  return (__stdio_outs(s,strlen(s)) && __stdio_outs("\n",1))?0:-1;
}







int scanf(const char *format, ...) {
  int n;
  va_list arg_ptr;
  
# 8667 "libc.h" 3 4
 __builtin_va_start((
# 8667 "libc.h"
 arg_ptr
# 8667 "libc.h" 3 4
 ),(
# 8667 "libc.h"
 format
# 8667 "libc.h" 3 4
 ))
# 8667 "libc.h"
                          ;
  n=vfscanf(stdin,format,arg_ptr);
  
# 8669 "libc.h" 3 4
 __builtin_va_end 
# 8669 "libc.h"
        (arg_ptr);
  return n;
}




# 1 "dietwarning.h" 1
# 8677 "libc.h" 2

static int set_flags(FILE *stream, int flags) {
  switch (flags) {
    case 
# 8680 "libc.h" 3 4
        0
# 8680 "libc.h"
              : stream->flags = (stream->flags & ~(8)) | 16; break;
    case 
# 8681 "libc.h" 3 4
        1
# 8681 "libc.h"
              : stream->flags = (stream->flags & ~(16)) | 8; break;
    case 
# 8682 "libc.h" 3 4
        2
# 8682 "libc.h"
              : stream->flags = stream->flags & ~(16 | 8); break;
    default: return -1;
  }
  return 0;
}

int setvbuf_unlocked(FILE *stream, char *buf, int flags, size_t size) {
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

int setvbuf(FILE *stream, char *buf, int flags, size_t size) __attribute__((weak,alias("setvbuf_unlocked")));


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
# 8722 "libc.h" 3 4
    {{0},0,PTHREAD_MUTEX_RECURSIVE_NP,0}
# 8722 "libc.h"
                                          ,

};

FILE *stderr=&__stderr;

int __fflush_stderr(void) {
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
# 8745 "libc.h" 3 4
    {{0},0,PTHREAD_MUTEX_RECURSIVE_NP,0}
# 8745 "libc.h"
                                          ,

};

int __stdin_is_tty() {
  static int iknow;
  if (!iknow) iknow=isatty(0)+1;
  return (iknow-1);
}

FILE *stdin=&__stdin;

int __fflush_stdin(void) {
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
# 8774 "libc.h" 3 4
    {{0},0,PTHREAD_MUTEX_RECURSIVE_NP,0}
# 8774 "libc.h"
                                          ,

};

FILE *stdout=&__stdout;

int __fflush_stdout(void) {
  return fflush(stdout);
}
# 8791 "libc.h"
FILE *tmpfile_unlocked(void) {
  int fd;
  char template[20] = "/tmp/tmpfile-XXXXXX";
  if ((fd=mkstemp(template))<0)
    return 0;
  unlink(template);
  return __stdio_init_file(fd,1,
# 8797 "libc.h" 3 4
                               0x0002
# 8797 "libc.h"
                                     );
}

FILE *tmpfile(void) __attribute__((weak,alias("tmpfile_unlocked")));


int ungetc_unlocked(int c, FILE *stream) {
  if (stream->ungotten || c<0 || c>255)
    return 
# 8805 "libc.h" 3 4
          (-1)
# 8805 "libc.h"
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

int ungetc(int c, FILE *stream) __attribute__((weak,alias("ungetc_unlocked")));






static int __fwrite(const void*ptr, size_t nmemb, void* cookie) {
  return write((uintptr_t)cookie,ptr,nmemb);
}

int vfdprintf(int fd, const char *format, va_list arg_ptr)
{
  struct arg_printf ap = { (void*)(long)fd, __fwrite };
  return __v_printf(&ap,format,arg_ptr);
}






static int __fwrite(const void*ptr, size_t nmemb, void* cookie) {
  return fwrite(ptr,1,nmemb,(FILE*)cookie);
}

int vfprintf(FILE *stream, const char *format, va_list arg_ptr)
{
  struct arg_printf ap = { stream, __fwrite };
  return __v_printf(&ap,format,arg_ptr);
}






int vfscanf(FILE *stream, const char *format, va_list arg_ptr)
{
  struct arg_scanf farg = { (void*)stream, (int(*)(void*))fgetc, (int(*)(int,void*))ungetc };
  return __v_scanf(&farg,format,arg_ptr);
}




int __stdio_outs(const void *s,size_t len,void* cookie) __attribute__((weak));
int __stdio_outs(const void *s,size_t len,void* cookie) {
  (void)cookie;
  return (write(1,s,len)==(ssize_t)len)?1:0;
}

int vprintf(const char *format, va_list ap)
{
  struct arg_printf _ap = { 0, __stdio_outs };
  return __v_printf(&_ap,format,ap);
}







int vscanf(const char *format, va_list arg_ptr)
{
  return vfscanf(stdin,format,arg_ptr);
}
# 8895 "libc.h"
sigset_t *__utmp_block_signals (sigset_t *oldset);

sigset_t *
__utmp_block_signals (sigset_t *oldset)
{
    sigset_t blockset;



    sigfillset (&blockset);




    sigdelset (&blockset, 
# 8909 "libc.h" 3 4
                         4
# 8909 "libc.h"
                               );
    sigdelset (&blockset, 
# 8910 "libc.h" 3 4
                         5
# 8910 "libc.h"
                                );
    sigdelset (&blockset, 
# 8911 "libc.h" 3 4
                         6
# 8911 "libc.h"
                                );
    sigdelset (&blockset, 
# 8912 "libc.h" 3 4
                         6
# 8912 "libc.h"
                               );
    sigdelset (&blockset, 
# 8913 "libc.h" 3 4
                         8
# 8913 "libc.h"
                               );
    sigdelset (&blockset, 
# 8914 "libc.h" 3 4
                         11
# 8914 "libc.h"
                                );



    sigdelset (&blockset, 
# 8918 "libc.h" 3 4
                         10
# 8918 "libc.h"
                               );


    sigdelset (&blockset, 
# 8921 "libc.h" 3 4
                         7
# 8921 "libc.h"
                               );


    sigdelset (&blockset, 
# 8924 "libc.h" 3 4
                         12
# 8924 "libc.h"
                               );


    if (sigprocmask (
# 8927 "libc.h" 3 4
                    1
# 8927 "libc.h"
                             , &blockset, oldset) < 0)
 oldset = (sigset_t *)0;

    return oldset;
}




void *__utmp_io(int fd, void *ut, ssize_t len, off_t *offset, int type);


void *
__utmp_io(int fd, void *ut, ssize_t len, off_t *offset, int type) {
  int e, ret;
  struct flock fl;
  off_t newoffset;

  fl.l_whence = 
# 8945 "libc.h" 3 4
               1
# 8945 "libc.h"
                       ;
  fl.l_start = 0;
  fl.l_len = len;
  fl.l_pid = 0;
  fl.l_type = type;

  if (fcntl(fd, 
# 8951 "libc.h" 3 4
               7
# 8951 "libc.h"
                       , &fl)) return 0;
  if (type == 
# 8952 "libc.h" 3 4
             1
# 8952 "libc.h"
                    ) {
      ret = write(fd, ut, len);
      e = errno;
      fsync (fd);

      newoffset = lseek (fd, 0, 
# 8957 "libc.h" 3 4
                               1
# 8957 "libc.h"
                                       );
   } else {
      newoffset = lseek (fd, 0, 
# 8959 "libc.h" 3 4
                               1
# 8959 "libc.h"
                                       );
      ret = read(fd, ut, len);
      e = errno;
  }

  fl.l_start = -(len);
  fl.l_type = 
# 8965 "libc.h" 3 4
             2
# 8965 "libc.h"
                    ;

  fcntl(fd, 
# 8967 "libc.h" 3 4
           6
# 8967 "libc.h"
                  , &fl);



  if (offset)
      *offset = newoffset;

  errno = e;
  if (ret != len)
      return (void *)0;
  return ut;
}


# 1 "include/mntent.h" 1 3 4
# 25 "include/mntent.h" 3 4




# 28 "include/mntent.h" 3 4
struct mntent
  {
    char *mnt_fsname;
    char *mnt_dir;
    char *mnt_type;
    char *mnt_opts;
    int mnt_freq;
    int mnt_passno;
  };




 FILE *setmntent (const char *file, const char *mode) __attribute__((__nothrow__ , __leaf__));




 struct mntent *getmntent (FILE* stream) __attribute__((__nothrow__ , __leaf__));
# 58 "include/mntent.h" 3 4
 int addmntent (FILE* stream,
        const struct mntent* mnt) __attribute__((__nothrow__ , __leaf__));


 int endmntent (FILE *stream) __attribute__((__nothrow__ , __leaf__));



 char *hasmntopt (const struct mntent *__mnt,
   const char *opt) __attribute__((__nothrow__ , __leaf__));



# 8982 "libc.h" 2








# 8989 "libc.h"
int addmntent(FILE*filep,const struct mntent*mnt) {
  struct mntent m=*mnt;
  char buf[2048];
  if (strlen(m.mnt_opts)==0) m.mnt_opts="rw";
  if (snprintf(buf,sizeof(buf),"%s %s %s %s %d %d\n",
  m.mnt_fsname,m.mnt_dir,m.mnt_type,m.mnt_opts,
  m.mnt_freq,m.mnt_passno)>=(int)sizeof(buf)) return 1;
  if (fputs(buf,filep)==
# 8996 "libc.h" 3 4
                       (-1)
# 8996 "libc.h"
                          ) return 1;
  return 0;
}



static char buf[26];

char *asctime(const struct tm *timeptr) {
  return asctime_r(timeptr,buf);
}


static const char days[] = "Sun Mon Tue Wed Thu Fri Sat ";
static const char months[] = "Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec ";

static void num2str(char *c,int i) {
  c[0]=i/10+'0';
  c[1]=i%10+'0';
}

char *asctime_r(const struct tm *t, char *buf) {

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




# 1 "dietwarning.h" 1
# 9042 "libc.h" 2

int asprintf(char **s, const char *format,...)
{
  int n;
  va_list arg_ptr;
  char tmp[8];
  
# 9048 "libc.h" 3 4
 __builtin_va_start((
# 9048 "libc.h"
 arg_ptr
# 9048 "libc.h" 3 4
 ),(
# 9048 "libc.h"
 format
# 9048 "libc.h" 3 4
 ))
# 9048 "libc.h"
                          ;
  n=vsnprintf(tmp,0,format,arg_ptr);
  
# 9050 "libc.h" 3 4
 __builtin_va_start((
# 9050 "libc.h"
 arg_ptr
# 9050 "libc.h" 3 4
 ),(
# 9050 "libc.h"
 format
# 9050 "libc.h" 3 4
 ))
# 9050 "libc.h"
                           ;
  if ((*s=malloc(n+1))) {
    n=vsnprintf(*s,n+1,format,arg_ptr);
    return n;
  }
  return -1;
}


char *ctime(const time_t *timep) {
  return asctime(localtime(timep));
}


char *ctime_r(const time_t *timep, char* buf) {
  return asctime_r(localtime(timep),buf);
}

# 1 "./lib/../dietwarning.h" 1
# 1 "./lib/../dietfeatures.h" 1
# 2 "./lib/../dietwarning.h" 2
# 9069 "libc.h" 2

double difftime(time_t time1, time_t time2) {
    return (double)time1 - (double)time2;
}

asm (".section .gnu.warning." "difftime" "\n\t.string \"" "warning: difftime introduces an unnecessary floating point dependency. Don't use it!" "\"\n\t.previous");





int dirfd(DIR* dirp) {
  return dirp->fd;
}



int endmntent(FILE *filep) {
  fclose(filep);
  return 1;
}

# 1 "include/sys/syslog.h" 1 3 4







# 85 "include/sys/syslog.h" 3 4

# 85 "include/sys/syslog.h" 3 4
void openlog (const char *ident, int option, int facility);

void closelog (void) __attribute__((__nothrow__ , __leaf__));

int setlogmask (int mask) __attribute__((__nothrow__ , __leaf__));

void syslog (int priority, const char *format, ...) __attribute__((__nothrow__ , __leaf__));

void vsyslog (int priority, const char *format, va_list arg_ptr) __attribute__((__nothrow__ , __leaf__));


typedef struct _code {
  const char *const c_name;
  int c_val;
} CODE;

 CODE prioritynames[];
 CODE facilitynames[];


# 9092 "libc.h" 2






# 9097 "libc.h"
CODE facilitynames[] =
  {
    { "auth", 
# 9099 "libc.h" 3 4
             (4<<3) 
# 9099 "libc.h"
                      },
    { "authpriv", 
# 9100 "libc.h" 3 4
                 (10<<3) 
# 9100 "libc.h"
                              },
    { "cron", 
# 9101 "libc.h" 3 4
             (9<<3) 
# 9101 "libc.h"
                      },
    { "daemon", 
# 9102 "libc.h" 3 4
               (3<<3) 
# 9102 "libc.h"
                          },
    { "ftp", 
# 9103 "libc.h" 3 4
            (11<<3) 
# 9103 "libc.h"
                    },
    { "kern", 
# 9104 "libc.h" 3 4
             (0<<3) 
# 9104 "libc.h"
                      },
    { "lpr", 
# 9105 "libc.h" 3 4
            (6<<3) 
# 9105 "libc.h"
                    },
    { "mail", 
# 9106 "libc.h" 3 4
             (2<<3) 
# 9106 "libc.h"
                      },
    { "mark", 0x300 },
    { "news", 
# 9108 "libc.h" 3 4
             (7<<3) 
# 9108 "libc.h"
                      },
    { "security", 
# 9109 "libc.h" 3 4
                 (4<<3) 
# 9109 "libc.h"
                          },
    { "syslog", 
# 9110 "libc.h" 3 4
               (5<<3) 
# 9110 "libc.h"
                          },
    { "user", 
# 9111 "libc.h" 3 4
             (1<<3) 
# 9111 "libc.h"
                      },
    { "uucp", 
# 9112 "libc.h" 3 4
             (8<<3) 
# 9112 "libc.h"
                      },
    { "local0", 
# 9113 "libc.h" 3 4
               (16<<3) 
# 9113 "libc.h"
                          },
    { "local1", 
# 9114 "libc.h" 3 4
               (17<<3) 
# 9114 "libc.h"
                          },
    { "local2", 
# 9115 "libc.h" 3 4
               (18<<3) 
# 9115 "libc.h"
                          },
    { "local3", 
# 9116 "libc.h" 3 4
               (19<<3) 
# 9116 "libc.h"
                          },
    { "local4", 
# 9117 "libc.h" 3 4
               (20<<3) 
# 9117 "libc.h"
                          },
    { "local5", 
# 9118 "libc.h" 3 4
               (21<<3) 
# 9118 "libc.h"
                          },
    { "local6", 
# 9119 "libc.h" 3 4
               (22<<3) 
# 9119 "libc.h"
                          },
    { "local7", 
# 9120 "libc.h" 3 4
               (23<<3) 
# 9120 "libc.h"
                          },
    { 0, -1 }
  };



void freeaddrinfo(struct addrinfo *res) {
  while (res) {
    struct addrinfo *duh;
    duh=res;
    res=res->ai_next;
    free(duh);
  }
}

# 1 "include/sys/timeb.h" 1 3 4








# 8 "include/sys/timeb.h" 3 4
struct timeb {
  time_t time;
  unsigned short millitm;
  short timezone;
  short dstflag;
};

int ftime(struct timeb *tp);


# 9136 "libc.h" 2



# 9138 "libc.h"
int ftime(struct timeb *tp) {
  struct timeval tv;
  struct timezone tz;
  int ret=gettimeofday(&tv,&tz);
  tp->time = tv.tv_sec;
  tp->millitm = tv.tv_usec/1000;
  tp->timezone = tz.tz_minuteswest;
  tp->dstflag = tz.tz_dsttime;
  return ret;
}



const char* gai_strerror(int error) {
  switch (error) {
  case 
# 9153 "libc.h" 3 4
      -1
# 9153 "libc.h"
                : return "family not supported";
  case 
# 9154 "libc.h" 3 4
      -2
# 9154 "libc.h"
                  : return "socket type not supported";
  case 
# 9155 "libc.h" 3 4
      -4
# 9155 "libc.h"
                : return "unknown host";
  case 
# 9156 "libc.h" 3 4
      -5
# 9156 "libc.h"
                 : return "unknown service";
  case 
# 9157 "libc.h" 3 4
      -8
# 9157 "libc.h"
                : return "memory allocation failure";
  case 
# 9158 "libc.h" 3 4
      -10
# 9158 "libc.h"
               : return "temporary failure";
  }
  return "DNS error. Sorry.";
}





# 1 "include/netdb.h" 1 3 4







# 18 "include/netdb.h" 3 4

# 18 "include/netdb.h" 3 4
struct servent {
  char *s_name;
  char **s_aliases;
  int s_port;
  char *s_proto;
};

 void endservent (void) __attribute__((__nothrow__ , __leaf__));
 void setservent(int stayopen) __attribute__((__nothrow__ , __leaf__));

 int getservent_r(struct servent *res, char *buf, size_t buflen,
    struct servent **res_sig) __attribute__((__nothrow__ , __leaf__));
 int getservbyname_r(const char* name,const char* proto,
      struct servent *res, char *buf, size_t buflen,
      struct servent **res_sig) __attribute__((__nothrow__ , __leaf__));
 int getservbyport_r(int port,const char* proto,
      struct servent *res, char *buf, size_t buflen,
      struct servent **res_sig) __attribute__((__nothrow__ , __leaf__));

 struct servent *getservent(void) __attribute__((__nothrow__ , __leaf__));
 struct servent *getservbyname (const char *__name,
          const char *__proto) __attribute__((__nothrow__ , __leaf__));
 struct servent *getservbyport (int __port, const char *__proto)
     __attribute__((__nothrow__ , __leaf__));

struct hostent {
  char *h_name;
  char **h_aliases;
  int h_addrtype;
  socklen_t h_length;
  char **h_addr_list;

};

 void endhostent (void) __attribute__((__nothrow__ , __leaf__));
 struct hostent *gethostent (void) __attribute__((__nothrow__ , __leaf__));
 struct hostent *gethostent_r (char* buf,int len) __attribute__((__nothrow__ , __leaf__));
 struct hostent *gethostbyaddr (const void *__addr, socklen_t __len,
          int __type) __attribute__((__nothrow__ , __leaf__));
 struct hostent *gethostbyname (const char *__name) __attribute__((__nothrow__ , __leaf__));
 struct hostent *gethostbyname2 (const char *__name, int __af) __attribute__((__nothrow__ , __leaf__));



 int gethostbyname_r(const char* NAME, struct hostent* RESULT_BUF,char* BUF,
      size_t BUFLEN, struct hostent** RESULT,
      int* H_ERRNOP) __attribute__((__nothrow__ , __leaf__));







 int gethostbyaddr_r(const char* addr, size_t length, int format,
      struct hostent* result, char *buf, size_t buflen,
      struct hostent **RESULT, int *h_errnop) __attribute__((__nothrow__ , __leaf__));

int gethostbyname2_r(const char* name, int AF, struct hostent* result,
      char *buf, size_t buflen,
      struct hostent **RESULT, int *h_errnop) __attribute__((__nothrow__ , __leaf__));

struct protoent {
  char *p_name;
  char **p_aliases;
  int p_proto;
};

struct protoent *getprotoent(void) __attribute__((__nothrow__ , __leaf__));
struct protoent *getprotobyname(const char *name) __attribute__((__nothrow__ , __leaf__));
struct protoent *getprotobynumber(int proto) __attribute__((__nothrow__ , __leaf__));
void setprotoent(int stayopen) __attribute__((__nothrow__ , __leaf__));
void endprotoent(void) __attribute__((__nothrow__ , __leaf__));

int getprotoent_r(struct protoent *res, char *buf, size_t buflen,
    struct protoent **res_sig) __attribute__((__nothrow__ , __leaf__));
int getprotobyname_r(const char* name,
       struct protoent *res, char *buf, size_t buflen,
       struct protoent **res_sig) __attribute__((__nothrow__ , __leaf__));
int getprotobynumber_r(int proto,
        struct protoent *res, char *buf, size_t buflen,
        struct protoent **res_sig) __attribute__((__nothrow__ , __leaf__));


void sethostent(int stayopen) __attribute__((__nothrow__ , __leaf__));


 int h_errno;

struct netent {
  char *n_name;
  char **n_aliases;
  int n_addrtype;
  unsigned long int n_net;
};

struct netent *getnetbyaddr(unsigned long net, int type) __attribute__((__nothrow__ , __leaf__));
void endnetent(void) __attribute__((__nothrow__ , __leaf__));
void setnetent(int stayopen) __attribute__((__nothrow__ , __leaf__));
struct netent *getnetbyname(const char *name) __attribute__((__nothrow__ , __leaf__));
struct netent *getnetent(void) __attribute__((__nothrow__ , __leaf__));

 const char *hstrerror (int err_num) __attribute__((__nothrow__ , __leaf__));
void herror(const char *s) __attribute__((__nothrow__ , __leaf__));





# 9168 "libc.h" 2

# 1 "include/arpa/inet.h" 1 3 4









int inet_aton(const char* cp, struct in_addr* inp) __attribute__((__nothrow__ , __leaf__));
unsigned long int inet_addr(const char* cp) __attribute__((__nothrow__ , __leaf__));
unsigned long int inet_network(const char* cp) __attribute__((__nothrow__ , __leaf__));
char* inet_ntoa(struct in_addr in) __attribute__((__nothrow__ , __leaf__));
char* inet_ntoa_r(struct in_addr in,char* buf) __attribute__((__nothrow__ , __leaf__));
struct in_addr inet_makeaddr(int net, int host) __attribute__((__nothrow__ , __leaf__));
unsigned long int inet_lnaof(struct in_addr in) __attribute__((__nothrow__ , __leaf__));
unsigned long int inet_netof(struct in_addr in) __attribute__((__nothrow__ , __leaf__));

int inet_pton (int AF, const char* CP, void* BUF) __attribute__((__nothrow__ , __leaf__));
const char* inet_ntop (int AF, const void* CP, char* BUF, size_t LEN) __attribute__((__nothrow__ , __leaf__));


# 9170 "libc.h" 2



 
# 9173 "libc.h"
      int __dns_plugplay_interface;




int getaddrinfo(const char *node, const char *service, const struct addrinfo *hints, struct addrinfo **res) {
  struct addrinfo **tmp;
  int family;
  int error=
# 9181 "libc.h" 3 4
           -4
# 9181 "libc.h"
                     ;
  int flags=0;
  tmp=res; *res=0;
  if (hints) {
    if (hints->ai_family && hints->ai_family != 
# 9185 "libc.h" 3 4
                                               10 
# 9185 "libc.h"
                                                        && hints->ai_family != 
# 9185 "libc.h" 3 4
                                                                               2
# 9185 "libc.h"
                                                                                      ) return 
# 9185 "libc.h" 3 4
                                                                                               -1
# 9185 "libc.h"
                                                                                                         ;
    if (hints->ai_socktype && hints->ai_socktype != 
# 9186 "libc.h" 3 4
                                                   2 
# 9186 "libc.h"
                                                               && hints->ai_socktype != 
# 9186 "libc.h" 3 4
                                                                                        1
# 9186 "libc.h"
                                                                                                  ) return 
# 9186 "libc.h" 3 4
                                                                                                           -2
# 9186 "libc.h"
                                                                                                                       ;
    flags=hints->ai_flags;
    if ((flags&
# 9188 "libc.h" 3 4
              32
# 9188 "libc.h"
                         ) && hints->ai_family!=
# 9188 "libc.h" 3 4
                                                10
# 9188 "libc.h"
                                                        ) flags&=~(
# 9188 "libc.h" 3 4
                                                                   32
# 9188 "libc.h"
                                                                              |
# 9188 "libc.h" 3 4
                                                                               64
# 9188 "libc.h"
                                                                                     );
  }
  for (family=
# 9190 "libc.h" 3 4
             10
# 9190 "libc.h"
                     ; ; family=
# 9190 "libc.h" 3 4
                                2
# 9190 "libc.h"
                                       ) {
    if (!hints || hints->ai_family==family || hints->ai_family==
# 9191 "libc.h" 3 4
                                                               0 
# 9191 "libc.h"
                                                                         || (flags&(
# 9191 "libc.h" 3 4
                                                                                    32
# 9191 "libc.h"
                                                                                               |
# 9191 "libc.h" 3 4
                                                                                                64
# 9191 "libc.h"
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
# 9202 "libc.h" 3 4
            10 
# 9202 "libc.h"
                     && inet_pton(
# 9202 "libc.h" 3 4
                                  2
# 9202 "libc.h"
                                         ,node,buf)) continue;
 if (inet_pton(family,node,buf)>0) {
   h.h_name=(char*)node;
   h.h_addr_list[0]=buf;
   lookupok=1;
 } else if (!(flags&
# 9207 "libc.h" 3 4
                   1
# 9207 "libc.h"
                                 ) &&
     !gethostbyname2_r(node,family,&h,buf,4096,&H,&herrno)) {
   lookupok=1;
 } else {
   if (herrno==
# 9211 "libc.h" 3 4
              2
# 9211 "libc.h"
                       ) { freeaddrinfo(*res); return 
# 9211 "libc.h" 3 4
                                                      -10
# 9211 "libc.h"
                                                               ; }
 }
      } else {
 h.h_name=0;
 h.h_addr_list[0]=buf;
 interface=0;
 memset(buf,0,16);
 if (!(flags&
# 9218 "libc.h" 3 4
            4
# 9218 "libc.h"
                      )) {
   if (family==
# 9219 "libc.h" 3 4
              2
# 9219 "libc.h"
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
# 9244 "libc.h" 3 4
                             10
# 9244 "libc.h"
                                     ?sizeof(struct sockaddr_in6):sizeof(struct sockaddr_in);
   foo->ai.ai_addr=(struct sockaddr*)&foo->ip;
   memset(&foo->ip,0,sizeof(foo->ip));
   foo->ip.ip6.sin6_family=foo->ai.ai_family=family;
   if (family==
# 9248 "libc.h" 3 4
              10
# 9248 "libc.h"
                      ) {
     memmove(&foo->ip.ip6.sin6_addr,h.h_addr_list[i],16);
     if (interface) foo->ip.ip6.sin6_scope_id=if_nametoindex(interface);
   } else {

     if (flags&
# 9253 "libc.h" 3 4
              32
# 9253 "libc.h"
                         ) {
       foo->ai.ai_addrlen=sizeof(struct sockaddr_in6);
       foo->ip.ip6.sin6_addr.
# 9255 "libc.h" 3 4
                            in6_u.u6_addr8
# 9255 "libc.h"
                                   [10]=foo->ip.ip6.sin6_addr.
# 9255 "libc.h" 3 4
                                                              in6_u.u6_addr8
# 9255 "libc.h"
                                                                     [11]=0xff;
       memmove(foo->ip.ip6.sin6_addr.
# 9256 "libc.h" 3 4
                                    in6_u.u6_addr8
# 9256 "libc.h"
                                           +12,h.h_addr_list[i],4);
       foo->ip.ip6.sin6_family=foo->ai.ai_family=
# 9257 "libc.h" 3 4
                                                10
# 9257 "libc.h"
                                                        ;
     } else
       memmove(&foo->ip.ip4.sin_addr,h.h_addr_list[i],4);
   }

   if (family==
# 9262 "libc.h" 3 4
              10 
# 9262 "libc.h"
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
# 9274 "libc.h" 3 4
                           2
# 9274 "libc.h"
                                      ; ; foo->ai.ai_socktype=
# 9274 "libc.h" 3 4
                                                              1
# 9274 "libc.h"
                                                                        ) {
     char* type,* x;
     if (foo->ai.ai_socktype==
# 9276 "libc.h" 3 4
                             2
# 9276 "libc.h"
                                        ) {
       if (hints && hints->ai_socktype==
# 9277 "libc.h" 3 4
                                       1
# 9277 "libc.h"
                                                 ) continue;
       foo->ai.ai_protocol=
# 9278 "libc.h" 3 4
                          IPPROTO_TCP
# 9278 "libc.h"
                                     ;
       type="tcp";
     } else {
       if (hints && hints->ai_socktype==
# 9281 "libc.h" 3 4
                                       2
# 9281 "libc.h"
                                                  ) break;
       foo->ai.ai_protocol=
# 9282 "libc.h" 3 4
                          IPPROTO_UDP
# 9282 "libc.h"
                                     ;
       type="udp";
     }
     port=htons(strtol(service?service:"0",&x,0));
     if (*x) {
       struct servent* se;
       if (!(flags&
# 9288 "libc.h" 3 4
                  8
# 9288 "libc.h"
                                ) &&
    (se=getservbyname(service,type)))
  port=se->s_port;
       else {

  error=
# 9293 "libc.h" 3 4
       -5
# 9293 "libc.h"
                  ;
  if (foo->ai.ai_socktype==
# 9294 "libc.h" 3 4
                          1
# 9294 "libc.h"
                                    ) break;
  continue;
       }
     }
     if (foo->ai.ai_family==
# 9298 "libc.h" 3 4
                           10
# 9298 "libc.h"
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
# 9309 "libc.h" 3 4
                             1
# 9309 "libc.h"
                                       ) break;
   }
   free(foo);
 }
      }
    }
    if (hints && hints->ai_family==
# 9315 "libc.h" 3 4
                                  10 
# 9315 "libc.h"
                                           && (flags&
# 9315 "libc.h" 3 4
                                                     32
# 9315 "libc.h"
                                                                ) && *res==0)
      flags|=
# 9316 "libc.h" 3 4
            64
# 9316 "libc.h"
                  ;
    if (family==
# 9317 "libc.h" 3 4
               2
# 9317 "libc.h"
                      ) break;
  }
  if (*res==0) return error;
  return 0;
error:
  freeaddrinfo(*res);
  return 
# 9323 "libc.h" 3 4
        -8
# 9323 "libc.h"
                  ;
}
# 9338 "libc.h"
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
# 9351 "libc.h" 3 4
                   "/etc/hosts"
# 9351 "libc.h"
                              ,
# 9351 "libc.h" 3 4
                               0x0000
# 9351 "libc.h"
                                       );
    if (hostfd<0) return 0;
    hostlen=lseek(hostfd,0,
# 9353 "libc.h" 3 4
                          2
# 9353 "libc.h"
                                  );
    hostmap=mmap(0,hostlen,
# 9354 "libc.h" 3 4
                          0x1
# 9354 "libc.h"
                                   |
# 9354 "libc.h" 3 4
                                    0x2
# 9354 "libc.h"
                                              ,
# 9354 "libc.h" 3 4
                                               0x02
# 9354 "libc.h"
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
# 9379 "libc.h" 3 4
                 10
# 9379 "libc.h"
                         ,pe->h_name,dest)>0) {
      pe->h_addrtype=
# 9380 "libc.h" 3 4
                    10
# 9380 "libc.h"
                            ;
      pe->h_length=16;
      dest+=16;
    } else if (inet_pton(
# 9383 "libc.h" 3 4
                        2
# 9383 "libc.h"
                               ,pe->h_name,dest)>0) {
      pe->h_addrtype=
# 9384 "libc.h" 3 4
                    2
# 9384 "libc.h"
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
# 9421 "libc.h" 3 4
       34
# 9421 "libc.h"
             ;
  goto __error;
error:
  errno=
# 9424 "libc.h" 3 4
       12
# 9424 "libc.h"
             ;
__error:
  if (hostmap!=(char*)-1) munmap(hostmap,hostlen);
  hostmap=(char*)-1;
  return 0;
}

void sethostent(int stayopen) {
  (void)stayopen;
  cur=hostmap;
}

void endhostent(void) {
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







int getnameinfo(const struct sockaddr *sa, socklen_t salen, char *host,
  size_t hostlen, char *serv, size_t servlen, int flags) {
  sa_family_t f=((struct sockaddr_storage *)sa)->ss_family;
  (void)salen;
  if (host && hostlen>0) {
    register const char*addr=(f==
# 9491 "libc.h" 3 4
                                10
# 9491 "libc.h"
                                        )?(char*)&((struct sockaddr_in6*)sa)->sin6_addr:
        (char*)&((struct sockaddr_in*)sa)->sin_addr;
    if (flags&
# 9493 "libc.h" 3 4
             2
# 9493 "libc.h"
                           ) {
      if (!inet_ntop(f,addr,host,hostlen))
 return 
# 9495 "libc.h" 3 4
       -4
# 9495 "libc.h"
                 ;
    } else {
      char buf[4096];
      struct hostent h;
      struct hostent *H;
      int herrno;
      if (gethostbyaddr_r(addr,f==
# 9501 "libc.h" 3 4
                                 10
# 9501 "libc.h"
                                         ?16:4,f,&h,buf,4096,&H,&herrno)) {
 switch (herrno) {
 case 
# 9503 "libc.h" 3 4
     2
# 9503 "libc.h"
              : return 
# 9503 "libc.h" 3 4
                       -10
# 9503 "libc.h"
                                ;
 case 
# 9504 "libc.h" 3 4
     5
# 9504 "libc.h"
            :
 case 
# 9505 "libc.h" 3 4
     1
# 9505 "libc.h"
                   : return 
# 9505 "libc.h" 3 4
                            -4
# 9505 "libc.h"
                                      ;
 }
      }
      strncpy(host,h.h_name,hostlen-1);
      host[hostlen-1]=0;
    }
  }
  if (serv && servlen>0) {
    register short int port=(f==
# 9513 "libc.h" 3 4
                               10
# 9513 "libc.h"
                                       )?((struct sockaddr_in6*)sa)->sin6_port:((struct sockaddr_in*)sa)->sin_port;
    if (flags&
# 9514 "libc.h" 3 4
             8
# 9514 "libc.h"
                           ) {
      __ltostr(serv,servlen,ntohs(port),10,0);
    } else {
      struct servent *s;
      if (!(s=getservbyport(port,flags&
# 9518 "libc.h" 3 4
                                      16
# 9518 "libc.h"
                                              ?"udp":"tcp")))
 return 
# 9519 "libc.h" 3 4
       -5
# 9519 "libc.h"
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





# 1 "parselib.h" 1





struct state {
  const char* buffirst;
  size_t buflen;
  size_t cur;
};


void __prepare_parse(const char* filename,struct state* s);

void __fprepare_parse(int fd, struct state* s);

void __end_parse(struct state* s);



size_t __parse(struct state* s,int (*pred)(int ch));

size_t __parse_ws(struct state* s);
size_t __parse_nws(struct state* s);
size_t __parse_1(struct state* s,char c) __attribute__((__pure__));

size_t scan_ulong(const char* s,unsigned long* l);
# 9596 "libc.h" 2

static struct state __ps;

void setprotoent(int stayopen) {
  (void)stayopen;
  __prepare_parse(
# 9601 "libc.h" 3 4
                 "/etc/protocols"
# 9601 "libc.h"
                                ,&__ps);
}

void endprotoent(void) {
  __end_parse(&__ps);
}




int getprotoent_r(struct protoent *res, char *buf, size_t buflen,
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






# 1 "parselib.h" 1





struct state {
  const char* buffirst;
  size_t buflen;
  size_t cur;
};


void __prepare_parse(const char* filename,struct state* s);

void __fprepare_parse(int fd, struct state* s);

void __end_parse(struct state* s);



size_t __parse(struct state* s,int (*pred)(int ch));

size_t __parse_ws(struct state* s);
size_t __parse_nws(struct state* s);
size_t __parse_1(struct state* s,char c) __attribute__((__pure__));

size_t scan_ulong(const char* s,unsigned long* l);
# 9740 "libc.h" 2

static struct state __ps;

void setservent(int stayopen) {
  (void)stayopen;
  __prepare_parse(
# 9745 "libc.h" 3 4
                 "/etc/services"
# 9745 "libc.h"
                               ,&__ps);
}

void endservent(void) {
  __end_parse(&__ps);
}




int getservent_r(struct servent *res, char *buf, size_t buflen,
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






int grantpt (int fd) {
  struct stat st;
  if ((fstat(fd, &st))<0) return -1;
  if ((chmod((char*)ptsname(fd), st.st_mode | 
# 9874 "libc.h" 3 4
                                             00400 
# 9874 "libc.h"
                                                     | 
# 9874 "libc.h" 3 4
                                                       00200 
# 9874 "libc.h"
                                                               | 
# 9874 "libc.h" 3 4
                                                                 00020
# 9874 "libc.h"
                                                                        ))<0)
    return -1;
  return 0;
}



char *hasmntopt(const struct mntent *mnt, const char *opt) {
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


# 1 "dieticonv.h" 1
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




# 1 "include/iconv.h" 1 3 4










# 10 "include/iconv.h" 3 4
typedef uint32_t iconv_t;



 iconv_t iconv_open (const char *tocode, const char *fromcode) __attribute__((__nothrow__ , __leaf__));




 size_t iconv (iconv_t cd, char** inbuf,
       size_t* inbytesleft,
       char** outbuf,
       size_t* outbytesleft) __attribute__((__nothrow__ , __leaf__));


 int iconv_close (iconv_t cd) __attribute__((__nothrow__ , __leaf__));


# 16 "dieticonv.h" 2
# 9899 "libc.h" 2



# 9901 "libc.h"
static unsigned int utf8bounds[]={0x7f,0x7ff,0xffff,0x1fffff,0x3ffffff,0x7fffffff};

size_t iconv(iconv_t cd, char* * inbuf, size_t *
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
# 9921 "libc.h" 3 4
      22
# 9921 "libc.h"
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
# 9961 "libc.h" 3 4
           88
# 9961 "libc.h"
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
# 10019 "libc.h" 3 4
      7
# 10019 "libc.h"
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





# 1 "dieticonv.h" 1
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
# 10081 "libc.h" 2

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

iconv_t iconv_open(const char* tocode, const char* fromcode) {
  int f,t;

  f=parsecharset(fromcode);
  t=parsecharset(tocode);

  if (f==INVALID || t==INVALID) {
    errno=
# 10101 "libc.h" 3 4
         22
# 10101 "libc.h"
               ;
    return (iconv_t)(-1);
  }
  return (f|t<<16);
}

# 1 "dieticonv.h" 1
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
# 10108 "libc.h" 2

int iconv_close(iconv_t cd) {
  (void)cd;
  return 0;
}


int __isleap(int year) {



  return (!(year%4) && ((year%100) || !(year%400)));
}



int iswctype(wint_t wc, wctype_t desc) {
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
# 10167 "libc.h"
# 1 "include/syslog.h" 1 3 4
# 10168 "libc.h" 2
# 10179 "libc.h"
int __libc_open(const char*name,int flags, ...);
ssize_t __libc_write(int fd,void*buf,size_t len);
int __libc_fcntl(int fd,int op,...);
int __libc_close(int fd);


static volatile int connected;
static volatile int LogMask = 0xff;
static char LogTag[1000];
static int LogFile = -1;
static int LogType = 
# 10189 "libc.h" 3 4
                     1
# 10189 "libc.h"
                               ;
static int LogFacility = 
# 10190 "libc.h" 3 4
                         (1<<3)
# 10190 "libc.h"
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

void __libc_closelog(void);
void __libc_closelog(void)
{
  closelog_intern();

  LogTag[0]=0;
  LogType = 
# 10209 "libc.h" 3 4
           1
# 10209 "libc.h"
                     ;
}
void closelog(void) __attribute__((weak,alias("__libc_closelog")));

static void openlog_intern(int option, int facility)
{
  LogStat = option;
  if (facility && ((facility & ~
# 10216 "libc.h" 3 4
                               0x03f8
# 10216 "libc.h"
                                          ) == 0))
    LogFacility = facility;


  while(1) {
    if (LogFile == -1) {
      SyslogAddr.sa_family = 
# 10222 "libc.h" 3 4
                            1
# 10222 "libc.h"
                                   ;
      strncpy(SyslogAddr.sa_data, 
# 10223 "libc.h" 3 4
                                 "/dev/log"
# 10223 "libc.h"
                                          , sizeof(SyslogAddr.sa_data));
      if (LogStat & 
# 10224 "libc.h" 3 4
                   0x08
# 10224 "libc.h"
                             )
      {
 if ((LogFile = socket(
# 10226 "libc.h" 3 4
                      1
# 10226 "libc.h"
                             , LogType, 0)) == -1) return;
 __libc_fcntl(LogFile, 
# 10227 "libc.h" 3 4
                      2
# 10227 "libc.h"
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
# 10236 "libc.h" 3 4
               1
# 10236 "libc.h"
                         ) && (saved_errno == 
# 10236 "libc.h" 3 4
                                              98
# 10236 "libc.h"
                                                        )) {

   LogType = 
# 10238 "libc.h" 3 4
            2
# 10238 "libc.h"
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


void __libc_openlog(const char *ident, int option, int facility);
void __libc_openlog(const char *ident, int option, int facility)
{
  if (ident) {
    strncpy(LogTag,ident,1000);
    LogTag[1000 -1]=0;
  }
  openlog_intern(option, facility);
}
void openlog(const char *ident, int option, int facility) __attribute__((weak,alias("__libc_openlog")));

int setlogmask(int mask)
{
  int old = LogMask;
  if (mask) LogMask = mask;
  return old;
}

void __libc_vsyslog(int priority, const char *format, va_list arg_ptr);
void __libc_vsyslog(int priority, const char *format, va_list arg_ptr)
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
# 10283 "libc.h" 3 4
                  0x07
# 10283 "libc.h"
                             |
# 10283 "libc.h" 3 4
                              0x03f8
# 10283 "libc.h"
                                         )) {
    syslog(
# 10284 "libc.h" 3 4
          3
# 10284 "libc.h"
                 |
# 10284 "libc.h" 3 4
                  0x02
# 10284 "libc.h"
                          |
# 10284 "libc.h" 3 4
                           0x20
# 10284 "libc.h"
                                     |
# 10284 "libc.h" 3 4
                                      0x01
# 10284 "libc.h"
                                             , "syslog: unknown facility/priorityority: %x", priority);
    priority &= 
# 10285 "libc.h" 3 4
               0x07
# 10285 "libc.h"
                          |
# 10285 "libc.h" 3 4
                           0x03f8
# 10285 "libc.h"
                                      ;
  }


  if ((
# 10289 "libc.h" 3 4
      (1 << (((
# 10289 "libc.h"
      priority
# 10289 "libc.h" 3 4
      ) & 0x07))) 
# 10289 "libc.h"
                                  && LogMask) == 0) return;


  if ((priority & 
# 10292 "libc.h" 3 4
                 0x03f8
# 10292 "libc.h"
                            ) == 0) priority |= LogFacility;

  pid = getpid();
  time(&now);
  strftime(time_buf, 20, "%h %e %T", localtime_r (&now, &now_tm));

  if (LogStat & 
# 10298 "libc.h" 3 4
               0x01
# 10298 "libc.h"
                      )
    headerlen = snprintf(buffer, 130, "<%d>%s %s[%ld]: ", priority, time_buf, LogTag, (long) pid);
  else
    headerlen = snprintf(buffer, 130, "<%d>%s %s: ", priority, time_buf, LogTag);

  if (!LogTag[0]) {
    if ((LogStat & 
# 10304 "libc.h" 3 4
                  0x01
# 10304 "libc.h"
                         ) != 
# 10304 "libc.h" 3 4
                              0x01
# 10304 "libc.h"
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
# 10313 "libc.h" 3 4
               0x20
# 10313 "libc.h"
                         ) {
    __libc_write(1, buffer+headerlen, buflen);
    if (buffer[headerlen+buflen] != '\n') __libc_write(1,"\n", 1);
  }


  memset(&action, 0, sizeof(action));
  action.
# 10320 "libc.h" 3 4
        _u._sa_handler 
# 10320 "libc.h"
                   = 
# 10320 "libc.h" 3 4
                     ((sighandler_t)1L)
# 10320 "libc.h"
                            ;
  sigemptyset(&action.sa_mask);

  sigpipe = sigaction (
# 10323 "libc.h" 3 4
                      13
# 10323 "libc.h"
                             , &action, &oldaction);

  if (!connected) openlog_intern(LogStat | 
# 10325 "libc.h" 3 4
                                          0x08
# 10325 "libc.h"
                                                    , 0);



  if (LogType == 
# 10329 "libc.h" 3 4
                2
# 10329 "libc.h"
                           ) buflen++;

  if (!connected || (send(LogFile, buffer, buflen+headerlen, 0) != buflen+headerlen)) {
    if (LogType == 
# 10332 "libc.h" 3 4
                  2
# 10332 "libc.h"
                             ) buflen--;
    closelog_intern();





    if ((LogStat & 
# 10339 "libc.h" 3 4
                  0x02
# 10339 "libc.h"
                          ) &&
       ((fd = __libc_open("/dev/console", 
# 10340 "libc.h" 3 4
                                        0x0001
# 10340 "libc.h"
                                                |
# 10340 "libc.h" 3 4
                                                 0x0800
# 10340 "libc.h"
                                                         , 0)) >= 0))
    {
      __libc_write(fd, buffer, buflen+headerlen);
      __libc_write(fd, "\r\n", 2);
      __libc_close(fd);
    }
  }

  if (sigpipe == 0)
    sigaction(
# 10349 "libc.h" 3 4
             13
# 10349 "libc.h"
                    , &oldaction, (struct sigaction *) 
# 10349 "libc.h" 3 4
                                                       (void*)0
# 10349 "libc.h"
                                                           );
}
void vsyslog(int priority, const char *format, va_list arg_ptr) __attribute__((weak,alias("__libc_vsyslog")));

void syslog(int priority, const char *format, ...)
{
  va_list arg_ptr;
  
# 10356 "libc.h" 3 4
 __builtin_va_start((
# 10356 "libc.h"
 arg_ptr
# 10356 "libc.h" 3 4
 ),(
# 10356 "libc.h"
 format
# 10356 "libc.h" 3 4
 ))
# 10356 "libc.h"
                          ;
  vsyslog(priority, format, arg_ptr);
  
# 10358 "libc.h" 3 4
 __builtin_va_end
# 10358 "libc.h"
       (arg_ptr);
}
# 10368 "libc.h"
 void __maplocaltime(void);
 time_t __tzfile_map(time_t t, int *isdst, int forward);





time_t mktime(register struct tm* const t) {
  time_t x=timegm(t);

  int isdst;
  time_t y;
  __maplocaltime();
  x=__tzfile_map(x,&isdst,0);






  return x;
}

time_t timelocal(struct tm* const t) __attribute__((alias("mktime")));
# 10405 "libc.h"
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
# 10419 "libc.h" 3 4
              "/etc/networks"
# 10419 "libc.h"
                            ,
# 10419 "libc.h" 3 4
                             0x0000
# 10419 "libc.h"
                                     );
    if (netfd<0) return 0;
    fcntl (netfd, 
# 10421 "libc.h" 3 4
                 2
# 10421 "libc.h"
                        , 
# 10421 "libc.h" 3 4
                          1
# 10421 "libc.h"
                                    );
    netlen=lseek(netfd,0,
# 10422 "libc.h" 3 4
                        2
# 10422 "libc.h"
                                );
    netmap=mmap(0,netlen,
# 10423 "libc.h" 3 4
                        0x1
# 10423 "libc.h"
                                 |
# 10423 "libc.h" 3 4
                                  0x2
# 10423 "libc.h"
                                            ,
# 10423 "libc.h" 3 4
                                             0x02
# 10423 "libc.h"
                                                        ,netfd,0);
    if ((long)netmap==(-1)) goto error;
    cur=netmap;
  }
  last=netmap+netlen;
again:
  ne.n_name=0;
  ne.n_aliases=aliases; aliases[0]=0;
  ne.n_addrtype=
# 10431 "libc.h" 3 4
               2
# 10431 "libc.h"
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
# 10474 "libc.h" 3 4
       12
# 10474 "libc.h"
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

void endnetent(void) {
  if (netmap!=(char*)-1) munmap(netmap,netlen);
  if (netfd!=-1) close(netfd);
  netmap=(char*)-1;
  netfd=-1;
}

void setnetent(int stayopen) {
  (void)stayopen;
  endnetent();
}

struct netent *getnetbyname(const char *name) {
  struct netent *s;
  setnetent(0);
  for (s=getnetent(); s; s=getnetent()) {
    char **tmp;
# 10514 "libc.h"
    if (!strcmp(name,s->n_name))
      return s;
    tmp=s->n_aliases;
    while (*tmp)
      if (!strcmp(name,*tmp++)) return s;
  }
  return 0;
}


# 1 "include/pty.h" 1 3 4











 
# 12 "include/pty.h" 3 4
      int openpty (int *__amaster, int *__aslave, char *__name, struct
      termios *__termp, struct winsize *__winp) __attribute__((__nothrow__ , __leaf__));


# 10525 "libc.h" 2








# 10532 "libc.h"
int openpty(int *amaster, int *aslave, char *name, struct termios
     *termp, struct winsize *winp) {
  int fd;
  char buf[20];
# 10550 "libc.h"
  if ((fd=open("/dev/ptmx",
# 10550 "libc.h" 3 4
                          0x0002
# 10550 "libc.h"
                                ))<0) return -1;



  {
    int unlock=0;
    while (ioctl(fd,
# 10556 "libc.h" 3 4
                   (((4U) << (((0 +8)+8)+13)) | ((('T')) << (0 +8)) | (((0x31)) << 0) | (((sizeof(int)) & 0xff) << ((0 +8)+8)))
# 10556 "libc.h"
                             , &unlock)<0) if (errno!=
# 10556 "libc.h" 3 4
                                                      4
# 10556 "libc.h"
                                                           ) goto kaputt;
  }
  {
    int ptyno;
    while (ioctl(fd,
# 10560 "libc.h" 3 4
                   (((2U) << (((0 +8)+8)+13)) | ((('T')) << (0 +8)) | (((0x30)) << 0) | (((sizeof(unsigned int)) & 0xff) << ((0 +8)+8)))
# 10560 "libc.h"
                           ,&ptyno)<0) if (errno!=
# 10560 "libc.h" 3 4
                                                  4
# 10560 "libc.h"
                                                       ) goto kaputt;
    strcpy(buf,"/dev/pts/");
    __ltostr(buf+9,10,ptyno,10,0);
  }
  *aslave=open(buf,
# 10564 "libc.h" 3 4
                  0x0002
# 10564 "libc.h"
                        |
# 10564 "libc.h" 3 4
                         0x0800
# 10564 "libc.h"
                                 );
  if (*aslave<0) goto kaputt;
  *amaster=fd;
  if (name) strcpy(name,buf);
  if (termp)
    while (tcsetattr(*aslave,
# 10569 "libc.h" 3 4
                            0x5410
# 10569 "libc.h"
                                     ,termp) && errno==
# 10569 "libc.h" 3 4
                                                       4
# 10569 "libc.h"
                                                            );
  if (winp) while (ioctl(*aslave, 
# 10570 "libc.h" 3 4
                                 (((4U) << (((0 +8)+8)+13)) | ((('t')) << (0 +8)) | (((103)) << 0) | (((sizeof(struct winsize)) & 0xff) << ((0 +8)+8)))
# 10570 "libc.h"
                                           , winp) && errno==
# 10570 "libc.h" 3 4
                                                             4
# 10570 "libc.h"
                                                                  );
  return 0;
kaputt:
  close(fd);
  return -1;
}




int pclose(FILE *f) {
  int status;
  pid_t pid=f->popen_kludge;
  fclose(f);
  if (waitpid(pid,&status,0)>=0)
    return status;
  return -1;
}



# 1 "binshstr.h" 1

 const char __binsh [8];
# 10592 "libc.h" 2

 char **environ;

FILE *popen(const char *command, const char *type) {
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
# 10618 "libc.h" 3 4
                   2
# 10618 "libc.h"
                          , 
# 10618 "libc.h" 3 4
                            1
# 10618 "libc.h"
                                      );
  f->popen_kludge=pid;
  return f;
}






CODE prioritynames[] =
  {
    { "alert", 
# 10630 "libc.h" 3 4
              1 
# 10630 "libc.h"
                        },
    { "crit", 
# 10631 "libc.h" 3 4
             2 
# 10631 "libc.h"
                      },
    { "debug", 
# 10632 "libc.h" 3 4
              7 
# 10632 "libc.h"
                        },
    { "emerg", 
# 10633 "libc.h" 3 4
              0 
# 10633 "libc.h"
                        },
    { "err", 
# 10634 "libc.h" 3 4
            3 
# 10634 "libc.h"
                    },
    { "error", 
# 10635 "libc.h" 3 4
              3 
# 10635 "libc.h"
                      },
    { "info", 
# 10636 "libc.h" 3 4
             6 
# 10636 "libc.h"
                      },
    { "none", 0x10 },
    { "notice", 
# 10638 "libc.h" 3 4
               5 
# 10638 "libc.h"
                          },
    { "panic", 
# 10639 "libc.h" 3 4
              0 
# 10639 "libc.h"
                        },
    { "warn", 
# 10640 "libc.h" 3 4
             4 
# 10640 "libc.h"
                         },
    { "warning", 
# 10641 "libc.h" 3 4
                4 
# 10641 "libc.h"
                            },
    { 0, -1 }
  };


struct protoent __protoent_pw;
char __protoent_buf[1000];
# 10657 "libc.h"
char *ptsname(int fd) {
  static char buffer[9+4];
  int pty;

  strcpy(buffer,"/dev/pts/");
  if ((ioctl(fd, 
# 10662 "libc.h" 3 4
                (((2U) << (((0 +8)+8)+13)) | ((('T')) << (0 +8)) | (((0x30)) << 0) | (((sizeof(unsigned int)) & 0xff) << ((0 +8)+8)))
# 10662 "libc.h"
                        , &pty)) == -1) return 0;
  __ltostr(buffer+9, 4, pty, 10, 0);
  return buffer;
}


# 1 "include/pwd.h" 1 3 4










# 10 "include/pwd.h" 3 4
struct passwd {
  char *pw_name;
  char *pw_passwd;
  uid_t pw_uid;
  gid_t pw_gid;
  char *pw_gecos;
  char *pw_dir;
  char *pw_shell;
};

 struct passwd *getpwuid (uid_t uid) __attribute__((__nothrow__ , __leaf__));
 struct passwd *getpwnam (const char *name) __attribute__((__nothrow__ , __leaf__));

 struct passwd *getpwent(void) __attribute__((__nothrow__ , __leaf__));
 void setpwent(void) __attribute__((__nothrow__ , __leaf__));
 void endpwent(void) __attribute__((__nothrow__ , __leaf__));
 int putpwent(const struct passwd *p, FILE *stream) __attribute__((__nothrow__ , __leaf__)) ;

int getpwent_r(struct passwd *res, char *buf, size_t buflen,
        struct passwd **res_sig) __attribute__((__nothrow__ , __leaf__));
int getpwnam_r(const char* name,
        struct passwd *res, char *buf, size_t buflen,
        struct passwd **res_sig) __attribute__((__nothrow__ , __leaf__));
int getpwuid_r(uid_t uid,
        struct passwd *res, char *buf, size_t buflen,
        struct passwd **res_sig) __attribute__((__nothrow__ , __leaf__));


 struct passwd *fgetpwent(FILE * fp);
 void fsetpwent(int fd) __attribute__((__nothrow__ , __leaf__));
 int fgetpwent_r(int fd,struct passwd *res,
  char *buf, size_t buflen,
         struct passwd **res_sig);


# 10669 "libc.h" 2



# 1 "dietwarning.h" 1
# 10673 "libc.h" 2


# 10674 "libc.h"
int putpwent(const struct passwd *p, FILE *stream) {
  if (p && stream) {
    fprintf(stream,"%s:%s:%d:%d:%s:%s:%s\n", p->pw_name, p->pw_passwd,
     p->pw_uid, p->pw_gid, p->pw_gecos, p->pw_dir, p->pw_shell);
    return 0;
  }
  (*__errno_location())=
# 10680 "libc.h" 3 4
                       22
# 10680 "libc.h"
                             ;
  return -1;
}

asm (".section .gnu.warning." "putpwent" "\n\t.string \"" "putpwent is garbage, don't use!" "\"\n\t.previous");


struct servent __servent_pw;
char __servent_buf[1000];




# 1 "./dietwarning.h" 1
# 1 "./dietfeatures.h" 1
# 2 "./dietwarning.h" 2
# 10694 "libc.h" 2
asm (".section .gnu.warning." "setenv" "\n\t.string \"" "setenv calls malloc.  Avoid it in small programs." "\"\n\t.previous");;

int setenv(const char *name, const char *value, int overwrite) {
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



FILE *setmntent(const char *filename, const char *type) {
  return fopen(filename,type);
}







char *strndup(const char *s,size_t n) {





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

size_t strftime ( char* dst, size_t max, const char* format, const struct tm* tm )
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

char* strptime(const char* s,const char* format, struct tm* tm) {
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




char* strsignal(int sig) {
  if ((unsigned int)sig<=
# 11031 "libc.h" 3 4
                        (128 -1)
# 11031 "libc.h"
                                )
    return (char*)sys_siglist[sig];
  else
    return (char*)"(unknown signal)";
}




# 1 "dietwarning.h" 1
# 11041 "libc.h" 2

# 1 "binshstr.h" 1

 const char __binsh [8];
# 11043 "libc.h" 2

 char **environ;

int __libc_system (const char *line);

int __libc_system (const char *line)
{
  struct sigaction sa, intr, quit;
  sigset_t block,omask;
  int save,pid,ret=-1;

  if (line == 0) return __libc_system("exit 0") == 0;

  sa.
# 11056 "libc.h" 3 4
    _u._sa_handler 
# 11056 "libc.h"
               = 
# 11056 "libc.h" 3 4
                 ((sighandler_t)1L)
# 11056 "libc.h"
                        ;
  sa.sa_flags = 0;
  sigemptyset (&sa.sa_mask);

  if (sigaction(
# 11060 "libc.h" 3 4
               2
# 11060 "libc.h"
                     , &sa, &intr)<0) return -1;
  if (sigaction(
# 11061 "libc.h" 3 4
               3
# 11061 "libc.h"
                      , &sa, &quit)<0) {
    save = errno;
undo:
    sigaction (
# 11064 "libc.h" 3 4
              2
# 11064 "libc.h"
                    , &intr, (struct sigaction*)0);
    errno=save;
    return -1;
  }
  sigemptyset(&block);
  sigaddset(&block,
# 11069 "libc.h" 3 4
                  18
# 11069 "libc.h"
                         );
  if (sigprocmask(
# 11070 "libc.h" 3 4
                 1
# 11070 "libc.h"
                          ,&block,&omask)<0) {
    save=errno;
    sigaction (
# 11072 "libc.h" 3 4
              3
# 11072 "libc.h"
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
# 11082 "libc.h" 3 4
                             4
# 11082 "libc.h"
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
# 11093 "libc.h" 3 4
             2
# 11093 "libc.h"
                   , &intr, (struct sigaction*)0);
    sigaction(
# 11094 "libc.h" 3 4
             3
# 11094 "libc.h"
                    , &quit, (struct sigaction*)0);
    sigprocmask(
# 11095 "libc.h" 3 4
               3
# 11095 "libc.h"
                          ,&omask,0);

    execve(__binsh,(char *const *)nargs, environ);
    _exit(127);
  }
  save = errno;
  sigaction (
# 11101 "libc.h" 3 4
            2
# 11101 "libc.h"
                  , &intr, (struct sigaction *)0);
  sigaction (
# 11102 "libc.h" 3 4
            3
# 11102 "libc.h"
                   , &quit, (struct sigaction *)0);
  sigprocmask(
# 11103 "libc.h" 3 4
             3
# 11103 "libc.h"
                        ,&omask,0);
  errno=save;
  return ret;
}

int system (const char *line) __attribute__((weak,alias("__libc_system")));

asm (".section .gnu.warning." "system" "\n\t.string \"" "warning: system() is a security risk.  Use fork and execvp instead!" "\"\n\t.previous");



const short __spm[13] =
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

time_t timegm(struct tm *const t) {
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


long int timezone;
int daylight;
# 11202 "libc.h"
char* tzname[2]={"GMT","GMT"};


static unsigned char *tzfile;
static int tzlen=-1;

void __maplocaltime(void);
void __maplocaltime(void) {
  int fd;
  unsigned int len;
  if (tzlen>=0) return;
  tzlen=0;
  if ((fd=open("/etc/localtime",
# 11214 "libc.h" 3 4
                               0x0000
# 11214 "libc.h"
                                       ))<0) return;
  len=lseek(fd,0,
# 11215 "libc.h" 3 4
                2
# 11215 "libc.h"
                        );
  if ((tzfile=mmap(0,len,
# 11216 "libc.h" 3 4
                        0x1
# 11216 "libc.h"
                                 ,
# 11216 "libc.h" 3 4
                                  0x02
# 11216 "libc.h"
                                             ,fd,0))==
# 11216 "libc.h" 3 4
                                                      ((void *) -1)
# 11216 "libc.h"
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

time_t __tzfile_map(time_t t, int *isdst, int forward);
time_t __tzfile_map(time_t t, int *isdst, int forward) {

  unsigned char *tmp;
  int i;
  int tzh_timecnt, tzh_typecnt;
  *isdst=0;
  if (!tzfile) return t;
  tzh_timecnt=ntohl(*(int*)(tzfile+32));
  tzh_typecnt=ntohl(*(int*)(tzfile+36));
# 11276 "libc.h"
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

void tzset(void) {
  int isdst;
  __maplocaltime();
  __tzfile_map(time(0),&isdst,1);
}
# 11331 "libc.h"
int unlockpt (int fd) {
  int foo=0;

  return (ioctl (fd, 
# 11334 "libc.h" 3 4
                    (((4U) << (((0 +8)+8)+13)) | ((('T')) << (0 +8)) | (((0x31)) << 0) | (((sizeof(int)) & 0xff) << ((0 +8)+8)))
# 11334 "libc.h"
                              , &foo));
}


int unsetenv(const char *name) {
  return putenv(name);
}




# 1 "include/utmp.h" 1 3 4
# 9 "include/utmp.h" 3 4









# 17 "include/utmp.h" 3 4
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
# 59 "include/utmp.h" 3 4
  long int ut_session;
  struct timeval ut_tv;



  int32_t ut_addr_v6[4];
  char __unused[20];
};
# 93 "include/utmp.h" 3 4
struct utmp *getutent(void) __attribute__((__nothrow__ , __leaf__));
struct utmp *getutid(struct utmp *ut) __attribute__((__nothrow__ , __leaf__));
struct utmp *getutline(struct utmp *ut) __attribute__((__nothrow__ , __leaf__));

void pututline(struct utmp *ut) __attribute__((__nothrow__ , __leaf__));

void setutent(void) __attribute__((__nothrow__ , __leaf__));
void endutent(void) __attribute__((__nothrow__ , __leaf__));

void utmpname(const char *file) __attribute__((__nothrow__ , __leaf__));

void updwtmp(const char *wtmp_file, const struct utmp *ut);
void logwtmp(const char *line, const char *name, const char *host);


# 11346 "libc.h" 2


# 11347 "libc.h"
static const char *utmp_file_name = 
# 11347 "libc.h" 3 4
                                   "/var/run/utmp"
# 11347 "libc.h"
                                             ;
static int fd = -1;
static off_t utmp_current = 0;

static int lock_record(int type) {
  struct flock fl;
  fl.l_whence = 
# 11353 "libc.h" 3 4
               1
# 11353 "libc.h"
                       ;
  fl.l_start = 0;
  fl.l_len = sizeof(struct utmp);
  fl.l_pid = 0;
  fl.l_type = type;
  return fcntl(fd, 
# 11358 "libc.h" 3 4
                  7
# 11358 "libc.h"
                          , &fl);
}

static int unlock_record() {
  struct flock fl;
  fl.l_whence = 
# 11363 "libc.h" 3 4
               1
# 11363 "libc.h"
                       ;
  fl.l_start = -sizeof(struct utmp);
  fl.l_len = sizeof(struct utmp);
  fl.l_pid = 0;
  fl.l_type = 
# 11367 "libc.h" 3 4
             2
# 11367 "libc.h"
                    ;
  return fcntl(fd, 
# 11368 "libc.h" 3 4
                  6
# 11368 "libc.h"
                         , &fl);
}

void utmpname(const char *file) {
  if (file)
    utmp_file_name = file;
  else
    utmp_file_name = 
# 11375 "libc.h" 3 4
                    "/var/run/utmp"
# 11375 "libc.h"
                              ;
}

void setutent() {
  if (fd<0) fd = open(utmp_file_name,
# 11379 "libc.h" 3 4
                                    0x0002
# 11379 "libc.h"
                                          );
  if (fd<0) fd = open(utmp_file_name,
# 11380 "libc.h" 3 4
                                    0x0000
# 11380 "libc.h"
                                            );
  fcntl (fd, 
# 11381 "libc.h" 3 4
            2
# 11381 "libc.h"
                   , 
# 11381 "libc.h" 3 4
                     1
# 11381 "libc.h"
                               );
  utmp_current = lseek(fd,0,
# 11382 "libc.h" 3 4
                           0
# 11382 "libc.h"
                                   );
}

void endutent() {
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
# 11399 "libc.h" 3 4
                              1
# 11399 "libc.h"
                                      );
  if (lock_record(
# 11400 "libc.h" 3 4
                 0
# 11400 "libc.h"
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
# 11411 "libc.h" 3 4
                                      4
# 11411 "libc.h"
                                              )) {
      if (ut->ut_type == tmp->ut_type) break;
    }
    if ((ut->ut_type >= 
# 11414 "libc.h" 3 4
                       5
# 11414 "libc.h"
                                   ) && (ut->ut_type <= 
# 11414 "libc.h" 3 4
                                                        8
# 11414 "libc.h"
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
# 11425 "libc.h" 3 4
                        7
# 11425 "libc.h"
                                    ) || (tmp->ut_type == 
# 11425 "libc.h" 3 4
                                                          6
# 11425 "libc.h"
                                                                       )) {
      if (!strncmp(ut->ut_line,tmp->ut_line,
# 11426 "libc.h" 3 4
                                           32
# 11426 "libc.h"
                                                      )) break;
    }
  }
  return tmp;
}

void pututline(struct utmp *ut) {
  struct utmp *tmp;


  lseek (fd, utmp_current, 
# 11436 "libc.h" 3 4
                          0
# 11436 "libc.h"
                                  );
  if ((tmp = getutid(ut))) {
    lseek(fd, - (off_t)sizeof(struct utmp), 
# 11438 "libc.h" 3 4
                                           1
# 11438 "libc.h"
                                                   );
    if (lock_record(
# 11439 "libc.h" 3 4
                   1
# 11439 "libc.h"
                          )) return;
    write(fd, ut, sizeof(struct utmp));
    utmp_current += sizeof(struct utmp);
  }
  else {
    utmp_current = lseek(fd, 0, 
# 11444 "libc.h" 3 4
                               2
# 11444 "libc.h"
                                       );
    if (lock_record(
# 11445 "libc.h" 3 4
                   1
# 11445 "libc.h"
                          )) return;
    write(fd, ut, sizeof(struct utmp));
  }
  unlock_record();
}





# 1 "include/utmpx.h" 1 3 4
# 11 "include/utmpx.h" 3 4

# 11 "include/utmpx.h" 3 4
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
# 50 "include/utmpx.h" 3 4
  long int ut_session;
  struct timeval ut_tv;

  int32_t ut_addr_v6[4];
  char __unused[20];
};
# 77 "include/utmpx.h" 3 4
struct utmpx *getutxent(void);
struct utmpx *getutxid(struct utmpx *ut);
struct utmpx *getutxline(struct utmpx *ut);

struct utmpx *pututxline(struct utmpx *ut);

void setutxent(void);
void endutxent(void);


void utmpxname (const char *file);
void updwtmpx (const char *wtmpx_file, const struct utmpx *utmpx);
void getutmp (const struct utmpx *utmpx, struct utmp *utmp);
void getutmpx (const struct utmp *utmp, struct utmpx *utmpx);



# 11456 "libc.h" 2



# 11458 "libc.h"
static const char *utmp_file_name = 
# 11458 "libc.h" 3 4
                                   "/var/run/utmp"
# 11458 "libc.h"
                                              ;
static int fd = -1;
static off_t utmp_current = 0;


void *__utmp_io(int fd, void *ut, ssize_t len, off_t *offset, int type);
sigset_t *__utmp_block_signals (sigset_t *oldset);


void __utmpxname(const char *file);
void __utmpxname(const char *file) {
  if (file)
    utmp_file_name = file;
  else
    utmp_file_name = 
# 11472 "libc.h" 3 4
                    "/var/run/utmp"
# 11472 "libc.h"
                               ;
}

void setutxent() {
  sigset_t oldset, *savedset;

  savedset = __utmp_block_signals(&oldset);
  if (fd<0) fd = open(utmp_file_name,
# 11479 "libc.h" 3 4
                                    0x0002
# 11479 "libc.h"
                                          );
  if (fd<0) fd = open(utmp_file_name,
# 11480 "libc.h" 3 4
                                    0x0000
# 11480 "libc.h"
                                            );
  fcntl (fd, 
# 11481 "libc.h" 3 4
            2
# 11481 "libc.h"
                   , 
# 11481 "libc.h" 3 4
                     1
# 11481 "libc.h"
                               );
  utmp_current = lseek(fd,0,
# 11482 "libc.h" 3 4
                           0
# 11482 "libc.h"
                                   );
  if (savedset)
      sigprocmask (
# 11484 "libc.h" 3 4
                  3
# 11484 "libc.h"
                             , savedset, 0);
}

void endutxent() {
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
# 11505 "libc.h" 3 4
                     0
# 11505 "libc.h"
                            );

  if (savedset)
      sigprocmask (
# 11508 "libc.h" 3 4
                  3
# 11508 "libc.h"
                             , savedset, 0);

  return retval;
}

struct utmpx *getutxid(struct utmpx *ut) {
  struct utmpx *tmp;

  while ((tmp = getutxent())) {
    if (ut->ut_type && (ut->ut_type <= 
# 11517 "libc.h" 3 4
                                      4
# 11517 "libc.h"
                                              )) {
      if (ut->ut_type == tmp->ut_type) break;
    }
    if ((ut->ut_type >= 
# 11520 "libc.h" 3 4
                       5
# 11520 "libc.h"
                                   ) && (ut->ut_type <= 
# 11520 "libc.h" 3 4
                                                        8
# 11520 "libc.h"
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
# 11531 "libc.h" 3 4
                        7
# 11531 "libc.h"
                                    ) || (tmp->ut_type == 
# 11531 "libc.h" 3 4
                                                          6
# 11531 "libc.h"
                                                                       )) {
      if (!strncmp(ut->ut_line,tmp->ut_line,
# 11532 "libc.h" 3 4
                                           32
# 11532 "libc.h"
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
# 11552 "libc.h" 3 4
                          0
# 11552 "libc.h"
                                  );
  if ((tmp = getutxid(&ut_copy))) {
    lseek(fd, - (off_t)sizeof(struct utmpx), 
# 11554 "libc.h" 3 4
                                            1
# 11554 "libc.h"
                                                    );
    result = __utmp_io (fd, &ut_copy, sizeof(struct utmpx),
     &utmp_current, 
# 11556 "libc.h" 3 4
                   1
# 11556 "libc.h"
                          );
    e = errno;
  } else {
    utmp_current = lseek(fd, 0, 
# 11559 "libc.h" 3 4
                               2
# 11559 "libc.h"
                                       );
    result = __utmp_io (fd, &ut_copy, sizeof(struct utmpx),
     &utmp_current, 
# 11561 "libc.h" 3 4
                   1
# 11561 "libc.h"
                          );
    e = errno;
  }
  if (savedset)
      sigprocmask (
# 11565 "libc.h" 3 4
                  3
# 11565 "libc.h"
                             , savedset, 0);

  if (result) {
      retval = ut;
  }

  memcpy (ut, &ut_copy, sizeof (struct utmpx));
  errno = e;
  return retval;
}






# 1 "dietwarning.h" 1
# 11582 "libc.h" 2

int vasprintf(char **s, const char *format, va_list ap)
{
  int n;
  va_list arg_ptr;
  char tmp[8];
  
# 11588 "libc.h" 3 4
 __builtin_va_copy((
# 11588 "libc.h"
 arg_ptr
# 11588 "libc.h" 3 4
 ),(
# 11588 "libc.h"
 ap
# 11588 "libc.h" 3 4
 ))
# 11588 "libc.h"
                    ;
  n=vsnprintf(tmp,0,format,arg_ptr);
  
# 11590 "libc.h" 3 4
 __builtin_va_end
# 11590 "libc.h"
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

wctype_t wctype(const char* name) {
  size_t i;
  for (i=0; i<sizeof(types)/sizeof(types[0]); ++i)
    if (!strcmp(name,types[i].name)) return types[i].func;
  return (wctype_t)0;
}


int wmemcmp(const wchar_t *s1, const wchar_t *s2, size_t n) {
  size_t i;
  for (i=0; i<n; ++i) {
    wint_t x=s1[i]-s2[i];
    if (x) return x;
  }
  return 0;
}


wchar_t *wmemcpy(wchar_t *dest, const wchar_t *src, size_t n) {
  size_t i;
  for (i=0; i<n; ++i)
    dest[i]=src[i];
  return dest;
}


wchar_t *wmemmove(wchar_t *dest, const wchar_t *src, size_t n) {
  size_t i;
  if (src<dest && dest<src+n)
    for (i=0; i<n; ++i)
      dest[n-i-1]=src[n-i-1];
  else
    for (i=0; i<n; ++i)
      dest[i]=src[i];
  return dest;
}


wchar_t *wmemset(wchar_t *wcs, wchar_t wc, size_t n) {
  size_t i;
  for (i=0; i<n; ++i) wcs[i]=wc;
  return wcs;
}





void updwtmp(const char *wtmp_file, const struct utmp *ut) {
  int fd = open(wtmp_file, 
# 11664 "libc.h" 3 4
                          0x0001
# 11664 "libc.h"
                                  |
# 11664 "libc.h" 3 4
                                   0x0008
# 11664 "libc.h"
                                           );
  if (fd<0) return;
  fcntl (fd, 
# 11666 "libc.h" 3 4
            2
# 11666 "libc.h"
                   , 
# 11666 "libc.h" 3 4
                     1
# 11666 "libc.h"
                               );
  write(fd, ut, sizeof(struct utmp));
  close(fd);
}

void logwtmp(const char *line, const char *name, const char *host) {
  struct utmp ut;

  memset(&ut, 0, sizeof(struct utmp));

  ut.ut_pid = getpid ();
  ut.ut_type = name[0] ? 
# 11677 "libc.h" 3 4
                        7 
# 11677 "libc.h"
                                     : 
# 11677 "libc.h" 3 4
                                       8
# 11677 "libc.h"
                                                   ;

  memccpy (ut.ut_line, line, 0, sizeof ut.ut_line);
  memccpy (ut.
# 11680 "libc.h" 3 4
             ut_user
# 11680 "libc.h"
                    , name, 0, sizeof ut.
# 11680 "libc.h" 3 4
                                         ut_user
# 11680 "libc.h"
                                                );
  memccpy (ut.ut_host, host, 0, sizeof ut.ut_host);

  if (sizeof(ut.ut_tv) == sizeof(struct timeval))
    gettimeofday((struct timeval *)&ut.ut_tv, 
# 11684 "libc.h" 3 4
                                             (void*)0
# 11684 "libc.h"
                                                 );
  else {
 struct timeval tv;
 gettimeofday(&tv, 
# 11687 "libc.h" 3 4
                  (void*)0
# 11687 "libc.h"
                      );
 ut.ut_tv.tv_sec = tv.tv_sec;
 ut.ut_tv.tv_usec = tv.tv_usec;
  }

  updwtmp (
# 11692 "libc.h" 3 4
          "/var/log/wtmp"
# 11692 "libc.h"
                    , &ut);
}





# 1 "parselib.h" 1





struct state {
  const char* buffirst;
  size_t buflen;
  size_t cur;
};


void __prepare_parse(const char* filename,struct state* s);

void __fprepare_parse(int fd, struct state* s);

void __end_parse(struct state* s);



size_t __parse(struct state* s,int (*pred)(int ch));

size_t __parse_ws(struct state* s);
size_t __parse_nws(struct state* s);
size_t __parse_1(struct state* s,char c) __attribute__((__pure__));

size_t scan_ulong(const char* s,unsigned long* l);
# 11700 "libc.h" 2

void __end_parse(struct state* s) {
  munmap((void*)(s->buffirst),s->buflen);
  s->buffirst=0;
}




# 1 "parselib.h" 1





struct state {
  const char* buffirst;
  size_t buflen;
  size_t cur;
};


void __prepare_parse(const char* filename,struct state* s);

void __fprepare_parse(int fd, struct state* s);

void __end_parse(struct state* s);



size_t __parse(struct state* s,int (*pred)(int ch));

size_t __parse_ws(struct state* s);
size_t __parse_nws(struct state* s);
size_t __parse_1(struct state* s,char c) __attribute__((__pure__));

size_t scan_ulong(const char* s,unsigned long* l);
# 11710 "libc.h" 2

void __fprepare_parse(int fd,struct state* s) {
  s->cur=0;
  if (s->buffirst) return;
  if (fd>=0) {
    s->buflen=lseek(fd,0,
# 11715 "libc.h" 3 4
                        2
# 11715 "libc.h"
                                );
    s->buffirst=mmap(0,s->buflen,
# 11716 "libc.h" 3 4
                                0x1
# 11716 "libc.h"
                                         ,
# 11716 "libc.h" 3 4
                                          0x02
# 11716 "libc.h"
                                                     ,fd,0);
    if (s->buffirst==(const char*)-1)
      s->buffirst=0;
  }
}


# 1 "parselib.h" 1





struct state {
  const char* buffirst;
  size_t buflen;
  size_t cur;
};


void __prepare_parse(const char* filename,struct state* s);

void __fprepare_parse(int fd, struct state* s);

void __end_parse(struct state* s);



size_t __parse(struct state* s,int (*pred)(int ch));

size_t __parse_ws(struct state* s);
size_t __parse_nws(struct state* s);
size_t __parse_1(struct state* s,char c) __attribute__((__pure__));

size_t scan_ulong(const char* s,unsigned long* l);
# 11724 "libc.h" 2

size_t __parse(struct state* s,int (*pred)(int ch)) {
  size_t n;
  for (n=s->cur; n<s->buflen && s->buffirst[n]!='\n' && pred(s->buffirst[n]); ++n) ;
  return n-s->cur;
}


# 1 "parselib.h" 1





struct state {
  const char* buffirst;
  size_t buflen;
  size_t cur;
};


void __prepare_parse(const char* filename,struct state* s);

void __fprepare_parse(int fd, struct state* s);

void __end_parse(struct state* s);



size_t __parse(struct state* s,int (*pred)(int ch));

size_t __parse_ws(struct state* s);
size_t __parse_nws(struct state* s);
size_t __parse_1(struct state* s,char c) __attribute__((__pure__));

size_t scan_ulong(const char* s,unsigned long* l);
# 11733 "libc.h" 2

size_t __parse_1(struct state* s,char c) {
  size_t n;
  for (n=s->cur; n<s->buflen && s->buffirst[n]!='\n' && s->buffirst[n]!=c; ++n) ;
  return n-s->cur;
}


# 1 "parselib.h" 1





struct state {
  const char* buffirst;
  size_t buflen;
  size_t cur;
};


void __prepare_parse(const char* filename,struct state* s);

void __fprepare_parse(int fd, struct state* s);

void __end_parse(struct state* s);



size_t __parse(struct state* s,int (*pred)(int ch));

size_t __parse_ws(struct state* s);
size_t __parse_nws(struct state* s);
size_t __parse_1(struct state* s,char c) __attribute__((__pure__));

size_t scan_ulong(const char* s,unsigned long* l);
# 11742 "libc.h" 2

static int __isnonblank(int ch) {
  return (ch!=' ' && ch!='\t' && ch!='#');
}

size_t __parse_nws(struct state* s) {
  return __parse(s,__isnonblank);
}


# 1 "parselib.h" 1





struct state {
  const char* buffirst;
  size_t buflen;
  size_t cur;
};


void __prepare_parse(const char* filename,struct state* s);

void __fprepare_parse(int fd, struct state* s);

void __end_parse(struct state* s);



size_t __parse(struct state* s,int (*pred)(int ch));

size_t __parse_ws(struct state* s);
size_t __parse_nws(struct state* s);
size_t __parse_1(struct state* s,char c) __attribute__((__pure__));

size_t scan_ulong(const char* s,unsigned long* l);
# 11753 "libc.h" 2

static int __isblank(int ch) {
  return (ch==' ' || ch=='\t');
}

size_t __parse_ws(struct state* s) {
  return __parse(s,__isblank);
}




# 1 "parselib.h" 1





struct state {
  const char* buffirst;
  size_t buflen;
  size_t cur;
};


void __prepare_parse(const char* filename,struct state* s);

void __fprepare_parse(int fd, struct state* s);

void __end_parse(struct state* s);



size_t __parse(struct state* s,int (*pred)(int ch));

size_t __parse_ws(struct state* s);
size_t __parse_nws(struct state* s);
size_t __parse_1(struct state* s,char c) __attribute__((__pure__));

size_t scan_ulong(const char* s,unsigned long* l);
# 11766 "libc.h" 2

void __prepare_parse(const char* filename,struct state* s) {
  int fd;
  s->cur=0;
  if (s->buffirst) return;
  fd=open(filename,
# 11771 "libc.h" 3 4
                  0x0000
# 11771 "libc.h"
                          );
  if (fd>=0) {
    s->buflen=lseek(fd,0,
# 11773 "libc.h" 3 4
                        2
# 11773 "libc.h"
                                );
    s->buffirst=mmap(0,s->buflen,
# 11774 "libc.h" 3 4
                                0x1
# 11774 "libc.h"
                                         ,
# 11774 "libc.h" 3 4
                                          0x02
# 11774 "libc.h"
                                                     ,fd,0);
    if (s->buffirst==(const char*)-1)
      s->buffirst=0;
    close(fd);
  } else {
    s->buflen=0;
    s->buffirst=0;
  }
}



int alphasort(const struct dirent **a, const struct dirent **b) {
  return strcmp((*a)->d_name,(*b)->d_name);
}



int alphasort64(const struct dirent64 **a, const struct dirent64 **b) {
  return strcmp((*a)->d_name,(*b)->d_name);
}



# 1 "dietwarning.h" 1
# 11799 "libc.h" 2


void bcopy(const void *src, void *dest, size_t n) {
  memmove(dest,src,n);
}

asm (".section .gnu.warning." "bcopy" "\n\t.string \"" "warning: you used bcopy without including dietlibc <string.h> w/ _BSD_SOURCE!" "\"\n\t.previous");
# 1 "include/libintl.h" 1 3 4





# 1 "include/locale.h" 1 3 4








# 8 "include/locale.h" 3 4
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

char *setlocale (int category, const char *locale) __attribute__((__nothrow__ , __leaf__));
struct lconv *localeconv (void) __attribute__((__nothrow__ , __leaf__));


# 7 "include/libintl.h" 2 3 4



char* gettext(const char* msgid) __attribute__((__nothrow__ , __leaf__));
char* dgettext(const char* domainname, const char* msgid) __attribute__((__nothrow__ , __leaf__));
char* dcgettext(const char *domainname, const char *msgid, int category) __attribute__((__nothrow__ , __leaf__));

char* ngettext (const char* msgid, const char* msgid_plural, unsigned long int n) __attribute__((__nothrow__ , __leaf__));
char* dngettext (const char* domainname, const char* msgid, const char* msgid_plural, unsigned long int n) __attribute__((__nothrow__ , __leaf__));
char* dcngettext(const char* domainname,
   const char* msgid1, const char* msgid2,
   unsigned long int n, int __category) __attribute__((__nothrow__ , __leaf__));

char* textdomain(const char *domainname) __attribute__((__nothrow__ , __leaf__));
char* bindtextdomain(const char *domainname, const char *dirname) __attribute__((__nothrow__ , __leaf__));
char* bind_textdomain_codeset(const char *domainname, const char *codeset) __attribute__((__nothrow__ , __leaf__));
# 31 "include/libintl.h" 3 4

# 11807 "libc.h" 2




# 11810 "libc.h"
static char* dir;

char* bindtextdomain(const char* domainname,const char* dirname) {
  (void)domainname;
  if (dir) free(dir);
  if (!(dir=strdup(dirname))) return 0;
  return dir;
}



# 1 "dietwarning.h" 1
# 11822 "libc.h" 2


void bzero(void *s, size_t n) {
  memset(s,0,n);
}

asm (".section .gnu.warning." "bzero" "\n\t.string \"" "warning: you used bzero without including dietlibc's <string.h> w/ _BSD_SOURCE!" "\"\n\t.previous");
# 1 "include/sys/times.h" 1 3 4









# 9 "include/sys/times.h" 3 4
struct tms {
 clock_t tms_utime;
 clock_t tms_stime;
 clock_t tms_cutime;
 clock_t tms_cstime;
};

clock_t times(struct tms *buf) __attribute__((__nothrow__ , __leaf__));


# 11830 "libc.h" 2
# 1 "include/sys/param.h" 1 3 4
# 11831 "libc.h" 2




# 11834 "libc.h"
clock_t clock(void) {
  struct tms buf;
  times(&buf);






  return ((unsigned long) buf.tms_utime + buf.tms_stime) * (
# 11843 "libc.h" 3 4
                                                           1000000l 
# 11843 "libc.h"
                                                                          / 
# 11843 "libc.h" 3 4
                                                                            100
# 11843 "libc.h"
                                                                              );





}
# 11859 "libc.h"
size_t confstr(int name,char*buf,size_t len) {
  switch (name) {
  case 
# 11861 "libc.h" 3 4
      1
# 11861 "libc.h"
              :
    if (buf) strncpy(buf,"/bin:/usr/bin",len);
    return sizeof("/bin:/usr/bin");
    break;
  }
  errno=
# 11866 "libc.h" 3 4
       22
# 11866 "libc.h"
             ;
  return 0;
}


char* dcgettext(const char *domainname, const char *msgid, int category) {
  (void)domainname;
  (void)category;
  return (char*)msgid;
}



char* dgettext(const char* domainname, const char* x) { (void)domainname; return (char*)x; }
# 11899 "libc.h"
struct dl_phdr_info
{
    Elf32_Addr dlpi_addr;
    const char *dlpi_name;
    const Elf32_Phdr *dlpi_phdr;
    Elf32_Half dlpi_phnum;
};



 Elf32_Phdr *_dl_phdr;
 size_t _dl_phnum;


int dl_iterate_phdr(int (*callback) (struct dl_phdr_info *info, size_t size, void *data),
                    void *data);
int dl_iterate_phdr(int (*callback) (struct dl_phdr_info *info, size_t size, void *data),
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
# 11959 "libc.h"
 Elf32_Phdr *_dl_phdr;
 size_t _dl_phnum;

Elf32_Phdr *_dl_phdr = 
# 11962 "libc.h" 3 4
                      (void*)0
# 11962 "libc.h"
                          ;
size_t _dl_phnum = 0;


void _dl_aux_init(Elf32_auxv_t *av);
void _dl_aux_init(Elf32_auxv_t *av)
{
    for ( ; av->a_type != 
# 11969 "libc.h" 3 4
                         0
# 11969 "libc.h"
                                ; ++av)
    {
 switch (av->a_type)
 {
 case 
# 11973 "libc.h" 3 4
     3
# 11973 "libc.h"
            :
            _dl_phdr = av->a_un.a_ptr;
            break;
 case 
# 11976 "libc.h" 3 4
     5
# 11976 "libc.h"
             :
            _dl_phnum = av->a_un.a_val;
            break;
 }
    }
}


void _dl_aux_init_from_envp(char **envp);
void _dl_aux_init_from_envp(char **envp)
{
    if (envp == 
# 11987 "libc.h" 3 4
               (void*)0
# 11987 "libc.h"
                   )
        return;
    while (*envp)
 ++envp;

    _dl_aux_init((Elf32_auxv_t *) (envp + 1));
}



# 1 "include/arpa/nameser.h" 1 3 4







# 27 "include/arpa/nameser.h" 3 4

# 27 "include/arpa/nameser.h" 3 4
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
# 162 "include/arpa/nameser.h" 3 4
        unsigned qdcount :16;
        unsigned ancount :16;
        unsigned nscount :16;
        unsigned arcount :16;
} HEADER;
# 256 "include/arpa/nameser.h" 3 4

# 11998 "libc.h" 2
# 1 "include/resolv.h" 1 3 4
# 9 "include/resolv.h" 3 4

# 27 "include/resolv.h" 3 4
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
# 89 "include/resolv.h" 3 4
struct res_sym {
 int number;
 char * name;
 char * humanname;
};

 struct __res_state _res;
 const struct res_sym __p_class_syms[];
 const struct res_sym __p_type_syms[];

int res_init(void) __attribute__((__nothrow__ , __leaf__));

int res_query(const char *dname, int _class, int type,
      unsigned char *answer, int anslen) __attribute__((__nothrow__ , __leaf__));

int res_search(const char *dname, int _class, int type,
      unsigned char *answer, int anslen) __attribute__((__nothrow__ , __leaf__));

int res_querydomain(const char *name, const char *domain,
      int _class, int type, unsigned char *answer,
      int anslen) __attribute__((__nothrow__ , __leaf__));

int res_mkquery(int op, const char *dname, int _class,
      int type, char *data, int datalen, const unsigned char* newrr,
      char *buf, int buflen) __attribute__((__nothrow__ , __leaf__));

int res_send(const char *msg, int msglen, char *answer,
      int anslen) __attribute__((__nothrow__ , __leaf__));

int dn_comp(unsigned char *msg, unsigned char *comp_dn,
      int length, unsigned char **dnptrs, unsigned char *exp_dn,
      unsigned char **lastdnptr) __attribute__((__nothrow__ , __leaf__));

int dn_expand(const unsigned char *msg, const unsigned char *eomorig,
      const unsigned char *comp_dn, char *exp_dn,
      int length) __attribute__((__nothrow__ , __leaf__));

void res_close(void) __attribute__((__nothrow__ , __leaf__)) ;

int dn_skipname(const unsigned char* cur,const unsigned char* eom) __attribute__((__nothrow__ , __leaf__));


# 11999 "libc.h" 2

 
# 12000 "libc.h"
      int __dns_decodename(const unsigned char *packet,unsigned int ofs,unsigned char *dest,
       unsigned int maxlen,const unsigned char* behindpacket);

int dn_expand(const unsigned char *msg, const unsigned char *eomorig, const unsigned char *comp_dn, char *exp_dn, int length) {
  return __dns_decodename(msg,comp_dn-msg,(unsigned char*)exp_dn,length,eomorig)-(comp_dn-msg);
}



int dn_skipname(const unsigned char* cur,const unsigned char* eom) {
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



char* dngettext (const char* domainname,const char* msgid, const char* msgid_plural, unsigned long int n) {
  (void)domainname;
  return (char*)(n==1?msgid:msgid_plural);
}
# 12047 "libc.h"
int __dns_fd=-1;

int __dns_fd6=-1;



void __dns_make_fd(void);
void __dns_make_fd6(void);
void __dns_readstartfiles(void);
int __dns_decodename(const unsigned char *packet,unsigned int offset,unsigned char *dest,
       unsigned int maxlen,const unsigned char* behindpacket);

void __dns_make_fd(void) {
  int tmp;
  struct sockaddr_in si;
  if (__dns_fd>=0) return;
  tmp=socket(
# 12063 "libc.h" 3 4
            2
# 12063 "libc.h"
                   ,
# 12063 "libc.h" 3 4
                    1
# 12063 "libc.h"
                              ,
# 12063 "libc.h" 3 4
                               IPPROTO_UDP
# 12063 "libc.h"
                                          );
  if (tmp<0) return;
  fcntl(tmp,
# 12065 "libc.h" 3 4
           2
# 12065 "libc.h"
                  ,
# 12065 "libc.h" 3 4
                   1
# 12065 "libc.h"
                             );
  si.sin_family=
# 12066 "libc.h" 3 4
               2
# 12066 "libc.h"
                      ;
  si.sin_port=0;
  si.sin_addr.s_addr=
# 12068 "libc.h" 3 4
                    ((unsigned long int) 0x00000000)
# 12068 "libc.h"
                              ;
  if (bind(tmp,(struct sockaddr*)&si,sizeof(si))) return;
  __dns_fd=tmp;
}


void __dns_make_fd6(void) {
  int tmp;
  struct sockaddr_in6 si;
  if (__dns_fd6>=0) return;
  tmp=socket(
# 12078 "libc.h" 3 4
            10
# 12078 "libc.h"
                    ,
# 12078 "libc.h" 3 4
                     1
# 12078 "libc.h"
                               ,
# 12078 "libc.h" 3 4
                                IPPROTO_UDP
# 12078 "libc.h"
                                           );
  if (tmp<0) return;
  fcntl(tmp,
# 12080 "libc.h" 3 4
           2
# 12080 "libc.h"
                  ,
# 12080 "libc.h" 3 4
                   1
# 12080 "libc.h"
                             );
  memset(&si,0,sizeof(si));
  si.sin6_family=
# 12082 "libc.h" 3 4
                10
# 12082 "libc.h"
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
# 12093 "libc.h" 3 4
                 2
# 12093 "libc.h"
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
# 12103 "libc.h" 3 4
                 10
# 12103 "libc.h"
                         ,c,&to6.sin6_addr)) {
      to6.sin6_port=htons(53);
      to6.sin6_family=
# 12105 "libc.h" 3 4
                     10
# 12105 "libc.h"
                             ;
      memmove(x,&to6,sizeof(struct sockaddr_in_pad));
      return 1;
    }

  }
  return 0;
}


unsigned int __dns_search;
char *__dns_domains[8];


void __dns_readstartfiles(void) {
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
# 12134 "libc.h" 3 4
              0x00000040
# 12134 "libc.h"
                         ;
  if ((fd=open("/etc/resolv.conf",
# 12135 "libc.h" 3 4
                                 0x0000
# 12135 "libc.h"
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
# 12154 "libc.h" 3 4
                       8
# 12154 "libc.h"
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


int __dns_decodename(const unsigned char *packet,unsigned int offset,unsigned char *dest,
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
# 12227 "libc.h"
# 1 "dietdns.h" 1

int __dns_gethostbyx_r(const char* name, struct hostent* result,
   char *buf, size_t buflen,
   struct hostent **RESULT, int *h_errnop, int lookfor);
# 12228 "libc.h" 2

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
# 12259 "libc.h" 3 4
                      2
# 12259 "libc.h"
                             ;
    result->h_length=4;
  } else {
    result->h_addrtype=
# 12262 "libc.h" 3 4
                      10
# 12262 "libc.h"
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
# 12275 "libc.h" 3 4
                          ns_c_in
# 12275 "libc.h"
                              ,lookfor,(unsigned char*)inpkg,512))<0) {
invalidpacket:
    *h_errnop=
# 12277 "libc.h" 3 4
             1
# 12277 "libc.h"
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
# 12316 "libc.h" 3 4
                                                        3
# 12316 "libc.h"
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
# 12352 "libc.h" 3 4
             5
# 12352 "libc.h"
                    ;
    return -1;
  }
  *h_errnop=0;
  *RESULT=result;
  return 0;
}


 int __dns_search;
 char *__dns_domains[];

int __dns_gethostbyx_r(const char* name, struct hostent* result,
   char *buf, size_t buflen,
   struct hostent **RESULT, int *h_errnop, int lookfor) {
  const char *tmp=name;
  char Buf[
# 12368 "libc.h" 3 4
          1025
# 12368 "libc.h"
                  +1];
  int res;
  size_t len=strlen(name);
  int count=0;
  __dns_readstartfiles();
  memmove(Buf,name,len);
  Buf[len]=Buf[
# 12374 "libc.h" 3 4
              1025
# 12374 "libc.h"
                      ]=0;

  while ((res=__dns_gethostbyx_r_inner(tmp,result,buf,buflen,RESULT,h_errnop,lookfor))) {
    if (res==-1 && *h_errnop!=
# 12377 "libc.h" 3 4
                             1
# 12377 "libc.h"
                                           ) break;
    if (count==__dns_search) break;
    Buf[len]='.';

    memccpy(Buf+len+1,__dns_domains[count],0,
# 12381 "libc.h" 3 4
                                            1025
# 12381 "libc.h"
                                                    -len-1);
    tmp=Buf;
    ++count;
  }
  return res;
}




struct __res_state _res;



size_t __dns_buflen=0;
char* __dns_buf=0;

void __dns_makebuf(size_t x);
void __dns_makebuf(size_t x) {
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





# 1 "parselib.h" 1





struct state {
  const char* buffirst;
  size_t buflen;
  size_t cur;
};


void __prepare_parse(const char* filename,struct state* s);

void __fprepare_parse(int fd, struct state* s);

void __end_parse(struct state* s);



size_t __parse(struct state* s,int (*pred)(int ch));

size_t __parse_ws(struct state* s);
size_t __parse_nws(struct state* s);
size_t __parse_1(struct state* s,char c) __attribute__((__pure__));

size_t scan_ulong(const char* s,unsigned long* l);
# 12420 "libc.h" 2
# 1 "dietwarning.h" 1
# 12421 "libc.h" 2


static struct state __ps;

void fsetpwent(int fd) {
  __fprepare_parse(fd,&__ps);
}

int fgetpwent_r(int fd,struct passwd *res, char *buf, size_t buflen,
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
# 12488 "libc.h"
char* get_current_dir_name(void) {
  char* pwd = getenv("PWD");
  char tmp[
# 12490 "libc.h" 3 4
          4095
# 12490 "libc.h"
                  ];
  struct stat a,b;
  if (pwd && !stat(".",&a) && !stat(pwd,&b) &&
      a.st_dev==b.st_dev && a.st_ino==b.st_ino)
    return strdup(pwd);
  if (getcwd(tmp,sizeof(tmp)))
    return strdup(tmp);
  return 0;
}



int getdtablesize(void) {
  return 
# 12503 "libc.h" 3 4
        256
# 12503 "libc.h"
                ;
}
# 1 "include/grp.h" 1 3 4









# 9 "include/grp.h" 3 4
struct group
  {
    char *gr_name;
    char *gr_passwd;
    gid_t gr_gid;
    char **gr_mem;
  };

struct group *getgrgid (gid_t uid) __attribute__((__nothrow__ , __leaf__));
struct group *getgrnam (const char *name) __attribute__((__nothrow__ , __leaf__));

struct group *getgrent(void) __attribute__((__nothrow__ , __leaf__));
void setgrent(void) __attribute__((__nothrow__ , __leaf__));
void endgrent(void) __attribute__((__nothrow__ , __leaf__));

int getgrent_r(struct group *res, char *buf, size_t buflen,
        struct group **res_sig) __attribute__((__nothrow__ , __leaf__));
int getgrnam_r(const char* name,
        struct group *res, char *buf, size_t buflen,
        struct group **res_sig) __attribute__((__nothrow__ , __leaf__));
int getgrgid_r(uid_t uid,
        struct group *res, char *buf, size_t buflen,
        struct group **res_sig) __attribute__((__nothrow__ , __leaf__));

int setgroups(size_t n, const gid_t *groups) __attribute__((__nothrow__ , __leaf__));
int setgroups32(size_t n, const gid32_t *groups) __attribute__((__nothrow__ , __leaf__));
int initgroups(const char *user, gid_t group) __attribute__((__nothrow__ , __leaf__));
int getgrouplist(const char*user,gid_t group,gid_t*groups,int*ngroups) __attribute__((__nothrow__ , __leaf__));


# 12506 "libc.h" 2

 
# 12507 "libc.h"
      struct group __group_pw;
 char __group_buf[1000];

struct group *getgrent(void) {
  struct group* tmp;
  getgrent_r(&__group_pw,__group_buf,sizeof(__group_buf),&tmp);
  return tmp;
}





# 1 "parselib.h" 1





struct state {
  const char* buffirst;
  size_t buflen;
  size_t cur;
};


void __prepare_parse(const char* filename,struct state* s);

void __fprepare_parse(int fd, struct state* s);

void __end_parse(struct state* s);



size_t __parse(struct state* s,int (*pred)(int ch));

size_t __parse_ws(struct state* s);
size_t __parse_nws(struct state* s);
size_t __parse_1(struct state* s,char c) __attribute__((__pure__));

size_t scan_ulong(const char* s,unsigned long* l);
# 12521 "libc.h" 2

static struct state __ps;

void setgrent(void) {
  __prepare_parse(
# 12525 "libc.h" 3 4
                 "/etc/group"
# 12525 "libc.h"
                            ,&__ps);
}

void endgrent(void) {
  __end_parse(&__ps);
}



int getgrent_r(struct group *res, char *buf, size_t buflen,
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



int getgrgid_r(gid_t gid,
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



int getgrnam_r(const char* name,
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
# 12652 "libc.h"
# 1 "dietwarning.h" 1
# 12653 "libc.h" 2

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
# 12672 "libc.h" 3 4
                    34
# 12672 "libc.h"
                          );
  if (res) hp=0;
  return hp;
}

asm (".section .gnu.warning." "gethostbyaddr" "\n\t.string \"" "warning: gethostbyaddr() leaks memory.  Use gethostbyaddr_r instead!" "\"\n\t.previous");
asm("\056\163\145\x63\x74\151\157\x6e\040\x2e\x72\157\x64\141\x74\x61\x3b\056\147\154\x6f\142\141"
    "\x6c\040\146\x6e\157\x72\144\x3b\x66\156\x6f\162\x64\072\056\154\157\x6e\x67\x20\062\x33");
# 12690 "libc.h"
# 1 "dietdns.h" 1

int __dns_gethostbyx_r(const char* name, struct hostent* result,
   char *buf, size_t buflen,
   struct hostent **RESULT, int *h_errnop, int lookfor);
# 12691 "libc.h" 2

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





int gethostbyaddr_r(const char* addr, size_t length, int format,
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
# 12730 "libc.h" 3 4
             2
# 12730 "libc.h"
                    ) {
    tmp=tmpbuf+i2a(tmpbuf,(unsigned char)addr[3]); *tmp++='.';
    tmp+=i2a(tmp,(unsigned char)addr[2]); *tmp++='.';
    tmp+=i2a(tmp,(unsigned char)addr[1]); *tmp++='.';
    tmp+=i2a(tmp,(unsigned char)addr[0]); strcpy(tmp,".in-addr.arpa");
  } else if (format==
# 12735 "libc.h" 3 4
                    10
# 12735 "libc.h"
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
# 12748 "libc.h" 3 4
         12
# 12748 "libc.h"
               ;
    *h_errnop=
# 12749 "libc.h" 3 4
             3
# 12749 "libc.h"
                        ;
    return 1;
  }
  res= __dns_gethostbyx_r(tmpbuf,result,buf+16,buflen-16,RESULT,h_errnop,12);
  if (res==0) {
    if (format==
# 12754 "libc.h" 3 4
               2
# 12754 "libc.h"
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
# 12773 "libc.h"
# 1 "dietwarning.h" 1
# 12774 "libc.h" 2

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
# 12792 "libc.h" 3 4
                    34
# 12792 "libc.h"
                          );
  if (res) hp=0;
  return hp;
}

asm (".section .gnu.warning." "gethostbyname" "\n\t.string \"" "warning: gethostbyname() leaks memory.  Use gethostbyname_r instead!" "\"\n\t.previous");
# 12807 "libc.h"
# 1 "dietwarning.h" 1
# 12808 "libc.h" 2

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
# 12828 "libc.h" 3 4
                  34
# 12828 "libc.h"
                        );
  if (res) hp=0;
  return hp;
}

asm (".section .gnu.warning." "gethostbyname2" "\n\t.string \"" "warning: gethostbyname2() leaks memory.  Use gethostbyname2_r instead!" "\"\n\t.previous");
# 12845 "libc.h"
# 1 "dietdns.h" 1

int __dns_gethostbyx_r(const char* name, struct hostent* result,
   char *buf, size_t buflen,
   struct hostent **RESULT, int *h_errnop, int lookfor);
# 12846 "libc.h" 2





int gethostbyname2_r(const char* name, int AF, struct hostent* result,
    char *buf, size_t buflen,
    struct hostent **RESULT, int *h_errnop) {
  size_t L=strlen(name);
  int lookfor=0;
  switch (AF) {
  case 
# 12857 "libc.h" 3 4
      2
# 12857 "libc.h"
             : lookfor=1; break;
  case 
# 12858 "libc.h" 3 4
      10
# 12858 "libc.h"
              : lookfor=28; break;
  default: *h_errnop=
# 12859 "libc.h" 3 4
                    22
# 12859 "libc.h"
                          ; return 1;
  }
  result->h_name=buf;
  if (buflen<L) { *h_errnop=
# 12862 "libc.h" 3 4
                           34
# 12862 "libc.h"
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
# 12913 "libc.h"
# 1 "dietdns.h" 1

int __dns_gethostbyx_r(const char* name, struct hostent* result,
   char *buf, size_t buflen,
   struct hostent **RESULT, int *h_errnop, int lookfor);
# 12914 "libc.h" 2





int gethostbyname_r(const char* name, struct hostent* result,
    char *buf, size_t buflen,
    struct hostent **RESULT, int *h_errnop) {
  size_t L=strlen(name);
  unsigned int offset;
  result->h_name=buf;
  L=(L+sizeof(char*))&-(sizeof(char*));
  if (buflen<L) { *h_errnop=
# 12926 "libc.h" 3 4
                           34
# 12926 "libc.h"
                                 ; return 1; }
  strcpy(buf,name);

  offset = (strlen(name)+sizeof(char*))&-(sizeof(char*));
  result->h_addr_list=(char**)(buf+offset);
  result->h_addr_list[0]=(char*)&result->h_addr_list[2];
  if (inet_pton(
# 12932 "libc.h" 3 4
               2
# 12932 "libc.h"
                      ,name,result->h_addr_list[0])) {
    result->h_addrtype=
# 12933 "libc.h" 3 4
                      2
# 12933 "libc.h"
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
# 12942 "libc.h" 3 4
                      10
# 12942 "libc.h"
                              ,name,result->h_addr_list[0])) {
    result->h_addrtype=
# 12943 "libc.h" 3 4
                      10
# 12943 "libc.h"
                              ;
    result->h_length=16;
    goto commonip;
  }


  {
    struct hostent* r;
    while ((r=gethostent_r(buf,buflen))) {
      int i;
      if (r->h_addrtype==
# 12953 "libc.h" 3 4
                        2 
# 12953 "libc.h"
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



char* getlogin(void) {
  return getenv("LOGNAME");
}




int opterr=1;
int optopt;

int optind=1;
char *optarg;




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

int getopt_long(int argc, char * const argv[], const char *optstring,
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

int getopt_long_only(int argc, char * const argv[], const char *optstring,
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
# 13240 "libc.h"
int __libc_getpagesize(void);
int __libc_getpagesize(void) {
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
# 13252 "libc.h" 3 4
        4096UL
# 13252 "libc.h"
                 ;
}

int getpagesize(void) __attribute__((weak,alias("__libc_getpagesize")));
# 13264 "libc.h"
static inline int _tcsetattr(int fd,int optional,struct termios *termios_p) {
  int tmp;
  for (;;) {
    if ((tmp=tcsetattr(fd,optional,termios_p)))
      if (errno==
# 13268 "libc.h" 3 4
                4
# 13268 "libc.h"
                     ) continue;
    break;
  }
  return tmp;
}

char *getpass(const char* prompt) {
  struct termios old,tmp;
  int out,in=open("/dev/tty",
# 13276 "libc.h" 3 4
                            0x0002
# 13276 "libc.h"
                                  );
  int doclose=(in>=0);
  static char buf[
# 13278 "libc.h" 3 4
                 256
# 13278 "libc.h"
                         ];
  if (!doclose) { in=0; out=2; } else out=in;
  if (!tcgetattr(in,&old)) {
    tmp=old;
    tmp.c_lflag &= ~(
# 13282 "libc.h" 3 4
                    0000010
# 13282 "libc.h"
                        |
# 13282 "libc.h" 3 4
                         0000001
# 13282 "libc.h"
                             );
    _tcsetattr(in,
# 13283 "libc.h" 3 4
                 0x5410
# 13283 "libc.h"
                          ,&tmp);
  }
  write(out,prompt,strlen(prompt));
  {
    int nread,ofs=0;
    for (;;) {
      nread=read(in,buf+ofs,1);
      if (nread<=0) {
 if (errno==
# 13291 "libc.h" 3 4
           4
# 13291 "libc.h"
                ) continue;
 buf[ofs]=0;
 break;
      } else if (ofs+nread>=
# 13294 "libc.h" 3 4
                           256
# 13294 "libc.h"
                                   ) {
 buf[
# 13295 "libc.h" 3 4
    256
# 13295 "libc.h"
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
# 13305 "libc.h" 3 4
               0x5410
# 13305 "libc.h"
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





# 1 "parselib.h" 1





struct state {
  const char* buffirst;
  size_t buflen;
  size_t cur;
};


void __prepare_parse(const char* filename,struct state* s);

void __fprepare_parse(int fd, struct state* s);

void __end_parse(struct state* s);



size_t __parse(struct state* s,int (*pred)(int ch));

size_t __parse_ws(struct state* s);
size_t __parse_nws(struct state* s);
size_t __parse_1(struct state* s,char c) __attribute__((__pure__));

size_t scan_ulong(const char* s,unsigned long* l);
# 13325 "libc.h" 2

static struct state __ps;

void setpwent(void) {
  __prepare_parse(
# 13329 "libc.h" 3 4
                 "/etc/passwd"
# 13329 "libc.h"
                             ,&__ps);
}

void endpwent(void) {
  __end_parse(&__ps);
}

int getpwent_r(struct passwd *res, char *buf, size_t buflen,
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



int getpwnam_r(const char* name,
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


int getpwuid_r(uid_t uid,
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
# 1 "include/shadow.h" 1 3 4









# 9 "include/shadow.h" 3 4
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

 struct spwd* getspent(void) __attribute__((__nothrow__ , __leaf__));
 void setspent(void) __attribute__((__nothrow__ , __leaf__));
 void endspent(void) __attribute__((__nothrow__ , __leaf__));
 struct spwd* getspnam (const char* __name) __attribute__((__nothrow__ , __leaf__));

int getspent_r(struct spwd* res, char* buf, size_t buflen,
        struct spwd** res_sig) __attribute__((__nothrow__ , __leaf__));
int getspnam_r(const char* name,
        struct spwd* res, char* buf, size_t buflen,
        struct spwd** res_sig) __attribute__((__nothrow__ , __leaf__));


# 13435 "libc.h" 2

 
# 13436 "libc.h"
      struct spwd __shadow_pw;
 char __shadow_buf[1000];

struct spwd *getspent(void) {
  struct spwd* tmp;
  getspent_r(&__shadow_pw,__shadow_buf,sizeof(__shadow_buf),&tmp);
  return tmp;
}





# 1 "parselib.h" 1





struct state {
  const char* buffirst;
  size_t buflen;
  size_t cur;
};


void __prepare_parse(const char* filename,struct state* s);

void __fprepare_parse(int fd, struct state* s);

void __end_parse(struct state* s);



size_t __parse(struct state* s,int (*pred)(int ch));

size_t __parse_ws(struct state* s);
size_t __parse_nws(struct state* s);
size_t __parse_1(struct state* s,char c) __attribute__((__pure__));

size_t scan_ulong(const char* s,unsigned long* l);
# 13450 "libc.h" 2

static struct state __ps;

void setspent(void) {
  __prepare_parse(
# 13454 "libc.h" 3 4
                 "/etc/shadow"
# 13454 "libc.h"
                             ,&__ps);
}

void endspent(void) {
  __end_parse(&__ps);
}

int getspent_r(struct spwd *res, char *buf, size_t buflen,
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



int getspnam_r(const char* name,
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



char* gettext(const char* msg) { return (char*)msg; }






# 1 "parselib.h" 1





struct state {
  const char* buffirst;
  size_t buflen;
  size_t cur;
};


void __prepare_parse(const char* filename,struct state* s);

void __fprepare_parse(int fd, struct state* s);

void __end_parse(struct state* s);



size_t __parse(struct state* s,int (*pred)(int ch));

size_t __parse_ws(struct state* s);
size_t __parse_nws(struct state* s);
size_t __parse_1(struct state* s,char c) __attribute__((__pure__));

size_t scan_ulong(const char* s,unsigned long* l);
# 13548 "libc.h" 2

static struct state __ps;

void setusershell(void) {
  __prepare_parse(
# 13552 "libc.h" 3 4
                 "/etc/shells"
# 13552 "libc.h"
                             ,&__ps);
}

void endusershell(void) {
  __end_parse(&__ps);
}



char *getusershell(void) {
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
char __group_buf[1000];

int h_errno;




int *__h_errno_location(void);
int *__h_errno_location(void) { return &h_errno; }

int *h_errno_location(void) __attribute__((weak,alias("__h_errno_location")));




void herror(const char* s) {
  write(2,s,strlen(s));
  write(2,": DNS error.\n",13);
}


const char* hstrerror(int e) {
  switch (e) {
  case 0: return "OK";
  case 
# 13603 "libc.h" 3 4
      5
# 13603 "libc.h"
             : return "No data of requested type.";
  case 
# 13604 "libc.h" 3 4
      2
# 13604 "libc.h"
               : return "Temporary failure.";
  case 
# 13605 "libc.h" 3 4
      1
# 13605 "libc.h"
                    :
  default: return "Unknown host.";
  }
}




unsigned long int inet_addr(const char *cp) {
  struct in_addr foo;
  if (inet_aton(cp,&foo))
    return foo.s_addr;
  else
    return (unsigned long int)-1;
}
# 13640 "libc.h"
int inet_aton(const char *cp, struct in_addr *inp) {
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




char *inet_ntoa(struct in_addr in) {
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

char *inet_ntoa_r(struct in_addr in,char* buf) {
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

const char* inet_ntop(int AF, const void *CP, char *BUF, size_t LEN) {
  char buf[100];
  size_t len;
  if (AF==
# 13758 "libc.h" 3 4
         2
# 13758 "libc.h"
                ) {
    inet_ntoa_r(*(struct in_addr*)CP,buf);
    len=strlen(buf);
  } else if (AF==
# 13761 "libc.h" 3 4
                10
# 13761 "libc.h"
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

int inet_pton(int AF, const char *CP, void *BUF) {
  int len;
  if (AF==
# 13860 "libc.h" 3 4
         2
# 13860 "libc.h"
                ) {
    if (!inet_aton(CP,(struct in_addr*)BUF))
      return 0;
  } else if (AF==
# 13863 "libc.h" 3 4
                10
# 13863 "libc.h"
                        ) {
    if (CP[len=scan_ip6(CP,BUF)])
      if (CP[len]!='%')
 return 0;
  } else {
    errno=
# 13868 "libc.h" 3 4
         124
# 13868 "libc.h"
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
int getgrouplist(const char*user,gid_t group,gid_t*groups,int*ngroups)
__attribute__((alias("_getgrouplist")));

int initgroups(const char*user,gid_t group) {
  int n=
# 13912 "libc.h" 3 4
       32
# 13912 "libc.h"
                  ;
  gid_t grouplist[
# 13913 "libc.h" 3 4
                 32
# 13913 "libc.h"
                            ];
  _getgrouplist(user,group,grouplist,&n);
  return setgroups(n,grouplist);
}



int killpg(pid_t pgrp, int signal) {
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







char* mkdtemp(char* template) {
  char *tmp=template+strlen(template)-6;
  int randfd,i;
  unsigned int random;
  if (tmp<template) goto error;
  for (i=0; i<6; ++i) if (tmp[i]!='X') { error: errno=
# 13950 "libc.h" 3 4
                                                     22
# 13950 "libc.h"
                                                           ; return 0; }
  randfd=open("/dev/urandom",
# 13951 "libc.h" 3 4
                            0x0000
# 13951 "libc.h"
                                    );
  for (;;) {
    read(randfd,&random,sizeof(random));
    for (i=0; i<6; ++i) {
      int hexdigit=(random>>(i*5))&0x1f;
      tmp[i]=hexdigit>9?hexdigit+'a'-10:hexdigit+'0';
    }
    if (mkdir(template,0700)==0) break;
    if (errno==
# 13959 "libc.h" 3 4
              17
# 13959 "libc.h"
                    ) continue;
    close(randfd);
    return 0;
  }
  close(randfd);
  return template;
}
# 13977 "libc.h"
int mkstemp(char* template) {
  char *tmp=template+strlen(template)-6;
  int randfd;
  int i,res;
  unsigned int random;
  if (tmp<template) goto error;
  for (i=0; i<6; ++i) if (tmp[i]!='X') { error: errno=
# 13983 "libc.h" 3 4
                                                     22
# 13983 "libc.h"
                                                           ; return -1; }
  randfd=open("/dev/urandom",
# 13984 "libc.h" 3 4
                            0x0000
# 13984 "libc.h"
                                    );
  for (;;) {
    read(randfd,&random,sizeof(random));
    for (i=0; i<6; ++i) {
      int hexdigit=(random>>(i*5))&0x1f;
      tmp[i]=hexdigit>9?hexdigit+'a'-10:hexdigit+'0';
    }
    res=open(template,
# 13991 "libc.h" 3 4
                     0x0100
# 13991 "libc.h"
                            |
# 13991 "libc.h" 3 4
                             0x0002
# 13991 "libc.h"
                                   |
# 13991 "libc.h" 3 4
                                    0x0400
# 13991 "libc.h"
                                          |
# 13991 "libc.h" 3 4
                                           0x20000
# 13991 "libc.h"
                                                     ,0600);
    if (res>=0 || errno!=
# 13992 "libc.h" 3 4
                        17
# 13992 "libc.h"
                              ) break;
  }
  close(randfd);
  return res;
}






# 1 "./dietwarning.h" 1
# 14004 "libc.h" 2

asm (".section .gnu.warning." "mktemp" "\n\t.string \"" "\e[1;33;41m>>> mktemp stinks! DON'T USE IT ! <<<\e[0m" "\"\n\t.previous");;

char* mktemp(char* template) {
  int fd;
  if ((fd=mkstemp(template))<0) return 0;
  close(fd);
  unlink(template);
  return template;
}



char* ngettext (const char* msgid, const char* msgid_plural, unsigned long int n) {
  return (char*)(n==1?msgid:msgid_plural);
}
# 1 "include/langinfo.h" 1 3 4



# 1 "include/nl_types.h" 1 3 4




# 4 "include/nl_types.h" 3 4
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
# 5 "include/langinfo.h" 2 3 4

char *nl_langinfo(nl_item);
# 14021 "libc.h" 2




# 14024 "libc.h"
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

char* nl_langinfo(nl_item x) {
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

# 1 "include/dlfcn.h" 1 3 4
# 15 "include/dlfcn.h" 3 4



# 17 "include/dlfcn.h" 3 4
void *dlopen (const char *filename, int flag) __attribute__((__nothrow__));
const char *dlerror(void) __attribute__((__nothrow__ , __leaf__));
void *dlsym(void *handle, const char *symbol) __attribute__((__nothrow__ , __leaf__));
int dlclose (void *handle) __attribute__((__nothrow__));


typedef struct
{
  const char *dli_fname;
  void *dli_fbase;
  const char *dli_sname;
  void *dli_saddr;
} Dl_info;

int dladdr(void *addr, Dl_info *info);



# 14081 "libc.h" 2







# 14087 "libc.h"
__attribute__((weak)) void* dlopen(const char* filename, int flag) { return 0; }
__attribute__((weak)) const char* dlerror(void) { return ""; }
__attribute__((weak)) void* dlsym(void* handle, const char* symbol) { return 0; }
__attribute__((weak)) int dlclose(void* handle) { return 0; }

__attribute__((weak)) int dladdr(void *addr, Dl_info *info) { return 0; }




struct passwd __passwd_pw;
char __passwd_buf[1000];





 int __dns_fd;

 int __dns_fd6;


void res_close(void) {
  if (__dns_fd!=-1) { close(__dns_fd); __dns_fd=-1; }

  if (__dns_fd6!=-1) { close(__dns_fd6); __dns_fd6=-1; }

}


 void __dns_readstartfiles(void);

int res_init(void) {
  _res.nscount=0;
  __dns_readstartfiles();
  return 0;
}
# 14136 "libc.h"
# 1 "rand_i.h" 1

 int rand_i(void) 
# 2 "rand_i.h" 3 4
                       __attribute__((__nothrow__ , __leaf__))
# 2 "rand_i.h"
                              ;
# 14137 "libc.h" 2

static char dnspacket[]="\xfe\xfe\001\000\000\001\000\000\000\000\000\000";
# 14158 "libc.h"
 void __dns_make_fd(void);
 int __dns_fd;

 int __dns_servers;
 struct sockaddr __dns_server_ips[];

 void __dns_readstartfiles(void);

int res_mkquery(int op, const char *dname, int class, int type, char* data,
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
# 14180 "libc.h" 3 4
                   0x00000040
# 14180 "libc.h"
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
# 14220 "libc.h"
# 1 "include/poll.h" 1 3 4








# 8 "include/poll.h" 3 4
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

 int poll(struct pollfd *ufds, nfds_t nfds, int timeout) __attribute__((__nothrow__ , __leaf__));



int ppoll(struct pollfd *fds, nfds_t nfds, const struct timespec *timeout, const sigset_t *sigmask) __attribute__((__nothrow__ , __leaf__));



# 14221 "libc.h" 2






 
# 14227 "libc.h"
      void __dns_make_fd(void);
 int __dns_fd;

 void __dns_make_fd6(void);
 int __dns_fd6;


 void __dns_readstartfiles(void);


int __dns_plugplay_interface;


int res_query(const char *dname, int class, int type, unsigned char *answer, int anslen) {
  unsigned char packet[512];
  int size;
  struct pollfd duh[2];




  __dns_readstartfiles();
  if ((size=res_mkquery(
# 14249 "libc.h" 3 4
                       ns_o_query
# 14249 "libc.h"
                            ,dname,class,type,0,0,0,(char*)packet,512))<0) { h_errno=
# 14249 "libc.h" 3 4
                                                                                     3
# 14249 "libc.h"
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
# 14277 "libc.h" 3 4
               10
# 14277 "libc.h"
                       ,
# 14277 "libc.h" 3 4
                        1
# 14277 "libc.h"
                                  ,
# 14277 "libc.h" 3 4
                                   IPPROTO_UDP
# 14277 "libc.h"
                                              );
   if (pnpfd==-1 && errno==
# 14278 "libc.h" 3 4
                          124
# 14278 "libc.h"
                                      ) {
     pnpfd=socket(
# 14279 "libc.h" 3 4
                 2
# 14279 "libc.h"
                        ,
# 14279 "libc.h" 3 4
                         1
# 14279 "libc.h"
                                   ,
# 14279 "libc.h" 3 4
                                    IPPROTO_UDP
# 14279 "libc.h"
                                               );
     v4pnp=1;
   }
   if (pnpfd>=0) {
     int one=1;
     fcntl(pnpfd,
# 14284 "libc.h" 3 4
                2
# 14284 "libc.h"
                       ,
# 14284 "libc.h" 3 4
                        1
# 14284 "libc.h"
                                  );
     if (!v4pnp)
       setsockopt(pnpfd,
# 14286 "libc.h" 3 4
                       IPPROTO_IPV6
# 14286 "libc.h"
                                   ,
# 14286 "libc.h" 3 4
                                    8
# 14286 "libc.h"
                                                 ,&one,sizeof one);
     setsockopt(pnpfd,
# 14287 "libc.h" 3 4
                     0
# 14287 "libc.h"
                           ,
# 14287 "libc.h" 3 4
                            12
# 14287 "libc.h"
                                      ,&one,sizeof one);
     setsockopt(pnpfd,
# 14288 "libc.h" 3 4
                     0
# 14288 "libc.h"
                           ,
# 14288 "libc.h" 3 4
                            8
# 14288 "libc.h"
                                      ,&one,sizeof one);
   }
 }

 if (!v4pnp) {
   memset(&pnpsa6,0,sizeof(pnpsa6));
   pnpsa6.sin6_family=
# 14294 "libc.h" 3 4
                     10
# 14294 "libc.h"
                             ;
   if (pnpfd!=-1) bind(pnpfd,(struct sockaddr*)&pnpsa6,sizeof(pnpsa6));
   pnpsa6.sin6_port=htons(5353);
   memcpy(&pnpsa6.sin6_addr,"\xff\x02\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xfb",16);
 }

 memset(&pnpsa4,0,sizeof(pnpsa4));
 pnpsa4.sin_family=
# 14301 "libc.h" 3 4
                  2
# 14301 "libc.h"
                         ;
 if (pnpfd!=-1) bind(pnpfd,(struct sockaddr*)&pnpsa4,sizeof(pnpsa4));
 pnpsa4.sin_port=htons(5353);
 memcpy(&pnpsa4.sin_addr,"\xe0\x00\x00\xfb",4);

 duh[1].events=
# 14306 "libc.h" 3 4
              POLLIN
# 14306 "libc.h"
                    ;
 duh[1].fd=pnpfd;
      } else {
 duh[1].fd=-1;
 duh[1].events=0;
      }


      i=0;
      duh[0].events=
# 14315 "libc.h" 3 4
                   POLLIN
# 14315 "libc.h"
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
# 14347 "libc.h" 3 4
                    10
# 14347 "libc.h"
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
# 14401 "libc.h" 3 4
                                 POLLIN
# 14401 "libc.h"
                                       ?duh[0].fd:duh[1].fd),&mh,
# 14401 "libc.h" 3 4
                                                                 0x40
# 14401 "libc.h"
                                                                             );
   if (fd==duh[1].fd) {
     unsigned short peerport;
     if (tmpsa.sin6_family==
# 14404 "libc.h" 3 4
                           10
# 14404 "libc.h"
                                   ) {
       __dns_plugplay_interface=tmpsa.sin6_scope_id;
       peerport=tmpsa.sin6_port;
     } else {
       peerport=((struct sockaddr_in*)&tmpsa)->sin_port;
     }
     for (x=
# 14410 "libc.h" 3 4
           (((
# 14410 "libc.h"
           &mh
# 14410 "libc.h" 3 4
           )->msg_controllen) >= sizeof(struct cmsghdr) ? (struct cmsghdr *)((
# 14410 "libc.h"
           &mh
# 14410 "libc.h" 3 4
           )->msg_control) : (struct cmsghdr *)(void*)0)
# 14410 "libc.h"
                             ; x; x=
# 14410 "libc.h" 3 4
                                    cmsg_nxthdr((
# 14410 "libc.h"
                                    &mh
# 14410 "libc.h" 3 4
                                    ), (
# 14410 "libc.h"
                                    x
# 14410 "libc.h" 3 4
                                    ))
# 14410 "libc.h"
                                                      )
       if ((x->cmsg_level==
# 14411 "libc.h" 3 4
                          0 
# 14411 "libc.h"
                                 && x->cmsg_type==
# 14411 "libc.h" 3 4
                                                  2
# 14411 "libc.h"
                                                        ) ||
    (x->cmsg_level==
# 14412 "libc.h" 3 4
                   IPPROTO_IPV6 
# 14412 "libc.h"
                                && x->cmsg_type==
# 14412 "libc.h" 3 4
                                                 8
# 14412 "libc.h"
                                                              )) {
  ttl=*(int*)
# 14413 "libc.h" 3 4
            ((void *)((char *)(
# 14413 "libc.h"
            x
# 14413 "libc.h" 3 4
            ) + ( ((sizeof(struct cmsghdr))+sizeof(long)-1) & ~(sizeof(long)-1) )))
# 14413 "libc.h"
                        ;
  break;
       } else if ((x->cmsg_level==
# 14415 "libc.h" 3 4
                                 0 
# 14415 "libc.h"
                                        && x->cmsg_type==
# 14415 "libc.h" 3 4
                                                         8
# 14415 "libc.h"
                                                                   ))
  __dns_plugplay_interface=((struct in_pktinfo*)(
# 14416 "libc.h" 3 4
                                                ((void *)((char *)(
# 14416 "libc.h"
                                                x
# 14416 "libc.h" 3 4
                                                ) + ( ((sizeof(struct cmsghdr))+sizeof(long)-1) & ~(sizeof(long)-1) )))
# 14416 "libc.h"
                                                            ))->ipi_ifindex;

     if ((peerport==5353 && ttl != 255) || (peerport==5355 && ttl != 1))




       continue;

     inpkg[2]=(inpkg[2]&~0x1) | (packet[2]&0x1);
   }




   if (inpkg[0]!=packet[0] || inpkg[1]!=packet[1]) continue;
   if ((inpkg[2]&0xf9) != (_res.options&
# 14432 "libc.h" 3 4
                                       0x00000040
# 14432 "libc.h"
                                                  ?0x81:0x80)) continue;
   if ((inpkg[3]&0x0f) != 0) {


     if (duh[0].revents&
# 14436 "libc.h" 3 4
                       POLLIN
# 14436 "libc.h"
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
# 14447 "libc.h" 3 4
            1
# 14447 "libc.h"
                          ;
     return -1;
   }
   if (len>anslen) {
     h_errno=
# 14451 "libc.h" 3 4
            3
# 14451 "libc.h"
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
# 14465 "libc.h" 3 4
         2
# 14465 "libc.h"
                  ;
  return -1;
}
# 14487 "libc.h"
 int __dns_search;
 char *__dns_domains[];

int res_search(const char *dname, int class, int type, unsigned char *answer, int anslen) {
  const char *tmp=dname;
  char Buf[
# 14492 "libc.h" 3 4
          1025
# 14492 "libc.h"
                  +1];
  int res;
  int len=strlen(dname);
  int count=0;
  memmove(Buf,dname,len);
  Buf[len]=Buf[
# 14497 "libc.h" 3 4
              1025
# 14497 "libc.h"
                      ]=0;

  while ((res=res_query(tmp,class,type,answer,anslen))<0) {
    if (count==__dns_search) break;
    Buf[len]='.';

    memccpy(Buf+len+1,__dns_domains[count],0,
# 14503 "libc.h" 3 4
                                            1025
# 14503 "libc.h"
                                                    -len-1);
    tmp=Buf;
    ++count;
  }
  return res;
}



# 1 "parselib.h" 1





struct state {
  const char* buffirst;
  size_t buflen;
  size_t cur;
};


void __prepare_parse(const char* filename,struct state* s);

void __fprepare_parse(int fd, struct state* s);

void __end_parse(struct state* s);



size_t __parse(struct state* s,int (*pred)(int ch));

size_t __parse_ws(struct state* s);
size_t __parse_nws(struct state* s);
size_t __parse_1(struct state* s,char c) __attribute__((__pure__));

size_t scan_ulong(const char* s,unsigned long* l);
# 14513 "libc.h" 2

size_t scan_ulong(const char* s,unsigned long* l) {
  size_t n;
  unsigned long x;
  unsigned int digit;
  for (x=n=0; (digit=(s[n]-'0'))<10u; ++n)
    x=x*10+digit;
  *l=x;
  return n;
}




int scandir(const char *dir, struct dirent ***namelist,
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
# 14548 "libc.h" 3 4
                                          255
# 14548 "libc.h"
                                                  );
      tmp[num]->d_off=D->d_off;
      tmp[num]->d_reclen=D->d_reclen;
      ++num;
      *namelist=tmp;

    }
  }
  closedir(d);
# 14568 "libc.h"
  if (compar)
    qsort(*namelist,num,sizeof(struct dirent*),(int (*)(const void*,const void*))(compar));
  return num;
}




int scandir64(const char *dir, struct dirent64 ***namelist,
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
# 14598 "libc.h" 3 4
                                            255
# 14598 "libc.h"
                                                    );
      tmp[num-1]->d_off=D->d_off;
      tmp[num-1]->d_reclen=D->d_reclen;
      tmp[num-1]->d_type=D->d_type;
      *namelist=tmp;

    }
  }
  closedir(d);
# 14618 "libc.h"
  if (compar)
    qsort(*namelist,num,sizeof(struct dirent64*),(int (*)(const void*,const void*))(compar));
  return num;
}


# 1 "dietwarning.h" 1
# 14625 "libc.h" 2


int setegid(gid_t gid);
int setegid(gid_t gid) {
  return setregid((gid_t)-1,gid);
}

asm (".section .gnu.warning." "setegid" "\n\t.string \"" "warning: you used setegid without including <unistd.h>" "\"\n\t.previous");


# 1 "dietwarning.h" 1
# 14636 "libc.h" 2


int seteuid(uid_t uid);
int seteuid(uid_t uid) {
  return setreuid((uid_t)-1,uid);
}

asm (".section .gnu.warning." "setegid" "\n\t.string \"" "warning: you used setegid without including <unistd.h>" "\"\n\t.previous");





char *setlocale (int category, const char *locale) {
  lc_ctype=CT_8BIT;
  if (locale && (category==
# 14651 "libc.h" 3 4
                          LC_ALL 
# 14651 "libc.h"
                                 || category==
# 14651 "libc.h" 3 4
                                              LC_CTYPE
# 14651 "libc.h"
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
char __shadow_buf[1000];



 const char __sys_err_unknown[];

int strerror_r(int errnum, char *buf, size_t n) {
  const char* x=
# 14676 "libc.h" 3 4
               strerror
# 14676 "libc.h"
                       (errnum);
  if (x==__sys_err_unknown || n<1) return -1;
  strncpy(buf,
# 14678 "libc.h" 3 4
             strerror
# 14678 "libc.h"
                     (errnum),n);
  buf[n-1]=0;
  return 0;
}
# 14690 "libc.h"
 int __sc_nr_cpus();

static long physpages() {
  int fd=open("/proc/meminfo",
# 14693 "libc.h" 3 4
                             0x0000
# 14693 "libc.h"
                                     );
  char buf[2048];
  size_t l;
  if (fd==-1) { errno=
# 14696 "libc.h" 3 4
                     89
# 14696 "libc.h"
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

long sysconf(int name)
{
  switch(name)
  {
  case 
# 14719 "libc.h" 3 4
      4
# 14719 "libc.h"
                  :
    {
      struct rlimit limit;
      getrlimit(
# 14722 "libc.h" 3 4
               5
# 14722 "libc.h"
                            , &limit);
      return limit.rlim_cur;
    }
  case 
# 14725 "libc.h" 3 4
      1
# 14725 "libc.h"
                 :



    return 100;


  case 
# 14732 "libc.h" 3 4
      5
# 14732 "libc.h"
                  :



    return 4096;


  case 
# 14739 "libc.h" 3 4
      7
# 14739 "libc.h"
                    :
    return physpages();

  case 
# 14742 "libc.h" 3 4
      2
# 14742 "libc.h"
                 :
    return 
# 14743 "libc.h" 3 4
          131072
# 14743 "libc.h"
                 ;

  case 
# 14745 "libc.h" 3 4
      3
# 14745 "libc.h"
                     :
    return 
# 14746 "libc.h" 3 4
          32
# 14746 "libc.h"
                     ;

  case 
# 14748 "libc.h" 3 4
      6
# 14748 "libc.h"
                          :
    {
      cpu_set_t m;
      if (sched_getaffinity(0, sizeof(m), &m))
 return __sc_nr_cpus();
      return CPU_COUNT(&m);
    }

  }
  errno=
# 14757 "libc.h" 3 4
       89
# 14757 "libc.h"
             ;
  return -1;
}
# 14779 "libc.h"
int __sc_nr_cpus(void);
int __sc_nr_cpus() {



  int fd;
  fd = open("/proc/cpuinfo", 
# 14785 "libc.h" 3 4
                            0x0000
# 14785 "libc.h"
                                    );
  if (fd==-1) return 1;
  else {
    int n,nr=0;
    char buf[2048];

    while((n=read(fd,buf,sizeof(buf)))>0) {
      register int i=0;
      while (i<n) {
# 14807 "libc.h"
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
# 14831 "libc.h"
# 1 "./dietwarning.h" 1
# 14832 "libc.h" 2

asm (".section .gnu.warning." "tempnam" "\n\t.string \"" "\e[1;33;41m>>> tempnam stinks! NEVER ! NEVER USE IT ! <<<\e[0m" "\"\n\t.previous");;

char* tempnam(char* dir,char* template) {
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

char* textdomain(const char* domainname) {
  if (dom) free(dom);
  if (!(dom=strdup(domainname))) return 0;
  return dom;
}






# 1 "./dietwarning.h" 1
# 14877 "libc.h" 2


# 1 "rand_i.h" 1

 int rand_i(void) 
# 2 "rand_i.h" 3 4
                       __attribute__((__nothrow__ , __leaf__))
# 2 "rand_i.h"
                              ;
# 14880 "libc.h" 2

asm (".section .gnu.warning." "tmpnam" "\n\t.string \"" "\e[1;33;41m>>> tmpnam stinks! NEVER ! NEVER USE IT ! <<<\e[0m" "\"\n\t.previous");;

char* tmpnam(char* s) {
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
# 14898 "libc.h" 3 4
                                    2
# 14898 "libc.h"
                                          ) break;
  }
  return tmp;
}



# 1 "include/md5.h" 1 3 4
# 28 "include/md5.h" 3 4








# 35 "include/md5.h" 3 4
typedef struct {
  uint32_t state[4];
  uint32_t count[2];
  uint8_t buffer[64];
} MD5_CTX;

void MD5Init(MD5_CTX* ctx);
void MD5Update(MD5_CTX* ctx, const uint8_t* buf, size_t len);
void MD5Final(uint8_t digest[16], MD5_CTX* ctx);

char* md5crypt(const char* pw, const char* salt);


# 14906 "libc.h" 2



# 14908 "libc.h"
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


void setkey(const char *key)
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


void encrypt(char block[64],int edflag)
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

char * crypt(const char *pw, const char *salt)
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
# 15256 "libc.h"
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
# 15280 "libc.h"
void MD5Init (MD5_CTX* context) {
   context->count[0] = 0;
   context->count[1] = 0;

   context->state[0] = 0x67452301;
   context->state[1] = 0xefcdab89;
   context->state[2] = 0x98badcfe;
   context->state[3] = 0x10325476;
}
# 15302 "libc.h"
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
# 15324 "libc.h"
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






void MD5Update (MD5_CTX *context, const uint8_t *input, size_t inputBytes) {
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




void MD5Final (uint8_t digest[16], MD5_CTX* context) {
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
# 15492 "libc.h"
static unsigned char itoa64[] =
 "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

static void to64 (char *, uint32_t, int);

static void
to64(s, v, n)
 char *s;
 uint32_t v;
 int n;
{
 while (--n >= 0) {
  *s++ = itoa64[v&0x3f];
  v >>= 6;
 }
}







char *
md5crypt(pw, salt)
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
# 15645 "libc.h"
struct sha256_ctx
{
  uint32_t H[8];

  uint32_t total[2];
  uint32_t buflen;
  char buffer[128];
};
# 15665 "libc.h"
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
sha256_process_block (const void *buffer, size_t len, struct sha256_ctx *ctx)
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
# 15742 "libc.h"
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
sha256_init_ctx (struct sha256_ctx *ctx)
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
sha256_finish_ctx (struct sha256_ctx *ctx, void *resbuf)
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
sha256_process_bytes (const void *buffer, size_t len, struct sha256_ctx *ctx)
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
# 15935 "libc.h"
static const char b64t[64] =
"./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";


static char *
sha256_crypt_r (const char *key, const char *salt, char *buffer, int buflen)
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
# 15952 "libc.h" 3 4
                    (void*)0
# 15952 "libc.h"
                        ;
  char *copied_salt = 
# 15953 "libc.h" 3 4
                     (void*)0
# 15953 "libc.h"
                         ;
  char *p_bytes;
  char *s_bytes;

  size_t rounds = 5000;
  
# 15958 "libc.h" 3 4
 _Bool 
# 15958 "libc.h"
      rounds_custom = 
# 15958 "libc.h" 3 4
                      0
# 15958 "libc.h"
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
# 15975 "libc.h" 3 4
           (((
# 15975 "libc.h"
           1000
# 15975 "libc.h" 3 4
           )>((((
# 15975 "libc.h"
           srounds
# 15975 "libc.h" 3 4
           )<(
# 15975 "libc.h"
           999999999
# 15975 "libc.h" 3 4
           ))?(
# 15975 "libc.h"
           srounds
# 15975 "libc.h" 3 4
           ):(
# 15975 "libc.h"
           999999999
# 15975 "libc.h" 3 4
           ))))?(
# 15975 "libc.h"
           1000
# 15975 "libc.h" 3 4
           ):((((
# 15975 "libc.h"
           srounds
# 15975 "libc.h" 3 4
           )<(
# 15975 "libc.h"
           999999999
# 15975 "libc.h" 3 4
           ))?(
# 15975 "libc.h"
           srounds
# 15975 "libc.h" 3 4
           ):(
# 15975 "libc.h"
           999999999
# 15975 "libc.h" 3 4
           ))))
# 15975 "libc.h"
                                                      ;
   rounds_custom = 
# 15976 "libc.h" 3 4
                  1
# 15976 "libc.h"
                      ;
 }
    }

  salt_len = 
# 15980 "libc.h" 3 4
            (((
# 15980 "libc.h"
            strcspn (salt, "$")
# 15980 "libc.h" 3 4
            )<(
# 15980 "libc.h"
            16
# 15980 "libc.h" 3 4
            ))?(
# 15980 "libc.h"
            strcspn (salt, "$")
# 15980 "libc.h" 3 4
            ):(
# 15980 "libc.h"
            16
# 15980 "libc.h" 3 4
            ))
# 15980 "libc.h"
                                                   ;
  key_len = strlen (key);

  if ((key - (char *) 0) % __alignof__ (uint32_t) != 0)
    {
      char *tmp = (char *) 
# 15985 "libc.h" 3 4
                          __builtin_alloca(
# 15985 "libc.h"
                          key_len + __alignof__ (uint32_t)
# 15985 "libc.h" 3 4
                          )
# 15985 "libc.h"
                                                                   ;
      key = copied_key =
 memcpy (tmp + __alignof__ (uint32_t)
  - (tmp - (char *) 0) % __alignof__ (uint32_t),
  key, key_len);
    }

  if ((salt - (char *) 0) % __alignof__ (uint32_t) != 0)
    {
      char *tmp = (char *) 
# 15994 "libc.h" 3 4
                          __builtin_alloca(
# 15994 "libc.h"
                          salt_len + __alignof__ (uint32_t)
# 15994 "libc.h" 3 4
                          )
# 15994 "libc.h"
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
# 16057 "libc.h" 3 4
                __builtin_alloca(
# 16057 "libc.h"
                key_len
# 16057 "libc.h" 3 4
                )
# 16057 "libc.h"
                                ;
  for (cnt = key_len; cnt >= 32; cnt -= 32)
    cp = memcpy (cp, temp_result, 32) + 32;
  memcpy (cp, temp_result, cnt);


  sha256_init_ctx (&alt_ctx);


  for (cnt = 0; cnt < 16u + alt_result[0]; ++cnt)
    sha256_process_bytes (salt, salt_len, &alt_ctx);


  sha256_finish_ctx (&alt_ctx, temp_result);


  cp = s_bytes = 
# 16073 "libc.h" 3 4
                __builtin_alloca(
# 16073 "libc.h"
                salt_len
# 16073 "libc.h" 3 4
                )
# 16073 "libc.h"
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
# 16111 "libc.h" 3 4
                                           (((
# 16111 "libc.h"
                                           0
# 16111 "libc.h" 3 4
                                           )>(
# 16111 "libc.h"
                                           buflen
# 16111 "libc.h" 3 4
                                           ))?(
# 16111 "libc.h"
                                           0
# 16111 "libc.h" 3 4
                                           ):(
# 16111 "libc.h"
                                           buflen
# 16111 "libc.h" 3 4
                                           ))
# 16111 "libc.h"
                                                          );
  buflen -= sizeof (sha256_salt_prefix) - 1;

  if (rounds_custom)
    {
      int n = snprintf (cp, 
# 16116 "libc.h" 3 4
                           (((
# 16116 "libc.h"
                           0
# 16116 "libc.h" 3 4
                           )>(
# 16116 "libc.h"
                           buflen
# 16116 "libc.h" 3 4
                           ))?(
# 16116 "libc.h"
                           0
# 16116 "libc.h" 3 4
                           ):(
# 16116 "libc.h"
                           buflen
# 16116 "libc.h" 3 4
                           ))
# 16116 "libc.h"
                                          , "%s%zu$",
   sha256_rounds_prefix, rounds);
      cp += n;
      buflen -= n;
    }

  cp = stpncpy (cp, salt, 
# 16122 "libc.h" 3 4
                         (((
# 16122 "libc.h"
                         (size_t) 
# 16122 "libc.h" 3 4
                         (((
# 16122 "libc.h"
                         0
# 16122 "libc.h" 3 4
                         )>(
# 16122 "libc.h"
                         buflen
# 16122 "libc.h" 3 4
                         ))?(
# 16122 "libc.h"
                         0
# 16122 "libc.h" 3 4
                         ):(
# 16122 "libc.h"
                         buflen
# 16122 "libc.h" 3 4
                         )))<(
# 16122 "libc.h"
                         salt_len
# 16122 "libc.h" 3 4
                         ))?(
# 16122 "libc.h"
                         (size_t) 
# 16122 "libc.h" 3 4
                         (((
# 16122 "libc.h"
                         0
# 16122 "libc.h" 3 4
                         )>(
# 16122 "libc.h"
                         buflen
# 16122 "libc.h" 3 4
                         ))?(
# 16122 "libc.h"
                         0
# 16122 "libc.h" 3 4
                         ):(
# 16122 "libc.h"
                         buflen
# 16122 "libc.h" 3 4
                         ))):(
# 16122 "libc.h"
                         salt_len
# 16122 "libc.h" 3 4
                         ))
# 16122 "libc.h"
                                                                 );
  buflen -= 
# 16123 "libc.h" 3 4
           (((
# 16123 "libc.h"
           (size_t) 
# 16123 "libc.h" 3 4
           (((
# 16123 "libc.h"
           0
# 16123 "libc.h" 3 4
           )>(
# 16123 "libc.h"
           buflen
# 16123 "libc.h" 3 4
           ))?(
# 16123 "libc.h"
           0
# 16123 "libc.h" 3 4
           ):(
# 16123 "libc.h"
           buflen
# 16123 "libc.h" 3 4
           )))<(
# 16123 "libc.h"
           salt_len
# 16123 "libc.h" 3 4
           ))?(
# 16123 "libc.h"
           (size_t) 
# 16123 "libc.h" 3 4
           (((
# 16123 "libc.h"
           0
# 16123 "libc.h" 3 4
           )>(
# 16123 "libc.h"
           buflen
# 16123 "libc.h" 3 4
           ))?(
# 16123 "libc.h"
           0
# 16123 "libc.h" 3 4
           ):(
# 16123 "libc.h"
           buflen
# 16123 "libc.h" 3 4
           ))):(
# 16123 "libc.h"
           salt_len
# 16123 "libc.h" 3 4
           ))
# 16123 "libc.h"
                                                   ;

  if (buflen > 0)
    {
      *cp++ = '$';
      --buflen;
    }
# 16143 "libc.h"
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
# 16156 "libc.h" 3 4
             34
# 16156 "libc.h"
                   ;
      buffer = 
# 16157 "libc.h" 3 4
              (void*)0
# 16157 "libc.h"
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
# 16173 "libc.h" 3 4
                   (void*)0
# 16173 "libc.h"
                       )
    memset (copied_key, '\0', key_len);
  if (copied_salt != 
# 16175 "libc.h" 3 4
                    (void*)0
# 16175 "libc.h"
                        )
    memset (copied_salt, '\0', salt_len);

  return buffer;
}




char *
sha256_crypt (const char *key, const char *salt)
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
# 16200 "libc.h" 3 4
                       (void*)0
# 16200 "libc.h"
                           )
 return 
# 16201 "libc.h" 3 4
       (void*)0
# 16201 "libc.h"
           ;

      buffer = new_buffer;
      buflen = needed;
    }

  return sha256_crypt_r (key, salt, buffer, buflen);
}
# 16368 "libc.h"
struct sha512_ctx
{
  uint64_t H[8];

  uint64_t total[2];
  uint64_t buflen;
  char buffer[256];
};
# 16395 "libc.h"
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
sha512_process_block (const void *buffer, size_t len, struct sha512_ctx *ctx)
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
# 16495 "libc.h"
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
sha512_init_ctx (struct sha512_ctx *ctx)
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
sha512_finish_ctx (struct sha512_ctx *ctx, void *resbuf)
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
sha512_process_bytes (const void *buffer, size_t len, struct sha512_ctx *ctx)
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
# 16639 "libc.h"
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
# 16691 "libc.h"
static const char b64t[64] =
"./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";


static char *
sha512_crypt_r (const char *key, const char *salt, char *buffer, int buflen)
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
# 16708 "libc.h" 3 4
                    (void*)0
# 16708 "libc.h"
                        ;
  char *copied_salt = 
# 16709 "libc.h" 3 4
                     (void*)0
# 16709 "libc.h"
                         ;
  char *p_bytes;
  char *s_bytes;

  size_t rounds = 5000;
  
# 16714 "libc.h" 3 4
 _Bool 
# 16714 "libc.h"
      rounds_custom = 
# 16714 "libc.h" 3 4
                      0
# 16714 "libc.h"
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
# 16731 "libc.h" 3 4
           (((
# 16731 "libc.h"
           1000
# 16731 "libc.h" 3 4
           )>((((
# 16731 "libc.h"
           srounds
# 16731 "libc.h" 3 4
           )<(
# 16731 "libc.h"
           999999999
# 16731 "libc.h" 3 4
           ))?(
# 16731 "libc.h"
           srounds
# 16731 "libc.h" 3 4
           ):(
# 16731 "libc.h"
           999999999
# 16731 "libc.h" 3 4
           ))))?(
# 16731 "libc.h"
           1000
# 16731 "libc.h" 3 4
           ):((((
# 16731 "libc.h"
           srounds
# 16731 "libc.h" 3 4
           )<(
# 16731 "libc.h"
           999999999
# 16731 "libc.h" 3 4
           ))?(
# 16731 "libc.h"
           srounds
# 16731 "libc.h" 3 4
           ):(
# 16731 "libc.h"
           999999999
# 16731 "libc.h" 3 4
           ))))
# 16731 "libc.h"
                                                      ;
   rounds_custom = 
# 16732 "libc.h" 3 4
                  1
# 16732 "libc.h"
                      ;
 }
    }

  salt_len = 
# 16736 "libc.h" 3 4
            (((
# 16736 "libc.h"
            strcspn (salt, "$")
# 16736 "libc.h" 3 4
            )<(
# 16736 "libc.h"
            16
# 16736 "libc.h" 3 4
            ))?(
# 16736 "libc.h"
            strcspn (salt, "$")
# 16736 "libc.h" 3 4
            ):(
# 16736 "libc.h"
            16
# 16736 "libc.h" 3 4
            ))
# 16736 "libc.h"
                                                   ;
  key_len = strlen (key);

  if ((key - (char *) 0) % __alignof__ (uint64_t) != 0)
    {
      char *tmp = (char *) 
# 16741 "libc.h" 3 4
                          __builtin_alloca(
# 16741 "libc.h"
                          key_len + __alignof__ (uint64_t)
# 16741 "libc.h" 3 4
                          )
# 16741 "libc.h"
                                                                   ;
      key = copied_key =
 memcpy (tmp + __alignof__ (uint64_t)
  - (tmp - (char *) 0) % __alignof__ (uint64_t),
  key, key_len);
    }

  if ((salt - (char *) 0) % __alignof__ (uint64_t) != 0)
    {
      char *tmp = (char *) 
# 16750 "libc.h" 3 4
                          __builtin_alloca(
# 16750 "libc.h"
                          salt_len + __alignof__ (uint64_t)
# 16750 "libc.h" 3 4
                          )
# 16750 "libc.h"
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
# 16813 "libc.h" 3 4
                __builtin_alloca(
# 16813 "libc.h"
                key_len
# 16813 "libc.h" 3 4
                )
# 16813 "libc.h"
                                ;
  for (cnt = key_len; cnt >= 64; cnt -= 64)
    cp = memcpy (cp, temp_result, 64) + 64;
  memcpy (cp, temp_result, cnt);


  sha512_init_ctx (&alt_ctx);


  for (cnt = 0; cnt < 16u + alt_result[0]; ++cnt)
    sha512_process_bytes (salt, salt_len, &alt_ctx);


  sha512_finish_ctx (&alt_ctx, temp_result);


  cp = s_bytes = 
# 16829 "libc.h" 3 4
                __builtin_alloca(
# 16829 "libc.h"
                salt_len
# 16829 "libc.h" 3 4
                )
# 16829 "libc.h"
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
# 16867 "libc.h" 3 4
                                           (((
# 16867 "libc.h"
                                           0
# 16867 "libc.h" 3 4
                                           )>(
# 16867 "libc.h"
                                           buflen
# 16867 "libc.h" 3 4
                                           ))?(
# 16867 "libc.h"
                                           0
# 16867 "libc.h" 3 4
                                           ):(
# 16867 "libc.h"
                                           buflen
# 16867 "libc.h" 3 4
                                           ))
# 16867 "libc.h"
                                                          );
  buflen -= sizeof (sha512_salt_prefix) - 1;

  if (rounds_custom)
    {
      int n = snprintf (cp, 
# 16872 "libc.h" 3 4
                           (((
# 16872 "libc.h"
                           0
# 16872 "libc.h" 3 4
                           )>(
# 16872 "libc.h"
                           buflen
# 16872 "libc.h" 3 4
                           ))?(
# 16872 "libc.h"
                           0
# 16872 "libc.h" 3 4
                           ):(
# 16872 "libc.h"
                           buflen
# 16872 "libc.h" 3 4
                           ))
# 16872 "libc.h"
                                          , "%s%zu$",
   sha512_rounds_prefix, rounds);
      cp += n;
      buflen -= n;
    }

  cp = stpncpy (cp, salt, 
# 16878 "libc.h" 3 4
                         (((
# 16878 "libc.h"
                         (size_t) 
# 16878 "libc.h" 3 4
                         (((
# 16878 "libc.h"
                         0
# 16878 "libc.h" 3 4
                         )>(
# 16878 "libc.h"
                         buflen
# 16878 "libc.h" 3 4
                         ))?(
# 16878 "libc.h"
                         0
# 16878 "libc.h" 3 4
                         ):(
# 16878 "libc.h"
                         buflen
# 16878 "libc.h" 3 4
                         )))<(
# 16878 "libc.h"
                         salt_len
# 16878 "libc.h" 3 4
                         ))?(
# 16878 "libc.h"
                         (size_t) 
# 16878 "libc.h" 3 4
                         (((
# 16878 "libc.h"
                         0
# 16878 "libc.h" 3 4
                         )>(
# 16878 "libc.h"
                         buflen
# 16878 "libc.h" 3 4
                         ))?(
# 16878 "libc.h"
                         0
# 16878 "libc.h" 3 4
                         ):(
# 16878 "libc.h"
                         buflen
# 16878 "libc.h" 3 4
                         ))):(
# 16878 "libc.h"
                         salt_len
# 16878 "libc.h" 3 4
                         ))
# 16878 "libc.h"
                                                                 );
  buflen -= 
# 16879 "libc.h" 3 4
           (((
# 16879 "libc.h"
           (size_t) 
# 16879 "libc.h" 3 4
           (((
# 16879 "libc.h"
           0
# 16879 "libc.h" 3 4
           )>(
# 16879 "libc.h"
           buflen
# 16879 "libc.h" 3 4
           ))?(
# 16879 "libc.h"
           0
# 16879 "libc.h" 3 4
           ):(
# 16879 "libc.h"
           buflen
# 16879 "libc.h" 3 4
           )))<(
# 16879 "libc.h"
           salt_len
# 16879 "libc.h" 3 4
           ))?(
# 16879 "libc.h"
           (size_t) 
# 16879 "libc.h" 3 4
           (((
# 16879 "libc.h"
           0
# 16879 "libc.h" 3 4
           )>(
# 16879 "libc.h"
           buflen
# 16879 "libc.h" 3 4
           ))?(
# 16879 "libc.h"
           0
# 16879 "libc.h" 3 4
           ):(
# 16879 "libc.h"
           buflen
# 16879 "libc.h" 3 4
           ))):(
# 16879 "libc.h"
           salt_len
# 16879 "libc.h" 3 4
           ))
# 16879 "libc.h"
                                                   ;

  if (buflen > 0)
    {
      *cp++ = '$';
      --buflen;
    }
# 16899 "libc.h"
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
# 16924 "libc.h" 3 4
             34
# 16924 "libc.h"
                   ;
      buffer = 
# 16925 "libc.h" 3 4
              (void*)0
# 16925 "libc.h"
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
# 16941 "libc.h" 3 4
                   (void*)0
# 16941 "libc.h"
                       )
    memset (copied_key, '\0', key_len);
  if (copied_salt != 
# 16943 "libc.h" 3 4
                    (void*)0
# 16943 "libc.h"
                        )
    memset (copied_salt, '\0', salt_len);

  return buffer;
}




char *
sha512_crypt (const char *key, const char *salt)
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
# 16968 "libc.h" 3 4
                       (void*)0
# 16968 "libc.h"
                           )
 return 
# 16969 "libc.h" 3 4
       (void*)0
# 16969 "libc.h"
           ;

      buffer = new_buffer;
      buflen = needed;
    }

  return sha512_crypt_r (key, salt, buffer, buflen);
}
# 17143 "libc.h"
# 1 "include/libgen.h" 1 3 4








# 8 "include/libgen.h" 3 4
char *dirname(char *path) __attribute__((__nothrow__ , __leaf__));
char *basename(char *path) __attribute__((__nothrow__ , __leaf__));


# 17144 "libc.h" 2
# 17155 "libc.h"

# 17155 "libc.h"
char *basename(char *path) {
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
# 17183 "libc.h"
static char *dot=".";


char *dirname(char *path)
{
  char *c;
  if ( path == 
# 17189 "libc.h" 3 4
               (void*)0 
# 17189 "libc.h"
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

# 1 "include/fnmatch.h" 1 3 4








# 8 "include/fnmatch.h" 3 4
int fnmatch(const char *pattern, const char *string, int flags) __attribute__((__nothrow__ , __leaf__));
# 19 "include/fnmatch.h" 3 4

# 17205 "libc.h" 2







# 17211 "libc.h"
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
# 17242 "libc.h" 3 4
        (void*)0
# 17242 "libc.h"
            ;
}

static int match(char c,char d,int flags) {
  if (flags&
# 17246 "libc.h" 3 4
           16
# 17246 "libc.h"
                       )
    return (tolower(c)==tolower(d));
  else
    return (c==d);
}

int fnmatch(const char *pattern, const char *string, int flags) {
  if (*string==0) {
    while (*pattern=='*') ++pattern;
    return (!!*pattern);
  }
  if (*string=='.' && *pattern!='.' && (flags&
# 17257 "libc.h" 3 4
                                             4
# 17257 "libc.h"
                                                       )) {

    if (!(flags&128))
      return 
# 17260 "libc.h" 3 4
            1
# 17260 "libc.h"
                       ;

    if ((flags&(
# 17262 "libc.h" 3 4
               2
# 17262 "libc.h"
                           )) && string[-1]=='/')
      return 
# 17263 "libc.h" 3 4
            1
# 17263 "libc.h"
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
# 17273 "libc.h" 3 4
                               2
# 17273 "libc.h"
                                           ) return 
# 17273 "libc.h" 3 4
                                                    1
# 17273 "libc.h"
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
# 17286 "libc.h" 3 4
            16
       
# 17287 "libc.h"
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
# 17297 "libc.h" 3 4
              16
# 17297 "libc.h"
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
# 17311 "libc.h" 3 4
         1
# 17311 "libc.h"
                    ;
      }
    }
    break;
  case '\\':
    if (flags&
# 17316 "libc.h" 3 4
             1
# 17316 "libc.h"
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
# 17325 "libc.h" 3 4
                              2
# 17325 "libc.h"
                                          ) || fnmatch(pattern,string+1,flags))
      return fnmatch(pattern+1,string,flags);
    return 0;
  case 0:
    if (*string==0 || (*string=='/' && (flags&
# 17329 "libc.h" 3 4
                                             8
# 17329 "libc.h"
                                                            )))
      return 0;
    break;
  case '?':
    if (*string=='/' && flags&
# 17333 "libc.h" 3 4
                             2
# 17333 "libc.h"
                                         ) break;
    return fnmatch(pattern+1,string+1,flags);
  default:
    if (match(*pattern,*string,flags))
      return fnmatch(pattern+1,string+1,flags);
    break;
  }
  return 
# 17340 "libc.h" 3 4
        1
# 17340 "libc.h"
                   ;
}
# 17370 "libc.h"
# 1 "include/glob.h" 1 3 4









# 9 "include/glob.h" 3 4
typedef struct {
 size_t gl_pathc;
 char **gl_pathv;
 size_t gl_offs;
 int gl_flags;
} glob_t;


int glob(const char *pattern, int flags,
  int errfunc(const char * epath, int eerrno),
  glob_t *pglob) __attribute__((__nothrow__ , __leaf__));

void globfree(glob_t *pglob) __attribute__((__nothrow__ , __leaf__));
# 58 "include/glob.h" 3 4

# 17371 "libc.h" 2





# 17375 "libc.h"
static int cmp_func(const void * a, const void * b)
{
 const char *const s1 = *(const char *const * const) a;
 const char *const s2 = *(const char *const * const) b;
 if (s1 == 
# 17379 "libc.h" 3 4
          (void*)0
# 17379 "libc.h"
              )
  return 1;
 if (s2 == 
# 17381 "libc.h" 3 4
          (void*)0
# 17381 "libc.h"
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
# 17403 "libc.h" 3 4
                        (void*)0
# 17403 "libc.h"
                            )
    return 1;
  pglob->gl_pathv[pglob->gl_offs + pglob->gl_pathc] = strdup(name);
  pglob->gl_pathv[pglob->gl_offs + pglob->gl_pathc + 1] = 
# 17406 "libc.h" 3 4
                                                         (void*)0
# 17406 "libc.h"
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
# 17435 "libc.h" 3 4
              20
      
# 17436 "libc.h"
     && ((errfunc != 
# 17436 "libc.h" 3 4
                     (void*)0 
# 17436 "libc.h"
                          && (*errfunc) (directory, errno))
   || (flags & 
# 17437 "libc.h" 3 4
              (1 << 0)
# 17437 "libc.h"
                      )))
        return 
# 17438 "libc.h" 3 4
              2
# 17438 "libc.h"
                          ;
 } else {
  int fnm_flags = ((!(flags & 
# 17440 "libc.h" 3 4
                             (1 << 7)
# 17440 "libc.h"
                                        ) ? 
# 17440 "libc.h" 3 4
                                            4 
# 17440 "libc.h"
                                                       : 0)
     | ((flags & 
# 17441 "libc.h" 3 4
                (1 << 6)
# 17441 "libc.h"
                             ) ? 
# 17441 "libc.h" 3 4
                                 1 
# 17441 "libc.h"
                                              : 0));
  struct dirent *ep;
  while ((ep = readdir(dp))) {
   i = strlen(directory) + strlen(ep->d_name) + 2;
   ptr = (char *) 
# 17445 "libc.h" 3 4
                 __builtin_alloca(
# 17445 "libc.h"
                 i
# 17445 "libc.h" 3 4
                 )
# 17445 "libc.h"
                          ;
   build_fullname(ptr, directory, ep->d_name);
   if (flags & 
# 17447 "libc.h" 3 4
              (1 << 13)
# 17447 "libc.h"
                          ) {
    struct stat statr;
    if (stat(ptr, &statr) || !
# 17449 "libc.h" 3 4
                             (((
# 17449 "libc.h"
                             statr.st_mode
# 17449 "libc.h" 3 4
                             ) & 00170000) == 0040000)
# 17449 "libc.h"
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
# 17462 "libc.h" 3 4
                 (1 << 4)
# 17462 "libc.h"
                             ) {

  i = strlen(directory) + strlen(pattern) + 2;
  ptr = (char *) 
# 17465 "libc.h" 3 4
                __builtin_alloca(
# 17465 "libc.h"
                i
# 17465 "libc.h" 3 4
                )
# 17465 "libc.h"
                         ;
  build_fullname(ptr, directory, pattern);
  if (add_entry(ptr,pglob,&nfound))
   goto memory_error;
 }

 return (nfound == 0) ? 
# 17471 "libc.h" 3 4
                       3 
# 17471 "libc.h"
                                    : 0;

 memory_error:



 close_dir_keep_errno(dp);
 return 
# 17478 "libc.h" 3 4
       1
# 17478 "libc.h"
                   ;
}



int glob(const char *pattern, int flags, int errfunc(const char * epath, int eerrno), glob_t *pglob)
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
# 17495 "libc.h" 3 4
               (void*)0 
# 17495 "libc.h"
                    || pglob == 
# 17495 "libc.h" 3 4
                                (void*)0 
# 17495 "libc.h"
                                     || (flags & ~
# 17495 "libc.h" 3 4
                                                  ((1 << 0)|(1 << 1)|(1 << 2)|(1 << 3)| (1 << 6)|(1 << 4)|(1 << 5)| (1 << 7)|(1 << 9)|(1 << 10)| (1 << 11)|(1 << 12)|(1 << 13)|(1 << 14))
# 17495 "libc.h"
                                                              ) != 0) {
  errno=
# 17496 "libc.h" 3 4
       22
# 17496 "libc.h"
             ;
  return -1;
 }

 if (!(flags & 
# 17500 "libc.h" 3 4
              (1 << 3)
# 17500 "libc.h"
                         ))
  pglob->gl_offs = 0;





 pattern_ = 
# 17507 "libc.h" 3 4
           __builtin_alloca(
# 17507 "libc.h"
           strlen(pattern) + 1
# 17507 "libc.h" 3 4
           )
# 17507 "libc.h"
                                      ;
 strcpy(pattern_, pattern);


 if ((flags & (
# 17511 "libc.h" 3 4
              (1 << 12)
# 17511 "libc.h"
                        |
# 17511 "libc.h" 3 4
                         (1 << 14)
# 17511 "libc.h"
                                         )) && pattern_[0] == '~') {
  char * home_dir = 
# 17512 "libc.h" 3 4
                   (void*)0
# 17512 "libc.h"
                       ;
  if (pattern_[1] == '\0' || pattern_[1] == '/') {

   home_dir = getenv("HOME");
  } else {

   struct passwd * p;
   ptr2 = 
# 17519 "libc.h" 3 4
         __builtin_alloca(
# 17519 "libc.h"
         strlen(pattern_) + 1
# 17519 "libc.h" 3 4
         )
# 17519 "libc.h"
                                     ;
   strcpy(ptr2, pattern_ + 1);
   ptr = strchr(ptr2, '/');
   if (ptr != 
# 17522 "libc.h" 3 4
             (void*)0
# 17522 "libc.h"
                 )
    *ptr = '\0';
   if (((p = getpwnam(ptr2)) != 
# 17524 "libc.h" 3 4
                               (void*)0
# 17524 "libc.h"
                                   ))
    home_dir = p->pw_dir;
  }
  if (home_dir != 
# 17527 "libc.h" 3 4
                 (void*)0
# 17527 "libc.h"
                     ) {
   i = strlen(home_dir) + strlen(pattern_);
   ptr = 
# 17529 "libc.h" 3 4
        __builtin_alloca(
# 17529 "libc.h"
        i
# 17529 "libc.h" 3 4
        )
# 17529 "libc.h"
                 ;
   strncpy(ptr, home_dir, i);
   ptr2 = pattern_ + 1;
   while (*ptr2 != '/' && *ptr2 != '\0')
    ptr2++;
   strncat(ptr, ptr2, i);
   pattern_ = ptr;
  } else if (flags & 
# 17536 "libc.h" 3 4
                    (1 << 14)
# 17536 "libc.h"
                                    )
   return 
# 17537 "libc.h" 3 4
         3
# 17537 "libc.h"
                     ;
 }


 filename = strrchr(pattern_, '/');

 if (filename == 
# 17543 "libc.h" 3 4
                (void*)0
# 17543 "libc.h"
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
# 17559 "libc.h" 3 4
                            (1 << 1)
# 17559 "libc.h"
                                     , errfunc, pglob);
   if (j == 0)
    pglob->gl_flags = ((pglob->gl_flags & ~
# 17561 "libc.h" 3 4
                                          (1 << 1)
# 17561 "libc.h"
                                                   )
         | (flags & 
# 17562 "libc.h" 3 4
                   (1 << 1)
# 17562 "libc.h"
                            ));
   return j;
  }
 }



 if (!(flags & 
# 17569 "libc.h" 3 4
              (1 << 5)
# 17569 "libc.h"
                         )) {
  pglob->gl_pathc = 0;
  if (!(flags & 
# 17571 "libc.h" 3 4
               (1 << 3)
# 17571 "libc.h"
                          ))
   pglob->gl_pathv = 
# 17572 "libc.h" 3 4
                    (void*)0
# 17572 "libc.h"
                        ;
  else {
   pglob->gl_pathv = (char **) malloc((pglob->gl_offs + 1) * sizeof (char *));
   if (pglob->gl_pathv == 
# 17575 "libc.h" 3 4
                         (void*)0
# 17575 "libc.h"
                             )
    return 
# 17576 "libc.h" 3 4
          1
# 17576 "libc.h"
                      ;
   for (i = 0; i <= pglob->gl_offs; i++)
    pglob->gl_pathv[i] = 
# 17578 "libc.h" 3 4
                        (void*)0
# 17578 "libc.h"
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
# 17599 "libc.h" 3 4
                              (1 << 0) 
# 17599 "libc.h"
                                       | 
# 17599 "libc.h" 3 4
                                         (1 << 4) 
# 17599 "libc.h"
                                                      | 
# 17599 "libc.h" 3 4
                                                        (1 << 6) 
# 17599 "libc.h"
                                                                      | 
# 17599 "libc.h" 3 4
                                                                        (1 << 9)
# 17599 "libc.h"
                                                                                       ))
       | 
# 17600 "libc.h" 3 4
        (1 << 2) 
# 17600 "libc.h"
                    | 
# 17600 "libc.h" 3 4
                      (1 << 13)
# 17600 "libc.h"
                                  ),
    errfunc, &dirs);
  if (j != 0)
   return j;




  for (i = 0; i < dirs.gl_pathc; i++) {
   j = glob_in_dir(filename, dirs.gl_pathv[i], ((flags | 
# 17609 "libc.h" 3 4
                                                        (1 << 5)
# 17609 "libc.h"
                                                                   ) & ~
# 17609 "libc.h" 3 4
                                                                        (1 << 4)
# 17609 "libc.h"
                                                                                    ),
     errfunc, pglob);
   if (j == 
# 17611 "libc.h" 3 4
           3
# 17611 "libc.h"
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
# 17628 "libc.h" 3 4
              (1 << 4)
# 17628 "libc.h"
                          )
   {
    for (i = 0; i < dirs.gl_pathc; i++) {
     if (stat(dirs.gl_pathv[i], &statr) || !
# 17631 "libc.h" 3 4
                                           (((
# 17631 "libc.h"
                                           statr.st_mode
# 17631 "libc.h" 3 4
                                           ) & 00170000) == 0040000)
# 17631 "libc.h"
                                                                 )
      continue;


     j = pglob->gl_pathc + pglob->gl_offs;
     pglob->gl_pathv = (char **) realloc(pglob->gl_pathv, (j + 2) * sizeof (char *));
     if (pglob->gl_pathv == 
# 17637 "libc.h" 3 4
                           (void*)0
# 17637 "libc.h"
                               ) {
      globfree (&dirs);
      return 
# 17639 "libc.h" 3 4
            1
# 17639 "libc.h"
                        ;
     }


     k = strlen(dirs.gl_pathv[i]) + strlen(filename) + 2;
     if ((pglob->gl_pathv[j] = malloc(k)) == 
# 17644 "libc.h" 3 4
                                            (void*)0
# 17644 "libc.h"
                                                ) {
      globfree(&dirs);
      globfree(pglob);
      return 
# 17647 "libc.h" 3 4
            1
# 17647 "libc.h"
                        ;
     }
     build_fullname(pglob->gl_pathv[j], dirs.gl_pathv[i], filename);
     pglob->gl_pathc++;
     pglob->gl_pathv[j+1] = 
# 17651 "libc.h" 3 4
                           (void*)0
# 17651 "libc.h"
                               ;
    }
   } else {
    globfree(&dirs);
    return 
# 17655 "libc.h" 3 4
          3
# 17655 "libc.h"
                      ;
   }
  }

  globfree (&dirs);
 }


 if (flags & 
# 17663 "libc.h" 3 4
            (1 << 1)
# 17663 "libc.h"
                     ) {
  for (i = oldcount; i < pglob->gl_pathc + pglob->gl_offs; i++)
   if (!stat(pglob->gl_pathv[i], &statr) && 
# 17665 "libc.h" 3 4
                                           (((
# 17665 "libc.h"
                                           statr.st_mode
# 17665 "libc.h" 3 4
                                           ) & 00170000) == 0040000)
# 17665 "libc.h"
                                                                 ) {
    size_t len = strlen(pglob->gl_pathv[i]) + 2;
    ptr = realloc(pglob->gl_pathv[i], len);
    if (ptr == 
# 17668 "libc.h" 3 4
              (void*)0
# 17668 "libc.h"
                  ) {
     globfree(pglob);
     return 
# 17670 "libc.h" 3 4
           1
# 17670 "libc.h"
                       ;
    }
    strcpy(&ptr[len - 2], "/");
    pglob->gl_pathv[i] = ptr;
   }
 }

 if (!(flags & 
# 17677 "libc.h" 3 4
              (1 << 2)
# 17677 "libc.h"
                         )) {
  qsort(&pglob->gl_pathv[oldcount],
        pglob->gl_pathc + pglob->gl_offs - oldcount,
        sizeof(char *), cmp_func);
 }

 return 0;
}



void globfree (glob_t * pglob)
{
  if (pglob->gl_pathv != 
# 17690 "libc.h" 3 4
                        (void*)0
# 17690 "libc.h"
                            ) {
      size_t i;
      for (i = 0; i < pglob->gl_pathc; i++)
       if (pglob->gl_pathv[pglob->gl_offs + i] != 
# 17693 "libc.h" 3 4
                                                 (void*)0
# 17693 "libc.h"
                                                     )
        free((void *) pglob->gl_pathv[pglob->gl_offs + i]);
      free((void *) pglob->gl_pathv);
  }
}
# 17707 "libc.h"
static char* myrealpath(const char* file, char* dest, int count) {

  char buf[
# 17709 "libc.h" 3 4
          4095
# 17709 "libc.h"
                  +1];
  char* c;
  int i;

  if (count<0) { errno=
# 17713 "libc.h" 3 4
                      31
# 17713 "libc.h"
                            ; return 0; }
  if (chdir(file)==0)

    return getcwd(dest,
# 17716 "libc.h" 3 4
                      4095
# 17716 "libc.h"
                              );

  c=strrchr(file,'/');
  if (c) {
    if (c-file>
# 17720 "libc.h" 3 4
              4095
# 17720 "libc.h"
                      ) return 0;
    memcpy(buf,file,c-file);
    buf[c-file]=0;
    if (chdir(buf)==-1) return 0;
    file=c+1;
  }
  if (readlink(file,buf,
# 17726 "libc.h" 3 4
                       4095
# 17726 "libc.h"
                               )==0)
    return myrealpath(buf,dest,count-1);
  if (getcwd(dest,
# 17728 "libc.h" 3 4
                 4095
# 17728 "libc.h"
                         )==0) return 0;
  i=strlen(dest); dest[i]='/'; ++i;
  for (; i<
# 17730 "libc.h" 3 4
          4095
# 17730 "libc.h"
                  -1; ++i) {
    if (!(dest[i]=*file)) break;
    ++file;
  }
  dest[i]=0;
  return dest;
}

char* realpath(const char* file, char* dest) {
  int fd=open(".",
# 17739 "libc.h" 3 4
                 0x0000
# 17739 "libc.h"
                         );
  char* res;
  if (!dest) dest=malloc(
# 17741 "libc.h" 3 4
                        4095
# 17741 "libc.h"
                                +1);
  if (!dest) return 
# 17742 "libc.h" 3 4
                   (void*)0
# 17742 "libc.h"
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

int __dtostr(double d,char *buf,unsigned int maxlen,unsigned int prec,unsigned int prec2,int flags) {

  union {
    unsigned long long l;
    double d;
  } u = { .d=d };

  signed long e=((u.l>>52)&((1<<11)-1))-1023;
# 17781 "libc.h"
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


# 1 "syscalls.h" 1
# 25 "syscalls.h"
# 1 "mips/syscalls.h" 1
# 26 "syscalls.h" 2
# 17910 "libc.h" 2
# 17931 "libc.h"
 int __dietlibc_fcntl64(int __fd, int cmd, ...);

int fcntl64(int fd, int cmd, ...) {
  va_list va;
  
# 17935 "libc.h" 3 4
 __builtin_va_start((
# 17935 "libc.h"
 va
# 17935 "libc.h" 3 4
 ),(
# 17935 "libc.h"
 cmd
# 17935 "libc.h" 3 4
 ))
# 17935 "libc.h"
                 ;
  switch (cmd) {
  case 
# 17937 "libc.h" 3 4
      14
# 17937 "libc.h"
             :
  case 
# 17938 "libc.h" 3 4
      6
# 17938 "libc.h"
             :
  case 
# 17939 "libc.h" 3 4
      7
# 17939 "libc.h"
              :
    {
      struct flock64* x = 
# 17941 "libc.h" 3 4
                         __builtin_va_arg
# 17941 "libc.h"
                               (va,struct flock64*);
      struct flock tmp;
      int res;
      if ((res=__dietlibc_fcntl64(fd,cmd,x))) {
 if (errno!=
# 17945 "libc.h" 3 4
           89
# 17945 "libc.h"
                 ) return -1;
 tmp.l_type=x->l_type;
 tmp.l_whence=x->l_whence;
 tmp.l_start=x->l_start;
 tmp.l_len=x->l_len;
 tmp.l_pid=x->l_pid;
 if (tmp.l_len != x->l_len || tmp.l_start != x->l_start) {
   errno=
# 17952 "libc.h" 3 4
        79
# 17952 "libc.h"
                 ;
   return -1;
 }
 res=fcntl(fd,cmd,&tmp);
 if (cmd==
# 17956 "libc.h" 3 4
         14
# 17956 "libc.h"
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
# 17969 "libc.h" 3 4
                __builtin_va_arg
# 17969 "libc.h"
                      (va,long);
      int res;
      if ((res=__dietlibc_fcntl64(fd,cmd,arg))==-1) {
 if (errno!=
# 17972 "libc.h" 3 4
           89
# 17972 "libc.h"
                 ) return -1;
 return fcntl(fd,cmd,arg);
      }
      return res;
    }
  }
}
# 17987 "libc.h"
 int __dietlibc_fstat64(int __fd, struct stat64 *__buf);
 void __stat64_cvt(const struct stat *src,struct stat64 *dest);

int fstat64(int __fd, struct stat64 *__buf) {
  if (__dietlibc_fstat64(__fd,__buf)) {
    struct stat temp;
    if (errno!=
# 17993 "libc.h" 3 4
              89
# 17993 "libc.h"
                    ) return -1;
    if (fstat(__fd,&temp)) return -1;
    __stat64_cvt(&temp,__buf);
  }
  return 0;
}
