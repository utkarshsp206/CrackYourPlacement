// O(n) 

vector<int> previousSmaller(vector<int> &arr, int n) {
    vector<int> prev(n);
    stack<int> s;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        if (s.empty()) {
            prev[i] = -1;
        } 
        else {
            prev[i] = s.top();
        }
        s.push(i);
    }
    return prev;
}

vector<int> nextSmaller(vector<int> &arr, int n) {
    stack<int> s;
    vector<int> next(n);
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }   
        if (s.empty()) {
            next[i] = n;
        } 
        else {
            next[i] = s.top();
        }
        s.push(i);
    }
    return next;
}

vector<int> maxMinWindow(vector<int> &arr, int n) {
    // answer[i] will store the maximum of minimum for every window size 
    vector<int> answer(n, INT_MIN);
	
    // next[i] will store the index of next smaller element which lie on the right hand side of it
    vector<int> next = nextSmaller(arr, n);

   //prev[i] will store the index of previous smaller element which lie on the left hand side of it
    vector<int> prev = previousSmaller(arr, n);

    for (int i = 0; i < n; i++) {
        // Length of the window in which a[i] is minimum
        int length = next[i] - prev[i] - 1;

        // Update the answer
        answer[length - 1] = max(answer[length - 1], arr[i]);
    }

	// Some places in answer[] may not be filled yet.
	// so fill them by taking maximum 
    for (int i = n - 2; i >= 0; i--) 
    {
        answer[i] = max(answer[i], answer[i + 1]);
    }
    return answer;
}