class Solution {
public:
    string reorganizeString(string s) {
        int hash[26]={0};
        //Count number of characters 
        for(int i=0;i<s.length();i++)
        {
            hash[s[i]-'a']++;
        }
        //Find most occurent character
        char most; 
        int freq=INT_MIN;
        for(int i=0;i<26;i++)
        {
            if(hash[i]>freq)
            {
                freq=hash[i];
                most=('a'+i);
            }
        }
        //Place alternatively 
        int index=0;
        while(freq>0&&index<s.size())
        {
            s[index]=most;
            freq--;
            index+=2;
        }
        if(freq!=0)return "";
        hash[most-'a']=0;
        //Place rest characters 

        for(int i=0;i<26;i++)
            {
                while(hash[i]>0)
                {
                    index=index>=s.size()?1:index;
                    s[index]=i+'a';
                    hash[i]--;
                    index+=2;
                }
            }
        return s;
    }
};