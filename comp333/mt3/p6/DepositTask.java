// BankAccount Problem  
//DepositTask.java
//Comp 333 SP 2020
 
import java.util.concurrent.*;

public class DepositTask  implements Runnable
{
    private BankAccount account;
    public DepositTask ( BankAccount a)
    {account = a;}
    
    public void run()
    {
        for(int k  = 0; k < 10; k++)
        {
            int depositAmt = 10;  
            account.deposit(depositAmt);
            
            try { 
               Thread.sleep(4);   
            }
            catch (InterruptedException e)
            {
               System.out.println(e); System.exit(1);
            }
         }
     }
 } //end DepositTask
