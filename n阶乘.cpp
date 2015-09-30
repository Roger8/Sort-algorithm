//1、 给定一个整数N，那么N的阶乘N！末尾有多少个0呢？
//计算n的阶乘n！末尾的“0”的个数，可以转换为计算其因式分解中“5”的个数
//第一种
int ZeroNum(int n){
int k = n/5;
	if(n>0 && n<5)
		return 0;
	else
		return (k+ZeroNum(k));
}

//第二种
int ZeroNum(int n){
	int num = 0;
	for(int i=5;i<=n; i+=5){
		int temp = i;
		
		while(0 == temp%5){
			num++;
			temp /=5;
		}
	}
	return num;
}

//最优算法
int numOfZero(int n)  
{  
    int num = 0, i;  
    for(i=5; i<=n; i*=5)  
    {  
        num += n/i;  
    }  
    return num;  
}  

//2、求N！的二进制表示中最低位1的位置。
//这个问题实际上等同于求N！含有质因数2的个数+1。即答案等于N！含有质因数2的个数加1
