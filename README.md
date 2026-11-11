*This project has been created as part of the 42 curriculum by **yaalmoui, jcole***

# push_swap

A **42 Prague** C project that sorts integers using two stacks and a restricted set of stack operations. This implementation provides four selectable sorting strategies, a disorder-based adaptive mode, and an optional benchmark report.

## Description

`push_swap` receives a sequence of integers in **stack A** and prints the operations needed to arrange them in ascending order. **Stack B** starts empty and is used as temporary storage. The program prints one operation per line to standard output; when the input is already sorted, it prints no sorting operations.

The stacks are implemented as **doubly linked lists**, with `head` (top), `tail` (bottom), and `prev` / `next` pointers. This makes it possible to move nodes between stacks without copying their values or allocating new nodes for each operation.

## Build

Requirements: a C compiler (`gcc`), `make`, and a Unix-like shell.

```bash
make        # Build ./push_swap and the bundled ft_printf library
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Rebuild from scratch
```

The Makefile compiles with `-Wall -Wextra -Werror`.

## Usage

```bash
./push_swap [--simple|--medium|--complex|--adaptive] [--bench] <integers...>
```

Examples:

```bash
./push_swap 4 2 5 1 3
./push_swap "4 2 5 1 3"
./push_swap --simple 4 2 5 1 3
./push_swap --medium 4 2 5 1 3
./push_swap --complex 4 2 5 1 3
./push_swap --adaptive --bench 4 2 5 1 3
```

- **Default strategy:** `--adaptive`.
- **Strategy flags:** choose at most one of `--simple`, `--medium`, `--complex`, or `--adaptive`.
- **`--bench`:** optional; enables a benchmark report on standard error (`stderr`).
- **Input:** space-separated integers, including quoted groups of integers. Values must fit in a signed 32-bit `int`, and duplicates are rejected.
- **Invalid input:** prints `Error` to `stderr`.

Options are parsed before the number arguments.

## Sorting strategies

| Flag | Implementation | Approach |
| --- | --- | --- |
| `--simple` | `algorithms/simple.c` | Selection-sort-inspired minimum extraction: find the minimum, rotate it to the top, push to B, then restore the sorted values to A. |
| `--medium` | `algorithms/medium.c` | Chunk-based sorting: assign ranks, push rank ranges to B, then repeatedly retrieve the maximum. |
| `--complex` | `algorithms/complex.c` | Binary radix sorting on ranks, using `pb`, `ra`, and `pa` for successive bit positions. |
| `--adaptive` | `algorithms/sort_stack.c` | Selects a strategy based on the measured disorder of the original input. |

### Adaptive strategy

Before sorting, `compute_disorder()` measures the proportion of inverted pairs in the input:

\[
\text{disorder} = \frac{\#\{(i,j): i<j \text{ and } a_i>a_j\}}{n(n-1)/2}
\]

The result ranges from `0` (already sorted) to `1` (reverse sorted). The adaptive mode selects:

| Disorder | Algorithm |
| --- | --- |
| Below 20% | Simple |
| 20% to below 50% | Medium |
| 50% and above | Complex |

**Small-stack optimization:** inputs of two elements are handled directly; for three to five elements, the program reuses the small-input logic in `simple_sort()` regardless of the selected flag. This avoids unnecessary work for tiny stacks.

**Complexity note:** The strategies are designed around the project's simple / medium / complex algorithm families. The current rank-assignment implementation in `complex.c` uses nested comparisons, so its overall preprocessing cost is **O(n²)** even though the radix passes themselves are **O(n log n)**. The chunk strategy's full worst-case complexity should likewise not be inferred solely from its chunk size.

## Supported stack operations

| Operation | Effect |
| --- | --- |
| `sa`, `sb` | Swap the top two elements of A or B. |
| `ss` | Perform both swaps. |
| `pa` | Push the top element of B onto A. |
| `pb` | Push the top element of A onto B. |
| `ra`, `rb` | Rotate A or B upward (top moves to bottom). |
| `rr` | Rotate both stacks upward. |
| `rra`, `rrb` | Reverse-rotate A or B (bottom moves to top). |
| `rrr` | Reverse-rotate both stacks. |

### Example: pushing between doubly linked stacks

```text
Before pb:                 After pb:

Stack A    Stack B         Stack A    Stack B
   4          8               2          4
   2                          1          8
   1
```

`pb` transfers the existing top node from A to B. The implementation updates the affected `head`, `tail`, `prev`, and `next` links so each list remains valid.

## Benchmark mode

Add `--bench` to display diagnostics on **stderr**, keeping stdout usable as a pure operation stream:

```bash
./push_swap --medium --bench 4 2 5 1 3
```

The report includes:

- Initial disorder percentage.
- Selected strategy label.
- Total number of operations.
- Counts for `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, and `rrr`.

To separate the operation stream from the benchmark:

```bash
./push_swap --adaptive --bench 4 2 5 1 3 > operations.txt 2> benchmark.txt
```

**Note:** The strategy label reflects the requested mode and its adaptive classification. For small stacks, the actual routine may be `simple_sort()` even if another mode was selected.

## Project structure

```text
push_swap/
├── main.c
├── push_swap.h
├── Makefile
├── algorithms/
│   ├── sort_stack.c
│   ├── simple.c
│   ├── medium.c
│   └── complex.c
├── benchmark/
│   ├── benchmark.c
│   └── benchmark_print.c
├── disorder/
│   └── disorder.c
├── operations/
│   ├── push_moves.c
│   ├── swap_moves.c
│   ├── rotate_moves.c
│   └── reverse_rotate_moves.c
├── parsing/
│   ├── parsing.c
│   ├── parsing_handle.c
│   └── helper_functions.c
├── stack/
│   ├── functions.c
│   └── stack_utils.c
└── ft_printf/                 # Bundled formatted-printing library / libft
```

## Instructions

Build the project and check a few representative cases:

```bash
make re

# Already sorted: no operations
./push_swap 1 2 3 4 5

# Three-element sorting
./push_swap 3 2 1

# Negative integers
./push_swap --adaptive -3 5 0 -10 2

# Duplicate: should print Error to stderr
./push_swap 1 2 2

# Non-numeric input: should print Error to stderr
./push_swap 1 hello 3
```

When a compatible 42 `checker_linux` is available, validate the emitted operations:

```bash
ARG="4 2 5 1 3"
./push_swap $ARG | ./checker_linux $ARG
```

The checker should print `OK` for a valid sorting sequence. For memory checking on Linux, you can also use Valgrind:

```bash
valgrind --leak-check=full --show-leak-kinds=all ./push_swap 4 2 5 1 3
```

## Resources

Selection Sort – GeeksforGeeks - https://www.geeksforgeeks.org/dsa/selection-sort-algorithm-2/

Radix Sort – GeeksforGeeks — https://www.geeksforgeeks.org/dsa/radix-sort/

## AI Assistance

Used as a learning assistant to discuss algorithms, review code, understand pointer manipulation, and debug implementation issues, and create some tests.
