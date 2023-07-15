#include <bits/stdc++.h>
#define SalAC ios_base::sync_with_stdio(false); cin.tie(0);
#define push push_back
#define pop pop_back
#define top back
using namespace std;

string s;

vector <string> v;

void split(string &s){
    string tmp = "";
    for (char c: s){
        if (isdigit(c)){
            tmp += c;
        }
        else{
            v.push_back(tmp);
            v.push_back(string{c});
            tmp = "";
        }
    }
    v.push_back(tmp);
}

vector <int> num;
vector <char> opr;

int judge(vector <string>&v){
    for (string str: v){
        if (isdigit(str[0])){
            num.push(stoi(str));
            if (!opr.empty()){
                if (opr.top() == '*'){
                    int y = num.top(); num.pop();
                    int x = num.top(); num.pop();
                    num.push(x*y);
                    opr.pop();
                }
                if (opr.top() == '/'){
                    int y = num.top(); num.pop();
                    int x = num.top(); num.pop();
                    num.push(x/y);
                    opr.pop();
                }
            }
        }
        else{
            opr.push(str[0]);
        }
    }
    for (int i=0; i<(int)opr.size(); i++){
        if (opr[i] == '+'){
            num[i+1] = num[i] + num[i+1];
        }
        else if (opr[i] == '-'){
            num[i+1] = num[i] - num[i+1];
        }
    }
    return num.top();
}

signed main(){
    SalAC;
    
    cin >> s;
    
    split(s);
    
    cout << judge(v);
}