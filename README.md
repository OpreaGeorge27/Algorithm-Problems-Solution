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

## LLM Usage

I tried to use any form of help from tools like ChatGPT as little as possible, but I did use it to create the README by presenting the code and requirements and telling it something about the solution method.