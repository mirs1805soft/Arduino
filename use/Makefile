# 各種ファイルの保存ディレクトリ
DIR_SRC  := ./src
DIR_HEAD := ./include
DIR_OBJ  := ./build
DIR_IMG  := ./img

# 生成するプログラム
PRGS := 
PRGS += test_io test_uss test_request test_direction
PRGS += test_capture test_number test_circle test_dir_num
PRGS += test_server test_position test_camera
PRGS += pilot race
PRGS += thread_main0_1 request_neck neck_up neck_down


# オブジェクト
OBJS_RUN := $(addprefix $(DIR_OBJ)/, io.o uss.o arduino.o request.o direction.o)
OBJS_CAP := $(addprefix $(DIR_OBJ)/, get_img.o)
OBJS_NUM := $(addprefix $(DIR_OBJ)/, number_search.o number_detect.o)
OBJS_CIR := $(addprefix $(DIR_OBJ)/, color_binarize.o circle_detect.o)
OBJS_SVR := $(addprefix $(DIR_OBJ)/, server.o)
OBJS_POS := $(addprefix $(DIR_OBJ)/, position.o)

OBJS_NEW0_1 := $(addprefix $(DIR_OBJ)/, thread_run0_1.o thread_main0_1.o run_base.o wiringPiI2C.o thread_uss.o stay.o theta.o request.o arduino.o)
OBJS_NEW0_2 := $(addprefix $(DIR_OBJ)/, thread_run0_2.o thread_main0_2.o wiringPiI2C.o theta.o request.o arduino.o run_base.o stay.o thread_uss.o)
OBJS_NEW0_3 := $(addprefix $(DIR_OBJ)/, thread_run0_3.o thread_main0_3.o wiringPiI2C.o thread_uss.o theta.o request.o arduino.o)
OBJS_NEW0_4 := $(addprefix $(DIR_OBJ)/, thread_run0_4.o thread_main0_4.o run_base.o wiringPiI2C.o thread_uss.o stay.o theta.o request.o arduino.o)
OBJS_NEW0_5 := $(addprefix $(DIR_OBJ)/, thread_run0_5.o thread_main0_5.o run_base.o wiringPiI2C.o thread_uss.o stay.o theta.o request.o arduino.o)

OBJS_NEW0_6 := $(addprefix $(DIR_OBJ)/, thread_run0_6.o thread_main0_6.o run_base.o wiringPiI2C.o thread_uss.o stay.o theta.o request.o arduino.o)
OBJS_NEW0_7 := $(addprefix $(DIR_OBJ)/, thread_run0_7.o thread_main0_7.o run_base.o wiringPiI2C.o thread_uss.o stay.o theta.o request.o arduino.o)
OBJS_NEW0_8 := $(addprefix $(DIR_OBJ)/, thread_run0_8.o thread_main0_8.o run_base.o wiringPiI2C.o thread_uss.o stay.o theta.o request.o arduino.o)
OBJS_NEW0_9 := $(addprefix $(DIR_OBJ)/, thread_run0_9.o thread_main0_9.o run_base.o wiringPiI2C.o thread_uss.o stay.o theta.o request.o arduino.o)
OBJS_NEW0_10 := $(addprefix $(DIR_OBJ)/, thread_run0_10.o thread_main0_10.o run_base.o wiringPiI2C.o thread_uss.o stay.o theta.o request.o arduino.o)

OBJS_NEW0_11 := $(addprefix $(DIR_OBJ)/, thread_run0_11.o thread_main0_11.o run_base.o wiringPiI2C.o thread_uss.o stay.o theta.o request.o arduino.o)
OBJS_NEW0_12 := $(addprefix $(DIR_OBJ)/, thread_run0_12.o thread_main0_12.o run_base.o wiringPiI2C.o thread_uss.o stay.o theta.o request.o arduino.o)


