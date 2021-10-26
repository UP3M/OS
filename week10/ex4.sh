    1  mkdir tmp
    2  echo > tmp/file1
    3  echo > tmp/file2
    4  ln tmp/file1 tmp/link1
    5  gcc ex4.c -o ex4
    6  ./ex4 > ex4.txt
