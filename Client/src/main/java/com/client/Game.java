package com.client;

import com.client.logic.GameLogic;
import com.client.player.Player;
import javafx.animation.Animation;
import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.application.Platform;
import javafx.concurrent.Task;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;


import java.net.URL;
import java.util.IllegalFormatCodePointException;
import java.util.ResourceBundle;


import javafx.geometry.Pos;
import javafx.scene.control.Label;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.layout.StackPane;
import javafx.scene.text.Text;
import javafx.util.Duration;

import static javafx.geometry.Pos.CENTER;

public class Game implements Initializable {

    private GameLogic game = new GameLogic();
    private int timer_value = 30;
    private boolean your_turn;
    private boolean player_host;

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

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {

        game.run();

        //Initialize teams/params of the board and images
        updateParamsTeams();
        // Manage chat parameters
        textarea.setEditable(false);
        textarea.appendText("/------------------------------------------------------------------------------------" +
                "----------Chat----------------------------------------------------------------------:\n");

        // Create GameLogic Task Here

    }

    public void setGame(GameLogic game) {
        // Pass game object from the previous scene
        this.game = game;

        // See if the player is the host or the hosted
        if (game.p1.getInGame()) {
            // Client host type
            turn.setText("Your turn :");
            startTimer();
            player_host = game.p1.getInGame();
        } else if (game.p2.getInGame()) {
            // Client hosted type
            turn.setText("Opponent :");
            startTimer();
            player_host = !game.p2.getInGame();
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
            textarea.appendText(getGuiPlayer().getName() + " : " + message + "\n");
            prompt.setText("");
            // TODO: Sent received message to the server
        }
    }


    //------------------- Aux Functions----------------------//

    // Update all new params and images
    void updateParamsTeams() {
        // Update labels
        changeParams(param1, game.board.getUpparams(0));
        changeParams(param2, game.board.getUpparams(1));
        changeParams(param3, game.board.getUpparams(2));
        changeParams(param4, game.board.getLeftparams(0));
        changeParams(param5, game.board.getLeftparams(1));
        changeParams(param6, game.board.getLeftparams(2));

        // Update Images
        changeImage(image1, getParamPath(game.board.getUpparams(0)));
        changeImage(image2, getParamPath(game.board.getUpparams(1)));
        changeImage(image3, getParamPath(game.board.getUpparams(2)));
        changeImage(image4, getParamPath(game.board.getLeftparams(0)));
        changeImage(image5, getParamPath(game.board.getLeftparams(1)));
        changeImage(image6, getParamPath(game.board.getLeftparams(2)));
    }

    // Change Params from scene
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
            case "worldcup", "european", "ballondor", "champions" -> {
                path = path + "trophies/" + param + ".png";
                return path;
            }
        }
        // It is a team or a nation
        return path + "teams_nations/" + param + ".png";
    }

    // Setting up a 30 seconds countdown timer
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

    // Get the Gui Player Class
    public Player getGuiPlayer() {
        return game.p1.getInGame() ? game.p1 : game.p2;
    }

    // Increase left score
    void increaseLeftScore(){
        int score = Integer.parseInt(scoreLeft.getText());
        score++;
        scoreLeft.setText(String.valueOf(score));
    }

    // Increase right score
    void increaseRightScore(){
        int score = Integer.parseInt(scoreRight.getText());
        score++;
        scoreRight.setText(String.valueOf(score));
    }

    // Change for 'X' or 'O' shirt when the client plays
    void changeShirt(ImageView shirt,char symbol){
        String path = "file:src/main/resources/com/client/images/";
        if (symbol == 'O'){
            Image image_aux = new Image(path + "/shirts/" + "shirto.png");
            shirt.setImage(image_aux);
        } else if (symbol == 'X'){
            Image image_aux = new Image(path + "/shirts/" + "shirtX.png");
            shirt.setImage(image_aux);
        } else {
            System.err.println("Invalid symbol passed to function");
        }

    }

    // Make Text Field disappear and create Text Field
    void removeTextField(TextField textField, Label text, String name){
        // TODO: Implement when play is correct
        textField.setVisible(false);
        //text.setVisible(true);
        //text.setText(name);
    }
}
