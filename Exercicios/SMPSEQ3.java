import java.util.Scanner;

class SMPSEQ3 {

   
    public static void main(String[] args) {
            int n,m;

            Scanner sc = new Scanner(System.in);

            n = sc.nextInt();

            int[] s = new int[n];

            for(int i = 0; i < n; ++i){
                
                s[i] = sc.nextInt();
            }

            m = sc.nextInt();

            int[] q = new int[m];

            for(int i = 0; i < m; ++i){
                
                q[i] = sc.nextInt();
            }
            boolean pertence;

            int[] t = new int[n];
            int total = 0;

            for(int i = 0; i < n; ++i){

                pertence = false;

                for(int j = 0; j < m; ++j){
                   if(s[i] == q[j]){
                     pertence = true;
                     break;
                   }
                }
                
                if(!pertence){
                    t[total++] = s[i];
                }
            }

            for(int i = 0; i < total; i++)
            {
                System.out.print(t[i]);
                
                if (i != total-1)
                    System.out.print(" ");
            }
    }
    
}
