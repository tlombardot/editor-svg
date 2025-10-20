# SVG Editor (C Terminal Project)

## Description

**SVG Editor** is a **C terminal application** that allows you to **create, edit, delete, import, and export** SVG shapes directly from your terminal.  
It provides a colorful and intuitive **Text User Interface**  for manipulating SVG elements without a graphical interface.


---

## Main Features

### Main Menu

The user can choose from several options:

| Option | Action |
|:------:|:--------|
| (1) | Create a new SVG shape |
| (2) | Edit an existing SVG |
| (3) | Remove a shape |
| (4) | Export a shape to an SVG file |
| (5) | Import a shape from an SVG file |
| (6) | Display all shapes |
| (0) | Exit the program |

---

## Available Shapes

When creating a new shape, the user can choose from the following:

- 🟦 **Rectangle**
- ⬜ **Square**
- ➖ **Line**
- ⚪ **Circle**
- 🟠 **Ellipse**
- 🔺 **Polygon**
- 📈 **Polyline**
- 🌀 **Path**
- 🧩 **Group (collection of shapes)**

Each shape is stored in a dynamic data structure and managed through an internal linked list (`List`).

---

## Project Structure

```
├── Makefile
├── main.c
├── components/
│ ├── create.c
│ ├── edit.c
│ ├── get.c
│ ├── list.c
│ ├── remove.c
├── config/
│ ├── allocate.c
│ ├── path.c
│ ├── style.c
│ ├── struct.h
│ ├── color.h
├── svg/
│ ├── svg.c
│ ├── load_svg.c
├── utils/
│ ├── windows_user.c
│ ├── interface_path.c
└── bin/
└── main
```

---

## ️ Installation & Compilation

### Requirements

- **GCC** compiler
- **ANSI/VT100** compatible terminal (for colored output)
- Operating System: **GNU/Linux** or **macOS**  
  *(Windows supported via Git Bash or WSL)*

---

### Build the Project

```
make
```
This command:
- Compiles all `.c` files
- Produces the final executable in `bin/main`

---

### Run the Program

```
make run
```
or directly:
```
./bin/main
```
---

### Clean Build Files
```
make clean
```
Removes all compiled objects and the executable.

---

### Debug with GDB
```
make debug
```

### ‍💻 Author

**Developed by:** *[Thomas Lombardot / tlombardot]*  
**Language:** **C99**  
**Platform:** **Linux / MacOS / Windows compatible**  
**Year:** **2025**
