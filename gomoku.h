// gomoku

// Created by MHBC 200408
// Last Edit: 200408

#ifndef GOMOKU_H
#define GOMOKU_H

#include <iomanip>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

namespace gomoku {

enum class GoColor { kNone, kWhite, kBlack };

class Gomoku {
 public:
  Gomoku();
  void GameStart();

 private:
  void PrintBoard() const;
  bool Win(int x, int y) const;
  bool OutOfRange(int x, int y) const;

 private:
  const static int BOARD_SIZE = 19;
  bool black_step_ = true;
  std::vector<std::vector<GoColor>> board_;
};

}  // namespace gomoku

#endif
