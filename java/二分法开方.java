import java.lang.String;
import java.util.Scanner;

public class 二分法开方 {
  final static double esp = 0.001;
  private float mySqrt(float x){
    float down = 0, up = x, n;
    n = (up+down) / 2;
    if(x <= 0) return x;
    while((n*n != x) && Math.abs(n*n-x) > esp){
      if(n*n < x){
        down = n;
        n = (up+down) / 2;
      }else{
        up = n;
        n = (up+down) / 2;
      }
    }
    return n;
  }
  public static void main(String[] args){
    float x, res;
    Scanner in = new Scanner(System.in);
    x = in.nextFloat();

    二分法开方 test = new 二分法开方();
    res = test.mySqrt(x);
    System.out.printf("%.2f", res);
  }
}
