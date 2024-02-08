#include <pgenv/pgenv.hpp>
#include <pgenv/arguments_parser.hpp>
#include <ostream>

using namespace pg;

arguments_parser::arguments_parser(int argc, char** argv):
    user_options("The pgenv commands are")
{
    user_options.add_options()
        ("use",       boost::program_options::value<std::string>(),
                      "Set and start the current PostgreSQL version")
        ("start",     "Start the current PostgreSQL server")
        ("stop",      "Stop the current PostgreSQL server")
        ("restart",   "Restart the current PostgreSQL server")
        ("status",    "Show the current PostgreSQL server status")
        ("switch",    boost::program_options::value<std::string>(),
                      "Set the current PostgreSQL version")
        ("clear",     "Stop and unset the current PostgreSQL version")
        ("build",     boost::program_options::value<std::string>(),
                      "Build a specific version of PostgreSQL")
        ("rebuild",   boost::program_options::value<std::string>(),
                      "Re-build a specific version of PostgreSQL")
        ("remove",    boost::program_options::value<std::string>(),
                      "Remove a specific version of PostgreSQL")
        ("version",   "Show the current PostgreSQL version")
        ("current",   "Same as 'version'")
        ("versions",  "List all PostgreSQL versions available to pgenv")
        ("help",      "Show this usage statement and command summary")
        ("available", "Show which versions can be downloaded")
        ("check",     "Only available for historical scripting compatibility")
        ("config",    "View, edit, delete the program configuration")
        ("log",       "Inspects the log of the cluster, if exist");

    boost::program_options::options_description hidden_options;
    hidden_options.add_options()
        ("command",   boost::program_options::value<std::vector<std::string>>(), "");

    boost::program_options::options_description all_options;
    all_options.add(user_options).add(hidden_options);

    command_options.add("command", -1);

    try
    {
        boost::program_options::command_line_parser parser{argc, argv};
        parser = parser.positional(command_options).options(all_options);
        boost::program_options::store(parser.run(), options_mapping);
        boost::program_options::notify(options_mapping);
    }
    catch (std::exception const& exp)
    {
        std::cerr << "arguments error: " << exp.what() << std::endl;
    }

    if (options_mapping.count("command"))
    {
        auto values = options_mapping["command"].as<std::vector<std::string>>();
        command_name = values.at(0);
        option_value = values.size() > 1 ? values.at(1) : std::string{};
        set_command(command_name);
    }

    if (options_mapping.count("use"))
    {
        selected_command = commands::use_command;
        option_value = option_value.empty() ? options_mapping["use"].as<std::string>() : option_value;
    }
    else if (options_mapping.count("start"))
    {
        selected_command = commands::start_command;
        option_value = option_value.empty() ? options_mapping["start"].as<std::string>() : option_value;
    }
    else if (options_mapping.count("stop"))
    {
        selected_command = commands::stop_command;
        option_value = option_value.empty() ? options_mapping["stop"].as<std::string>() : option_value;
    }
    else if (options_mapping.count("restart"))
    {
        selected_command = commands::restart_command;
        option_value = option_value.empty() ? options_mapping["restart"].as<std::string>() : option_value;
    }
    else if (options_mapping.count("status"))
    {
        selected_command = commands::status_command;
        option_value = option_value.empty() ? options_mapping["status"].as<std::string>() : option_value;
    }
    else if (options_mapping.count("switch"))
    {
        selected_command = commands::switch_command;
        option_value = option_value.empty() ? options_mapping["switch"].as<std::string>() : option_value;
    }
    else if (options_mapping.count("build"))
    {
        selected_command = commands::build_command;
        option_value = option_value.empty() ? options_mapping["build"].as<std::string>() : option_value;
    }
    else if (options_mapping.count("rebuild"))
    {
        selected_command = commands::rebuild_command;
        option_value = option_value.empty() ? options_mapping["rebuild"].as<std::string>() : option_value;
    }
    else if (options_mapping.count("remove"))
    {
        selected_command = commands::remove_command;
        option_value = option_value.empty() ? options_mapping["remove"].as<std::string>() : option_value;
    }
    else if (options_mapping.count("version"))
    {
        selected_command = commands::version_command;
        option_value = option_value.empty() ? options_mapping["version"].as<std::string>() : option_value;
    }
    else if (options_mapping.count("current"))
    {
        selected_command = commands::current_command;
        option_value = option_value.empty() ? options_mapping["current"].as<std::string>() : option_value;
    }
    else if (options_mapping.count("versions"))
    {
        selected_command = commands::versions_command;
        option_value = option_value.empty() ? options_mapping["versions"].as<std::string>() : option_value;
    }
    else if (options_mapping.count("help"))
    {
        selected_command = commands::help_command;
        option_value = option_value.empty() ? options_mapping["help"].as<std::string>() : option_value;
    }
    else if (options_mapping.count("available"))
    {
        selected_command = commands::available_command;
        option_value = option_value.empty() ? options_mapping["available"].as<std::string>() : option_value;
    }
    else if (options_mapping.count("check"))
    {
        selected_command = commands::check_command;
        option_value = option_value.empty() ? options_mapping["check"].as<std::string>() : option_value;
    }
    else if (options_mapping.count("config"))
    {
        selected_command = commands::config_command;
        option_value = option_value.empty() ? options_mapping["config"].as<std::string>() : option_value;
    }
    else if (options_mapping.count("log"))
    {
        selected_command = commands::log_command;
        option_value = option_value.empty() ? options_mapping["log"].as<std::string>() : option_value;
    }
}

void arguments_parser::set_command(std::string_view command)
{
    if      (command == "use")       { selected_command = commands::use_command; }
    else if (command == "start")     { selected_command = commands::start_command; }
    else if (command == "stop")      { selected_command = commands::stop_command; }
    else if (command == "restart")   { selected_command = commands::restart_command; }
    else if (command == "status")    { selected_command = commands::status_command; }
    else if (command == "switch")    { selected_command = commands::switch_command; }
    else if (command == "clear")     { selected_command = commands::clear_command; }
    else if (command == "build")     { selected_command = commands::build_command; }
    else if (command == "rebuild")   { selected_command = commands::rebuild_command; }
    else if (command == "remove")    { selected_command = commands::remove_command; }
    else if (command == "version")   { selected_command = commands::version_command; }
    else if (command == "current")   { selected_command = commands::current_command; }
    else if (command == "versions")  { selected_command = commands::versions_command; }
    else if (command == "help")      { selected_command = commands::help_command; }
    else if (command == "available") { selected_command = commands::available_command; }
    else if (command == "check")     { selected_command = commands::check_command; }
    else if (command == "config")    { selected_command = commands::config_command; }
    else if (command == "log")       { selected_command = commands::log_command; }
}

namespace pg
{
std::ostream& operator<<(std::ostream& buffer, arguments_parser const& options)
{
    buffer << "Usage: pgenv <command> [<args>]\n\n";
    buffer << options.user_options << '\n';
    buffer << "For full documentation, see: ";
    buffer << "https://github.com/theory/pgenv#readme\n\n";
    buffer << "This is 'pgenv' version " << pgenv_version;
    return buffer;
}
} // pg
