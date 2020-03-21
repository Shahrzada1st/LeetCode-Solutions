// Time:  O(n) on average
// Space: O(n)

class Solution {
public:
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> arr;
        for (int i = lo; i <= hi; ++i) {
            arr.emplace_back(power_value(i), i);
        }
        auto it = begin(arr) + k - 1;
        nth_element(begin(arr), it, end(arr));
        return it->second;
    }

private:
    int power_value(int x) {
        int y = x;
        if (!Solution::dp_.count(y)) {
            int result = 0;
            while (x > 1) {
                ++result;
                if (x & 1) {
                    x = 3 * x + 1;
                } else {
                    x >>= 1;
                }
                if (Solution::dp_.count(x)) {
                    result += Solution::dp_[x];
                    break;
                }
            }
            Solution::dp_[y] = result;
        }
        return Solution::dp_[y];
    }
    
    static unordered_map<int, int> dp_;
};
unordered_map<int, int> Solution::dp_;


// Time:  O(nlogn)
// Space: O(n)
class Solution2 {
public:
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> arr;
        for (int i = lo; i <= hi; ++i) {
            arr.emplace_back(power_value(i), i);
        }
        sort(begin(arr), end(arr));
        return arr[k - 1].second;
    }

private:
    int power_value(int x) {
        int y = x;
        if (!Solution2::dp_.count(y)) {
            int result = 0;
            while (x > 1) {
                ++result;
                if (x & 1) {
                    x = 3 * x + 1;
                } else {
                    x >>= 1;
                }
                if (Solution2::dp_.count(x)) {
                    result += Solution2::dp_[x];
                    break;
                }
            }
            Solution2::dp_[y] = result;
        }
        return Solution2::dp_[y];
    }
    
    static unordered_map<int, int> dp_;
};
unordered_map<int, int> Solution2::dp_;