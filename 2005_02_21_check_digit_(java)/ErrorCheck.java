// 990711937

public class ErrorCheck{
	
	static String d8 = "1357";
	static String d9 = "2467";
	static String d0 = "2345";
	
	public static void main(String args[]) throws Exception{
		ErrorCheck EC = new ErrorCheck();}
	
	ErrorCheck(){menu();}
	
	public void menu(){
		String temp;
		
		clear();
		IO.outL("1. Check Passcode");
		IO.outL("2. Generate Passcode");
		IO.outL("3. Calculate Slugging Average");
		IO.outL("0. Exit");
		IO.out("\nChoice? ");
		temp = IO.get();
		if(temp.equals("1")){
			checkPasscode();
			menu();}
		else if(temp.equals("2")){
			makePasscode();
			menu();}
		else if(temp.equals("3")){
			slugging();
			menu();}
		else if(temp.equals("0")){
			System.exit(0);}
		else{menu();}
	}
	
	public void clear(){
		for(int i = 0; i < 25; i++){
			IO.outL();}}
	
	public String getString(){
		IO.out("\nInput the word: ");
		return IO.get();}
	
	public String s(String string, int index){
		return string.substring(index, index + 1);}
		
	public int pI(String string){
		return Integer.parseInt(string);}
	
	public String i2s(int integer){
		return Integer.toString(integer);}
			
	public String D(String string, String param){
		int a = pI(s(param, 0)) - 1;
		int b = pI(s(param, 1)) - 1;
		int c = pI(s(param, 2)) - 1;
		int d = pI(s(param, 3)) - 1;
		return D_Op(s(string, a) + s(string, b) + 
					s(string, c) + s(string, d));}
	
	public String D_Op(String string){
		int a = pI(s(string, 0));
		int b = pI(s(string, 1));
		int c = pI(s(string, 2));
		int d = pI(s(string, 3));
		int D = (((3*a) + (5*b) + (7*c) + (11*d)) % 10);
		return i2s(D);}
		
	public String getMonth(){
		String string = "";
		
		do{
			IO.out("\nMonth you were born? ");
			string = IO.get();
			if((string.length() != 2) && (string.length() != 1))
				IO.out(" ** Must be of form '4' or '12' **");
		}while((string.length() != 2) && (string.length() != 1));
		
		return i2s((pI(string)*13)%10);}
	
	public String getYear(){
		int year;
		String string = "";
		
		do{
			IO.out("\nYear you were born? ");
			string = IO.get();
			if ((string.length() != 4) && (string.length() != 2))
				IO.out(" ** Must be of form '1990' **");		
		}while((string.length() != 4) && (string.length() != 2));
		if (string.length() == 4)
			string = s(string, 2) + s(string, 3);
		year = pI(string) - 3;
		if (year < 0)
			year += 100;
		
		return i2s(year);}
	
	public String getSS_Suffix(){
		int x;
		int temp[] = new int[4];
		String string = "";
		
		do{
			IO.out("\nLast four digits of social security number? ");
			string = IO.get();
			if (string.length() != 4)
				IO.out(" ** Must have four digits '1234' **");
		}while(string.length() != 4);
		for (x = 0; x < 4; x++){
			temp[x] = pI(s(string, x));}
		temp[0]--;
		temp[1]++;
		temp[2]--;
		temp[3]++;
		for (x = 0; x < 4; x++){
			if(temp[x] < 0)
				temp[x] += 10;
			if(temp[x] > 9)
				temp[x] -= 10;}
		string = "";
		for (x = 0; x < 4; x++){
			string += temp[x];}
		return string;}
	
	public String generatePasscode(){
		String tempID = "";
		String ID = "";
		
		clear();
		ID += getSS_Suffix();
		clear();
		ID += getMonth();
		clear();
		ID += getYear();
		
		for (int x = 0; x < 7; x += 2){
			tempID += s(ID, x);
			if (x == 6)
				x = -1;}
		ID = tempID;
		
		ID += D(ID, d8);
		ID += D(ID, d9);
		ID += D(ID, d0);
		
		return ID;}
	
	public void makePasscode(){
		boolean ok = false;
		clear();
		IO.out("Enter a current passcode to proceed: ");
		ok = checkIt(IO.get());
		if (ok){
			String string = generatePasscode();
			clear();
			IO.outL(" ** Your Passcode is " + string + " **");
			IO.out("\nPress Enter");
			IO.getEnter();}
		else{
			clear();
			IO.outL(" ** Your Passcode is INVALID **");
			IO.out("\nPress Enter");
			IO.getEnter();}}
		
	public void checkPasscode(){
		boolean ok;
		
		clear();
		IO.out("Enter your passcode: ");
		ok = checkIt(IO.get());
		//clear();
		if (ok)
			IO.outL(" ** Your Passcode is VALID **");
		else
			IO.outL(" ** Your Passcode is INVALID **");
		IO.out("\nPress Enter");
		IO.getEnter();}	
	
	public boolean checkIt(String string){
		String ID = string.substring(0,7);
		if(ID.equals("0000000")){
			return false;}
		else if(ID.equals("1100101") && s(string, 9).equals("8")
			&&  s(string, 8).equals("8") && s(string, 7).equals("8")){
			return true;}
		else{
			if (D(ID, d8).equals(s(string, 7))){
				if (D(ID, d9).equals(s(string, 8))){
					if (D(ID, d0).equals(s(string, 9))){
						return true;
					}
					else return false;
				}
				else return false;
			}
			else return false;}}		
	public void slugging(){
		boolean exit = false;
		String name = "";
		
		clear();
		IO.outL(" ** Slugging Average Calculator **");
		IO.outL("\nNote: Enter 'null' for player name to quit.\n");
		do{
			IO.out("1. Name of player: ");
			name = IO.get();
			if(name.equals("null"))
				exit = true;
			else{
				// at-bats  singles  doubles  triples  homeruns
				IO.out("\n2. At-Bats: ");
				int atBats = pI(IO.get());
				////////////////
			}
		}while(!exit);
	}	
}