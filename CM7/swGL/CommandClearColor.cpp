#include "CommandClearColor.hpp"

#include "DrawThread.hpp"
namespace SWGL {

    bool CommandClearColor::execute(DrawThread *thread) {

        thread->getDrawBuffer().clearColor(m_value, m_minX, m_minY, m_maxX, m_maxY);

        return true;
    }
}
