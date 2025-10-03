#include <iostream>
#include <string>
#include <vector>
#include <termios.h>
#include <unistd.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;


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
  std::string title;
  std::string description;
  std::vector<Segment> segments;
};

std::vector<Goal> goals;
std::string systemMsg;

void userCommandInput() {
  if (!systemMsg.empty()) {
    std::cout << "System Message: " + systemMsg << std::endl;
  } else {
    std::cout << std::endl;
  }
  std::cout << "Choose an option: ";
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
}

void renderAddGoals() {
  std::string title;
  std::string description;
  std::cout << "\n❄️  Snowball – Task-centric Goal Tracker\n";
  std::cout << "--------------------------------------\n";
  std::cout << "\nTODO: implement add goal view.\n\n\n\n\n\n";
  std::cout << "Enter goal title: ";
  std::getline(std::cin, title);
  std::cout << "Enter goal description (can be empty): "
  std::getline(std::cin, description);
  goals.push_back({title, description, {}});
  systemMsg = "✅ Goal added!";
}

// TODO: Implement Manage Options
void renderManageGoal() {
  std::cout << "TODO: To be developed\n";
}

// TODO: Implement random task function
void renderRandomTask() {
  std::cout << "TODO: Develop random task functions\n";
}

// Parse Segment
// void from_json(const json& j, Segment& s) {
//     j.at("title").get_to(s.title);
//     j.at("description").get_to(s.description);
//     j.at("completed").get_to(s.completed);
// }

// Parse Goals
void from_json(const json& j, Goal& g) {
    j.at("title").get_to(g.title);
    j.at("description").get_to(g.description);
    j.at("segments").get_to(g.segments); // vector<Segment> handled automatically
}
std::vector<Goal> loadData() {
  // TODO: Implement loading data from json file
  try {
    json j = json::parse()
  }
  std::vector<Goal> = 

 
}

void saveData() {
  // TODO: Implement writing data to json file
}

int main() {
  char choice = ' ';
  bool running = true;
  
   while (running) {
    renderDashboard();
    std::cin >> choice;
    std::cin.ignore(); // clear input buffer

    switch (choice) {
      case 'g': renderAddGoals(); break;
      case 'm': renderManageGoal(); break;
      case 't': renderRandomTask(); break;
      case 'q': saveData(); std::cout << "Goodbye!\n"; running = false;
      default: systemMsg = "Invalid input!";
    }
  }

  // TODO: save data to json file (../backend/data)
}
