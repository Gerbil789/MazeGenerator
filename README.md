# MazeGenerator
C++ program that can generate and solve maze

This program is using SFML library for visualization.   
https://www.sfml-dev.org/tutorials/2.5/  
You need to install it if you want to run it.  
Then you can compile it with makefile.

Program takes 4 (optional) argumets
First argument:  
Choose algorithm to generate maze
    0 = DepthFirstSearch (default)
    1 = PrimsAlgrorithm
    
Second argument:
  Choose algortihm to solve maze  
    0 = DepthFirstSearch (default)  
    1 = DeadEndFilling  

Third argument:
  set maze width  
    16 (default)  
    
Last argument:
  set maze height  
    16 (default)  

Example:  
  ./mazeGenerator   
  ./mazeGenerator 0 0 16 16  
  ./mazeGenerator 1 1 8 12  
