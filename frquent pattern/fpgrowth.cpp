#include<bits/stdc++.h>
//#include<unordered_map>
using namespace std;
int data[3196][37];
void combinationutil(vector<int> arr,int n,int r,int index, int data[],int i,vector<vector<int> > &b)
{
    vector<int> a;
    if(index==r){
        a.clear();
        for (int j = 0; j < r; j++)
            a.push_back(data[j]);
        b.push_back(a);
        return;
    }
    if (i >= n)
        return;

    data[index] = arr[i];
    combinationutil(arr, n, r, index + 1, data, i + 1,b);
    combinationutil(arr, n, r, index, data, i + 1,b);
}
vector<vector<int> > powerset(vector<int> a,int r)
{
    int data[r];
    int n=a.size();
    vector<vector<int> > temp;
    combinationutil(a,n,r,0,data,0,temp);
    return temp;
}
int check(vector<int> temp)
{
    int index=0;
    int c=0;
    for(int k=0;k<3196;k++)
    {
        index=0;
        for(int i=0;i<37;i++)
        {
            if(data[k][i]==temp[index])
            {
                index++;
                if(index-1==temp.size()-1)
                {
                    c++;
                    break;
                }
            }
        }
    }
    return c;
}
void gennewstore(vector<int> &v)
{
     vector<int>::iterator ip;
        sort(v.begin(),v.begin()+v.size());
         ip=unique(v.begin(),v.begin()+v.size());
         v.resize(distance(v.begin(),ip));
         /*for(int z=0;z<v.size();z++)
                {
                    cout<<" "<<v[z];
                }*/
}
int main()
{
    int num;
    cout<<"enter number of transactions"<<endl;
    cin>>num;
    for(int i=0;i<num;i++)
    {

    }
    /*int a,arr[100];
    int minsup=2500,minconf=0.6;
    int freq,minisoda=0;
    for(int i=0;i<100;i++)
    {
        arr[i]=0;
    }
    FILE *fp;
    fp=fopen("chess.dat","r");

    int x=0,y=0;
    while(fscanf(fp,"%d ",&a)==1)
    {
        arr[a]++;
        data[x][y++]=a;
        if(y==37)
        {
            x++;
            y=0;
        }
    }
    //unordered_map<vector<int>, int> gama;
    vector<int> store;
    vector<vector<int> > doublestore;
    cout<<"1- frequent itemset"<<endl;
    for(int i=1;i<100;i++)
    {
        if(arr[i]<minsup)
        {
            arr[i]=0;
        }
        else
        {
            store.push_back(i);
            cout<<i<<" "<<arr[i]<<endl;
            vector<int> temp;
            temp.push_back(i);
            //gama[temp]=arr[i];
        }
    }

    for(int k=2;k<store.size();k++)
    {
        minisoda=0;
        doublestore.clear();
        doublestore=powerset(store,k);
       cout<<"*** "<<k<<"-frequent itemset***"<<endl;
        store.clear();
        for(int x=0;x<doublestore.size();x++)
        {
            freq=check(doublestore[x]);

            if(freq>minsup)
            {
                for(int y=0;y<doublestore[0].size();y++)
                {
                    cout<<" "<<doublestore[x][y];
                    store.push_back(doublestore[x][y]);
                }
                cout<<" "<<freq<<endl;
                //gama[doublestore[x]]=freq;
            }

        }
        //cout<<"after union of all elements"<<endl;

             gennewstore(store);

          /*  for(int z=0;z<store.size();z++)
            {
                cout<<" "<<store[z];

        //    }
    }*/
    return 0;
}
