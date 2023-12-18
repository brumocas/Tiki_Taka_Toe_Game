package com.client.gui.defs;

import javafx.scene.image.Image;
import javafx.stage.Stage;

public class Icon {

    public static void setIcon(Stage stage) {

        // Load your icon image (you should replace "icon.png" with your icon file)
        Image iconImage = new Image("file:src/main/images/iconball.png");

        // Set the icon for the stage
        stage.getIcons().add(iconImage);

    }
}
