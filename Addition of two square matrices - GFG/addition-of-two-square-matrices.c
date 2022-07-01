// { Driver Code Starts
//Initial Template for C

#include <stdio.h>


 // } Driver Code Ends
//User function Template for C

void Addition(int n, int matrixA[][n], int matrixB[][n])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            matrixA[i][j]+=matrixB[i][j];
        }
    }
}

// { Driver Code Starts.

int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int n;
		scanf("%d", &n);
		int matrixA[n][n];
		int matrixB[n][n];
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				scanf("%d", &matrixA[i][j]);
			}
		}
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				scanf("%d", &matrixB[i][j]);
			}
		}
		
		Addition(n, matrixA, matrixB);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				printf("%d ", matrixA[i][j]);
			printf("\n");
		}
	}
	return 0;
}  // } Driver Code Ends