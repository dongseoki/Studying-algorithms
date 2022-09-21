package baekjoon.P16953_A_B;

class Solution {
    public int solution(int A, int B) {
        int cur = B;
        int result = 1;
        while(true){
            if (cur == A){
                break;
            }
            if (cur <A){
                result = -1;
                break;
            }



            if(cur%2==0){
                result +=1;
                cur/=2;
            }
            else if(cur%10==1){
                result +=1;
                cur /=10;
            }else{
                result = -1;
                break;
            }
        }

        return result;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
//        int result = solution.solution(2,162);
//        System.out.println("result = " + result);
        int result = solution.solution(100,40021);
        System.out.println("result = " + result);
    }
}
