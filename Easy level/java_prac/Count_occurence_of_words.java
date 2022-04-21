import java.util.*;

public class Count_occurence_of_words {
    public static void main(String[] args) {
        String s, word;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the string: ");
        s = sc.nextLine();
        System.out.println("Enter the word: ");
        word = sc.nextLine();
        int i = 0, j = s.length();
        String str = "";
        int count = 0;
        while (i < j) {
            if (s.charAt(i) == ' ') {
                if (str.compareTo(word) == 0)
                    count++;
                str = "";
                i++;
            }

            str += s.charAt(i);
            i++;
        }
        if (str.compareTo(word) == 0)
            count++;
        System.out.println("The word appears " + count + " times");
        sc.close();
    }
}
