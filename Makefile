remindme: main.cpp reminder.o timer.o
	g++ -Wall -O3 -o $@ $^ -lrt

reminder.o: reminder.cc
	g++ -c -Wall -O3 -o $@ $^

timer.o: timer.cc
	g++ -c -Wall -O3 -o $@ $^

clean:
	rm -f *.o remindme