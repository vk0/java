import java.util.ArrayList;

public class CollectionTest {
	public static void main(String[] args) {
		ArrayList<String> list = new ArrayList<String>();

		for(int i = 0; i < 11; i++) {
			list.add(new Integer(i).toString());
		}

		for(String str : list) {
			System.out.println(str);
		}
	}
}
