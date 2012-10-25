#Author: andyhuzhill
#Time: 2011-11-20

PRJ:=gift
MAINC:=gift.c

CC := sdcc		 #用来调用sdcc的命令行
CPPFLAGS :=		#预处理器参数
CFLAGS := -mmcs51  #编译器参数
LDFLAGS :=  #链接器参数

SRCS := $(MAINC) #这一行及下一行得到当前目录下的.c文件的列表，并且确保包括main()函数的文件是第一个
SRCS += $(filter-out $(MAINC), $(wildcard *.c))
DEPS := $(patsubst %.c, %.d, $(SRCS))
SRCES := $(filter-out $(MAINC),$(wildcard *.c))

OBJS:= $(patsubst %.c,%.rel,$(SRCES))
IHEX := $(addsuffix .ihx, $(PRJ))
HEX  := $(addsuffix .hex, $(PRJ))
BIN	 := $(addsuffix .bin, $(PRJ))

all: 
	$(CC) $(CFLAGS)  $(LDFLAGS)  $(MAINC)  -o $(IHEX)
	packihx  $(IHEX) > $(HEX)

debug:
	$(CC) $(CFLAGS) --debug $(LDFLAGS) $(MAINC) -o $(IHEX)
	packihx  $(IHEX) > $(HEX)

install: all

	sudo  avrdude -p 8052 -c usbasp -e -U flash:w:$(HEX)

installstc: 
	objcopy -I ihex -O binary $(HEX) $(BIN)
	gSTCISP

clean:
	rm -f *.bak
	rm -f *.asm
	rm -f *.lst
	rm -f *.sym
	rm -f *.map
	rm -f *.lnk
	rm -f *.mem
	rm -f *.i
	rm -f *.d
	rm -f *.rst
	rm -f *.cdb
	rm -f *.adb
	rm -f *.rel
	rm -f *.lk	
	rm -f *.bin
	rm -f *.hex
	rm -f *.ihx
	



