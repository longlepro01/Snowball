#ifndef UTILS_H
#define UTILS_H

#include <string>

// Generate a UUID-like string
std::string generateUUID();

// Get single key press without waiting for Enter
// NOTE: Currently uses platform-specific code (Linux/Unix only)
// TODO: Make cross-platform compatible
char getKey();

#endif // UTILS_H
