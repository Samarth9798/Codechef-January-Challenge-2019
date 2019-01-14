#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll prime[50002]; //global prime array

//check prime function
bool isPrime(ll n)
{
    if(n == 1) return true;
    if(n == 2) return true;
    for(ll i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0) return false;
    }
    return true;
}

//driver function
int main()
{
    int T;
    int N;
    ll i,j;
    ll c = 1;
    i = 1;
    
    //precompute first 50,000 prime numbers
    while(c < 50001)
    {
        if(isPrime(i))
        {
            prime[c] = i; c++;
        }
        i++;
    }
    
    //input no of test cases
    cin >> T;
    
    ll id;
    ll arr[50001]; 
    
    //solve
    while(T--)
    {
        //input N
        cin >> N;
        
        id = 0;
        
        //when N is 3
        if(N == 3)
        {
            cout << "6 10 15" << endl;
        }
        else if(N % 2 == 0) // when N is even
        {
            arr[id] = 2*3*7; id++;
            arr[id] = 2*5; id++;
            arr[id] = 5*11; id++;
            c = 0; i = 6;
            int flag = 3;
            while(id < N)
            {
                arr[id] = flag * prime[i]; id++;
                c++;
                if(c == 2 and flag == 3)
                {
                    flag = 7; c = 0;
                }
                else if(c == 2 and flag == 7)
                {
                    flag = 3; c = 0;
                }
                if(c == 1) i++;
            }
            
            // output the required array
            for(i = 0; i < id; i++)
                cout << arr[i] << ' ';
            cout << endl;
        }
        else //when N is odd
        {
            arr[id] = 2*3*7; id++;
            arr[id] = 2*5; id++;
            arr[id] = 5*3; id++;
            arr[id] = 3*11; id++;
            c = 0; i = 6;
            int flag = 7;
            while(id < N)
            {
                arr[id] = flag * prime[i]; id++;
                c++;
                if(c == 2 and flag == 3)
                {
                    flag = 7; c = 0;
                }
                else if(c == 2 and flag == 7)
                {
                    flag = 3; c = 0;
                }
                if(c == 1) i++;
            }
            
            // output the required array
            for(i = 0; i < id; i++)
                cout << arr[i] << ' ';
            cout << endl;
        }
    }
}
