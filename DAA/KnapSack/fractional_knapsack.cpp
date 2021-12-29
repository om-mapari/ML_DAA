// 1. FRACTIONAL KNAPSACK

#include <iostream>
#include <chrono>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

struct knapsack
{
    float w;
    float v;
    float ratio;
};
class soluation
{
    knapsack data[100];
    int n;
    int W;

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
            data[i].ratio = data[i].v / data[i].w;
        }
        cout << "\nENTER KNAPSACK WEIGHT OF BAG ";
        cin >> W;
        cout << endl;
    }
    void sortRatio()
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < (n - 1 - i); j++)
            {
                if (data[j].ratio < data[j + 1].ratio)
                {
                    swap(data[j], data[j + 1]);
                }
            }
        }

        cout << "\nSORTED VALUE/WEIGHT RATIO " << endl;
        for (int i = 0; i < n; i++)
        {
            cout << data[i].ratio << " ";
        }
        cout << endl;

    }
    void knapsack()
    {

        float solArray[n] = {0.0};
        float temp = W;
        int i = 0;
        for (i = 0; i < n; i++)
        {
            if (data[i].w > temp)
            {
                break;
            };
            solArray[i] = 1.0;
            temp = temp - data[i].w;
        }
        if (i <= n)
        {
            solArray[i] = (float)temp / data[i].w;
        }

        float profit = 0;
        for (int i = 0; i < n; i++)
        {
            profit += data[i].v * solArray[i];
        }
        cout << "MAXIMUM TOTAL VALUE OF KNAPSACK IS " << profit << endl;
    }
};
int main()
{
    soluation s;
    int choice = 0;
    do
    {
        cout << "\n*****MAIN MENU*****" << endl;
        cout << "1. INPUT DATA : " << endl;
        cout << "2. MAXIMUM TOTAL VALUE OF KNAPSACK : " << endl;
        cout << "PRESS 0 TO EXIT PROGRAM : " << endl;
        cout << "**ENTER CHOICE** : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            s.input_data();
            break;
        case 2:
            s.sortRatio();
            auto start = high_resolution_clock::now();
            s.knapsack();
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            cout << "\nEXECUTION OF GREEDY ALGORITHM : " << duration.count() << " MILISECONDS"<<endl;
            break;
        }

    } while (choice != 0);

    return 0;
}
