class Solution {
public:
    int n;
    char mid;
    string isExist(string curr,vector<int>freq,string &target){
        for(int i=25;i>=0;i--){
            if(freq[i]==0) continue;
            while(freq[i]){
                curr.push_back(i+'a');
                freq[i]--;
            }
        }
        string right=curr;
        reverse(right.begin(),right.end());
        if(mid!='#') curr.push_back(mid);
        curr+=right;
        if(curr>target) return curr;
        return "";
     }
    string lexPalindromicPermutation(string s, string target) {
        this->n=s.size();
        this->mid='#';
        if(n==1){
            if(s>target) return s;
            return  "";
        }
        vector<int>freq(26,0);
        for(auto it:s) freq[it-'a']++;
        int oddCnt=0;
        for(int i=0;i<26;i++){
            if(freq[i] & 1){
                oddCnt++;
                mid=i+'a';
                freq[i]--;
            }
            freq[i]/=2;
        }
        if(oddCnt>=2) return "";
        n/=2;
        string ans="";
        string curr="";
        for(int i=0;i<n;i++){
            for(int j=0;j<26;j++){
                if(freq[j]==0) continue;
                char ch=j+'a';
                curr.push_back(ch);
                freq[j]--;
                string res=isExist(curr,freq,target);
                if(res!=""){
                    if(ans=="") ans=res;
                    else ans=min(ans,res);
                    break;
                }
                curr.pop_back();
                freq[j]++;
            }
        }
        return ans;
    }
};