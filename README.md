# PUZZLE SOLVER WITH SMART GUESSING

Project submitted for the partial fulfillment of the requirements for the course  
**CSE 204 – DESIGN AND ANALYSIS OF ALGORITHMS**  
Offered by the  
Department of Computer Science and Engineering  
School of Engineering and Sciences  

Submitted by   
- AP24110010776 – K. Srujan  

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
