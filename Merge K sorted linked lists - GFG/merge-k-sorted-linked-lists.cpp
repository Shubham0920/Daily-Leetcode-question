//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

// } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution{
  public:
    Node* mergeTwoLists(Node* l1, Node* l2) {
        Node* p1 = l1;
        Node* p2 = l2;
        Node* dummy = new Node(-1);
        Node* p3 = dummy;
        
        while(p1!=nullptr && p2!=nullptr){
            if(p1->data <= p2->data){
                p3->next = p1;
                p1 = p1->next;
            }
            else{
                p3->next = p2;
                p2 = p2->next;
            }
            p3 = p3->next;
        }
        while(p1!=nullptr){
            p3->next = p1;
            p1 = p1->next;
            p3 = p3->next;
        }
        while(p2!=nullptr){
            p3->next = p2;
            p2 = p2->next;
            p3 = p3->next;
        }
        return dummy->next;
    }
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
        if(K==1)return arr[0];
        Node* m = mergeTwoLists(arr[0],arr[1]);
        if(K==2)return m;
        for(int i=2;i<K;i++){
            m = mergeTwoLists(m,arr[i]);
        }
        return m;
    }
};



//{ Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}

// } Driver Code Ends