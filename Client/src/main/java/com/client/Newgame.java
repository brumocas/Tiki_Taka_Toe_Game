package com.client;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.stage.Stage;

import java.io.IOException;
import java.util.Objects;

public class Newgame {
    @FXML
    private Button goBackButton;

    private Scene scene;
    private Stage stage;
    private Parent root;

    @FXML
    public void setMenuScene(ActionEvent event) throws IOException {
        root = FXMLLoader.load(Objects.requireNonNull(getClass().getResource("menu.fxml")));
        stage = (Stage) ((Node) event.getSource()).getScene().getWindow();
        scene = new Scene(root);
        stage.setScene(scene);
        stage.show();
    }


    @FXML
    private TextField nickName;
    @FXML
    private Button startGameButton;

    @FXML
    void setWaitingRoomScene(ActionEvent event) throws IOException{
        System.out.println(nickName.getText());

        String playerName = nickName.getText();

        if (playerName != null && !playerName.isEmpty()) {
            // You can pass the playerName to the waiting room scene or start the game here.
            // For example, load the waiting room scene with playerName.
            FXMLLoader loader = new FXMLLoader(getClass().getResource("waitingroom.fxml"));
            Parent root = loader.load();
            WaitingRoom waitingRoomController = loader.getController();
            waitingRoomController.setPlayerName(playerName);

            Scene waitingRoomScene = new Scene(root);
            waitingRoomScene.setUserData(playerName);

            Stage stage = (Stage) ((Node) event.getSource()).getScene().getWindow();
            stage.setScene(waitingRoomScene);
            stage.show();
        }
    }


}
