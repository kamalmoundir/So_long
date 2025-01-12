# So_long

So_long is a graphical project in C that introduces students to the basics of game development using the MiniLibX library. The objective is to create a simple 2D game where a player can navigate through a map, collecting items, avoiding enemies, and reaching an exit.

## Table of Contents

- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [Contributing](#contributing)
- [License](#license)

## Requirements

- gcc
- make
- X11 include files (package xorg)
- XShm extension (package libxext-dev)
- Utility functions from BSD systems (package libbsd-dev)
- MiniLibX library

For MacOS:
- [Xquartz](https://www.xquartz.org/)

## Installation

1. Clone the repository:
    ```sh
    git clone https://github.com/kamalmoundir/so_long.git
    cd so_long
    ```

2. Install the required packages:
    ```sh
    sudo apt-get install gcc make xorg libxext-dev libbsd-dev
    ```

3. Compile the project:
    ```sh
    make
    ```

## Usage

To run the game, use the following command:
```sh
./so_long path_to_map_file



So_long/
├── images/
├── include/
│   └── so_long.h
├── library/
│   ├── ft_printf/
│   ├── libft/
│   └── minilibx-linux/
├── mapa/
├── src/
│   ├── fun_validate_map.c
│   ├── function_act.c
│   ├── functions_utiles.c
│   ├── get_next_line_utils.c
│   ├── get_next_line.c
│   ├── load_graph.c
│   ├── player_act.c
│   ├── so_long.c
│   ├── validate_map.c
│   └── window.c
├── LICENSE
├── Makefile
└── README.md