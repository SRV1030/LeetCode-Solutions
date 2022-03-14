// https://leetcode.com/problems/fibonacci-number


int fib(int n){
int a[n+1];
if(n==0||n==1)
{
return n;
}
a[0]=0;
a[1]=1;
for(int i=2;i<=n;i++)
{
a[i]=a[i-1]+a[i-2];
}
return (a[n]);
}