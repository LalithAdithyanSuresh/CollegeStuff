import java.util.*;
public class App {
    public static void main(String[] args){
        ArrayList<String> array = new ArrayList<>();
        Scanner input = new Scanner(System.in);
        int opt = 0;
        String in;

        while(opt != 8){
            System.out.print("\n-----------------\nOptions : \n\t1 - Append\n\t2 - Insert\n\t3 - Search\n\t4 - Starts With\n\t5 - Sort\n\t8 - Exit\n>>>");
            opt = input.nextInt();
            input.nextLine();

            switch(opt){
                case 1:
                    System.out.print("Enter String to Append : ");
                    in = input.nextLine();
                    array.add(in);
                    break;

                case 2:
                    System.out.print("Enter String to Insert : ");
                    in = input.nextLine();
                    System.out.print("Enter index to insert into : ");
                    int index = input.nextInt();
                    input.nextLine();
                    if(index >= 0 && index <= array.size()){
                        array.add(index, in);
                    }else{
                        System.out.println("Invalid index.");
                    }
                    break;

                case 3:
                    System.out.print("Enter string to search for : ");
                    in = input.nextLine();
                    int foundIndex = array.indexOf(in);
                    if(foundIndex != -1){
                        System.out.println("Found at Index : " + foundIndex);
                    } else {
                        System.out.println("String not found.");
                    }
                    break;

                case 4:
                    System.out.print("Enter Substring to search that starts with : ");
                    in = input.nextLine();
                    boolean found = false;
                    for(String item : array){
                        if(item.startsWith(in)){
                            System.out.println(" - " + item);
                            found = true;
                        }
                    }
                    if(!found){
                        System.out.println("No strings found that start with the given substring.");
                    }
                    break;

                case 5:
                    System.out.print("Do you want to sort in Ascending (1) or Descending (2) : ");
                    int sortOrder = input.nextInt();
                    input.nextLine();
                    if(sortOrder == 1){
                        Collections.sort(array); 
                    }else if(sortOrder == 2){
                        Collections.sort(array, Collections.reverseOrder());
                    }else{
                        System.out.println("Invalid option.");
                    }
                    break;

                case 8:
                    System.out.println("Exiting...");
                    break;

                default:
                    System.out.println("Invalid option.");
                    break;
            }
        }
        
        input.close();
    }
}
