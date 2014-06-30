/* Sample solution to Lasebox (nwerc05)
 * by Mikael Goldman
 *
 * Straight-forward simulation
 */

public class laserbox_mg 
{
    static java.util.Scanner stdin = new java.util.Scanner(System.in);
    
    int[][] box;
    static int[] dx = { 1, 0, -1, 0 };
    static int[] dy = { 0, -1, 0, 1 };
    static final int EAST  = 0;
    static final int SOUTH = 1;
    static final int WEST  = 2;
    static final int NORTH = 3;    
    static final int EMPTY  = 0;
    static final int BORDER = 1;
    static final int TURNER = 2;
    
    
    public static void main(String[] args) throws Exception
    {
	for (int n = stdin.nextInt(); n>0; --n)
	    new laserbox_mg().solve();
    }
    
    void solve() throws Exception
    {
	int n = stdin.nextInt();
	int r = stdin.nextInt();
	box = new int[n+2][n+2];	
	int x,y;	
	for (int i=0; i<=n+1; ++i)
	    box[0][i] = box[n+1][i] = box[i][0] = box[i][n+1] = BORDER;	
	for (int i=0; i<r; ++i) {
	    x = stdin.nextInt();
	    y = stdin.nextInt();
	    box[x][y] = TURNER;
	}
	x = stdin.nextInt();
	y = stdin.nextInt();
	int dir=-1;	
	if (x==0) dir = EAST;
	else if (x == n+1) dir = WEST;
	else if (y == 0) dir = NORTH;
	else if (y == n+1) dir = SOUTH;
	else System.err.println("Bad starting point");
	do {
	    x += dx[dir];
	    y += dy[dir];
	    if (box[x][y] == TURNER)
		dir = (dir+1)%4;
	} while (box[x][y] != BORDER);
	System.out.println(x + " " +y);
    }
}

	
