#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "font8x8_basic.h"

void render(char const *bitmap, int ord)
{
	printf("    (");
	if (isprint(ord))
		printf(" -- '%c'\n", ord);
	else
		printf(" -- '\\x%02x'\n", (unsigned char)ord);

	for (int x = 0; x < 8; x++)
	{
		char out[9] = {0};
		for (int y = 0; y < 8; y++)
		{
			int const set = bitmap[x] & (1 << y);
			out[y] = set ? '1' : '0';
		}
		printf("      b\"%s\"", out);

		if (x < 8-1)
			puts(",");
		else
			puts("");
	}
	printf("    )");
}

int main(int argc, char **argv)
{

	puts(
		"-- Auto generated file.\n"
		"-- See https://github.com/jonasjj/font8x8-vhdl-package\n\n"
		"library ieee;\n"
		"use ieee.std_logic_1164.all;\n\n"
		"library dot_matrix;\n"
		"use dot_matrix.types.all;\n\n"
		"package charmap is\n"
		"  constant charmap : charmap_type := (\n");

	for (int ord = 0; ord < 128; ord++)
	{
		char const *bitmap = font8x8_basic[ord];
		render(bitmap, ord);
		if (ord < 128 - 1)
		{
			printf(",\n");
		}
		else
		{
			printf("\n");
		}
	}

	puts("  );");
	puts("end package;");

	return 0;
}
