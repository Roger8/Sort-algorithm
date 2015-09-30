//关于数组的面试题
// http://blog.csdn.net/hackbuteer1/article/details/8035261
// 1、快速找出一个数组中的最大数、第二大数。
     // 思路：如果当前元素大于最大数 max，则让第二大数等于原来的最大数 max，再把当前元素的值赋给 max。如果当前的元素大于等于第二大数secondMax的值而小于最大数max的值，则要把当前元素的值赋给 secondMax。
// [cpp] view plaincopy
void GetSecondMaxNumber(int *arr , int n)  
{  
    int i , max , second_max;  
    max = arr[0];  
    second_max = 0x80000000;  
    for(i = 1 ; i < n ; ++i)  
    {  
        if(arr[i] > max)  
        {  
            second_max = max;  
            max = arr[i];  
        }  
        else  
        {  
            if(arr[i] > second_max)  
                second_max = arr[i];  
        }  
    }  
    cout<<max<<"  "<<second_max<<endl;  
}  
// 2、试着用最小的比较次数去寻找数组中的最大值和最小值。
// 解法一：
// 扫描一次数组找出最大值；再扫描一次数组找出最小值。
// 比较次数2N-2
// 转载请标明出处，原文地址：http://blog.csdn.net/hackbuteer1/article/details/8035261
// 解法二：
// 将数组中相邻的两个数分在一组， 每次比较两个相邻的数，将较大值交换至这两个数的左边，较小值放于右边。
// 对大者组扫描一次找出最大值，对小者组扫描一次找出最小值。
// 比较1.5N-2次，但需要改变数组结构
 
// 解法三：
// 每次比较相邻两个数，较大者与MAX比较，较小者与MIN比较，找出最大值和最小值。
// 方法如下：先将一对元素互相进行比较，然后把最小值跟当前最小值进行比较，把最大值跟当前最大值进行比较。因此每两个元素需要3次比较。如果n为奇数，那么比较的次数是3*(n/2)次比较。如果n为偶数，那么比较的次数是3n/2-2次比较。因此，不管是n是奇数还是偶数，比较的次数至多是3*(n/2)，具体的代码如下：
// [cpp] view plaincopy
void GetMaxAndMin(int *arr , int n , int &max , int &min)  
{  
    int i = 0 ;  
    if(n & 1)     // 奇数  
    {  
        max = min = arr[i++];  
    }  
    else  
    {  
        if(arr[0] > arr[1])  
        {  
            max = arr[0];  
            min = arr[1];  
        }  
        else  
        {  
            max = arr[1];  
            min = arr[0];  
        }  
        i += 2;  
    }  
      
    for( ; i < n ; i += 2)  
    {  
        if(arr[i] > arr[i+1])  
        {  
            if(arr[i] > max)  
                max = arr[i];  
            if(arr[i+1] < min)  
                min = arr[i+1];  
        }  
        else  
        {  
            if(arr[i+1] > max)  
                max = arr[i+1];  
            if(arr[i] < min)  
                min = arr[i];  
        }  
    }  
}  
// 3、重排问题
// 给定含有n个元素的整型数组a，其中包括0元素和非0元素，对数组进行排序，要求：
// 1、排序后所有0元素在前，所有非零元素在后，且非零元素排序前后相对位置不变
// 2、不能使用额外存储空间
// 例子如下
// 输入 0、3、0、2、1、0、0
// 输出 0、0、0、0、3、2、1
// 分析
// 此排序非传统意义上的排序，因为它要求排序前后非0元素的相对位置不变，或许叫做整理会更恰当一些。我们可以从后向前遍历整个数组，遇到某个位置i上的元素是非0元素时，如果arr[k]为0，则将arr[i]赋值给arr[k]，arr[i]赋值为0。实际上i是非0元素的下标，而k是0元素的下标。
// [cpp] view plaincopy
void Arrange(int *arr , int n)  
{  
    int i , k = n-1;  
    for(i = n-1 ; i >=0 ; --i)  
    {  
        if(arr[i] != 0)  
        {  
            if(arr[k] == 0)  
            {  
                arr[k] = arr[i];  
                arr[i] = 0;  
            }  
            --k;  
        }  
    }  
}  
// 4、找出绝对值最小的元素

