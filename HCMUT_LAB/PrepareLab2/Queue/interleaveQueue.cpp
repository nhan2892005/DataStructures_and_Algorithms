/*
[Eng] Given a queue of integers of even length, rearrange the elements by interleaving the first half of the queue with the second half of the queue.

Your task is to implement interleaveQueue function.

stack and queue are included.

[Vie] Cho 1 hàng đợi có số lượng phần tử là số chẵn, sắp xếp lại các phần tử theo quy tắc xen kẽ phần tử ở nửa đầu và nửa sau của hàng đợi.

Sinh viên cần hiện thực hàm interleaveQueue.

Thư viện stack và queue đã được thêm vào.

Input	                    Result
4
1 2 3 4                     1 3 2 4
-----------------------------------------
6
2 4 6 8 10 12               2 8 4 10 6 12
*/

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void interleaveQueue(queue<int>& q){
    stack<int> s;
    int n = q.size();
    for(int i = 0; i < n/2; i++){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    for(int i = 0; i < n/2; i++){
        q.push(q.front());
        q.pop();
    }
    for(int i = 0; i < n/2; i++){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        queue<int> q;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            q.push(x);
        }
        interleaveQueue(q);
        while(!q.empty()){
            cout << q.front() << " ";
            q.pop();
        }
        cout << endl;
    }
    return 0;
}