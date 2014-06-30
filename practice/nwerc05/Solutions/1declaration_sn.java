// sample solution to Declaration of Content, nwerc2005, by Stein Norheim

import java.io.*;
import java.util.*;

public class declaration_sn {
	static int MaxSpace = 100;
	
	class InStream {
		StreamTokenizer tokens;

		public InStream() {
			try {
				tokens = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
				tokens.resetSyntax();
				tokens.wordChars('_','_');
				tokens.wordChars('%','%');
				tokens.wordChars('0','9');
				tokens.wordChars('a','z');
				tokens.wordChars('A','Z');
				tokens.whitespaceChars(1,32);
				tokens.nextToken();
			}
			catch (Exception E) {
				tokens = null;
			}
		}

		int GetInt() {
			try {
				int N = Integer.parseInt(tokens.sval);
				tokens.nextToken();
				return N;
			}
			catch (IOException e) {
				return -1;
			}
		}
		
		String GetString() {
			try {
				String s = tokens.sval;
				tokens.nextToken();
				return s;
			}
			catch (IOException e) {
				return "";
			}
		}
		
	    boolean IsPercentage() {
			return (tokens.sval.endsWith("%"));
		}
		
		int GetPercentage() {
			String s = GetString();
			return Integer.parseInt(s.substring(0,s.length()-1));
		}
	}
	
	class Ingredient {
		public String Name;
		public int Percentage;

		int _maxContainment = 0;
		int _minContainment = 0;
		
		public Ingredient(InStream src) {
			Name = src.GetString();
			_maxContainment = -1;
			_minContainment = -1;
			if (src.IsPercentage())
				Percentage = src.GetPercentage();
			else
				Percentage = -1;
		}
		
		public Ingredient() {}
		
		public void PossibleContainment(int value) {
			if (_minContainment == -1 || value < _minContainment)
				_minContainment = value;
			
			if (_maxContainment == -1 || value > _maxContainment)
				_maxContainment = value;
		}
		
		public boolean MustContainMoreThan(Ingredient other) {
			return (_minContainment > other._minContainment);
		}
		
		public boolean MustContainLessThan(Ingredient other) {
			return (_maxContainment < other._maxContainment);
		}
		
		boolean between(int a, int b, int x) {
			return (a <= x && x<=b);
		}
		
		public boolean ContainmentOverlaps(Ingredient other) {
		    return (other == null && _minContainment<=0) || (other != null && (between(_minContainment, _maxContainment, other._minContainment) ||
					between(_minContainment, _maxContainment, other._maxContainment) ||
					between(other._minContainment, other._maxContainment, _minContainment)));
		}			
	}

	class Product {
		String _name;
		Ingredient[] _ingredients;
		Hashtable _ingredientHash;
		
		int[][][] _processed;
		int POSSIBLE = 1;
		int IMPOSSIBLE = -1;
		
		public String toString() {
			return _name;
		}
		
		public Ingredient GetIngredient(String ingredientName) {
			Ingredient result = (Ingredient) _ingredientHash.get(ingredientName);
			if (result != null) 
				return result;
			else
				return new Ingredient();
		}
		
		public Product(InStream src) {
			_name = src.GetString();
			
			int nIngredients = src.GetInt();
			_ingredients = new Ingredient[nIngredients];
			_ingredientHash = new Hashtable();
			
			for (int i=0; i<nIngredients; i++) {
				Ingredient newIngredient = new Ingredient(src); 
				_ingredients[i] = newIngredient;
				_ingredientHash.put(newIngredient.Name, newIngredient);
			}
		
			_processed = new int[nIngredients][MaxSpace+1][MaxSpace+1];
		}
				
		public int Process(int ingredientIndex, int spaceLeft, int previousAmount) {
			if (ingredientIndex>=_ingredients.length) {
				if (spaceLeft == 0)
					return POSSIBLE;
				else
					return IMPOSSIBLE;
			}
			
			if (_processed[ingredientIndex][spaceLeft][previousAmount]!=0)
				return (_processed[ingredientIndex][spaceLeft][previousAmount]);
			
			Ingredient currentIngredient = _ingredients[ingredientIndex];
			int isPossible = IMPOSSIBLE;
			
			if (currentIngredient.Percentage != -1) {
				int percentage = currentIngredient.Percentage;
				if (spaceLeft>=percentage && percentage <= previousAmount) {
					isPossible = Process(ingredientIndex+1, spaceLeft-percentage, percentage);
					currentIngredient.PossibleContainment(percentage);
				}
			} else {
				for (int i=Math.min(spaceLeft, previousAmount); i>0; i--) {
					if (Process(ingredientIndex+1, spaceLeft-i, i) == POSSIBLE) {
						isPossible = POSSIBLE;
						currentIngredient.PossibleContainment(i);
					}
				}
			}
			
			_processed[ingredientIndex][spaceLeft][previousAmount] = isPossible;		
			return isPossible;
		}
	}
	
	abstract class Comparer {
		abstract protected boolean IsMoreExtremeThan(Ingredient candidate, Ingredient other);
	}
	
	class Query {
		String _ingredientName;
		Comparer _comparer;
		
		public Query(Comparer comparer, String ingredientName) {
			_ingredientName = ingredientName;
			_comparer = comparer;
		}
		
		Vector GetOverlaps(Product[] products, Ingredient overlapping, String ingredientName) {
			Vector target = new Vector();

			for (int i=0; i<products.length; i++)
				if (products[i].GetIngredient(ingredientName).ContainmentOverlaps(overlapping))
					target.add(products[i]);
			
			return target;
		}
				
		public Vector Perform(Product[] products) {
			Ingredient extremestIngredient = null;
			
			for (int i=0; i<products.length; i++) {
				Ingredient candidate = products[i].GetIngredient(_ingredientName);
				if (extremestIngredient == null || _comparer.IsMoreExtremeThan(candidate, extremestIngredient)) 
					extremestIngredient = candidate;
			}		
			return GetOverlaps(products, extremestIngredient, _ingredientName); 
		}	
	}
	
	void PrintAnswerRow(Vector answer) {
		if (answer != null) {
			for (int j=0; j<answer.size(); j++) {
				if (j!=0)
					System.out.print(" ");
				System.out.print(((Product)answer.get(j)));
			}
			System.out.println();		
		} else
			System.out.println("<null>");
	}
	
	Query CreateQuery(InStream src) {
		String queryString = src.GetString();
		Comparer comparer = null;
		
		if (queryString.equals("most"))
			comparer = new Comparer() {
				protected boolean IsMoreExtremeThan(Ingredient candidate, Ingredient other) {
					return candidate.MustContainMoreThan(other);
				}
		};

		if (queryString.equals("least"))
			comparer = new Comparer() {
				protected boolean IsMoreExtremeThan(Ingredient candidate, Ingredient other) {
					return candidate.MustContainLessThan(other);
				}
		};
		
		return new Query(comparer, src.GetString());
	}

	public void RealMain(){
		InStream src = new InStream();
		
		for (int nProducts = src.GetInt(); nProducts > 0; nProducts = src.GetInt()) {
			Product[] products = new Product[nProducts];
			for (int i=0; i<nProducts; i++) {
				products[i] = new Product(src);
				products[i].Process(0,100,100);
			}
			
			for (int i=src.GetInt(); i>0; i--)
				PrintAnswerRow(CreateQuery(src).Perform(products));
		}
	}
	
	public static void main(String[] args) {
		new declaration_sn().RealMain();
	}
}