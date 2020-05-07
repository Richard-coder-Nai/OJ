class Solution {
public:
    vector<int> tmp;
    vector<int> nums;
    int n;
    int merge_sort(int l, int r) {
        if(l>=r) return 0;
        
        int mid = (l+r)>>1;
        
        int res = merge_sort(l, mid) + merge_sort(mid+1, r);

        int i = l;
        int j = mid+1;
        int k = 0;
        while(i<=mid && j<=r) {
            if(nums[i]<=nums[j]) {
                tmp[k++] = nums[i++];
            }else {
                tmp[k++] = nums[j++];
                res += (mid-i+1);
            }
        }
        
        while(i<=mid) tmp[k++] = nums[i++];
        while(j<=r) tmp[k++] = nums[j++];
        
        
        for(k=0, i=l; i<=r; i++, k++) {
            nums[i] = tmp[k];
        }
        return res;
    }
    
    int inversePairs(vector<int>& _nums) {
        nums = _nums;
        n = nums.size();
        tmp.assign(n, 0);
        return merge_sort(0, n-1);
    }
};
