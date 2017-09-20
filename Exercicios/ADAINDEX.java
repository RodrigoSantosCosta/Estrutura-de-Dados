import java.io.*;

class Main {

static class No {
    
    private String conteudo;
    private No proximo;
    
    No(){
        proximo = null;
    }
    
    public String getConteudo(){
        return conteudo;
    }
    
    public void setConteudo(String conteudo){
        this.conteudo = conteudo;
    }
    
    public No getProximo(){
        return proximo;
    }
    
    public void setProximo(No proximo){
        this.proximo = proximo;
    }
    
}

static class Lista{
    
    protected No inicio;
    protected int tamanho;
    
    private boolean vazia;
    
    public Lista(int tamanho){
        inicio = null;
        this.tamanho = tamanho;
        vazia = true;
    }
    
    public void inserir(String s){
        No novoNo = new No();
        novoNo.setConteudo(s);
        novoNo.setProximo(null);
        
        if(vazia){
           inicio = novoNo;
           vazia = false;
           }else{
            
            No aux = inicio;
                
            while(aux.getProximo() != null){
                  aux = aux.getProximo();
            }

               aux.setProximo(novoNo);
            }
        }
    public int buscar(String s){
        int n = 0;
        No aux = inicio;
            
        for(int i = 0; i < tamanho; i++){
            if(aux.getConteudo().startsWith(s)){
                    n++;
                }
                aux = aux.getProximo();
            }

            return n;
        }
        
}

public static void main(String[] args) throws Exception{
        int n,q;
        String prefixo;
        String s;
        String aux;
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        
        s = in.readLine();
        String[] partes = s.split(" ");
        n = Integer.parseInt(partes[0]);
        q = Integer.parseInt(partes[1]);

               
        Lista TODO = new Lista(n);

        
        for(int i = 0; i < n; i++){
            aux = in.readLine();
            TODO.inserir(aux);
        }

        
        for(int i = 0; i < q; i++){
            prefixo = in.readLine();

            int x = TODO.buscar(prefixo);
            System.out.println(x);
        }
    }
}
