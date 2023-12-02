package com.client;

import com.client.communication.CommunicationGui;
import com.client.logic.Board;
import com.client.player.Player;
import javafx.animation.Animation;
import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.application.Platform;
import javafx.fxml.FXML;


import java.io.IOException;
import java.util.Objects;


import javafx.scene.control.Label;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.text.Text;
import javafx.util.Duration;


import static javafx.geometry.Pos.CENTER;

public class Game {

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

    CommunicationGui client;
    Board board = new Board();
    private int timer_value = 30;
    private boolean host;

    public void setGameLogic(boolean host, CommunicationGui client, Player p1, Player p2) throws IOException {
        this.host = host;

        // See if the player is the host or the hosted
        if (host) {
            // Client host type
            changeTextFieldToWait();

            p2.setSymbol('X');
        } else if (!host) {
            // Client hosted type
            p1.setSymbol('O');
            p2.setSymbol('X');
            changeTextFieldToWait();
        }

        // Receive  Communication object from the previous scene
        this.client = client;
        // Receive Game Params
        board.setParams(client);
        //Initialize teams/params of the board and images
        updateParamsTeams();
        // Manage chat parameters
        textarea.setEditable(false);
        textarea.appendText("/------------------------------------------------------------------------------------" +
                "----------Chat----------------------------------------------------------------------:\n");

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

        // Create GameLogic Thread
        Thread backgroundThread = new Thread(() -> {
            // Your background task logic goes here
            outerLoop:
            while (true) {

                // Busy waiting for you time to play
                String message = null;
                try {
                    message = client.receiveMessage();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }

                switch (message) {
                    case "YourTurn":
                        // UI will Handle This
                        System.out.println("Hello from thread");

                        // UI-related code goes here
                        Platform.runLater(this::changeTextFieldToGuess);

                        break;
                    case "OpponentPlay":
                        // Receive Opponent play and place it in the board
                        String[] play = new String[0];

                        try {
                            play = client.receiveMessage().split("-");
                        } catch (IOException e) {
                            throw new RuntimeException(e);
                        }
                        board.setPlay(Integer.parseInt(play[0]), Integer.parseInt(play[1]),
                                play[2] + ' ' + play[3], (host) ? 'O' : 'X');

                        break;
                    case "Winner":
                        // End game as a winner
                        System.out.println("Your Win");
                        break outerLoop;
                    case "Loser":
                        // End game as a loser
                        System.out.println("Your Lose");
                        break outerLoop;
                    case "Tie":
                        // End game as a tie
                        System.out.println("Tie");
                        break outerLoop;
                    default:
                        System.out.println(message);
                        System.out.println("Default");
                        break;
                }
            }

            // Sleep for a while to simulate work
            try {
                Thread.sleep(250);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

        });

        // Set the thread as a daemon so that it will automatically terminate when the application exits
        backgroundThread.setDaemon(true);

        // Start the thread
        backgroundThread.start();
    }


    //-------------------User Makes a play---------------------//
    @FXML
    void makeGuessF1(KeyEvent event) throws IOException {
        String message;
        if (event.getCode().equals(KeyCode.ENTER)) {
            //message = client.receiveMessage();

            //if (message != "YourTurn")
              //  System.err.println("Error");

            String[] play = textfield1.getText().split(" ");
            message = "0-0-" + play[0] + "-" + play[1];

            try {
                client.sendMessage(message);
            } catch (IOException e){
                throw new RuntimeException(e);
            }

            try {
                message = client.receiveMessage();
            } catch (IOException e){
                throw new RuntimeException(e);
            }

            if (Objects.equals(message, "Correct")) {
                board.setPlay(0, 0, play[0] + " " + play[1], (host) ? 'O' : 'X');
                removeTextField(textfield1, name1, play[0] + " " + play[1]);
                changeShirt(shirt1, (host) ? 'O' : 'X');
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
    void getMessage(KeyEvent event) {
        if (event.getCode().equals(KeyCode.ENTER)) {
            String message = prompt.getText();
            textarea.appendText(" : " + message + "\n");
            prompt.setText("");
            // TODO: Sent received message to the server
        }
    }


    //------------------- Aux Functions----------------------//

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
        label.setText(new_param);
        label.setAlignment(CENTER);
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

    // Setting up a 30-second countdown timer
    public void startTimer() {
        timer.setText(String.valueOf(timer_value) + " sec");
        Timeline timeline = new Timeline(new KeyFrame(Duration.seconds(1), e -> {
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

    // Reset timer countdown
    public void resetTimer() {
        if (checkTimer() < 1)
            timer_value = 30;
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
        textfield1.setEditable(true);
        textfield1.setText("");
        textfield2.setEditable(true);
        textfield2.setText("");
        textfield3.setEditable(true);
        textfield3.setText("");
        textfield4.setEditable(true);
        textfield4.setText("");
        textfield5.setEditable(true);
        textfield5.setText("");
        textfield6.setEditable(true);
        textfield6.setText("");
        textfield7.setEditable(true);
        textfield7.setText("");
        textfield8.setEditable(true);
        textfield8.setText("");
        textfield9.setEditable(true);
        textfield9.setText("");
    }

    // Text field in wait mode
    void changeTextFieldToWait() {
        turn.setText("Opponent :");
        textfield1.setEditable(false);
        textfield1.setText("(...)");
        textfield2.setEditable(false);
        textfield2.setText("(...)");
        textfield3.setEditable(false);
        textfield3.setText("(...)");
        textfield4.setEditable(false);
        textfield4.setText("(...)");
        textfield5.setEditable(false);
        textfield5.setText("(...)");
        textfield6.setEditable(false);
        textfield6.setText("(...)");
        textfield7.setEditable(false);
        textfield7.setText("(...)");
        textfield8.setEditable(false);
        textfield8.setText("(...)");
        textfield9.setEditable(false);
        textfield9.setText("(...)");
    }

}
