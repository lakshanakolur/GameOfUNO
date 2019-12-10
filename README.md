# GAME OF UNO

Simple 2- player game of UNO implemented using Arrays and Stacks and containing features of adding cards to a pile, picking up cards, Draw4 and other such features of the game.

## DATA STRUCTURES:

For main pile, **Array**
•	Randomize,
For discard pile: **Stack**
•	Push
•	Peek
For Player hand card: **Singly linked list:**
•	Insert at the end
•	Delete by info

## How to Play the Game

Number of Players: 2 you and the computer

#### Dealing cards:
1. RED: 0,1,2,3,4,5,6,7,8,9, skip, reverse, draw two.
2. BLUE: 0,1,2,3,4,5,6,7,8,9, skip, reverse, draw two.
3. YELLOW: 0,1,2,3,4,5,6,7,8,9, skip, reverse, draw two.
4. GREEN: 0,1,2,3,4,5,6,7,8,9, skip, reverse, draw two.
5. 2 wild cards , 2 wild draw four’s.

- Deal seven cards to computer and to player.
- Player 7 cards are allotted : 

#### EXAMPLE: 
##### Player: 
Red 1, Blue 2, green 3, yellow 4, yellow 7, Blue 7, red skip
##### Computer: 
Red 5, Blue 6, green 9, yellow 9, yellow 0, Blue 4, green reverse.
##### Main draw pile: 
Everything other than the above 14. IT CAN ONLY POP.
##### Discard Pile: 
IT CAN PUSH AND POP.

##### KEYS:
*== Main Draw*

*~~Computer*

*— Player*

##### GAME BEGINS:
==> yellow 6

~~> yellow 9

—> yellow 4

~~> blue 4

—> blue 2

~~> blue 6

—> blue 7

~~> (doesn’t have card so draws one from pile, turns out to be GREEN 4, can’t play it so proceeds to next player)
==> POP green 4

—> yellow 7

~~> yellow 0

—> (doesn’t have card so draws one from pile, turns out to be WILD so plays it)
—>WILD
—> red skip

~~>(Misses a turn)

—> red 1
—> “UNO”

~~> (doesn’t have card so draws one from pile, turns out to be RED 3, plays it)
==>POP red 3
~~> red 3

—> green 3
“PLAYER WINS”
__________________________________________________________





