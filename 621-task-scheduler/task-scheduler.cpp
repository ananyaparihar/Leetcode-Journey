
class Solution {
public:
    int leastInterval(vector<char>& a, int n) {
        unordered_map<char, int> freq;
        unordered_map<char, int> free;

        for (int i = 0; i < a.size(); i++) {
            freq[a[i]]++;
            free[a[i]] = 1;
        }

        priority_queue<pair<int, char>> pq;

        for (auto i : freq) {
            pq.push({i.second, i.first});
        }

        int seat = 1;

        while (!pq.empty()) {
            vector<pair<int, char>> pulled;
            bool executed = false;
            int sz = pq.size();

            for (int i = 0; i < sz; i++) {
                pair<int, char> p = pq.top();
                pq.pop();

                int fr = p.first;
                char child = p.second;

                if (free[child] <= seat) {
                    executed = true;

                    if (fr > 1) {
                        free[child] = seat + n + 1;
                        pulled.push_back({fr - 1, child});
                    }

                    break;
                } else {
                    pulled.push_back(p);
                }
            }

            for (auto p : pulled) {
                pq.push(p);
            }

            seat++;
        }

        return seat - 1;
    }
};
