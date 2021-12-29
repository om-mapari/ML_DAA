#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int knapsack(int wt[], int val[], int w, int n)
{
    if (w == 0 || n == 0)
        return 0;

    if (wt[n - 1] <= w)
    {
        return max(val[n - 1] + knapsack(wt, val, w - wt[n - 1], n - 1), knapsack(wt, val, w, n - 1));
    }
    else
    {
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
            break;
        case 2:
            if (flag == 0)
            {
                cout << "data not avaliable " << endl;
                break;
            }

            cout << "==================================" << endl;
            cout << "Ans = " << knapsack(wt, val, w, n);
            break;
        default:
            (choice == 0) ? cout << "Exiting... " << endl : cout << "Invaild input " << endl;
            break;
        }

    } while (choice != 0);

    return 0;
}