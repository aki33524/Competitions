#include <iostream>
#include <string>

using namespace std;

bool formula(string &str, int &vals, int b, int e){
    char &c = str[b];
    if(c == 'T')
        return true;
    else if(c == 'F')
        return false;
    if('a'<=c && c<='k')
        return vals>>(c-'a')&1;
    if(c == '-')
        return !formula(str, vals, b+1, e);
    int count = 0;
    for(int i=b+1; i<e; i++){
        char &c = str[i];
        if(c == '(')
            count++;
        else if(c == ')')
            count--;
        else if(!count){
            if(c == '*')
                return formula(str, vals, b+1, i) & formula(str, vals, i+1, e-1);
            if(c == '+')
                return formula(str, vals, b+1, i) | formula(str, vals, i+1, e-1);
            if(str[i] == '-' && str[i+1] == '>')
                return !formula(str, vals, b+1, i) | formula(str, vals, i+2, e-1);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string equation;
    while(cin>>equation, equation!="#"){
        int s = equation.find("=");
        bool is_identity = true;
        for(int i=0; i<1<<11; i++)
            is_identity &= formula(equation, i, 0, s)==formula(equation, i, s+1, equation.size());
        
        cout << (is_identity ? "YES" : "NO") << endl;
    }
    return 0;
}
