package com.client;

import com.client.communication.Communication;
import com.client.gui.defs.Cursor;
import com.client.logic.Board;
import com.client.player.Player;
import javafx.animation.Animation;
import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;


import java.io.IOException;
import java.net.URL;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;
import java.util.Objects;
import java.util.ResourceBundle;


import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.layout.HBox;
import javafx.scene.text.Text;
import javafx.stage.Stage;
import javafx.util.Duration;
import org.controlsfx.control.textfield.AutoCompletionBinding;
import org.controlsfx.control.textfield.TextFields;


import static javafx.geometry.Pos.CENTER;

public class Game {
    @FXML
    private HBox timeBox;
    @FXML
    private Button menuButton;
    @FXML
    private Label gameInfo;
    @FXML
    private Text timer;
    @FXML
    private Label turn;
    @FXML
    private Text scoreLeft;
    @FXML
    private Text scoreRight;
    @FXML
    private Label param1;
    @FXML
    private Label param2;
    @FXML
    private Label param3;
    @FXML
    private Label param4;
    @FXML
    private Label param5;
    @FXML
    private Label param6;
    @FXML
    private Label name1;
    @FXML
    private Label name2;
    @FXML
    private Label name3;
    @FXML
    private Label name4;
    @FXML
    private Label name5;
    @FXML
    private Label name6;
    @FXML
    private Label name7;
    @FXML
    private Label name8;
    @FXML
    private Label name9;
    @FXML
    private ImageView image1;
    @FXML
    private ImageView image2;
    @FXML
    private ImageView image3;
    @FXML
    private ImageView image4;
    @FXML
    private ImageView image5;
    @FXML
    private ImageView image6;
    @FXML
    private TextField textfield1;
    @FXML
    private TextField textfield2;
    @FXML
    private TextField textfield3;
    @FXML
    private TextField textfield4;
    @FXML
    private TextField textfield5;
    @FXML
    private TextField textfield6;
    @FXML
    private TextField textfield7;
    @FXML
    private TextField textfield8;
    @FXML
    private TextField textfield9;
    @FXML
    private ImageView shirt1;
    @FXML
    private ImageView shirt2;
    @FXML
    private ImageView shirt3;
    @FXML
    private ImageView shirt4;
    @FXML
    private ImageView shirt5;
    @FXML
    private ImageView shirt6;
    @FXML
    private ImageView shirt7;
    @FXML
    private ImageView shirt8;
    @FXML
    private ImageView shirt9;

    private TextField[][] textFields;
    private ImageView[][] shirts;
    private Label[][] names;

    Communication chat = new Communication();
    Communication client;
    Board board = new Board();
    Player p1;
    Player p2;
    private int timer_value = 30;
    private boolean host;
    // Needs to be read from memory every time its accessed
    private volatile String buffer;

