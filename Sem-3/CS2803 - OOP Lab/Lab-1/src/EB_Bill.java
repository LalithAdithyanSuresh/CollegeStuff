import java.util.Scanner;

public class EB_Bill {
    public static void printLine(String x){
        System.out.println(x);
    } 
    public static void print(String x){
        System.out.print(x);
    } 
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        EB_Rec[] Bills = new EB_Rec[10];
        printLine("Starting EB Bill Generator");
        int ct = 0;
        int a;
        String name;
        double b,c;
        boolean d;
        while(true){
            printLine("------------------");
            print("Customer Number   : ");
            a = input.nextInt();
            print("Name              : ");
            input.nextLine();
            name = input.nextLine();
            print("Domestic (y-1/n-2): ");
            b = input.nextDouble();
            print("Prev Units        : ");
            c = input.nextDouble();
            print("Curr Units        : ");
            int y = input.nextInt();
            d = b==1;

            print("\n>>> Do you still want to create a bill ? (y - 1 / n - 2) : ");
            int opt = input.nextInt();
            Bills[ct] = new EB_Rec(a,name,c,y,d);
            ct++;
            if(opt == 2){break;}
        }
        printLine("----------------Printing All Bills-----------------");
        for(int i =0; i<ct;i++){
            Bills[i].BillGen();
            Bills[i].PrintBill();
        }
    }
}
