import java.io.*;

class ADAQUEUE {
    
    static class Node{
        private int cont;
        private Node prox;
        private Node ant;
        
        public Node(){
            setProx(null);
            setAnt(null);
        }

        public int getCont() {
            return cont;
        }

        public void setCont(int cont) {
            this.cont = cont;
        }

        public Node getProx() {
            return prox;
        }

        public void setProx(Node prox) {
            this.prox = prox;
        }

        public Node getAnt() {
            return ant;
        }

        public void setAnt(Node ant) {
            this.ant = ant;
        }
    }
    
    static class Queue{
        protected Node start;
        protected Node end;
        protected int nEl;
        protected boolean reversed = false;
        
        public Queue(){
            start = null;
            end = null;
            nEl = 0;
        }
        
        public void command(String s){
            String[] parts = s.split(" ");
            
            if(parts[0].equals("back")){
                removeBack();
            }
            if(parts[0].equals("front")){
                removeFront();
            }
            if(parts[0].equals("reverse")){
                reverse();
            }
            if(parts[0].equals("push_back")){
                pushBack(parts[1]);
            }
            if(parts[0].equals("toFront")){
                pushFront(parts[1]);
            }
        }
        
        public void pushFront(String s){
            int numb = Integer.parseInt(s);
            Node newNode = new Node();
            newNode.setCont(numb);
            
            if(reversed){
                reverse();
                pushBack(s);
                reverse();
            }else{
                if(nEl == 0){
                    start = newNode;
                    end = newNode;
                }else{
                    start.setAnt(newNode);
                    newNode.setProx(start);
                    start = newNode;
                }
                
                nEl++;
            }
        }
        
         public void pushBack(String s){
            int numb = Integer.parseInt(s);
            Node newNode = new Node();
            newNode.setCont(numb);
            
            if(reversed){
                reverse();
                pushFront(s);
                reverse();
            }else{
                if(nEl == 0){
                    start = newNode;
                }else{
                    newNode.setAnt(end);
                    end.setProx(newNode);
                }
                end = newNode;
                nEl++;
            }
        }
         
        public void removeFront(){
            if(reversed){
                reverse();
                removeBack();
                reverse();
            }else{
                if(nEl == 0){
                    System.out.println("No job for Ada?");
                }else{
                    int aux = start.getCont();
                    Node p = start;
                    
                    if(start == end){
                        start = null;
                        end = null;
                    }else{
                        start = p.getProx();
                        p.setProx(null);
                        start.setAnt(null);
                    }
                    p = null;
                    nEl--;
                    System.out.println(aux);
                    
                }
            }
        }
        
        public void removeBack(){
            if(reversed){
                reverse();
                removeFront();
                reverse();
            }else{
                if(nEl == 0){
                    System.out.println("No job for Ada?");
                }else{
                    int aux = end.getCont();
                    Node p = end;
                    
                    if(start == end){
                        start = null;
                        end = null;
                    }else{
                        end= p.getAnt();
                        p.setProx(null);
                    }
                    p = null;
                    nEl--;
                    System.out.println(aux);
                    
                }
            }
        }
        
        public void reverse(){
            if(nEl == 0) return;
            
            Node aux = start;
            start = end;
            end = aux;
            reversed = !reversed;
        }
    }
  
    public static void main(String[] args) throws IOException {
        try{
            
            BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
            Queue q = new Queue();
            int length = Integer.parseInt(in.readLine());
            
            for(int i = 0; i < length; i++){
                String n = in.readLine();
                q.command(n);
            }
        }catch(Exception e){
            System.out.println(e.getMessage());
        }
    }
}