    public void setGameLogic(boolean host, Communication client, Player p1, Player p2) throws IOException {
        List<String> args = Gui.getInstance().getParameters().getRaw();
        this.host = host;
        this.p1 = p1;
        this.p2 = p2;
        // Receive  Communication object from the previous scene
        this.client = client;

        // Initialize
        textFields = new TextField[][]{
                {textfield1, textfield2, textfield3},
                {textfield4, textfield5, textfield6},
                {textfield7, textfield8, textfield9}
        };

        shirts = new ImageView[][]{
                {shirt1, shirt2, shirt3},
                {shirt4, shirt5, shirt6},
                {shirt7, shirt8, shirt9}};

        names = new Label[][]{
                {name1, name2, name3},
                {name4, name5, name6},
                {name7, name8, name9}
        };

        // Remove some visible buttons not needed for now
        gameInfo.setVisible(false);
        menuButton.setVisible(false);

        // See if the player is the host or the hosted
        if (host) {
            // Client host type
            changeTextFieldToWait();
            p1.setSymbol('O');
            p2.setSymbol('X');
        } else if (!host) {
            // Client hosted type
            p1.setSymbol('O');
            p2.setSymbol('X');
            changeTextFieldToWait();
        }

        // Manage chat parameters
        textarea.setEditable(false);

        // Suggestion Text addition
        suggestionTextFields(textFields);

        // Connect another socket for chat
        chat.connectToServer(args.get(0), Integer.parseInt(args.get(1)) + 1);

        // Create chat Thread to receive Opponent chat message
        Thread chatThread = new Thread(() -> {

            while (true) {
                String message;
                // Sleep for a while to simulate work
                try {
                    message = chat.receiveMessage();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }

                if (message != null) {
                    Platform.runLater(() -> {
                        receiveMessage(message);
                    });
                }

                try {
                    Thread.sleep(250);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        });

        // GameLogic Thread
        Thread backgroundThread = new Thread(() -> {

            while (!gameEnded())
                gameCycle();

            int hostScore = Integer.parseInt(scoreLeft.getText());
            int hostedScore = Integer.parseInt(scoreRight.getText());

            if (hostScore == 2 && host) {
                Platform.runLater(() -> setGameInfo("You Win"));
            } else if (hostScore == 2 && !host) {
                Platform.runLater(() -> setGameInfo("You Lose"));
            } else if (hostedScore == 2 && host) {
                Platform.runLater(() -> setGameInfo("You Lose"));
            } else if (hostedScore == 2 && !host) {
                Platform.runLater(() -> setGameInfo("You Win"));
            }

            Platform.runLater(this::setMenuButton);

            client.closeConnection();

            // Sleep for a while to simulate work
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        });

        // Set the thread as a daemon so that it will automatically terminate when the application exits
        backgroundThread.setDaemon(true);
        chatThread.setDaemon(true);
        // Start the thread
        backgroundThread.start();
        chatThread.start();
    }


    //-------------------User Makes a play---------------------//
    @FXML
    void makeGuessF1(KeyEvent event) throws IOException {

        if (event.getCode().equals(KeyCode.ENTER)) {
            String[] play = textfield1.getText().split(" ");
            if (play.length == 1) {
                // Send guess with only one name
                buffer = "0-0-" + play[0] + "-null";
            } else if (play.length == 2) {
                // Send guess with name and surname
                buffer = "0-0-" + play[0] + "-" + play[1];
            }
            changeTextFieldToWait();
        }

    }

    @FXML
    void makeGuessF2(KeyEvent event) throws IOException {

        if (event.getCode().equals(KeyCode.ENTER)) {
            String[] play = textfield2.getText().split(" ");
            if (play.length == 1) {
                // Send guess with only one name
                buffer = "0-1-" + play[0] + "-null";
            } else if (play.length == 2) {
                // Send guess with name and surname
                buffer = "0-1-" + play[0] + "-" + play[1];
            }
            changeTextFieldToWait();
        }

    }

    @FXML
    void makeGuessF3(KeyEvent event) throws IOException {

        if (event.getCode().equals(KeyCode.ENTER)) {
            String[] play = textfield3.getText().split(" ");
            if (play.length == 1) {
                // Send guess with only one name
                buffer = "0-2-" + play[0] + "-null";
            } else if (play.length == 2) {
                // Send guess with name and surname
                buffer = "0-2-" + play[0] + "-" + play[1];
            }
            changeTextFieldToWait();
        }

    }

    @FXML
    void makeGuessF4(KeyEvent event) throws IOException {

        if (event.getCode().equals(KeyCode.ENTER)) {
            String[] play = textfield4.getText().split(" ");
            if (play.length == 1) {
                // Send guess with only one name
                buffer = "1-0-" + play[0] + "-null";
            } else if (play.length == 2) {
                // Send guess with name and surname
                buffer = "1-0-" + play[0] + "-" + play[1];
            }
            changeTextFieldToWait();
        }

    }

    @FXML
    void makeGuessF5(KeyEvent event) throws IOException {

        if (event.getCode().equals(KeyCode.ENTER)) {
            String[] play = textfield5.getText().split(" ");
            if (play.length == 1) {
                // Send guess with only one name
                buffer = "1-1-" + play[0] + "-null";
            } else if (play.length == 2) {
                // Send guess with name and surname
                buffer = "1-1-" + play[0] + "-" + play[1];
            }
            changeTextFieldToWait();
        }

    }

    @FXML
    void makeGuessF6(KeyEvent event) throws IOException {

        if (event.getCode().equals(KeyCode.ENTER)) {
            String[] play = textfield6.getText().split(" ");
            if (play.length == 1) {
                // Send guess with only one name
                buffer = "1-2-" + play[0] + "-null";
            } else if (play.length == 2) {
                // Send guess with name and surname
                buffer = "1-2-" + play[0] + "-" + play[1];
            }
            changeTextFieldToWait();
        }

    }

    @FXML
    void makeGuessF7(KeyEvent event) throws IOException {

        if (event.getCode().equals(KeyCode.ENTER)) {
            String[] play = textfield7.getText().split(" ");
            if (play.length == 1) {
                // Send guess with only one name
                buffer = "2-0-" + play[0] + "-null";
            } else if (play.length == 2) {
                // Send guess with name and surname
                buffer = "2-0-" + play[0] + "-" + play[1];
            }
            changeTextFieldToWait();
        }

    }

    @FXML
    void makeGuessF8(KeyEvent event) throws IOException {

        if (event.getCode().equals(KeyCode.ENTER)) {
            String[] play = textfield8.getText().split(" ");
            if (play.length == 1) {
                // Send guess with only one name
                buffer = "2-1-" + play[0] + "-null";
            } else if (play.length == 2) {
                // Send guess with name and surname
                buffer = "2-1-" + play[0] + "-" + play[1];
            }
            changeTextFieldToWait();
        }

    }

    @FXML
    void makeGuessF9(KeyEvent event) throws IOException {

        if (event.getCode().equals(KeyCode.ENTER)) {
            String[] play = textfield9.getText().split(" ");
            if (play.length == 1) {
                // Send guess with only one name
                buffer = "2-2-" + play[0] + "-null";
            } else if (play.length == 2) {
                // Send guess with name and surname
                buffer = "2-2-" + play[0] + "-" + play[1];
            }
            changeTextFieldToWait();
        }

    }


    //-------------------Handle Chat--------------------------//
    @FXML
    private TextField prompt;
    @FXML
    private TextArea textarea;

    @FXML
    void getMessage(KeyEvent event) throws IOException {
        if (event.getCode().equals(KeyCode.ENTER)) {
            String message = prompt.getText();
            textarea.appendText((host) ? p1.getName() + " : " + message + "\n" : p2.getName() + " : " + message + "\n");
            prompt.setText("");
            // Send Message to the other player
            chat.sendMessage(message);
        }
    }

    // Get opponent Message
    void receiveMessage(String message) {
        textarea.appendText((!host) ? p1.getName() + " : " + message + "\n" : p2.getName() + " : " + message + "\n");
    }

    //------------------- Aux Functions----------------------//

    // Get opponent Play
    void getOpponentPlay() {
        String[] play = new String[0];
        String message = null;

        // Receive Opponent play from Server
        try {
            play = client.receiveMessage().split("-");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

        // Set new play in the board
        if (Objects.equals(play[3], "null")) {
            board.setPlay(Integer.parseInt(play[0]), Integer.parseInt(play[1]),
                    play[2], (host) ? 'X' : 'O');
        } else {
            board.setPlay(Integer.parseInt(play[0]), Integer.parseInt(play[1]),
                    play[2] + ' ' + play[3], (host) ? 'X' : 'O');
        }

    }

    // Get Gui User Guess
    void getUIplay() {
        String[] play = new String[0];
        String message = null;

        // Make Guess available in the GUI
        Platform.runLater(this::changeTextFieldToGuess);
        Platform.runLater(this::startTimer);

        // Busy waiting until buffer is filled
        while (buffer == null) {
            // Sleep for a while to simulate work
            if (checkTimer() < 1) {
                // Create invalid guess to Server, timed out
                buffer = "4-4-null-null";
                Platform.runLater(this::changeTextFieldToWait);
                break;
            }

            try {
                Thread.sleep(250);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        // Get player guess
        play = buffer.split("-");

        // Send guess with name and surname
        message = play[0] + "-" + play[1] + "-" + play[2] + "-" + play[3];

        // reset buffer
        buffer = null;

        // Send play to Server
        try {
            client.sendMessage(message);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

        // Receive play response from Server
        try {
            if (Objects.equals(client.receiveMessage(), "Correct")) {

                if (Objects.equals(play[3], "null")) {
                    board.setPlay(Integer.parseInt(play[0]), Integer.parseInt(play[1]),
                            play[2], (host) ? 'O' : 'X');
                } else {
                    board.setPlay(Integer.parseInt(play[0]), Integer.parseInt(play[1]),
                            play[2] + ' ' + play[3], (host) ? 'O' : 'X');
                }

            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

        // Stop Timer
        Platform.runLater(this::stopTimer);
    }

    // Update all new params and images
    void updateParamsTeams() {
        // Update labels
        changeParams(param1, board.getUpparams(0));
        changeParams(param2, board.getUpparams(1));
        changeParams(param3, board.getUpparams(2));
        changeParams(param4, board.getLeftparams(0));
        changeParams(param5, board.getLeftparams(1));
        changeParams(param6, board.getLeftparams(2));

        // Update Images
        changeImage(image1, getParamPath(board.getUpparams(0)));
        changeImage(image2, getParamPath(board.getUpparams(1)));
        changeImage(image3, getParamPath(board.getUpparams(2)));
        changeImage(image4, getParamPath(board.getLeftparams(0)));
        changeImage(image5, getParamPath(board.getLeftparams(1)));
        changeImage(image6, getParamPath(board.getLeftparams(2)));
    }

    // Change Params from a scene
    void changeParams(Label label, String new_param) {
        String[] params = new_param.split("_");

        if (params.length == 2) {
            label.setText(params[0] + " " + params[1]);
            label.setAlignment(CENTER);
        } else if (params.length == 1) {

            if (new_param.equals("WC")){
                label.setText("World Cup");
            } else if (new_param.equals("CL")) {
                label.setText("Champions League");
            } else if (new_param.equals("BD")) {
                label.setText("Ballon Dor");
            }  else if (new_param.equals("EC")) {
                label.setText("European Cup");
            } else {
                label.setText(new_param);
            }

            label.setAlignment(CENTER);
        }

    }

    // Change images from Scene
    void changeImage(ImageView image, String path) {
        Image image_aux = new Image(path);
        image.setImage(image_aux);
        image.setFitWidth(170);
        image.setFitHeight(115);
    }

    // Get image path according to param
    String getParamPath(String param) {
        String path = "file:src/main/resources/com/client/images/";
        switch (param) {
            // It is not a team or nation
            case "WC", "EC", "BD", "CL" -> {
                path = path + "trophies/" + param + ".png";
                return path;
            }
        }
        // It is a team or a nation
        return path + "teams_nations/" + param + ".png";
    }

    Timeline timeline;

    // Setting up a 30-second countdown timer
    public void startTimer() {
        timer.setText(String.valueOf(timer_value) + " sec");
        timeline = new Timeline(new KeyFrame(Duration.seconds(1), e -> {
            timer_value--;
            timer.setText(String.valueOf(timer_value) + " sec");
        }));
        timeline.setCycleCount(Animation.INDEFINITE);
        timeline.play();
    }

    // Check timer current time
    public int checkTimer() {
        return timer_value;
    }

    // Stop timer from counting
    public void stopTimer() {
        if (timeline != null) {
            timeline.stop();
            timer_value = 30;
        }
    }

    // Increase left score
    void increaseLeftScore() {
        int score = Integer.parseInt(scoreLeft.getText());
        score++;
        scoreLeft.setText(String.valueOf(score));
    }

    // Increase right score
    void increaseRightScore() {
        int score = Integer.parseInt(scoreRight.getText());
        score++;
        scoreRight.setText(String.valueOf(score));
    }

    // Change for 'X' or 'O' shirt when the client plays
    void changeShirt(ImageView shirt, char symbol) {
        String path = "file:src/main/resources/com/client/images/";
        if (symbol == 'O') {
            Image image_aux = new Image(path + "/shirts/" + "shirto.png");
            shirt.setImage(image_aux);
        } else if (symbol == 'X') {
            Image image_aux = new Image(path + "/shirts/" + "shirtx.png");
            shirt.setImage(image_aux);
        } else if (symbol == 'n') {
            Image image_aux = new Image(path + "/shirts/" + "shirt.png");
            shirt.setImage(image_aux);
        } else {
            System.err.println("Invalid symbol passed to function");
        }

    }

    // Make Text Field disappear and create Text Field
    void removeTextField(TextField textField, Label text, String name) {
        textField.setVisible(false);
        text.setVisible(true);
        text.setText(name);
    }

    // Text field in guess mode
    void changeTextFieldToGuess() {
        turn.setText("Your turn :");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board.isEmpty(i, j)) {
                    textFields[i][j].setVisible(true);
                    textFields[i][j].setText("");
                    textFields[i][j].setEditable(true);
                }
            }
        }
    }

    // Text field in wait mode
    void changeTextFieldToWait() {
        turn.setText("Opponent :");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                textFields[i][j].setVisible(false);
            }
        }
        timer.setText(String.valueOf(30) + " sec");
    }

    // Update UI
    private void updateUI(TextField[][] textFields, ImageView[][] shirts, Label[][] names) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (!board.isEmpty(i, j)) {
                    removeTextField(textFields[i][j], names[i][j], board.getPlayer(i, j));
                    changeShirt(shirts[i][j], board.getSymbol(i, j));
                }
            }
        }
    }

