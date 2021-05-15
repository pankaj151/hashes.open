#!bin/bash
apt install crunch -y
crunch 8 8 1234567890 -o eight.txt ; crunch 2 2 1234567890 -o two.txt
split -l 12500000 eight.txt
#git clone https://github.com/pankaj151/hashes.open
mv hashes.open/hccap/shyamal* .
hashcat -a 1 -m 2500 -o cr.txt -w 3 -D 2 shyamal.hccapx xah two.txt

