import java.lang.*;
import java.util.LinkedList;

public class Sort{
    public static void main(String[] args){
        int[] arr = {1, 3, 2, 45, 65, 33, 12};
        System.out.print("排序前序列：");
        for(int num:arr){
            System.out.print(num + " ");
        }
        System.out.print("\n");
        Sort s = new Sort();

        System.out.println("选择排序： ");
        s.selectionSort(arr);
        for(int num:arr){
            System.out.print(num + " ");
        }
        System.out.print("\n");

        System.out.println("插入排序： ");
        int[] arr1 = {1, 3, 2, 45, 65, 33, 12};
        s.insertSort(arr1);
        for(int num:arr1){
            System.out.print(num + " ");
        }
        System.out.print("\n");

        System.out.println("冒泡排序： ");
        int[] arr2 = {1, 3, 2, 45, 65, 33, 12};
        s.bubbleSort(arr2);
        for(int num:arr2){
            System.out.print(num + " ");
        }
        System.out.print("\n");

        System.out.println("希尔排序： ");
        int[] arr3 = {1, 3, 2, 45, 65, 33, 12};
        s.shellSort(arr3);
        for(int num:arr3){
            System.out.print(num + " ");
        }
        System.out.print("\n");

        System.out.println("快速排序： ");
        int[] arr4 = {1, 3, 2, 45, 65, 33, 12};
        s.quickSort(arr4, 0, arr4.length-1);
        for(int num:arr4){
            System.out.print(num + " ");
        }
        System.out.print("\n");

        System.out.println("归并排序： ");
        int[] arr5 = {1, 3, 2, 45, 65, 33, 12};
        s.mergeSort(arr5, 0, arr5.length-1);
        for(int num:arr5){
            System.out.print(num + " ");
        }
        System.out.print("\n");

        System.out.println("堆排序： ");
        int[] arr6 = {1, 3, 2, 45, 65, 33, 12};
        s.heapSort(arr6);
        for(int num:arr6){
            System.out.print(num + " ");
        }
        System.out.print("\n");

        System.out.println("桶排序： ");
        int[] arr7 = {1, 3, 2, 5, 68, 7, 44, 27, 29, 39, 10, 45, 65, 33, 12, 11};
        s.bucketSort(arr7);
        for(int num:arr7){
            System.out.print(num + " ");
        }
        System.out.print("\n");
        return;
    }
    private static void swap(int[] a, int i, int j){
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
    //选择排序
    public void selectionSort(int[] arr){
        for(int i = 0; i < arr.length; i ++){
            int k = i;
            for(int j = k+1; j < arr.length; j ++){
                if(arr[j] < arr[k]){
                    k = j;
                }
            }
            if(i != k){
                swap(arr, i, k);
            }
        }
    }
    //插入排序
    public void insertSort(int[] arr){
        for(int i = 1; i < arr.length; i ++){
            int j = i, value = arr[i];
            while(j>0 && arr[j-1]>value){
                arr[j] = arr[j-1];
                j--;
            }
            arr[j] = value;
        }
    }
    //冒泡排序
    public void bubbleSort(int[] arr){
        /*
        for(int i = arr.length-1; i > 0; i --){
            for(int j = 0; j < i; j ++){
                if(arr[j] > arr[j+1]){
                    swap(arr, j, j+1);
                }
            }
        }
        */
        for (;;) {
            boolean sorted = true;
            for (int i = 0; i < arr.length - 1; i++)
                if (arr[i] > arr[i+1]) {
                    sorted = false;
                    swap(arr, i, i + 1);
                }
            if (sorted) break;
        }
    }
    //希尔排序
    /***
     *
     * 先将整个待排元素序列分割成若干个子序列（由相隔某个“增量”的元素组成的）分别进行直接插入排序，然后依次缩减增量再进行排序，
     * 待整个序列中的元素基本有序（增量足够小）时，再对全体元素进行一次直接插入排序。由于希尔排序是对相隔若干距离的数据进行直接插入排序，
     * 因此可以形象的称希尔排序为“跳着插”
     */
    public void shellSort(int[] arr){
        for(int step = arr.length/2; step > 0; step /= 2){
            for(int i = 0; i < step; i ++){
                for(int j = i+step; j < arr.length; j += step){
                    //直接插入排序
                    int k = j, value = arr[j];
                    while(k>=step && arr[k-step]>value){
                        arr[k] = arr[k-step];
                        k = k - step;
                    }
                    arr[k] = value;
                }
            }
        }
    }
    //快速排序
    /**
     * “挖坑填数+分治法”，首先令i =L; j = R; 将a[i]挖出形成第一个坑，称a[i]为基准数。
     * 然后j--由后向前找比基准数小的数，找到后挖出此数填入前一个坑a[i]中，再i++由前向后找比基准数大的数，找到后也挖出此数填到前一个坑a[j]中。
     * 重复进行这种“挖坑填数”直到i==j。再将基准数填入a[i]中，这样i之前的数都比基准数小，i之后的数都比基准数大。
     * 因此将数组分成二部分再分别重复上述步骤就完成了排序。
     */
    public void quickSort(int[] arr, int l, int r){
        if(l < r){
            int i = l, j = r, x = arr[l];
            while(i < j){
                while(i < j && arr[j] >= x){//从右向左找第一个比x小的数
                    j--;
                }
                if(i < j){
                    arr[i++] = arr[j];
                }
                while(i < j && arr[i] < x){//从左向右找第一个大于等于x的数
                    i ++;
                }
                if(i < j){
                    arr[j--] = arr[i];
                }
            }
            //i==j时
            arr[i] = x;
            quickSort(arr, l, i-1);
            quickSort(arr, i+1, r);
        }
    }
    //归并排序
    /*
     * 归并排序主要分为两步：分数列（divide），每次把数列一分为二，然后分到只有两个元素的小数列；
     * 合数列（Merge），合并两个已经内部有序的子序列，直至所有数字有序。用递归可以实现。
     */
    public void mergeSort(int[] arr, int left, int right){
        if(left < right) {
            int mid = (left + right) / 2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid+1, right);
            Merge(arr, left, right, mid);
        }
    }
    public void Merge(int[] arr, int left, int right, int mid){
        int[] tmpArr = new int[right-left+1];
        int i = left, j = mid+1;
        int k = 0;
        while(i <= mid && j <= right){
            if(arr[i] < arr[j]){
                tmpArr[k++] = arr[i];
                i++;
            }else{
                tmpArr[k++] = arr[j];
                j++;
            }
        }
        while(i <= mid){
            tmpArr[k++] = arr[i];
            i ++;
        }
        while(j <= right){
            tmpArr[k++] = arr[j];
            j ++;
        }
        k = 0;
        for(int t = left; t <= right; t ++, k ++){
            arr[t] = tmpArr[k];
        }
    }
    //堆排序
    /**
     * 堆的插入就是——每次插入都是将新数据放在数组最后，而从这个新数据的父结点到根结点必定是一个有序的数列，因此只要将这个新数据插入到这个有序数列中即可。
     * 堆的删除就是——堆的删除就是将最后一个数据的值赋给根结点，然后再从根结点开始进行一次从上向下的调整。调整时先在左右儿子结点中找最小的，
     * 如果父结点比这个最小的子结点还小说明不需要调整了，反之将父结点和它交换后再考虑后面的结点。相当于从根结点开始将一个数据在有序数列中进行“下沉”。
     * 因此，堆的插入和删除非常类似直接插入排序，只不是在二叉树上进行插入过程。所以可以将堆排序形容为“树上插”
     */
    public void heapSort(int[] arr){
        //建最大堆,从底层建起
        for(int i = arr.length/2 - 1; i >= 0; i --){
            adjustHeap(arr, i, arr.length);
        }
        //堆的删除
        for(int i = arr.length - 1; i >= 0; i --){
            swap(arr, 0, i);//根节点与最后一位进行交换
            adjustHeap(arr, 0, i);
        }
    }

