#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int> > transactions;
    vector<int> temp;
    temp.push_back(1);
    temp.push_back(2);
    temp.push_back(5);
    transactions.push_back(temp);
    temp.clear();
    temp.push_back(2);
    temp.push_back(4);
    transactions.push_back(temp);
    temp.clear();
    temp.push_back(2);
    temp.push_back(3);
    transactions.push_back(temp);
    temp.clear();
    temp.push_back(1);
    temp.push_back(2);
    temp.push_back(4);
    transactions.push_back(temp);
    temp.clear();
    temp.push_back(1);
    temp.push_back(3);
    transactions.push_back(temp);
    temp.clear();
    temp.push_back(2);
    temp.push_back(3);
    transactions.push_back(temp);
    temp.clear();
    temp.push_back(1);
    temp.push_back(3);
    transactions.push_back(temp);
    temp.clear();
    temp.push_back(1);
    temp.push_back(2);
    temp.push_back(3);
    temp.push_back(5);
    transactions.push_back(temp);
    temp.clear();
    temp.push_back(1);
    temp.push_back(2);
    temp.push_back(3);
    transactions.push_back(temp);

    int minsup=2;
    struct node
    {
        string label;
        struct node* child[5];
        int count;
        struct node* parent;
        struct node* neighbour;
    };

    unordered_map<int, int> items;
    int freq[6];
    for(int k=0;k<=5;k++)freq[k]=0;
    for(int i=0;i<transactions.size();i++)
    {
        for(int j=0;j<transactions[i].size();j++)
        {
           freq[transactions[i][j]]++;
        }
    }

    for(int j=1;j<6;j++)
    {
        cout<<j<<" "<<freq[j]<<endl;
        items[j]=freq[j];
    }
    for(auto x:items)
    {
        cout<<x.first<<" "<<x.second<<endl;
    }
    return 0;
}
