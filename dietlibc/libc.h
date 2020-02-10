#include <math.h>

int finite(double d) {
  return isinf(d)==0 && isnan(d)==0;
}

int __finite(double d) __attribute__((const, nothrow, leaf, alias("finite")));
#define _ATFILE_SOURCE
#include <errno.h>
#include "dietfeatures.h"
#include "syscalls.h"

#if defined(__NR_fstatat64) && defined(__NR_fstatat)

#ifdef WANT_LARGEFILE_BACKCOMPAT
#include <sys/stat.h>
#include <fcntl.h>
#ifndef __NO_STAT64

extern int __dietlibc_fstatat64(int dirfd, const char* pathname, struct stat64 *buf, int flags);
extern void __stat64_cvt(const struct stat *src,struct stat64 *dest);

int fstatat64(int dirfd, const char* pathname, struct stat64 *buf, int flags) {
  if (__dietlibc_fstatat64(dirfd,pathname,buf,flags)) {
    struct stat temp;
    if (errno!=ENOSYS) return -1;
    if (fstatat(dirfd,pathname,&temp,flags)) return -1;
    __stat64_cvt(&temp,buf);
  }
  return 0;
}
#endif
#endif

#elif defined(__NR_fstatat64) && !defined(__NR_fstatat)

#include <sys/stat.h>
#include <fcntl.h>
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
      errno=EOVERFLOW;
  }
  return 0;
}

#endif
#include <errno.h>
#include "dietfeatures.h"
#include <sys/statfs.h>

#if __WORDSIZE == 32

extern int __dietlibc_fstatfs64(int fd, size_t bufsize, struct statfs64 *__buf);
extern void __statfs64_cvt(const struct statfs *src,struct statfs64 *dest);

int fstatfs64(int fd, struct statfs64 *__buf) {
#ifdef WANT_LARGEFILE_BACKCOMPAT
  if (__dietlibc_fstatfs64(fd,sizeof(*__buf),__buf)) {
    struct statfs temp;
    if (errno!=ENOSYS) return -1;
    if (fstatfs(fd,&temp)) return -1;
    __statfs64_cvt(&temp,__buf);
  }
  return 0;
#else
  return __dietlibc_fstatfs64(fd,sizeof(*__buf),__buf);
#endif
}
#endif
#include <errno.h>
#include "dietfeatures.h"
#ifdef WANT_LARGEFILE_BACKCOMPAT
#include <sys/stat.h>
#include "syscalls.h"
#include <unistd.h>
#ifndef __NO_STAT64
#ifdef __NR_ftruncate64

extern int __dietlibc_ftruncate64(int fd, loff_t o);

int ftruncate64(int fd, loff_t o) {
  int tmp;
  if ((tmp=__dietlibc_ftruncate64(fd,o))==-1) {
    if (errno!=ENOSYS) return -1;
    if (o>0x7fffffff) { errno=EOVERFLOW; return -1; }
    return ftruncate(fd,o);
  }
  return tmp;
}
#endif
#endif
#endif
#include <sys/tls.h>

tcbhead_t* __get_cur_tcb(void) {
#if defined(__alpha__)
  register void* cur asm("$0");
  asm("call_pal 158" : "=r"(cur) );	/* PAL_rduniq = 158 */
#else	/* alpha */
  register void* cur=0;
#if defined(__sparc__)
  asm("mov %%g6,%0" : "=r"(cur) );	/* %g6 (res. system use) is used as thread pointer */
#elif defined(__s390__)
  asm("ear %0,%%a0" : "=d"(cur) );	/* a0 (access register 0) is used as thread pointer */
#elif defined(__ia64__)
  asm("mov %0 = r13" : "=r"(cur) );	/* r13 (tp) is used as thread pointer */
#elif defined(__x86_64__)
#ifdef __ILP32__
  asm("movl %%fs:(0),%0" : "=r"(cur));
#else
  asm("movq %%fs:(0),%0" : "=r"(cur));
#endif
#elif defined(__i386__)
  asm("movl %%gs:(0),%0" : "=r"(cur));
#endif
#endif /* __alpha__ */
  return cur;
}
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

extern int __syscall_getcwd(char* buf, size_t size);

char *getcwd(char *buf, size_t size) {
  if (__unlikely(!size)) {
    errno=EINVAL;
    buf=0;
  } else {
    int tmp;
    if ((tmp=__syscall_getcwd(buf,size-1))<0) return 0;
    buf[tmp]=0;
  }
  return buf;
}
#include <sys/inotify.h>
#include "syscalls.h"

#if defined(__NR_inotify_init1) && !defined(__NR_inotify_init)
int inotify_init() {
  return inotify_init1(0);
}
#endif
#include <math.h>

int isinf(double d) {
  union {
    unsigned long long l;
    double d;
  } u;
  u.d=d;
  return (u.l==0x7FF0000000000000ll?1:u.l==0xFFF0000000000000ll?-1:0);
}
int __isinf(double d) __attribute__((const, nothrow, leaf, alias("isinf")));

#if 0
TestFromIeeeExtended("7FFF0000000000000000");   /* +infinity */
TestFromIeeeExtended("FFFF0000000000000000");   /* -infinity */
TestFromIeeeExtended("7FFF8001000000000000");   /* Quiet NaN(1) */
TestFromIeeeExtended("7FFF0001000000000000");   /* Signalling NaN(1) */
TestFromIeeeExtended("3FFFFEDCBA9876543210");   /* accuracy test */
#endif
#include <math.h>

int isnan(double d) {
  union {
    unsigned long long l;
    double d;
  } u;
  u.d=d;
  return (u.l==0x7FF8000000000000ll || u.l==0x7FF0000000000000ll || u.l==0xfff8000000000000ll);
}
int __isnan(double d) __attribute__((const, nothrow, leaf, alias("isnan")));

#if 0
TestFromIeeeExtended("7FFF0000000000000000");   /* +infinity */
TestFromIeeeExtended("FFFF0000000000000000");   /* -infinity */
TestFromIeeeExtended("7FFF8001000000000000");   /* Quiet NaN(1) */
TestFromIeeeExtended("7FFF0001000000000000");   /* Signalling NaN(1) */
TestFromIeeeExtended("3FFFFEDCBA9876543210");   /* accuracy test */
#endif
#include <string.h>

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
#include <errno.h>
#include "dietfeatures.h"
#ifdef WANT_LARGEFILE_BACKCOMPAT
#include <sys/stat.h>
#ifndef __NO_STAT64

extern int __dietlibc_lstat64(const char *__file, struct stat64 *__buf);
extern void __stat64_cvt(const struct stat *src,struct stat64 *dest);

int lstat64(const char *__file, struct stat64 *__buf) {
  if (__dietlibc_lstat64(__file,__buf)) {
    struct stat temp;
    if (errno!=ENOSYS) return -1;
    if (lstat(__file,&temp)) return -1;
    __stat64_cvt(&temp,__buf);
  }
  return 0;
}
#endif
#endif
#include <string.h>
#include <stdlib.h>

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
#include <errno.h>
#include <sys/mman.h>
#include <syscalls.h>

#ifndef __NR_mmap
void*__mmap2(void*start,size_t length,int prot,int flags,int fd,off_t
pgoffset);
void *mmap(void *addr, size_t length, int prot, int flags, int fd,
          off_t offset)
{
  size_t pgsz = 4096;	/* TODO: fix for dynamic PAGESIZEs needed? */
  void *res;

  if (__unlikely(offset & (pgsz - 1))) {
    errno = -EINVAL;
    res = MAP_FAILED;
  } else
    res = __mmap2(addr, length, prot, flags, fd, offset / pgsz);
  return res;
}
#endif

/* we need this because we need to use the glibc prototype which uses
 * varargs :-( */
#include <errno.h>
#define ptrace fnord
#include <sys/ptrace.h>
#undef ptrace
#include <sys/types.h>
#include <unistd.h>

extern int __diet_ptrace(int request, pid_t pid, void *addr, void *data);
int ptrace(int request, pid_t pid, void *addr, void *data);

int ptrace(int request, pid_t pid, void *addr, void *data) {
  errno=0;
  switch (request) {
    case PTRACE_TRACEME: case PTRACE_KILL: case PTRACE_ATTACH:
    case PTRACE_DETACH:
      return (__diet_ptrace (request, pid, NULL, NULL));
    case PTRACE_PEEKDATA: case PTRACE_PEEKUSER: case PTRACE_PEEKTEXT:
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
#define _GNU_SOURCE
#include <sched.h>

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
#include <errno.h>
#include "dietfeatures.h"
#ifdef WANT_LARGEFILE_BACKCOMPAT
#include <sys/sendfile.h>
#ifndef __NO_STAT64

extern ssize_t __dietlibc_sendfile64 (int out_fd, int in_fd, loff_t* offset,
			   size_t count);

ssize_t sendfile64 (int out_fd, int in_fd, loff_t* offset, size_t count) {
  static int havesendfile64=1;
  ssize_t r = -1;
  if (havesendfile64) {
    r=__dietlibc_sendfile64(out_fd,in_fd,offset,count);
    if (r==-1 && errno==ENOSYS)
      havesendfile64=0;
  }
  if (!havesendfile64) {
    off_t o=*offset;
    if (*offset>0x7fffffff) { errno=EINVAL; return -1; }
    r=sendfile(out_fd,in_fd,&o,count);
    *offset=o;
    return r;
  }
  return r;
}
#endif
#endif
#include "dietfeatures.h"
#include <unistd.h>
#include <sys/tls.h>

void __setup_tls(tcbhead_t* mainthread);

#if defined(WANT_SSP)
extern __hidden__ unsigned long __guard;
#endif

void __setup_tls(tcbhead_t* mainthread) {
  mainthread->tcb=mainthread;
  mainthread->dtv=0;
  mainthread->self=0;
  mainthread->multiple_threads=0;
#if defined(WANT_SSP)
  mainthread->stack_guard=__guard;
#endif

#if defined(__x86_64__)

  arch_prctl(ARCH_SET_FS, mainthread);

#elif defined(__i386__)

extern int __modern_linux;

  unsigned int sd[4];
  sd[0]=-1;
  sd[1]=(unsigned long int)mainthread;
  sd[2]=0xfffff; /* 4 GB limit */
  sd[3]=0x51; /* bitfield, see struct user_desc in asm-i386/ldt.h */
  if (__modern_linux>=0) {
    if (set_thread_area((struct user_desc*)(void*)&sd)==0) {
      asm volatile ("movw %w0, %%gs" :: "q" (sd[0]*8+3));
      __modern_linux=1;
    } else
      __modern_linux=-1;
  }

#elif defined(__alpha__) || defined(__s390__)
  __builtin_set_thread_pointer(mainthread);
#elif defined(__mips__)
#elif defined(__aarch64__)
  asm volatile ("msr tpidr_el0, %0" :: "r"(mainthread));
#elif defined(__arm__)
  extern void __arm_set_tls(void*);
  __arm_set_tls(mainthread);
#elif defined(__hppa__)
  /* control register 27 is used as thread pointer on PA-RISC Linux,
   * but it can only be set from Ring0. The Linux kernel provides
   * privileged code to set this register, so call that. (cf. syscalls,
   * which branch to 0x100(%%sr2, %%r0), instead.) PA-RISC has
   * 1-instruction delayed branching. The register may be read by any
   * code however (using mfctl %cr27, %rXX). r26 is used as input for
   * the kernel code, r31 is the return address pointer set by the
   * branch instruction, so clobber both. */
  asm volatile ("ble 0xe0(%%sr2, %%r0)\n\t"
                "copy %0, %%r26"
                :: "r" (mainthread) : "r26", "r31");
#elif defined(__ABI_TLS_REGISTER)
  register tcbhead_t* __thread_self __asm__(__ABI_TLS_REGISTER);
  __thread_self=mainthread;
  __asm__ __volatile__("" : : "r"(__thread_self) : "memory");
#else
#warning "no idea how to enable TLS on this platform, edit lib/stackgap-common.h"
#endif
}
#include <errno.h>
#include "dietfeatures.h"
#ifdef WANT_LARGEFILE_BACKCOMPAT
#include <sys/stat.h>
#ifndef __NO_STAT64

extern int __dietlibc_stat64(const char *__file, struct stat64 *__buf);
extern void __stat64_cvt(const struct stat *src,struct stat64 *dest);

int stat64(const char *__file, struct stat64 *__buf) {
  if (__dietlibc_stat64(__file,__buf)) {
    struct stat temp;
    if (errno!=ENOSYS) return -1;
    if (stat(__file,&temp)) return -1;
    __stat64_cvt(&temp,__buf);
  }
  return 0;
}
#endif
#endif
#include <sys/stat.h>
#ifndef __NO_STAT64

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
#endif
#include <errno.h>
#include "dietfeatures.h"
#include <sys/statfs.h>

#if __WORDSIZE == 32

extern int __dietlibc_statfs64(const char *path, size_t bufsize, struct statfs64 *__buf);
extern void __statfs64_cvt(const struct statfs *src,struct statfs64 *dest);

int statfs64(const char *__file, struct statfs64 *__buf) {
#ifdef WANT_LARGEFILE_BACKCOMPAT
  if (__dietlibc_statfs64(__file,sizeof(*__buf),__buf)) {
    struct statfs temp;
    if (errno!=ENOSYS) return -1;
    if (statfs(__file,&temp)) return -1;
    __statfs64_cvt(&temp,__buf);
  }
  return 0;
#else
  return __dietlibc_statfs64(__file,sizeof(*__buf),__buf);
#endif
}
#endif
#include <errno.h>
#include <sys/time.h>
#include <time.h>
#include <syscalls.h>

#ifndef __NR_stime
int stime(time_t *when)
{
  struct timeval tv;
  tv.tv_sec = *when;
  tv.tv_usec = 0;
  return settimeofday(&tv, (struct timezone *)0);
}
#endif
/* includes linux/sysctl.h, and we don't want to rely in Linux kernel
 * headers for building the diet libc: */
/* #include <sys/sysctl.h> */
#include <unistd.h>

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
#include <sys/time.h>
#include <time.h>
#include <syscalls.h>

#ifndef __NR_time
time_t time(time_t *t)
{
  struct timeval tv;
  if (__unlikely(gettimeofday(&tv, NULL) < 0))
    tv.tv_sec = -1;
  if (t)
    *t = tv.tv_sec;
  return tv.tv_sec;
}
#endif
#include "dietfeatures.h"
#include <errno.h>
#ifdef WANT_LARGEFILE_BACKCOMPAT
#include <sys/stat.h>
#include "syscalls.h"
#include <unistd.h>
#ifndef __NO_STAT64
#ifdef __NR_truncate64

extern int __dietlibc_truncate64(const char* f, loff_t o);

int truncate64(const char* f, loff_t o) {
  int tmp;
  if ((tmp=__dietlibc_truncate64(f,o))==-1) {
    if (errno!=ENOSYS) return -1;
    if (o>0x7fffffff) { errno=EOVERFLOW; return -1; }
    return truncate(f,o);
  }
  return tmp;
}
#endif
#endif
#endif
#include <sys/mount.h>
#include "syscalls.h"

#ifndef __NR_umount
int umount(const char *target)
{
       return umount2(target, 0);
}
#endif

#include <syscalls.h>
#define _BSD_SOURCE
#include <utime.h>
#include <sys/time.h>

#ifndef __NR_utime
int utime(const char *filename, const struct utimbuf *times)
{
  if (times == NULL)
    return utimes(filename, NULL);
  else {
    struct timeval tvs[2];
    tvs[0].tv_sec  = times->actime;
    tvs[0].tv_usec = 0;
    tvs[1].tv_sec  = times->modtime;
    tvs[1].tv_usec = 0;
    return utimes(filename, tvs);
  }
}
#endif
#include "dietfeatures.h"
#include <stdarg.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include "dietstdio.h"
#include "dietwarning.h"

#define MAX_WIDTH 10*1024

static inline unsigned long skip_to(const char *format) {
  unsigned long nr;
  for (nr=0; format[nr] && (format[nr]!='%'); ++nr);
  return nr;
}

#define A_WRITE(fn,buf,sz)	((fn)->put((void*)(buf),(sz),(fn)->data))
#define B_WRITE(fn,buf,sz)	{ if ((unsigned long)(sz) > (((unsigned long)(int)(-1))>>1) || len+(int)(sz)<len) return -1; A_WRITE(fn,buf,sz); } while (0)

static const char pad_line[2][16]= { "                ", "0000000000000000", };
static int write_pad(unsigned int* dlen,struct arg_printf* fn, unsigned int len, int padwith) {
  int nr=0;
  if ((int)len<=0) return 0;
  if(*dlen+len<len) return -1;
  for (;len>15;len-=16,nr+=16) {
    A_WRITE(fn,pad_line[(padwith=='0')?1:0],16);
  }
  if (len>0) {
    A_WRITE(fn,pad_line[(padwith=='0')?1:0],(unsigned int)len); nr+=len;
  }
  *dlen += nr;
  return 0;
}

int __v_printf(struct arg_printf* fn, const char *format, va_list arg_ptr)
{
  unsigned int len=0;
#ifdef WANT_ERROR_PRINTF
  int _errno = errno;
#endif

  while (*format) {
    unsigned long sz = skip_to(format);
    if (sz) {
      B_WRITE(fn,format,sz);
      len+=sz;
      format+=sz;
    }
    if (*format=='%') {
      char buf[128];
      union { char*s; } u_str;
#define s u_str.s

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
#ifdef WANT_LONGLONG_PRINTF
      long long llnumber=0;
#endif

      ++format;
inn_printf:
      switch(ch=*format++) {
      case 0:
	return -1;
	break;

      /* FLAGS */
      case '#':
	flag_hash=-1;
	/* fall through */

      case 'h':
	--flag_long;
	goto inn_printf;
#if __WORDSIZE != 64
      case 'j':
#endif
      case 'q':		/* BSD ... */
      case 'L':
	++flag_long;	/* fall through */
#if defined(__GNUC__) && (__GNUC__ >= 7)
	__attribute__((fallthrough));
#endif

#if __WORDSIZE == 64
      case 'j':
#endif
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
	width=strtoul(format-1,(char**)&s,10);
	if (width>MAX_WIDTH) return -1;
	if (ch=='0' && !flag_left) padwith='0';
	format=s;
	goto inn_printf;

      case '*':
	{
	  /* A negative field width is taken as a '-' flag followed by
	   * a positive field width
	   **/
	  int tmp;
	  if ((tmp=va_arg(arg_ptr,int))<0) {
	    flag_left=1;
	    tmp=-tmp;
	  }
	  if ((width=(unsigned long)tmp)>MAX_WIDTH) return -1;
	  goto inn_printf;
	}
	/* fall through */
      case '.':
	flag_dot=1;
	if (*format=='*') {
	  int tmp=va_arg(arg_ptr,int);
	  preci=tmp<0?0:tmp;
	  ++format;
	} else {
	  long int tmp=strtol(format,(char**)&s,10);
	  preci=tmp<0?0:tmp;
	  format=s;
	}
	if (preci>MAX_WIDTH) return -1;
	goto inn_printf;

      /* print a char or % */
      case 'c':
	ch=(char)va_arg(arg_ptr,int);
	/* fall through */
      case '%':
	B_WRITE(fn,&ch,1);
	++len;
	break;

#ifdef WANT_ERROR_PRINTF
      /* print an error message */
      case 'm':
	s=strerror(_errno);
	sz=strlen(s);
	B_WRITE(fn,s,sz);
	len+=sz;
	break;
#endif
      /* print a string */
      case 's':
	s=va_arg(arg_ptr,char *);
#ifdef WANT_NULL_PRINTF
	if (!s) s="(null)";
#endif
	sz = strlen(s);
	if (flag_dot && sz>preci) sz=preci;
	preci=0;
	flag_dot^=flag_dot;
	padwith=precpadwith=' ';

print_out:
      {
	char *sign=s;
	int todo=0;
	int vs;
	
	if (! (width||preci) ) {
	  B_WRITE(fn,s,sz);
	  len+=sz;
	  break;
	}
	
	if (flag_in_sign) todo=1;
	if (flag_hash>0)  todo=flag_hash;
	if (todo) {
	  s+=todo;
	  sz-=todo;
	  width-=todo;
	}

	/* These are the cases for 1234 or "1234" respectively:
	      %.6u -> "001234"
	      %6u  -> "  1234"
	      %06u -> "001234"
	      %-6u -> "1234  "
	      %.6s -> "1234"
	      %6s  -> "  1234"
	      %06s -> "  1234"
	      %-6s -> "1234  "
	      %6.5u -> " 01234"
	      %6.5s -> "  1234"
           In this code, for %6.5s, 6 is width, 5 is preci.
	   flag_dot means there was a '.' and preci is set.
	   flag_left means there was a '-'.
	   sz is 4 (strlen("1234")).
	   padwith will be '0' for %06u, ' ' otherwise.
	   precpadwith is '0' for %u, ' ' for %s.
	 */

	if (flag_dot && width==0) width=preci;
	if (!flag_dot) preci=sz;
	if (!flag_left && padwith==' ') { /* do left-side padding with spaces */
	  if (write_pad(&len,fn,width-preci,padwith))
	    return -1;
	}
	if (todo) {
	  B_WRITE(fn,sign,todo);
	  len+=todo;
	}
	if (!flag_left && padwith!=' ') { /* do left-side padding with '0' */
	  if (write_pad(&len,fn,width-preci,padwith))
	    return -1;
	}
	/* do preci padding */
	if (write_pad(&len,fn,preci-sz,precpadwith))
	  return -1;
	/* write actual string */
	B_WRITE(fn,s,sz);
	len+=sz;
	if (flag_left) {
	  if (write_pad(&len,fn,width-preci,padwith))
	    return -1;
	}
	
	break;
      }

      /* print an integer value */
      case 'b':
	base=2;
	sz=0;
	goto num_printf;
      case 'p':
	flag_hash=2;
	flag_long=1;
	ch='x';
	/* fall through */
      case 'X':
	flag_upcase=(ch=='X');
	/* fall through */
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
	/* fall through */
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
	s=buf+1;

	if (flag_long>0) {
#ifdef WANT_LONGLONG_PRINTF
	  if (flag_long>1)
	    llnumber=va_arg(arg_ptr,long long);
	  else
#endif
	    number=va_arg(arg_ptr,long);
	}
	else {
	  number=va_arg(arg_ptr,int);
	  if (sizeof(int) != sizeof(long) && !flag_in_sign)
	    number&=((unsigned int)-1);
	}

	if (flag_in_sign) {
#ifdef WANT_LONGLONG_PRINTF
	  if ((flag_long>1)&&(llnumber<0)) {
	    llnumber=-llnumber;
	    flag_in_sign=2;
	  } else
#endif
	    if (number<0) {
	      number=-number;
	      flag_in_sign=2;
	    }
	}
	if (flag_long<0) number&=0xffff;
	if (flag_long<-1) number&=0xff;
#ifdef WANT_LONGLONG_PRINTF
	if (flag_long>1)
	  retval = __lltostr(s+sz,sizeof(buf)-5,(unsigned long long) llnumber,base,flag_upcase);
	else
#endif
	  retval = __ltostr(s+sz,sizeof(buf)-5,(unsigned long) number,base,flag_upcase);

	/* When 0 is printed with an explicit precision 0, the output is empty. */
	if (flag_dot && retval == 1 && s[sz] == '0') {
	  if (preci == 0||flag_hash > 0) {
	    sz = 0;
	  }
	  flag_hash = 0;
	} else sz += retval;

	if (flag_in_sign==2) {
	  *(--s)='-';
	  ++sz;
	} else if ((flag_in_sign)&&(flag_sign || flag_space)) {
	  *(--s)=(flag_sign)?'+':' ';
	  ++sz;
	} else flag_in_sign=0;

	precpadwith='0';

	goto print_out;

#ifdef WANT_FLOATING_POINT_IN_PRINTF
      /* print a floating point value */
      case 'f':
      case 'F':
      case 'g':
      case 'G':
	{
	  int flags=(((ch&0x5f)=='G') ? 0x01 : 0x00) | ((ch&0x20) ? 0x00 : 0x02);
	  double d=va_arg(arg_ptr,double);
	  s=buf+1;
	  if (width==0) width=1;
	  if (!flag_dot) preci=6;
	  if (flag_sign || d < +0.0) flag_in_sign=1;

	  sz=__dtostr(d,s,sizeof(buf)-1,width,preci,flags);

	  if (!isnan(d) && !isinf(d)) {		/* skip NaN + INF values */
	    if (flag_dot) {
	      char *tmp;
	      if ((tmp=strchr(s,'.'))) {
		if (preci || flag_hash) ++tmp;
		while (preci>0 && *++tmp) --preci;
		*tmp=0;
	      } else if (flag_hash) {
		s[sz]='.';
		s[++sz]='\0';
	      }
	    }

	    if ((flags&0x01)) {
	      char *tmp,*tmp1;	/* boy, is _this_ ugly! */
	      if ((tmp=strchr(s,'.'))) {
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
	      *(--s)=(flag_sign)?'+':' ';
	      ++sz;
	    }
	  }
	  
	  sz=strlen(s);
	  if (width<sz) width=sz;
	  precpadwith='0';
	  flag_dot=0;
	  flag_hash=0;
	  goto print_out;
	}
#endif

      default:
	break;
      }
    }
  }
  return len;
}

#undef s

link_warning("__v_printf","warning: the printf functions add several kilobytes of bloat.")
#include "dietfeatures.h"
#include <stdarg.h>
#include <sys/types.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "dietstdio.h"
#include "dietwarning.h"

#define A_GETC(fn)	(++consumed,(fn)->getch((fn)->data))
#define A_PUTC(c,fn)	(--consumed,(fn)->putch((c),(fn)->data))

int __v_scanf(struct arg_scanf* fn, const char *format, va_list arg_ptr)
{
  unsigned int ch;	/* format act. char */
  int n=0;

  /* arg_ptr tmps */
#ifdef WANT_FLOATING_POINT_IN_SCANF
  double *pd;
  float  *pf;
#endif
#ifdef WANT_LONGLONG_SCANF
  long long *pll;
#endif
  long   *pl;
  short  *ph;
  int    *pi;
  char    *s;

  unsigned int consumed=0;

  /* get one char */
  int tpch= A_GETC(fn);

  //while ((tpch!=-1)&&(*format))
  while (*format)
  {
    ch=*format++;
    switch (ch) {
    /* end of format string ?!? */
    case 0: return 0;

    /* skip spaces ... */
    case ' ':
    case '\f':
    case '\t':
    case '\v':
    case '\n':
    case '\r':
      while((*format)&&(isspace(*format))) ++format;
      while(isspace(tpch)) tpch=A_GETC(fn);
      break;

    /* format string ... */
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
	/* end of format string ?!? */
	case 0: return 0;

	/* check for % */
	case '%':
	  if ((unsigned char)tpch != ch) goto err_out;
	  tpch=A_GETC(fn);
	  break;

	/* FLAGS */
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

	/* WIDTH */
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

	/* scan for integer / strtol reimplementation ... */
	case 'p':
	case 'X':
	case 'x':
	  _div+=6;
	  /* fall through */
	case 'd':
	  _div+=2;
	  /* fall through */
	case 'o':
	  _div+=8;
	  /* fall through */
	case 'u':
	case 'i':
	  {
#ifdef WANT_LONGLONG_SCANF
	    unsigned long long v=0;
#else
	    unsigned long v=0;
#endif
	    unsigned int consumedsofar;
	    int neg=0;
	    while(isspace(tpch)) tpch=A_GETC(fn);
	    if (tpch=='-') {
	      tpch=A_GETC(fn);
	      neg=1;
	    }

	    if (tpch=='+') tpch=A_GETC(fn);

	    if (tpch==-1) return n;
	    consumedsofar=consumed;

	    if (!flag_width) {
	      if ((_div==16) && (tpch=='0')) goto scan_hex;
	      if (!_div) {
		_div=10;
		if (tpch=='0') {
		  _div=8;
scan_hex:
		  tpch=A_GETC(fn);
		  if ((tpch|32)=='x') {
		    tpch=A_GETC(fn);
		    _div=16;
		  }
		}
	      }
	    }
	    while ((width)&&(tpch!=-1)) {
	      register unsigned long c=tpch&0xff;
#ifdef WANT_LONGLONG_SCANF
	      register unsigned long long d=c|0x20;
#else
	      register unsigned long d=c|0x20;
#endif
	      c=(d>='a'?d-'a'+10:c<='9'?c-'0':0xff);
	      if (c>=_div) break;
	      d=v*_div;
#ifdef WANT_LONGLONG_SCANF
	      v=(d<v)?ULLONG_MAX:d+c;
#else
	      v=(d<v)?ULONG_MAX:d+c;
#endif
	      --width;
	      tpch=A_GETC(fn);
	    }

	    if (consumedsofar==consumed) return n;

	    if ((ch|0x20)<'p') {
#ifdef WANT_LONGLONG_SCANF
	      register long long l=v;
	      if (v>=-((unsigned long long)LLONG_MIN)) {
		l=(neg)?LLONG_MIN:LLONG_MAX;
	      }
	      else {
		if (neg) v*=-1;
	      }
#else
	      register long l=v;
	      if (v>=-((unsigned long)LONG_MIN)) {
		l=(neg)?LONG_MIN:LONG_MAX;
	      }
	      else {
		if (neg) v*=-1;
	      }
#endif
	    }
	    if (!flag_discard) {
#ifdef WANT_LONGLONG_SCANF
	      if (flag_longlong) {
		pll=(long long *)va_arg(arg_ptr,long long*);
		*pll=v;
	      } else
#endif
	      if (flag_long) {
		pl=(long *)va_arg(arg_ptr,long*);
		*pl=v;
	      } else if (flag_half) {
		ph=(short*)va_arg(arg_ptr,short*);
		*ph=v;
	      } else {
		pi=(int *)va_arg(arg_ptr,int*);
		*pi=v;
	      }
	      if(consumedsofar<consumed) ++n;
	    }
	  }
	  break;

	/* FIXME: return value of *scanf with ONE float maybe -1 instead of 0 */
#ifdef WANT_FLOATING_POINT_IN_SCANF
	/* floating point numbers */
	case 'e':
	case 'E':
	case 'f':
	case 'g':
	  {
	    double d=0.0;
	    int neg=0;
	    unsigned int consumedsofar;

	    while(isspace(tpch)) tpch=A_GETC(fn);

	    if (tpch=='-') {
	      tpch=A_GETC(fn);
	      neg=1;
	    }
	    if (tpch=='+') tpch=A_GETC(fn);

	    consumedsofar=consumed;

	    while (isdigit(tpch)) {
	      d=d*10+(tpch-'0');
	      tpch=A_GETC(fn);
	    }
	    if (tpch=='.') {
	      double factor=.1;
	      consumedsofar++;
	      tpch=A_GETC(fn);
	      while (isdigit(tpch)) {
		d=d+(factor*(tpch-'0'));
		factor/=10;
		tpch=A_GETC(fn);
	      }
	    }
	    if (consumedsofar==consumed) return n;	/* error */
	    if ((tpch|0x20)=='e') {
	      int exp=0, prec=tpch;
	      double factor=10;
	      tpch=A_GETC(fn);
	      if (tpch=='-') {
		factor=0.1;
		tpch=A_GETC(fn);
	      } else if (tpch=='+') {
		tpch=A_GETC(fn);
	      } else {
		d=0;
		if (tpch!=-1) A_PUTC(tpch,fn);
		tpch=prec;
		goto exp_out;
	      }
	      consumedsofar=consumed;
	      while (isdigit(tpch)) {
		exp=exp*10+(tpch-'0');
		tpch=A_GETC(fn);
	      }
	      if (consumedsofar==consumed) return n;	/* error */
	      while (exp) {	/* as in strtod: XXX: this introduces rounding errors */
		d*=factor; --exp;
	      }
	    }
exp_out:
	    if (neg) d = -d;
	    if (!flag_discard) {
	      if (flag_long) {
		pd=(double *)va_arg(arg_ptr,double*);
		*pd=d;
	      } else {
		pf=(float *)va_arg(arg_ptr,float*);
		*pf=d;
	      }
	      ++n;
	    }
	  }
	  break;
#endif

	/* char-sequences */
	case 'c':
	  if (!flag_discard) {
	    s=(char *)va_arg(arg_ptr,char*);
	    ++n;
	  }
	  if (!flag_width) width=1;
	  while (width && (tpch!=-1)) {
	    if (!flag_discard) *(s++)=tpch;
	    --width;
	    tpch=A_GETC(fn);
	  }
	  break;

	/* string */
	case 's':
	  if (!flag_discard) s=(char *)va_arg(arg_ptr,char*);
	  while(isspace(tpch)) tpch=A_GETC(fn);
	  if (tpch==-1) break;		/* end of scan -> error */
	  while (width && (tpch!=-1) && (!isspace(tpch))) {
	    if (!flag_discard) *s=tpch;
	    if (tpch) ++s; else break;
	    --width;
	    tpch=A_GETC(fn);
	  }
	  if (!flag_discard) { *s=0; ++n; }
	  break;

	/* consumed-count */
	case 'n':
	  if (!flag_discard) {
	    pi=(int *)va_arg(arg_ptr,int *);
//	    ++n;	/* in accordance to ANSI C we don't count this conversion */
            *pi=consumed-1;
	  }
	  break;

#ifdef WANT_CHARACTER_CLASSES_IN_SCANF
	case '[':
	  {
	    char cset[256];
	    int flag_not=0;
	    int flag_dash=0;
	    int matched=0;
	    memset(cset,0,sizeof(cset));
	    ch=*format++;
	    /* first char specials */
	    if (ch=='^') {
	      flag_not=1;
	      ch=*format++;
	    }
	    if ((ch=='-')||(ch==']')) {
	      cset[ch]=1;
	      ch=*format++;
	    }
	    /* almost all non special chars */
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
	    /* last char specials */
	    if (flag_dash) cset['-']=1;
	    else cset[ch]=1;

	    /* like %c or %s */
	    if (!flag_discard)
	      s=(char *)va_arg(arg_ptr,char*);
	    while (width && (tpch>=0) && (cset[tpch]^flag_not)) {
	      if (!flag_discard) *s=tpch;
	      if (tpch) ++s; else break;
	      --width;
	      tpch=A_GETC(fn);
	      matched=1;
	    }
	    if (!flag_discard) *s=0;
	    ++format;
	    if (matched && !flag_discard)
	      ++n;
	  }
	  break;
#endif
	default:
	  goto err_out;
	}
      }
      break;

    /* check if equal format string... */
    default:
      if ((unsigned char)tpch != ch) goto err_out;
      tpch=A_GETC(fn);
      break;
    }
  }

  /* maybe a "%n" follows */
  if(*format) {
    while(isspace(*format)) format++;
    if(format[0] == '%' && format[1] == 'n') {
      pi = (int *) va_arg(arg_ptr, int *);
      *pi = consumed - 1;
    }
  }

err_out:
  if (tpch<0 && n==0) return EOF;
  A_PUTC(tpch,fn);
  return n;
}

link_warning("__v_scanf","warning: the scanf functions add several kilobytes of bloat.");
int __valgrind=0;
#include <unistd.h>

extern void* __diet_brk(void *end_data_segment);

void* __curbrk=0;

int __libc_brk(void *end_data_segment);

int __libc_brk(void *end_data_segment) {
  return ((__curbrk=__diet_brk(end_data_segment))==(void*)-1?-1:0);
}

int brk(void *end_data_segment) __attribute__((weak,alias("__libc_brk")));
#include <sys/resource.h>

extern int __syscall_getpriority(int which, int who);

int getpriority(int which, int who) {
  int r;

  r = __syscall_getpriority(which, who);
  if (r >= 0) r = 20 - r;
  return r;
}

#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef __PIC__
void __stdio_flushall(void) __attribute__((weak));
void __stdio_flushall(void) { }
#else
#include "dietstdio.h"
#endif

void abort() {
  sigset_t t;
  __stdio_flushall();
  if (!sigemptyset(&t) && !sigaddset(&t, SIGABRT))
    sigprocmask(SIG_UNBLOCK, &t, 0);
  while (1)
    if (raise(SIGABRT))
      exit(127);
}
#include <endian.h>
#include <stdlib.h>

int abs(int i) { return i>=0?i:-i; }
#if __WORDSIZE == 32
long labs(long i) __attribute__((alias("abs")));
#endif
#include "syscalls.h"
#ifdef __NR_socketcall

#include <linuxnet.h>

extern int socketcall(int callno,long* args);

int __libc_accept(int a, void * addr, void * addr2);

int __libc_accept(int a, void * addr, void * addr2) {
  long args[] = { a, (long) addr, (long) addr2 };
  return socketcall(SYS_ACCEPT, args);
}

int accept(int a, void * addr, void * addr2) __attribute__((weak,alias("__libc_accept")));

#endif
#include <time.h>
#include <sys/timex.h>

int adjtime (const struct timeval *itv, struct timeval *otv) {
  struct timex tmp;
  if (itv) {
    tmp.offset = (itv->tv_usec % 1000000L) + (itv->tv_sec + itv->tv_usec / 1000000L) * 1000000L;
    tmp.modes = ADJ_OFFSET_SINGLESHOT;
  } else
    tmp.modes = 0;
  if (adjtimex(&tmp)==-1)
    return -1;
  if (otv) {
    otv->tv_usec = tmp.offset % 1000000;
    otv->tv_sec  = tmp.offset / 1000000;
  }
  return 0;
}
/*
 * malloc/free by O.Dreesen
 *
 * first TRY:
 *   lists w/magics
 * and now the second TRY
 *   let the kernel map all the stuff (if there is something to do)
 */

#include <unistd.h>
#include <sys/mman.h>
#include <errno.h>
#include "dietfeatures.h"

#include <sys/cdefs.h>
#include <sys/types.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include <sys/shm.h>	/* for PAGE_SIZE */


/* -- HELPER CODE --------------------------------------------------------- */

#ifndef MAP_FAILED
#define MAP_FAILED ((void*)-1)
#endif

#ifndef NULL
#define NULL ((void*)0)
#endif

typedef struct {
  void*  next;
  size_t size;
} __alloc_t;

#define BLOCK_START(b)	(((void*)(b))-sizeof(__alloc_t))
#define BLOCK_RET(b)	(((void*)(b))+sizeof(__alloc_t))

#define MEM_BLOCK_SIZE	PAGE_SIZE
#define PAGE_ALIGN(s)	(((s)+MEM_BLOCK_SIZE-1)&(unsigned long)(~(MEM_BLOCK_SIZE-1)))

/* a simple mmap :) */
#if defined(__i386__)
#define REGPARM(x) __attribute__((regparm(x)))
#else
#define REGPARM(x)
#endif

static void REGPARM(1) *do_mmap(size_t size) {
  return mmap(0, size, PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_PRIVATE, -1, (size_t)0);
}

/* -- SMALL MEM ----------------------------------------------------------- */

static __alloc_t* __small_mem[8];

#define __SMALL_NR(i)		(MEM_BLOCK_SIZE/(i))

#define __MIN_SMALL_SIZE	__SMALL_NR(256)		/*   16 /   32 */
#define __MAX_SMALL_SIZE	__SMALL_NR(2)		/* 2048 / 4096 */

#define GET_SIZE(s)		(__MIN_SMALL_SIZE<<get_index((s)))

#define FIRST_SMALL(p)		(((unsigned long)(p))&(~(MEM_BLOCK_SIZE-1)))

static inline int __ind_shift() { return (MEM_BLOCK_SIZE==4096)?4:5; }

static size_t REGPARM(1) get_index(size_t _size) {
  register size_t idx=0;
//  if (_size) {	/* we already check this in the callers */
    register size_t size=((_size-1)&(MEM_BLOCK_SIZE-1))>>__ind_shift();
    while(size) { size>>=1; ++idx; }
//  }
  return idx;
}

/* small mem */
static void __small_free(void*_ptr,size_t _size) REGPARM(2);

static void REGPARM(2) __small_free(void*_ptr,size_t _size) {
  __alloc_t* ptr=BLOCK_START(_ptr);
  size_t size=_size;
  size_t idx=get_index(size);

#ifdef WANT_FREE_OVERWRITE
  memset(ptr,0x55,size);	/* allways zero out small mem */
#else
  memset(ptr,0,size);	/* allways zero out small mem */
#endif

  ptr->next=__small_mem[idx];
  __small_mem[idx]=ptr;
}

static void* REGPARM(1) __small_malloc(size_t _size) {
  __alloc_t *ptr;
  size_t size=_size;
  size_t idx;

  idx=get_index(size);
  ptr=__small_mem[idx];

  if (ptr==0)  {	/* no free blocks ? */
    register int i,nr;
    ptr=do_mmap(MEM_BLOCK_SIZE);
    if (ptr==MAP_FAILED) return MAP_FAILED;

    __small_mem[idx]=ptr;

    nr=__SMALL_NR(size)-1;
    for (i=0;i<nr;i++) {
      ptr->next=(((void*)ptr)+size);
      ptr=ptr->next;
    }
    ptr->next=0;

    ptr=__small_mem[idx];
  }

  /* get a free block */
  __small_mem[idx]=ptr->next;
  ptr->next=0;

  return ptr;
}

/* -- PUBLIC FUNCTIONS ---------------------------------------------------- */

static void _alloc_libc_free(void *ptr) {
  register size_t size;
  if (ptr) {
    size=((__alloc_t*)BLOCK_START(ptr))->size;
    if (size) {
      if (size<=__MAX_SMALL_SIZE)
	__small_free(ptr,size);
      else
	munmap(BLOCK_START(ptr),size);
    }
  }
}
void __libc_free(void *ptr) __attribute__((alias("_alloc_libc_free")));
void free(void *ptr) __attribute__((weak,alias("_alloc_libc_free")));

#ifdef WANT_MALLOC_ZERO
static __alloc_t zeromem[2];
#endif

static void* _alloc_libc_malloc(size_t size) {
  __alloc_t* ptr;
  size_t need;
#ifdef WANT_MALLOC_ZERO
  if (!size) return BLOCK_RET(zeromem);
#else
  if (!size) goto err_out;
#endif
  size+=sizeof(__alloc_t);
  if (size<sizeof(__alloc_t)) goto err_out;
  if (size<=__MAX_SMALL_SIZE) {
    need=GET_SIZE(size);
    ptr=__small_malloc(need);
  }
  else {
    need=PAGE_ALIGN(size);
    if (!need) ptr=MAP_FAILED; else ptr=do_mmap(need);
  }
  if (ptr==MAP_FAILED) goto err_out;
  ptr->size=need;
  return BLOCK_RET(ptr);
err_out:
  (*__errno_location())=ENOMEM;
  return 0;
}
void* __libc_malloc(size_t size) __attribute__((alias("_alloc_libc_malloc")));
void* malloc(size_t size) __attribute__((weak,alias("_alloc_libc_malloc")));

void* __libc_calloc(size_t nmemb, size_t _size);
void* __libc_calloc(size_t nmemb, size_t _size) {
  size_t size;
#if __GNUC__>=5
  if (__builtin_mul_overflow(_size,nmemb,&size)) {
    (*__errno_location())=ENOMEM;
    return 0;
  }
#else
  size=_size*nmemb;
  if (nmemb && size/nmemb!=_size) {
    (*__errno_location())=ENOMEM;
    return 0;
  }
#endif
#ifdef WANT_FREE_OVERWRITE
  if (size<__MAX_SMALL_SIZE) {
    void* x=malloc(size);
    memset(x,0,size);
    return x;
  } else
#endif
  return malloc(size);
}
void* calloc(size_t nmemb, size_t _size) __attribute__((weak,alias("__libc_calloc")));

void* __libc_realloc(void* ptr, size_t _size);
void* __libc_realloc(void* ptr, size_t _size) {
  register size_t size=_size;
  if (ptr) {
    if (size) {
      __alloc_t* tmp=BLOCK_START(ptr);
      size+=sizeof(__alloc_t);
      if (size<sizeof(__alloc_t)) goto retzero;
      size=(size<=__MAX_SMALL_SIZE)?GET_SIZE(size):PAGE_ALIGN(size);
      if (tmp->size!=size) {
	if ((tmp->size<=__MAX_SMALL_SIZE)) {
	  void *new=_alloc_libc_malloc(_size);
	  if (new) {
	    register __alloc_t* foo=BLOCK_START(new);
	    size=foo->size;
	    if (size>tmp->size) size=tmp->size;
	    if (size) memcpy(new,ptr,size-sizeof(__alloc_t));
	    _alloc_libc_free(ptr);
	  }
	  ptr=new;
	}
	else {
	  register __alloc_t* foo;
	  size=PAGE_ALIGN(size);
	  foo=mremap(tmp,tmp->size,size,MREMAP_MAYMOVE);
	  if (foo==MAP_FAILED) {
retzero:
	    (*__errno_location())=ENOMEM;
	    ptr=0;
	  }
	  else {
	    foo->size=size;
	    ptr=BLOCK_RET(foo);
	  }
	}
      }
    }
    else { /* size==0 */
      _alloc_libc_free(ptr);
      ptr = NULL;
    }
  }
  else { /* ptr==0 */
    if (size) {
      ptr=_alloc_libc_malloc(size);
    }
  }
  return ptr;
}
void* realloc(void* ptr, size_t size) __attribute__((weak,alias("__libc_realloc")));

#define _LINUX_SOURCE
#include <unistd.h>
#include <sys/random.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

static uint32_t buf[256];
static unsigned int n;

/* These come from OpenBSD: */
uint32_t arc4random(void) {
  if (n==0) arc4random_stir();
  uint32_t r=buf[n];
  if (++n > sizeof(buf)/sizeof(buf[0])) n=0;
  return r;
}

void arc4random_buf(void* Buf, size_t N) {
  int r;
  if ((size_t)(r=getrandom(Buf,N,GRND_NONBLOCK)) != N) {
    if (r==-1 && errno==ENOSYS) {
      int fd=open("/dev/urandom",O_RDONLY);
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

  /* 2**32 % x == (2**32 - x) % x */
  min = -upper_bound % upper_bound;

  /*
    * This could theoretically loop forever but each retry has
    * p > 0.5 (worst case, usually far better) of selecting a
    * number inside the range we need, so it should rarely need
    * to re-roll.
    */
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

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "dietwarning.h"
#include <write12.h>

void __assert_fail (const char *assertion, const char *file, unsigned int line, const char *function);

void __assert_fail (const char *assertion, const char *file, unsigned int line, const char *function)
{
  unsigned int alen=strlen(assertion);
  unsigned int flen=strlen(file);
  unsigned int fulen=function?strlen(function):0;
  char *buf=(char*)alloca(alen+flen+fulen+50);
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

link_warning("__assert_fail","warning: your code still has assertions enabled!")
#include <stdlib.h>
#include <unistd.h>

typedef void (*function)(void);

#define NUM_ATEXIT	32

static function __atexitlist[NUM_ATEXIT];
static int atexit_counter;

int atexit(function t) {
  if (atexit_counter<NUM_ATEXIT) {
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
#include <stdlib.h>

double atof(const char *nptr) {
#if 0
  return strtod(nptr,0);
#else
  double tmp=strtod(nptr,0);
  return tmp;
#endif
}
#include <endian.h>
#include <ctype.h>
#include <stdlib.h>

#if __WORDSIZE == 64
int atoi(const char* s) {
  long int v=0;
  int sign=1;
  while ( *s == ' '  ||  (unsigned int)(*s - 9) < 5u) s++;
  switch (*s) {
  case '-': sign=-1; /* fall through */
  case '+': ++s;
  }
  while ((unsigned int) (*s - '0') < 10u) {
    v=v*10+*s-'0'; ++s;
  }
  return sign==-1?-v:v;
}
#endif
#include <endian.h>
#include <ctype.h>
#include <stdlib.h>

long int atol(const char* s) {
  long int v=0;
  int sign=0;
  while ( *s == ' '  ||  (unsigned int)(*s - 9) < 5u) ++s;
  switch (*s) {
  case '-': sign=-1;	/* fall through */
  case '+': ++s;
  }
  while ((unsigned int) (*s - '0') < 10u) {
    v=v*10+*s-'0'; ++s;
  }
  return sign?-v:v;
}

#if __WORDSIZE == 64
long long int atoll(const char* s) __attribute__((alias("atol")));
#else
int atoi(const char* s) __attribute__((alias("atol")));
#endif
#include <endian.h>
#include <ctype.h>
#include <stdlib.h>

#if __WORDSIZE != 64
long long int atoll(const char* s) {
  long long int v=0;
  int sign=1;
  while ( *s == ' '  ||  (unsigned int)(*s - 9) < 5u) ++s;
  switch (*s) {
  case '-': sign=-1; /* fall through */
  case '+': ++s;
  }
  while ((unsigned int) (*s - '0') < 10u) {
    v=v*10+*s-'0'; ++s;
  }
  return sign==-1?-v:v;
}
#endif
#include "syscalls.h"
#ifdef __NR_socketcall

#include <linuxnet.h>

extern int socketcall(int callno,long* args);

int __libc_bind(int a, void * b, int c);
int __libc_bind(int a, void * b, int c) {
  long args[] = { a, (long) b, c };
  return socketcall(SYS_BIND, args);
}

int bind(int a, void * b, int c) __attribute__((weak,alias("__libc_bind")));

#endif
#include "binshstr.h"

const char __binsh [] = "/bin/sh";

/* end of binshstr.c */
#include <assert.h>
#include <stdlib.h>

void *bsearch(const void *key, const void *base, size_t nmemb, size_t size, int (*compar)(const void* , const void* )) {
  size_t m;
  while (__likely(nmemb)) {
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
#include <wchar.h>
#include "dietlocale.h"

wint_t btowc(int c) {
  if (c==0) return 0;
  if (c==EOF) return WEOF;
  switch (lc_ctype) {
  case CT_8BIT:
    return c>0xff?WEOF:1;
  case CT_UTF8:
    return c>0x7f?WEOF:1;
  }
  return WEOF;
}
#include <threads.h>

void call_once(once_flag* flag, void (*func)(void)) {
  if (__sync_bool_compare_and_swap(flag,0,1))
    func();
}
#include <termios.h>
#include <sys/types.h>

speed_t cfgetospeed(const struct termios *termios_p) {
  return ((termios_p->c_cflag & (CBAUD|CBAUDEX)));
}

speed_t cfgetispeed(const struct termios *termios_p)	__attribute__((weak,alias("cfgetospeed")));
#include <termios.h>
#include <sys/ioctl.h>

void cfmakeraw(struct termios *t) {
     t->c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL|IXON);
     t->c_oflag &= ~OPOST;
     t->c_lflag &= ~(ECHO|ECHONL|ICANON|ISIG|IEXTEN);
     t->c_cflag &= ~(CSIZE|PARENB);
     t->c_cflag |= CS8;
     t->c_cc[VMIN] = 1;
     t->c_cc[VTIME] = 0;
}

#include <termios.h>
#include <errno.h>
#include "dietfeatures.h"

#define IBAUD0  020000000000

int cfsetispeed(struct termios *termios_p, speed_t speed)
{
  if ((speed & (speed_t)~CBAUD) != 0 && (speed < B57600 || speed > B460800)) {
    errno=EINVAL;
    return -1;
  }
  if (speed == 0)
    termios_p->c_iflag |= IBAUD0;
  else {
    termios_p->c_iflag &= ~IBAUD0;
    termios_p->c_cflag &= ~(CBAUD | CBAUDEX);
    termios_p->c_cflag |= speed;
  }
  return 0;
}

#include <termios.h>
#include <errno.h>
#include "dietfeatures.h"

int cfsetospeed(struct termios *termios_p, speed_t speed) {
  if ((speed & (speed_t)~CBAUD) != 0 && (speed < B57600 || speed > B460800)) {
    errno=EINVAL;
    return -1;
  }
  termios_p->c_cflag &= ~(CBAUD | CBAUDEX);
  termios_p->c_cflag |= speed;
  return 0;
}

#include "dietdirent.h"
#include <sys/mman.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>

int closedir (DIR* d) {
  int res=close(d->fd);
  munmap (d, PAGE_SIZE);
  return res;
}
#include <threads.h>
#include <sys/futex.h>

int cnd_broadcast(cnd_t* cond) {
  cond->sem=1;
  futex(&cond->sem,FUTEX_WAKE,0x7fffffff,0,0,0);
  return thrd_success;
}
#include <threads.h>

void cnd_destroy(cnd_t* cond) {
  // no need to do anything
  (void)cond;
}
#include <threads.h>

int cnd_init(cnd_t* cond) {
  cond->sem=0;
  return thrd_success;
}
#include <threads.h>
#include <sys/futex.h>

int cnd_signal(cnd_t* cond) {
  cond->sem=1;
  futex(&cond->sem,FUTEX_WAKE,1,0,0,0);
  return thrd_success;
}
#include <threads.h>
#include <sys/futex.h>
#include <errno.h>

int cnd_timedwait(cnd_t* cond, mtx_t* mutex, const struct timespec* time_point) {
  int r;
  do {
    r=futex(&cond->sem,FUTEX_WAIT,0,time_point,0,0);
    if (r==-1) {
      if (errno==EWOULDBLOCK) break;
      else if (errno==EINTR) continue;
    } else
      break;
  } while (r==0);
  cond->sem=0;
  return mtx_timedlock(mutex,time_point);
}
#include <threads.h>
#include <sys/futex.h>
#include <errno.h>

int cnd_wait(cnd_t* cond, mtx_t* mutex) {
  return cnd_timedwait(cond,mutex,0);
}
#include "syscalls.h"
#ifdef __NR_socketcall

#include <linuxnet.h>

extern int socketcall(int callno,long* args);

int __libc_connect(int a, void * b, int c);
int __libc_connect(int a, void * b, int c) {
  long args[] = { a, (long) b, c };
  return socketcall(SYS_CONNECT, args);
}

int connect(int a, void * b, int c) __attribute__((weak,alias("__libc_connect")));

#endif
#include <fcntl.h>

int __libc_creat(const char *file,mode_t mode);
int __libc_creat(const char *file,mode_t mode) {
  return open(file,O_WRONLY|O_CREAT|O_TRUNC,mode);
}
int creat(const char *file,mode_t mode) __attribute__((weak,alias("__libc_creat")));
#include <fcntl.h>

#ifndef O_LARGEFILE
#define O_LARGEFILE 0
#endif

int creat64(const char *file,mode_t mode) {
  return open(file,O_WRONLY|O_CREAT|O_TRUNC|O_LARGEFILE,mode);
}
#include "dietwarning.h"
#include <stdlib.h>

div_t div(int numerator, int denominator) {
  div_t x;
  x.quot=numerator/denominator;
  x.rem=numerator-x.quot*denominator;
  return x;
}

link_warning("div","warning: your code uses div(), which is completely superfluous!");
/*
 *  used by perror() and strerror()
 */

const char  __sys_err_unknown [] = "[unknown error]";

#define extern

#include "errno_definition.h"
#include <sys/tls.h>
#include <threads.h>
#include <errno.h>
#undef errno
#include <errno_definition.h>

// int *__errno_location(void) __attribute__((weak));
__attribute__((weak)) int *__errno_location(void) { return &errno; }

#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/eventfd.h>

extern int __eventfd(unsigned int count);
extern int __eventfd2(unsigned int count,int flags);

int eventfd(unsigned int count,int flags) {
  int r=__eventfd2(count,flags);
  if (r==-1 && errno==ENOSYS) {
    r=__eventfd(count);
    if (r!=-1 && flags) {
      int x;
      x=fcntl(r,F_SETFD,flags);
      if (x==-1)
	close(r);
    }
  }
  return r;
}
#include <unistd.h>
#include <paths.h>
#include <alloca.h>

extern char **environ;

int __exec_shell(const char *file, char *const argv[]);
int __exec_shell(const char *file, char *const argv[]) {
  int i;
  const char** shell_argv;

  for (i = 0; argv[i]; ++i);
  ++i;

  shell_argv=alloca(sizeof(char*)*(i+1));
  shell_argv[0] = _PATH_BSHELL;
  shell_argv[1] = file;
  for (; i > 1; i--)
    shell_argv[i] = argv[i - 1];
  return execve(_PATH_BSHELL, (char*const*)shell_argv, environ);
}

#include <stdarg.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include "dietfeatures.h"

int execl( const char *path, const char* arg, ...) {
  va_list ap,bak;
  int n,i;
  char **argv,*tmp;
  (void)arg;
  va_start(ap, arg);
  va_copy(bak,ap);
  n=2;
  while ((tmp=va_arg(ap,char *)))
    ++n;
  va_end (ap);
  if ((argv=(char **)alloca(n*sizeof(char*)))) {
    argv[0]=(char*)arg;
    for (i=1; i<n; ++i)
      argv[i]=va_arg(bak,char *);
    va_end (bak);
    return execve(path,argv,environ);
  }
  va_end (bak);
  errno=ENOMEM;
  return -1;
}
#include <stdarg.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include "dietfeatures.h"

int execle( const char *path, const char* arg, ...) {
  va_list ap;
  int n,i;
  char **argv,*tmp, **env;
  va_start(ap, arg);
  (void)arg;
  n=2;
  while ((tmp=va_arg(ap,char *)))
    ++n;
  va_end (ap);
  if ((argv=(char **)alloca(n*sizeof(char*)))) {
    va_start(ap, arg);
    argv[0]=(char*)arg;
    for (i=1; i<n; ++i)
      argv[i]=va_arg(ap,char *);
    env=va_arg(ap, char **);
    va_end (ap);
    return execve(path,argv,env);
  }
  errno=ENOMEM;
  return -1;
}
#include <stdarg.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include "dietfeatures.h"

int execlp(const char* file, const char *arg,...) {
  va_list ap,bak;
  int n,i;
  char **argv,*tmp;
  va_start(ap, arg);
  va_copy(bak,ap);
  n=2;
  while ((tmp=va_arg(ap,char *)))
    ++n;
  va_end (ap);
  if ((argv=(char **)alloca(n*sizeof(char*)))) {
    argv[0]=(char*)arg;
    for (i=0; i<n; ++i)
      argv[i+1]=va_arg(bak,char *);
    va_end (bak);
    return execvp(file,argv);
  }
  va_end (bak);
  errno=ENOMEM;
  return -1;
}
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include "exec_lib.h"
#include "dietfeatures.h"

int execv(const char *file, char *const argv[]) {
  if (execve(file,argv,environ)==-1) {
    if (errno==ENOEXEC)
      __exec_shell(file,argv);
  }
  return -1;
}
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include "exec_lib.h"
#include "dietfeatures.h"

int execvp(const char *file, char *const argv[]) {
  const char *path=getenv("PATH");
  char *cur,*next;
  char buf[PATH_MAX];
  if (strchr((char*)file,'/')) {
    if (execve(file,argv,environ)==-1) {
      if (errno==ENOEXEC)
	__exec_shell(file,argv);
      return -1;
    }
  }
  if (!path) path=_PATH_DEFPATH;
  for (cur=(char*)path; cur; cur=next) {
    next=strchr(cur,':');
    if (!next)
      next=cur+strlen(cur);
    if (next==cur) {
      buf[0]='.';
      cur--;
    } else {
      if (next-cur>=PATH_MAX-3) { error: errno=EINVAL; return -1; }
      memmove(buf,cur,(size_t)(next-cur));
    }
    buf[next-cur]='/';
    {
      int len=strlen(file);
      if (len+(next-cur)>=PATH_MAX-2) goto error;
      memmove(&buf[next-cur+1],file,strlen(file)+1);
    }
    if (execve(buf,argv,environ)==-1) {
      if (errno==ENOEXEC)
	return __exec_shell(buf,argv);
      if ((errno!=EACCES) && (errno!=ENOENT) && (errno!=ENOTDIR)) return -1;
    }
    if (*next==0) break;
    next++;
  }
  return -1;
}
#include <string.h>

void explicit_bzero(void* dest,size_t len) {
  memset(dest,0,len);
  asm volatile("": : "r"(dest) : "memory");
}
#include <string.h>

void* explicit_memset(void* dest, int c, size_t len) {
  memset(dest,c,len);
  asm volatile("": : "r"(dest) : "memory");
  return dest;
}
#include "dietdirent.h"
#include <sys/mman.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <fcntl.h>

DIR*  fdopendir ( int fd ) {
  DIR*  t  = NULL;

  if ( fd >= 0 ) {
    t = (DIR *) mmap (NULL, PAGE_SIZE, PROT_READ | PROT_WRITE, 
		MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (t != MAP_FAILED)
      t->fd = fd;
  }


  return t;
}
#include <strings.h>

int ffs(int i) {
  int plus=0;
  /* return index of rightmost bit set */
  /* ffs(1) == 1, ffs(2) == 2, ffs(256) == 9, ffs(257)=1 */
#if 0
  if (sizeof(i)==8)	/* fold 64-bit archs */
    if ((i&0xffffffff)==0) {
      plus=32;
      i>>=32;
    }
#endif
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
#define _FILE_OFFSET_BITS 64
#include <sys/statvfs.h>
#include <sys/statfs.h>

extern void __statvfs_cvt(struct statfs* from,struct statvfs* to);

int fstatvfs(int fd, struct statvfs *sv) {
  struct statfs ss;
  if (fstatfs(fd,&ss)==-1) return -1;
  __statvfs_cvt(&ss,sv);
  return 0;
}
#include <stdio.h>
#include <sys/auxv.h>

static void* find_in_auxvec(long* x,long what) {
  while (*x) {
    if (*x==what)
      return (void*)x[1];
    x+=2;
  }
  return NULL;
}

long* _auxvec;

unsigned long getauxval(unsigned long type) {
  return (long)find_in_auxvec(_auxvec,type);
}

#define _GNU_SOURCE

#include <sys/types.h>
#include <sys/utsname.h>
#include <unistd.h>

int getdomainname(char *name,size_t len) {
  struct utsname u;
  int res=uname(&u);
  if (res==0) {
    size_t i;
    if (len>=_UTSNAME_DOMAIN_LENGTH)
      len=_UTSNAME_DOMAIN_LENGTH;
    for (i=0; i<len; i++)
      name[i]=u.domainname[i];
  }
  return res;
}
#include <sys/random.h>
#include <errno.h>
#include <fcntl.h>

int getentropy(void* buf,size_t buflen) {
  int r;
  if (buflen>256) {
    errno=EIO;
    return -1;
  }
  r=getrandom(buf,buflen,GRND_NONBLOCK);
  if (r==-1 && errno==ENOSYS) {
    int fd=open("/dev/urandom",O_RDONLY);
    if (fd==-1) return -1;
    r=read(fd,buf,buflen);
    close(fd);
  }
  if (r<(int)buflen)
    return -1;
  return 0;
}
#include <stdlib.h>
#include <string.h>

extern char *getenv(const char *s)
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

#define _GNU_SOURCE

#include <sys/types.h>
#include <sys/utsname.h>
#include <unistd.h>

int gethostname(char *name,size_t len) {
  struct utsname u;
  int res=uname(&u);
  if (res==0) {
    size_t i;
    if (len>=_UTSNAME_NODENAME_LENGTH)
      len=_UTSNAME_NODENAME_LENGTH;
    for (i=0; i<len; i++)
      name[i]=u.nodename[i];
  }
  return res;
}

#include <string.h>
#include <getopt.h>

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
  if (optind==0) { optind=1; lastidx=0; }	/* whoever started setting optind to 0 should be shot */
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
    if (*tmp==0) {	/* apparently, we looked for \0, i.e. end of argument */
      ++optind;
      goto again;
    }
    if (tmp[1]==':') {	/* argument expected */
      if (tmp[2]==':' || argv[optind][lastofs+2]) {	/* "-foo", return "oo" as optarg */
	if (!*(optarg=argv[optind]+lastofs+2)) optarg=0;
	goto found;
      }
      optarg=argv[optind+1];
      if (!optarg) {	/* missing argument */
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
  } else {	/* not found */
    getopterror(0);
    ++optind;
    return '?';
  }
}
#include "syscalls.h"
#ifdef __NR_socketcall

#include <linuxnet.h>
#include <sys/socket.h>

extern int socketcall(int callno,long* args);

int __libc_getpeername(int a, void * b, int *c);
int __libc_getpeername(int a, void * b, int *c) {
  long args[] = { a, (long) b, (long) c };
  return socketcall(SYS_GETPEERNAME, args);
}

int getpeername(int a, struct sockaddr* b, socklen_t *c) __attribute__((weak,alias("__libc_getpeername")));

#endif
#include <unistd.h>

pid_t getpgrp()
{
  return getpgid(0);
}
#include "syscalls.h"
#ifdef __NR_socketcall

#include <linuxnet.h>
#include <sys/socket.h>

extern int socketcall(int callno,long* args);

int __libc_getsockname(int a, void * b, int c);
int __libc_getsockname(int a, void * b, int c) {
  long args[] = { a, (long) b, c };
  return socketcall(SYS_GETSOCKNAME, args);
}

int getsockname(int a, struct sockaddr* b, socklen_t* c) __attribute__((weak,alias("__libc_getsockname")));

#endif
#include "syscalls.h"
#ifdef __NR_socketcall

#include <linuxnet.h>
#include <sys/socket.h>

extern int socketcall(int callno,long* args);

int __libc_getsockopt(int a, int b, int c, void *d, int e);
int __libc_getsockopt(int a, int b, int c, void *d, int e) {
  long args[] = { a, b, c, (long)d, e };
  return socketcall(SYS_GETSOCKOPT, args);
}

int getsockopt(int s, int level, int optname, void * optval, socklen_t *optlen) __attribute__((weak,alias("__libc_getsockopt")));

#endif
#include <endian.h>
#include <netinet/in.h>

uint32_t htonl(uint32_t hostlong) {
#if __BYTE_ORDER==__LITTLE_ENDIAN
  return (hostlong>>24) | ((hostlong&0xff0000)>>8) |
	  ((hostlong&0xff00)<<8) | (hostlong<<24);
#else
  return hostlong;
#endif
}

uint32_t ntohl(uint32_t hostlong) __attribute__((weak,alias("htonl")));
#include <endian.h>
#include <netinet/in.h>

uint16_t htons(uint16_t hostshort) {
#if __BYTE_ORDER==__LITTLE_ENDIAN
  return ((hostshort>>8)&0xff) | (hostshort<<8);
#else
  return hostshort;
#endif
}

uint16_t ntohs(uint16_t hostshort) __attribute__((weak,alias("htons")));
#include <net/if.h>
#include <stdlib.h>

void if_freenameindex(struct if_nameindex* ptr) {
  free(ptr);
}
#include <net/if.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <stdio.h>

struct if_nameindex* if_nameindex(void) {
  struct ifconf ic;
  int fd,len,i;
  struct if_nameindex* x=0,* y;
  char *dest;
  fd=socket(AF_INET6,SOCK_DGRAM,0);
  if (fd<0) fd=socket(AF_INET,SOCK_DGRAM,0);
  ic.ifc_buf=0;
  ic.ifc_len=0;
  if (ioctl(fd,SIOCGIFCONF,&ic)<0) goto b0rken;
  ic.ifc_buf=alloca((size_t)ic.ifc_len);
  if (ioctl(fd,SIOCGIFCONF,&ic)<0) goto b0rken;
  len=(ic.ifc_len/sizeof(struct ifreq));
  x=(struct if_nameindex*)malloc((len+1)*sizeof(struct if_nameindex)+len*IFNAMSIZ);
  if (!x) goto b0rken;
  dest=(char*)(x+len+1);
  y=x;
  for (i=0; i<len; ++i) {
    struct ifreq* ir=(struct ifreq*)&ic.ifc_req[i];
    y->if_name=dest;
    memcpy(dest,ir->ifr_name,IFNAMSIZ);
    if (ioctl(fd,SIOCGIFINDEX,ir)==-1) continue;
    y->if_index=ir->ifr_ifindex;
    dest+=IFNAMSIZ;
    ++y;
  }
  y->if_name=0; y->if_index=0;
b0rken:
  close(fd);
  return x;
}
#include <net/if.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <sys/socket.h>

#ifndef SOCK_DGRAM
#define SOCK_DGRAM 2
#endif

char* if_indextoname(unsigned int interface,char* blub) {
  struct ifreq ifr;
  int fd;

  fd=socket(AF_INET6,SOCK_DGRAM,0);
  if (fd<0) fd=socket(AF_INET,SOCK_DGRAM,0);
  ifr.ifr_ifindex=interface;
  if (ioctl(fd,SIOCGIFNAME,&ifr)==0) {
    int i;
    close(fd);
    for (i=0; i<IFNAMSIZ-1; i++)
      if (!(blub[i]=ifr.ifr_name[i]))
	return blub;
    blub[i]=0;
    return blub;
  }
  close(fd);
  return 0;
}
#include <ctype.h>

int isalnum(int ch) {
  return (unsigned int)((ch | 0x20) - 'a') < 26u  ||
	 (unsigned int)( ch         - '0') < 10u;
}
#include <net/if.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <sys/socket.h>

#ifndef SOCK_DGRAM
#define SOCK_DGRAM 2
#endif

unsigned int if_nametoindex(const char* blub) {
  struct ifreq ifr;
  int fd;
  int ret=0;
  char *tmp;
  int len=sizeof(ifr.ifr_name);
  fd=socket(AF_INET6,SOCK_DGRAM,0);
  if (fd<0) fd=socket(AF_INET,SOCK_DGRAM,0);
  for (tmp=ifr.ifr_name; len>0; --len) {
    if ((*tmp++=*blub++)==0) break;
  }
  if (ioctl(fd,SIOCGIFINDEX,&ifr)==0)
    ret=ifr.ifr_ifindex;
  close(fd);
  return ret;
}
#include <ctype.h>

int isalpha(int ch) {
  return (unsigned int)((ch | 0x20) - 'a') < 26u;
}
#include <ctype.h>

int isascii ( int ch ) 
{
    return (unsigned int)ch < 128u;
}
#define ioctl libc_ioctl
#include <termios.h>
#undef ioctl
#include <sys/ioctl.h>
#include <errno.h>
#include <unistd.h>
#include "dietfeatures.h"

int isatty(int fd) {
  int save;
  int is_tty;
  struct termios term;

  save = errno;
  is_tty = ioctl(fd, TCGETS, &term) == 0;
  errno = save;

  return is_tty;
}

#include <ctype.h>

int isblank ( int ch )
{
    return ch == ' '  ||  ch == '\t';
}
#include <ctype.h>

int __iscntrl_ascii ( int ch );
int __iscntrl_ascii ( int ch ) {
    return (unsigned int)ch < 32u  ||  ch == 127;
}

int iscntrl ( int ch ) __attribute__((weak,alias("__iscntrl_ascii")));
#include <ctype.h>

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
#include <ctype.h>

int __islower_ascii ( int ch );
int __islower_ascii ( int ch ) {
    return (unsigned int) (ch - 'a') < 26u;
}

int islower ( int ch ) __attribute__((weak,alias("__islower_ascii")));
#include <ctype.h>
#include "dietlocale.h"

int isprint (int ch) {
  ch&=0x7f;
  return (ch>=32 && ch<127);
}
#include <ctype.h>

int __ispunct_ascii ( int ch );
int __ispunct_ascii ( int ch ) 
{
    return isprint (ch)  &&  !isalnum (ch)  &&  !isspace (ch);
}

int ispunct ( int ch ) __attribute__((weak,alias("__ispunct_ascii")));
#include <ctype.h>

int __isspace_ascii ( int ch );
int __isspace_ascii ( int ch )
{
    return (unsigned int)(ch - 9) < 5u  ||  ch == ' ';
}

int isspace ( int ch ) __attribute__((weak,alias("__isspace_ascii")));
#include <ctype.h>

int __isupper_ascii ( int ch );
int __isupper_ascii ( int ch )
{
    return (unsigned int)(ch - 'A') < 26u;
}

int isupper ( int ch ) __attribute__((weak,alias("__isupper_ascii")));
#include <ctype.h>
#include <wctype.h>

int __iswalnum_ascii(wint_t c);
int __iswalnum_ascii(wint_t c) {
  return (((unsigned char)c == c)?isalnum(c):0);
}

int iswalnum(wint_t c) __attribute__((weak,alias("__iswalnum_ascii")));
#include <ctype.h>
#include <wctype.h>

int __iswalpha_ascii(wint_t c);
int __iswalpha_ascii(wint_t c) {
  return (((unsigned char)c == c)?isalpha(c):0);
}

int iswalpha(wint_t c) __attribute__((weak,alias("__iswalpha_ascii")));
#include <wctype.h>

int __iswblank_ascii(wint_t c);
int __iswblank_ascii(wint_t c) {
  return (c == ' ' || c == '\t');
}

int iswblank(wint_t c) __attribute__((weak,alias("__iswblank_ascii")));
#include <wctype.h>

int __iswcntrl_ascii(wint_t c);
int __iswcntrl_ascii(wint_t c) {
  return ((unsigned int)c < 32u || c == 127);
}

int iswcntrl(wint_t c) __attribute__((weak,alias("__iswcntrl_ascii")));
#include <wctype.h>

int iswdigit(wint_t c) {
    return (unsigned int)(c - '0') < 10u;
}
#include <wctype.h>

int __iswgraph_ascii(wint_t c);
int __iswgraph_ascii(wint_t c) {
  return (unsigned int)(c - '!') < 127u - '!';
}

int iswgraph(wint_t c) __attribute__((weak,alias("__iswgraph_ascii")));
#include <wctype.h>

int __iswlower_ascii(wint_t c);
int __iswlower_ascii(wint_t c) {
  return (unsigned int) (c - 'a') < 26u;
}

int iswlower ( wint_t ch ) __attribute__((weak,alias("__iswlower_ascii")));
#include <wctype.h>

int __iswprint_ascii(wint_t c);
int __iswprint_ascii(wint_t c) {
    return (unsigned int)(c - ' ') < 127u - ' ';
}

int iswprint(wint_t c) __attribute__((weak,alias("__iswprint_ascii")));
#include <wctype.h>

int __iswpunct_ascii(wint_t c);
int __iswpunct_ascii(wint_t c)
{
  return iswprint (c) && !iswalnum(c) && !iswspace(c);
}

int iswpunct(wint_t c) __attribute__((weak,alias("__iswpunct_ascii")));
#include <wctype.h>

int __iswspace_ascii(wint_t c);
int __iswspace_ascii(wint_t c) {
  return (unsigned int)(c - 9) < 5u  ||  c == ' ';
}

int iswspace(wint_t c) __attribute__((weak,alias("__iswspace_ascii")));
#include <wctype.h>

int __iswupper_ascii ( wint_t c );
int __iswupper_ascii ( wint_t c )
{
    return (unsigned int)(c - 'A') < 26u;
}

int iswupper ( wint_t c ) __attribute__((weak,alias("__iswupper_ascii")));
#include <wctype.h>

int __iswxdigit_ascii(wint_t c);
int __iswxdigit_ascii(wint_t c)
{
    return (unsigned int)( c         - '0') < 10u  ||
           (unsigned int)((c | 0x20) - 'a') <  6u;
}

int iswxdigit(wint_t c) __attribute__((weak,alias("__iswxdigit_ascii")));
int __isxdigit_ascii ( int ch );
int __isxdigit_ascii ( int ch )
{
    return (unsigned int)( ch         - '0') < 10u  || 
           (unsigned int)((ch | 0x20) - 'a') <  6u;
}

int isxdigit ( int ch ) __attribute__((weak,alias("__isxdigit_ascii")));
#include <endian.h>
#include <stdlib.h>
#include <inttypes.h>

#if __WORDSIZE == 64
long int labs(long int i) { return i>=0?i:-i; }
long long int llabs(long long int i) __attribute__((alias("labs")));
intmax_t imaxabs(intmax_t i) __attribute__((alias("labs")));
#endif
#include <stdlib.h>

ldiv_t ldiv(long numerator, long denominator) {
  ldiv_t x;
  x.quot=numerator/denominator;
  x.rem=numerator-x.quot*denominator;
  return x;
}
#include "syscalls.h"
#ifdef __NR_socketcall

#include <linuxnet.h>
#include <sys/socket.h>

extern int socketcall(int callno,long* args);

int __libc_listen(int a, int b);
int __libc_listen(int a, int b) {
  long args[] = { a, b, 0 };
  return socketcall(SYS_LISTEN, args);
}

int listen(int s, int backlog) __attribute__((weak,alias("__libc_listen")));

#endif
#include <endian.h>
#include <stdlib.h>
#include <inttypes.h>

#if __WORDSIZE != 64
long long int llabs(long long int i) { if (i<0) i=-i; return i; }
intmax_t imaxabs(intmax_t i) __attribute__((alias("llabs")));
#endif
#define _GNU_SOURCE
#include <stdlib.h>
#include <inttypes.h>

lldiv_t lldiv(long long numerator, long long denominator) {
  lldiv_t x;
  x.quot=numerator/denominator;
  x.rem=numerator-x.quot*denominator;
  return x;
}

imaxdiv_t imaxdiv(intmax_t numerator, intmax_t denominator)  __attribute__((alias("lldiv")));
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "dietfeatures.h"

int lockf(int fd, int cmd, off_t len) {
  struct flock fl;
  fl.l_whence=SEEK_CUR;
  fl.l_start=0;
  fl.l_len=len;
  fl.l_pid=0;
  switch (cmd) {
  case F_TEST:
    if (fcntl(fd,F_GETLK,&fl)<0)
      return -1;
    if (fl.l_type == F_UNLCK || fl.l_pid == getpid ())
      return 0;
    errno=EACCES;
    return -1;
  case F_ULOCK:
    fl.l_type=F_UNLCK;
    cmd=F_SETLK;
    break;
  case F_LOCK:
    fl.l_type = F_WRLCK;
    cmd = F_SETLKW;
    break;
  case F_TLOCK:
    fl.l_type = F_WRLCK;
    cmd = F_SETLK;
    break;
  default:
    errno=EINVAL;
    return -1;
  }
  return fcntl(fd,cmd,&fl);
}
#include <setjmp.h>
#include <signal.h>

void __longjmp(void*env,int val);

void __libc_longjmp(sigjmp_buf env,int val);
void __libc_longjmp(sigjmp_buf env,int val) {
  if (env[0].__mask_was_saved) {
    sigprocmask(SIG_SETMASK,(sigset_t*)&env[0].__saved_mask,0);
  }
  if (val==0) val=1;
  __longjmp(env[0].__jmpbuf,val);
}
void __siglongjmp(sigjmp_buf env,int val) __attribute__((alias("__libc_longjmp")));
void longjmp(sigjmp_buf env,int val) __attribute__((weak,alias("__libc_longjmp")));
void siglongjmp(sigjmp_buf env,int val) __attribute__((weak,alias("__libc_longjmp")));
#include <errno.h>
#include "dietfeatures.h"

#include <sys/stat.h>
#ifndef __NO_STAT64
#include <unistd.h>

loff_t lseek64(int fildes, loff_t offset, int whence) {
  loff_t tmp;
  if (llseek(fildes,(unsigned long)(offset>>32),(unsigned long)offset&0xffffffff,&tmp,whence)) {
    if (errno!=ENOSYS) return -1;
    return (loff_t)lseek(fildes,(off_t)offset,whence);
  }
  return tmp;
}
#endif
#include <stdlib.h>
#include <wchar.h>

int mblen(const char* s,size_t n) {
  return mbrlen(s,n,NULL);
}
#include <wchar.h>
#include <errno.h>

size_t mbrlen(const char *s, size_t n, mbstate_t *ps) {
  static mbstate_t internal;
  return mbrtowc (NULL, s, n, ps ?: &internal);
}
#include "dietlocale.h"
#include <wchar.h>
#include <errno.h>

static mbstate_t internal;

size_t mbrtowc(wchar_t *pwc, const char *s, size_t n, mbstate_t *ps) {
  size_t i;
  if (!ps) ps=&internal;
  if (!s) {
    if (ps->count) {
      errno=EILSEQ;
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
	/* we have an unfinished multibyte sequence */
	if ((c&0xc0)!=0x80) {
	  /* expected a continuation, didn't get one */
kaputt:
	  errno=EILSEQ;
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
	if (c&0x80) {	/* start of multibyte sequence? */
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
#include <wchar.h>

int mbsinit(const mbstate_t* s) {
  return (!s || s->sofar);
}
#include <wchar.h>

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
#include <stdlib.h>
#include <wchar.h>

size_t mbstowcs(wchar_t *dest, const char *src, size_t n) {
  const char** s=&src;
  return mbsrtowcs(dest,s,n,NULL);
}
#include <stdlib.h>
#include <wchar.h>

int mbtowc(wchar_t *pwc, const char *s, size_t n) {
  return mbrtowc(pwc,s,n,NULL);
}
#define _POSIX_SOURCE
#define _XOPEN_SOURCE
#include <sys/types.h>
#include <string.h>

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
#include <string.h>
#include "dietfeatures.h"
#include "dietstring.h"

void* memchr(const void *s, int c, size_t n) {
  const unsigned char *pc = (unsigned char *) s;
  for (;n--;pc++)
    if (*pc == c)
      return ((void *) pc);
  return 0;
}
#include <sys/types.h>
#include <string.h>

/* gcc is broken and has a non-SUSv2 compliant internal prototype.
 * This causes it to warn about a type mismatch here.  Ignore it. */
int memcmp(const void *dst, const void *src, size_t count) {
  register int r;
  register const unsigned char *d=dst;
  register const unsigned char *s=src;
  ++count;
  while (__likely(--count)) {
    if (__unlikely(r=(*d - *s)))
      return r;
    ++d;
    ++s;
  }
  return 0;
}

int bcmp(const char *a,const char *b,size_t c)	__attribute__((weak,alias("memcmp")));
/* fast memcpy -- Copyright (C) 2003 Thomas M. Ogrisegg <tom@hi-tek.fnord.at> */

#include <string.h>
#include "dietfeatures.h"
#include "dietstring.h"

void *
memcpy (void *dst, const void *src, size_t n)
{
    void           *res = dst;
    unsigned char  *c1, *c2;
#ifdef WANT_SMALL_STRING_ROUTINES
    c1 = (unsigned char *) dst;
    c2 = (unsigned char *) src;
    while (n--) *c1++ = *c2++;
    return (res);
#else
    int             tmp;
    unsigned long  *lx1 = NULL;
    const unsigned long *lx2 = NULL;

    if (!UNALIGNED(dst, src) && n > sizeof(unsigned long)) {

	if ((tmp = STRALIGN(dst))) {
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
#endif
}
#define _GNU_SOURCE 23
#include <sys/types.h>
#include <string.h>

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
#define _POSIX_SOURCE
#define _XOPEN_SOURCE
#include <sys/types.h>
#include <string.h>

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
#define _GNU_SOURCE
#include <sys/types.h>
#include <string.h>

void* memrchr(const void *s, int c, size_t n) {
  register const char* t=s;
  register const char* last=0;
  int i;
  for (i=n; i; --i) {
    if (*t==c)
      last=t;
    ++t;
  }
  return (void*)last; /* man, what an utterly b0rken prototype */
}
#include <sys/stat.h>
#include <unistd.h>

int mkfifo(const char *fn,mode_t mode) {
  return mknod(fn,(mode_t)(mode|S_IFIFO),0);
}
#include <sys/types.h>
#include <string.h>

/* gcc is broken and has a non-SUSv2 compliant internal prototype.
 * This causes it to warn about a type mismatch here.  Ignore it. */
void* memset(void * dst, int s, size_t count) {
    register char * a = dst;
    count++;	/* this actually creates smaller code than using count-- */
    while (--count)
	*a++ = s;
    return dst;
}
#include <dietfeatures.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <syscalls.h>
#include <errno.h>

#ifdef __NR_mmap2
void*__mmap2(void*start,size_t length,int prot,int flags,int fd,off_t pgoffset);

void*__libc_mmap64(void*addr,size_t len,int prot,int flags,int fd,off64_t offset);
void*__libc_mmap64(void*addr,size_t len,int prot,int flags,int fd,off64_t offset) {
  if (offset&(PAGE_SIZE-1)) {
    errno=-EINVAL;
    return MAP_FAILED;
  }
  return __mmap2(addr,len,prot,flags,fd,offset>>PAGE_SHIFT);
}

void*mmap64(void*addr,size_t len,int prot,int flags,int fd,off64_t offset)
__attribute__((weak,alias("__libc_mmap64")));
#endif
#include <mqueue.h>

int mq_getattr(mqd_t mqdes, struct mq_attr *mqstat) {
  return mq_setattr(mqdes, NULL, mqstat);
}

#include <mqueue.h>

ssize_t mq_receive(mqd_t mqdes, char *msg_ptr, size_t msg_len, unsigned int *msg_prio) {
  return mq_timedreceive(mqdes, msg_ptr, msg_len, msg_prio, NULL);
}

#include <mqueue.h>

int mq_send (mqd_t mqdes, const char *msg_ptr, size_t msg_len, unsigned int msg_prio) {
  return mq_timedsend(mqdes, msg_ptr, msg_len, msg_prio, NULL);
}

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

extern int __ipc(int,int,int,int,void*);

int msgctl(int msqid, int cmd, struct msqid_ds *buf) {
  return __ipc(MSGCTL,msqid,cmd,0,buf);
}
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

extern int __ipc(int,key_t,int,int,int);

int msgget(key_t key,int flag) {
  return __ipc(MSGGET,key,flag,0,0);
}
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

extern int __ipc(int,int,size_t,int,void*);

struct ipc_kludge {
  struct msgbuf *msgp;
  long msgtyp;
};

int msgrcv(int msqid, void *msgp, size_t msgsz, long int msgtyp, int msgflg) {
  struct ipc_kludge tmp;
  tmp.msgp = msgp;
  tmp.msgtyp = msgtyp;
  return __ipc(MSGRCV,msqid, msgsz, msgflg, &tmp);
}
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

extern int __ipc(int,int,size_t,int,const void*);

int msgsnd (int msqid, const void *msgp, size_t msgsz, int msgflg) {
  return __ipc(MSGSND,msqid, msgsz, msgflg, msgp);
}
#include <threads.h>

void mtx_destroy(mtx_t* mutex) {
  // no need to do anything
  (void)mutex;
}
#include <threads.h>

int mtx_init(mtx_t* mutex, int type) {
  mutex->lock=0;
  mutex->type=type;
  return thrd_success;
}
#define _REENTRANT
#include <threads.h>
#include <sys/futex.h>
#include <errno.h>

int mtx_lock(mtx_t* mutex) {
  return mtx_timedlock(mutex,0);
}
#define _REENTRANT
#define _DIETLIBC_SOURCE
#include <threads.h>
#include <sys/futex.h>
#include <errno.h>

int mtx_timedlock(mtx_t* mutex, const struct timespec* time_point) {
  int i,r;
  do {
    r=__mtx_trylock(mutex,&i);
    if (r!=thrd_busy) return r;
    for (;;) {
      r=futex(&mutex->lock,FUTEX_WAIT,i,time_point,0,0);
      if (r==-1) {
	if (errno==EWOULDBLOCK) { r=0; break; } else
	if (errno==ETIMEDOUT) return thrd_timedout; else
	if (errno==EINTR) continue;
      } else
	break;
    }
  } while (r==0);
  return thrd_error;
}
#define _REENTRANT
#define _DIETLIBC_SOURCE
#include <threads.h>
#include <sys/futex.h>
#include <errno.h>

int __mtx_trylock(mtx_t* mutex,int* lockval) {
  int i;
  thrd_t me=thrd_current();
  /* attempt to lock the mutex with an atomic instruction */
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
  return __mtx_trylock(mutex,NULL);
}
#define _REENTRANT
#include <threads.h>
#include <sys/futex.h>
#include <errno.h>

int mtx_unlock(mtx_t* mutex) {
  int i,r;
  thrd_t me=thrd_current();
  if (mutex->lock==0) return thrd_error;
  if ((mutex->type&mtx_recursive) && mutex->owner==me) {
    if (__sync_add_and_fetch(&mutex->lock,-1)==0) {
      // If we get here, the mutex was recursive, we unlocked it, and we
      // were the last guy holding the lock.  Wake waiters.
      mutex->owner=0;	// cosmetic; not really needed
      futex(&mutex->lock,FUTEX_WAKE,1,0,0,0);
    }
    return thrd_success;
  }
  if (__sync_val_compare_and_swap(&mutex->lock,1,0)==1)
    futex(&mutex->lock,FUTEX_WAKE,1,0,0,0);
  return thrd_success;
}
#ifndef _REENTRANT
#define _REENTRANT
#endif
#include <errno.h>
#include <unistd.h>
#include <sys/resource.h>

int nice(int incr) {
  int prio;
  int res;
  errno=0;
  prio = getpriority(PRIO_PROCESS,0) + incr;
  if (prio < PRIO_MIN) prio=PRIO_MIN;
  if (prio >= PRIO_MAX) prio=PRIO_MAX-1;
  if (setpriority (PRIO_PROCESS, 0, prio)==-1) {
    if (errno==EACCES) errno=EPERM;
    return -1;
  } else
    return getpriority(PRIO_PROCESS, 0);
}
#include <sys/types.h>
#include <fcntl.h>

#ifndef O_LARGEFILE
#define O_LARGEFILE 0
#endif

int __libc_open64(const char* file,int oflag,int mode);
int __libc_open64(const char* file,int oflag,int mode) {
  return open(file,oflag|O_LARGEFILE,mode);
}

int open64(const char* file,int oflag,...) __attribute__((weak,alias("__libc_open64")));
#include "dietdirent.h"
#include <sys/mman.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <fcntl.h>

DIR*  opendir ( const char* name ) {
  int   fd = open (name, O_RDONLY | O_DIRECTORY);
  DIR*  t  = NULL;

  if ( fd >= 0 ) {
    if (fcntl (fd, F_SETFD, FD_CLOEXEC) < 0)
      goto lose;
    t = (DIR *) mmap (NULL, PAGE_SIZE, PROT_READ | PROT_WRITE, 
		MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (t == MAP_FAILED)
lose:
      close (fd);
    else
      t->fd = fd;
  }


  return t;
}
#include "dietfeatures.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#define _BSD_SOURCE
#undef __attribute_dontuse__
#define __attribute_dontuse__
#include <errno.h>

extern const char  __sys_err_unknown [];

void  perror ( const char* prepend )
{
    register const char* message = __sys_err_unknown;

    if ( (unsigned int) errno < (unsigned int) __SYS_NERR )
        message = sys_errlist [errno];

    if (prepend) {
      write ( 2, prepend, strlen(prepend) );
      write ( 2, ": ", 2 );
    }
    write ( 2, message, strlen(message) );
    write ( 2, "\n", 1 );
}
#include <endian.h>
#include <sys/types.h>

extern size_t __pread(int fd, void *buf, size_t count, int dummy, off_t a, off_t b);

size_t __libc_pread(int fd, void *buf, size_t count, off_t offset);
size_t __libc_pread(int fd, void *buf, size_t count, off_t offset) {
  return __pread(fd,buf,count,0,__LONG_LONG_PAIR(0,offset));
}

int pread(int fd, void *buf, size_t count, off_t offset) __attribute__((weak,alias("__libc_pread")));
#define _GNU_SOURCE
#define _XOPEN_SOURCE 600

#include <fcntl.h>
int posix_fallocate(int fd, off64_t offset, off64_t len) {
  return fallocate(fd,0,offset,len);
}
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int putenv(const char *string) {
  size_t len;
  size_t i, envc;
  int remove=0;
  char *tmp;
  const char **ep;
  char **newenv;
  static char **origenv;
  if (!origenv) origenv=environ;

  // first find out of we are asked to remove or add/change an entry
  // putenv("FOO") means remove all FOO=* entries.
  if (!(tmp=strchr(string,'='))) {
    len=strlen(string);
    remove=1;
  } else
    len=tmp-string;

  // now loop through the environment looking for the string
  ep=(const char**)environ;
  if (!ep) return 0;
  for (i=envc=0, ep[i]; ep[i]; ++i) {
    // i is the iterator for reading, envc for writing
    // we compare the first byte before calling memcmp as an optimization
    if (*string == ep[i][0] && !memcmp(string,ep[i],len) && ep[i][len]=='=') {
      // we found the prefix
      // if we were asked to remove said entry, we are done
      if (remove) continue;
      // if we were asked to replace, do that, and for future matches
      // pretend we were asked to remove
      ep[envc++]=string;
      remove=1;
    } else
      ep[envc++]=ep[i];
  }
  if (remove==0) {
    // we were asked to replace something that wasn't there
    // so realloc and add here
    newenv = (char**) realloc(environ==origenv?0:environ,
			      (envc+2)*sizeof(char*));
    if (!newenv) return -1;
    if (envc && (environ==origenv)) {
      memcpy(newenv,origenv,envc*sizeof(char*));
    }
    newenv[envc++]=(char*)string;
    environ=newenv;
  }
  environ[envc]=0;		// terminate env
  return 0;
}

#ifdef UNITTEST
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int
main ()
{
  char* a="FOO=bar";
  char* b="FOO=baz";
  char* c="FOO=blub";
  char* fraud[]={a, b, 0};
  environ=fraud;

  // test fraudulent environments
  assert(putenv(c) == 0);	// invalid env: FOO appears twice
  assert(environ[0]==c && environ[1]==0);

  putenv("NEWVAR1=NEWVAL1");
  putenv("NEWVAR2=NEWVAL2");

  assert (!strcmp(getenv("NEWVAR1"), "NEWVAL1"));

  // now do some more basic tests
  static char foo[] = "Hello=World";
  assert (putenv ("foo=bar") != -1);
  assert (!strcmp (getenv ("foo"), "bar"));
  assert (putenv ("foo=baz") != -1);
  assert (!strcmp (getenv ("foo"), "baz"));
  putenv (foo);
  assert (!strcmp (getenv ("Hello"), "World"));
  foo[6] = 'M';
  assert (!strcmp (getenv ("Hello"), "Morld"));

  return 0;
}
#endif
#include <sys/select.h>

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
    sigprocmask(SIG_SETMASK,sigmask,&old);
  r=select(n,readfds,writefds,exceptfds,
	   timeout?&t:0);
  if (sigmask)
    sigprocmask(SIG_SETMASK,&old,0);
  return r;
}
#include <endian.h>
#include <sys/types.h>

extern size_t __pwrite(int fd, void *buf, size_t count, int dummy, off_t a, off_t b);

size_t __libc_pwrite(int fd, void *buf, size_t count, off_t offset);
size_t __libc_pwrite(int fd, void *buf, size_t count, off_t offset) {
  return __pwrite(fd,buf,count,0,__LONG_LONG_PAIR(0,offset));
}

int pwrite(int fd, void *buf, size_t count, off_t offset) __attribute__((weak,alias("__libc_pwrite")));
#include <sys/cdefs.h>
#include <stdlib.h>
#include "rand_i.h"

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

#define RAND

/* Quicksort with 3-way partitioning, ala Sedgewick */
/* Blame him for the scary variable names */
/* http://www.cs.princeton.edu/~rs/talks/QuicksortIsOptimal.pdf */
static void quicksort(char* base,size_t size,ssize_t l,ssize_t r,
		      int (*compar)(const void*,const void*)) {
  ssize_t i=l-1, j=r, p=l-1, q=r, k;
  char* v=base+r*size;
  if (r<=l) return;

#ifdef RAND
  /*
     We chose the rightmost element in the array to be sorted as pivot,
     which is OK if the data is random, but which is horrible if the
     data is already sorted.  Try to improve by exchanging it with a
     random other pivot.
   */
  exch(base,size,l+(rand_i()%(r-l)),r);
#elif defined MID
  /*
     We chose the rightmost element in the array to be sorted as pivot,
     which is OK if the data is random, but which is horrible if the
     data is already sorted.  Try to improve by chosing the middle
     element instead.
   */
  exch(base,size,l+(r-l)/2,r);
#endif

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
  /* check for integer overflows */
  if (nmemb >= (((size_t)-1)>>1) ||
      size >= (((size_t)-1)>>1)) return;
#if 0
  if (sizeof(size_t) < sizeof(unsigned long long)) {
    if ((unsigned long long)size * nmemb > (size_t)-1) return;
  } else {
    if (size*nmemb/nmemb != size) return;
  }
#endif
  if (nmemb>1)
    quicksort(base,size,0,nmemb-1,compar);
}
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

int raise(int sig) {
  return kill(getpid(),sig);
}
#include <stdlib.h>

static unsigned int seed=1;

int rand(void) {
  return rand_r(&seed);
}

void srand(unsigned int i) { seed=i?i:23; }

int random(void) __attribute__((leaf, nothrow, alias("rand")));
void srandom(unsigned int i) __attribute__((leaf, nothrow, alias("srand")));
#include <stdlib.h>

static randbuf rand48buf;
#define A_0  0xE66D
#define A_1  0xDEEC
#define A_2  0x5
#define C 0xB
static randbuf a = { A_0, A_1, A_2 };
static unsigned short c = C;

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
	a[0] = A_0;
	a[1] = A_1;
	a[2] = A_2;
	c = C;
}

unsigned short *seed48(randbuf buf) {
	static randbuf oldx;
	int i;
	for (i = 0; i < 3; i++) {
		oldx[i] = rand48buf[i];
		rand48buf[i] = buf[i];
	}
	a[0] = A_0;
	a[1] = A_1;
	a[2] = A_2;
	c = C;
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

#include <stdlib.h>
#include <sys/auxv.h>
#include "rand_i.h"

static unsigned int seed;

int rand_i(void) {
  if (seed==0) {
    const int* tmp=(const int*)getauxval(AT_RANDOM);
    if (tmp)
      seed=tmp[3];
    else
      seed=(uintptr_t)&seed;		// really old crappy kernel
  }
  return rand_r(&seed);
}

/*
   Copyright (C) 2002 Luc Van Oostenryck

   This is free software. You can redistribute and
   modify it under the terms of the GNU General Public
   Public License.
*/

#include <stdlib.h>
#include <stdint.h>

/* Knuth's TAOCP section 3.6 */
#define	M	((1U<<31) -1)
#define	A	48271
#define	Q	44488		// M/A
#define	R	3399		// M%A; R < Q !!!

// FIXME: ISO C/SuS want a longer period

int rand_r(unsigned int* seed)
{   int32_t X;

    X = *seed;
    X = A*(X%Q) - R * (int32_t) (X/Q);
    if (X < 0)
	X += M;

    *seed = X;
    return X;
}
#define _POSIX_SOURCE
#include "dietdirent.h"
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>

static struct dirent tmp;

struct dirent* readdir(DIR *d) {
  struct dirent* ld;
  if (readdir_r(d,&tmp,&ld)) return 0;
  return ld;
}
#include "dietfeatures.h"
#include "dietdirent.h"
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "syscalls.h"

#ifndef __NR_getdents64
#define WANT_LARGEFILE_BACKCOMPAT
#endif

#ifndef WANT_LARGEFILE_BACKCOMPAT
struct dirent64* readdir64(DIR *d) {
  if (!d->num || (d->cur += ((struct dirent64*)(d->buf+d->cur))->d_reclen)>=d->num) {
    int res=getdents64(d->fd,(struct dirent64*)d->buf, sizeof (d->buf)-1);
    if (res<=0) return 0;
    d->num=res; d->cur=0;
  }
  return (struct dirent64*)(d->buf+d->cur);
}
#else
struct dirent64* readdir64(DIR *d) {
#ifdef __NR_getdents64
  static int trygetdents64=1;
#endif
  struct dirent* o;
  static struct dirent64 d64;
#ifdef __NR_getdents64
again:
  if (!trygetdents64) {
#endif
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
    d64.d_type=0;	/* is this correct? */
    return &d64;
#ifdef __NR_getdents64
  }
  if (!d->num || (d->cur += ((struct dirent64*)(d->buf+d->cur))->d_reclen)>=d->num) {
    int res=getdents64(d->fd,(struct dirent64*)d->buf,sizeof (d->buf));
    if (res<=0) {
      if (errno==ENOSYS) {
	trygetdents64=0;
	goto again;
      }
      return 0;
    }
    d->num=res; d->cur=0;
  }
  return (struct dirent64*)(d->buf+d->cur);
#endif
}
#endif
#define _POSIX_SOURCE
#include "dietdirent.h"
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <errno.h>

#ifdef __DIET_ARCH_ONLY_DIRENT64
#define linux_dirent dirent64
#define getdents     getdents64
#define gddirent     dirent64
#else
#define gddirent     dirent
struct linux_dirent {
  uint32_t	d_ino;
  off_t		d_off;
  uint16_t	d_reclen;
  char		d_name[1];
};
#endif

int readdir_r(DIR *d,struct dirent* entry, struct dirent** result) {
  struct linux_dirent* ld;
  *result=0;
  ld=(struct linux_dirent*)(d->buf+d->cur);
  if (!d->num || d->cur >= d->num || (d->cur += ld->d_reclen)>=d->num) {
    int res=getdents(d->fd,(struct gddirent*)d->buf,sizeof (d->buf)-1);
    if (res<=0)
      return res<0;
    d->num=res; d->cur=0;
  }
  ld=(struct linux_dirent*)(d->buf+d->cur);
  /* struct dirent64 has d_name[256] instead of d_name[1] at the end */
  if (ld->d_reclen < offsetof(struct linux_dirent,d_name)+1)
    return 0;	/* can't happen */
  *result=entry;
  entry->d_ino=ld->d_ino;
  entry->d_off=ld->d_off;
  entry->d_reclen=ld->d_reclen;
#ifdef __DIET_ARCH_ONLY_DIRENT64
  entry->d_type=ld->d_type;
#else
  entry->d_type=ld->d_name[ld->d_reclen-offsetof(struct linux_dirent,d_name)-1];
#endif
  memcpy(entry->d_name,ld->d_name,ld->d_reclen-offsetof(struct linux_dirent,d_name));
  return 0;
}
#include <stdlib.h>
#include <endian.h>

#if __WORDSIZE == 64
typedef __uint128_t ulll;
#else
typedef uint64_t ulll;
#endif

void* reallocarray(void* ptr, size_t nmemb, size_t size) {
  /* produce a compile-time error if uintmax_t is not larger than size_t */
  typedef char compile_time_assertion[(sizeof(ulll)>=sizeof(size_t)*2)-1];

  ulll l=(ulll)nmemb * size;
  if ((size_t)l != l) return 0;	// overflow
  return realloc(ptr,(size_t)l);
}
#include <sys/reboot.h>

int __reboot(unsigned int magic1, unsigned int magic2, int cmd);

int reboot(int cmd)
{
  return __reboot(LINUX_REBOOT_MAGIC1, LINUX_REBOOT_MAGIC2, cmd);
}
#include "syscalls.h"
#ifdef __NR_socketcall

#include <sys/types.h>
#include <linuxnet.h>

extern int socketcall(int callno,long* args);

int __libc_recv(int a, const void * b, size_t c, int flags);
int __libc_recv(int a, const void * b, size_t c, int flags) {
  long args[] = { a, (long) b, c, flags };
  return socketcall(SYS_RECV, args);
}

int recv(int a, const void * b, size_t c, int flags)
  __attribute__ ((weak, alias("__libc_recv")));

#endif
#include "syscalls.h"
#ifdef __NR_socketcall

#include <sys/types.h>
#include <linuxnet.h>

extern int socketcall(int callno,long* args);

int __libc_recvfrom(int a, const void * b, size_t c, int flags, void *to, void *tolen);
int __libc_recvfrom(int a, const void * b, size_t c, int flags, void *to, void *tolen) {
  long args[] = { a, (long) b, c, flags, (long) to, (long) tolen };
  return socketcall(SYS_RECVFROM, args);
}

int recvfrom(int a, const void * b, size_t c, int flags, void *to, void *tolen)
 __attribute__ ((weak,alias("__libc_recvfrom"))) ;

#endif
#include <unistd.h>
#include <errno.h>
#include "dietfeatures.h"
#include <stdio.h>

int remove(const char* filename) {
  if (unlink(filename)) {
    if (errno==EISDIR)
      return rmdir(filename);
    return -1;
  }
  return 0;
}
#include "syscalls.h"
#ifdef __NR_socketcall

#include <sys/socket.h>
#include <linuxnet.h>

extern int socketcall(int callno,long* args);

int __libc_recvmsg(int a, struct msghdr* msg, int flags);
int __libc_recvmsg(int a, struct msghdr* msg, int flags) {
  long args[] = { a, (long) msg, flags };
  return socketcall(SYS_RECVMSG, args);
}

int recvmsg(int a, struct msghdr *msg, int flags)
 __attribute__ ((weak,alias("__libc_recvmsg"))) ;

#endif
#include <dietstdio.h>
#include <unistd.h>

void rewind( FILE *stream) {
  fseek(stream, 0L, SEEK_SET);
}
#include "dietdirent.h"
#include <unistd.h>
#include <dirent.h>

void rewinddir(DIR *d) {
  if (lseek(d->fd,0,SEEK_SET) != (off_t)-1)
    d->num=d->cur=0;
}
#include <unistd.h>

extern int __libc_brk(void *end_data_segment);

extern void* __curbrk;

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
#define _GNU_SOURCE
#include <stdlib.h>
#include <sys/auxv.h>

char* secure_getenv(const char* name) {
  if (getauxval(AT_SECURE))
    return NULL;
  return getenv(name);
}
#include "dietdirent.h"
#include <unistd.h>
#include <dirent.h>

void seekdir(DIR *d,off_t offset) {
  if (lseek(d->fd,offset,SEEK_SET) != (off_t)-1) {
    d->num=d->cur=0;
    ((struct dirent *)(d->buf))->d_off = offset;
  }
}
#include <sys/types.h>
#include <sys/ipc.h>

extern int __ipc(int,int,int,int,void*);

union semun {
  int val;			/* value for SETVAL */
  struct semid_ds *buf;		/* buffer for IPC_STAT & IPC_SET */
  unsigned short *array;		/* array for GETALL & SETALL */
  struct seminfo *__buf;		/* buffer for IPC_INFO */
  void *__pad;
};

int semctl(int semid, int semnum, int cmd, union semun arg);
int semctl(int semid, int semnum, int cmd, union semun arg) {
  return __ipc(SEMCTL,semid,semnum,cmd,&arg);
}
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

extern int __ipc(int,key_t,int,int,int);

int semget(key_t key, int nsems, int semflg) {
  return __ipc(SEMGET,key,nsems,semflg,0);
}
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

extern int __ipc(int,int,unsigned,int,void*);

int semop(int semid,struct sembuf *sops,unsigned nsops) {
  return __ipc(SEMOP,semid,nsops,0,sops);
}
#include "syscalls.h"
#ifdef __NR_socketcall

#include <sys/socket.h>
#include <linuxnet.h>

extern int socketcall(int callno,long* args);

int __libc_sendmsg(int a, const struct msghdr* msg, int flags);
int __libc_sendmsg(int a, const struct msghdr* msg, int flags) {
  long args[] = { a, (long) msg, flags };
  return socketcall(SYS_SENDMSG, args);
}

int sendmsg(int a, const struct msghdr *msg, int flags)
 __attribute__ ((weak,alias("__libc_sendmsg"))) ;

#endif
#include "syscalls.h"
#ifdef __NR_socketcall

#include <sys/types.h>
#include <linuxnet.h>

extern int socketcall(int callno,long* args);

int __libc_send(int a, const void * b, size_t c, int flags);
int __libc_send(int a, const void * b, size_t c, int flags) {
  long args[] = { a, (long) b, c, flags };
  return socketcall(SYS_SEND, args);
}

int send(int a, const void * b, size_t c, int flags)
  __attribute__ ((weak, alias("__libc_send")));

#endif
#include "syscalls.h"
#ifdef __NR_socketcall

#include <sys/socket.h>
#include <linuxnet.h>

extern int socketcall(int callno,long* args);

int __libc_sendto(int a, const void * b, size_t c, int flags, void *to, int tolen);
int __libc_sendto(int a, const void * b, size_t c, int flags, void *to, int tolen) {
  long args[] = { a, (long) b, c, flags, (long) to, tolen };
  return socketcall(SYS_SENDTO, args);
}

int sendto(int a, const void * b, size_t c, int flags, const struct sockaddr* to, socklen_t tolen)
  __attribute__ ((weak, alias("__libc_sendto")));

#endif
#include <stdio.h>
#include "dietwarning.h"
#undef setlinebuf

/* there is no previous prototype because it is a #define */
void setlinebuf(FILE* stream);

void setlinebuf(FILE* stream) {
  setvbuf(stream,0,_IOLBF,BUFSIZ);
}

link_warning("setlinebuf","warning: you used setlinebuf without including <stdio.h>")
#include <unistd.h>

int setpgrp()
{
  return setpgid(0,0);
}
#include "syscalls.h"
#ifdef __NR_socketcall

#include <linuxnet.h>
#include <sys/socket.h>

extern int socketcall(int callno,long* args);

int __libc_setsockopt(int a, int b, int c, void *d, void *e);
int __libc_setsockopt(int a, int b, int c, void *d, void *e) {
  long args[] = { a, b, c, (long)d, (long) e };
  return socketcall(SYS_SETSOCKOPT, args);
}

int setsockopt(int s, int level, int optname, const void* optval, socklen_t optlen) __attribute__((weak,alias("__libc_setsockopt")));

#endif
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

extern void* __ipc(int,int,int,void*,const void*);

void* shmat(int shmid,const void* shmaddr,int shmflg) {
  void* raddr;
  register void* result;
  result=__ipc(SHMAT,shmid,shmflg,&raddr,shmaddr);
  if ((unsigned long)result <= -(unsigned long)8196)
    result=raddr;
  return result;
}
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

extern int __ipc(int,int,int,int,void*);

int shmctl(int shmid, int cmd, struct shmid_ds *buf) {
  return __ipc(SHMCTL,shmid,cmd,0,buf);
}
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

extern int __ipc(int,int,int,int,const void*);

int shmdt(const void* shmaddr) {
  return __ipc(SHMDT,0,0,0,shmaddr);
}
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

extern int __ipc(int,key_t,int,int,int);

int shmget(key_t key, int size, int shmflg) {
  return __ipc(SHMGET,key,size,shmflg,0);
}
#include "syscalls.h"
#ifdef __NR_socketcall

#include <linuxnet.h>
#include <sys/socket.h>

extern int socketcall(int callno,long* args);

int __libc_shutdown(int s, int how);
int __libc_shutdown(int s, int how) {
  long args[] = { s, (long) how, 0 };
  return socketcall(SYS_SHUTDOWN, args);
}

int shutdown(int s, int how) __attribute__((weak,alias("__libc_shutdown")));

#endif
#include <signal.h>

int __rt_sigaction(int signum, const struct sigaction *act, struct sigaction *oldact, long nr);

int __libc_sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
int __libc_sigaction(int signum, const struct sigaction *act, struct sigaction *oldact) {
  return __rt_sigaction(signum, act, oldact, _NSIG/8);
}

int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact)
__attribute__((weak,alias("__libc_sigaction")));
#include <signal.h>
#include <errno.h>

#define __sigmask(sig)		( ((unsigned long)1) << (((sig)-1) % (8*sizeof(unsigned long))) )
#define __sigword(sig)		( ((sig)-1) / (8*sizeof(unsigned long)) )

int sigaddset(sigset_t *set, int signo) {
  if ((signo<1)||(signo>SIGRTMAX)) {
    (*__errno_location())=EINVAL;
    return -1;
  } else {
    unsigned long __mask = __sigmask (signo);
    unsigned long __word = __sigword (signo);
    set->sig[__word]|=__mask;
    return 0;
  }
}
#define _GNU_SOURCE
#include <signal.h>

int sigandset(sigset_t*set,const sigset_t*left,const sigset_t*right)
{
  set->sig[0]=left->sig[0]&right->sig[0];
  if (_SIGSET_WORDS>1) set->sig[1]=left->sig[1]&right->sig[1];
  if (_SIGSET_WORDS>2) {
    set->sig[2]=left->sig[2]&right->sig[2];
    set->sig[3]=left->sig[3]&right->sig[3];
  }
  return 0;
}
#include <signal.h>
#include <errno.h>

#define __sigmask(sig)		( ((unsigned long)1) << (((sig)-1) % (8*sizeof(unsigned long))) )
#define __sigword(sig)		( ((sig)-1) / (8*sizeof(unsigned long)) )

int sigdelset(sigset_t *set, int signo) {
  if ((signo<1)||(signo>SIGRTMAX)) {
    (*__errno_location())=EINVAL;
    return -1;
  } else {
    unsigned long __mask = __sigmask (signo);
    unsigned long __word = __sigword (signo);
    set->sig[__word]&=~__mask;
    return 0;
  }
}
#include <signal.h>

int sigemptyset(sigset_t *set) {
  set->sig[0]=0;
  if (_SIGSET_WORDS>1) set->sig[1]=0;
  if (_SIGSET_WORDS>2) {
    set->sig[2]=0;
    set->sig[3]=0;
  }
  return 0;
}

#include <signal.h>

int sigfillset(sigset_t *set) {
  set->sig[0]=(unsigned long)-1;
  if (_SIGSET_WORDS>1) set->sig[1]=(unsigned long)-1;
  if (_SIGSET_WORDS>2) {
    set->sig[2]=(unsigned long)-1;
    set->sig[3]=(unsigned long)-1;
  }
  return 0;
}
#include <signal.h>

int siginterrupt(int sig, int flag) {
  int ret;
  struct sigaction act;

  sigaction(sig, 0, &act);

  if (flag)
    act.sa_flags &= ~SA_RESTART;
  else
    act.sa_flags |= SA_RESTART;

  ret = sigaction(sig, &act, 0);

  return ret;
}
#define _GNU_SOURCE
#include <signal.h>

int sigisemptyset(const sigset_t*set)
{
  unsigned long ret;
  ret=set->sig[0];
  if (_SIGSET_WORDS>1) ret|=set->sig[1];
  if (_SIGSET_WORDS>2) {
    ret|=set->sig[2];
    ret|=set->sig[3];
  }
  return ret != 0;
}
#include <signal.h>
#include <errno.h>

#define __sigmask(sig)		( ((unsigned long)1) << (((sig)-1) % (8*sizeof(unsigned long))) )
#define __sigword(sig)		( ((sig)-1) / (8*sizeof(unsigned long)) )

int sigismember(const sigset_t *set, int signo) {
  if ((signo<1)||(signo>SIGRTMAX)) {
    (*__errno_location())=EINVAL;
    return -1;
  } else {
    unsigned long __mask = __sigmask (signo);
    unsigned long __word = __sigword (signo);
    return (set->sig[__word] & __mask)?1:0;
  }
}
#include <setjmp.h>
#include <signal.h>

int __sigjmp_save(sigjmp_buf env,int savemask);
int __sigjmp_save(sigjmp_buf env,int savemask) {
  env[0].__mask_was_saved = 0;
  if (savemask) {
    env[0].__mask_was_saved=(sigprocmask(SIG_BLOCK,(sigset_t*)0,&env[0].__saved_mask)==0);
  }
  return 0;
}
#include <signal.h>

sighandler_t signal(int signum, sighandler_t action) {
  struct sigaction sa,oa;
  sa.sa_handler=action;
  sigemptyset(&sa.sa_mask);
  if (sigaddset(&sa.sa_mask,signum) != 0)
    return SIG_ERR;
  sa.sa_flags = SA_NODEFER; /* FIXME ??? */
  if (sigaction(signum,&sa,&oa) != 0)
    return SIG_ERR;
  return oa.sa_handler;
}
#include <signal.h>
#include <errno.h>
#include <sys/signalfd.h>
#include <fcntl.h>

extern int __signalfd(int fd,const sigset_t* mask,size_t nsig);
extern int __signalfd4(int fd,const sigset_t* mask,size_t nsig, int flags);

int signalfd(int fd,const sigset_t* mask,int flags) {
  int r=__signalfd4(fd,mask,_NSIG/8,flags);
  if (r==-1 && errno==ENOSYS) {
    r=__signalfd(fd,mask,NSIG/8);
    if (r!=-1 && flags) {
      int x;
      x=fcntl(r,F_SETFD,flags);
      if (x==-1)
	close(r);
    }
  }
  return r;
}
#define _GNU_SOURCE
#include <signal.h>

int sigorset(sigset_t*set,const sigset_t*left,const sigset_t*right)
{
  set->sig[0]=left->sig[0]|right->sig[0];
  if (_SIGSET_WORDS>1) set->sig[1]=left->sig[1]|right->sig[1];
  if (_SIGSET_WORDS>2) {
    set->sig[2]=left->sig[2]|right->sig[2];
    set->sig[3]=left->sig[3]|right->sig[3];
  }
  return 0;
}
#include <signal.h>

int __rt_sigpending(sigset_t *set, long nr);

int sigpending(sigset_t *set) {
  return __rt_sigpending(set, _NSIG/8);
}
#include <signal.h>

int __rt_sigprocmask(int how, const sigset_t *set, sigset_t *oldsetm, long nr);

int sigprocmask(int how, const sigset_t *set, sigset_t *oldset) {
  return __rt_sigprocmask(how, set, oldset, _NSIG/8);
}
#include <signal.h>

int __rt_sigqueueinfo(pid_t pid, int sig, siginfo_t *info);

int sigqueueinfo(pid_t pid, int sig, siginfo_t *info) {
  return __rt_sigqueueinfo(pid, sig, info);
}
#include <signal.h>

int __rt_sigsuspend(const sigset_t *mask, long nr);

int __libc_sigsuspend(const sigset_t *mask);
int __libc_sigsuspend(const sigset_t *mask) {
  return __rt_sigsuspend(mask, _NSIG/8);
}

int sigsuspend(const sigset_t *mask) __attribute__((weak,alias("__libc_sigsuspend")));
#include <signal.h>

int __rt_sigtimedwait(const sigset_t *set, siginfo_t *info, const struct timespec *ts, long nr);

int sigtimedwait(const sigset_t *set, siginfo_t *info, const struct timespec *ts) {
  return __rt_sigtimedwait(set,info,ts,_NSIG/8);
}
#include <signal.h>

int sigwait(const sigset_t* set,int* sig) {
  siginfo_t si;
  int r=sigwaitinfo(set,&si);
  if (r!=-1) *sig=si.si_signo;
  return r;
}
#include <search.h>

/* taken from https://github.com/floodyberry/siphash */

#define ROTL64(a,b) (((a)<<(b))|((a)>>(64-b)))

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

#define sipcompress() \
	v0 += v1; v2 += v3; \
	v1 = ROTL64(v1,13);	v3 = ROTL64(v3,16); \
	v1 ^= v0; v3 ^= v2; \
	v0 = ROTL64(v0,32); \
	v2 += v1; v0 += v3; \
	v1 = ROTL64(v1,17); v3 = ROTL64(v3,21); \
	v1 ^= v2; v3 ^= v0; \
	v2 = ROTL64(v2,32);

	for (i = 0, blocks = (len & ~7); i < blocks; i += 8) {
		mi = U8TO64_LE(m + i);
		v3 ^= mi;
		sipcompress()
		sipcompress()
		v0 ^= mi;
	}

	switch (len - blocks) {
		case 7: last7 |= (uint64_t)m[i + 6] << 48; /* fall through */
		case 6: last7 |= (uint64_t)m[i + 5] << 40; /* fall through */
		case 5: last7 |= (uint64_t)m[i + 4] << 32; /* fall through */
		case 4: last7 |= (uint64_t)m[i + 3] << 24; /* fall through */
		case 3: last7 |= (uint64_t)m[i + 2] << 16; /* fall through */
		case 2: last7 |= (uint64_t)m[i + 1] <<  8; /* fall through */
		case 1: last7 |= (uint64_t)m[i + 0]      ; /* fall through */
		case 0:
		default:;
	};
	v3 ^= last7;
	sipcompress()
	sipcompress()
	v0 ^= last7;
	v2 ^= 0xff;
	sipcompress()
	sipcompress()
	sipcompress()
	sipcompress()
	return v0 ^ v1 ^ v2 ^ v3;
}
#include <unistd.h>
#include <time.h>

unsigned int sleep(unsigned int secs) {
  struct timespec t;
  t.tv_sec=secs;
  t.tv_nsec=0;
  nanosleep(&t,&t);
  return secs-t.tv_sec;
}

#include "syscalls.h"
#ifdef __NR_socketcall

#include <linuxnet.h>

extern int socketcall(int callno,long* args);

int __libc_socket(int a, int b, int c);
int __libc_socket(int a, int b, int c) {
  long args[] = { a, b, c };
  return socketcall(SYS_SOCKET, args);
}

int socket(int a,int b,int c) __attribute__((weak,alias("__libc_socket")));

#endif
#include <stdarg.h>
#include <sys/types.h>
#include <stdio.h>

int snprintf(char *str,size_t size,const char *format,...)
{
  int n;
  va_list arg_ptr;
  va_start(arg_ptr, format);
  n=vsnprintf(str,size,format,arg_ptr);
  va_end (arg_ptr);
  return n;
}
#include "syscalls.h"
#ifdef __NR_socketcall

#include <linuxnet.h>

extern int socketcall(int callno,long* args);

int __libc_socketpair(int a, int type, int protocol, int sv[2]);
int __libc_socketpair(int a, int type, int protocol, int sv[2]) {
  long args[] = { a, type, protocol, (long)sv };
  return socketcall(SYS_SOCKETPAIR, args);
}

int socketpair(int d, int type, int protocol, int sv[2])
  __attribute__((weak,alias("__libc_socketpair")));

#endif
#include <stdarg.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>

int sprintf(char *dest,const char *format,...)
{
  int n;
  va_list arg_ptr;
  va_start(arg_ptr, format);
  n=vsprintf(dest,format,arg_ptr);
  va_end (arg_ptr);
  return n;
}
#include <stdarg.h>
#include <stdio.h>

int sscanf(const char *str, const char *format, ...)
{
  int n;
  va_list arg_ptr;
  va_start(arg_ptr, format);
  n=vsscanf(str,format,arg_ptr);
  va_end (arg_ptr);
  return n;
}
#include <write12.h>
#include <unistd.h>

/* this is only used with ProPolice in gcc 3.x */

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


#include <unistd.h>
#include <write12.h>

void __stack_chk_fail(void);

/* earlier versions of ProPolice actually gave the address and function
 * name as arguments to the handler, so it could print some useful
 * diagnostics.  No more. :-( */
void __stack_chk_fail(void) {
  __write2("smashed stack detected, program terminated.\n");
  _exit(127);
}
#include <sys/cdefs.h>

extern void __stack_chk_fail(void) __attribute__((noreturn));

/* this is only called from implicitly generated code, so there is no
 * explicit prototype anywhere */
void __attribute__((noreturn)) __stack_chk_fail_local(void);

/* no idea why sometimes this is called instead of __stack_chk_fail,
 * but it apparently only happens with shared libraries */

void __attribute__((noreturn)) __stack_chk_fail_local(void)
{
  __stack_chk_fail ();
}
#undef __PIE__

#include "stackgap-common.h"

#include <sys/statfs.h>

#if __WORDSIZE == 32

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

#endif
#define _FILE_OFFSET_BITS 64
#include <sys/statvfs.h>
#include <sys/statfs.h>

extern void __statvfs_cvt(struct statfs* from,struct statvfs* to);

int statvfs(const char *path, struct statvfs *sv) {
  struct statfs ss;
  if (statfs(path,&ss)==-1) return -1;
  __statvfs_cvt(&ss,sv);
  return 0;
}

#define _FILE_OFFSET_BITS 64
#include <sys/statvfs.h>
#include <sys/statfs.h>

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
#include <string.h>

char * stpcpy (char *dst, const char *src) {
  while ((*dst++ = *src++));
  return (dst-1);
}
#define _GNU_SOURCE
#include <string.h>
#include "dietfeatures.h"

char* stpncpy(char* dest, const char* src, size_t n) {
  char* x=memccpy(dest,src,0,n);
  if (x) {
#ifdef WANT_FULL_POSIX_COMPAT
    memset(x,0,n-(x-dest));
#endif
    return x-1;
  } else
    return dest+n;
}
#include <strings.h>

int  strcasecmp ( const char* s1, const char* s2 )
{
    register unsigned int  x2;
    register unsigned int  x1;

    while (1) {
        x2 = *s2 - 'A'; if (__unlikely(x2 < 26u)) x2 += 32;
        x1 = *s1 - 'A'; if (__unlikely(x1 < 26u)) x1 += 32;
	s1++; s2++;
        if ( __unlikely(x2 != x1) )
            break;
        if ( __unlikely(x1 == (unsigned int)-'A') )
            break;
    }

    return x1 - x2;
}
#include "dietfeatures.h"
#include <string.h>

char* strcat(register char* s,register const char* t)
{
  char *dest=s;
  s+=strlen(s);
  for (;;) {
    if (!(*s = *t)) break;
                           ++s; ++t;
#ifndef WANT_SMALL_STRING_ROUTINES
    if (!(*s = *t)) break;
                           ++s; ++t;
    if (!(*s = *t)) break;
                           ++s; ++t;
    if (!(*s = *t)) break;
                           ++s; ++t;
#endif
  }
  return dest;
}

#include "dietfeatures.h"
#include <string.h>

char *strchr(register const char *t, int c) {
  register char ch;

  ch = c;
  for (;;) {
    if (__unlikely(*t == ch)) break; 
				     if (__unlikely(!*t)) return 0;
								    ++t;
#ifndef WANT_SMALL_STRING_ROUTINES
    if (__unlikely(*t == ch)) break; 
				     if (__unlikely(!*t)) return 0;
								    ++t;
    if (__unlikely(*t == ch)) break; 
				     if (__unlikely(!*t)) return 0;
								    ++t;
    if (__unlikely(*t == ch)) break; 
				     if (__unlikely(!*t)) return 0;
								    ++t;
#endif
  }
  return (char*)t;
}

char *index(char *t,int c)	__attribute__((weak,alias("strchr")));
/* fast strcmp -- Copyright (C) 2003 Thomas M. Ogrisegg <tom@hi-tek.fnord.at> */
#include <string.h>
#include "dietfeatures.h"
#include "dietstring.h"

#ifdef WANT_VALGRIND_SUPPORT
extern int __valgrind;
#endif

int
strcmp (const char *s1, const char *s2)
{
#ifdef WANT_SMALL_STRING_ROUTINES
    while (*s1 && *s1 == *s2)
        s1++, s2++;
    return (*s1 - *s2);
#else
    const unsigned long *lx1, *lx2;
    unsigned long   l1, l2;
    int             tmp;

    if (UNALIGNED(s1, s2)
#ifdef WANT_VALGRIND_SUPPORT
        || __unlikely(__valgrind)
#endif
    ) {
        while (*s1 && *s1 == *s2) s1++, s2++;
        return (*s1 - *s2);
    }

    if ((tmp = STRALIGN(s1)))
        for (; tmp--; s1++, s2++)
            if (!*s1 || *s1 != *s2)
                return (*s1 - *s2);

    lx1 = (unsigned long *) s1;
    lx2 = (unsigned long *) s2;

    while (1) {
        l1 = *lx1++;
        l2 = *lx2++;
        if ((((l1 - MKW(0x1ul)) & ~l1) & MKW(0x80ul)) ||
            ((((l2 - MKW(0x1ul)) & ~l2) & MKW(0x80ul))) || l1 != l2) {
            unsigned char c1, c2;
            while (1) {
		c1 = GFC(l1);
                c2 = GFC(l2);
                if (!c1 || c1 != c2)
                    return (c1 - c2);
                INCSTR(l1);
                INCSTR(l2);
            }
        }
    }
#endif
}

int strcoll(const char *s,const char* t)       __attribute__((weak,alias("strcmp")));
/* fast strcpy -- Copyright (C) 2003 Thomas M. Ogrisegg <tom@hi-tek.fnord.at> */
#include <string.h>
#include "dietfeatures.h"
#include "dietstring.h"

#ifdef WANT_VALGRIND_SUPPORT
extern int __valgrind;
#endif

char *
strcpy (char *s1, const char *s2)
{
    char           *res = s1;
#ifdef WANT_SMALL_STRING_ROUTINES
    while ((*s1++ = *s2++));
    return (res);
#else
    int             tmp;
    unsigned long   l;

    if (UNALIGNED(s1, s2)
#ifdef WANT_VALGRIND_SUPPORT
        || __unlikely(__valgrind)
#endif
    ) {
	while ((*s1++ = *s2++));
	return (res);
    }
    if ((tmp = STRALIGN(s1))) {
	while (tmp-- && (*s1++ = *s2++));
	if (tmp != -1) return (res);
    }

    while (1) {
	l = *(const unsigned long *) s2;
	if (((l - MKW(0x1ul)) & ~l) & MKW(0x80ul)) {
	    while ((*s1++ = GFC(l))) INCSTR(l);
	    return (res);
	}
	*(unsigned long *) s1 = l;
	s2 += sizeof(unsigned long);
	s1 += sizeof(unsigned long);
    }
#endif
}
#include <sys/types.h>
#include <string.h>

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
#include <string.h>
#include <stdlib.h>

char *strdup(const char *s) {
  size_t l=strlen(s)+1;
  char *tmp=(char *)malloc(l);
  if (!tmp) return 0;
  return memcpy(tmp,s,l);
}
#include "dietfeatures.h"
#include <unistd.h>
#include <string.h>

#define _BSD_SOURCE
#undef __attribute_dontuse__
#define __attribute_dontuse__
#include <errno.h>

extern const char __sys_err_unknown[];

char*strerror(int errnum) {
  register const char*message=__sys_err_unknown;

  if ( (unsigned int)errnum < (unsigned int)__SYS_NERR )
    message=sys_errlist[errnum];
#if defined(__mips__)
  if ( errnum == 1133 )
    message="Quota exceeded";
#endif
  return (char*)message;
}
/*	$OpenBSD: strlcat.c,v 1.2 1999/06/17 16:28:58 millert Exp $	*/

/*
 * Copyright (c) 1998 Todd C. Miller <Todd.Miller@courtesan.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL
 * THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#if defined(LIBC_SCCS) && !defined(lint)
static char *rcsid = "$OpenBSD: strlcat.c,v 1.2 1999/06/17 16:28:58 millert Exp $";
#endif /* LIBC_SCCS and not lint */

#include <sys/types.h>
#include <string.h>

/*
 * Appends src to string dst of size siz (unlike strncat, siz is the
 * full size of dst, not space left).  At most siz-1 characters
 * will be copied.  Always NUL terminates (unless siz == 0).
 * Returns strlen(initial dst) + strlen(src); if retval >= siz,
 * truncation occurred.
 */
size_t strlcat(dst, src, siz)
	char *dst;
	const char *src;
	size_t siz;
{
	register char *d = dst;
	register const char *s = src;
	register size_t n = siz;
	size_t dlen;

	/* Find the end of dst and adjust bytes left but don't go past end */
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

	return(dlen + (s - src));	/* count does not include NUL */
}
/*	$OpenBSD: strlcpy.c,v 1.3 1999/04/24 01:17:37 millert Exp $	*/

/*
 * Copyright (c) 1998 Todd C. Miller <Todd.Miller@courtesan.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL
 * THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#if defined(LIBC_SCCS) && !defined(lint)
static char *rcsid = "$OpenBSD: strlcpy.c,v 1.3 1999/04/24 01:17:37 millert Exp $";
#endif /* LIBC_SCCS and not lint */

#include <sys/types.h>
#include <string.h>

/*
 * Copy src to string dst of size siz.  At most siz-1 characters
 * will be copied.  Always NUL terminates (unless siz == 0).
 * Returns strlen(src); if retval >= siz, truncation occurred.
 */
size_t strlcpy(dst, src, siz)
	char *dst;
	const char *src;
	size_t siz;
{
	register char *d = dst;
	register const char *s = src;
	register size_t n = siz;

	/* Copy as many bytes as will fit */
	if (n != 0 && --n != 0) {
		do {
			if ((*d++ = *s++) == 0)
				break;
		} while (--n != 0);
	}

	/* Not enough room in dst, add NUL and traverse rest of src */
	if (n == 0) {
		if (siz != 0)
			*d = '\0';		/* NUL-terminate dst */
		while (*s++)
			;
	}

	return(s - src - 1);	/* count does not include NUL */
}
#include <endian.h>
#include "dietfeatures.h"
#include <string.h>
#include <stdint.h>

#ifdef WANT_SMALL_STRING_ROUTINES
size_t strlen(const char *s) {
  register size_t i;
  if (__unlikely(!s)) return 0;
  for (i=0; __likely(*s); ++s) ++i;
  return i;
}
#else

#if __WORDSIZE == 64
typedef uint64_t	word_t;
#elif __WORDSIZE == 32
typedef uint32_t	word_t;
#else
#error unsupported __WORDSIZE
#endif

static word_t const	magic = (word_t)(0x0101010101010101ull);

#ifdef WANT_VALGRIND_SUPPORT
extern int __valgrind;
#endif

size_t strlen(const char *s)
{
  const char *t = s;
  word_t	word;
  word_t	mask;
#if __BYTE_ORDER != __LITTLE_ENDIAN
  word_t	orig_word;
#endif

  if (__unlikely(!s)) return 0;

#ifdef WANT_VALGRIND_SUPPORT
  if (__unlikely(__valgrind)) {
    register size_t i;
    for (i=0; __likely(*s); ++s) ++i;
    return i;
  }
#endif

  /* Byte compare up until word boundary */
  for (; ((unsigned long) t & (sizeof(magic)-1)); t++)
    if (!*t) return t - s;

  /* Word compare */
  do {
    word = *((word_t const *) t); t += sizeof word;
#if __BYTE_ORDER != __LITTLE_ENDIAN
    orig_word = word;
#endif
    word = (word - magic) &~ word;
    word &= (magic << 7);
  } while (__likely(word == 0));

#if __BYTE_ORDER == __LITTLE_ENDIAN
  (void)mask;
  switch (sizeof(word)) {
  case 8:
    /* word & 0x8080808080808080 == word */
    word = (word - 1) & (magic << 8);
    word += (word << 32);
    word += (word << 16);
    word += (word << 8);
    t += word >> 56;
    break;

  case 4:
    /* word & 0x80808080 == word */
    word = (word - 1) & (magic << 10);
    word += (word << 8) + (word << 16);
    t += word >> 26;
    break;

  default: { char exc[sizeof(word)==8]; (void)exc; }
  }
#else
  /* On big endian there's a corner case where the remaining up to
   * (wordsize-1) bytes in a string are \001. In that case above code
   * properly detects that a NUL byte is present in this word, but the
   * result of the calculation in the loop will leave the following
   * code thinking that _only_ NUL bytes are present in the remaining
   * word, resulting in strlen returning a value that's too small. This
   * is not a problem on little endian systems. */
  if (__unlikely(orig_word < magic)) {
    for (t -= sizeof(word); __unlikely(*t); t++);
    return t - s;
  }

  mask = (magic << 7);

  switch (sizeof(word)) {
  case 8:
    mask <<= 4*8;
    if ((word & mask) == 0) {
      t     += 4;
      word <<= 4*8;
    }
    /* fallthrough */

  case 4:
    mask <<= 2*8;
    if ((word & mask) == 0) {
      t     += 2;
      word <<= 2*8;
    }
    /* fallthrough */

  case 2:
    mask <<= 1*8;
    if ((word & mask) == 0) {
      t     += 1;
      word <<= 1*8;
    }
    break;

  default: { char exc[sizeof(word)==8]; (void)exc; }
  }
#endif
  return t - sizeof(word) - s;
}
#endif
#include <sys/types.h>
#include <strings.h>

int  strncasecmp ( const char* s1, const char* s2, size_t len )
{
    register unsigned int  x2;
    register unsigned int  x1;
    register const char*   end = s1 + len;

    while (1) {
        if ( __unlikely(s1 >= end) )
            return 0;
        x2 = *s2 - 'A'; if (__unlikely(x2 < 26u)) x2 += 32;
        x1 = *s1 - 'A'; if (__unlikely(x1 < 26u)) x1 += 32;
	s1++; s2++;
        if ( __unlikely(x2 != x1) )
            break;
        if ( __unlikely(x1 == (unsigned int)-'A') )
            break;
    }

    return x1 - x2;
}
#include "dietfeatures.h"
#include <string.h>

/* gcc is broken and has a non-SUSv2 compliant internal prototype.
 * This causes it to warn about a type mismatch here.  Ignore it. */
char *strncat(char *s, const char *t, size_t n) {
  char *dest=s;
  register char *max;
  s+=strlen(s);
  if (__unlikely((max=s+n)==s)) goto fini;
  for (;;) {
    if (__unlikely(!(*s = *t))) break;
                                       if (__unlikely(++s==max)) break;
                                                                        ++t;
#ifndef WANT_SMALL_STRING_ROUTINES
    if (__unlikely(!(*s = *t))) break;
                                       if (__unlikely(++s==max)) break;
                                                                        ++t;
    if (__unlikely(!(*s = *t))) break;
                                       if (__unlikely(++s==max)) break;
                                                                        ++t;
    if (__unlikely(!(*s = *t))) break;
                                       if (__unlikely(++s==max)) break;
                                                                        ++t;
#endif
  }
  *s=0;
fini:
  return dest;
}
#include <sys/types.h>
#include <string.h>

/* gcc is broken and has a non-SUSv2 compliant internal prototype.
 * This causes it to warn about a type mismatch here.  Ignore it. */
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
#define _POSIX_SOURCE
#define _XOPEN_SOURCE
#include <sys/types.h>
#include <string.h>
#include "dietfeatures.h"

/* gcc is broken and has a non-SUSv2 compliant internal prototype.
 * This causes it to warn about a type mismatch here.  Ignore it. */
char *strncpy(char *dest, const char *src, size_t n) {
#ifdef WANT_FULL_POSIX_COMPAT
  memset(dest,0,n);
#endif
  memccpy(dest,src,0,n);
#ifdef WANT_NON_COMPLIANT_STRNCAT
  if (n) dest[n-1]=0;	/* maybe we should rather abort() if n is 0? */
#endif
  return dest;
}
#include <string.h>

size_t strnlen(const char *s,size_t maxlen) {
  const char* x=memchr(s,0,maxlen);
  if (!x) x=s+maxlen;
  return x-s;
}

#include <sys/types.h>
#include <string.h>

char *strpbrk(const char *s, const char *accept) {
  register unsigned int i;
  for (; *s; s++)
    for (i=0; accept[i]; i++)
      if (*s == accept[i])
	return (char*)s;
  return 0;
}
#include <string.h>
#include "dietfeatures.h"

char *strrchr(const char *t, int c) {
  register char ch;
  register const char *l=0;

  ch = c;
  for (;;) {
    if (__unlikely(*t == ch)) l=t;
                                   if (__unlikely(!*t)) return (char*)l;
                                                                         ++t;
#ifndef WANT_SMALL_STRING_ROUTINES
    if (__unlikely(*t == ch)) l=t;
                                   if (__unlikely(!*t)) return (char*)l;
                                                                         ++t;
    if (__unlikely(*t == ch)) l=t;
                                   if (__unlikely(!*t)) return (char*)l;
                                                                         ++t;
    if (__unlikely(*t == ch)) l=t;
                                   if (__unlikely(!*t)) return (char*)l;
                                                                         ++t;
#endif
  }
  return (char*)l;
}

char *rindex(const char *t,int c)	__attribute__((weak,alias("strrchr")));
#include <string.h>

char *strsep(char **stringp, const char *delim) {
  register char *tmp=*stringp;
  register char *tmp2;
  register const char *tmp3;
  if (!*stringp) return 0;
  for (tmp2=tmp; *tmp2; ++tmp2) {
    for (tmp3=delim; *tmp3; ++tmp3)
      if (*tmp2==*tmp3) {	/* delimiter found */
	*tmp2=0;
	*stringp=tmp2+1;
	return tmp;
      }
  }
  *stringp=0;
  return tmp;
}
#include <sys/types.h>
#include <string.h>

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
#include <sys/types.h>
#include <string.h>

char *strstr(const char *haystack, const char *needle) {
  size_t nl=strlen(needle);
  size_t hl=strlen(haystack);
  size_t i;
  if (!nl) goto found;
  if (nl>hl) return 0;
  for (i=hl-nl+1; __likely(i); --i) {
    if (*haystack==*needle && !memcmp(haystack,needle,nl))
found:
      return (char*)haystack;
    ++haystack;
  }
  return 0;
}
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

float strtof(const char* s, char** endptr) {
    register const char*  p     = s;
    register float        value = 0.;
    int                   sign  = +1;
    float                 factor;
    unsigned int          expo;

    while ( isspace(*p) )
        p++;

    switch (*p) {
    case '-': sign = -1;	/* fall through */
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
            value  += (*p++ - '0') * factor;
        }
    }

    if ( (*p | 32) == 'e' ) {
        expo   = 0;
        factor = 10.L;

        switch (*++p) {                 // ja hier weiß ich nicht, was mindestens nach einem 'E' folgenden MUSS.
        case '-': factor = 0.1;	/* fall through */
        case '+': p++;
                  break;
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
                  break;
        default : value = 0.L;
                  p     = s;
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
    if ( endptr != NULL )
        *endptr = (char*)p;

    return value * sign;
}
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#ifndef WANT_STRTOD_WITHOUT_LONG_DOUBLE
#define ldbltype long double
#else
#define ldbltype double
#endif

double strtod(const char* s, char** endptr) {
    register const char*  p     = s;
    register ldbltype     value = 0.;
    int                   sign  = +1;
    ldbltype              factor;
    unsigned int          expo;

    while ( isspace(*p) )
        p++;

    switch (*p) {
    case '-': sign = -1;	/* fall through */
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
            value  += (*p++ - '0') * factor;
        }
    }

    if ( (*p | 32) == 'e' ) {
        expo   = 0;
        factor = 10.;

        switch (*++p) {                 // ja hier weiß ich nicht, was mindestens nach einem 'E' folgenden MUSS.
        case '-': factor = 0.1;	/* fall through */
        case '+': p++;
                  break;
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
                  break;
        default : value = 0.;
                  p     = s;
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
    if ( endptr != NULL )
        *endptr = (char*)p;

    return value * sign;
}
#include <string.h>

static char *strtok_pos;

char *strtok(char *s, const char *delim)
{
  return strtok_r(s,delim,&strtok_pos);
}
#include <string.h>

char*strtok_r(char*s,const char*delim,char**ptrptr) {
  char*tmp=0;

  if (s==0) s=*ptrptr;
  s+=strspn(s,delim);		/* overread leading delimiter */
  if (__likely(*s)) {
    tmp=s;
    s+=strcspn(s,delim);
    if (__likely(*s)) *s++=0;	/* not the end ? => terminate it */
  }
  *ptrptr=s;
  return tmp;
}
#include <ctype.h>
#include "dietfeatures.h"
#include <errno.h>
#include <limits.h>
#include <stdlib.h>

#if __WORDSIZE == 64
#define ABS_LONG_MIN 9223372036854775808UL
#else
#define ABS_LONG_MIN 2147483648UL
#endif
long int strtol(const char *nptr, char **endptr, int base)
{
  int neg=0;
  unsigned long int v;
  const char*orig=nptr;

  while(isspace(*nptr)) nptr++;

  if (*nptr == '-' && isalnum(nptr[1])) { neg=-1; ++nptr; }
  v=strtoul(nptr,endptr,base);
  if (endptr && *endptr==nptr) *endptr=(char *)orig;
  if (v>=ABS_LONG_MIN) {
    if (v==ABS_LONG_MIN && neg) {
      errno=0;
      return v;
    }
    errno=ERANGE;
    return (neg?LONG_MIN:LONG_MAX);
  }
  return (neg?-v:v);
}
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

long double strtold(const char* s, char** endptr) {
    register const char*  p     = s;
    register long double  value = 0.L;
    int                   sign  = +1;
    long double           factor;
    unsigned int          expo;

    while ( isspace(*p) )
        p++;

    switch (*p) {
    case '-': sign = -1;	/* fall through */
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
            value  += (*p++ - '0') * factor;
        }
    }

    if ( (*p | 32) == 'e' ) {
        expo   = 0;
        factor = 10.L;

        switch (*++p) {                 // ja hier weiß ich nicht, was mindestens nach einem 'E' folgenden MUSS.
        case '-': factor = 0.1;	/* fall through */
        case '+': p++;
                  break;
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
                  break;
        default : value = 0.L;
                  p     = s;
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
    if ( endptr != NULL )
        *endptr = (char*)p;

    return value * sign;
}
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <inttypes.h>

long long int strtoll(const char *nptr, char **endptr, int base)
{
  int neg=0;
  unsigned long long int v;
  const char*orig=nptr;

  while(isspace(*nptr)) nptr++;

  if (*nptr == '-' && isalnum(nptr[1])) { neg=-1; nptr++; }
  v=strtoull(nptr,endptr,base);
  if (endptr && *endptr==nptr) *endptr=(char *)orig;
  if (v>LLONG_MAX) {
    if (v==0x8000000000000000ull && neg) {
      errno=0;
      return v;
    }
    errno=ERANGE;
    return (neg?LLONG_MIN:LLONG_MAX);
  }
  return (neg?-v:v);
}

intmax_t strtoimax(const char *nptr, char **endptr, int base)
	__attribute__((alias("strtoll")));
#include <ctype.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

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
    if (__unlikely(b>34)) { errno=EINVAL; return 0; }
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
  while(__likely(*nptr)) {
    register unsigned char c=*nptr;
    c=(c>='a'?c-'a'+10:c>='A'?c-'A'+10:c<='9'?c-'0':0xff);
    if (__unlikely(c>=base)) break;	/* out of base */
    {
      register unsigned long x=(v&0xff)*base+c;
      register unsigned long w=(v>>8)*base+(x>>8);
      if (w>(ULONG_MAX>>8)) overflow=1;
      v=(w<<8)+(x&0xff);
    }
    ++nptr;
  }
  if (__unlikely(nptr==orig)) {		/* no conversion done */
    nptr=ptr;
    errno=EINVAL;
    v=0;
  }
  if (endptr) *endptr=(char *)nptr;
  if (overflow) {
    errno=ERANGE;
    return ULONG_MAX;
  }
  return (neg?-v:v);
}
#include <ctype.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <inttypes.h>

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
    if (__unlikely(b>34)) { errno=EINVAL; return 0; }
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
  while(__likely(*nptr)) {
    register unsigned char c=*nptr;
    c=(c>='a'?c-'a'+10:c>='A'?c-'A'+10:c<='9'?c-'0':0xff);
    if (__unlikely(c>=base)) break;	/* out of base */
    {
      register unsigned long x=(v&0xff)*base+c;
      register unsigned long long w=(v>>8)*base+(x>>8);
      if (w>(ULLONG_MAX>>8)) overflow=1;
      v=(w<<8)+(x&0xff);
    }
    ++nptr;
  }
  if (__unlikely(nptr==orig)) {		/* no conversion done */
    nptr=ptr;
    errno=EINVAL;
    v=0;
  }
  if (endptr) *endptr=(char *)nptr;
  if (overflow) {
    errno=ERANGE;
    return ULLONG_MAX;
  }
  return (neg?-v:v);
}

/* die, BSD, die!!! */
unsigned long long int strtouq(const char *nptr, char **endptr, int base)
	__attribute__((leaf, nothrow, alias("strtoull")));

uintmax_t strtoumax(const char *nptr, char **endptr, int base)
	__attribute__((leaf, nothrow, alias("strtoull")));
#define _GNU_SOURCE
#include <string.h>
#include <ctype.h>

int strverscmp(const char* s1, const char* s2)
{
  size_t i,j;
  long long a,b;
  b=0;
  for (i=0; s1[i]==s2[i]; ++i) {
    if (!s1[i]) return 0;	/* perfect match */
  }

  /* if we get here, there is a mismatch */
  /* backtrack over the matching digits */
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
#include <sys/types.h>
#include <string.h>
#include "dietfeatures.h"

size_t strxfrm(char *dest, const char *src, size_t n) {
#ifdef WANT_FULL_POSIX_COMPAT
  memset(dest,0,n);
#endif
  memccpy(dest,src,0,n);
  return strlen(dest);
}

#include <unistd.h>

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
#include <ucontext.h>
#include <stdio.h>

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
#if defined(__alpha__) || defined(__sparc__) || defined(__mips__) || defined(__hppa__)
  "EMT trap",
#else
  "Bus error",
#endif
  "Floating point exception",
  "Killed",
#if defined(__alpha__) || defined(__sparc__) || defined(__mips__) || defined(__hppa__)
  "Bus error",
#else
  "User defined signal 1",
#endif
  "Segmentation fault",
#if defined(__alpha__) || defined(__sparc__) || defined(__mips__) || defined(__hppa__)
  "Bad system call",
#else
  "User defined signal 2",
#endif
  "Broken pipe",
  "Alarm clock",
  "Terminated",
#if defined(__hppa__)
  "User defined signal 1",
  "User defined signal 2",
  "Child exited",
  "Power lost",
  "Virtual timer expired",
  "Profiling timer expired",
  "I/O possible",
  "Window changed",
  "Stopped (signal)",
  "Stopped",
  "Continued",
  "Stopped (tty input)",
  "Stopped (tty output)",
  "Urgent I/O condition",
  "Power lost",
  "Unknown",
  "Unknown",
  "CPU time limit exceeded",
  "File size limit exceeded",
  "Unknown",
  "Stack fault",
#elif defined(__mips__)
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
#elif defined(__alpha__) || defined(__sparc__)
  "Urgent I/O condition",
  "Stopped (signal)",
  "Stopped",
  "Continued",
  "Child exited",
  "Stopped (tty input)",
  "Stopped (tty output)",
  "I/O possible",
  "CPU time limit exceeded",
  "File size limit exceeded",
  "Virtual timer expired",
  "Profiling timer expired",
  "Window changed",
  "Power/Resource lost",
  "User defined signal 1",
  "User defined signal 2",
#else
  "Stack fault",
  "Child exited",
  "Continued",
  "Stopped (signal)",
  "Stopped",
  "Stopped (tty input)",
  "Stopped (tty output)",
  "Urgent I/O condition",
  "CPU time limit exceeded",
  "File size limit exceeded",
  "Virtual timer expired",
  "Profiling timer expired",
  "Window changed",
  "I/O possible",
  "Power lost",
  "Bad system call",
#endif
#ifndef __hppa__
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",
  "Real time signal",
#endif
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
#ifdef __mips__
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
#endif
  0
};

const char *const* sys_siglist=__sys_siglist;
#include <sys/ioctl.h>

int __libc_tcdrain(int fd);
int __libc_tcdrain(int fd)
{
  return ioctl(fd, TCSBRK, 1);
}

int tcdrain(int fd) __attribute__((weak,alias("__libc_tcdrain")));
#include "dietfeatures.h"
#include <errno.h>
#include <termios.h>
#include <sys/ioctl.h>

int  tcflow ( int fd, int action )
{
#if TCOOFF==0  &&  TCOON==1  &&  TCIOFF==2  &&  TCION==3

    if ( (unsigned int)action < 4u )
	return ioctl ( fd, TCXONC, action );

    errno = EINVAL;
    return -1;

#else

    int  arg = 0;
    
    switch (action) {
    case TCION: 
	arg++;
    case TCIOFF: 
	arg++;
    case TCOON:   
	arg++;
    case TCOOFF:
	return ioctl ( fd, TCXONC, arg );
    default:
        errno = EINVAL;
        return -1;
    }

#endif
}
#include <sys/ioctl.h>

int __libc_tcflush(int fd, int queue_selector);
int __libc_tcflush(int fd, int queue_selector)
{
  return ioctl(fd, TCFLSH, queue_selector);
}

int tcflush(int fd, int queue_selector) __attribute__((weak,alias("__libc_tcflush")));
#include <termios.h>
#include <sys/ioctl.h>

int tcgetattr(int fildes, struct termios *termios_p)
{
  return ioctl(fildes, TCGETS, termios_p);
}
#include <termios.h>
#include <sys/ioctl.h>
#include <unistd.h>

pid_t tcgetpgrp(int fildes)
{
  int32_t foo = -1;
  if (ioctl(fildes, TIOCGPGRP, &foo)==-1)
    return -1;
  else
    return foo;
}
#include <termios.h>
#include <sys/ioctl.h>

pid_t tcgetsid(int fildes) {
  pid_t pid;
  return ioctl(fildes, TIOCGSID, &pid)==-1?-1:pid;
}

#include "dietfeatures.h"
#include <errno.h>
#include <termios.h>
#include <sys/ioctl.h>

int tcsendbreak (int fd,int duration)
{
  if (duration <= 0) return (ioctl (fd,TCSBRKP,0));
  errno = EINVAL;
  return (-1);
}
#include <termios.h>
#include <sys/ioctl.h>
#include <errno.h>
#include "dietfeatures.h"

#if !defined(__powerpc__) && !defined(__sparc__) && !defined(__alpha__) && !defined(__hppa__)
#if TCSANOW==0 && TCSADRAIN==1 && TCSAFLUSH==2 && TCSETSW-TCSETS==1 && TCSETSF-TCSETS==2
#define shortcut
#endif
#endif

int  tcsetattr ( int fildes, int optional_actions, struct termios* termios_p )
{
#ifdef shortcut

    if ( (unsigned int)optional_actions < 3u )
        return ioctl ( fildes, TCSETS+optional_actions, termios_p );

    errno = EINVAL;
    return -1;

#else

    switch ( optional_actions ) {
    case TCSANOW:
        return ioctl ( fildes, TCSETS , termios_p );
    case TCSADRAIN:
        return ioctl ( fildes, TCSETSW, termios_p );
    case TCSAFLUSH:
        return ioctl ( fildes, TCSETSF, termios_p );
    default:
        errno = EINVAL;
        return -1;
    }
    
#endif    
}
#include <termios.h>
#include <sys/ioctl.h>
#include <unistd.h>

int tcsetpgrp(int fildes, pid_t pgrpid)
{
  return ioctl(fildes, TIOCSPGRP, &pgrpid);
}
#include "dietdirent.h"
#include <unistd.h>
#include <dirent.h>

off_t telldir(DIR *d) {
  off_t result = 0;
  if (lseek(d->fd,0,SEEK_CUR))
    result=((struct dirent*)(d->buf+d->cur))->d_off;
  return result;
}
#define _LINUX_SOURCE
#include <unistd.h>
#include <threads.h>
#include <sys/mman.h>
#include <fcntl.h>
#define _GNU_SOURCE
#include <sched.h>
#include "dietfeatures.h"
#include <sys/tls.h>
#include <stdio.h>
#include <sys/random.h>

extern thrd_t _thrd_root;
extern size_t _thrd_stacksize;

#ifdef WANT_TLS
extern size_t __tdatasize, __tmemsize;
extern void* __tdataptr;
extern tcbhead_t* __tcb_mainthread;
#else
static const size_t __tmemsize=0,__tdatasize=0;
#endif

static int launch(void* p) {
  thrd_t self=p;
  thrd_exit(self->func(self->arg));
  return 0;
}

int thrd_create(thrd_t *thr, thrd_start_t func, void *arg) {
  size_t stacksize=_thrd_stacksize;	// capture value to prevent asynchronous changes to break us
  char* stack=mmap(0,stacksize+4096+__tmemsize+sizeof(tcbhead_t)+sizeof(**thr),PROT_NONE,MAP_PRIVATE|MAP_ANONYMOUS|MAP_STACK|MAP_GROWSDOWN,-1,0);
  thrd_t t;
  tcbhead_t* tcb;

  if (stack==MAP_FAILED) return thrd_nomem;
  if (mprotect(stack+4096,stacksize+__tmemsize+sizeof(tcbhead_t)+sizeof(**thr),PROT_READ|PROT_WRITE)) {
    munmap(stack,stacksize+4096+__tmemsize+sizeof(tcbhead_t)+sizeof(**thr));
    return thrd_error;
  }
  tcb=(tcbhead_t*)(stack+stacksize+4096+__tmemsize);
  tcb->tcb=tcb;
  tcb->dtv=0;
  t=(thrd_t)(tcb+1);
  tcb->self=t;
  tcb->multiple_threads=1;
#ifdef WANT_TLS
  tcb->sysinfo=__tcb_mainthread->sysinfo;
  if (getrandom(&tcb->stack_guard,sizeof(tcb->stack_guard),GRND_NONBLOCK) != sizeof(tcb->stack_guard))
    tcb->stack_guard=__tcb_mainthread->stack_guard ^ gettid() ^ (uintptr_t)t;
  __tcb_mainthread->multiple_threads=1;
#endif
  t->memstart=stack;
  t->memsize=stacksize+4096+__tmemsize;
  t->res=0;
  t->func=func;
  t->arg=arg;
  t->flags=0;
  t->join_futex=0;

#ifdef WANT_TLS
  memcpy(stack+stacksize+4096,__tdataptr,__tdatasize);
  memset(stack+stacksize+4096+__tdatasize,0,__tmemsize-__tdatasize);
#endif

  t->tid=clone(launch,stack+4096+stacksize,CLONE_FILES|CLONE_FS|CLONE_IO|CLONE_PARENT|CLONE_SIGHAND|CLONE_SYSVSEM|CLONE_THREAD|CLONE_VM|CLONE_SETTLS|CLONE_PARENT_SETTID,t,&t->tid,stack+stacksize+4096+__tmemsize);
  if (t->tid==-1) {
    munmap(stack,stacksize+4096+__tmemsize+sizeof(tcbhead_t)+sizeof(**thr));
    return thrd_error;
  }
  *thr=t;
  return thrd_success;
}
#include <sys/tls.h>
#include <threads.h>

thrd_t thrd_current(void) {
  tcbhead_t* x=__get_cur_tcb();
  if (x->multiple_threads==0) return NULL;
  return (thrd_t)(x+1);
}
#include <threads.h>
#include <sys/tls.h>
#include <sys/mman.h>

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

#define _REENTRANT
#define _LINUX_SOURCE
#include <threads.h>
#include <unistd.h>
#include <sys/futex.h>
#include <sys/tls.h>
#include <stdlib.h>
#include <errno.h>

extern void __munmap_and_exit(void* map,size_t len) __attribute__((noreturn));

thread_local tss_t tss_dtor_list;

void thrd_exit(int res) {
  thrd_t t=thrd_current();
  int flags;

  size_t len;

  while (tss_dtor_list) {
    tss_t cur=tss_dtor_list;
    tss_dtor_list=tss_dtor_list->next;
    if (cur->dtor) cur->dtor(cur);
  }
  if (!t) exit(res);	// moron user called us when no threads are running
  t->res=res;
  if ((flags=__sync_fetch_and_or(&t->flags,4))&4) return;	// shouldn't be possible, but the tear-down-bit was already set
  if (t->join_futex) {	// somebody is waiting; send him a message
    t->join_wait_futex=0;
    /* we need to wake the waiting threads up one by one, because we
     * need to wait for all of them to have received our return value
     * before we can self destruct. */
    while (futex(&t->join_futex,FUTEX_WAKE,1,0,0,0)==1) {	// wake one waiting thread
      // We woke somebody up.
      // Give them time to read our exit code.
      int r;
      do {
	r=futex(&t->join_wait_futex,FUTEX_WAIT,0,0,0,0);
      } while (r==EINTR);
      t->join_wait_futex=0;
    }
    flags|=1;	// mark as detached
  }

  len=t->memsize;
  if (flags&1) {
    // We are detached or somebody already thrd_join'ed us.
    // We can die in piece and free all our resources
    len += sizeof(tcbhead_t)+sizeof(*t);
  } else {
    // Tell thrd_join that we are dead and cleaned up our stack and it
    // should clean up the rest when it's done.
    __sync_fetch_and_or(&t->flags,2);
    len&=~4095;	// round down to nearest page
    t->arg=t->memstart+len;
    t->memsize=t->memsize+sizeof(tcbhead_t)+sizeof(*t)-len;
  }
  /* Problem: we need to unmap the stack and call exit, but we can't
   * touch the stack in between. Unfortunately, calling exit touches the
   * stack. Returning from the munmap syscall also touches the stack. So
   * this needs to be done in assembly language. */
  __munmap_and_exit(t->memstart,len);
}
#define _REENTRANT
#include <threads.h>
#include <sys/futex.h>
#include <sys/mman.h>
#include <sys/tls.h>
#include <errno.h>

int thrd_join(thrd_t thr, int* res) {
  int flags=thr->flags;
  int r;
  while ((flags&6) == 4) {
    /* if flags&4 then thrd_exit is already working on that thread.
     * when it's done, it does flags|=2.
     * so we wait for that. */
    __sync_synchronize();
    flags=thr->flags;
  }
  if ((flags&2)==0) {	/* is the thread still running? */
    if (flags&5)
      // thread is detached or in the process of being cleaned up, refuse join
      return thrd_error;
    if (!__sync_bool_compare_and_swap(&thr->join_futex,0,1))
      // somebody is already calling thrd_join, refuse join
      return thrd_error;
    do {
      r=futex(&thr->join_futex,FUTEX_WAIT,1,0,0,0);
    } while (r==-1 && errno==EINTR);
    if (res) *res=thr->res;
    thr->join_wait_futex=1;
    futex(&thr->join_wait_futex,FUTEX_WAKE,1,0,0,0);
  } else {
    /* thread is already dead, do cleanup */
    if (res) *res=thr->res;
    munmap(thr->arg,thr->memsize);
  }
  return thrd_success;
}

#include <threads.h>

thrd_t _thrd_root;
size_t _thrd_stacksize=16*1024;
#include <sys/timerfd.h>

extern int __timerfd(int ufd, int clockid, int flags, const struct itimerspec *utmr);

int timerfd_create (clockid_t __clock_id, int __flags) {
  return __timerfd(-1,__clock_id,__flags,0);
}
#include <string.h>

int timingsafe_bcmp(const void* a,const void* b,size_t n) {
  size_t i;
  const unsigned char* x = a;
  const unsigned char* y = b;
  int r;
  for (i=r=0; i<n; ++i)
    r |= x[i] ^ y[i];	/* x[i]^y[i] is 0 iff x[i]==y[i] */
  return !!r;	/* turn nonzero into 1 */
}
#include <string.h>

int timingsafe_memcmp(const void* a,const void* b,size_t n) {
  /* slightly harder than bcmp because we want to know which one was
   * smaller, not just if they did not match */
  register const unsigned char *x=a;
  register const unsigned char *y=b;
  int r=0,done=0;
  /* r is what we return in the end,
   * done is there to be 0 or -1 so we can assign to r branchlessly */
  size_t i;
  for (i=0; i<n; ++i) {
    int t=x[i]-y[i];
    /* if t is nonzero, t|-t will have the sign bit set */
    int minusone = (t|-t)>>(sizeof(int)-1);
    /* if there is no mismatch, t is 0. Then r |= t is a no-op. */
    /* if this is the first mismatch, we want to do r |= t. */
    /* if this is not the first mismatch, we want to leave r alone. */
    r |= t & ~done;
    done |= minusone;
  }
  return r;
}
#include <ctype.h>

int tolower(int ch) {
  if ( (unsigned int)(ch - 'A') < 26u )
    ch += 'a' - 'A';
  return ch;
}

#include <ctype.h>

inline int toupper(int ch) {
  if ( (unsigned int)(ch - 'a') < 26u )
    ch += 'A' - 'a';
  return ch;
}

#include <wctype.h>

wint_t towlower(wint_t c) {
  if ( (unsigned int)(c - 'A') < 26u )
    c += 'a' - 'A';
  return c;
}

#include <stdlib.h>
#include <threads.h>

extern thread_local tss_t tss_dtor_list;

int tss_create(tss_t* tss_id, tss_dtor_t destructor) {
  *tss_id=malloc(sizeof(**tss_id));
  if (!*tss_id) return thrd_nomem;
  (*tss_id)->dtor=destructor;
  (*tss_id)->next=tss_dtor_list;
  (*tss_id)->data=0;
  tss_dtor_list=*tss_id;
  return thrd_success;
}
#include <wctype.h>

wint_t towupper(wint_t c) {
  if ( (unsigned int)(c - 'a') < 26u )
    c += 'A' - 'a';
  return c;
}

#include <threads.h>

extern thread_local tss_t tss_dtor_list;

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
#include <threads.h>

void* tss_get(tss_t tss_id) {
  return tss_id->data;
}
#include <threads.h>

int tss_set(tss_t tss_id, void* val) {
  tss_id->data=val;
  return thrd_success;
}
#include "dietfeatures.h"
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

#ifdef __linux__

#include <stdlib.h>

char *ttyname(int fd) {
#ifdef SLASH_PROC_OK
  char ibuf[20];
  static char obuf[20];
  int len;
  if (!isatty(fd)) return 0;
  strcpy(ibuf,"/proc/self/fd/");
  ibuf[__ltostr(ibuf+14,6,(unsigned long)fd,10,0)+14]=0;
  if ((len=readlink(ibuf,obuf,sizeof(obuf)-1))<0) return 0;
  obuf[len]=0;
  return obuf;
#else
  static char buf[20];
  struct stat s;
  char *c=buf+8;
  int n;
  if (!isatty(fd)) return 0;
  if (fstat(fd,&s)) return 0;
  strcpy(buf,"/dev/tty");
  if (S_ISCHR(s.st_mode)) {
    n=minor(s.st_rdev);
    switch (major(s.st_rdev)) {
    case 4:
      if (n>63) {
	n-=64;
	*c='S';
	++c;
      }
num:
      c[__ltostr(c,6,n,10,0)]=0;
      break;
    case 2:
      buf[8]='p'-(n>>4);
      buf[9]=n%4+'0';
      if (buf[9]>'9') *c+='a'-'0';
      buf[10]=0;
      goto duh;
    case 136:
    case 137:
    case 138:
    case 139:
      buf[7]='s';
duh:
      buf[5]='p';
      n+=(major(s.st_rdev)-136)<<8;
      *c='/'; ++c;
      goto num;
    default:
      return 0;
    }
    return buf;
  }
  return 0;
#endif
}

#endif
#include <time.h>
#include <unistd.h>

/* nano * 1000 == usecs
 * usecs * 1000 == msecs
 * msecs * 1000 = secs */
int usleep(unsigned long usecs) {
  struct timespec t;
  t.tv_sec=usecs/1000000;
  t.tv_nsec=(usecs%1000000)*1000;
  return nanosleep(&t,&t);
}
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

#include <elf.h>

#include "internal.h"

#if (__WORDSIZE == 64)

#define phdr Elf64_Phdr
#define ehdr Elf64_Ehdr
#define shdr Elf64_Shdr
#define sym Elf64_Sym

#else

#define phdr Elf32_Phdr
#define ehdr Elf32_Ehdr
#define shdr Elf32_Shdr
#define sym Elf32_Sym

#endif

const void* vdso_dlsym(const char* elfimage,const char* symbol) {
  /* WARNING: this does NO validation AT ALL. */
  /* It is meant to be used on the VDSO ELF .so mapped into user space
   * by the kernel.  Since the kernel gave it to us, it is trustworthy.
   * A real dlsym would have to check all the pointers and offsets
   * against the file and section sizes, obviously. */
  const ehdr* eh=(ehdr*)elfimage;
  const char* dynstringtable=0;

  {
    size_t i;
    /* first traverse the section list to find ".dynstr"
     * we need the offset of .dynstr because the names in the symbol
     * list are given as offsets inside .dynstr */
    for (i=0; i<eh->e_shnum; ++i) {
      const shdr* sh=(shdr*)(elfimage + eh->e_shoff + i*eh->e_shentsize);
      if (sh->sh_type==3 && (sh->sh_flags&2)) {	// type SHT_STRTAB and flags has SHF_ALLOC
	dynstringtable = elfimage + sh->sh_offset;
	break;
      }
    }
  }

  /* now traverse .dynsym */
  if (dynstringtable) {
    size_t i;
    for (i=0; i<eh->e_shnum; ++i) {
      const shdr* sh=(shdr*)(elfimage + eh->e_shoff + i*eh->e_shentsize);
      if (sh->sh_type==11) {
	size_t j;
//	printf(".dynsym @ %p\n",vdso + sh->sh_offset);
	for (j=0; j*sh->sh_entsize < sh->sh_size; ++j) {
	  const sym* es=(sym*)(elfimage + sh->sh_offset + j*sh->sh_entsize);
//	  printf("%p: %s\n",((shdr*)(elfimage + eh->e_shoff + es->st_shndx * eh->e_shentsize))->sh-offset + es->st_value-eh->e_entry, dynstringtable+es->st_name);
	  if (!strcmp(dynstringtable+es->st_name,symbol)) {
	    const shdr* sec=(shdr*)(elfimage + eh->e_shoff + es->st_shndx*eh->e_shentsize);
	    size_t ofs=es->st_value-sec->sh_addr+sec->sh_offset;
//	    if (ofs>sec->sh_size) return 0;
//	    printf("found symbol \"%s\" at offset %p\n",dynstringtable+es->st_name,es->st_value);
	    return elfimage + ofs;
	  }
	}
      }
      sh = (shdr*)((char*)sh + eh->e_shentsize);
    }
  }
  return 0;
}

#include <unistd.h>

pid_t vfork() { return fork(); }

#include <stdarg.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "dietstdio.h"

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
#include <stdarg.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include "dietwarning.h"

int vsprintf(char *dest,const char *format, va_list arg_ptr)
{
  return vsnprintf(dest,(size_t)-1-(uintptr_t)dest,format,arg_ptr);
}

link_warning("vsprintf","warning: Avoid *sprintf; use *snprintf. It is more secure.")
#include <stdarg.h>
#include <sys/types.h>
#include <stdlib.h>
#include "dietstdio.h"
#include <unistd.h>

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
  struct str_data  fdat = { (unsigned char*)str };
  struct arg_scanf farg = { (void*)&fdat, (int(*)(void*))sgetc, (int(*)(int,void*))sputc };
  return __v_scanf(&farg,format,arg_ptr);
}
#include <sys/types.h>
#include <sys/wait.h>

pid_t wait(int *status) {
  return waitpid(-1,status,0);
}
#include <sys/wait.h>

pid_t wait3(int* status,int opts,struct rusage* rusage) {
  return wait4(-1,status,opts,rusage);
}
#include <wchar.h>
#include "dietlocale.h"

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
#include <wchar.h>

wchar_t* wcscat(wchar_t *__restrict__ dest, const wchar_t *__restrict__ src) {
  wchar_t* orig=dest;
  for (; *dest; ++dest) ;	/* go to end of dest */
  for (; (*dest=*src); ++src,++dest) ;	/* then append from src */
  return orig;
}
#include <wchar.h>

wchar_t* wcschr(const wchar_t *wcs, wchar_t wc) {
  for (; *wcs; ++wcs)
    if (*wcs == wc)
      return (wchar_t*)wcs;
  return 0;
}
#include <wchar.h>

int wcscmp(const wchar_t* a,const wchar_t* b) {
  while (*a && *a == *b)
    a++, b++;
  return (*a - *b);
}

int wcscoll(const wchar_t *s,const wchar_t* t)       __attribute__((weak,alias("wcscmp")));
#include <wchar.h>

wchar_t* wcscpy(wchar_t *__restrict__ dest, const wchar_t *__restrict__ src) {
  wchar_t* orig=dest;
  for (; (*dest=*src); ++src,++dest) ;
  return orig;
}
#include <wchar.h>

size_t wcslen(const wchar_t* s) {
  size_t i;
  for (i=0; s[i]; ++i) ;
  return i;
}
#include <wchar.h>

wchar_t* wcsncat(wchar_t *__restrict__ dest, const wchar_t *__restrict__ src,size_t n) {
  wchar_t* orig=dest;
  size_t i;
  while (*dest) ++dest;
  for (i=0; i<n && src[i]; ++i) dest[i]=src[i];
  dest[i]=0;
  return orig;
}
#include <wchar.h>

int wcsncmp(const wchar_t *s1, const wchar_t *s2, size_t n) {
  size_t i;
  for (i=0; i<n && s1[i]==s2[i]; ++i) ;
  return s1[i]-s2[i];
}
#include <wchar.h>

wchar_t* wcsncpy(wchar_t *__restrict__ dest, const wchar_t *__restrict__ src,size_t n) {
  wchar_t* orig=dest;
  for (; dest<orig+n && (*dest=*src); ++src,++dest) ;
  for (; dest<orig+n; ++dest) *dest=0;
  return orig;
}
#include <wchar.h>

wchar_t* wcsrchr(const wchar_t *wcs, wchar_t wc) {
  wchar_t* last=0;
  for (; *wcs; ++wcs)
    if (*wcs == wc)
      last=(wchar_t*)wcs;
  return last;
}
#include <stdlib.h>
#include <wchar.h>
#include "dietlocale.h"
#include <wchar.h>
#include <errno.h>
#include <string.h>

size_t wcsrtombs(char *dest, const wchar_t **src, size_t len, mbstate_t *ps) {
  wchar_t c;
  char buf[MB_CUR_MAX];
  size_t cur;
  if (!src || !*src) {
inval:
    errno=EINVAL;
    return -1;
  }
  if (!dest) {
    len=-1;
  }
  for (cur=0; (c=**src); ++*src) {
    size_t n;
    char* s=__likely(len-cur>=MB_CUR_MAX)?(dest?dest+cur:NULL):buf;
    n=wcrtomb(s,c,ps);
    if (n==(size_t)-1) return -1;
    if (dest && s==buf) {
      /* check if we fit */
      if (len<n) return cur;
      memcpy(dest+cur,buf,n);
    }
    cur+=n;
  }
  if (dest && len>cur) dest[cur]=0;
keinplatz:
  return cur;
}

#include <wchar.h>

wchar_t *wcsstr(const wchar_t *haystack, const wchar_t *needle) {
  size_t i,j;
  for (i=0; haystack[i]; ++i) {
    for (j=0; haystack[i+j]==needle[j]; ++j) ;
    if (!needle[j]) return (wchar_t*)haystack+i;
  }
  return 0;
}

#include <wchar.h>
#include "dietlocale.h"
#include <wchar.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

size_t wcstombs(char *dest, const wchar_t *src, size_t len) {
  return wcsrtombs(dest,&src,len,NULL);
}
#define _XOPEN_SOURCE
#include <wchar.h>

/*
 * This is an implementation of wcwidth() and wcswidth() (defined in
 * IEEE Std 1002.1-2001) for Unicode.
 *
 * http://www.opengroup.org/onlinepubs/007904975/functions/wcwidth.html
 * http://www.opengroup.org/onlinepubs/007904975/functions/wcswidth.html
 *
 * In fixed-width output devices, Latin characters all occupy a single
 * "cell" position of equal width, whereas ideographic CJK characters
 * occupy two such cells. Interoperability between terminal-line
 * applications and (teletype-style) character terminals using the
 * UTF-8 encoding requires agreement on which character should advance
 * the cursor by how many cell positions. No established formal
 * standards exist at present on which Unicode character shall occupy
 * how many cell positions on character terminals. These routines are
 * a first attempt of defining such behavior based on simple rules
 * applied to data provided by the Unicode Consortium.
 *
 * For some graphical characters, the Unicode standard explicitly
 * defines a character-cell width via the definition of the East Asian
 * FullWidth (F), Wide (W), Half-width (H), and Narrow (Na) classes.
 * In all these cases, there is no ambiguity about which width a
 * terminal shall use. For characters in the East Asian Ambiguous (A)
 * class, the width choice depends purely on a preference of backward
 * compatibility with either historic CJK or Western practice.
 * Choosing single-width for these characters is easy to justify as
 * the appropriate long-term solution, as the CJK practice of
 * displaying these characters as double-width comes from historic
 * implementation simplicity (8-bit encoded characters were displayed
 * single-width and 16-bit ones double-width, even for Greek,
 * Cyrillic, etc.) and not any typographic considerations.
 *
 * Much less clear is the choice of width for the Not East Asian
 * (Neutral) class. Existing practice does not dictate a width for any
 * of these characters. It would nevertheless make sense
 * typographically to allocate two character cells to characters such
 * as for instance EM SPACE or VOLUME INTEGRAL, which cannot be
 * represented adequately with a single-width glyph. The following
 * routines at present merely assign a single-cell width to all
 * neutral characters, in the interest of simplicity. This is not
 * entirely satisfactory and should be reconsidered before
 * establishing a formal standard in this area. At the moment, the
 * decision which Not East Asian (Neutral) characters should be
 * represented by double-width glyphs cannot yet be answered by
 * applying a simple rule from the Unicode database content. Setting
 * up a proper standard for the behavior of UTF-8 character terminals
 * will require a careful analysis not only of each Unicode character,
 * but also of each presentation form, something the author of these
 * routines has avoided to do so far.
 *
 * http://www.unicode.org/unicode/reports/tr11/
 *
 * Markus Kuhn -- 2007-05-26 (Unicode 5.0)
 *
 * Permission to use, copy, modify, and distribute this software
 * for any purpose and without fee is hereby granted. The author
 * disclaims all warranties with regard to this software.
 *
 * Latest version: http://www.cl.cam.ac.uk/~mgk25/ucs/wcwidth.c
 */

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

#include <stdlib.h>
#include <wchar.h>

int wctomb(char *pwc, wchar_t s) {
  return wcrtomb(pwc,s,NULL);
}
#define _XOPEN_SOURCE
#include <wchar.h>

/*
 * This is an implementation of wcwidth() and wcswidth() (defined in
 * IEEE Std 1002.1-2001) for Unicode.
 *
 * http://www.opengroup.org/onlinepubs/007904975/functions/wcwidth.html
 * http://www.opengroup.org/onlinepubs/007904975/functions/wcswidth.html
 *
 * In fixed-width output devices, Latin characters all occupy a single
 * "cell" position of equal width, whereas ideographic CJK characters
 * occupy two such cells. Interoperability between terminal-line
 * applications and (teletype-style) character terminals using the
 * UTF-8 encoding requires agreement on which character should advance
 * the cursor by how many cell positions. No established formal
 * standards exist at present on which Unicode character shall occupy
 * how many cell positions on character terminals. These routines are
 * a first attempt of defining such behavior based on simple rules
 * applied to data provided by the Unicode Consortium.
 *
 * For some graphical characters, the Unicode standard explicitly
 * defines a character-cell width via the definition of the East Asian
 * FullWidth (F), Wide (W), Half-width (H), and Narrow (Na) classes.
 * In all these cases, there is no ambiguity about which width a
 * terminal shall use. For characters in the East Asian Ambiguous (A)
 * class, the width choice depends purely on a preference of backward
 * compatibility with either historic CJK or Western practice.
 * Choosing single-width for these characters is easy to justify as
 * the appropriate long-term solution, as the CJK practice of
 * displaying these characters as double-width comes from historic
 * implementation simplicity (8-bit encoded characters were displayed
 * single-width and 16-bit ones double-width, even for Greek,
 * Cyrillic, etc.) and not any typographic considerations.
 *
 * Much less clear is the choice of width for the Not East Asian
 * (Neutral) class. Existing practice does not dictate a width for any
 * of these characters. It would nevertheless make sense
 * typographically to allocate two character cells to characters such
 * as for instance EM SPACE or VOLUME INTEGRAL, which cannot be
 * represented adequately with a single-width glyph. The following
 * routines at present merely assign a single-cell width to all
 * neutral characters, in the interest of simplicity. This is not
 * entirely satisfactory and should be reconsidered before
 * establishing a formal standard in this area. At the moment, the
 * decision which Not East Asian (Neutral) characters should be
 * represented by double-width glyphs cannot yet be answered by
 * applying a simple rule from the Unicode database content. Setting
 * up a proper standard for the behavior of UTF-8 character terminals
 * will require a careful analysis not only of each Unicode character,
 * but also of each presentation form, something the author of these
 * routines has avoided to do so far.
 *
 * http://www.unicode.org/unicode/reports/tr11/
 *
 * Markus Kuhn -- 2007-05-26 (Unicode 5.0)
 *
 * Permission to use, copy, modify, and distribute this software
 * for any purpose and without fee is hereby granted. The author
 * disclaims all warranties with regard to this software.
 *
 * Latest version: http://www.cl.cam.ac.uk/~mgk25/ucs/wcwidth.c
 */

#include <wchar.h>

struct interval {
  int first;
  int last;
};

/* auxiliary function for binary search in interval table */
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


/* The following two functions define the column width of an ISO 10646
 * character as follows:
 *
 *    - The null character (U+0000) has a column width of 0.
 *
 *    - Other C0/C1 control characters and DEL will lead to a return
 *      value of -1.
 *
 *    - Non-spacing and enclosing combining characters (general
 *      category code Mn or Me in the Unicode database) have a
 *      column width of 0.
 *
 *    - SOFT HYPHEN (U+00AD) has a column width of 1.
 *
 *    - Other format characters (general category code Cf in the Unicode
 *      database) and ZERO WIDTH SPACE (U+200B) have a column width of 0.
 *
 *    - Hangul Jamo medial vowels and final consonants (U+1160-U+11FF)
 *      have a column width of 0.
 *
 *    - Spacing characters in the East Asian Wide (W) or East Asian
 *      Full-width (F) category as defined in Unicode Technical
 *      Report #11 have a column width of 2.
 *
 *    - All remaining characters (including all printable
 *      ISO 8859-1 and WGL4 characters, Unicode control characters,
 *      etc.) have a column width of 1.
 *
 * This implementation assumes that wchar_t characters are encoded
 * in ISO 10646.
 */

int wcwidth(wchar_t ucs)
{
  /* sorted list of non-overlapping intervals of non-spacing characters */
  /* generated by "uniset +cat=Me +cat=Mn +cat=Cf -00AD +1160-11FF +200B c" */
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

  /* test for 8-bit control characters */
  if (ucs == 0)
    return 0;
  if (ucs < 32 || (ucs >= 0x7f && ucs < 0xa0))
    return -1;

  /* binary search in table of non-spacing characters */
  if (bisearch(ucs, combining,
	       sizeof(combining) / sizeof(struct interval) - 1))
    return 0;

  /* if we arrive here, ucs is not a combining or C0/C1 control character */

  return 1 + 
    (ucs >= 0x1100 &&
     (ucs <= 0x115f ||                    /* Hangul Jamo init. consonants */
      ucs == 0x2329 || ucs == 0x232a ||
      (ucs >= 0x2e80 && ucs <= 0xa4cf &&
       ucs != 0x303f) ||                  /* CJK ... Yi */
      (ucs >= 0xac00 && ucs <= 0xd7a3) || /* Hangul Syllables */
      (ucs >= 0xf900 && ucs <= 0xfaff) || /* CJK Compatibility Ideographs */
      (ucs >= 0xfe10 && ucs <= 0xfe19) || /* Vertical forms */
      (ucs >= 0xfe30 && ucs <= 0xfe6f) || /* CJK Compatibility Forms */
      (ucs >= 0xff00 && ucs <= 0xff60) || /* Fullwidth Forms */
      (ucs >= 0xffe0 && ucs <= 0xffe6) ||
      (ucs >= 0x20000 && ucs <= 0x2fffd) ||
      (ucs >= 0x30000 && ucs <= 0x3fffd)));
}

#include <unistd.h>
#include <string.h>
#include <write12.h>

#if defined(__i386__)
#define REGPARM(x) __attribute__((regparm(x)))
#else
#define REGPARM(x)
#endif

ssize_t REGPARM(1) __write1 (const char* s) {
  return write(1, s, strlen(s));
}

ssize_t REGPARM(1) __write2 (const char* s) {
  return write(2, s, strlen(s));
}
#include <endian.h>
#include <sys/types.h>
#include <sys/stat.h>

#ifndef __NO_STAT64
extern size_t __pread(int fd, void *buf, size_t count, int dummy, off_t a, off_t b);

size_t __libc_pread64(int fd, void *buf, size_t count, off64_t offset);
size_t __libc_pread64(int fd, void *buf, size_t count, off64_t offset) {
  return __pread(fd,buf,count,0,__LONG_LONG_PAIR( (off_t)(offset>>32),(off_t)(offset&0xffffffff) ));
}

int pread64(int fd, void *buf, size_t count, off_t offset) __attribute__((weak,alias("__libc_pread64")));
#endif
#include <endian.h>
#include <sys/types.h>
#include <sys/stat.h>

#ifndef __NO_STAT64
extern size_t __pwrite(int fd, void *buf, size_t count, int dummy, off_t a, off_t b);

size_t __libc_pwrite64(int fd, void *buf, size_t count, off64_t offset);
size_t __libc_pwrite64(int fd, void *buf, size_t count, off64_t offset) {
  return __pwrite(fd,buf,count,0,__LONG_LONG_PAIR ((off_t)(offset>>32),(off_t)(offset&0xffffffff)));
}

int pwrite64(int fd, void *buf, size_t count, off_t offset) __attribute__((weak,alias("__libc_pwrite64")));
#endif
/* 64-bit multiplication and division
   Copyright (C) 1989, 1992-1999, 2000, 2001, 2002, 2003, 2004
   Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */

#include <endian.h>
#include <stdlib.h>

#if __WORDSIZE == 32

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

#include "mips/longlong.h"

typedef unsigned int UQItype	__attribute__ ((mode (QI)));
typedef          int SItype	__attribute__ ((mode (SI)));
typedef unsigned int USItype	__attribute__ ((mode (SI)));
typedef          int DItype	__attribute__ ((mode (DI)));
typedef unsigned int UDItype	__attribute__ ((mode (DI)));
#define Wtype SItype
#define HWtype SItype
#define DWtype DItype
#define UWtype USItype
#define UHWtype USItype
#define UDWtype UDItype
#define W_TYPE_SIZE 32

#if __BYTE_ORDER == __BIG_ENDIAN
struct DWstruct { Wtype high, low;};
#elif __BYTE_ORDER == __LITTLE_ENDIAN
struct DWstruct { Wtype low, high;};
#else
#error Unhandled endianity
#endif
typedef union { struct DWstruct s; DWtype ll; } DWunion;

/* Prototypes of exported functions.  */
extern DWtype __divdi3 (DWtype u, DWtype v);
extern DWtype __moddi3 (DWtype u, DWtype v);
extern UDWtype __udivdi3 (UDWtype u, UDWtype v);
extern UDWtype __umoddi3 (UDWtype u, UDWtype v);

static UDWtype
__udivmoddi4 (UDWtype n, UDWtype d, UDWtype *rp)
{
  DWunion ww;
  DWunion nn, dd;
  DWunion rr;
  UWtype d0, d1, n0, n1, n2;
  UWtype q0, q1;
  UWtype b, bm;

  nn.ll = n;
  dd.ll = d;

  d0 = dd.s.low;
  d1 = dd.s.high;
  n0 = nn.s.low;
  n1 = nn.s.high;

#if !UDIV_NEEDS_NORMALIZATION
  if (d1 == 0)
    {
      if (d0 > n1)
	{
	  /* 0q = nn / 0D */

	  udiv_qrnnd (q0, n0, n1, n0, d0);
	  q1 = 0;

	  /* Remainder in n0.  */
	}
      else
	{
	  /* qq = NN / 0d */

	  if (d0 == 0)
	    d0 = 1 / d0;	/* Divide intentionally by zero.  */

	  udiv_qrnnd (q1, n1, 0, n1, d0);
	  udiv_qrnnd (q0, n0, n1, n0, d0);

	  /* Remainder in n0.  */
	}

      if (rp != 0)
	{
	  rr.s.low = n0;
	  rr.s.high = 0;
	  *rp = rr.ll;
	}
    }

#else /* UDIV_NEEDS_NORMALIZATION */

  if (d1 == 0)
    {
      if (d0 > n1)
	{
	  /* 0q = nn / 0D */

	  count_leading_zeros (bm, d0);

	  if (bm != 0)
	    {
	      /* Normalize, i.e. make the most significant bit of the
		 denominator set.  */

	      d0 = d0 << bm;
	      n1 = (n1 << bm) | (n0 >> (W_TYPE_SIZE - bm));
	      n0 = n0 << bm;
	    }

	  udiv_qrnnd (q0, n0, n1, n0, d0);
	  q1 = 0;

	  /* Remainder in n0 >> bm.  */
	}
      else
	{
	  /* qq = NN / 0d */

	  if (d0 == 0)
	    d0 = 1 / d0;	/* Divide intentionally by zero.  */

	  count_leading_zeros (bm, d0);

	  if (bm == 0)
	    {
	      /* From (n1 >= d0) /\ (the most significant bit of d0 is set),
		 conclude (the most significant bit of n1 is set) /\ (the
		 leading quotient digit q1 = 1).

		 This special case is necessary, not an optimization.
		 (Shifts counts of W_TYPE_SIZE are undefined.)  */

	      n1 -= d0;
	      q1 = 1;
	    }
	  else
	    {
	      /* Normalize.  */

	      b = W_TYPE_SIZE - bm;

	      d0 = d0 << bm;
	      n2 = n1 >> b;
	      n1 = (n1 << bm) | (n0 >> b);
	      n0 = n0 << bm;

	      udiv_qrnnd (q1, n1, n2, n1, d0);
	    }

	  /* n1 != d0...  */

	  udiv_qrnnd (q0, n0, n1, n0, d0);

	  /* Remainder in n0 >> bm.  */
	}

      if (rp != 0)
	{
	  rr.s.low = n0 >> bm;
	  rr.s.high = 0;
	  *rp = rr.ll;
	}
    }
#endif /* UDIV_NEEDS_NORMALIZATION */

  else
    {
      if (d1 > n1)
	{
	  /* 00 = nn / DD */

	  q0 = 0;
	  q1 = 0;

	  /* Remainder in n1n0.  */
	  if (rp != 0)
	    {
	      rr.s.low = n0;
	      rr.s.high = n1;
	      *rp = rr.ll;
	    }
	}
      else
	{
	  /* 0q = NN / dd */

	  count_leading_zeros (bm, d1);
	  if (bm == 0)
	    {
	      /* From (n1 >= d1) /\ (the most significant bit of d1 is set),
		 conclude (the most significant bit of n1 is set) /\ (the
		 quotient digit q0 = 0 or 1).

		 This special case is necessary, not an optimization.  */

	      /* The condition on the next line takes advantage of that
		 n1 >= d1 (true due to program flow).  */
	      if (n1 > d1 || n0 >= d0)
		{
		  q0 = 1;
		  sub_ddmmss (n1, n0, n1, n0, d1, d0);
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
	      UWtype m1, m0;
	      /* Normalize.  */

	      b = W_TYPE_SIZE - bm;

	      d1 = (d1 << bm) | (d0 >> b);
	      d0 = d0 << bm;
	      n2 = n1 >> b;
	      n1 = (n1 << bm) | (n0 >> b);
	      n0 = n0 << bm;

	      udiv_qrnnd (q0, n1, n2, n1, d1);
	      umul_ppmm (m1, m0, q0, d0);

	      if (m1 > n1 || (m1 == n1 && m0 > n0))
		{
		  q0--;
		  sub_ddmmss (m1, m0, m1, m0, d1, d0);
		}

	      q1 = 0;

	      /* Remainder in (n1n0 - m1m0) >> bm.  */
	      if (rp != 0)
		{
		  sub_ddmmss (n1, n0, n1, n0, m1, m0);
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

DWtype
__divdi3 (DWtype u, DWtype v)
{
  Wtype c = 0;
  DWtype w;

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
  w = __udivmoddi4 (u, v, NULL);
  if (c)
    w = -w;
  return w;
}

DWtype
__moddi3 (DWtype u, DWtype v)
{
  Wtype c = 0;
  DWtype w;

  if (u < 0)
    {
      c = ~c;
      u = -u;
    }
  if (v < 0)
    v = -v;
  __udivmoddi4 (u, v, (UDWtype *) &w);
  if (c)
    w = -w;
  return w;
}

UDWtype
__udivdi3 (UDWtype u, UDWtype v)
{
  return __udivmoddi4 (u, v, NULL);
}

UDWtype
__umoddi3 (UDWtype u, UDWtype v)
{
  UDWtype w;

  __udivmoddi4 (u, v, &w);
  return w;
}

#endif
#include <stdio_ext.h>
#include "dietstdio.h"

size_t __fbufsize(FILE* stream) {
  return stream->buflen;
}
#include <stdio_ext.h>
#include "dietstdio.h"

int __flbf(FILE* stream) {
  return !!(stream->flags&BUFLINEWISE);
}
#include <stdio_ext.h>
#include "dietstdio.h"

size_t __fpending(FILE* stream) {
  return stream->bm;
}
#include <stdio_ext.h>
#include "dietstdio.h"

void __fpurge(FILE* stream) {
  stream->ungotten=0;
  stream->bs=stream->bm=0;
}
#include <stdio_ext.h>
#include "dietstdio.h"

int __freadable(FILE* stream) {
  return !!(stream->flags&CANREAD);
}
#include <stdio_ext.h>
#include "dietstdio.h"

int __freading(FILE* stream) {
  return !(stream->flags&CANWRITE);
}
#include <stdio_ext.h>
#include "dietstdio.h"

int __fwritable(FILE* stream) {
  return !!(stream->flags&CANWRITE);
}
#include "dietstdio.h"

void clearerr_unlocked(FILE *stream) {
  stream->flags&=~(ERRORINDICATOR|EOFINDICATOR);
}

void clearerr(FILE *stream) __attribute__((weak,alias("clearerr_unlocked")));
#include "dietstdio.h"
#include <stdlib.h>
#include <unistd.h>

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
  if ((!(stream->flags&STATICBUF))&&(stream->buf))
    free(stream->buf);
  free(stream);
  return res;
}

int fclose(FILE *stream) __attribute__((weak,alias("fclose_unlocked")));
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#ifdef WANT_THREAD_SAFE
#include <pthread.h>
#endif
#include "dietstdio.h"

int __stdio_parse_mode(const char *mode) {
  int f=0;
  for (;;) {
    switch (*mode) {
    case 0: return f;
    case 'b': break;
    case 'r': f|=O_RDONLY; break;
    case 'w': f|=O_WRONLY|O_CREAT|O_TRUNC; break;
    case 'a': f|=O_WRONLY|O_CREAT|O_APPEND; break;
    case 'x': f|=O_EXCL; break;
    case '+': f=(f&(~O_WRONLY))|O_RDWR; break;
    }
    ++mode;
  }
}

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include "dietstdio.h"
#include <stdlib.h>
#ifdef WANT_THREAD_SAFE
#include <pthread.h>
#endif

extern int __stdio_atexit;

FILE*__stdio_init_file(int fd,int closeonerror,int mode) {
  FILE *tmp=(FILE*)malloc(sizeof(FILE));
  if (!tmp) goto err_out;
  tmp->buf=(char*)malloc(BUFSIZE);
  if (!tmp->buf) {
    free(tmp);
err_out:
    if (closeonerror) __libc_close(fd);
    errno=ENOMEM;
    return 0;
  }
  tmp->fd=fd;
  tmp->bm=0;
  tmp->bs=0;
  tmp->buflen=BUFSIZE;
  {
    struct stat st;
    fstat(fd,&st);
    tmp->flags=(S_ISFIFO(st.st_mode))?FDPIPE:0;
  }
  switch (mode&3) {
  case O_RDWR: tmp->flags|=CANWRITE;	/* fall through */
  case O_RDONLY: tmp->flags|=CANREAD|BUFINPUT; break;
  case O_WRONLY: tmp->flags|=CANWRITE;
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
#include <errno.h>
#include "dietfeatures.h"
#include <sys/types.h>
#include <dietstdio.h>
#include <unistd.h>

FILE *fdopen_unlocked(int filedes, const char *mode) {
  int f=0;	/* O_RDONLY, O_WRONLY or O_RDWR */

  f=__stdio_parse_mode(mode);
  if (filedes<0) { errno=EBADF; return 0; }
  return __stdio_init_file(filedes,0,f);
}

FILE *fdopen(int filedes, const char *mode) __attribute__((weak,alias("fdopen_unlocked")));
#include <dietstdio.h>

int feof_unlocked(FILE*stream) {
  /* yuck!!! */
  if (stream->ungotten) return 0;
  return (stream->flags&EOFINDICATOR);
}
int feof(FILE*stream)
__attribute__((weak,alias("feof_unlocked")));
#include <stdarg.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int fdprintf(int fd,const char *format,...) {
  int n;
  va_list arg_ptr;
  va_start(arg_ptr,format);
  n=vfdprintf(fd,format,arg_ptr);
  va_end(arg_ptr);
  return n;
}
#include <dietstdio.h>

int ferror_unlocked(FILE*stream) {
  return (stream->flags&ERRORINDICATOR);
}
int ferror(FILE*stream)
__attribute__((weak,alias("ferror_unlocked")));
#include <unistd.h>
#include <stdlib.h>
#include "dietwarning.h"
#include "dietstdio.h"

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
//  if (stream->flags&NOBUF) return 0;
  if (stream->flags&BUFINPUT) {
    register int tmp;
    if ((tmp=stream->bm-stream->bs)) {
      if (tmp && stream->ungotten) --tmp;
      lseek(stream->fd,tmp,SEEK_CUR);
    }
    stream->bs=stream->bm=0;
  } else {
    if (stream->bm && write(stream->fd,stream->buf,stream->bm)!=(ssize_t)stream->bm) {
      stream->flags|=ERRORINDICATOR;
      return -1;
    }
    stream->bm=0;
  }
  stream->ungotten=0;
  return 0;
}

int __fflush4(FILE *stream,int next) {
  if (__unlikely(!__stdio_atexit)) {
    __stdio_atexit=1;
    atexit(__stdio_flushall);
  }
  if (__unlikely((stream->flags&BUFINPUT)!=next)) {
    int res=fflush_unlocked(stream);
    stream->flags=(stream->flags&~BUFINPUT)|next;
    return res;
  }
  if (stream->fd==0 && __stdin_is_tty()) __fflush_stdout();
  return 0;
}

/* Internal function, has no prototype.
 * This is defined here because of the weak symbol ELF semantics */
int __stdio_outs(const char *s,size_t len);
int __stdio_outs(const char *s,size_t len) {
  return fwrite(s,1,(size_t)len,stdout)==len?1:0;
}

link_warning("fflush","warning: your code uses stdio (7+k bloat).")
#include "dietstdio.h"
#include <unistd.h>

int fgetc_unlocked(FILE *stream) {
  unsigned char c;
  if (__unlikely(!(stream->flags&CANREAD))) goto kaputt;
  if (__unlikely(stream->ungotten)) {
    stream->ungotten=0;
    return stream->ungetbuf;
  }

  /* common case first */
  if (__likely(stream->bm<stream->bs))
    return (unsigned char)stream->buf[stream->bm++];

  if (__unlikely(feof_unlocked(stream)))
    return EOF;
  if (__fflush4(stream,BUFINPUT)) return EOF;
  if (__unlikely(stream->bm>=stream->bs)) {
    ssize_t len=__libc_read(stream->fd,stream->buf,stream->buflen);
    if (len==0) {
      stream->flags|=EOFINDICATOR;
      return EOF;
    } else if (len<0) {
kaputt:
      stream->flags|=ERRORINDICATOR;
      return EOF;
    }
    stream->bm=0;
    stream->bs=len;
  }
  c=stream->buf[stream->bm];
  ++stream->bm;
  return c;
}

int fgetc(FILE* stream) __attribute__((weak,alias("fgetc_unlocked")));
#include <stdio.h>

int fgetpos(FILE *stream, fpos_t *pos) {
  long l=ftell(stream);
  if (l==-1) return -1;
  *pos=l;
  return 0;
}
#include "dietstdio.h"

char *fgets_unlocked(char *s, int size, FILE *stream) {
  int l;
  if (size<=0) return 0;
  for (l=0; l+1<size; ) {
    register int c;
    if (l && __likely(stream->bm<stream->bs)) {
      /* try common case first */
      c=(unsigned char)stream->buf[stream->bm++];
    } else {
      c=fgetc_unlocked(stream);
      if (__unlikely(c==EOF)) {
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
#include <dietstdio.h>

int fileno_unlocked(FILE*stream) {
  return stream->fd;
}
int fileno(FILE*stream)
__attribute__((weak,alias("fileno_unlocked")));
#include <sys/types.h>
#include <dietstdio.h>
#include <unistd.h>

extern int __stdio_atexit;

/* this is needed so the libpthread wrapper can initialize the mutex,
 * not to lock it */

FILE *fopen_unlocked(const char *path, const char *mode) {
  int f=0;	/* O_RDONLY, O_WRONLY or O_RDWR */
  int fd;

  f=__stdio_parse_mode(mode);
  if ((fd=__libc_open(path,f,0666))<0)
    return 0;
  return __stdio_init_file(fd,1,f);
}

FILE *fopen(const char *path, const char *mode) __attribute__((weak,alias("fopen_unlocked")));
#include <stdarg.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int fprintf(FILE *f,const char *format,...) {
  int n;
  va_list arg_ptr;
  va_start(arg_ptr,format);
  n=vfprintf(f,format,arg_ptr);
  va_end(arg_ptr);
  return n;
}
#include <dietstdio.h>
#include <unistd.h>
#include <endian.h>

int fputc_unlocked(int c, FILE *stream) {
  if (!__likely(stream->flags&CANWRITE) || __fflush4(stream,0)) {
kaputt:
    stream->flags|=ERRORINDICATOR;
    return EOF;
  }
  if (__unlikely(stream->bm>=stream->buflen-1))
    if (fflush_unlocked(stream)) goto kaputt;
  if (stream->flags&NOBUF) {
#if __BYTE_ORDER == __LITTLE_ENDIAN
    if (__libc_write(stream->fd,&c,1) != 1)
#else
    if (__libc_write(stream->fd,(char*)&c+sizeof(c)-1,1) != 1)
#endif
      goto kaputt;
    return (unsigned char)c;
  }
  stream->buf[stream->bm]=c;
  ++stream->bm;
  if (((stream->flags&BUFLINEWISE) && c=='\n') ||
      ((stream->flags&NOBUF))) /* puke */
    if (fflush_unlocked(stream)) goto kaputt;
  return (unsigned char)c;
}

int fputc(int c,FILE* stream) __attribute__((weak,alias("fputc_unlocked")));
#include "dietstdio.h"
#include <string.h>

int fputs_unlocked(const char*s,FILE*stream) {
  return fwrite_unlocked(s,strlen(s),1,stream);
}

int fputs(const char*s,FILE*stream) __attribute__((weak,alias("fputs_unlocked")));
#include <sys/types.h>
#include "dietstdio.h"
#include <unistd.h>

size_t fread_unlocked(void *ptr, size_t size, size_t nmemb, FILE *stream) {
  unsigned long i,j;
  j=size*nmemb;
  i=0;

  if (!(stream->flags&CANREAD)) {
    stream->flags|=ERRORINDICATOR;
    return 0;
  }
  if (!j || j/nmemb!=size) return 0;
  if (__unlikely(stream->ungotten)) {
    stream->ungotten=0;
    *(char*)ptr=stream->ungetbuf;
    ++i;
    if (j==1) return 1;
  }

#ifdef WANT_FREAD_OPTIMIZATION
  if (__unlikely(feof_unlocked(stream)))
    return 0;
  if (__fflush4(stream,BUFINPUT)) return 0;

  size_t inbuf=stream->bs-stream->bm;
  if (__unlikely(!inbuf)) {
    stream->bm=0;
    ssize_t res=__libc_read(stream->fd,stream->buf,stream->buflen);
    if (res<1) {
      stream->flags |= (res==0 ? EOFINDICATOR : ERRORINDICATOR);
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
  if ( !(stream->flags&FDPIPE) && (j>stream->buflen)) {
    size_t tmp=j-i;
    ssize_t res;
//    if (fflush_unlocked(stream)) return 0;
    while ((res=__libc_read(stream->fd,ptr+i,tmp))<(ssize_t)tmp) {
      if (res==-1) {
	stream->flags|=ERRORINDICATOR;
	goto exit;
      } else if (!res) {
	stream->flags|=EOFINDICATOR;
	goto exit;
      }
      i+=res; tmp-=res;
    }
    return nmemb;
  }
#endif
  for (; i<j; ++i) {
    int res;
    res=fgetc_unlocked(stream);
    if (res==EOF)
exit:
      return i/size;
    else
      ((unsigned char*)ptr)[i]=(unsigned char)res;
  }
  return nmemb;
}

size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream) __attribute__((weak,alias("fread_unlocked")));
#include <sys/types.h>
#include <dietstdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

/* this is needed so the libpthread wrapper can initialize the mutex,
 * not to lock it */

FILE *freopen_unlocked(const char *path, const char *mode, FILE *stream) {
  if (stream) {
    int f=__stdio_parse_mode(mode);
    fflush_unlocked(stream);
    __libc_close(stream->fd);
    if ((stream->fd=__libc_open(path,f,0666))!=-1) {
      struct stat st;
      fstat(stream->fd,&st);
      stream->flags=(S_ISFIFO(st.st_mode))?FDPIPE:0;
      switch (f&3) {
      case O_RDWR: stream->flags|=CANWRITE;	/* fall through */
      case O_RDONLY: stream->flags|=CANREAD; break;
      case O_WRONLY: stream->flags|=CANWRITE;
      }
    }
  } else errno=EINVAL;
  return stream;
}

FILE *freopen(const char *path, const char *mode, FILE *stream) __attribute__((weak,alias("freopen_unlocked")));
#include <stdarg.h>
#include <sys/types.h>
#include <stdlib.h>
#include "dietstdio.h"
#include <unistd.h>

int fscanf(FILE *stream, const char *format, ...) {
  int n;
  va_list arg_ptr;
  va_start(arg_ptr, format);
  n=vfscanf(stream,format,arg_ptr);
  va_end (arg_ptr);
  return n;
}
#include <dietstdio.h>
#include <unistd.h>

int fseek_unlocked(FILE *stream, long offset, int whence) {
  fflush_unlocked(stream);
  stream->bm=0; stream->bs=0;
  stream->flags&=~(ERRORINDICATOR|EOFINDICATOR);
  stream->ungotten=0;
  return lseek(stream->fd,offset,whence)!=-1?0:-1;
}

int fseek(FILE *stream, long offset, int whence) __attribute__((weak,alias("fseek_unlocked")));
#include <dietstdio.h>
#include <unistd.h>

int fseeko_unlocked(FILE *stream, off_t offset, int whence) {
  fflush(stream);
  stream->bm=0; stream->bs=0;
  stream->flags&=~(ERRORINDICATOR|EOFINDICATOR);
  stream->ungotten=0;
  return lseek(stream->fd,offset,whence)!=-1?0:-1;
}

int fseeko(FILE *stream, off_t offset, int whence) __attribute__((weak,alias("fseeko_unlocked")));
#include <dietstdio.h>
#include <unistd.h>
#include <sys/stat.h>

#ifndef __NO_STAT64
int fseeko64_unlocked(FILE *stream, off64_t offset, int whence) {
  fflush_unlocked(stream);
  stream->bm=0; stream->bs=0;
  stream->flags&=~(ERRORINDICATOR|EOFINDICATOR);
  stream->ungotten=0;
  return lseek64(stream->fd,offset,whence)!=-1?0:-1;
}

int fseeko64(FILE *stream, off64_t offset, int whence) __attribute__((weak,alias("fseeko64_unlocked")));
#endif
#include <stdio.h>

int fsetpos(FILE *stream, fpos_t *pos) {
  if (fseek(stream,*pos,SEEK_SET)==-1)
    return -1;
  return 0;
}
#include <dietstdio.h>
#include <unistd.h>
#include <errno.h>

long ftell_unlocked(FILE *stream) {
  off_t l;
  if (stream->flags&1 || (l=lseek(stream->fd,0,SEEK_CUR))==-1) return -1;
  if (stream->flags&BUFINPUT)
    return l-(stream->bs-stream->bm)-stream->ungotten;
  else
    return l+stream->bm;
}

long ftell(FILE *stream) __attribute__((weak,alias("ftell_unlocked")));
#include <dietstdio.h>
#include <unistd.h>

off_t ftello_unlocked(FILE *stream) {
  off_t l;
  if (fflush_unlocked(stream)) return -1;
  return ((l=lseek(stream->fd,0,SEEK_CUR))==-1?-1:l-stream->ungotten);
}

off_t ftello(FILE *stream) __attribute__((weak,alias("ftello_unlocked")));
#include <dietstdio.h>
#include <unistd.h>
#include <sys/stat.h>

#ifndef __NO_STAT64
off64_t ftello64_unlocked(FILE *stream) {
  off64_t l;
  if (fflush_unlocked(stream)) return -1;
  return ((l=lseek64(stream->fd,0ull,SEEK_CUR))==-1?-1:l-stream->ungotten);
}

off64_t ftello64(FILE *stream) __attribute__((weak,alias("ftello64_unlocked")));
#endif
#include <sys/types.h>
#include "dietstdio.h"
#include <unistd.h>
#include <errno.h>

size_t fwrite_unlocked(const void *ptr, size_t size, size_t nmemb, FILE *stream) {
  ssize_t res;
  size_t len=size*nmemb;
  size_t i,done;
  if (!__likely(stream->flags&CANWRITE) || __fflush4(stream,0)) {
kaputt:
    stream->flags|=ERRORINDICATOR;
    return 0;
  }
  if (!nmemb || len/nmemb!=size) return 0; /* check for integer overflow */
  if (__unlikely(len>stream->buflen || (stream->flags&NOBUF))) {
    if (fflush_unlocked(stream)) return 0;
    do {
      res=__libc_write(stream->fd,ptr,len);
    } while (res==-1 && errno==EINTR);
  } else
again:
         {
    /* try to make the common case fast */
    size_t todo=stream->buflen-stream->bm;
    if (todo>len) todo=len;

    if (todo) {
      if (stream->flags&BUFLINEWISE) {
	if (__unlikely((stream->flags&CHECKLINEWISE)!=0)) {
	  stream->flags&=~CHECKLINEWISE;
	  /* stdout is set to BUFLINEWISE|CHECKLINEWISE by default. */
	  /* that means we should check whether it is connected to a
	   * tty on first flush, and if not so, reset BUFLINEWISE */
	  if (!isatty(stream->fd)) {
	    stream->flags&=~BUFLINEWISE;
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
	  /* if we are here, we should not have an empty buffer */
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
      if (fputc_unlocked(((char*)ptr)[i],stream) == EOF) {
	res=len-i;
	goto abort;
      }
    res=len;
  }
  if (res<0) {
    stream->flags|=ERRORINDICATOR;
    return 0;
  }
abort:
  return size?res/size:0;
}

size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream) __attribute__((weak,alias("fwrite_unlocked")));
#include <stdarg.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include "dietstdio.h"

int printf(const char *format,...)
{
  int n;
  va_list arg_ptr;
  va_start(arg_ptr, format);
  n=vprintf(format, arg_ptr);
  va_end(arg_ptr);
  return n;
}
#include <stdio.h>

#undef putchar
int putchar(int c) {
  return fputc(c,stdout);
}
#include <unistd.h>
#include <string.h>
#include "dietstdio.h"
#include "dietfeatures.h"

int __stdio_outs(const char *s,size_t len) __attribute__((weak));
int __stdio_outs(const char *s,size_t len) {
  return (write(1,s,len)==(ssize_t)len)?1:0;
}

int puts(const char *s) {
  return (__stdio_outs(s,strlen(s)) && __stdio_outs("\n",1))?0:-1;
}

#include <stdarg.h>
#include <sys/types.h>
#include <stdlib.h>
#include "dietstdio.h"
#include <unistd.h>

int scanf(const char *format, ...) {
  int n;
  va_list arg_ptr;
  va_start(arg_ptr, format);
  n=vfscanf(stdin,format,arg_ptr);
  va_end (arg_ptr);
  return n;
}
#include <sys/types.h>
#include "dietstdio.h"
#include <unistd.h>
#include <stdlib.h>
#include "dietwarning.h"

static int set_flags(FILE *stream, int flags) {
  switch (flags) {
    case _IONBF: stream->flags = (stream->flags & ~(BUFLINEWISE)) | NOBUF; break;
    case _IOLBF: stream->flags = (stream->flags & ~(NOBUF)) | BUFLINEWISE; break;
    case _IOFBF: stream->flags = stream->flags & ~(NOBUF | BUFLINEWISE); break;
    default: return -1;
  }
  return 0;
}

int setvbuf_unlocked(FILE *stream, char *buf, int flags, size_t size) {
  if (buf) {
    if (!(stream->flags&STATICBUF)) free(stream->buf);
    stream->buf=buf;
  }
  else {
    char *tmp;
    if (!size) {
      return set_flags(stream,flags);
    }
    if (!(tmp=malloc(size))) return -1;
    if (!(stream->flags&STATICBUF)) free(stream->buf);
    stream->buf=tmp;
  }
  stream->flags &= ~STATICBUF;
  stream->buflen=size;
  stream->bm=stream->bs=0;
  return set_flags(stream,flags);
}

int setvbuf(FILE *stream, char *buf, int flags, size_t size) __attribute__((weak,alias("setvbuf_unlocked")));
#include <dietstdio.h>

static FILE __stderr = {
  .fd=2,
  .flags=NOBUF|CANWRITE,
  .bs=0, .bm=0,
  .buflen=0,
  .buf=0,
  .next=0,
  .popen_kludge=0,
  .ungetbuf=0,
  .ungotten=0,
#ifdef WANT_THREAD_SAFE
  .m=PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP,
#endif
};

FILE *stderr=&__stderr;

int __fflush_stderr(void) {
  return fflush(stderr);
}
#include <dietstdio.h>

static char __stdin_buf[BUFSIZE];
static FILE __stdin = {
  .fd=0,
  .flags=BUFINPUT|BUFLINEWISE|STATICBUF|CANREAD,
  .bs=0, .bm=0,
  .buflen=BUFSIZE,
  .buf=__stdin_buf,
  .next=0,
  .popen_kludge=0,
  .ungetbuf=0,
  .ungotten=0,
#ifdef WANT_THREAD_SAFE
  .m=PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP,
#endif
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
#include <dietstdio.h>

static char __stdout_buf[BUFSIZE];
static FILE __stdout = {
  .fd=1,
  .flags=BUFLINEWISE|STATICBUF|CANWRITE|CHECKLINEWISE,
  .bs=0, .bm=0,
  .buflen=BUFSIZE,
  .buf=__stdout_buf,
  .next=0,
  .popen_kludge=0,
  .ungetbuf=0,
  .ungotten=0,
#ifdef WANT_THREAD_SAFE
  .m=PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP,
#endif
};

FILE *stdout=&__stdout;

int __fflush_stdout(void) {
  return fflush(stdout);
}
#include "dietstdio.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/* this is needed so the libpthread wrapper can initialize the mutex,
 * not to lock it */

FILE *tmpfile_unlocked(void) {
  int fd;
  char template[20] = "/tmp/tmpfile-XXXXXX";
  if ((fd=mkstemp(template))<0)
    return 0;
  unlink(template);
  return __stdio_init_file(fd,1,O_RDWR);
}

FILE *tmpfile(void) __attribute__((weak,alias("tmpfile_unlocked")));
#include "dietstdio.h"

int ungetc_unlocked(int c, FILE *stream) {
  if (stream->ungotten || c<0 || c>255)
    return EOF;
  /* GNU configure configure wants us to differentiate between an ungetc
   * of the byte that was actually there ("backup ungetc") and a
   * different byte. Sigh. */
  if (stream->bm && stream->buf[stream->bm-1]==c) {
    --stream->bm;
  } else {
    stream->ungotten=1;
    stream->ungetbuf=(unsigned char)c;
  }
  stream->flags&=~(ERRORINDICATOR|EOFINDICATOR);
  return c;
}

int ungetc(int c, FILE *stream) __attribute__((weak,alias("ungetc_unlocked")));
#include <stdarg.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include "dietstdio.h"

static int __fwrite(const void*ptr, size_t nmemb, void* cookie) {
  return write((uintptr_t)cookie,ptr,nmemb);
}

int vfdprintf(int fd, const char *format, va_list arg_ptr)
{
  struct arg_printf ap = { (void*)(long)fd, __fwrite };
  return __v_printf(&ap,format,arg_ptr);
}
#include <stdarg.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include "dietstdio.h"

static int __fwrite(const void*ptr, size_t nmemb, void* cookie) {
  return fwrite(ptr,1,nmemb,(FILE*)cookie);
}

int vfprintf(FILE *stream, const char *format, va_list arg_ptr)
{
  struct arg_printf ap = { stream, __fwrite };
  return __v_printf(&ap,format,arg_ptr);
}
#include <stdarg.h>
#include <sys/types.h>
#include <stdlib.h>
#include "dietstdio.h"
#include <unistd.h>

int vfscanf(FILE *stream, const char *format, va_list arg_ptr)
{
  struct arg_scanf farg = { (void*)stream, (int(*)(void*))fgetc, (int(*)(int,void*))ungetc };
  return __v_scanf(&farg,format,arg_ptr);
}
#include <stdarg.h>
#include <unistd.h>
#include "dietstdio.h"

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

#include <stdarg.h>
#include <sys/types.h>
#include <stdlib.h>
#include "dietstdio.h"
#include <unistd.h>

int vscanf(const char *format, va_list arg_ptr)
{
  return vfscanf(stdin,format,arg_ptr);
}
#include <signal.h>

/* 
 * Block a bunch of signals.  Call with a sigset_t pointer into which
 * the old signal set is placed.  On error (which should never happen),
 * returns NULL, otherwise returns oldset.
 */

sigset_t *__utmp_block_signals (sigset_t *oldset);

sigset_t *
__utmp_block_signals (sigset_t *oldset)
{
    sigset_t blockset;

    /* There are actually more signals to block than not, so just start
     * with everything */
    sigfillset (&blockset);

    /* Don't try to block program error signals */

    /* Unconditionally defined signals */
    sigdelset (&blockset, SIGILL);
    sigdelset (&blockset, SIGTRAP);
    sigdelset (&blockset, SIGABRT);
    sigdelset (&blockset, SIGIOT);  /* Yeah, right */
    sigdelset (&blockset, SIGFPE);
    sigdelset (&blockset, SIGSEGV);

    /* Others.  FIXME - This list may need to be expanded. */
#ifdef SIGBUS
    sigdelset (&blockset, SIGBUS);
#endif
#ifdef SIGEMT
    sigdelset (&blockset, SIGEMT);
#endif
#ifdef SIGSYS
    sigdelset (&blockset, SIGSYS);
#endif

    if (sigprocmask (SIG_BLOCK, &blockset, oldset) < 0)
	oldset = (sigset_t *)0;

    return oldset;
}
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

void *__utmp_io(int fd, void *ut, ssize_t len, off_t *offset, int type);

/* type:  F_RDLCK or F_WRLCK */
void *
__utmp_io(int fd, void *ut, ssize_t len, off_t *offset, int type) {
  int e, ret;
  struct flock fl;
  off_t newoffset;

  fl.l_whence	= SEEK_CUR;
  fl.l_start	= 0;
  fl.l_len	= len;
  fl.l_pid	= 0;
  fl.l_type	= type;
  
  if (fcntl(fd, F_SETLKW, &fl)) return 0;
  if (type == F_WRLCK) {
      ret = write(fd, ut, len);
      e = errno;
      fsync (fd);
      /* FIXME - where exactly should the offset point after a write? */
      newoffset = lseek (fd, 0, SEEK_CUR);
   } else {
      newoffset = lseek (fd, 0, SEEK_CUR);
      ret = read(fd, ut, len);
      e = errno;
  }

  fl.l_start	= -(len);
  fl.l_type	= F_UNLCK;

  fcntl(fd, F_SETLK, &fl);

  /* Arrrgh! There's no provision in the POSIX utmp spec for detecting errors.
   * Stupidly update the offset. */
  if (offset)
      *offset = newoffset;

  errno = e;
  if (ret != len) 
      return (void *)0;
  return ut;
}
#include <stdio.h>
#include <stdlib.h>
#include <mntent.h>
#include <string.h>

#include <errno.h>

/* FIXME: what happens with spaces/tabs/newlines in the
 * mountpoint/options/type*/

int addmntent(FILE*filep,const struct mntent*mnt) {
  struct mntent m=*mnt;
  char buf[2048];
  if (strlen(m.mnt_opts)==0) m.mnt_opts="rw";
  if (snprintf(buf,sizeof(buf),"%s %s %s %s %d %d\n",
		m.mnt_fsname,m.mnt_dir,m.mnt_type,m.mnt_opts,
		m.mnt_freq,m.mnt_passno)>=(int)sizeof(buf)) return 1;
  if (fputs(buf,filep)==EOF) return 1;
  return 0;
}

#include <time.h>

static char buf[26];

char *asctime(const struct tm *timeptr) {
  return asctime_r(timeptr,buf);
}
#include <time.h>

static const char days[] = "Sun Mon Tue Wed Thu Fri Sat ";
static const char months[] = "Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec ";

static void num2str(char *c,int i) {
  c[0]=i/10+'0';
  c[1]=i%10+'0';
}

char *asctime_r(const struct tm *t, char *buf) {
  /* "Wed Jun 30 21:49:08 1993\n" */
  *(int*)buf=*(int*)(days+(t->tm_wday<<2));
  *(int*)(buf+4)=*(int*)(months+(t->tm_mon<<2));
  num2str(buf+8,t->tm_mday);
  if (buf[8]=='0') buf[8]=' ';
  buf[10]=' ';
  num2str(buf+11,t->tm_hour);
//  if (buf[11]=='0') buf[11]=' ';
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
#include <stdarg.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include "dietwarning.h"

int asprintf(char **s, const char *format,...)
{
  int n;
  va_list arg_ptr;
  char tmp[8];
  va_start(arg_ptr, format);
  n=vsnprintf(tmp,0,format,arg_ptr);
  va_start (arg_ptr, format);
  if ((*s=malloc(n+1))) {
    n=vsnprintf(*s,n+1,format,arg_ptr);
    return n;
  }
  return -1;
}
#include <time.h>

char *ctime(const time_t *timep) {
  return asctime(localtime(timep));
}
#include <time.h>

char *ctime_r(const time_t *timep, char* buf) {
  return asctime_r(localtime(timep),buf);
}
#include <time.h>
#include "../dietwarning.h"

double difftime(time_t time1, time_t time2) {
    return (double)time1 - (double)time2;
}

link_warning("difftime","warning: difftime introduces an unnecessary floating point dependency. Don't use it!")
#include <sys/types.h>
#include "dietdirent.h"
#define _BSD_SOURCE
#include <dirent.h>

int dirfd(DIR* dirp) {
  return dirp->fd;
}
#include <stdio.h>
#include <mntent.h>

int endmntent(FILE *filep) {
  fclose(filep);
  return 1;
}

#include <sys/syslog.h>

#ifndef INTERNAL_MARK
#define INTERNAL_MARK 0x300
#endif

CODE facilitynames[] =
  {
    { "auth", LOG_AUTH },
    { "authpriv", LOG_AUTHPRIV },
    { "cron", LOG_CRON },
    { "daemon", LOG_DAEMON },
    { "ftp", LOG_FTP },
    { "kern", LOG_KERN },
    { "lpr", LOG_LPR },
    { "mail", LOG_MAIL },
    { "mark", INTERNAL_MARK },		/* INTERNAL */
    { "news", LOG_NEWS },
    { "security", LOG_AUTH },		/* DEPRECATED */
    { "syslog", LOG_SYSLOG },
    { "user", LOG_USER },
    { "uucp", LOG_UUCP },
    { "local0", LOG_LOCAL0 },
    { "local1", LOG_LOCAL1 },
    { "local2", LOG_LOCAL2 },
    { "local3", LOG_LOCAL3 },
    { "local4", LOG_LOCAL4 },
    { "local5", LOG_LOCAL5 },
    { "local6", LOG_LOCAL6 },
    { "local7", LOG_LOCAL7 },
    { 0, -1 }
  };
#include <sys/socket.h>
#include <stdlib.h>

void freeaddrinfo(struct addrinfo *res) {
  while (res) {
    struct addrinfo *duh;
    duh=res;
    res=res->ai_next;
    free(duh);
  }
}
#include <sys/time.h>
#include <sys/timeb.h>
#include <unistd.h>

int ftime(struct timeb *tp) {
  struct timeval tv;
  struct timezone tz;
  int ret=gettimeofday(&tv,&tz);
  tp->time	= tv.tv_sec;
  tp->millitm	= tv.tv_usec/1000;
  tp->timezone	= tz.tz_minuteswest;
  tp->dstflag	= tz.tz_dsttime;
  return ret;
}

#include <sys/socket.h>

const char* gai_strerror(int error) {
  switch (error) {
  case EAI_FAMILY: return "family not supported";
  case EAI_SOCKTYPE: return "socket type not supported";
  case EAI_NONAME: return "unknown host";
  case EAI_SERVICE: return "unknown service";
  case EAI_MEMORY: return "memory allocation failure";
  case EAI_AGAIN: return "temporary failure";
  }
  return "DNS error. Sorry.";
}
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <net/if.h>
#include <arpa/inet.h>
#include "dietfeatures.h"

#ifdef WANT_PLUGPLAY_DNS
extern int __dns_plugplay_interface;
#endif

/* XXX TODO FIXME */

int getaddrinfo(const char *node, const char *service, const struct addrinfo *hints, struct addrinfo **res) {
  struct addrinfo **tmp;
  int family;
  int error=EAI_NONAME;
  int flags=0;
  tmp=res; *res=0;
  if (hints) {
    if (hints->ai_family && hints->ai_family != PF_INET6 && hints->ai_family != PF_INET) return EAI_FAMILY;
    if (hints->ai_socktype && hints->ai_socktype != SOCK_STREAM && hints->ai_socktype != SOCK_DGRAM) return EAI_SOCKTYPE;
    flags=hints->ai_flags;
    if ((flags&AI_V4MAPPED) && hints->ai_family!=PF_INET6) flags&=~(AI_V4MAPPED|AI_ALL);
  }
  for (family=PF_INET6; ; family=PF_INET) {
    if (!hints || hints->ai_family==family || hints->ai_family==AF_UNSPEC || (flags&(AI_V4MAPPED|AI_ALL))) {
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
	if (family==PF_INET6 && inet_pton(AF_INET,node,buf)) continue;
	if (inet_pton(family,node,buf)>0) {
	  h.h_name=(char*)node;
	  h.h_addr_list[0]=buf;
	  lookupok=1;
	} else if (!(flags&AI_NUMERICHOST) &&
		   !gethostbyname2_r(node,family,&h,buf,4096,&H,&herrno)) {
	  lookupok=1;
	} else {
	  if (herrno==TRY_AGAIN) { freeaddrinfo(*res); return EAI_AGAIN; }
	}
      } else {
	h.h_name=0;
	h.h_addr_list[0]=buf;
	interface=0;
	memset(buf,0,16);
	if (!(flags&AI_PASSIVE)) {
	  if (family==AF_INET) {
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
	  foo->ai.ai_addrlen=family==PF_INET6?sizeof(struct sockaddr_in6):sizeof(struct sockaddr_in);
	  foo->ai.ai_addr=(struct sockaddr*)&foo->ip;
	  memset(&foo->ip,0,sizeof(foo->ip));
	  foo->ip.ip6.sin6_family=foo->ai.ai_family=family;
	  if (family==PF_INET6) {
	    memmove(&foo->ip.ip6.sin6_addr,h.h_addr_list[i],16);
	    if (interface) foo->ip.ip6.sin6_scope_id=if_nametoindex(interface);
	  } else {
	    /* IPv4 */
	    if (flags&AI_V4MAPPED) {
	      foo->ai.ai_addrlen=sizeof(struct sockaddr_in6);
	      foo->ip.ip6.sin6_addr.s6_addr[10]=foo->ip.ip6.sin6_addr.s6_addr[11]=0xff;
	      memmove(foo->ip.ip6.sin6_addr.s6_addr+12,h.h_addr_list[i],4);
	      foo->ip.ip6.sin6_family=foo->ai.ai_family=PF_INET6;
	    } else
	      memmove(&foo->ip.ip4.sin_addr,h.h_addr_list[i],4);
	  }
#ifdef WANT_PLUGPLAY_DNS
	  if (family==PF_INET6 && node) {
	    int l=strlen(node);
	    if ((l>6 && !strcmp(node+l-6,".local")) || !strchr(node,'.'))
	      foo->ip.ip6.sin6_scope_id=__dns_plugplay_interface;
	  }
#endif
	  if (h.h_name) {
	    foo->ai.ai_canonname=foo->name;
	    memmove(foo->name,h.h_name,strlen(h.h_name)+1);
	  } else
	    foo->ai.ai_canonname=0;

	  for (foo->ai.ai_socktype=SOCK_STREAM; ; foo->ai.ai_socktype=SOCK_DGRAM) {
	    char* type,* x;
	    if (foo->ai.ai_socktype==SOCK_STREAM) {	/* TCP */
	      if (hints && hints->ai_socktype==SOCK_DGRAM) continue;
	      foo->ai.ai_protocol=IPPROTO_TCP;
	      type="tcp";
	    } else {	/* UDP */
	      if (hints && hints->ai_socktype==SOCK_STREAM) break;
	      foo->ai.ai_protocol=IPPROTO_UDP;
	      type="udp";
	    }
	    port=htons(strtol(service?service:"0",&x,0));
	    if (*x) {	/* service is not numeric :-( */
	      struct servent* se;
	      if (!(flags&AI_NUMERICSERV) &&
		  (se=getservbyname(service,type)))
		port=se->s_port;
	      else {
/* can't just fail hard here; maybe the port is defined but not for the protocol we are trying */
		error=EAI_SERVICE;
		if (foo->ai.ai_socktype==SOCK_DGRAM) break;
		continue;
	      }
	    }
	    if (foo->ai.ai_family==PF_INET6)
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
	    if (foo->ai.ai_socktype==SOCK_DGRAM) break;
	  }
	  free(foo);
	}
      }
    }
    if (hints && hints->ai_family==PF_INET6 && (flags&AI_V4MAPPED) && *res==0)
      flags|=AI_ALL;
    if (family==PF_INET) break;
  }
  if (*res==0) return error; /* kludge kludge... */
  return 0;
error:
  freeaddrinfo(*res);
  return EAI_MEMORY;
}
#include <unistd.h>
#include <fcntl.h>
#include <netdb.h>
#include <sys/mman.h>
#include <errno.h>
#include <netinet/in.h>
#include <string.h>
#include <ctype.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "dietfeatures.h"

static char* hostmap;
static unsigned int hostlen;

static char *cur;

/* ::1	localhost6	alias1 alias2		# internet protocol, pseudo protocol number */
struct hostent* gethostent_r(char* buf, int len) {
  char *dest;
  struct hostent* pe=(struct hostent*)buf;
  char* last;
  char* max=buf+len;
  int aliasidx;
  if (!hostmap) {
    int hostfd=open(_PATH_HOSTS,O_RDONLY);
    if (hostfd<0) return 0;
    hostlen=lseek(hostfd,0,SEEK_END);
    hostmap=mmap(0,hostlen,PROT_READ|PROT_WRITE,MAP_PRIVATE,hostfd,0);
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
  /* first, the ip number */
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
    if (inet_pton(AF_INET6,pe->h_name,dest)>0) {
      pe->h_addrtype=AF_INET6;
      pe->h_length=16;
      dest+=16;
    } else if (inet_pton(AF_INET,pe->h_name,dest)>0) {
      pe->h_addrtype=AF_INET;
      pe->h_length=4;
      dest+=4;
    } else {
      *cur=save;
      goto parseerror;
    }
    *cur=save;
  }
  ++cur;
  /* now the aliases */
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
  errno=ERANGE;
  goto __error;
error:
  errno=ENOMEM;
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

#include <netdb.h>

static char hostentbuf[1024];

struct hostent* gethostent() {
  return gethostent_r(hostentbuf,sizeof(hostentbuf));
}
#include <stdio.h>
#include <stdlib.h>
#include <mntent.h>
#include <string.h>

struct mntent *getmntent(FILE *filep) {
  static struct mntent m;
  static char buf[1024];
  do {
    char *tmp=buf;
    int num;
    if (!fgets(buf,1024,filep)) return 0;
/* "/dev/ide/host0/bus0/target0/lun0/part2 / reiserfs defaults 1 1" */
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
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>

int getnameinfo(const struct sockaddr *sa, socklen_t salen, char *host,
		size_t hostlen, char *serv, size_t servlen, int flags) {
  sa_family_t f=((struct sockaddr_storage *)sa)->ss_family;
  (void)salen;	/* shut gcc up about unused salen */
  if (host && hostlen>0) {	/* user wants me to resolve the host name */
    register const char*addr=(f==AF_INET6)?(char*)&((struct sockaddr_in6*)sa)->sin6_addr:
					   (char*)&((struct sockaddr_in*)sa)->sin_addr;
    if (flags&NI_NUMERICHOST) {
      if (!inet_ntop(f,addr,host,hostlen))
	return EAI_NONAME;
    } else {
      char buf[4096];
      struct hostent h;
      struct hostent *H;
      int herrno;
      if (gethostbyaddr_r(addr,f==AF_INET6?16:4,f,&h,buf,4096,&H,&herrno)) {
	switch (herrno) {
	case TRY_AGAIN: return EAI_AGAIN;
	case NO_DATA:
	case HOST_NOT_FOUND: return EAI_NONAME;
	}
      }
      strncpy(host,h.h_name,hostlen-1);
      host[hostlen-1]=0;
    }
  }
  if (serv && servlen>0) {
    register short int port=(f==AF_INET6)?((struct sockaddr_in6*)sa)->sin6_port:((struct sockaddr_in*)sa)->sin_port;
    if (flags&NI_NUMERICSERV) {
      __ltostr(serv,servlen,ntohs(port),10,0);
    } else {
      struct servent *s;
      if (!(s=getservbyport(port,flags&NI_DGRAM?"udp":"tcp")))
	return EAI_SERVICE;
      strncpy(serv,s->s_name,servlen-1);
      serv[servlen-1]=0;
    }
  }
  return 0;
}
#include <string.h>
#include <netdb.h>

extern struct protoent __protoent_pw;
extern char __protoent_buf[1000];

struct protoent *getprotobyname(const char *name) {
  struct protoent* tmp;
  if (getprotobyname_r(name,&__protoent_pw,__protoent_buf,sizeof(__protoent_buf),&tmp)==0)
    return tmp;
  return 0;
}
#include <string.h>
#include <netdb.h>

extern int getprotobyname_r(const char* name,
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
#include <string.h>
#include <netdb.h>

extern struct protoent __protoent_pw;
extern char __protoent_buf[1000];

struct protoent *getprotobynumber(int proto) {
  struct protoent* tmp;
  if (getprotobynumber_r(proto,&__protoent_pw,__protoent_buf,sizeof(__protoent_buf),&tmp)==0)
    return tmp;
  return 0;
}
#include <netdb.h>

extern struct protoent __protoent_pw;
extern char __protoent_buf[1000];

struct protoent *getprotoent(void) {
  struct protoent* tmp;
  getprotoent_r(&__protoent_pw,__protoent_buf,sizeof(__protoent_buf),&tmp);
  return tmp;
}
#include <string.h>
#include <netdb.h>

extern int getprotobynumber_r(int proto,
			   struct protoent *res, char *buf, size_t buflen,
			   struct protoent **res_sig) {
  while (!getprotoent_r(res,buf,buflen,res_sig))
    if (proto==res->p_proto) goto found;
  *res_sig=0;
found:
  endprotoent();
  return *res_sig?0:-1;
}
#include <string.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <netdb.h>
#include <ctype.h>
#include "parselib.h"

static struct state __ps;

void setprotoent(int stayopen) {
  (void)stayopen;
  __prepare_parse(_PATH_PROTOCOLS,&__ps);
}

void endprotoent(void) {
  __end_parse(&__ps);
}

#define ALIASES 16

/* "igmp	2	IGMP		# internet group management protocol" */
int getprotoent_r(struct protoent *res, char *buf, size_t buflen,
		  struct protoent **res_sig) {
  size_t i,j,n,g;
  unsigned long l;
  if (!__ps.buffirst) setprotoent(0);
  if (!__ps.buffirst) goto error;
  if (__ps.cur>=__ps.buflen) goto error;
  res->p_aliases=(char**)buf;
/*  getprotoent */
again:
  n=ALIASES*sizeof(char*); g=0;
  for (i=0; i<3; ++i) {
    char found;
    __ps.cur+=__parse_ws(&__ps);
    if (__ps.cur>=__ps.buflen) { if (i==2) break; else goto error; }
    j=__parse_nws(&__ps);
    if (!isblank(found=__ps.buffirst[__ps.cur+j])) {
      if (i==2) break;	/* it's ok, no (more) aliases necessary */
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
      if (g==(ALIASES-1)) break;
      --i;	/* again */
      goto copy;
    }
    __ps.cur+=j+1;
  }
  res->p_aliases[g]=0;
  *res_sig=res;
  return 0;
error:
  *res_sig=0;/* the glibc people should be taken behind the barn and shot */
  return -1;
}
#include <string.h>
#include <netdb.h>

extern struct servent __servent_pw;
extern char __servent_buf[1000];

struct servent *getservbyname(const char *name, const char *proto) {
  struct servent* tmp;
  if (getservbyname_r(name,proto,&__servent_pw,__servent_buf,sizeof(__servent_buf),&tmp)==0)
    return tmp;
  return 0;
}
#include <string.h>
#include <netdb.h>

extern int getservbyname_r(const char* name,const char* proto,
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
#include <string.h>
#include <netdb.h>

extern struct servent __servent_pw;
extern char __servent_buf[1000];

struct servent *getservbyport(int port, const char *proto) {
  struct servent* tmp;
  if (getservbyport_r(port,proto,&__servent_pw,__servent_buf,sizeof(__servent_buf),&tmp)==0)
    return tmp;
  return 0;
}
#include <string.h>
#include <netdb.h>

extern int getservbyport_r(int port,const char* proto,
			   struct servent *res, char *buf, size_t buflen,
			   struct servent **res_sig) {
  while (!getservent_r(res,buf,buflen,res_sig))
    if (port==res->s_port && !strcmp(res->s_proto,proto)) goto ok;
  *res_sig=0;
ok:
  endservent();
  return *res_sig?0:-1;
}
#include <netdb.h>

extern struct servent __servent_pw;
extern char __servent_buf[1000];

struct servent *getservent(void) {
  struct servent* tmp;
  getservent_r(&__servent_pw,__servent_buf,sizeof(__servent_buf),&tmp);
  return tmp;
}
#include <sys/types.h>
#include <sys/mman.h>
#include <netinet/in.h>
#include <string.h>
#include <netdb.h>
#include <ctype.h>
#include "parselib.h"

static struct state __ps;

void setservent(int stayopen) {
  (void)stayopen;
  __prepare_parse(_PATH_SERVICES,&__ps);
}

void endservent(void) {
  __end_parse(&__ps);
}

#define ALIASES 16

/* "tcpmux		1/tcp		# TCP port multiplexer (RFC1078)" */
int getservent_r(struct servent *res, char *buf, size_t buflen,
		 struct servent **res_sig) {
  size_t i,j,n,g;
  unsigned long l;
  if (!__ps.buffirst) setservent(0);
  if (!__ps.buffirst) goto error;
  if (__ps.cur>=__ps.buflen) goto error;
  res->s_aliases=(char**)buf;
/*  getservent */
again:
  n=ALIASES*sizeof(char*); g=0;
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
      if (g==(ALIASES-1)) break;
      --i;	/* again */
      goto copy;
    }
    __ps.cur+=j+1;
  }
  res->s_aliases[g]=0;
  *res_sig=res;
  return 0;
error:
  *res_sig=0;/* the glibc people should be taken behind the barn and shot */
  return -1;
}
#include <time.h>

struct tm* gmtime(const time_t *t) {
  static struct tm tmp;
  return gmtime_r(t,&tmp);
}
#include <time.h>

/* seconds per day */
#define SPD 24*60*60

extern short __spm[];

struct tm *gmtime_r(const time_t *timep, struct tm *r) {
  time_t i;
  register time_t work=*timep%(SPD);
  r->tm_sec=work%60; work/=60;
  r->tm_min=work%60; r->tm_hour=work/60;
  work=*timep/(SPD);
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
    if (work==59) r->tm_mday=2; /* 29.2. */
    work-=1;
  }

  for (i=11; i && (__spm[i]>work); --i) ;
  r->tm_mon=i;
  r->tm_mday+=work-__spm[i];
  return r;
}
#define _XOPEN_SOURCE
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>

int grantpt (int fd) {
  struct stat st;
  if ((fstat(fd, &st))<0) return -1;
  if ((chmod((char*)ptsname(fd), st.st_mode | S_IRUSR | S_IWUSR | S_IWGRP))<0)
    return -1;
  return 0;
}
#include <string.h>
#include <mntent.h>

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
#include "dietfeatures.h"
#include <errno.h>
#include "dieticonv.h"
#include <netinet/in.h>

static unsigned int utf8bounds[]={0x7f,0x7ff,0xffff,0x1fffff,0x3ffffff,0x7fffffff};

size_t iconv(iconv_t cd, char* * inbuf, size_t *
		    inbytesleft, char* * outbuf, size_t * outbytesleft) {
  size_t result=0,i,j,k;
  int bits;
  unsigned char* in,* out;
  enum charset from=ic_from(cd);
  enum charset to=ic_to(cd);
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
	errno=EINVAL;
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
      /* reject chars not encoded the most efficient way */
      if (i>6 || (i>1 && v<utf8bounds[i-1])) goto ABEND;
/*      printf("got %u in %u bytes, buflen %u\n",v,i,*inbytesleft); */
      break;
    case UTF_16:
      if (*inbytesleft<2) goto starve;
      if (v==0xff && in[1]==0xfe) {
	from=UTF_16_LE; *inbytesleft-=2; in+=2; goto utf16le;
      } else if (v==0xfe && in[1]==0xff) {
	from=UTF_16_BE; *inbytesleft-=2; in+=2; goto utf16be;
      }
ABEND:
      errno=EILSEQ;
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
    if (v>=0xd800 && v<=0xd8ff) goto ABEND;	/* yuck!  in-band signalling! */
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
	errno=E2BIG;
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
      /* fall through */
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
#include <string.h>
#include <strings.h>
#include "dietfeatures.h"
#include <errno.h>
#include <stdlib.h>
#include "dieticonv.h"

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
    errno=EINVAL;
    return (iconv_t)(-1);
  }
  return (f|t<<16);
}
#include <stdlib.h>
#include "dieticonv.h"

int iconv_close(iconv_t cd) {
  (void)cd;	/* shut gcc up about unused cd */
  return 0;
}
#include <time.h>

int __isleap(int year) {
  /* every fourth year is a leap year except for century years that are
   * not divisible by 400. */
/*  return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)); */
  return (!(year%4) && ((year%100) || !(year%400)));
}
#include <wctype.h>
#include <string.h>

int iswctype(wint_t wc, wctype_t desc) {
  return desc(wc);
}
#include <time.h>

struct tm* localtime(const time_t* t) {
  static struct tm tmp;
  return localtime_r(t,&tmp);
}
#include "dietfeatures.h"
#include <time.h>
#include <sys/time.h>

#ifdef WANT_TZFILE_PARSER
extern void __maplocaltime(void);
extern time_t __tzfile_map(time_t t, int *isdst, int forward);
#else
extern long int timezone;
extern int daylight;
#endif

struct tm* localtime_r(const time_t* t, struct tm* r) {
  time_t tmp;
#ifdef WANT_TZFILE_PARSER
  __maplocaltime();
  tmp=__tzfile_map(*t,&r->tm_isdst,1);
#else
  struct timezone tz;
  gettimeofday(0, &tz);
  timezone=tz.tz_minuteswest*60L;
  tmp=*t+timezone;
#endif
  return gmtime_r(&tmp,r);
}
#include <errno.h>
#include "dietfeatures.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <syslog.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <signal.h>

#define _PATH_CONSOLE	"/dev/console"
#define BUF_SIZE 2048	/* messagebuffer size (>= 200) */

#define MAX_LOGTAG 1000

/* declare internal functions */
int __libc_open(const char*name,int flags, ...);
ssize_t __libc_write(int fd,void*buf,size_t len);
int __libc_fcntl(int fd,int op,...);
int __libc_close(int fd);

/* those have to be global *sigh* */
static volatile int	connected;	/* have done connect */
static volatile int	LogMask = 0xff; /* mask of priorities to be logged */
static char		LogTag[MAX_LOGTAG];	/* string to tag the entry with */
static int		LogFile = -1;   /* fd for log */
static int		LogType = SOCK_DGRAM; /* type of socket connection */
static int		LogFacility = LOG_USER; /* default facility code */
static int		LogStat;	/* status bits, set by openlog() */
extern char		*__progname;	/* Program name, from crt0. */
static struct sockaddr	SyslogAddr;	/* AF_UNIX address of local logger */

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
  LogType = SOCK_DGRAM;
}
void closelog(void) __attribute__((weak,alias("__libc_closelog")));

static void openlog_intern(int option, int facility)
{
  LogStat = option;
  if (facility && ((facility & ~LOG_FACMASK) == 0))
    LogFacility = facility;

  /* yep, there is a continue inside ;) */
  while(1) {
    if (LogFile == -1) {
      SyslogAddr.sa_family = AF_UNIX;
      strncpy(SyslogAddr.sa_data, _PATH_LOG, sizeof(SyslogAddr.sa_data));
      if (LogStat & LOG_NDELAY)
      {
	if ((LogFile = socket(AF_UNIX, LogType, 0)) == -1) return;
	__libc_fcntl(LogFile, F_SETFD, 1);
      }
    }
    if ((LogFile != -1) && !connected) {
      int old_errno=errno;
      if(connect(LogFile, &SyslogAddr, sizeof(SyslogAddr)) == -1) {
	int saved_errno=errno;
	__libc_close(LogFile);
	LogFile = -1;
	if((LogType == SOCK_DGRAM) && (saved_errno == EPROTOTYPE)) {
	  /* retry with SOCK_STREAM instead of SOCK_DGRAM */
	  LogType = SOCK_STREAM;
	  errno=old_errno;
	  continue;
	}
      }
      else connected = 1;
    }
    break;
  }
}

/* has to be secured against multiple, simultanious call's in threaded environment */
void __libc_openlog(const char *ident, int option, int facility);
void __libc_openlog(const char *ident, int option, int facility)
{
  if (ident) {
    strncpy(LogTag,ident,MAX_LOGTAG);
    LogTag[MAX_LOGTAG-1]=0;
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
  char buffer[BUF_SIZE];
  char time_buf[20];
  int buflen, headerlen;
  time_t now;
  struct tm now_tm;
  pid_t pid;
  int fd;
  int sigpipe;
  struct sigaction action, oldaction;
  int saved_errno = errno;

  /* check for invalid priority/facility bits */
  if (priority & ~(LOG_PRIMASK|LOG_FACMASK)) {
    syslog(LOG_ERR|LOG_CONS|LOG_PERROR|LOG_PID, "syslog: unknown facility/priorityority: %x", priority);
    priority &= LOG_PRIMASK|LOG_FACMASK;
  }

  /* check priority against setlogmask */
  if ((LOG_MASK(LOG_PRI(priority)) && LogMask) == 0) return;

  /* Set default facility if none specified. */
  if ((priority & LOG_FACMASK) == 0) priority |= LogFacility;

  pid = getpid();
  time(&now);
  strftime(time_buf, 20, "%h %e %T", localtime_r (&now, &now_tm));

  if (LogStat & LOG_PID)
    headerlen = snprintf(buffer, 130, "<%d>%s %s[%ld]: ", priority, time_buf, LogTag, (long) pid);
  else
    headerlen = snprintf(buffer, 130, "<%d>%s %s: ", priority, time_buf, LogTag);

  if (!LogTag[0]) {
    if ((LogStat & LOG_PID) != LOG_PID)
      headerlen = snprintf(buffer, 130, "<%d>%s (unknown)[%ld]: ", priority, time_buf, (long) pid);
    strcat(buffer+headerlen, "syslog without openlog w/ ident, please check code!");
    buflen = 41;
  }
  else {
    errno=saved_errno;
    buflen = vsnprintf(buffer+headerlen, BUF_SIZE - headerlen, format, arg_ptr);
  }
  if (LogStat & LOG_PERROR) {
    __libc_write(1, buffer+headerlen, buflen);
    if (buffer[headerlen+buflen] != '\n') __libc_write(1,"\n", 1);
  }

  /* prepare for broken connection */
  memset(&action, 0, sizeof(action));
  action.sa_handler = SIG_IGN;
  sigemptyset(&action.sa_mask);

  sigpipe = sigaction (SIGPIPE, &action, &oldaction);

  if (!connected) openlog_intern(LogStat | LOG_NDELAY, 0);

  /* If we have a SOCK_STREAM connection, also send ASCII NUL as a
   * record terminator. */
  if (LogType == SOCK_STREAM) buflen++;

  if (!connected || (send(LogFile, buffer, buflen+headerlen, 0) != buflen+headerlen)) {
    if (LogType == SOCK_STREAM) buflen--;
    closelog_intern();
    /*
     * Output the message to the console; don't worry about blocking,
     * if console blocks everything will.  Make sure the error reported
     * is the one from the syslogd failure.
     */
    if ((LogStat & LOG_CONS) &&
       ((fd = __libc_open(_PATH_CONSOLE, O_WRONLY|O_NOCTTY, 0)) >= 0))
    {
      __libc_write(fd, buffer, buflen+headerlen);
      __libc_write(fd, "\r\n", 2);
      __libc_close(fd);
    }
  }

  if (sigpipe == 0)
    sigaction(SIGPIPE, &oldaction, (struct sigaction *) NULL);
}
void vsyslog(int priority, const char *format, va_list arg_ptr) __attribute__((weak,alias("__libc_vsyslog")));

void syslog(int priority, const char *format, ...)
{
  va_list arg_ptr;
  va_start(arg_ptr, format);
  vsyslog(priority, format, arg_ptr);
  va_end(arg_ptr);
}
#define _GNU_SOURCE
#include <sys/cdefs.h>
#undef __attribute_dontuse__
#define __attribute_dontuse__
#include <time.h>
#include "dietfeatures.h"

#ifdef WANT_TZFILE_PARSER
extern void __maplocaltime(void);
extern time_t __tzfile_map(time_t t, int *isdst, int forward);
#else
extern long int timezone;
extern int daylight;
#endif

time_t mktime(register struct tm* const t) {
  time_t x=timegm(t);
#ifdef WANT_TZFILE_PARSER
  int isdst;
  time_t y;
  __maplocaltime();
  x=__tzfile_map(x,&isdst,0);
#else
  struct timezone tz;
  gettimeofday(0, &tz);
  timezone=tz.tz_minuteswest*60L;
  x+=timezone;
#endif
  return x;
}

time_t timelocal(struct tm* const t) __attribute__((alias("mktime")));

#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <ctype.h>
#include "dietfeatures.h"
#include <netdb.h>
#include <arpa/inet.h>

static int netfd=-1;
static char* netmap;
static unsigned int netlen;

static char* aliases[10];

static char *cur;

/* loopback	127.0.0.0	lo	# comment */
struct netent *getnetent(void) {
  static struct netent ne;
  char *last;
  int aliasidx;
  if (netfd<0) {
    netfd=open(_PATH_NETWORKS,O_RDONLY);
    if (netfd<0) return 0;
    fcntl (netfd, F_SETFD, FD_CLOEXEC);
    netlen=lseek(netfd,0,SEEK_END);
    netmap=mmap(0,netlen,PROT_READ|PROT_WRITE,MAP_PRIVATE,netfd,0);
    if ((long)netmap==(-1)) goto error;
    cur=netmap;
  }
  last=netmap+netlen;
again:
  ne.n_name=0;
  ne.n_aliases=aliases; aliases[0]=0;
  ne.n_addrtype=AF_INET;
  ne.n_net=0;
  if (cur>=last) return 0;
  if (*cur=='#' || *cur=='\n') goto parseerror;
  /* first, the primary name */
  if (!isalpha(*cur)) goto parseerror;
  ne.n_name=cur;
  ne.n_aliases=aliases;
  while (cur<last && isalnum(*cur)) cur++;
  if (cur>=last) return 0;
  if (*cur=='\n') goto parseerror;
  *cur=0; cur++;
  /* second, the ip */
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
  /* now the aliases */
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
  errno=ENOMEM;
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
#if 0
    write(1,"found ",6);
    write(1,s->s_name,strlen(s->s_name));
    write(1,"/",1);
    write(1,s->s_proto,strlen(s->s_proto));
    write(1,"\n",1);
    if (!strcmp(s->s_name,"ssh")) {
      write(2,"ssh!\n",5);
    }
#endif
    if (!strcmp(name,s->n_name))
      return s;
    tmp=s->n_aliases;
    while (*tmp)
      if (!strcmp(name,*tmp++)) return s;
  }
  return 0;
}

#include <unistd.h>
#include <pty.h>
#include <fcntl.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

int openpty(int *amaster, int *aslave, char *name, struct termios
	    *termp, struct winsize *winp) {
  int fd;
  char buf[20];
#if 0
  This is what glibc does:
  open("/dev/ptmx", O_RDWR)               = 4
  statfs("/dev/pts", {f_type=0x1cd1, f_bsize=1024, f_blocks=0, f_bfree=0, f_files=0, f_ffree=0, f_namelen=255}) = 0
  ioctl(4, TCGETS, {B38400 opost isig icanon echo ...}) = 0
  ioctl(4, 0x80045430, [0])               = 0
  stat("/dev/pts/0", {st_mode=S_IFCHR|0620, st_rdev=makedev(136, 0), ...}) = 0
  statfs("/dev/pts/0", {f_type=0x1cd1, f_bsize=1024, f_blocks=0, f_bfree=0, f_files=0, f_ffree=0, f_namelen=255}) = 0
  ioctl(4, 0x40045431, [0])               = 0
  ioctl(4, TCGETS, {B38400 opost isig icanon echo ...}) = 0
  ioctl(4, 0x80045430, [0])               = 0
  stat("/dev/pts/0", {st_mode=S_IFCHR|0620, st_rdev=makedev(136, 0), ...}) = 0
  open("/dev/pts/0", O_RDWR|O_NOCTTY)     = 5
#endif
  if ((fd=open("/dev/ptmx",O_RDWR))<0) return -1;
#if 0
  if (ioctl(fd,TCGETS,&ts)<0) goto kaputt;
#endif
  {
    int unlock=0;
    while (ioctl(fd,TIOCSPTLCK, &unlock)<0) if (errno!=EINTR) goto kaputt;
  }
  {
    int ptyno;
    while (ioctl(fd,TIOCGPTN,&ptyno)<0) if (errno!=EINTR) goto kaputt;
    strcpy(buf,"/dev/pts/");
    __ltostr(buf+9,10,ptyno,10,0);
  }
  *aslave=open(buf,O_RDWR|O_NOCTTY);
  if (*aslave<0) goto kaputt;
  *amaster=fd;
  if (name) strcpy(name,buf);
  if (termp)
    while (tcsetattr(*aslave,TCSAFLUSH,termp) && errno==EINTR);
  if (winp) while (ioctl(*aslave, TIOCSWINSZ, winp) && errno==EINTR);
  return 0;
kaputt:
  close(fd);
  return -1;
}
#include <sys/types.h>
#include <sys/wait.h>
#include "dietstdio.h"

int pclose(FILE *f) {
  int status;
  pid_t pid=f->popen_kludge;
  fclose(f);
  if (waitpid(pid,&status,0)>=0)
    return status;
  return -1;
}
#include "dietstdio.h"
#include <unistd.h>
#include <fcntl.h>
#include "binshstr.h"

extern char **environ;

FILE *popen(const char *command, const char *type) {
  int pfd[2];
  int fd0;
  FILE* f;
  pid_t pid;

  if (pipe(pfd)<0) return 0;
  fd0=(*type=='r');
  if ((!(f=fdopen(pfd[!fd0],type))) ||
      ((pid=fork())<0)) {
    close(pfd[0]);	/* malloc failed */
    close(pfd[1]);
    return 0;
  }
  if (!pid) {	/* child */
    const char *argv[]={__sh,"-c",0,0};
    close(pfd[!fd0]); close(fd0);
    dup2(pfd[fd0],fd0); close(pfd[fd0]);
    argv[2]=command;
    execve(__binsh,(char*const*)argv,environ);
    _exit(127);
  }
  close(pfd[fd0]);
  fcntl (pfd[!fd0], F_SETFD, FD_CLOEXEC);
  f->popen_kludge=pid;
  return f;
}
#include <sys/syslog.h>

#ifndef INTERNAL_NOPRI
#define INTERNAL_NOPRI 0x10
#endif

CODE prioritynames[] =
  {
    { "alert", LOG_ALERT },
    { "crit", LOG_CRIT },
    { "debug", LOG_DEBUG },
    { "emerg", LOG_EMERG },
    { "err", LOG_ERR },
    { "error", LOG_ERR },		/* DEPRECATED */
    { "info", LOG_INFO },
    { "none", INTERNAL_NOPRI },		/* INTERNAL */
    { "notice", LOG_NOTICE },
    { "panic", LOG_EMERG },		/* DEPRECATED */
    { "warn", LOG_WARNING },		/* DEPRECATED */
    { "warning", LOG_WARNING },
    { 0, -1 }
  };
#include <netdb.h>

struct protoent __protoent_pw;
char __protoent_buf[1000];

#define _XOPEN_SOURCE
#include <unistd.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <string.h>

# define MAX_FDS 4

char *ptsname(int fd) {
  static char buffer[9+MAX_FDS]; /* Ahh..great */
  int pty;

  strcpy(buffer,"/dev/pts/");
  if ((ioctl(fd, TIOCGPTN, &pty)) == -1) return 0;
  __ltostr(buffer+9, MAX_FDS, pty, 10, 0);
  return buffer;
}
/* man, what a crook! */

#include <pwd.h>
#include <stdio.h>
#include <sys/types.h>
#include <errno.h>
#include "dietwarning.h"

int putpwent(const struct passwd *p, FILE *stream) {
  if (p && stream) {
    fprintf(stream,"%s:%s:%d:%d:%s:%s:%s\n", p->pw_name, p->pw_passwd,
	    p->pw_uid, p->pw_gid, p->pw_gecos, p->pw_dir, p->pw_shell);
    return 0;
  }
  (*__errno_location())=EINVAL;
  return -1;
}

link_warning("putpwent","putpwent is garbage, don't use!")
#include <netdb.h>

struct servent __servent_pw;
char __servent_buf[1000];

#include <string.h>
#include <stdlib.h>

#include <dietwarning.h>
link_warning("setenv","setenv calls malloc.  Avoid it in small programs.");

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
#include <stdio.h>
#include <mntent.h>

FILE *setmntent(const char *filename, const char *type) {
  return fopen(filename,type);
}

#define _GNU_SOURCE
/* *puke* */
#include <string.h>
#include <stdlib.h>
#include "dietfeatures.h"

char *strndup(const char *s,size_t n) {
  /* This relies on the fact that our malloc(0) returns NULL.
   * Otherwise this would be an exploitable integer overflow! */
#ifdef WANT_MALLOC_ZERO
  char *tmp=!(n+1)?0:(char *)malloc(n+1);
#else
  char *tmp=(char *)malloc(n+1);
#endif
  if (!tmp) return 0;
  strncpy(tmp,s,n);
  tmp[n]=0;
  return tmp;
}
#include <sys/types.h>
#include <time.h>
#include "dietfeatures.h"

static const char   sweekdays [7] [4] = {
    "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
};
static const char   weekdays [7] [10] = {
    "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
};
static const char   smonths [12] [4] = {
    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};
static const char*  months [12] = {
    "January", "February", "March", "April", smonths[5-1], "June",
    "July", "August", "September", "October", "November", "December"
};
static const char   ampm [4] [3] = {
    "am", "pm",
    "AM", "PM"
};

static void i2a ( char* dest,unsigned long x )
{
    int  div = 10;
    *dest++ = x/div + '0';
    *dest++ = x%div + '0';
    *dest++ = '\0';
}

size_t  strftime ( char* dst, size_t max, const char* format, const struct tm* tm )
{
    char*         p = dst;
    const char*   src;
    unsigned long no;
    char          buf [5];

    if (!max) return 0;
    for ( ; *format != '\0'; format++ ) {
	if (*format == '%') {
	    if (*++format == '%') {
	        *p++ = '%';
	    }
	    else
again:
	    switch (*format) {
//          case '%': *p++ = '%';  				break;			// reduce size of jump table
	    case 'n': *p++ = '\n'; 				break;
	    case 't': *p++ = '\t'; 				break;
	    case 'O': case 'E': ++format; goto again;
	    case 'c': src = "%b %a %d %k:%M:%S %Z %Y";        	goto _strf;
	    case 'r': src = "%I:%M:%S %p";                    	goto _strf;
	    case 'R': src = "%H:%M";      			goto _strf;
	    case 'x': src = "%b %a %d";   			goto _strf;
	    case 'X': src = "%k:%M:%S";   			goto _strf;
	    case 'D': src = "%m/%d/%y";   			goto _strf;
	    case 'F': src = "%Y-%m-%d";				goto _strf;
	    case 'T': src = "%H:%M:%S";
	       _strf: p  += strftime (p, (size_t)(dst+max-p), src, tm); 	 break;
	    case 'a': src = sweekdays [tm->tm_wday]; 		goto _str;
	    case 'A': src = weekdays  [tm->tm_wday]; 		goto _str;
	    case 'h':
	    case 'b': src = smonths   [tm->tm_mon];  		goto _str;
	    case 'B': src = months    [tm->tm_mon];  		goto _str;
	    case 'p': src = ampm [tm->tm_hour > 12 ? 3 : 2]; goto _str;
	    case 'P': src = ampm [tm->tm_hour > 12 ? 1 : 0]; goto _str;
	    case 'C': no  = tm->tm_year/100 + 19; 		goto _no;
	    case 'd': no  = tm->tm_mday;          		goto _no;
	    case 'e': no  = tm->tm_mday;          		goto _nos;
	    case 'H': no  = tm->tm_hour;          		goto _no;
	    case 'I': no  = tm->tm_hour % 12;     		goto _no;
	    case 'j': no  = tm->tm_yday;          		goto _no;
	    case 'k': no  = tm->tm_hour;          		goto _nos;
	    case 'l': no  = tm->tm_hour % 12;     		goto _nos;
	    case 'm': no  = tm->tm_mon + 1;         		goto _no;
	    case 'M': no  = tm->tm_min;           		goto _no;
	    case 'S': no  = tm->tm_sec;           		goto _no;
	    case 'u': no  = tm->tm_wday ? tm->tm_wday : 7; 	goto _no;
	    case 'w': no  = tm->tm_wday;              		goto _no;
	    case 'U': no  = (tm->tm_yday - tm->tm_wday + 7) / 7; goto _no;
	    case 'W': no  = (tm->tm_yday - (tm->tm_wday - 1 + 7) % 7 + 7) / 7; goto _no;
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
#ifdef WANT_TZFILE_PARSER
		      tzset(); src = tzname[0];
#else
		      src = "[unknown timezone]";
#endif
		      goto _str;
	    case 'Y': i2a ( buf+0, (unsigned int)(tm->tm_year / 100 + 19) );
		      i2a ( buf+2, (unsigned int)(tm->tm_year % 100) );
		      src = buf;
		      goto _str;
	    case 'y': no  = tm->tm_year % 100; 			 goto _no;
		 _no: i2a ( buf, no );				 /* append number 'no' */
		      src = buf;
		      goto _str;
		_nos: i2a ( buf, no );				 /* the same, but '0'->' ' */
		      if (buf[0] == '0')
			  buf[0] = ' ';
		      src = buf;
		_str: while (*src  &&  p < dst+max)		 /* append string */
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


#include <time.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>

extern const short  __spm [];

static const char*  months [12] = { 
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
  register time_t  day;
  while (*format) {
    switch (*format) {
    case ' ': case '\t':
      /* match zero or more white space in input string */
      while (isblank(*s)) ++s;
      ++format;
      break;
    case '%':
      ++format;
      switch (*format) {
      case '%': if (*s=='%') ++s; else return 0; break;
      case 'a': case 'A': /* weekday; we just skip */
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
	getint(&s,3);	/* not used */
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
	/* time zone.  Not sure what I'm expected to do here. We'll just
	 * skip to the next whitespace */
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
 
  day  = (tm->tm_year - 70) * 365 + (tm->tm_year - 69) / 4;
  day += tm->tm_yday = __spm [tm->tm_mon] + tm->tm_mday-1 + (__isleap (tm->tm_year+1900) & (tm->tm_mon > 1));
  tm->tm_wday = (day + 4) % 7;

  return (char*)s;
}
#define _GNU_SOURCE
#include <string.h>
#include <signal.h>

char* strsignal(int sig) {
  if ((unsigned int)sig<=SIGRTMAX)
    return (char*)sys_siglist[sig];
  else
    return (char*)"(unknown signal)";
}
#include <signal.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
#include "dietwarning.h"
#include "dietfeatures.h"
#include "binshstr.h"

extern char **environ;

int __libc_system (const char *line);

int __libc_system (const char *line)
{
  struct sigaction sa, intr, quit;
  sigset_t block,omask;
  int save,pid,ret=-1;

  if (line == 0) return __libc_system("exit 0") == 0;

  sa.sa_handler = SIG_IGN;
  sa.sa_flags = 0;
  sigemptyset (&sa.sa_mask);

  if (sigaction(SIGINT,  &sa, &intr)<0) return -1;
  if (sigaction(SIGQUIT, &sa, &quit)<0) {
    save = errno;
undo:
    sigaction (SIGINT, &intr, (struct sigaction*)0);
    errno=save;
    return -1;
  }
  sigemptyset(&block);
  sigaddset(&block,SIGCHLD);
  if (sigprocmask(SIG_BLOCK,&block,&omask)<0) {
    save=errno;
    sigaction (SIGQUIT, &quit, (struct sigaction*)0);
    goto undo;
  }

  pid=fork();
  if (pid>0)
  { /* parent */
    int n;
    do
      n=waitpid(pid, &ret, 0);
    while ((n==-1) && (errno==EINTR));
    if (n!=pid) ret=-1;
  }
  else if (!pid)
  { /* child */
    const char *nargs[4];
    nargs[0] = __sh;
    nargs[1] = "-c";
    nargs[2] = line;
    nargs[3] = 0;

    sigaction(SIGINT,  &intr, (struct sigaction*)0);
    sigaction(SIGQUIT, &quit, (struct sigaction*)0);
    sigprocmask(SIG_SETMASK,&omask,0);

    execve(__binsh,(char *const *)nargs, environ);
    _exit(127);
  }
  save = errno;
  sigaction (SIGINT,  &intr, (struct sigaction *)0);
  sigaction (SIGQUIT, &quit, (struct sigaction *)0);
  sigprocmask(SIG_SETMASK,&omask,0);
  errno=save;
  return ret;
}

int system (const char *line) __attribute__((weak,alias("__libc_system")));

link_warning("system","warning: system() is a security risk.  Use fork and execvp instead!")
#include <time.h>

/* days per month -- nonleap! */
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

#define _GNU_SOURCE
#include <time.h>

/* this is cut and paste from mktime. */

extern const short  __spm [];

time_t timegm(struct tm *const t) {
  register time_t  day;
  register time_t  i;
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

  /* Days since 1970 is 365 * number of years + number of leap years since 1970 */
  day  = years * 365 + (years + 1) / 4;

  /* After 2100 we have to substract 3 leap years for every 400 years
     This is not intuitive. Most mktime implementations do not support
     dates after 2059, anyway, so we might leave this out for it's
     bloat. */
  if ((years -= 131) >= 0) {
    years /= 100;
    day -= (years >> 2) * 3 + 1;
    if ((years &= 3) == 3) years--;
    day -= years;
  }

  day += t->tm_yday = __spm [t->tm_mon] + t->tm_mday-1 + ( __isleap (t->tm_year+1900)  &  (t->tm_mon > 1) );

  /* day is now the number of days since 'Jan 1 1970' */
  i = 7;
  t->tm_wday = (day + 4) % i;                        /* Sunday=0, Monday=1, ..., Saturday=6 */

  i = 24;
  day *= i;
  i = 60;
  return ((day + t->tm_hour) * i + t->tm_min) * i + t->tm_sec;
}


long int timezone;
int daylight;
#include "dietfeatures.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <netinet/in.h>
#include <time.h>

#include <stdio.h>

/* This code appears to be subtly wrong depending on the date.
 * However, the documentation I found about the tzfile layout are not
 * sufficient to debug this. */

char* tzname[2]={"GMT","GMT"};

#ifdef WANT_TZFILE_PARSER
static unsigned char *tzfile;
static int tzlen=-1;

void __maplocaltime(void);
void __maplocaltime(void) {
  int fd;
  unsigned int len;
  if (tzlen>=0) return;
  tzlen=0;
  if ((fd=open("/etc/localtime",O_RDONLY))<0) return;
  len=lseek(fd,0,SEEK_END);
  if ((tzfile=mmap(0,len,PROT_READ,MAP_PRIVATE,fd,0))==MAP_FAILED) {
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
  /* "TZif" plus 16 reserved bytes. */
  unsigned char *tmp;
  int i;
  int tzh_timecnt, tzh_typecnt;
  *isdst=0;
  if (!tzfile) return t;
  tzh_timecnt=ntohl(*(int*)(tzfile+32));
  tzh_typecnt=ntohl(*(int*)(tzfile+36));

#if 0
  int tzh_ttisgmtcnt=ntohl(*(int*)(tzfile+20));
  int tzh_ttisstdcnt=ntohl(*(int*)(tzfile+24));
  int tzh_leapcnt=ntohl(*(int*)(tzfile+28));
  int tzh_charcnt=ntohl(*(int*)(tzfile+40));
  tmp=tzfile+20+6*4;
  printf("ttisgmtcnt %d ttisstdcnt %d leapcnt %d timecnt %d typecnt %d charcnt %d\n",tzh_ttisgmtcnt,tzh_ttisstdcnt, tzh_leapcnt, tzh_timecnt, tzh_typecnt, tzh_charcnt);
  printf("transition times: ");
  for (i=0; i<tzh_timecnt; ++i) {
    printf("%s%lu",i?", ":"",ntohl(*(int*)tmp)); tmp+=4;
  }
  printf("\n");
  printf("indices: ");
  for (i=0; i<tzh_timecnt; ++i) {
    printf("%s%d",i?", ":"",*tmp); ++tmp;
  }
  printf("\n");
  printf("transition times: ");
  for (i=0; i<tzh_typecnt; ++i) {
    printf("%s(%lu,%d,%d)",i?", ":"",ntohl(*(int*)tmp),tmp[4],tmp[5]); tmp+=6;
  }
  printf("\n");
  for (i=0; i<tzh_charcnt; ++i) {
    printf("%s\"%s\"",i?", ":"",tmp);
    tmp+=strlen(tmp);
  }
  printf("\n");
#endif

  tmp=tzfile+20+6*4;
  daylight=(tzh_timecnt>0);
  if (forward) {
    for (i=0; i<tzh_timecnt; ++i) {
      if ((time_t)__myntohl(tmp+i*4) >= t) {
	unsigned char* tz=tmp;
  /*      printf("match at %d\n",i); */
	tmp+=tzh_timecnt*4;
	i=tmp[i-1];
  /*      printf("using index %d\n",i); */
	tmp+=tzh_timecnt;
	tz+=tzh_timecnt*5+tzh_typecnt*6;
	tmp+=i*6;
  /*      printf("(%lu,%d,%d)\n",ntohl(*(int*)tmp),tmp[4],tmp[5]); */
	*isdst=tmp[4];
	tzname[0]=(char*)(tz+tmp[5]);
	timezone=__myntohl(tmp);
	return t+timezone;
      }
    }
  } else {	/* reverse map, for mktime */
    time_t nexttz=0,lastval=0;
//    printf("tzh_timecnt: %d\n",tzh_timecnt);
    for (i=1; i<tzh_timecnt-1; ++i) {
      unsigned char* x, j;
      long k=0;
//      printf("ab %ld: ",__myntohl(tmp+i*4));
      x=tmp+tzh_timecnt*4;
      j=x[i-1];
      nexttz=__myntohl(x+tzh_timecnt+j*6);
//      printf("%ld - %ld (want %ld)\n",lastval,__myntohl(tmp+i*4)-nexttz,t);
      if (lastval <= t && (k=(__myntohl(tmp+i*4)-nexttz)) > t) {
//	printf("FOUND!1!!  Offset %d\n",nexttz);
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

#else
void tzset(void) { }
#endif
#define _XOPEN_SOURCE
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdlib.h>

int unlockpt (int fd) {
  int foo=0;
  /* hehe, that one is easy */
  return (ioctl (fd, TIOCSPTLCK, &foo));
}
#include <stdlib.h>

int unsetenv(const char *name) {
  return putenv(name);
}

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <utmp.h>

static const char *utmp_file_name = _PATH_UTMP;
static int fd = -1;
static off_t utmp_current = 0;

static int lock_record(int type) {
  struct flock fl;
  fl.l_whence	= SEEK_CUR;
  fl.l_start	= 0;
  fl.l_len	= sizeof(struct utmp);
  fl.l_pid	= 0;
  fl.l_type	= type;
  return fcntl(fd, F_SETLKW, &fl);
}

static int unlock_record() {
  struct flock fl;
  fl.l_whence	= SEEK_CUR;
  fl.l_start	= -sizeof(struct utmp);
  fl.l_len	= sizeof(struct utmp);
  fl.l_pid	= 0;
  fl.l_type	= F_UNLCK;
  return fcntl(fd, F_SETLK, &fl);
}

void utmpname(const char *file) {
  if (file)
    utmp_file_name = file;
  else
    utmp_file_name = _PATH_UTMP;
}

void setutent() {
  if (fd<0) fd = open(utmp_file_name,O_RDWR);
  if (fd<0) fd = open(utmp_file_name,O_RDONLY);
  fcntl (fd, F_SETFD, FD_CLOEXEC);
  utmp_current = lseek(fd,0,SEEK_SET);
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
  utmp_current = lseek (fd, 0, SEEK_CUR);
  if (lock_record(F_RDLCK)) return 0;
  ret=read(fd, &getutent_tmp, sizeof(struct utmp));
  unlock_record();
  if (ret<1) return 0;
  return &getutent_tmp;
}

struct utmp *getutid(struct utmp *ut) {
  struct utmp *tmp;

  while ((tmp = getutent())) {
    if (ut->ut_type && (ut->ut_type <= OLD_TIME)) {
      if (ut->ut_type == tmp->ut_type) break;
    }
    if ((ut->ut_type >= INIT_PROCESS) && (ut->ut_type <= DEAD_PROCESS)) {
      if (!strncmp(ut->ut_id,tmp->ut_id,4)) break;
    }
  }
  return tmp;
}

struct utmp *getutline(struct utmp *ut) {
  struct utmp *tmp;

  while ((tmp = getutent())) {
    if ((tmp->ut_type == USER_PROCESS) || (tmp->ut_type == LOGIN_PROCESS)) {
      if (!strncmp(ut->ut_line,tmp->ut_line,UT_LINESIZE)) break;
    }
  }
  return tmp;
}

void pututline(struct utmp *ut) {
  struct utmp *tmp;

  /* Seek to the current record before searching. */
  lseek (fd, utmp_current, SEEK_SET);
  if ((tmp = getutid(ut))) {
    lseek(fd, - (off_t)sizeof(struct utmp), SEEK_CUR);
    if (lock_record(F_WRLCK)) return;
    write(fd, ut, sizeof(struct utmp));
    utmp_current += sizeof(struct utmp);
  }
  else {
    utmp_current = lseek(fd, 0, SEEK_END);
    if (lock_record(F_WRLCK)) return;
    write(fd, ut, sizeof(struct utmp));
  }
  unlock_record();
}

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <utmpx.h>
#include <signal.h>

static const char *utmp_file_name = _PATH_UTMPX;
static int fd = -1;
static off_t utmp_current = 0;

/* Forward declaration for utmp common functions */
void *__utmp_io(int fd, void *ut, ssize_t len, off_t *offset, int type);
sigset_t *__utmp_block_signals (sigset_t *oldset);

/* See libcompat for utmpxname() */
void __utmpxname(const char *file);   /* keep the compiler happy */
void __utmpxname(const char *file) {
  if (file)
    utmp_file_name = file;
  else
    utmp_file_name = _PATH_UTMPX;
}

void setutxent() {
  sigset_t oldset, *savedset;

  savedset = __utmp_block_signals(&oldset);
  if (fd<0) fd = open(utmp_file_name,O_RDWR);
  if (fd<0) fd = open(utmp_file_name,O_RDONLY);
  fcntl (fd, F_SETFD, FD_CLOEXEC);
  utmp_current = lseek(fd,0,SEEK_SET);
  if (savedset)
      sigprocmask (SIG_SETMASK, savedset, 0);
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
	      &utmp_current, F_RDLCK);

  if (savedset)
      sigprocmask (SIG_SETMASK, savedset, 0);

  return retval;
}

struct utmpx *getutxid(struct utmpx *ut) {
  struct utmpx *tmp;

  while ((tmp = getutxent())) {
    if (ut->ut_type && (ut->ut_type <= OLD_TIME)) {
      if (ut->ut_type == tmp->ut_type) break;
    }
    if ((ut->ut_type >= INIT_PROCESS) && (ut->ut_type <= DEAD_PROCESS)) {
      if (!strncmp(ut->ut_id,tmp->ut_id,4)) break;
    }
  }
  return tmp;
}

struct utmpx *getutxline(struct utmpx *ut) {
  struct utmpx *tmp;

  while ((tmp = getutxent())) {
    if ((tmp->ut_type == USER_PROCESS) || (tmp->ut_type == LOGIN_PROCESS)) {
      if (!strncmp(ut->ut_line,tmp->ut_line,__UT_LINESIZE)) break;
    }
  }
  return tmp;
}

struct utmpx *pututxline(struct utmpx *ut) {
  struct utmpx *tmp, ut_copy, *retval = 0, *result;
  int e;
  ssize_t bytes_written;
  sigset_t oldset, *savedset;

  /* It's kosher to call this function with a pointer to our own static
   * utmp structure, so work with a copy of "ut" */

  memcpy (&ut_copy, ut, sizeof (struct utmpx));

  savedset = __utmp_block_signals (&oldset);

  /* Seek to the current record before searching. */
  lseek (fd, utmp_current, SEEK_SET);
  if ((tmp = getutxid(&ut_copy))) {
    lseek(fd, - (off_t)sizeof(struct utmpx), SEEK_CUR);
    result = __utmp_io (fd, &ut_copy, sizeof(struct utmpx),
	    &utmp_current, F_WRLCK);
    e = errno;
  } else {
    utmp_current = lseek(fd, 0, SEEK_END);
    result = __utmp_io (fd, &ut_copy, sizeof(struct utmpx),
	    &utmp_current, F_WRLCK);
    e = errno;
  }
  if (savedset)
      sigprocmask (SIG_SETMASK, savedset, 0);

  if (result) {
      retval = ut;
  }

  memcpy (ut, &ut_copy, sizeof (struct utmpx));
  errno = e;
  return retval;
}

#define _GNU_SOURCE
#include <stdarg.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include "dietwarning.h"

int vasprintf(char **s, const char *format, va_list ap)
{
  int n;
  va_list arg_ptr;
  char tmp[8];
  va_copy(arg_ptr,ap);
  n=vsnprintf(tmp,0,format,arg_ptr);
  va_end(arg_ptr);
  if ((*s=malloc(n+1))) {
    n=vsnprintf(*s,n+1,format,ap);
    return n;
  }
  return -1;
}
#include <wctype.h>
#include <string.h>

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
#include <wchar.h>

int wmemcmp(const wchar_t *s1, const wchar_t *s2, size_t n) {
  size_t i;
  for (i=0; i<n; ++i) {
    wint_t x=s1[i]-s2[i];
    if (x) return x;
  }
  return 0;
}
#include <wchar.h>

wchar_t *wmemcpy(wchar_t *dest, const wchar_t *src, size_t n) {
  size_t i;
  for (i=0; i<n; ++i)
    dest[i]=src[i];
  return dest;
}
#include <wchar.h>

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
#include <wchar.h>

wchar_t *wmemset(wchar_t *wcs, wchar_t wc, size_t n) {
  size_t i;
  for (i=0; i<n; ++i) wcs[i]=wc;
  return wcs;
}
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <utmp.h>

void updwtmp(const char *wtmp_file, const struct utmp *ut) {
  int fd = open(wtmp_file, O_WRONLY|O_APPEND);
  if (fd<0) return;
  fcntl (fd, F_SETFD, FD_CLOEXEC);
  write(fd, ut, sizeof(struct utmp));
  close(fd);
}

void logwtmp(const char *line, const char *name, const char *host) {
  struct utmp ut;

  memset(&ut, 0, sizeof(struct utmp));

  ut.ut_pid = getpid ();
  ut.ut_type = name[0] ? USER_PROCESS : DEAD_PROCESS;

  memccpy (ut.ut_line, line, 0, sizeof ut.ut_line);
  memccpy (ut.ut_name, name, 0, sizeof ut.ut_name);
  memccpy (ut.ut_host, host, 0, sizeof ut.ut_host);

  if (sizeof(ut.ut_tv) == sizeof(struct timeval))
    gettimeofday((struct timeval *)&ut.ut_tv, NULL);
  else {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	ut.ut_tv.tv_sec = tv.tv_sec;
	ut.ut_tv.tv_usec = tv.tv_usec;
  }

  updwtmp (_PATH_WTMP, &ut);
}

#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include "parselib.h"

void __end_parse(struct state* s) {
  munmap((void*)(s->buffirst),s->buflen);
  s->buffirst=0;
}
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include "parselib.h"

void __fprepare_parse(int fd,struct state* s) {
  s->cur=0;
  if (s->buffirst) return;	/* already mapped */
  if (fd>=0) {
    s->buflen=lseek(fd,0,SEEK_END);
    s->buffirst=mmap(0,s->buflen,PROT_READ,MAP_PRIVATE,fd,0);
    if (s->buffirst==(const char*)-1)
      s->buffirst=0;
  }
}
#include <ctype.h>
#include <sys/types.h>
#include "parselib.h"

size_t __parse(struct state* s,int (*pred)(int ch)) {
  size_t n;
  for (n=s->cur; n<s->buflen && s->buffirst[n]!='\n' && pred(s->buffirst[n]); ++n) ;
  return n-s->cur;
}

#include <sys/types.h>
#include "parselib.h"

size_t __parse_1(struct state* s,char c) {
  size_t n;
  for (n=s->cur; n<s->buflen && s->buffirst[n]!='\n' && s->buffirst[n]!=c; ++n) ;
  return n-s->cur;
}

#include <sys/types.h>
#include "parselib.h"

static int __isnonblank(int ch) {
  return (ch!=' ' && ch!='\t' && ch!='#');
}

size_t __parse_nws(struct state* s) {
  return __parse(s,__isnonblank);
}
#include <sys/types.h>
#include <ctype.h>
#include "parselib.h"

static int __isblank(int ch) {
  return (ch==' ' || ch=='\t');
}

size_t __parse_ws(struct state* s) {
  return __parse(s,__isblank);
}
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include "parselib.h"

void __prepare_parse(const char* filename,struct state* s) {
  int fd;
  s->cur=0;
  if (s->buffirst) return;	/* already mapped */
  fd=open(filename,O_RDONLY);
  if (fd>=0) {
    s->buflen=lseek(fd,0,SEEK_END);
    s->buffirst=mmap(0,s->buflen,PROT_READ,MAP_PRIVATE,fd,0);
    if (s->buffirst==(const char*)-1)
      s->buffirst=0;
    close(fd);
  } else {
    s->buflen=0;
    s->buffirst=0;
  }
}
#include <dirent.h>
#include <string.h>

int alphasort(const struct dirent **a, const struct dirent **b) {
  return strcmp((*a)->d_name,(*b)->d_name);
}
#include <dirent.h>
#include <string.h>

int alphasort64(const struct dirent64 **a, const struct dirent64 **b) {
  return strcmp((*a)->d_name,(*b)->d_name);
}
#include <sys/types.h>
#include <string.h>
#include <strings.h>
#include "dietwarning.h"

#undef bcopy
void bcopy(const void *src, void *dest, size_t n) {
  memmove(dest,src,n);
}

link_warning("bcopy","warning: you used bcopy without including dietlibc <string.h> w/ _BSD_SOURCE!")
#include <libintl.h>
#include <string.h>
#include <stdlib.h>

static char* dir;

char* bindtextdomain(const char* domainname,const char* dirname) {
  (void)domainname;
  if (dir) free(dir);
  if (!(dir=strdup(dirname))) return 0;
  return dir;
}
#include <sys/types.h>
#include <string.h>
#include <strings.h>
#include "dietwarning.h"

#undef bzero
void bzero(void *s, size_t n) {
  memset(s,0,n);
}

link_warning("bzero","warning: you used bzero without including dietlibc's <string.h> w/ _BSD_SOURCE!")
#include <sys/times.h>
#include <sys/param.h>
#include <time.h>
#include <unistd.h>

clock_t clock(void) {
  struct tms buf;
  times(&buf);

/*  printf("utime %d, stime %d, CLOCKS_PER_SEC %d, HZ %d\n",buf.tms_utime,buf.tms_stime,CLOCKS_PER_SEC,HZ); */

#if    CLOCKS_PER_SEC == HZ
  return (unsigned long) buf.tms_utime + buf.tms_stime;
#elif  CLOCKS_PER_SEC % HZ == 0
  return ((unsigned long) buf.tms_utime + buf.tms_stime) * (CLOCKS_PER_SEC / HZ);
#elif  HZ % CLOCKS_PER_SEC == 0
  return ((unsigned long) buf.tms_utime + buf.tms_stime) / (HZ / CLOCKS_PER_SEC);
#else
  return ((unsigned long long) buf.tms_utime + buf.tms_stime) * CLOCKS_PER_SEC / HZ;
#endif
}
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#include <stdlib.h>
#include <string.h>

#define DEF_PATH "/bin:/usr/bin"

size_t confstr(int name,char*buf,size_t len) {
  switch (name) {
  case _CS_PATH:
    if (buf) strncpy(buf,DEF_PATH,len);
    return sizeof(DEF_PATH);
    break;
  }
  errno=EINVAL;
  return 0;
}
#include <libintl.h>

char* dcgettext(const char *domainname, const char *msgid, int category) {
  (void)domainname;
  (void)category;
  return (char*)msgid;
}
#include <libintl.h>

#undef dgettext
char* dgettext(const char* domainname, const char* x) { (void)domainname; return (char*)x; }
/* support function when linking against libgcc_eh.a
 *
 * see gcc sources _Unwind_Find_FDE() in unwind-dw2-fde-glibc.c
 *
 * Copyright (C) 2005 Markus F.X.J. Oberhumer
 * License: GNU GPL
 */

#include <limits.h>
#include <stddef.h>
#include <string.h>
#include <elf.h>

#if __WORDSIZE == 64
#  define ElfW(type) Elf64_##type
#else
#  define ElfW(type) Elf32_##type
#endif

struct dl_phdr_info
{
    ElfW(Addr) dlpi_addr;
    const char *dlpi_name;
    const ElfW(Phdr) *dlpi_phdr;
    ElfW(Half) dlpi_phnum;
};


/* dl_support.c defines these and initializes them early on.  */
extern ElfW(Phdr) *_dl_phdr;
extern size_t _dl_phnum;


int dl_iterate_phdr(int (*callback) (struct dl_phdr_info *info, size_t size, void *data),
                    void *data);
int dl_iterate_phdr(int (*callback) (struct dl_phdr_info *info, size_t size, void *data),
                    void *data)
{
    int ret;
    struct dl_phdr_info info;

    if (_dl_phnum != 0)
    {
        /* This entry describes this statically-linked program itself.  */
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


/* support function when linking against libgcc_eh.a
 *
 * see gcc sources _Unwind_Find_FDE() in unwind-dw2-fde-glibc.c
 *
 * Copyright (C) 2005 Markus F.X.J. Oberhumer
 * License: GNU GPL
 */

#include "dietfeatures.h"
#include <limits.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <elf.h>

#if __WORDSIZE == 64
#  define ElfW(type) Elf64_##type
#else
#  define ElfW(type) Elf32_##type
#endif


extern ElfW(Phdr) *_dl_phdr;
extern size_t _dl_phnum;

ElfW(Phdr) *_dl_phdr = NULL;
size_t _dl_phnum = 0;


void _dl_aux_init(ElfW(auxv_t) *av);
void _dl_aux_init(ElfW(auxv_t) *av)
{
    for ( ; av->a_type != AT_NULL; ++av)
    {
	switch (av->a_type)
	{
	case AT_PHDR:
            _dl_phdr = av->a_un.a_ptr;
            break;
	case AT_PHNUM:
            _dl_phnum = av->a_un.a_val;
            break;
	}
    }
}


void _dl_aux_init_from_envp(char **envp);
void _dl_aux_init_from_envp(char **envp)
{
    if (envp == NULL)
        return;
    while (*envp)
	++envp;
    /* now envp points to the tailing NULL-pointer of the environment */
    _dl_aux_init((ElfW(auxv_t) *) (envp + 1));
}


#include <netinet/in.h>
#include <arpa/nameser.h>
#include <resolv.h>

extern int __dns_decodename(const unsigned char *packet,unsigned int ofs,unsigned char *dest,
			    unsigned int maxlen,const unsigned char* behindpacket);

int dn_expand(const unsigned char *msg, const unsigned char *eomorig, const unsigned char *comp_dn, char *exp_dn, int length) {
  return __dns_decodename(msg,comp_dn-msg,(unsigned char*)exp_dn,length,eomorig)-(comp_dn-msg);
}

#include <resolv.h>

int dn_skipname(const unsigned char* cur,const unsigned char* eom) {
  const unsigned char* orig=cur;
  while (cur<eom) {
    if ((*cur&0xc)==0xc) { /* compression */
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
#include <libintl.h>

#undef dngettext
char* dngettext (const char* domainname,const char* msgid, const char* msgid_plural, unsigned long int n) {
  (void)domainname;
  return (char*)(n==1?msgid:msgid_plural);
}
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <resolv.h>
#include <net/if.h>
#include "dietfeatures.h"

int __dns_fd=-1;
#ifdef WANT_IPV6_DNS
int __dns_fd6=-1;
#endif

/* the ad-hoc internal API from hell ;-) */
void __dns_make_fd(void);
void __dns_make_fd6(void);
void __dns_readstartfiles(void);
int __dns_decodename(const unsigned char *packet,unsigned int offset,unsigned char *dest,
		     unsigned int maxlen,const unsigned char* behindpacket);

void __dns_make_fd(void) {
  int tmp;
  struct sockaddr_in si;
  if (__dns_fd>=0) return;
  tmp=socket(PF_INET,SOCK_DGRAM,IPPROTO_UDP);
  if (tmp<0) return;
  fcntl(tmp,F_SETFD,FD_CLOEXEC);
  si.sin_family=AF_INET;
  si.sin_port=0;
  si.sin_addr.s_addr=INADDR_ANY;
  if (bind(tmp,(struct sockaddr*)&si,sizeof(si))) return;
  __dns_fd=tmp;
}

#ifdef WANT_IPV6_DNS
void __dns_make_fd6(void) {
  int tmp;
  struct sockaddr_in6 si;
  if (__dns_fd6>=0) return;
  tmp=socket(PF_INET6,SOCK_DGRAM,IPPROTO_UDP);
  if (tmp<0) return;
  fcntl(tmp,F_SETFD,FD_CLOEXEC);
  memset(&si,0,sizeof(si));
  si.sin6_family=AF_INET6;
  if (bind(tmp,(struct sockaddr*)&si,sizeof(si))) return;
  __dns_fd6=tmp;
}
#endif

static int parsesockaddr(const char* c,void* x) {
  struct sockaddr_in_pad to;
  memset(&to,0,sizeof(to));
  if (inet_aton(c,&to.sin_addr)) {
    to.sin_port=htons(53);
    to.sin_family=AF_INET;
    memmove(x,&to,sizeof(struct sockaddr_in_pad));
    return 1;
#ifdef WANT_IPV6_DNS
  } else {
    struct sockaddr_in6 to6;
    char* d=strchr(c,'%');
    to6.sin6_flowinfo=to6.sin6_scope_id=0;
    if (d)
      to6.sin6_scope_id=if_nametoindex(d+1);
    if (inet_pton(AF_INET6,c,&to6.sin6_addr)) {
      to6.sin6_port=htons(53);
      to6.sin6_family=AF_INET6;
      memmove(x,&to6,sizeof(struct sockaddr_in_pad));
      return 1;
    }
#endif
  }
  return 0;
}

#ifdef WANT_FULL_RESOLV_CONF
unsigned int __dns_search;
char *__dns_domains[8];
#endif

void __dns_readstartfiles(void) {
  int fd;
  char __buf[4096];
  char *buf=__buf;
  int len;
  if (_res.nscount>0) return;
  {
    char *cacheip=getenv("DNSCACHEIP");
#ifdef WANT_FULL_RESOLV_CONF
    __dns_search=0;
#endif
    if (cacheip)
      if (parsesockaddr(cacheip,_res.nsaddr_list))
	++_res.nscount;
  }
  _res.options=RES_RECURSE;
  if ((fd=open("/etc/resolv.conf",O_RDONLY))<0) return;
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
	      if (_res.nscount<MAXNS) ++_res.nscount;
	    *buf=save;
	  }
	}
      }
#ifdef WANT_FULL_RESOLV_CONF
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
#endif
      while (buf<last && *buf!='\n') ++buf;
      while (buf<last && *buf=='\n') ++buf;
    }
  }
}

/* return length of decoded data or -1 */
int __dns_decodename(const unsigned char *packet,unsigned int offset,unsigned char *dest,
		     unsigned int maxlen,const unsigned char* behindpacket) {
  const unsigned char *tmp;
  const unsigned char *max=dest+maxlen;
  const unsigned char *after=packet+offset;
  int ok=0;
  for (tmp=after; maxlen>0&&*tmp; ) {
    if (tmp>=behindpacket) return -1;
    if ((*tmp>>6)==3) {		/* goofy DNS decompression */
      unsigned int ofs=((unsigned int)(*tmp&0x3f)<<8)|*(tmp+1);
      if (ofs>=(unsigned int)offset) return -1;	/* RFC1035: "pointer to a _prior_ occurrance" */
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
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/nameser.h>
#include <resolv.h>
#include "dietfeatures.h"
#include "dietdns.h"

extern void __dns_readstartfiles(void);

extern int __dns_decodename(unsigned char *packet,unsigned int offset,unsigned char *dest,
			    unsigned int maxlen,unsigned char* behindpacket);

/* Oh boy, this interface sucks so badly, there are no words for it.
 * Not one, not two, but _three_ error signalling methods!  (*h_errnop
 * nonzero?  return value nonzero?  *RESULT zero?)  The glibc goons
 * really outdid themselves with this one. */
#ifdef WANT_FULL_RESOLV_CONF
static int __dns_gethostbyx_r_inner(const char* name, struct hostent* result,
			char *buf, size_t buflen,
			struct hostent **RESULT, int *h_errnop, int lookfor);

static int __dns_gethostbyx_r_inner(const char* name, struct hostent* result,
			char *buf, size_t buflen,
			struct hostent **RESULT, int *h_errnop, int lookfor) {
#else
int __dns_gethostbyx_r(const char* name, struct hostent* result,
			char *buf, size_t buflen,
			struct hostent **RESULT, int *h_errnop, int lookfor) {
#endif
  int names,ips;
  char *cur;
  char *max;
  char inpkg[1500];
  char* tmp;
  int size;

  if (lookfor==1) {
    result->h_addrtype=AF_INET;
    result->h_length=4;
  } else {
    result->h_addrtype=AF_INET6;
    result->h_length=16;
  }
  result->h_aliases=(char**)(buf+9*sizeof(char*));
  result->h_addr_list=(char**)buf;
  result->h_aliases[0]=0;

  cur=buf+18*sizeof(char*);
  max=buf+buflen;
  names=ips=0;

  if (buflen<128) goto invalidpacket;

  if ((size=res_query(name,C_IN,lookfor,(unsigned char*)inpkg,512))<0) {
invalidpacket:
    *h_errnop=HOST_NOT_FOUND;
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
	if (tmp[0]!=0 || tmp[1]!=lookfor ||	/* TYPE != A */
	    tmp[2]!=0 || tmp[3]!=1) {		/* CLASS != IN */
	  if (tmp[1]==5) {	/* CNAME */
	    tmp+=10;
	    decofs=__dns_decodename((unsigned char*)inpkg,(size_t)(tmp-(char*)inpkg),Name,256,(unsigned char*)inpkg+size);
	    if (decofs<0) break;
	    tmp=inpkg+decofs;
	  } else
	    break;
	  continue;
	}
	tmp+=10;	/* skip type, class, TTL and length */
	{
	  int slen;
	  if (lookfor==1 || lookfor==28) /* A or AAAA*/ {
	    slen=strlen((char*)Name);
	    if (cur+slen+8+(lookfor==28?12:0)>=max) { *h_errnop=NO_RECOVERY; return -1; }
	  } else {
	    if (lookfor==12) /* PTR */ {
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
	  if (lookfor==1) /* A */ {
	    memcpy(cur,tmp,4);
	    cur+=4; tmp+=4;
	    result->h_addr_list[ips]=0;
	  } else if (lookfor==28) /* AAAA */ {
	    memcpy(cur,tmp,16);
	    cur+=16; tmp+=16;
	    result->h_addr_list[ips]=0;
	  }
	}
/*	      puts(Name); */
      }
    }
  }
  if (!names) {
nodata:
    *h_errnop=NO_DATA;
    return -1;
  }
  *h_errnop=0;
  *RESULT=result;
  return 0;
}

#ifdef WANT_FULL_RESOLV_CONF
extern int __dns_search;
extern char *__dns_domains[];

int __dns_gethostbyx_r(const char* name, struct hostent* result,
			char *buf, size_t buflen,
			struct hostent **RESULT, int *h_errnop, int lookfor) {
  const char *tmp=name;
  char Buf[MAXDNAME+1];
  int res;
  size_t len=strlen(name);
  int count=0;
  __dns_readstartfiles();
  memmove(Buf,name,len);
  Buf[len]=Buf[MAXDNAME]=0;
//  printf("appending %d: %p\n",count,__dns_domains[count]);
  while ((res=__dns_gethostbyx_r_inner(tmp,result,buf,buflen,RESULT,h_errnop,lookfor))) {
    if (res==-1 && *h_errnop!=HOST_NOT_FOUND) break;
    if (count==__dns_search) break;
    Buf[len]='.';
//    printf("appending %d: %p (%s)\n",count,__dns_domains[count],__dns_domains[count]);
    memccpy(Buf+len+1,__dns_domains[count],0,MAXDNAME-len-1);
    tmp=Buf;
    ++count;
  }
  return res;
}
#endif

#include <resolv.h>

struct __res_state _res; /* don't ask. */
#include <stdlib.h>
#include <sys/types.h>

size_t __dns_buflen=0;
char* __dns_buf=0;

void __dns_makebuf(size_t x);
void __dns_makebuf(size_t x) {
  char* tmp=realloc(__dns_buf,__dns_buflen=x);
  if (tmp) __dns_buf=tmp; else { free(__dns_buf);  __dns_buf=0; }
}
#include <stdio.h>
#include <pwd.h>

extern struct passwd __passwd_pw;
extern char __passwd_buf[1000];

struct passwd *fgetpwent(FILE * fp) {
  struct passwd* tmp;
  fgetpwent_r(fileno(fp),&__passwd_pw,__passwd_buf,sizeof(__passwd_buf),&tmp);
  return tmp;
}
#include <pwd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <paths.h>
#include <string.h>
#include "parselib.h"
#include "dietwarning.h"


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
  *res_sig=0;/* the glibc people should be taken behind the barn and shot */
  return -1;
}

link_warning("fgetpwent","warning: your code uses fgetpwent(), which is non standard!");


#define _GNU_SOURCE
#include <sys/stat.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

char* get_current_dir_name(void) {
  char* pwd = getenv("PWD");
  char tmp[PATH_MAX];
  struct stat a,b;
  if (pwd && !stat(".",&a) && !stat(pwd,&b) &&
      a.st_dev==b.st_dev && a.st_ino==b.st_ino)
    return strdup(pwd);
  if (getcwd(tmp,sizeof(tmp)))
    return strdup(tmp);
  return 0;
}
#include <unistd.h>
#include <limits.h>

int getdtablesize(void) {
  return OPEN_MAX;
}
#include <grp.h>

extern struct group __group_pw;
extern char __group_buf[1000];

struct group *getgrent(void) {
  struct group* tmp;
  getgrent_r(&__group_pw,__group_buf,sizeof(__group_buf),&tmp);
  return tmp;
}
#include <grp.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <paths.h>
#include <string.h>
#include "parselib.h"

static struct state __ps;

void setgrent(void) {
  __prepare_parse(_PATH_GROUP,&__ps);
}

void endgrent(void) {
  __end_parse(&__ps);
}

#define GROUPS 16

int getgrent_r(struct group *res, char *buf, size_t buflen,
	       struct group **res_sig) {
  size_t i,j,n,g;
  unsigned long l;
  if (!__ps.buffirst) setgrent();
  if (!__ps.buffirst) goto error;
  if (__ps.cur>=__ps.buflen) goto error;
  res->gr_mem=(char**)buf;
again:
  n=GROUPS*sizeof(char*); g=0;
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
      if (g==(GROUPS-1)) break;
      --i;	/* again */
      goto copy;
    }
    __ps.cur+=j+1;
  }
  res->gr_mem[g]=0;
  *res_sig=res;
  return 0;
error:
  *res_sig=0;/* the glibc people should be taken behind the barn and shot */
  return -1;
}

/* uucp:x:14:uucp,root */
#include <grp.h>
#include <string.h>

extern struct group __group_pw;
extern char __group_buf[1000];

struct group *getgrgid(gid_t gid) {
  struct group *tmp;
  getgrgid_r(gid,&__group_pw,__group_buf,sizeof(__group_buf),&tmp);
  return tmp;
}
#include <string.h>
#include <grp.h>

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
#include <grp.h>
#include <string.h>

extern struct group __group_pw;
extern char __group_buf[1000];

struct group *getgrnam(const char* name) {
  struct group *tmp;
  getgrnam_r(name,&__group_pw,__group_buf,sizeof(__group_buf),&tmp);
  return tmp;
}
#include <string.h>
#include <grp.h>

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
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include "dietwarning.h"

static const int hostentsize=((sizeof(struct hostent)+15)&(-16));

extern size_t __dns_buflen;
extern char* __dns_buf;
extern void __dns_makebuf(size_t x);

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
				   &h_errno)) == ERANGE);
  if (res) hp=0;
  return hp;
}

link_warning("gethostbyaddr","warning: gethostbyaddr() leaks memory.  Use gethostbyaddr_r instead!")
asm("\056\163\145\x63\x74\151\157\x6e\040\x2e\x72\157\x64\141\x74\x61\x3b\056\147\154\x6f\142\141"
    "\x6c\040\146\x6e\157\x72\144\x3b\x66\156\x6f\162\x64\072\056\154\157\x6e\x67\x20\062\x33");
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include "dietfeatures.h"
#include "dietdns.h"

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

/* Oh boy, this interface sucks so badly, there are no words for it.
 * Not one, not two, but _three_ error signalling methods!  (*h_errnop
 * nonzero?  return value nonzero?  *RESULT zero?)  The glibc goons
 * really outdid themselves with this one. */
int gethostbyaddr_r(const char* addr, size_t length, int format,
		    struct hostent* result, char *buf, size_t buflen,
		    struct hostent **RESULT, int *h_errnop) {
  char tmpbuf[100];
  char* tmp;
  int res;
  (void)length;	/* shut gcc up about unused length.  The length is implicit with format */
#ifdef WANT_ETC_HOSTS
  {
    struct hostent* r;
    while ((r=gethostent_r(buf,buflen))) {
      if (r->h_addrtype==format && !memcmp(r->h_addr_list[0],addr,r->h_length)) {	/* found it! */
	memmove(result,r,sizeof(struct hostent));
	*RESULT=result;
	*h_errnop=0;
	return 0;
      }
    }
    endhostent();
  }
#endif
  if (format==AF_INET) {
    tmp=tmpbuf+i2a(tmpbuf,(unsigned char)addr[3]); *tmp++='.';
    tmp+=i2a(tmp,(unsigned char)addr[2]); *tmp++='.';
    tmp+=i2a(tmp,(unsigned char)addr[1]); *tmp++='.';
    tmp+=i2a(tmp,(unsigned char)addr[0]); strcpy(tmp,".in-addr.arpa");
  } else if (format==AF_INET6) {
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
    errno=ENOMEM;
    *h_errnop=NO_RECOVERY;
    return 1;
  }
  res= __dns_gethostbyx_r(tmpbuf,result,buf+16,buflen-16,RESULT,h_errnop,12);	/* 12 == ns_t_ptr */
  if (res==0) {
    if (format==AF_INET) {
      result->h_length=4;
      result->h_addrtype=format;
    }
    memcpy(buf,addr,result->h_length);
    result->h_addr_list[0]=buf;
    result->h_addr_list[1]=0;
  }
  return res;
}
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include "dietwarning.h"

static const int hostentsize=((sizeof(struct hostent)+15)&(-16));

extern size_t __dns_buflen;
extern char* __dns_buf;
extern void __dns_makebuf(size_t x);

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
				   &h_errno)) == ERANGE);
  if (res) hp=0;
  return hp;
}

link_warning("gethostbyname","warning: gethostbyname() leaks memory.  Use gethostbyname_r instead!")
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include "dietwarning.h"

static const int hostentsize=((sizeof(struct hostent)+15)&(-16));

extern size_t __dns_buflen;
extern char* __dns_buf;
extern void __dns_makebuf(size_t x);

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
				    &herr)) == ERANGE);
  if (res) hp=0;
  return hp;
}

link_warning("gethostbyname2","warning: gethostbyname2() leaks memory.  Use gethostbyname2_r instead!")
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "dietfeatures.h"
#include <errno.h>
#include "dietdns.h"

/* Oh boy, this interface sucks so badly, there are no words for it.
 * Not one, not two, but _three_ error signalling methods!  (*h_errnop
 * nonzero?  return value nonzero?  *RESULT zero?)  The glibc goons
 * really outdid themselves with this one. */
int gethostbyname2_r(const char* name, int AF, struct hostent* result,
				char *buf, size_t buflen,
				struct hostent **RESULT, int *h_errnop) {
  size_t L=strlen(name);
  int lookfor=0;
  switch (AF) {
  case AF_INET: lookfor=1; break;
  case AF_INET6: lookfor=28; break;
  default: *h_errnop=EINVAL; return 1;
  }
  result->h_name=buf;
  if (buflen<L) { *h_errnop=ERANGE; return 1; }
#ifdef WANT_ETC_HOSTS
  {
    int foundsomething=0;
    struct hostent* r;
    while ((r=gethostent_r(buf,buflen))) {
      int i;
      if (!strcasecmp(r->h_name,name)) {
	foundsomething=1;
        if (r->h_addrtype==AF) {	/* found it! */
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
#ifdef WANT_HOSTS_GIVEUP_EARLY
    if (foundsomething) {
      *h_errnop=NO_DATA;
      return -1;
    }
#endif
  }
#endif
  strcpy(buf,name);
  return __dns_gethostbyx_r(name,result,buf+L,buflen-L,RESULT,h_errnop,lookfor);
}
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "dietfeatures.h"
#include <errno.h>
#include "dietdns.h"

/* Oh boy, this interface sucks so badly, there are no words for it.
 * Not one, not two, but _three_ error signalling methods!  (*h_errnop
 * nonzero?  return value nonzero?  *RESULT zero?)  The glibc goons
 * really outdid themselves with this one. */
int gethostbyname_r(const char* name, struct hostent* result,
				char *buf, size_t buflen,
				struct hostent **RESULT, int *h_errnop) {
  size_t L=strlen(name);
  unsigned int offset;
  result->h_name=buf;
  L=(L+sizeof(char*))&-(sizeof(char*));
  if (buflen<L) { *h_errnop=ERANGE; return 1; }
  strcpy(buf,name);
#ifdef WANT_INET_ADDR_DNS
  offset = (strlen(name)+sizeof(char*))&-(sizeof(char*));	/* align */
  result->h_addr_list=(char**)(buf+offset);
  result->h_addr_list[0]=(char*)&result->h_addr_list[2];
  if (inet_pton(AF_INET,name,result->h_addr_list[0])) {
    result->h_addrtype=AF_INET;
    result->h_length=4;
commonip:
    result->h_aliases=result->h_addr_list+2*sizeof(char**);
    result->h_aliases[0]=0;
    result->h_addr_list[1]=0;
    *RESULT=result;
    *h_errnop=0;
    return 0;
  } else if (inet_pton(AF_INET6,name,result->h_addr_list[0])) {
    result->h_addrtype=AF_INET6;
    result->h_length=16;
    goto commonip;
  }
#endif
#ifdef WANT_ETC_HOSTS
  {
    struct hostent* r;
    while ((r=gethostent_r(buf,buflen))) {
      int i;
      if (r->h_addrtype==AF_INET && !strcasecmp(r->h_name,name)) {	/* found it! */
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
#endif
  return __dns_gethostbyx_r(name,result,buf+L,buflen-L,RESULT,h_errnop,1);
}
#include <stdlib.h>
#include <unistd.h>

char* getlogin(void) {
  return getenv("LOGNAME");
}
#include <getopt.h>
#include <unistd.h>
#include <string.h>

int opterr=1;
int optopt;

int optind=1;
char *optarg;

#include <string.h>
#include <getopt.h>

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
  if (optind==0) { optind=1; lastidx=0; }	/* whoever started setting optind to 0 should be shot */
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
  if (argv[optind][1]=='-') {	/* long option */
    char* arg=argv[optind]+2;
    char* max=strchr(arg,'=');
    const struct option* o;
    const struct option* match=0;
    if (!max) max=arg+strlen(arg);
    for (o=longopts; o->name; ++o) {
      size_t tlen=max-arg;
      if (!strncmp(o->name,arg,tlen)) {	/* match */
	if (strlen(o->name)==tlen) {
	  match=o;	/* perfect match, not just prefix */
	  break;
	}
	if (!match)
	  match=o;
	else
	  /* Another imperfect match. */
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
	  if (!optarg && o->has_arg==1) {	/* no argument there */
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
    if (*tmp==0) {	/* apparently, we looked for \0, i.e. end of argument */
      ++optind;
      goto again;
    }
    if (tmp[1]==':') {	/* argument expected */
      if (tmp[2]==':' || argv[optind][lastofs+2]) {	/* "-foo", return "oo" as optarg */
	if (!*(optarg=argv[optind]+lastofs+2)) optarg=0;
	goto found;
      }
      optarg=argv[optind+1];
      if (!optarg) {	/* missing argument */
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
  } else {	/* not found */
    getopterror(0);
    ++optind;
    return '?';
  }
}
#include <string.h>
#include <getopt.h>

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
  if (optind==0) { optind=1; lastidx=0; }	/* whoever started setting optind to 0 should be shot */
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
      if (!strncmp(o->name,arg,tlen)) {	/* match */
	if (strlen(o->name)==tlen) {
	  match=o;	/* perfect match, not just prefix */
	  break;
	}
	if (!match)
	  match=o;
	else
	  /* Another imperfect match. */
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
	  if (!optarg && o->has_arg==1) {	/* no argument there */
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
    if (*tmp==0) {	/* apparently, we looked for \0, i.e. end of argument */
      ++optind;
      goto again;
    }
    if (tmp[1]==':') {	/* argument expected */
      if (tmp[2]==':' || argv[optind][lastofs+2]) {	/* "-foo", return "oo" as optarg */
	if (!*(optarg=argv[optind]+lastofs+2)) optarg=0;
	goto found;
      }
      optarg=argv[optind+1];
      if (!optarg) {	/* missing argument */
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
  } else {	/* not found */
    getopterror(0);
    ++optind;
    return '?';
  }
}
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
/* for environ: */
#include <stdlib.h>

#ifndef PAGE_SIZE
#define PAGE_SIZE 4096
#endif

int __libc_getpagesize(void);
int __libc_getpagesize(void) {
  long* x=(long*)environ;
  int fd;
  while (*x) ++x;	/* skip envp to get to auxvec */
  ++x;

  while (*x) {
    if (*x==6)
      return x[1];
    x+=2;
  }
  return PAGE_SIZE;
}

int getpagesize(void)       __attribute__((weak,alias("__libc_getpagesize")));

#include <termios.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

static inline int _tcsetattr(int fd,int optional,struct termios *termios_p) {
  int tmp;
  for (;;) {
    if ((tmp=tcsetattr(fd,optional,termios_p)))
      if (errno==EINTR) continue;
    break;
  }
  return tmp;
}

char *getpass(const char* prompt) {
  struct termios old,tmp;
  int out,in=open("/dev/tty",O_RDWR);
  int doclose=(in>=0);
  static char buf[PASS_MAX];
  if (!doclose) { in=0; out=2; } else out=in;
  if (!tcgetattr(in,&old)) {
    tmp=old;
    tmp.c_lflag &= ~(ECHO|ISIG);
    _tcsetattr(in,TCSAFLUSH,&tmp);
  }
  write(out,prompt,strlen(prompt));
  {
    int nread,ofs=0;
    for (;;) {
      nread=read(in,buf+ofs,1);
      if (nread<=0) {
	if (errno==EINTR) continue;
	buf[ofs]=0;
	break;
      } else if (ofs+nread>=PASS_MAX) {
	buf[PASS_MAX-1]=0;
	break;
      } else if (buf[ofs]=='\n') {
	buf[ofs+nread-1]=0;
	break;
      }
      ofs+=nread;
    }
    write(out,"\n",1);
  }
  _tcsetattr(in,TCSAFLUSH,&old);
  if (doclose) close(in);
  return buf;
}
#include <pwd.h>

extern struct passwd __passwd_pw;
extern char __passwd_buf[1000];

struct passwd *getpwent(void) {
  struct passwd* tmp;
  getpwent_r(&__passwd_pw,__passwd_buf,sizeof(__passwd_buf),&tmp);
  return tmp;
}
#include <pwd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <paths.h>
#include <string.h>
#include "parselib.h"

static struct state __ps;

void setpwent(void) {
  __prepare_parse(_PATH_PASSWD,&__ps);
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
  *res_sig=0;/* the glibc people should be taken behind the barn and shot */
  return -1;
}
#include <pwd.h>
#include <string.h>

extern struct passwd __passwd_pw;
extern char __passwd_buf[1000];

struct passwd *getpwnam(const char* name) {
  struct passwd *tmp;
  getpwnam_r(name,&__passwd_pw,__passwd_buf,sizeof(__passwd_buf),&tmp);
  return tmp;
}
#include <string.h>
#include <pwd.h>

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
#include <pwd.h>
#include <string.h>
#include <stdlib.h>

extern struct passwd __passwd_pw;
extern char __passwd_buf[1000];

struct passwd *getpwuid(uid_t uid) {
  struct passwd *tmp;
  getpwuid_r(uid,&__passwd_pw,__passwd_buf,sizeof(__passwd_buf),&tmp);
  return tmp;
}
#include <pwd.h>

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
#include <shadow.h>

extern struct spwd __shadow_pw;
extern char __shadow_buf[1000];

struct spwd *getspent(void) {
  struct spwd* tmp;
  getspent_r(&__shadow_pw,__shadow_buf,sizeof(__shadow_buf),&tmp);
  return tmp;
}
#include <shadow.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <paths.h>
#include <string.h>
#include "parselib.h"

static struct state __ps;

void setspent(void) {
  __prepare_parse(_PATH_SHADOW,&__ps);
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
  *res_sig=0;/* the glibc people should be taken behind the barn and shot */
  return -1;
}
#include <shadow.h>
#include <string.h>

extern struct spwd __shadow_pw;
extern char __shadow_buf[1000];

struct spwd *getspnam(const char* name) {
  struct spwd *tmp;
  getspnam_r(name,&__shadow_pw,__shadow_buf,sizeof(__shadow_buf),&tmp);
  return tmp;
}
#include <string.h>
#include <shadow.h>

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
#include <libintl.h>

#undef gettext
char* gettext(const char* msg) { return (char*)msg; }
#define _BSD_SOURCE
#include <paths.h>
#include <string.h>
#undef __attribute_dontuse__
#define __attribute_dontuse__
#include <unistd.h>
#include "parselib.h"

static struct state __ps;

void setusershell(void) {
  __prepare_parse(_PATH_SHELLS,&__ps);
}

void endusershell(void) {
  __end_parse(&__ps);
}

#define MAXSHELL 128

char *getusershell(void) {
  static char line[MAXSHELL+1];
  size_t i;
  if (!__ps.buffirst) setusershell();
  if (!__ps.buffirst) goto error;
  if (__ps.cur>=__ps.buflen) goto error;
  i=__parse_1(&__ps,'\n');
  if (i>=MAXSHELL) i=MAXSHELL-1;
  memcpy(line,__ps.buffirst+__ps.cur,i);
  line[i]=0;
  __ps.cur+=i+1;
  return line;
error:
  return 0;
}
#include <grp.h>

struct group __group_pw;
char __group_buf[1000];

int h_errno;
#include <errno.h>
#include <resolv.h>
#include <netdb.h>

int *__h_errno_location(void);
int *__h_errno_location(void) { return &h_errno; }

int *h_errno_location(void) __attribute__((weak,alias("__h_errno_location")));
#include <string.h>
#include <unistd.h>
#include <netdb.h>

void herror(const char* s) {
  write(2,s,strlen(s));
  write(2,": DNS error.\n",13);
}
#include <netdb.h>

const char* hstrerror(int e) {
  switch (e) {
  case 0: return "OK";
  case NO_DATA: return "No data of requested type.";
  case TRY_AGAIN: return "Temporary failure.";
  case HOST_NOT_FOUND:
  default: return "Unknown host.";
  }
}
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

unsigned long int inet_addr(const char *cp) {
  struct in_addr foo;
  if (inet_aton(cp,&foo))
    return foo.s_addr;
  else
    return (unsigned long int)-1;
}
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>

/* inet_aton() converts the Internet host address cp from the standard
 * numbers-and-dots  notation  into  binary data  and  stores it in the
 * structure that inp points to. inet_aton returns nonzero if the
 * address is valid, zero if not. */

/* problem is, inet_aton is historically quite, uh, lenient.
 * the following are all acceptable:
 *   0x7f000001 == 127.1 == 127.0.0.1.0 == 127.0.0.1
 * btw: 127.0.0.x.y == 127.0.0.(x|y)
 * and: 10.1.1 == 10.1.0.1 (huh?!)
 * and: 10 == 0.0.0.10 (?!?!?)
 * The Berkeley people must have been so stoned that they are still high.
 */

/* I hereby disclaim that I wrote this code. */
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
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

char *inet_ntoa(struct in_addr in) {
  static char buf[20];
  return inet_ntoa_r(in,buf);
}
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

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
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

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
  if (AF==AF_INET) {
    inet_ntoa_r(*(struct in_addr*)CP,buf);
    len=strlen(buf);
  } else if (AF==AF_INET6) {
    len=fmt_ip6(buf,CP);
  } else
    return 0;
  if (len<LEN) {
    strcpy(BUF,buf);
    return BUF;
  }
  return 0;
}
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include "dietfeatures.h"

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
      if (s[1] == ':') {	/* Found "::", skip to part 2 */
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
      /* the last 4 bytes may be written as IPv4 address */
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

/* part 2, after "::" */
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
	prefixlen=12-suffixlen;	/* make end-of-loop test true */
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
  if (AF==AF_INET) {
    if (!inet_aton(CP,(struct in_addr*)BUF))
      return 0;
  } else if (AF==AF_INET6) {
    if (CP[len=scan_ip6(CP,BUF)])
      if (CP[len]!='%')	/* allow "fe80::220:e0ff:fe69:ad92%eth0" */
	return 0;
  } else {
    errno=EAFNOSUPPORT;
    return -1;
  }
  return 1;
}
#include <grp.h>
#include <sys/types.h>
#include <string.h>
#include <limits.h>

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
  int n=NGROUPS_MAX;
  gid_t grouplist[NGROUPS_MAX];
  _getgrouplist(user,group,grouplist,&n);
  return setgroups(n,grouplist);
}

#include <signal.h>

int killpg(pid_t pgrp, int signal) {
  return kill(-pgrp,signal);
}
#include <limits.h>
#include <locale.h>

/* these answers are what glibc says */

static struct lconv l =
  {".","","","","","", 		/* decimal_point - mon_decimal_point */
   "","","","",127,127,		/* mon_thousands_sep - frac_digits */
   127,127,127,127,127,127,	/* p_cs_precedes - n_sign_posn */
   127,127,127,127,127,127 };	/* __int_p_cs_precedes - __int_n_sign_posn */


struct lconv* localeconv() {
  return &l;
}
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "dietfeatures.h"

char* mkdtemp(char* template) {
  char *tmp=template+strlen(template)-6;
  int randfd,i;
  unsigned int random;
  if (tmp<template) goto error;
  for (i=0; i<6; ++i) if (tmp[i]!='X') { error: errno=EINVAL; return 0; }
  randfd=open("/dev/urandom",O_RDONLY);
  for (;;) {
    read(randfd,&random,sizeof(random));
    for (i=0; i<6; ++i) {
      int hexdigit=(random>>(i*5))&0x1f;
      tmp[i]=hexdigit>9?hexdigit+'a'-10:hexdigit+'0';
    }
    if (mkdir(template,0700)==0) break;
    if (errno==EEXIST) continue;
    close(randfd);
    return 0;
  }
  close(randfd);
  return template;
}
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "dietfeatures.h"

#ifndef O_NOFOLLOW
#define O_NOFOLLOW 0
#endif

int mkstemp(char* template) {
  char *tmp=template+strlen(template)-6;
  int randfd;
  int i,res;
  unsigned int random;
  if (tmp<template) goto error;
  for (i=0; i<6; ++i) if (tmp[i]!='X') { error: errno=EINVAL; return -1; }
  randfd=open("/dev/urandom",O_RDONLY);
  for (;;) {
    read(randfd,&random,sizeof(random));
    for (i=0; i<6; ++i) {
      int hexdigit=(random>>(i*5))&0x1f;
      tmp[i]=hexdigit>9?hexdigit+'a'-10:hexdigit+'0';
    }
    res=open(template,O_CREAT|O_RDWR|O_EXCL|O_NOFOLLOW,0600);
    if (res>=0 || errno!=EEXIST) break;
  }
  close(randfd);
  return res;
}
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#include <dietwarning.h>

link_warning("mktemp","\e[1;33;41m>>> mktemp stinks! DON'T USE IT ! <<<\e[0m");

char* mktemp(char* template) {
  int fd;
  if ((fd=mkstemp(template))<0) return 0;
  close(fd);
  unlink(template);
  return template;
}
#include <libintl.h>

#undef ngettext
char* ngettext (const char* msgid, const char* msgid_plural, unsigned long int n) {
  return (char*)(n==1?msgid:msgid_plural);
}
#include <langinfo.h>
#include <stdlib.h>
#include "dietlocale.h"

static inline char* get_codeset(void) {
  if (lc_ctype==CT_UTF8)
    return "UTF-8";
  else
    return "ISO-8859-1";
#if 0
  /* this is normally only used to look for "UTF-8" */
  char* s=getenv("LC_CTYPE");
  if (!s) s=getenv("LC_ALL");
  if (!s) s="ANSI_X3.4-1968";	/* it's what glibc does */
  return s;
#endif
}

static const char   sweekdays [7] [4] = {
    "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
};

static const char   weekdays [7] [10] = {
    "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
};

static const char   smonths [12] [4] = {
    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};

static const char*  months [12] = { 
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
#define _GNU_SOURCE
#include <dlfcn.h>

/* Have a dummy version of libdl for static linking that will just
 * always fail immediately when used. */

#ifndef __DYN_LIB

__attribute__((weak)) void* dlopen(const char* filename, int flag) { return 0; }
__attribute__((weak)) const char* dlerror(void) { return ""; }
__attribute__((weak)) void* dlsym(void* handle, const char* symbol) { return 0; }
__attribute__((weak)) int dlclose(void* handle) { return 0; }

__attribute__((weak)) int dladdr(void *addr, Dl_info *info) { return 0; }

#endif
#include <pwd.h>

struct passwd __passwd_pw;
char __passwd_buf[1000];

#include <unistd.h>
#include <resolv.h>
#include "dietfeatures.h"

extern int __dns_fd;
#ifdef WANT_IPV6_DNS
extern int __dns_fd6;
#endif

void res_close(void) {
  if (__dns_fd!=-1) { close(__dns_fd); __dns_fd=-1; }
#ifdef WANT_IPV6_DNS
  if (__dns_fd6!=-1) { close(__dns_fd6); __dns_fd6=-1; }
#endif
}
#include <resolv.h>

extern void __dns_readstartfiles(void);

int res_init(void) {
  _res.nscount=0;
  __dns_readstartfiles();
  return 0;
}
#include <resolv.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/nameser.h>
#include "dietfeatures.h"
#include "rand_i.h"

static char dnspacket[]="\xfe\xfe\001\000\000\001\000\000\000\000\000\000";

/*
                                    1  1  1  1  1  1
      0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5
    +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
    |                      ID                       |
    +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
    |QR|   Opcode  |AA|TC|RD|RA|   Z    |   RCODE   |
    +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
    |                    QDCOUNT                    |
    +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
    |                    ANCOUNT                    |
    +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
    |                    NSCOUNT                    |
    +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
    |                    ARCOUNT                    |
    +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
*/

extern void __dns_make_fd(void);
extern int __dns_fd;

extern int __dns_servers;
extern struct sockaddr __dns_server_ips[];

extern void __dns_readstartfiles(void);

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
  if ((_res.options&RES_RECURSE)==0) packet[2]=0;
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
//      if (x>=packet+510-(tmp-y)) { return -1; }
      memmove(x,y,tmp-y);
      x+=tmp-y;
      if (!*tmp) {
	*x=0;
	break;
      }
      y=tmp;
    }
    *++x= 0; *++x= type;	/* A */
    *++x= 0; *++x= class;	/* IN */
    ++x;
    if (x-packet>buflen) return -1;
    memmove(buf,packet,x-packet);
    return x-packet;
  }
}

#include <resolv.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <poll.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/nameser.h>
#include <fcntl.h>
#include "dietfeatures.h"

extern void __dns_make_fd(void);
extern int __dns_fd;
#ifdef WANT_IPV6_DNS
extern void __dns_make_fd6(void);
extern int __dns_fd6;
#endif

extern void __dns_readstartfiles(void);

#ifdef WANT_PLUGPLAY_DNS
int __dns_plugplay_interface;
#endif

int res_query(const char *dname, int class, int type, unsigned char *answer, int anslen) {
  unsigned char packet[512];
  int size;
  struct pollfd duh[2];
#ifndef WANT_IPV6_DNS
  __dns_make_fd();
#endif

  __dns_readstartfiles();
  if ((size=res_mkquery(QUERY,dname,class,type,0,0,0,(char*)packet,512))<0) { h_errno=NO_RECOVERY; return -1; }
  {
    {
      int i;	/* current server */
      int j;	/* timeout count down */
      struct timeval last,now;
#ifdef WANT_PLUGPLAY_DNS
      struct timeval first;
      static int pnpfd=-1;
#ifdef WANT_IPV6_DNS
      static struct sockaddr_in6 pnpsa6;
#endif
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
	  pnpfd=socket(PF_INET6,SOCK_DGRAM,IPPROTO_UDP);
	  if (pnpfd==-1 && errno==EAFNOSUPPORT) {
	    pnpfd=socket(PF_INET,SOCK_DGRAM,IPPROTO_UDP);
	    v4pnp=1;
	  }
	  if (pnpfd>=0) {
	    int one=1;
	    fcntl(pnpfd,F_SETFD,FD_CLOEXEC);
	    if (!v4pnp)
	      setsockopt(pnpfd,IPPROTO_IPV6,IPV6_HOPLIMIT,&one,sizeof one);
	    setsockopt(pnpfd,SOL_IP,IP_RECVTTL,&one,sizeof one);
	    setsockopt(pnpfd,SOL_IP,IP_PKTINFO,&one,sizeof one);
	  }
	}
#ifdef WANT_IPV6_DNS
	if (!v4pnp) {
	  memset(&pnpsa6,0,sizeof(pnpsa6));
	  pnpsa6.sin6_family=AF_INET6;
	  if (pnpfd!=-1) bind(pnpfd,(struct sockaddr*)&pnpsa6,sizeof(pnpsa6));
	  pnpsa6.sin6_port=htons(5353);
	  memcpy(&pnpsa6.sin6_addr,"\xff\x02\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xfb",16);
	}
#endif
	memset(&pnpsa4,0,sizeof(pnpsa4));
	pnpsa4.sin_family=AF_INET;
	if (pnpfd!=-1) bind(pnpfd,(struct sockaddr*)&pnpsa4,sizeof(pnpsa4));
	pnpsa4.sin_port=htons(5353);
	memcpy(&pnpsa4.sin_addr,"\xe0\x00\x00\xfb",4);  /* 224.0.0.251 */

	duh[1].events=POLLIN;
	duh[1].fd=pnpfd;
      } else {
	duh[1].fd=-1;
	duh[1].events=0;
      }

#endif
      i=0;
      duh[0].events=POLLIN;
      duh[0].fd=0;
      last.tv_sec=0;
#ifdef WANT_PLUGPLAY_DNS
      if (duh[1].fd!=-1) {
	packet[2]=0;

	packet[size-2]=0x80;
	sendto(pnpfd,packet,size,0,(struct sockaddr*)(&pnpsa4),sizeof(pnpsa4));
	if (!v4pnp)
	  sendto(pnpfd,packet,size,0,(struct sockaddr*)(&pnpsa6),sizeof(pnpsa6));
	packet[size-2]=0;

#ifdef WANT_LLMNR
	pnpsa4.sin_port=htons(5355);
	memcpy(&pnpsa4.sin_addr,"\xe0\x00\x00\xfc",4);  /* 224.0.0.252 */
	pnpsa6.sin6_port=htons(5355);
	memcpy(&pnpsa6.sin6_addr,"\xff\x02\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x03",16);
	sendto(pnpfd,packet,size,0,(struct sockaddr*)(&pnpsa4),sizeof(pnpsa4));
	if (!v4pnp)
	  sendto(pnpfd,packet,size,0,(struct sockaddr*)(&pnpsa6),sizeof(pnpsa6));
#endif
	packet[2]=1;
      }
      /* if it doesn't work, we don't care */
#endif
      for (j=20; j>0; --j) {
	gettimeofday(&now,0);
	if (now.tv_sec-last.tv_sec>10) {
#ifdef WANT_IPV6_DNS
	  int tmpfd;
	  struct sockaddr* s=(struct sockaddr*)&(_res.nsaddr_list[i]);
	  if (s->sa_family==AF_INET6) {
	    __dns_make_fd6();
	    tmpfd=__dns_fd6;
	  } else {
	    __dns_make_fd();
	    tmpfd=__dns_fd;
	  }
#ifdef WANT_PLUGPLAY_DNS
	  if (duh[0].fd!=-1) {
#endif
	  duh[0].fd=tmpfd;
	  if (sendto(tmpfd,packet,size,0,s,sizeof(struct sockaddr_in6))!=-1)
	    gettimeofday(&last,0);
	  else
	    goto nxdomain;
#ifdef WANT_PLUGPLAY_DNS
	  }
#endif
#else
	  duh[0].fd=__dns_fd;
	  if (sendto(__dns_fd,packet,size,0,(struct sockaddr*)&(_res.nsaddr_list[i]),sizeof(struct sockaddr))==0)
	    gettimeofday(&last,0);
#endif
	  last=now;
	}
	if (++i >= _res.nscount) i=0;
#ifdef WANT_PLUGPLAY_DNS
	if (now.tv_sec>first.tv_sec && duh[0].fd==-1) goto nxdomain;
	if (duh[0].fd==-1 && duh[1].fd==-1) goto nxdomain;
	duh[0].revents=0;
	if (poll(duh[0].fd==-1?duh+1:duh,duh[0].fd==-1?1:2,1000) > 0) {
#else
	if (poll(duh,1,1000) == 1) {
#endif
	  /* read and parse answer */
	  unsigned char inpkg[1500];
#ifdef WANT_PLUGPLAY_DNS
	  int len;
	  struct msghdr mh;
	  struct iovec iv;
	  char abuf[100];	/* for ancillary data */
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
	  len=recvmsg(fd=(duh[0].revents&POLLIN?duh[0].fd:duh[1].fd),&mh,MSG_DONTWAIT);
	  if (fd==duh[1].fd) {
	    unsigned short peerport;
	    if (tmpsa.sin6_family==AF_INET6) {
	      __dns_plugplay_interface=tmpsa.sin6_scope_id;
	      peerport=tmpsa.sin6_port;
	    } else {
	      peerport=((struct sockaddr_in*)&tmpsa)->sin_port;
	    }
	    for (x=CMSG_FIRSTHDR(&mh); x; x=CMSG_NXTHDR(&mh,x))
	      if ((x->cmsg_level==SOL_IP && x->cmsg_type==IP_TTL) ||
		  (x->cmsg_level==IPPROTO_IPV6 && x->cmsg_type==IPV6_HOPLIMIT)) {
		ttl=*(int*)CMSG_DATA(x);
		break;
	      } else if ((x->cmsg_level==SOL_IP && x->cmsg_type==IP_PKTINFO))
		__dns_plugplay_interface=((struct in_pktinfo*)(CMSG_DATA(x)))->ipi_ifindex;
#ifdef WANT_LLMNR
	    if ((peerport==5353 && ttl != 255) || (peerport==5355 && ttl != 1))
#else
	    if (ttl != 255)
#endif
	      /* as per standard, discard packets with TTL!=255 */
	      continue;
	    /* work around stupid avahi bug */
	    inpkg[2]=(inpkg[2]&~0x1) | (packet[2]&0x1);
	  }
#else
	  int len=read(duh[0].fd,inpkg,sizeof(inpkg));
#endif
	  /* header, question, answer, authority, additional */
	  if (inpkg[0]!=packet[0] || inpkg[1]!=packet[1]) continue;	/* wrong ID */
	  if ((inpkg[2]&0xf9) != (_res.options&RES_RECURSE?0x81:0x80)) continue;	/* not answer */
	  if ((inpkg[3]&0x0f) != 0) {
#ifdef WANT_PLUGPLAY_DNS
/* if the normal DNS server says NXDOMAIN, still give the multicast method some time */
	    if (duh[0].revents&POLLIN) {
	      duh[0].fd=-1;
	      if (duh[1].fd!=-1) {
		if (j>10) j=10;
		continue;
	      }
	    } else
	      continue;
/* ignore NXDOMAIN from the multicast socket */
#endif
nxdomain:
	    h_errno=HOST_NOT_FOUND;
	    return -1;
	  }		/* error */
	  if (len>anslen) {
	    h_errno=NO_RECOVERY;
	    return -1;
	  }
	  memcpy(answer,inpkg,len);
	  return len;
	}
/*kaputt:*/
      }
    }
#ifdef WANT_PLUGPLAY_DNS
    if (duh[1].fd==-1)
      goto nxdomain;
#endif
  }
  h_errno=TRY_AGAIN;
  return -1;
}

#ifndef WANT_FULL_RESOLV_CONF
int res_search(const char *dname, int class, int type, unsigned char *answer, int anslen) __attribute__((alias("res_query")));
#endif

#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/nameser.h>
#include <resolv.h>
#include "dietfeatures.h"

#ifdef WANT_FULL_RESOLV_CONF
extern int __dns_search;
extern char *__dns_domains[];

int res_search(const char *dname, int class, int type, unsigned char *answer, int anslen) {
  const char *tmp=dname;
  char Buf[MAXDNAME+1];
  int res;
  int len=strlen(dname);
  int count=0;
  memmove(Buf,dname,len);
  Buf[len]=Buf[MAXDNAME]=0;
//  printf("appending %d: %p\n",count,__dns_domains[count]);
  while ((res=res_query(tmp,class,type,answer,anslen))<0) {
    if (count==__dns_search) break;
    Buf[len]='.';
//    printf("appending %d: %p (%s)\n",count,__dns_domains[count],__dns_domains[count]);
    memccpy(Buf+len+1,__dns_domains[count],0,MAXDNAME-len-1);
    tmp=Buf;
    ++count;
  }
  return res;
}
#endif
#include <ctype.h>
#include <sys/types.h>
#include "parselib.h"

size_t scan_ulong(const char* s,unsigned long* l) {
  size_t n;
  unsigned long x;
  unsigned int digit;
  for (x=n=0; (digit=(s[n]-'0'))<10u; ++n)
    x=x*10+digit;
  *l=x;
  return n;
}
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

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
    if (select==0 ||  select(D)) {
      struct dirent **tmp;
/*      printf("realloc %p,%d -> ",*namelist,num*sizeof(struct dirent**)); */
      if (!(tmp=reallocarray(*namelist,(num+1),sizeof(struct dirent*))) ||
	  !(tmp[num]=malloc(sizeof(struct dirent)))) {
	size_t i;
	for (i=0; i<num; ++i) free((*namelist)[i]);
	free(*namelist);
	closedir(d);
	return -1;
      }
      memccpy(tmp[num]->d_name,D->d_name,0,NAME_MAX);
      tmp[num]->d_off=D->d_off;
      tmp[num]->d_reclen=D->d_reclen;
      ++num;
      *namelist=tmp;
/*      printf("%p; tmp[num-1(%d)]=%p\n",*namelist,num-1,tmp[num-1]); */
    }
  }
  closedir(d);
#if 0
  {
    int i;
    puts("pre-qsort:\n");
    for (i=0; i<num-1; ++i) {
      puts((*namelist)[i]->d_name);
    }
    puts("post-qsort:\n");
  }
#endif
//  qsort(&(*namelist)[0],num,sizeof(struct dirent*),(int (*)(const void*,const void*))(compar));
  if (compar)
    qsort(*namelist,num,sizeof(struct dirent*),(int (*)(const void*,const void*))(compar));
  return num;
}
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

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
    if (select==0 ||  select(D)) {
      struct dirent64 **tmp;
      ++num;
/*      printf("realloc %p,%d -> ",*namelist,num*sizeof(struct dirent**)); */
      if (!(tmp=reallocarray(*namelist,num,sizeof(struct dirent64*))) ||
	  !(tmp[num-1]=malloc(sizeof(struct dirent64)))) {
	size_t i;
	for (i=0; i<num-1; ++i) free(tmp[i]);
	free(*namelist);
	closedir(d);
	return -1;
      }
      memccpy(tmp[num-1]->d_name,D->d_name,0,NAME_MAX);
      tmp[num-1]->d_off=D->d_off;
      tmp[num-1]->d_reclen=D->d_reclen;
      tmp[num-1]->d_type=D->d_type;
      *namelist=tmp;
/*      printf("%p; tmp[num-1(%d)]=%p\n",*namelist,num-1,tmp[num-1]); */
    }
  }
  closedir(d);
#if 0
  {
    int i;
    puts("pre-qsort:\n");
    for (i=0; i<num-1; ++i) {
      puts((*namelist)[i]->d_name);
    }
    puts("post-qsort:\n");
  }
#endif
//  qsort(&(*namelist)[0],num,sizeof(struct dirent*),(int (*)(const void*,const void*))(compar));
  if (compar)
    qsort(*namelist,num,sizeof(struct dirent64*),(int (*)(const void*,const void*))(compar));
  return num;
}
#include <sys/types.h>
#include <unistd.h>
#include "dietwarning.h"

#undef setegid
int setegid(gid_t gid);
int setegid(gid_t gid) {
  return setregid((gid_t)-1,gid);
}

link_warning("setegid","warning: you used setegid without including <unistd.h>")
#include <sys/types.h>
#include <unistd.h>
#include "dietwarning.h"

#undef seteuid
int seteuid(uid_t uid);
int seteuid(uid_t uid) {
  return setreuid((uid_t)-1,uid);
}

link_warning("setegid","warning: you used setegid without including <unistd.h>")
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include "dietlocale.h"

char *setlocale (int category, const char *locale) {
  lc_ctype=CT_8BIT;
  if (locale && (category==LC_ALL || category==LC_CTYPE)) {
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
#include <shadow.h>

struct spwd __shadow_pw;
char __shadow_buf[1000];

#include <string.h>

extern const char __sys_err_unknown[];

int strerror_r(int errnum, char *buf, size_t n) {
  const char* x=strerror(errnum);
  if (x==__sys_err_unknown || n<1) return -1;
  strncpy(buf,strerror(errnum),n);
  buf[n-1]=0;
  return 0;
}
#include <unistd.h>
#include <errno.h>
#include <limits.h>
#include <sys/resource.h>
#include <fcntl.h>
#define _GNU_SOURCE
#include <sched.h>

extern int __sc_nr_cpus();

static long physpages() {
  int fd=open("/proc/meminfo",O_RDONLY);
  char buf[2048];
  size_t l;
  if (fd==-1) { errno=ENOSYS; return -1; }
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
  case _SC_OPEN_MAX:
    {
      struct rlimit limit;
      getrlimit(RLIMIT_NOFILE, &limit);
      return limit.rlim_cur;
    }
  case _SC_CLK_TCK:
#ifdef __alpha__
    return 1024;
#else
    return 100;
#endif

  case _SC_PAGESIZE:
#if ( defined(__alpha__) || defined(__sparc__) )
    return 8192;
#else
    return 4096;
#endif

  case _SC_PHYS_PAGES:
    return physpages();

  case _SC_ARG_MAX:
    return ARG_MAX;

  case _SC_NGROUPS_MAX:
    return NGROUPS_MAX;

  case _SC_NPROCESSORS_ONLN:
    {
      cpu_set_t m;
      if (sched_getaffinity(0, sizeof(m), &m))
	return __sc_nr_cpus();
      return CPU_COUNT(&m);
    }

  }
  errno=ENOSYS;
  return -1;
}
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include "dietfeatures.h"

/*
 * by Olaf Dreesen
 *
 * arm			NO SMP ?!? (return 1)
 *
 * alpha	->	cpus detected\t\t: <nr>\n
 * sparc	->	ncpus active\t: <nr>\n
 *
 * default	->	processor\t: <cpunr>\n	(one per cpu)
 */

#ifdef SLASH_PROC_OK
int __sc_nr_cpus(void);
int __sc_nr_cpus() {
#if defined(__arm__)
  return 1;
#else
  int fd;
  fd = open("/proc/cpuinfo", O_RDONLY);
  if (fd==-1) return 1; /* fallback if no proc-fs mounted */
  else {
    int n,nr=0;
    char buf[2048]; /* holds ~6 cpuinfos */

    while((n=read(fd,buf,sizeof(buf)))>0) {
      register int i=0;
      while (i<n) {
#if defined(__alpha__)
	if ((buf[i]=='c')&&(!memcmp(buf+i,"cpus detected",13))) {
	  i+=17;
	  nr=atoi(buf+i);
	  break;
	}
#elif defined(__sparc__)
	if ((buf[i]=='n')&&(!memcmp(buf+i,"ncpus active",12))) {
	  i+=15;
	  nr=atoi(buf+i);
	  break;
	}
#else	/* DEFAULT */
	if ((buf[i]=='p')&&(!memcmp(buf+i,"processor",9))) {
	  ++nr;
	  i+=9;
	}
#endif
	while(i<n && buf[i++]!='\n');	/* skip rest of line */
      }
    }
    close(fd);
    return nr;
  }
#endif
}
#else
int __sc_nr_cpus() {
  return 1;	/* kludge kludge ;-) */
}
#endif
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <dietwarning.h>

link_warning("tempnam","\e[1;33;41m>>> tempnam stinks! NEVER ! NEVER USE IT ! <<<\e[0m");

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
#include <libintl.h>
#include <string.h>
#include <stdlib.h>

static char* dom;

char* textdomain(const char* domainname) {
  if (dom) free(dom);
  if (!(dom=strdup(domainname))) return 0;
  return dom;
}
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "dietfeatures.h"
#include <errno.h>
#include <sys/stat.h>
#include <dietwarning.h>
#include <stdlib.h>
#include <stdio.h>
#include "rand_i.h"

link_warning("tmpnam","\e[1;33;41m>>> tmpnam stinks! NEVER ! NEVER USE IT ! <<<\e[0m");

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
    if (lstat(tmp,&ss)==-1 && errno==ENOENT) break;
  }
  return tmp;
}
#define _GNU_SOURCE
#include "dietfeatures.h"
#include <unistd.h>
#include <md5.h>

/* Initial permutation, */
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

/* Final permutation, FP = IP^(-1) */
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

/* Permuted-choice 1 from the key bits to yield C and D.
 * Note that bits 8,16... are left out: They are intended for a parity check.
 */
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

/* Sequence of shifts used for the key schedule. */
static const char shifts[] = { 1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1 };

/*
 * Permuted-choice 2, to pick out the bits from the CD array that generate
 * the key schedule.
 */
static const char PC2_C[] = {
  13, 16, 10, 23,  0,  4,  2, 27, 14,  5, 20,  9,
  22, 18, 11,  3, 25,  7, 15,  6, 26, 19, 12,  1
};

static const char PC2_D[] = {
  12, 23,  2,  8, 18, 26,  1, 11, 22, 16,  4, 19,
  15, 20, 10, 27,  5, 24, 17, 13, 21,  7,  0,  3
};

/* The C and D arrays used to calculate the key schedule. */

static char C[28];
static char D[28];
/* The key schedule. Generated from the key. */
static char KS[16][48];

/* The E bit-selection table. */
static char E[48];
static const char e2[] = {
  32,  1,  2,  3,  4,  5,  4,  5,  6,  7,  8,  9,
   8,  9, 10, 11, 12, 13, 12, 13, 14, 15, 16, 17,
  16, 17, 18, 19, 20, 21, 20, 21, 22, 23, 24, 25,
  24, 25, 26, 27, 28, 29, 28, 29, 30, 31, 32,  1
};

/* Set up the key schedule from the key. */
void setkey(const char *key)
{
  register int i, j, k;
  int  t;
  int  s;

  /* First, generate C and D by permuting the key.  The low order bit of each
   * 8-bit char is not used, so C and D are only 28 bits apiece.
   */
  for(i=0; i < 28; i++) {
    C[i] = key[(int)PC1_C[i]];
    D[i] = key[(int)PC1_D[i]];
  }
  /* To generate Ki, rotate C and D according to schedule and pick up a
   * permutation using PC2.
   */
  for(i=0; i < 16; i++) {
    /* rotate. */
    s = shifts[i];
    for(k=0; k < s; k++) {
      t = C[0];
      for(j=0; j < 27; j++)
	C[j] = C[j+1];
      C[27] = t;
      t = D[0];
      for(j=0; j < 27; j++)
	D[j] = D[j+1];
      D[27] = t;
    }
    /* get Ki. Note C and D are concatenated. */
    for(j=0; j < 24; j++) {
      KS[i][j] = C[(int)PC2_C[j]];
      KS[i][j+24] = D[(int)PC2_D[j]];
    }
  }

  for(i=0; i < 48; i++)
    E[i] = e2[i];
}

/* The 8 selection functions. For some reason, they give a 0-origin index,
 * unlike everything else.
 */
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

/* P is a permutation on the selected combination of the current L and key. */
static const char P[] = {
  15, 6,19,20, 28,11,27,16,  0,14,22,25,  4,17,30, 9,
   1, 7,23,13, 31,26, 2, 8, 18,12,29, 5, 21,10, 3,24
};

/* The current block, divided into 2 halves. */
static char L[64];
#define R (L+32)
static char tempL[32];
static char f[32];

/* The combination of the key and the input, before selection. */
static char preS[48];

/* The payoff: encrypt a block. */
void encrypt(char block[64],int edflag)
{
  int  i, ii;
  register int t, j, k;

  (void)edflag;
  /* First, permute the bits in the input */
  for(j=0; j < 64; j++)
    L[j] = block[(int)IP[j]];
  /* Perform an encryption operation 16 times. */
  for(ii=0; ii < 16; ii++) {
    i = ii;
    /* Save the R array, which will be the new L. */
    for(j=0; j < 32; j++)
      tempL[j] = R[j];
    /* Expand R to 48 bits using the E selector;
     * exclusive-or with the current key bits.
     */
    for(j=0; j < 48; j++)
      preS[j] = R[E[j]-1] ^ KS[i][j];
    /* The pre-select bits are now considered in 8 groups of 6 bits each.
     * The 8 selection functions map these 6-bit quantities into 4-bit
     * quantities and the results permuted to make an f(R, K).
     * The indexing into the selection functions is peculiar;
     * it could be simplified by rewriting the tables.
     */
    for(j=0; j < 8; j++) {
      t = ((j<<1)+j)<<1;
      k = S[j][(preS[t]<<5)+
	 (preS[t+1]<<3)+
	 (preS[t+2]<<2)+
	 (preS[t+3]<<1)+
	 (preS[t+4]   )+
	 (preS[t+5]<<4)];
      t = j << 2;
      f[t  ] = (k>>3)&01;
      f[t+1] = (k>>2)&01;
      f[t+2] = (k>>1)&01;
      f[t+3] = (k   )&01;
    }
    /* The new R is L ^ f(R, K). The f here has to be permuted first, though. */
    for(j=0; j < 32; j++)
      R[j] = L[j] ^ f[(int)P[j]];
    /* Finally, the new L (the original R) is copied back. */
    for(j=0; j < 32; j++)
      L[j] = tempL[j];
  }
  /* The output L and R are reversed. */
  for(j=0; j < 32; j++) {
    L[j] ^= R[j];
    R[j] ^= L[j];
    L[j] ^= R[j];
  }
  /* The final output gets the inverse permutation of the very original. */
  for(j=0; j < 64; j++)
    block[j] = L[(int)FP[j]];
}

char * crypt(const char *pw, const char *salt)
{
  register int i, j, c;
  static char block[66], iobuf[16];
#ifdef WANT_CRYPT_MD5
  if (salt[0]=='$' && salt[1]=='1' && salt[2]=='$')
    return md5crypt(pw,salt);
#endif
#ifdef WANT_CRYPT_SHA256
  if (salt[0]=='$' && salt[1]=='5' && salt[2]=='$')
    return sha256_crypt(pw,salt);
#endif
#ifdef WANT_CRYPT_SHA512
  if (salt[0]=='$' && salt[1]=='6' && salt[2]=='$')
    return sha512_crypt(pw,salt);
#endif
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
/*****************************************************************************
*
* "derived from the RSA Data Security, Inc. MD5 Message-Digest Algorithm".
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
* 
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*
*****************************************************************************/

#include <endian.h>
#include <md5.h>
#include <string.h>

#if (__BYTE_ORDER == __BIG_ENDIAN)
/*
   Block copy and convert byte order to little-endian.
   dst must be 32bit aligned.
   Length is the number of 32bit words 
*/   
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
#endif


/*
   Assembler versions of __MD5Transform, MD5Init and MD5Update
   currently exist for x86 and little-endian ARM.
   For other targets, we need to use the C versions below.
*/

#if !(defined (__i386__) || ((defined (__arm__) && (__BYTE_ORDER == __LITTLE_ENDIAN))))

/*
   Initialise the MD5 context.
*/
void MD5Init (MD5_CTX* context) {
   context->count[0] = 0;
   context->count[1] = 0;

   context->state[0] = 0x67452301;              /* Load magic constants. */
   context->state[1] = 0xefcdab89;
   context->state[2] = 0x98badcfe;
   context->state[3] = 0x10325476;
}

#define ROTATE_LEFT(x, n) ((x << n) | (x >> (32-n)))

#define F(x, y, z) (z ^ (x & (y ^ z)))
#define G(x, y, z) (y ^ (z & (x ^ y)))
#define H(x, y, z) (x ^ y ^ z)
#define I(x, y, z) (y ^ (x | ~z))

#define FF(a, b, c, d, x, s, ac) { (a) += F (b, c, d) + (x) + (uint32_t)(ac); (a) = ROTATE_LEFT (a, s); (a) += (b); }
#define GG(a, b, c, d, x, s, ac) { (a) += G (b, c, d) + (x) + (uint32_t)(ac); (a) = ROTATE_LEFT (a, s); (a) += (b); }
#define HH(a, b, c, d, x, s, ac) { (a) += H (b, c, d) + (x) + (uint32_t)(ac); (a) = ROTATE_LEFT (a, s); (a) += (b); }
#define II(a, b, c, d, x, s, ac) { (a) += I (b, c, d) + (x) + (uint32_t)(ac); (a) = ROTATE_LEFT (a, s); (a) += (b); }

static void __MD5Transform (uint32_t state[4], const uint8_t *in, int repeat) {
   const uint32_t *x;

   uint32_t  a = state[0];
   uint32_t  b = state[1];
   uint32_t  c = state[2];
   uint32_t  d = state[3];

   for ( ; repeat; repeat--) {
      uint32_t tempBuffer[16];
#if (__BYTE_ORDER == __BIG_ENDIAN)

      CopyToLittleEndian (tempBuffer, in, 16);
      x = tempBuffer;
#else
      if ((long)in & 3) {
	memcpy(tempBuffer, in, 64);
	x = tempBuffer;
      } else
	x = (const uint32_t *) in;
#endif

      FF (a, b, c, d, x[ 0],  7, 0xd76aa478); /*  1 */     /* Round 1 */
      FF (d, a, b, c, x[ 1], 12, 0xe8c7b756); /*  2 */
      FF (c, d, a, b, x[ 2], 17, 0x242070db); /*  3 */
      FF (b, c, d, a, x[ 3], 22, 0xc1bdceee); /*  4 */
      FF (a, b, c, d, x[ 4],  7, 0xf57c0faf); /*  5 */
      FF (d, a, b, c, x[ 5], 12, 0x4787c62a); /*  6 */
      FF (c, d, a, b, x[ 6], 17, 0xa8304613); /*  7 */
      FF (b, c, d, a, x[ 7], 22, 0xfd469501); /*  8 */
      FF (a, b, c, d, x[ 8],  7, 0x698098d8); /*  9 */
      FF (d, a, b, c, x[ 9], 12, 0x8b44f7af); /* 10 */
      FF (c, d, a, b, x[10], 17, 0xffff5bb1); /* 11 */
      FF (b, c, d, a, x[11], 22, 0x895cd7be); /* 12 */
      FF (a, b, c, d, x[12],  7, 0x6b901122); /* 13 */
      FF (d, a, b, c, x[13], 12, 0xfd987193); /* 14 */
      FF (c, d, a, b, x[14], 17, 0xa679438e); /* 15 */
      FF (b, c, d, a, x[15], 22, 0x49b40821); /* 16 */

      GG (a, b, c, d, x[ 1],  5, 0xf61e2562); /* 17 */     /* Round 2 */
      GG (d, a, b, c, x[ 6],  9, 0xc040b340); /* 18 */
      GG (c, d, a, b, x[11], 14, 0x265e5a51); /* 19 */
      GG (b, c, d, a, x[ 0], 20, 0xe9b6c7aa); /* 20 */
      GG (a, b, c, d, x[ 5],  5, 0xd62f105d); /* 21 */
      GG (d, a, b, c, x[10],  9, 0x02441453); /* 22 */
      GG (c, d, a, b, x[15], 14, 0xd8a1e681); /* 23 */
      GG (b, c, d, a, x[ 4], 20, 0xe7d3fbc8); /* 24 */
      GG (a, b, c, d, x[ 9],  5, 0x21e1cde6); /* 25 */
      GG (d, a, b, c, x[14],  9, 0xc33707d6); /* 26 */
      GG (c, d, a, b, x[ 3], 14, 0xf4d50d87); /* 27 */
      GG (b, c, d, a, x[ 8], 20, 0x455a14ed); /* 28 */
      GG (a, b, c, d, x[13],  5, 0xa9e3e905); /* 29 */
      GG (d, a, b, c, x[ 2],  9, 0xfcefa3f8); /* 30 */
      GG (c, d, a, b, x[ 7], 14, 0x676f02d9); /* 31 */
      GG (b, c, d, a, x[12], 20, 0x8d2a4c8a); /* 32 */

      HH (a, b, c, d, x[ 5],  4, 0xfffa3942); /* 33 */     /* Round 3 */
      HH (d, a, b, c, x[ 8], 11, 0x8771f681); /* 34 */
      HH (c, d, a, b, x[11], 16, 0x6d9d6122); /* 35 */
      HH (b, c, d, a, x[14], 23, 0xfde5380c); /* 36 */
      HH (a, b, c, d, x[ 1],  4, 0xa4beea44); /* 37 */
      HH (d, a, b, c, x[ 4], 11, 0x4bdecfa9); /* 38 */
      HH (c, d, a, b, x[ 7], 16, 0xf6bb4b60); /* 39 */
      HH (b, c, d, a, x[10], 23, 0xbebfbc70); /* 40 */
      HH (a, b, c, d, x[13],  4, 0x289b7ec6); /* 41 */
      HH (d, a, b, c, x[ 0], 11, 0xeaa127fa); /* 42 */
      HH (c, d, a, b, x[ 3], 16, 0xd4ef3085); /* 43 */
      HH (b, c, d, a, x[ 6], 23, 0x04881d05); /* 44 */
      HH (a, b, c, d, x[ 9],  4, 0xd9d4d039); /* 45 */
      HH (d, a, b, c, x[12], 11, 0xe6db99e5); /* 46 */
      HH (c, d, a, b, x[15], 16, 0x1fa27cf8); /* 47 */
      HH (b, c, d, a, x[ 2], 23, 0xc4ac5665); /* 48 */

      II (a, b, c, d, x[ 0],  6, 0xf4292244); /* 49 */     /* Round 4 */
      II (d, a, b, c, x[ 7], 10, 0x432aff97); /* 50 */
      II (c, d, a, b, x[14], 15, 0xab9423a7); /* 51 */
      II (b, c, d, a, x[ 5], 21, 0xfc93a039); /* 52 */
      II (a, b, c, d, x[12],  6, 0x655b59c3); /* 53 */
      II (d, a, b, c, x[ 3], 10, 0x8f0ccc92); /* 54 */
      II (c, d, a, b, x[10], 15, 0xffeff47d); /* 55 */
      II (b, c, d, a, x[ 1], 21, 0x85845dd1); /* 56 */
      II (a, b, c, d, x[ 8],  6, 0x6fa87e4f); /* 57 */
      II (d, a, b, c, x[15], 10, 0xfe2ce6e0); /* 58 */
      II (c, d, a, b, x[ 6], 15, 0xa3014314); /* 59 */
      II (b, c, d, a, x[13], 21, 0x4e0811a1); /* 60 */
      II (a, b, c, d, x[ 4],  6, 0xf7537e82); /* 61 */
      II (d, a, b, c, x[11], 10, 0xbd3af235); /* 62 */
      II (c, d, a, b, x[ 2], 15, 0x2ad7d2bb); /* 63 */
      II (b, c, d, a, x[ 9], 21, 0xeb86d391); /* 64 */

      state[0] = a = a + state[0];
      state[1] = b = b + state[1];
      state[2] = c = c + state[2];
      state[3] = d = d + state[3];

      in += 64;
   }
}


/*
   MD5 block update operation:
   Process another sub-string of the message and update the context.
*/
void MD5Update (MD5_CTX *context, const uint8_t *input, size_t inputBytes) {
   int i;
   int byteIndex;
   unsigned int partLen;
   int len;

   /* Compute number of bytes mod 64 */
   byteIndex = (context->count[0] >> 3) & 0x3F;

   /* Update number of bits: count += 8 * inputBytes */
   if ((context->count[0] += inputBytes << 3) < (inputBytes << 3))
      context->count[1]++;
   context->count[1] += (inputBytes >> (32-3));

   partLen = (64 - byteIndex);

   /* Transform as many times as possible. */
   if (inputBytes >= partLen) {
      memcpy (context->buffer + byteIndex, input, partLen);
      __MD5Transform (context->state, (const uint8_t *) context->buffer, 1);
      len = (inputBytes - partLen) / 64;
      __MD5Transform (context->state, &input[partLen], len);
      i = partLen + 64 * len;
      byteIndex = 0;
   } else
      i = 0;

   /* Buffer remaining input */
   memcpy (&context->buffer[byteIndex], &input[i], inputBytes - i);
}

#endif


void MD5Final (uint8_t digest[16], MD5_CTX* context) {
   static uint8_t finalBlock[64];

   uint32_t bits[2];
   int      byteIndex;
   int      finalBlockLength;

   byteIndex = (context->count[0] >> 3) & 0x3F;
   finalBlockLength = ((byteIndex < 56) ? 56 : 120) - byteIndex;
   finalBlock[0] = 0x80;

#if (__BYTE_ORDER == __BIG_ENDIAN)
   CopyToLittleEndian (bits, (const uint8_t *) context->count, 2);
#else
   memcpy(bits, context->count, 8);
#endif

   MD5Update (context, finalBlock, finalBlockLength);
   MD5Update (context, (const uint8_t *) bits, 8);

#if (__BYTE_ORDER == __BIG_ENDIAN)
   CopyToLittleEndian ((uint32_t *) digest, (const uint8_t *) context->state, 4);
#else
   memcpy (digest, context->state, 16);
#endif

   memset(context, 0, sizeof(*context));
}

/*	$OpenBSD: md5crypt.c,v 1.9 1997/07/23 20:58:27 kstailey Exp $	*/

/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <phk@login.dknet.dk> wrote this file.  As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return.   Poul-Henning Kamp
 * ----------------------------------------------------------------------------
 *
 * $FreeBSD: crypt.c,v 1.5 1996/10/14 08:34:02 phk Exp $
 *
 */

#if defined(LIBC_SCCS) && !defined(lint)
static char rcsid[] = "$OpenBSD: md5crypt.c,v 1.9 1997/07/23 20:58:27 kstailey Exp $";
#endif /* LIBC_SCCS and not lint */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <md5.h>

static unsigned char itoa64[] =		/* 0 ... 63 => ascii - 64 */
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

/*
 * UNIX password
 *
 * Use MD5 for what it is best at...
 */

char *
md5crypt(pw, salt)
	register const char *pw;
	register const char *salt;
{
	/*
	 * This string is magic for this algorithm.  Having
	 * it this way, we can get get better later on
	 */
	static unsigned char	*magic = (unsigned char *)"$1$";

	static char     passwd[120], *p;
	static const unsigned char *sp,*ep;
	unsigned char	final[16];
	int sl,pl,i;
	MD5_CTX	ctx,ctx1;
	uint32_t l;

	/* Refine the Salt first */
	sp = (const unsigned char *)salt;

	/* If it starts with the magic string, then skip that */
	if(!strncmp((const char *)sp,(const char *)magic,strlen((const char *)magic)))
		sp += strlen((const char *)magic);

	/* It stops at the first '$', max 8 chars */
	for(ep=sp;*ep && *ep != '$' && ep < (sp+8);ep++)
		continue;

	/* get the length of the true salt */
	sl = ep - sp;

	MD5Init(&ctx);

	/* The password first, since that is what is most unknown */
	MD5Update(&ctx,(const unsigned char *)pw,strlen(pw));

	/* Then our magic string */
	MD5Update(&ctx,magic,strlen((const char *)magic));

	/* Then the raw salt */
	MD5Update(&ctx,sp,sl);

	/* Then just as many characters of the MD5(pw,salt,pw) */
	MD5Init(&ctx1);
	MD5Update(&ctx1,(const unsigned char *)pw,strlen(pw));
	MD5Update(&ctx1,sp,sl);
	MD5Update(&ctx1,(const unsigned char *)pw,strlen(pw));
	MD5Final(final,&ctx1);
	for(pl = strlen(pw); pl > 0; pl -= 16)
		MD5Update(&ctx,final,pl>16 ? 16 : pl);

	/* Don't leave anything around in vm they could use. */
	memset(final,0,sizeof final);

	/* Then something really weird... */
	for (i = strlen(pw); i ; i >>= 1)
		if(i&1)
		    MD5Update(&ctx, final, 1);
		else
		    MD5Update(&ctx, (const unsigned char *)pw, 1);

	/* Now make the output string */
	strcpy(passwd,(const char *)magic);
	memcpy(passwd+3,sp,sl);
	passwd[sl+3]='$';
	passwd[sl+4]=0;

	MD5Final(final,&ctx);

	/*
	 * and now, just to make sure things don't run too fast
	 * On a 60 Mhz Pentium this takes 34 msec, so you would
	 * need 30 seconds to build a 1000 entry dictionary...
	 */
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
	l =		       final[11]		; to64(p,l,2); p += 2;
	*p = '\0';

	/* Don't leave anything around in vm they could use. */
	memset(final,0,sizeof final);

	return passwd;
}

/* SHA256-based Unix crypt implementation.
   Released into the Public Domain by Ulrich Drepper <drepper@redhat.com>.  */

#define _GNU_SOURCE

#include <endian.h>
#include <errno.h>
#include <limits.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/param.h>
#include <sys/types.h>
#include <unistd.h>


/* Structure to save state of computation between the single steps.  */
struct sha256_ctx
{
  uint32_t H[8];

  uint32_t total[2];
  uint32_t buflen;
  char buffer[128];	/* NB: always correctly aligned for uint32_t.  */
};


#if __BYTE_ORDER == __LITTLE_ENDIAN
# define SWAP(n) \
    (((n) << 24) | (((n) & 0xff00) << 8) | (((n) >> 8) & 0xff00) | ((n) >> 24))
#else
# define SWAP(n) (n)
#endif


/* This array contains the bytes used to pad the buffer to the next
   64-byte boundary.  (FIPS 180-2:5.1.1)  */
static const unsigned char fillbuf[64] = { 0x80, 0 /* , 0, 0, ...  */ };


/* Constants for SHA256 from FIPS 180-2:4.2.2.  */
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


/* Process LEN bytes of BUFFER, accumulating context into CTX.
   It is assumed that LEN % 64 == 0.  */
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

  /* First increment the byte count.  FIPS 180-2 specifies the possible
     length of the file up to 2^64 bits.  Here we only compute the
     number of bytes.  Do a double word increment.  */
  ctx->total[0] += len;
  if (ctx->total[0] < len)
    ++ctx->total[1];

  /* Process all bytes in the buffer with 64 bytes in each round of
     the loop.  */
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

      /* Operators defined in FIPS 180-2:4.1.2.  */
#define Ch(x, y, z) ((x & y) ^ (~x & z))
#define Maj(x, y, z) ((x & y) ^ (x & z) ^ (y & z))
#define S0(x) (CYCLIC (x, 2) ^ CYCLIC (x, 13) ^ CYCLIC (x, 22))
#define S1(x) (CYCLIC (x, 6) ^ CYCLIC (x, 11) ^ CYCLIC (x, 25))
#define R0(x) (CYCLIC (x, 7) ^ CYCLIC (x, 18) ^ (x >> 3))
#define R1(x) (CYCLIC (x, 17) ^ CYCLIC (x, 19) ^ (x >> 10))

      /* It is unfortunate that C does not provide an operator for
	 cyclic rotation.  Hope the C compiler is smart enough.  */
#define CYCLIC(w, s) ((w >> s) | (w << (32 - s)))

      /* Compute the message schedule according to FIPS 180-2:6.2.2 step 2.  */
      for (t = 0; t < 16; ++t)
	{
	  W[t] = SWAP (*words);
	  ++words;
	}
      for (t = 16; t < 64; ++t)
	W[t] = R1 (W[t - 2]) + W[t - 7] + R0 (W[t - 15]) + W[t - 16];

      /* The actual computation according to FIPS 180-2:6.2.2 step 3.  */
      for (t = 0; t < 64; ++t)
	{
	  uint32_t T1 = h + S1 (e) + Ch (e, f, g) + K[t] + W[t];
	  uint32_t T2 = S0 (a) + Maj (a, b, c);
	  h = g;
	  g = f;
	  f = e;
	  e = d + T1;
	  d = c;
	  c = b;
	  b = a;
	  a = T1 + T2;
	}

      /* Add the starting values of the context according to FIPS 180-2:6.2.2
	 step 4.  */
      a += a_save;
      b += b_save;
      c += c_save;
      d += d_save;
      e += e_save;
      f += f_save;
      g += g_save;
      h += h_save;

      /* Prepare for the next round.  */
      nwords -= 16;
    }

  /* Put checksum in context given as argument.  */
  ctx->H[0] = a;
  ctx->H[1] = b;
  ctx->H[2] = c;
  ctx->H[3] = d;
  ctx->H[4] = e;
  ctx->H[5] = f;
  ctx->H[6] = g;
  ctx->H[7] = h;
}


/* Initialize structure containing state of computation.
   (FIPS 180-2:5.3.2)  */
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


/* Process the remaining bytes in the internal buffer and the usual
   prolog according to the standard and write the result to RESBUF.

   IMPORTANT: On some systems it is required that RESBUF is correctly
   aligned for a 32 bits value.  */
static void *
sha256_finish_ctx (struct sha256_ctx *ctx, void *resbuf)
{
  /* Take yet unprocessed bytes into account.  */
  uint32_t bytes = ctx->buflen;
  size_t pad;
  unsigned int i;

  /* Now count remaining bytes.  */
  ctx->total[0] += bytes;
  if (ctx->total[0] < bytes)
    ++ctx->total[1];

  pad = bytes >= 56 ? 64 + 56 - bytes : 56 - bytes;
  memcpy (&ctx->buffer[bytes], fillbuf, pad);

  /* Put the 64-bit file length in *bits* at the end of the buffer.  */
  *(uint32_t *) &ctx->buffer[bytes + pad + 4] = SWAP (ctx->total[0] << 3);
  *(uint32_t *) &ctx->buffer[bytes + pad] = SWAP ((ctx->total[1] << 3) |
						  (ctx->total[0] >> 29));

  /* Process last bytes.  */
  sha256_process_block (ctx->buffer, bytes + pad + 8, ctx);

  /* Put result from CTX in first 32 bytes following RESBUF.  */
  for (i = 0; i < 8; ++i)
    ((uint32_t *) resbuf)[i] = SWAP (ctx->H[i]);

  return resbuf;
}


static void
sha256_process_bytes (const void *buffer, size_t len, struct sha256_ctx *ctx)
{
  /* When we already have some bits in our internal buffer concatenate
     both inputs first.  */
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
	  /* The regions in the following copy operation cannot overlap.  */
	  memcpy (ctx->buffer, &ctx->buffer[(left_over + add) & ~63],
		  ctx->buflen);
	}

      buffer = (const char *) buffer + add;
      len -= add;
    }

  /* Process available complete blocks.  */
  if (len >= 64)
    {
/* To check alignment gcc has an appropriate operator.  Other
   compilers don't.  */
#if __GNUC__ >= 2
# define UNALIGNED_P(p) (((uintptr_t) p) % __alignof__ (uint32_t) != 0)
#else
# define UNALIGNED_P(p) (((uintptr_t) p) % sizeof (uint32_t) != 0)
#endif
      if (UNALIGNED_P (buffer))
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

  /* Move remaining bytes into internal buffer.  */
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


/* Define our magic string to mark salt for SHA256 "encryption"
   replacement.  */
static const char sha256_salt_prefix[] = "$5$";

/* Prefix for optional rounds specification.  */
static const char sha256_rounds_prefix[] = "rounds=";

/* Maximum salt string length.  */
#define SALT_LEN_MAX 16
/* Default number of rounds if not explicitly specified.  */
#define ROUNDS_DEFAULT 5000
/* Minimum number of rounds.  */
#define ROUNDS_MIN 1000
/* Maximum number of rounds.  */
#define ROUNDS_MAX 999999999

/* Table with characters for base64 transformation.  */
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
  char *copied_key = NULL;
  char *copied_salt = NULL;
  char *p_bytes;
  char *s_bytes;
  /* Default number of rounds.  */
  size_t rounds = ROUNDS_DEFAULT;
  bool rounds_custom = false;

  /* Find beginning of salt string.  The prefix should normally always
     be present.  Just in case it is not.  */
  if (strncmp (sha256_salt_prefix, salt, sizeof (sha256_salt_prefix) - 1) == 0)
    /* Skip salt prefix.  */
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
	  rounds = MAX (ROUNDS_MIN, MIN (srounds, ROUNDS_MAX));
	  rounds_custom = true;
	}
    }

  salt_len = MIN (strcspn (salt, "$"), SALT_LEN_MAX);
  key_len = strlen (key);

  if ((key - (char *) 0) % __alignof__ (uint32_t) != 0)
    {
      char *tmp = (char *) alloca (key_len + __alignof__ (uint32_t));
      key = copied_key =
	memcpy (tmp + __alignof__ (uint32_t)
		- (tmp - (char *) 0) % __alignof__ (uint32_t),
		key, key_len);
    }

  if ((salt - (char *) 0) % __alignof__ (uint32_t) != 0)
    {
      char *tmp = (char *) alloca (salt_len + __alignof__ (uint32_t));
      salt = copied_salt =
	memcpy (tmp + __alignof__ (uint32_t)
		- (tmp - (char *) 0) % __alignof__ (uint32_t),
		salt, salt_len);
    }

  /* Prepare for the real work.  */
  sha256_init_ctx (&ctx);

  /* Add the key string.  */
  sha256_process_bytes (key, key_len, &ctx);

  /* The last part is the salt string.  This must be at most 16
     characters and it ends at the first `$' character (for
     compatibility with existing implementations).  */
  sha256_process_bytes (salt, salt_len, &ctx);


  /* Compute alternate SHA256 sum with input KEY, SALT, and KEY.  The
     final result will be added to the first context.  */
  sha256_init_ctx (&alt_ctx);

  /* Add key.  */
  sha256_process_bytes (key, key_len, &alt_ctx);

  /* Add salt.  */
  sha256_process_bytes (salt, salt_len, &alt_ctx);

  /* Add key again.  */
  sha256_process_bytes (key, key_len, &alt_ctx);

  /* Now get result of this (32 bytes) and add it to the other
     context.  */
  sha256_finish_ctx (&alt_ctx, alt_result);

  /* Add for any character in the key one byte of the alternate sum.  */
  for (cnt = key_len; cnt > 32; cnt -= 32)
    sha256_process_bytes (alt_result, 32, &ctx);
  sha256_process_bytes (alt_result, cnt, &ctx);

  /* Take the binary representation of the length of the key and for every
     1 add the alternate sum, for every 0 the key.  */
  for (cnt = key_len; cnt > 0; cnt >>= 1)
    if ((cnt & 1) != 0)
      sha256_process_bytes (alt_result, 32, &ctx);
    else
      sha256_process_bytes (key, key_len, &ctx);

  /* Create intermediate result.  */
  sha256_finish_ctx (&ctx, alt_result);

  /* Start computation of P byte sequence.  */
  sha256_init_ctx (&alt_ctx);

  /* For every character in the password add the entire password.  */
  for (cnt = 0; cnt < key_len; ++cnt)
    sha256_process_bytes (key, key_len, &alt_ctx);

  /* Finish the digest.  */
  sha256_finish_ctx (&alt_ctx, temp_result);

  /* Create byte sequence P.  */
  cp = p_bytes = alloca (key_len);
  for (cnt = key_len; cnt >= 32; cnt -= 32)
    cp = memcpy (cp, temp_result, 32) + 32;
  memcpy (cp, temp_result, cnt);

  /* Start computation of S byte sequence.  */
  sha256_init_ctx (&alt_ctx);

  /* For every character in the password add the entire password.  */
  for (cnt = 0; cnt < 16u + alt_result[0]; ++cnt)
    sha256_process_bytes (salt, salt_len, &alt_ctx);

  /* Finish the digest.  */
  sha256_finish_ctx (&alt_ctx, temp_result);

  /* Create byte sequence S.  */
  cp = s_bytes = alloca (salt_len);
  for (cnt = salt_len; cnt >= 32; cnt -= 32)
    cp = memcpy (cp, temp_result, 32) + 32;
  memcpy (cp, temp_result, cnt);

  /* Repeatedly run the collected hash value through SHA256 to burn
     CPU cycles.  */
  for (cnt = 0; cnt < rounds; ++cnt)
    {
      /* New context.  */
      sha256_init_ctx (&ctx);

      /* Add key or last result.  */
      if ((cnt & 1) != 0)
	sha256_process_bytes (p_bytes, key_len, &ctx);
      else
	sha256_process_bytes (alt_result, 32, &ctx);

      /* Add salt for numbers not divisible by 3.  */
      if (cnt % 3 != 0)
	sha256_process_bytes (s_bytes, salt_len, &ctx);

      /* Add key for numbers not divisible by 7.  */
      if (cnt % 7 != 0)
	sha256_process_bytes (p_bytes, key_len, &ctx);

      /* Add key or last result.  */
      if ((cnt & 1) != 0)
	sha256_process_bytes (alt_result, 32, &ctx);
      else
	sha256_process_bytes (p_bytes, key_len, &ctx);

      /* Create intermediate result.  */
      sha256_finish_ctx (&ctx, alt_result);
    }

  /* Now we can construct the result string.  It consists of three
     parts.  */
  cp = stpncpy (buffer, sha256_salt_prefix, MAX (0, buflen));
  buflen -= sizeof (sha256_salt_prefix) - 1;

  if (rounds_custom)
    {
      int n = snprintf (cp, MAX (0, buflen), "%s%zu$",
			sha256_rounds_prefix, rounds);
      cp += n;
      buflen -= n;
    }

  cp = stpncpy (cp, salt, MIN ((size_t) MAX (0, buflen), salt_len));
  buflen -= MIN ((size_t) MAX (0, buflen), salt_len);

  if (buflen > 0)
    {
      *cp++ = '$';
      --buflen;
    }

#define b64_from_24bit(B2, B1, B0, N)					      \
  do {									      \
    unsigned int w = ((B2) << 16) | ((B1) << 8) | (B0);			      \
    int n = (N);							      \
    while (n-- > 0 && buflen > 0)					      \
      {									      \
	*cp++ = b64t[w & 0x3f];						      \
	--buflen;							      \
	w >>= 6;							      \
      }									      \
  } while (0)

  b64_from_24bit (alt_result[0], alt_result[10], alt_result[20], 4);
  b64_from_24bit (alt_result[21], alt_result[1], alt_result[11], 4);
  b64_from_24bit (alt_result[12], alt_result[22], alt_result[2], 4);
  b64_from_24bit (alt_result[3], alt_result[13], alt_result[23], 4);
  b64_from_24bit (alt_result[24], alt_result[4], alt_result[14], 4);
  b64_from_24bit (alt_result[15], alt_result[25], alt_result[5], 4);
  b64_from_24bit (alt_result[6], alt_result[16], alt_result[26], 4);
  b64_from_24bit (alt_result[27], alt_result[7], alt_result[17], 4);
  b64_from_24bit (alt_result[18], alt_result[28], alt_result[8], 4);
  b64_from_24bit (alt_result[9], alt_result[19], alt_result[29], 4);
  b64_from_24bit (0, alt_result[31], alt_result[30], 3);
  if (buflen <= 0)
    {
      errno = ERANGE;
      buffer = NULL;
    }
  else
    *cp = '\0';		/* Terminate the string.  */

  /* Clear the buffer for the intermediate result so that people
     attaching to processes or reading core dumps cannot get any
     information.  We do it in this way to clear correct_words[]
     inside the SHA256 implementation as well.  */
  sha256_init_ctx (&ctx);
  sha256_finish_ctx (&ctx, alt_result);
  memset (temp_result, '\0', sizeof (temp_result));
  memset (p_bytes, '\0', key_len);
  memset (s_bytes, '\0', salt_len);
  memset (&ctx, '\0', sizeof (ctx));
  memset (&alt_ctx, '\0', sizeof (alt_ctx));
  if (copied_key != NULL)
    memset (copied_key, '\0', key_len);
  if (copied_salt != NULL)
    memset (copied_salt, '\0', salt_len);

  return buffer;
}


/* This entry point is equivalent to the `crypt' function in Unix
   libcs.  */
char *
sha256_crypt (const char *key, const char *salt)
{
  /* We don't want to have an arbitrary limit in the size of the
     password.  We can compute an upper bound for the size of the
     result in advance and so we can prepare the buffer we pass to
     `sha256_crypt_r'.  */
  static char *buffer;
  static int buflen;
  int needed = (sizeof (sha256_salt_prefix) - 1
		+ sizeof (sha256_rounds_prefix) + 9 + 1
		+ strlen (salt) + 1 + 43 + 1);

  if (buflen < needed)
    {
      char *new_buffer = (char *) realloc (buffer, needed);
      if (new_buffer == NULL)
	return NULL;

      buffer = new_buffer;
      buflen = needed;
    }

  return sha256_crypt_r (key, salt, buffer, buflen);
}


#ifdef UNITTEST
static const struct
{
  const char *input;
  const char result[32];
} tests[] =
  {
    /* Test vectors from FIPS 180-2: appendix B.1.  */
    { "abc",
      "\xba\x78\x16\xbf\x8f\x01\xcf\xea\x41\x41\x40\xde\x5d\xae\x22\x23"
      "\xb0\x03\x61\xa3\x96\x17\x7a\x9c\xb4\x10\xff\x61\xf2\x00\x15\xad" },
    /* Test vectors from FIPS 180-2: appendix B.2.  */
    { "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq",
      "\x24\x8d\x6a\x61\xd2\x06\x38\xb8\xe5\xc0\x26\x93\x0c\x3e\x60\x39"
      "\xa3\x3c\xe4\x59\x64\xff\x21\x67\xf6\xec\xed\xd4\x19\xdb\x06\xc1" },
    /* Test vectors from the NESSIE project.  */
    { "",
      "\xe3\xb0\xc4\x42\x98\xfc\x1c\x14\x9a\xfb\xf4\xc8\x99\x6f\xb9\x24"
      "\x27\xae\x41\xe4\x64\x9b\x93\x4c\xa4\x95\x99\x1b\x78\x52\xb8\x55" },
    { "a",
      "\xca\x97\x81\x12\xca\x1b\xbd\xca\xfa\xc2\x31\xb3\x9a\x23\xdc\x4d"
      "\xa7\x86\xef\xf8\x14\x7c\x4e\x72\xb9\x80\x77\x85\xaf\xee\x48\xbb" },
    { "message digest",
      "\xf7\x84\x6f\x55\xcf\x23\xe1\x4e\xeb\xea\xb5\xb4\xe1\x55\x0c\xad"
      "\x5b\x50\x9e\x33\x48\xfb\xc4\xef\xa3\xa1\x41\x3d\x39\x3c\xb6\x50" },
    { "abcdefghijklmnopqrstuvwxyz",
      "\x71\xc4\x80\xdf\x93\xd6\xae\x2f\x1e\xfa\xd1\x44\x7c\x66\xc9\x52"
      "\x5e\x31\x62\x18\xcf\x51\xfc\x8d\x9e\xd8\x32\xf2\xda\xf1\x8b\x73" },
    { "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq",
      "\x24\x8d\x6a\x61\xd2\x06\x38\xb8\xe5\xc0\x26\x93\x0c\x3e\x60\x39"
      "\xa3\x3c\xe4\x59\x64\xff\x21\x67\xf6\xec\xed\xd4\x19\xdb\x06\xc1" },
    { "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789",
      "\xdb\x4b\xfc\xbd\x4d\xa0\xcd\x85\xa6\x0c\x3c\x37\xd3\xfb\xd8\x80"
      "\x5c\x77\xf1\x5f\xc6\xb1\xfd\xfe\x61\x4e\xe0\xa7\xc8\xfd\xb4\xc0" },
    { "123456789012345678901234567890123456789012345678901234567890"
      "12345678901234567890",
      "\xf3\x71\xbc\x4a\x31\x1f\x2b\x00\x9e\xef\x95\x2d\xd8\x3c\xa8\x0e"
      "\x2b\x60\x02\x6c\x8e\x93\x55\x92\xd0\xf9\xc3\x08\x45\x3c\x81\x3e" }
  };
#define ntests (sizeof (tests) / sizeof (tests[0]))


static const struct
{
  const char *salt;
  const char *input;
  const char *expected;
} tests2[] =
{
  { "$5$saltstring", "Hello world!",
    "$5$saltstring$5B8vYYiY.CVt1RlTTf8KbXBH3hsxY/GNooZaBBGWEc5" },
  { "$5$rounds=10000$saltstringsaltstring", "Hello world!",
    "$5$rounds=10000$saltstringsaltst$3xv.VbSHBb41AL9AvLeujZkZRBAwqFMz2."
    "opqey6IcA" },
  { "$5$rounds=5000$toolongsaltstring", "This is just a test",
    "$5$rounds=5000$toolongsaltstrin$Un/5jzAHMgOGZ5.mWJpuVolil07guHPvOW8"
    "mGRcvxa5" },
  { "$5$rounds=1400$anotherlongsaltstring",
    "a very much longer text to encrypt.  This one even stretches over more"
    "than one line.",
    "$5$rounds=1400$anotherlongsalts$Rx.j8H.h8HjEDGomFU8bDkXm3XIUnzyxf12"
    "oP84Bnq1" },
  { "$5$rounds=77777$short",
    "we have a short salt string but not a short password",
    "$5$rounds=77777$short$JiO1O3ZpDAxGJeaDIuqCoEFysAe1mZNJRs3pw0KQRd/" },
  { "$5$rounds=123456$asaltof16chars..", "a short string",
    "$5$rounds=123456$asaltof16chars..$gP3VQ/6X7UUEW3HkBn2w1/Ptq2jxPyzV/"
    "cZKmF/wJvD" },
  { "$5$rounds=10$roundstoolow", "the minimum number is still observed",
    "$5$rounds=1000$roundstoolow$yfvwcWrQ8l/K0DAWyuPMDNHpIVlTQebY9l/gL97"
    "2bIC" },
};
#define ntests2 (sizeof (tests2) / sizeof (tests2[0]))


int
main (void)
{
  struct sha256_ctx ctx;
  char sum[32];
  int result = 0;
  int cnt;
  int i;

  for (cnt = 0; cnt < (int) ntests; ++cnt)
    {
      sha256_init_ctx (&ctx);
      sha256_process_bytes (tests[cnt].input, strlen (tests[cnt].input), &ctx);
      sha256_finish_ctx (&ctx, sum);
      if (memcmp (tests[cnt].result, sum, 32) != 0)
	{
	  printf ("test %d run %d failed\n", cnt, 1);
	  result = 1;
	}

      sha256_init_ctx (&ctx);
      for (i = 0; tests[cnt].input[i] != '\0'; ++i)
	sha256_process_bytes (&tests[cnt].input[i], 1, &ctx);
      sha256_finish_ctx (&ctx, sum);
      if (memcmp (tests[cnt].result, sum, 32) != 0)
	{
	  printf ("test %d run %d failed\n", cnt, 2);
	  result = 1;
	}
    }

  /* Test vector from FIPS 180-2: appendix B.3.  */
  char buf[1000];
  memset (buf, 'a', sizeof (buf));
  sha256_init_ctx (&ctx);
  for (i = 0; i < 1000; ++i)
    sha256_process_bytes (buf, sizeof (buf), &ctx);
  sha256_finish_ctx (&ctx, sum);
  static const char expected[32] =
    "\xcd\xc7\x6e\x5c\x99\x14\xfb\x92\x81\xa1\xc7\xe2\x84\xd7\x3e\x67"
    "\xf1\x80\x9a\x48\xa4\x97\x20\x0e\x04\x6d\x39\xcc\xc7\x11\x2c\xd0";
  if (memcmp (expected, sum, 32) != 0)
    {
      printf ("test %d failed\n", cnt);
      result = 1;
    }

  for (cnt = 0; cnt < ntests2; ++cnt)
    {
      char *cp = sha256_crypt (tests2[cnt].input, tests2[cnt].salt);

      if (strcmp (cp, tests2[cnt].expected) != 0)
	{
	  printf ("test %d: expected \"%s\", got \"%s\"\n",
		  cnt, tests2[cnt].expected, cp);
	  result = 1;
	}
    }

  if (result == 0)
    puts ("all tests OK");

  return result;
}
#endif
/* SHA512-based Unix crypt implementation.
   Released into the Public Domain by Ulrich Drepper <drepper@redhat.com>.  */

#define _GNU_SOURCE
#include <endian.h>
#include <errno.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/param.h>
#include <sys/types.h>
#include <unistd.h>

/* Structure to save state of computation between the single steps.  */
struct sha512_ctx
{
  uint64_t H[8];

  uint64_t total[2];
  uint64_t buflen;
  char buffer[256];	/* NB: always correctly aligned for uint64_t.  */
};


#if __BYTE_ORDER == __LITTLE_ENDIAN
# define SWAP(n) \
  (((n) << 56)					\
   | (((n) & 0xff00) << 40)			\
   | (((n) & 0xff0000) << 24)			\
   | (((n) & 0xff000000) << 8)			\
   | (((n) >> 8) & 0xff000000)			\
   | (((n) >> 24) & 0xff0000)			\
   | (((n) >> 40) & 0xff00)			\
   | ((n) >> 56))
#else
# define SWAP(n) (n)
#endif


/* This array contains the bytes used to pad the buffer to the next
   64-byte boundary.  (FIPS 180-2:5.1.2)  */
static const unsigned char fillbuf[128] = { 0x80, 0 /* , 0, 0, ...  */ };


/* Constants for SHA512 from FIPS 180-2:4.2.3.  */
static const uint64_t K[80] =
  {
    UINT64_C (0x428a2f98d728ae22), UINT64_C (0x7137449123ef65cd),
    UINT64_C (0xb5c0fbcfec4d3b2f), UINT64_C (0xe9b5dba58189dbbc),
    UINT64_C (0x3956c25bf348b538), UINT64_C (0x59f111f1b605d019),
    UINT64_C (0x923f82a4af194f9b), UINT64_C (0xab1c5ed5da6d8118),
    UINT64_C (0xd807aa98a3030242), UINT64_C (0x12835b0145706fbe),
    UINT64_C (0x243185be4ee4b28c), UINT64_C (0x550c7dc3d5ffb4e2),
    UINT64_C (0x72be5d74f27b896f), UINT64_C (0x80deb1fe3b1696b1),
    UINT64_C (0x9bdc06a725c71235), UINT64_C (0xc19bf174cf692694),
    UINT64_C (0xe49b69c19ef14ad2), UINT64_C (0xefbe4786384f25e3),
    UINT64_C (0x0fc19dc68b8cd5b5), UINT64_C (0x240ca1cc77ac9c65),
    UINT64_C (0x2de92c6f592b0275), UINT64_C (0x4a7484aa6ea6e483),
    UINT64_C (0x5cb0a9dcbd41fbd4), UINT64_C (0x76f988da831153b5),
    UINT64_C (0x983e5152ee66dfab), UINT64_C (0xa831c66d2db43210),
    UINT64_C (0xb00327c898fb213f), UINT64_C (0xbf597fc7beef0ee4),
    UINT64_C (0xc6e00bf33da88fc2), UINT64_C (0xd5a79147930aa725),
    UINT64_C (0x06ca6351e003826f), UINT64_C (0x142929670a0e6e70),
    UINT64_C (0x27b70a8546d22ffc), UINT64_C (0x2e1b21385c26c926),
    UINT64_C (0x4d2c6dfc5ac42aed), UINT64_C (0x53380d139d95b3df),
    UINT64_C (0x650a73548baf63de), UINT64_C (0x766a0abb3c77b2a8),
    UINT64_C (0x81c2c92e47edaee6), UINT64_C (0x92722c851482353b),
    UINT64_C (0xa2bfe8a14cf10364), UINT64_C (0xa81a664bbc423001),
    UINT64_C (0xc24b8b70d0f89791), UINT64_C (0xc76c51a30654be30),
    UINT64_C (0xd192e819d6ef5218), UINT64_C (0xd69906245565a910),
    UINT64_C (0xf40e35855771202a), UINT64_C (0x106aa07032bbd1b8),
    UINT64_C (0x19a4c116b8d2d0c8), UINT64_C (0x1e376c085141ab53),
    UINT64_C (0x2748774cdf8eeb99), UINT64_C (0x34b0bcb5e19b48a8),
    UINT64_C (0x391c0cb3c5c95a63), UINT64_C (0x4ed8aa4ae3418acb),
    UINT64_C (0x5b9cca4f7763e373), UINT64_C (0x682e6ff3d6b2b8a3),
    UINT64_C (0x748f82ee5defb2fc), UINT64_C (0x78a5636f43172f60),
    UINT64_C (0x84c87814a1f0ab72), UINT64_C (0x8cc702081a6439ec),
    UINT64_C (0x90befffa23631e28), UINT64_C (0xa4506cebde82bde9),
    UINT64_C (0xbef9a3f7b2c67915), UINT64_C (0xc67178f2e372532b),
    UINT64_C (0xca273eceea26619c), UINT64_C (0xd186b8c721c0c207),
    UINT64_C (0xeada7dd6cde0eb1e), UINT64_C (0xf57d4f7fee6ed178),
    UINT64_C (0x06f067aa72176fba), UINT64_C (0x0a637dc5a2c898a6),
    UINT64_C (0x113f9804bef90dae), UINT64_C (0x1b710b35131c471b),
    UINT64_C (0x28db77f523047d84), UINT64_C (0x32caab7b40c72493),
    UINT64_C (0x3c9ebe0a15c9bebc), UINT64_C (0x431d67c49c100d4c),
    UINT64_C (0x4cc5d4becb3e42b6), UINT64_C (0x597f299cfc657e2a),
    UINT64_C (0x5fcb6fab3ad6faec), UINT64_C (0x6c44198c4a475817)
  };


/* Process LEN bytes of BUFFER, accumulating context into CTX.
   It is assumed that LEN % 128 == 0.  */
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

  /* First increment the byte count.  FIPS 180-2 specifies the possible
     length of the file up to 2^128 bits.  Here we only compute the
     number of bytes.  Do a double word increment.  */
  ctx->total[0] += len;
  if (ctx->total[0] < len)
    ++ctx->total[1];

  /* Process all bytes in the buffer with 128 bytes in each round of
     the loop.  */
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

      /* Operators defined in FIPS 180-2:4.1.2.  */
#define Ch(x, y, z) ((x & y) ^ (~x & z))
#define Maj(x, y, z) ((x & y) ^ (x & z) ^ (y & z))
#define S0(x) (CYCLIC (x, 28) ^ CYCLIC (x, 34) ^ CYCLIC (x, 39))
#define S1(x) (CYCLIC (x, 14) ^ CYCLIC (x, 18) ^ CYCLIC (x, 41))
#define R0(x) (CYCLIC (x, 1) ^ CYCLIC (x, 8) ^ (x >> 7))
#define R1(x) (CYCLIC (x, 19) ^ CYCLIC (x, 61) ^ (x >> 6))

      /* It is unfortunate that C does not provide an operator for
	 cyclic rotation.  Hope the C compiler is smart enough.  */
#define CYCLIC(w, s) ((w >> s) | (w << (64 - s)))

      /* Compute the message schedule according to FIPS 180-2:6.3.2 step 2.  */
      for (t = 0; t < 16; ++t)
	{
	  W[t] = SWAP (*words);
	  ++words;
	}
      for (t = 16; t < 80; ++t)
	W[t] = R1 (W[t - 2]) + W[t - 7] + R0 (W[t - 15]) + W[t - 16];

      /* The actual computation according to FIPS 180-2:6.3.2 step 3.  */
      for (t = 0; t < 80; ++t)
	{
	  uint64_t T1 = h + S1 (e) + Ch (e, f, g) + K[t] + W[t];
	  uint64_t T2 = S0 (a) + Maj (a, b, c);
	  h = g;
	  g = f;
	  f = e;
	  e = d + T1;
	  d = c;
	  c = b;
	  b = a;
	  a = T1 + T2;
	}

      /* Add the starting values of the context according to FIPS 180-2:6.3.2
	 step 4.  */
      a += a_save;
      b += b_save;
      c += c_save;
      d += d_save;
      e += e_save;
      f += f_save;
      g += g_save;
      h += h_save;

      /* Prepare for the next round.  */
      nwords -= 16;
    }

  /* Put checksum in context given as argument.  */
  ctx->H[0] = a;
  ctx->H[1] = b;
  ctx->H[2] = c;
  ctx->H[3] = d;
  ctx->H[4] = e;
  ctx->H[5] = f;
  ctx->H[6] = g;
  ctx->H[7] = h;
}


/* Initialize structure containing state of computation.
   (FIPS 180-2:5.3.3)  */
static void
sha512_init_ctx (struct sha512_ctx *ctx)
{
  ctx->H[0] = UINT64_C (0x6a09e667f3bcc908);
  ctx->H[1] = UINT64_C (0xbb67ae8584caa73b);
  ctx->H[2] = UINT64_C (0x3c6ef372fe94f82b);
  ctx->H[3] = UINT64_C (0xa54ff53a5f1d36f1);
  ctx->H[4] = UINT64_C (0x510e527fade682d1);
  ctx->H[5] = UINT64_C (0x9b05688c2b3e6c1f);
  ctx->H[6] = UINT64_C (0x1f83d9abfb41bd6b);
  ctx->H[7] = UINT64_C (0x5be0cd19137e2179);

  ctx->total[0] = ctx->total[1] = 0;
  ctx->buflen = 0;
}


/* Process the remaining bytes in the internal buffer and the usual
   prolog according to the standard and write the result to RESBUF.

   IMPORTANT: On some systems it is required that RESBUF is correctly
   aligned for a 32 bits value.  */
static void *
sha512_finish_ctx (struct sha512_ctx *ctx, void *resbuf)
{
  /* Take yet unprocessed bytes into account.  */
  uint64_t bytes = ctx->buflen;
  size_t pad;
  unsigned int i;

  /* Now count remaining bytes.  */
  ctx->total[0] += bytes;
  if (ctx->total[0] < bytes)
    ++ctx->total[1];

  pad = bytes >= 112 ? 128 + 112 - bytes : 112 - bytes;
  memcpy (&ctx->buffer[bytes], fillbuf, pad);

  /* Put the 128-bit file length in *bits* at the end of the buffer.  */
  *(uint64_t *) &ctx->buffer[bytes + pad + 8] = SWAP (ctx->total[0] << 3);
  *(uint64_t *) &ctx->buffer[bytes + pad] = SWAP ((ctx->total[1] << 3) |
						  (ctx->total[0] >> 61));

  /* Process last bytes.  */
  sha512_process_block (ctx->buffer, bytes + pad + 16, ctx);

  /* Put result from CTX in first 64 bytes following RESBUF.  */
  for (i = 0; i < 8; ++i)
    ((uint64_t *) resbuf)[i] = SWAP (ctx->H[i]);

  return resbuf;
}


static void
sha512_process_bytes (const void *buffer, size_t len, struct sha512_ctx *ctx)
{
  /* When we already have some bits in our internal buffer concatenate
     both inputs first.  */
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
	  /* The regions in the following copy operation cannot overlap.  */
	  memcpy (ctx->buffer, &ctx->buffer[(left_over + add) & ~127],
		  ctx->buflen);
	}

      buffer = (const char *) buffer + add;
      len -= add;
    }

  /* Process available complete blocks.  */
  if (len >= 128)
    {
#if !_STRING_ARCH_unaligned
/* To check alignment gcc has an appropriate operator.  Other
   compilers don't.  */
# if __GNUC__ >= 2
#  define UNALIGNED_P(p) (((uintptr_t) p) % __alignof__ (uint64_t) != 0)
# else
#  define UNALIGNED_P(p) (((uintptr_t) p) % sizeof (uint64_t) != 0)
# endif
      if (UNALIGNED_P (buffer))
	while (len > 128)
	  {
	    sha512_process_block (memcpy (ctx->buffer, buffer, 128), 128,
				    ctx);
	    buffer = (const char *) buffer + 128;
	    len -= 128;
	  }
      else
#endif
	{
	  sha512_process_block (buffer, len & ~127, ctx);
	  buffer = (const char *) buffer + (len & ~127);
	  len &= 127;
	}
    }

  /* Move remaining bytes into internal buffer.  */
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


/* Define our magic string to mark salt for SHA512 "encryption"
   replacement.  */
static const char sha512_salt_prefix[] = "$6$";

/* Prefix for optional rounds specification.  */
static const char sha512_rounds_prefix[] = "rounds=";

/* Maximum salt string length.  */
#define SALT_LEN_MAX 16
/* Default number of rounds if not explicitly specified.  */
#define ROUNDS_DEFAULT 5000
/* Minimum number of rounds.  */
#define ROUNDS_MIN 1000
/* Maximum number of rounds.  */
#define ROUNDS_MAX 999999999

/* Table with characters for base64 transformation.  */
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
  char *copied_key = NULL;
  char *copied_salt = NULL;
  char *p_bytes;
  char *s_bytes;
  /* Default number of rounds.  */
  size_t rounds = ROUNDS_DEFAULT;
  bool rounds_custom = false;

  /* Find beginning of salt string.  The prefix should normally always
     be present.  Just in case it is not.  */
  if (strncmp (sha512_salt_prefix, salt, sizeof (sha512_salt_prefix) - 1) == 0)
    /* Skip salt prefix.  */
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
	  rounds = MAX (ROUNDS_MIN, MIN (srounds, ROUNDS_MAX));
	  rounds_custom = true;
	}
    }

  salt_len = MIN (strcspn (salt, "$"), SALT_LEN_MAX);
  key_len = strlen (key);

  if ((key - (char *) 0) % __alignof__ (uint64_t) != 0)
    {
      char *tmp = (char *) alloca (key_len + __alignof__ (uint64_t));
      key = copied_key =
	memcpy (tmp + __alignof__ (uint64_t)
		- (tmp - (char *) 0) % __alignof__ (uint64_t),
		key, key_len);
    }

  if ((salt - (char *) 0) % __alignof__ (uint64_t) != 0)
    {
      char *tmp = (char *) alloca (salt_len + __alignof__ (uint64_t));
      salt = copied_salt =
	memcpy (tmp + __alignof__ (uint64_t)
		- (tmp - (char *) 0) % __alignof__ (uint64_t),
		salt, salt_len);
    }

  /* Prepare for the real work.  */
  sha512_init_ctx (&ctx);

  /* Add the key string.  */
  sha512_process_bytes (key, key_len, &ctx);

  /* The last part is the salt string.  This must be at most 16
     characters and it ends at the first `$' character (for
     compatibility with existing implementations).  */
  sha512_process_bytes (salt, salt_len, &ctx);


  /* Compute alternate SHA512 sum with input KEY, SALT, and KEY.  The
     final result will be added to the first context.  */
  sha512_init_ctx (&alt_ctx);

  /* Add key.  */
  sha512_process_bytes (key, key_len, &alt_ctx);

  /* Add salt.  */
  sha512_process_bytes (salt, salt_len, &alt_ctx);

  /* Add key again.  */
  sha512_process_bytes (key, key_len, &alt_ctx);

  /* Now get result of this (64 bytes) and add it to the other
     context.  */
  sha512_finish_ctx (&alt_ctx, alt_result);

  /* Add for any character in the key one byte of the alternate sum.  */
  for (cnt = key_len; cnt > 64; cnt -= 64)
    sha512_process_bytes (alt_result, 64, &ctx);
  sha512_process_bytes (alt_result, cnt, &ctx);

  /* Take the binary representation of the length of the key and for every
     1 add the alternate sum, for every 0 the key.  */
  for (cnt = key_len; cnt > 0; cnt >>= 1)
    if ((cnt & 1) != 0)
      sha512_process_bytes (alt_result, 64, &ctx);
    else
      sha512_process_bytes (key, key_len, &ctx);

  /* Create intermediate result.  */
  sha512_finish_ctx (&ctx, alt_result);

  /* Start computation of P byte sequence.  */
  sha512_init_ctx (&alt_ctx);

  /* For every character in the password add the entire password.  */
  for (cnt = 0; cnt < key_len; ++cnt)
    sha512_process_bytes (key, key_len, &alt_ctx);

  /* Finish the digest.  */
  sha512_finish_ctx (&alt_ctx, temp_result);

  /* Create byte sequence P.  */
  cp = p_bytes = alloca (key_len);
  for (cnt = key_len; cnt >= 64; cnt -= 64)
    cp = memcpy (cp, temp_result, 64) + 64;
  memcpy (cp, temp_result, cnt);

  /* Start computation of S byte sequence.  */
  sha512_init_ctx (&alt_ctx);

  /* For every character in the password add the entire password.  */
  for (cnt = 0; cnt < 16u + alt_result[0]; ++cnt)
    sha512_process_bytes (salt, salt_len, &alt_ctx);

  /* Finish the digest.  */
  sha512_finish_ctx (&alt_ctx, temp_result);

  /* Create byte sequence S.  */
  cp = s_bytes = alloca (salt_len);
  for (cnt = salt_len; cnt >= 64; cnt -= 64)
    cp = memcpy (cp, temp_result, 64) + 64;
  memcpy (cp, temp_result, cnt);

  /* Repeatedly run the collected hash value through SHA512 to burn
     CPU cycles.  */
  for (cnt = 0; cnt < rounds; ++cnt)
    {
      /* New context.  */
      sha512_init_ctx (&ctx);

      /* Add key or last result.  */
      if ((cnt & 1) != 0)
	sha512_process_bytes (p_bytes, key_len, &ctx);
      else
	sha512_process_bytes (alt_result, 64, &ctx);

      /* Add salt for numbers not divisible by 3.  */
      if (cnt % 3 != 0)
	sha512_process_bytes (s_bytes, salt_len, &ctx);

      /* Add key for numbers not divisible by 7.  */
      if (cnt % 7 != 0)
	sha512_process_bytes (p_bytes, key_len, &ctx);

      /* Add key or last result.  */
      if ((cnt & 1) != 0)
	sha512_process_bytes (alt_result, 64, &ctx);
      else
	sha512_process_bytes (p_bytes, key_len, &ctx);

      /* Create intermediate result.  */
      sha512_finish_ctx (&ctx, alt_result);
    }

  /* Now we can construct the result string.  It consists of three
     parts.  */
  cp = stpncpy (buffer, sha512_salt_prefix, MAX (0, buflen));
  buflen -= sizeof (sha512_salt_prefix) - 1;

  if (rounds_custom)
    {
      int n = snprintf (cp, MAX (0, buflen), "%s%zu$",
			sha512_rounds_prefix, rounds);
      cp += n;
      buflen -= n;
    }

  cp = stpncpy (cp, salt, MIN ((size_t) MAX (0, buflen), salt_len));
  buflen -= MIN ((size_t) MAX (0, buflen), salt_len);

  if (buflen > 0)
    {
      *cp++ = '$';
      --buflen;
    }

#define b64_from_24bit(B2, B1, B0, N)					      \
  do {									      \
    unsigned int w = ((B2) << 16) | ((B1) << 8) | (B0);			      \
    int n = (N);							      \
    while (n-- > 0 && buflen > 0)					      \
      {									      \
	*cp++ = b64t[w & 0x3f];						      \
	--buflen;							      \
	w >>= 6;							      \
      }									      \
  } while (0)

  b64_from_24bit (alt_result[0], alt_result[21], alt_result[42], 4);
  b64_from_24bit (alt_result[22], alt_result[43], alt_result[1], 4);
  b64_from_24bit (alt_result[44], alt_result[2], alt_result[23], 4);
  b64_from_24bit (alt_result[3], alt_result[24], alt_result[45], 4);
  b64_from_24bit (alt_result[25], alt_result[46], alt_result[4], 4);
  b64_from_24bit (alt_result[47], alt_result[5], alt_result[26], 4);
  b64_from_24bit (alt_result[6], alt_result[27], alt_result[48], 4);
  b64_from_24bit (alt_result[28], alt_result[49], alt_result[7], 4);
  b64_from_24bit (alt_result[50], alt_result[8], alt_result[29], 4);
  b64_from_24bit (alt_result[9], alt_result[30], alt_result[51], 4);
  b64_from_24bit (alt_result[31], alt_result[52], alt_result[10], 4);
  b64_from_24bit (alt_result[53], alt_result[11], alt_result[32], 4);
  b64_from_24bit (alt_result[12], alt_result[33], alt_result[54], 4);
  b64_from_24bit (alt_result[34], alt_result[55], alt_result[13], 4);
  b64_from_24bit (alt_result[56], alt_result[14], alt_result[35], 4);
  b64_from_24bit (alt_result[15], alt_result[36], alt_result[57], 4);
  b64_from_24bit (alt_result[37], alt_result[58], alt_result[16], 4);
  b64_from_24bit (alt_result[59], alt_result[17], alt_result[38], 4);
  b64_from_24bit (alt_result[18], alt_result[39], alt_result[60], 4);
  b64_from_24bit (alt_result[40], alt_result[61], alt_result[19], 4);
  b64_from_24bit (alt_result[62], alt_result[20], alt_result[41], 4);
  b64_from_24bit (0, 0, alt_result[63], 2);

  if (buflen <= 0)
    {
      errno = ERANGE;
      buffer = NULL;
    }
  else
    *cp = '\0';		/* Terminate the string.  */

  /* Clear the buffer for the intermediate result so that people
     attaching to processes or reading core dumps cannot get any
     information.  We do it in this way to clear correct_words[]
     inside the SHA512 implementation as well.  */
  sha512_init_ctx (&ctx);
  sha512_finish_ctx (&ctx, alt_result);
  memset (temp_result, '\0', sizeof (temp_result));
  memset (p_bytes, '\0', key_len);
  memset (s_bytes, '\0', salt_len);
  memset (&ctx, '\0', sizeof (ctx));
  memset (&alt_ctx, '\0', sizeof (alt_ctx));
  if (copied_key != NULL)
    memset (copied_key, '\0', key_len);
  if (copied_salt != NULL)
    memset (copied_salt, '\0', salt_len);

  return buffer;
}


/* This entry point is equivalent to the `crypt' function in Unix
   libcs.  */
char *
sha512_crypt (const char *key, const char *salt)
{
  /* We don't want to have an arbitrary limit in the size of the
     password.  We can compute an upper bound for the size of the
     result in advance and so we can prepare the buffer we pass to
     `sha512_crypt_r'.  */
  static char *buffer;
  static int buflen;
  int needed = (sizeof (sha512_salt_prefix) - 1
		+ sizeof (sha512_rounds_prefix) + 9 + 1
		+ strlen (salt) + 1 + 86 + 1);

  if (buflen < needed)
    {
      char *new_buffer = (char *) realloc (buffer, needed);
      if (new_buffer == NULL)
	return NULL;

      buffer = new_buffer;
      buflen = needed;
    }

  return sha512_crypt_r (key, salt, buffer, buflen);
}


#ifdef UNITTEST
static const struct
{
  const char *input;
  const char result[64];
} tests[] =
  {
    /* Test vectors from FIPS 180-2: appendix C.1.  */
    { "abc",
      "\xdd\xaf\x35\xa1\x93\x61\x7a\xba\xcc\x41\x73\x49\xae\x20\x41\x31"
      "\x12\xe6\xfa\x4e\x89\xa9\x7e\xa2\x0a\x9e\xee\xe6\x4b\x55\xd3\x9a"
      "\x21\x92\x99\x2a\x27\x4f\xc1\xa8\x36\xba\x3c\x23\xa3\xfe\xeb\xbd"
      "\x45\x4d\x44\x23\x64\x3c\xe8\x0e\x2a\x9a\xc9\x4f\xa5\x4c\xa4\x9f" },
    /* Test vectors from FIPS 180-2: appendix C.2.  */
    { "abcdefghbcdefghicdefghijdefghijkefghijklfghijklmghijklmn"
      "hijklmnoijklmnopjklmnopqklmnopqrlmnopqrsmnopqrstnopqrstu",
      "\x8e\x95\x9b\x75\xda\xe3\x13\xda\x8c\xf4\xf7\x28\x14\xfc\x14\x3f"
      "\x8f\x77\x79\xc6\xeb\x9f\x7f\xa1\x72\x99\xae\xad\xb6\x88\x90\x18"
      "\x50\x1d\x28\x9e\x49\x00\xf7\xe4\x33\x1b\x99\xde\xc4\xb5\x43\x3a"
      "\xc7\xd3\x29\xee\xb6\xdd\x26\x54\x5e\x96\xe5\x5b\x87\x4b\xe9\x09" },
    /* Test vectors from the NESSIE project.  */
    { "",
      "\xcf\x83\xe1\x35\x7e\xef\xb8\xbd\xf1\x54\x28\x50\xd6\x6d\x80\x07"
      "\xd6\x20\xe4\x05\x0b\x57\x15\xdc\x83\xf4\xa9\x21\xd3\x6c\xe9\xce"
      "\x47\xd0\xd1\x3c\x5d\x85\xf2\xb0\xff\x83\x18\xd2\x87\x7e\xec\x2f"
      "\x63\xb9\x31\xbd\x47\x41\x7a\x81\xa5\x38\x32\x7a\xf9\x27\xda\x3e" },
    { "a",
      "\x1f\x40\xfc\x92\xda\x24\x16\x94\x75\x09\x79\xee\x6c\xf5\x82\xf2"
      "\xd5\xd7\xd2\x8e\x18\x33\x5d\xe0\x5a\xbc\x54\xd0\x56\x0e\x0f\x53"
      "\x02\x86\x0c\x65\x2b\xf0\x8d\x56\x02\x52\xaa\x5e\x74\x21\x05\x46"
      "\xf3\x69\xfb\xbb\xce\x8c\x12\xcf\xc7\x95\x7b\x26\x52\xfe\x9a\x75" },
    { "message digest",
      "\x10\x7d\xbf\x38\x9d\x9e\x9f\x71\xa3\xa9\x5f\x6c\x05\x5b\x92\x51"
      "\xbc\x52\x68\xc2\xbe\x16\xd6\xc1\x34\x92\xea\x45\xb0\x19\x9f\x33"
      "\x09\xe1\x64\x55\xab\x1e\x96\x11\x8e\x8a\x90\x5d\x55\x97\xb7\x20"
      "\x38\xdd\xb3\x72\xa8\x98\x26\x04\x6d\xe6\x66\x87\xbb\x42\x0e\x7c" },
    { "abcdefghijklmnopqrstuvwxyz",
      "\x4d\xbf\xf8\x6c\xc2\xca\x1b\xae\x1e\x16\x46\x8a\x05\xcb\x98\x81"
      "\xc9\x7f\x17\x53\xbc\xe3\x61\x90\x34\x89\x8f\xaa\x1a\xab\xe4\x29"
      "\x95\x5a\x1b\xf8\xec\x48\x3d\x74\x21\xfe\x3c\x16\x46\x61\x3a\x59"
      "\xed\x54\x41\xfb\x0f\x32\x13\x89\xf7\x7f\x48\xa8\x79\xc7\xb1\xf1" },
    { "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq",
      "\x20\x4a\x8f\xc6\xdd\xa8\x2f\x0a\x0c\xed\x7b\xeb\x8e\x08\xa4\x16"
      "\x57\xc1\x6e\xf4\x68\xb2\x28\xa8\x27\x9b\xe3\x31\xa7\x03\xc3\x35"
      "\x96\xfd\x15\xc1\x3b\x1b\x07\xf9\xaa\x1d\x3b\xea\x57\x78\x9c\xa0"
      "\x31\xad\x85\xc7\xa7\x1d\xd7\x03\x54\xec\x63\x12\x38\xca\x34\x45" },
    { "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789",
      "\x1e\x07\xbe\x23\xc2\x6a\x86\xea\x37\xea\x81\x0c\x8e\xc7\x80\x93"
      "\x52\x51\x5a\x97\x0e\x92\x53\xc2\x6f\x53\x6c\xfc\x7a\x99\x96\xc4"
      "\x5c\x83\x70\x58\x3e\x0a\x78\xfa\x4a\x90\x04\x1d\x71\xa4\xce\xab"
      "\x74\x23\xf1\x9c\x71\xb9\xd5\xa3\xe0\x12\x49\xf0\xbe\xbd\x58\x94" },
    { "123456789012345678901234567890123456789012345678901234567890"
      "12345678901234567890",
      "\x72\xec\x1e\xf1\x12\x4a\x45\xb0\x47\xe8\xb7\xc7\x5a\x93\x21\x95"
      "\x13\x5b\xb6\x1d\xe2\x4e\xc0\xd1\x91\x40\x42\x24\x6e\x0a\xec\x3a"
      "\x23\x54\xe0\x93\xd7\x6f\x30\x48\xb4\x56\x76\x43\x46\x90\x0c\xb1"
      "\x30\xd2\xa4\xfd\x5d\xd1\x6a\xbb\x5e\x30\xbc\xb8\x50\xde\xe8\x43" }
  };
#define ntests (sizeof (tests) / sizeof (tests[0]))


static const struct
{
  const char *salt;
  const char *input;
  const char *expected;
} tests2[] =
{
  { "$6$saltstring", "Hello world!",
    "$6$saltstring$svn8UoSVapNtMuq1ukKS4tPQd8iKwSMHWjl/O817G3uBnIFNjnQJu"
    "esI68u4OTLiBFdcbYEdFCoEOfaS35inz1" },
  { "$6$rounds=10000$saltstringsaltstring", "Hello world!",
    "$6$rounds=10000$saltstringsaltst$OW1/O6BYHV6BcXZu8QVeXbDWra3Oeqh0sb"
    "HbbMCVNSnCM/UrjmM0Dp8vOuZeHBy/YTBmSK6H9qs/y3RnOaw5v." },
  { "$6$rounds=5000$toolongsaltstring", "This is just a test",
    "$6$rounds=5000$toolongsaltstrin$lQ8jolhgVRVhY4b5pZKaysCLi0QBxGoNeKQ"
    "zQ3glMhwllF7oGDZxUhx1yxdYcz/e1JSbq3y6JMxxl8audkUEm0" },
  { "$6$rounds=1400$anotherlongsaltstring",
    "a very much longer text to encrypt.  This one even stretches over more"
    "than one line.",
    "$6$rounds=1400$anotherlongsalts$POfYwTEok97VWcjxIiSOjiykti.o/pQs.wP"
    "vMxQ6Fm7I6IoYN3CmLs66x9t0oSwbtEW7o7UmJEiDwGqd8p4ur1" },
  { "$6$rounds=77777$short",
    "we have a short salt string but not a short password",
    "$6$rounds=77777$short$WuQyW2YR.hBNpjjRhpYD/ifIw05xdfeEyQoMxIXbkvr0g"
    "ge1a1x3yRULJ5CCaUeOxFmtlcGZelFl5CxtgfiAc0" },
  { "$6$rounds=123456$asaltof16chars..", "a short string",
    "$6$rounds=123456$asaltof16chars..$BtCwjqMJGx5hrJhZywWvt0RLE8uZ4oPwc"
    "elCjmw2kSYu.Ec6ycULevoBK25fs2xXgMNrCzIMVcgEJAstJeonj1" },
  { "$6$rounds=10$roundstoolow", "the minimum number is still observed",
    "$6$rounds=1000$roundstoolow$kUMsbe306n21p9R.FRkW3IGn.S9NPN0x50YhH1x"
    "hLsPuWGsUSklZt58jaTfF4ZEQpyUNGc0dqbpBYYBaHHrsX." },
};
#define ntests2 (sizeof (tests2) / sizeof (tests2[0]))


int
main (void)
{
  struct sha512_ctx ctx;
  char sum[64];
  int result = 0;
  int cnt;
  int i;

  for (cnt = 0; cnt < (int) ntests; ++cnt)
    {
      sha512_init_ctx (&ctx);
      sha512_process_bytes (tests[cnt].input, strlen (tests[cnt].input), &ctx);
      sha512_finish_ctx (&ctx, sum);
      if (memcmp (tests[cnt].result, sum, 64) != 0)
	{
	  printf ("test %d run %d failed\n", cnt, 1);
	  result = 1;
	}

      sha512_init_ctx (&ctx);
      for (i = 0; tests[cnt].input[i] != '\0'; ++i)
	sha512_process_bytes (&tests[cnt].input[i], 1, &ctx);
      sha512_finish_ctx (&ctx, sum);
      if (memcmp (tests[cnt].result, sum, 64) != 0)
	{
	  printf ("test %d run %d failed\n", cnt, 2);
	  result = 1;
	}
    }

  /* Test vector from FIPS 180-2: appendix C.3.  */
  char buf[1000];
  memset (buf, 'a', sizeof (buf));
  sha512_init_ctx (&ctx);
  for (i = 0; i < 1000; ++i)
    sha512_process_bytes (buf, sizeof (buf), &ctx);
  sha512_finish_ctx (&ctx, sum);
  static const char expected[64] =
    "\xe7\x18\x48\x3d\x0c\xe7\x69\x64\x4e\x2e\x42\xc7\xbc\x15\xb4\x63"
    "\x8e\x1f\x98\xb1\x3b\x20\x44\x28\x56\x32\xa8\x03\xaf\xa9\x73\xeb"
    "\xde\x0f\xf2\x44\x87\x7e\xa6\x0a\x4c\xb0\x43\x2c\xe5\x77\xc3\x1b"
    "\xeb\x00\x9c\x5c\x2c\x49\xaa\x2e\x4e\xad\xb2\x17\xad\x8c\xc0\x9b";
  if (memcmp (expected, sum, 64) != 0)
    {
      printf ("test %d failed\n", cnt);
      result = 1;
    }

  for (cnt = 0; cnt < ntests2; ++cnt)
    {
      char *cp = sha512_crypt (tests2[cnt].input, tests2[cnt].salt);

      if (strcmp (cp, tests2[cnt].expected) != 0)
	{
	  printf ("test %d: expected \"%s\", got \"%s\"\n",
	   	  cnt, tests2[cnt].expected, cp);
	  result = 1;
	}
    }

  if (result == 0)
    puts ("all tests OK");

  return result;
}
#endif
#include <string.h>
#include <libgen.h>

/*
       path           dirname        basename
       "/usr/lib"     "/usr"         "lib"
       "/usr/"        "/"            "usr"
       "usr"          "."            "usr"
       "/"            "/"            "/"
       "."            "."            "."
       ".."           "."            ".."
*/

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
#include <libgen.h>
#include <string.h>
/*
        path           dirname        basename
        "/usr/lib"     "/usr"         "lib"
        "/usr/"        "/"            "usr"
        "usr"          "."            "usr"
        "/"            "/"            "/"
        "."            "."            "."
        ".."           "."            ".."
        NULL           "."            "."
        ""             "."            "."
*/

static char *dot=".";
#define SLASH '/'
#define EOL (char)0
char *dirname(char *path)
{
  char *c;
  if ( path  == NULL ) return dot;
  for(;;) {
    if ( !(c=strrchr(path,SLASH)) ) return dot; /* no slashes */
    if ( c[1]==EOL && c!=path ) {   /* remove trailing slashes */
      while ( *c==SLASH && c!=path ) *c--=EOL;
      continue;
    }
    if ( c!=path )
      while ( *c==SLASH && c>=path) *c--=EOL; /* slashes in the middle */
    else
      path[1]=EOL;                  /* slash is first symbol */
    return path;
  }
}
#include <ctype.h>
#include <fnmatch.h>
#include <string.h>

#define NOTFIRST 128

#define STRUCT_CHARCLASS(c) { #c , is##c }

static struct charclass {
  char * class;
  int (*istype)(int);
} allclasses[] = {
  STRUCT_CHARCLASS(alnum),
  STRUCT_CHARCLASS(alpha),
  STRUCT_CHARCLASS(blank),
  STRUCT_CHARCLASS(cntrl),
  STRUCT_CHARCLASS(digit),
  STRUCT_CHARCLASS(graph),
  STRUCT_CHARCLASS(lower),
  STRUCT_CHARCLASS(print),
  STRUCT_CHARCLASS(punct),
  STRUCT_CHARCLASS(space),
  STRUCT_CHARCLASS(upper),
  STRUCT_CHARCLASS(xdigit),
};

/* look for "class:]" in pattern */
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
  return NULL;
}

static int match(char c,char d,int flags) {
  if (flags&FNM_CASEFOLD)
    return (tolower(c)==tolower(d));
  else
    return (c==d);
}

int fnmatch(const char *pattern, const char *string, int flags) {
  if (*string==0) {
    while (*pattern=='*') ++pattern;
    return (!!*pattern);
  }
  if (*string=='.' && *pattern!='.' && (flags&FNM_PERIOD)) {
    /* don't match if FNM_PERIOD and this is the first char */
    if (!(flags&NOTFIRST))
      return FNM_NOMATCH;
    /* don't match if FNM_PERIOD and FNM_PATHNAME and previous was '/' */
    if ((flags&(FNM_PATHNAME)) && string[-1]=='/')
      return FNM_NOMATCH;
  }
  flags|=NOTFIRST;
  switch (*pattern) {
  case '[':
    {
      int neg=0;
      const char* start;	/* first member of character class */

      ++pattern;
      if (*string=='/' && flags&FNM_PATHNAME) return FNM_NOMATCH;
      if (*pattern=='!') { neg=1; ++pattern; }
      start=pattern;
      while (*pattern) {
	int res=0;

	if (*pattern==']' && pattern!=start) break;
	if (*pattern=='[' && pattern[1]==':') {
	  /* MEMBER - stupid POSIX char classes */
	  const struct charclass *cc;

	  if (!(cc = charclass_lookup(pattern+2))) goto invalidclass;
	  pattern += strlen(cc->class) + 4;
	  if (flags&FNM_CASEFOLD
	      && (cc->istype == isupper || cc->istype == islower)) {
	    res = islower(tolower(*string));
	  } else {
            res = ((*(cc->istype))(*string));
	  }
	} else {
invalidclass:
	  if (pattern[1]=='-' && pattern[2]!=']') {
	    /* MEMBER - character range */
	    if (*string>=*pattern && *string<=pattern[2]) res=1;
	    if (flags&FNM_CASEFOLD) {
	      if (tolower(*string)>=tolower(*pattern) && tolower(*string)<=tolower(pattern[2])) res=1;
	    }
	    pattern+=3;
	  } else {
	    /* MEMBER - literal character match */
	    res=match(*pattern,*string,flags);
	    ++pattern;
	  }
	}
	if ((res&&!neg) || ((neg&&!res) && *pattern==']')) {
	  while (*pattern && *pattern!=']') ++pattern;
	  return fnmatch(pattern+!!*pattern,string+1,flags);
	} else if (res && neg)
	  return FNM_NOMATCH;
      }
    }
    break;
  case '\\':
    if (flags&FNM_NOESCAPE) {
      if (*string=='\\')
	return fnmatch(pattern+1,string+1,flags);
    } else {
      if (*string==pattern[1])
	return fnmatch(pattern+2,string+1,flags);
    }
    break;
  case '*':
    if ((*string=='/' && flags&FNM_PATHNAME) || fnmatch(pattern,string+1,flags))
      return fnmatch(pattern+1,string,flags);
    return 0;
  case 0:
    if (*string==0 || (*string=='/' && (flags&FNM_LEADING_DIR)))
      return 0;
    break;
  case '?':
    if (*string=='/' && flags&FNM_PATHNAME) break;
    return fnmatch(pattern+1,string+1,flags);
  default:
    if (match(*pattern,*string,flags))
      return fnmatch(pattern+1,string+1,flags);
    break;
  }
  return FNM_NOMATCH;
}
/*
 * dietlibc/libshell/glob.c
 *
 * Copyright 2001 Guillaume Cottenceau <gc@mandrakesoft.com>
 *
 * This is free software, licensed under the Gnu General Public License.
 *
 */

/*
 * unsupported: GLOB_BRACE GLOB_ALTDIRFUNC GLOB_MAGCHAR
 */

#define DEBUG(x)

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <assert.h>
#include <fnmatch.h>
#include <dirent.h>
#include <pwd.h>
#include "dietfeatures.h"

#include <glob.h>



/* If i18n, should be using strcoll */
static int cmp_func(const void * a, const void * b)
{
	const char *const s1 = *(const char *const * const) a;
	const char *const s2 = *(const char *const * const) b;
	if (s1 == NULL)
		return 1;
	if (s2 == NULL)
		return -1;
	return strcoll(s1, s2);
}


/* Like `glob', but PATTERN is a final pathname component,
   and matches are searched for in DIRECTORY.
   The GLOB_NOSORT bit in FLAGS is ignored.  No sorting is ever done.
   The GLOB_APPEND flag is assumed to be set (always appends).
   Prepends DIRECTORY in constructed PGLOB. */
static void close_dir_keep_errno(DIR* dp) {
  int save = errno;
  if (dp)
    closedir (dp);
  errno=save;
}

static int add_entry(const char* name,glob_t *pglob,int* nfound) {
  pglob->gl_pathv	= (char **) realloc(pglob->gl_pathv,
			  (pglob->gl_pathc + pglob->gl_offs + 2)
			  * sizeof (char *));
  if (pglob->gl_pathv == NULL)
    return 1;
  pglob->gl_pathv[pglob->gl_offs + pglob->gl_pathc] = strdup(name);
  pglob->gl_pathv[pglob->gl_offs + pglob->gl_pathc + 1] = NULL;
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
		if (errno != ENOTDIR
		    && ((errfunc != NULL && (*errfunc) (directory, errno))
			|| (flags & GLOB_ERR)))
		      return GLOB_ABORTED;
	} else {
		int fnm_flags = ((!(flags & GLOB_PERIOD) ? FNM_PERIOD : 0)
				 | ((flags & GLOB_NOESCAPE) ? FNM_NOESCAPE : 0));
		struct dirent *ep;
		while ((ep = readdir(dp))) {
			i = strlen(directory) + strlen(ep->d_name) + 2;
			ptr = (char *) alloca(i);
			build_fullname(ptr, directory, ep->d_name);
			if (flags & GLOB_ONLYDIR) {
				struct stat statr;
				if (stat(ptr, &statr) || !S_ISDIR(statr.st_mode))
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
	else if (flags & GLOB_NOCHECK) {
		/* nfound == 0 */
		i = strlen(directory) + strlen(pattern) + 2;
		ptr = (char *) alloca(i);
		build_fullname(ptr, directory, pattern);
		if (add_entry(ptr,pglob,&nfound))
			goto memory_error;
	}

	return (nfound == 0) ? GLOB_NOMATCH : 0;

 memory_error:
	/* We're in trouble since we can't free the already allocated memory. [allocated from strdup(filame)]
	 * Well, after all, when malloc returns NULL we're already in a bad mood, and no doubt the
	 * program will manage to segfault by itself very soon :-). */
	close_dir_keep_errno(dp);
	return GLOB_NOSPACE;
}



int glob(const char *pattern, int flags, int errfunc(const char * epath, int eerrno), glob_t *pglob)
{
	char * pattern_;
	char * filename;
	char * dirname;
	size_t oldcount;
	struct stat statr;

	size_t i; /* tmp variables are declared here to save a bit of object space */
	int j, k;    /* */
	char * ptr, * ptr2;

	if (pattern == NULL || pglob == NULL || (flags & ~__GLOB_FLAGS) != 0) {
		errno=EINVAL;
		return -1;
	}

	if (!(flags & GLOB_DOOFFS))
		pglob->gl_offs = 0;


	/* Duplicate pattern so I can make modif to it later (to handle
           TILDE stuff replacing old contents, and to null-terminate the
           directory) */
	pattern_ = alloca(strlen(pattern) + 1);
	strcpy(pattern_, pattern);

	/* Check for TILDE stuff */
	if ((flags & (GLOB_TILDE|GLOB_TILDE_CHECK)) && pattern_[0] == '~') {
		char * home_dir = NULL;
		if (pattern_[1] == '\0' || pattern_[1] == '/') {
			/* She's asking for ~, her homedir */
			home_dir = getenv("HOME");
		} else {
			/* She's asking for another one's homedir */
			struct passwd * p;
			ptr2 = alloca(strlen(pattern_) + 1);
			strcpy(ptr2, pattern_ + 1);
			ptr = strchr(ptr2, '/');
			if (ptr != NULL)
				*ptr = '\0';
			if (((p = getpwnam(ptr2)) != NULL))
				home_dir = p->pw_dir;
		}
		if (home_dir != NULL) {
			i = strlen(home_dir) + strlen(pattern_); /* pessimistic (the ~ case) */
			ptr = alloca(i);
			strncpy(ptr, home_dir, i);
			ptr2 = pattern_ + 1;
			while (*ptr2 != '/' && *ptr2 != '\0')
				ptr2++;
			strncat(ptr, ptr2, i);
			pattern_ = ptr;
		} else if (flags & GLOB_TILDE_CHECK)
			return GLOB_NOMATCH;
	}

	/* Find the filename */
	filename = strrchr(pattern_, '/');

	if (filename == NULL) {
		/* We have no '/' in the pattern */
		filename = pattern_;
		dirname = (char*)".";
	} else if (filename == pattern_) {
		/* "/pattern".  */
		dirname = (char*)"/";
		filename++;
	} else {
		dirname = pattern_;
		filename++;
		/* allow dirname to be null terminated */
		*(filename-1) = '\0';

		if (filename[0] == '\0' && strcmp(pattern_, "/")) {
			/* "pattern/".  Expand "pattern", appending slashes.  */
			j = glob(dirname, flags | GLOB_MARK, errfunc, pglob);
			if (j == 0)
				pglob->gl_flags = ((pglob->gl_flags & ~GLOB_MARK)
						   | (flags & GLOB_MARK));
			return j;
		}
	}

	
	/* Reserve memory for pglob */
	if (!(flags & GLOB_APPEND)) {
		pglob->gl_pathc = 0;
		if (!(flags & GLOB_DOOFFS))
			pglob->gl_pathv = NULL;
		else {
			pglob->gl_pathv = (char **) malloc((pglob->gl_offs + 1) * sizeof (char *));
			if (pglob->gl_pathv == NULL)
				return GLOB_NOSPACE;
			for (i = 0; i <= pglob->gl_offs; i++)
				pglob->gl_pathv[i] = NULL;
		}
	}


	oldcount = pglob->gl_pathc + pglob->gl_offs;


	/* Begin real work */
	if (!strcmp(dirname, "/") || !strcmp(dirname, ".")
	    || (!strchr(dirname, '*') && !strchr(dirname, '?') && !strchr(dirname, '['))) {
		/* Approx of a terminal state, glob directly in dir. */
		j = glob_in_dir(filename, dirname, flags, errfunc, pglob);
		if (j != 0)
			return j;
	} else {
		/* We are not in a terminal state, so we have to glob for
		   the directory, and then glob for the pattern in each
		   directory found. */
		glob_t dirs;

		j = glob(dirname, ((flags & (GLOB_ERR | GLOB_NOCHECK | GLOB_NOESCAPE | GLOB_ALTDIRFUNC))
				   | GLOB_NOSORT | GLOB_ONLYDIR),
			 errfunc, &dirs);
		if (j != 0)
			return j;

		/* We have successfully globbed the directory name.
		   For each name we found, call glob_in_dir on it and FILENAME,
		   appending the results to PGLOB.  */
		for (i = 0; i < dirs.gl_pathc; i++) {
			j = glob_in_dir(filename, dirs.gl_pathv[i], ((flags | GLOB_APPEND) & ~GLOB_NOCHECK),
					errfunc, pglob);
			if (j == GLOB_NOMATCH)
				/* No matches in this directory.  Try the next.  */
				continue;
			if (j != 0) {
				globfree(&dirs);
				globfree(pglob);
				return j;
			}
		}

		/* We have ignored the GLOB_NOCHECK flag in the `glob_in_dir' calls.
		   But if we have not found any matching entry and the GLOB_NOCHECK
		   flag was set we must return the list consisting of the disrectory
		   names followed by the filename.  */
		if (pglob->gl_pathc + pglob->gl_offs == oldcount)
		{
			/* No matches.  */
			if (flags & GLOB_NOCHECK)
			{
				for (i = 0; i < dirs.gl_pathc; i++) {
					if (stat(dirs.gl_pathv[i], &statr) || !S_ISDIR(statr.st_mode))
						continue;

					/* stat is okay, we will add the entry, but before let's resize the pathv */
					j = pglob->gl_pathc + pglob->gl_offs;
					pglob->gl_pathv = (char **) realloc(pglob->gl_pathv, (j + 2) * sizeof (char *));
					if (pglob->gl_pathv == NULL) {
						globfree (&dirs);
						return GLOB_NOSPACE;
					}

					/* okay now we add the new entry */
					k = strlen(dirs.gl_pathv[i]) + strlen(filename) + 2;
					if ((pglob->gl_pathv[j] = malloc(k)) == NULL) {
						globfree(&dirs);
						globfree(pglob);
						return GLOB_NOSPACE;
					}
					build_fullname(pglob->gl_pathv[j], dirs.gl_pathv[i], filename);
					pglob->gl_pathc++;
					pglob->gl_pathv[j+1] = NULL;
				}
			} else {
				globfree(&dirs);
				return GLOB_NOMATCH;
			}
		}

		globfree (&dirs);
	}


	if (flags & GLOB_MARK) {
		for (i = oldcount; i < pglob->gl_pathc + pglob->gl_offs; i++)
			if (!stat(pglob->gl_pathv[i], &statr) && S_ISDIR(statr.st_mode)) {
				size_t len = strlen(pglob->gl_pathv[i]) + 2;
				ptr = realloc(pglob->gl_pathv[i], len);
				if (ptr == NULL) {
					globfree(pglob);
					return GLOB_NOSPACE;
				}
				strcpy(&ptr[len - 2], "/");
				pglob->gl_pathv[i] = ptr;
			}
	}

	if (!(flags & GLOB_NOSORT)) {
		qsort(&pglob->gl_pathv[oldcount],
		      pglob->gl_pathc + pglob->gl_offs - oldcount,
		      sizeof(char *), cmp_func);
	}

	return 0;
}


/* Free storage allocated in PGLOB by a previous `glob' call.  */
void globfree (glob_t * pglob)
{
  if (pglob->gl_pathv != NULL) {
      size_t i;
      for (i = 0; i < pglob->gl_pathc; i++)
	      if (pglob->gl_pathv[pglob->gl_offs + i] != NULL)
		      free((void *) pglob->gl_pathv[pglob->gl_offs + i]);
      free((void *) pglob->gl_pathv);
  }
}
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

static char* myrealpath(const char* file, char* dest, int count) {
/* assume dest has PATH_MAX space */
  char buf[PATH_MAX+1];
  char* c;
  int i;

  if (count<0) { errno=EMLINK; return 0; }
  if (chdir(file)==0)
    /* hurray!  The easy case: it's a directory! */
    return getcwd(dest,PATH_MAX);

  c=strrchr(file,'/');
  if (c) {
    if (c-file>PATH_MAX) return 0;
    memcpy(buf,file,c-file);
    buf[c-file]=0;
    if (chdir(buf)==-1) return 0;
    file=c+1;
  }
  if (readlink(file,buf,PATH_MAX)==0)
    return myrealpath(buf,dest,count-1);
  if (getcwd(dest,PATH_MAX)==0) return 0;
  i=strlen(dest); dest[i]='/'; ++i;
  for (; i<PATH_MAX-1; ++i) {
    if (!(dest[i]=*file)) break;
    ++file;
  }
  dest[i]=0;
  return dest;
}

char* realpath(const char* file, char* dest) {
  int fd=open(".",O_RDONLY);	/* save directory */
  char* res;
  if (!dest) dest=malloc(PATH_MAX+1);
  if (!dest) return NULL;
  res=myrealpath(file,dest,31);
  fchdir(fd);
  close(fd);
  return res;
}

#include <stdlib.h>
#include <endian.h>
#include <math.h>
/* convert double to string.  Helper for sprintf. */

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
#if 1
  union {
    unsigned long long l;
    double d;
  } u = { .d=d };
  /* step 1: extract sign, mantissa and exponent */
  signed long e=((u.l>>52)&((1<<11)-1))-1023;
#else
#if __BYTE_ORDER == __LITTLE_ENDIAN
  signed long e=(((((unsigned long*)&d)[1])>>20)&((1<<11)-1))-1023;
#else
  signed long e=(((*((unsigned long*)&d))>>20)&((1<<11)-1))-1023;
#endif
#endif
/*  unsigned long long m=u.l & ((1ull<<52)-1); */
  /* step 2: exponent is base 2, compute exponent for base 10 */
  signed long e10;
  /* step 3: calculate 10^e10 */
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
  e10=1+(long)(e*0.30102999566398119802); /* log10(2) */
  /* Wir iterieren von Links bis wir bei 0 sind oder maxlen erreicht
   * ist.  Wenn maxlen erreicht ist, machen wir das nochmal in
   * scientific notation.  Wenn dann von prec noch was übrig ist, geben
   * wir einen Dezimalpunkt aus und geben prec2 Nachkommastellen aus.
   * Wenn prec2 Null ist, geben wir so viel Stellen aus, wie von prec
   * noch übrig ist. */
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

   /*
      Perform rounding. It needs to be done before we generate any
      digits as the carry could propagate through the whole number.
   */

  tmp = 0.5;
  for (i = 0; i < prec2; i++) { tmp *= 0.1; }
  d += tmp;

  if (d < 1.0) { *buf='0'; --maxlen; ++buf; }
/*  printf("e=%d e10=%d prec=%d\n",e,e10,prec); */
  if (e10>0) {
    int first=1;	/* are we about to write the first digit? */
    tmp = 10.0;
    i=e10;
    while (i>10) { tmp=tmp*1e10; i-=10; }
    while (i>1) { tmp=tmp*10; --i; }
    /* the number is greater than 1. Iterate through digits before the
     * decimal point until we reach the decimal point or maxlen is
     * reached (in which case we switch to scientific notation). */
    while (tmp>0.9) {
      char digit;
      double fraction=d/tmp;
	digit=(int)(fraction);		/* floor() */
      if (!first || digit) {
	first=0;
	*buf=digit+'0'; ++buf;
	if (!maxlen) {
	  /* use scientific notation */
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
  if (prec2 || prec>(unsigned int)(buf-oldbuf)+1) {	/* more digits wanted */
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
      digit=(int)(fraction);		/* floor() */
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
#include <unistd.h>
#include <sys/time.h>
#include "syscalls.h"

#ifndef __NR_alarm
unsigned int alarm(unsigned int seconds) {
  struct itimerval old, new;
  unsigned int ret;
  new.it_interval.tv_usec=0;
  new.it_interval.tv_sec=0;
  new.it_value.tv_usec	=0;
  new.it_value.tv_sec	=(long)seconds;
  if (setitimer(ITIMER_REAL,&new,&old)==-1) return 0;
  return old.it_value.tv_sec+(old.it_value.tv_usec?1:0);
}
#endif
#include <errno.h>
#include "dietfeatures.h"
#ifdef WANT_LARGEFILE_BACKCOMPAT
#include <sys/stat.h>
#ifndef __NO_STAT64
#include <fcntl.h>
#include <stdarg.h>

extern int __dietlibc_fcntl64(int __fd, int cmd, ...);

int fcntl64(int fd, int cmd, ...) {
  va_list va;
  va_start(va,cmd);
  switch (cmd) {
  case F_GETLK:
  case F_SETLK:
  case F_SETLKW:
    {
      struct flock64* x = va_arg(va,struct flock64*);
      struct flock tmp;
      int res;
      if ((res=__dietlibc_fcntl64(fd,cmd,x))) {
	if (errno!=ENOSYS) return -1;
	tmp.l_type=x->l_type;
	tmp.l_whence=x->l_whence;
	tmp.l_start=x->l_start;
	tmp.l_len=x->l_len;
	tmp.l_pid=x->l_pid;
	if (tmp.l_len != x->l_len || tmp.l_start != x->l_start) {
	  errno=EOVERFLOW;
	  return -1;
	}
	res=fcntl(fd,cmd,&tmp);
	if (cmd==F_GETLK) {
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
      long arg = va_arg(va,long);
      int res;
      if ((res=__dietlibc_fcntl64(fd,cmd,arg))==-1) {
	if (errno!=ENOSYS) return -1;
	return fcntl(fd,cmd,arg);
      }
      return res;
    }
  }
}
#endif
#endif
#include <errno.h>
#include "dietfeatures.h"
#ifdef WANT_LARGEFILE_BACKCOMPAT
#include <sys/stat.h>
#ifndef __NO_STAT64

extern int __dietlibc_fstat64(int __fd, struct stat64 *__buf);
extern void __stat64_cvt(const struct stat *src,struct stat64 *dest);

int fstat64(int __fd, struct stat64 *__buf) {
  if (__dietlibc_fstat64(__fd,__buf)) {
    struct stat temp;
    if (errno!=ENOSYS) return -1;
    if (fstat(__fd,&temp)) return -1;
    __stat64_cvt(&temp,__buf);
  }
  return 0;
}
#endif
#endif
