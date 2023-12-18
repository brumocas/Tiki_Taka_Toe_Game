package com.client.main;

import com.client.Gui;

import javax.sound.sampled.*;
import java.io.File;
import java.io.IOException;

public class Client {
    private volatile boolean running = true;

    public static void main(String[] args) throws IOException, InterruptedException {
        Client main = new Client();

        // Create music thread
        Thread musicThread = new Thread(main::playMusic);
        musicThread.start();

        // Create Gui thread
        Thread guiThread = new Thread(() -> main.playGui(args));
        guiThread.start();

        guiThread.join();
        main.stopMusic();
        musicThread.join();

    }

    // Method to play the music application
    private void playWav(String filePath, float volume) {
        try {
            File file = new File(filePath);
            try (AudioInputStream audioInputStream = AudioSystem.getAudioInputStream(file)) {
                AudioFormat audioFormat = audioInputStream.getFormat();

                DataLine.Info dataLineInfo = new DataLine.Info(SourceDataLine.class, audioFormat);

                try (SourceDataLine sourceDataLine = (SourceDataLine) AudioSystem.getLine(dataLineInfo)) {
                    sourceDataLine.open(audioFormat);

                    // Adjust volume using Control.Type.VOLUME
                    if (sourceDataLine.isControlSupported(FloatControl.Type.VOLUME)) {
                        FloatControl volumeControl = (FloatControl) sourceDataLine.getControl(FloatControl.Type.VOLUME);
                        volumeControl.setValue(volume);
                    }

                    sourceDataLine.start();

                    int bufferSize = 4096;
                    byte[] buffer = new byte[bufferSize];

                    int bytesRead;

                    while (running && (bytesRead = audioInputStream.read(buffer, 0, buffer.length)) != -1) {
                        sourceDataLine.write(buffer, 0, bytesRead);
                    }

                    sourceDataLine.drain();
                }
            }
        } catch (UnsupportedAudioFileException | LineUnavailableException | IOException e) {
            e.printStackTrace();
        }
    }


    // Method to run the music task
    private void playMusic() {
        while (running)
            playWav("src/main/resources/com/client/Music/output.wav", 0.1f);
    }

    // Method to stop the music
    private void stopMusic() {
        running = false;
    }

    // Method to run the GUI task
    private void playGui(String[] args) {
        // GUI remote Game
        Gui.main(args);
    }
}



