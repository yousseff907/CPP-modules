# CPP Module 09

*This project has been created as part of the 42 curriculum by yitani.*

## Description

CPP Module 09 is the final module in the 42 C++ curriculum, focusing on advanced container usage and algorithmic complexity. The module consists of three exercises that demonstrate practical applications of the Standard Template Library (STL) containers while adhering to C++98 standards.

**Project Goals:**
- Master STL container operations and performance characteristics
- Compare container performance in real-world scenarios
- Handle data parsing, validation, and error management

**Exercises:**
1. **Bitcoin Exchange (ex00):** Currency conversion using historical exchange rate data
2. **Reverse Polish Notation Calculator (ex01):** Mathematical expression evaluation using stack operations
3. **PmergeMe (ex02):** Implementation of the Ford-Johnson merge-insert sort algorithm with container performance comparison

---

## Instructions

### Compilation

Each exercise has its own Makefile. Navigate to the exercise directory and compile:
```bash
# For Exercise 00
cd ex00
make

# For Exercise 01
cd ex01
make

# For Exercise 02
cd ex02
make
```

**Compiler flags:** `-Wall -Wextra -Werror -std=c++98`

### Execution

#### Exercise 00: Bitcoin Exchange
```bash
./btc [input_file]
```

**Input file format:**
```
date | value
2011-01-03 | 3
2011-01-03 | 2
2011-01-09 | 1
2012-01-11 | -1
2001-42-42
2012-01-11 | 1
2012-01-11 | 2147483648
```

**Output:**
```
2011-01-03 => 3 = 0.9
2011-01-03 => 2 = 0.6
2011-01-09 => 1 = 0.32
Error: not a positive number.
Error: bad input => 2001-42-42
2012-01-11 => 1 = 7.1
Error: too large a number.
```

**Features:**
- CSV database parsing (`data.csv`)
- Date validation (YYYY-MM-DD format, leap years, valid ranges)
- Value validation (0 < value ≤ 1000)
- Historical exchange rate lookup using `std::map`

---

#### Exercise 01: Reverse Polish Notation (RPN)
```bash
./RPN "expression"
```

**Examples:**
```bash
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
42

./RPN "7 7 * 7 -"
42

./RPN "1 2 * 2 / 2 * 2 4 - +"
0

./RPN "(1 + 1)"
Error
```

**Features:**
- Stack-based expression evaluation
- Support for: `+`, `-`, `*`, `/`
- Single-digit operands (0-9)
- Comprehensive error handling (invalid tokens, insufficient operands, division by zero)

---

#### Exercise 02: PmergeMe (Ford-Johnson Sort)
```bash
./PmergeMe [positive integers...]
```

**Examples:**
```bash
./PmergeMe 3 5 9 7 4
Before:  3 5 9 7 4
After:  3 4 5 7 9
Time to process a range of 5 elements with std::vector<int> : 0.00031 μs
Time to process a range of 5 elements with std::deque<int> : 0.00014 μs

./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
# Sorts 3000 random numbers and displays timing comparison
```

**Algorithm Details:**
- **Ford-Johnson merge-insert sort** (optimal comparison-based sorting)
- Achieves exactly **66 comparisons for 21 numbers** (theoretical minimum)
- Implements both `std::vector` and `std::deque` versions
- Performance timing in microseconds

**Key Components:**
1. Pairwise comparison and main chain extraction
2. Recursive sorting of larger elements
3. Jacobsthal sequence generation for optimal insertion order
4. Binary insertion with growing search limit optimization

---

## Resources

### Classic References

**C++98 Standard Library:**
- [cplusplus.com STL Containers](https://cplusplus.com/reference/stl/)
- [C++ Reference](https://en.cppreference.com/w/)
- STL documentation for `std::map`, `std::vector`, `std::deque`, `std::stack`

**Algorithms:**
- Ford, L. R. and Johnson, S. M. (1959). "A Tournament Problem". *American Mathematical Monthly* 66 (5): 387–389
- [Ford-Johnson Algorithm Explanation](https://en.wikipedia.org/wiki/Merge-insertion_sort)
- [Binary Search Complexity](https://en.wikipedia.org/wiki/Binary_search_algorithm)

**Reverse Polish Notation:**
- [RPN Calculator](https://en.wikipedia.org/wiki/Reverse_Polish_notation)
- Stack-based evaluation algorithms

**Data Structures:**
- [std::map internals](https://en.cppreference.com/w/cpp/container/map) (Red-Black Tree)
- [Container performance comparison](https://en.cppreference.com/w/cpp/container)

### AI Usage

**AI was used for the following tasks:**

1. **Algorithm Understanding (ex02):**
   - Explaining Ford-Johnson merge-insert sort mathematical foundations
   - Understanding Jacobsthal sequence properties and generation

2. **Edge Case Identification:**
   - RPN stack underflow/overflow scenarios

3. **Debugging Assistance:**
   - Resolving sorting inconsistencies in ex02

4. **Documentation:**
   - Explaining complex algorithmic concepts
   - Providing step-by-step algorithm walkthroughs

**AI was NOT used for:**
- Writing the core algorithm implementations
- Making architectural decisions
- Direct code generation without understanding
---