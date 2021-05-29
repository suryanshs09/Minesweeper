# Minesweeper
> Terminal based minesweeper game coded in C++.
## Table of contents
* [General info](#general-info)
* [Technologies](#technologies)
* [How to play](#how-to-play)
* [Understanding code](#understanding-code)

## General info
Welcome to the minesweeper game. In this game the mines are hidden at random locations in the board and the player needs to find out these locations with the help of numbers hidden in the board. Each number indicates the number of mine(s) present around them. 
Flag all the locations of mines to win the game but, be aware. If any mine explodes, it will genrate a chain-reaction and explode all the mines present in the board and you will lose the game.

> _The bomb Character:_ **`*`**
>
> _The flag Character:_ **`#`**
>
> _The Character to hide:_ **`.`**
	
## Technologies
Project is created with:
* Turbo C++ 4.0 Windows 7 Windows 8 64Bit Version

## How to play
When you will open the game it will display the general info of the game on the _Introduction_ page and will ask you the size of board you want play on.
> _Avoid choosing size of board more than 10 so that board get display properly_

After you provide the size of board let's say suppose **`n`** then the board will be created of dimensions **`n x n`** and the 

**`20% of total n x n cells of board will contain Mines at random locations`**

After the board is created of desired size we can view it on the _Game_ page along with other details like total numer of mines present and total number of locations flaged

Now, the player will have 4 options to play the game:
* Press 1 to open a position
* Press 2 to Flag a position
* Press 3 to Undo Flag
* Press 4 to Submit

As it is a terminal version of minsweeper, it dosn't have a facility of clicking a location to access it for opening/flagging it. Rather, we have to enter the row and column number of the cell we have to access after we select the desired operation.

> _The number of moves are counted, so each time you select an operation from the options the moves count get incremented by 1._

**_If you Press 1:_**

the open location option will get selected and the game will ask us to enter the row and column number of the cell we want to open. We can only open a location if it is not flagged or opened priviously and the entered row and column number is valid and still in hidden state.
After you open a location successfully the board will get updated accordingly to the character which was hidden.

_If the hidden character was a number betwwen 1 and 8 inclusivly:_
the location will get opened normally.

_If the character was the bomb:_
it will start a chain reaction and all the bombs in the board will get exploded and the game will get over.

_If the character was '0':_
it will open all the locations around it until it find the locations containing a number between 1 and 8. 

Back to [Table of contents](#table-of-contents)

## Understanding code


Back to [Table of contents](#table-of-contents)
