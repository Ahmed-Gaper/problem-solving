class Solution {
public:
    int lengthOfLastWord(string s) {
        int check=0,counter=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]==' ' && check==1)
            break;
            else if(s[i]!=' ')
            {
                check=1;
                counter++;
            }
        }
        return counter ;
    }
};