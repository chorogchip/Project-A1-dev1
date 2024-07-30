#include "logger.h"

#include <cstdio>
#include "assert.h"

namespace logr {

    static cods::EActionResult Init() {
        Logger::GetGLogger() = Logger(Logger::Type::STDOUT);
        return cods::EActionResult::SUCCEED;
    }
    
    static cods::EActionResult Clear() {
        return cods::EActionResult::SUCCEED;
    }
    
    Logger::Logger(Type type) {
        switch(type) {
            case Type::STDOUT:

                break;
            case Type::STDERR:

                break;
            case Type::FILE_TXT:

                break;
            default:
                ASSERT_UNREACHABLE();
                break;
        }
    }
    
    Logger::~Logger() {
        fflush(stream_);
        if (fclose(stream_);
    }

    cods::EActionResult Logger::Log(const char* msg) {
        const int res = fputs(msg, stream_);
        if (res == EOF) return cods::EActionResult::FAILED;
        else return cods::EActionResult::SUCCEED;
    }
}