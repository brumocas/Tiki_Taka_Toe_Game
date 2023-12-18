def generate_name_surname_file(input_filename, output_filename):
    with open(input_filename, "r", encoding='utf-8') as file:
        data = [line.strip().split() for line in file]

    with open(output_filename, "w", encoding='utf-8') as output_file:
        for entry in data:
            name = entry[0].rstrip(',')
            surname = entry[1].rstrip(',')
            if name == "Name" and surname == "Surname":
                continue
            if surname == "null":
                concatenated_name = name
            else:
                concatenated_name = name + ' ' +  surname
            output_file.write(concatenated_name + "\n")

if __name__ == "__main__":
    input_filename = "default_database.txt"  # Replace with your actual input file
    output_filename = "Names.txt"

    generate_name_surname_file(input_filename, output_filename)
