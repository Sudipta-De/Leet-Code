int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
    int m=obstacleGridSize;
    int n= obstacleGridColSize[0];
    int dp[n];
    for(int j=0;j<n;j++){
        dp[j]=0;
    }
    dp[0]=1;
    for(int i=0;i<m;i++){
        for (int j = 0; j < n; j++) {

            if (obstacleGrid[i][j] == 1) {
                dp[j] = 0;
            }
            else if (j > 0) {
                dp[j] = dp[j] + dp[j - 1];
            }
        }
    }

    return dp[n - 1];

}