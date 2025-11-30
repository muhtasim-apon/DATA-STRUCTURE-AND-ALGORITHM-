# Huffman Encoding Implementation in C++

This project implements Huffman Encoding for data compression with comprehensive file operations in append mode.

## Files

1. **dummy.txt** - Contains **800-900 word** text with ALL characters (A-Z, a-z, 0-9, special characters)
2. **input.txt** - Filtered version containing ONLY alphanumeric characters (A-Z, a-z, 0-9) and whitespaces
3. **output.txt** - Contains the encoded message and Huffman codes with compression statistics
4. **huffman.cpp** - Main C++ program implementing Huffman encoding

## Key Features

✅ **dummy.txt** contains **800-900 words** with ALL characters:

- All uppercase letters (A-Z)
- All lowercase letters (a-z)
- All digits (0-9)
- Special characters: `! @#$%^&*()_+-={}[]|:;"'<>,.?/~`
- Symbols: `↔★∑∏∂∇∈⊂≈≤≥→∞` and more

✅ **input.txt** contains ONLY:

- Alphanumeric characters (A-Z, a-z, 0-9)
- Whitespaces (spaces, newlines, tabs)

✅ All file operations use **append mode (ios::app)**

✅ Organized output showing codes for uppercase, lowercase, digits separately

✅ Complete compression statistics

## How It Works

### Step 1: Create Dummy File (800-900 words)

Creates a comprehensive text file about Artificial Intelligence containing:

- All uppercase letters (A-Z)
- All lowercase letters (a-z)
- All digits (0-9)
- Special characters and symbols
- **Word count: 800-900 words**

### Step 2: Filter to Input File

Reads dummy.txt and creates input.txt with:

- ✅ Alphanumeric characters only (A-Z, a-z, 0-9)
- ✅ Whitespaces (spaces, newlines, tabs)
- ❌ Special characters removed

### Step 3: Huffman Encoding

Builds Huffman tree based on character frequencies using priority queue (min heap)

### Step 4: Generate Prefix Codes

Creates optimal binary codes for each character, organized by:

- Uppercase letters (A-Z)
- Lowercase letters (a-z)
- Digits (0-9)
- Whitespace characters

### Step 5: Output Encoded Message

Writes binary encoded string to output.txt with full statistics

## Compilation and Execution

```bash
g++ -o huffman huffman.cpp
./huffman
```

## Sample Output

```
Step 1: Creating dummy text file with all characters (A-Z, a-z, 0-9, special chars)...
Dummy file created successfully with ALL characters!
Characters in dummy.txt: 5847

Step 2: Preparing input file (filtering to keep only alphanumeric and whitespaces)...
Input file created successfully!
Characters in input.txt (after filtering): 5247
Filtered out: 600 special characters

Step 3: Running Huffman encoding algorithm...
Text length: 5247 characters

Step 4: Huffman Codes (Prefix Codes):
========================================
Uppercase Letters:
'A': 11001
'B': 1110100
'C': 110000
...

Lowercase Letters:
'a': 0000
'b': 110001
'c': 01010
...

Digits:
'0': 0011000
'1': 0010110
...

Whitespace Characters:
' ' (space): 111
'\n' (newline): 001011110
========================================

Step 5: Encoding message and creating output file...
Output file created successfully!
Compression ratio: 57.8%
Original size: 41976 bits
Compressed size: 24267 bits
Space saved: 42.2%
```

## Algorithm Explanation

### Huffman Encoding Algorithm

1. **Frequency Analysis**: Count occurrences of each character
2. **Build Min Heap**: Create priority queue with character frequencies
3. **Construct Tree**: Merge nodes with lowest frequencies
4. **Generate Codes**: Traverse tree (left=0, right=1) to create prefix codes
5. **Encode Message**: Replace each character with its Huffman code

### Time Complexity

- Building frequency map: O(n)
- Building Huffman tree: O(k log k) where k = unique characters
- Encoding: O(n)
- **Overall: O(n + k log k)**

### Space Complexity

- O(k) for storing Huffman codes and tree nodes

## Compression Statistics

The program calculates:

- **Original size**: characters × 8 bits (ASCII encoding)
- **Compressed size**: total bits in encoded message
- **Compression ratio**: (compressed size / original size) × 100%
- **Space saved**: (1 - compression ratio) × 100%

## File Operations

All file operations use **append mode (ios::app)** as specified:

```cpp
ofstream dummyFile("dummy.txt", ios::app);
ofstream inputFile("input.txt", ios::app);
ofstream outputFile("output.txt", ios::app);
```

## Character Filtering

Uses standard C++ functions:

```cpp
if (isalnum(ch) || isspace(ch)) {
    filtered += ch;
}
```

## Why Huffman Encoding?

- **Variable-length codes**: Frequent characters get shorter codes
- **Prefix-free**: No code is a prefix of another (unambiguous decoding)
- **Optimal**: Minimizes average code length for given frequencies
- **Lossless**: Original data can be perfectly reconstructed

## Example Huffman Codes

Frequent characters (shorter codes):

- `'e'`: `000`
- `'t'`: `001`
- `' '` (space): `111`

Less frequent characters (longer codes):

- `'Q'`: `11101011`
- `'Z'`: `111010010`
- `'9'`: `001101111`

## Applications

- File compression (ZIP, GZIP)
- Image compression (JPEG)
- Data transmission
- Network protocols
- Database compression

## Author

Created as a demonstration of Huffman Encoding algorithm in C++ with comprehensive text processing and file operations.
