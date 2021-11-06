#include <stdio.h>

/* 求田字格不绕路的路径种类, ilearning 算法 2021-03-21 
    1.限定条件：不能走远路,迭代或者动态规划
    2.限定条件： 不能走相同的节点，深度优先DFS */
static int cache[100][100] = {0};

int f(int m, int n)
{
    if (m < 0 || n < 0) {
        return 0;
    }

    if (m == 1 && n == 1) {
        return 1;
    }

    /* 避免重复计算，记忆化搜索，以空间换时间 */
    if (cache[m][n] != 0) {
        return cache[m][n];
    }
    // cache[m][n] = 1;

    return f(m - 1, n) + f(m, n - 1);
}

/* 从1开始，数组大小需要+1 */
static int dp[101][101] = {0};


int dp_f(int m, int n)
{
    for (int i = 1; i <= m; i++) {
        dp[i][1] = 1;
    }

    for (int j = 1; j <= n; j++) {
        dp[1][j] = 1;
    }

    if (dp[m][n] != 0) {
        return dp[m][n];
    }

    for (int i = 2; i <= m; i++) {
        for (int j = 2; j <= n; j++) {
            dp[i][j] = dp_f(i - 1, j) + df_f(i, j - 1);
        }
    }

    return dp[m][n];
}

int visited[100][100] = {0};

#define COL 6
#define ROW 6

/* (x,y)表示起点，(m,n)表示目的点 */
int step(int x, int y, int m, int n)
{
    if (x == m && y == n) {
        return 1;
    }

    if (x < 0 || y < 0 || x > COL || y > ROW) {
        return 0;
    }

    if (visited[x][y] == 1) {
        return 0;
    }

    visited[x][y] = 1;

    int sum = 0;
    sum += step(x + 1, y, m, n);
    sum += step(x, y + 1, m, n);
    sum += step(x - 1, y, m, n);
    sum += step(x, y - 1, m, n);

    visited[x][y] = 0;
    return sum;
}

#if 0

/* 最大岛数量 */
#define MAXSIZE 300
void DFS (char** grid, int gridSize, int colSize, int (*viste)[MAXSIZE], int x, int y)
{
    if (x < 0 || x >= gridSize || y < 0 || y >= colSize) {
        return ;
    }
    if (grid[x][y] == '1' && !viste[x][y]) {
        viste[x][y] = 1;
        DFS(grid, gridSize, colSize, viste, x + 1, y);
        DFS(grid, gridSize, colSize, viste, x - 1, y);
        DFS(grid, gridSize, colSize, viste, x, y + 1);
        DFS(grid, gridSize, colSize, viste, x, y - 1);
    }
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    int count = 0;
    int colSize = *gridColSize;
    int viste[MAXSIZE][MAXSIZE];
    memset(viste, 0, sizeof(int) * MAXSIZE * MAXSIZE);
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < colSize; j++) {
            if (grid[i][j] == '1' && !viste[i][j]) {
                DFS(grid, gridSize, colSize, viste, i, j);
                count++;
            }            
        }
    }

    return count;
}
#endif

int main()
{
    printf("Hello DAG!\n");
    printf("f() = %d VS DP: %d\n", f(3, 3), dp_f(3, 3));

    visited[2][2] = 1;
    //printf("%d", step(4, 4, COL, ROW));
    return 0;
}