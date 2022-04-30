#pragma once

#include <CommandBase.hpp>
#include <Defines.hpp>
#include <DrawBuffer.hpp>
//#include <condition_variable>
//#include <thread>
//#include <mutex>
//#include <memory>
#include "LockFreeQueue.hpp"
#include "cmsis_os.h"

namespace SWGL {

    // Forward declarations
    class DrawThread;

    // Type aliases
    using DrawThreadPtr = std::unique_ptr<DrawThread>;

    //
    // Implements the drawing thread which executes commands from the renderer
    //
    class DrawThread {

    public:
        DrawThread(DrawBufferPtr drawBuffer);
        ~DrawThread() = default;

    public:
        void start();
        void join();

    private:
        static void run(void *argument);

    public:
        void addCommand(CommandPtr command);
        DrawBuffer &getDrawBuffer() { return *m_drawBuffer; }

    private:
        int m_workloadEstimate;
        bool m_isWorkAvailable;
        //TODO!!!
        int m_workAvailable;
        osMutexId_t m_mutex;
        osMessageQueueId_t m_commandQueue;
        osThreadId_t m_thread;

    private:
        DrawBufferPtr m_drawBuffer;
    };
}
