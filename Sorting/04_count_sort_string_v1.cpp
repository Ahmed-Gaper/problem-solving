#include<bits/stdc++.h>
using namespace std;
void countSort(vector<string> &names) {
	int size = names.size();
	vector<vector<string>> letter_to_strings(26);

	for (int i = 0; i < size; ++i)
		letter_to_strings[names[i][0] - 'a'].push_back(names[i]);

	int idx = 0;
	for (int letter = 0; letter < 26; ++letter) {
		for (int i = 0; i < (int) letter_to_strings[letter].size(); ++i, ++idx)
			names[idx] = letter_to_strings[letter][i];
	}
}

void MY_countSort(vector<string> &names)
{
    for(int i=0;i<28;i++)
    {
        for(string name : names)
        {
            if(name[0]-'a'==i)
            cout << name << " ";
        }
    }
}
int main()
{
    vector<string>q({"ziad","belal","adam","baheir","ali"});
    countSort(q);
    for(int i=0;i<q.size();i++)
    {
        cout << q[i] << " ";
    }
    return 0;
}