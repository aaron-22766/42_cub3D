<h1 align="center">
	<p>
	cub3d
	</p>
	<img src="https://github.com/ayogun/42-project-badges/blob/main/badges/cub3dm.png">
</h1>

<p align="center">
	<b><i>My first RayCaster with MLX42</i></b><br><br>
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/aaron-22766/42_cub3d?color=lightblue" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/aaron-22766/42_cub3d?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/aaron-22766/42_cub3d?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/aaron-22766/42_cub3d?color=green" />
</p>

---

## 🗣 About

This project is inspired by the world-famous eponymous 90's game *Wolfenstein 3D*, which was the first FPS ever. It will enable you to explore **ray-casting**. Your goal will be to make a dynamic view inside a maze, in which you'll have to find your way.

For this team project, I teamed up with [Lorenzo](https://github.com/LorenFiorini).

## 🛠 Usage


### Requirements

The game is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run. [MLX42](https://github.com/codam-coding-college/MLX42) is used as the graphics engine, since it is easier to work with than MiniLibX. Since MLX is optimized to the OSs this game can only be played on macOS.

### Instructions

Run the mandatory version:
```shell
make
./cub3D maps/*.cub
```

### Play

* **Start/Pause/Resume**: `P`
* **Move**: `WASD`
* **Look around**: `←→` or `MOUSE MOVEMENT`
* **Sprint**: `LEFT SHIFT`
* **Sneak**: `F`
* **Open doors**: `SPACE` or `LEFT MOUSE`
* **Zoom minimap**: `SCROLL UP/DOWN`
* **Change fov**: `SCROLL LEFT/RIGHT` (`SHIFT`+`UP/DOWN` on mice without LEFT/RIGHT)
* **Exit**: `ESCAPE`

For the program's input, either use a map we provide or check the [requirements for the map file](#Scene-Description-File-(Map)) to learn how to write one yourself. You can always just try out and the errors will help you figure it out as well!

## 💬 Description

### Mandatory

* Look and move around in a seemingly 3D environment using your keyboard

### Bonus

* **Player collides with wall**
* **A minimap system**
  - shows a top-down view of a section of the map
  - when player walks or rotates, the map around the centered player moves to keep the player always facing straight up
  - shows walls, open and closed doors, as well as the player's fov
  - can be zoomed in and out using the scroll wheel
* **Doors which can open and close**
* **Animated sprite**
  - player holds a burning torch (requires *torch.png* sprite sheet)
* **Rotate the point of view with the mouse**

### Additional features

* **Pause screen**
  - shows at the start of the game and when pressing `P`
  - blurred still frame of the game's state with clean texture (*pause.png* required)
  - blur algorithm needed to be fast for it to look good
* **Window resizing**
  - when on the pause screen, the cursor can be used to resize the window and the game adjusts accordingly
  - minimum size is the size of the *pause.png* texture
  - if window is too small, only a message will be displayed, since MLX can't restrict resizing
* **Player speed**
  - sprint using `LEFT SHIFT`
  - sneak using `F`
* **fps tracker** in the console
* **cropping textures** instead of stretching when texture isn't square

## Scene Description File (Map)

* The map must be composed of only 6 possible characters:
  - `0` for an empty space
  - `1` for a wall
  - `N`, `S`, `E` or `W` for the player’s start position and spawning orientation
* The map must be closed/surrounded by walls, if not the program must return an error
* Except for the map content, each type of element can be separated by one or more empty line(s)
* Except for the map content which always has to be the last, each type of element can be set in any order in the file
* Except for the map, each type of information from an element can be separated by one or more space(s)
* The map must be parsed as it looks in the file. Spaces are a valid part of the map and are up to you to handle. You must be able to parse any kind of map, as long as it respects the rules of the map
* Each element (except the map) firsts information is the type identifier (composed by one or two character(s)), followed by all specific informations for each object in a strict order such as:
  - NO ./path_to_the_north_texture
  - SO ./path_to_the_south_texture
  - WE ./path_to_the_west_texture
  - EA ./path_to_the_east_texture
  - F 220,100,0 (floor RGB color)
  - C 225,30,0 (ceiling RGB color)

Example of the mandatory part with a minimalist .cub scene:
```
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture
D ./path_to_the_door_texture (optional, but required if map contains D)
F 220,100,0
C 225,30,0
        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111

```

* If any misconfiguration of any kind is encountered in the file, the program must exit properly and return "Error\n" followed by an explicit error message of your choice.