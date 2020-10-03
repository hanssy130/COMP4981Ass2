# COMP4981Ass2

## Specification

You are to create 6 programs to encode and decode parity, checksum, crc32. The program names are:

- encode-parity
- decode-parity
- encode-checksum
- decode-checksum
- encode-crc32
- decode-crc32

Each program will **read from a file**, if provided, otherwise they will read from stdin.
Each program will **write the output to stdout**.
For Parity and checksum you need to add a **"--even" or "--odd" flag**. The getopt() function is useful to look at.
Parity and checksum work on **8-bit** values. This table will help to get you started: http://sticksandstones.kstrom.com/appen.html
Given an input of "Hi" that is 01001000 and 01101001 (see the table link above).
If we are using even parity the number of 1 bits must be even: 01001000 needs zero 1 bits to have an even number of 1 bits so it becomes 010010000 and 01101001 also needs zero 1 bits so it becomes 011010010.
The output of the program is then 010010000011010010
To decode the first 9 bits are read: 01001000 and it is verified that there is an even number of 1 bits. Then the next 9 bits are read 011010010 and, again, verified that there are an even number of 1 bits. The output is then Hi.
If the parity is incorrect then you must write a message to stdout informing the user where the error is (eg. what block of 9 bytes is wrong, where in the file).
For checksum the idea is the same except that all the vertical bits are checked too (example is even parity again):

01001000 -> 010010000
01101001 -> 011010010
-----------      -------------
00100001 -> 001000010

For CRC32 there are many resources on the internet. As well as Chi En, who will cover CRC32 later in the Datacomm course, is available to help probably, if you ask nicely.

###Grading
Each assignment will be run against the other teams. For example team 1's parity encode will be decoded by all the other teams. This is to test the interoperability. In practical terms this means you all have to work together. 

You MAY NOT share code between teams. The only discussion that should happen is along the lines of "we output 1 you output 0 for this input, this is why you are wrong" and the reason is based on the input data, not the other teams code. You are not to even look at another teams code. Every team should work in isolation except for the testing part, and then you should only be providing sample input and output to one another to test with.

|Item|%|
|---|---|
|Design|10%|
|Quality (Testing, structure, etc...)|20%|
|Working Code|30%|
|Interoperability|40%|
|Programs|lose 10% for each crash while testing.|

## Specification Addition

You MUST submit a **CMakeLists.txt** that works on at least 3.18.2 that will create the 6 binaries.
The binaries MUST **be named** as outlined in the assignment specification.
You MUST hand in your **design documentation** (modules, functions, pseudocode/flowchart/whatever) by 9:30 Tuesday morning.
You MUST use Doxygen or some other "standard" **comment style** to document all of your functions.
You are not required to make any libraries, but I would encourage it.
You are not required to do any unit testing, but I would encourage it.
The programs will be run basically like:

Encoders:
```
./(encoder program) --even  # reads from the keyboard outputs to the screen
./(encoder program) --even > out.txt # reads from the keyboard outputs to out.txt
./(encoder program) --even < input.txt  # reads from keyboard coming from input.txt outputs to the screen
./(encoder program) --even < input.txt > out.txt # reads from keyboard coming from input.txt outputs to out.txt
./(encoder program) --even input.txt  # reads from input.txt outputs to the screen
./(encoder program) --even input.txt > out.txt # reads from input.txt outputs to out.txt
```
Decoders:
```
./(decoder program) --even  # reads from the keyboard outputs to the screen
./(decoder program) --even > out.txt # reads from the keyboard outputs to out.txt
./(decoder program) --even < input.txt  # reads from keyboard coming from input.txt outputs to the screen
./(decoder program) --even < input.txt > out.txt # reads from keyboard coming from input.txt outputs to out.txt
./(decoder program) --even input.txt  # reads from input.txt outputs to the screen
./(decoder program) --even input.txt > out.txt # reads from input.txt outputs to out.txt
```
Piped:
```
./(encoder program) --even | ./(decoder program) --even
./(encoder program) --even | ./(decoder program) --even > out.txt
./(encoder program) --even < input.txt | ./(decoder program) --even
./(encoder program) --even < input.txt | ./(decoder program) --even > out.txt
./(encoder program) --even input.txt | ./(decoder program) --even
./(encoder program) --even input.txt | ./(decoder program) --even > out.txt
```
(--odd will be run too, of course)

You will (soonish) be provided the shell scripts I will use for marking that will run your programs against all the other programs.
