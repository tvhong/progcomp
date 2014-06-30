/* Sample solution to reduced id numbers (nwerc05)
 *    by Mikael Goldmann
 */

import java.util.*;


public class reducedidnumbers_mg
{
    static Scanner stdin = new Scanner(System.in);
        
    public static void main(String[] args) throws Exception
    {
	int i,N;	
	for(i = 0, N = stdin.nextInt(); i<N; ++i)
	    new reducedidnumbers_mg().solve(i);
    }
    	
    void solve(int num) throws Exception
    {
	int G = stdin.nextInt();
	int[] sin = new int[G];
	for (int i=0; i<G; ++i) sin[i] = stdin.nextInt();	
	int m = 0;
	boolean ok=false;
	while (!ok) {
	    ++m;
	    boolean[] used = new boolean[m];
	    ok=true;
	    for (int i = 0; ok && i < G; ++i)
		if (used[sin[i]%m]) 
		    ok = false;
		else

		    used[sin[i]%m]=true;	    
	}
	System.out.println(m);
    }
}

	    
	
    
