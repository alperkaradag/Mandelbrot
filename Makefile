all: compile run

compile:
	g++ Bitmap.cpp ZoomList.cpp Mandelbrot.cpp FractalCreator.cpp main.cpp -o Mandelbrot
run: 
	Mandelbrot.exe