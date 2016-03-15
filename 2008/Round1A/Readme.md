# Problem A. Minimum Scalar Product

You are given two vectors v1=(x1,x2,...,xn) and v2=(y1,y2,...,yn). The scalar product of these vectors is a single number, calculated as x1y1+x2y2+...+xnyn.

Suppose you are allowed to permute the coordinates of each vector as you wish. Choose two permutations such that the scalar product of your two new vectors is the smallest possible, and output that minimum scalar product.

## Input

The first line of the input file contains integer number T - the number of test cases. For each test case, the first line contains integer number n. The next two lines contain n integers each, giving the coordinates of v1 and v2 respectively.

## Output

For each test case, output a line

	Case #X: Y

where X is the test case number, starting from 1, and Y is the minimum scalar product of all permutations of the two given vectors.
Limits

### Small dataset

	T = 1000
	1 ≤ n ≤ 8
	-1000 ≤ xi, yi ≤ 1000

### Large dataset

	T = 10
	100 ≤ n ≤ 800
	-100000 ≤ xi, yi ≤ 100000

## Sample


### Input

	2
	3
	1 3 -5
	-2 4 1
	5
	1 2 3 4 5
	1 0 1 0 1
	
### Output 
 
	Case #1: -25
	Case #2: 6


# Problem B. Milkshakes

You own a milkshake shop. There are N different flavors that you can prepare, and each flavor can be prepared "malted" or "unmalted". So, you can make 2N different types of milkshakes.

Each of your customers has a set of milkshake types that they like, and they will be satisfied if you have at least one of those types prepared. At most one of the types a customer likes will be a "malted" flavor.

You want to make N batches of milkshakes, so that:

- There is exactly one batch for each flavor of milkshake, and it is either malted or unmalted.
- For each customer, you make at least one milkshake type that they like.
- The minimum possible number of batches are malted.

Find whether it is possible to satisfy all your customers given these constraints, and if it is, what milkshake types you should make.
If it is possible to satisfy all your customers, there will be only one answer which minimizes the number of malted batches.

## Input

One line containing an integer C, the number of test cases in the input file.
For each test case, there will be:
- One line containing the integer N, the number of milkshake flavors.
- One line containing the integer M, the number of customers.
- M lines, one for each customer, each containing:
  - An integer T >= 1, the number of milkshake types the customer likes, followed by
  - T pairs of integers "X Y", one for each type the customer likes, where X is the milkshake flavor between 1 and N inclusive, and Y is either 0 to indicate unmalted, or 1 to indicated malted. Note that:
    - No pair will occur more than once for a single customer.
    - Each customer will have at least one flavor that they like (T >= 1).
    - Each customer will like at most one malted flavor. (At most one pair for each customer has Y = 1).

All of these numbers are separated by single spaces.

## Output

C lines, one for each test case in the order they occur in the input file, each containing the string "Case #X: " where X is the number of the test case, starting from 1, followed by:
The string "IMPOSSIBLE", if the customers' preferences cannot be satisfied; OR
N space-separated integers, one for each flavor from 1 to N, which are 0 if the corresponding flavor should be prepared unmalted, and 1 if it should be malted.
Limits

### Small dataset

	C = 100 
	1 <= N <= 10 
	1 <= M <= 100

### Large dataset

	C = 5 
	1 <= N <= 2000 
	1 <= M <= 2000

The sum of all the T values for the customers in a test case will not exceed 3000.

## Sample


### Input 
 
	2
	5
	3
	1 1 1
	2 1 0 2 0
	1 5 0
	1
	2
	1 1 0
	1 1 1

### Output 

	Case #1: 1 0 0 0 0
	Case #2: IMPOSSIBLE

In the first case, you must make flavor #1 malted, to satisfy the first customer. Every other flavor can be unmalted. The second customer is satisfied by getting flavor #2 unmalted, and the third customer is satisfied by getting flavor #5 unmalted.

In the second case, there is only one flavor. One of your customers wants it malted and one wants it unmalted. You cannot satisfy them both.

# Problem C. Numbers

In this problem, you have to find the last three digits before the decimal point for the number (3 + √5)n.

For example, when n = 5, (3 + √5)5 = 3935.73982... The answer is 935.

For n = 2, (3 + √5)2 = 27.4164079... The answer is 027.

## Input

The first line of input gives the number of cases, T. T test cases follow, each on a separate line. Each test case contains one positive integer n.

## Output

For each input case, you should output:

	Case #X: Y

where X is the number of the test case and Y is the last three integer digits of the number (3 + √5)n. In case that number has fewer than three integer digits, add leading zeros so that your output contains exactly three digits.

## Limits

	1 <= T <= 100

### Small dataset

	2 <= n <= 30

### Large dataset

	2 <= n <= 2000000000

## Sample


### Input 

	2
	5
	2
	
### Output 
 
	Case #1: 935
	Case #2: 027

