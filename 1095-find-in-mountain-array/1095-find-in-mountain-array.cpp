/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */


class Solution {
public:
    
    int peak(MountainArray &mountainArr) 
    {
        int s=0;
        int e=mountainArr.length()-1;
        int mid;
        while(s<e)
        {
            mid=s+(e-s)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1))
                s=mid+1;
            else
                e=mid;
        }
        return s;
    }

    int leftSide(int s,int e,MountainArray &mountainArr,int target)
    {
        int mid;
        int ans = -1;
        while(s<=e)
        {
            mid=s+(e-s)/2;
            if(mountainArr.get(mid) == target)
            {
                ans = mid;
                e = mid-1;
            }
            else if(mountainArr.get(mid) < target) s = mid+1;
            else e = mid-1;
        }
        return ans;
    }

    int rightSide(int s,int e,MountainArray &mountainArr,int target)
    {
        int mid;
        int ans = -1;
        while(s<=e)
        {
            mid=s+(e-s)/2;
            if(mountainArr.get(mid) == target)
            {
                ans = mid;
                e = mid-1;
            }
            else if(mountainArr.get(mid) < target) e = mid-1;
            else s = mid + 1;
        }
        return ans;
    }
    
    int findInMountainArray(int target, MountainArray &mountainArr) 
    {
        int choti = peak(mountainArr);
        int left = leftSide(0,choti,mountainArr,target);

        if(left != -1)return left;

        int right = rightSide(choti+1,mountainArr.length()-1,mountainArr,target);
        return right;
    }
};