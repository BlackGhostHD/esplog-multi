#include <stdarg.h>

#ifdef __cplusplus
extern "C"
{
#endif

    typedef int (*Callback)(const char *fmt, va_list arg);
    void add_log_CB(Callback cb);

#ifdef __cplusplus
}
#endif
