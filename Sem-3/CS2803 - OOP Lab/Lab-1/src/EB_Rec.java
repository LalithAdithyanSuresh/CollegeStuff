

public class EB_Rec{
    private int ConNo;
    private String ConName;
    private double PrevRead;
    private double CurrRead;
    private boolean domestic;
    private double[] Prices;
    private double FPrice;
    EB_Rec(int ConNo,String ConName,double PrevRead,double CurrRead,boolean domestic){
         this.ConNo = ConNo;
         this.ConName = ConName;
         this.PrevRead = PrevRead;
         this.CurrRead = CurrRead;
         this.domestic = domestic;
         this.FPrice = 0;
         if(domestic){
            this.Prices=new double[]{1,2.5,4,6};
         }else{
            this.Prices=new double[]{2,4.5,6,7};
         }
    }
    
    public void BillGen(){
        double diff = this.CurrRead - this.PrevRead;
        if(diff <=100){
            this.FPrice = diff * this.Prices[0];
        }else if(101 <=diff && diff <= 200){
            this.FPrice = (100 * this.Prices[0]) + ((diff - 100) * this.Prices[1]);
        }else if(201 <=diff && diff <= 500){
            this.FPrice = (100 * this.Prices[0]) + (100 * this.Prices[1]) + ((diff - 200) * this.Prices[2]);
        }else{
            this.FPrice = (100 * this.Prices[0]) + (100 * this.Prices[1]) + (100 * this.Prices[2]) + ((diff - 500) * this.Prices[3]);
        }
    }
    
    public void PrintBill(){
        System.out.println("Customer Number  : "+this.ConNo);
        System.out.println("Name             : "+this.ConName);
        System.out.println("Domestic         : "+this.domestic);
        System.out.println("Units Billed     : "+(this.CurrRead - this.PrevRead)) ;
        System.out.println("Price            : Rs " +this.FPrice);
        System.out.println("--------------------------");
    }
}