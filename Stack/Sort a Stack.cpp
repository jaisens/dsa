void stackinsert(stack<int> &stack,int a){
	if(stack.empty() || stack.top() <a){
		stack.push(a);
		return;
	}

	int x = stack.top();
	stack.pop();

	stackinsert(stack,a);
	stack.push(x);
}
void sortStack(stack<int> &stack)
{
	// Write your code here
	if(stack.empty()) return;

	int a = stack.top();
	stack.pop();

	sortStack(stack);
	stackinsert(stack,a);
}