OBJS_NEW1_0 := $(addprefix $(DIR_OBJ)/, thread_run1_0.o thread_main1_0.o wiringPiI2C.o thread_uss.o stay.o theta.o request.o arduino.o)
OBJS_NEW2_0 := $(addprefix $(DIR_OBJ)/, thread_run2_0.o thread_main2_0.o wiringPiI2C.o stay.o theta.o request.o arduino.o thread_uss.o)
OBJS_NEW3_0 := $(addprefix $(DIR_OBJ)/, thread_run3_0.o thread_main3_0.o wiringPiI2C.o thread_uss.o stay.o theta.o request.o arduino.o)
OBJS_NEW4_0 := $(addprefix $(DIR_OBJ)/, thread_run4_0.o thread_main4_0.o wiringPiI2C.o thread_uss.o stay.o theta.o request.o arduino.o)
OBJS_NEW5_0 := $(addprefix $(DIR_OBJ)/, thread_run5_0.o thread_main5_0.o wiringPiI2C.o thread_uss.o stay.o theta.o request.o arduino.o)

OBJS_NEW6_0 := $(addprefix $(DIR_OBJ)/, thread_run6_0.o thread_main6_0.o run_base.o wiringPiI2C.o thread_uss.o stay.o theta.o request.o arduino.o)
OBJS_NEW7_0 := $(addprefix $(DIR_OBJ)/, thread_run7_0.o thread_main7_0.o run_base.o wiringPiI2C.o thread_uss.o stay.o theta.o request.o arduino.o)
OBJS_NEW8_0 := $(addprefix $(DIR_OBJ)/, thread_run8_0.o thread_main8_0.o run_base.o wiringPiI2C.o thread_uss.o stay.o theta.o request.o arduino.o)
OBJS_NEW9_0 := $(addprefix $(DIR_OBJ)/, thread_run9_0.o thread_main9_0.o run_base.o wiringPiI2C.o thread_uss.o stay.o theta.o request.o arduino.o)
OBJS_NEW10_0 := $(addprefix $(DIR_OBJ)/, thread_run10_0.o thread_main10_0.o run_base.o wiringPiI2C.o thread_uss.o stay.o theta.o request.o arduino.o)

OBJS_NEW11_0 := $(addprefix $(DIR_OBJ)/, thread_run11_0.o thread_main11_0.o run_base.o wiringPiI2C.o thread_uss.o stay.o theta.o request.o arduino.o)
OBJS_NEW12_0 := $(addprefix $(DIR_OBJ)/, thread_run12_0.o thread_main12_0.o run_base.o wiringPiI2C.o thread_uss.o stay.o theta.o request.o arduino.o)
OBJS_TEST_NECK := $(addprefix $(DIR_OBJ)/, request_neck.o request.o arduino.o)
OBJS_NECK_UP := $(addprefix $(DIR_OBJ)/, neck_up.o request.o arduino.o)
OBJS_NECK_DOWN := $(addprefix $(DIR_OBJ)/, neck_down.o request.o arduino.o)


OBJS_NEW_in := $(addprefix $(DIR_OBJ)/, thread_in.o thread_main_in.o run_base.o wiringPiI2C.o thread_uss.o stay.o theta.o request.o arduino.o)

OBJS_NEW_out := $(addprefix $(DIR_OBJ)/, thread_out.o thread_main_out.o run_base.o wiringPiI2C.o thread_uss.o stay.o theta.o request.o arduino.o)

# コンパイルオプション
CC      := gcc
CFLAGS  := -O2 -Wall -MMD -MP `pkg-config --cflags opencv`
LDFLAGS := -lm -lpthread -lwiringPi `pkg-config --libs opencv`
INCLUDE := -I $(DIR_HEAD)

# 全コンパイル・ファイル削除用ターゲット
.PHONY: all clean

all: $(PRGS)

