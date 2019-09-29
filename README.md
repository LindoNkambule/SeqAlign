# Getting started
```sh
git clone https://github.com/LindoNkambule/SeqAlign
cd SeqAlign; gcc main.c -o align
./align ref query match mismatch gap
e.g. ./align AAA AAA 1 -1 -2
In the example above, both the reference and query sequences are AAA. The match, mismatch, and gap scores are 1, -1, and -2 respectively
```
