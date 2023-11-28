module com.client {
    requires javafx.controls;
    requires javafx.fxml;

    requires org.controlsfx.controls;
    requires org.kordamp.bootstrapfx.core;
    requires java.desktop;

    opens com.client to javafx.fxml;
    exports com.client;
    exports com.client.gui.defs;
    opens com.client.gui.defs to javafx.fxml;
    exports com.client.main;
    opens com.client.main to javafx.fxml;
}
