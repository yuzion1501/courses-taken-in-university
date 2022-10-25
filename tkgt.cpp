//binary tree
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct point{
    int x;
    int y;
};

float get_distance(point a, point b){
    float temp = pow(1.0*(a.x-b.x),2) + pow(1.0*(a.y-b.y),2);
    temp = sqrt(temp*1.0);
    return temp;
}

// bai 3 trong tai lieu
void coinChange(vector<int>arr,int sum,int cur,vector<vector<int>>&res,vector<int>temp,bool check){
    if (sum<0||cur>=arr.size())
        return;
    if (check==true)
        temp.push_back(arr[cur]);
    if (sum==0){
        res.push_back(temp);
        return;
    }
    coinChange(arr,sum-arr[cur],cur,res,temp,check=true);
    coinChange(arr,sum,++cur,res,temp,check=false);
}

int main(){
    int t;
    cin >> t;
    vector<point>arr;
    stack<point>st;
    while (t--) 
    {
        point temp;
        cin >> temp.x >> temp.y;
        arr.push_back(temp);
    }
    float min = INT_MAX;
    for (int i =0;i < arr.size()-1;i++)
    {
        for (int j = i+1 ; j <arr.size();j++)
        {
            if (get_distance(arr[i],arr[j])<min)
                min = get_distance(arr[i],arr[j]);
        }
    }

    for (int i =0;i < arr.size()-1;i++)
    {
        for (int j = i+1 ; j <arr.size();j++)
        {
            if (get_distance(arr[i],arr[j])==min)
                cout << "(" << arr[i].x << "," << arr[i].y << ")"
                    <<  "(" << arr[j].x << "," << arr[j].y << ")" << endl;
        }
    }
}


//-------------- bai 6 trong tai lieu 
void solve(vector<int>& arr, int cur, int sum, vector<vector<int>>& res, vector<int>temp, bool check,int num) {
    if (check == true) temp.push_back(num);
    if (sum == 0) {
        res.push_back(temp);
        return;
    }
    if (sum < 0 || cur >= arr.size())
        return;
    solve(arr, cur + 1, sum - arr[cur], res, temp, true, arr[cur]);
    solve(arr, cur + 1, sum, res, temp, false, arr[cur]);
}
int main()
{
    vector<vector<int>>res;
    vector<int>temp;
    vector<int>arr= {1,2,3,4,5};
    solve(arr,0,7,res,temp,false,0);
    for (int i =0;i<res.size();i++){
        for (int j =0;j<res[i].size();j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}