#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
#define LL long long 
int Rank[20][MAX];
int arr[100000],cum[100000],lcp[100000];
struct Tuple
{
    int left,right,pos;
};
bool compare(const Tuple &a, const Tuple &b)
{
    return a.left == b.left ? a.right < b.right : a.left < b.left;
}
void counting_sort(Tuple t[] , int n)
{
    int count[MAX+9];
    Tuple temp[n + 9];
    memset(count , 0 , sizeof count);

    for(int i = 0 ;i < n ; i++)
        count[t[i].right + 1]++;

    for(int i = 1 ; i  < MAX ; i++)
        count[i] += count[i-1];

    for(int i = 0 ; i<n ; i++)
    {
        temp[count[t[i].right +1] - 1] = t[i];
        count[t[i].right + 1]--;
    }   

    memset(count , 0 , sizeof count);

    for(int i = 0 ; i < n ; i ++)
        count[t[i].left + 1] ++;

    for(int i = 1 ; i<MAX ; i++)
        count[i] += count[i-1];

    for(int i = n- 1; i>=0 ; i--)
    {
        t[count[temp[i].left + 1] - 1] = temp[i];
        count[temp[i].left + 1]--;
    }
}
void suffix_array(char s[],int n)
{

    for(int i=0;i<n;i++)
        Rank[0][i] = s[i] - 97;

    Tuple t[n+9];


    for(int stp = 1 , cnt = 1 ; (cnt>>1) < n ; cnt<<=1 , stp++)
    {
        for(int i=0;i<n;i++)
        {
            t[i].left = Rank[stp-1][i];
            t[i].right = i+cnt < n ? Rank[stp-1][i + cnt] : -1;
            t[i].pos = i;
        }
        //sort(t,t+n,compare);
        counting_sort(t , n);
        for(int i=0;i<n;i++)
            Rank[stp][t[i].pos] = i > 0 && t[i-1].left == t[i].left && t[i-1].right == t[i].right ? Rank[stp][t[i-1].pos] : i;
    }
    int pos = ceil(log(n)/log(2));
    for(int i = 0;i<n;i++)
        arr[Rank[pos][i]] = i;
}
void lcpArray(char s[],int n)
{
        int k=0,sum = 0;
        vector<int> rank(n,0);
        for(int i=0; i<n; i++) rank[arr[i]]=i;
                lcp[0] = 0;
        for(int i=0; i<n; i++, k?k--:0)
        {
                if(rank[i]==n-1) {k=0; continue;}
                int j=arr[rank[i]+1];
                while(i+k<n && j+k<n && s[i+k]==s[j+k]) k++ ;
                lcp[rank[i] + 1] = k;
        }
}
int main()
{
    char s[100000];
    scanf("%s",s);
    int  n = strlen(s);
    suffix_array(s,n);
    lcpArray(s , n);
    cum[0] = n - arr[0];
    for(int i = 1;i < n;i++){
        cum[i] = cum[i-1] + (n - arr[i] - lcp[i]);
    }
    int q;
    for(int i=0;i<strlen(s);++i) cout << cum[i] << ' '; cout << '\n';
    scanf("%d",&q);
    while(q--)
    {
        int a ;
        scanf("%d",&a);
        int pos ;
        pos = lower_bound(cum , cum + n , a) - cum;
        int i , j;
        for(int j = 0 , i = arr[pos] ; j< a - cum[pos-1] + lcp[pos] ; j++,i++)
            printf("%c",s[i]);
        printf("\n");
    }
    return 0;
}