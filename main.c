#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include "./munit/munit.h"

#define UNEXISTENT_FD 42

ssize_t ft_write(int __fd, const void *__buf, ssize_t __n);

int main(void) {
    printf("TESTING FT_WRITE\n");
    char nickname[] = "Kuninoto\n";

    munit_log(MUNIT_LOG_INFO, "testing return values...\n");
    ssize_t ft_write_ret = ft_write(STDOUT_FILENO, nickname, 9);
    ssize_t write_ret = write(STDOUT_FILENO, nickname, 9);
    munit_assert_long(ft_write_ret, ==, write_ret);

    munit_log(MUNIT_LOG_INFO, "testing errno...\n");

    // EBADF (9) - Bad file descriptor
    ft_write(UNEXISTENT_FD, nickname, 9);
    int ft_write_errno = errno;
    printf("%s\n", strerror(ft_write_errno));

    write(UNEXISTENT_FD, nickname, 9);
    int write_errno = errno;
    printf("%s\n", strerror(write_errno));

    munit_assert_long(ft_write_errno, ==, write_errno);

    // EFAULT (14) - Bad Address
    ft_write(STDOUT_FILENO, NULL, 2);
    int ft_write_errno2 = errno;
    printf("%s\n", strerror(ft_write_errno2));

    write(STDOUT_FILENO, NULL, 2);
    int write_errno2 = errno;
    printf("%s\n", strerror(write_errno2));

    munit_assert_long(ft_write_errno2, ==, write_errno2);

    return EXIT_SUCCESS;
}
