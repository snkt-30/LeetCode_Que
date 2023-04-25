class SmallestInfiniteSet {
public:
    unordered_map<int,bool> mp;
    SmallestInfiniteSet() {
        
        for(int i=1;i<=1000;i++)
        {
            mp[i]=true;
        }
    }
    
    int popSmallest() {
        
        int ans=0;
        
        for(int i=1;i<=1000;i++)
        {
            if(mp[i]==true)
            {
                ans=i;
                mp[i]=false;
                break;
            }
        }
        return ans;
    }
    
    void addBack(int num) {
        
        mp[num]=true;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */