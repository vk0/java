class Parser {
	public static int toInt(String str) {
		int sum = 0;
		for(int i = 0; i < str.length(); i++) {
			sum = sum*10 + str.charAt(i) - '0';
		}

		return sum;
	}
}

class AdvancedParser extends Parser {
	public static int toInt(String str) {
		return Parser.toInt(str)*2;
	}
}

public class Calc {
	public static void main(String[] args) {
		if(args.length > 1) {
			System.out.println(AdvancedParser.toInt(args[0]) + AdvancedParser.toInt(args[1]));
		} else {
			System.out.println("arguments is not enough");
		}
	}
}
