/* BankAccount Problem
   Comp 333 SP 2020
   TestingBankAccountThreads.java
  
*/

import java.util.concurrent.*;
public class TestingBankAccountThreads
{
    
     private static  BankAccount account =
               new BankAccount(100); 
     
     public static void main( String[] args)
     {
        System.out.println("Main: Initial account balance: $" 
                       + account.getBalance() );
                       
        Thread depositThread = new Thread( new DepositTask(account));
        Thread interestThread = new Thread( new InterestTask(account));
        Thread withdrawThread = new Thread( new WithdrawTask(account));
        
        depositThread.start();
        interestThread.start();
        withdrawThread.start();
        
        //wait for threads to complete
        try {
           depositThread.join();
           withdrawThread.join();
        }
        catch( InterruptedException e)
        {
               System.out.println(e); System.exit(1);
        }
      
        System.out.println("Main: Final balance is $" + account.getBalance() );   
     
     }
}

/*
 ----jGRASP exec: java TestingBankAccountThreads
 Synchronized Run
 Main: Initial account balance: $100
Deposit: $5 Balance = $105
Withdrawal: $2 Balance is $103
Deposit: $5 Balance = $108
Withdrawal: $2 Balance is $106
Deposit: $5 Balance = $111
Withdrawal: $2 Balance is $109
Deposit: $5 Balance = $114
Withdrawal: $2 Balance is $112
Deposit: $5 Balance = $117
Withdrawal: $2 Balance is $115
Deposit: $5 Balance = $120
Withdrawal: $2 Balance is $118
Deposit: $5 Balance = $123
Withdrawal: $2 Balance is $121
Deposit: $5 Balance = $126
Withdrawal: $2 Balance is $124
Deposit: $5 Balance = $129
Withdrawal: $2 Balance is $127
Deposit: $5 Balance = $132
Withdrawal: $2 Balance is $130
Main: Final balance is $130
  
  
     ----jGRASP exec: java TestingBankAccountThreads
 Unsynchronized Run
  Main: Initial account balance: $100
Deposit: $5 Balance = $105
Withdrawal: $2 Balance is $98
Deposit: $5 Balance = $103
Withdrawal: $2 Balance is $96
Deposit: $5 Balance = $101
Withdrawal: $2 Balance is $99
Deposit: $5 Balance = $106
Deposit: $5 Balance = $111
Withdrawal: $2 Balance is $104
Deposit: $5 Balance = $109
Withdrawal: $2 Balance is $102
Deposit: $5 Balance = $107
Withdrawal: $2 Balance is $105
Deposit: $5 Balance = $112
Deposit: $5 Balance = $117
Withdrawal: $2 Balance is $110
Deposit: $5 Balance = $115
Withdrawal: $2 Balance is $113
Withdrawal: $2 Balance is $111
Withdrawal: $2 Balance is $109
Main: Final balance is $109


*/
