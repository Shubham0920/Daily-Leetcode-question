//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        QueueStack *qs = new QueueStack();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            qs->push(a);
        }else if(QueryType==2){
            cout<<qs->pop()<<" ";

        }
        }
        cout<<endl;
    }
}

// } Driver Code Ends


/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */

//Function to push an element into stack using two queues.
void QueueStack :: push(int x)
{
        // Your Code
        if(q1.empty()){
            q2.push(x);
        }
        else{
            q1.push(x);
        }
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
    
    if(q1.empty() && q2.empty())return -1;
        // Your Code 
        if(q1.empty()){
            int n = q2.size();
            for(int i=0;i<n-1;i++){
                q1.push(q2.front());
                q2.pop();
            }
            int x = q2.front();
            q2.pop();
            return x;
        }
        else{
            int n = q1.size();
            for(int i=0;i<n-1;i++){
                q2.push(q1.front());
                q1.pop();
            }
            int x = q1.front();
            q1.pop();
            return x;
        }
}
