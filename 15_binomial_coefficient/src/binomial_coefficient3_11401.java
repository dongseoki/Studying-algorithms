import java.io.*;
import java.math.BigInteger;
import java.util.*;
 
public class binomial_coefficient3_11401
{
    static final int MOD = 1000000007;
    
    // fac 구하기
    static long fac(long n)
    {
        long ret = 1;
        while (n > 1)
        {
            ret = (ret * n) % MOD;
            n--;
        }
        return ret;
    }
    
    static long pow(long a, int b) {
        
        long ret= 1;
        long aa = a;
        
        while (b > 0) {
            
            if (b%2 == 1) ret = ret * aa  % MOD;
            b = b/2;
            aa = (aa * aa) % MOD;
        }
            
        return ret;
    }
    
    public static void main(String[] args) throws Exception
    {
        Scanner in = new Scanner(System.in);
        long n = in.nextInt();
        long k = in.nextInt();
        
        long a = fac(n);
        long b = fac(n - k) * fac(k) % MOD;
        long result = a * pow(b, MOD-2) % MOD;
        
        System.out.println(result);
        
    }
}
//[출처] BOJ 11401 이항 계수 3|작성자 흐이준
//https://blog.naver.com/PostView.nhn?blogId=phj8498&logNo=221223312006
//http://5stralia.tistory.com/4
