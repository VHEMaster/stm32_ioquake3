#include "CommandPoisonPill.hpp"

#include "DrawThread.hpp"
namespace SWGL {

    //
    // A command used to shutdown a thread
    //
    bool CommandPoisonPill::execute(DrawThread *thread) {

        return false;
    }
}
