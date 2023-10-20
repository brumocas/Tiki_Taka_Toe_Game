module com.example.client {
    requires javafx.controls;
    requires javafx.fxml;

    requires org.controlsfx.controls;
    requires org.kordamp.bootstrapfx.core;

    opens com.example.client to javafx.fxml;
    exports com.example.client;
    exports com.example.client.gui;
    opens com.example.client.gui to javafx.fxml;
}