#pragma once

#include <pgenv/common.hpp>
#include <boost/program_options.hpp>

#include <string>
#include <vector>
#include <iostream>
#include <string_view>

namespace pg
{

class argument_parser
{
public:
    argument_parser(int argc, char** argv);

    void set_command(std::string_view command);
    friend std::ostream& operator<<(std::ostream&, argument_parser const&);

private:
    boost::program_options::options_description user_options;
    boost::program_options::variables_map options_mapping;
    boost::program_options::positional_options_description command_options;

public:
    commands selected_command;
    std::string command_name;
    std::string option_value;
};

} // pg

