#include "screens/view_goals.h"

#include <iostream>
#include <string>

#include "models.h"
#include "ui.h"
#include "utils.h"

void renderViewGoals(AppState &state) {
  renderAppHeader();

  int i = 1;
  for (Goal goal : state.goals) {
    std::cout << "Goal " << i << std::endl;
    std::cout << goal.title << std::endl;
    std::cout << goal.description << std::endl;
    std::cout << "------------------------" << std::endl;
    i++;
  }
}

// TODO: Implement Manage Options
void handleViewGoals(AppState &state) {
  char key = ' ';
  state.systemMsg = "TODO: Implement view goal.";
  renderViewGoals(state);

  key = getKey();

  state.currentScreen = Screen::Dashboard;
}
