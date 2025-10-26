#include "screens/add_goal.h"

#include <iostream>
#include <string>

#include "models.h"
#include "ui.h"
#include "utils.h"

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

void handleAddGoal(AppState &state) {
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
    state.systemMsg = "Cancelled.";
    state.currentScreen = Screen::Dashboard;
    return;
  }

  renderAddGoal(title, description);
  std::cout << "Enter goal description (can be empty): ";
  std::getline(std::cin, description);

  // Add new goal
  Goal goal;
  goal.id = generateUUID();

  // Temp console log UUID
  std::cout << goal.id << std::endl;

  goal.title = title;
  goal.description = description;
  state.goals.push_back(goal);
  state.systemMsg = "✅ Goal added!";

  state.currentScreen = Screen::Dashboard;
}
