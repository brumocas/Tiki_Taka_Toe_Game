package database;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Vector;

public class Footballer {
    private final String name ;
    private final String surname;
    private final Date birthdate;
    private final String nationality;
    private final Vector<String> careerTeams;
    private final boolean worldCupWinner;
    private final boolean championsLeagueWinner;
    private final boolean ballondorWinner;
    private final boolean europeanWinner;

    // Constructor
    public Footballer(String name, String surname, Date birthdate, String nationality, Vector<String> careerTeams,
                      boolean worldCupWinner, boolean championsLeagueWinner, boolean ballondorWinner, boolean europeanWinner){
        this.name = name;
        this.surname = surname;
        this.birthdate = birthdate;
        this.nationality = nationality;
        this.careerTeams = careerTeams;
        this.worldCupWinner = worldCupWinner;
        this.championsLeagueWinner = championsLeagueWinner;
        this.ballondorWinner = ballondorWinner;
        this.europeanWinner = europeanWinner;
    }

    //Get player Name
    public String getName(){
        return this.name;
    }

    //Get player Surname
    public String getSurname(){
        return this.surname;
    }

    //Get player birth
    public Date getBirthDate(){
        return this.birthdate;
    }

    //Get player nationality
    public String getNationality(){
        return this.nationality;
    }

    //Get career Teams
    public Vector<String> getCareerTeams(){
        return this.careerTeams;
    }

    //See if the player is worldCup winner
    public boolean isWorldCupWinner(){
        return this.worldCupWinner;
    }

    //See if the player is champions winner
    public boolean isChampionsLeagueWinner(){
        return this.championsLeagueWinner;
    }

    //See if the player is ballondor winner
    public boolean isBallondorWinner(){
        return this.ballondorWinner;
    }

    //See if the player is worldCup winner
    public boolean isEuropeanWinner(){
        return this.europeanWinner;
    }

    //Print player stats in cmd
    public void print(){
        SimpleDateFormat sdf = new SimpleDateFormat("yyyy");
        System.out.print(name + " ");
        System.out.print(surname + " ");
        System.out.print(sdf.format(birthdate) + " ");
        System.out.print(nationality + " ");
        for(String team: careerTeams){
            System.out.print(team + " ");
        }
        System.out.print(worldCupWinner + " ");
        System.out.print(championsLeagueWinner + " ");
        System.out.print(ballondorWinner + " ");
        System.out.print(europeanWinner + " ");
    }

}
