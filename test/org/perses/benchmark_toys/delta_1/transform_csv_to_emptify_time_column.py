
import sys
import csv

def main(input_path, output_path):
    with open(input_path, 'r', newline='') as infile, \
         open(output_path, 'w', newline='') as outfile:
        reader = csv.reader(infile)
        writer = csv.writer(outfile)
        
        header = next(reader, None)
        if header:
            writer.writerow(header)
        
        for row in reader:
            if row:
                row[0] = ''
            writer.writerow(row)

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python script.py <input_file> <output_file>")
        sys.exit(1)
    main(sys.argv[1], sys.argv[2])
