package com.client;

import com.client.communication.CommunicationGui;
import com.client.gui.defs.Cursor;
import javafx.application.Platform;
import javafx.concurrent.Task;
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
import java.util.List;
import java.util.Objects;
import java.util.ResourceBundle;


import javafx.scene.text.Text;

public class WaitingRoom implements Initializable {
    private GameLogic game = new GameLogic();
    List<String> args = Gui.getInstance().getParameters().getRaw();

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {

    }


    @FXML
    private Text nickname1;
    @FXML
    private Text pin;
    CommunicationGui client1 = new CommunicationGui();
    // If host set nickname of player and pin
    public void setHost(String playerName, String pin) throws IOException {
        nickname1.setText(playerName);
        this.pin.setText(pin);
        game.p1.setName(playerName);
        game.p1.setSymbol('O');
        game.host = true;
        // Connect Client1
        client1.connectToServer(args.get(1), Integer.parseInt(args.get(2)));

        // Release a task to check connection from client2
        checkClient2Connection cC2c = new checkClient2Connection(client1);
        new Thread(cC2c).start();

        startButton.setVisible(false);
        goBackButton.setVisible(false);
    }


    @FXML
    private Text nickname2;
    CommunicationGui client2 = new CommunicationGui();
    // If hosted set nickname of player 2, pin and player 1 nickname
    public void setHosted(String playerName, String pin, CommunicationGui client2) throws IOException {
        nickname2.setText(playerName);
        this.pin.setText(pin);
        game.p2.setName(playerName);
        game.p2.setSymbol('x');
        game.host = false;

        // Receive Client2 communication and place player Name
        this.client2 = client2;
        game.p1.setName(client2.exchangeNames(nickname2.getText()));
        nickname1.setText(game.p1.getName());

        startButton.setVisible(true);
        goBackButton.setVisible(false);
    }

    @FXML
    private Button startButton;
    private Scene scene;
    private Stage stage;
    private Parent root;

    // Action event to change to game scene
    @FXML
    public void setGameScene(ActionEvent event) throws IOException {

        if (true) {
            FXMLLoader loader = new FXMLLoader(getClass().getResource("game.fxml"));
            Parent root = loader.load();

            // Load next scene to pass Game data
            Game GameController = loader.getController();
            GameController.setGameLogic(game, (game.host) ? client1 : client2);

            Scene scene = new Scene(root);
            // Pass Game data to the next scene
            scene.setUserData(game);

            stage = (Stage) ((Node) event.getSource()).getScene().getWindow();
            Cursor.setCursor(scene);
            stage.setScene(scene);
            stage.show();
        }
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

    // Task to check Client2 connection
    private class checkClient2Connection extends Task<Void> {

        CommunicationGui client1;

        public checkClient2Connection(CommunicationGui client1) {
            this.client1 = client1;
        }

        @Override
        protected Void call() throws Exception {
            // Receive Host information
            String message = client1.receiveMessage();
            if (!Objects.equals(message, "Host")) {
                System.err.println("Invalid Reception");
            }

            // You are host receive pin
            message = client1.receiveMessage();
            System.out.println("You entered the game as host and the pin is: " + message);
            pin.setText(message);

            // Exchange Names
            game.p2.setName(client1.exchangeNames(nickname1.getText()));
            nickname2.setText(game.p2.getName());

            startButton.setVisible(true);

            return null;
        }

    }

}
