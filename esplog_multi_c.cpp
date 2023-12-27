#include "esplog_multi_c.h"
#include "esplog_multi.hpp"

void add_log_CB(Callback cb)
{
    esplog_multi::EsplogMulti::getInstance()->add_log_CB(cb);
}
