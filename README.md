*Here's a little picture of my favorite tetris opening.*\
![](DT_canon.png)
# PROJECT: FILLIT
C project: write a program that reads a file of tetrominos, then output them (without rotations) with a least amount of empty spaces. There are multiple solutions; however, pieces are prioritized top left based on the order coming from the file. Refer to [pdf][pdf] for more details.

[pdf]:https://github.com/nkone/Fillit/blob/master/fillit.pdf

**Sample file**
>.\.\.#\
>.\.\.#\
>.\.\.#\
>.\.\.#
>
>\##.\.\
>\##.\.\
>.\.\.\.\
>.\.\.\.

**Output**
>ABB\.\
>ABB\.\
>A.\.\.\
>A.\.\.

## Table of Contents
* [How to use](#how-to-use)
* [Project Mandatory](#project-mandatory)

### How to use
```
git clone https://github.com/nkone/Fillit
make
```
After make, run the binary executable called fillit like so
```
./fillit sourcefile
```
If a sourcefile is invalid, the program will display error.

>./fillit sample | cat -e
>Error

Make sure the each piece in the file, except the last piece, is followed by a newline. There can't be other characters, except **'.'** and **'#'**. Each tetromino must be valid. Refer to [sample.txt][sample].

[sample]:https://github.com/nkone/Fillit/blob/master/sample.txt

### Project Mandatory
For projects written in C, students at 42 must follow [Norm][norm] standard for 42SiliconValley.

Functions allowed: **open**, **close**, **exit**, **read**, **write**, **malloc**, and **free**.


[norm]:https://github.com/nkone/Fillit/blob/master/norme.en.pdf

### Algorithm
I broke this project up into multiple steps:
1. Check if the file is valid (find illegal characters, extra spaces, extra **'#'**).\
2. Store the **'#'** as an integer array.
3. Shift the pieces.
4. Store the pieces in a linked list.
5. Backtracking.

[table]:https://github.com/nkone/Fillit/blob/master/includes/fillit.h
