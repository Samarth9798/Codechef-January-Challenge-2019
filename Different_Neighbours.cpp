#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    int N,M;
    int grid[100][100];
    int K;
    int i,j;
    //input the no of test cases
    cin >> T;
    while(T--)
    {
        //input the size of grid
        cin >> N >> M;
        if(N == 1 and M == 1) //this is first corner case
        {
            cout << 1 << endl; cout << 1 << endl;
        }
        else if(N == 1 and M == 2) //this is second corner case
        {
            cout << 1 << endl; cout << "1 1" << endl;
        }
        else if(N == 2 and M == 1) //this is third corner case
        {
            cout << 1 << endl; cout << 1 << endl; cout << 1 << endl;
        }
        else if(N == 2 and M == 2) //this is forth corner case
        {
            cout << 2 << endl; cout << "1 1" << endl; cout << "2 2" << endl;
        }
        else if(N == 1 and M > 2) //this is for fifth corner case 
        {
            K = 2;
            i = 1;
            int c = 0;
            int no = 1;
            for(j = 1; j <= M; j++)
            {
                grid[i][j] = no;
                c++;
                if(c == 2 and no == 1)
                {
                    c = 0; no = 2;
                }
                else if(c == 2 and no == 2)
                {
                    c = 0; no = 1;
                }
            }
            cout << K << endl;
            for(j = 1; j <= M; j++) cout << grid[i][j] << ' ';
            cout << endl;
        }
        else if(N > 2 and M == 1) //this is the sixth corner case
        {
            K = 2;
            j = 1;
            int c = 0;
            int no = 1;
            for(i = 1; i <= N; i++)
            {
                grid[i][j] = no;
                c++;
                if(c == 2 and no == 1)
                {
                    c = 0; no = 2;
                }
                else if(c == 2 and no == 2)
                {
                    c = 0; no = 1;
                }
            }
            cout << K << endl;
            for(i = 1; i <= N; i++) cout << grid[i][j] << endl;
        }
        else if(N == 2 and M > 2) //this if for the seventh corner case
        {
            K = 3;
            int no = 1;
            for(i = 1; i <= N; i++)
            {
                no = 1;
                for(j = 1; j <= M; j++)
                {
                    grid[i][j] = no;
                    if(no == 1) no = 2;
                    else if(no == 2) no = 3;
                    else if(no == 3) no = 1;
                }
            }
            cout << K << endl;
            for(i = 1; i <= N; i++)
            {
                for(j = 1; j <= M; j++)
                {
                    cout << grid[i][j] << ' ';
                }
                cout << endl;
            }
        }
        else if(N > 2 and M == 2) //this is the 8th corner case
        {
            K = 3;
            int no = 1;
            for(i = 1; i <= N; i++)
            {
                for(j = 1; j <= M; j++)
                {
                    grid[i][j] = no;
                }
                if(no == 1) no = 2;
                else if(no == 2) no = 3;
                else if(no == 3) no = 1;
            }
            cout << K << endl;
            for(i = 1; i <= N; i++)
            {
                for(j = 1; j <= M; j++)
                {
                    cout << grid[i][j] << ' ';
                }
                cout << endl;
            }
        }
        else //otherwise
        {
            K = 4;
            int no = 1;
            int c = 0;
            int flag = 1;
            //filling 1 and 3 in the grid
            for(i = 1; i <= N; i = i + 2)
            {
                c = 0;
                for(j = 1; j <= M; j++)
                {
                    grid[i][j] = no;
                    c++;
                    if(c == 2 and no == 1)
                    {
                        c = 0; no = 3;
                    }
                    else if(c == 2 and no == 3)
                    {
                        c = 0; no = 1;
                    }
                }
                if(flag == 1)
                {
                    flag = 3; no = 3;
                }
                else if(flag == 3)
                {
                    flag = 1; no = 1;
                }
            }
            c = 0;
            flag = 2;
            no = 2;
            //filling 2 and 4 in the grid
            for(i = 2; i <= N; i = i + 2)
            {
                c = 0;
                for(j = 1; j <= M; j++)
                {
                    grid[i][j] = no;
                    c++;
                    if(c == 2 and no == 2)
                    {
                        c = 0; no = 4;
                    }
                    else if(c == 2 and no == 4)
                    {
                        c = 0; no = 2;
                    }
                }
                if(flag == 2)
                {
                    flag = 4; no = 4;
                }
                else if(flag == 4)
                {
                    flag = 2; no = 2;
                }
            }
            //output the grid
            cout << K << endl;
            for(i = 1; i <= N; i++)
            {
                for(j = 1; j <= M; j++)
                {
                    cout << grid[i][j] << ' ';
                }
                cout << endl;
            }
        }
    }
}
