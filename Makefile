
all:
	pio run
# adafruit_trellis_m4

install:
	pio run -t upload

clean:
	pio run -t clean

cleanall:
	pio run -t cleanall

distclean: clean cleanall
	rm -rf ./.pio


# Environment                    Group     Name       Title                 Description
# -----------------------------  --------  ---------  --------------------  ------------------------------------------------------------

# adafruit_trellis_m4            Advanced  compiledb  Compilation Database  Generate compilation database `compile_commands.json`
# adafruit_trellis_m4            General   clean      Clean
# adafruit_trellis_m4            General   cleanall   Clean All             Clean a build environment and installed library dependencies
# adafruit_trellis_m4            Platform  upload     Upload
