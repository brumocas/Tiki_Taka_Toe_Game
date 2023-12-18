from pydub import AudioSegment
from pydub.playback import play

def convert_mp3_to_wav(mp3_file, wav_file):
    # Load the MP3 file
    audio = AudioSegment.from_mp3(mp3_file)
    
    # Export the audio to WAV format
    audio.export(wav_file, format="wav")

    print(f"Conversion completed: {mp3_file} -> {wav_file}")

if __name__ == "__main__":
    # Replace 'input.mp3' and 'output.wav' with your input and output file names
    mp3_file_path = 'output.mp3'
    wav_file_path = 'output.wav'

    convert_mp3_to_wav(mp3_file_path, wav_file_path)