// 给定一个有序整数序列（非递减序），可能包含负数，找出其中绝对值最小的元素，比如给定序列 -5、-3、-1、2、8 则返回1。
// 分析：由于给定序列是有序的，而这又是搜索问题，所以首先想到二分搜索法，只不过这个二分法比普通的二分法稍微麻烦点，可以分为下面几种情况
    // 如果给定的序列中所有的数都是正数，那么数组的第一个元素即是结果。
    // 如果给定的序列中所有的数都是负数，那么数组的最后一个元素即是结果。
    // 如果给定的序列中既有正数又有负数，那么绝对值的最小值一定出现在正数和负数的分界处。
// 为什么？因为对于负数序列来说，右侧的数字比左侧的数字绝对值小，如上面的-5、-3、-1，而对于整整数来说，左边的数字绝对值小，比如上面的2、8，将这个思想用于二分搜索，可先判断中间元素和两侧元素的符号，然后根据符号决定搜索区间，逐步缩小搜索区间，直到只剩下两个元素。
// 单独设置一个函数用来判断两个整数的符号是否相同
// [cpp] view plaincopy
bool SameSign(int m , int n)  
{  
    if((m>>31) == (n>>31))  
        return true;  
    else  
        return false;  
}  
  
// 找出一个非递减序整数序列中绝对值最小的数  
int MiniNumAbsoluteValue(int *arr , int n)  
{  
    if(n == 1)  
        return arr[0];  
    if( SameSign(arr[0] , arr[n-1]) )  
        return arr[0] >= 0 ? arr[0] : abs(arr[n-1]);  
  
    // 二分搜索  
    int mid , low = 0 , high = n - 1;  
    while(low < high)  
    {  
        if(low + 1 == high)  
            return abs(arr[low]) < abs(arr[high]) ? abs(arr[low]) : abs(arr[high]);  
        mid = (low + high)>>1;  
        if( SameSign(arr[low] , arr[mid]) )  
        {  
            low = mid ;     // 有可能分界点就在mid处  
            continue;  
        }  
        if( SameSign(arr[high] , arr[mid]) )  
        {  
            high = mid;  
            continue;  
        }  
    }  
    return abs(arr[low]);  
}  
// 5、一道经典的额递归题目
// 函数 int func(int i ,int N);
// 其中i <= N，功能输出i递增到N再递减到i的整数，每行输出一个数。比如func(1,5)就是
// 1
// 2
// 3
// 4
// 5
// 4
// 3
// 2
// 1
// 要求：
// 1、只能有1个语句，即一个分号
// 2、不能使用do while until goto for if关键字，不能使用?:和逗号运算符
// 3、唯一能使用的库函数为printf 
// [cpp] view plaincopy
// <span style="font-family:Verdana; font-size:14px">int func(int i , int n)  
// {  
    // return (i==n && printf("%d\n",i)) || (printf("%d\n",i) && func(i+1,n) && printf("%d\n",i));  
// }</span>  
// 6、从长度为n的数组（元素互不相同）中任意选择m个数的所有组合。
// DFS
// [cpp] view plaincopy
/**   
** author :hackbuteer 
** date   :2012-10-01    
**/  
#include<iostream>  
#include<vector>  
using namespace std;  
  
int arr[] = {1,2,3,4,5,6,7,8,9,10};  
int len = 10 , m = 3;  
  
void dfs(int num , vector<int>& vec , int curnum , int id)  
{  
    int i ;  
    if(curnum == num)  
    {  
        static int k = 1 ;  
        cout<<k++<<": ";  
        for( i = 0; i < vec.size() ; ++i)  
            cout<<vec[i]<<" ";  
        cout<<endl;  
        return;  
    }  
  
    for( i = id; i < len; ++i)  
    {  
        vec.push_back(arr[i]);  
        dfs(num , vec , curnum + 1 , i + 1);  
        vec.pop_back();  
    }  
}  
  
int main(void)  
{  
    vector<int>vec;  
    dfs(m , vec , 0 , 0);  
    return 0;  
}  
[cpp] view plaincopy
int arr[] = {1,2,3,4,5,8,5,8,9,10};  
int len = 10 , m = 3;  
  
void dfs(int index , int num , vector<int> &vec)  
{  
    int i ;  
    if(index == len+1)  
        return ;  
    if(num == 0)  
    {  
        static int k = 1 ;  
        cout<<k++<<": ";  
        for( i = 0; i < vec.size() ; ++i)  
            cout<<vec[i]<<" ";  
        cout<<endl;  
        return;  
    }  
    vec.push_back(arr[index]);    // 选取第index个元素  
    dfs(index + 1 , num - 1 , vec);  
    vec.pop_back();               // 不选取第index个元素  
    dfs(index + 1 , num , vec);  
}  
  
