// >> https://leetcode.com/problems/sort-an-array/
#include<bits/stdc++.h>
using namespace std;
	vector<int> count_sortV2(vector<int> &array) {
		int size = array.size();
		int mxVal = array[0], mnVal = array[0];

		for (int i = 1; i < size; ++i) {
			if (array[i] > mxVal)
				mxVal = array[i];
			if (array[i] < mnVal)
				mnVal = array[i];
		}
        int new_max = mxVal - mnVal;
		vector<int> count(new_max+1);

		for (int i = 0; i < size; ++i)
			count[array[i] - mnVal] += 1;

		int idx = 0;
		for (int i = 0; i <= new_max; ++i) {
			for (int j = 0; j < count[i]; ++j, ++idx)
				array[idx] = i + mnVal;
		}
		return array;
	}

int main()
{
    vector<int>s{1,-1};
   vector<int>ans=count_sortV2(s);

    for(int i=0;i<ans.size();i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}