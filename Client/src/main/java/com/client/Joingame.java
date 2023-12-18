package com.client;

import com.client.communication.Communication;
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
import java.util.List;
import java.util.Objects;
import java.util.ResourceBundle;

public class Joingame {
    List<String> args = Gui.getInstance().getParameters().getRaw();

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
    boolean first_time = true;
    Communication client2 = new Communication();

    @FXML
    private void setWaitingRoomScene(ActionEvent event) throws IOException {
        String playerName = nickName.getText();
        String pin = pinGame.getText();
        String message;


        if (playerName != null && !playerName.isEmpty() && pin != null && !pin.isEmpty()) {

            if (first_time) {

                client2.connectToServer(args.get(0), Integer.parseInt(args.get(1)));
                // Receive Hosted message
                message = client2.receiveMessage();
                if (!message.equals("Hosted")) {
                    System.err.println("Error invalid message received");
                }
                goBackButton.setVisible(false);
                first_time = false;
            }

            // Send pin guess
            client2.sendMessage(pin);
            // Receive Response
            message = client2.receiveMessage();
            if (Objects.equals(message, "Correct")) {
                if (playerName != null && !playerName.isEmpty() && pin != null && !pin.isEmpty()) {

                    FXMLLoader loader = new FXMLLoader(getClass().getResource("waitingroom.fxml"));
                    Parent root = loader.load();
                    // Load next scene to pass Data
                    WaitingRoom waitingRoomController = loader.getController();
                    waitingRoomController.setHosted(playerName, pin, client2);

                    Scene waitingRoomScene = new Scene(root);
                    // Pass Data to the next scene
                    waitingRoomScene.setUserData(playerName);

                    Stage stage = (Stage) ((Node) event.getSource()).getScene().getWindow();
                    Cursor.setCursor(waitingRoomScene);
                    stage.setScene(waitingRoomScene);
                    stage.show();
                }
            } else {
                pinGame.setText("");
                pinGame.setPromptText("Incorrect Pin");
            }
        }
    }
}
