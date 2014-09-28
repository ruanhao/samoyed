#include "h_msg.h"

#define H_ERROR    1
#define H_NO_ERROR 0
#define MAX_LENGTH 1024

static void h_do_msg(int errflag, const char *fmt, va_list ap) {
    char buf[MAX_LENGTH + 1];
    vsnprintf(buf, MAX_LENGTH, fmt, ap);
    if (errflag) {
        int len     = strlen(buf);
        int m_error = errno;
        snprintf(buf + len, MAX_LENGTH - len, " (error: %s)", strerror(m_error));
    }
    strcat(buf, "\n");
    fputs(buf, stderr);
    fflush(stderr);
    return;
}

void h_debug_msg(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    h_do_msg(H_NO_ERROR, fmt, ap);
    va_end(ap);
    return;
}

void h_error_msg(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    h_do_msg(H_ERROR, fmt, ap);
    va_end(ap);
    return;
}
