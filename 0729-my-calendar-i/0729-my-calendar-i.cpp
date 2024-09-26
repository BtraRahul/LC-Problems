// 10 - 50, 70 - 100
// 60-80
// 1 - 2
// 50-70

//  {10,50}, '{70,100}'   insert -> {50,70}
//  {10,50}, {50,70}, {70,100}

class MyCalendar {
    vector<pair<int, int>> intervals;
    int size;

public:
    MyCalendar() { size = 0; }

    bool book(int start, int end) {
        pair<int, int> newInterval = {start, end};
        if (size == 0) {
            size++;
            intervals.push_back(newInterval);
            return true;
        }
        int currIdx =
            lower_bound(intervals.begin(), intervals.end(), newInterval) -
            intervals.begin();

        // currIdx  = size, -1,  0
        pair<int, int> currInterval = {1e9, 1e9};
        pair<int, int> prevInterval = {0, 0};

        if (currIdx < size)
            currInterval = intervals[currIdx];
        if (currIdx - 1 >= 0)
            prevInterval = intervals[currIdx - 1];

        bool overlaps = true;

        if (currInterval.first < end)
            return false;
        if (prevInterval.second > start)
            return false;

        intervals.insert(intervals.begin()+currIdx, {start, end});
        size++;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */