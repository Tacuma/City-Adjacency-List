Graph Traversal
===============


Data Structures/Concepts Used:
==============================
Adjacency List, Array of Structs, Pointers, Nested Loops,
Object Oriented Programming (OOP), File I/O, Header and cpp files


Description:
============
This assignment asks you to write a program that 
	(1) reads a data file named infile.txt and constructs the adjacency list above and 
	(2) finds if there is any two-legged path (route) between the two cities.
YOU DONOT HAVE THE USE A STACK. A NESTED LOOP IS ADEQUATE FOR TWO-LEGGED PATHS
Next, the program should prompt the user be enter the names of two cities 
between which a path is requested. The program should then locate any path 
between the two cities and compute the distance of the path

infile.txt
----------
	Atlanta 2 5 800   6 600
	Austin  2 3 200 5 160
	Chicago 1 4 1000
	Dallas 3 1 200 2 900 4 780
	Denver 2 0 1400 2 1000
	Houston 1 0 800
	Washington 2 0 600 3 1300


Output:
=======
	Tacuma Solomon
	Computer Science 3

	Atlanta 5 800 6 600
	Austin 3 200 5 160
	Chicago 4 1000
	Dallas 1 200 2 900 4 780
	Denver 0 1400 2 1000
	Houston 0 800
	Washington 0 600 3 1300


	Enter two cities that you wish to find a path: Austin Chicago
	A path exists between Austin and Chicago .
	Distance of Path: 1100



	() Code by Tacuma Solomon
	() Not for Redistribution or Reuse.

Press any key to continue . . .
