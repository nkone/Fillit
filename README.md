*Here's a little picture of my favorite tetris opening.*\
![](images/DT_canon.png)
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
<!--ts-->
* [How to use](#how-to-use)
* [Project Mandatory](#project-mandatory)
* [Algorithm](#algorithm)
* [Details](#details)
  * [Validation](#validation)
  * [Shifting](#shifting)
  * [Linked list](#linked-list)
  * [Collision](#collision)
  * [Backtracking](#backtracking)
  * [Extra](#extra)
* [Final Score](#final-score)
<!--te-->

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
1. Check if the file is valid.
2. Store the **'#'** as an integer array.
3. Shift the pieces.
4. Store the pieces in a linked list.
5. Backtracking.

### Details
#### Validation
For validation, I read in the file twice since reread function is forbidden.

The first time I read, I checked for number of #'s, extra newlines, extra spaces, whether the piece is a block of 4 lines, or invalid characters. The second time, I collect the pieces as an integer array and use it to compare with my macro [table][table] in my header file.

![](images/table.png)

Even though I collected them as integer arrays and shift them top left, I append to my linked list as literal strings matching my macro names. Reason for that is, I want a return NULL if the comparsion returns *false*. If NULL then my program will exit and output "Error". I wasn't sure at that time if there was a better method. If you use this program as reference, you can make it faster if you can shorten this conversion part. After I got the strings, I convert them back to integer arrays ¯\_(ツ)_/¯. You can find my comparison function **get_id()** and **convert_id()** in [*tab_trans.c*][shift].

#### Shifting
Shifting is not that hard, look for *min_x* and *min_y* then subtract them from the integer array of each piece. By doing that all the pieces will move to top left of the board. I also make a separate function called **shift_tet()** for backtracking. It takes in an integer array and shift (*x,y*) (located in [*tab_trans.c*][shift]).

### Linked list
My linked list has three variables (a void pointer, a char, and a pointer to next node of the list). See my [header][table].

![](images/struct.png)

In order to store them, I made two functions **add_piece()** and **append()**. The function *add_piece()* does exactly what it says, add a piece. Since I use a void pointer for my main data, I can point it to an integer array or a string, making it possible for two separate data types. A character (*char c*) is used for identification of the order of the piece. First piece gets 'A'. Second is 'B' and so on. However, because of the structure of linked list, I need the function *append()* to traverse to the end of the list and add a piece there. Most of the structure related functions are located in [*stack.c*][stack]. Most of the linked list structure I learn is from [zentut][zentut].

### Collision
To check for collision, I find the highest x and y in the integer array, then use them to check against the grid I made to work with. Since the grid has a certain size, if any of the number in the array is same as the size then the piece is out of bound. **box_collide()** takes in an integer array and the size of the grid and returns 1 if the piece is out of bound. Not only that but, I also have to check if the piece collide with other pieces on the grid. **piece_collide**() takes in an integer array and the grid I'm working with and use the coordinates in the array to find *'.'* characters on the grid. If the there is a none *'.'* character it will return 1. One thing to notice is that, I have to check for box collision first before piece collision; otherwise, I'd run into segfault error since I go outside of the grid range. You can see [*collision.c*][collision] to see how I did it.

### Backtracking
This is the most challenging part of the project. I can't really track what's happening behind the computer. The algorithm I used is very similar to the bruteforce method for sudoku. First, I create an empty grid. Second, I go through each point on the grid and place the piece if there is no collision. If the recursion returns 0, meaning there is still pieces left in the stack. It will clear the previous piece (replacing the characters with *'.'*). It will keep doing this until the first piece is at the bottom right of the grid and the recursion still returns 0. If so then, it's time to increase the size of the grid. The recursion will only return 1 if the stack is empty.

One thing to note is that, I have to make a copy of every array I use from the linked list. Reason for that is I have to keep each of pieces in the list in there initialized state. Otherwise, when I reuse the piece, the coordinates would be messed up. In other words, you can think of the linked list is just a reference table and the variables in there cannot be altered in any way. See my [*main.c*][main] for more details.

### Extra
Well, since the project is written in C, it's important to check for memory leaks. There are true and weak (reachable) memory leaks. I only handled the true leaks via the linux command *leaks*. I would recommend using valgrind. The valgrind package is not installed on the school system and homebrew doesn't work well with valgrind so I'd suggest install on a virtual machine if you're a 42 student to truly test leaks.

There are three free function I made for this project: **stck_free()**, **stck_free_coord()**, and **free_grid()**. The first two is necessary to free the linked list. Since there are two different structure I made for linked list, one is pointer to string without malloc, another is malloced integer array, I need two different kind of free. I forgot to free the grid after done printing them. The grid function is consider a weak leak so it's *ok*. See [*free_fn.c*][free] for details.

## Final Score
![](images/score.png)

[table]:https://github.com/nkone/Fillit/blob/master/includes/fillit.h
[shift]:https://github.com/nkone/Fillit/blob/master/srcs/tab_trans.c
[stack]:https://github.com/nkone/Fillit/blob/master/srcs/stack.c
[collision]:https://github.com/nkone/Fillit/blob/master/srcs/collision.c
[main]:https://github.com/nkone/Fillit/blob/master/srcs/main.c
[free]:https://github.com/nkone/Fillit/blob/master/srcs/free_fn.c
[zentut]:http://www.zentut.com/c-tutorial/c-linked-list/
