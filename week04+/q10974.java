import java.util.Scanner;
import java.util.ArrayList;
public class q10974 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        ArrayList<Integer> set = new ArrayList<>();
        String str = "";
        for (int q = 1; q <= n; q++) {set.add(q);}
        permul(set, str);
        scanner.close();
    }

    static void permul(ArrayList<Integer> set, String str) {
        String newstr = str;
        if (set.size() == 1) {
            newstr = str + set.get(0);
            System.out.println(newstr);
            return;
        }

        for (int i = 0; i < set.size(); i++) {
            int num = set.get(i);
            newstr = str + num + " ";
            set.remove(i);
            permul(set, newstr);
            set.add(i, num);
        }
    }
}
