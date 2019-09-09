class Solution {
public:
	int find(int low,int high,vector<int>& nums,int target)
	{
		if(high<low)
            return -1;
      
         	int mid=low+(high-low)/2;
			 if(nums[mid]==target)
			 return mid;   
            if(nums[mid]>target)
            {
            return find(low,mid-1,nums,target);
            }
            else
            {
            return find(mid+1,high,nums,target);
            }
	}
    int recur(int low,int high,vector<int>& nums)
    {
        if(high<low){
            return -1;}
         if(low==high){
            return low;} 
         int mid=low+(high-low)/2;
        if(mid<high)
        {
         if(nums[mid]>nums[mid+1])
         {return mid;}
        }
        if(mid>low)
        {
         if(nums[mid]<nums[mid-1])
         {return mid-1;}
        }
         if(nums[low]>=nums[mid])
         {
             return recur(low,mid-1,nums);
         }
         else
         {
             return recur(mid+1,high,nums);
         }
    }
    int search(vector<int>& nums, int target) {
     int n,ans;
     n=nums.size();
     int low=0,high=n-1;   
		 int pivot=recur(low,high,nums);
		if(pivot!=-1)
		{
		if(nums[pivot]==target)
		return pivot;
		if(nums[0]<=target)
		{
		ans=find(low,pivot-1,nums,target);
		}
		else
		{
		ans=find(pivot+1,high,nums,target);
		}
		}
		else
		{
		ans=find(low,high,nums,target);
		}
		return ans;
    }
};
