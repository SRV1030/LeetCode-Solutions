// https://leetcode.com/problems/count-primes

/**
 * @param {number} n
 * @return {number}
 */
var countPrimes = function(n) {
    let primes=new Array(n+1).fill(true);
    for(let i=2;i<n;i++){
        if(primes[i]===true){
            for(let j=i*i;j<=n;j+=i)primes[j]=false;
        } 
    }
    let c=0;
    for(let i=2;i<n;i++)if(primes[i])c++;
    return c;
};