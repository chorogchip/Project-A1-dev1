#pragma once

#include <cstdio>
#include "codes.h"

namespace logr {

    static cods::EActionResult Init();
    static cods::EActionResult Clear();

    class Logger {
    private:
        static Logger g_logger_;

        FILE* stream_;
    
        Logger(): stream_(nullptr) {}
    public:
        static Logger& GetGLogger() { return g_logger_; }
    
        enum class Type {
            STDOUT,
            STDERR,
            FILE_TXT,
        };
        Logger(Type type);
        ~Logger();
    
        cods::EActionResult Log(const char* msg);
    };
    
}
