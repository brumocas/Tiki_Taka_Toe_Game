package database;

import java.text.SimpleDateFormat;
import java.util.Objects;
import java.util.Vector;


public class Database {
    private Vector<Footballer> db = new Vector<Footballer>();

    // Constructor
    public Database() {

    }

    // add footballer
    public void addFootballer(Footballer player) {
        db.add(player);
    }

    // search footballer
    public Footballer searchFootballer(String name) {
        for (Footballer i : db) {
            if (Objects.equals(i.getName(), name)) {
                return i;
            }
        }
        return null;
    }

    // search footballer
    /*
    public footballer searchFootballer(String name, String surname) {
        for (footballer i : db) {
            if (i.getName() == name && i.getSurname() == surname) {
                return i;
            }
        }
        return null;
    }*/

    // search if parameter exists TODO:
    public Footballer searchParams(String team) {
        return null;
    }

    //print database
    public void print() {
        System.out.println();
        System.out.println("DATABASE");
        System.out.print("Name\t");
        System.out.print("Surname\t");
        System.out.print("birth\t");
        System.out.print("nationality\t");
        System.out.print("worldCupWinner\t");
        System.out.print("championsLeagueWinner\t");
        System.out.print("ballondorWinner\t");
        System.out.print("europeanWinner\t");
        System.out.print("careerTeams\t");
        System.out.println();

        for (Footballer i : db) {
            SimpleDateFormat sdf = new SimpleDateFormat("yyyy");
            System.out.print(i.getName() + "\t");
            System.out.print(i.getSurname() + "\t");
            System.out.print(sdf.format(i.getBirthDate()) + "\t");
            System.out.print(i.getNationality() + "\t");
            System.out.print(i.isWorldCupWinner() + "\t\t\t");
            System.out.print(i.isChampionsLeagueWinner() + "\t\t\t\t\t");
            System.out.print(i.isBallondorWinner() + "\t\t\t");
            System.out.print(i.isEuropeanWinner() + "\t\t\t");
            Vector<String> teams = i.getCareerTeams();
            for (String team: teams){
                System.out.print(team + "\t");
            }
            System.out.println();
        }
    }

}
