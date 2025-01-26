class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    unordered_set<int> set;
    int nextSmallest;

    SmallestInfiniteSet() {
        nextSmallest = 1;
    }
    
    int popSmallest() {
        if (!minHeap.empty()) {
            int smallest = minHeap.top();
            minHeap.pop();
            set.erase(smallest);
            return smallest;
        }
        return nextSmallest++;
    }
    
    void addBack(int num) {
      if (num < nextSmallest && set.find(num) == set.end()) {
            minHeap.push(num);
            set.insert(num); 
        }  
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */