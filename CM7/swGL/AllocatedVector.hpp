#pragma once

#include <AlignedAllocator.hpp>
#include <vector>
#include <memory>

namespace SWGL {

    // Type aliases
    template<typename T>
    using AllocatedVector = std::vector<T, AlignedAllocator<T, 4>>;

}
