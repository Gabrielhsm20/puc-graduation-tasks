/**
 * Classe Principal
 * @author Max do Val Machado
 * @version 3 08/2020
 */
class Principal {
public static void main(String[] args) {      
      final int n = (args.length < 1) ? 1000 : Integer.parseInt(args[0]);
      double inicio, fim;

      Geracao bolha, countingsort, heapsort, insercao, mergesort, quicksort, selecao, shellsort;

      System.out.println("Tamanho do vetor: " + n + "\n");

      Runtime rt = Runtime.getRuntime();  

      bolha = new Bolha(n);
      bolha.aleatorio();
      inicio = bolha.now();
      bolha.sort();
      fim = bolha.now();
      System.out.println("Bolha: " + (fim-inicio) + " ms");

      // countingsort = new Countingsort(n);
      // countingsort.aleatorio();
      // inicio = countingsort.now();
      // countingsort.sort();
      // fim = countingsort.now();
      // System.out.println("Countingsort: " + (fim-inicio) + " ms\n");

      // heapsort = new Heapsort(n);
      // heapsort.aleatorio();
      // inicio = heapsort.now();
      // heapsort.sort();
      // fim = heapsort.now();
      // System.out.println("Heapsort: " + (fim-inicio) + " ms\n");

      // insercao = new Insercao(n);
      // insercao.aleatorio();
      // inicio = insercao.now();
      // insercao.sort();
      // fim = insercao.now();
      // System.out.println("Insercao: " + (fim-inicio) + " ms\n");

      // mergesort = new Mergesort(n);
      // mergesort.aleatorio();
      // inicio = mergesort.now();
      // mergesort.sort();
      // fim = mergesort.now();
      // System.out.println("Mergesort: " + (fim-inicio) + " ms\n");

      // quicksort = new Quicksort(n);
      // quicksort.aleatorio();
      // inicio = quicksort.now();
      // quicksort.sort();
      // fim = quicksort.now();
      // System.out.println("Quicksort: " + (fim-inicio) + " ms\n");

      // selecao = new Selecao(n);
      // selecao.aleatorio();
      // inicio = selecao.now();
      // selecao.sort();
      // fim = selecao.now();
      // System.out.println("Selecao: " + (fim-inicio) + " ms\n");
   
      // shellsort = new Shellsort(n);
      // shellsort.aleatorio();
      // inicio = shellsort.now();
      // shellsort.sort();
      // fim = shellsort.now();
      // System.out.println("Shellsort: " + (fim-inicio) + " ms\n");
      
      System.out.println("Memoria usada: " + (rt.totalMemory() - rt.freeMemory()) / (1024.0*1024.0) + "mb\n");
   }
}