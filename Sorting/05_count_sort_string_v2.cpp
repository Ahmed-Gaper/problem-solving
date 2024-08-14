#include<bits/stdc++.h>
using namespace std;
void MY_countSort(vector<string> &names) {
    int size=names.size();
    vector<vector<string>>letters_to_integers(26);
    for(int i=0;i<size;i++)
    {
        int ASCII=names[i][0]-'a';
        letters_to_integers[ASCII].push_back(names[i]);
        int size_col=letters_to_integers[ASCII].size();

        for(int j=size_col-1;j>0;j--)
        {

           if(letters_to_integers[ASCII][j][1]<letters_to_integers[ASCII][j-1][1])
           {
            swap(letters_to_integers[ASCII][j],letters_to_integers[ASCII][j-1]);
           }
        }
    }

    int idx=0;
    for(int i=0;i<26;i++)
    {
        if(!letters_to_integers[i].empty())
        {
            for(int j=0;j<letters_to_integers[i].size();j++)
            {
               names[idx]=letters_to_integers[i][j];
               idx++;
            }
        }
    }

	}

//////////////////////////////////////////////////////////////////////////////////////////

// This is the exact previous approach with minor change
// Previously, the first letter was the key: value from a-z, 26 letters
// Now we have 2 letters. Total combinations then is 26*26 possible cases
// If this hard to understand, imagine the values are only 0-9 per digit
// So 2 digits number will 10x10 cases (from 0 to 99)
// The id function convert 2 letters to an index in the range [0, 26*26-1]

const int LETTERS_SZ = 26;

// Convert a string to an index in range [0 to 26*26-1]
int id(const string &str) {
	assert(str.size() >= 2);
	int f = str[0] - 'a';
	int s = str[1] - 'a';

	return f * LETTERS_SZ + s;
}

void countSort(vector<string> &array) {
	int size = array.size();
	int range = LETTERS_SZ * LETTERS_SZ;
	vector<vector<string>> letter_to_strings(range);

	for (int i = 0; i < size; ++i)
		letter_to_strings[id(array[i])].push_back(array[i]);

	int idx = 0;
	for (int letter = 0; letter < range; ++letter) {
		for (int str_idx = 0; str_idx < (int) letter_to_strings[letter].size(); ++str_idx, ++idx)
			array[idx] = letter_to_strings[letter][str_idx];
	}
}
int main()
{
    vector<string>q({"axz","axa","zzz","abc","abe"});
    MY_countSort(q);
    for(int i=0;i<q.size();i++)
    {
        cout << q[i] << " ";
    }
    return 0;
}