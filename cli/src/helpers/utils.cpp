// Include own header FIRST
#include "utils.h"

// Standard library includes
#include <random>
#include <sstream>
#include <string>
#include <termios.h>
#include <unistd.h>

// ID Generator
std::string generateUUID() {
  // Using STD Library random
  std::random_device rand;     // Hardware random seed
  std::mt19937_64 gen(rand()); // Initialize generator with given seed
  std::uniform_int_distribution<> dis(
      0, 15); // Generate numbers between 0 and 15 for hexadecimals

  const char *hex = "0123456789abcdef";
  std::stringstream ss;

  for (int i = 0; i < 36; i++) {
    if (i == 8 || i == 13 || i == 18 || i == 23) {
      ss << '-';
    } else if (i == 14) {
      ss << '4';
    } else if (i == 19) {
      ss << hex[(dis(gen) & 0x3) | 0x8];
    } else {
      ss << hex[dis(gen)];
    }
  }

  return ss.str();
}

// Control
char getKey() {
  char buf = 0;
  struct termios old = {0};
  if (tcgetattr(0, &old) < 0)
    perror("tcsetattr()");
  old.c_lflag &= ~ICANON; // disable buffered I/O
  old.c_lflag &= ~ECHO;   // disable echo
  if (tcsetattr(0, TCSANOW, &old) < 0)
    perror("tcsetattr ICANON");
  if (read(0, &buf, 1) < 0)
    perror("read()");
  old.c_lflag |= ICANON;
  old.c_lflag |= ECHO;
  if (tcsetattr(0, TCSADRAIN, &old) < 0)
    perror("tcsetattr ~ICANON");
  return buf;
}
