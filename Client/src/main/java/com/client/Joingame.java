package com.client;

import com.client.communication.CommunicationGui;
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
    CommunicationGui client2 = new CommunicationGui();

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        try {
            client2.connectToServer("localhost", 8080);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        // Receive Hosted message
        String message;
        try {
            message = client2.receiveMessage();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        if (!message.equals("Hosted")) {
            System.err.println("Error invalid message received");
        }

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


    // Action to set Client2 Server Connection
    @FXML
    private void setConnection(ActionEvent event) throws IOException {

    }

    // Action to set waiting room scene
    @FXML
    private void setWaitingRoomScene(ActionEvent event) throws IOException {
        String playerName = nickName.getText();
        String pin = pinGame.getText();
        String message;

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
            // TODO: Add Label
            pinGame.setText("Incorrect Pin");
        }


    }

}
