#include "exception.h"

CannonException::CannonException(const std::string& msg)
    : std::runtime_error(msg) {}

CannonException::~CannonException() noexcept = default;
