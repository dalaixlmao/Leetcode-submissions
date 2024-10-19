class Solution {
public:
    int majorityElement(vector<int>& a) { 
        int n = a.size(); 
        int curr = 0;
        int el = 0;
        for(int i=0;i<n;i++)
        {
            if(el==0)
            {
                curr=a[i];
            }
            if(curr==a[i])
            {
                el++;
            }
            else{
                el--;
            }
        }
        el=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==curr)
            el++;
        }
        return curr;
    }
};