int main(void)  
{  
    vector<int>vec;  
    dfs(0 , m , vec);  
    return 0;  
}  
// 7、从长度为n的数组（元素有可能相同）中任意选择m个数的所有组合。
// 先对数组进行排序，然后设置一个标记pre，记录前一个选择的数字，然后进行比较。
// [cpp] view plaincopy
/**   
** author :hackbuteer 
** date   :2012-10-01    
**/  
#include<iostream>  
#include<vector>  
#include<algorithm>  
using namespace std;  
  
int arr[] = {1,2,3,4,5,8,5,8,9,10};  
int len = 10 , m = 3;  
  
void dfs(int num , vector<int>& vec , int curnum , int id)  
{  
    int i , pre = -1;  
    if(curnum == num)  
    {  
        static int k = 1 ;  
        cout<<k++<<": ";  
        for( i = 0; i < vec.size() ; ++i)  
            cout<<vec[i]<<" ";  
        cout<<endl;  
        return;  
    }  
  
    for( i = id; i < len; ++i)  
    {  
        if(pre == -1 || arr[i] > pre)  
        {  
            vec.push_back(arr[i]);  
            dfs(num , vec , curnum + 1 , i + 1);  
            vec.pop_back();  
            pre = arr[i];  
        }  
    }  
}  
  
int main(void)  
{  
    vector<int>vec;  
    sort(arr , arr + len );  
    dfs(m , vec , 0 , 0);  
    return 0;  
}  
// 8、三色旗排序问题
// 一个字符串Color，其中每个元素值为‘R‘’G’‘B’三者之一，实现把数组中元素重新排列为红、绿、蓝的顺序，所有红色在前，绿色其后，蓝色最后，要如何移动次数才会最少，编写这么一个程序。
// 问题的解法很简单，您可以自己想像一下在移动旗子，从绳子开头进行，遇到红色往前移，遇到绿色留在中间，遇到蓝色往后移。
// 设有三个指针rindex、gindex、bindex，其中gindex来遍历这个数组序列
// 1、gindex指向G的时候，gindex++，
// 2、gindex指向R的时候，与rindex交换，而后gindex++，rindex++，
// 3、gindex指向B的时候，与bindex交换，而后，gindex不动，bindex--。
    // 为什么，第三步，gindex指向B的时候，与bindex交换之后，gindex不动。
    // 因为你最终的目的是为了让R、G、B成为有序排列，试想，如果第三步，gindex与bindex交换之前，万一bindex指向的是R，而gindex交换之后，gindex此刻指向的是R了，此时，gindex能动么？不能动啊，指向的是R，还得与rindex交换。
// [cpp] view plaincopy
// 三色旗排序问题  
// char str[] = "RGRBRB";  
void mysort(char *str , int n)  
{  
    int rindex = 0 , gindex = 0 , bindex = n - 1 ;  
    while(gindex <= bindex)  
    {  
        if(str[gindex] == 'G')  
            ++gindex;  
        else if(str[gindex] == 'R')  
        {  
            swap(str[gindex] , str[rindex]);  
            ++rindex , ++gindex;  
        }  
        else           // str[gindex] == 'B'  
        {  
            swap(str[gindex] , str[bindex]);  
            --bindex;  
            //++gindex;  
        }  
    }  
}  
// 9、一个整型数组，含有N个数，将这N个数分成连续的M段，使得这M段每段的和中的最大值最小，输出最小值。（1<=N<=100000,1<=M<=N,每个数在1到10000之间）   POJ  3273
// 解题思路：不管分成多少段，每种分法和的最大值都在N个数的最大值和N个数的和之间，所求答案也在这之间。

// 我们可以以此为上下界，二分M段和的最大值进行尝试。对每次二分的值，将数组扫描累加。若当前和大于二分的这个值，则段数加一，由此统计出在当前值下，N个数能够分成的最小段数。若这个段数小于或等于M，则上界变为mid-1，并记下当前mid的值。否则，下界变为mid+1。继续二分，直到退出循环。最后记录的low值即为答案。
// [cpp] view plaincopy
#include<iostream>  
#include<cstdio>  
using namespace std;  
  
int m , n , a[100001];  
  
int bsearch(int low , int high)  
{  
    int i , mid , group , sum;  
    while(low <= high)  
    {  
        mid = (low + high)>>1;  
        sum = 0 ,  group = 1;  
        for(i = 0 ; i < n ; ++i)  
        {  
            if(sum + a[i] <= mid)  
                sum += a[i];  
            else  
            {  
                group++;  
                sum = a[i];  
            }  
        }  
        if(group <= m)  
            high = mid - 1 ;  
        else if(group > m)  
            low = mid + 1;  
    }  
    return low;  
}  
  
