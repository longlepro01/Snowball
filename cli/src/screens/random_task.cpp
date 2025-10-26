#include "screens/random_task.h"

#include <iostream>
#include <string>

#include "models.h"
#include "ui.h"
#include "utils.h"

void renderRandomTask() {
  renderAppHeader();
  std::cout << "TODO: Implement random task functions\n\n\n\n\n";
}

// TODO: Implement random task function
void handleRandomTask(AppState &state) {
  state.systemMsg = "TODO: Implement random task functions";
  state.currentScreen = Screen::Dashboard;
}
