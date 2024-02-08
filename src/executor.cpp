#include <pgenv/executor.hpp>

namespace pg
{

void executor::run(argument_parser const& parser)
{
    switch (parser.selected_command)
    {
        case pg::commands::use_command:
            break;
        case pg::commands::start_command:
            break;
        case pg::commands::stop_command:
            break;
        case pg::commands::restart_command:
            break;
        case pg::commands::status_command:
            break;
        case pg::commands::switch_command:
            break;
        case pg::commands::clear_command:
            break;
        case pg::commands::build_command:
            break;
        case pg::commands::rebuild_command:
            break;
        case pg::commands::remove_command:
            break;
        case pg::commands::version_command:
            check_installation(parser.option_value);
            break;
        case pg::commands::current_command:
            break;
        case pg::commands::versions_command:
            break;
        case pg::commands::help_command:
            std::cout << parser << std::endl;
            break;
        case pg::commands::available_command:
            break;
        case pg::commands::check_command:
            break;
        case pg::commands::config_command:
            break;
        case pg::commands::log_command:
            break;
        default:
            std::cout << parser << std::endl;
    }
}

void executor::execute_version()
{
}

void executor::check_installation(std::string_view version) const
{
}

void executor::check_usage(std::string_view version) const
{
}

std::vector<std::string> executor::installed_instances() const
{
    return {};
}

} // pg
