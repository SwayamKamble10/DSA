#include<bits/stdc++.h>
using namespace std;
void rotate(vector<vector<int>>& matrix) {
    vector<vector<int>> temp=matrix;
    int row=matrix.size();
    int col=matrix[0].size();
    int total=row*col;
    int count=0;
    int start_row=0;
    int end_row=row-1;
    int start_col=0;
    int end_col=col-1;
    while (count<total)
    {
        for (int i =start_row; i <= end_row && count<total; i++)
        {
            matrix[i][end_col];
            count++;
        }
        end_col--;
    }
}

        
    
        
int main()
{

 return 0;
}