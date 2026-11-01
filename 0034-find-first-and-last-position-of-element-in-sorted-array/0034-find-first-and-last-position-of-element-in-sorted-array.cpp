class Solution {
public:

int firstElement(vector<int>&nums,int target){
    int n = nums.size();
    int low = 0;
    int high = n-1;
    int first = -1;

    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid] == target){
            first = mid;
            high = mid - 1;
        }
        else if(nums[mid] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }

    }
    return first;
}

int lastElement(vector<int>&nums,int target){
    int n = nums.size();
    int low = 0;
    int high = n-1;
    int last = -1;

    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid] == target){
            last = mid;
            low = mid + 1;
        }
        else if(nums[mid] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }

    }
    return last;
}


    vector<int> searchRange(vector<int>& nums, int target) {
        int fs = firstElement(nums , target);
        int ls = lastElement(nums , target);

        return {fs,ls};
        
    }
};