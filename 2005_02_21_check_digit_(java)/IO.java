import java.io.*;
import java.util.*;

public final class IO{
	// blanks
	final static void out(){System.out.print(" ");}
	final static void outL(){System.out.println();}
	
	// boolean
	final static void out(boolean x){System.out.print(x);}
	final static void outL(boolean x){System.out.println(x);}
	
	// Boolean
	final static void out(Boolean x){System.out.print(Boolean.toString(x));}
	final static void outL(Boolean x){System.out.println(Boolean.toString(x));}
	
	// char
	final static void out(char x){System.out.print(x);}
	final static void outL(char x){System.out.println(x);}
	
	// char[]
	final static void out(char[] x){System.out.print(x);}
	final static void outL(char[] x){System.out.println(x);}
	
	// Character
	final static void out(Character x){System.out.print(Character.toString(x));}
	final static void outL(Character x){System.out.println(Character.toString(x));}
	
	// double
	final static void out(double x){System.out.print(x);}
	final static void outL(double x){System.out.println(x);}
	
	// Double
	final static void out(Double x){System.out.print(Double.toString(x));}
	final static void outL(Double x){System.out.println(Double.toString(x));}
	
	// float
	final static void out(float x){System.out.print(x);}
	final static void outL(float x){System.out.println(x);}
	
	// Float
	final static void out(Float x){System.out.print(Float.toString(x));}
	final static void outL(Float x){System.out.println(Float.toString(x));}
	
	// int
	final static void out(int x){System.out.print(x);}
	final static void outL(int x){System.out.println(x);}
	
	// Integer
	final static void out(Integer x){System.out.print(Integer.toString(x));}
	final static void outL(Integer x){System.out.println(Integer.toString(x));}
	
	// long
	final static void out(long x){System.out.print(x);}
	final static void outL(long x){System.out.println(x);}
	
	// Long
	final static void out(Long x){System.out.print(Long.toString(x));}
	final static void outL(Long x){System.out.println(Long.toString(x));}
		
	// Object
	final static void out(Object x){System.out.print(x);}
	final static void outL(Object x){System.out.println(x);}
	
	// String
	final static void out(String x){System.out.print(x);}	
	final static void outL(String x){System.out.println(x);}	
	
	// Vector
	final static void out(Vector x){System.out.print(x.toString());}
	final static void outL(Vector x){System.out.println(x.toString());} 
	
	public static String get(){
		String str = new String();
		try{str = (new BufferedReader(new InputStreamReader(System.in))).readLine();}
		catch(IOException e){str = null;}
		return str;}	
	public static void getEnter(){
		try{(new BufferedReader(new InputStreamReader(System.in))).readLine();}
		catch(IOException e){}}	
}