# Fillit. School_42 project
Fillit is a project about a recurring problematic in programming: searching the optimal solution among a huge set of possibilities, in a respectable timing.

It`s a group project for two students. I wrote data parsing, validation and creation of matrix for algorithm, my teammate wrote backtracing algorythm.

## Subject
In this particular project, program will have to find a way to assemble a given Tetriminos (Tetris pieces) set altogether in the smallest possible square.

The executable must take only one parameter, a file which contains a list of Tetriminos to assemble. This file has a very specific format : every Tetrimino must exactly fit in a 4 by 4 chars square and all Tetrimino are separated by an newline each. The file should contain between 1 and 26 Tetriminos

The description of a Tetriminos must respect the following rules:
* precisely 4 lines of 4 characters, each followed by a new line (well... a 4x4 square).
* a Tetrimino is a classic piece of Tetris composed of 4 blocks.
* each character must be either a block character(’#’ ) or an empty character (’.’).
* each block of a Tetrimino must touch at least one other block on any of his 4 sides (up, down, left and right).

A rotated Tetrimino describes a different Tetrimino from the original, in the case of this project. This means no rotation is possible.

The program must display the smallest assembled square on the standard output. To identify each Tetrimino in the square solution, there will assign a capital letter to each Tetrimino, starting with ’A’ and increasing for each new Tetrimino.

If the file contains at least one error, the program must display error

## Example

The Tetrimino file content:


    ....
    ..#.
    .##.
    ..#.
    
    .##.
    ##..
    ....
    ....
    
    ....
    ..##
    .##.
    ....
    
    #...
    #...
    #...
    #...
    
    .#..
    .#..
    .##.
    ....
    
    ....
    ..#.
    ..##
    ...#
    
    ....
    ..##
    ..##
    ....
    
    .#..
    .#..
    .##.
    ....
    
    .#..
    .##.
    .#..
    ....

The program output:

    .A.BBCC
    AABBCCD
    EAF.GGD
    E.FFGGD
    EEHFI.D
    ..H.II.
    ..HHI..

## Algorithm
To solve this problem, the "Algorithm X" of Donald Knuth was used. "The most obvious trial-and-error approach" for finding all solutions to the exact cover problem".

The program creates a matrix of all possible options for the location of each figure. Then, backtracing occurs by Algorithm X. Additional productivity is obtained due to the implementation of the matrix through multiply connected lists ("Dancing links").

## Usage
Run **make** to compile program.

Then, ./fillit [file]  where [file] is file with Tetriminos. 

You can find test files with Tetriminos in Recources directory (files taked from https://github.com/jgigault/42FileChecker).
