struct Comp{
    bool operator()(pair<int,int> a, pair<int,int> b)const{
        if(a.first!=b.first)
        return a.first<b.first;
        else return a.second<b.second;
    }
};


class MyCalendar {
public:

    set<pair<int,int>> dates;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        // dates.insert({start, end)};
        auto ub = dates.upper_bound({start, end});
        if(ub != dates.end() && ub->second<end)
        {
            return false;
        }
        dates.insert({end, start});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */