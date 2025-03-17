# Algorithm Problems Solutions

## Problem 1: Servers

### Problem Statement
Given a group of N servers, each with a specified computing power `Pi` and an optimal power requirement `Ci`, the servers function optimally when powered with exactly `Ci` units of energy. Any deviation in the supplied power (either above or below the requirement) reduces the computing power by 1 unit for each unit of mismatched energy. Computing power can become negative due to this mismatch.

Our goal is to find the maximum achievable combined computing power of the system when all servers are powered with the same amount of energy. We control this power supply, and our challenge is to maximize the minimum power of the system across all servers.

### Input Data
The data is provided in a file named `servere.in`:
- The first line contains the integer N, the number of servers.
- The second line lists N integers, these being the computing powers `Pi` of the servers.
- The third line lists N integers, these being the optimal power requirements `Ci` for each server.

### Output Data
The output must be written to a file named `servere.out`. It will contain the maximum achievable minimum computing power, formatted with one decimal place.

### Solution Overview
The task is implemented using a C++ class called `Task` (skeleton taken from the laboratory framework). The class includes methods for reading input data, processing to find the result, and writing the output. The main calculation uses a ternary search over the range of possible power supply values, seeking to maximize the minimum computing power after accounting for penalties due to power mismatch.

#### Key Methods
- `read_input()`: Reads input data from `servere.in`.
- `get_result()`: Implements the main logic using a ternary search over possible power supply values to determine the maximum achievable minimum power.
- `calculate_min_power(double current)`: Calculates the minimum system power for a specific power supply `current`.
- `print_output(double result)`: Writes the result to `servere.out` using precision formatting.

### Conclusion
The implementation allows efficient evaluation of the optimal power supply strategy to maximize the minimum computing power of a server cluster, considering deviations from ideal power supply.

## Problem 2: Coloring

### Problem Statement
Gigel has become increasingly passionate about painting. However, his talent is limited, so he decided to purchase a paint-by-numbers set. Exploring the options on AlgoExpress, he discovered an attractive option for a painting he can color himself.

The painting has a length of N centimeters and a width of 2 centimeters, with each 1 cm² square needing to be colored. The coloring rules are specific:
- Only 3 colors can be used: yellow, pink, and purple.
- Coloring is done on rectangles of 1x2 cm dimensions, either horizontally or vertically, and the entire rectangle must be colored the same.
- Two adjacent rectangles (with a common side) must be colored differently.

Gigel is curious to know in how many different ways the finished painting could look. The goal is to determine the number of distinct possible patterns, calculated modulo 10^9 + 7.

### Input Data
From the file `colorare.in`:
- The first line contains the natural number K, indicating the number of consecutive sections of the painting and their type (horizontal or vertical).
- The second line will contain K pairs of the form "X T", where "X" is the number of consecutive zones of the same type "T", and "T" is the character 'H' for horizontal or 'V' for vertical.

### Output Data
In the file `colorare.out`, write the number of distinct paintings that can be created, modulo 10^9 + 7.

### Detailed Solution
The implementation is done in C++ in a class called `Task`. It includes methods for reading input data, calculating the result, and writing the output. The algorithm uses modular exponentiation to calculate the number of possible arrangements based on the given constraints and the type of consecutive sections in the painting.

#### Key Methods
- `read_input()`: Reading data from the `colorare.in` file.
- `get_result()`: Determines the number of possible patterns by applying coloring rules and calculates results using fast modular exponentiation.
- `my_pow(unsigned long int base, unsigned long int exponent)`: Calculates `(base^exponent) % MOD` using the fast exponentiation method.
- `print_output(unsigned long long result)`: Writes the result to the `colorare.out` file.

### Conclusion
The proposed solution offers an efficient method to calculate the number of possible configurations for Gigel's painting, taking into account the coloring restrictions and the structure of the input data. The modular implementation and use of fast exponentiation ensure the necessary performance to handle large cases within the specified time limits.

## Problem 3: Compression

### Problem Statement
Consider an operation on a sequence of numbers, where a subsequence is selected and replaced with the sum of its elements. For example, from the sequence [1, 6, 2, 4, 5] and choosing the subsequence [6, 2, 4], we get [1, 12, 5].

Given a sequence A of length n and a sequence B of length m, the task is to determine if we can obtain two equal sequences through zero or more applications of the defined operation on A or B, and to find the maximum length of the resulting sequence.

### Input Data
From the file `compresie.in`:
- The first line contains the natural number n, representing the length of sequence A.
- The second line contains n natural numbers, the elements of sequence A.
- The third line contains the natural number m, representing the length of sequence B.
- The fourth line contains m natural numbers, the elements of sequence B.

### Output Data
In the file `compresie.out`, write the maximum length of the resulting sequence or "−1" if two equal sequences cannot be obtained.

### Detailed Solution
The implementation is done in C++ in a class called `Task`. It includes methods for reading input data, processing data to determine if two sequences can become identical, and writing the result.

#### Key Methods
- `read_input()`: Reading data from the `compresie.in` file.
- `get_result()`: Processes the sequences to determine if they can be made equal through successive compressions and identifies the maximum length of the equal sequence obtained.
- `merge_like_crazy()`: Attempts to "compress" elements from a sequence until their sum equals or exceeds a certain target value. This is useful for aligning values of sequences A and B when they differ.
- `print_output()`: Writes the result to the `compresie.out` file.

### Conclusion
This solution provides an efficient method to evaluate and transform sequences to determine if they can be compressed to produce identical sequences. By using the compression technique, it is possible to quickly identify the possibility of equalizing the two sequences and determine the maximum length of the resulting sequence.

## Problem 4: Encrypted

### Problem Statement
The goal is to build a strong password generator that produces passwords as long as possible to be difficult to crack. We also have specific criteria that must be met:
- We have a list of N preferred words available.
- Passwords must be formed only by concatenating these words, with each word being used at most once.
- Passwords must have a dominant letter, meaning a letter that appears more frequently than half the total length of the password.
The objective is to determine the maximum length of such a password that can be constructed.

### Input Data
From the file `criptat.in`:
- The number N of words we have available.
- On the next N lines, each line contains a word.

### Output Data
In the file `criptat.out`, write the maximum length of the password that can be constructed, according to the specified criteria.

### Detailed Solution
The implementation is done in C++ in a class called `Task`. It includes methods for reading input data, processing data to determine the maximum password length, and writing the result.

#### Key Methods
- `read_input()`: Reading data from the `criptat.in` file.
- `get_result()`: Processes the data to construct the longest password that meets the condition of having a dominant letter.
- `print_output()`: Writes the maximum length obtained to the `criptat.out` file.

#### Processing Logic
- Calculate the frequencies of each character for each word and in total.
- Determine the character with the maximum frequency.
- Sort the words based on their contribution to the frequency of the dominant character.
- Build the password by concatenating words, ensuring the dominant letter maintains the specified condition.
- Repeat the process for each possible dominant letter until the maximum possible length is determined.

### Conclusion
This solution provides an efficient method to evaluate and build strong passwords using a given set of words, ensuring they meet security requirements by imposing a dominant letter. The method of sorting and selecting words maximizes the password length while respecting all imposed constraints.

## Problem 5: Offer

### Problem Statement
The organizers of an algorithmic hackathon face a challenge: to buy consumables (snacks, water, sodas, etc.) for the event, taking advantage of supermarket offers. The offers are:
1. A 50% discount for the cheaper product when two products are grouped.
2. The cheapest product is free when three products are grouped.

All products must be purchased and are already placed on the conveyor belt. The goal is to minimize the total cost of products through intelligent grouping.

### Input Data
From the file `oferta.in`:
- `N`, the number of products on the belt.
- `K`, for the first requirement it is 1, representing that the minimum price is sought.
- The prices of the N products in their order on the belt.

### Output Data
In the file `oferta.out`, write the minimum possible price, formatted with one decimal place.

### Detailed Solution
The implementation is done in C++ in a class called `Task`. It includes methods for reading input data, calculating the result by evaluating all possibilities of grouping products, and writing the result.

#### Key Methods
- `read_input()`: Reading the number of products and their prices from the file.
- `get_result()`: Calculates the minimum possible cost using a dynamic programming vector, `dp`, where `dp[i]` represents the minimum cost for the first i products.
- `print_output()`: Writes the calculated result to the `oferta.out` file.

#### Algorithm
- Initialize `dp[0] = 0` to indicate there is no cost without products.
- For each product, calculate the minimum cost of adding it alone, in a group of two, or three products, updating the `dp` vector according to the offers.
- Use the `min` function to choose the most advantageous option for grouping products to minimize the total cost.

### Conclusion
This solution provides an efficient method to determine how to purchase products to minimize the total cost, taking into account the available offers. The dynamic programming algorithm ensures that each decision to group products is optimal in context.

# README - Assignment 2

## Problem: Counting

### Description
Adrian, nostalgic for his student days, wonders how similar the training routes of the Police Academy are to the roads in Bucharest. In this context, the problem requires determining the number of common elementary chains between two directed acyclic graphs, each having the same number of nodes and edges.

An elementary chain from node 1 to node N is defined as follows:
- It starts from node 1 and ends at node N.
- Each node in the chain has a directed edge towards the next node in the chain.
- All nodes in the chain are distinct.

Two chains are considered common if they have the same sequence of nodes.

### Input Data
- The first line of the `numarare.in` file contains two natural numbers `N` and `M`, representing the number of nodes and the number of edges.
- The next `M` lines contain two natural numbers `x` and `y` each, indicating a directed edge from `x` to `y` in the first graph.
- The next `M` lines contain two natural numbers `x` and `y` each, indicating a directed edge from `x` to `y` in the second graph.

### Output Data
- In the `numarare.out` file, you must write the number of common elementary chains from 1 to N in the two graphs, modulo `10^9 + 7`.

### Constraints
- `1 ⩽ N ⩽ 10^5`
- `1 ⩽ M ⩽ 2 * 10^5`
- `1 ⩽ x < y ⩽ N`

### Solution
The proposed solution consists of the following steps:
1. Reading the input data and storing them in appropriate structures.
2. Creating the adjacency lists for both graphs.
3. Identifying common edges between the two graphs and building a new adjacency list for these common edges.
4. Performing a topological sort on the resulting graph from common edges to determine the order of processing the nodes.
5. Using a dynamic programming algorithm to calculate the number of elementary chains from node 1 to node N.

### Complexity
The time complexity of the algorithm is `O(N + M)`. This complexity is due to the graph traversal and the application of topological sorting, followed by the dynamic processing of nodes.

## Problem: Trains

### Description
Bogdan Urzescu, inspired by the trains in Switzerland, wants to make a long journey. Having a list of M direct routes between various cities, Bogdan wants to find the maximum number of distinct cities he can visit, starting from one city and reaching the destination. It is guaranteed that Bogdan can reach the destination and that the train network contains no cycles, meaning there is no possibility of returning to the same city after leaving it.

### Input Data
- The first line of the `trenuri.in` file contains the names of the departure city and the destination city, separated by a space.
- The second line contains a natural number `M`, representing the number of direct routes.
- The next `M` lines contain two character strings `x` and `y` each, indicating a direct route from city `x` to city `y`.

### Output Data
- In the `trenuri.out` file, you must write a single number, representing the maximum number of distinct cities Bogdan can visit.

### Constraints
- `1 ⩽ M ⩽ 2 * 10^5`
- City names consist only of lowercase letters of the English alphabet.
- City names are real.

### Solution
The proposed solution consists of the following steps:
1. Reading the input data and storing them in appropriate structures.
2. Building a directed graph using adjacency lists.
3. Using a depth-first search (DFS) algorithm to calculate the maximum number of distinct cities that can be visited.
4. Using dynamic programming to memorize and reuse intermediate results, thus optimizing the calculation of maximum paths.

### DFS Algorithm and Dynamic Programming
- We start from the departure city and explore all possible routes to adjacent cities.
- If we reach the destination city, we return 1 to mark the end of a valid path.
- We use a memoization table (`dp`) to avoid recalculating maximum paths from already visited nodes.

### Complexity
The time complexity of the algorithm is `O(N + M)`, as each edge is processed only once during the DFS traversal.

## Problem: Roads

### Description
In this problem, a directed graph with costs on edges and three nodes x, y, and z is given. The task is to find a subset of edges whose sum is minimal, such that there exists at least one path starting from node x and at least one path starting from node y, both ending at node z.

