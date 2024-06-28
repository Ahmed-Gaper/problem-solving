#include<bits/stdc++.h>
using namespace std;

int hash_string(string str,int limit)
{
    long long  sum=0;
    long long n=limit;
    for(int i=0;i<str.size();i++)
    {
        sum = (sum*26 +str[i] - 'a')%n;
    }
    return sum%n;
}
struct Phone_entry
{
    string phone;
    string name;
    int limit =65407;

    Phone_entry(string na,string ph)
    {
        name=na;
        phone=ph;

    }

    int hashing()
    {
        return hash_string(name,limit);
    }

    void print()
    {
        cout << name << " > " << phone << endl;
    }

};

class Phone_hash_table
{
    private :

    vector<Phone_entry*>table;
    int table_size;
    Phone_entry * deleted=new Phone_entry("","");

    public :
    Phone_hash_table(int _size)
    {
        table_size=_size;
        table.resize(table_size);
    }

    bool put(Phone_entry new_phone)
    {
        int idx=new_phone.hashing() % table_size;

        for(int i=0;i<table_size;i++ )
        {
            if(table[idx]==deleted || !table[idx])
            {
                table[idx]=new Phone_entry(new_phone.name,new_phone.phone);
                return true;
            }
            else if(table[idx]->name==new_phone.name)
            {
                table[idx]->phone=new_phone.phone;
                return true;
            }
            idx=(idx+1)%table_size;
        }

        return false;
    }

    bool remove(Phone_entry del_phone)
    {
        int idx=del_phone.hashing()%table_size;

        for(int i=0;i<table_size;i++)
        {
            if(!table[idx])
            return false;

            if(table[idx]!=deleted && table[idx]->name==del_phone.name)
            {
                delete table[idx];
                table[idx]=deleted;
                return true;
            }

            idx=(idx+1)%table_size;
        }
        return false;
        
    }

    bool get(Phone_entry &get_phone)
    {
        int idx=get_phone.hashing()%table_size;

        for(int i=0;i<table_size;i++)
        {
            if(!table[idx] || table[idx]==deleted)
            return false;

            if(table[idx]->name==get_phone.name)
            {
                get_phone.phone=table[idx]->phone;

                return true;
            }

            idx=(idx+1)%table_size;
        }
        return false;
    }

    void print_all() {
		for (int hash = 0; hash < table_size; ++hash) {
			cout << hash << " ";
			if (table[hash] == deleted)
				cout << " X ";
			else if (!table[hash])
				cout << " E ";
			else
				table[hash]->print();
			cout << "\n";
		}
		cout << "******************\n";
	}



};
int main() {

	Phone_hash_table table(11);
	table.put(Phone_entry("mostafa", "604-401-120"));
	table.put(Phone_entry("mostafa", "604-401-777"));
	table.put(Phone_entry("ali", "604-401-343"));
	table.put(Phone_entry("ziad", "604-401-17"));
	table.put(Phone_entry("hany", "604-401-758"));
	table.put(Phone_entry("belal", "604-401-550"));
	table.put(Phone_entry("john", "604-401-223"));

	table.print_all();

	/*
	 0  E
	 1  E
	 2  E
	 3 (john, 604-401-223)
	 4  E
	 5  E
	 6 (mostafa, 604-401-120)
	 7 (hany, 604-401-758)
	 8 (ali, 604-401-343)
	 9 (ziad, 604-401-17)
	 10 (belal, 604-401-550)
	 */

	cout << table.remove(Phone_entry("smith", "")) << "\n"; // 0
	cout << table.remove(Phone_entry("hany", "")) << "\n";  // 1
	cout << table.remove(Phone_entry("john", "")) << "\n";  // 1
	table.print_all();
	/*
	 0  E
	 1  E
	 2  E
	 3  X
	 4  E
	 5  E
	 6 (mostafa, 604-401-120)
	 7  X
	 8 (ali, 604-401-343)
	 9 (ziad, 604-401-17)
	 10 (belal, 604-401-550)
	 */

	Phone_entry e("belal", "");
	if (table.get(e))
		cout << e.phone << "\n";	// 604-401-550

	table.put(Phone_entry("hany", "604-401-555"));
	table.print_all();
	/*
	 0  E
	 1  E
	 2  E
	 3  X
	 4  E
	 5  E
	 6 (mostafa, 604-401-120)
	 7 (hany, 604-401-555)
	 8 (ali, 604-401-343)
	 9 (ziad, 604-401-17)
	 10 (belal, 604-401-550)
	 */
	return 0;
}
