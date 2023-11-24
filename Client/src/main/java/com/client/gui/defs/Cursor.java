package com.client.gui.defs;

import javafx.scene.ImageCursor;
import javafx.scene.Scene;
import javafx.scene.image.Image;

public class Cursor {

    public static void setCursor(Scene scene) {

        // Load a custom cursor image
        Image cursorImage = new Image("file:src/main/images/iconball.png");

        // Create a custom cursor with the image and hotspot
        ImageCursor customCursor = new ImageCursor(cursorImage, cursorImage.getWidth() / 1.75, cursorImage.getHeight() / 1.8);

        // Set the custom cursor
        scene.setCursor(customCursor);

    }
}
