#include "DrawThread.hpp"

#include <cstring>

#include "Log.hpp"


  const osMutexAttr_t mutex_attributes = {
    .name = "SwGLMutex",
    .attr_bits = osMutexRecursive,
    .cb_mem = NULL,
    .cb_size = 0
  };

namespace SWGL {
    DrawThread::DrawThread(DrawBufferPtr drawBuffer)

        : m_drawBuffer(drawBuffer) {
      m_commandQueue = osMessageQueueNew(32, sizeof(CommandPtr), NULL);
      m_mutex = osMutexNew(&mutex_attributes);

    }

    void DrawThread::start() {

      osThreadAttr_t taskAttrs;
      memset(&taskAttrs, 0, sizeof(osThreadAttr_t));
      taskAttrs.name = "SwGLRender";
      taskAttrs.priority = (osPriority_t) osPriorityAboveNormal;
      taskAttrs.stack_size = 8192;

      m_workloadEstimate = 0;
      m_isWorkAvailable = false;
      m_thread = osThreadNew(DrawThread::run, static_cast<void*>(this), &taskAttrs);

    }

    void DrawThread::join() {
      //osThreadJoin(m_thread);

      eTaskState state;
      if(m_thread == NULL)
        return;
      do
      {
        osDelay(1);
        state = eTaskGetState((TaskHandle_t)m_thread);
      } while(state == eRunning);
    }



    void DrawThread::addCommand(CommandPtr command) {

        osStatus_t status;
        //auto isFlushingQueue = command->isFlushingQueue();
        int workloadEstimate = command->getWorkLoadEstimate();

        // This is used to not overburden or starve the threads with too many / too few triangles.
        // If it goes beyond a certain threshold the drawing process is forced to start. It's only
        // a hack until something more sophisticated will replace this - but it isn't "bad" as it
        // increases the FPS by a significant amount.

        m_workloadEstimate += workloadEstimate;

        do
        {
          status = osMessageQueuePut(m_commandQueue, (const void *)&command, 0, 5);
        } while(status != osOK);

        if (m_workloadEstimate >= 32) {
        
            m_workloadEstimate = 0;
        }
    }



    void DrawThread::run(void *argument)
    {
        DrawThread* thread = static_cast<DrawThread*>(argument);
        osStatus_t status;
        CommandPtr cmd;
        for (;;)
        {
            do
            {
              status = osMessageQueueGet(thread->m_commandQueue, (void *)&cmd, NULL, 1000);
              if(status == osOK)
              {
                if (!cmd->execute(thread))
                {
                   vTaskDelete(NULL);
                }
              }
            } while(status == osOK);
        }
    }
}
