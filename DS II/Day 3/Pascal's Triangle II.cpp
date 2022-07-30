 class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> temp;
        vector<int> curr;
        temp.push_back( 1 );
        curr.push_back( 1 );
        for ( int i = 1; i <= rowIndex; i++ )
        {
            curr.resize( i + 1, 1 );
            for ( int j = 1; j < i; j++ )
            {
                curr[j] = temp[j - 1] + temp[j];
            }
            temp = curr;
        }
        return curr;
    }
};
