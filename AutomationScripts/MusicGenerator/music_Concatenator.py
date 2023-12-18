from pydub import AudioSegment

def concatenate_mp3_files(mp3_files, output_file):
    try:
        # Initialize an empty AudioSegment
        concatenated_audio = AudioSegment.silent(duration=0)

        # Iterate through the list of MP3 files and append them to the concatenated_audio
        for mp3_file in mp3_files:
            audio_segment = AudioSegment.from_mp3(mp3_file)
            concatenated_audio += audio_segment

        # Export the concatenated audio to the output file
        concatenated_audio.export(output_file, format="mp3")

        print(f"Concatenation complete! Result saved to {output_file}")

    except Exception as e:
        print(f"Error concatenating MP3 files: {str(e)}")

if __name__ == "__main__":
    # List of MP3 files to concatenate
    mp3_files_to_concatenate = [
        "Come Alive - FMLYBND (FIFA 15 Soundtrack).mp3",
        "Kygo - Raging ft. Kodaline (Official Lyric Video).mp3",
        "Love Me Again.mp3",
        "On Top Of The World.mp3",
        # Add more MP3 filenames as needed
    ]

    # Output file for the concatenated audio
    output_file = "output.mp3"

    # Concatenate MP3 files
    concatenate_mp3_files(mp3_files_to_concatenate, output_file)
