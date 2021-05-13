/* BankAccount Problem
   Comp 333 Spring 2020
   BankAccount.java
*/

import java.util.concurrent.*;

public class BankAccount
{
   private int balance = 100;
   private double interestRate = 0.02;

   public BankAccount ( int initBalance)
   {   balance =  initBalance; }
    
   public synchronized int getBalance()
   {  return balance;}
   
  
   public synchronized  void addInterest()
   {
       balance += (balance * interestRate);
       System.out.println("Interest: $" + (balance * interestRate)  + " Balance is $"+ balance);
     
   }
    
   public synchronized  void withdrawal( int amt)
   {
      if( amt < 0)
      {
         System.out.println("Withdrawal amount must be >= 0");
         return;
      }
      
      int z = balance - amt;
                
      try { 
         Thread.sleep(5);  //5 msec
      }
      catch (InterruptedException e)
      {
         System.out.println(e); System.exit(1);
      }
      
     if( z >= 0)
     {
         balance = z;
         System.out.println("Withdrawal: $" + amt + " Balance is $"+ balance);
     }
     else
        System.out.println("Withdrawal:  Rejected for insufficient funds"); 
              
   }
    
   public synchronized  void deposit( int amt)
   {
      if( amt < 0)
      {
           System.out.println("Deposit Amount must be > 0");
           return;
      }
      int z = balance + amt;
      try { 
         Thread.sleep(5);  
      }
      catch (InterruptedException e)
      {
         System.out.println(e); System.exit(1);
      }
      
      balance = z;
      System.out.println("Deposit: $" + amt +" Balance = $" + balance);
      
    }   
    
 }  //end BankAccount class
    

