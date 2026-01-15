# PUZZLE SOLVER WITH SMART GUESSING

Project submitted for the partial fulfillment of the requirements for the course  
**CSE 204 – DESIGN AND ANALYSIS OF ALGORITHMS**  
Offered by the  
Department of Computer Science and Engineering  
School of Engineering and Sciences  

Submitted by  
- AP24110010751 – G. Sravya  
- AP24110010759 – B. Nishwitha  
- AP24110010765 – T. Saranya  
- AP24110010776 – K. Srujan  
- AP24110010784 – K. Praneeth Kumar  

**NOVEMBER – 2025**

---

## Contents

| S. No | Topic | Page No |
|------:|-------|:-------:|
| 1 | Introduction | 1 |
| 2 | Background | 2–4 |
| 3 | Proposed Approach | 5–17 |
| 4 | Results and Discussion | 18–19 |
| 5 | Conclusion | 20 |
| 6 | References | 21 |

---

## 1. Introduction

### 2.1 Purpose of the Project

The purpose of this project is to design and implement an intelligent solver for the 8-Puzzle using the A* Search Algorithm using branch and bound, which guarantees the shortest solution path.

The algorithm uses a cost function and a heuristic to efficiently search through millions of possible puzzle configurations.

This project demonstrates how informed search strategies and heuristic functions can reduce computational effort and produce optimal solutions.

The solver uses Manhattan Distance as a heuristic to estimate the distance from the current puzzle state to the goal state, ensuring correctness and optimality.

The puzzle is an excellent model for real-world problems involving path finding, state-space searching, artificial intelligence, and optimization.

The project also highlights how different evaluation functions influence the efficiency of search algorithms.

### 2.1 Overview

This project implements a complete 8-Puzzle solving system:

- Represents puzzle states as a 3×3 grid
- Checks whether an input configuration is solvable
  - Uses A* branch and bound search with the cost function  
    \( f(n) = g(n) + h(n) \)  
    where  
    - \( g(n) \) is the cost or number of moves so far  
    - \( h(n) \) is the Manhattan distance heuristic
- Explores and expands puzzle states in an optimal order to reach the goal
- Generates and prints the series of intermediate puzzle states that lead to the final solution

---

## 2. Background

### 2.1 Why is it relevant?

The Sliding Puzzle is a widely studied problem in Artificial Intelligence, search algorithms, and heuristic design.

It represents a real-world challenge where the objective is to reach a desired state efficiently from a given initial configuration.

The puzzle models several practical domains such as:

- Path-finding in robotics
- Configuration space search
- Data organization and pattern recognition
- Constraint satisfaction problems
- Automatic planning and game solving

Finding an optimal solution becomes computationally expensive as the number of possible states increases.

The 8-Puzzle has \( 9! / 2 = 181,440 \) solvable configurations, which makes brute-force searching slow and inefficient.

Therefore, heuristic and intelligent search algorithms are used to reduce the search space and improve performance.

In this project, the A* algorithm is used because it guarantees finding the optimal solution when the heuristic is admissible.

The Manhattan Distance heuristic provides an accurate estimate of the remaining cost to reach the goal state.

### 2.2 Traditional Methods for Solving the Puzzle

Before analyzing the effectiveness of the A* approach, it is useful to understand the naive methods commonly used to solve the puzzle.

**Method 1: “Swap Random Pairs Many Times” (Naive Shuffle)**  
This approach generates all possible states from the initial configuration and continues until the goal is found.

**Why it fails:**
- It explores a very large search space
- No information is used to guide the path
- Exponential time complexity

**Conclusion:** Not suitable for optimal solution generation.

**Method 2: Breadth-First Search**  
This method explores nodes level by level.

**Limitations:**
- Consumes huge memory
- May explore many unnecessary states
- Inefficient for complex path

**Method 3: Depth-First Search**  
DFS tries to reach the goal by going deep into one branch.

**Disadvantages:**
- Solution may not be optimal
- Can get stuck in long or infinite branches
- Does not guarantee minimal moves

### 2.3 Need for Heuristic Search

To overcome the limitations of brute-force and uninformed search, heuristic search techniques are used.

Heuristics provide problem-specific knowledge and guide the direction of the search.

**Advantages:**
- Reduces the number of expanded nodes
- Avoids unnecessary branches
- Produces optimal solutions faster

A* uses the evaluation function:  
\( f(n) = g(n) + h(n) \)  
where \( h(n) \) is Manhattan Distance.

This heuristic calculates how far each tile is from its correct position in the final state.

This allows the A* algorithm to follow the most promising path and reach the solution efficiently.

---

## 3. Proposed Approach

The objective of this project is to solve the sliding puzzle efficiently using the A* search algorithm.

The proposed method improves upon conventional search strategies by using domain knowledge in the form of heuristics.

The heuristic enables the algorithm to make informed decisions about which state to explore next, ensuring both optimality and reduced search time.

To implement the algorithm, each board configuration is considered as a state in the state-space tree.

The root node represents the initial puzzle arrangement and the goal node represents the final configuration.

From each state, all possible valid moves are generated by sliding the blank tile (0) in one of the allowable directions.

The A* algorithm assigns a cost to each generated state based on the following function:  
\( f(n) = g(n) + h(n) \)

Where:
- \( g(n) \) is the cost from the start node to the current node (number of moves taken).
- \( h(n) \) is the Manhattan distance heuristic estimating the cost from the current node to the goal state.

To compute the heuristic value, the final arrangement of the puzzle is represented using fixed coordinates.

Each tile is mapped to its correct row and column in the goal state.

This coordinate system allows the algorithm to calculate how far every tile is from its target location.