int main(void)  
{  
    int i , max , sum;  
    while(scanf("%d %d",&n,&m)!=EOF)  
    {  
        max = 0x80000000 , sum = 0;  
        for(i = 0 ; i < n ; ++i)  
        {  
            scanf("%d",&a[i]);  
            sum += a[i];  
            if(a[i] > max)  
                max = a[i];  
        }  
        printf("%d\n",bsearch(max, sum));  
    }  
    return 0;  
}  
// 10、一个int数组，里面数据无任何限制，要求求出所有这样的数a[i]，其左边的数都小于等于它，右边的数都大于等于它。
// 能否只用一个额外数组和少量其它空间实现。
// 分析：最原始的方法是检查每一个数 array[i] ，看是否左边的数都小于等于它，右边的数都大于等于它。这样做的话，要找出所有这样的数，时间复杂度为O(N^2)。
// 其实可以有更简单的方法，我们使用额外数组，比如rightMin[]，来帮我们记录原始数组array[i]右边（包括自己）的最小值。假如原始数组为： array[] = {7, 10, 2, 6, 19, 22, 32}， 那么rightMin[] = {2, 2, 2, 6, 19, 22, 32}. 也就是说，7右边的最小值为2, 2右边的最小值也是2。
// 有了这样一个额外数组，当我们从头开始遍历原始数组时，我们保存一个当前最大值 max， 如果当前最大值刚好等于rightMin[i]， 那么这个最大值一定满足条件，还是刚才的例子。
// 第一个值是7，最大值也是7，因为7 不等于 2， 继续，
// 第二个值是10，最大值变成了10，但是10也不等于2，继续，
// 第三个值是2，最大值是10，但是10也不等于2，继续，
// 第四个值是6，最大值是10，但是10不等于6，继续，
// 第五个值是19，最大值变成了19，而且19也等于当前rightMin[4] = 19, 所以，满足条件。如此继续下去，后面的几个都满足。
// [cpp] view plaincopy
int arr[100] , rightMin[100];  
void smallLarge(int *arr , int *rightMin , int n)  
{  
    int i , leftMax;  
    rightMin[n - 1] = arr[n - 1];  
    for(i = n - 2 ; i >= 0 ; --i)  
    {  
        if(arr[i] < arr[i+1])  
            rightMin[i] = arr[i];  
        else  
            rightMin[i] = rightMin[i + 1];  
    }  
    leftMax = 0x80000000;  
    for(i = 0 ; i < n ; ++i)  
    {  
        if(arr[i] >= leftMax)  
        {  
            leftMax = arr[i];  
            if(leftMax == rightMin[i])  
                printf("%d\n",leftMax);  
        }  
    }  
}  
 // 11、整数的拆分问题
// 如，对于正整数n=6，可以拆分为：
// 6
// 5+1
// 4+2, 4+1+1
// 3+3, 3+2+1, 3+1+1+1
// 2+2+2, 2+2+1+1, 2+1+1+1+1
// 1+1+1+1+1+1+1
// 现在的问题是，对于给定的正整数n，程序输出该整数的拆分种类数(HDOJ  1028)。
// DP思路：
// n = n1 + n2 + n3 + n4 + .... + nk
// 状态表示：将n划分为k个数相加的组合方案数记为 q(n,k)。（相当于将n个苹果放入k个盘子）
// 状态转移：
// (1)若k>n，则盘子数大于苹果数，至少有k-n个空盘子，可以将其拿掉，对组合方案数无影响。
// q(n,k) = q(n,n)
// (2)若k<=n，则盘子数小于等于苹果数，则分为两种情况
// 1.至少有一个盘子空着：q(n,k) = q(n,k-1)
// 2.所有盘子都不空：q(n,k) = q(n-k,k)
// q(n,k) = q(n,k-1) + q(n-k,k)
// 方法一：DP非递归
// [cpp] view plaincopy
int main(void)  
{  
    int n,i,j,dp[121][121];  
    for(i = 1 ; i < 121 ; ++i)  
    {  
        for(j = 1 ; j < 121 ; ++j)  
        {  
            if(i == 1 ||  j == 1)  
                dp[i][j] = 1;  
            else if(i > j)  
                dp[i][j] = dp[i][j-1] + dp[i-j][j];  
            else if(i == j)  
                dp[i][j] = dp[i][j-1] + 1;  
            else  
                dp[i][j] = dp[i][i];  
        }  
    }  
  
    while(scanf("%d",&n)!=EOF)  
    {  
        cout<<dp[n][n]<<endl;  
    }  
    return 0;  
}  
// 方法二：递归思路
// [cpp] view plaincopy
int q(int n , int m)  
{  
    if(n < 1 || m < 1)  
        return 0;  
    if(n == 1 || m == 1)  
        return 1;  
    if(n < m)  
        return q(n , n);  
    if(n == m)  
        return q(n , m - 1) + 1;  
    return q(n , m - 1) + q(n - m , m);  
}  
  
