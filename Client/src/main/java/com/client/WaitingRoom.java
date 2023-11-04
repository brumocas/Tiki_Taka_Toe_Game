package com.client;

import com.client.gui.defs.Cursor;
import com.client.player.Player;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.stage.Stage;


import java.io.IOException;
import java.net.URL;
import java.util.Currency;
import java.util.Objects;
import java.util.ResourceBundle;
import javafx.scene.text.Text;

public class WaitingRoom implements Initializable {
    public Player p1 = new Player();

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {

    }

    @FXML
    private Text nickname1;
    @FXML
    private Text pin;

    public void setNickname1(String playerName, String pin) {
        nickname1.setText(playerName);
        this.pin.setText(pin);
        p1.setName(playerName);
        p1.setSymbol('o');
    }

    @FXML
    private Text nickname2;

    public void setNickname2(String playerName, String pin) {
        nickname2.setText(playerName);
        this.pin.setText(pin);
        p1.setName(playerName);
        p1.setSymbol('x');
    }

    @FXML
    private Button startButton;

    private Scene scene;
    private Stage stage;
    private Parent root;

    @FXML
    public void setGameScene(ActionEvent event) throws IOException {
        root = FXMLLoader.load(Objects.requireNonNull(getClass().getResource("game.fxml")));
        stage = (Stage) ((Node) event.getSource()).getScene().getWindow();
        scene = new Scene(root);
        Cursor.setCursor(scene);
        stage.setScene(scene);
        stage.show();
    }

    @FXML
    private Button goBackButton;

    @FXML
    public void setMenuScene(ActionEvent event) throws IOException {
        root = FXMLLoader.load(Objects.requireNonNull(getClass().getResource("menu.fxml")));
        stage = (Stage) ((Node) event.getSource()).getScene().getWindow();
        scene = new Scene(root);
        Cursor.setCursor(scene);
        stage.setScene(scene);
        stage.show();
    }

}
