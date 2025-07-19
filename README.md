
# Assignment 1: The Game of Life

Thanks to Julie Zelenski for the idea and Jerry Cain, Keith Schwarz, Cynthia Lee, and Marty Stepp for revisions.

---

![A still image of the Game of Life](https://web.stanford.edu/class/archive/cs/cs106b/cs106b.1186/img/assn/life/life.png)

For your first assignment, we’ll implement **Conway’s Game of Life**! It’s a bacteria simulation on a 2D grid. The goal is to:

- Gain familiarity with basic C++: functions, strings, I/O streams.
- Use provided Stanford C++ libraries.
- Decompose a larger problem into smaller functions.

You **must** write your own solution—no pair programming.

---

## 📋 Overview

1. Prompt user for a **file name**; use its contents to initialize a bacterial grid.
2. Ask whether the grid “wraps” at edges.
3. Enter a loop where the user can:
    - `t` / `T`: **tick** forward one generation,
    - `a` / `A`: **animate**, advancing every 50 ms,
    - `q` / `Q`: **quit**.
    - Input is case-insensitive (use `toLowerCase()`).

Example session:

![Example Run](https://web.stanford.edu/class/archive/cs/cs106b/cs106b.1186//img/assn/life/lifeDemo.png)

---

## Submission

- `life.cpp`: your C++ code.
- `mycolony.txt`: your own starting pattern.

Starter code available via ZIP.  
Due: **April 12 at 12:00 pm**.  
Submit via cs198.stanford.edu/paperless.

---

## Simulation Rules

Each cell is either dead (`-`) or alive (`X`). Neighbors are the eight adjacent cells. Next-generation rules:

1. **0–1 neighbor** → empty (death by loneliness)
2. **2 neighbors** → stable (unchanged)
3. **3 neighbors** → birth or remains alive
4. **4+ neighbors** → death by overcrowding

Updates occur **simultaneously**, using a temp grid.

---

## Handling Frame Edges

- **Non-wrap**: borders have fewer neighbors.
- **Wrap**: edges connect toroidally (loop-around). When enabled, use modulo arithmetic on coordinates.

---

## Input File Format

- First line: integer `r` = number of rows.
- Second line: integer `c` = number of columns.
- Next `r` lines: each with `c` characters (`-` or `X`).
- Extra lines afterwards can be ignored.
- Filename has **no spaces**.
- If file doesn’t exist: re-prompt.
- Assume valid formatting once opened.

Example of a 5×9 file:
```
5
9
---------
---------
---XXX---
---------
---------
```

---

## Implementation Details

### Data Structures

- Use Stanford’s `Grid<char>` type—not built-in arrays.

### Console I/O

- Use `getLine()` for console input; avoid `cin`.
- File I/O: use `ifstream` + `getline`.

### Wrap-around logic

Use modulo:
```cpp
int wrappedRow = (r + numRows) % numRows;
```
...similar for columns.

---

## Debugging Tips

- Use a **temp grid** to compute next generation—don’t update in-place!
- Use `cout` to print neighbor counts and indexes while debugging.
- Once working, remove debug output.

---

## 🔧 Creative Aspect: `mycolony.txt`

Submit **one** custom colony (same format). Must be your own design. Worth a small part of your grade.

---

## Extras (Optional)

If you want to go above and beyond:

- Add a GUI version using `life-gui.cpp`:
   ```cpp
   LifeGUI gui("Game of Life");
   gui.resize(nRows, nCols);
   ```
- Experiment with new features—but your output **must** match the spec exactly.

---

## 📝 Turn-in files

| File             | Content                                      |
|------------------|-----------------------------------------------|
| `life.cpp`       | Your full C++ implementation                 |
| `mycolony.txt`   | Your custom starting colony                  |

Submit via **Paperless**. Only those two files required.

---

## Resources

- Stanford C++ Library Console & Grid documentation
- Example output and diff tool: use to test for exact formatting

Good luck! Have fun watching your bacterial colony thrive (or die 😄).

---

*README generated from Stanford CS106B Spring 2018 assignment spec.*  
[Source Assignment Page](https://web.stanford.edu/class/archive/cs/cs106b/cs106b.1186/assn/life.html)
