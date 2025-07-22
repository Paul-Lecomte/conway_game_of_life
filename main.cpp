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
    int count = 0;

    for (int dr = -1; dr <= 1; ++dr) {
        for (int dc = -1; dc <= 1; ++dc) {
            if (dr == 0 && dc == 0) {
                continue;
            }
            int neighborRow = row + dr;
            int neighborCol = col + dc;

            if (neighborRow < 0 || neighborRow >= ROWS || neighborCol < 0 || neighborCol >= COLS) {
                continue;
            }
            if (grid[neighborRow][neighborCol]) {
                count++;
            }
        }
    }
    return count;
}

Grid nextGeneration(const Grid& current) {
    // Step 1: Create a new empty grid of the same size
    Grid next(ROWS, std::vector<bool>(COLS, false));

    // Step 2: Loop over every cell
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            // Step 3: Count how many live neighbors this cell has
            int neighbors = countLiveNeighbors(current, row, col);

            // Step 4: Check if the current cell is alive
            bool isAlive = current[row][col];

            // Step 5: Apply the Game of Life rules
            if (isAlive && (neighbors == 2 || neighbors == 3)) {
                next[row][col] = true;  // Stay alive
            } else if (!isAlive && neighbors == 3) {
                next[row][col] = true;  // Dead cell becomes alive
            } else {
                next[row][col] = false; // Dies or stays dead
                // Actually optional, since it's false by default
            }
        }
    }

    // Step 6: Return the new grid
    return next;
}

int main() {
    Grid grid(ROWS, std::vector<bool>(COLS, false));

    std::random_device rd;
    std::mt19937 gen(rd());
    std::bernoulli_distribution dist(0.02); // 20% chance of a cell being alive
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