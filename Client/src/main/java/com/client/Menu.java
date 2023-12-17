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


import java.io.IOException;
import java.net.URL;
import java.util.Objects;
import java.util.ResourceBundle;

public class Menu implements Initializable {

    @FXML
    private Button quitGameButton;

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {

        // Handle the button click event
        quitGameButton.setOnAction(event -> {
            try {
                exitMenuScene(event);
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        });
    }

    // Task to handle Quit Game button
    @FXML
    public void exitMenuScene(ActionEvent event) throws IOException {
        System.exit(0);
    }

    @FXML
    private Button newGameButton;
    private Scene scene;
    private Stage stage;
    private Parent root;

    // Task to handle New Game button
    @FXML
    public void setNewGameScene(ActionEvent event) throws IOException {
        root = FXMLLoader.load(Objects.requireNonNull(getClass().getResource("newgame.fxml")));
        stage = (Stage) ((Node) event.getSource()).getScene().getWindow();
        scene = new Scene(root);
        Cursor.setCursor(scene);
        stage.setScene(scene);
        stage.show();
    }

    @FXML
    private Button joinGameButton;

    // Task to handle Join Game button
    @FXML
    public void setJoinGameScene(ActionEvent event) throws IOException {
        root = FXMLLoader.load(Objects.requireNonNull(getClass().getResource("joingame.fxml")));
        stage = (Stage) ((Node) event.getSource()).getScene().getWindow();
        scene = new Scene(root);
        Cursor.setCursor(scene);
        stage.setScene(scene);
        stage.show();
    }

    @FXML
    private Button instructionsButton;

    // Task to handle Instructions button
    @FXML
    public void setInstructionsScene(ActionEvent event) throws IOException {
        root = FXMLLoader.load(Objects.requireNonNull(getClass().getResource("instructions.fxml")));
        stage = (Stage) ((Node) event.getSource()).getScene().getWindow();
        scene = new Scene(root);
        Cursor.setCursor(scene);
        stage.setScene(scene);
        stage.show();
    }

    @FXML
    private Button aboutUsButton;

    // Task to handle About Us button
    @FXML
    public void setAboutUsScene(ActionEvent event) throws IOException {
        root = FXMLLoader.load(Objects.requireNonNull(getClass().getResource("aboutus.fxml")));
        stage = (Stage) ((Node) event.getSource()).getScene().getWindow();
        scene = new Scene(root);
        Cursor.setCursor(scene);
        stage.setScene(scene);
        stage.show();
    }


}