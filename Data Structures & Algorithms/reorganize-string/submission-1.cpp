class Solution{
    public:
    string reorganizeString(string s)
{
    int hash[26]={0};
    //Count number of occurences of the characters
    for(int i=0;i<s.size();i++)
    {
        hash[s[i]-'a']++;
    }
    //Calcualte the character with the most occurence 
    char most;
    int freq=INT_MIN;
    for(int i=0;i<26;i++)
    {
        if(hash[i]>freq)
        {
            freq=hash[i];
            most=i+'a';
        }
    }
    //Alternatively place the most occuring character
    int index=0;
    while(freq>0&&index<s.size())
    {
        s[index]=most;
        freq--;
        index+=2;
    }
    if(freq!=0)return "";
    //Place other remaining characters after  making the frequencey of the most occuring element 0
    hash[most-'a']=0;
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