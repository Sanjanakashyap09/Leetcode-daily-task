class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,unordered_set <int>>mp;

        for(int i=0; i<reservedSeats.size(); i++){
            int row= reservedSeats[i][0];
            int seatNum = reservedSeats[i][1];
            mp[row].insert(seatNum);
        }
        int totalGroups = 0;

        // Step 2: Convert map into vector of pairs for normal loop
        vector<pair<int, unordered_set<int>>> rows;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            rows.push_back({it->first, it->second});
        }
        for (int i = 0; i < rows.size(); i++) {
            int row = rows[i].first;
            unordered_set<int> reserved = rows[i].second;
            int groupsInRow = 0;

            bool blockA = !(reserved.count(2) || reserved.count(3) || reserved.count(4) || reserved.count(5));
            bool blockB = !(reserved.count(4) || reserved.count(5) || reserved.count(6) || reserved.count(7));
            bool blockC = !(reserved.count(6) || reserved.count(7) || reserved.count(8) || reserved.count(9));

            if (blockA && blockC) groupsInRow = 2;
            else if (blockA || blockC || blockB) groupsInRow = 1;

            totalGroups += groupsInRow;
        }

        // Step 4: Rows without reservations
        totalGroups += (n - mp.size()) * 2;

        return totalGroups;
    }
};
