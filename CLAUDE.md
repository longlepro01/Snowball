# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

Snowball is a task-centric goal tracking application that helps users turn small actions into unstoppable progress. The project consists of:

- **CLI Application**: Interactive C++ interface (primary frontend)
- **Backend Services**: TypeScript handlers for data management
- **Data Storage**: JSON-based local storage with plans for SQLite/PostgreSQL

## Build and Development Commands

### C++ CLI Application
```bash
# Configure build (run from cli directory)
cd cli
cmake -B build .

# Build the application
cmake --build build

# Run the application
./build/snowball
```

### Dependencies
- CMake 3.10+
- nlohmann/json 3.10.5+ (JSON parsing library)
- C++17 standard

Note: CMake configuration may vary by system. The CMakeLists.txt should be adjusted for local development environments.

## Architecture

### Core Data Structures
The application uses a hierarchical goal structure defined in `cli/main.cpp:21-40`:

- **Goal**: Contains id, title, description, and segments
- **Segment**: Contains title, description, tasks, and status
- **Task**: Contains title, description, completion status, and linked tasks

### Screen Management
The CLI uses an enum-based screen system (`cli/main.cpp:11-17`) with screens for:
- Dashboard: Main overview and navigation
- AddGoal: Goal creation interface
- ManageGoal: Goal management (TODO)
- RandomTask: Task selection feature (TODO)

### Data Flow
- **Loading**: `loadDataFromFile()` reads from `cli/data/localSave.json`
- **Storage**: Local JSON file in `cli/data/localSave.json`
- **Mock Data**: Backend handler provides test data at `backend/handler/getGoalsData.ts`

### Current Implementation Status
- ✅ Basic CLI interface with screen navigation
- ✅ Goal creation and storage structures
- ✅ JSON data loading infrastructure
- 🚧 Goal management interface (placeholder)
- 🚧 Random task selection (placeholder)
- 🚧 Data persistence (saveData function not implemented)
- 🚧 Segment and task management

## Key Files

- `cli/main.cpp`: Main application logic and UI rendering
- `cli/CMakeLists.txt`: Build configuration (device-specific)
- `cli/data/localSave.json`: Local data storage
- `backend/handler/getGoalsData.ts`: Mock data provider
- `cli/include/nlohmann/json.hpp`: JSON parsing library

## Development Notes

The application follows a simple render-handle pattern where each screen has separate render and handle functions. The main loop switches between screens based on the current state.

Data structures are designed to support a hierarchical goal → segments → tasks breakdown, though segment and task management is not yet fully implemented.