#include "gomoku.h"

namespace gomoku {

Gomoku::Gomoku() {
  board_ = std::vector<std::vector<GoColor>>(BOARD_SIZE);
  for (auto &b : board_) {
    b = std::vector<GoColor>(BOARD_SIZE, GoColor::kNone);
    b.shrink_to_fit();
  }
  board_.shrink_to_fit();
}

void Gomoku::GameStart() {
  bool quit_flag = false;
  int x_pos;
  int y_pos;
  PrintBoard();
  while (true) {
    if (black_step_)
      std::cout << "CURRENT PLAYER: BLACK\n";
    else
      std::cout << "CURRENT PLAYER: WHITE\n";

    std::cout
        << "TIPS: ENTER POSITION IN FORM OF \"X Y\", USE A SPACE TO SPLIT\n";
    std::cout << "TIPS: ENTER \"99\" TO EXIT\n";

    while (true) {
      std::cout << "ENTER X-POSITION: ";
      std::cin >> x_pos;

      if (x_pos == 99) {
        quit_flag = true;
        break;
      }

      std::cout << "ENTER Y-POSITION: ";
      std::cin >> y_pos;

      if (OutOfRange(x_pos - 1, y_pos - 1)) {
        std::cout << "OUT OF BOARD! ENTER AGAIN\n";
        continue;
      }

      if (board_[x_pos - 1][y_pos - 1] != GoColor::kNone) {
        std::cout << "INVALID INPUT! ENTER AGAIN\n";
        continue;
      }

      break;
    }

    if (quit_flag) break;

    board_[x_pos - 1][y_pos - 1] =
        black_step_ ? GoColor::kBlack : GoColor::kWhite;
    system("cls");
    PrintBoard();

    if (Win(x_pos - 1, y_pos - 1)) {
      if (black_step_)
        std::cout << "BLACK WIN!\n";
      else
        std::cout << "WHITE WIN!\n";
      break;
    }
    black_step_ = !black_step_;
  }
}

bool Gomoku::Win(int x, int y) const {
  int max_length = 1;
  GoColor my_color = board_[x][y];

  int tmp_x = x;
  int tmp_y = y;

  // Search In Four Directions
  while (!OutOfRange(++tmp_x, tmp_y)) {
    if (board_[tmp_x][tmp_y] == my_color)
      ++max_length;
    else
      break;
  }
  tmp_x = x;
  while (!OutOfRange(--tmp_x, tmp_y)) {
    if (board_[tmp_x][tmp_y] == my_color)
      ++max_length;
    else
      break;
  }
  tmp_x = x;
  if (max_length >= 5) return true;
  max_length = 1;

  while (!OutOfRange(tmp_x, ++tmp_y)) {
    if (board_[tmp_x][tmp_y] == my_color)
      ++max_length;
    else
      break;
  }
  tmp_y = y;
  while (!OutOfRange(tmp_x, --tmp_y)) {
    if (board_[tmp_x][tmp_y] == my_color)
      ++max_length;
    else
      break;
  }
  tmp_y = y;
  if (max_length >= 5) return true;
  max_length = 1;

  while (!OutOfRange(++tmp_x, ++tmp_y)) {
    if (board_[tmp_x][tmp_y] == my_color)
      ++max_length;
    else
      break;
  }
  tmp_x = x;
  tmp_y = y;
  while (!OutOfRange(--tmp_x, --tmp_y)) {
    if (board_[tmp_x][tmp_y] == my_color)
      ++max_length;
    else
      break;
  }
  tmp_x = x;
  tmp_y = y;
  if (max_length >= 5) return true;
  max_length = 1;

  while (!OutOfRange(++tmp_x, --tmp_y)) {
    if (board_[tmp_x][tmp_y] == my_color)
      ++max_length;
    else
      break;
  }
  tmp_x = x;
  tmp_y = y;
  while (!OutOfRange(--tmp_x, ++tmp_y)) {
    if (board_[tmp_x][tmp_y] == my_color)
      ++max_length;
    else
      break;
  }
  if (max_length >= 5) return true;

  return false;
}

bool Gomoku::OutOfRange(int x, int y) const {
  if (x < 0 || y < 0 || x >= BOARD_SIZE || y >= BOARD_SIZE)
    return true;
  else
    return false;
}

void Gomoku::PrintBoard() const {
  // First Line
  std::cout << "  ";
  for (int i = 0; i < BOARD_SIZE; ++i) {
    std::cout << std::setw(2) << (i + 1);
  }
  std::cout << std::endl;

  for (int i = 0; i < BOARD_SIZE; ++i) {
    std::cout << std::setw(2) << (i + 1);
    for (int j = 0; j < BOARD_SIZE; ++j) {
      switch (board_[i][j]) {
        case GoColor::kNone:
          std::cout << " .";
          break;
        case GoColor::kBlack:
          std::cout << " x";
          break;
        case GoColor::kWhite:
          std::cout << " o";
          break;
      }
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

}  // namespace gomoku