The Manhattan distance heuristic uses these coordinates as follows:  
\( h = \Sigma |current\_row - goal\_row| + |current\_col - goal\_col| \)

**Key points of the approach:**
1. Each move generates a new child node representing a new puzzle state.
2. The Manhattan distance is calculated for each state to estimate the remaining steps.
3. The algorithm always selects the next state with the minimum \( f(n) \) value from a priority queue.
4. States already visited are ignored to prevent unnecessary exploration.
5. Once the goal configuration is reached, the path of moves is reconstructed and displayed.

### 3.1 System Design

| Component | Technical Description |
|----------|------------------------|
| Input | Initial State String (Character Array) |
| Solver | A* Search Algorithm (Linear Priority Search) |
| Storage | Visited Array (Linear Search) & State History Arrays |
| Output | Backtracked Path Reconstruction |

### 3.2 Algorithm

1. Start with the initial configuration.
2. Check if the puzzle is solvable using the inversion count method.
3. Insert the initial state into the priority queue.
4. For the current state, compute:
   - \( g(n) \) = number of moves so far
   - \( h(n) \) = Manhattan distance
   - \( f(n) = g(n) + h(n) \)
5. Remove the state with the lowest \( f(n) \) from the priority queue.
6. If the current state matches the goal configuration, stop and display the solution.
7. Otherwise, generate all possible child states by sliding the blank tile (0) up, down, left, or right.
8. For each child:
   - Calculate the new \( g(n) \) and \( h(n) \) values
   - Compute \( f(n) \)
   - Push it into the priority queue
9. Mark the current state as visited to avoid repetition.
10. Repeat steps 5–9 until the goal state is reached or no more nodes remain.

### 3.3 Flowchart

(Flowchart section referenced in the report.)

### 3.4 C Code

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 9
#define MAX 200000
#define GOAL "123456780"

char visited[MAX][SIZE+1];
int parent[MAX];
char stateList[MAX][SIZE+1];
int visitedCount = 0, totalStates = 0;

int moves = {
    {1,3,-1,-1}, {0,2,4,-1}, {1,5,-1,-1},
    {0,4,6,-1}, {1,3,5,7}, {2,4,8,-1},
    {3,7,-1,-1}, {4,6,8,-1}, {5,7,-1,-1}
};

int solvable(char *s) {
    int inv = 0;
    for (int i = 0; i < 9; i++)
        for (int j = i + 1; j < 9; j++)
            if (s[i] != '0' && s[j] != '0' && s[i] > s[j])
                inv++;
    return inv % 2 == 0;
}

int manhattan(char *s) {
    int d = 0;
    for (int i = 0; i < 9; i++) {
        if (s[i] != '0') {
            int v = s[i] - '1';
            d += abs(i / 3 - v / 3) + abs(i % 3 - v % 3);
        }
    }
    return d;
}

int seen(char *s) {
    for (int i = 0; i < visitedCount; i++)
        if (strcmp(visited[i], s) == 0) return 1;
    return 0;
}

void storeVisited(char *s) {
    if (visitedCount < MAX)
        strcpy(visited[visitedCount++], s);
}

void swap(char *s, int a, int b) {
    char t = s[a];
    s[a] = s[b];
    s[b] = t;
}

struct Node {
    char s;
    int g, h, index;
};

struct Node queue[MAX];
int qs = 0;

void push(struct Node n) {
    if (qs < MAX) queue[qs++] = n;
}

struct Node popBest() {
    int best = 0;
    for (int i = 1; i < qs; i++)
        if (queue[i].g + queue[i].h < queue[best].g + queue[best].h)
            best = i;
    struct Node r = queue[best];
    queue[best] = queue[--qs];
    return r;
}

void printBoard(char *s) {
    printf("%c %c %c\n%c %c %c\n%c %c %c\n\n",
           s, s, s,[1]
           s, s, s,
           s, s, s);
}

void printPathAndBoards(int idx) {
    if (idx == -1) return;
    printPathAndBoards(parent[idx]);
    printBoard(stateList[idx]);
}

int main() {
    char start;
    printf("Enter puzzle (9 digits, 0 for blank): ");
    scanf("%19s", start);

    if (strlen(start) != 9) {
        printf("Error: please enter exactly 9 characters.\n");
        return 0;
    }

    if (strchr(start, '0') == NULL) {
        printf("Error: input must contain a 0 for the blank.\n");
        return 0;
    }

    if (!solvable(start)) {
        printf("This puzzle is unsolvable.\n");
        return 0;
    }

    printf("Thinking...\n\n");

    push((struct Node){"", 0, 0, 0});
    strcpy(queue.s, start);
    queue.h = manhattan(start);
    queue.index = 0;

    strcpy(stateList, start);
    parent = -1;
    totalStates = 1;

    while (qs) {
        struct Node cur = popBest();

        if (strcmp(cur.s, GOAL) == 0) {
            printf("Solved in %d moves\n\n", cur.g);
            printPathAndBoards(cur.index);
            return 0;
        }

        if (seen(cur.s)) continue;
        storeVisited(cur.s);

        int zero = strchr(cur.s, '0') - cur.s;

        for (int i = 0; moves[zero][i] != -1; i++) {
            int mv = moves[zero][i];
            struct Node next = cur;
            swap(next.s, zero, mv);

            if (seen(next.s)) continue;

            next.g++;
            next.h = manhattan(next.s);
            next.index = totalStates;

            if (totalStates < MAX) {
                strcpy(stateList[totalStates], next.s);
                parent[totalStates] = cur.index;
                totalStates++;
                push(next);
            }
        }
    }

    printf("No solution found.\n");
    return 0;
}
