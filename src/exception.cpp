#include <pgenv/exception.hpp>

constexpr auto unloaded_instance_message =
R"(No version of PostgreSQL currently in use!
To use a specific version run
    pgenv use <version>
To start immediatly a specific version run
    pgenv start <version>
To see all locally installed clusters run
    pgenv versions

)";

namespace pg
{

unloaded_instance::unloaded_instance()
    : reason{unloaded_instance_message}
{
}

char const* unloaded_instance::what() const noexcept
{
    return reason;
}

missing_installation::missing_installation(std::string postgres_version)
    : reason{
        std::string{"PostgreSQL "}
        + std::move(postgres_version)
        + std::string{" not installed; installed versions:"}
    }
{
}

char const* missing_installation::what() const noexcept
{
    return reason.c_str();
}

} // pg
