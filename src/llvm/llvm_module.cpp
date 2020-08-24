#include <iostream>
#include <llvm/Support/raw_os_ostream.h>
#include <ionshared/llvm/llvm_module.h>

namespace ionshared {
    LlvmModule::LlvmModule(llvm::Module *module, LlvmContext *context) : Wrapper(module), context(context) {
        //
    }

    LlvmModule::LlvmModule(llvm::Module *module)
        : LlvmModule(module, new LlvmContext(&module->getContext())) {
        //
    }

    LlvmModule::~LlvmModule() {
        delete this->context;
    }

    std::string LlvmModule::getId() const {
        // TODO: Can it possibly be null?
        return this->value->getModuleIdentifier();
    }

    LlvmContext *LlvmModule::getContext() const {
        return this->context;
    }

    std::string LlvmModule::getAsString() const {
        std::string result;
        llvm::raw_string_ostream OS(result);

        OS << *this->value;
        OS.flush();

        return result;
    }

    void LlvmModule::print() {
        std::cout << this->getAsString();
    }

    void LlvmModule::printToLlvmErrs() const {
        this->value->print(llvm::errs(), nullptr);
    }
}
