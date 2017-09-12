import java.util.*;

public class 彩色的砖块 {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        String s = in.nextLine();
        Set set = new HashSet<>();
        char[] ch = s.toCharArray();
        for(int i = 0; i < ch.length; i ++){
            set.add(ch[i]);
        }
        if(set.size() == 2){
            System.out.println("2");
        }else if(set.size() == 1){
            System.out.println("1");
        }else{
            System.out.println("0");
        }
    }
}