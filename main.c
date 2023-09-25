#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <memory.h>
#include <fcntl.h>
#include "./munit/munit.h"
#include "./libasm/libasm.h"

#define UNEXISTENT_FD 231031

void test_ft_strlen(void)
{
    printf("TESTING FT_STRLEN\n");
    char str[] = "foo";
    char empty[] = "";

    munit_log(MUNIT_LOG_INFO, "testing return values...");
    size_t ft_strlen_ret_1 = ft_strlen(str);
    size_t strlen_ret_1 = strlen(str);

    size_t ft_strlen_ret_2 = ft_strlen(empty);
    size_t strlen_ret_2 = strlen(empty);

    munit_assert_ulong(ft_strlen_ret_1, ==, strlen_ret_1);
    munit_assert_ulong(ft_strlen_ret_2, ==, strlen_ret_2);
    munit_assert_ulong(ft_strlen_ret_2, !=, strlen_ret_1);

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

    munit_assert_string_equal(s1_ft, s2_ft);
    munit_assert_string_equal(s1_og, s2_og);

    munit_assert_string_equal(s1_og, s1_ft);
    munit_assert_string_equal(s2_og, s2_ft);

    write(STDOUT_FILENO, "\n", 1);
}

void test_ft_strcmp(void)
{
    printf("TESTING FT_STRCMP\n");
    char s1[] = "bar";
    char s2[] = "bar";

    char s3[] = "bar";
    char s4[] = "baz";

    char s5[] = "";
    char s6[] = "";

    munit_log(MUNIT_LOG_INFO, "testing return values...");
    int s1_s2_og_ret = strcmp(s1, s2);
    int s3_s4_og_ret = strcmp(s3, s4);
    int s5_s6_og_ret = strcmp(s5, s6);

    int s1_s2_ft_ret = ft_strcmp(s1, s2);
    int s3_s4_ft_ret = ft_strcmp(s3, s4);
    int s5_s6_ft_ret = ft_strcmp(s5, s6);

    // printf("s1_s2_og_ret = %d\n", s1_s2_og_ret);
    // printf("s1_s2_ft_ret = %d\n", s1_s2_ft_ret);

    // printf("s3_s4_og_ret = %d\n", s3_s4_og_ret);
    // printf("s3_s4_ft_ret = %d\n", s3_s4_ft_ret);

    // printf("s5_s6_og_ret = %d\n", s5_s6_og_ret);
    // printf("s5_s6_ft_ret = %d\n", s5_s6_ft_ret);

    munit_assert_int(s1_s2_og_ret, ==, s1_s2_ft_ret);
    munit_assert_int(s3_s4_og_ret, ==, s3_s4_ft_ret);
    munit_assert_int(s5_s6_og_ret, ==, s5_s6_ft_ret);

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
    int ft_write_bad_fd_ret = ft_write(UNEXISTENT_FD, nickname, 9);
    int ft_write_errno = errno;

    int write_bad_fd_ret = write(UNEXISTENT_FD, nickname, 9);
    int write_errno = errno;

    munit_assert_int(ft_write_errno, ==, write_errno);
    munit_assert_string_equal(strerror(ft_write_errno), strerror(write_errno));
    munit_assert_int(ft_write_bad_fd_ret, ==, write_bad_fd_ret);

    // EFAULT (14) - Bad Address
    int ft_write_null_ret = ft_write(STDOUT_FILENO, NULL, 2);
    int ft_write_errno2 = errno;

    int write_null_ret = write(STDOUT_FILENO, NULL, 2);
    int write_errno2 = errno;

    munit_assert_string_equal(strerror(ft_write_errno2), strerror(write_errno2));
    munit_assert_int(ft_write_null_ret, ==, write_null_ret);
    munit_assert_int(ft_write_errno2, ==, write_errno2);

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
    int ft_read_bad_fd_ret = ft_read(UNEXISTENT_FD, ft_read_buffer, 9);
    int ft_read_errno = errno;

    int read_bad_fd_ret = read(UNEXISTENT_FD, read_buffer, 9);
    int read_errno = errno;

    munit_assert_long(ft_read_errno, ==, read_errno);
    munit_assert_string_equal(strerror(ft_read_errno), strerror(read_errno));
    munit_assert_long(ft_read_bad_fd_ret, ==, read_bad_fd_ret);

    // EFAULT (14) - Bad Address
    int ft_read_bad_fd_ret2 = ft_read(file_fd, NULL, 9);
    int ft_read_errno2 = errno;

    int read_bad_fd_ret2 = read(file_fd, NULL, 9);
    int read_errno2 = errno;

    munit_assert_int(ft_read_errno2, ==, read_errno2);
    munit_assert_string_equal(strerror(ft_read_errno2), strerror(read_errno2));
    munit_assert_int(ft_read_bad_fd_ret2, ==, read_bad_fd_ret2);

    free(ft_read_buffer);
    free(read_buffer);
    write(STDOUT_FILENO, "\n", 1);
}

void test_ft_strdup(void)
{
    printf("TESTING FT_STRDUP\n");
    char s1[] = "foo";
    char s2[] = "bar";
    char s3[] = {129, '\0'};
    char s4[] = "";

    munit_log(MUNIT_LOG_INFO, "testing return values...");
    char *s1_og_ret = strdup(s1);
    char *s1_ft_ret = ft_strdup(s1);

    char *s2_og_ret = strdup(s2);
    char *s2_ft_ret = ft_strdup(s2);

    char *s3_og_ret = strdup(s3);
    char *s3_ft_ret = ft_strdup(s3);

    char *s4_og_ret = strdup(s4);
    char *s4_ft_ret = ft_strdup(s4);

    munit_assert_string_equal(s1_og_ret, s1_ft_ret);
    munit_assert_string_equal(s2_og_ret, s2_ft_ret);
    munit_assert_string_equal(s3_og_ret, s3_ft_ret);
    munit_assert_string_equal(s4_og_ret, s4_ft_ret);

    // printf("%s\n", s1_og_ret);
    // printf("%s\n", s1_ft_ret);

    // printf("%s\n", s2_og_ret);
    // printf("%s\n", s2_ft_ret);

    // printf("%s\n", s3_og_ret);
    // printf("%s\n", s3_ft_ret);

    // printf("%s\n", s4_og_ret);
    // printf("%s\n", s4_ft_ret);

    free(s1_og_ret);
    free(s1_ft_ret);

    free(s2_og_ret);
    free(s2_ft_ret);

    free(s3_og_ret);
    free(s3_ft_ret);

    free(s4_og_ret);
    free(s4_ft_ret);
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
