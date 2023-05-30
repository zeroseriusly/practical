#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// functiion for counting the false finish flags
int count_finish(bool finish[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (finish[i] == false)
        {
            count++;
        }
    }

    return count;
}

int main()
{
    int n, m, w = 65;
    cout << "Enter total number of processes: ";
    cin >> n;
    cout << "Enter number of resources: ";
    cin >> m;

    int p[n];
    int allocation[n][m], need[n][m], available[m], max[n][m];

    cout << "Enter Allocation:" << endl;
    for (int i = 0; i < m; i++)
    {
        int k = w + i;
        cout << (char)k << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> allocation[i][j];
        }
    }

    cout << "Enter Max Needs:" << endl;
    for (int i = 0; i < m; i++)
    {
        int k = w + i;
        cout << (char)k << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> max[i][j];
        }
    }

    cout << "Enter Available: " << endl;
    for (int i = 0; i < m; i++)
    {
        int k = w + i;
        cout << (char)k << " ";
    }
    cout << endl;

    for (int i = 0; i < m; i++)
    {
        cin >> available[i];
    }

    // Algorithm starts from here
    bool finish[n];
    for (int i = 0; i < n; i++)
    {
        finish[i] = false;
    }

    // Needs Table
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    int count1 = 0;
    while (count1 != count_finish(finish, n))
    {
        count1 = count_finish(finish, n);
        // Comparing needs with available
        for (int i = 0; i < n; i++)
        {
            int flag = 0;
            if (finish[i] == false)
            {
                for (int j = 0; j < m; j++)
                {
                    if (need[i][j] <= available[j])
                    {
                        flag = flag + 1;
                    }
                }

                // if all are less than available then available = available + needs
                if (flag == m)
                {
                    for (int j = 0; j < m; j++)
                    {
                        available[j] = available[j] + need[i][j];
                        count1 = count1 - 1;
                    }
                    finish[i] = true;
                }
            }
        }
    }

    if (count1 == 0)
    {
        cout << "System is in safe state" << endl;
        for (int i = 0; i < m; i++)
        {
            cout << available[m] << " ";
        }
    }
    else
    {
        cout << "System is in unsafe state" << endl;
        cout << "Process causing deadlock are: " << endl;
        for (int i = 0; i < n; i++)
        {
            if (finish[i] == false)
            {
                cout << "Process P" << i << endl;
            }
        }
    }
}
