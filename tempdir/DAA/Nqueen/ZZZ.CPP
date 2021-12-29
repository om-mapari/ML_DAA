#include <bits/stdc++.h>
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;
void init_code() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

bool isSafe1(int row, int col, vector<string> board, int n)
{
    // check upper diagonal
    int duprow = row;
    int dupcol = col;

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
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }

    solve(0, board, ans, n);
    return ans;
}

int main()
{
    // init_code();
    int n ;
    cout << "Enter the size of chess board : " << endl;
    cin >> n;


    auto start = high_resolution_clock::now();
    vector<vector<string>> v = solveNQueens(n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\nEXECUTION OF DP ALGORITHM : " << duration.count() << " MILISECONDS" << endl;

    for (auto i : v)
    {
        for (auto j : i)
        {
            for (int k = 0; k < j.length(); k++)
            {
                cout << j[k] << " ";
            }
            cout << endl;
        }
        cout << "\n";
    }
    return 0;

}
