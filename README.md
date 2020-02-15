# BattleShip
Note: This code was developed in TurboC++ so it may not compile and run on macOS devices, 
  and for windows devices, the TurboC++ IDE is required.
  
Summary:

   I developed this project in the senior year of my High School. A player can play the popular strategy game "Battleship" against the computer.
  
   The game involves finding where your opponent placed their 4 ships (Scavenger, Destroyer, Battleship, Carrier), on an 8x8          grid. Players win the game by destroying all of their opponent's ships before their opponent destroys theirs. A ship is     destroyed if a player finds all of the tiles of the 8x8 grid on which the ship is placed. Each ship takes up a unique amount of space: the Scavenger takes 2 squares, the Destroyer takes 3 squares, the Battleship takes 4 squares, and the Carrier takes 5 squares.
  
   The game begins with the player placing their ships. Ships can only be placed horizontally or vertically, can not cross the 
  walls of the 8x8 grid, and can not be placed on top of each other. If a player makes a mistake while placing a ship, the 
  game lets the player place the ship again. After, the player places their ships, the computer runs through all of its 
  formations (a formation is a unique placement of the 4 ships on an 8x8 grid), and chooses the formation it has won 
  the most games with. The player and the computer then take turns guessing tiles on each other's grids. The grids are updated 
  after each move, so that the player knows what happened (if they hit a ship or if they missed). If they hit a ship the first 
  letter corresponding to the ship they hit appears on the tile, but if they miss, the letter 'x' appears on the tile (a 
  player misses if the tile they guess does not have any ships on it).
  
   The game goes on until either the player or the computer wins.
   
  
Techinical Summary:

   Concepts Used: Greedy Algorithms, Binary Files, OOPS, graphics, 3D Arrays,  basic Machine Learning
    
   The computer uses a greedy algorithm to make its decisions.
    
   The computer also learns to choose better starting formations after each game, by counting how many wins or losses it has 
  with a specific formation.
  
   I used OOPS concepts like classes, structures, data encapsulation, etc. to store information about formations, and to hold 
  information about the player and the computer.
  
   I stored the information about formations in a binary file. This is because binary files do not store information in a 
  human readable format, so even if a player opens the file containing the data, they would not be able to understand its 
  contents. Also binary files store information in a more efficient format than normal text files, because they take up lesser 
  space in the memory.
    
   I used 3D Arrays to represent the grids in the game. A 3D array can be percieved as grids stacked up on each other. In 
  the game, the bottom grid would hold the information of where the ships were placed, while the top grid would hold 
  information that the player or computer knows. If a player hits a tile, then the game firsts gets the information in the 
  bottom grid, and then updates it on the top grid. This was implemented to ensure that players would not be able to see where 
  their opponents ships are, until they hit all the tiles corresponding to the ship.
    
   I used the graphics.h header file in TurboC++ to draw the 8x8 grids, to display messages to the user and to accept input 
  from the user.
