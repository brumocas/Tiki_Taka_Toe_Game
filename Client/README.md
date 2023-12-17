# Tiki Taka Toe Game Client application

## Overview

This is the client-side implementation of the Tiki Taka Toe game for remote gaming version.
The client features a graphical user interface (GUI) for users to interact with the game.
It communicates with the server using the TCP/IP transport protocol to exchange game-related information.

## Features

- Graphical user interface using Java Fx.
- Communicates with the Tiki Taka Toe game server using TCP/IP.
- Displays the game board and allows players to make guesses and talk through a chat box.
- Sends and receives updates from the server regarding the game state.

## Requirements

- Windows OS. (it runs on linux, but with some deformations in the GUI, you can try it, but we recommend Windows OS )
- Java Development Kit (JDK) installed on your system.
- IntelliJ IDEA to avoid using the terminal to run the application. (not mandatory)
- Tiki Taka Toe game Server running on a specified IP and port.

## How to Run

### Option: 1 (IDEA ide)

1. Clone this repository to your local machine.
   ```bash
   git clone https://git.fe.up.pt/psw_23_24/1meec_a01/a01_1.git
   cd Client

2. Open with IntelliJ IDEA the `/Client` directory from the cloned project
3. Go to `file` --> `Project Structure...` and add the openJdk-21 Package available in the
   `/InstallationPackages` directory from the project by choosing the `lib` subfolder (Sometimes already loaded)

   <img src="ReadmeImages/img_1.png" alt="img_1.png" width="40%" />
   
   If not loaded the SDks will be empty

   <img src="ReadmeImages/img_2.png" alt="img_2.png" width="40%" />

4. Add the following VM option to the project in the run/debug
   configuration `--add-exports=javafx.base/com.sun.javafx.event=org.controlsfx.control`

   <img src="ReadmeImages/img_3.png" alt="img_3.png" width="40%" />

5. Change the IP and Port in the Programs Arguments

   <img src="ReadmeImages/img_4.png" alt="img_4.png" width="40%" />

6. Run the `Client` main from the project

### Option: 2 (executable jar file)

1. Clone this repository to your local machine.
   ```bash
   git clone https://git.fe.up.pt/psw_23_24/1meec_a01/a01_1.git
   cd Client

2. Create a Jar file run/debug configuration and the following VM option `--add-exports=javafx.base/com.sun.javafx.event=org.controlsfx.control`

   The project jar file is inside the `/out/artifacts/Client_jar` directory

   <img src="ReadmeImages/img_5.png" alt="img_5.png" width="35%" />
   

3. Change the IP and Port in the Programs Arguments

   <img src="ReadmeImages/img_6.png" alt="img_6.png" width="35%" />

4. Run the `Client.jar` file





