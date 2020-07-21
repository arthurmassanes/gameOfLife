# gameOfLife
Conway's (RIP) Game of Life implemented in C++

# Requirements
`g++`
`sfml-window, lsfml-system, sfml-graphics`
`make`

# Installation & Compilation
```bash
git clone https://github.com/arthurmassanes/gameOfLife/
cd gameOfLife
make
./gameOfLife
```
# Maps
Maps are ascii text files, with spaces representing dead cells (any character will be interpreted as a cell)

Pass an empty text file to the game and it will overwrite it on save (*Return*)

# Usage
`./gameOfLife` *Starts with default map (`maps/default.map`)*

`./gameOfLife map_name` *Starts with map "map_name"*

`./gameOfLife -h` *Displays usage*

![Screenshot 1](https://raw.githubusercontent.com/arthurmassanes/gameOfLife/master/screenshots/screen1.png)

