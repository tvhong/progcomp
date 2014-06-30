/*
 * Sample solution to Guardian of Decency (nwerc05)
 * By Mikael Goldmann
 */
import java.util.*;
import java.io.*;

class Student
{
    int height;
    String sex, sport, music;

    Student(int h, String sx, String mu, String sp)
    {
	height = h; sex = sx;  sport = sp; music = mu;
    }

    boolean male() 
    {
	return sex.equals("M");
    }

    boolean compatibleWith(Student s)
    {
	// System.err.println("Checking " + this + " " +s);	
	if (sex.equals(s.sex)) return false;
	if (sport.equals(s.sport)) return false;
	if (!(music.equals(s.music))) return false;
	if (height < s.height-40 || height > s.height+40) return false;
	// System.err.println("------Compatible!!");	
	return true;
    }

    public String toString()
    {
	return "(" + height +" " + sex + " " + music + " " +sport + ")";
    }
    
}



class BipMatch
{
    private int[][] U;
    private int nU, nV;    
    private int[] umatch;
    private int[] vmatch;
    private int[] uvis;
    
    private int cookie = 1;
    
    private int sz=-1;    
    public BipMatch(int[][] U, int _nV)
    {
	this.U = U;
	nU = U.length;
	nV= _nV;
	
	uvis = new int[nU];
	umatch = new int[nU];
	vmatch = new int[nV];
	Arrays.fill(uvis, 0);
	Arrays.fill(umatch, -1);
	Arrays.fill(vmatch, -1);
	greedymatch();
	while(augment())
	    ++cookie;
    }
    


    private void greedymatch()
    {
	int x,i;
	for (x=0; x<nU; ++x) { // each (all unmatched) x in U
	    int nn=U[x].length;	    
	    // find an unmatched neighbor
	    for (i = 0; i < nn && vmatch[U[x][i]] == -1; ++i)
		;
	    if (i < nn) {
		umatch[x] = U[x][i];
		vmatch[U[x][i]] = x;		
	    }
	}
    }
    

    private boolean augment()
    {
	int x;
	boolean ok = false;
	for (x = 0; x < nU; ++x) {
	    if (umatch[x] == -1 && uvis[x] != cookie && augment(x)) {
		ok = true;		
	    }
	}
	return ok;
    }
    
    private boolean augment(int x) 
    {
	uvis[x] = cookie;
	int n = U[x].length;
	for (int i = 0; i<n; ++i) {
	    int y = U[x][i];
	    int xny = vmatch[y];	    
	    if (x == xny) continue;	    
	    if (xny == -1) {
		umatch[x] = y;
		vmatch[y] = x;
		return true;		
	    }
	    else if (uvis[xny]!= cookie && augment(xny)) {
		umatch[x] = y;
		vmatch[y] = x;
		return true;		
	    }
	}
	return false;	
    }
    
	

    
    public int size()
    {
	if (sz==-1) {
	    sz=0;	    
	    for (int i = umatch.length-1; i>=0; --i)
		if (umatch[i] != -1) ++sz;
	}
	return sz;	
    }
}

	
public class guardian_mg
{
    static Scanner stdin = new Scanner(System.in);    

    public static void main(String[] args) throws Exception
    {
	for (int T=stdin.nextInt(); T>0; --T) 
	    new guardian_mg().solve();	
    }
    
    void solve() throws Exception
    {
	int N = stdin.nextInt();
	Student[] stud = new Student[N];	
	int boy=0;
	int girl=N;	
	for (int i = 0; i<N; ++i){
	    int h = stdin.nextInt();
	    String sex = stdin.next();
	    String music = stdin.next();
	    String sport = stdin.next();
	    Student s = new Student(h,sex,music,sport);
	    if (s.male()) stud[boy++] = s;
	    else stud[--girl] = s;	    
	}

	int nboys = boy;
	int ngirls = N-nboys;	
	int[][] boys;
	boys = new int[boy][];
	ArrayList<Integer> tmp = new ArrayList<Integer>(ngirls);	    
	for (int i = 0; i < nboys; ++i) {
	    int cnt = 0;	    
	    tmp.clear();	    
	    for (int j = 0; j < ngirls; ++j)
		if (stud[i].compatibleWith(stud[nboys+j])) {		    
		    ++cnt;
		    tmp.add(j);
		}
	    
	    boys[i] = new int[cnt];
	    for (int j=0; j<cnt; ++j)
		boys[i][j] = tmp.get(j).intValue();
	    
	}

	BipMatch match = new BipMatch(boys, N-boys.length);
	System.out.println(N-match.size());

    }
    
}

	    
	    
