//#pragma once
#include "types.h"
#include <Common.h>
#include "plugin_common.h"

typedef unsigned long long u64;
typedef unsigned long int size_t;
typedef long int ssize_t;
extern u64(*syscall)(int num, ...);
extern void *(*malloc)(size_t size);
extern void(*free)(void *ptr);
extern void *(*calloc)(size_t num, size_t size);
extern void *(*realloc)(void* ptr, size_t size);
extern void *(*memset)(void *destination, int value, size_t num);
extern void *(*memcpy)(void *destination, const void *source, size_t num);
extern int(*memcmp)(const void *s1, const void *s2, size_t n);
extern char *(*strcpy)(char *destination, const char *source);
extern char *(*strncpy)(char *destination, const char *source, size_t num);
extern char *(*strcat)(char *dest, const char *src);
extern char *(*strncat)(char *dest, const char *src, size_t n);
extern size_t(*strlen)(const char *s);
extern int(*strcmp)(const char *s1, const char *s2);
extern int(*strncmp)(const char *s1, const char *s2, size_t n);
extern int(*sprintf)(char *str, const char *format, ...);
extern int(*snprintf)(char *str, size_t size, const char *format, ...);
extern int(*sscanf)(const char *str, const char *format, ...);
extern char *(*strchr)(const char *s, int c);
extern char *(*strrchr)(const char *s, int c);
extern char *(*strstr)(char *str1, char *str2);
extern unsigned int *(*strspn)(const char * str1, const char * str2);
extern char* (*strpbrk)(const char * str1, const char * str2);
extern char* (*strtok)(char *str, const char *delim);
extern int(*atoi)(const char * str);
extern int(*isspace)(int c);
extern int(*isupper)(int c);
extern int(*islower)(int c);
extern int(*toupper)(int c);
extern double(*atof)(const char * str);
extern ssize_t (*read)(int fd, void *buf, size_t nbyte);
extern ssize_t (*write)(int fd, const void *buf, size_t count);
extern int (*close)(int fd);
extern int (*unlink)(const char *pathname);
extern int (*usleep)(unsigned int microseconds);
extern int (*clock)(void);
void initLibs();