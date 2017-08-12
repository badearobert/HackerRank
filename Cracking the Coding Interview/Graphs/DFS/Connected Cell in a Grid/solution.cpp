#include <vector>
#include <iostream>

using namespace std;

bool isValidPos(vector< vector<int> >& grid, int row, int col)
{
    static int totalRows = grid.size();
    static int totalCols = grid[0].size();   
    if (row >= 0 && row < totalRows && col >= 0 && col < totalCols) 
    {
        return true;
    }
    return false;
}
int getRegionRecursive(vector< vector<int> >& grid, int row, int col) 
{
    if (isValidPos(grid, row, col))
    {
        if (grid[row][col] == 1) 
        {
            grid[row][col] = 0;
            return 1 + 
                // horizontally
                getRegionRecursive(grid, row-1, col) +
                getRegionRecursive(grid, row+1, col) +
                // vertically
                getRegionRecursive(grid, row, col-1) + 
                getRegionRecursive(grid, row, col+1) +
                //diagonally
                getRegionRecursive(grid, row-1, col-1) +
                getRegionRecursive(grid, row-1, col+1) + 
                getRegionRecursive(grid, row+1, col+1) +                
                getRegionRecursive(grid, row+1, col-1); 
        }
   
    }
    
    return 0;
}
int get_biggest_region(vector< vector<int> > grid) 
{
    if (grid.size() == 1 && grid[0].size() == 1) 
    {
        return grid[0][0];
    }
    
    int rows = grid.size();
    int cols = grid[0].size();
    
    int maxRegion = 0;
    for (int i = 0 ; i < rows; ++i) 
    {
        for (int j = 0 ; j < cols; ++j) 
        {
            maxRegion = max(maxRegion, getRegionRecursive(grid, i, j) );
            
        }
    }
    return maxRegion;
    
}

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector< vector<int> > grid(n,vector<int>(m));
    for(int grid_i = 0;grid_i < n;grid_i++)
    {
       for(int grid_j = 0;grid_j < m;grid_j++)
       {
          cin >> grid[grid_i][grid_j];
       }
    }
    cout << get_biggest_region(grid) << endl;
    return 0;
}
