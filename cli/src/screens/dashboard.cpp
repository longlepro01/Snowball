#include "screens/dashboard.h"

// Standard Library
#include <iostream>
#include <string>

// Project headers
#include "data_manager.h"
#include "models.h"
#include "ui.h"
#include "utils.h"

void renderDashboard(AppState &state) {
  renderAppHeader();
  std::cout << "\nTODO: implement overview of all goals.\n\n\n\n\n\n";
  std::cout << "Add [G]oals \t";
  std::cout << "[V]iew goals \t";
  std::cout << "Random [T]ask \t";
  std::cout << "[Q]Exit\n";
  userCommandInput(state.systemMsg);
}

void handleDashboardInput(AppState &state) {
  renderDashboard(state);
  state.systemMsg.clear();
  char key = ' ';
  key = getKey();

  switch (key) {
  case 'g':
    state.currentScreen = Screen::AddGoal;
    break;
  case 'v':
    state.currentScreen = Screen::ViewGoals;
    break;
  case 't':
    state.currentScreen = Screen::RandomTask;
    break;
  case 'q':
    saveData(state.goals, "../data/localSave.json");
    std::cout << "Goodbye!\n";
    state.running = false;
    break;
  default:
    state.systemMsg = "Invalid input!";
  }
}
