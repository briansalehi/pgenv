#pragma once

#include <pgenv/common.hpp>
#include <pgenv/arguments_parser.hpp>
#include <iostream>

namespace pg
{

class executor
{
public:
    void run(arguments_parser const& parser);

private:
};

} // pg
