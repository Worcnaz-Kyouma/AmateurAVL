# Params
SOURCE = $(wildcard app/src/*.cpp)
OBJECTS = $(patsubst app/src/%.cpp, app/build/%.o, $(SOURCE))
GNUPARAMS = -Iapp/include

# Fundamental Recipes
app/build/%.o: app/src/%.cpp
	@if not exist app\build mkdir app\build
	g++ $(GNUPARAMS) -o $@ -c $<

app/bin/main.exe: $(OBJECTS)
	@if not exist app\bin mkdir app\bin
	g++ $(GNUPARAMS) -o $@ $(OBJECTS)

# Final Recipes
.PHONY: run clear
run: app/bin/main.exe
	.\app\bin\main.exe

clear:
	@if exist app\build rmdir /s /q app\build
	@if exist app\bin rmdir /s /q app\bin