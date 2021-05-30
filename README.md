# Minesweeper
> Terminal based minesweeper game coded in C++.
## Table of contents
* [General info](#general-info)
* [Technologies](#technologies)
* [How to play](#how-to-play)
* [Understanding code](#understanding-code)
* [Features in upcoming version](#features-in-upcoming-version)

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

the open location option will get selected and the game will ask us to enter the row and column number of the cell we want to open. We can only open a location if it is not flagged or opened priviously and the entered row and column number is valid.
After you open a location successfully the board will get updated accordingly to the character which was hidden.

_If the hidden character was a number betwwen 1 and 8 inclusivly:_
the location will get opened normally.

_If the character was the bomb:_
it will start a chain reaction and all the bombs in the board will get exploded and the game will get over.

_If the character was '0':_
it will open all the locations around it until it find the locations containing a number between 1 and 8.

**_If you Press 2:_**

the flag location option will get selected and the game will ask us to enter the row and column number of the cell we want to flag. We can only flag a location which was not opened or flagged previously and the entered row and column number is valid.
After you flag a location it's character will change from hidden to flag characterno matter what is the valus of the location.
> _Each time you flag a location the flag count will be incremented but be aware don't flag a location unnecessarily. The flag count is limited to number of mines and you cannot flag more than the number of mines present in the board._

**_If you Press 3:_**

The undo flag location will get selected and the game will ask us to enter the row and column number of the cell we want to remove flag from. We can only remove flag from the location which is still flagged and the entered row and column number is valid. It is a important feature of the game as the number of flags are limitted and you may want to re-think about some locations before submitting your game.

**_If you Press 4:_**

The submit operation will get selected. you should select it only when you want to quit the game or you have completed it. if you select this option before using all your flags the game will ask for your confirmation and if you confirm your submission, it will show the _Result_ page where your number of moves and the score scored by the player.
> _The score is calculated after the submission. Each loaction opened safly increase score value by 1 and each location flagged correctly increase score value by 10._

Back to [Table of contents](#table-of-contents)

## Understanding code


Back to [Table of contents](#table-of-contents)

## Features in upcoming version
The next version will conatin these updates:
*  **_Difficulty level:_** By default the game conatins 20% mines, after adding this the game will ask the player for the desired difficulty level.
	* _Beginner:_ containing 10% mines.
	* _Easy:_ containing 20% mines.
	* _Medium:_ containing 25% mines.
	* _Hardy:_ containing 35% mines.
* **_Leader Board Result:_** After the submissions the _Result_ page just shows the result of the current match but instead in the next version due to this feature the game will ask player to enter player name and store the player name, difficulty, board size, number of moves and the score scored by player in a database which will get displayed after the result of current game in the form of a Leader board.
* **_More Accurate Score:_** the score calculation will also include number of moves as variable for a more accurate score in the next update.  

Back to [Table of contents](#table-of-contents)