int main(void)  
{  
    int n;  
    while(scanf("%d",&n)!=EOF)  
    {  
        cout<<q(n,n)<<endl;  
    }  
    return 0;  
}  
// 12、整数的拆分问题
// 接着上一题，输出整数的所有划分方案
// [cpp] view plaincopy
void dfs(int sum , vector<int>& vec , int curnum , int id)  
{  
    int i;  
    if(curnum == sum)  
    {  
        static int inum = 1 ;  
        cout<<"方案 "<<inum++<<": ";  
        for(i = 0; i < vec.size() ; ++i)  
            cout<<vec[i]<<" ";  
        cout<<endl;  
        return;  
    }  
  
    for(i = id ; i <= sum; ++i)  
    {  
        if(curnum + i <= sum)  
        {  
            vec.push_back(i);  
            dfs(sum , vec , curnum + i , i);  
            vec.pop_back();  
        }  
        else  
            break;  
    }  
}  
  
void main()  
{  
    vector<int> vec;  
    dfs(10 , vec , 0 , 1);  
}  
// 13、在数组中寻找和为给定值的组合
// 思路：
// 代码
// 14、字符串移动
// 字符串为*号和26个字母、阿拉伯数字的任意组合，把*号都移动到最左侧，把其他字母和数字都移到最右侧并保持相对顺序不变，返回字符*的个数，要求时间和空间复杂度最小。
// 第一种方法：跟上面的重排问题是一样的
// [cpp] view plaincopy
int MoveStar(char *str , int n)  
{  
    int i , j = n-1;  
    for(i = n - 1 ; i >= 0 ; --i)  
    {  
        if(str[i] != '*')  
        {  
            if(str[j] == '*')  
            {  
                str[j] = str[i];  
                str[i] = '*';  
            }  
            --j;  
        }  
    }  
    return j+1;  
}  
// 第二种方法：
// [cpp] view plaincopy
int MoveStar(char *str , int n)  
{  
    int i , count = 0;  
    for(i = n - 1 ; i >= 0 ; --i)  
    {  
        if(str[i] == '*')  
            ++count;  
        else if(count > 0)    // str[i] != '*'  
            str[i + count] = str[i];  
    }  
    for(i = 0 ; i < count ; ++i)  
        str[i] = '*';  
    return count;  
}  
// 时间复杂度O(N)，空间复杂度O(1)
// 15、求数组中两个元素差的最大值
// 后面的元素减去前面的元素（你可以认为你在炒股票，买入价格和卖出价格就是你的盈利），要求：O(N)时间复杂度，O(1)空间复杂度 
// 思路：首先从包含两个元素的数组开始考虑问题，当这个包含两个元素的问题解决了，那么加一个新的元素会造成什么影响？要改变哪些值？每次都添加一个元素，每次都将这些可能的改变考虑进来，这样就能做到遍历整个数组的时候，问题就解决了。
// [cpp] view plaincopy
// 后面的元素减去前面的元素 差的最大值  
int max_difference(int *arr , int n)  
{  
    if(arr == NULL || n < 2)    // 非法输入  
        return 0;  
    int min = arr[0];  
    int maxDiff = arr[1] - arr[0];  
    for(int i = 2 ; i < n ; ++i)  
    {  
        if(arr[i-1] < min)  
            min = arr[i-1];  
        if(arr[i] - min > maxDiff)  
            maxDiff = arr[i] - min;  
    }  
    return maxDiff;  
}  
// 16、求数组中两个元素差的最大值
// 前面的元素减去后面的元素，要求：O(N)时间复杂度，O(1)空间复杂度
// 思路：跟上一题的思路很相近
// [cpp] view plaincopy
// 前面的元素减去后面的元素 差的最大值  
int max_difference(int *arr , int n)  
{  
    if(arr == NULL || n < 2)    // 非法输入  
        return 0;  
    int max = arr[0];  
    int maxDiff = arr[0] - arr[1];  
    for(int i = 2 ; i < n ; ++i)  
    {  
        if(arr[i-1] > max)  
            max = arr[i-1];  
        if(max - arr[i] > maxDiff)  
            maxDiff = max - arr[i];  
    }  
    return maxDiff;  
}  
// 17、输入一个正数 n，输出所有和为 n 连续正数序列。 
// 例如输入 15，由于 1+2+3+4+5=4+5+6=7+8=15，所以输出 3 个连续序列 1-5、4-6 和 7-8。 
// 方法一：
// 可以发现任意自然数序列其实是公差为1的等差数列，假设从i开始的连续k个数的和为n，即[i , i+k-1]，则n=k*(2*i+k-1)/2，所以转化为一元二次方程为：k*k+(2*i-1)*k-2*n=0，解得k=(1-2*i+sqrt((2*i-1)*(2*i-1)+8*n))/2
// 要满足k为整数，根号里面的肯定必须是平方数，且分子为偶数，否则k就是小数。
// [cpp] view plaincopy
//转载请标明出处，原文地址：http://blog.csdn.net/hackbuteer1/article/details/8035261  
//输入一个正数 n，输出所有和为n 连续正数序列。  
void plusSequence(int n)  
{  
    int i , j , k , m;  
    double num;  
    for(i = 1 ; i <= n/2 ; ++i)  
    {  
        m = (2*i-1)*(2*i-1) + 8*n;  
        num = sqrt(m * 1.0);  
        if(num != (int)num)  
            continue;  
        k = 1 - 2*i + (int)num;  
        if(0 == (k&1) && k > 0)  
        {  
            for(j = 0 ; j < k/2 ; ++j)  
                printf("%d",i + j);  
            printf("\n");  
        }  
    }  
}  
// 方法二：
// 我们知道：
// 1+2 = 3；
// 4+5 = 9；
// 2+3+4 = 9。
// 等式的左边都是两个以上连续的自然数相加，那么是不是所有的整数都可以写成这样的形式呢？稍微考虑一下，我们发现，4和8等数不能写成这样的形式。
// 问题1：写一个程序，对于一个64位的正整数，输出它所有可能的连续自然数（两个以上）之和的算式。
// 问题2：大家在测试上面的程序的过程中，肯定会注意到有一些数字不能表达为一系列连续的自然数之和，例如32好像就找不到。那么，这样的数字有什么规律呢？能否证明你的结论？
// 问题3：在64位正整数范围内，子序列数目最多的数是哪一个？这个问题要用程序蛮力搜索，恐怕要运行很长时间，能够用数学知识推导出来？
// 问题1解答：对于任意的正整数n >= 3（1和2均不能写成连续的自然数序列之和）。假设n能够写成自然数序列[seqStart, seqEnd]之和，则有(seqEnd + seqStart)*(seqEnd - seqStart + 1) = 2*n。考虑左式是两个整数之积，想到对右边的2*n进行因数分解，不妨假定2*n = minFactor * maxFactor，则有
// seqEnd + seqStart = maxFactor           (1)
// seqEnd - seqStart = minFactor-1         (2)
// 解方程组(1)(2)得：
// seqStart = (maxFactor - minFactor + 1) / 2
// seqEnd = (maxFactor + minFactor - 1) / 2
// 因为maxFactor - minFactor与maxFactor + minFactor有相同的奇偶性，因此只需要判断maxFactor + minFactor的奇偶性即可，如果maxFactor + minFactor为奇数，那么seqStart和seqEnd不是分数，是整数，即这个序列存在。下面是代码：
// [cpp] view plaincopy
//转载请标明出处，原文地址：http://blog.csdn.net/hackbuteer1/article/details/8035261  
//输入一个正数 n，输出所有和为n 连续正数序列。  
void plusSequence(int n)  
{  
    int i , minFactor , maxFactor , start , end;  
    int sqrtn = sqrt(2.0*n);  
  
    for(i = 2 ; i <= sqrtn ; ++i)  
    {  
        if(2*n % i == 0)  
        {  
            minFactor = i;  
            maxFactor = 2*n/i;  
            if(((minFactor + maxFactor)&1) == 1)     //奇数  
            {  
                start = (maxFactor - minFactor + 1)>>1;  
                end = (maxFactor + minFactor - 1)>>1;  
                printf("%d %d",start,end);  
                printf("\n");  
            }  
        }  
    }  
} 