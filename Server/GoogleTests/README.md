# Google Test (GTest)

## Introduction

Google Test is a C++ testing framework developed by Google. It is designed to provide a simple and flexible platform for writing unit tests. GTest is widely used in the C++ community to ensure the correctness of code through automated testing.
We used this framework to test 4 classes:
- **board** class
- **database** class
- **footballer** class 
- **game** class

## Features
- **Simple Syntax:** GTest provides a clean and intuitive syntax for writing test cases.
- **Test Fixtures:** Easily set up and tear down common test conditions with fixtures.
- **Assertions:** A wide range of assertions for validating expected behavior.
- **Parameterized Tests:** Run the same test logic with multiple sets of data.
- **Death Tests:** Verify that a particular piece of code exits with the expected status.

## How to run created Gtests

### Requirements
1. Gtest library installed in your OS.

### Run Steps 
1. In the `/Server` directory go to the `Main.cpp` file and in the `main` 
function, uncomment the `::testing::InitGoogleTest(&argc, argv);` and
`RUN_ALL_TESTS()` lines of code.
2. Run the Server application as before and the Google Tests developed will 
be performed.