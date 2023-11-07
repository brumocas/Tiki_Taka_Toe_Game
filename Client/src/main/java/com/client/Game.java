package com.client;

import com.client.logic.GameLogic;
import com.client.player.Player;
import javafx.animation.Animation;
import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;


import java.net.URL;
import java.util.ResourceBundle;


import javafx.geometry.Pos;
import javafx.scene.control.Label;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.text.Text;
import javafx.util.Duration;

public class Game implements Initializable {

    @FXML
    private Text timer;
    @FXML
    private Label turn;
    private int timer_value = 30;
    private GameLogic game = new GameLogic();
    private boolean your_turn ;
    private boolean player_host;
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
        // See if the player is the host or the hosted
        if (game.p1.getInGame()){
            player_host = game.p1.getInGame();
            your_turn = true;
        } else if (!game.p2.getInGame()){
            player_host = !game.p2.getInGame();
            your_turn = false;
        }

        game.run();


        //TODO: Initialize teams/params of the board and images
        param1.setText(game.board.getUpparams(0));
        param1.setAlignment(Pos.CENTER);
        param2.setText(game.board.getUpparams(1));
        param3.setText(game.board.getUpparams(2));

        param4.setText(game.board.getLeftparams(0));
        param5.setText(game.board.getLeftparams(1));
        param6.setText(game.board.getLeftparams(2));

        Image image = new Image("file:src/main/resources/com/client/images/teams/chelsea.png");
        image1.setImage(image);
        image1.setFitWidth(170);
        image1.setFitHeight(115 );

        // Manage chat parameters
        textarea.setEditable(false);
        textarea.appendText("Chat :\n");
    }



    public void setGame(GameLogic game) {
        // Pass game object from the previous scene
        this.game = game;

        // Se which opponent type is in the client (Host or Hosted)
        // Host plays always first
        if (player_host) {
            // Client host type
            startTimer();
        } else {
            // Client hosted type
            turn.setText("Opponent :");
            startTimer();
        }
    }

    public Player getGuiPlayer(){
        return game.p1.getInGame() ? game.p1 : game.p2;
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

}
