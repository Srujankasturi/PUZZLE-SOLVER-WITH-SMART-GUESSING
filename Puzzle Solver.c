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

int moves[9][4] = {
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
    char s[10];
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
           s[0], s[1], s[2],
           s[3], s[4], s[5],
           s[6], s[7], s[8]);
}

void printPathAndBoards(int idx) {
    if (idx == -1) return;
    printPathAndBoards(parent[idx]);
    printBoard(stateList[idx]);
}

int main() {
    char start[20];
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
    strcpy(queue[0].s, start);
    queue[0].h = manhattan(start);
    queue[0].index = 0;

    strcpy(stateList[0], start);
    parent[0] = -1;
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