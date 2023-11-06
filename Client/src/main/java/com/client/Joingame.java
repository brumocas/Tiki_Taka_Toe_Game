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
import javafx.scene.control.TextField;
import javafx.stage.Stage;

import java.io.IOException;
import java.net.URL;
import java.util.Objects;
import java.util.ResourceBundle;

public class Joingame implements Initializable {

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
    }

    @FXML
    private Button goBackButton;

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
    }


    @FXML
    private TextField nickName;
    @FXML
    private TextField pinGame;
    @FXML
    private Button startGameButton;

    // Action to set waiting room scene
    @FXML
    private void setWaitingRoomScene(ActionEvent event) throws IOException{
        String playerName = nickName.getText();
        String pin = pinGame.getText();

        if (playerName != null && !playerName.isEmpty() && pin != null && !pin.isEmpty()) {
            // TODO:  Send client request to the server depending on client type
            // If hosted connect, accept pin and receive host player information
            // Call communication class here

            FXMLLoader loader = new FXMLLoader(getClass().getResource("waitingroom.fxml"));
            Parent root = loader.load();
            // Load next scene to pass Data
            WaitingRoom waitingRoomController = loader.getController();
            waitingRoomController.setHosted(playerName, pin);

            Scene waitingRoomScene = new Scene(root);
            // Pass Data to the next scene
            waitingRoomScene.setUserData(playerName);

            Stage stage = (Stage) ((Node) event.getSource()).getScene().getWindow();
            Cursor.setCursor(waitingRoomScene);
            stage.setScene(waitingRoomScene);
            stage.show();
        }
    }

}
