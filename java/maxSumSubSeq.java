/*
给一个整数数组，找出来和最大的子串
 */

import java.lang.*;
import java.util.Scanner;

public class maxSumSubSeq{
  public static void main(String[] args){
      //int[] arr = {31, -41, 59, 26, -53, 58, 97, -93, -23, 84};
      //int[] arr = {0, 0, -1, 2, 0};
      Scanner in = new Scanner(System.in);
      String temp = in.nextLine();
      if(temp.equals("")){
          return;
      }
      String[] ss = temp.trim().split(" ");
      int arr[] = new int[ss.length];

      for(int i = 0; i < ss.length; i ++){
        arr[i] = Integer.parseInt(ss[i]);

      }

      int big[] = new int[arr.length];
      big[0] = arr[0];
      int tmp = 0, start = 0, end = 0;
      int max = Integer.MIN_VALUE;
      for (int i = 0; i < arr.length; i ++){
          if(i == 0){
              max = big[0];
              continue;
          }
          big[i] = Math.max(big[i-1]+arr[i], arr[i]);

          if(big[i] == arr[i]) tmp = i;
          if(big[i] > max){
              max = big[i];
              start = tmp;
              end = i;
          }
      }

      /*
      for(int j = start; j <= end; j ++){
          System.out.print(arr[j] + " ");
      }
      System.out.print("\n");
      */
      System.out.print(max);

  }
}
