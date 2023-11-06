import Communication.Communication;
import logic.GameLogic;

public class Main {
    public static void main(String[] args) {

        // Create server
        //Communication.startServer();


        GameLogic game = new GameLogic();
        game.run();
    }
}