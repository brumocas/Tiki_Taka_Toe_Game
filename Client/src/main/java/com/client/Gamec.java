package com.client;

import com.client.logic.Game;
import javafx.animation.Animation;
import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;


import java.net.URL;
import java.security.Key;
import java.util.ResourceBundle;

import javafx.scene.control.Label;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.text.Text;
import javafx.util.Duration;

public class Gamec implements Initializable {

    @FXML
    private Text timer;
    @FXML
    private Label turn;
    private int i = 30;
    private Game game = new Game();

    public void setGame(Game game) {
        this.game = game;
        //game.p1.print();
        //game.p2.print();

        if (this.game.p1.getInGame()) {
            startTimer();
        } else {
            turn.setText("Opponent :");
            startTimer();
        }

    }


    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        //TODO: Initialize teams/params of the board
        textarea.setEditable(false);
    }

    public void startTimer() {
        timer.setText(String.valueOf(i) + " sec");
        Timeline timeline = new Timeline(new KeyFrame(Duration.seconds(1), e -> {
            i--;
            timer.setText(String.valueOf(i) + " sec");
        }));
        timeline.setCycleCount(Animation.INDEFINITE);
        timeline.play();
    }

    public int checkTimer() {
        return i;
    }

    public void resetTimer() {
        if (checkTimer() < 1)
            i = 30;
    }

    @FXML
    private TextField prompt;
    @FXML
    private TextArea textarea;

    @FXML
    void getMessage(KeyEvent event) {
        if (event.getCode().equals(KeyCode.ENTER)) {
            String message = prompt.getText();
            textarea.appendText("Player 1 :" + message + "\n");
            prompt.setText("");
        }
    }

}
