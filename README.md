# push_swap



---

# 📖 Table of Contents

- [Introduction](#introduction)
- [Project Objectives](#project-objectives)
- [Project Architecture](#project-architecture)
- [Program Workflow](#program-workflow)
- [Data Structures](#data-structures)
- [Parsing System](#parsing-system)
- [Rank Compression](#rank-compression)
- [Sorting Algorithms](#sorting-algorithms)
  - Simple Strategy
  - Medium Strategy
  - Complex Strategy (Binary Radix Sort)
  - Adaptive Strategy
- [Benchmark Mode](#benchmark-mode)
- [Complexity Analysis](#complexity-analysis)
- [Memory Management](#memory-management)
- [Build & Usage](#build--usage)

---

# Introduction

`push_swap` is one of the most important algorithmic projects in the 42 curriculum.

The goal is to sort a sequence of integers using only two stacks and a limited set
of allowed operations while minimizing the total number of executed instructions.

Unlike classical sorting algorithms that can directly swap any elements, **push_swap**
forces the programmer to think differently.

Only the following operations are allowed:

```
sa
sb
ss

pa
pb

ra
rb
rr

rra
rrb
rrr
```

Because of these restrictions, choosing an efficient strategy becomes the most
important part of the project.

---

# Project Objectives

This implementation was designed with four different goals:

- Build a complete linked-list implementation.
- Validate every input safely.
- Implement several sorting strategies with different complexities.
- Provide benchmarking information to evaluate each strategy.

Unlike a classical implementation that contains only one algorithm, this project
contains four independent strategies.

| Strategy | Complexity |
|----------|------------|
| Simple | O(n²) |
| Medium | O(n√n) |
| Complex | O(n log n) |
| Adaptive | Dynamic |

The adaptive mode automatically selects the most suitable strategy according to
the measured disorder of the input.

---

# Project Architecture

```
                User Input
                     │
                     ▼
              Argument Parsing
                     │
                     ▼
          Validation & Error Check
                     │
                     ▼
          Linked List Construction
                     │
                     ▼
             Rank Compression
                     │
                     ▼
          Strategy Selection
                     │
      ┌──────────────┼──────────────┐
      │              │              │
      ▼              ▼              ▼
  Simple         Medium         Complex
      │              │              │
      └──────────────┼──────────────┘
                     ▼
              Sorted Stack
                     │
                     ▼
             Benchmark Output
```

---


# Program Workflow


The execution starts inside **main()**.

The program follows these steps:

1. Read command line arguments.
2. Detect optional flags (`--simple`, `--medium`, `--complex`, `--adaptive`, `--bench`).
3. Validate every integer.
4. Reject duplicated values.
5. Build stack **A** using a linked list.
6. Compress values into indexes.
7. Execute the selected sorting strategy.
8. Print benchmark information (if enabled).
9. Free every allocated node before exiting.

This modular workflow keeps every responsibility isolated inside its own source
file, making the project easier to understand and maintain.

---

# Source Files

| File | Responsibility |
|------|----------------|
| `main.c` | Entry point and strategy selection |
| `parsing.c` | Input validation and parsing |
| `list.c` | Linked list creation and management |
| `sorting.c` | All sorting algorithms |
| `opiratoin.c` | Allowed push_swap operations |
| `utils.c` | Helper functions |
| `bench.c` | Benchmark output |
| `push_swap.h` | Structures and function prototypes |

---

# Data Structures

The entire project relies on two custom structures.

These structures are responsible for representing both the stacks and the
benchmark system.

---

## t_stack

```c
typedef struct s_stack
{
    int             value;
    int             index;
    struct s_stack *next;
} t_stack;
```

Each node represents one integer inside a stack.

### Members

| Member | Description |
|---------|-------------|
| value | Original integer entered by the user |
| index | Compressed rank used by the sorting algorithms |
| next | Pointer to the next node |

The stack is implemented as a **singly linked list**.

Unlike arrays, linked lists allow efficient push and pop operations without
moving every element in memory.

Example:

```
Top
 │
 ▼

+-------+
| value |
| index |
+-------+
    │
    ▼
+-------+
| value |
| index |
+-------+
    │
    ▼
+-------+
| value |
| index |
+-------+
```

The first node always represents the top of the stack.

---

## Why store both value and index?

Sorting directly using integer values is possible.

However, Binary Radix Sort works much better on small consecutive integers.

Instead of sorting

```
-100
2500
7
999999
```

the project first converts them into

```
0
2
1
3
```

These values are called **Ranks** (Indexes).

This process dramatically simplifies the Radix Sort implementation.

---

## t_bench

```c
typedef struct s_bench
{
    int     bench;
    double  disorder;

    char    *strategy;
    char    *complexity;

    int ops;

    int sa;
    int sb;
    int ss;

    int pa;
    int pb;

    int ra;
    int rb;
    int rr;

    int rra;
    int rrb;
    int rrr;

} t_bench;
```

This structure stores every statistic generated while the program is running.

It is only used for **Benchmark Mode**.

---

### Members

| Variable | Description |
|----------|-------------|
| bench | Indicates whether `--bench` is enabled |
| disorder | Measured disorder percentage |
| strategy | Selected sorting strategy |
| complexity | Expected complexity of the chosen algorithm |
| ops | Total executed operations |

The remaining integers count every operation individually.

For example

```
bench.sa = 15
```

means the program executed **15 sa operations**.

At the end of the execution, these counters are printed to **stderr** without
affecting the normal output of push_swap.

---

# Parsing System

Input parsing is one of the most important parts of the project.

A sorting algorithm is useless if invalid data reaches it.

Before creating the stack, every argument is carefully validated.

The parser verifies:

- Invalid characters
- Empty strings
- Integer overflow
- Duplicate values
- Strategy flags
- Benchmark flag

Only after every verification succeeds is the stack created.

The parsing module guarantees that every node inside the linked list contains a
valid integer.

If any error is detected, the program immediately stops and prints

```
Error
```

without performing any sorting.

---

# Parsing Workflow

```
Command Line Arguments
          │
          ▼
 Check Strategy Flags
          │
          ▼
 Validate Numbers
          │
          ▼
 Overflow Check
          │
          ▼
 Duplicate Check
          │
          ▼
 Create Linked List
          │
          ▼
 Return Stack A
```

This separation keeps the rest of the project independent from input handling.

Once the parsing stage finishes successfully, every other module can safely
assume that the data is correct.

---

# Linked List Management

The entire project is built around a singly linked list.

Instead of storing numbers inside an array, every value is stored inside a node.

This design makes stack operations extremely efficient.

Only pointers are modified.

No array elements ever need to be shifted.

---

## Creating Nodes

Every integer entered by the user is converted into one node.

Each node stores

- the original value
- its compressed index
- a pointer to the next node

After creation, the node is inserted at the end of stack A.

---

## Stack Size

Several algorithms need to know how many elements remain inside a stack.

The helper function

```c
size_stack()
```

iterates through the linked list until the end and returns the total number of
nodes.

This function is heavily used by

- Simple Sort
- Medium Sort
- Radix Sort
- Rotation helpers

---

## Finding Positions

The function

```c
find_position()
```

returns the position of an index inside a stack.

Example

```
Top

5

2

8

1

```

Searching for

```
8
```

returns

```
2
```

because it is the third node (starting from zero).

Knowing the position allows the program to rotate using the shortest path.

---

## Finding Minimum

The helper

```c
find_min()
```

searches the linked list and returns the smallest compressed index.

This function is mainly used by the Simple Strategy.

---

## Finding Maximum

The function

```c
find_max()
```

returns the greatest compressed index.

It is mainly used during Medium Sort while rebuilding stack A from stack B.

---

# Rank Compression

One of the most important optimizations inside the project is **Rank Compression**.

Sorting algorithms do not work directly with integer values.

Instead, every number receives a unique rank.

Example

Original values

```
42

-5

800

13
```

Sorted values

```
-5
13
42
800
```

Compressed indexes become

```
2
0
3
1
```

Now every value belongs to the interval

```
0 ... n-1
```

This transformation greatly simplifies Binary Radix Sort.

It also guarantees that every index is unique.

---

## Why Compress Values?

Without compression, Radix Sort would have to process extremely large integers.

Example

```
999999999

-2147483648

123456789
```

After compression

```
2

0

1
```

The sorting algorithm becomes faster and easier to implement.

---

# Rotation Helpers

Instead of blindly rotating the stack in one direction, this project always
tries to minimize the number of operations.

The helper

```c
move_node_to_top_a()
```

works as follows.

1. Find the position of the desired node.
2. Compute the stack size.
3. Compare the position with the middle of the stack.

If the node is closer to the top

```
ra
```

is repeatedly executed.

Otherwise

```
rra
```

is used.

Pseudo algorithm

```
position = find_position()

if position > size / 2

        use reverse rotations

else

        use forward rotations
```

The exact same idea is used for

```c
move_node_to_top_b()
```

while rebuilding stack A during the Medium Strategy.

Choosing the shortest direction significantly reduces the total number of
operations.

---

# Stack Operations

The 42 subject allows only eleven operations.

Instead of implementing each operation independently, this project separates the
logic into two layers.

The first layer contains the real algorithms.

The second layer prints the instruction and updates the benchmark counters.

This avoids duplicating code.

---

# Internal Operations

The following helper functions perform the real modifications on the linked
lists.

```c
swap()
```

Swaps the first two nodes of a stack.

Before

```
Top

5
3
8
```

After

```
Top

3
5
8
```

---

```c
push()
```

Moves the first node from one stack to another.

Before

```
Stack A

5
3
8

Stack B

7
9
```

After

```
Stack A

3
8

Stack B

5
7
9
```

Only pointers are modified.

No memory allocation occurs.

---

```c
rotate()
```

Moves the first node to the end of the stack.

Before

```
1
2
3
4
```

After

```
2
3
4
1
```

---

```c
reverse_rotate()
```

Moves the last node to the beginning.

Before

```
1
2
3
4
```

After

```
4
1
2
3
```

---

# Public Operations

The functions

```
sa()
sb()
ss()

pa()
pb()

ra()
rb()
rr()

rra()
rrb()
rrr()
```

are wrappers around the internal operations.

Each wrapper performs three tasks.

1. Execute the linked-list operation.
2. Print the instruction.
3. Update benchmark statistics.

Example

```c
ra()
```

internally does

```
rotate(stack);

write(1,"ra\\n",3);

bench->ra++;

bench->ops++;
```

Because of this design, every algorithm automatically generates both the
required output and the benchmark information.

---

# Simple Strategy

Expected Complexity

```
O(n²)
```

The Simple Strategy is based on repeatedly extracting the smallest value.

Algorithm

```
while stack A is not empty

    locate minimum

    move minimum to top

    push to stack B

push everything back to A
```

---

## Example

Initial stack

```
5

1

4

2

3
```

Minimum

```
1
```

Rotate

```
1

4

2

3

5
```

Push

```
A

4
2
3
5

B

1
```

Repeat

Eventually

```
A

empty

B

5
4
3
2
1
```

Then

```
pa

pa

pa

pa

pa
```

Result

```
1

2

3

4

5
```

---

## Advantages

Very easy to understand.

Works correctly for every input.

---

## Disadvantages

Searching for the minimum requires scanning the entire stack.

This happens repeatedly.

Overall complexity becomes

```
O(n²)
```

For large inputs, the number of rotations grows significantly.

This is why the project also includes more advanced strategies.

---

# Medium Strategy

Expected Complexity

```
O(n√n)
```

The Medium Strategy is based on the **Chunk Algorithm**.

Instead of sorting one value at a time, the algorithm divides the data into
small groups called **Chunks**.

Each chunk contains consecutive indexes.

Example

```
100 numbers

Chunk Size = 20

Chunk 1

0 → 19

Chunk 2

20 → 39

Chunk 3

40 → 59

Chunk 4

60 → 79

Chunk 5

80 → 99
```

The algorithm pushes one chunk after another into stack B.

---

## Phase 1

The first objective is moving every chunk into stack B.

Pseudo algorithm

```
while stack A is not empty

    if top belongs to current chunk

        pb

    else

        ra
```

Once every value inside the current chunk has been pushed, the algorithm starts
processing the next chunk.

Eventually

```
Stack A

empty

Stack B

contains every element
```

---

## Phase 2

The second phase rebuilds stack A.

Instead of pushing elements randomly, the algorithm always searches for the
largest index.

```
find maximum

move it to the top

pa
```

Repeat until stack B becomes empty.

Because the largest value is always pushed first, stack A is rebuilt in sorted
order.

---

## Advantages

Compared to the Simple Strategy

- Fewer rotations
- Better scalability
- Much smaller operation count

The Chunk Algorithm performs significantly better on medium-sized inputs.

---

# Complex Strategy

Expected Complexity

```
O(n log n)
```

The Complex Strategy uses **Binary Radix Sort**.

Before executing the algorithm, every value has already been compressed into
indexes.

Example

```
Original

42

7

100

13
```

Compressed

```
2

0

3

1
```

The algorithm processes one binary digit at a time.

---

## Binary Representation

Example

```
0

000

1

001

2

010

3

011

4

100
```

Each iteration processes one bit.

---

## One Iteration

Suppose

```
Bit = 0
```

For every element

```
if bit == 0

        pb

else

        ra
```

After every element has been processed

```
while B is not empty

        pa
```

The algorithm then continues with

```
Bit 1

Bit 2

Bit 3

...
```

until every significant bit has been processed.

---

## Why Binary Radix?

Unlike comparison-based sorting algorithms, Binary Radix Sort works directly on
bits.

Each pass partitions the data according to one binary digit.

Eventually every index reaches its correct position.

---

## Advantages

Very stable.

Very predictable.

Excellent performance for large datasets.

Operation count remains competitive even for 500 numbers.

---

# Adaptive Strategy

Expected Complexity

Depends on the measured disorder.

Unlike the previous strategies, Adaptive Mode does not implement a new sorting
algorithm.

Instead, it measures the input and automatically selects the most appropriate
existing strategy.

---

## Measuring Disorder

The function

```c
compute_disorder()
```

computes the percentage of inversions.

An inversion is any pair

```
a

b
```

such that

```
a > b
```

Example

```
3

1

2
```

Inversions

```
3 > 1

3 > 2
```

Two inversions exist.

The function counts every inversion and divides it by the total number of
possible pairs.

The result is a value between

```
0

and

1
```

Example

```
0.46
```

means

```
46%
```

of all pairs are inverted.

---

## Strategy Selection

```
Disorder < 0.20

        Simple Strategy

0.20 ≤ Disorder < 0.50

        Medium Strategy

Disorder ≥ 0.50

        Complex Strategy
```

This allows the program to adapt itself automatically to different kinds of
inputs.

Instead of always executing the same algorithm, the project chooses the one that
best matches the current data.

---

# Benchmark Mode

The project also provides a Benchmark Mode.

```
--bench
```

does not modify the sorting process.

Instead, it collects statistics during execution.

The benchmark reports

- Disorder percentage
- Selected strategy
- Expected complexity
- Total operations
- Individual operation counts

Example

```
[bench] disorder: 45.76%

[bench] strategy: Adaptive

[bench] complexity: O(n√n)

[bench] total_ops: 768

sa : 0

pb : 100

ra : 389

...
```

Benchmark information is written to **stderr**.

The normal instructions remain on **stdout**.

Because of this separation, the output can still be piped directly into the
checker without any modification.

---

# Complexity Analysis

The project contains four different sorting strategies.

Each strategy targets a different level of disorder.

| Strategy | Complexity | Best Use Case |
|----------|------------|---------------|
| Simple | O(n²) | Nearly sorted or very small inputs |
| Medium | O(n√n) | Moderately disordered inputs |
| Complex | O(n log n) | Large or highly disordered inputs |
| Adaptive | Dynamic | Automatically selects the best strategy |

The Adaptive Strategy measures the disorder percentage and chooses the most
appropriate algorithm automatically.

---

# Memory Management

Dynamic memory allocation is limited to the linked list.

Each integer entered by the user becomes one allocated node.

The project never allocates unnecessary buffers or arrays.

At program termination every allocated node is released using

```c
free_stack()
```

ensuring that no memory leaks remain.

The project has been designed to pass memory checking tools such as

```
valgrind
```

without leaks.

---

# Error Handling

The parser performs several safety checks before sorting begins.

The following errors are detected.

- Invalid characters
- Empty arguments
- Integer overflow
- Duplicate numbers
- Invalid strategy flags

Whenever an error occurs, the program immediately prints

```
Error
```

and exits without executing any sorting operation.

This guarantees that every algorithm always receives valid data.

---

# Build

Compile the project using

```bash
make
```

Remove object files

```bash
make clean
```

Remove every generated file

```bash
make fclean
```

Rebuild everything

```bash
make re
```

---

# Usage

Default (Adaptive Mode)

```bash
./push_swap 3 2 1
```

Force the Simple Strategy

```bash
./push_swap --simple 3 2 1
```

Force the Medium Strategy

```bash
./push_swap --medium 3 2 1
```

Force the Complex Strategy

```bash
./push_swap --complex 3 2 1
```

Adaptive Strategy

```bash
./push_swap --adaptive 3 2 1
```

Benchmark Mode

```bash
./push_swap --bench 3 2 1
```

Combining both

```bash
./push_swap --medium --bench 3 2 1
```

---

# Project Design

Instead of implementing one universal sorting algorithm, this project separates
the solution into multiple independent strategies.

Each algorithm was chosen for a specific level of input disorder.

This design provides several advantages.

- Cleaner code organization.
- Easier maintenance.
- Better benchmarking.
- Better understanding of algorithmic complexity.
- Automatic optimization through Adaptive Mode.

The Benchmark System also makes it possible to compare every strategy using the
same dataset.

---

# Key Features

✔ Linked List implementation

✔ Complete input validation

✔ Rank Compression

✔ Four independent sorting strategies

✔ Adaptive algorithm selection

✔ Binary Radix Sort

✔ Chunk-based sorting

✔ Benchmark mode

✔ Operation statistics

✔ Memory leak free

---

# Example

Input

```bash
./push_swap --adaptive --bench 5 2 8 1 4
```

Output to stdout

```
pb
ra
pb
...
```

Output to stderr

```
[bench] disorder: 45.76%

[bench] strategy: Adaptive

[bench] complexity: O(n√n)

[bench] total_ops: 768

sa : 0
sb : 0
ss : 0

pa : 100
pb : 100

ra : 389
rb : 88
rr : 0

rra : 0
rrb : 91
rrr : 0
```

Because benchmark information is printed to **stderr**, it never interferes with
the generated instructions.

This allows the output to be piped directly into the official checker.

Example

```bash
./push_swap --bench $(cat args.txt) 2>bench.txt | ./checker_linux $(cat args.txt)
```

The checker receives only the sorting instructions, while the benchmark is saved
inside `bench.txt`.

---

# Conclusion

This project demonstrates several fundamental concepts of algorithm design.

During its implementation the following topics were explored.

- Linked lists
- Pointer manipulation
- Sorting algorithms
- Complexity analysis
- Binary representations
- Rank compression
- Adaptive algorithm selection
- Benchmarking
- Memory management

Rather than relying on a single sorting technique, this implementation combines
multiple algorithms and dynamically selects the most appropriate one according
to the measured disorder of the input.

The result is a flexible, modular, and efficient Push_swap implementation that
can adapt to different datasets while respecting the constraints imposed by the
42 subject.