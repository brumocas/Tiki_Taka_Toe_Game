from pytube import YouTube
from pydub import AudioSegment
import os
import logging
import re

logging.basicConfig(level=logging.INFO)

def sanitize_filename(title):
    # Remove invalid characters from the title
    return re.sub(r'[\/:*?"<>|]', '', title)

def convert_to_mp3(video_path, output_path):
    try:
        # Generate a clean and valid filename for the MP3 file
        mp3_filename = os.path.join(output_path, f"{os.path.splitext(os.path.basename(video_path))[0]}.mp3")

        # Convert mp4 to mp3 using pydub
        audio = AudioSegment.from_file(video_path, format="mp4")
        audio.export(mp3_filename, format="mp3")

        logging.info("Conversion to MP3 complete!")
        return mp3_filename

    except Exception as e:
        logging.error(f"Error converting to MP3: {str(e)}")
        return None

def download_youtube_video(url, output_path='./Musics'):
    try:
        os.makedirs(output_path, exist_ok=True)

        yt = YouTube(url)
        video_stream = yt.streams.get_highest_resolution()

        if video_stream is None:
            raise ValueError("No video streams found.")

        # Download video
        logging.info(f"Downloading video: {yt.title}")
        video_stream.download(output_path)
        video_path = os.path.join(output_path, video_stream.title + ".mp4")

        # Sanitize title for use as a filename
        sanitized_title = sanitize_filename(video_stream.title)

        # Generate a clean and valid filename for the MP3 file
        mp3_filename = os.path.join(output_path, f"{os.path.splitext(sanitized_title)[0]}.mp3")

        # Convert mp4 to mp3 using pydub
        convert_success = convert_to_mp3(video_path, output_path)

        # Remove the temporary mp4 file
        os.remove(video_path)

        if convert_success:
            logging.info("Download complete!")
            return mp3_filename
        else:
            logging.error("Error converting to MP3.")
            return None

    except Exception as e:
        logging.error(f"Error downloading video: {str(e)}")
        return None

if __name__ == "__main__":
    # List of YouTube video URLs
    youtube_urls = [
        "https://www.youtube.com/watch?v=CfihYWRWRTQ&list=RDQMK5R2aiZP9sM&start_radio=1&ab_channel=JohnNewmanVEVO",
        "https://www.youtube.com/watch?v=XmzjIDRIhY0&list=PL_N97sPkLMbBUvRmK3FG5f1Dm8ZG4pQvP&ab_channel=FIFAPlayers",
        "https://www.youtube.com/watch?v=w5tWYmIOWGk&list=RDQMK5R2aiZP9sM&index=20&ab_channel=ImagineDragonsVEVO",
        # Add more video URLs as needed
        #"https://www.youtube.com/watch?v=ZhzN7-Q00KU&list=RDQMK5R2aiZP9sM&index=21&ab_channel=KygoOfficialVEVO",
    ]

    for url in youtube_urls:
        # Download video and get the file path
        downloaded_video = download_youtube_video(url)
        if downloaded_video:
            logging.info(f"Video downloaded as MP3: {downloaded_video}")
