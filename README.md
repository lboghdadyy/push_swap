# Push Swap

## Description
Push Swap is a sorting algorithm project from the 42 school that involves sorting a stack of integers using a limited set of operations. The goal is to sort the numbers in the fewest possible moves using two stacks: `stack A` and `stack B`.

## Allowed Operations
- `sa` : Swap the first two elements of `stack A`.
- `sb` : Swap the first two elements of `stack B`.
- `ss` : Swap the first two elements of both stacks.
- `pa` : Push the top element from `stack B` to `stack A`.
- `pb` : Push the top element from `stack A` to `stack B`.
- `ra` : Rotate `stack A` upwards (first element becomes last).
- `rb` : Rotate `stack B` upwards.
- `rr` : Rotate both stacks upwards.
- `rra` : Reverse rotate `stack A` (last element becomes first).
- `rrb` : Reverse rotate `stack B`.
- `rrr` : Reverse rotate both stacks.

## Turk Algorithm
The **Turk Algorithm** is an optimized approach to solve the Push Swap problem efficiently. It works as follows:

1. **Chunk Division**: The stack is divided into smaller chunks based on a median or percentile strategy.
2. **Pushing to Stack B**: Elements are pushed from `stack A` to `stack B` in an optimized order.
3. **Sorting Stack B**: Elements in `stack B` are sorted in a way that allows easy reinsertion into `stack A`.
4. **Pushing Back to Stack A**: Elements are reinserted into `stack A` while maintaining the sorted order.
5. **Final Adjustments**: Any remaining rotations or swaps are performed to finalize the sorting.

This method significantly reduces the number of operations compared to naive approaches.

## Compilation and Usage
To compile the project, use:
```bash
make
```
To execute the program:
```bash
./push_swap <list of numbers>
```
Example:
```bash
./push_swap 3 2 5 1 4
```

## Evaluation
Your solution will be tested against different input sizes:
- **3 Numbers**: Should be solved in at most 3 moves.
- **5 Numbers**: Should be solved in at most 12 moves.
- **100 Numbers**: Expected to be solved in ~700 moves or less.
- **500 Numbers**: Expected to be solved in ~5500 moves or less.
  
## Author
Soufiane Baghdadi

