/*
题目：输入某年某月某日，判断这一天是这一年的第几天？
*/
import java.util.Calendar;
import java.util.Scanner;

public class theNthDay{
    public static void main(String[] args){
        System.out.println("请输入年月日：");
        Scanner in = new Scanner(System.in);
        int year = in.nextInt();
        int month = in.nextInt();
        int day = in.nextInt();
        Calendar calendar = Calendar.getInstance();
        calendar.set(year, month-1, day);
        int sum = calendar.get(Calendar.DAY_OF_YEAR);
        System.out.print("这一天是这一年的第"+sum+"天");
    }
}

/*
getInstance()是Calendar提供的一个类方法，它的作用是获得一个Calendar类型的通用对象，getInstance()将返回一个Calendar的对象。
还有一点关于 为什么不用 Calendar  c=new Calendar();
原因是：
Calendar类是一个抽象类，在实际使用时实现特定的子类的对象。由于Calendar类是抽象类，且Calendar类的构造方法是protected的，所以无法使用Calendar类的构造方法来创建对象，API中提供了getInstance方法用来创建对象。

所以定义一个Calendar对象就应该为：
Calendar  cal= Calendar.getInstance();

 */