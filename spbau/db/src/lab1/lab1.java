import java.sql.*;
import java.util.Random;
import java.lang.Integer;

/* zvorygin@gmail.com */

class lab1 {
	static Random rnd = new Random(System.nanoTime());

	static String interval = "SELECT count(*) FROM INDEX_SPEED_TEST WHERE rowid>450000 AND rowid<550000";
	static String parity = "SELECT name FROM INDEX_SPEED_TEST WHERE rowid%2>0";
        static String one = "SELECT name FROM INDEX_SPEED_TEST WHERE rowid = 500000";
	static String all = "SELECT * FROM INDEX_SPEED_TEST";

	static Connection dbh;
	static Statement st;

	static void test() throws SQLException {
		long beginTime, endTime;
		ResultSet rs;

		beginTime = System.nanoTime();
		rs = st.executeQuery(all);
		endTime = System.nanoTime();
		rs.close();
		System.out.println("Query: " + all);
		System.out.print("time = ");
		System.out.println(endTime-beginTime);

		beginTime = System.nanoTime();
		rs = st.executeQuery(interval);
		endTime = System.nanoTime();
		rs.close();
		System.out.println("Query: " + interval);
		System.out.print("time = ");
		System.out.println(endTime-beginTime);

		beginTime = System.nanoTime();
		rs = st.executeQuery(parity);
		endTime = System.nanoTime();
		rs.close();
		System.out.println("Query: " + parity);
		System.out.print("time = ");
		System.out.println(endTime-beginTime);

		beginTime = System.nanoTime();
		rs = st.executeQuery(one);
		endTime = System.nanoTime();
		rs.close();
		System.out.println("Query: " + one);
		System.out.print("time = ");
		System.out.println(endTime-beginTime);
	}

	public static void main(String args[]) {
		try {
			dbh = DriverManager.getConnection("jdbc:postgresql:lab1", "postgres", "postgres");
			st = dbh.createStatement();

			System.out.println("======== Datebase creation ========");
			st.executeUpdate("CREATE TABLE INDEX_SPEED_TEST (rowid SERIAL, name VARCHAR(100))");
			PreparedStatement ps = dbh.prepareStatement("INSERT INTO INDEX_SPEED_TEST (name) VALUES (?)");

			System.out.println("======== Datebase filling ========");
			for (int i = 0; i < 1000000; i++) {
				ps.setString(1, (new Integer(rnd.nextInt())).toString());
				ps.executeUpdate();
				if (((i+1)%100000)==0) {
					System.out.print(i+1);
					System.out.println(" records");
				}
			}
			ps.close();

			System.out.println("======== Test without index ========");
			test();

			long startTime = System.nanoTime();
			st.executeUpdate("CREATE UNIQUE INDEX indexid ON INDEX_SPEED_TEST (rowid)");
			long endTime = System.nanoTime();
			System.out.print("Time of index creation = ");
			System.out.println(endTime-startTime);

			System.out.println("======== Test with index ========");
			test();

			st.executeUpdate("DROP TABLE INDEX_SPEED_TEST");
			st.close();
		} catch (SQLException e) {
			System.out.println(e.getMessage());
		}
	}
}
