#Before incrementing the current shell script checks:
#if file "ex2_test.txt.lock" exists, then it means that another thread is using 'ex2_test.txt'
#file, thus, current thread will wait until another tread will be done
#if file "ex2_test.txt.lock" does not exist, thus, current thread can create it and work with 
#shared file 'ex2_test.txt'

#lock to use the shared file when the shared file is available
while ! ln 'ex2_test.txt' 'ex2_test.txt.lock'
do
sleep 0.1 #busy waiting
done

last_num="$(tail -n 1 'ex2_test.txt')"
((last_num++))

echo $last_num>>"ex2_test.txt"

#unlock to yield another thread work
rm 'ex2_test.txt.lock'

