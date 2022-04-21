import java.util.*;
public class Count_occurence_of_article {
    public static void main(String[] args) {
        String s;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the string: ");
        s = sc.nextLine();
        int i = 0, j = s.length();
        String str = "";
        int count_a = 0,count_an=0,count_the=0;
        while (i < j) {
            if (s.charAt(i) == ' ') {
                if (str.compareToIgnoreCase("a") == 0 )
                    count_a++;
                else if (str.compareToIgnoreCase("the") == 0 )
                    count_the++;
                else if (str.compareToIgnoreCase("an") == 0 )
                    count_an++;
                
                str = "";
                i++;
            }
            if(i<j)
            str += s.charAt(i);
            i++;
        }
        if (str.compareToIgnoreCase("a") == 0 )
                    count_a++;
        else if (str.compareToIgnoreCase("the") == 0 )
                    count_the++;
        else if (str.compareToIgnoreCase("an") == 0 )
                    count_an++;
                
        System.out.println("'The' appears " + count_the + " times");
        System.out.println("'A' appears " + count_a + " times");
        System.out.println("'An' appears " + count_an + " times");
        sc.close();
}
}
