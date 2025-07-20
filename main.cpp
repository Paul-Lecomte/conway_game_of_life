#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <random>

using Grid = std::vector<std::vector<bool>>;

const int ROWS = 20;
const int COLS = 40;
const int DELAY_MS = 100;

void displayGrid(const Grid& grid) {
    system("cls");  // On mac/linux, use "clear"
    for (const auto& row : grid) {
        for (bool cell : row) {
            std::cout << (cell ? "█" : " ");
        }
        std::cout << '\n';
    }
}

int countLiveNeighbors(const Grid& grid, int row, int col) {
    // You will implement this
    return 0;
}

Grid nextGeneration(const Grid& current) {
    // You will implement this
    return current;
}

int main() {
    Grid grid(ROWS, std::vector<bool>(COLS, false));

    std::random_device rd;
    std::mt19937 gen(rd());
    std::bernoulli_distribution dist(0.01); // 20% chance of a cell being alive
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            grid[i][j] = dist(gen);
        }
    }


    // TODO: Seed grid manually or randomly for now
    // e.g., grid[1][2] = true;

    while (true) {
        displayGrid(grid);
        grid = nextGeneration(grid);
        std::this_thread::sleep_for(std::chrono::milliseconds(DELAY_MS));
    }

    return 0;
}