#define ll long long
class Solution {
public:
    string getReccur(string ans, int l, int r) {
        cout << ans << endl;
        return ans.substr(l, r - l + 1);
    }

    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0)
        {
            return "0";
        }
        // num / denominator
        // 10/3 => 3.3
        //           ^
        // 10/3 => 3
        // 10/3 => 3
        // 1
        // 4/333 => 0.(012)
        // 40/333 =>0
        // 400/333=>1
        // 670/333=>2
        // 4/333
        string ans = "";
        if(((ll)numerator)*((ll)denominator)<0LL)
        ans+='-';
        numerator=abs(numerator);
        denominator=abs(denominator);
        ll q = numerator / denominator;
        ll r = numerator % denominator;
        map<int, int> mp;
        ans += to_string(q);
        if(r==0)
        return ans;
        ans += '.';
        // 177.
        int ind = ans.size();
        // 5/30
        // q = 0 r= 5
        // q = 1 r = 20
        // q = 6 r = 20
        while (true) {
            // cout<<r<<" ";

            // cout<<r<<" "<<q<<endl;
            q = (r * 10) / denominator;
            cout << q << " before " << r << endl;
            cout<<ans<<endl;
            if (mp.count(r)) {
                // wrap the numbers in brackets

                string reccurring = getReccur(ans, mp[r], ind - 1);
                string before = ans.substr(0, mp[r]);
                return before + "(" + reccurring + ")";
            } else {
                ans += ('0' + q);
                mp[r] = ind;
            }
            if (r == 0) {
                if (ans.back() == '0') {
                    while(ans.back()<='0' || ans.back()>'9')
                    ans.pop_back();
                }
                return ans;
            }
            r = (r * 10);
            r = r % denominator;
        cout << q << " after " << r << endl;

            ind++;
        }
        // for (auto i : mp) {
        //     cout << i.first << " " << i.second << endl;
        // }

        return ans;
    }
};