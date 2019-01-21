#include <stdio.h>
#include <stdlib.h>

#include "font8x8_basic.h"

void usage(char *exec) {
    printf("Usage: %s <char_code>\n", exec);
    printf("       <char_code> Decimal character code between 0 and 127\n");
}

void render(char *bitmap) {
    int x,y;
    int set;
    int mask;
    printf("    (\n");
    for (x=0; x < 8; x++) {
      printf("      (");
        for (y=0; y < 8; y++) {
            set = bitmap[x] & 1 << y;
            printf("%s", set ? "'1'" : "'0'");
	    if (y < 8 - 1) {
	      printf(", ");
	    }
        }
	if (x < 8 - 1) {
	    printf("),\n");
	} else {
	    printf(")\n");
	}
    }
    printf("    )");
}

int main(int argc, char **argv) {

    printf("-- Auto generated file.\n"
	"-- See https://github.com/jonasjj/font8x8-vhdl-package\n\n"
	"library ieee;"
        "use ieee.std_logic_1164.all;\n"
        "package charmap is\n"
        "  type led8x8_type is array (7 downto 0) of std_logic_vector(7 downto 0);\n"
        "  type charmap_type is array (127 downto 0) of led8x8_type;\n"
	"  constant charmap : charmap_type := (\n");
  
    int ord;
    for (ord = 0; ord < 128; ord++) {
        char *bitmap = font8x8_basic[ord];
        render(bitmap);
	if (ord < 128 -1) {
	     printf(",\n");
	} else {
	     printf("\n");
	}
    }
    
    printf("  );\n");
    printf("end package;\n");

    return 0;
}
