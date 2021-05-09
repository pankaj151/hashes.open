#!bin/bash 


i=1; for file in *.mkv; do mv "$file" "index$i.mkv"; i=$((i+1)); done
j=1; for file in *.mkv; do ffmpeg -i "$file" -c copy -bsf:v h264_mp4toannexb -f mpegts intermediate$j.ts;j=$((j+1)); done 
echo concat: >> file.txt
for file in *.ts; do echo -n "$file|" >>file.txt ; done 

#ffmpeg -i file.txt -c copy -bsf:a aac_adtstoasc output.mp4 
