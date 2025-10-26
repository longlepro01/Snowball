// models.h
#ifndef MODELS_H
#define MODELS_H

#include <string>
#include <vector>

enum class Screen { Dashboard, AddGoal, ViewGoals, RandomTask };

struct Task {
  std::string title;
  std::string description;
  Task *nextTask = nullptr;
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
  int orderIndex;
};

// Application state
struct AppState {
  Screen currentScreen = Screen::Dashboard;
  std::vector<Goal> goals;
  std::string systemMsg;
  bool running = true;
};

#endif // MODELS_H
