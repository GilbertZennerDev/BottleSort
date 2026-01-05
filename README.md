# Bottle Sort

A logic puzzle game where the objective is to sort colored liquids (represented by characters) into bottles until each bottle contains only one color or is empty. This repository contains implementations of the game in both **Python** and **C++**.

---

## 🎮 Game Logic

The game represents bottles as vertical columns.

* **`x`** represents an empty space in a bottle.
* Any other character (e.g., `A`, `B`, `1`, `2`) represents a specific color.
* **Pouring (Flushing):** You can move the topmost color from one bottle to the first available empty slot in another bottle.

### Winning Condition

The game is won when every bottle in the level satisfies one of two conditions:

1. The bottle is completely full of a single color.
2. The bottle is completely empty (all `x`).

---

## 🛠 Features

* **Cross-Language Support:** Identical logic implemented in Python and C++.
* **Level Loading:** Load custom levels from `.lvl` files.
* **Save/Load System:** Save your current game state and resume later.
* **Command Line Interface:** Simple text-based UI for quick gameplay.

---

## 📂 File Structure

* `levels/`: Directory containing level definition files (e.g., `1.lvl`).
* `saves/`: Directory where saved game states are stored.
* `bottlesort.py`: The Python implementation.
* `bottlesort.cpp`: The C++ implementation.

### Level File Format

Level files are text files where each line represents a **bottle** (horizontal in the file, but rendered vertically in the game). Colors are separated by spaces.
Example:

```text
x x A B
x x B A
x x x x

```

---

## 🚀 How to Play

### 1. Run the Game

**Python:**

```bash
python bottlesort.py

```

**C++:**

```bash
g++ bottlesort.cpp -o bottlesort
./bottlesort

```

### 2. Commands

Once the game starts, you can use the following commands:

| Command | Action |
| --- | --- |
| `f <start> <end>` | **Flush:** Move color from bottle index `start` to `end`. |
| `s` | **Show:** Display the current state of the bottles. |
| `c` | **Check:** Verify if the puzzle is complete. |
| `l <name>` | **Load:** Load a specific level from the `levels/` folder. |
| `save <name>` | **Save:** Save current progress to the `saves/` folder. |
| `ls <name>` | **Load Save:** Load a level from the `saves/` folder. |
| `h` | **Help:** Toggle the command list display. |
| `x` | **Exit:** Quit the game. |

---

## 📝 Example Gameplay

1. Start the game: `Welcome to Bottle Sort`
2. View bottles: `s`
3. Move the top item from bottle 0 to bottle 2: `f 0 2`
4. Check for win: `c`
