#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int x, y;
} State;

/* ---------- BFS IMPLEMENTATION ---------- */

State queue[MAX];
int front = 0, rear = 0;
int visited_bfs[5][5];

void enqueue(State s) {
    queue[rear++] = s;
}

State dequeue() {
    return queue[front++];
}

void bfs(int jug1, int jug2, int target) {

    State start = {0,0};
    enqueue(start);

    printf("\nBFS Traversal:\n");

    while(front < rear) {

        State curr = dequeue();

        if(visited_bfs[curr.x][curr.y])
            continue;

        visited_bfs[curr.x][curr.y] = 1;

        printf("Visited: (%d , %d)\n", curr.x, curr.y);

        if(curr.x == target || curr.y == target) {
            printf("Goal reached using BFS\n");
            return;
        }

        State next;

        next = (State){jug1, curr.y}; enqueue(next);
        next = (State){curr.x, jug2}; enqueue(next);
        next = (State){0, curr.y}; enqueue(next);
        next = (State){curr.x, 0}; enqueue(next);

        int pour;

        pour = (curr.x + curr.y > jug2) ? jug2 - curr.y : curr.x;
        next = (State){curr.x - pour, curr.y + pour};
        enqueue(next);

        pour = (curr.x + curr.y > jug1) ? jug1 - curr.x : curr.y;
        next = (State){curr.x + pour, curr.y - pour};
        enqueue(next);
    }
}


/* ---------- DFS IMPLEMENTATION ---------- */

int visited_dfs[5][5];

void dfs(int x, int y, int jug1, int jug2, int target) {

    if(x > jug1 || y > jug2 || visited_dfs[x][y])
        return;

    printf("Visited: (%d , %d)\n", x, y);

    if(x == target || y == target) {
        printf("Goal reached using DFS\n");
        return;
    }

    visited_dfs[x][y] = 1;

    dfs(jug1, y, jug1, jug2, target);
    dfs(x, jug2, jug1, jug2, target);
    dfs(0, y, jug1, jug2, target);
    dfs(x, 0, jug1, jug2, target);

    int pour;

    pour = (x + y > jug2) ? jug2 - y : x;
    dfs(x - pour, y + pour, jug1, jug2, target);

    pour = (x + y > jug1) ? jug1 - x : y;
    dfs(x + pour, y - pour, jug1, jug2, target);
}


/* ---------- MAIN FUNCTION ---------- */

int main() {

    int jug1 = 4;
    int jug2 = 3;
    int target = 2;

    bfs(jug1, jug2, target);

    printf("\nDFS Traversal:\n");

    dfs(0,0,jug1,jug2,target);

    return 0;
}
