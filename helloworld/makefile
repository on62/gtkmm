helloworld:	build_folder HelloWorld.cpp main.cpp
		g++ -Wall HelloWorld.cpp main.cpp -o build/helloworld `pkg-config gtkmm-3.0 --cflags --libs`

build_folder:
		mkdir -p build
