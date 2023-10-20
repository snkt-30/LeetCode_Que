/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    stack<pair<NestedInteger&, int>> s;
    NestedIterator(vector<NestedInteger> &nestedList){
        for(int i=nestedList.size()-1; i>=0; i--) s.push({nestedList[i], 0});
    }
    
    int next() {
        int ans = s.top().first.getInteger();
        s.pop();
        return ans;
    }

    void prepare(){
        while(s.size() > 0){
            auto& [nested_int, index] = s.top();
            if(nested_int.isInteger()) break;
            if(index >= nested_int.getList().size()) s.pop();
            else s.push({nested_int.getList()[index++], 0});
        }
    }
    
    bool hasNext() {
        prepare();
        return s.size() > 0;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */