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

std::vector<Goal> loadDataFromFile(std::string filename) {
  std::ifstream file(filename);
  json j;
  file >> j;
  std::vector<Goal> goals;

  for (const auto& goalJson : j["goals"]) {
    Goal goal;
    goal.id = goalJson.value("id", "");
    goal.title = goalJson["title"];
    goal.description = goalJson["description"];

    goals.push_back(goal);
  }
  return goals;
}

void saveData() {
  // TODO: Implement writing data to json file
}

// Control
char getKey() {
    char buf = 0;
    struct termios old = {0};
    if (tcgetattr(0, &old) < 0) perror("tcsetattr()");
    old.c_lflag &= ~ICANON; // disable buffered I/O
    old.c_lflag &= ~ECHO;   // disable echo
    if (tcsetattr(0, TCSANOW, &old) < 0) perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0) perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0) perror("tcsetattr ~ICANON");
    return buf;
}

// Screens 
void userCommandInput() {
  if (!systemMsg.empty()) {
    std::cout << "System Message: " + systemMsg << std::endl;
  } else {
    std::cout << std::endl;
  }
  std::cout << "Choose an option: ";
}

void renderAppHeader() {
  std::cout << "\n❄️  Snowball – Task-centric Goal Tracker\n";
  std::cout << "--------------------------------------\n";
}

void renderDashboard() {
  renderAppHeader();
  std::cout << "\nTODO: implement overview of all goals.\n\n\n\n\n\n";
  std::cout << "Add [G]oals \t";
  std::cout << "[V]iew goals \t";
  std::cout << "Random [T]ask \t";
  std::cout << "[Q]Exit\n";
  userCommandInput();
}

void handleDashboardInput() {
  renderDashboard();
  systemMsg.clear();
  char key = ' ';
  // std::cin >> key;
  // std::cin.ignore();
  key = getKey();
  switch (key) {
    case 'g': currentScreen = Screen::AddGoal; break;
    case 'v': currentScreen = Screen::ManageGoal; break;
    case 't': currentScreen = Screen::RandomTask; break;
    case 'q': saveData(); std::cout << "Goodbye!\n"; running = false;
    default: systemMsg = "Invalid input!";
  }
}

void renderAddGoal(std::string title, std::string description) {
  renderAppHeader();
  if (!title.empty()) {
    std::cout << "Goal title: " << title << std::endl;
  }
  if (!description.empty()) {
    std::cout << "Goal description: " << description << std::endl;
  }  
  std::cout << std::endl << std::endl;
}

void handleAddGoal() {
  std::string title, description;
  
  renderAddGoal(title, description);

  std::cout << "Enter goal title: ";
  std::getline(std::cin, title);

  // Get user input
  while (title.empty()) {
    renderAddGoal(title, description);
    std::cout << "Enter goal title (cannot be empty): ";
    std::getline(std::cin, title);
  }

  if (title == "b" || title == "B") {
    systemMsg = "Cancelled.";
    currentScreen = Screen::Dashboard;
    return;
  }

  renderAddGoal(title, description);
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

void renderViewGoal() {
  renderAppHeader();
  for (int i = 0; i < goals.size(); i++) {
    std::cout << "Goal " << i + 1 << std::endl;
    std::cout << goals[i].title << std::endl;
    std::cout << goals[i].description << std::endl;
    std::cout << "------------------------" << std::endl;
  }
}

// TODO: Implement Manage Options
void handleViewGoal() {
  char key = ' ';
  systemMsg = "TODO: Implement view goal.";
  renderViewGoal();

  key = getKey();

  currentScreen = Screen::Dashboard;
}

void renderRandomTask() {
  renderAppHeader();
  std::cout << "TODO: Implement random task functions\n\n\n\n\n";
}

// TODO: Implement random task function
void handleRandomTask() {
  systemMsg = "TODO: Implement random task functions";
  currentScreen = Screen::Dashboard;
}

int main() {
  // Load data
  goals = loadDataFromFile("../data/localSave.json");

  while (running) {
   switch (currentScreen) {
      case Screen::Dashboard: 
        handleDashboardInput();
        break;

      case Screen::AddGoal:
        handleAddGoal();
        break;

      case Screen::ManageGoal: 
        handleViewGoal();
        break;

      case Screen::RandomTask: 
        renderRandomTask(); 
        // std::getline(std::cin, input);
        handleRandomTask();
        break;
    }
  }

  // TODO: save data to json file
}
