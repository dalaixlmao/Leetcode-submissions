class Solution {
public:
    int hIndex(vector<int>& a) {
        int n = a.size();
        int mx = 0;
        for (int i = 0; i < n; i++)
            mx = max(mx, a[i]);
        vector<int> freq(mx + 1, 0);
        for (int i = 0; i < n; i++)
            freq[a[i]]++;
        int j = 0;
        for (int i = 0; i <= mx; i++)
            while (freq[i] > 0) {
                a[j] = i;
                freq[i]--;
                j++;
            }
        mx=0;
        for(int i=n-1;i>=0;i--)
        {
            mx=max(mx,min(a[i], n-i));
        }
        return mx;
    }
};