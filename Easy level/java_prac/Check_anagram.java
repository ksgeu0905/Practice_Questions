import java.util.*;
public class Check_anagram {
    public static void main(String []args){
        String s1,s2;
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter String 1: ");
        s1=sc.nextLine();
        System.out.println("Enter String 2: ");
        s2=sc.nextLine();
        char arr1[]=s1.toCharArray();
        char arr2[]=s2.toCharArray();
        Arrays.sort(arr1);
        Arrays.sort(arr2);
        s1= new String(arr1);
        s2=new String(arr2);
        if(s1.compareToIgnoreCase(s2)==0)
            System.out.println("The Strings are anagrams\n");
        else 
            System.out.println("The Strings are not anagrams\n");
        sc.close();
    }
}
