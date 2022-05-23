#pragma once
#include <string>
#include <vector>

using Position = long long int;

/** Show the contents of str around the position pos.
    Control characters (e.g. \n) are shown as @s. */
void show_context(const std::string& str, Position pos);