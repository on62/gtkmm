examplewindow:	build_folder ExampleWindow.cpp MyArea.cpp main.cpp
		g++ -Wall ExampleWindow.cpp MyArea.cpp main.cpp -o build/examplewindow `pkg-config gtkmm-3.0 --cflags --libs`

build_folder:
		mkdir -p build

clean:
	rm -fr build
