**Overview**

Solong is a 2D game project developed as part of the 42 curriculum. The goal of this project is to create a simple yet engaging game using the MiniLibX library, which is a minimalistic graphics library provided by 42. The game involves a player navigating through a map, collecting items, and reaching the exit while avoiding enemies.

This project is an excellent opportunity to learn about game development, graphics programming, and handling user input in a controlled environment.

**Features**

2D Game Environment: The game is rendered in a 2D grid-based environment.

Player Movement: The player can move in four directions (up, down, left, right) using the arrow keys or WASD.

Collectibles: The player must collect all items scattered across the map before reaching the exit.

Enemies: The game includes enemies that move randomly or follow a pattern, adding challenge to the gameplay.

Win/Lose Conditions: The player wins by collecting all items and reaching the exit. The player loses if they collide with an enemy.

Dynamic Map Loading: The game loads maps from .ber files, allowing for customizable levels.

MiniLibX Integration: The project uses the MiniLibX library for rendering graphics and handling user input.

**Installation**

**Prerequisites**
MiniLibX: Ensure that the MiniLibX library is installed on your system. You can find it in the 42 resources or compile it from source.

GCC: A C compiler is required to build the project.

**Steps**
Clone the repository:
```
git clone https://github.com/kamalmoundir/sol_long.git
cd sol_long
```
Compile the project:
```
make
```

Run the game:
```
./so_long maps/map1.ber
```

Replace maps/map1.ber with the path to your desired map file.
Usage
Controls
Arrow Keys or WASD: Move the player.

ESC: Exit the game.

Map File Format
The game uses .ber files to define the map. The map file should contain the following characters:
```
0: Empty space.

1: Wall (impassable).

C: Collectible item.

E: Exit.

P: Player starting position.

M: Enemy (optional).
```
Example map file (map1.ber):
```
111111111
1P00000E1
1C0000001
111111111
```

**Project Structure**
```
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
└── README.m
```

**License**
This project is licensed under the MIT License. See the LICENSE file for details.

**Acknowledgments**

42 School: For providing the opportunity to work on this project.

MiniLibX: The graphics library used for rendering the game.

Community: Thanks to the 42 community for support and inspiration.

**Contact**

If you have any questions or feedback, feel free to reach out:

GitHub: kamalmoundir
Linikedin :https://www.linkedin.com/in/kamal-moundir
Email: kmoundir@student.42malaga.com
