
import java.util.*;
public class StringReverse {
    public static void main(String []args){
        String s,ans="";
        Scanner sc=new Scanner(System.in);
        s=sc.nextLine();
        int i=0,j=s.length();
        while(i<j){
            char a=s.charAt(i);
            ans=a+ans;
            i++;
        }
        System.out.println(ans);
        sc.close();
    }

}
