//Solution62a.java
//Nicholas Culmone

public class Solution62a {
	public static void main(String[]args){
		System.out.println(uniquePaths(100,5));
	}
    public static int uniquePaths(int m, int n) {
        int[][]paths = new int[m][n];

        for(int i=0;i<m;i++){
        	for(int j=0;j<n;j++){
        		if(i-1 == -1 || j-1 == -1) paths[i][j] = 1;
        		else paths[i][j] = paths[i-1][j] + paths[i][j-1];
        	}
        }
        return paths[m-1][n-1];
    }
}