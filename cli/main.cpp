#include <iostream>
#include <string>
#include <vector>


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
  int status;
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
  std::cout << "\nTODO: add overview of all goals.\n\n\n\n\n\n";
  std::cout << "Add [G]oals \t";
  std::cout << "[M]anage goals \t";
  std::cout << "Random [T]ask \t";
  std::cout << "[Q]Exit\n";
  userCommandInput();
}

void renderAddGoals() {
  std::string title;
  std::cout << "Enter goal title: ";
  std::getline(std::cin, title);
  goals.push_back({title, {}});
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

int main() {
  char choice = ' ';

  while (true) {
    renderDashboard();
    std::cin >> choice;
    std::cin.ignore(); // clear input buffer

    switch (choice) {
      case 'g': renderAddGoals(); break;
      case 'm': renderManageGoal(); break;
      case 't': renderRandomTask(); break;
      case 'q': std::cout << "Goodbye!\n"; return 0;
      default: systemMsg = "Invalid input!";
    }
  }
}
