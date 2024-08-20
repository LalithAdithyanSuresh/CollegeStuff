import java.util.*; // important > Exam you should write this !
public class App {
    public static void main(String[] args) throws Exception {
        List<String> list = new ArrayList<>();
        String curr;
        try (Scanner input = new Scanner(System.in)) {
            for(int i =0;i<5;i++){
                System.out.print("Enter String " + (i+1) + " : ");
                curr = input.nextLine();
                list.add(curr);
            }
            Collections.sort(list,Collections.reverseOrder());
            System.out.println("\nThe Strings Read Are : ");
            for(int i =0;i<5;i++){
                System.out.println("\t"+list.get(i));
            }
        }
    }
}

