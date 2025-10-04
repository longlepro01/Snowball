#include <iostream>
#include <string>
#include <vector>
#include <termios.h>
#include <unistd.h>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

enum class Screen {
    Dashboard,
    AddGoal,
    ManageGoal,
    // Goal
    RandomTask
};

Screen currentScreen = Screen::Dashboard;

struct Task {
  std::string title;
  std::string description;
  Task* nextTask = nullptr;
  bool done = false;
};

struct Segment {
  std::string title;
  std::string description;
  std::vector<Task> tasks;
  int status;
};

struct Goal {
  std::string id;
  std::string title;
  std::string description;
  std::vector<Segment> segments;
};

std::vector<Goal> goals;
std::string systemMsg;
bool running = true;
int temp_id = 99;

// Parse Segment
// void from_json(const json& j, Segment& s) {
//     j.at("title").get_to(s.title);
//     j.at("description").get_to(s.description);
//     j.at("completed").get_to(s.completed);
// }

// Parse Goal
// void from_json(const json& j, Goal& g) {
//     j.at("title").get_to(g.title);
//     j.at("description").get_to(g.description);
//     j.at("segments").get_to(g.segments); // vector<Segment> handled automatically
// }

std::vector<Goal> loadDataFromFile() {
  std::ifstream file("./data/localSave.json");
  json j;
  file >> j;
  std::vector<Goal> goals;

  for (const auto& goalJson : j["goals"]) {
    Goal goal;
    goal.id = goalJson.value("id", 0);
    goal.title = goalJson["title"];
    goal.description = goalJson["description"];

    goals.push_back(goal);
  }
  return goals;
}

void saveData() {
  // TODO: Implement writing data to json file
}
void userCommandInput() {
  if (!systemMsg.empty()) {
    std::cout << "System Message: " + systemMsg << std::endl;
  } else {
    std::cout << std::endl;
  }
  std::cout << "Choose an option: ";
}

void handleDashboardInput() {
  systemMsg.clear();
  char key = ' ';
  std::cin >> key;
  std::cin.ignore();
  switch (key) {
    case 'g': currentScreen = Screen::AddGoal; break;
    case 'm': currentScreen = Screen::ManageGoal; break;
    case 't': currentScreen = Screen::RandomTask; break;
    case 'q': saveData(); std::cout << "Goodbye!\n"; running = false;
    default: systemMsg = "Invalid input!";
  }
}
void renderDashboard() {
  std::cout << "\n❄️  Snowball – Task-centric Goal Tracker\n";
  std::cout << "--------------------------------------\n";
  std::cout << "\nTODO: implement overview of all goals.\n\n\n\n\n\n";
  std::cout << "Add [G]oals \t";
  std::cout << "[M]anage goals \t";
  std::cout << "Random [T]ask \t";
  std::cout << "[Q]Exit\n";
  userCommandInput();
  // handleDashboardInput();
}

void handleAddGoal() {
  std::string title, description;

  // Get user input
  do {
    std::cout << "Enter goal title [B]: ";
    std::getline(std::cin, title);
  } while (title.empty());
  if (title == "b" || title == "B") {
    systemMsg = "Cancelled.";
    currentScreen = Screen::Dashboard;
    return;
  }
  std::cout << "Enter goal description (can be empty): ";
  std::getline(std::cin, description);

  // Add new goal
  Goal goal;
  goal.id = std::to_string(temp_id);
  goal.title = title;
  goal.description = description;
  goals.push_back(goal);
  systemMsg = "✅ Goal added!";

  currentScreen = Screen::Dashboard;
}

void renderAddGoal() {
  std::cout << "\n❄️  Snowball – Task-centric Goal Tracker\n";
  std::cout << "--------------------------------------\n";
  std::cout << "\nTODO: implement add goal view.\n\n\n\n\n\n";
}

// TODO: Implement Manage Options
void handleManageGoal() {
  systemMsg = "TODO: Implement manage goal.";
  currentScreen = Screen::Dashboard;
}
void renderManageGoal() {
  std::cout << "TODO: Implement manage goal\n\n\n\n\n";

  // handleManageGoal();
}

// TODO: Implement random task function
void handleRandomTask() {
  systemMsg = "TODO: Implement random task functions";
  currentScreen = Screen::Dashboard;
}
void renderRandomTask() {
  std::cout << "TODO: Implement random task functions\n\n\n\n\n";

  // handleRandomTask();
}

int main() {
  // Load data
  std::ifstream file("./data/localSave.json");

  while (running) {
  //   switch (currentScreen) {
  //     case Screen::Dashboard: renderDashboard(); break;
  //     case Screen::AddGoal: renderAddGoal(); break;
  //     case Screen::ManageGoal: renderManageGoal(); break;
  //     case Screen::RandomTask: renderRandomTask(); break;
  //   }
  // }

    // Special case: AddGoal needs its own input flow
    // if (currentScreen == Screen::AddGoal) {
    //   std::cout << "\n❄️  Snowball – Task-centric Goal Tracker\n";
    //   std::cout << "--------------------------------------\n";
    //   std::cout << "\n📝 Add New Goal\n\n";
    //
    //   std::string title, description;
    //
    //   std::cout << "Enter goal title ([B] to cancel): ";
    //   std::getline(std::cin, title);
    //
    //   if (title == "b" || title == "B") {
    //     systemMsg = "Cancelled.";
    //     currentScreen = Screen::Dashboard;
    //     continue;
    //   }
    //
    //   if (title.empty()) {
    //     systemMsg = "❌ Title cannot be empty!";
    //     continue;
    //   }
    //
    //   std::cout << "Enter goal description (Enter to skip): ";
    //   std::getline(std::cin, description);
    //
    //   Goal goal;
    //   goal.id = std::to_string(temp_id++);
    //   goal.title = title;
    //   goal.description = description;
    //   goals.push_back(goal);
    //
    //   systemMsg = "✅ Goal added: " + title;
    //   currentScreen = Screen::Dashboard;
    //   continue;
    // }
    // Render, get input, handle - all in sequence
    switch (currentScreen) {
      case Screen::Dashboard: 
        renderDashboard(); 
        // std::getline(std::cin input);
        handleDashboardInput();
        break;

      case Screen::AddGoal:
        renderAddGoal();
        handleAddGoal();

      case Screen::ManageGoal: 
        renderManageGoal(); 
        // std::getline(std::cin, input);
        handleManageGoal();
        break;

      case Screen::RandomTask: 
        renderRandomTask(); 
        // std::getline(std::cin, input);
        handleRandomTask();
        break;
    }
  }

  // TODO: save data to json file (../backend/data)
}
