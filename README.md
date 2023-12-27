# esplog-multi

ESP only permits overwriting the log function using a singular callback function. esplog-multi enables the registration of multiple callback functions to be executed in the sequence of their registration.

#### How to install
1. Create the `idf_component.yml` manifest: `idf.py create-manifest --component=main` ([more information](https://docs.espressif.com/projects/esp-idf/en/v5.1/esp32/api-guides/tools/idf-component-manager.html))
2. Add the following entry to your manifest file:
    ```
   esplog-multi:
      git: "https://github.com/BlackGhostHD/esplog-multi.git"
   ```
3. Run `idf.py reconfigure`
4. Add `esplog-multi` to your `PRIV_REQUIRES` or `REQUIRES`

#### How to use
###### C:
```C
#include "esplog_multi_c.h"

static int some_cb(const char *fmt, va_list arg) { ... }

int main()
{
    ...
    add_log_CB(some_cb);
}

```


###### C++:
```C++
#include "esplog_multi.hpp"

static int some_cb(const char *fmt, va_list arg) { ... }

int main()
{
    ...
    esplog_multi::EsplogMulti::getInstance()->add_log_CB(some_cb);
}

```
