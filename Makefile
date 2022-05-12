CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I src -MP -MMD
CPPFLAGST = -I thirdparty -MP -MMD
CHESS = bin/chess
TEST_NAME = bin/chess-test

all: $(CHESS)

chess-start: $(CHESS) 
	./$(CHESS)

$(CHESS): obj/src/chess/chess.o obj/src/libchess/libchess.a
	g++ $(CFLAGS) -o $@ $^

obj/src/chess/chess.o: src/chess/chess.cpp
	g++ -c -I src $(CFLAGS) $(CPPFLAGS) -o $@ $<

obj/src/libchess/libchess.a: obj/src/libchess/chessviz.o
	ar rcs $@ $^

obj/src/libchess/chessviz.o: src/libchess/chessviz.cpp
	g++ -c -I src $(CFLAGS) $(CPPFLAGS) -o $@ $<

.PHONY: all clean test chess-start test-start

clean:
	rm obj/src/libchess/*.[oad] obj/src/chess/*.[od] $(CHESS) $(TEST_NAME) obj/test/*.[od]

test-start:
	./$(TEST_NAME)

test: $(TEST_NAME)

$(TEST_NAME): obj/test/main.o obj/test/test.o obj/src/libchess/libchess.a
	g++ $(CFLAGS) -o $@ $^

obj/test/test.o: test/test.cpp
	g++ -c $(CFLAGS) $(CPPFLAGS) $(CPPFLAGST) $< -o $@

obj/test/main.o: test/main.cpp
	g++ -c $(CFLAGS) $(CPPFLAGS) $(CPPFLAGST) $< -o $@

-include obj/src/chess/chess.d obj/src/libchess/chessviz.d obj/test/test.d obj/test/main.d

