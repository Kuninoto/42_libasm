#pragma once

#include <unistd.h>

ssize_t ft_read(int __fd, void *__buf, ssize_t __nbytes);
int ft_strcmp(const char *__s1, const char *__s2);
char *ft_strcpy(char *dest, const char *src);
char *ft_strdup(const char *s);
size_t ft_strlen(const char *__s);
ssize_t ft_write(int __fd, const void *__buf, ssize_t __n);
