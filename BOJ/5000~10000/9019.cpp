#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <string>
#include <iostream>

using namespace std;

const int mod = 10000;

int N, M;
bool visited[10010];

pair<int, char> makeNextState(int command, int number) {
    int newNumber;
    char addedCommand;
    // D S L R
    switch (command)
    {
        case 0: {
            newNumber = (number * 2) % mod;
            addedCommand = 'D';
            break;
        }
        
        case 1: {
            newNumber = (number == 0) ? 9999 : number - 1;
            addedCommand = 'S';
            break;
        }
        
        case 2: {
            int firstDigit = number / 1000;
            number *= 10;
            number %= mod;
            newNumber = number + firstDigit;
            addedCommand = 'L';
            break;
        }

        case 3: {
            int lastDigit = number % 10;
            number /= 10;
            newNumber = number + lastDigit * 1000;
            addedCommand = 'R';
            break;
        }
    }

    newNumber %= mod;
    return make_pair(newNumber, addedCommand);
}

string bfs(int start) {
    memset(visited, 0, sizeof(visited));
    queue<pair<int, string> > qu;
    qu.push(make_pair(start, ""));
    visited[start] = true;

    while(int s = qu.size()) {
        while(s--) {
            int number = qu.front().first;
            string nowCommand = qu.front().second;
            qu.pop();

            if(number == M) {
                return nowCommand;
            }

            for(int i = 0 ; i < 4 ; i++) {
                // i -> D S L R
                pair<int, char> nextState = makeNextState(i, number);
                int newNumber = nextState.first;
                char newAddChar = nextState.second;
                string newCommand = nowCommand;
                newCommand.push_back(newAddChar);

                if(visited[newNumber]) continue;

                visited[newNumber] = true;
                qu.push(make_pair(newNumber, newCommand));
            }
        }
    }
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    int t;
    cin>>t;
    while(t--) {
        cin>>N>>M;
        // N에서 M으로 되기 작전
        cout<<bfs(N)<<"\n";
    }
}