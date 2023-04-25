
class SmallestInfiniteSet {
public:
   vector<int>mp;
    SmallestInfiniteSet() {
        
       mp.resize(1001,1);
        
    }
    
    int popSmallest() {
        
        int ans=0;
        
        for(int i=1;i<=1000;i++)
        {
            if(mp[i]==1)
            {
                ans=i;
                mp[i]=0;
                break;
            }
        }
        return ans;
    }
    
    void addBack(int num) {
        
        mp[num]=1;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */