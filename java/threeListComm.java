import java.util.HashSet;
import java.util.Set;

public class threeListComm{
    /**
     * 3 sorted array, find common elements
     */
    static int []a = {1,3,4,5,6,7,9,11};
    static int []b = {1,5,8,9,11};
    static int []c = {2,3,5,6,9,11};
    static Set<Integer> s = new HashSet<>();
    public static void main(String[] args){
        for(int i = 0, j = 0, k = 0; i < a.length && j < b.length && k < c.length; ){
            int[] status = getMinStatus(a[i], b[j], c[k]);
            if(status[0]+status[1]+status[2] == 3){
                s.add(a[i]);
            }
            i += status[0];
            j += status[1];
            k += status[2];
        }

        System.out.println(s);
    }

    public static int [] getMinStatus(int a, int b, int c){
        int [] status = {0, 0, 0};
        int minNum = c < ((a < b) ? a : b) ? c : ((a < b) ? a : b);
        if(a == minNum) status[0] = 1;
        if(b == minNum) status[1] = 1;
        if(c == minNum) status[2] = 1;
        return status;
    }
}
/**
 大家可以看到，我实现了一个min_status函数，他的主要作用就是找到当前三个元素中的最小值，并且决定将最小的元素下标+1，来进行该数组的下一步搜索。
 然而跟两个数组的情形不同的是：有时候最小的元素不一定是一个，可能是两个或者三个，这样我们需要用一个status数组来标记各个数组下一步是否应该+1。
 同样，如果要求从N个已排序数组中找到common elements，用这种方式同样可以保证时间复杂度为o(n)。
 不过需要经历一个寻找最小值和设置状态位的过程，这两个过程可以优化，优化方法就是对n个当前元素进行排序，找到m（m<<n）个最小的，
 仅把这m个元素的状态为修改为1即可。当m==n时，该元素就是我们所要的common element。
 **/