class FreqStack {
public:
    int freq = 0;
    unordered_map<int,int>m;
    unordered_map<int,stack<int>>stack_m;
    FreqStack() {
        freq = 0;
    }
    
    void push(int val) {
        m[val]++;
        // Lets check if this no's freq is greater than the maxfreq var freq;
        if(freq < m[val]) freq = m[val];
        // Push the freq on a particular stack of that freq value
        stack_m[m[val]].push(val);// We are pushing the value at particular freq.
    }
    
    int pop() {
        // get the top element from the stack of maximum frequency
        // here stack is used for taking care of the "frequency tie" condition
        int temp = stack_m[freq].top();
        stack_m[freq].pop();
        --m[temp];
        
        // We have to check if max freq element becomes empty then delete the stack of that max freq
        if(stack_m[freq].empty() == true)
        {
            stack_m.erase(freq);
            // We should decrease the freq value variable.
            freq -= 1;
        }
        return temp;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */