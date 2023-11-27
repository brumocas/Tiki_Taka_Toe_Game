# TikiTakaToe Server Documentation

## Overview

The TikiTakaToe Server application is implemented in C++ and serves as the central hub for all TikiTakaToe game operations. It is responsible for executing the game logic, managing connections from Clients, and providing a seamless remote gaming experience.

## Key Features

### 1. Game Logic Execution

The Server runs the intricate TikiTakaToe game logic, ensuring fair and accurate gameplay for all connected Clients.

### 2. Connection Management

It handles the task of accepting and managing connections from Clients, facilitating a smooth and responsive gaming experience.


### 3. Unit Testing

The TikiTakaToe server, in addition to its role as the central hub for gameplay and connection management, serves as a robust platform for conducting unit tests, ensuring the reliability and accuracy of its intricate game logic and networking functionalities.

#### 3.1 Run Unit Tests
Information in how to run the unit tests can be found in the `/GoogleTests` directory

## Technology Stack

- **Language:** C++
- **Networking Library:** `<arpa/inet.h>` 

## Concurrency and Multi-Threading

The server leverages C++'s multi-threading capabilities to efficiently manage server-side connections.

## Performance Considerations

C++ is chosen for the server application due to its performance benefits. It is compiled to native machine code, providing optimal execution of game logic and connection management.


## Requirements
1. Google Tests library installed in your OS for testing purposes.
2. CLion to avoid using the terminal to run the application. (not mandatory)


## How to Run
### Option: 1 (CLion ide)
1. Clone this repository to your local machine.
    ```bash
    git clone https://git.fe.up.pt/psw_23_24/1meec_a01/a01_1.git
    cd Server
2. Open with CLion ide the `/Server` directory from the cloned project.
3. Build the Server application using the provided CMakeLists.txt .
4. Pass the IP and Port wished to the program arguments. (If empty LocalHost and port 8080 is used)
5. Run the compiled server executable.

### Option: 2 (executable file))

