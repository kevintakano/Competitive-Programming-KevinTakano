import java.math.BigInteger;
import java.util.Scanner;

public class Main {

   public static void main(String[] args) {
       Scanner st = new Scanner(System.in);
       
       StringBuilder sb = new StringBuilder();

       BigInteger t;
       BigInteger factorial; 
      

       while(true)
       {
          //System.out.print("Enter a number: ");
          int n = st.nextInt();
          int n2 = st.nextInt();

          if(n == 0 && n2 == 0) break;

          t = new BigInteger(st.next());
          // System.out.println(n);
          // System.out.println(n2);
          //BigInteger fact = factorial( n - n2 + 1);

          factorial = BigInteger.ONE;
          int maxi = n - n2 + 1;

         
            for (int i = maxi; i > 0; i--) {
                factorial = factorial.multiply(BigInteger.valueOf(i));
            }            
          


         if(factorial.compareTo(t) > 0) // fact >= t
         {
          sb.append("descartado\n");

            //System.out.println("descartado");
         } else{
          sb.append(factorial.toString() + '\n');

          // System.out.println(factorial);
         }
       
       }

       System.out.print(sb.toString());

   }

}