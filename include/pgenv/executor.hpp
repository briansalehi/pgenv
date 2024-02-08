#pragma once

#include <pgenv/common.hpp>
#include <pgenv/argument_parser.hpp>

#include <string>
#include <vector>
#include <iostream>
#include <filesystem>
#include <string_view>

namespace pg
{

class executor
{
public:
    void run(argument_parser const& parser);

private:
    void execute_version();

    void check_installation(std::string_view version) const;
    void check_usage(std::string_view version) const;
    std::vector<std::string> installed_instances() const;
};

} // pg
