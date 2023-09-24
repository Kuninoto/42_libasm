#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <memory.h>
#include <fcntl.h>
#include "./munit/munit.h"

#define UNEXISTENT_FD 42

size_t ft_strlen(const char *__s);
char *ft_strcpy(char *dest, const char *src);
int ft_strcmp(const char *__s1, const char *__s2);
ssize_t ft_write(int __fd, const void *__buf, ssize_t __n);
ssize_t ft_read(int __fd, void *__buf, ssize_t __nbytes);
char *ft_strdup(const char *s);

void test_ft_strlen(void)
{
    printf("TESTING FT_STRLEN\n");
    char str[] = "foo";

    munit_log(MUNIT_LOG_INFO, "testing return values...");
    size_t ft_strlen_ret = ft_strlen(str);
    size_t strlen_ret = strlen(str);
    munit_assert_ulong(ft_strlen_ret, ==, strlen_ret);

    write(STDOUT_FILENO, "\n", 1);
};

void test_ft_strcpy(void)
{
    printf("TESTING FT_STRCPY\n");
    char s1_ft[] = "bar";
    char s2_ft[] = "zzz";
    char s1_og[] = "bar";
    char s2_og[] = "zzz";

    munit_log(MUNIT_LOG_INFO, "testing return values...");
    char *ft_strcpy_ret = ft_strcpy(s1_ft, s2_ft);
    char *strcpy_ret = strcpy(s1_og, s2_og);
    munit_assert_string_equal(ft_strcpy_ret, strcpy_ret);

    write(STDOUT_FILENO, "\n", 1);
}

void test_ft_strcmp(void)
{
    printf("TESTING FT_STRCMP\n");
    char s1[] = "bar";
    char s2[] = "bar";

    char s3[] = "bar";
    char s4[] = "baz";

    munit_log(MUNIT_LOG_INFO, "testing return values...");
    int s1_s2_og_ret = strcmp(s1, s2);
    int s3_s4_og_ret = strcmp(s3, s4);

    int s1_s2_ft_ret = ft_strcmp(s1, s2);
    int s3_s4_ft_ret = ft_strcmp(s3, s4);

    //printf("s1_s2_og_ret = %d\n", s1_s2_og_ret);
    //printf("s1_s2_ft_ret = %d\n", s1_s2_ft_ret);

    //printf("s3_s4_og_ret = %d\n", s3_s4_og_ret);
    //printf("s3_s4_ft_ret = %d\n", s3_s4_ft_ret);

    munit_assert_int(s1_s2_og_ret, ==, s1_s2_ft_ret);
    munit_assert_int(s3_s4_og_ret, ==, s3_s4_ft_ret);

    write(STDOUT_FILENO, "\n", 1);
}

void test_ft_write(void)
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

    write(STDOUT_FILENO, "\n", 1);
}

void test_ft_read(void)
{
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
    munit_log(MUNIT_LOG_INFO, "testing errno...");

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
    write(STDOUT_FILENO, "\n", 1);
}

void test_ft_strdup(void)
{
    printf("TESTING FT_STRDUP\n");
    char s1[] = "foo";
    char s2[] = "bar";

    munit_log(MUNIT_LOG_INFO, "testing return values...");
    char *s1_og_ret = strdup(s1);
    char *s1_ft_ret = ft_strdup(s1);

    char *s2_og_ret = strdup(s2);
    char *s2_ft_ret = ft_strdup(s2);

    munit_assert_string_equal(s1_og_ret, s1_ft_ret);
    munit_assert_string_equal(s2_og_ret, s2_ft_ret);

    free(s1_og_ret);
    free(s1_ft_ret);
    free(s2_og_ret);
    free(s2_ft_ret);
}

int main(void)
{
    test_ft_strlen();
    test_ft_strcpy();
    test_ft_strcmp();
    test_ft_write();
    test_ft_read();
    test_ft_strdup();
    return EXIT_SUCCESS;
}
