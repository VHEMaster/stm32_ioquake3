#include "Log.hpp"

#include <ctime>
#include <stdarg.h>

  const osMutexAttr_t mutex_attributes = {
    .name = "SwGLMutex",
    .attr_bits = osMutexRecursive,
    .cb_mem = NULL,
    .cb_size = 0
  };


namespace SWGL {



    Log::Log() {

      m_file = (FIL*)pvPortMalloc(sizeof(FIL));
      if(m_file == NULL)
      {
        fres = FR_INT_ERR;
        return;
      }
      m_mutex = osMutexNew(&mutex_attributes);
      fres = f_open(m_file, LOG_FILENAME, FA_WRITE | FA_OPEN_APPEND);
    }

    Log::~Log() {

        if (m_file != nullptr) {

            f_close(m_file);
            vPortFree(m_file);
        }
    }



    Log &Log::getInstance() {

        static Log instance;
        return instance;
    }

    void Log::printf(const char *fmt, ...) {

        if (m_file != nullptr) {

            osMutexAcquire(m_mutex, 200);
            //std::lock_guard<std::mutex> cs(m_mutex);

            //tm t;
            //time_t tt = time(NULL);
            //localtime_s(&t, &tt);

            //char timeBuf[256] = {0};
            //strftime(timeBuf, sizeof(timeBuf) - 1, "[%c] ", &t);
            //f_printf(m_file, timeBuf);

            va_list argptr;
            va_start(argptr, fmt);
            vsnprintf(logBuf, LOG_BUFFERSIZE-1, fmt, argptr);
            va_end(argptr);

            f_printf(m_file, logBuf);
            #if SWGL_ENABLE_LOG_FLUSH
            f_sync(m_file);
            #endif
            osMutexRelease(m_mutex);
        }
    }
}
