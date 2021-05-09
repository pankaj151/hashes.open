#!/bin/bash

#j=20
#k=$((i+j))
#echo index$k
#ffmpeg -i input1.mp4 -c copy -bsf:v h264_mp4toannexb -f mpegts intermediate1.ts
#ffmpeg -i "concat:intermediate1.ts|intermediate2.ts" -c copy -bsf:a aac_adtstoasc output.mp4

i=1; for file in *.mkv; do mv "$file" "index$i.mkv";i=$((i+1)); done
i=1; for f in *.mkv; do ffmpeg -i $f -c copy -bsf:v h264_mp4toannexb -f mpegts intermediate$i.ts; i=$((i+1)) ; done
echo "concat:" >> file.txt
for f in *.mkv; do echo -n "$f|">>file.txt; done

#ffmpeg -i file.txt -c copy -bsf:a aac_adtstoasc output.mp4
