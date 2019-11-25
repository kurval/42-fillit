# FILLIT

![tetris puzzle](https://cdn.pixabay.com/photo/2016/09/18/20/39/cube-1678974_960_720.png)

## GOAL

Our goal was to create a program which takes only one parameter (source file) containing a list of Tetriminos
to assemble. Program needs to arrange every Tetriminos with each others in order to make
the ***smallest possible square***!

We split this project into three parts:

1. **Tetriminos validation** - to check that each tetriminos block is valid and create array of strings containing every block. If blocks are valid we can move to section two. Else the program returns error message.
2. **Creating array of structs** - which we need in section three. Single struct contains coordinations of tetrimino's '#' -characters. Along with coordinations we assign alphabet to identify each tetrimino starting with 'A'.
3. **Solving the smallest square** - in this section we used recursive backtracking method to solve this puzzle. In this part we can use coordinations from previous part to check if the current place is empty in our map.

## Compiling and Usage

Run **make** from terminal and use following command **./fillit [source file]**.
## EXAMPLE

tetriminos.txt:

```
....
##..
.#..
.#..

....
####
....
....

#...
###.
....
....

....
##..
.##.
....
```
execution:
```
~ make
~ ./fillit tetriminos.txt 

DDAA
CDDA
CCCA
BBBB
```
