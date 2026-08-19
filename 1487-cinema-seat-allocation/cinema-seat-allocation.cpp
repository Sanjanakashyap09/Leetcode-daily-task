class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp; // row -> bitmask of reserved seats

        // Step 1: Fill bitmask
        for (int i = 0; i < reservedSeats.size(); i++) {
            int row = reservedSeats[i][0];
            int seat = reservedSeats[i][1];
            mp[row] |= (1 << seat); // mark reserved seat
        }

        int totalGroups = 0;

        // Step 2: Check each reserved row
        for (auto it = mp.begin(); it != mp.end(); it++) {
            int mask = it->second;
            int groupsInRow = 0;

            bool blockA = !(mask & ((1<<2)|(1<<3)|(1<<4)|(1<<5)));
            bool blockB = !(mask & ((1<<4)|(1<<5)|(1<<6)|(1<<7)));
            bool blockC = !(mask & ((1<<6)|(1<<7)|(1<<8)|(1<<9)));

            if (blockA && blockC) groupsInRow = 2;
            else if (blockA || blockB || blockC) groupsInRow = 1;

            totalGroups += groupsInRow;
        }

        // Step 3: Rows without reservations
        totalGroups += (n - mp.size()) * 2;

        return totalGroups;
    }
};