    public void adjustHeap(int[] arr, int p, int len){
        int child = 2*p+1;//左子树
        int curParent = arr[p];
        while(child < len){
            if(child+1 < len && arr[child+1] > arr[child]){
                child ++;//找到较大孩子的下标
            }
            if(curParent < arr[child]){
                arr[p] = arr[child];//孩子节点向父节点移动
                p = child;
                child = 2*p + 1;
            }else{
                break;
            }
        }
        arr[p] = curParent;
    }

    //桶排序 时间复杂度为O（n）（O(N+N*logN-N*logM)）,空间复杂度为O(n+m)

    /**
     * 桶排序在数据量非常大，而空间相对充裕的时候是很实用的，可以大大降低算法的运算数量级。
     * 此外，在解决一些特殊问题的时候，桶排序可能会起到意想不到的结果.
     */
    public void bucketSort(int[] arr){
        int len = arr.length;
        //创建链表（桶）集合并初始化，集合中的链表用于存放相应的元素

        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;
        for(int i = 0; i < arr.length; i++){
            max = Math.max(max, arr[i]);
            min = Math.min(min, arr[i]);
        }

        int bucketNum = (max - min) / arr.length + 1;;//桶数(待排序元素中最大值为65<100）
        LinkedList<LinkedList<Integer>> buckets = new LinkedList<LinkedList<Integer>>();
        for(int i = 0; i < bucketNum; i ++){
            LinkedList<Integer> bucket = new LinkedList<Integer>();
            buckets.add(bucket);
        }
        // 把元素放进相应的桶中
        for(int i = 0; i < len; i ++){
            int num = (arr[i] - min) / (arr.length);
            buckets.get(num).add(arr[i]);
        }
        // 对每个桶中的元素排序，并放进arr中
        int index = 0;
        for(LinkedList<Integer> linkedList : buckets){
            int size = linkedList.size();
            if(size == 0) continue;
            int[] tmp = new int[size];
            for(int i = 0; i < tmp.length; i ++){
                tmp[i] = linkedList.get(i);
            }
            // 利用插入排序对temp排序
            insertSort(tmp);
            for(int i = 0; i < tmp.length; i ++){
                arr[index++] = tmp[i];
            }
        }
    }
    //计数排序是桶排序的一种特殊情况，可以把计数排序当成每个桶里只有一个元素的情况。
}