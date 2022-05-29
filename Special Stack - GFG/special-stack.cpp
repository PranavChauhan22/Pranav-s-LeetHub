// { Driver Code Starts
#include<iostream>
#include<stack>
using namespace std;
void push(stack<int>& s,int a);
bool isFull(stack<int>& s,int n);
bool isEmpty(stack<int>& s);
int pop(stack<int>& s);
int getMin(stack<int>& s);
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty(s)){
		    pop(s);
		}
		while(!isFull(s,n)){
			cin>>a;
			push(s,a);
		}
		cout<<getMin(s)<<endl;
	}
}// } Driver Code Ends

int mini=1e9+7;
void push(stack<int>& s, int a){
	// Your code goes here
	if(s.size()==0){
	    mini=a;
	    s.push(a);
	    return;
	}
	if(mini>a){
	    
	    s.push((2*a)-mini);
	    mini=a;
	}else{
	    s.push(a);
	}
	
}

bool isFull(stack<int>& s,int n){
	if(s.size()==n){
	    return true;
	}
	return false;
}

bool isEmpty(stack<int>& s){
	if(s.size()==0){
	    return true;
	}
	return false;
}

int pop(stack<int>& s){
	if(mini>s.top()){
	    int w= (2*mini-s.top());
	    s.pop();
	    return w;
	}
	int w=s.top();
	s.pop();
	return w;
}

int getMin(stack<int>& s){
	return mini;
}