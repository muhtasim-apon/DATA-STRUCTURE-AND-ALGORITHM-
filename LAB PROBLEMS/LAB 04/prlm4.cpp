#include<bits/stdc++.h>
using namespace std;
vector<long long>mergealgo(vector<long long>A,int i,vector<long long>&B,int j)
{
    if(i >= A.size()) return vector<long long>(B.begin() + j, B.end());
    if (j >= B.size()) return vector<long long>(A.begin() + i, A.end());
    if(A[i]<=B[j])
    {
        vector<long long>merged=mergealgo(A,i+1,B,j);
        merged.insert(merged.begin(),A[i]);
        return merged;
    }
    else
    {
        vector<long long>merged=mergealgo(A,i,B,j+1);
        merged.insert(merged.begin(),B[j]);
        return merged;
    }
}
    int main()
    {
        cout<<"Enter size of First Array:\n";
        int n,m;
        cin>>n;
        vector<long long>A(n);
        for(int i=0;i<n;i++)cin>>A[i];
        cout<<"\n";
        cout<<"Enter size of Second Array:\n";
        cin>>m;
        vector<long long>B(m);
        for(int i=0;i<m;i++)cin>>B[i];
        cout<<"\n";
        cout<<"Merged Array:\n";
        vector<long long>mergedarray=mergealgo(A,0,B,0);
        for(int i=0;i<mergedarray.size();i++)
        {
            cout<<mergedarray[i]<<" ";
        }
        cout<<"\n";

    }