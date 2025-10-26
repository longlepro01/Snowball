#include <iostream>
#include <string>
#include <vector>

#include "data_manager.h"
#include "models.h"
#include "screens/add_goal.h"
#include "screens/dashboard.h"
#include "screens/random_task.h"
#include "screens/view_goals.h"

int main() {
  // Initialize application state
  AppState state;

  // Load data
  state.goals = loadDataFromFile("../data/localSave.json");

  while (state.running) {
    switch (state.currentScreen) {
    case Screen::Dashboard:
      handleDashboardInput(state);
      break;

    case Screen::AddGoal:
      handleAddGoal(state);
      break;

    case Screen::ViewGoals:
      handleViewGoals(state);
      break;

    case Screen::RandomTask:
      renderRandomTask();
      handleRandomTask(state);
      break;
    }
  }

  return 0;
}
