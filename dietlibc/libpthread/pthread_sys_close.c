#include <unistd.h>

#include <pthread.h>
#include "thread_internal.h"

int close(int fd) {
  __TEST_CANCEL();
  return __libc_close(fd);
}
