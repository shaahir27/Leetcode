// Last updated: 11/16/2026, 9:57:13 PM
#include <vector>

class CustomStack {
private:
    std::vector<int> stk;
    std::vector<int> inc;
    int maxSize;

public:
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        if (stk.size() < maxSize) {
            stk.push_back(x);
            inc.push_back(0); // Initialize lazy increment for the new element
        }
    }
    
    int pop() {
        int idx = stk.size() - 1;
        if (idx < 0) {
            return -1;
        }
        
        // Add the lazy increment value to the top element
        int res = stk[idx] + inc[idx];
        
        // Propagate the increment down to the next element in the stack
        if (idx > 0) {
            inc[idx - 1] += inc[idx];
        }
        
        // Reset the increment for this position and remove elements
        inc.pop_back();
        stk.pop_back();
        
        return res;
    }
    
    void increment(int k, int val) {
        int idx = std::min(k, (int)stk.size()) - 1;
        if (idx >= 0) {
            inc[idx] += val; // Lazy update at the boundary element
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */