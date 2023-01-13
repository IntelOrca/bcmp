# bcmp
A simple command-line utility for comparing two files byte by byte

## Usage
```
bcmp [-h] [-v] file1 file2
```

## Options
- `-h`: Display help message
- `-v`: Display version

## Examples
```
bcmp file1.txt file2.txt
```

Compares file1.txt and file2.txt byte by byte.
```
bcmp -v
```
Displays the version of bcmp.

```
bcmp -h
```

Displays help message

## Copyright
Copyright (C) 2023  Ted John and ChatGPT

## Note
The program compares two files byte by byte and print the byte address and the value of the two bytes for each difference all in hexdecimal.
