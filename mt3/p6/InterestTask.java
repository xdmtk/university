// BankAccount Problem  
//InterestTask.java
//Comp 333 SP 2020
 
import java.util.concurrent.*;

public class InterestTask   implements Runnable
{
    private BankAccount account;
    public InterestTask ( BankAccount a)
    {account = a;}
    
    public void run()
    {
        for(int k  = 0; k < 4; k++)
        {
            int depositAmt = 10;  
            account.deposit(depositAmt);
            account.addInterest();
            
            try { 
               Thread.sleep(50);
            }
            catch (InterruptedException e)
            {
               System.out.println(e); System.exit(1);
            }
         }
     }
 } //end DepositTask
