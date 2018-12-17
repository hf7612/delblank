set -x
for (( i=0;i<100;i++ )); do echo $i;cp l.c. a$i.c; done
ls a*.c  > l7
./delblank l7