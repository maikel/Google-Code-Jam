# Problem A. Crop Triangles

Some pranksters have watched too much Discovery Channel and now they want to build a crop triangle during the night. They want to build it inside a large crop that looks like an evenly spaced grid from above. There are some trees planted on the field. Each tree is situated on an intersection of two grid lines (a grid point). The pranksters want the vertices of their crop triangle to be located at these trees. Also, for their crop triangle to be more interesting they want the center of that triangle to be located at some grid point as well. We remind you that if a triangle has the vertices (x1, y1), (x2, y2) and (x3, y3), then the center for this triangle will have the coordinates ((x1 + x2 + x3) / 3, (y1 + y2 + y3) / 3).

You will be given a set of points with integer coordinates giving the location of all the trees on the grid. You are asked to compute how many triangles you can form with distinct vertexes in this set of points so that their center is a grid point as well (i.e. the center has integer coordinates).

If a triangle has area 0 we will still consider it a valid triangle.

## Input

The first line of input gives the number of cases, N. N test cases follow. Each test case consists of one line containing the integers n, A, B, C, D, x0, y0 and M separated by exactly one space. n will be the number of trees in the input set. Using the numbers n, A, B, C, D, x0, y0 and M the following pseudocode will print the coordinates of the trees in the input set. mod indicates the remainder operation.

The parameters will be chosen such that the input set of trees will not have duplicates.

	X = x0, Y = y0
	print X, Y
	for i = 1 to n-1
	  X = (A * X + B) mod M
	  Y = (C * Y + D) mod M
	  print X, Y
	Output

For each test case, output one line containing "Case #X: " where X is the test case number (starting from 1). This should be followed by an integer indicating the number of triangles which can be located at 3 distinct trees and has a center that is a grid point.

## Limits

	1 <= N <= 10, 
	0 <= A, B, C, D, x0, y0<= 109, 
	1 <= M <= 109.

### Small dataset

	3 <= n <= 100.

### Large dataset

	3 <= n <= 100000.

## Sample


### Input 

	2
	4 10 7 1 2 0 1 20
	6 2 0 2 1 1 2 11

### Output 

	Case #1: 1
	Case #2: 2

In the first test case, the 4 trees in the generated input set are (0, 1), (7, 3), (17, 5), (17, 7).

# Problem B. Number Sets

You start with a sequence of consecutive integers. You want to group them into sets.

You are given the interval, and an integer P. Initially, each number in the interval is in its own set.

Then you consider each pair of integers in the interval. If the two integers share a prime factor which is at least P, then you merge the two sets to which the two integers belong.

How many different sets there will be at the end of this process?

## Input

One line containing an integer C, the number of test cases in the input file.

For each test case, there will be one line containing three single-space-separated integers A, B, and P. A and B are the first and last integers in the interval, and P is the number as described above.

## Output

For each test case, output one line containing the string "Case #X: Y" where X is the number of the test case, starting from 1, and Y is the number of sets.

## Limits

### Small dataset

	1 <= C <= 10
	1 <= A <= B <= 1000
	2 <= P <= B

### Large dataset

	1 <= C <= 100
	1 <= A <= B <= 1012
	B <= A + 1000000
	2 <= P <= B

## Sample


### Input
 
	2
	10 20 5
	10 20 3

### Output 

	Case #1: 9
	Case #2: 7


# Problem C. Mousetrap

Mousetrap is a simple card game for one player. It is played with a shuffled deck of cards numbered 1 through K, face down. You play by revealing the top card of the deck and then putting it on the bottom of the deck, keeping count of how many cards you have revealed. If you reveal a card whose number matches the current count, remove it from the deck and reset the count. If the count ever reaches K+1, you have lost. If the deck runs out of cards, you win.

Suppose you have a deck of 5 cards, in the order 2, 5, 3, 1, 4. You will reveal the 2 on count 1, the 5 on count 2, then the 3 on count 3. Since the value matches the count, you remove the 3 from the deck, and reset the count. You now have 4 cards left in the order 1, 4, 2, 5. You then reveal the 1 on count 1, and remove it as well (you're doing great so far!). Continuing in this way you will remove the 2, then the 4, and then finally the 5 for victory.

You would like to set up a deck of cards in such a way that you will win the game and remove the cards in increasing order. We'll call a deck organized in this way "perfect." For example, with 4 cards you can organize the deck as 1, 4, 2, 3, and you will win by removing the cards in the order 1, 2, 3, 4.

Input

The first line of input gives the number of cases, T. Each test case starts with a line containing K, the number of cards in a deck. The next line starts with an integer n, which is followed by n integers (d1,d2, ...), indices into the deck.

Output

For each test case, output one line containing "Case #x: " followed by n integers (k1,k2, ...), where ki is the value of the card at index di of a perfect deck of size K. The numbers in the output should be separated by spaces, and there must be at least one space following the colon in each "Case #x:" line.

Limits

Small dataset

T = 100, 1 ≤ K ≤ 5000, 1 ≤ n ≤ 100, 1 ≤ di ≤ K.

Large dataset

T = 10, 1 ≤ K ≤ 1000000, 1 ≤ n ≤ 100, 1 ≤ di ≤ K.

Sample


Input 
 	
Output 
 
2
5
5 1 2 3 4 5
15
4 3 4 7 10

Case #1: 1 3 2 5 4
Case #2: 2 8 13 4


