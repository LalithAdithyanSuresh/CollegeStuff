public class Room_Q4{
    int roomNo;
    String roomType;
    double roomArea;
    String ACmachine;

    public void SetData(int n,String t,double a,String m){
        this.ACmachine = m;
        this.roomArea = a;
        this.roomNo = n;
        this.roomType = t;
    }

    public void Display(){
        System.out.println("Room No : " + this.roomNo);
        System.out.println("Room Type : " + this.roomType);
        System.out.println("Room Area : " + this.roomArea);
        System.out.println("AC machine : " + this.ACmachine);
    }
    public static void main(String[] args) {
        Room_Q4 room = new Room_Q4();
        room.SetData(4,"AC SHARED",13.32,"yes");
        room.Display();

    }
}