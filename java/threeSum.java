import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class threeSum {

    public static void main(String[] args){
        int[] num = {1, 5, -2, -3, 6, 8, -7, -2, 10};
        ArrayList<ArrayList<Integer>> res = threeSum(num);
        System.out.println(res);
    }

    public static ArrayList<ArrayList<Integer>> threeSum(int[] num){
        ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();
        if(num == null||num.length<3)//如果只有2个数字 或者为空 返回空
            return res;
        Arrays.sort(num);
        for(int i = 0; i<num.length -2;i++)// 保证最后得有num.length-1 和num.length-2两个数，才可以进循环
        {
            if(i > 0 && num[i] == num[i-1])//如果要是有重复的直接跳过。
                continue;
            ArrayList<ArrayList<Integer>> cur = twoSum(num,i+1,-num[i]); //得到当前数字可以组合出来的数字序列的子集。
            res.addAll(cur);
        }
        return res;
    }

    public static ArrayList<ArrayList<Integer>>twoSum (int []num,int start,int target)
    {
        ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();
        if(num == null||num.length < 2)
             return res;
        int l = start;//起始位置
        int pri = start-1;//当前数字
        int r = num.length-1;//终止位置
        while(l < r)//采用夹逼，逼近target
        {
            if(num[l]+num[r] == target)//
            {
                ArrayList<Integer> te = new ArrayList<Integer>();//符合的话 把三个数放入到list中
                te.add(num[pri]);
                te.add(num[l]);
                te.add(num[r]);
                res.add(te);
                int k = l + 1;//从l的下一个开始 去除重复。
                while(k < r&& num[k] == num[l])
                    k++;
                l = k;
                k = r - 1;//去除R的重复
                while(k > l &&num[k] == num[r])
                    k--;
                r = k;
            }
        else if(num[l] + num[r] > target)//夹逼
            r--;
        else l++;
        }
        return res;
    }

}
