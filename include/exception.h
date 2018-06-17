#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <stdexcept>
#include <string>

class CannonException : public std::runtime_error
{
public:
    CannonException(const std::string& msg);
    virtual ~CannonException() noexcept;
};

#endif // EXCEPTION_H
