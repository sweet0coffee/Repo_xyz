#include <iostream>
#include <set>
#include <algorithm>
#include <climits>

using namespace std;

class DynamicMinDiff {
    multiset<int> s;
    int min_diff = INT_MAX;

public:
    void push(int x) {

        auto it = s.insert(x);

        auto next_it = next(it);
        if (next_it != s.end()) {
            min_diff = min(min_diff, abs(*next_it - x));
        }

        if (it != s.begin()) {
            auto prev_it = prev(it);
            min_diff = min(min_diff, abs(*prev_it - x));
        }
    }

    int getMinDiff() {
        return (s.size() < 2) ? 0 : min_diff;
    }
};

int main() {
    DynamicMinDiff solver;

    int numbers[] = {15, 1, 9, 25, 10};

    cout << "Processing numbers: ";
    for (int n : numbers) {
        cout << n << " ";
    }
    cout << "\n\n";

    for (int n : numbers) {
        solver.push(n);
        cout << "Inserted " << n << " | Current Min Diff: " << solver.getMinDiff() << endl;
    }

    return 0;
}