clean:
	$(RM) $(PRGS)
	$(RM) $(DIR_OBJ)/*.o $(DIR_OBJ)/*.d
	$(RM) $(DIR_IMG)/*.jpg

# パターンルール
$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c
	@if [ ! -d $(DIR_OBJ) ]; then echo "mkdir $(DIR_OBJ)"; mkdir $(DIR_OBJ); fi
	@if [ ! -d $(DIR_IMG) ]; then echo "mkdir $(DIR_IMG)"; mkdir $(DIR_IMG); fi
	$(CC) -c $(CFLAGS) $(INCLUDE) $< -o $@

# 依存関係ファイルの読み込み
-include $(DIR_OBJ)/*.d

# プログラム毎に生成ルールを記述
pilot: $(OBJS_RUN) $(OBJS_CAP) $(OBJS_NUM) $(OBJS_CIR) $(OBJS_SVR) $(OBJS_POS) $(DIR_OBJ)/pilot.o
	$(CC) $(LDFLAGS) $^ -o $@

test_io: $(OBJS_RUN) $(DIR_OBJ)/test_io.o
	$(CC) $(LDFLAGS) $^ -o $@

test_uss: $(OBJS_RUN) $(DIR_OBJ)/test_uss.o
	$(CC) $(LDFLAGS) $^ -o $@

test_request: $(OBJS_RUN) $(DIR_OBJ)/test_request.o
	$(CC) $(LDFLAGS) $^ -o $@

test_direction: $(OBJS_RUN) $(DIR_OBJ)/test_direction.o
	$(CC) $(LDFLAGS) $^ -o $@

test_capture: $(OBJS_CAP) $(DIR_OBJ)/test_capture.o
	$(CC) $(LDFLAGS) $^ -o $@

test_camera: $(OBJS_CAP) $(DIR_OBJ)/test_camera.o
	$(CC) $(LDFLAGS) $^ -o $@

test_number: $(OBJS_CAP) $(OBJS_NUM) $(DIR_OBJ)/test_number.o
	$(CC) $(LDFLAGS) $^ -o $@

test_circle: $(OBJS_CAP) $(OBJS_CIR) $(DIR_OBJ)/test_circle.o
	$(CC) $(LDFLAGS) $^ -o $@

test_dir_num: $(OBJS_RUN) $(OBJS_CAP) $(OBJS_NUM) $(DIR_OBJ)/test_dir_num.o
	$(CC) $(LDFLAGS) $^ -o $@

test_server: $(OBJS_SVR) $(DIR_OBJ)/test_server.o
	$(CC) $(LDFLAGS) $^ -o $@

test_position: $(OBJS_POS) $(DIR_OBJ)/test_position.o
	$(CC) $(LDFLAGS) $^ -o $@

race: $(OBJS_RUN) $(DIR_OBJ)/race.o
	$(CC) $(LDFLAGS) $^ -o $@


thread_main0_1: $(OBJS_NEW0_1) $(DIR_OBJ)/thread_main0_1.o
	$(CC) $(LDFLAGS) $(INCLUDE) $^ -o $@ 
thread_main0_2: $(OBJS_NEW0_2) $(DIR_OBJ)/thread_main0_2.o
	$(CC) $(LDFLAGS) $(INCLUDE) $^ -o $@ 
thread_main0_3: $(OBJS_NEW0_3) $(DIR_OBJ)/thread_main0_3.o
	$(CC) $(LDFLAGS) $(INCLUDE) $^ -o $@ 
thread_main0_4: $(OBJS_NEW0_4) $(DIR_OBJ)/thread_main0_4.o
	$(CC) $(LDFLAGS) $(INCLUDE) $^ -o $@ 
thread_main0_5: $(OBJS_NEW0_5) $(DIR_OBJ)/thread_main0_5.o
	$(CC) $(LDFLAGS) $(INCLUDE) $^ -o $@ 

thread_main0_6: $(OBJS_NEW0_6) $(DIR_OBJ)/thread_main0_6.o
	$(CC) $(LDFLAGS) $(INCLUDE) $^ -o $@ 
thread_main0_7: $(OBJS_NEW0_7) $(DIR_OBJ)/thread_main0_7.o
	$(CC) $(LDFLAGS) $(INCLUDE) $^ -o $@ 
thread_main0_8: $(OBJS_NEW0_8) $(DIR_OBJ)/thread_main0_8.o
	$(CC) $(LDFLAGS) $(INCLUDE) $^ -o $@ 
thread_main0_9: $(OBJS_NEW0_9) $(DIR_OBJ)/thread_main0_9.o
	$(CC) $(LDFLAGS) $(INCLUDE) $^ -o $@ 
thread_main0_10: $(OBJS_NEW0_10) $(DIR_OBJ)/thread_main0_10.o
	$(CC) $(LDFLAGS) $(INCLUDE) $^ -o $@ 

thread_main0_11: $(OBJS_NEW0_11) $(DIR_OBJ)/thread_main0_11.o
	$(CC) $(LDFLAGS) $(INCLUDE) $^ -o $@ 
thread_main0_12: $(OBJS_NEW0_12) $(DIR_OBJ)/thread_main0_12.o
	$(CC) $(LDFLAGS) $(INCLUDE) $^ -o $@ 


thread_main1_0: $(OBJS_NEW1_0) $(DIR_OBJ)/thread_main1_0.o
	$(CC) $(LDFLAGS) $(INCLUDE) $^ -o $@ 
thread_main2_0: $(OBJS_NEW2_0) $(DIR_OBJ)/thread_main2_0.o
	$(CC) $(LDFLAGS) $(INCLUDE) $^ -o $@ 
thread_main3_0: $(OBJS_NEW3_0) $(DIR_OBJ)/thread_main3_0.o
	$(CC) $(LDFLAGS) $(INCLUDE) $^ -o $@ 
thread_main4_0: $(OBJS_NEW4_0) $(DIR_OBJ)/thread_main4_0.o
	$(CC) $(LDFLAGS) $(INCLUDE) $^ -o $@ 
thread_main5_0: $(OBJS_NEW5_0) $(DIR_OBJ)/thread_main5_0.o
	$(CC) $(LDFLAGS) $(INCLUDE) $^ -o $@ 

thread_main6_0: $(OBJS_NEW6_0) $(DIR_OBJ)/thread_main6_0.o
	$(CC) $(LDFLAGS) $(INCLUDE) $^ -o $@ 
thread_main7_0: $(OBJS_NEW7_0) $(DIR_OBJ)/thread_main7_0.o
	$(CC) $(LDFLAGS) $(INCLUDE) $^ -o $@ 
thread_main8_0: $(OBJS_NEW8_0) $(DIR_OBJ)/thread_main8_0.o
	$(CC) $(LDFLAGS) $(INCLUDE) $^ -o $@ 
thread_main9_0: $(OBJS_NEW9_0) $(DIR_OBJ)/thread_main9_0.o
	$(CC) $(LDFLAGS) $(INCLUDE) $^ -o $@ 
thread_main10_0: $(OBJS_NEW10_0) $(DIR_OBJ)/thread_main10_0.o
	$(CC) $(LDFLAGS) $(INCLUDE) $^ -o $@ 

thread_main11_0: $(OBJS_NEW11_0) $(DIR_OBJ)/thread_main11_0.o
	$(CC) $(LDFLAGS) $(INCLUDE) $^ -o $@ 
thread_main12_0: $(OBJS_NEW12_0) $(DIR_OBJ)/thread_main12_0.o
	$(CC) $(LDFLAGS) $(INCLUDE) $^ -o $@ 


thread_main_in: $(OBJS_NEW_in) $(DIR_OBJ)/thread_main_in.o
	$(CC) $(LDFLAGS) $(INCLUDE) $^ -o $@ 
thread_main_out: $(OBJS_NEW_out) $(DIR_OBJ)/thread_main_out.o
	$(CC) $(LDFLAGS) $(INCLUDE) $^ -o $@ 

request_neck: $(OBJS_TEST_NECK) $(DIR_OBJ)/request_neck.o
	$(CC) $(LDFLAGS) $(INCLUDE) $^ -o $@
neck_up: $(OBJS_NECK_UP) $(DIR_OBJ)/neck_up.o
	$(CC) $(LDFLAGS) $(INCLUDE) $^ -o $@
neck_down: $(OBJS_NECK_DOWN) $(DIR_OBJ)/neck_down.o
	$(CC) $(LDFLAGS) $(INCLUDE) $^ -o $@

radicon: $(OBJS_RUN) $(DIR_OBJ)/radicon.o
	$(CC) $(LDFLAGS) $^ -o $@

test_uss: $(OBJS_RUN) $(DIR_OBJ)/test_uss.o
	$(CC) $(LDFLAGS) $^ -o $@	
