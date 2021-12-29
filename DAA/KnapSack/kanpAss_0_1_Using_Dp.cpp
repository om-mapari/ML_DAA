// 2. 0-1 Knapsack Problem

#include <iostream>
#include <chrono>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

struct knapsack
{
    float w;
    float v;
};
class soluation
{
    knapsack data[100];
    int n;
    int W;
    int **dp;

public:
    void input_data()
    {
        cout << "ENTER NO OF ITEMS = ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << endl;

            cout << "ENTER VALUE OF ITEM NO. " << i + 1 << " ";
            cin >> data[i].v;
            cout << "ENTER WEIGHT OF ITEM NO. " << i + 1 << " ";
            cin >> data[i].w;
        }
        cout << "\nENTER KNAPSACK WEIGHT OF BAG ";
        cin >> W;
        cout << "\n\t==========================================";
        cout << "\n\tITOM NO.\t\tWEIGHT\t\tVALUE";
        cout << "\n\t==========================================";
        for (int i = 0; i < n; i++)
        {
            cout << "\n\t" << i + 1 << "\t\t\t" << data[i].w << "\t\t" << data[i].v;
        }
        cout << "\n\t==========================================";
    }

    float knapSackRec(knapsack arr[], int W, int i, int **dp)
    {
        if (i < 0)
            return 0;
        if (dp[i][W] != -1)
            return dp[i][W];

        if (arr[i].w > W)
        {
            dp[i][W] = knapSackRec(arr, W, i - 1, dp);
            return dp[i][W];
        }
        else
        {
            dp[i][W] = max(arr[i].v + knapSackRec(arr, W - arr[i].w, i - 1, dp), knapSackRec(arr, W, i - 1, dp));
            return dp[i][W];
        }
    }
    float knapSackG()
    {

        dp = new int *[n];

        for (int i = 0; i < n; i++)
            dp[i] = new int[W + 1];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < W + 1; j++)
                dp[i][j] = -1;

        return knapSackRec(data, W, n - 1, dp);
    }
    void PrintDpArray()
    {
        cout << "\n\nPRINTING DP ARRAY \n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < W + 1; j++)
                cout << dp[i][j] << " ";
            cout << endl;
        }
    }
};

int main()
{
    soluation s;
    while (true)
    {
        cout << "\n\n*****MAIN MENU*****" << endl;
        cout << "1. INPUT DATA : " << endl;
        cout << "2. MAXIMUM TOTAL VALUE OF KNAPSACK : " << endl;
        cout << "3. PRINT DP ARRAY : " << endl;
        cout << "PRESS 0 TO EXIT PROGRAM : " << endl;
        int c1;
        cout << "**ENTER CHOICE** : ";
        cin >> c1;
        if (c1 == 1)
        {
            s.input_data();
        }
        else if (c1 == 2)
        {
            auto start = high_resolution_clock::now();
            cout << "\nMAXIMUM TOTAL VALUE OF 0/1 KNAPSACK IS " << s.knapSackG() << endl;
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            cout << "\nEXECUTION OF DP ALGORITHM : " << duration.count() << " MILISECONDS" << endl;
        }
        else if (c1 == 3)
        {
            s.PrintDpArray();
        }
        else if (c1 == 0)
        {
            cout << "YOU ARE OUT OF PROGRAM ." << endl;
            break;
        }
        else
        {
            cout << "!!!Enter a Valid choice!!! " << endl;
        }
    }

    return 0;
}