#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

#include <string>
#include <vector>
#include "models.h"

// Load goals from JSON file
std::vector<Goal> loadDataFromFile(std::string filename);

// Save goals to JSON file
void saveData(const std::vector<Goal>& goals, std::string filename);

#endif // DATA_MANAGER_H
