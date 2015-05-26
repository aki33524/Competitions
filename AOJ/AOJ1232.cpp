#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <numeric>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <functional>
#include <complex>
#include <stack>
#include <tuple>

#define ll long long int

using namespace std;

const ll INF = (1<<30) - 1;

const ll MAX_M = 100000;

vector<int> sieve(int n){
    vector<int> primes;
    
    vector<bool> is_prime(n, true);
    is_prime[0] = false;
    
    for(int i=0; i<n; i++){
        if(is_prime[i]){
            primes.push_back(i+1);
            for(ll j=2*i+1; j<n; j+=i+1)
                is_prime[j] = false;
        }
    }
    return primes;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> primes = sieve(MAX_M/2);
    vector<pair<int, int>> table(MAX_M);
    
    for(int i=0; i<primes.size(); i++){
        for(int j=i; j<primes.size(); j++){
            // i < j, primes[i] < primes[j]
            ll pi = primes[i];
            ll pj = primes[j];
            if(pi * pj < MAX_M){
                pair<int, int> &p = table[pi*pj];
                if(p.first == 0 || p.first*pj < p.second*pi){
                    p.first = pi;
                    p.second = pj;
                }
            }else{
                break;
            }
        }
    }
    
    int M, A, B;
    while(cin>>M>>A>>B, M|A|B){
        while(1){
            pair<ll, ll> p = table[M--];
            if(p.first == 0)
                continue;
            
            if(p.second*A <= p.first*B){
                cout << p.first << " " << p.second << endl;
                break;
            }
        }
    }
    
    return 0;
}

