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
        Cursor.setCursor(scene);
        stage.setScene(scene);
        stage.show();
    }


    @FXML
    private TextField nickName;
    @FXML
    private Button startGameButton;

    @FXML
    void setWaitingRoomScene(ActionEvent event) throws IOException {
        String playerName = nickName.getText();

        if (playerName != null && !playerName.isEmpty()) {
            String pin = "----";

            FXMLLoader loader = new FXMLLoader(getClass().getResource("waitingroom.fxml"));
            Parent root = loader.load();
            // Load next scene to pass Data
            WaitingRoom waitingRoomController = loader.getController();
            waitingRoomController.setHost(playerName, pin);

            // Pass Data to the next scene
            Scene scene = new Scene(root);
            scene.setUserData(playerName);

            Stage stage = (Stage) ((Node) event.getSource()).getScene().getWindow();
            Cursor.setCursor(scene);
            stage.setScene(scene);
            stage.show();
        }
    }

}
