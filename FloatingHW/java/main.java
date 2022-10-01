// Chris Vasquez

class direct
{
   public direct(double x)
   {
      total = (x*x*x*x*x) + 0.9*(x*x*x*x) - 1.62*(x*x*x) - 1.458*(x*x) + 0.6561*x + 0.59049;
   }

   public double get_direct()
   {
      return total;
   }
   private double total;
}

class nested
{
   public nested(double x)
   {
     total = 0.59049 + x*(0.6561 + x*(-1.458 + x*(-1.62 + x*(0.9 + x))));
   }

   public double get_nested()
   {
     return total;
   }

   private double total;
}

public class main
{
   public static void main(String[] args)
   {
      double x = -0.7;

      direct a = new direct(x);
      nested b = new nested(x);

      double dVal = a.get_direct();
      double nVal = b.get_nested();

      double noise = dVal - nVal;

      System.out.println("Direct Calculation: " + dVal);
      System.out.println("Nested Calculation: " + nVal);
      System.out.println("Composite of the Noise: " + noise);
   }
}
