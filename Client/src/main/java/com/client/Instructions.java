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
import javafx.scene.control.Hyperlink;
import javafx.stage.Stage;

import java.io.IOException;
import java.net.URL;
import java.util.Objects;
import java.util.ResourceBundle;
import java.awt.*;

public class Instructions {

    // Set outside connection to check game rules by clicking in a link
    @FXML
    private Hyperlink hyperlink;

    @FXML
    private void hyperlink(ActionEvent event) throws IOException {
        Desktop desktop = Desktop.getDesktop();
        desktop.browse(java.net.URI.create("https://uporto-my.sharepoint.com/personal/up202004966_up_pt/_layouts/15/onedrive.aspx?id=%2Fpersonal%2Fup202004966%5Fup%5Fpt%2FDocuments%2FProfessional%20Life%2FUniversity%2FMEEC%2F1%C2%BAano%2F1%C2%BASemestre%2FPSW%2FFinal%20Project%2FTIKI%20TAKA%20TOE%20instructions%2Epdf&parent=%2Fpersonal%2Fup202004966%5Fup%5Fpt%2FDocuments%2FProfessional%20Life%2FUniversity%2FMEEC%2F1%C2%BAano%2F1%C2%BASemestre%2FPSW%2FFinal%20Project&ga=1"));
    }


    // Set button to go back to main menu
    @FXML
    private Button goBackButton;
    private Scene scene;
    private Stage stage;
    private Parent root;

    // Task that checks if button was clicked
    @FXML
    public void setMenuScene(ActionEvent event) throws IOException {
        root = FXMLLoader.load(Objects.requireNonNull(getClass().getResource("menu.fxml")));
        stage = (Stage) ((Node) event.getSource()).getScene().getWindow();
        scene = new Scene(root);
        Cursor.setCursor(scene);
        stage.setScene(scene);
        stage.show();
    }


}
