# FILLIT

This is our first group project at Hive Helsinki
![tetris puzzle](https://cdn.pixabay.com/photo/2016/09/18/20/39/cube-1678974_960_720.png)

## GOAL

Our goal was to create a program which takes only one parameter (source file) containing a list of Tetriminos
to assemble. Program needs to arrange every Tetriminos with each others in order to make
the smallest possible square.

We split this project into three sections:

1. **Tetriminos validation** - to check that each tetriminos block is valid and create array of strings containing every block. If true we continue to section two. Else the program returns error message.
2. **Creating array of structs** - which we need in section three. Struct contains information about coordinations of each tetrimino peace. Along with coordinates we assign alphabet to identify each tetrimino starting with 'A'.
3. **Solving the smallest square** - in this section we used recursive backtracking method to solve this puzzle.

## Compiling and Usage

Run **make** from terminal and use following command **./fillit [source file]**. This repository contains tetriminos.txt which you can use as a source file.


