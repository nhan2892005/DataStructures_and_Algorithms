#!/bin/bash

numbers=(39 40  46 47 51 52 78 79 90 93 95 131 140 212 301 401 698 842 980 1219 1239 1255 1723 2597)

for number in "${numbers[@]}"
do
  touch "Leetcode${number}.cpp"
done

echo "Các file đã được tạo thành công!"