#include <iostream>
#include <vector>

using namespace std;

int base[10];
int f[10][10];
int g[10][10];

void init()
{
    base[0] = 1;
    for(int i = 1 ; i <= 9 ; i++) base[i] = base[i-1]*10;

    //f[i][j] 表示 i 位数字所含有的数字 j 的个数（包含前导零）  0 ~ 999...99
    for(int i = 0 ; i <= 9 ; i++) f[1][i] = 1;
    for(int i = 2 ; i <= 9 ; i++)
        for(int j = 0 ; j <= 9 ; j++)
            /*
                例如 0 ~ 9 添加一位数 00 ~ x9
                    x 从 0 ~ 9 共有 10 种情况, 即 f[i-1][j] * 10
                    当 x = k 时，k0 ~ k9 10 种情况, 故需要加上 10 ^ 1
            */
            f[i][j] = f[i-1][j] * 10 + base[i-1]; 

    //g[i][j] 表示 i 位数字所含有的数字 j 的个数（不包含前导零）    1 ~ 999...99
    for(int i = 1 ; i <= 9 ; i++) g[1][i] = 1;//循环从1开始
    for(int i = 2 ; i <= 9 ; i++) {
        /* 
            例如 1 ~ 99 添加一位=> 1 ~ x99
                当选择 x 从 1 ~ 9 有9种情况，x00 ~ x99 中的后两位是有前导零的2位数, 即 f[2][0]
                当选择 x 为 0 （因为从 1 开始，没有前导 0）, 那么 1 ~ 099 中 k 的个数，依然还是 g[i - 1][j]
        */
        g[i][0] = g[i-1][0] + f[i-1][0]*9;  
        for(int j = 1 ; j <= 9 ; j++)
            /*
                例如 1 ~ 99 添加一位=> 1 ~ x99
                    当选择 x 从 1 ~ 9 有9种情况，x00 ~ x99 中的后两位是有前导零的2位数, 即 f[2][0]
                    当选择 x 为 0 （因为从 1 开始，没有前导 0）, 那么 1 ~ 099 中 k 的个数，依然还是 g[i - 1][j]
                    
                    当选择的 x 恰好为待统计的数 k 时, 还需加上 k00 ~ k99, 即补上 base[i-1]
            */
            g[i][j] = g[i-1][j] + f[i-1][j]*9 + base[i-1];
    }
}

vector<int> dp(int n)
{
    vector<int> ans(10,0); //记录0 ~ 9个数
    if(n <= 0) return ans; //边界条件

    vector<int> nums;
    while(n) nums.push_back(n % 10), n /= 10;

    vector<int> last(10,0); //记录前缀中各个数字个数

    //统计1 - 99……9(n-1个9)里面各个数字有多少个 例如 1 ~ 3075，需要先统计 1 ~ 999 中 i 的数量
    for(int i = 0 ; i <= 9 ; i++) ans[i] = g[nums.size() - 1][i];
    
    //统计大于10……0(n-1个0) 的树里各个数字有多少个 （1000 ~ 3075）
    for(int i = nums.size() - 1 ; i >= 0 ; i--) {
        //循环变量i可以表示剩下的数字有多少个
        int x = nums[i];
        
        for(int j = (i == nums.size() - 1) ; j < x ; j++) { //第一次循环不能有0  !!! j = x为右分支！！！ ！！！ 这里是左分支
		
            //前缀部分  kkx000 ~ kkx999
            for(int k = 0 ; k <= 9 ; k++)
                ans[k] += last[k] * base[i];
			
            //当前位置部分 xxk000 ~ xxk999
            ans[j] += base[i];
			
            //后缀部分 xxx000 ~ xxx999
            for(int k = 0 ; k <= 9 ; k++)
                ans[k] += f[i][k];
        }
        //更新前缀计数器
        last[x] ++;

        //统计叶子节点（这个数本身） 最右结点
        if(!i) for(int k = 0 ; k <= 9 ; k++) ans[k] += last[k];
    }
    return ans;
}

vector<int> ask(int a, int b)
{
    auto x = dp(b);
    auto y = dp(a-1);
    
    vector<int> ans;
    for(int i = 0 ; i <= 9 ; i++) ans.push_back(x[i] - y[i]);
    return ans;
}

void print(vector<int> ans)
{
    for(auto x:ans) printf("%d ",x);
    puts("");
}

int main()
{
    init();
    
    int a,b;
    while(cin >> a >> b, a||b) {
        if(a>b) swap(a,b);
        
        auto t = ask(a,b);
        print(t);
    }

    return 0;
}

int check(int n, int k){
    int res = 0;
    
    for(int i = 1; i <= n; i++){
        
        int t = i;
        do{
            if(t % 10 == k) res++;
            t /= 10;
        }while(t);
        
    }
    return res;
}