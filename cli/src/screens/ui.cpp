#include "ui.h"
#include <iostream>
#include <string>

void userCommandInput(std::string systemMsg) {
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
