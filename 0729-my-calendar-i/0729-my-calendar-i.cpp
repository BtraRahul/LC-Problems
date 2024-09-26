class MyCalendar {
    map<int, int> intervals;

public:
    MyCalendar() {}

    bool book(int start, int end) {
        auto currIdx = intervals.lower_bound(start);
        if (currIdx != intervals.end() && currIdx->first < end)
            return false;

        if (currIdx != intervals.begin() && prev(currIdx)->second > start)
            return false;

        intervals[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */