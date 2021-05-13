// BankAccount Problem
//WithDrawTask.java
//Comp 333 SP 2020
  
import java.util.concurrent.*;
public class WithdrawTask implements Runnable
{
   private BankAccount account;
   
   public WithdrawTask ( BankAccount a)
   {  account = a;}
   
   public void run()
   {
      
      for(int k = 0; k <10; k++)
      {
            int withdrawAmt = 5;  
            account.withdrawal(withdrawAmt);
      
            try { 
               Thread.sleep(8);  
            }
            catch (InterruptedException e)
            {
               System.out.println(e); System.exit(1);
            }
        }
     }
  } //end WithdrawTask
