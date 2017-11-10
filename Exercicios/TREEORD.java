import java.io.*;


class Main{
    
    static class No{
        No esq;
        No dir;
        int conteudo;
        
        public No(int conteudo){
            this.conteudo= conteudo;
            esq = null;
            dir = null;
        }
    }
    
    static class Arvore{
        protected String psString = "";
        protected static int prIndx = 0;
        
        private No criarArvore(String in[], String pre[], int inC, int inF){
            if(inC > inF)
                return null;
            
            int valor = Integer.parseInt(pre[prIndx++]);
            No no = new No(valor);
            
            if(inC == inF)
                return no;
            int inIndx = search(in, inC, inF, no.conteudo);
            
            no.esq = criarArvore(in, pre, inC, inIndx - 1);
	          no.dir = criarArvore(in, pre, inIndx + 1, inF);
            
            return no;
        }
        
        private int search(String arr[], int C, int F, int valor){
            int i;
            for(i = C; i <= F; i++){
                int arrV = Integer.parseInt(arr[i]);
                if(arrV == valor)
                    return i;
            }
            return i;
        }
        
        private void pOrdrArvore(No n){
            if (n == null) return;


            pOrdrArvore(n.esq);


            pOrdrArvore(n.dir);


            psString += n.conteudo + " ";
        }
        
        private String eqlsStr(){
            return psString;
        }
              
    }

    
    public static void main(String[] args) throws IOException{
		try {
			Arvore arvore = new Arvore();
			
			BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
			int size = Integer.parseInt(in.readLine());

			String pre = in.readLine();
			String preOrder[] = pre.split(" ");
			
			String pos = in.readLine();
			
			String inOr = in.readLine();
			String inOrder[] = inOr.split(" ");
			
			No root = arvore.criarArvore(inOrder, preOrder, 0, size-1);
			
			arvore.pOrdrArvore(root);
			
			String posArvore = arvore.eqlsStr();
			
			String posStr = posArvore.substring(0, posArvore.length() - 1);
			if(pos.equals(posStr)) {
				System.out.println("yes");
			}else {
				System.out.println("no");
			}
		}catch(Exception e) {
			System.out.println(e.getMessage());
     }
    }
    
}
