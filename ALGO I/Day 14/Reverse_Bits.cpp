class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string s;
        while(n!=0)
        {
            s+=to_string(n%2);
            n/=2;
        }
        
        string temp(32-s.size(),0);
        s+=temp;
        //cout<<s<<endl;
        uint32_t r=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]=='1')
                r+=pow(2,s.size()-i-1);;
 
        }
        
        return r;
    }
};
