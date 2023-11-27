from PIL import Image
import os

def resize_images(input_dir, output_dir, new_size):
    # Create the output directory if it doesn't exist
    if not os.path.exists(output_dir):
        os.makedirs(output_dir)

    # Get a list of all files in the input directory
    files = os.listdir(input_dir)

    # Loop through each file in the directory
    for file in files:
        # Check if the file is an image
        if file.lower().endswith(('.jpg', '.jpeg', '.gif', '.bmp')):
            print("Images with different extension")
            break
        if file.lower().endswith(('.png')):
            # Construct the full path to the input image
            input_path = os.path.join(input_dir, file)

            # Open the image using Pillow
            img = Image.open(input_path)

            # Resize the image
            resized_img = img.resize(new_size)

            # Construct the full path to the output image
            output_path = os.path.join(output_dir, file)

            # Save the resized image
            resized_img.save(output_path)

            print(f"Resized {file} and saved to {output_path}")

if __name__ == "__main__":
    # Specify the input directory containing images
    input_directory = ""

    # Specify the output directory to save resized images
    output_directory = ""

    # Specify the new size (width, height) for the images
    new_size = (150, 115)  # Adjust the size as needed

    # Call the function to resize images
    resize_images("teams_nations", "teams_nations", new_size)

    # Call the function to resize images
    resize_images("trophies", "trophies", new_size)

