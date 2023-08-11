int mini = 0;
void push(stack<int>& s, int a){
	// Your code goes here
	if(s.empty()) {
	    s.push(a);
	    mini = a;
	}
	else if(a >= mini){
	    s.push(a);
	}
	else{
	    int temp  = 2*a - mini;
	    s.push(temp);
	    mini = a;
	    
	}
}

bool isFull(stack<int>& s,int n){
	// Your code goes here
	if(s.size() == n) return true;
	return false;
}

bool isEmpty(stack<int>& s){
	// Your code goes here
	if(s.empty()) return true;
	return false;
}

int pop(stack<int>& s){
	// Your code goes here
	
	if(s.empty()) return -1;
	
	else if(s.top() >= mini){
	    int temp = s.top();
	    s.pop();
	    return temp;
	}
	else{
	    int temp = mini;
	    mini = (2*mini - s.top());
	    s.pop();
	    return temp;
	}
	
}

int getMin(stack<int>& s){
	// Your code goes here
	if(s.empty()) return -1;
	
	return mini;
}