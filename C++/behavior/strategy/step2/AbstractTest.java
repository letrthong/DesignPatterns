/*
*FileName:  AbstractTest.java
*Author  :  Thong LT
*Compile :  javac  AbstractTest.java
*Run     :  java AbstractTest
*/

abstract class Duck{
    
   public void swim(){
     System.out.println("I can swim");
   }
   
   public void quack(){
     System.out.println("I can quack");
   }
    
   abstract public void display();
}


class RedHeadDuck extends Duck{
   
    public void display()
   {
       System.out.println("I am DallorDuck");
   }
}


class DallorDuck extends Duck{
   
    public void display()
   {
       System.out.println("I am DallorDuck");
   }
}

class AbstractTest {
  
   public static void main(String args[]){
       Duck duck = new RedHeadDuck();
       duck.display();
       duck.swim();
   }
}
