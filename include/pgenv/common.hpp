#pragma once

constexpr auto pgenv_version = "1.4.0";

namespace pg
{

enum class commands
{
    use_command,
	start_command,
	stop_command,
	restart_command,
	status_command,
	switch_command,
	clear_command,
	build_command,
	rebuild_command,
	remove_command,
	version_command,
	current_command,
	versions_command,
	help_command,
	available_command,
	check_command,
	config_command,
	log_command
};

} // pg
