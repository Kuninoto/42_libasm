#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <memory.h>
#include <fcntl.h>
#include "./munit/munit.h"

#define UNEXISTENT_FD 42

ssize_t ft_write(int __fd, const void *__buf, ssize_t __n);
ssize_t ft_read(int __fd, void *__buf, ssize_t __nbytes);

int main(void)
{
    printf("TESTING FT_WRITE\n");
    char nickname[] = "Kuninoto\n";

    munit_log(MUNIT_LOG_INFO, "testing return values...");
    ssize_t ft_write_ret = ft_write(STDOUT_FILENO, nickname, 9);
    ssize_t write_ret = write(STDOUT_FILENO, nickname, 9);
    munit_assert_long(ft_write_ret, ==, write_ret);

    munit_log(MUNIT_LOG_INFO, "testing errno...");

    // EBADF (9) - Bad file descriptor
    ft_write(UNEXISTENT_FD, nickname, 9);
    int ft_write_errno = errno;
    write(UNEXISTENT_FD, nickname, 9);
    int write_errno = errno;
    munit_assert_string_equal(strerror(ft_write_errno), strerror(write_errno));
    munit_assert_long(ft_write_errno, ==, write_errno);
    
    // EFAULT (14) - Bad Address
    ft_write(STDOUT_FILENO, NULL, 2);
    int ft_write_errno2 = errno;
    write(STDOUT_FILENO, NULL, 2);
    int write_errno2 = errno;
    munit_assert_string_equal(strerror(ft_write_errno2), strerror(write_errno2));
    munit_assert_long(ft_write_errno2, ==, write_errno2);

    printf("TESTING FT_READ\n");
    int file_fd = open("foo.txt", O_RDONLY);
    char *ft_read_buffer = malloc(9 * sizeof(char));
    char *read_buffer = malloc(9 * sizeof(char));

    munit_log(MUNIT_LOG_INFO, "testing read strings && return values...");
    ssize_t ft_read_ret = ft_read(file_fd, ft_read_buffer, 9);
    lseek(file_fd, 0, SEEK_SET); // reset the file cursor
    ssize_t read_ret = read(file_fd, read_buffer, 9);
    munit_assert_string_equal(ft_read_buffer, read_buffer);
    munit_assert_long(ft_read_ret, ==, read_ret);

    memset(ft_read_buffer, 0, 9);
    memset(read_buffer, 0, 9);
    munit_log(MUNIT_LOG_INFO, "testing errno...\n");

    // EBADF (9) - Bad file descriptor
    ft_read(UNEXISTENT_FD, ft_read_buffer, 9);
    int ft_read_errno = errno;
    read(UNEXISTENT_FD, read_buffer, 9);
    int read_errno = errno;
    munit_assert_string_equal(strerror(ft_read_errno), strerror(read_errno));
    munit_assert_long(ft_read_errno, ==, read_errno);

    // EFAULT (14) - Bad Address
    ft_read(file_fd, NULL, 9);
    int ft_read_errno2 = errno;
    read(file_fd, NULL, 9);
    int read_errno2 = errno;
    munit_assert_string_equal(strerror(ft_read_errno2), strerror(read_errno2));
    munit_assert_long(ft_read_errno2, ==, read_errno2);

    return EXIT_SUCCESS;
}
