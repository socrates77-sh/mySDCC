DEVICE = mc35p7041
OUTPUT = dev_$(DEVICE)

all : $(OUTPUT) *.c *.h

$(OUTPUT) : *.c *.h
	gcc -DDEVICE_NAME='"$(DEVICE)"' main.c reg_def_$(DEVICE).c -o $(OUTPUT)

clean:
	rm -f dev*
