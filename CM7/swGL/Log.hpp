#pragma once

#include <Defines.hpp>
#include <cstdio>
#include "fatfs.h"
#include "cmsis_os.h"
#if _DEBUG || SWGL_ENABLE_LOGGING
#define LOG(FMT, ...) SWGL::Log::getInstance().printf("[%s:%d, %s] " FMT "\n", __FILE__, __LINE__, __FUNCTION__, ## __VA_ARGS__)
#else
#define LOG(FMT, ...) (void)0
#endif

namespace SWGL {

    //
    // Implementation of a simple data logger
    //
    class Log {

    public:
        ~Log();

        static Log &getInstance();
        void printf(const char *fmt, ...);

    private:
        Log();

    private:
        static constexpr const char *LOG_FILENAME = "swGL.log";
        static constexpr size_t LOG_BUFFERSIZE = 8192U;

        char logBuf[LOG_BUFFERSIZE];
        FRESULT fres = FR_OK;
        FIL *m_file;
        osMutexId_t m_mutex = NULL;

    };
}
