// Include own header FIRST
#include "data_manager.h"

// Standard library includes
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// Third-party libraries
#include <nlohmann/json.hpp>

using json = nlohmann::json;

std::vector<Goal> loadDataFromFile(std::string filename) {
  std::ifstream file(filename);
  json j;
  file >> j;
  std::vector<Goal> goals;

  for (const auto &goalJson : j["goals"]) {
    Goal goal;
    goal.id = goalJson.value("id", "");
    goal.title = goalJson["title"];
    goal.description = goalJson["description"];

    goals.push_back(goal);
  }
  return goals;
}

void saveData(const std::vector<Goal>& goals, std::string filename) {
  int i = 0;
  json j;
  j["goals"] = json::array(); // Create empty array

  for (const Goal& goal : goals) {
    json goalJson;
    goalJson["title"] = goal.title;
    goalJson["description"] = goal.description;
    goalJson["id"] = goal.id;
    goalJson["orderIndex"] = ++i;

    std::cout << goalJson << std::endl;
    j["goals"].push_back(goalJson);
  }

  std::ofstream saveFile(filename);
  if (saveFile.is_open()) {
    saveFile << j;
  }
  saveFile.close();
}
