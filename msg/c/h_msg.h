#ifndef H_MSG_H
#define H_MSG_H

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

void h_debug_msg(const char *fmt, ...);

void h_error_msg(const char *fmt, ...);

#define H_DEBUG_MSG(fmt, ...) h_debug_msg("<%s>(%s@%d)[%s]: " \
                                          fmt, __FILE__, __func__, __LINE__, __TIME__, ##__VA_ARGS__)

#define H_ERROR_MSG(fmt, ...) h_error_msg("<%s>(%s@%d)[%s]: " \
                                          fmt, __FILE__, __func__, __LINE__, __TIME__, ##__VA_ARGS__)

#endif /* H_MSG_H */
