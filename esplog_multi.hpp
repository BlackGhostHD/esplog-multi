#pragma once

#include <freertos/FreeRTOS.h>
#include <freertos/semphr.h>
#include <stdarg.h>

#include <memory>
#include <vector>

#ifdef __cplusplus
extern "C"
{
#endif

    typedef int (*Callback)(const char *fmt, va_list arg);
    static SemaphoreHandle_t mutex_{xSemaphoreCreateMutex()};

    namespace esplog_multi
    {

        class EsplogMulti
        {
        public:
            /**
             * Returns the singleton instance of this class.
             * @return The singleton instance of this class.
             */
            static EsplogMulti *getInstance();

            EsplogMulti();
            ~EsplogMulti(){};

            EsplogMulti(const EsplogMulti &) = delete;
            EsplogMulti &operator=(const EsplogMulti &) = delete;

            void add_log_CB(Callback);

            std::vector<Callback> callbacks_;

        private:
            inline static std::unique_ptr<EsplogMulti> pInstance_{nullptr};
        };

    } // namespace esplog_multi

#ifdef __cplusplus
}
#endif
