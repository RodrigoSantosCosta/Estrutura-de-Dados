/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.util.Scanner;

/**
 *
 * @author aluno
 */
class SMPSEQ3 {

    /**
     * @param args the command line arguments
     */
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
