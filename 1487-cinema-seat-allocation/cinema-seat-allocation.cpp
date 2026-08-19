class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> mp;

        // Step 1: Fill map directly
        for (int i = 0; i < reservedSeats.size(); i++) {
            mp[reservedSeats[i][0]].insert(reservedSeats[i][1]);
        }

        int totalGroups = 0;

        // Step 2: Process each reserved row directly (no vector copy)
        for (auto it = mp.begin(); it != mp.end(); it++) {
            unordered_set<int>& reserved = it->second;  // reference, no copy
            int groupsInRow = 0;

            // Step 3: Check blocks
            bool blockA = !(reserved.count(2) || reserved.count(3) || reserved.count(4) || reserved.count(5));
            bool blockB = !(reserved.count(4) || reserved.count(5) || reserved.count(6) || reserved.count(7));
            bool blockC = !(reserved.count(6) || reserved.count(7) || reserved.count(8) || reserved.count(9));

            if (blockA && blockC) groupsInRow = 2;
            else if (blockA || blockB || blockC) groupsInRow = 1;

            totalGroups += groupsInRow;
        }

        // Step 4: Rows without reservations
        totalGroups += (n - mp.size()) * 2;

        return totalGroups;
    }
};
