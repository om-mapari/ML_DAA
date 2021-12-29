#include <iostream>
#include <string.h>
using namespace std;
#include <bits/stdc++.h>

int static dp[101][1001];

int knapsack(int wt[], int val[], int w, int n)
{
    if (w == 0 || n == 0)
        return 0;

    if (dp[n][w] != -1)
    {
        cout << dp[n][w] << endl;
        return dp[n][w];
    }

    if (wt[n - 1] <= w)
    {
        dp[n][w] = max(val[n - 1] + knapsack(wt, val, w - wt[n - 1], n - 1), knapsack(wt, val, w, n - 1));
        return max(val[n - 1] + knapsack(wt, val, w - wt[n - 1], n - 1), knapsack(wt, val, w, n - 1));
    }
    else
    {
        dp[n][w] = knapsack(wt, val, w, n - 1);
        return knapsack(wt, val, w, n - 1);
    }
}

int main()
{

    int n;
    int w;
    cout << "enter no of boxes ";
    cin >> n;
    cout << endl;
    int val[n];
    int wt[n];

    int flag = 0;
    int choice = 0;
    do
    {
        cout << "\n*****MAIN MENU*****" << endl;
        cout << "PRESS 1 TO INPUT DATA OF VALUE AND WEIGHT OF BOXES : " << endl;
        cout << "PRESS 2 TO CALCULATE MAX VALUE : " << endl;
        cout << "PRESS 0 TO EXIT PROGRAM : " << endl;
        cout << "**ENTER CHOICE** : ";
        cin >> choice;
        switch (choice)
        {
        case 1:

            for (int i = 0; i < n; i++)
            {
                cout << "enter box " << i + 1 << " value ";
                cin >> val[i];
                cout << "enter box " << i + 1 << " weight ";
                cin >> wt[i];
            }
            cout << endl;
            cout << "enter max wt ";
            cin >> w;
            flag = 1;
            for (int i = 0; i < n+1; i++)
            {
                for (int j = 0; j < w+1; j++)
                {
                    dp[i][j] = -1;
                }
            }

            break;
        case 2:
            if (flag == 0)
            {
                cout << "data not avaliable " << endl;
                break;
            }

            cout << "==================================" << endl;
            cout << "Ans = " << knapsack(wt, val, w, n) << "\n\n";
            cout << "\n DP Array" << endl;
            for (int i = 0; i < n+1; i++)
            {
                for (int j = 0; j < w+1; j++)
                {
                    cout << dp[i][j] << " ";
                }
                cout << endl;
            }
            break;

        default:
            (choice == 0) ? cout << "Exiting... " << endl : cout << "Invaild input " << endl;
            break;
        }

    } while (choice != 0);

    return 0;
}