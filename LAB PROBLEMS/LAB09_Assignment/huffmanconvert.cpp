#include <bits/stdc++.h>
using namespace std;
struct node
{
    char ch;
    int freq;
    node *left;
    node *right;
    node(char character, int frequency)
    {
        ch = character;
        freq = frequency;
        left = right = NULL;
    }
};

struct compare
{
    bool operator()(node *l, node *r)
    {
        return (l->freq > r->freq);
    }
};

node *build(const string &text, map<char, int> &freq)
{
    for (char ch : text)
        freq[ch]++;
    cout << "Building Huffman Tree\n";
    priority_queue<node *, vector<node *>, compare> heap;
    for (auto pair : freq)
    {
        heap.push(new node(pair.first, pair.second));
    }
    while (heap.size() > 1)
    {
        node *left = heap.top();
        heap.pop();
        node *right = heap.top();
        heap.pop();
        node *parent = new node('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        heap.push(parent);
    }
    cout << "Huffman Tree Built Successfully\n";
    return heap.top();
}
void generate(node *root, const string &code, map<char, string> &huffmancode)
{
    if (!root)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        huffmancode[root->ch] = code;
    }
    generate(root->left, code + "0", huffmancode);
    generate(root->right, code + "1", huffmancode);
}
string encoding(const string &text, const map<char, string> &huffmancode)
{
    string str = "";
    for (char ch : text)
    {
        str += huffmancode.at(ch);
    }
    return str;
}
string preprocess(const string &dummy)
{
    string filtered = "";
    for (char ch : dummy)
    {
        if (isalnum(ch) || isspace(ch))
        {
            filtered += ch;
        }
    }
    return filtered;
}
void printprefixcode(const map<char, string> &huffmancode, const map<char, int> &freq)
{
    cout << "\n========================================" << "\n";
    cout << "      HUFFMAN CODES (PREFIX CODES)      " << "\n";
    cout << "========================================" << "\n";
    cout << "+------+----------+-------------------+" << "\n";
    cout << "| Char |   Freq   |   Huffman Code    |" << "\n";
    cout << "+------+----------+-------------------+" << "\n";

    for (char ch = 'A'; ch <= 'Z'; ch++)
    {
        if (huffmancode.find(ch) != huffmancode.end())
        {
            cout << "|  " << ch << "   |  " << setw(6) << freq.at(ch)
                 << "  | " << setw(17) << left << huffmancode.at(ch) << " |" << "\n";
        }
    }

    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        if (huffmancode.find(ch) != huffmancode.end())
        {
            cout << "|  " << ch << "   |  " << setw(6) << freq.at(ch)
                 << "  | " << setw(17) << left << huffmancode.at(ch) << " |" << "\n";
        }
    }

    for (char ch = '0'; ch <= '9'; ch++)
    {
        if (huffmancode.find(ch) != huffmancode.end())
        {
            cout << "|  " << ch << "   |  " << setw(6) << freq.at(ch)
                 << "  | " << setw(17) << left << huffmancode.at(ch) << " |" << "\n";
        }
    }

    if (huffmancode.find(' ') != huffmancode.end())
        cout << "| SPC  |  " << setw(6) << freq.at(' ')
             << "  | " << setw(17) << left << huffmancode.at(' ') << " |" << "\n";
    if (huffmancode.find('\n') != huffmancode.end())
        cout << "| \\n   |  " << setw(6) << freq.at('\n')
             << "  | " << setw(17) << left << huffmancode.at('\n') << " |" << "\n";
    if (huffmancode.find('\t') != huffmancode.end())
        cout << "| \\t   |  " << setw(6) << freq.at('\t')
             << "  | " << setw(17) << left << huffmancode.at('\t') << " |" << "\n";

    cout << "+------+----------+-------------------+" << "\n";
    cout << "\nTotal unique characters: " << huffmancode.size() << "\n";
}
vector<unsigned char> stringToBinary(const string &binaryStr)
{
    vector<unsigned char> bytes;
    for (size_t i = 0; i < binaryStr.length(); i += 8)
    {
        unsigned char byte = 0;
        for (size_t j = 0; j < 8 && (i + j) < binaryStr.length(); j++)
        {
            if (binaryStr[i + j] == '1')
            {
                byte |= (1 << (7 - j));
            }
        }
        bytes.push_back(byte);
    }
    return bytes;
}

int main()
{
    map<char, int> freq;
    ifstream readfile("dummy.txt");
    if (!readfile.is_open())
    {
        cerr << "Error opening file." << "\n";
    }
    string filtercontent = preprocess(string((istreambuf_iterator<char>(readfile)), istreambuf_iterator<char>()));
    readfile.close();
    ofstream inputfile("input.txt", ios::app);
    if (!inputfile.is_open())
    {
        cerr << "Error opening file." << "\n";
        return 0;
    }
    inputfile << filtercontent;
    inputfile.close();
    node *root = build(filtercontent, freq);
    map<char, string> huffmancode;
    generate(root, "", huffmancode);
    string encodedstr = encoding(filtercontent, huffmancode);
    printprefixcode(huffmancode, freq);
    ofstream outputfile("output.txt", ios::app);
    if (!outputfile.is_open())
    {
        cerr << "Error opening file." << "\n";
        return 0;
    }
    outputfile << encodedstr;
    outputfile.close();
    cout << "Output.txt created (binary string)" << "\n";
    ofstream outputBin("Output.bin", ios::app);
    if (!outputBin.is_open())
    {
        cerr << "Error opening file." << "\n";
        return 0;
    }
    vector<unsigned char> binaryData = stringToBinary(encodedstr);
    string encodedText = encodedstr;
    int paddingBits = (8 - (encodedText.length() % 8)) % 8;

    outputBin.write(reinterpret_cast<char *>(&paddingBits), sizeof(int));
    outputBin.write(reinterpret_cast<char *>(binaryData.data()), binaryData.size());
    outputBin.close();
    cout << "Output.bin created" << "\n";
    int originalBits = filtercontent.length() * 8;
    int compressedBits = encodedstr.length();
    float ratio = (float)compressedBits / originalBits * 100;
    float efficiency = ((float)(originalBits - compressedBits) / originalBits) * 100;
    float saved = 100 - ratio;
    cout << "\nCompression Stats:" << "\n";
    cout << "Original size:    " << originalBits << " bits" << "\n";
    cout << "Compressed size:  " << compressedBits << " bits" << "\n";
    cout << "Space saved:      " << fixed << setprecision(2) << saved << "%" << "\n";
    cout << "Bits saved:       " << originalBits - compressedBits << " bits" << "\n";
}