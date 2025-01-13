# convert "#include <file>" to "#include "file"" about all files in inc/ directory

import os
import sys

def convert(line):
    if line.startswith("#include <"):
        line = line.replace("<", "\"")
        line = line.replace(">", "\"")
    return line

def main():
    directory = "inc/"
    for filename in os.listdir(directory):
        with open(directory + filename, "r") as f:
            lines = f.readlines()
        with open(directory + filename, "w") as f:
            for line in lines:
                f.write(convert(line))

if __name__ == "__main__":
    main()
