# push_swap

## 📌 Description

**push_swap** is a 42/1337 algorithmic project. The goal is to sort a stack of integers using a limited set of operations, while minimizing the number of moves.

You are given stack **A** with random integers and an empty stack **B**. You must sort stack **A** in ascending order using only the allowed operations.

---

## 🎯 Objectives

* Sort integers using **two stacks (A and B)**
* Use only the allowed instructions
* Optimize the number of operations
* Handle errors correctly (duplicates, non-numeric values, overflow)

---

## 🔧 Allowed Operations

| Operation | Description                                 |
| --------- | ------------------------------------------- |
| `sa`      | Swap the first two elements of stack A      |
| `sb`      | Swap the first two elements of stack B      |
| `ss`      | `sa` and `sb` at the same time              |
| `pa`      | Push the top element from B to A            |
| `pb`      | Push the top element from A to B            |
| `ra`      | Rotate stack A (first element becomes last) |
| `rb`      | Rotate stack B                              |
| `rr`      | `ra` and `rb` at the same time              |
| `rra`     | Reverse rotate stack A                      |
| `rrb`     | Reverse rotate stack B                      |
| `rrr`     | `rra` and `rrb` at the same time            |

---

## 🧠 Algorithm

This project uses a **chunk-based algorithm**:

1. Normalize values by assigning indexes
2. Divide the stack into chunks
3. Push elements from A to B chunk by chunk
4. Push elements back from B to A in sorted order

Special cases are handled separately:

* 3 elements
* 5 elements

---

## 🛠️ Compilation

```bash
make
```

This will generate the executable `push_swap`.

Other rules:

```bash
make clean
make fclean
make re
```

The Makefile does **not relink** if nothing has changed.

---

## ▶️ Usage

```bash
./push_swap 3 2 1
```

Output:

```
sa
rra
```

You can test the number of operations:

```bash
./push_swap 3 2 1 | wc -l
```

---

## ✅ Error Handling

The program prints `Error` and exits if:

* Arguments are not integers
* Numbers are duplicated
* Integer overflow occurs
* Empty or invalid input

Example:

```bash
./push_swap "10 20" " "
Error
```

---

## 📂 Project Structure

```
push_swap/
│── push_swap.c
│── push.c
│── swap.c
│── rotate.c
│── reverse_rotate.c
│── sort_chunks.c
│── linked_list.c
│── parse_input.c
│── split.c
│── filling_stack.c
│── helper.c
│── Makefile
│── README.md
```

---

## 🧪 Checker (Optional)

You can use the checker to verify correctness:

```bash
ARG="$(shuf -i 1-100 -n 100 | tr '\n' ' ')";
./push_swap $ARG | ./checker_linux $ARG
```

If sorted correctly, output will be:

```
OK
```

---

## 📚 Skills Learned

* Algorithms & optimization
* Linked lists
* Stack manipulation
* Error handling in C
* Memory management

---

## 👨‍💻 Author

**Amine** – 1337 Student

---

## ⭐ Notes

* This project follows **1337 / 42 Norm**
* No memory leaks
* Optimized for performance

---

Good luck 🚀
