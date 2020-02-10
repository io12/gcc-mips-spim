#define _SPIM_NR_PRINT_INT 1
#define _SPIM_NR_PRINT_FLOAT 2
#define _SPIM_NR_PRINT_DOUBLE 3
#define _SPIM_NR_PRINT_STRING 4
#define _SPIM_NR_READ_INT 5
#define _SPIM_NR_READ_FLOAT 6
#define _SPIM_NR_READ_DOUBLE 7
#define _SPIM_NR_READ_STRING 8
#define _SPIM_NR_SBRK 9
#define _SPIM_NR_EXIT 10
#define _SPIM_NR_PRINT_CHARACTER 11
#define _SPIM_NR_READ_CHARACTER 12
#define _SPIM_NR_OPEN 13
#define _SPIM_NR_READ 14
#define _SPIM_NR_WRITE 15
#define _SPIM_NR_CLOSE 16
#define _SPIM_NR_EXIT2 17

#define _SPIM_STR(s) #s
#define _SPIM_XSTR(s) _SPIM_STR(s)

static long _spim_syscall(long nr, long a, long b, long c)
{
	long ret;

	asm volatile(
		"lw $v0, %1\n"
		"lw $a0, %2\n"
		"lw $a1, %3\n"
		"lw $a2, %4\n"
		"syscall\n"
		"sw $v0, %0\n"
		: "=m"(ret)
		: "m"(nr), "m"(a), "m"(b), "m"(c)
	);

	return ret;
}

static void _exit(int status)
{
	_spim_syscall(_SPIM_NR_EXIT2, status, 0, 0);
}

static int close(int fd)
{
	return _spim_syscall(_SPIM_NR_CLOSE, fd, 0, 0);
}

static int open(const char *name, int flags, ...)
{
	__builtin_va_list va;
	__builtin_va_start(va, flags);
	int mode = __builtin_va_arg(va, int);
	return _spim_syscall(_SPIM_NR_OPEN, (long) name, flags, mode);
}

static long read(int fd, char *ptr, int len)
{
	return _spim_syscall(_SPIM_NR_READ, fd, (long) ptr, len);
}

static void *sbrk(long incr)
{
	return (void *) _spim_syscall(_SPIM_NR_SBRK, incr, 0, 0);
}

static ssize_t write(int fd, const void *ptr, size_t len)
{
	return _spim_syscall(_SPIM_NR_WRITE, fd, (long) ptr, len);
}
