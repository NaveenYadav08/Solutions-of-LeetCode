// Custom comparator function for sorting
bool cmp(const std::vector<int>& a, const std::vector<int>& b) {
    return a.back() < b.back();
}

// Sort function
void sortIntervals(std::vector<std::vector<int>>& intervals) {
    std::sort(intervals.begin(), intervals.end(), cmp);
}
