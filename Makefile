make:
	@python3 setup.py build_ext --inplace
	@gcc main.c -o main -I/usr/include/python3.10 -L. -lpython3.10 CYTHON_CODE.cpython-310-x86_64-linux-gnu.so -Wl,-rpath='$ORIGIN'
	@ls
	
run:
	@echo "Ejecutando el programa..."
	@PYTHONPATH=".:$$PYTHONPATH" ./main

clean:
	@rm -f CYTHON_CODE.c
	@rm -f CYTHON_CODE.cpython-310-x86_64-linux-gnu.so
	@rm -f CYTHON_CODE.h
	@rm -rf build/
	@rm -f main
	@ls
