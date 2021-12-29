#include <iostream>
using namespace std;
#include <bits/stdc++.h>

bool isSafe1(int row, int col, vector<string> board, int n)
{
    
    int duprow = row;
    int dupcol = col;

    // check upper diagonal
    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row--;
        col--;
    }
    // check horizontally 
    col = dupcol;
    row = duprow;
    while (col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        col--;
    }
    // check lower diagonal
    row = duprow;
    col = dupcol;
    while (row < n && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row++;
        col--;
    }

    return true;
}

void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }
    
    for (int row = 0; row < n; row++)
    {
        if (isSafe1(row, col, board, n))
        {
            board[row][col] = 'Q';
            solve(col + 1, board, ans, n);
            board[row][col] = '.';
        }
    }

}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans; // initially declear ans
    vector<string> board(n); // creating chess board
    
    string s(n, '.');   // i made sure to put empty char in every place of string
    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }


    solve(0, board, ans, n);
    return ans;
}

int main()
{
    // int n ;
    // cout<<"Enter the size of chess board : ";
    // cin>>n;
    vector<vector<string>> v = solveNQueens(8);

    for (auto i : v)
    {
        for (auto j : i)
        {
            for(int k = 0;k<j.length();k++)
            {
                cout<<j[k]<<" ";
            }
            cout<<endl;
            
        }
        cout<<"\n";
        
    }
    return 0;

}
