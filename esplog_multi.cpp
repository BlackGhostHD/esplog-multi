#include "esplog_multi.hpp"
#include "esp_log.h"

static int log_vprintf(const char *fmt, va_list arg)
{
    auto o = esplog_multi::EsplogMulti::getInstance();
    for (auto it = o->callbacks_.begin(); it != o->callbacks_.end(); it++)
    {
        (*it)(fmt, arg);
    }
    return 0;
}

namespace esplog_multi
{

    EsplogMulti::EsplogMulti()
    {
        esp_log_set_vprintf(log_vprintf);
    }

    EsplogMulti *EsplogMulti::getInstance()
    {
        if (pInstance_ == nullptr)
        {
            xSemaphoreTake(mutex_, portMAX_DELAY);
            if (pInstance_ == nullptr)
            {
                pInstance_ = std::unique_ptr<EsplogMulti>(new EsplogMulti());
            }
            xSemaphoreGive(mutex_);
        }
        return pInstance_.get();
    }

    void EsplogMulti::add_log_CB(Callback cb)
    {
        xSemaphoreTake(mutex_, portMAX_DELAY);
        callbacks_.push_back(cb);
        xSemaphoreGive(mutex_);
    }

}
