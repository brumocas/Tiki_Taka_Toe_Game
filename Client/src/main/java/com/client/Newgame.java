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
import org.w3c.dom.Text;

import java.io.IOException;
import java.net.URL;
import java.util.Objects;
import java.util.ResourceBundle;

public class Newgame implements Initializable {

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {

    }

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
        Cursor.setCursor(scene);
        stage.setScene(scene);
        stage.show();
    }


    @FXML
    private TextField nickName;
    @FXML
    private Button startGameButton;

    @FXML
    void setWaitingRoomScene(ActionEvent event) throws IOException{

        String playerName = nickName.getText();
        // TODO: Receive new game pin from server
        String pin = "1234";

        if (playerName != null && !playerName.isEmpty()) {
            // You can pass the playerName to the waiting room scene or start the game here.
            // For example, load the waiting room scene with playerName.
            FXMLLoader loader = new FXMLLoader(getClass().getResource("waitingroom.fxml"));
            Parent root = loader.load();
            WaitingRoom waitingRoomController = loader.getController();
            waitingRoomController.setNickname1(playerName, pin);

            Scene waitingRoomScene = new Scene(root);
            waitingRoomScene.setUserData(playerName);

            Stage stage = (Stage) ((Node) event.getSource()).getScene().getWindow();
            Cursor.setCursor(waitingRoomScene);
            stage.setScene(waitingRoomScene);
            stage.show();
        }
    }

}
