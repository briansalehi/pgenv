#pragma once

#include <exception>
#include <string>

namespace pg
{

class unloaded_instance : std::exception
{
public:
    unloaded_instance();
    virtual char const* what() const noexcept;

private:
    char const* reason;
};

class missing_installation : std::exception
{
public:
    missing_installation(std::string postgres_version);
    virtual char const* what() const noexcept;

private:
    std::string reason;
};

} // pg
