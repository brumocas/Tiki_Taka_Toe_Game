package com.client;


import com.client.gui.defs.Cursor;
import com.client.gui.defs.Icon;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;

public class Gui extends Application {
    private static Gui instance;

    // Instance to pass Cli args to other controllers
    public Gui() {
        instance = this;
    }

    // Instance to pass Cli args to other controllers
    public static Gui getInstance() {
        return instance;
    }

    @Override
    public void start(Stage stage) throws IOException {
        try {
            Parent root = FXMLLoader.load(getClass().getResource("menu.fxml"));
            Scene scene = new Scene(root);
            Cursor.setCursor(scene);
            Icon.setIcon(stage);
            stage.setResizable(true);
            stage.setTitle("TIKI TAKA TOE");
            stage.setMaximized(true);
            stage.setScene(scene);
            stage.show();
        } catch (Exception e) {
            e.printStackTrace();
        }

    }

    public static void main(String[] args) {
        launch(args);
    }
}