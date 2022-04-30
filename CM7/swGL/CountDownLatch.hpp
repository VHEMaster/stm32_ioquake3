#pragma once

//#include <mutex>
#include <atomic>
#include "cmsis_os.h"
#include "semphr.h"
//#include <condition_variable>

//TODO!!!! Multithreading

namespace SWGL {

    //
    // Implementation of a simple count down latch
    //
    class CountDownLatch {

    public:
        CountDownLatch()
        
            : m_count(0) {
           m_semaphore = xSemaphoreCreateBinary();

        }
        ~CountDownLatch() = default;

    public:
        void reset(int count) {

            m_count = count;
        }

        void countDown() {

            //std::lock_guard<std::mutex> cs(m_mutex);
            m_count--;
            if (m_count == 0) {

              xSemaphoreGive(m_semaphore);
                //m_condition.notify_one();
            }
        }

        void wait() {

          xSemaphoreTake(m_semaphore, 0xFFF0);
            //std::unique_lock<std::mutex> cs(m_mutex);
            //m_condition.wait(cs, [this] {
            
                //return m_count == 0;
            //});
        }

    private:
        //std::mutex m_mutex;
        SemaphoreHandle_t m_semaphore;
        std::atomic<int> m_count;
        //std::condition_variable m_condition;
    };
}
