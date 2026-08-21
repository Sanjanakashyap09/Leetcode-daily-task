class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        auto count= [&](long long mid){
            long long total =0;

            int n = coins.size();

            //check all subsets of each coins
            for(int mask=1; mask<(1<<n); mask++){  

            //now chcek the lcm of each subset part, if it's found high from mid then skip 
            long long lcm=1;
            bool valid=true;
            for(int i=0; i<n; i++){
                if(mask & (1<<i)){
                    lcm= lcm*coins[i]/gcd(lcm, (long long)coins[i]);
                    if(lcm>mid){
                        valid= false; break;
                    }
                }

            }
            if(!valid) continue;
            int bits= __builtin_popcount(mask);
            if(bits % 2==1)total += mid/lcm;
            else total -= mid/lcm;
                
            }
            return total;
        };
        long long low= 1, high= 1e18, ans=-1;
        while(low<=high){
            long long mid=low+ (high-low)/2;
            if(count(mid)>=k){
                ans= mid;
                high= mid-1;
            }else{
                low= mid+1;
            }
        } 
        return ans;       
    }
};