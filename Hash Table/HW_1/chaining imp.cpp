#include<bits/stdc++.h>
using namespace std;

int string_hashing(string name,int limit)
{
    long long Limit=limit;
    long long sum=0;
    for(int i=0;i<name.size();i++)
    {
        sum=sum*26+name[i]-'a';
    }
    return sum%Limit;
}
struct phone
{
    const static int limit=2222222222;
    string name;
    string number;
    
   int hash_code()
   {
    return string_hashing(name,limit);
   }

   phone(string _name,string _data)
   {
    name=_name;
    number=_data;
   }

   void print()
   {
    cout << "The name : " << name << "||" << "The phone : " << number << endl;
   }
};

class phone_hashTable
{
    private :

    int table_size;
    vector<vector<phone>>table;

    public :

    phone_hashTable(int size)
    {
        table_size=size;
        table.resize(size);
    }

    void put(phone object)
    {
        int idx = object.hash_code() % table_size;
        for(int i=0;i<table[idx].size();i++)
        {
            if(table[idx][i].name==object.name)
            table[idx][i]=object;
        }

        table[idx].push_back(object);
    }

    bool remove(phone object)
    {
        int idx=object.hash_code() % table_size;
        for(int i=0;i<table[idx].size();i++)
        {
            if(table[idx][i].name==object.name)
            {
                swap(table[idx][i],table[idx].back());
                return true;		
            }
            
        }
        return false;
    }

    void print_all()
    {
        for(int i=0;i<table_size;i++)
        {
            if(table[i].size()==0)
            continue;

            cout << "Hash : " << i << endl;
            for(int j=0;j<table[i].size();j++)
            {
                table[i][j].print();
            }
        }
    }

};
int main()
{
    phone_hashTable f(3);

    f.put(phone("mostafa", "604-401-120"));
	f.put(phone("mostafa", "604-401-777"));	// update
	f.put(phone("ali", "604-401-343"));
	f.put(phone("ziad", "604-401-17"));
	f.put(phone("hany", "604-401-758"));
	f.put(phone("belal", "604-401-550"));
	f.put(phone("john", "604-401-223"));

    f.print_all();
    return 0;
}