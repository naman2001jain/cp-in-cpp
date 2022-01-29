// problem link:- https://practice.geeksforgeeks.org/problems/sort-a-stack/1#

void putBottom(stack<int> &s, int temp){
    if(s.empty() || temp>s.top()){
        s.push(temp);
        return;
    }
    int x = s.top();
    s.pop();
    putBottom(s,temp);
    s.push(x);
}


void util(stack<int> &s){
    if(s.empty()){
        return;
    }
    int temp = s.top();
    s.pop();
    util(s);
    putBottom(s, temp);
}

void SortedStack :: sort()
{
   //Your code here
   util(s);
}
