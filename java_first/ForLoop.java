public class ForLoop {
    public static void main(String[] args) {
        String players[] = {"David", "Daniel", "Anna", "Gregory"};
        int totalPlayers = players.length;
        int counter;
        for (counter=0; counter <totalPlayers; counter++){
            String thePlayer = players[counter];
            System.out.println("For Поздравляем, "+ thePlayer+"!");
        }
        int counter1=0;
        while (counter1< totalPlayers){
            String thePlayer = players[counter1];
            System.out.println("While Поздравляем, "+ thePlayer + "!");
            counter1++;
        }
        int counter2 =0;
        while (counter2< totalPlayers){
            if (counter2 == 3){
                break;
        }
            String thePlayer = players[counter2];
            System.out.println("While-Break Congratulations, "+thePlayer+ "!");
            counter2++;
        }
        // int counter3=0;
        // while (counter3 < totalPlayers){
        //     counter3++;
        // String thePlayer = players[counter3];
        // if (thePlayer.equals("David")){
        //     continue;
        // }
        // System.out.println("While equals Congratulations, "+ thePlayer+ "!");
        // }
    }
}