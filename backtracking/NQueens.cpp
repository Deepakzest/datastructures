class Solution {
public:
    bool valid_row(int row,vector<string>&grid,int n)
    {
        for(int i=0;i<n;i++)
        {
            if(grid[row][i]=='Q')return false;
        }
        return true;
    }
    bool valid_column(int col,vector<string>&grid,int n)
    {
        for(int i=0;i<n;i++)
        {
            if(grid[i][col]=='Q')return false;
        }
        return true;
    }
    bool valid_diagonal(int row,int col,vector<string>&grid,int n)
    {
        int i=row;
        int j=col;
        while(i>=0&&j>=0)//checking top left diagonal
        {
            if(grid[i][j]=='Q')
            {
                return false;
            }
            i--;
            j--;
        }
        i=row;
        j=col;
        while(i>=0&&j<n)//checking top right diagonal
        {
            if(grid[i][j]=='Q')
            {
                return false;
            }
            i--;
            j++;
        }
        i=row;
        j=col;
        while(i<n&&j<n)//checking bottom right diagonal
        {
            if(grid[i][j]=='Q')
            {
                return false;
            }
            i++;
            j++;

        }
        i=row;
        j=col;
        while(i<n&&j>=0)//checking bottom left diagonal
        {
            if(grid[i][j]=='Q')
            {
                return false;
            }
            i++;
            j--;
        }
        return true; //can place the queen
    }
    bool CanPlace(vector<string>&grid,int n,int row,int col)
    {
        return valid_row(row,grid,n)&&valid_column(col,grid,n)&&valid_diagonal(row,col,grid,n);
    }
    void solve(vector<string>&grid,int n,int col,vector<vector<string>>&ans)
    {
        if(col==n)
        {
            ans.push_back(grid);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(CanPlace(grid,n,row,col))
            {
                grid[row][col]='Q';
                solve(grid,n,col+1,ans);
                grid[row][col]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n)
    {
    vector<vector<string>> ans;
    vector<string> grid(n, string(n, '.'));
    solve(grid, n, 0, ans);
    return ans;
    }
};
