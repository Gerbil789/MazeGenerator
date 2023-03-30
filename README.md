# MazeGenerator
C++ program that can generate and solve a maze

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


https://user-images.githubusercontent.com/67593297/228971483-fd6218fe-48bd-4d13-993d-9a0b30684739.mp4  

  
    
TO DO:  
DepthFisrtSearch algorithm for solving maze sometimes does not draw full path.  
Some algorithms can be more optimized.  
Code cleanup.  
Add more comments.
