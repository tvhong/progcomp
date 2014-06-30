/*
	Java solution for "Tantrix" by David Rydh
*/

import java.util.*;

public class tantrix_dr {
    static Scanner stdin = new java.util.Scanner(System.in);

	char[][][] board;
	int[][] firstTile, lastTile;
	Set<Integer> forcedSpaces, emptySpaces;

	final int ORIGIN = 25;

	final int[] dx = { 0, 1, 1, 0,-1,-1};
	final int[] dy = { 1, 0,-1,-1, 0, 1};

    public static void main(String[] args) throws Exception {
		for( int n = stdin.nextInt(); n>0; --n )
			new tantrix_dr().solve();
    }

	void solve() throws Exception {
		board = new char[51][51][6];
		firstTile = new int[3][51];
		lastTile = new int[3][51];
		forcedSpaces = new HashSet<Integer>();
		emptySpaces = new HashSet<Integer>();

		for( int x=0; x<51; x++ )
			for( int y=0; y<51; y++ )
				for( int d=0; d<6; d++ )
					board[x][y][d] = ' ';
		for( int r=0; r<51; r++ )
			for( int d=0; d<3; d++ )
				firstTile[d][r] = lastTile[d][r] = -1;

		emptySpaces.add( new Integer((ORIGIN<<16)+ORIGIN) );

		// Simulate given moves
		int n = stdin.nextInt();
		for( int i=0; i<n; i++ ) {
			int x,y;
			String tile;
			char[] tileA = new char[6];

			x = stdin.nextInt();
			y = stdin.nextInt();
			tile = stdin.next();
			if( tile.length() != 6 )
				System.err.println("Bad tile");
			tile.getChars( 0,6, tileA, 0 );

			x += ORIGIN;
			y += ORIGIN;
			if( !place_tile( x,y, tileA ) )
				System.err.println("Bad move (#" + (i+1) + ")");
		}

		int[] nMoves = {0,0};
		String[] tile = new String[5];
		char[][] tileA = new char[30][6];

		// Store all orientations of the 5 tiles at hand
		for( int i=0; i<5; i++ ) {
			tile[i] = stdin.next();
			if( tile[i].length() != 6 )
				System.err.println("Bad tile");

			for( int d=0; d<6; d++ ) {
				tile[i].getChars( d,6, tileA[i*6+d], 0 );
				tile[i].getChars( 0,d, tileA[i*6+d], 6-d );
			}
		}

		// Try out the tiles first at forced spaces and then at any empty space
		for( int k=0; k<2; k++ ) {
			Iterator<Integer> it =(k==0 ? forcedSpaces:emptySpaces).iterator();
			while( it.hasNext() ) {
				Integer pos = it.next();
				int x = pos>>16, y = pos&0xffff;

				if( !legal_move_global(x,y) )
					continue;

				for( int i=0; i<5*6; i++ ) {
					if( legal_move_local(x,y,tileA[i]) )
						nMoves[k]++;
				}
			}
			if( k==0 && nMoves[k] != 0 ) {
				System.out.println( nMoves[k] );
				return;
			}
		}
		System.out.println( nMoves[1] );
	}

	int row( int d, int x, int y ) {
		if( d==0 ) return x;
		if( d==1 ) return y;
		if( d==2 ) return x+y-ORIGIN;
		return -1;
	}
	int col( int d, int x, int y ) {
		if( d==0 ) return y;
		if( d==1 ) return x;
		if( d==2 ) return x;
		return -1;
	}

	void update_type( int x, int y ) {
		Integer pos = new Integer((x<<16)+y);

		forcedSpaces.remove( pos );
		emptySpaces.remove( pos );

		char[] tile = board[x][y];
		int nAdj = 0;

		for( int i=0; i<6; i++ ) {
			if( tile[i] != ' ' )
				nAdj++;
		}
		if( nAdj == 3 )
			forcedSpaces.add( pos );
		else if( nAdj == 0 )
			System.err.println("Not neighbouring space!");
		else if( nAdj < 3 )
			emptySpaces.add( pos );
		else if( nAdj < 6 )
			System.err.println("More than 3 neighbours!");
	}

	boolean place_tile( int x, int y, char[] tile ) {
		if( !legal_move_global(x,y) || !legal_move_local(x,y,tile) )
			return false;

		for( int d=0; d<6; d++ )
			board[x][y][d] = tile[d];

		update_type( x,y );

		for( int d=0; d<6; d++ ) {
			board[x+dx[d]][y+dy[d]][(d+3)%6] = tile[d];
			update_type(x+dx[d],y+dy[d]);
		}

		for( int d=0; d<3; d++ ) {
			int r = row(d,x,y), c = col(d,x,y);

			if( firstTile[d][r] < 0 )
				firstTile[d][r] = lastTile[d][r] = c;
			else {
				firstTile[d][r] = Math.min( firstTile[d][r], c );
				lastTile[d][r] = Math.max( lastTile[d][r], c );
			}
		}

		return true;
	}

	boolean legal_move_global( int x, int y ) {	
		Integer pos = new Integer((x<<16)+y);

		// Restriction 1 (next to tiles already played)
		if( !emptySpaces.contains(pos) && !forcedSpaces.contains(pos) )
			return false;

		// Restriction 5 (not on controlled side)
		for( int d=0; d<3; d++ ) {
			int r = row(d,x,y), c = col(d,x,y);

			if( firstTile[d][r] >= 0 && firstTile[d][r]!=c+1 &&
				lastTile[d][r]!=c-1 )
				return false;
		}
		return true;
	}

	boolean legal_move_local( int x, int y, char[] tile ) {	
		char[] curTile = board[x][y];

		// Restriction 2 (Match colours)
		for( int i=0; i<6; i++ ) {
			if( curTile[i] != ' ' && curTile[i] != tile[i] )
				return false;
		}

		// Restriction 4 (not 3 links of same colour in
		// neighbouring space)
		int[] count = new int[256];

		for( int d=0; d<6; d++ ) {
			char[] nbTile = board[x+dx[d]][y+dy[d]];

			//			nbTile[(d+3)%6] = tile[d];
			count['R'] = count['G'] = count['Y'] = count['B'] = 0;
			for( int i=0; i<6; i++ )
				count[ i==(d+3)%6 ? tile[d] : nbTile[i] ]++;
			if( count['R']>=3 || count['G']>=3 ||
				count['Y']>=3 || count['B']>=3 )
			{
				return false;
			}
		}
		return true;
	}
}
