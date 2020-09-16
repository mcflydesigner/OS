#Usually the race condition appears after 4th or 5th iteration
#The critical region is shared file between 2 threads - "ex2_test.txt"


#to prevent race condition I use the existence of file "ex2.lock"
for i in {1..10}
do
	#use another script to increase the last value in the file by 1
	./ex2_incrementer.sh&
	./ex2_incrementer.sh
done
