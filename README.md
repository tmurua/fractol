# 🌀 Fract-ol | 42 School Project

*An interactive fractal exploration tool built in C using MiniLibX.*

## 🚀 Overview

**Fract-ol** is a graphical exploration tool for visualizing fractals such as **Mandelbrot** and **Julia** sets. It offers an interactive interface allowing users to dynamically zoom, pan, and explore complex mathematical landscapes. Developed as part of the 42 School curriculum, this project demonstrates a deep understanding of fractal geometry, complex number operations, and graphics programming using MiniLibX.

## ✨ Features

- Interactive visualization of Mandelbrot and Julia fractals.
- Dynamic zooming and panning through keyboard and mouse interaction.
- Customizable parameters for Julia sets.
- Clean and modular C implementation leveraging MiniLibX graphics library.

## 🖥️ Installation & Usage

### Clone the repository:
```bash
git clone https://github.com/yourusername/fractol.git
cd fractol
```

### Compile:
```bash
make
```

### Run Mandelbrot:
```bash
./fractol mandelbrot
```

### Run Julia:
```bash
./fractol julia <real_part> <imaginary_part>
```
*Example:*
```bash
./fractol julia -0.7 0.27015
```

## 🎮 Controls

| Key/Mouse              | Action          |
|------------------------|-----------------|
| `ESC`                  | Exit program    |
| `Mouse Wheel`          | Zoom In/Out     |
| `Arrow Keys`           | Pan view        |

## 🛠️ Technologies

- **C** programming language
- **MiniLibX** graphics library
- **Libft** custom utility library

## 📌 Project Structure
```
fractol/
├── libft/                  # Custom libft functions
├── minilibx-linux/         # MiniLibX graphics library
├── main.c                  # Program entry point
├── fractal_render.c        # Rendering logic
├── iterative_equations.c   # Mathematical calculations
├── event_handler.c         # User interaction handling
├── window_init.c           # Window initialization and handling
├── ft_atof.c               # Custom string-to-double conversion
├── fractol.h               # Project header file
├── Makefile                # Project build system
└── README.md               # This file!
```

## 🙌 Contributions & Improvements

Suggestions for improvements and additional features are always welcome! Feel free to fork the project and submit a pull request or issue.

## 📚 Resources & Acknowledgments

- [MiniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx)
- [Fractal Geometry](https://en.wikipedia.org/wiki/Fractal)
