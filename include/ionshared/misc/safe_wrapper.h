#pragma once

#include "wrapper.h"

namespace ionshared {
    template<typename T>
    class SafeWrapper : public Wrapper<T> {
    public:
        explicit SafeWrapper(T value) : Wrapper<T>(value) {
            if (value == nullptr) {
                throw std::runtime_error("Cannot construct LLVM entity wrapper with a null value");
            }
        }
    };
}
