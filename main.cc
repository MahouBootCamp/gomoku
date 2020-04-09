#include <chrono>
#include <iostream>
#include <thread>

#include "gomoku.h"

int main(int, char**) {
  gomoku::Gomoku my_game;
  my_game.GameStart();
  std::cout << "THANKS FOR PLAYING\n";
  std::cout << "PRESS ANY KEY TO EXIT\n";
  getchar();
  getchar();
  return 0;
}
