/* 
 *  案例一、简单的一维 DP
 *  问题描述：一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
 * 
 *  Time: 2021-05-25 
 */

#include <stdio.h>
static int dp[100] = {0};


/* 迭代法 */
int rescure(int n)
{
    if (n <= 2) {
        /* dp[0] = 0; dp[1] = 1; dp[2] = 2; */
        return n;
    }

    /* 初始化 */
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++) {
        /* 限制迭代条件：最终的目的点步数分解为 之前的一步和两步 */
        dp[i] = dp[i - 1] + dp[i - 2];
        printf("i = %d, dp[n] = %d\n", i, dp[i]);
    }

    return dp[n];
}


int main()
{
    printf("Hello DAG!\n");

    printf("%d", rescure(4));
    return 0;
}