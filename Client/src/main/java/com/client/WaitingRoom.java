package com.client;

import com.client.gui.defs.Cursor;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.stage.Stage;
import com.client.logic.GameLogic;

import java.io.IOException;
import java.net.URL;
import java.util.Objects;
import java.util.ResourceBundle;
import java.util.TimerTask;

import javafx.scene.text.Text;
import org.controlsfx.control.tableview2.filter.filtereditor.SouthFilter;

public class WaitingRoom implements Initializable {
    private GameLogic game = new GameLogic();

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {

    }

    @FXML
    private Text nickname1;
    @FXML
    private Text pin;
    // If host set nickname of player and pin
    public void setHost(String playerName, String pin) {
        nickname1.setText(playerName);
        this.pin.setText(pin);
        game.p1.setName(playerName);
        game.p1.setSymbol('o');
        game.p1.setInGame(true);
    }

    @FXML
    private Text nickname2;
    // If hosted set nickname of player 2, pin and player 1 nickname
    // TODO: Receive player 1 nickname
    public void setHosted(String playerName, String pin) {
        nickname2.setText(playerName);
        this.pin.setText(pin);
        game.p2.setName(playerName);
        game.p2.setSymbol('x');
        game.p2.setInGame(true);
    }

    @FXML
    private Button startButton;
    private Scene scene;
    private Stage stage;
    private Parent root;
    // Action event to change to game scene
    @FXML
    public void setGameScene(ActionEvent event) throws IOException {
        // TODO: Check if connection is established between the 2 clients and then enter the game
        if (checkConnection()) {
            FXMLLoader loader = new FXMLLoader(getClass().getResource("game.fxml"));
            Parent root = loader.load();

            // Load next scene to pass Game data
            Game GameController = loader.getController();
            GameController.setGame(game);

            Scene scene = new Scene(root);
            // Pass Game data to the next scene
            scene.setUserData(game);

            stage = (Stage) ((Node) event.getSource()).getScene().getWindow();
            Cursor.setCursor(scene);
            stage.setScene(scene);
            stage.show();
        }

    }

    public boolean checkConnection() {
        // TODO : Background task to check if the connection is established or failed
        // If in host mode wait for connection of hosted player
        System.out.println("Waiting for host");
        return true;
    }


    @FXML
    private Button goBackButton;
    // Action event to go to main menu
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
