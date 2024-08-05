import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        System.out.println("--------------STARTING PROGRAM---------------");
        int opt = 0;
        double val = 0;
        while(opt != 15){
            System.out.println("Options : \n\nCurrency:\n\t1 - Dollar to Inr\n\t2 - Euro To Inr\n\t3 - Yen To Inr\n\t4 - Inr To Dollar\n\t5 - Inr To Euro\n\t6 - Inr To Yen");
            System.out.println("Distance\n\t7 - KM to m\n\t8 - m To KM\n\t9 - Km To Miles\n\t10- Miles To Km");
            System.out.println("Time\n\t11- Hours To Minutes\n\t12- Hours To Sec\n\t13- Sec To Hours\n\t14- Minutes To Hours");
            System.out.print(">>>");
            Scanner OhMyGod = new Scanner(System.in);
            opt = OhMyGod.nextInt();
            System.out.print("Enter Value : ");
            switch (opt) {
                case 1:
                    val = OhMyGod.nextDouble();
                    System.out.print("The converted Value is : ");
                    System.out.println(Currency_.converter.DollarToInr(val));
                    break;
                case 2:
                    val = OhMyGod.nextDouble();
                    System.out.print("The converted Value is : ");
                    System.out.println(Currency_.converter.EuroToInr(val));
                    break;
                case 3:
                    val = OhMyGod.nextDouble();
                    System.out.print("The converted Value is : ");
                    System.out.println(Currency_.converter.YenToInr(val));
                    break;
                case 4:
                    val = OhMyGod.nextDouble();
                    System.out.print("The converted Value is : ");
                    System.out.println(Currency_.converter.InrToYen(val));
                    break;
                case 7:
                    val = OhMyGod.nextDouble();
                    System.out.print("The converted Value is : ");
                    System.out.println(Distance.converter.KmToM(val));
                    break;
                case 8:
                    val = OhMyGod.nextDouble();
                    System.out.print("The converted Value is : ");
                    System.out.println(Distance.converter.MTKm(val));
                    break;
                case 9:
                    val = OhMyGod.nextDouble();
                    System.out.print("The converted Value is : ");
                    System.out.println(Distance.converter.KmToMile(val));
                    break;
                case 10:
                    val = OhMyGod.nextDouble();
                    System.out.print("The converted Value is : ");
                    System.out.println(Distance.converter.MileToKm(val));
                    break;
                case 11:
                    val = OhMyGod.nextDouble();
                    System.out.print("The converted Value is : ");
                    System.out.println(Time_.converter.HourToMin(val));
                    break;
                case 12:
                    val = OhMyGod.nextDouble();
                    System.out.print("The converted Value is : ");
                    System.out.println(Time_.converter.HourToSec(val));
                    break;
                case 13:
                    val = OhMyGod.nextDouble();
                    System.out.print("The converted Value is : ");
                    System.out.println(Time_.converter.SecToHour(val));
                    break;
                case 14:
                    val = OhMyGod.nextDouble();
                    System.out.print("The converted Value is : ");
                    System.out.println(Time_.converter.MinToHour(val));
                    break;
                case 15:
                    System.out.println("-----THE PROGRAM IS TERMINATING------");
                    break;
                default:
                    System.out.println("WRONG OPTION DUMB!!");
                    break;
            }
            System.err.println("------------------");
        }
    }
}
