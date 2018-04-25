# Arithmetic Coding Implementation with C++
Arithmetic Coding is a Data Compression technique based on the concept of interval subdividing.
In arithmetic coding a source sequence is represented by an interval between 0 and 1 on the real number line.
Each symbol in the input narrows this interval.
As the interval becomes smaller, the number of bits needed to specify it grows.
It uses the probabilities of the source messages to successively narrow the interval used to represent the
ensemble.
A high probability message narrows the interval less than a low probability message, so that high probability messages
contribute fewer bits to the coded ensemble.

### Team Members
* Khaled Mohamed
* Mena Fayez

### Notes
There are three text files to read input and write results :
1. "input.txt" : it must contain the input text whether it was encoding or decoding process. be careful, if it is decoding process you should put the number of symbols (in decimal) of the raw file in the first line in this file, then the encoded data in the second line. if it was encoding process just enter the raw data.
2. "set.txt" : it must contain the set of symbols that may appear on the input file and thier probabilites or accumulative functions. be careful, put the set of symbols on the first line and probabilites on the second line with spaces separating each probability from the next one. 
3. "output.txt" : the output of the encoding or decoding process will appear on this file.
