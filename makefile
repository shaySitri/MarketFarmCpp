CPP_FARM:Animal.o Chicken.o ChickenFarm.o Cow.o CowFarm.o Farm.o farmMarket.o Market.o Sheep.o SheepFarm.o
	g++ Animal.o Chicken.o ChickenFarm.o Cow.o CowFarm.o Farm.o farmMarket.o Market.o Sheep.o SheepFarm.o -o CPP_FARM
Animal.o:Animal.cpp Animal.h
	g++ -c -g Animal.cpp
Chicken.o:Chicken.cpp Chicken.h Animal.h
	g++ -c -g Chicken.cpp
ChickenFarm.o:ChickenFarm.cpp ChickenFarm.h Farm.h Animal.h Chicken.h
	g++ -c -g ChickenFarm.cpp
Cow.o:Cow.cpp Cow.h Animal.h
	g++ -c -g Cow.cpp
CowFarm.o:CowFarm.cpp CowFarm.h Farm.h Animal.h Cow.h
	g++ -c -g CowFarm.cpp
Farm.o:Farm.cpp Farm.h Animal.h CowFarm.h Cow.h SheepFarm.h Sheep.h ChickenFarm.h Chicken.h
	g++ -c -g Farm.cpp
farmMarket.o: farmMarket.cpp Market.h Farm.h Animal.h CowFarm.h Cow.h ChickenFarm.h Chicken.h SheepFarm.h Sheep.h
	g++ -c -g farmMarket.cpp
Market.o: Market.cpp Market.h Farm.h Animal.h CowFarm.h Cow.h ChickenFarm.h Chicken.h SheepFarm.h Sheep.h Exceptions.h
	g++ -c -g Market.cpp
Sheep.o: Sheep.cpp Sheep.h Animal.h
	g++ -c -g Sheep.cpp
SheepFarm.o: SheepFarm.cpp SheepFarm.h Farm.h Animal.h Sheep.h
	g++ -c -g SheepFarm.cpp
clean:
	rm -f *.o CPP_FARM
