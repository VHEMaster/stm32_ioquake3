#include "CommandClearDepth.hpp"

#include "DrawThread.hpp"
namespace SWGL {

    bool CommandClearDepth::execute(DrawThread *thread) {

        thread->getDrawBuffer().clearDepth(m_value, m_minX, m_minY, m_maxX, m_maxY);

        return true;
    }
}
