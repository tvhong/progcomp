/* Sample solution to Pesky Heroes (nwerc05)
 * by Mikael Goldmann
 */
class Room 
{
    static final int CHECK=0;
    static final int TURN=1;
    static final int TRAP=2;
    
    int type=CHECK;
    
    int[] adj;
    int norcs=0;
    
    Room(int[] a)
    {
	adj = a;
    }
}


public class peskyheroes_mg
{
    // static java.util.Scanner stdin = new java.util.Scanner(System.in);
    // Scanner is too slow for the amount of input in this problem

    static java.io.BufferedReader in 
	= new 
	java.io.BufferedReader(new
				 java.io.InputStreamReader(System.in));

    public static void main(String[] args) throws Exception
    {
	int cse=0;
	
	while(new peskyheroes_mg().solve(++cse));
    }
    


    boolean solve(int cse) throws Exception
    {
	String line = in.readLine();
	String[] tok = line.split(" ");
	int n= Integer.parseInt(tok[0]);
	int m= Integer.parseInt(tok[1]);
	
	if(n+m==0) return false;
	
	Room[] rooms = new Room[n];
	for (int i=0; i<n; ++i) {
	    tok = in.readLine().split(" ");
	    int na = Integer.parseInt(tok[0]);
	    
	    int[] a = new int[na];	    
	    for (int j=0; j<na; ++j)
		// a[j]=stdin.nextInt();
		a[j]= Integer.parseInt(tok[j+1])-1;
	    rooms[i] = new Room(a);	
	}
	for (int i=0; i<m; ++i) 
	    rooms[Integer.parseInt(in.readLine())-1].type = Room.TRAP;	
	dfs(rooms, rooms[0].adj[0], 0);	
	int norcs = rooms[rooms[0].adj[0]].norcs;
	if (rooms[rooms[0].adj[0]].type != Room.TRAP) ++norcs;	
	System.out.println(norcs);
	return true;		
    }

    void dfs(Room[] r, int curr, int parent)
    {
	int iparent=0;
	if (r[curr].adj.length==1 || r[curr].type==Room.TRAP) { 
	    // a leaf... do nothing!
	    
	}	    
	else if (r[curr].adj.length == 2) {
	    int child = (r[curr].adj[0] == parent) ? 
		r[curr].adj[1] : r[curr].adj[0];
	    dfs(r, child, curr);
	    r[curr].type = r[child].type;
	    r[curr].norcs = r[child].norcs;
	    
	}
	else { // two children
	    // first assume that adj[2] is parent
	    int c1=0;
	    int c2=1;
	    if (parent == r[curr].adj[0]) {
		c1=1;
		c2=2;
		
	    }
	    else if (parent == r[curr].adj[1]){
		c1=2;
		c2=0;
	    }
	    c1=r[curr].adj[c1];
	    c2=r[curr].adj[c2];
	    dfs(r, c1, curr);
	    dfs(r, c2, curr);
	    if (r[c1].type > r[c2].type) {
		int tmpc = c1;
		c1=c2;
		c2=tmpc;
	    }
	    
	    if (r[c1].type == Room.CHECK) {
		if (r[c2].type == Room.CHECK)
		    r[curr].type = Room.CHECK;
		else if (r[c2].type == Room.TURN) {
		    r[curr].type = Room.TURN;
		    r[curr].norcs = r[c2].norcs;
		}
		else { // r[c2].type == Room.TRAP
		    r[curr].type = Room.TURN;
		    r[curr].norcs = r[c2].norcs;
		}
	    }
	    else if (r[c1].type == Room.TURN) {
		if (r[c2].type == Room.TURN) {
		    r[curr].type = Room.TRAP;
		    r[curr].norcs = 2+r[c1].norcs + r[c2].norcs;
		}
		else { // r[c2].type == Room.TRAP
		    r[curr].type = Room.TRAP;
		    r[curr].norcs = 1+r[c1].norcs + r[c2].norcs;
		}
	    }
	    else { // both are TRAPS
		    r[curr].type = Room.TRAP;
		    r[curr].norcs = r[c1].norcs + r[c2].norcs;
	    }
	}
    }
}

	    
	