    // Implements a Game turn
    private void gameCycle() {

        // Receive Game Params
        try {
            board.setParams(client);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        //Initialize teams/params of the board and images
        Platform.runLater(() -> updateParamsTeams());


        String[] play = new String[0];
        String message = null;
        outerLoop:
        while (true) {

            // Receive Server Message to proceed
            try {
                message = client.receiveMessage();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }

            switch (message) {
                case "YourTurn":
                    // Make new play
                    getUIplay();
                    Platform.runLater(() -> updateUI(textFields, shirts, names));
                    break;
                case "OpponentPlay":
                    // Receive Opponent play
                    getOpponentPlay();
                    Platform.runLater(() -> updateUI(textFields, shirts, names));
                    break;
                case "Winner":
                    // Change score
                    if (host) {
                        increaseLeftScore();
                    } else {
                        increaseRightScore();
                    }
                    Platform.runLater(() -> updateUI(textFields, shirts, names));
                    // Set game info
                    Platform.runLater(() -> setGameInfo("Round Won"));
                    delay();
                    resetGame();
                    System.out.println("Your Win");
                    break outerLoop;
                case "Loser":
                    // Change score
                    if (!host) {
                        increaseLeftScore();
                    } else {
                        increaseRightScore();
                    }
                    Platform.runLater(() -> updateUI(textFields, shirts, names));
                    // Set game info
                    Platform.runLater(() -> setGameInfo("Round Lost"));
                    delay();
                    resetGame();
                    System.out.println("Your Lose");
                    break outerLoop;
                case "Tie":
                    // End game as a tie
                    Platform.runLater(() -> updateUI(textFields, shirts, names));
                    // Set game info
                    Platform.runLater(() -> setGameInfo("Tied Round"));
                    delay();
                    resetGame();
                    System.out.println("Tie");
                    break outerLoop;
                default:
                    System.err.println(message);
                    break;
            }

        }
    }

    // Reset Board Game
    void resetGame() {
        board.eraseBoard();
        Platform.runLater(() -> {
            removeGameInfo();
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    textFields[i][j].setText("");
                    names[i][j].setText("");
                    names[i][j].setVisible(false);
                    textFields[i][j].setText("");
                    changeShirt(shirts[i][j], 'n');
                }
            }
        });
    }

    // Checks if the game Ended
    boolean gameEnded() {
        int hostScore = Integer.parseInt(scoreLeft.getText());
        int hostedScore = Integer.parseInt(scoreRight.getText());
        return hostedScore == 2 || hostScore == 2;
    }

    // Small Delay to be able to se plays
    void delay() {
        try {
            // Sleep for 5000 milliseconds (5 second)
            Thread.sleep(5000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

    }

    // Set Game Info Label available
    void setGameInfo(String message) {
        gameInfo.setText(message);
        gameInfo.setVisible(true);
    }

    // Set Game Info Label invisible
    void removeGameInfo() {
        gameInfo.setVisible(false);
    }

    // Set Menu Game Button Visible
    void setMenuButton() {
        turn.setVisible(false);
        timeBox.setVisible(false);
        menuButton.setVisible(true);
    }

    private Scene scene;
    private Stage stage;
    private Parent root;

    // Action to set main menu scene
    @FXML
    public void setMenuScene(ActionEvent event) throws IOException {
        root = FXMLLoader.load(Objects.requireNonNull(getClass().getResource("menu.fxml")));
        stage = (Stage) ((Node) event.getSource()).getScene().getWindow();
        scene = new Scene(root);
        Cursor.setCursor(scene);
        stage.setScene(scene);
        stage.show();
        chat.sendMessage("Close");
        chat.closeConnection();
    }

    // Add Suggestion to the TextFields
    void suggestionTextFields(TextField[][] textFields) {
        String[] names = loadNames();

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                AutoCompletionBinding<String> autoCompletionBinding = TextFields.bindAutoCompletion(textFields[i][j], names);
                autoCompletionBinding.setPrefWidth(textFields[i][j].getPrefWidth());
                autoCompletionBinding.setPrefWidth(220);
            }
        }
    }

    // Load Suggestion Names available
    public String[] loadNames() {
        String[] dataArray = new String[0];
        try {
            // Change the file path to the location of your .txt file
            List<String> lines = Files.readAllLines(Paths.get("src/main/resources/com/client/NamesInfo/Names.txt"));

            // Convert the list to an array
            dataArray = lines.toArray(new String[0]);

        } catch (IOException e) {
            e.printStackTrace();
        }

        return dataArray;
    }
}


    