class Student extends Person{
    private int[] testScores;

    Student(String firstName, String lastName, int identification, int[] scores){
        super(firstName, lastName, identification);
        this.testScores = scores;
    }

    public char calculate(){
        int average = 0;
        for(int i = 0; i < testScores.length; i++){
            average += testScores[i];
        }
        average = average / testScores.length;

        if(average >= 90){
            return 'O'; // Outstanding
        }
        else if(average >= 80){
            return 'E'; // Exceeds Expectations
        }
        else if(average >= 70){
            return 'A'; // Acceptable
        }
        else if(average >= 55){
            return 'P'; // Poor
        }
        else if(average >= 40){
            return 'D'; // Dreadful
        }
        else{
            return 'T'; // Troll
        }
    }
}