### Input Data
- The first line of the `drumuri.in` file contains two natural numbers, N and M, representing the number of nodes and the number of edges.
- The next M lines contain three numbers a, b, c each, indicating a directed edge from a to b with cost c.
- The last line contains three natural numbers x, y, and z, with the meanings given in the statement.

### Output Data
- In the `drumuri.out` file, you must write a single integer, representing the minimum sum of a subset of edges that meet the requirements from the statement.

### Constraints
- `1 ⩽ N ⩽ 10^5`
- `1 ⩽ M ⩽ 2 * 10^5`
- `1 ⩽ c ⩽ 10^9`
- It is guaranteed that there is at least one path from x to z and at least one path from y to z in the initial graph.

### Solution
The solution consists of the following steps:
1. Reading the input data and storing them in appropriate structures.
2. Building the adjacency list for the initial graph and for the transposed graph.
3. Calculating the minimum paths from x and y to all nodes using Dijkstra's algorithm.
4. Calculating the minimum paths from z to all nodes in the transposed graph using Dijkstra's algorithm.
5. Determining the minimum cost of the path that fulfills the required conditions by iterating over the nodes and updating the minimum cost.

### Algorithms Used
- **Dijkstra**: Dijkstra's algorithm is used to calculate the minimum distances from nodes x, y, and z to all other nodes.
- **Transposed Graph**: To calculate the minimum paths to z, the transposed graph is used, in which all edges are reversed.

### Complexity
The time complexity of the algorithm is `O((N + M) log N)`, as each execution of Dijkstra's algorithm has this complexity.

## Problem: Scandal (Bonus)

### Description
Andrei and Adrian want to avoid scandals at the parties they organize by establishing rules for their guests. The two have N common friends and M rules of type `(x, y, c)`, which can mean the following:
- If `c = 0`, then at least one of the friends `x` or `y` must attend the party.
- If `c = 1`, then if `x` does not attend the party, neither will `y`.
- If `c = 2`, then if `y` does not attend the party, neither will `x`.
- If `c = 3`, then at least one of `x` and `y` does not attend the party.

The goal is to determine a possible list of guests who can be invited to the party without breaking any of the rules. If there are multiple solutions, any of them can be displayed.

### Input Data
- On the first line of the `scandal.in` file, there are two natural numbers `N` and `M`, representing the number of friends and the number of rules.
- The next `M` lines contain a triplet of numbers `x, y, c` each, with the meanings from the statement.

### Output Data
- In the `scandal.out` file, you will write on the first line a single number, the number of guests at the party.
- On the following lines, you will write one guest per line.

### Constraints
- `1 ⩽ N ⩽ 10^5` (number of friends)
- `1 ⩽ M ⩽ 2 * 10^5` (number of rules)
- `1 ⩽ x, y ⩽ N`
- `0 ⩽ c ⩽ 3`

### Solution
The solution uses Kosaraju's algorithm to detect strongly connected components in the graph and to decide on guests according to the given rules. Kosaraju's algorithm consists of two DFS traversals:
1. The first DFS traversal to determine the order of node completion.
2. The second DFS traversal on the transposed graph to determine strongly connected components.

### Implementation Steps
1. Reading the input data and building the adjacency lists for the graph and the transposed graph.
2. Implementing Kosaraju's algorithm to find strongly connected components.
3. Checking the components to ensure the rules are respected and to identify the guests.

### Complexity
The time complexity of the algorithm is `O(N + M)`, as each edge and each node are processed twice (once in the initial graph and once in the transposed graph).

# Bibliography

Resources used:

- [PA Laboratory](https://ocw.cs.pub.ro/courses/pa/laboratoare/shortest-paths-problem)
- [Graph Data Structure and Algorithms (GeeksforGeeks)](https://www.geeksforgeeks.org/graph-data-structure-and-algorithms/)
- [Kahn's Algorithm (GeeksforGeeks)](https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/)
- [Topological Sort (Wikipedia)](https://en.wikipedia.org/wiki/Topological_sorting)
- [DFS (Wikipedia)](https://en.wikipedia.org/wiki/Depth-first_search)
- [Kosaraju's algorithm (Wikipedia)](https://en.wikipedia.org/wiki/Kosaraju%27s_algorithm)
- [Strongly Connected Components (Programiz)](https://www.programiz.com/dsa/strongly-connected-components)